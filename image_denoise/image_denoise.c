# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "image_denoise.h"

/******************************************************************************/

int *gray_mean_news ( int m, int n, int gray[] )

/******************************************************************************/
/*
  Purpose:

    GRAY_MEAN_NEWS uses a mean NEWS filter on a gray scale image to remove noise.

  Discussion:

    We don't expect the MEAN filter to do very well for noise!

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 March 2017

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of pixels.

    Input, int GRAY[M*N], the noisy grayscale data.

    Output, int GRAY_MEAN_NEWS[M*N], the grayscale data for the filtered image.
*/
{
  int *gray2;
  int i;
  int j;
  int p[5];

  gray2 = ( int * ) malloc ( m * n * sizeof ( int ) );
/*
  Process the main part of the image:
*/
  for ( i = 1; i < m - 1; i++ )
  {
    for ( j = 1; j < n - 1; j++ )
    {
      p[0] = gray[i-1+ j   *m];
      p[1] = gray[i+1+ j   *m];
      p[2] = gray[i  +(j+1)*m];
      p[3] = gray[i  +(j-1)*m];
      p[4] = gray[i  + j   *m];

      gray2[i+j*m] = i4vec_mean_i4 ( 5, p );
    }
  }
/*
  Process the four borders.
  Get an odd number of data points, 
*/
  for ( i = 1; i < m - 1; i++ )
  {
    j = 0;
    p[0] = gray[i-1+ j   *m];
    p[1] = gray[i+1+ j   *m];
    p[2] = gray[i  + j   *m];
    p[3] = gray[i  +(j+1)*m];
    p[4] = gray[i  +(j+2)*m];
    gray2[i+j*m] = i4vec_mean_i4 ( 5, p );

    j = n - 1;
    p[0] = gray[i-1+ j   *m];
    p[1] = gray[i+1+ j   *m];
    p[2] = gray[i  +(j-2)*m];
    p[3] = gray[i  +(j-1)*m];
    p[4] = gray[i  + j   *m];
    gray2[i+j*m] = i4vec_mean_i4 ( 5, p );
  }

  for ( j = 1; j < n - 1; j++ )
  {
    i = 0;
    p[0] = gray[i  + j   *m];
    p[1] = gray[i+1+ j   *m];
    p[2] = gray[i+2+ j   *m];
    p[3] = gray[i  +(j-1)*m];
    p[4] = gray[i  +(j+1)*m];
    gray2[i+j*m] = i4vec_mean_i4 ( 5, p );

    i = m - 1;
    p[0] = gray[i-2+ j   *m];
    p[1] = gray[i-1+ j   *m];
    p[2] = gray[i  + j   *m];
    p[3] = gray[i  +(j-1)*m];
    p[4] = gray[i  +(j+1)*m];
    gray2[i+j*m] = i4vec_mean_i4 ( 5, p );
  }
/*
  Process the four corners.
*/
  i = 0;
  j = 0;
  p[0] = gray[i+1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j+1)*m];
  gray2[i+j*m] = i4vec_mean_i4 ( 3, p );

  i = 0;
  j = n - 1;
  p[0] = gray[i+1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j-1)*m];
  gray2[i+j*m] = i4vec_mean_i4 ( 3, p );

  i = m - 1;
  j = 0;
  p[0] = gray[i-1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j+1)*m];
  gray2[i+j*m] = i4vec_mean_i4 ( 3, p );

  i = m - 1;
  j = n - 1;
  p[0] = gray[i-1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j-1)*m];
  gray2[i+j*m] = i4vec_mean_i4 ( 3, p );

  return gray2;
}
/******************************************************************************/

int *gray_median_news ( int m, int n, int gray[] )

/******************************************************************************/
/*
  Purpose:

    GRAY_MEDIAN_NEWS uses a median NEWS filter on a gray scale image to remove noise.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of pixels.

    Input, int GRAY[M*N], the noisy grayscale data.

    Output, int GRAY_MEDIAN_NEWS[M*N], the grayscale data for the filtered image.
*/
{
  int *gray2;
  int i;
  int j;
  int p[5];

  gray2 = ( int * ) malloc ( m * n * sizeof ( int ) );
/*
  Process the main part of the image:
*/
  for ( i = 1; i < m - 1; i++ )
  {
    for ( j = 1; j < n - 1; j++ )
    {
      p[0] = gray[i-1+ j   *m];
      p[1] = gray[i+1+ j   *m];
      p[2] = gray[i  +(j+1)*m];
      p[3] = gray[i  +(j-1)*m];
      p[4] = gray[i  + j   *m];

      gray2[i+j*m] = i4vec_median ( 5, p );
    }
  }
/*
  Process the four borders.
  Get an odd number of data points, 
*/
  for ( i = 1; i < m - 1; i++ )
  {
    j = 0;
    p[0] = gray[i-1+ j   *m];
    p[1] = gray[i+1+ j   *m];
    p[2] = gray[i  + j   *m];
    p[3] = gray[i  +(j+1)*m];
    p[4] = gray[i  +(j+2)*m];
    gray2[i+j*m] = i4vec_median ( 5, p );

    j = n - 1;
    p[0] = gray[i-1+ j   *m];
    p[1] = gray[i+1+ j   *m];
    p[2] = gray[i  +(j-2)*m];
    p[3] = gray[i  +(j-1)*m];
    p[4] = gray[i  + j   *m];
    gray2[i+j*m] = i4vec_median ( 5, p );
  }

  for ( j = 1; j < n - 1; j++ )
  {
    i = 0;
    p[0] = gray[i  + j   *m];
    p[1] = gray[i+1+ j   *m];
    p[2] = gray[i+2+ j   *m];
    p[3] = gray[i  +(j-1)*m];
    p[4] = gray[i  +(j+1)*m];
    gray2[i+j*m] = i4vec_median ( 5, p );

    i = m - 1;
    p[0] = gray[i-2+ j   *m];
    p[1] = gray[i-1+ j   *m];
    p[2] = gray[i  + j   *m];
    p[3] = gray[i  +(j-1)*m];
    p[4] = gray[i  +(j+1)*m];
    gray2[i+j*m] = i4vec_median ( 5, p );
  }
/*
  Process the four corners.
*/
  i = 0;
  j = 0;
  p[0] = gray[i+1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j+1)*m];
  gray2[i+j*m] = i4vec_median ( 3, p );

  i = 0;
  j = n - 1;
  p[0] = gray[i+1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j-1)*m];
  gray2[i+j*m] = i4vec_median ( 3, p );

  i = m - 1;
  j = 0;
  p[0] = gray[i-1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j+1)*m];
  gray2[i+j*m] = i4vec_median ( 3, p );

  i = m - 1;
  j = n - 1;
  p[0] = gray[i-1+ j   *m];
  p[1] = gray[i  + j   *m];
  p[2] = gray[i  +(j-1)*m];
  gray2[i+j*m] = i4vec_median ( 3, p );

  return gray2;
}
/******************************************************************************/

void i4mat_copy ( int m, int n, int a1[], int a2[] )

/******************************************************************************/
/*
  Purpose:

    I4MAT_COPY copies one I4MAT to another.

  Discussion:

    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, int A1[M*N], the matrix to be copied.

    Output, int A2[M*N], the copy of A1.
*/
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }
  return;
}
/******************************************************************************/

int i4vec_frac ( int n, int a[], int k )

/******************************************************************************/
/*
  Purpose:

    I4VEC_FRAC searches for the K-th smallest entry in an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

    Hoare's algorithm is used.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 September 2005

  Parameters:

    Input, int N, the number of elements of A.

    Input/output, int A[N].
    On input, A is the array to search.
    On output, the elements of A have been somewhat rearranged.

    Input, int K, the fractile to be sought.  If K = 1, the minimum
    entry is sought.  If K = N, the maximum is sought.  Other values
    of K search for the entry which is K-th in size.  K must be at
    least 1, and no greater than N.

    Output, double I4VEC_FRAC, the value of the K-th fractile of A.
*/
{
  int frac;
  int i;
  int iryt;
  int j;
  int left;
  int temp;
  int x;

  if ( n <= 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4VEC_FRAC - Fatal error!\n" );
    fprintf ( stderr, "  Illegal nonpositive value of N = %d\n", n );
    exit ( 1 );
  }

  if ( k <= 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4VEC_FRAC - Fatal error!\n" );
    fprintf ( stderr, "  Illegal nonpositive value of K = %d\n", k );
    exit ( 1 );
  }

  if ( n < k )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4VEC_FRAC - Fatal error!\n" );
    fprintf ( stderr, "  Illegal N < K, K = %d\n", k );
    exit ( 1 );
  }

  left = 1;
  iryt = n;

  for ( ; ; )
  {
    if ( iryt <= left )
    {
      frac = a[k-1];
      break;
    }

    x = a[k-1];
    i = left;
    j = iryt;

    for ( ; ; )
    {
      if ( j < i )
      {
        if ( j < k )
        {
          left = i;
        }
        if ( k < i )
        {
          iryt = j;
        }
        break;
      }
/*
  Find I so that X <= A(I).
*/
      while ( a[i-1] < x )
      {
        i = i + 1;
      }
/*
  Find J so that A(J) <= X.
*/
      while ( x < a[j-1] )
      {
        j = j - 1;
      }

      if ( i <= j )
      {
        temp   = a[i-1];
        a[i-1] = a[j-1];
        a[j-1] = temp;
        i = i + 1;
        j = j - 1;
      }
    }
  }

  return frac;
}
/******************************************************************************/

int i4vec_mean_i4 ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_mean_i4 returns the integer mean of an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 March 2016


  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of elements of A.

    Input/output, int A[N], the array to search. 

    Output, int I4VEC_mean_i4, the value of the integer mean of A.
*/
{
  int i;
  double r;
  int s;

  s = 0;
  for ( i = 0; i < n; i++ )
  {
    s = s + a[i];
  }
  if ( 0 < n )
  {
    r = ( double ) ( s ) / ( double ) ( n );
    s = round ( r );
  }

  return s;
}
/******************************************************************************/

int i4vec_median ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_MEDIAN returns the median of an unsorted I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

    Hoare's algorithm is used.  The values of the vector are
    rearranged by this routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 September 2005

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of elements of A.

    Input/output, int A[N], the array to search.  On output,
    the order of the elements of A has been somewhat changed.

    Output, int I4VEC_MEDIAN, the value of the median of A.
*/
{
  int k;
  int median;
/*
  i4vec_sort_bubble_a ( n, a );
  k = ( n + 1 ) / 2 - 1;
  median = a[k];
*/
  k = ( n + 1 ) / 2;

  median = i4vec_frac ( n, a, k );

  return median;
}
/******************************************************************************/

void i4vec_sort_bubble_a ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_SORT_BUBBLE_A ascending sorts an I4VEC using bubble sort.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, length of input array.

    Input/output, int A[N].
    On input, an unsorted array of ints.
    On output, A has been sorted.
*/
{
  int i;
  int j;
  int temp;

  for ( i = 0; i < n - 1; i++ )
  {
    for ( j = i + 1; j < n; j++ )
    {
      if ( a[j] < a[i] )
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  return;
}
/******************************************************************************/

void pgma_read_data ( FILE *file_in, int xsize, int ysize, int *g )

/******************************************************************************/
/*
  Purpose:

    PGMA_READ_DATA reads the data in an ASCII PGM file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, FILE *FILE_IN, a pointer to the file containing the data.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Output, int *G, the array of XSIZE by YSIZE data values.
*/
{
  int i;
  int j;
  int n;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      n = fscanf ( file_in, "%d", g );

      if ( n != 1 )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "PGMA_READ_DATA - Fatal error!\n" );
        fprintf ( stderr, "  Unable to read data.\n" );
        exit ( 1 );
      }
      g = g + 1;
    }
  }
  return;
}
/******************************************************************************/

void pgma_read_header ( FILE *file_in, int *xsize, int *ysize, int *maxg )

/******************************************************************************/
/*
  Purpose:

    PGMA_READ_HEADER reads the header of an ASCII PGM file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, FILE *FILE_IN, a pointer to the file.

    Output, int *XSIZE, *YSIZE, the number of rows and columns of data.

    Output, int *MAXG, the maximum gray value.
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
    error = fgets ( line, LINE_MAX, file_in );

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
      if ( strcmp ( word, "P2" ) != 0 && strcmp ( word, "p2" ) != 0 )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "PGMA_READ_HEADER - Fatal error.\n" );
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
      count = sscanf ( next, "%d%n", maxg, &width );
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

void pgma_write ( char *file_out_name, int xsize, int ysize, int *g )

/******************************************************************************/
/*
  Purpose:

    PGMA_WRITE writes the header and data for an ASCII PGM file.
 
  Example:

    P2
    # feep.pgm
    24 7
    15
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
    0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
    0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
    0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
    0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:
 
    05 June 2010
 
  Author:
 
    John Burkardt

  Parameters:

    Input, char *FILE_OUT_NAME, the name of the file.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int *G, the array of XSIZE by YSIZE data values.
*/
{
  FILE *file_out;
  int i;
  int *indexg;
  int j;
  int maxg;
/*
  Open the output file.
*/
  file_out = fopen ( file_out_name, "wt" );

  if ( !file_out )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "PGMA_WRITE - Fatal error!\n" );
    fprintf ( stderr, "  Cannot open the output file \"%s\".\n", file_out_name );
    exit ( 1 );
  }
/*
  Compute the maximum.
*/
  maxg = 0;
  indexg = g;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      if ( maxg < *indexg )
      {
        maxg = *indexg;
      }
      indexg = indexg + 1;

    }
  }
/*
  Write the header.
*/
  pgma_write_header ( file_out, file_out_name, xsize, ysize, maxg );
/*
  Write the data.
*/
  pgma_write_data ( file_out, xsize, ysize, g );
/*
  Close the file.
*/
  fclose ( file_out );

  return;
}
/******************************************************************************/

void pgma_write_data ( FILE *file_out, int xsize, int ysize, int *g )

/******************************************************************************/
/*
  Purpose:

    PGMA_WRITE_DATA writes the data for an ASCII PGM file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, FILE *FILE_OUT, a pointer to the file.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int *G, the array of XSIZE by YSIZE data.
*/
{
  int i;
  int *indexg;
  int j;
  int numval;

  indexg = g;
  numval = 0;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      fprintf ( file_out, "%d", *indexg );
      numval = numval + 1;
      indexg = indexg + 1;

      if ( numval % 12 == 0 || i == xsize - 1 || numval == xsize * ysize )
      {
        fprintf ( file_out, "\n" );
      }
      else
      {
        fprintf ( file_out, " " );
      }

    }
  }
  return;
}
/******************************************************************************/

void pgma_write_header ( FILE *file_out, char *file_out_name, int xsize, 
  int ysize, int maxg )

/******************************************************************************/
/*
  Purpose:

    PGMA_WRITE_HEADER writes the header of an ASCII PGM file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, FILE *FILE_OUT, a pointer to the file.

    Input, char *FILE_OUT_NAME, the name of the file.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int MAXG, the maximum gray value.
*/
{
  fprintf ( file_out, "P2\n" );
  fprintf ( file_out, "# %s created by PGMA_IO::PGMA_WRITE.\n",
    file_out_name );
  fprintf ( file_out, "%d %d\n", xsize, ysize );
  fprintf ( file_out, "%d\n", maxg );

  return;
}
/******************************************************************************/

void ppma_read_data ( FILE *input, int xsize, int ysize, int *r,
  int *g, int *b )

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
/******************************************************************************/

void rgb_median_news ( int m, int n, int r[], int g[], int b[] )

/******************************************************************************/
/*
  Purpose:

    RGB_MEDIAN_NEWS uses a median NEWS filter on RGB data to remove noise.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 March 2017

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of pixels.

    Input/output, int R[M*N], G[M*N}, B{M*N};
    on input, the noisy data.
    on output, the filtered data.
*/
{
  int *t;

  t = gray_median_news ( m, n, r );
  i4mat_copy ( m, n, t, r );
  free ( t );

  t = gray_median_news ( m, n, g );
  i4mat_copy ( m, n, t, g );
  free ( t );

  t = gray_median_news ( m, n, b );
  i4mat_copy ( m, n, t, b );
  free ( t );

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
