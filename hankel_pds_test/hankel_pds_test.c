# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "hankel_pds.h"

int main ( );
void hankel_pds_cholesky_lower_test01 ( );
void hankel_pds_cholesky_lower_test02 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    HANKEL_PDS_TEST tests HANKEL_PDS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "HANKEL_PDS_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the HANKEL_PDS library.\n" );

  hankel_pds_cholesky_lower_test01 ( );
  hankel_pds_cholesky_lower_test02 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "HANKEL_PDS_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void hankel_pds_cholesky_lower_test01 ( )

/******************************************************************************/
/*
  Purpose:

    HANKEL_PDS_CHOLESKY_LOWER_TEST01 tests HANKEL_PDS_CHOLESKY_LOWER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2017

  Author:

    John Burkardt
*/
{
  double *h;
  int i;
  double *l;
  double *lii;
  double *liim1;
  int n;
  int seed;

  printf ( "\n" );
  printf ( "HANKEL_PDS_CHOLESKY_LOWER_TEST01\n" );
  printf ( "  HANKEL_PDS_CHOLESKY_LOWER computes a lower Cholesky\n" );
  printf ( "  matrix L such that the matrix H = L * L' is a\n" );
  printf ( "  positive definite (symmetric) Hankel matrix.\n" );

  n = 5;
/*
  Example 1:
*/
  lii = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    lii[i] = 1.0;
  }

  liim1 = ( double * ) malloc ( ( n - 1 ) * sizeof ( double ) );
  for ( i = 0; i < n - 1; i++ )
  {
    liim1[i] = 1.0;
  }

  l = hankel_pds_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  free ( h );
  free ( l );
  free ( lii );
  free ( liim1 );
/*
  Example 2:
*/
  lii = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    lii[i] = ( double ) ( i + 1 );
  }

  liim1 = ( double * ) malloc ( ( n - 1 ) * sizeof ( double ) );
  for ( i = 0; i < n - 1; i++ )
  {
    liim1[i] = ( double ) ( n - 1 - i );
  }

  l = hankel_pds_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  free ( h );
  free ( l );
  free ( lii );
  free ( liim1 );
/*
  Example 3:
*/
  seed = 123456789;
  lii = r8vec_uniform_01_new ( n, &seed );
  liim1 = r8vec_uniform_01_new ( n - 1, &seed );

  l = hankel_pds_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  free ( h );
  free ( l );
  free ( lii );
  free ( liim1 );

  return;
}
/******************************************************************************/

void hankel_pds_cholesky_lower_test02 ( )

/******************************************************************************/
/*
  Purpose:

    HANKEL_PDS_CHOLESKY_LOWER_TEST02 tests HANKEL_PDS_CHOLESKY_LOWER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2017

  Author:

    John Burkardt
*/
{
  int flag;
  double *h;
  double *h2;
  int i;
  double *l;
  double *l2;
  double *lii;
  double *liim1;
  int n;

  printf ( "\n" );
  printf ( "HANKEL_PDS_CHOLESKY_LOWER_TEST02\n" );
  printf ( "  HANKEL_PDS_CHOLESKY_LOWER computes a lower Cholesky\n" );
  printf ( "  matrix L such that the matrix H = L * L' is a\n" );
  printf ( "  positive definite (symmetric) Hankel matrix.\n" );

  n = 5;

  lii = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    lii[i] = 1.0;
  }

  liim1 = ( double * ) malloc ( ( n - 1 ) * sizeof ( double ) );
  for ( i = 0; i < n - 1; i++ )
  {
    liim1[i] = 1.0;
  }

  l = hankel_pds_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  l2 = r8mat_cholesky_factor ( n, h, &flag );

  r8mat_print ( n, n, l2, "  The Cholesky factor L2 of H:" );

  h2 = r8mat_mmt_new ( n, n, n, l2, l2 );

  r8mat_print ( n, n, h2, "  The Hankel matrix H2 = L2 * L2':" );

  free ( h );
  free ( h2 );
  free ( l );
  free ( l2 );
  free ( lii );
  free ( liim1 );

  return;
}
