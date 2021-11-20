# include <stdlib.h>
# include <stdio.h>

# include "image_denoise.h"

int main ( int argc, char *argv[] );
void gray_mean_news_test ( );
void gray_median_news_test ( );
void rgb_median_news_test ( char *input_filename, char *output_filename );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for IMAGE_DENOISE_TEST.

  Discussion:

    IMAGE_DENOISE_TEST tests the IMAGE_DENOISE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 February 2012

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "IMAGE_DENOISE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the IMAGE_DENOISE library.\n" );

  gray_mean_news_test ( );
  gray_median_news_test ( );
  rgb_median_news_test ( "balloons_noisy.ascii.ppm", "balloons_median_news.ascii.ppm" );
  rgb_median_news_test ( "balloons_median_news.ascii.ppm", "balloons_median_news2.ascii.ppm" );
  rgb_median_news_test ( "balloons_median_news2.ascii.ppm", "balloons_median_news3.ascii.ppm" );
  rgb_median_news_test ( "balloons_median_news3.ascii.ppm", "balloons_median_news4.ascii.ppm" );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "IMAGE_DENOISE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void gray_mean_news_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_MEAN_NEWS tests GRAY_MEAN_NEWS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 March 2017

  Author:

    John Burkardt
*/
{
  int *g;
  int g_max;
  int *g2;
  char input_filename[80] = "glassware_noisy.ascii.pgm";
  FILE *input_unit;
  int m;
  int n;
  char output_filename[80] = "glassware_mean_news.ascii.pgm";

  printf ( "\n" );
  printf ( "GRAY_MEAN_NEWS_TEST:\n" );
  printf ( "  GRAY_MEAN_NEWS uses a NEWS median filter \n" );
  printf ( "  on a noisy grayscale image.\n" );

  printf ( "\n" );
  printf ( "  The input file is \"%s\".\n", input_filename );
/*
  Open the input file and read the data.
*/
  input_unit = fopen ( input_filename, "r" );

  if ( !input_unit )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "GRAY_MEAN_NEWS_TEST - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the file \"%s\"\n", input_filename );
    exit ( 1 );
  }

  pgma_read_header ( input_unit, &m, &n, &g_max );

  printf ( "\n" );
  printf ( "  Number of rows =          %d\n", m );
  printf ( "  Number of columns =       %d\n", n );
  printf ( "  Maximum pixel intensity = %d\n", g_max );

  g = ( int * ) malloc ( m * n * sizeof ( int ) );

  pgma_read_data ( input_unit, m, n, g );

  fclose ( input_unit );

  g2 = gray_mean_news ( m, n, g );
/*
  Write the denoised images.
*/
  pgma_write ( output_filename, m, n, g2 );

  printf ( "\n" );
  printf ( "  Wrote denoised image to \"%s\".\n", output_filename );

  free ( g );
  free ( g2 );

  return;
}
/******************************************************************************/

void gray_median_news_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_MEDIAN_NEWS tests GRAY_MEDIAN_NEWS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 February 2012

  Author:

    John Burkardt
*/
{
  int *g;
  int g_max;
  int *g2;
  char input_filename[80] = "glassware_noisy.ascii.pgm";
  FILE *input_unit;
  int m;
  int n;
  char output_filename[80] = "glassware_median_news.ascii.pgm";

  printf ( "\n" );
  printf ( "GRAY_MEDIAN_NEWS_TEST:\n" );
  printf ( "  GRAY_MEDIAN_NEWS uses a NEWS median filter \n" );
  printf ( "  on a noisy grayscale image.\n" );

  printf ( "\n" );
  printf ( "  The input file is \"%s\".\n", input_filename );
/*
  Open the input file and read the data.
*/
  input_unit = fopen ( input_filename, "r" );

  if ( !input_unit )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "GRAY_MEDIAN_NEWS_TEST - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the file \"%s\"\n", input_filename );
    exit ( 1 );
  }

  pgma_read_header ( input_unit, &m, &n, &g_max );

  printf ( "\n" );
  printf ( "  Number of rows =          %d\n", m );
  printf ( "  Number of columns =       %d\n", n );
  printf ( "  Maximum pixel intensity = %d\n", g_max );

  g = ( int * ) malloc ( m * n * sizeof ( int ) );

  pgma_read_data ( input_unit, m, n, g );

  fclose ( input_unit );

  g2 = gray_median_news ( m, n, g );
/*
  Write the denoised images.
*/
  pgma_write ( output_filename, m, n, g2 );

  printf ( "\n" );
  printf ( "  Wrote denoised image to \"%s\".\n", output_filename );

  free ( g );
  free ( g2 );

  return;
}
/******************************************************************************/

void rgb_median_news_test ( char *input_filename, char *output_filename )

/******************************************************************************/
/*
  Purpose:

   RGB_MEDIAN_NEWS tests RGB_MEDIAN_NEWS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 March 2017

  Author:

    John Burkardt
*/
{
  int *b;
  int *g;
/*
  char input_filename[] = "balloons_noisy.ascii.ppm";
  char input_filename[] = "balloons_median_news.ascii.ppm";
*/
  FILE *input_unit;
  int m;
  int n;
/*
  char output_filename[] = "balloons_median_news.ascii.ppm";
  char output_filename[] = "balloons_median_news2.ascii.ppm";
*/
  int *r;
  int rgb_max;

  printf ( "\n" );
  printf ( "RGB_MEDIAN_NEWS_TEST:\n" );
  printf ( "  RGB_MEDIAN_NEWS uses a NEWS median filter \n" );
  printf ( "  on a noisy RGB image.\n" );

  printf ( "\n" );
  printf ( "  The input file is \"%s\".\n", input_filename );
/*
  Open the input file and read the data.
*/
  input_unit = fopen ( input_filename, "r" );

  if ( !input_unit )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "RGB_MEDIAN_NEWS_TEST - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the file \"%s\"\n", input_filename );
    exit ( 1 );
  }

  ppma_read_header ( input_unit, &m, &n, &rgb_max );

  printf ( "\n" );
  printf ( "  Number of rows =          %d\n", m );
  printf ( "  Number of columns =       %d\n", n );
  printf ( "  Maximum pixel intensity = %d\n", rgb_max );

  r = ( int * ) malloc ( m * n * sizeof ( int ) );
  g = ( int * ) malloc ( m * n * sizeof ( int ) );
  b = ( int * ) malloc ( m * n * sizeof ( int ) );

  ppma_read_data ( input_unit, m, n, r, g, b );

  fclose ( input_unit );

  rgb_median_news ( m, n, r, g, b );
/*
  Write the denoised images.
*/
  ppma_write ( output_filename, m, n, r, g, b );

  printf ( "\n" );
  printf ( "  Wrote denoised image to \"%s\".\n", output_filename );

  free ( r );
  free ( g );
  free ( b );

  return;
}

