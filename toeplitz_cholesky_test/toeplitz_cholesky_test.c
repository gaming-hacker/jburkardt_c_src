# include <stdlib.h>
# include <stdio.h>

# include "toeplitz_cholesky.h"

int main ( );
void t_cholesky_lower_test ( );
void toep_cholesky_lower_test ( );
void toeplitz_cholesky_lower_test ( );
void t_cholesky_upper_test ( );
void toep_cholesky_upper_test ( );
void toeplitz_cholesky_upper_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TOEPLITZ_CHOLESKY_TEST.

  Discussion:

    TOEPLITZ_CHOLESKY_TEST tests the TOEPLITZ_CHOLESKY library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TOEPLITZ_CHOLESKY_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TOEPLITZ_CHOLESKY library.\n" );

  t_cholesky_lower_test ( );
  toep_cholesky_lower_test ( );
  toeplitz_cholesky_lower_test ( );
  t_cholesky_upper_test ( );
  toep_cholesky_upper_test ( );
  toeplitz_cholesky_upper_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TOEPLITZ_CHOLESKY_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void t_cholesky_lower_test ( )

/******************************************************************************/
/*
  Purpose:

    T_CHOLESKY_LOWER_TEST tests T_CHOLESKY_LOWER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{

  double *b;
  double *l;
  int n = 3;
  double t[3] = { 1.0,    0.5, -0.375};

  printf ( "\n" );
  printf ( "T_CHOLESKY_LOWER_TEST\n" );
  printf ( "  T_CHOLESKY_LOWER computes the lower Cholesky factor L\n" );
  printf ( "  of a positive definites symmetric Toeplitz matrix\n" );
  printf ( "  defined by the first row.\n" );

  r8vec_print ( n, t, "  First row of matrix T:" );

  l = t_cholesky_lower ( n, t );
  r8mat_print ( n, n, l, "  Computed lower Cholesky factor L:" );

  b = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, b, "  Product LL':" );

  free ( b );
  free ( l );

  return;
}
/******************************************************************************/

void toep_cholesky_lower_test ( )

/******************************************************************************/
/*
  Purpose:

    TOEP_CHOLESKY_LOWER_TEST tests TOEP_CHOLESKY_LOWER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{
  double *b;
  double g[2*3] = {
    1.0,    0.0,
    0.5,    0.5,
   -0.375, -0.375 };
  double *l;
  int n = 3;

  printf ( "\n" );
  printf ( "TOEP_CHOLESKY_LOWER_TEST\n" );
  printf ( "  TOEP_CHOLESKY_LOWER computes the lower Cholesky factor L\n" );
  printf ( "  of a positive definites symmetric Toeplitz matrix\n" );
  printf ( "  defined by a (2,N) array.\n" );

  r8mat_print ( 2, n, g, "  Compressed Toeplitz matrix G:" );

  l = toep_cholesky_lower ( n, g );
  r8mat_print ( n, n, l, "  Computed lower Cholesky factor L:" );

  b = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, b, "  Product LL':" );

  free ( b );
  free ( l );

  return;
}
/******************************************************************************/

void toeplitz_cholesky_lower_test ( )

/******************************************************************************/
/*
  Purpose:

    TOEPLITZ_CHOLESKY_LOWER_TEST tests TOEPLITZ_CHOLESKY_LOWER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{
  double a[3*3] = {  
    1.0,    0.5, -0.375,
    0.5,    1.0,  0.5,
   -0.375,  0.5,  1.0 };
  double *b;
  double *l;
  int n = 3;

  printf ( "\n" );
  printf ( "TOEPLITZ_CHOLESKY_LOWER_TEST\n" );
  printf ( "  TOEPLITZ_CHOLESKY_LOWER computes the lower Cholesky factor L\n" );
  printf ( "  of a positive definites symmetric Toeplitz matrix\n" );
  printf ( "  defined as an NxN array.\n" );

  r8mat_print ( n, n, a, "  Toeplitz matrix A:" );

  l = toeplitz_cholesky_lower ( n, a );
  r8mat_print ( n, n, l, "  Computed lower Cholesky factor L:" );

  b = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, b, "  Product LL':" );

  free ( b );
  free ( l );

  return;
}
/******************************************************************************/

void t_cholesky_upper_test ( )

/******************************************************************************/
/*
  Purpose:

    T_CHOLESKY_UPPER_TEST tests T_CHOLESKY_UPPER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{

  double *b;
  int n = 3;
  double *r;
  double t[3] = {  
    1.0,    0.5, -0.375 };

  printf ( "\n" );
  printf ( "T_CHOLESKY_UPPER_TEST\n" );
  printf ( "  T_CHOLESKY_UPPER computes the upper Cholesky factor R\n" );
  printf ( "  of a positive definites symmetric Toeplitz matrix\n" );
  printf ( "  defined by the first row.\n" );

  r8vec_print ( n, t, "  First row of Toeplitz matrix T:" );

  r = t_cholesky_upper ( n, t );
  r8mat_print ( n, n, r, "  Computed upper Cholesky factor R:" );

  b = r8mat_mtm_new ( n, n, n, r, r );
  r8mat_print ( n, n, b, "  Product R'R:" );

  free ( b );
  free ( r );

  return;
}
/******************************************************************************/

void toep_cholesky_upper_test ( )

/******************************************************************************/
/*
  Purpose:

    TOEP_CHOLESKY_UPPER_TEST tests TOEPLITZ_CHOLESKY_UPPER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{
  double *b;
  double g[2*3] = {
    1.0,    0.0,
    0.5,    0.5,
   -0.375, -0.375 };
  int n = 3;
  double *r;

  printf ( "\n" );
  printf ( "TOEP_CHOLESKY_UPPER_TEST\n" );
  printf ( "  TOEP_CHOLESKY_UPPER computes the upper Cholesky factor L\n" );
  printf ( "  of a positive definites symmetric Toeplitz matrix\n" );
  printf ( "  defined by a (2,N) array.\n" );

  r8mat_print ( 2, n, g, "  Compressed Toeplitz matrix G:" );

  r = toep_cholesky_upper ( n, g );
  r8mat_print ( n, n, r, "  Computed upper Cholesky factor R:" );

  b = r8mat_mtm_new ( n, n, n, r, r );
  r8mat_print ( n, n, b, "  Product R'R:" );

  free ( b );
  free ( r );

  return;
}
/******************************************************************************/

void toeplitz_cholesky_upper_test ( )

/******************************************************************************/
/*
  Purpose:

    TOEPLITZ_CHOLESKY_UPPER_TEST tests TOEPLITZ_CHOLESKY_UPPER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2017

  Author:

    John Burkardt
*/
{
  double a[3*3] = {  
    1.0,    0.5, -0.375,
    0.5,    1.0,  0.5,
   -0.375,  0.5,  1.0 };
  double *b;
  int n = 3;
  double *r;

  printf ( "\n" );
  printf ( "TOEPLITZ_CHOLESKY_UPPER_TEST\n" );
  printf ( "  TOEPLITZ_CHOLESKY_UPPER computes the upper Cholesky factor L\n" );
  printf ( "  of a positive definites symmetric Toeplitz matrix\n" );
  printf ( "  defined as an NxN array.\n" );

  r8mat_print ( n, n, a, "  Toeplitz matrix A:" );

  r = toeplitz_cholesky_upper ( n, a );
  r8mat_print ( n, n, r, "  Computed upper Cholesky factor R:" );

  b = r8mat_mtm_new ( n, n, n, r, r );
  r8mat_print ( n, n, b, "  Product R'R:" );

  free ( b );
  free ( r );

  return;
}

