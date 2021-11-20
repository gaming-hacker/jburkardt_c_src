# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "blas0.h"
# include "blas2_s.h"

int main ( );
void sgemv_test ( );
void sger_test ( );
void strmv_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BLAS2_S_TEST.

  Discussion:

    BLAS2_S_TEST tests the BLAS2_S library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 March 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BLAS2_S_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BLAS2_S library.\n" );

  sgemv_test ( );
  sger_test ( );
  strmv_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BLAS2_S_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void sgemv_test ( )

/******************************************************************************/
/*
  Purpose:

    SGEMV_TEST tests SGEMV.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 March 2017

  Author:

    John Burkardt
*/
{
  float *a;
  float alpha;
  float beta;
  int i;
  int incx;
  int incy;
  int lda;
  int m;
  int n;
  char trans;
  float *x;
  float *y;

  printf ( "\n" );
  printf ( "SGEMV_TEST\n" );
  printf ( "  SGEMV computes y := alpha * A * x + beta * y\n" );
  printf ( "  or             y := alpha * A'' * x + beta * y,\n" );
  printf ( "  for a general matrix A.\n" );
/*
  y = alpha * A * x + beta * y
*/
  trans = 'N';
  m = 5;
  n = 4;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( trans, lda, m, n );
  x = ( float * ) malloc ( n * sizeof ( float ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( float ) ( i + 1 );
  }
  incx = 1;
  beta = 3.0;
  y = ( float * ) malloc ( m * sizeof ( float ) );
  for ( i = 0; i < m; i++ )
  {
    y[i] = ( float ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r4mat_print ( m, n, a, "  Matrix A:" );
  r4vec_print ( n, x, "  Vector X:" );
  r4vec_print ( m, y, "  Vector Y:" );

  sgemv ( trans, m, n, alpha, a, lda, x, incx, beta, y, incy );

  r4vec_print ( m, y, "  Result Y = alpha * A  * x + beta * y" );

  free ( a );
  free ( x );
  free ( y );
/*
  y = alpha * A' * x + beta * y
*/
  trans = 'T';
  m = 5;
  n = 4;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( trans, lda, n, m );
  x = ( float * ) malloc ( m * sizeof ( float ) );
  for ( i = 0; i < m; i++ )
  {
    x[i] = ( float ) ( i + 1 );
  }
  incx = 1;
  beta = 3.0;
  y = ( float * ) malloc ( n * sizeof ( float ) );
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( float ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r4mat_print ( m, n, a, "  Matrix A:" );
  r4vec_print ( m, x, "  Vector X:" );
  r4vec_print ( n, y, "  Vector Y:" );

  sgemv ( trans, m, n, alpha, a, lda, x, incx, beta, y, incy );

  r4vec_print ( n, y, "  Result Y = alpha * A  * x + beta * y" );
/*
  Free memory.
*/
  free ( a );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void sger_test ( )

/******************************************************************************/
/*
  Purpose:

    SGER_TEST tests SGER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2014

  Author:

    John Burkardt
*/
{
  float *a;
  float alpha;
  int i;
  int incx;
  int incy;
  int lda;
  int m;
  int n;
  char trans;
  float *x;
  float *y;

  printf ( "\n" );
  printf ( "SGER_TEST\n" );
  printf ( "  SGER computes A := A + alpha * x * y'\n" );
  printf ( "  for a general matrix A.\n" );

  m = 5;
  n = 4;
  alpha = 2.0;
  trans = 'N';
  lda = m;
  a = r4mat_test ( trans, lda, m, n );

  x = ( float * ) malloc ( m * sizeof ( float ) );
  for ( i = 0; i < m; i++ )
  {
    x[i] = ( float ) ( i + 1 );
  }
  incx = 1;

  y = ( float * ) malloc ( n * sizeof ( float ) );
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( float ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r4mat_print ( m, n, a, "  Matrix A:" );
  r4vec_print ( m, x, "  Vector X:" );
  r4vec_print ( n, y, "  Vector Y:" );

  sger ( m, n, alpha, x, incx, y, incy, a, lda );

  r4mat_print ( m, n, a, "  Result A = A + alpha * x * y" );
/*
  Free memory.
*/
  free ( a );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void strmv_test ( )

/******************************************************************************/
/*
  Purpose:

    STRMV_TEST tests STRMV.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2014

  Author:

    John Burkardt
*/
{
  float *a;
  char diag;
  int i;
  int incx;
  int j;
  int lda = 5;
  int m = 5;
  int n = 5;
  int test;
  char trans;
  char uplo;
  float *x;

  a = ( float * ) malloc ( lda * n * sizeof ( float ) );
  x = ( float * ) malloc ( n * sizeof ( float ) );

  printf ( "\n" );
  printf ( "STRMV_TEST\n" );
  printf ( "  STRMV computes y := A * x or y := A' * x\n" );
  printf ( "  for a triangular matrix A.\n" );

  for ( test = 1; test <= 2; test++ )
  {
    uplo = 'U';

    if ( test == 1 )
    {
      trans = 'N';
    }
    else
    {
      trans = 'T';
    }

    diag = 'N';

    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i <= j; i++ )
      {
        a[i+j*m] = ( float ) ( i + j + 2 );
      }
      for ( i = j + 1; i < m; i++ )
      {
        a[i+j*m] = 0.0;
      }
    }

    incx = 1;
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( float ) ( i + 1 );
    }

    strmv ( uplo, trans, diag, n, a, lda, x, incx );

    if ( trans == 'N' )
    {
      r4vec_print ( n, x, "  Result y = A * x" );
    }
    else
    {
      r4vec_print ( n, x, "  Result y = A' * x" );
    }
  }
/*
  Free memory.
*/
  free ( a );
  free ( x );

  return;
}
