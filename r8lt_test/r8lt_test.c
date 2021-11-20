# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "r8lt.h"

int main ( );
void r8ge_to_r8lt_test ( );
void r8lt_det_test ( );
void r8lt_indicator_test ( );
void r8lt_inverse_test ( );
void r8lt_mm_test ( );
void r8lt_mtm_test ( );
void r8lt_mtv_test ( );
void r8lt_mv_test ( );
void r8lt_print_test ( );
void r8lt_print_some_test ( );
void r8lt_random_test ( );
void r8lt_sl_test ( );
void r8lt_slt_test ( );
void r8lt_to_r8ge_test ( );
void r8lt_zeros_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for R8LT_TEST.

  Discussion:

    R8LT_TEST tests R8LT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "R8LT_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test R8LT.\n" );

  r8ge_to_r8lt_test ( );

  r8lt_det_test ( );
  r8lt_indicator_test ( );
  r8lt_inverse_test ( );
  r8lt_mm_test ( );
  r8lt_mtm_test ( );
  r8lt_mtv_test ( );
  r8lt_mv_test ( );
  r8lt_print_test ( );
  r8lt_print_some_test ( );
  r8lt_random_test ( );
  r8lt_sl_test ( );
  r8lt_slt_test ( );
  r8lt_to_r8ge_test ( );
  r8lt_zeros_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "R8LT_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void r8ge_to_r8lt_test ( )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8LT_TEST tests R8GE_TO_R8LT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 August 2015

  Author:

    John Burkardt
*/
{
  double *a_ge;
  double *a_lt;
  int m = 5;
  int n = 4;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "R8GE_TO_R8LT_TEST\n" );
  printf ( "  R8GE_TO_R8LT converts an R8GE matrix to R8LT format.\n" );

  a_ge = r8ge_random ( m, n, &seed );

  r8ge_print ( m, n, a_ge, "  The random R8GE matrix:" );

  a_lt = r8ge_to_r8lt ( m, n, a_ge );

  r8lt_print ( m, n, a_lt, "  The R8LT matrix" );

  free ( a_ge );
  free ( a_lt );

  return;
}
/******************************************************************************/

void r8lt_det_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_DET_TEST tests R8LT_DET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double det;
  int m = 5;
  int n = 5;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "R8LT_DET_TEST\n" );
  printf ( "  R8LT_DET computes the determinant of an R8LT matrix.\n" );

  a = r8lt_random ( m, n, &seed );

  r8lt_print ( m, n, a, "  The matrix A:" );
/*
  Compute the determinant.
*/
  det = r8lt_det ( n, a );

  printf ( "\n" );
  printf ( "  Determinant is %g\n", det );

  free ( a );

  return;
}
/******************************************************************************/

void r8lt_indicator_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_INDICATOR_TEST tests R8LT_INDICATOR;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 August 2015

  Author:

    John Burkardt
*/
{
# define M 6
# define N 5

  double *a;

  printf ( "\n" );
  printf ( "R8LT_INDICATOR_TEST\n" );
  printf ( "  R8LT_INDICATOR sets up an indicator matrix in R8LT format;\n" );

  a = r8lt_indicator ( M, N );

  r8lt_print ( M, N, a, "  The R8LT indicator matrix:" );

  free ( a );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8lt_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_INVERSE_TEST tests R8LT_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  double *c;
  int n = 5;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "R8LT_INVERSE_TEST\n" );
  printf ( "  R8LT_INVERSE computes the inverse of an R8LT matrix\n" );

  a = r8lt_random ( n, n, &seed );

  r8lt_print ( n, n, a, "  The matrix A:" );
/*
  Compute the inverse matrix B.
*/
  b = r8lt_inverse ( n, a );

  r8lt_print ( n, n, b, "  The inverse matrix B:" );
/*
  Check
*/
  c = r8lt_mm ( n, a, b );

  r8lt_print ( n, n, c, "  The product A * B:" );

  free ( a );
  free ( b );
  free ( c );

  return;
}
/******************************************************************************/

void r8lt_mm_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_MM_TEST tests R8LT_MM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *c;
  int i;
  int j;
  int m = 5;
  int n = 5;

  printf ( "\n" );
  printf ( "R8LT_MM_TEST\n" );
  printf ( "  R8LT_MM computes C=A*B for R8LT matrices.\n" );

  a = r8lt_zeros ( m, n );
  for ( j = 0; j < n; j++ )
  {
    for ( i = j; i < m; i++ )
    {
      a[i+j*m] = 1.0;
    }
  }
  r8lt_print ( m, n, a, "  The matrix:" );

  c = r8lt_mm ( m, a, a );
  r8lt_print ( m, n, c, "  The product C = A * A:" );

  free ( a );
  free ( c );

  return;
}
/******************************************************************************/

void r8lt_mtm_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_MTM_TEST tests R8LT_MTM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *c;
  int i;
  int j;
  int m = 5;
  int n = 5;

  printf ( "\n" );
  printf ( "R8LT_MTM_TEST\n" );
  printf ( "  R8LT_MTM computes C=A'*B for R8LT matrices.\n" );

  a = r8lt_zeros ( m, n );
  for ( j = 0; j < n; j++ )
  {
    for ( i = j; i < m; i++ )
    {
      a[i+j*m] = 1.0;
    }
  }
  r8lt_print ( m, n, a, "  The matrix:" );

  c = r8lt_mtm ( n, a, a );
  r8ge_print ( n, n, c, "  The product C = A' * A:" );

  free ( a );
  free ( c );

  return;
}
/******************************************************************************/

void r8lt_mtv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_MTV_TEST tests R8LT_MTV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int m = 5;
  int n = 4;
  double *x;

  printf ( "\n" );
  printf ( "R8LT_MTV_TEST\n" );
  printf ( "  R8LT_MTV computes a product b=A'*x where A is in R8LT format.\n" );

  a = r8lt_indicator ( m, n );
  r8lt_print ( m, n, a, "  The matrix:" );

  x = r8vec_indicator1_new ( m );
  r8vec_print ( m, x, "  Vector x:" );

  b = r8lt_mtv ( m, n, a, x );
  r8vec_print ( n, b, "  Vector b:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8lt_mv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_MV_TEST tests R8LT_MV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int m = 5;
  int n = 4;
  double *x;

  printf ( "\n" );
  printf ( "R8LT_MV_TEST\n" );
  printf ( "  R8LT_MV computes a product b=A*x where A is in R8LT format.\n" );

  a = r8lt_indicator ( m, n );
  r8lt_print ( m, n, a, "  The matrix:" );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  Vector x:" );

  b = r8lt_mv ( m, n, a, x );
  r8vec_print ( m, b, "  Vector b:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8lt_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_PRINT_TEST tests R8LT_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 6;
  int n = 4;

  printf ( "\n" );
  printf ( "R8LT_PRINT_TEST\n" );
  printf ( "  R8LT_PRINT prints an R8LT marix.\n" );

  a = r8lt_indicator ( m, n );

  r8lt_print ( m, n, a, "  The matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8lt_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_PRINT_SOME_TEST tests R8LT_PRINT_SOME.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 4;
  int n = 6;

  printf ( "\n" );
  printf ( "R8LT_PRINT_SOME_TEST\n" );
  printf ( "  R8LT_PRINT_SOME prints some of an R8LT marix.\n" );

  a = r8lt_indicator ( m, n );

  r8lt_print_some ( m, n, a, 1, 1, 2, 3, "  Rows 1-2, Cols 1-3:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8lt_random_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_RANDOM_TEST tests R8LT_RANDOM;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 August 2015

  Author:

    John Burkardt
*/
{
# define M 6
# define N 5

  double *a;
  int seed;

  printf ( "\n" );
  printf ( "R8LT_RANDOM_TEST\n" );
  printf ( "  R8LT_RANDOM randomizes a matrix in R8LT format;\n" );

  seed = 123456789;
  a = r8lt_random ( M, N, &seed );

  r8lt_print ( M, N, a, "  The random R8LT matrix:" );

  free ( a );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8lt_sl_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_SL_TEST tests R8LT_SL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int i;
  int j;
  int m = 5;
  int n = 5;
  double *x;

  printf ( "\n" );
  printf ( "R8LT_SL_TEST\n" );
  printf ( "  R8LT_SL solves a linear system  A*x=b with R8LT matrix;\n" );

  a = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      a[i+j*m] = 0.0;
    }
    for ( i = j; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( i + 1 );
    }
  }

  r8lt_print ( n, n, a, "  The R8LT matrix:" );
/*
  Set the desired solution.
*/
  x = r8vec_indicator1_new ( n );
/*
  Compute the corresponding right hand side.
*/
  b = r8lt_mv ( n, n, a, x );
  free ( x );
/*
  Solve the linear system.
*/
  x = r8lt_sl ( n, a, b );

  r8vec_print ( n, x, "  Solution:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8lt_slt_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_SLT_TEST tests R8LT_SLT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int i;
  int j;
  int m = 5;
  int n = 5;
  double *x;

  printf ( "\n" );
  printf ( "R8LT_SLT_TEST\n" );
  printf ( "  R8LT_SLT solves a linear system  A'*x=b with R8LT matrix;\n" );
  printf ( "\n" );
  printf ( "  Matrix order N = %d \n", n );

  a = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      a[i+j*m] = 0.0;
    }
    for ( i = j; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( i + 1 );
    }
  }

  r8lt_print ( n, n, a, "  The R8LT matrix:" );
/*
  Set the desired solution.
*/
  x = r8vec_indicator1_new ( n );
/*
  Compute the corresponding right hand side.
*/
  b = r8lt_mtv ( n, n, a, x );
/*
  Solve the linear system.
*/
  free ( x );
  x = r8lt_slt ( n, a, b );

  r8vec_print ( n, x, "  Solution to transposed system:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8lt_to_r8ge_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_TO_R8GE_TEST tests R8LT_TO_R8GE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 August 2015

  Author:

    John Burkardt
*/
{
  double *a_ge;
  double *a_lt;
  int m;
  int n;
  int seed;

  m = 5;
  n = 4;
  seed = 123456789;

  printf ( "\n" );
  printf ( "R8LT_TO_R8GE_TEST\n" );
  printf ( "  R8LT_TO_R8GE converts an R8LT matrix to R8GE format.\n" );

  a_lt = r8lt_random ( m, n, &seed );

  r8lt_print ( m, n, a_lt, "  R8LT matrix:" );

  a_ge = r8lt_to_r8ge ( m, n, a_lt );

  r8ge_print ( m, n, a_ge, "  R8GE matrix" );

  free ( a_ge );
  free ( a_lt );

  return;
}
/******************************************************************************/

void r8lt_zeros_test ( )

/******************************************************************************/
/*
  Purpose:

    R8LT_ZEROS_TEST tests R8LT_ZEROS;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 August 2015

  Author:

    John Burkardt
*/
{
# define M 6
# define N 5

  double *a;

  printf ( "\n" );
  printf ( "R8LT_ZEROS_TEST\n" );
  printf ( "  R8LT_ZEROS zeros an R8LT matrix;\n" );

  a = r8lt_zeros ( M, N );

  r8lt_print ( M, N, a, "  The R8LT matrix:" );

  free ( a );

  return;
# undef M
# undef N
}

