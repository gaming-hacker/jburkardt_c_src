# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "r8ut.h"

int main ( );
void r8ge_to_r8ut_test ( );
void r8ut_det_test ( );
void r8ut_indicator_test ( );
void r8ut_inverse_test ( );
void r8ut_mm_test ( );
void r8ut_mtm_test ( );
void r8ut_mtv_test ( );
void r8ut_mv_test ( );
void r8ut_print_test ( );
void r8ut_print_some_test ( );
void r8ut_random_test ( );
void r8ut_sl_test ( );
void r8ut_slt_test ( );
void r8ut_to_r8ge_test ( );
void r8ut_zeros_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for R8UT_TEST.

  Discussion:

    R8UT_TEST tests the R8UT library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "R8UT_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the R8UT library.\n" );

  r8ge_to_r8ut_test ( );

  r8ut_det_test ( );
  r8ut_indicator_test ( );
  r8ut_inverse_test ( );
  r8ut_mm_test ( );
  r8ut_mtm_test ( );
  r8ut_mtv_test ( );
  r8ut_mv_test ( );
  r8ut_print_test ( );
  r8ut_print_some_test ( );
  r8ut_random_test ( );
  r8ut_sl_test ( );
  r8ut_slt_test ( );
  r8ut_to_r8ge_test ( );
  r8ut_zeros_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "R8UT_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void r8ge_to_r8ut_test ( )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8UT_TEST tests R8GE_TO_R8UT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2015

  Author:

    John Burkardt
*/
{
  double *a_ge;
  double *a_ut;
  int m = 5;
  int n = 4;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "R8GE_TO_R8UT_TEST\n" );
  printf ( "  R8GE_TO_R8UT converts an R8GE matrix to R8UT format.\n" );

  a_ge = r8ge_random ( m, n, &seed );

  r8ge_print ( m, n, a_ge, "  The random R8GE matrix:" );

  a_ut = r8ge_to_r8ut ( m, n, a_ge );

  r8ut_print ( m, n, a_ut, "  The R8UT matrix" );

  free ( a_ge );
  free ( a_ut );

  return;
}
/******************************************************************************/

void r8ut_det_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_DET_TEST tests R8UT_DET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

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
  printf ( "R8UT_DET_TEST\n" );
  printf ( "  R8UT_DET computes the determinant of an R8UT matrix.\n" );

  a = r8ut_random ( m, n, &seed );

  r8ut_print ( m, n, a, "  The matrix A:" );
/*
  Compute the determinant.
*/
  det = r8ut_det ( n, a );

  printf ( "\n" );
  printf ( "  Determinant is %g\n", det );

  free ( a );

  return;
}
/******************************************************************************/

void r8ut_indicator_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_INDICATOR_TEST tests R8UT_INDICATOR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "R8UT_INDICATOR_TEST\n" );
  printf ( "  R8UT_INDICATOR sets up an indicator matrix in R8UT format.\n" );

  a = r8ut_indicator ( m, n );

  r8ut_print ( m, n, a, "  The matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8ut_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_INVERSE_TEST tests R8UT_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2015

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
  printf ( "R8UT_INVERSE_TEST\n" );
  printf ( "  R8UT_INVERSE computes the inverse of an upper triangular matrix\n" );

  a = r8ut_random ( n, n, &seed );

  r8ut_print ( n, n, a, "  The matrix A:" );
/*
  Compute the inverse matrix B.
*/
  b = r8ut_inverse ( n, a );

  r8ut_print ( n, n, b, "  The inverse matrix B:" );
/*
  Check
*/
  c = r8ut_mm ( n, a, b );

  r8ut_print ( n, n, c, "  The product A * B:" );

  free ( a );
  free ( b );
  free ( c );

  return;
}
/******************************************************************************/

void r8ut_mm_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_MM_TEST tests R8UT_MM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *c;
  int i;
  int j;
  int n = 5;

  printf ( "\n" );
  printf ( "R8UT_MM_TEST\n" );
  printf ( "  R8UT_MM computes C=A*B for R8UT matrices.\n" );

  a = r8ut_zeros ( n, n );
  for ( i = 0; i < n; i++ )
  {
    for ( j = i; j < n; j++ )
    {
      a[i+j*n] = 1.0;
    }
  }
  r8ut_print ( n, n, a, "  The matrix:" );

  c = r8ut_mm ( n, a, a );
  r8ut_print ( n, n, c, "  The product C = A * A:" );

  free ( a );
  free ( c );

  return;
}
/******************************************************************************/

void r8ut_mtm_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_MTM_TEST tests R8UT_MTM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *c;
  int i;
  int j;
  int n = 5;

  printf ( "\n" );
  printf ( "R8UT_MTM_TEST\n" );
  printf ( "  R8UT_MTM computes C=A'*B for R8UT matrices.\n" );

  a = r8ut_zeros ( n, n );
  for ( i = 0; i < n; i++ )
  {
    for ( j = i; j < n; j++ )
    {
      a[i+j*n] = 1.0;
    }
  }
  r8ut_print ( n, n, a, "  The matrix:" );

  c = r8ut_mtm ( n, a, a );
  r8ge_print ( n, n, c, "  The product C = A' * A:" );

  free ( a );
  free ( c );

  return;
}
/******************************************************************************/

void r8ut_mtv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_MTV_TEST tests R8UT_MTV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

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
  printf ( "R8UT_MTV_TEST\n" );
  printf ( "  R8UT_MTV computes a product b=A'*x where A is in R8UT format.\n" );

  a = r8ut_indicator ( m, n );
  r8ut_print ( m, n, a, "  The matrix:" );

  x = r8vec_indicator1_new ( m );
  r8vec_print ( m, x, "  Vector x:" );

  b = r8ut_mtv ( m, n, a, x );
  r8vec_print ( n, b, "  Vector b:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8ut_mv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_MV_TEST tests R8UT_MV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

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
  printf ( "R8UT_MV_TEST\n" );
  printf ( "  R8UT_MV computes a product b=A*x where A is in R8UT format.\n" );

  a = r8ut_indicator ( m, n );
  r8ut_print ( m, n, a, "  The matrix:" );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  Vector x:" );

  b = r8ut_mv ( m, n, a, x );
  r8vec_print ( m, b, "  Vector b:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8ut_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_PRINT_TEST tests R8UT_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 6;
  int n = 4;

  printf ( "\n" );
  printf ( "R8UT_PRINT_TEST\n" );
  printf ( "  R8UT_PRINT prints an R8UT marix.\n" );

  a = r8ut_indicator ( m, n );

  r8ut_print ( m, n, a, "  The matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8ut_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_PRINT_SOME_TEST tests R8UT_PRINT_SOME.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 4;
  int n = 6;

  printf ( "\n" );
  printf ( "R8UT_PRINT_SOME_TEST\n" );
  printf ( "  R8UT_PRINT_SOME prints some of an R8UT marix.\n" );

  a = r8ut_indicator ( m, n );

  r8ut_print_some ( m, n, a, 0, 3, 2, 5, "  Some of the matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8ut_random_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_RANDOM_TEST tests R8UT_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m;
  int n;
  int seed;

  m = 5;
  n = 4;
  seed = 123456789;

  printf ( "\n" );
  printf ( "R8UT_RANDOM_TEST\n" );
  printf ( "  R8UT_RANDOM randomizes an R8UT matrix.\n" );
  printf ( "\n" );
  printf ( "  Matrix order M, N = %d, %d\n", m, n );

  a = r8ut_random ( m, n, &seed );

  r8ut_print ( m, n, a, "  Matrix A:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8ut_sl_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_SL_TEST tests R8UT_SL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int i;
  int j;
  int n = 5;
  double *x;

  printf ( "\n" );
  printf ( "R8UT_SL_TEST\n" );
  printf ( "  R8UT_SL solves a linear system  A*x=b with R8UT matrix;\n" );
  printf ( "\n" );
  printf ( "  Matrix order N = %d \n", n );

  a = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i <= j )
      {
        a[i-1+(j-1)*n] = ( double ) j;
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }

  r8ut_print ( n, n, a, "  The upper triangular matrix:" );

/*
  Set the desired solution.
*/
  x = r8vec_indicator1_new ( n );
/*
  Compute the corresponding right hand side.
*/
  b = r8ut_mv ( n, n, a, x );
  free ( x );
/*
  Solve the linear system.
*/
  x = r8ut_sl ( n, a, b );

  r8vec_print ( n, x, "  Solution:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8ut_slt_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_SLT_TEST tests R8UT_SLT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int i;
  int j;
  int n = 5;
  double *x;

  printf ( "\n" );
  printf ( "R8UT_SLT_TEST\n" );
  printf ( "  R8UT_SLT solves a linear system  A'*x=b with R8UT matrix;\n" );
  printf ( "\n" );
  printf ( "  Matrix order N = %d \n", n );

  a = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i <= j )
      {
        a[i-1+(j-1)*n] = ( double ) j;
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }

  r8ut_print ( n, n, a, "  The upper triangular matrix:" );
/*
  Set the desired solution.
*/
  x = r8vec_indicator1_new ( n );
/*
  Compute the corresponding right hand side.
*/
  b = r8ut_mtv ( n, n, a, x );
/*
  Solve the linear system.
*/
  free ( x );
  x = r8ut_slt ( n, a, b );

  r8vec_print ( n, x, "  Solution to transposed system:" );

  free ( a );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8ut_to_r8ge_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_TO_R8GE_TEST tests R8UT_TO_R8GE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2015

  Author:

    John Burkardt
*/
{
  double *a_ge;
  double *a_ut;
  int m;
  int n;
  int seed;

  m = 5;
  n = 4;
  seed = 123456789;

  printf ( "\n" );
  printf ( "R8UT_TO_R8GE_TEST\n" );
  printf ( "  R8UT_TO_R8GE converts an R8UT matrix to R8GE format.\n" );

  a_ut = r8ut_random ( m, n, &seed );

  r8ut_print ( m, n, a_ut, "  R8UT matrix:" );

  a_ge = r8ut_to_r8ge ( m, n, a_ut );

  r8ge_print ( m, n, a_ge, "  R8GE matrix" );

  free ( a_ge );
  free ( a_ut );

  return;
}
/******************************************************************************/

void r8ut_zeros_test ( )

/******************************************************************************/
/*
  Purpose:

    R8UT_ZEROS_TEST tests R8UT_ZEROS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "R8UT_ZEROS_TEST\n" );
  printf ( "  R8UT_ZEROS returns a zeroed out R8UT matrix.\n" );
  printf ( "\n" );
  printf ( "  Matrix order M, N = %d, %d\n", m, n );

  a = r8ut_zeros ( m, n );

  r8ut_print ( m, n, a, "  Matrix A:" );

  free ( a );

  return;
}
