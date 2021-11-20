# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "fastgl.h"

int main ( int argc, char **argv );
void besseljzero_test ( );
void besselj1squared_test ( );
void glpair_test ( );
void glpairs_test ( );
void glpairtabulated_test ( );
void legendre_theta_test ( );
void legendre_weight_test ( );

/******************************************************************************/

int main ( int argc, char **argv ) 

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for FASTGL_TEST.

  Discussion:

    FASTGL_TEST tests FASTGL.

  Licensing:

    This code is distributed under the BSD license. 

  Modified:

    06 January 2016

  Author:

    Ignace Bogaert

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "FASTGL_TEST\n" );
  printf ( "  C version.\n" );
  printf ( "  Test the FASTGL library.\n" );

  printf ( "\n" );
  printf ( "  This program shows examples for the Gauss-Legendre quadrature\n" );
  printf ( "  rules computed with GLPair(l, k)\n" );
  printf ( "  l is the number of nodes in the rule\n" );
  printf ( "  k is the index of the node that will be computed.\n" );
  printf ( "\n" );
  printf ( "  The computation is based on the following paper:\n" );
  printf ( "    Ignace Bogaert,\n" );
  printf ( "    Iteration-Free Computation of Gauss-Legendre Quadrature Nodes and Weights\n" );
  printf ( "    SIAM Journal of Scientific Computing,\n" );
  printf ( "    Volume 36, Number 3, 2014, pages A1008-1026\n" );
  printf ( "\n" );
  printf ( "  The main features of this software are:\n" );
  printf ( "  * Speed: due to the simple formulas and the O(1) complexity\n" );
  printf ( "    computation of individual Gauss-Legendre quadrature nodes \n" );
  printf ( "    and weights. This also makes it perfectly compatible with\n" );
  printf ( "    parallel computing paradigms such as multithreading and MPI.\n" );
  printf ( "  * Accuracy: the error on the nodes and weights is within a\n" );
  printf ( "    few ulps (see the paper for details).\n" );

  besseljzero_test ( );
  besselj1squared_test ( );
  glpair_test ( );
  glpairs_test ( );
  glpairtabulated_test ( );
  legendre_theta_test ( );
  legendre_weight_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "FASTGL_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void besseljzero_test ( )

/******************************************************************************/
/*
  Purpose:

    BESSELJZERO_TEST tests BESSELJZERO.

  Modified:

    03 January 2016

  Author:

    John Burkardt

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  double j0x;
  int k;
  double x;

  printf ( "\n" );
  printf ( "BESSELJZERO_TEST:\n" );
  printf ( "  BESSELJZERO returns the K-th zero of J0(X).\n" );
  printf ( "\n" );
  printf ( "   K           X(K)                  J0(X(K))\n" );
  printf ( "\n" );

  for ( k = 1; k <= 30; k++ )
  {
    x = besseljzero ( k );
    j0x = j0 ( x );
    printf ( "  %2d  %24.16g  %24.16g\n", k, x, j0x );
  }

  return;
}
/******************************************************************************/

void besselj1squared_test ( )

/******************************************************************************/
/*
  Purpose:

    BESSELJ1SQUARED_TEST tests BESSELJ1SQUARED.

  Modified:

    03 January 2016

  Author:

    John Burkardt

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  double f1;
  double f2;
  int k;
  double x;

  printf ( "\n" );
  printf ( "BESSELJ1SQUARED_TEST:\n" );
  printf ( "  BESSELJ1SQUARED returns the square of the Bessel J1(X) function\n" );
  printf ( "  at the K-th zero of J0(X).\n" );
  printf ( "\n" );
  printf ( "   K           X(K)                    J1(X(K))^2                 BESSELJ1SQUARED\n" );
  printf ( "\n" );

  for ( k = 1; k <= 30; k++ )
  {
    x = besseljzero ( k );
    f1 = pow ( j1 ( x ), 2 );
    f2 = besselj1squared ( k );
    printf ( "  %2d  %24.16g  %24.16g  %24.16g\n", k, x, f1, f2 );
  }

  return;
}
/******************************************************************************/

void glpair_test ( )

/******************************************************************************/
/*
  Purpose:

    GLPAIR_TEST tests GLPAIR.

  Discussion:

    Test the numerical integration of ln(x) over the range [0,1].
    Normally, one would not use Gauss-Legendre quadrature for this,
    but for the sake of having an example with l > 100, this is included.

  Modified:

    03 January 2016

  Author:

    Ignace Bogaert

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  int k;
  int l;
  int p;
  double q;
  double theta;
  double weight;
  double x;

  printf ( "\n" );
  printf ( "GLPAIR_TEST:\n" );
  printf ( "  integral ( 0 <= x <= 1 ) ln(x) dx.\n" );
  printf ( "\n" );
  printf ( "    Nodes           Estimate\n" );
  printf ( "\n" );

  l = 1;
  for ( p = 0; p <= 6; p++ )
  {
    q = 0.0;
    for ( k = 1; k <= l; k++ )
    {
      glpair ( l, k, &theta, &weight, &x );
      q = q + 0.5 * weight * log ( 0.5 * ( x + 1.0 ) );
    }
    printf ( "  %7d       %24.16g\n", l, q );
    l = l * 10;
  }
  printf ( "\n" );
  printf ( "    Exact            -1.0\n" );

  return;
}
/******************************************************************************/

void glpairs_test ( )

/******************************************************************************/
/*
  Purpose:

    GLPAIRS_TEST tests GLPAIRS.

  Discussion:

    Test the numerical integration of cos(1000 x) over the range [-1,1]
    for varying number of Gauss-Legendre quadrature nodes l.
    The fact that only twelve digits of accuracy are obtained is due to the 
    condition number of the summation.

  Modified:

    03 January 2016

  Author:

    Ignace Bogaert

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  int k;
  int l;
  double q;
  double theta;
  double weight;
  double x;

  printf ( "\n" );
  printf ( "GLPAIRS_TEST:\n" );
  printf ( "  integral ( -1 <= x <= 1 ) cos(1000 x) dx\n" );
  printf ( "\n" );
  printf ( "    Nodes           Estimate\n" );
  printf ( "\n" );

  for ( l = 500; l <= 600; l = l + 20 )
  {
    q = 0.0E+00;
    for ( k = 1; k <= l; k++ )
    {
      glpairs ( l, k, &theta, &weight, &x );
      q = q + weight * cos ( 1000.0E+00 * x );
    }
    printf ( "  %7d       %24.16g\n", l, q );
  }
  printf ( "\n" );
  printf ( "    Exact       %24.16g\n", 0.002E+00 * sin ( 1000.0E+00 ) );

  return;
}
/******************************************************************************/

void glpairtabulated_test ( )

/******************************************************************************/
/*
  Purpose:

    GLPAIRTABULATED_TEST tests GLPAIRTABULATED.

  Discussion:

    Test the numerical integration of exp(x) over the range [-1,1]
    for varying number of Gauss-Legendre quadrature nodes l.

  Modified:

    03 January 2016

  Author:

    Ignace Bogaert

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  size_t k;
  size_t l;
  double q;
  double theta;
  double weight;
  double x;

  printf ( "\n" );
  printf ( "GLPAIRTABULATED_TEST:\n" );
  printf ( "  integral ( -1 <= x <= 1 ) exp(x) dx\n" );
  printf ( "\n" );
  printf ( "    Nodes           Estimate\n" );
  printf ( "\n" );

  for ( l = 1; l <= 9; l++ )
  {
    q = 0.0E+00;
    for ( k = 1; k <= l; k++ )
    {
      glpairtabulated ( l, k, &theta, &weight, &x );
      q = q + weight * exp ( x );
    }
    printf ( "  %7d    %24.16g\n", ( int ) l, q );
  }
  printf ( "\n" );
  printf ( "    Exact    %24.16g\n", exp ( 1.0E+00 ) - exp ( -1.0E+00 ) );

  return;
}
/******************************************************************************/

void legendre_theta_test ( )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_THETA_TEST tests LEGENDRE_THETA.

  Modified:

    06 January 2016

  Author:

    John Burkardt

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  int k;
  int l;
  double theta;

  printf ( "\n" );
  printf ( "LEGENDRE_THETA_TEST:\n" );
  printf ( "  LEGENDRE_THETA returns the K-th theta value for\n" );
  printf ( "  a Gauss Legendre rule of order L.\n" );

  for ( l = 1; l <= 10; l++ )
  {
    printf ( "\n" );
    printf ( "  Gauss Legendre rule of order %d\n", l );
    printf ( "\n" );
    printf ( "   K       Theta      Cos(Theta)\n" );
    printf ( "\n" );
    for ( k = 1; k <= l; k++ )
    {
      theta = legendre_theta ( l, k );
      printf ( "  %2d  %14.6g  %14.6g\n", k, theta, cos ( theta ) );
    }
  }

  return;
}
/******************************************************************************/

void legendre_weight_test ( )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_WEIGHT_TEST tests LEGENDRE_WEIGHT.

  Modified:

    06 January 2016

  Author:

    John Burkardt

  Reference:

    Ignace Bogaert,
    Iteration-free computation of Gauss-Legendre quadrature nodes and weights,
    SIAM Journal on Scientific Computing,
    Volume 36, Number 3, 2014, pages A1008-1026.
*/
{
  int k;
  int l;
  double weight;

  printf ( "\n" );
  printf ( "LEGENDRE_WEIGHT_TEST:\n" );
  printf ( "  LEGENDRE_WEIGHT returns the K-th weight for\n" );
  printf ( "  a Gauss Legendre rule of order L.\n" );

  for ( l = 1; l <= 10; l++ )
  {
    printf ( "\n" );
    printf ( "  Gauss Legendre rule of order %d\n", l );
    printf ( "\n" );
    printf ( "   K       Weight\n" );
    printf ( "\n" );
    for ( k = 1; k <= l; k++ )
    {
      weight = legendre_weight ( l, k );
      printf ( "  %2d  %14.6g\n", k, weight );
    }
  }

  return;
}
