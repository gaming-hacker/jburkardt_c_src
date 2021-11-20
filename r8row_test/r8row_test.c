# include <complex.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "r8row.h"

int main ( );

void r8row_compare_test ( );
void r8row_indicator_new_test ( );
void r8row_max_test ( );
void r8row_mean_test ( );
void r8row_min_test ( );
void r8row_print_test ( );
void r8row_print_some_test ( );
void r8row_running_average_test ( );
void r8row_running_sum_test ( );
void r8row_sort_heap_a_test ( );
void r8row_sum_test ( );
void r8row_swap_test ( );
void r8row_to_r8vec_test ( );
void r8row_transpose_print_test ( );
void r8row_transpose_print_some_test ( );
void r8row_uniform_ab_new_test ( );
void r8row_variance_test ( );


void r8vec_print_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for R8ROW_TEST.

  Discussion:

    R8ROW_TEST tests the R8ROW library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "R8ROW_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the R8ROW library.\n" );

  r8row_compare_test ( );
  r8row_indicator_new_test ( );
  r8row_max_test ( );
  r8row_mean_test ( );
  r8row_min_test ( );
  r8row_print_test ( );
  r8row_print_some_test ( );
  r8row_running_average_test ( );
  r8row_running_sum_test ( );
  r8row_sort_heap_a_test ( );
  r8row_sum_test ( );
  r8row_swap_test ( );
  r8row_to_r8vec_test ( );
  r8row_transpose_print_test ( );
  r8row_transpose_print_some_test ( );
  r8row_uniform_ab_new_test ( );
  r8row_variance_test ( );

  r8vec_print_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "R8ROW_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void r8row_compare_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_COMPARE_TEST tests R8ROW_COMPARE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 February 2016

  Author:

    John Burkardt
*/
{
  double *a;
  int *c;
  int i;
  int j;
  int m;
  int n;

  printf ( "\n" );
  printf ( "R8ROW_COMPARE_TEST\n" );
  printf ( "  R8ROW_COMPARE compares rows of an R8ROW,\n" );
  printf ( "  returning -1, 0 or +1 for comparison.\n" );

  m = 6;
  n = 5;
 
  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( ( i + 1 + j +1 ) % 3 );
    }
  }

  r8row_print ( m, n, a, "  Matrix A:" );

  c = ( int * ) malloc ( m * m * sizeof ( int ) );

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      c[i+j*m] = r8row_compare ( m, n, a, i, j );
    }
  }

  i4mat_print ( m, m, c, "  C(I,J) = Row I compare Row J:" );

  free ( a );
  free ( c );

  return;
}
/******************************************************************************/

void r8row_indicator_new_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_INDICATOR_NEW_TEST tests R8ROW_INDICATOR_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 February 2016

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "R8ROW_INDICATOR_NEW_TEST\n" );
  printf ( "  R8ROW_INDICATOR_NEW returns the indicator matrix as an R8ROW.\n" );

  a = r8row_indicator_new ( m, n );

  r8row_print ( m, n, a, "  The indicator matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8row_max_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_MAX_TEST tests R8ROW_MAX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  double *amax;
  int i;
  int j;
  int k;

  printf ( "\n" );
  printf ( "R8ROW_MAX_TEST\n" );
  printf ( "  R8ROW_MAX computes maximums of an R8ROW.\n" );

  k = 0;
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) k;
    }
  }

  r8row_print ( M, N, a, "  The original matrix:" );

  amax = r8row_max ( M, N, a );

  r8vec_print ( M, amax, "  Row maximums:" );

  free ( amax );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_mean_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_MEAN_TEST tests R8ROW_MEAN ;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  int i;
  int j;
  int k;
  double *mean;

  printf ( "\n" );
  printf ( "R8ROW_MEAN_TEST\n" );
  printf ( "  R8ROW_MEAN computes means of an R8ROW.\n" );

  k = 0;
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) k;
    }
  }

  r8row_print ( M, N, a, "  The original matrix:" );

  mean = r8row_mean ( M, N, a );

  r8vec_print ( M, mean, "  The row means:" );

  free ( mean );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_min_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_MIN_TEST tests R8ROW_MIN;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  double *amin;
  int i;
  int j;
  int k;

  printf ( "\n" );
  printf ( "R8ROW_MIN_TEST\n" );
  printf ( "  R8ROW_MIN computes minimums of an R8ROW.\n" );

  k = 0;
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) k;
    }
  }

  r8row_print ( M, N, a, "  The original matrix:" );

  amin = r8row_min ( M, N, a );

  r8vec_print ( M, amin, "  Row minimums:" );

  free ( amin );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_PRINT_TEST tests R8ROW_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2014

  Author:

    John Burkardt
*/
{
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  printf ( "\n" );
  printf ( "R8ROW_PRINT_TEST\n" );
  printf ( "  R8ROW_PRINT prints an R8ROW.\n" );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8row_print ( m, n, a, "  The matrix:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_PRINT_SOME_TEST tests R8ROW_PRINT_SOME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2014

  Author:

    John Burkardt
*/
{
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  printf ( "\n" );
  printf ( "R8ROW_PRINT_SOME_TEST\n" );
  printf ( "  R8ROW_PRINT_SOME prints some of an R8ROW.\n" );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8row_print_some ( m, n, a, 2, 1, 4, 2, "  Rows 2:4, Cols 1:2:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_running_average_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_RUNNING_AVERAGE_TEST tests R8ROW_RUNNING_AVERAGE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 February 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int m;
  int n;
  double *r;
  double *s;
  int seed;

  printf ( "\n" );
  printf ( "R8ROW_RUNNING_AVERAGE_TEST\n" );
  printf ( "  R8ROW_RUNNING_AVERAGE returns M sets of running averages\n" );
  printf ( "  of an MxN R8ROW.\n" );

  m = 5;
  n = 10;
  a = -5.0;
  b = +10.0;
  seed = 123456789;

  r = r8row_uniform_ab_new ( m, n, a, b, &seed );

  r8row_print ( m, n, r, "  Random R8ROW:" );

  s = r8row_running_average ( m, n, r );

  r8row_print ( m, n + 1, s, "  Running averages:" );

  free ( r );
  free ( s );

  return;
}
/******************************************************************************/

void r8row_running_sum_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_RUNNING_SUM_TEST tests R8ROW_RUNNING_SUM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 February 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int m;
  int n;
  double *r;
  double *s;
  int seed;

  printf ( "\n" );
  printf ( "R8ROW_RUNNING_SUM_TEST\n" );
  printf ( "  R8ROW_RUNNING_SUM returns the M running sums of an R8ROW.\n" );

  m = 5;
  n = 10;
  a = -5.0;
  b = +10.0;
  seed = 123456789;

  r = r8row_uniform_ab_new ( m, n, a, b, &seed );

  r8row_print ( m, n, r, "  Random R8ROW:" );

  s = r8row_running_sum ( m, n, r );

  r8row_print ( m, n + 1, s, "  Running sums:" );

  free ( r );
  free ( s );

  return;
}
/******************************************************************************/

void r8row_sort_heap_a_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_SORT_HEAP_A_TEST tests R8ROW_SORT_HEAP_A.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 February 2016

  Author:

    John Burkardt
*/
{
  double a[4*3] = {
     2.0,  4.0, 1.0,  3.0, 
     6.0,  8.0, 5.0,  7.0, 
    10.0, 12.0, 9.0, 11.0 };
  int m = 4;
  int n = 3;

  printf ( "\n" );
  printf ( "R8ROW_SORT_HEAP_A_TEST\n" );
  printf ( "  R8ROW_SORT_HEAP_A ascending heap sorts of an R8ROW.\n" );

  r8row_print ( m, n, a, "  The unsorted matrix:" );

  r8row_sort_heap_a ( m, n, a );

  r8row_print ( m, n, a, "  The sorted matrix:" );

  return;
}
/******************************************************************************/

void r8row_sum_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_SUM_TEST tests R8ROW_SUM;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  int i;
  int j;
  int k;
  double *rowsum;

  printf ( "\n" );
  printf ( "R8ROW_SUM_TEST\n" );
  printf ( "  R8ROW_SUM computes sums of an R8ROW.\n" );

  k = 0;
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) k;
    }
  }

  r8row_print ( M, N, a, "  The original matrix:" );

  rowsum = r8row_sum ( M, N, a );

  r8vec_print ( M, rowsum, "  The row sums:" );

  free ( rowsum );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_swap_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_SWAP_TEST tests R8ROW_SWAP;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  int i;
  int row1;
  int row2;
  int j;
  int k;

  printf ( "\n" );
  printf ( "R8ROW_SWAP_TEST\n" );
  printf ( "  R8ROW_SWAP swaps two rows of an R8ROW.\n" );

  k = 0;
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) k;
    }
  }

  r8row_print ( M, N, a, "  The original matrix:" );

  row1 = 0;
  row2 = 2;

  printf ( "\n" );
  printf ( "  Swap rows %d and %d\n", row1, row2 );

  r8row_swap ( M, N, a, row1, row2 );

  r8row_print ( M, N, a, "  The modified matrix:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_to_r8vec_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_TO_R8VEC_TEST tests R8ROW_TO_R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  int i;
  int j;
  int k;
  double *x;

  printf ( "\n" );
  printf ( "R8ROW_TO_R8VEC_TEST\n" );
  printf ( "  R8ROW_TO_R8VEC converts an R8ROW into a vector.\n" );

  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) ( 10 * i + j );
    }
  }

  r8row_print ( M, N, a, "  The array of rows:" );

  x = r8row_to_r8vec ( M, N, a );

  r8vec_print ( M*N, x, "  The resulting vector of rows:" );

  free ( x );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_transpose_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_TRANSPOSE_PRINT_TEST tests R8ROW_TRANSPOSE_PRINT;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define M 7
# define N 12

  double a[M*N];
  int i;
  int j;

  printf ( "\n" );
  printf ( "R8ROW_TRANSPOSE_PRINT_TEST\n" );
  printf ( "  R8ROW_TRANSPOSE_PRINT prints an R8ROW,\n" );
  printf ( "  transposed.\n" );
  printf ( "\n" );
  printf ( "  Matrix row order M =    %d\n", M );
  printf ( "  Matrix column order N = %d\n", N );
/*
  Set the matrix.
*/
  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      a[i-1+(j-1)*M] = ( double ) ( i * 100 + j );
    }
  }

  r8row_transpose_print ( M, N, a, "  The transposed matrix A:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_transpose_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_TRANSPOSE_PRINT_SOME_TEST tests R8ROW_TRANSPOSE_PRINT_SOME;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define M 7
# define N 12

  double a[M*N];
  int i;
  int j;

  printf ( "\n" );
  printf ( "R8ROW_TRANSPOSE_PRINT_SOME_TEST\n" );
  printf ( "  R8ROW_TRANSPOSE_PRINT_SOME prints some of an R8ROW,\n" );
  printf ( "  transposed.\n" );
  printf ( "\n" );
  printf ( "  Matrix row order M =    %d\n", M );
  printf ( "  Matrix column order N = %d\n", N );
/*
  Set the matrix.
*/
  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      a[i-1+(j-1)*M] = ( double ) ( i * 100 + j );
    }
  }

  r8row_transpose_print_some ( M, N, a, 3, 4, 5, 8, "  Rows 3:5, Cols 4:8:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_uniform_ab_new_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_UNIFORM_AB_NEW_TEST tests R8ROW_UNIFORM_AB_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 October 2005

  Author:

    John Burkardt
*/
{
# define M 5
# define N 4

  double *a;
  double b = 2.0E+00;
  double c = 10.0E+00;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "R8ROW_UNIFORM_AB_NEW_TEST\n" );
  printf ( "  R8ROW_UNIFORM_AB_NEW sets an R8ROW to random values in [A,B].\n" );
  printf ( "\n" );

  a = r8row_uniform_ab_new ( M, N, b, c, &seed );

  r8row_print ( M, N, a, "  The random R8ROW:" );

  free ( a );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8row_variance_test ( )

/******************************************************************************/
/*
  Purpose:

    R8ROW_VARIANCE_TEST tests R8ROW_VARIANCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define M 3
# define N 4

  double a[M*N];
  int i;
  int j;
  int k;
  double *variance;

  printf ( "\n" );
  printf ( "R8ROW_VARIANCE_TEST\n" );
  printf ( "  R8ROW_VARIANCE computes variances of an R8ROW.\n" );

  k = 0;
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      k = k + 1;
      a[i+j*M] = ( double ) k;
    }
  }

  r8row_print ( M, N, a, "  The original matrix:" );

  variance = r8row_variance ( M, N, a );

  printf ( "\n" );
  printf ( "  Row variances:\n" );
  printf ( "\n" );

  for ( i = 0; i < M; i++ )
  {
    printf ( "  %3d  %10g\n", i + 1, variance[i] );
  }

  free ( variance );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8vec_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT_TEST tests R8VEC_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2014

  Author:

    John Burkardt
*/
{
  double a[4] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  int n = 4;

  printf ( "\n" );
  printf ( "R8VEC_PRINT_TEST\n" );
  printf ( "  R8VEC_PRINT prints an R8VEC.\n" );

  r8vec_print ( n, a, "  The R8VEC:" );

  return;
}
