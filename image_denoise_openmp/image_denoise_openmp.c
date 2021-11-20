# include <omp.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int main ( int argc, char *argv[] );
int int_cmp ( const void * pointer1, const void * pointer2 );
void median_news_filter ( int m, int n, int color[] );
void ppma_read_data ( FILE *input, int xsize, int ysize, int *r, int *g, int *b );
void ppma_read_header ( FILE *input, int *xsize, int *ysize, int *rgb_max );
int ppma_write ( char *file_out_name, int xsize, int ysize, int *r,
  int *g, int *b );
int ppma_write_data ( FILE *file_out, int xsize, int ysize, int *r,
  int *g, int *b );
int ppma_write_header ( FILE *file_out, char *file_out_name, int xsize,
  int ysize, int rgb_max );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for IMAGE_DENOISE_OPENMP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 March 2017

  Author:

    John Burkardt
*/
{
  int *b;
  int *g;
  char input_filename[] = "balloons_noisy.ppm";
  FILE *input_unit;
  int m;
  int n;
  char output_filename[] = "balloons_median.ppm";
  int *r;
  int rgb_max;

  printf ( "\n" );
  printf ( "IMAGE_DENOISE_OPENMP\n" );
  printf ( "  C version\n" );
  printf ( "  Remove noise from an image.\n" );
/*
  Open the input file and read the data.
*/
  input_unit = fopen ( input_filename, "r" );

  if ( ! input_unit )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "IMAGE_DENOISE_OPENMP - Fatal error!\n" );
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
/*
  Filter the file.
*/
  median_news_filter ( m, n, r );
  median_news_filter ( m, n, g );
  median_news_filter ( m, n, b );
/*
  Write the filtered image.
*/
  ppma_write ( output_filename, m, n, r, g, b );

  printf ( "\n" );
  printf ( "  Wrote denoised image to \"%s\".\n", output_filename );
/*
  Free memory.
*/
  free ( r );
  free ( g );
  free ( b );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "IMAGE_DENOISE_OPENMP\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
/******************************************************************************/

void median_news_filter ( int m, int n, int color[] )

/******************************************************************************/
/*
  Purpose:

    MEDIAN_NEWS_FILTER uses a median NEWS filter on a single color array.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 March 2017

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of pixels.

    Input/output, int COLOR[M*N], the color data.  On output, the data
    in the image interior has been filtered.
*/
{
  int *color2;
  int i;
  int j;
  int p[5];

  color2 = ( int * ) malloc ( m * n * sizeof ( int ) );
/*
  Process the main part of the image.
  Ignore edges and corners.
*/
# pragma omp parallel \
  private ( i, j, p ) \
  shared ( color, color2, m, n )
{
# pragma omp for

  for ( i = 1; i < m - 1; i++ )
  {
    for ( j = 1; j < n - 1; j++ )
    {
      p[0] = color[i-1+ j   *m];
      p[1] = color[i+1+ j   *m];
      p[2] = color[i  +(j+1)*m];
      p[3] = color[i  +(j-1)*m];
      p[4] = color[i  + j   *m];

      qsort ( p, 5, sizeof ( int ), int_cmp );

      color2[i+j*m] = p[2];
    }
  }
}
/*
  Overwrite old data.
*/
# pragma omp parallel \
  private ( i, j ) \
  shared ( color, color2, m, n )
{
# pragma omp for

  for ( i = 1; i < m - 1; i++ )
  {
    for ( j = 1; j < n - 1; j++ )
    {
      color[i+j*m] = color2[i+j*m];
    }
  }
}
/*
  Free memory.
*/
  free ( color2 );

  return;
}
/******************************************************************************/

int int_cmp ( const void * pointer1, const void * pointer2 )

/******************************************************************************/
/*
  Purpose:

    INT_CMP is used by QSORT to compare two integers.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 March 2017

  Author:

    John Burkardt

  Parameters:

    Input, const void * POINTER1, POINTER2, pointers to two integers.

    Output, int INT_CMP, -1, 0, or +1, as the first item is less than,
    equal to, or greater than the second.
*/
{
  int a;
  int b;
  int value;
  a = * ( ( int * ) pointer1 );
  b = * ( ( int * ) pointer2 );

  if ( a < b )
  {
    value = -1;
  }
  else if ( a == b )
  {
    value = 0;
  }
  else
  {
    value = +1;
  }

  return value;
}
/******************************************************************************/

void ppma_read_data ( FILE *input, int xsize, int ysize, int *r, int *g, int *b )

/******************************************************************************/
/*
  Purpose:

    PPMA_READ_DATA reads the data in an ASCII portable pixel map file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, FILE *INPUT, a pointer to the file containing the ASCII
    portable pixel map data.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Output, int *R, *G, *B, the arrays of XSIZE by YSIZE data values.
*/
{
  int i;
  int j;
  int n;
  int p;

  p = 0;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      n = fscanf ( input, "%d %d %d", r, g, b );

      if ( n != 3 )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "PPMA_READ_DATA - Fatal error!\n" );
        fprintf ( stderr, "  Unable to read data.\n" );
        fprintf ( stderr, "  FSCANF returns N = %d\n", n );
        fprintf ( stderr, "  Number of pixels already read is %d\n", p );
        exit ( 1 );
      }
      p = p + 1;
      r = r + 1;
      g = g + 1;
      b = b + 1;
    }
  }
  return;
}
/******************************************************************************/

void ppma_read_header ( FILE *input, int *xsize, int *ysize, int *rgb_max )

/******************************************************************************/
/*
  Purpose:

    PPMA_READ_HEADER reads the header of an ASCII portable pixel map file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, FILE *INPUT, a pointer to the file containing the ASCII
    portable pixel map data.

    Output, int *XSIZE, *YSIZE, the number of rows and columns of data.

    Output, int *RGB_MAX, the maximum RGB value.
*/
{
# define LINE_MAX 255

  int count;
  char *error;
  char line[LINE_MAX];
  char *next;
  int step;
  int width;
  char word[LINE_MAX];

  step = 0;

  while ( 1 )
  {
    error = fgets ( line, LINE_MAX, input );

    if ( !error )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "PGMA_READ_HEADER - Fatal error!\n" );
      fprintf ( stderr, "  End of file.\n" );
      exit ( 1 );
    }

    next = line;

    if ( line[0] == '#' )
    {
      continue;
    }

    if ( step == 0 )
    {
      count = sscanf ( next, "%s%n", word, &width );
      if ( count == EOF )
      {
        continue;
      }
      next = next + width;
      if ( strcmp ( word, "P3" ) != 0 && strcmp ( word, "p3" ) != 0 )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "PPMA_READ_HEADER - Fatal error.\n" );
        fprintf ( stderr, "  Bad magic number = \"%s\".\n", word );
        exit ( 1 );
      }
      step = 1;
    }

    if ( step == 1 )
    {

      count = sscanf ( next, "%d%n", xsize, &width );
      next = next + width;
      if ( count == EOF )
      {
        continue;
      }
      step = 2;
    }

    if ( step == 2 )
    {
      count = sscanf ( next, "%d%n", ysize, &width );
      next = next + width;
      if ( count == EOF )
      {
        continue;
      }
      step = 3;
    }

    if ( step == 3 )
    {
      count = sscanf ( next, "%d%n", rgb_max, &width );
      next = next + width;
      if ( count == EOF )
      {
        continue;
      }
      break;
    }

  }

  return;
# undef LINE_MAX
}

/******************************************************************************/

int ppma_write ( char *file_out_name, int xsize, int ysize, int *r,
  int *g, int *b )

/******************************************************************************/
/*
  Purpose:

    PPMA_WRITE writes the header and data for an ASCII portable pixel map file.

  Example:

    P3
    # feep.ppm
    4 4
    15
     0  0  0    0  0  0    0  0  0   15  0 15
     0  0  0    0 15  7    0  0  0    0  0  0
     0  0  0    0  0  0    0 15  7    0  0  0
    15  0 15    0  0  0    0  0  0    0  0  0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 February 2003

  Author:

    John Burkardt

  Parameters:

    Input, char *FILE_OUT_NAME, the name of the file to contain the ASCII
    portable pixel map data.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int *R, *G, *B, the arrays of XSIZE by YSIZE data values.

    Output, int PPMA_WRITE, is
    true, if an error was detected, or
    false, if the file was written.
*/
{
  int *b_index;
  int error;
  FILE *file_out;
  int *g_index;
  int i;
  int j;
  int *r_index;
  int rgb_max;
/*
  Open the output file.
*/
  file_out = fopen ( file_out_name, "wt" );

  if ( !file_out )
  {
    printf ( "\n" );
    printf ( "PPMA_WRITE - Fatal error!\n" );
    printf ( "  Cannot open the output file \"%s\".\n", file_out_name );
    return 1;
  }
/*
  Compute the maximum.
*/
  rgb_max = 0;
  r_index = r;
  g_index = g;
  b_index = b;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      if ( rgb_max < *r_index )
      {
        rgb_max = *r_index;
      }
      r_index = r_index + 1;

      if ( rgb_max < *g_index )
      {
        rgb_max = *g_index;
      }
      g_index = g_index + 1;

      if ( rgb_max < *b_index )
      {
        rgb_max = *b_index;
      }
      b_index = b_index + 1;
    }
  }
/*
  Write the header.
*/
  error = ppma_write_header ( file_out, file_out_name, xsize, ysize, rgb_max );

  if ( error )
  {
    printf ( "\n" );
    printf ( "PPMA_WRITE - Fatal error!\n" );
    printf ( "  PPMA_WRITE_HEADER failed.\n" );
    return 1;
  }
/*
  Write the data.
*/
  error = ppma_write_data ( file_out, xsize, ysize, r, g, b );

  if ( error )
  {
    printf ( "\n" );
    printf ( "PPMA_WRITE - Fatal error!\n" );
    printf ( "  PPMA_WRITE_DATA failed.\n" );
    return 1;
  }
/*
  Close the file.
*/
  fclose ( file_out );

  return 0;
}
/******************************************************************************/

int ppma_write_data ( FILE *file_out, int xsize, int ysize, int *r,
  int *g, int *b )

/******************************************************************************/
/*
  Purpose:

    PPMA_WRITE_DATA writes the data for an ASCII portable pixel map file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 February 2003

  Author:

    John Burkardt

  Parameters:

    Input, ofstream &FILE_OUT, a pointer to the file to contain the ASCII
    portable pixel map data.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int *R, *G, *B, the arrays of XSIZE by YSIZE data values.

    Output, int PPMA_WRITE_DATA, is
    true, if an error was detected, or
    false, if the data was written.
*/
{
  int *b_index;
  int *g_index;
  int i;
  int j;
  int *r_index;
  int rgb_num;

  r_index = r;
  g_index = g;
  b_index = b;
  rgb_num = 0;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      fprintf ( file_out, "%d  %d  %d", *r_index, *g_index, *b_index );
      rgb_num = rgb_num + 3;
      r_index = r_index + 1;
      g_index = g_index + 1;
      b_index = b_index + 1;

      if ( rgb_num % 12 == 0 || i == xsize - 1 || rgb_num == 3 * xsize * ysize )
      {
        fprintf ( file_out, "\n" );
      }
      else
      {
        fprintf ( file_out, " " );
      }
    }
  }
  return 0;
}
/******************************************************************************/

int ppma_write_header ( FILE *file_out, char *file_out_name, int xsize,
  int ysize, int rgb_max )

/******************************************************************************/
/*
  Purpose:

    PPMA_WRITE_HEADER writes the header of an ASCII portable pixel map file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 February 2003

  Author:

    John Burkardt

  Parameters:

    Input, FILE *FILE_OUT, a pointer to the file to contain the ASCII
    portable pixel map data.

    Input, char *FILE_OUT_NAME, the name of the file.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int RGB_MAX, the maximum RGB value.

    Output, int PPMA_WRITE_HEADER, is
    true, if an error was detected, or
    false, if the header was written.
*/
{
  fprintf ( file_out, "P3\n" );
  fprintf ( file_out, "# %s created by ppma_write.c.\n", file_out_name );
  fprintf ( file_out, "%d  %d\n", xsize, ysize );
  fprintf ( file_out, "%d\n", rgb_max );

  return 0;
}

