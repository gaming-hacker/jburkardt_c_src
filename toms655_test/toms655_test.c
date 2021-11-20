# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "toms655.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( int nt, int kind, double alpha, double beta );
void cgqf_test ( int nt, int kind, double alpha, double beta, double a, double b );
void wm_test ( );
void wm_tester ( int m, int kind, double alpha, double beta );
double f ( double x, int i );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TOMS655_TEST.

  Discussion:

    TOMS655_TEST tests the TOMS655 library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 November 2015

  Author:

    John Burkardt
*/
{
  double a;
  double alpha;
  double b;
  double beta;
  int kind;
  int nt;

  timestamp ( );
  printf ( "\n" );
  printf ( "TOMS655_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TOMS655 library.\n" );
 
  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );
/*
  Compute 15 points of an example of each rule.
*/
  for ( kind = 1; kind <= 8; kind++ )
  {
    nt = 15;
    if ( kind == 8 )
    {
      alpha = 1.0;
      beta = - alpha - 2 * nt - 2;
    }
    else
    {
      alpha = 0.0;
      beta = 0.0;
    }
    test10 ( nt, kind, alpha, beta );
  }
/*
  Compute 15 points of an example of each rule using nondefault A, B.
*/
  for ( kind = 1; kind <= 8; kind++ )
  {
    nt = 15;

    if ( kind == 1 )
    {
      alpha = 0.0;
      beta = 0.0;
      a = 0.0;
      b = 1.0;
    }
    else if ( kind == 2 )
    {
      alpha = 0.0;
      beta = 0.0;
      a = 0.0;
      b = 1.0;
    }
    else if ( kind == 3 )
    {
      alpha = 1.0;
      beta = 0.0;
      a = 0.0;
      b = 1.0;
    }
    else if ( kind == 4 )
    {
      alpha = 1.5;
      beta = 0.5;
      a = 0.0;
      b = 1.0;
    }
    else if ( kind == 5 )
    {
      alpha = 1.0;
      beta = 0.0;
      a = 1.0;
      b = 1.0;
    }
    else if ( kind == 6 )
    {
      alpha = 1.0;
      beta = 0.0;
      a = 0.0;
      b = 0.5;
    }
    else if ( kind == 7 )
    {
      alpha = 1.0;
      beta = 0.0;
      a = 0.0;
      b = 1.0;
    }
    else if ( kind == 8 )
    {
      alpha = 1.0;
      beta = - alpha - 2 * nt - 2;
      a = 0.0;
      b = 1.0;
    }

    cgqf_test ( nt, kind, alpha, beta, a, b );
  }

  wm_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TOMS655_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests CIQFS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double alpha;
  double beta;
  int i;
  int key;
  int kind;
  int lu;
  int *mlt;
  int *ndx;
  int nt;
  int nwts;
  double pi = 3.14159265358979323846264338327950;
  double *t;
  double *wts;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Test CIQFS.\n" );
/*
  Number of knots.
*/
  nt = 5;
/*
  Set the knots in the default interval [-1,+1].
*/
  t = ( double * ) malloc ( nt * sizeof ( double ) );

  for ( i = 1; i <= nt; i++ )
  {
    t[i-1] = cos ( ( double ) ( 2 * i - 1 ) * pi / ( double ) ( 2 * nt ) );
  }
/*
  Set the knot multiplicities.
*/
  mlt = ( int * ) malloc ( nt * sizeof ( int ) );
  for ( i = 0; i < nt; i++ )
  {
    mlt[i] = 2;
  }
/*
  Set the size of the weights array.
*/
  nwts = 0;
  for ( i = 0; i < nt; i++ )
  {
    nwts = nwts + mlt[i];
  }
/*
  Because KEY = 1, NDX will be set up for us.
*/
  ndx = ( int * ) malloc ( nt * sizeof ( int ) );
/*
  KEY = 1 indicates that the WTS array should hold the weights
  in the usual order.
*/
  key = 1;
/*
  Request Legendre weight function.
*/
  kind = 1;
/*
  ALPHA, BETA not used in Legendre weight function but set anyway.
*/
  alpha = 0.0;
  beta  = 0.0;
/*
  LU controls printing.
  A positive value requests that we compute and print weights, and
  conduct a moments check.
*/
  lu = 6;
/*
  This call returns the WTS array.
*/
  wts = ciqfs ( nt, t, mlt, nwts, ndx, key, kind, alpha, beta, lu );

  free ( mlt );
  free ( ndx );
  free ( t );
  free ( wts );

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests CIQFS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double a;
  double alpha;
  double b;
  double beta;
  int i;
  int key;
  int kind;
  int lu;
  int *mlt;
  int *ndx;
  int nt;
  int nwts;
  double *t;
  double *wts;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Test CIQF, CIQFS, CGQF and CGQFS\n" );
  printf ( "  with all classical weight functions.\n" );
/*
  Try all 8 weight functions.
*/
  for ( kind = 1; kind <= 8; kind++ )
  {
/*
  Number of knots.
*/
    nt = 5;
/*
  Set parameters ALPHA and BETA.
*/
    alpha = 0.5;
    if ( kind != 8 )
    {
      beta  = 2.0;
    }
    else
    {
      beta = - 16.0;
    }
/*
  Set A and B.
*/
    a = - 0.5;
    b = 2.0;
/*
  LU controls printing.
  A positive value requests that we compute and print weights, and
  conduct a moments check.
*/
    lu = 6;
/*
  Have CGQF compute the knots and weights.
*/
    t = ( double * ) malloc ( nt * sizeof ( double ) );
    wts = ( double * ) malloc ( nt * sizeof ( double ) );

    printf ( "\n" );
    printf ( "  Knots and weights of Gauss quadrature formula\n" );
    printf ( "  computed by CGQF.\n" );
    cgqf ( nt, kind, alpha, beta, a, b, lu, t, wts );
/*
  Now compute the weights for the same knots by CIQF.

  Set the knot multiplicities.
*/
    mlt = ( int * ) malloc ( nt * sizeof ( int ) );
    for ( i = 0; i < nt; i++ )
    {
      mlt[i] = 2;
    }
/*
  Set the size of the weights array.
*/
    nwts = 0;
    for ( i = 0; i < nt; i++ )
    {
      nwts = nwts + mlt[i];
    }
/*
  We need to deallocate and reallocate WTS because it is now of
  dimension NWTS rather than NT.
*/
    free ( wts );
    wts = ( double * ) malloc ( nwts * sizeof ( double ) );
/*
  Because KEY = 1, NDX will be set up for us.
*/
    ndx = ( int * ) malloc ( nt * sizeof ( int ) );
/*
  KEY = 1 indicates that the WTS array should hold the weights
  in the usual order.
*/
    key = 1;

    printf ( "\n" );
    printf ( "  Weights of Gauss quadrature formula computed from the\n" );
    printf ( "  knots by CIQF.\n" );

    wts = ciqf ( nt, t, mlt, nwts, ndx, key, kind, alpha, beta, a, b, lu );

    free ( mlt );
    free ( ndx );
    free ( t );
    free ( wts );
  }
  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests CEIQFS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double alpha;
  double beta;
  int i;
  int kind;
  int *mlt;
  int nt;
  double pi = 3.14159265358979323846264338327950;
  double qfsum;
  double qfsx;
  double *t;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Test CEIQFS.\n" );
/*
  Number of knots.
*/
  nt = 5;
/*
  Set the knots in the default interval [-1,+1].
*/
  t = ( double * ) malloc ( nt * sizeof ( double ) );

  for ( i = 1; i <= nt; i++ )
  {
    t[i-1] = cos ( ( double ) ( 2 * i - 1 ) * pi / ( double ) ( 2 * nt ) );
  }
/*
  Set the knot multiplicities.
*/
  mlt = ( int * ) malloc ( nt * sizeof ( int ) );
  for ( i = 0; i < nt; i++ )
  {
    mlt[i] = 2;
  }
/*
  Set KIND to the Legendre weight function.
*/
  kind = 1;
/*
  ALPHA, BETA not used in Legendre weight function but set anyway.
*/
  alpha = 0.0;
  beta  = 0.0;
/*
  Call CEIQFS to set up the quadrature formula and evaluate it on F.
*/
  qfsum = ceiqfs ( nt, t, mlt, kind, alpha, beta, f );

  printf ( "\n" );
  printf ( "  Integral of sin(x) on -1, 1 by Fejer type rule\n" );
  printf ( "  with %d points of multiplicity 2.\n", nt );
  printf ( "  Quadrature formula:%24.16f\n", qfsum );

  qfsx = cos ( - 1.0 ) - cos ( 1.0 );
  printf ( "  Exact value       :%24.16f\n", qfsx );
  printf ( "  Error             :%13.3e\n", r8_abs ( qfsum - qfsx ) );

  free ( mlt );
  free ( t );

  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 tests CEIQF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double a;
  double alpha;
  double b;
  double beta;
  int i;
  int kind;
  int *mlt;
  int nt;
  double pi = 3.14159265358979323846264338327950;
  double qfsum;
  double qfsx;
  double *t;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  Test CEIQF.\n" );
/*
  Number of knots.
*/
  nt = 5;
/*
  Set the knots in the default interval [-1,+1].
*/
  t = ( double * ) malloc ( nt * sizeof ( double ) );

  for ( i = 1; i <= nt; i++ )
  {
    t[i-1] = cos ( ( double ) ( 2 * i - 1 ) * pi / ( double ) ( 2 * nt ) );
  }
/*
  Set the knot multiplicities.
*/
  mlt = ( int * ) malloc ( nt * sizeof ( int ) );
  for ( i = 0; i < nt; i++ )
  {
    mlt[i] = 2;
  }
/*
  Set KIND to the Legendre weight function.
*/
  kind = 1;
/*
  ALPHA, BETA not used in Legendre weight function but set anyway.
*/
  alpha = 0.0;
  beta  = 0.0;
/*
  Set nonstandard interval A, B.
*/
  a = -0.5;
  b = 2.0;
/*
  Shift knots from [-1,1] to [A,B].
*/
  for ( i = 0; i < nt; i++ )
  {
    t[i] = ( ( b - a ) * t[i] + ( a + b ) ) / 2.0;
  }
/*
  Call CEIQF to set up the quadrature formula and evaluate it on F.
*/
  qfsum = ceiqf ( nt, t, mlt, kind, alpha, beta, a, b, f );

  printf ( "\n" );
  printf ( "  Integral of sin(x) from %f to %f\n", a, b );
  printf ( "  by Fejer type rule with %d points\n", nt );
  printf ( "  of multiplicity 2.\n" );
  printf ( "  Quadrature formula:%24.16f\n", qfsum );

  qfsx = cos ( a ) - cos ( b );
  printf ( "  Exact value       :%24.16f\n", qfsx );
  printf ( "  Error             :%13.3e\n", r8_abs ( qfsum - qfsx ) );

  free ( mlt );
  free ( t );

  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests CLIQFS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double alpha;
  double beta;
  int i;
  int kind;
  int lu;
  int nt;
  double pi = 3.14159265358979323846264338327950;
  double *t;
  double *wts;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Test CLIQFS.\n" );
/*
  Number of knots.
*/
  nt = 5;
/*
  Set the knots in the default interval [-1,+1].
*/
  t = ( double * ) malloc ( nt * sizeof ( double ) );

  for ( i = 1; i <= nt; i++ )
  {
    t[i-1] = cos ( ( double ) ( 2 * i - 1 ) * pi / ( double ) ( 2 * nt ) );
  }
/*
  Request Legendre weight function.
*/
  kind = 1;
/*
  ALPHA, BETA not used in Legendre weight function but set anyway.
*/
  alpha = 0.0;
  beta  = 0.0;
/*
  LU controls printing.
  A positive value requests that we compute and print weights, and
  conduct a moments check.
*/
  lu = 6;
/*
  This call returns the WTS array.
*/
  wts = cliqfs ( nt, t, kind, alpha, beta, lu );

  free ( t );
  free ( wts );
 
  return;
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests CLIQF and EIQFS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double a;
  double alpha;
  double b;
  double beta;
  int i;
  int kind;
  int lu;
  int nt;
  double pi = 3.14159265358979323846264338327950;
  double qfsum;
  double qfsx;
  double *t;
  double *wts;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  Test CLIQF and EIQFS.\n" );
/*
  Number of knots.
*/
  nt = 5;
/*
  Set the knots in the default interval [-1,+1].
*/
  t = ( double * ) malloc ( nt * sizeof ( double ) );

  for ( i = 1; i <= nt; i++ )
  {
    t[i-1] = cos ( ( double ) ( 2 * i - 1 ) * pi / ( double ) ( 2 * nt ) );
  }
/*
  Set KIND to the Legendre weight function.
*/
  kind = 1;
/*
  ALPHA, BETA not used in Legendre weight function but set anyway.
*/
  alpha = 0.0;
  beta  = 0.0;
/*
  Set nonstandard interval A, B.
*/
  a = -0.5;
  b = 2.0;
/*
  Shift knots from [-1,1] to [A,B].
*/
  for ( i = 0; i < nt; i++ )
  {
    t[i] = ( ( b - a ) * t[i] + ( a + b ) ) / 2.0;
  }
/*
  LU controls printout.
*/
  lu = 6;
/*
  Call CLIQF to set up the quadrature formula.
*/
  wts = cliqf ( nt, t, kind, alpha, beta, a, b, lu );
/*
  Call EIQFS to evaluate the quadrature formula.
*/
  qfsum = eiqfs ( nt, t, wts, f );

  printf ( "\n" );
  printf ( "  Integral of sin(x) from %f to %f\n", a, b );
  printf ( "  by Fejer type rule with %d points\n", nt );
  printf ( "  of multiplicity 1.\n" );
  printf ( "  Quadrature formula:%24.16f\n", qfsum );

  qfsx = cos ( a ) - cos ( b );
  printf ( "  Exact value       :%24.16f\n", qfsx );
  printf ( "  Error             :%13.3e\n", r8_abs ( qfsum - qfsx ) );

  free ( t );
  free ( wts );

  return;
}
/******************************************************************************/

void test07 ( )

/******************************************************************************/
/*
  Purpose:

    TEST07 tests CEGQF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double a;
  double alpha;
  double b;
  double beta;
  int kind;
  int nt;
  double qfsum;
  double qfsx;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  Test CEGQF.\n" );
/*
  Number of knots.
*/
  nt = 12;
/*
  Request exponential weight function.
*/
  kind = 7;
/*
  Set ALPHA and BETA.
*/
  alpha = 1.0;
  beta  = 0.0;
/*
  Set interval [A,B].
*/
  a = -0.5;
  b = 2.0;
/*
  Call CEGQF to compute and evaluate the Gauss quadrature formula.
*/
  qfsum = cegqf ( nt, kind, alpha, beta, a, b, f );

  printf ( "\n" );
  printf ( "  Integral of x*sin(x) from %f to %f\n", a, b );
  printf ( "  by Gauss-exponential rule with %d points\n", nt );
  printf ( "  Quadrature formula:%24.16f\n", qfsum );

  qfsx = ( b - a ) * 0.5 * ( cos ( a ) - cos ( b ) ) 
    + sin ( b ) + sin ( a ) - 2.0 * sin ( ( a + b ) / 2.0 );

  printf ( "  Exact value       :%24.16f\n", qfsx );
  printf ( "  Error             :%13.3e\n", r8_abs ( qfsum - qfsx ) );

  return;
}
/******************************************************************************/

void test08 ( )

/******************************************************************************/
/*
  Purpose:

    TEST08 tests CEGQFS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.
*/
{
  double alpha;
  double beta;
  int kind;
  int nt;
  double qfsum;
  double qfsx;

  printf ( "  ----------------------------------------\n" );
  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  Test CEGQFS.\n" );
/*
  Number of knots.
*/
  nt = 12;
/*
  Request exponential weight function.
*/
  kind = 7;
/*
  Set ALPHA and BETA.
*/
  alpha = 1.0;
  beta  = 0.0;
/*
  Call CEGQFS to compute and evaluate the Gauss quadrature formula.
*/
  qfsum = cegqfs ( nt, kind, alpha, beta, f );

  printf ( "\n" );
  printf ( "  Integral of x*sin(x) from -1 to +1\n" );
  printf ( "  by Gauss-exponential rule with %d points.\n", nt );
  printf ( "  Quadrature formula:%24.16f\n", qfsum );

  qfsx = cos ( -1.0 ) - cos ( +1.0 );

  printf ( "  Exact value       :%24.16f\n", qfsx );
  printf ( "  Error             :%13.3e\n", r8_abs ( qfsum - qfsx ) );

  return;
}
/******************************************************************************/

void test09 ( )

/******************************************************************************/
/*
  Purpose:

    TEST09 calls CGQFS to compute and print generalized Gauss-Hermite rules.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    John Burkardt
*/
{
  double alpha;
  double beta;
  int io;
  int kind;
  int nt;
  double *t;
  double *wts;

  printf ( "\n" );
  printf ( "TEST09\n" );
  printf ( "  Call CGQFS to compute generalized Hermite rules.\n" );

  nt = 15;
  kind = 6;
  alpha = 1.0;
  beta = 0.0;
  io = - 6;
  t = ( double * ) malloc ( nt * sizeof ( double ) );
  wts = ( double * ) malloc ( nt * sizeof ( double ) );

  printf ( "\n" );
  printf ( "  NT = %d\n", nt );
  printf ( "  ALPHA = %f\n", alpha );

  cgqfs ( nt, kind, alpha, beta, io, t, wts );

  free ( t );
  free ( wts );

  return;
}
/******************************************************************************/

void test10 ( int nt, int kind, double alpha, double beta )

/******************************************************************************/
/*
  Purpose:

    TEST10 calls CDGQF to compute a quadrature formula.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    John Burkardt
*/
{
  int i;
  double *t;
  double *wts;

  printf ( "\n" );
  printf ( "TEST10\n" );
  printf ( "  Call CDGQF to compute a quadrature formula.\n" );
  printf ( "\n" );
  printf ( "  KIND = %d\n", kind );
  printf ( "  ALPHA = %f\n", alpha );
  printf ( "  BETA  = %f\n", beta );

  t = ( double * ) malloc ( nt * sizeof ( double ) );
  wts = ( double * ) malloc ( nt * sizeof ( double ) );

  cdgqf ( nt, kind, alpha, beta, t, wts );

  printf ( "\n" );
  printf ( " Index     Abscissas                 Weights\n" );
  printf ( "\n" );
  for ( i = 0; i < nt; i++ )
  {
    printf ( "  %4d  %24.16g  %24.16g\n", i, t[i], wts[i] );
  }

  free ( t );
  free ( wts );

  return;
}
/******************************************************************************/

void cgqf_test ( int nt, int kind, double alpha, double beta, double a, double b )

/******************************************************************************/
/*
  Purpose:

    CGQF_TEST calls CGQF to compute a quadrature formula.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    John Burkardt
*/
{
  int i;
  int lo;
  double *t;
  double *wts;

  printf ( "\n" );
  printf ( "CGQF_TEST\n" );
  printf ( "  Call CGQF to compute a quadrature formula.\n" );
  printf ( "\n" );
  printf ( "  KIND = %d\n", kind );
  printf ( "  ALPHA = %f\n", alpha );
  printf ( "  BETA  = %f\n", beta );
  printf ( "  A     = %f\n", a );
  printf ( "  B     = %f\n", b );

  lo = 0;
  t = ( double * ) malloc ( nt * sizeof ( double ) );
  wts = ( double * ) malloc ( nt * sizeof ( double ) );

  cgqf ( nt, kind, alpha, beta, a, b, lo, t, wts );

  printf ( "\n" );
  printf ( " Index     Abscissas                 Weights\n" );
  printf ( "\n" );
  for ( i = 0; i < nt; i++ )
  {
    printf ( "  %4d  %24.16g  %24.16g\n", i, t[i], wts[i] );
  }

  free ( t );
  free ( wts );

  return;
}
/******************************************************************************/

void wm_test ( )

/******************************************************************************/
/*
  Purpose:

    WM_TEST calls WM_TESTER with various parameter values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 November 2015

  Author:

    John Burkardt.
*/
{
  double alpha;
  double beta;
  int kind;
  int m;

  m = 5;
  kind = 1;
  alpha = 0.0;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 2;
  alpha = 0.0;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 3;
  alpha = 0.5;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 4;
  alpha = 0.25;
  beta = 0.75;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 5;
  alpha = 2.0;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 6;
  alpha = 1.0;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 7;
  alpha = 2.0;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 8;
  alpha = -0.5;
  beta = -6.0;
  wm_tester ( m, kind, alpha, beta );

  m = 5;
  kind = 9;
  alpha = 0.0;
  beta = 0.0;
  wm_tester ( m, kind, alpha, beta );

  return;
}
/******************************************************************************/

void wm_tester ( int m, int kind, double alpha, double beta )

/******************************************************************************/
/*
  Purpose:

    WM_TESTER tests WM.

  Discussion:

    Moment(K) = Integral ( A <= X <= B ) X^(K-1) * W(X) dx

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 November 2015

  Author:

    John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int M, the number of moments to evaluate.

    Input, int KIND, the rule.
    1, Legendre,             (a,b)       1.0
    2, Chebyshev Type 1,     (a,b)       ((b-x)*(x-a))^(-0.5)
    3, Gegenbauer,           (a,b)       ((b-x)*(x-a))^alpha
    4, Jacobi,               (a,b)       (b-x)^alpha*(x-a)^beta
    5, Generalized Laguerre, (a,+oo)     (x-a)^alpha*exp(-b*(x-a))
    6, Generalized Hermite,  (-oo,+oo)   |x-a|^alpha*exp(-b*(x-a)^2)
    7, Exponential,          (a,b)       |x-(a+b)/2.0|^alpha
    8, Rational,             (a,+oo)     (x-a)^alpha*(x+b)^beta
    9, Chebyshev Type 2,     (a,b)       ((b-x)*(x-a))^(+0.5)

    Input, double ALPHA, the value of Alpha, if needed.

    Input, double BETA, the value of Beta, if needed.
*/
{
  int i;
  double *w;

  w = wm ( m, kind, alpha, beta );

  printf ( "\n" );
  printf ( "WM_TESTER:\n" );
  printf ( "  WM_TEST computes moments for rule %d\n", kind );
  printf ( "  with ALPHA = %g, BETA = %g\n", alpha, beta );
  printf ( "\n" );
  printf ( "  Order          Moment\n" );
  printf ( "\n" );
  for ( i = 0; i < m; i++ )
  {
    printf ( "     %2d  %14.6g\n", i, w[i] );
  }

  free ( w );

  return;
}
/******************************************************************************/

double f ( double x, int i )

/******************************************************************************/
/*
  Purpose:

    F returns values of the integrand or its derivatives.

  Discussion:

    This function is an example of an integrand function.

    The package can generate quadrature formulas that use derivative 
    information as well as function values.  Therefore, this routine is
    set up to provide derivatives of any order as well as the function
    value.  In an actual application, the highest derivative needed
    is of order one less than the highest knot multiplicity.

    In other words, in the usual case where knots are not repeated,
    this routine only needs to return function values, not any derivatives.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Parameters:

    Input, double X, the evaluation point.

    Input, int I, the order of the derivative of F to
    be evaluated.

    Output, double F, the value of the I-th derivative of F at X.
*/
{
  int l;
  double value;

  l = ( i % 4 );

  if ( l == 0 )
  {
    value = sin ( x );
  }
  else if ( l == 1 )
  {
    value = cos ( x );
  }
  else if ( l == 2 )
  {
    value = - sin ( x );
  }
  else if ( l == 3 )
  {
    value = - cos ( x );
  }

  return value;
}
