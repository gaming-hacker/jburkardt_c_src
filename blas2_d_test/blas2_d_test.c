# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "blas0.h"
# include "blas2_d.h"

int main ( );
void dgemv_test ( );
void dger_test ( );
void dtrmv_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BLAS2_D_TEST.

  Discussion:

    BLAS2_D_TEST tests the BLAS2_D library.

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
  printf ( "BLAS2_D_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BLAS2_D library.\n" );

  dgemv_test ( );
  dger_test ( );
  dtrmv_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BLAS2_D_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void dgemv_test ( )

/******************************************************************************/
/*
  Purpose:

    DGEMV_TEST tests DGEMV.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2014

  Author:

    John Burkardt
*/
{
  double *a;
  double alpha;
  double beta;
  int i;
  int incx;
  int incy;
  int lda;
  int m;
  int n;
  char trans;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "DGEMV_TEST\n" );
  printf ( "  DGEMV computes y := alpha * A * x + beta * y\n" );
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
  a = r8mat_test ( trans, lda, m, n );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }
  incx = 1;
  beta = 3.0;
  y = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r8mat_print ( m, n, a, "  Matrix A:" );
  r8vec_print ( n, x, "  Vector X:" );
  r8vec_print ( m, y, "  Vector Y:" );

  dgemv ( trans, m, n, alpha, a, lda, x, incx, beta, y, incy );

  r8vec_print ( m, y, "  Result Y = alpha * A  * x + beta * y" );

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
  a = r8mat_test ( trans, lda, n, m );
  x = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }
  incx = 1;
  beta = 3.0;
  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r8mat_print ( m, n, a, "  Matrix A:" );
  r8vec_print ( m, x, "  Vector X:" );
  r8vec_print ( n, y, "  Vector Y:" );

  dgemv ( trans, m, n, alpha, a, lda, x, incx, beta, y, incy );

  r8vec_print ( n, y, "  Result Y = alpha * A  * x + beta * y" );
/*
  Free memory.
*/
  free ( a );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void dger_test ( )

/******************************************************************************/
/*
  Purpose:

    DGER_TEST tests DGER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2014

  Author:

    John Burkardt
*/
{
  double *a;
  double alpha;
  int i;
  int incx;
  int incy;
  int lda;
  int m;
  int n;
  char trans;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "DGER_TEST\n" );
  printf ( "  DGER computes A := A + alpha * x * y'\n" );
  printf ( "  for a general matrix A.\n" );

  m = 5;
  n = 4;
  alpha = 2.0;
  trans = 'N';
  lda = m;
  a = r8mat_test ( trans, lda, m, n );

  x = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }
  incx = 1;

  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r8mat_print ( m, n, a, "  Matrix A:" );
  r8vec_print ( m, x, "  Vector X:" );
  r8vec_print ( n, y, "  Vector Y:" );

  dger ( m, n, alpha, x, incx, y, incy, a, lda );

  r8mat_print ( m, n, a, "  Result A = A + alpha * x * y" );
/*
  Free memory.
*/
  free ( a );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void dtrmv_test ( )

/******************************************************************************/
/*
  Purpose:

    DTRMV_TEST tests DTRMV.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2014

  Author:

    John Burkardt
*/
{
  double *a;
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
  double *x;

  a = ( double * ) malloc ( lda * n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "DTRMV_TEST\n" );
  printf ( "  DTRMV computes y := A * x or y := A' * x\n" );
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
        a[i+j*m] = ( double ) ( i + j + 2 );
      }
      for ( i = j + 1; i < m; i++ )
      {
        a[i+j*m] = 0.0;
      }
    }

    incx = 1;
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( double ) ( i + 1 );
    }

    dtrmv ( uplo, trans, diag, n, a, lda, x, incx );

    if ( trans == 'N' )
    {
      r8vec_print ( n, x, "  Result y = A * x" );
    }
    else
    {
      r8vec_print ( n, x, "  Result y = A' * x" );
    }
  }
/*
  Free memory.
*/
  free ( a );
  free ( x );

  return;
}
