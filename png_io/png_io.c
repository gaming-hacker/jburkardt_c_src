# include <float.h>
# include <math.h>
# include <png.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "png_io.h"

/******************************************************************************/

unsigned char *i41_to_uc1 ( int width, int height, int *i41, int gmin, 
  int gmax )

/******************************************************************************/
/*
  Purpose:

    I41_TO_UC1 converts a vector of data from I41 to UC1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, int I41[WIDTH*HEIGHT], gray scale data in int format.

    Input, int GMIN, GMAX, the gray scale values that will correspond
    to output values of 0 and 255, respectively.

    Output, unsigned char I41_TO_UC1[WIDTH*HEIGHT], gray scale
    data in unsigned char format.
*/
{
  int g;
  int i;
  int j;
  int k;
  unsigned char *uc1 = 
    ( unsigned char* ) malloc ( width * height * sizeof ( unsigned char ) );
 
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      g = i41[k];
      if ( g < gmin )
      {
        g = gmin;
      }
      else if ( gmax < g )
      {
        g = gmax;
      }
      uc1[k] = ( unsigned int ) 
        ( 255.0 * ( float ) ( g - gmin ) / ( float ) ( gmax - gmin ) );
      k = k + 1;
    }
  }
  return uc1;
}
/******************************************************************************/

int i4vec_max ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_MAX returns the value of the maximum element in an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 May 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, int A[N], the array to be checked.

    Output, int IVEC_MAX, the value of the maximum element.  This
    is set to 0 if N <= 0.
*/
{
  int i;
  int value;

  if ( n <= 0 )
  {
    return 0;
  }

  value = a[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < a[i] )
    {
      value = a[i];
    }
  }

  return value;
}
/******************************************************************************/

int i4vec_min ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_MIN returns the minimum element in an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 May 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, int A[N], the array to be checked.

    Output, int I4VEC_MIN, the value of the minimum element.  This
    is set to 0 if N <= 0.
*/
{
  int i;
  int value;

  if ( n <= 0 )
  {
    return 0;
  }

  value = a[0];

  for ( i = 1; i < n; i++ )
  {
    if ( a[i] < value )
    {
      value = a[i];
    }
  }
  return value;
}
/******************************************************************************/

unsigned char *r41_to_uc1 ( int width, int height, float *r41, float gmin, 
  float gmax )

/******************************************************************************/
/*
  Purpose:

    R41_TO_UC1 converts a vector of data from R4 to UC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R41[WIDTH*HEIGHT], gray scale data in float format.

    Input, float GMIN, GMAX, the gray scale values that will correspond
    to output values of 0 and 255, respectively.

    Output, unsigned char R41_TO_UC1[WIDTH*HEIGHT], gray scale
    data in unsigned char format.
*/
{
  float g;
  int i;
  int j;
  int k;
  unsigned char *uc1 = 
    ( unsigned char* ) malloc ( width * height * sizeof ( unsigned char ) );
 
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      g = r41[k];
      if ( g < gmin )
      {
        g = gmin;
      }
      else if ( gmax < g )
      {
        g = gmax;
      }
      uc1[k] = ( unsigned int ) ( 255.0 * ( g - gmin ) / ( gmax - gmin ) );
      k = k + 1;
    }
  }
  return uc1;
}
/******************************************************************************/

unsigned char *r43_to_uc3 ( int width, int height, float *r43 )

/******************************************************************************/
/*
  Purpose:

    R43_TO_UC3 converts data from float RGB to unsigned char RGB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 July 2019

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R43[3*WIDTH*HEIGHT], RGB data in float format.

    Output, unsigned char R43_TO_UC3[3*WIDTH*HEIGHT], RGB data
    in unsigned char format.
*/
{
  float b;
  float bmax;
  float bmin;
  float g;
  float gmax;
  float gmin;
  int i;
  int j;
  int k;
  float r;
  float rmax;
  float rmin;
  unsigned char *uc3;

  uc3 = ( unsigned char* ) malloc ( 3 * width * height * sizeof ( unsigned char ) );
/*
  Determine R, G, B ranges.
*/
  rmin = r43[0];
  rmax = r43[0];
  gmin = r43[1];
  gmax = r43[1];
  bmin = r43[2];
  bmax = r43[2];

  k = 0;

  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      r = r43[k];
      if ( r < rmin )
      {
        rmin = r;
      }
      if ( rmax < r )
      {
        rmax = r;
      }
      k = k + 1;

      g = r43[k];
      if ( g < gmin )
      {
        gmin = g;
      }
      if ( gmax < g )
      {
        gmax = g;
      }
      k = k + 1;

      b = r43[k];
      if ( b < bmin )
      {
        bmin = b;
      }
      if ( bmax < r )
      {
        bmax = b;
      }
      k = k + 1;
    }
  }

/*
  Fix bad ranges.
*/
  if ( rmin == rmax )
  {
    rmin = rmin - 0.5 * ( fabs ( rmin ) + 1.0 );
    rmax = rmax + 0.5 * ( fabs ( rmax ) + 1.0 );
  }
  if ( gmin == gmax )
  {
    gmin = gmin - 0.5 * ( fabs ( gmin ) + 1.0 );
    gmax = gmax + 0.5 * ( fabs ( gmax ) + 1.0 );

  }
  if ( bmin == bmax )
  {
    bmin = bmin - 0.5 * ( fabs ( bmin ) + 1.0 );
    bmax = bmax + 0.5 * ( fabs ( bmax ) + 1.0 );
  }
/*
  Map RMIN <= R <= RMAX to 0 <= RGB <= 255.
*/
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      uc3[k] = ( unsigned int ) 
        ( 255.0 * ( r43[k] - rmin ) / ( rmax - rmin ) );
      k = k + 1;

      uc3[k] = ( unsigned int ) 
        ( 255.0 * ( r43[k] - gmin ) / ( gmax - gmin ) );
      k = k + 1;

      uc3[k] = ( unsigned int ) 
        ( 255.0 * ( r43[k] - bmin ) / ( bmax - bmin ) );
      k = k + 1;
    }
  }
  return uc3;
}
/******************************************************************************/

unsigned char *r43_to_uc3_trimmed ( int width, int height, float *r43,
  float cmin[3], float cmax[3] )

/******************************************************************************/
/*
  Purpose:

    R43_TO_UC3_TRIMMED converts data from float RGB to unsigned char RGB.

  Discussion:

    Data outside a user-supplied range is trimmed.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R43[3*WIDTH*HEIGHT], RGB data in float format.

    Input, float CMIN[3], CMAX[3], the values of RGB that correspond to
    0 and 255.  Values outside this range are trimmed.

    Output, unsigned char R43_TO_UC3_TRIMMED[3*WIDTH*HEIGHT], RGB data
    in unsigned char format.
*/
{
  int i;
  int j;
  int k;
  unsigned char *uc3 = 
    ( unsigned char* ) malloc ( 3 * width * height * sizeof ( unsigned char ) );
/*
  Map RMIN <= R <= RMAX to 0 <= RGB <= 255.
*/
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      uc3[k] = ( unsigned int ) 
        ( 255.0 * ( r43[k] - cmin[0] ) / ( cmax[0] - cmin[0] ) );
      k = k + 1;

      uc3[k] = ( unsigned int ) 
        ( 255.0 * ( r43[k] - cmin[1] ) / ( cmax[1] - cmin[1] ) );
      k = k + 1;

      uc3[k] = ( unsigned int ) 
        ( 255.0 * ( r43[k] - cmin[2] ) / ( cmax[2] - cmin[2] ) );
      k = k + 1;
    }
  }
  return uc3;
}
/******************************************************************************/

float r4vec_max ( int n, float r4vec[] )

/******************************************************************************/
/*
  Purpose:

    R4VEC_MAX returns the value of the maximum element in a R4VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, float R4VEC[N], a pointer to the first entry of the array.

    Output, float R4VEC_MAX, the value of the maximum element.  This
    is set to 0.0 if N <= 0.
*/
{
  int i;
  float value;

  value = - FLT_MAX;

  if ( n <= 0 )
  {
    return value;
  }

  for ( i = 0; i < n; i++ )
  {
    if ( value < r4vec[i] )
    {
      value = r4vec[i];
    }
  }
  return value;
}
/******************************************************************************/

float r4vec_min ( int n, float r4vec[] )

/******************************************************************************/
/*
  Purpose:

    R4VEC_MIN returns the value of the minimum element in a R4VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, float R4VEC[N], the array to be checked.

    Output, float R4VEC_MIN, the value of the minimum element.
*/
{
  int i;
  float value;

  value = FLT_MAX;

  if ( n <= 0 )
  {
    return value;
  }

  for ( i = 0; i < n; i++ )
  {
    if ( r4vec[i] < value )
    {
      value = r4vec[i];
    }
  }
  return value;
}
/******************************************************************************/

int read_png ( const char *filename, int *width, int *height, 
  unsigned char **uc3, unsigned char **alpha )

/******************************************************************************/
/*
  Purpose:

    READ_PNG reads graphics data from a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2017

  Author:

    Original version by Hari Nair

  Parameters:

    Input, const char *FILENAME, the name of the file to be read.

    Output, int *WIDTH, *HEIGHT, the width and height of the image in pixels.

    Output, unsigned char *UC3[3*WIDTH*HEIGHT], RGB data in unsigned char 
    format.

    Output, unsigned char *ALPHA[WIDTH*HEIGHT], the alpha channel data.
*/
{
  int bit_depth;
  int color_type;
  png_uint_32 h;
  int i;
  FILE *infile = fopen ( filename, "rb" );
  png_infop info_ptr;
  int interlace_type;
  png_structp png_ptr;
  unsigned char *ptr = NULL;
  png_bytepp row_pointers;
  png_uint_32 w;

  png_ptr = png_create_read_struct ( 
    PNG_LIBPNG_VER_STRING, 
    ( png_voidp ) NULL, 
    ( png_error_ptr ) NULL, 
    ( png_error_ptr ) NULL );

  if ( ! png_ptr ) 
  {
    fclose ( infile );
    return 1;
  }
  
  info_ptr = png_create_info_struct ( png_ptr );

  if ( ! info_ptr )
  {
    png_destroy_read_struct ( 
      &png_ptr, 
      ( png_infopp ) NULL, 
      ( png_infopp ) NULL);

    fclose ( infile );

    return 1;
  }
  
  if ( setjmp ( png_jmpbuf(png_ptr) ) )
  {
/*
  if ( setjmp ( png_ptr->jmpbuf ) )
  {
*/
    png_destroy_read_struct (
      &png_ptr, 
      &info_ptr, 
      ( png_infopp ) NULL );

    fclose ( infile );

    return ( 1 );
  }
  
  png_init_io ( png_ptr, infile );

  png_read_info ( png_ptr, info_ptr );

  png_get_IHDR ( 
    png_ptr, 
    info_ptr, 
    &w, 
    &h,
    &bit_depth,
    &color_type,
    &interlace_type, 
    ( int * ) NULL, 
    ( int * ) NULL );

  *width = ( int ) w;
  *height = ( int ) h;
    
  if ( color_type == PNG_COLOR_TYPE_RGB_ALPHA ||
       color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
  {
    alpha[0] = malloc ( ( *width ) * ( *height ) );

    if ( alpha[0] == NULL )
  {
    fprintf ( stderr, "Can't allocate memory for alpha channel in PNG file.\n" );
    return 1; 
  }
  }
/* 
  Change a paletted/grayscale image to RGB 
*/
  if ( color_type == PNG_COLOR_TYPE_PALETTE && bit_depth <= 8 ) 
  {
    png_set_expand ( png_ptr );
  }
/* 
  Change a grayscale image to RGB.
*/
  if ( color_type == PNG_COLOR_TYPE_GRAY ||
       color_type == PNG_COLOR_TYPE_GRAY_ALPHA )
  {
    png_set_gray_to_rgb ( png_ptr );
  }
/* 
  If the PNG file has 16 bits per channel, strip them down to 8 
*/
  if ( bit_depth == 16 )
  {
    png_set_strip_16 ( png_ptr );
  }
/* 
  Use 1 byte per pixel 
*/
  png_set_packing ( png_ptr );

  row_pointers = malloc ( ( *height ) * sizeof ( png_bytep ) );

  if ( row_pointers == NULL )
  {
    fprintf ( stderr, "Can't allocate memory for PNG file.\n" );
    return 1;
  }

  for ( i = 0; i < *height; i++ )
  {
    row_pointers[i] = malloc ( 4 * ( *width ) );
    if ( row_pointers == NULL )
    {
      fprintf ( stderr, "Can't allocate memory for PNG line.\n" );
      return 1;
    }
  }

  png_read_image ( png_ptr, row_pointers );

  uc3[0] = malloc ( 3 * ( *width) * ( *height ) );
  if ( uc3[0] == NULL )
  {
    fprintf ( stderr, "Can't allocate memory for PNG file.\n" );
    return 1;
  }

  if ( alpha[0] == NULL )
  {
    ptr = uc3[0];
    for ( i = 0; i < *height; i++ )
    {
      memcpy ( ptr, row_pointers[i], 3 * ( *width ) );
      ptr = ptr + 3 * ( *width );
    }
  }
  else
  {
    int j;
    ptr = uc3[0];
    for ( i = 0; i < *height; i++ )
    {
      int ipos = 0;
      for ( j = 0; j < *width; j++ )
      {
        *ptr++ = row_pointers[i][ipos++];
        *ptr++ = row_pointers[i][ipos++];
        *ptr++ = row_pointers[i][ipos++];
        alpha[0][i * ( *width ) + j] = row_pointers[i][ipos++];
      }
    }
  }

  png_destroy_read_struct ( 
    &png_ptr, 
    &info_ptr, 
    ( png_infopp ) NULL );

  for ( i = 0; i < *height; i++ ) 
  {
    free ( row_pointers[i] );
  }
  free ( row_pointers );

  fclose ( infile );

  return 0;
}
/******************************************************************************/

unsigned char *uc1_to_uc3 ( int width, int height, unsigned char *uc1 )

/******************************************************************************/
/*
  Purpose:

    UC1_TO_UC3 converts a vector of UC to a tripled vector of UC.

   Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, unsigned char UC1[WIDTH*HEIGHT], gray scale
    data in unsigned char format.

    Output, unsigned char UC1_TO_UC3[3*WIDTH*HEIGHT], RGB
    data in unsigned char format, in which all three channels have the
    same value as the input gray scale channel.
*/
{
  int i;
  int j;
  int k;
  unsigned char *uc3 = 
    ( unsigned char * ) malloc ( 3 * width * height * sizeof ( unsigned char ) ); 
 
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      uc3[0+3*k] = uc1[k];
      uc3[1+3*k] = uc1[k];
      uc3[2+3*k] = uc1[k];
      k = k + 1;
    }
  }

  return uc3;
}
/******************************************************************************/

unsigned char *uc1_to_uc3_hot ( int width, int height, unsigned char *uc1 )

/******************************************************************************/
/*
  Purpose:

    UC1_TO_UC3_HOT converts UC1 data to UC3 using a "hot" scale.

   Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, unsigned char UC1[WIDTH*HEIGHT], gray scale data.

    Output, unsigned char UC1_TO_UC3_HOT[WIDTH*HEIGHT], the rescaled RGB data.
*/
{
  int i;
  int j;
  int k;
  unsigned char *uc3_hot = 
    ( unsigned char * ) malloc ( 3 * width * height * sizeof ( unsigned char ) ); 
 
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      if ( uc1[k] < 85 )
      {
        uc3_hot[0+3*k] = 3 * uc1[k];
        uc3_hot[1+3*k] =     uc1[k];
        uc3_hot[2+3*k] =     uc1[k];
      }
      else if ( uc1[k] < 170 )
      {
        uc3_hot[0+3*k] =     uc1[k];
        uc3_hot[1+3*k] = 3 * uc1[k] - 255;
        uc3_hot[2+3*k] =     uc1[k];
      }
      else
      {
        uc3_hot[0+3*k] =     uc1[k];
        uc3_hot[1+3*k] =     uc1[k];
        uc3_hot[2+3*k] = 3 * uc1[k] - 510;
      }
      k = k + 1;
    }
  }

  return uc3_hot;
}
/******************************************************************************/

unsigned char *uc1_to_uc3_hot2 ( int width, int height, unsigned char *uc1 )

/******************************************************************************/
/*
  Purpose:

    UC1_TO_UC3_HOT2 converts UC1 data to UC3 using a "hot2" scale.

   Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, unsigned char UC1[WIDTH*HEIGHT], gray scale data.

    Output, unsigned char UC1_TO_UC3_HOT[WIDTH*HEIGHT], the rescaled RGB data.
*/
{
  int i;
  int j;
  int k;
  unsigned char *uc3_hot = 
    ( unsigned char * ) malloc ( 3 * width * height * sizeof ( unsigned char ) ); 
 
  k = 0;
  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      if ( uc1[k] < 32 )
      {
        uc3_hot[0+3*k] =            uc1[k];
        uc3_hot[1+3*k] =            uc1[k];
        uc3_hot[2+3*k] =  255 - 8 * uc1[k];
      }
      else if ( uc1[k] < 64 )
      {
        uc3_hot[0+3*k] =            uc1[k];
        uc3_hot[1+3*k] =  511 - 8 * uc1[k];
        uc3_hot[2+3*k] =            uc1[k];
      }
      else if ( uc1[k] < 96 )
      {
        uc3_hot[0+3*k] =  767 - 8 * uc1[k];
        uc3_hot[1+3*k] =            uc1[k];
        uc3_hot[2+3*k] =            uc1[k];
      }
      else if ( uc1[k] < 128 )
      {
        uc3_hot[0+3*k] = 1023 - 8 * uc1[k];
        uc3_hot[1+3*k] =            uc1[k];
        uc3_hot[2+3*k] =            uc1[k];
      }
      else if ( uc1[k] < 192 )
      {
        uc3_hot[0+3*k] =            uc1[k];
        uc3_hot[1+3*k] = 1535 - 8 * uc1[k];
        uc3_hot[2+3*k] =            uc1[k];
      }
      else
      {
        uc3_hot[0+3*k] =            uc1[k];
        uc3_hot[1+3*k] =            uc1[k];
        uc3_hot[2+3*k] = 2047 - 8 * uc1[k];
      }
      k = k + 1;
    }
  }

  return uc3_hot;
}
/******************************************************************************/

unsigned char *ucrgb_to_uc3 ( int width, int height, unsigned char *ucr,
  unsigned char *ucg, unsigned char *ucb )

/******************************************************************************/
/*
  Purpose:

    UCRGB_TO_UC3 combines R, G, B data to single RGB array.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, unsigned char UCR[WIDTH*HEIGHT], UCG[WIDTH*HEIGHT], 
    UCB[WIDTH*HEIGHT], RGB data in unsigned char format, as 3 separate vectors.

    Output, unsigned char UCRGB_TO_UC3[3*WIDTH*HEIGHT], RGB
    data in unsigned char format, as a single array.
*/
{
  int i;
  int j;
  int k;
  unsigned char *uc3 = 
    ( unsigned char* ) malloc ( 3 * width * height * sizeof ( unsigned char ) );
 
  k = 0;

  for ( j = 0; j < height; j++ )
  {
    for ( i = 0; i < width; i++ )
    {
      uc3[0+k*3] = ucr[k];
      uc3[1+k*3] = ucg[k];
      uc3[2+k*3] = ucb[k];
      k = k + 1;
    }
  }

  return uc3;
}
/******************************************************************************/

int write_png_i41 ( char *filename, int width, int height, int *i41 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_I41 writes graphics data in I41 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, int I41[WIDTH*HEIGHT], grayscale data.
*/
{
  int gmax;
  int gmin;
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  gmin = i4vec_min ( width * height, i41 );
  gmax = i4vec_max ( width * height, i41 );

  uc1 = i41_to_uc1 ( width, height, i41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3 ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_i41_hot ( char *filename, int width, int height, int *i41 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_I41_HOT writes graphics data in I41 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, int I41[WIDTH*HEIGHT], grayscale data.
*/
{
  int gmax;
  int gmin;
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  gmin = i4vec_min ( width * height, i41 );
  gmax = i4vec_max ( width * height, i41 );

  uc1 = i41_to_uc1 ( width, height, i41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3_hot ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_i41_hot2 ( char *filename, int width, int height, int *i41 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_I41_HOT2 writes graphics data in I41 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, int I41[WIDTH*HEIGHT], grayscale data.
*/
{
  int gmax;
  int gmin;
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  gmin = i4vec_min ( width * height, i41 );
  gmax = i4vec_max ( width * height, i41 );

  uc1 = i41_to_uc1 ( width, height, i41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3_hot2 ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_r41 ( char *filename, int width, int height, float *r41 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41 writes graphics data in R41 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R41[WIDTH*HEIGHT], grayscale data.
*/
{
  float gmax;
  float gmin;
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  gmin = r4vec_min ( width * height, r41 );
  gmax = r4vec_max ( width * height, r41 );

  uc1 = r41_to_uc1 ( width, height, r41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3 ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_r41_hot ( char *filename, int width, int height, float *r41 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_HOT writes graphics data in R41 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R41[WIDTH*HEIGHT], grayscale data.
*/
{
  float gmax;
  float gmin;
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  gmin = r4vec_min ( width * height, r41 );
  gmax = r4vec_max ( width * height, r41 );

  uc1 = r41_to_uc1 ( width, height, r41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3_hot ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_r41_hot2 ( char *filename, int width, int height, float *r41 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_HOT2 writes graphics data in R41 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R41[WIDTH*HEIGHT], grayscale data.
*/
{
  float gmax;
  float gmin;
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  gmin = r4vec_min ( width * height, r41 );
  gmax = r4vec_max ( width * height, r41 );

  uc1 = r41_to_uc1 ( width, height, r41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3_hot2 ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_r41_trimmed ( char *filename, int width, int height, float *r41,
  float gmin, float gmax )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_TRIMMED writes graphics data in R41 format to a PNG file.

  Discussion:

    The user supplies a range outside of which the data is trimmed.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R41[WIDTH*HEIGHT], grayscale data.

    Input, float GMIN, GMAX, the gray scale values that will correspond
    to output values of 0 and 255, respectively.
*/
{
  unsigned char *uc1;
  unsigned char *uc3;
/*
  Convert floats in [GMIN,GMAX] to unsigned characters in [0,255].
*/
  uc1 = r41_to_uc1 ( width, height, r41, gmin, gmax );
/*
  "Stutter", emitting 3 copies of gray value to make RGB values.
*/
  uc3 = uc1_to_uc3 ( width, height, uc1 );
/*
  Write the file.
*/
  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc1 );
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_r43 ( char *filename, int width, int height, float *r43 )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R43 writes graphics data in R43 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R43[3*WIDTH*HEIGHT], RGB data.
*/
{
  unsigned char *uc3;
  
  uc3 = r43_to_uc3 ( width, height, r43 );

  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_r43_trimmed ( char *filename, int width, int height, float *r43,
  float cmin[3], float cmax[3] )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R43_TRIMMED writes graphics data in R43 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, float R43[3*WIDTH*HEIGHT], RGB data.

    Input, float CMIN[3], CMAX[3], the values of RGB that correspond to
    0 and 255.  Values outside this range are trimmed.
*/
{
  unsigned char *uc3;
  
  uc3 = r43_to_uc3_trimmed ( width, height, r43, cmin, cmax );

  write_png_uc3 ( filename, width, height, uc3, NULL ); 
/*
  Free memory.
*/
  free ( uc3 );

  return 0;
}
/******************************************************************************/

int write_png_uc3 ( char *filename, int width, int height, 
  unsigned char *uc3, unsigned char *alpha )

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_UC3 writes graphics data in UC3 format to a PNG file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2017

  Author:

    Original version by Hari Nair

  Parameters:

    Input, const char *FILENAME, the name of the file to be written.

    Input, int WIDTH, HEIGHT, the width and height of the image in pixels.

    Input, unsigned char UC3[3*WIDTH*HEIGHT], RGB data.

    Input, unsigned char ALPHA[WIDTH*HEIGHT], the alpha channel data.
    This can have the value NULL.
*/
{
  FILE *file;
  int i;
  png_infop info_ptr;
  png_structp png_ptr;
  png_bytep row_ptr;

  file = fopen ( filename, "wb" );

  png_ptr = png_create_write_struct (
    PNG_LIBPNG_VER_STRING, 
    ( png_voidp ) NULL, 
    ( png_error_ptr ) NULL, 
    ( png_error_ptr ) NULL );

  if ( ! png_ptr ) 
  {
    return ( 1 );
  }
 
  info_ptr = png_create_info_struct ( png_ptr );

  if ( ! info_ptr )
  {
    png_destroy_write_struct ( &png_ptr, ( png_infopp ) NULL );
    return ( 1 );
  }
  
  png_init_io ( png_ptr, file );

  if ( alpha == NULL )
  {
    png_set_IHDR ( 
      png_ptr,
      info_ptr,
      width,
      height,
      8,
      PNG_COLOR_TYPE_RGB,
      PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_DEFAULT,
      PNG_FILTER_TYPE_DEFAULT );
      
    png_write_info ( png_ptr, info_ptr );
      
    for ( i = 0; i < height; i++ ) 
    {
      row_ptr = uc3 + 3 * i * width;
      png_write_rows ( png_ptr, &row_ptr, 1 );
    }

  }
  else
  {
    int irgb = 0;
    int irgba = 0;

    int area = width * height;
    unsigned char *uc4 = malloc ( 4 * area );

    png_set_IHDR ( 
      png_ptr,
      info_ptr,
      width,
      height,
      8, 
      PNG_COLOR_TYPE_RGB_ALPHA,
      PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_DEFAULT,
      PNG_FILTER_TYPE_DEFAULT );
      
    png_write_info ( png_ptr, info_ptr );
      
    for ( i = 0; i < area; i++ )
    {
      uc4[irgba++] = uc3[irgb++];
      uc4[irgba++] = uc3[irgb++];
      uc4[irgba++] = uc3[irgb++];
      uc4[irgba++] = alpha[i];
    }
      
    for ( i = 0; i < height; i++ ) 
    {
      row_ptr = uc4 + 4 * i * width;
      png_write_rows ( png_ptr, &row_ptr, 1 );
    }

    free ( uc4 );
  }

  png_write_end ( png_ptr, info_ptr );
  png_destroy_write_struct ( &png_ptr, &info_ptr );

  fclose ( file );

  return ( 0 );
}

