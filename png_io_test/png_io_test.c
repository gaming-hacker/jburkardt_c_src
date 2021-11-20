# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "png_io.h"

int main ( int argc, char *argv[] );
void write_png_i41_test ( );
void write_png_r41_test ( );
void write_png_r41_hot_test ( );
void write_png_r41_hot2_test ( );
void write_png_r41_trimmed_test ( );
void write_png_r43_test ( );
void timestamp ( );
int *i41_example ( int width, int height );
float *r41_example ( int width, int height );
float *r43_example ( int width, int height );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PNG_IO_TEST.

  Discussion:

    PNG_IO_TEST tests the PNG_IO library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "PNG_IO_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the PNG_IO library.\n" );

  write_png_i41_test ( );
  write_png_r41_test ( );
  write_png_r41_hot_test ( );
  write_png_r41_hot2_test ( );
  write_png_r41_trimmed_test ( );
  write_png_r43_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "PNG_IO_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void write_png_i41_test ( )  

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_I41_TEST tests WRITE_PNG_I41.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 May 2017

  Author:

    John Burkardt
*/
{
  char filename[] = "png_i41.png";
  int height = 300;
  int *i41;
  int width = 300;

  printf ( "\n" );
  printf ( "WRITE_PNG_I41_TEST:\n" );
  printf ( "  WRITE_PNG_I41 writes a PNG image of I41 gray scale data.\n" );
  printf ( "\n" );

  i41 = i41_example ( width, height );

  write_png_i41 ( filename, width, height, i41 );
/*
  Free memory.
*/
  free ( i41 );

  return;
}
/******************************************************************************/

void write_png_r41_test ( )  

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_TEST tests WRITE_PNG_R41.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2017

  Author:

    John Burkardt
*/
{
  char filename[] = "png_r41.png";
  int height = 300;
  float *r41;
  int width = 300;

  printf ( "\n" );
  printf ( "WRITE_PNG_R41_TEST:\n" );
  printf ( "  WRITE_PNG_R41 writes a PNG image of R41 gray scale data.\n" );
  printf ( "\n" );

  r41 = r41_example ( width, height );

  write_png_r41 ( filename, width, height, r41 );
/*
  Free memory.
*/
  free ( r41 );

  return;
}
/******************************************************************************/

void write_png_r41_hot_test ( )  

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_HOT_TEST tests WRITE_PNG_R41_HOT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2017

  Author:

    John Burkardt
*/
{
  char filename[] = "png_r41_hot.png";
  int height = 300;
  float *r41;
  int width = 300;

  printf ( "\n" );
  printf ( "WRITE_PNG_R41_HOT_TEST:\n" );
  printf ( "  WRITE_PNG_R41_HOT writes a PNG image of R41 gray scale data\n" );
  printf ( "  with a hot color scheme.\n");
  printf ( "\n" );

  r41 = r41_example ( width, height );

  write_png_r41_hot ( filename, width, height, r41 );
/*
  Free memory.
*/
  free ( r41 );

  return;
}
/******************************************************************************/

void write_png_r41_hot2_test ( )  

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_HOT2_TEST tests WRITE_PNG_R41_HOT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2017

  Author:

    John Burkardt
*/
{
  char filename[] = "png_r41_hot2.png";
  int height = 300;
  float *r41;
  int width = 300;

  printf ( "\n" );
  printf ( "WRITE_PNG_R41_HOT2_TEST:\n" );
  printf ( "  WRITE_PNG_R41_HOT2 writes a PNG image of R41 gray scale data\n" );
  printf ( "  with a hot2 color scheme.\n");
  printf ( "\n" );

  r41 = r41_example ( width, height );

  write_png_r41_hot2 ( filename, width, height, r41 );
/*
  Free memory.
*/
  free ( r41 );

  return;
}
/******************************************************************************/

void write_png_r41_trimmed_test ( )  

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R41_TRIMMED_TEST tests WRITE_PNG_R41_TRIMMED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 May 2017

  Author:

    John Burkardt
*/
{
  char filename[] = "png_r41_trimmed.png";
  float gmax;
  float gmin;
  int height = 300;
  float *r41;
  int width = 300;

  printf ( "\n" );
  printf ( "WRITE_PNG_R41_TRIMMED_TEST:\n" );
  printf ( "  WRITE_PNG_R41_TRIMMED writes a PNG image of R41 gray scale data.\n" );
  printf ( "\n" );

  r41 = r41_example ( width, height );

  gmin = r4vec_min ( width * height, r41 );
  gmax = r4vec_max ( width * height, r41 );
  printf ( "  Data range is [%g,%g]\n", gmin, gmax );

  gmin = 0.3;
  gmax = 0.7;
  printf ( "  Data will be trimmed outside the range [%g,%g]\n", gmin, gmax );
  write_png_r41_trimmed ( filename, width, height, r41, gmin, gmax );
/*
  Free memory.
*/
  free ( r41 );

  return;
}
/******************************************************************************/

void write_png_r43_test ( )  

/******************************************************************************/
/*
  Purpose:

    WRITE_PNG_R43_TEST tests WRITE_PNG_R43.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 May 2017

  Author:

    John Burkardt
*/
{
  char filename[] = "png_r43.png";
  int height = 300;
  float *r43;
  int width = 300;

  printf ( "\n" );
  printf ( "WRITE_PNG_R43_TEST:\n" );
  printf ( "  WRITE_PNG_R43 writes R43 data to a PNG file.\n" );
  printf ( "\n" );

  r43 = r43_example ( width, height );
  printf ( "  R43_EXAMPLE has set up the R43 data.\n" );

  write_png_r43 ( filename, width, height, r43 );
/*
  Free memory.
*/
  free ( r43 );

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
/******************************************************************************/

int *i41_example ( int width, int height )

/******************************************************************************/
/*
  Purpose:

    I41_EXAMPLE sets up I41 data for a grayscale image.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the number of rows and columns of data.

    Output, int *I41_EXAMPLE[WIDTH*HEIGHT], the array of width by height gray values.
*/
{
  int i;
  int *i41;
  int j;
  int k;
  float r;
  const float r4_pi = 3.141592653589793;
  float t;
  float x;
  float y;

  i41 = ( int * ) malloc ( width * height * sizeof ( int ) );

  k = 0;

  for ( i = 0; i < height; i++ )
  {
    y = ( ( float ) ( 2 * i ) ) / ( ( float ) ( height - 1 ) ) - 1.0;

    for ( j = 0; j < width; j++ )
    {
      x = ( ( float ) ( 2 * j ) ) / ( ( float ) ( width - 1 ) ) - 1.0;

      t = 10.0 * ( atan2 ( y, x ) + r4_pi ) / r4_pi;
      r = sqrt ( x * x + y * y ) / sqrt ( 2.0 );

      i41[k] = ( int ) ( 50 * ( fmod ( t, 1.0 ) + fmod ( r, 1.0 ) ) );
      k = k + 1;
    }
  }

  return i41;
}
/******************************************************************************/

float *r41_example ( int width, int height )

/******************************************************************************/
/*
  Purpose:

    R41_EXAMPLE sets up R41 data for a grayscale image.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 April 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the number of rows and columns of data.

    Output, float *R41_EXAMPLE[WIDTH*HEIGHT], the array of width by height gray values.
*/
{
  int i;
  int j;
  int k;
  float r;
  const float r4_pi = 3.141592653589793;
  float *r41;
  float t;
  float x;
  float y;

  r41 = ( float * ) malloc ( width * height * sizeof ( float ) );

  k = 0;

  for ( i = 0; i < height; i++ )
  {
    y = ( ( float ) ( 2 * i ) ) / ( ( float ) ( height - 1 ) ) - 1.0;

    for ( j = 0; j < width; j++ )
    {
      x = ( ( float ) ( 2 * j ) ) / ( ( float ) ( width - 1 ) ) - 1.0;

      t = 10.0 * ( atan2 ( y, x ) + r4_pi ) / r4_pi;
      r = sqrt ( x * x + y * y ) / sqrt ( 2.0 );

      r41[k] = ( fmod ( t, 1.0 ) + fmod ( r, 1.0 ) ) / 2.0;
      k = k + 1;
    }
  }

  return r41;
}
/******************************************************************************/

float *r43_example ( int width, int height )

/******************************************************************************/
/*
  Purpose:

    R43_EXAMPLE sets up R43 data for an RGB image.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 April 2017

  Author:

    John Burkardt

  Parameters:

    Input, int WIDTH, HEIGHT, the number of rows and columns of data.

    Output, float R43_EXAMPLE[3*WIDTH*HEIGHT], the RGB values.
*/
{
  float b;
  float g;
  int i;
  int j;
  int k;
  float r;
  const float r4_pi = 3.141592653589793;
  float *r43;
  float x;
  float y;

  r43 = ( float * ) malloc ( 3 * width * height * sizeof ( float ) );

  k = 0;

  for ( i = 0; i < height; i++ )
  {
    y = ( float ) ( height + 1 - i ) / ( float ) ( height - 1 );
    for ( j = 0; j < width; j++ )
    {
      x = ( float ) ( j ) / ( float ) ( width - 1 );

      r = 4.0 * ( x - 0.5 ) * ( x - 0.5 );
      g = sin ( r4_pi * x );
      b = x;

      if ( y <= r )
      {
        r43[k] = r;
      }
      else
      {
        r43[k] = 50.0;
        r43[k] = y;
      }
      k = k + 1;

      if ( y <= g )
      {
        r43[k] = g;
      }
      else
      {
        r43[k] = 150.0;
        r43[k] = y;
      }
      k = k + 1;

      if ( y <= b )
      {
        r43[k] = b;
      }
      else
      {
        r43[k] = 250.0;
        r43[k] = y;
      }
      k = k + 1;
    }
  }

  return r43;
}
