# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "blas0.h"
# include "blas3_s.h"

int main ( );
void sgemm_test ( );
void strmm_test ( );
void strsm_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BLAS3_S_TEST.

  Discussion:

    BLAS3_S_TEST tests the BLAS3_S library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 March 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BLAS3_S_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BLAS3_S library.\n" );

  sgemm_test ( );
  strmm_test ( );
  strsm_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BLAS3_S_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void sgemm_test ( )

/******************************************************************************/
/*
  Purpose:

    SGEMM_TEST tests SGEMM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 March 2017

  Author:

    John Burkardt
*/
{
  float *a;
  float alpha;
  float *b;
  float beta;
  float *c;
  int k;
  int lda;
  int ldb;
  int ldc;
  int m;
  int n;
  char transa;
  char transb;
  char transc;

  printf ( "\n" );
  printf ( "SGEMM_TEST\n" );
  printf ( "  SGEMM carries out matrix multiplications\n" );
  printf ( "  for single precision real matrices.\n" );
  printf ( "\n" );
  printf ( "  1: C = alpha * A  * B  + beta * C;\n" );
  printf ( "  2: C = alpha * A' * B  + beta * C;\n" );
  printf ( "  3: C = alpha * A  * B' + beta * C;\n" );
  printf ( "  4: C = alpha * A' * B' + beta * C;\n" );
  printf ( "\n" );
  printf ( "  We carry out all four calculations, but in each case,\n" );
  printf ( "  we choose our input matrices so that we get the same result.\n" );
/*
  C = alpha * A * B + beta * C.
*/
  transa = 'N';
  transb = 'N';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( transa, lda, m, k );
  ldb = k;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A * B + beta * C:" );

  free ( a );
  free ( b );
  free ( c );
/*
  C = alpha * A' * B + beta * C.
*/
  transa = 'T';
  transb = 'N';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = k;
  a = r4mat_test ( transa, lda, m, k );
  ldb = k;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb,  m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A' * B + beta * C:" );

  free ( a );
  free ( b );
  free ( c );
/*
  C = alpha * A * B' + beta * C.
*/
  transa = 'N';
  transb = 'T';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( transa, lda, m, k );
  ldb = n;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A * B' + beta * C:" );

  free ( a );
  free ( b );
  free ( c );
/*
  C = alpha * A' * B' + beta * C.
*/
  transa = 'T';
  transb = 'T';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = k;
  a = r4mat_test ( transa, lda, m, k );
  ldb = n;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb,  m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A' * B' + beta * C:" );

  free ( a );
  free ( b );
  free ( c );

  return;
}
/******************************************************************************/

void strmm_test ( )

/******************************************************************************/
/*
  Purpose:

    STRMM_TEST tests STRMM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 March 2017

  Author:

    John Burkardt
*/
{
  float *a;
  float alpha;
  float *b;
  char diag;
  int i;
  int j;
  int lda;
  int ldb;
  int m;
  int n;
  char side;
  char transa;
  char transb;
  char uplo;

  printf ( "\n" );
  printf ( "STRMM_TEST\n" );
  printf ( "  STRMM multiplies a triangular matrix A and a\n" );
  printf ( "  rectangular matrix B\n" );
  printf ( "\n" );
  printf ( "  1: B = alpha * A  * B;\n" );
  printf ( "  2: B = alpha * A' * B;\n" );
/*
  B = alpha * A * B.
*/
  side = 'L';
  uplo = 'U';
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( float * ) malloc ( lda * m * sizeof ( float ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strmm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  B = alpha * A * B:" );

  free ( a );
  free ( b );
/*
  B = alpha * A' * B.
*/
  side = 'L';
  uplo = 'U';
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( float * ) malloc ( lda * m * sizeof ( float ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strmm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  B = alpha * A' * B:" );

  free ( a );
  free ( b );

  return;
}
/******************************************************************************/

void strsm_test ( )

/******************************************************************************/
/*
  Purpose:

    STRSM_TEST tests STRSM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2014

  Author:

    John Burkardt
*/
{
  float *a;
  float alpha;
  float *b;
  char diag;
  int i;
  int j;
  int lda;
  int ldb;
  int m;
  int n;
  char side;
  char transa;
  char transb;
  char uplo;

  printf ( "\n" );
  printf ( "STRSM_TEST\n" );
  printf ( "  STRSM solves a linear system involving a triangular\n" );
  printf ( "  matrix A and a rectangular matrix B.\n" );
  printf ( "\n" );
  printf ( "  1: Solve A  * X  = alpha * B;\n" );
  printf ( "  2: Solve A' * X  = alpha * B;\n" );
  printf ( "  3: Solve X  * A  = alpha * B;\n" );
  printf ( "  4: Solve X  * A' = alpha * B;\n" );
/*
  Solve A * X = alpha * B.
*/
  side = 'L';
  uplo = 'U';
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( float * ) malloc ( lda * m * sizeof ( float ) );

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = inv ( A ) * alpha * B:" );

  free ( a );
  free ( b );
/*
  Solve A' * X = alpha * B.
*/
  side = 'L';
  uplo = 'U';
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( float * ) malloc ( lda * m * sizeof ( float ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = inv ( A' ) * alpha * B:" );

  free ( a );
  free ( b );
/*
  Solve X * A = alpha * B.
*/
  side = 'R';
  uplo = 'U';
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = n;
  ldb = m;

  a = ( float * ) malloc ( lda * n * sizeof ( float ) );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = alpha * B * inv ( A ):" );

  free ( a );
  free ( b );
/*
  Solve X * A'' = alpha * B.
*/
  side = 'R';
  uplo = 'U';
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = n;
  ldb = m;

  a = ( float * ) malloc ( lda * n * sizeof ( float ) );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = alpha * B * inv ( A' ):" );

  free ( a );
  free ( b );

  return;
}

