# include <stdio.h>
# include <stdlib.h>

# include <omp.h>

int main ( );
unsigned char *julia_set ( int w, int h, float xl, float xr, float yb, float yt );
int julia ( int w, int h, float xl, float xr, float yb, float yt, int i, int j );
void tga_write ( int w, int h, unsigned char rgb[], char *filename );

/******************************************************************************/

int main ( ) 

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for julia_set_openmp.

  Discussion:

    Consider points (X,Y) in a rectangular domain R = [XL,XR]x[YB,YT].

    Let Z be the complex number X+Yi, and let C be some complex constant.

    Let Z(0) = Z, Z(k+1) = Z(k)^2 + C

    The Julia set is the set of points Z in R with the property that
    the sequence of points Z(k) remain within R.

    To compute a picture of the Julia set, we choose a discrete array
    of WxH points in R.  We carry out up to 200 steps of the iteration for
    each point Z.  If 1000 < |Z| at any time, we assume Z is not in the
    Julia set.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2017

  Parameters:

    Local, int H, W, the height and width of the region in pixels.

    Local, float XL, XR, YB, YT, the left and right X limits, the
    bottom and top Y limits, of the region.

    Local, unsigned char *RGB, will hold W*H*3 values between 0 and 255,
    specifying the pixel color values.
*/
{
  int h = 1000;
  unsigned char *rgb;
  int w = 1000;
  double t1;
  double t2;
  float xl = - 1.5;
  float xr = + 1.5;
  float yb = - 1.5;
  float yt = + 1.5;

  printf ( "\n" );
  printf ( "julia_set_openmp:\n" );
  printf ( "  C/OpenMP version.\n" );
  printf ( "  Plot a version of the Julia set for Z(k+1)=Z(k)^2-0.8+0.156i\n" );
/*
  Note that, on Hokiespeed, using a single variable T in place of T1 and T2,
  which should be perfectly correct, yielded ridiculous nonsensical values,
  including negative times.
*/
  t1 = omp_get_wtime ( );
  rgb = julia_set ( w, h, xl, xr, yb, yt );
  t2 = omp_get_wtime ( ) - t1;
  printf ( "  Using %d threads max, %g seconds\n", omp_get_max_threads ( ), t2 );

  tga_write ( w, h, rgb, "julia_set_openmp.tga" );
/*
  Free memory.
*/
  free ( rgb );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "julia_set_openmp:\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
/******************************************************************************/

unsigned char *julia_set ( int w, int h, float xl, float xr, float yb, float yt )

/******************************************************************************/
/*
  Purpose:

    JULIA_SET applies JULIA to each point in the domain.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2017

  Parameters:

    Input, int W, H, the width and height of the region in pixels.

    Input, float XL, XR, YB, YT, the left, right, bottom and top limits.

    Output, unsigned char *JULIA_SET[W*H*3], the B, G, R values,
    between 0 and 255, of a plot of the Julia set.  We want
    [0,0,255] for points in the set (red), and [255,255,255]
    for points not in the set (white).
*/
{
  int i;
  int j;
  int juliaValue;
  int k;
  unsigned char *rgb;

  rgb = ( unsigned char * ) malloc ( w * h * 3 * sizeof ( unsigned char ) );

# pragma omp parallel \
  shared ( h, w, xl, xr, yb, yt ) \
  private ( i, j, k, juliaValue )
  {
# pragma omp for

    for ( j = 0; j < h; j++ )
    {
      for ( i = 0; i < w; i++ )
      {
        juliaValue = julia ( w, h, xl, xr, yb, yt, i, j );

        k = 3 * ( j * w + i );

        rgb[k]   = 255 * ( 1 - juliaValue );
        rgb[k+1] = 255 * ( 1 - juliaValue );
        rgb[k+2] = 255;
      }
    }
  }

  return rgb;
}
/******************************************************************************/

int julia ( int w, int h, float xl, float xr, float yb, float yt, int i, int j )

/******************************************************************************/
/*
  Purpose:

    JULIA returns 1 if a point is in the Julia set.

  Discussion:

    The iteration Z(k+1) = Z(k) + C is used, with C=-0.8+0.156i.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2017

  Parameters:

    Input, int W, H, the width and height of the region in pixels.

    Input, float XL, XR, YB, YT, the left, right, bottom and top limits.

    Input, int I, J, the indices of the point to be checked.

    Ouput, int JULIA, is 1 if the point is in the Julia set.
*/
{
  float ai;
  float ar;
  float ci = 0.156;
  float cr = -0.8;
  int k;
  float t;
  float x;
  float y;
/*
  Convert (I,J) indices to (X,Y) coordinates.
*/
  x = ( ( float ) ( w - i - 1 ) * xl
      + ( float ) (     i     ) * xr ) 
      / ( float ) ( w     - 1 );

  y = ( ( float ) ( h - j - 1 ) * yb
      + ( float ) (     j     ) * yt ) 
      / ( float ) ( h     - 1 );
/*
  Think of (X,Y) as real and imaginary components of
  a complex number A = x + y*i.
*/
  ar = x;
  ai = y;
/*
  A -> A * A + C
*/
  for ( k = 0; k < 200; k++ )
  {
    t  = ar * ar - ai * ai + cr;
    ai = ar * ai + ai * ar + ci;
    ar = t;
/*
  if 1000 < ||A||, reject the point.
*/
    if ( 1000 < ar * ar + ai * ai )
    {
      return 0;
    }
  }

  return 1;
}
/******************************************************************************/

void tga_write ( int w, int h, unsigned char rgb[], char *filename )

/******************************************************************************/
/*
  Purpose:

    TGA_WRITE writes a TGA or TARGA graphics file of the data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2017

  Parameters:

    Input, int W, H, the width and height of the image.

    Input, unsigned char RGB[W*H*3], the pixel data.

    Input, char *FILENAME, the name of the file to contain the screenshot.
*/
{
  FILE *file_unit;
  unsigned char header1[12] = { 0,0,2,0,0,0,0,0,0,0,0,0 };
  unsigned char header2[6] = { w%256, w/256, h%256, h/256, 24, 0 };
/* 
  Create the file.
*/
  file_unit = fopen ( filename, "wb" );
/*
  Write the headers.
*/
  fwrite ( header1, sizeof ( unsigned char ), 12, file_unit );
  fwrite ( header2, sizeof ( unsigned char ), 6, file_unit );
/*
  Write the image data.
*/
  fwrite ( rgb, sizeof ( unsigned char ), 3 * w * h, file_unit );
/*
  Close the file.
*/
  fclose ( file_unit );

  printf ( "\n" );
  printf ( "TGA_WRITE:\n" );
  printf ( "  Graphics data saved as '%s'\n", filename );

  return;
}

