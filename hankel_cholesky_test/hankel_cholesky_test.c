# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "hankel_cholesky.h"

int main ( );
void hankel_cholesky_upper_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for HANKEL_CHOLESKY_TEST.

  Discussion:

    HANKEL_CHOLESKY_TEST tests HANKEL_CHOLESKY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 January 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "HANKEL_CHOLESKY_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the HANKEL_CHOLESKY library.\n" );

  hankel_cholesky_upper_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "HANKEL_CHOLESKY_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void hankel_cholesky_upper_test ( )

/******************************************************************************/
/*
  Purpose:

    HANKEL_CHOLESKY_UPPER_TEST tests HANKEL_CHOLESKY_UPPER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 January 2017

  Author:

    John Burkardt
*/
{
  int flag;
  double *h;
  double *hanti;
  int i;
  int j;
  double *l;
  double *lii;
  double *liim1;
  int n;
  double *r1;
  double *r2;
  int seed;

  n = 5;

  printf ( "\n" );
  printf ( "HANKEL_CHOLESKY_UPPER_TEST\n" );
  printf ( "  HANKEL_CHOLESKY_UPPER is given a Hankel matrix H and\n" );
  printf ( "  computes an upper triangular matrix R such that\n" );
  printf ( "  H = R' * R\n" );
/*
  Get a Hankel matrix that is positive definite.
*/
  seed = 123456789;
  lii = r8vec_uniform_01_new ( n, &seed );
  liim1 = r8vec_uniform_01_new ( n - 1, &seed );
  l = hankel_pds_cholesky_lower ( n, lii, liim1 );
  h = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, h, "  The Hankel matrix H:" );
/*
  Compute R using R8MAT_CHOLESKY_FACTOR_UPPER.
*/
  r1 = r8mat_cholesky_factor_upper ( n, h, &flag );
  if ( flag != 0 )
  {
    printf ( "\n" );
    printf ( " R8MAT_CHOLESKY_FACTOR_UPPER says H is not positive definite.\n" );
  }
  else
  {
    r8mat_print ( n, n, r1, "  R computed by R8MAT_CHOLESKY_FACTOR_UPPER:" );
  }
/*
  Compute R using HANKEL_CHOLESKY.
*/
  hanti = ( double * ) malloc ( ( 2 * n - 1 ) * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    hanti[i] = h[i+0*n];
  }
  for ( j = 1; j < n; j++ )
  {
    hanti[n-1+j] = h[n-1+j*n];
  }
  r2 = hankel_cholesky_upper ( n, hanti );
  r8mat_print ( n, n, r2, "  R computed by HANKEL_CHOLESKY:" );

  free ( hanti );
  free ( l );
  free ( lii );
  free ( liim1 );
  free ( r1 );
  free ( r2 );

  return;
}
