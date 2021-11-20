# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <complex.h>
# include <string.h>

# include "test_zero.h"

/******************************************************************************/

void bisection ( double fatol, int step_max, int prob, double xatol, 
  double *xa, double *xb, double *fxa, double *fxb )

/******************************************************************************/
/*
  Purpose:

    BISECTION carries out the bisection method to seek a root of F(X) = 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, double FATOL, an absolute error tolerance for
    the function value of the root.  If an approximate root X satisfies
      ABS ( F ( X ) ) <= FATOL, then X will be accepted as the
    root and the iteration will be terminated.

    Input, int STEP_MAX, the maximum number of steps
    allowed for an iteration.

    Input, int PROB, the index of the function whose root is
    to be sought.

    Input, double XATOL, an absolute error tolerance for the root.

    Input/output, double *XA, *XB, two points at which the
    function differs in sign.  On output, these values have been adjusted
    to a smaller interval.

    Input/output, double *FXA, *FXB, the value of the function
    at XA and XB.
*/
{
  double fxc;
  int step_num;
  double t;
  double xc;

  printf ( "\n" );
  printf ( "BISECTION\n" );
  printf ( "\n" );
  printf ( "  Step      XA            XB             F(XA)         F(XB)\n" );
  printf ( "\n" );
/*
  Make A the root with negative F, B the root with positive F.
*/
  if ( 0.0 < *fxa )
  {
    t = *xa;
    *xa = *xb;
    *xb = t;
    t = *fxa;
    *fxa = *fxb;
    *fxb = t;
  }

  step_num = 0;
/*
  Loop
*/
  for ( ; ; )
  {
    printf ( "  %4d  %14g  %14g  %14g  %14g\n", step_num, *xa, *xb, *fxa, *fxb );

    step_num = step_num + 1;

    if ( step_max < step_num )
    {
      printf ( "\n" );
      printf ( "  Maximum number of steps taken without convergence.\n" );
      break;
    }

    if ( r8_abs ( *xa - *xb ) < xatol )
    {
      printf ( "\n" );
      printf ( "  Interval small enough for convergence.\n" );
      break;
    }

    if ( r8_abs ( *fxa ) <= fatol || r8_abs ( *fxb ) <= fatol )
    {
      printf ( "\n" );
      printf ( "  Function small enough for convergence.\n" );
      break;
    }
/*
  Compute the next iterate.
*/
    xc = 0.5 * ( *xa + *xb );
    fxc = p00_fx ( prob, xc );
/*
  Replace one of the old points.
*/
    if ( fxc < 0.0 )
    {
      *xa = xc;
      *fxa = fxc;
    }
    else
    {
      *xb = xc;
      *fxb = fxc;
    }
  }

  return;
}
/******************************************************************************/

void brent ( double fatol, int step_max, int prob, double xatol, double xrtol, 
  double *xa, double *xb, double *fxa, double *fxb )

/******************************************************************************/
/*
  Purpose:

    BRENT implements the Brent bisection-based zero finder.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 May 2011

  Author:

    John Burkardt

  Reference:

    Richard Brent,
    Algorithms for Minimization without Derivatives,
    Prentice Hall, 1973.

  Parameters:

    Input, double FATOL, an absolute error tolerance for the
    function value of the root.  If an approximate root X satisfies
      ABS ( F ( X ) ) <= FATOL, then X will be accepted as the
    root and the iteration will be terminated.

    Input, int STEP_MAX, the maximum number of steps allowed
    for an iteration.

    Input, int PROB, the index of the function whose root is
    to be sought.

    Input, double XATOL, XRTOL, absolute and relative error
    tolerances for the root.

    Input/output, double *XA, *XB, two points at which the
    function differs in sign.  On output, these values have been adjusted
    to a smaller interval.

    Input/output, double *FXA, *FXB, the value of the function
    at XA and XB.
*/
{
  double d;
  double e;
  double fxc;
  int step_num;
  double p;
  double q;
  double r;
  double s;
  double xc;
  double xm;
  double xtol;
/*
  Initialization.
*/
  printf ( "\n" );
  printf ( "BRENT\n" );
  printf ( "\n" );
  printf ( "  Step      XA            XB             F(XA)         F(XB)\n" );
  printf ( "\n" );

  step_num = 0;

  *fxa = p00_fx ( prob, *xa );
  *fxb = p00_fx ( prob, *xb );
/*
  Check that f(ax) and f(bx) have different signs.
*/
  if ( ( *fxa < 0.0 && *fxb < 0.0 ) || ( 0.0 < *fxa && 0.0 < *fxb ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "BRENT - Fatal error!\n" );
    fprintf ( stderr, "  F(XA) and F(XB) have same sign.\n" );
    exit ( 1 );
  }

  xc = *xa;
  fxc = *fxa;
  d = *xb - *xa;
  e = d;

  for ( ; ; )
  {
    printf ( "  %4d  %14g  %14g  %14g  %14g\n", step_num, *xb, xc, *fxb, fxc );

    step_num = step_num + 1;

    if ( step_max < step_num )
    {
      printf ( "\n" );
      printf ( "  Maximum number of steps taken.\n" );
      break;
    }

    if ( r8_abs ( fxc ) < r8_abs ( *fxb ) )
    {
      *xa = *xb;
      *xb = xc;
      xc = *xa;
      *fxa = *fxb;
      *fxb = fxc;
      fxc = *fxa;
    }

    xtol = 2.0 * xrtol * r8_abs ( *xb ) + 0.5 * xatol;
/*
  XM is the halfwidth of the current change-of-sign interval.
*/
    xm = 0.5 * ( xc - *xb );

    if ( r8_abs ( xm ) <= xtol )
    {
      printf ( "\n" );
      printf ( "  Interval small enough for convergence.\n" );
      break;
    }

    if ( r8_abs ( *fxb ) <= fatol )
    {
      printf ( "\n" );
      printf ( "  Function small enough for convergence.\n" );
      break;
    }
/*
  See if a bisection is forced.
*/
    if ( r8_abs ( e ) < xtol || r8_abs ( *fxa ) <= r8_abs ( *fxb ) )
    {
      d = xm;
      e = d;
    }
    else
    {
      s = *fxb / *fxa;
/*
  Linear interpolation.
*/
      if ( *xa == xc )
      {
        p = 2.0 * xm * s;
        q = 1.0 - s;
      }
/*
  Inverse quadratic interpolation.
*/
      else
      {
        q = *fxa / fxc;
        r = *fxb / fxc;
        p = s * ( 2.0 * xm * q * ( q - r ) - ( *xb - *xa ) * ( r - 1.0 ) );
        q = ( q - 1.0 ) * ( r - 1.0 ) * ( s - 1.0 );

      }

      if ( 0.0 < p )
      {
        q = - q;
      }
      else
      {
        p = - p;
      }

      s = e;
      e = d;

      if ( 3.0 * xm * q - r8_abs ( xtol * q ) <= 2.0 * p ||
           r8_abs ( 0.5 * s * q ) <= p )
      {
        d = xm;
        e = d;
      }
      else
      {
        d = p / q;
      }
    }
/*
  Save in XA, FXA the previous values of XB, FXB.
*/
    *xa = *xb;
    *fxa = *fxb;
/*
  Compute the new value of XB, and evaluate the function there.
*/
    if ( xtol < r8_abs ( d ) )
    {
      *xb = *xb + d;
    }
    else if ( 0.0 < xm )
    {
      *xb = *xb + xtol;
    }
    else if ( xm <= 0.0 )
    {
      *xb = *xb - xtol;
    }

    *fxb = p00_fx ( prob, *xb );
/*
  If the new FXB has the same sign as FXC, then replace XC by XA.
*/
    if ( ( 0.0 < *fxb && 0.0 < fxc ) || ( *fxb < 0.0 && fxc < 0.0 ) )
    {
      xc = *xa;
      fxc = *fxa;
      d = *xb - *xa;
      e = d;
    }
  }
  return;
}
/******************************************************************************/

void muller ( double fatol, int step_max, int prob, double xatol, double xrtol, 
  double *xa, double *xb, double *xc, double *fxa, double *fxb, double *fxc )

/******************************************************************************/
/*
  Purpose:

    MULLER carries out Muller's method for seeking a real root of a nonlinear function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, double FATOL, an absolute error tolerance for the
    function value of the root.  If an approximate root X satisfies7
      ABS ( F ( X ) ) <= FATOL, then X will be accepted as the
    root and the iteration will be terminated.

    Input, int STEP_MAX, the maximum number of steps allowed
    for an iteration.

    Input, int PROB, the index of the function whose root is
    to be sought.

    Input, double XATOL, XRTOL, absolute and relative error
    tolerances  for the root.

    Input/output, double *XA, *XB, *XC, three points.

    Input/output, double *FXA, *FXB, *FXC, the value of the
    function at XA, XB, and XC.
*/
{
  double a;
  double b;
  double c;
  int i;
  double t;
  double xd;
  double z1;
  double z2;
/*
  Initialization.
*/
  printf ( "\n" );
  printf ( "MULLER\n" );
  printf ( "\n" );
  printf ( "  Step      XA           XB           XC\n" );
  printf ( "          F(XA)        F(XB)        F(XC)\n" );
  printf ( "\n" );

  i = 0;

  printf ( "  %4d  %12g  %12g  %12g\n", i, *xa, *xb, *xc );
  printf ( "        %12g  %12g  %12g\n", *fxa, *fxb, *fxc );

  for ( i = 1; i <= step_max; i++ )
  {
/*
  Determine the coefficients
    A, B, C
  of the polynomial
    Y(X) = A * (X-X2)**2 + B * (X-X2) + C
  which goes through the data:
    (X1,Y1), (X2,Y2), (X3,Y3).
*/
    a = ( ( *fxa - *fxc ) * ( *xb - *xc ) 
        - ( *fxb - *fxc ) * ( *xa - *xc ) ) / 
          ( ( *xa - *xc ) * ( *xb - *xc ) * ( *xa - *xb ) );

    b = ( ( *fxb - *fxc ) * ( *xa - *xc ) * ( *xa - *xc )
        - ( *fxa - *fxc ) * ( *xb - *xc ) * ( *xb - *xc ) ) / 
        ( ( *xa - *xc ) * ( *xb - *xc ) * ( *xa - *xb ) );

    c = *fxc;
/*
  Get the real roots of the polynomial,
  unless A = 0, in which case the algorithm is breaking down.
*/
    if ( a != 0.0 )
    {
      r8poly2_rroot ( a, b, c, &z1, &z2 );
    }
    else if ( b != 0.0 )
    {
      z2 = - c / b;
    }
    else
    {
      printf ( "\n" );
      printf ( "  Polynomial fitting has failed.\n" );
      printf ( "  Muller''s algorithm breaks down.\n" );
      return;
    }

    xd = *xc + z2;
/*
  Set XA, YA, based on which of XA and XB is closer to XD.
*/
    if ( r8_abs ( xd - *xb ) < r8_abs ( xd - *xa ) )
    {
      t = *xa;
      *xa = *xb;
      *xb = t;
      t = *fxa;
      *fxa = *fxb;
      *fxb = t;
    }
/*
  Set XB, YB, based on which of XB and XC is closer to XD.
*/
    if ( r8_abs ( xd - *xc ) < r8_abs ( xd - *xb ) )
    {
      t = *xb;
      *xb = *xc;
      *xc = t;
      t = *fxb;
      *fxb = *fxc;
      *fxc = t;
    }
/*
  Set XC, YC.
*/
    *xc = xd;
    *fxc = p00_fx ( prob, *xc );

    printf ( "  %4d  %12g  %12g  %12g\n", i, *xa, *xb, *xc );
    printf ( "        %12g  %12g  %12g\n", *fxa, *fxb, *fxc );
/*
  Estimate the relative significance of the most recent correction.
*/
    if ( r8_abs ( z2 ) <= xrtol * r8_abs ( *xc ) + xatol )
    {
      printf ( "\n" );
      printf ( "  Stepsize small enough for convergence.\n" );
      return;
    }

    if ( r8_abs ( *fxc ) < fatol )
    {
      printf ( "\n" );
      printf ( "  Function small enough for convergence.\n" );
      return;
    }
  }

  printf ( "\n" );
  printf ( "  Took maximum number of steps without convergence.\n" );

  return;
}
/******************************************************************************/

void newton ( double fatol, int step_max, int prob, double xatol, double xmin, 
  double xmax, double *xa, double *fxa )

/******************************************************************************/
/*
  Purpose:

    NEWTON carries out Newton's method to seek a root of F(X) = 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, double FATOL, an absolute error tolerance for the
    function value of the root.  If an approximate root X satisfies
      ABS ( F ( X ) ) <= FATOL, then X will be accepted as the
    root and the iteration will be terminated.

    Input, int STEP_MAX, the maximum number of steps allowed
    for an iteration.

    Input, int PROB, the index of the function whose root is
    to be sought.

    Input, double XATOL, an absolute error tolerance for the root.

    Input, double XMIN, XMAX, the interval in which the root should
    be sought.

    Input/output, double *XA, on input, the starting point.  On output,
    the estimated root.

    Input/output, double *FXA,  the value of the function at XA.
*/
{
  double fp;
  int step_num;
  double step;

  step = 0.0;

  printf ( "\n" );
  printf ( "NEWTON\n" );
  printf ( "\n" );
  printf ( "  Step           X          F(X)        FP(X)\n" );
  printf ( "\n" );

  step_num = 0;
  fp = p00_fx1 ( prob, *xa );

  printf ( "  %4d  %10g  %10g  %10g\n", step_num, *xa, *fxa, fp );

  for ( step_num = 1; step_num <= step_max; step_num++ )
  {
    if ( *xa < xmin || xmax < *xa )
    {
      printf ( "\n" );
      printf ( "  The iterate X = %g  has left the region [XMIN,XMAX].\n", *xa );
      return;
    }

    if ( r8_abs ( *fxa ) <= fatol )
    {
      printf ( "\n" );
      printf ( "  The function norm is small enough for convergence.\n" );
      return;
    }

    if ( 1 < step_num && r8_abs ( step ) <= xatol )
    {
      printf ( "\n" );
      printf ( "  The stepsize is small enough for convergence.\n" );
      return;
    }

    if ( fp == 0.0 )
    {
      printf ( "\n" );
      printf ( "  F''(X)=0, the algorithm fails.\n" );
      return;
    }

    step = *fxa / fp;

    *xa = *xa - step;

    *fxa = p00_fx ( prob, *xa );
    fp = p00_fx1 ( prob, *xa );

    printf ( "  %4d  %10g  %10g  %10g\n", step_num, *xa, *fxa, fp );
  }

  printf ( "\n" );
  printf ( "  Took maximum number of steps without convergence.\n" );

  return;
}
/******************************************************************************/

double p00_fx ( int prob, double x )

/******************************************************************************/
/*
  Purpose:

    P00_FX evaluates a function specified by problem number.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Input, double X, the point at which F is to be evaluated.

    Output, double P00_FX, the value of the function at X.
*/
{
  double fx;

  if ( prob == 1 )
  {
    fx = p01_fx ( x );
  }
  else if ( prob == 2 )
  {
    fx = p02_fx ( x );
  }
  else if ( prob == 3 )
  {
    fx = p03_fx ( x );
  }
  else if ( prob == 4 )
  {
    fx = p04_fx ( x );
  }
  else if ( prob == 5 )
  {
    fx = p05_fx ( x );
  }
  else if ( prob == 6 )
  {
    fx = p06_fx ( x );
  }
  else if ( prob == 7 ) 
  {
    fx = p07_fx ( x );
  }
  else if ( prob == 8 )
  {
    fx = p08_fx ( x );
  }
  else if ( prob == 9 )
  {
    fx = p09_fx ( x );
  }
  else if ( prob == 10 )
  {
    fx = p10_fx ( x );
  }
  else if ( prob == 11 )
  {
    fx = p11_fx ( x );
  }
  else if ( prob == 12 )
  {
    fx = p12_fx ( x );
  }
  else if ( prob == 13 )
  {
    fx = p13_fx ( x );
  }
  else if ( prob == 14 )
  {
    fx = p14_fx ( x );
  }
  else if ( prob == 15 )
  {
    fx = p15_fx ( x );
  }
  else if ( prob == 16 )
  {
    fx = p16_fx ( x );
  }
  else if ( prob == 17 )
  {
    fx = p17_fx ( x );
  }
  else if ( prob == 18 )
  {
    fx = p18_fx ( x );
  }
  else if ( prob == 19 )
  {
    fx = p19_fx ( x );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_FX - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return fx;
}
/******************************************************************************/

double p00_fx1 ( int prob, double x )

/******************************************************************************/
/*
  Purpose:

    P00_FX1 evaluates the first derivative of a function specified by problem number.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Input, double X, the abscissa.

    Output, double P00_FX1, the first derivative of the function at X.
*/
{
  double fx1;

  if ( prob == 1 )
  {
    fx1 = p01_fx1 ( x );
  }
  else if ( prob == 2 )
  {
    fx1 = p02_fx1 ( x );
  }
  else if ( prob == 3 )
  {
    fx1 = p03_fx1 ( x );
  }
  else if ( prob == 4 )
  {
    fx1 = p04_fx1 ( x );
  }
  else if ( prob == 5 )
  {
    fx1 = p05_fx1 ( x );
  }
  else if ( prob == 6 )
  {
    fx1 = p06_fx1 ( x );
  }
  else if ( prob == 7 )
  {
    fx1 = p07_fx1 ( x );
  }
  else if ( prob == 8 )
  {
    fx1 = p08_fx1 ( x );
  }
  else if ( prob == 9 )
  {
    fx1 = p09_fx1 ( x );
  }
  else if ( prob == 10 )
  {
    fx1 = p10_fx1 ( x );
  }
  else if ( prob == 11 )
  {
    fx1 = p11_fx1 ( x );
  }
  else if ( prob == 12 )
  {
    fx1 = p12_fx1 ( x );
  }
  else if ( prob == 13 )
  {
    fx1 = p13_fx1 ( x );
  }
  else if ( prob == 14 )
  {
    fx1 = p14_fx1 ( x );
  }
  else if ( prob == 15 )
  {
    fx1 = p15_fx1 ( x );
  }
  else if ( prob == 16 )
  {
    fx1 = p16_fx1 ( x );
  }
  else if ( prob == 17 )
  {
    fx1 = p17_fx1 ( x );
  }
  else if ( prob == 18 )
  {
    fx1 = p18_fx1 ( x );
  }
  else if ( prob == 19 )
  {
    fx1 = p19_fx1 ( x );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_FX1 - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return fx1;
}
/******************************************************************************/

double p00_fx2 ( int prob, double x )

/******************************************************************************/
/*
  Purpose:

    P00_FX2 evaluates the second derivative of a function specified by problem number.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Input, double X, the abscissa.

    Output, double P00_FX2, the second derivative of the function at X.
*/
{
  double fx2;

  if ( prob == 1 )
  {
    fx2 = p01_fx2 ( x );
  }
  else if ( prob == 2 )
  {
    fx2 = p02_fx2 ( x );
  }
  else if ( prob == 3 )
  {
    fx2 = p03_fx2 ( x );
  }
  else if ( prob == 4 )
  {
    fx2 = p04_fx2 ( x );
  }
  else if ( prob == 5 )
  {
    fx2 = p05_fx2 ( x );
  }
  else if ( prob == 6 )
  {
    fx2 = p06_fx2 ( x );
  }
  else if ( prob == 7 )
  {
    fx2 = p07_fx2 ( x );
  }
  else if ( prob == 8 )
  {
    fx2 = p08_fx2 ( x );
  }
  else if ( prob == 9 )
  {
    fx2 = p09_fx2 ( x );
  }
  else if ( prob == 10 )
  {
    fx2 = p10_fx2 ( x );
  }
  else if ( prob == 11 )
  {
    fx2 = p11_fx2 ( x );
  }
  else if ( prob == 12 )
  {
    fx2 = p12_fx2 ( x );
  }
  else if ( prob == 13 )
  {
    fx2 = p13_fx2 ( x );
  }
  else if ( prob == 14 )
  {
    fx2 = p14_fx2 ( x );
  }
  else if ( prob == 15 )
  {
    fx2 = p15_fx2 ( x );
  }
  else if ( prob == 16 )
  {
    fx2 = p16_fx2 ( x );
  }
  else if ( prob == 17 )
  {
    fx2 = p17_fx2 ( x );
  }
  else if ( prob == 18 )
  {
    fx2 = p18_fx2 ( x );
  }
  else if ( prob == 19 )
  {
    fx2 = p19_fx2 ( x );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_FX2 - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return fx2;
}
/******************************************************************************/

int p00_prob_num ( )

/******************************************************************************/
/*
  Purpose:

    P00_PROB_NUM returns the number of problems available.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Output, int P00_PROB_NUM, the number of problems available.
*/
{
  int prob_num;

  prob_num = 19;

  return prob_num;
}
/******************************************************************************/

double *p00_range ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_RANGE returns an interval bounding the root for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Output, double RANGE[2], the minimum and maximum values of
    an interval containing the root.
*/
{
  double *range;

  if ( prob == 1 )
  {
    range = p01_range ( );
  }
  else if ( prob == 2 )
  {
    range = p02_range ( );
  }
  else if ( prob == 3 )
  {
    range = p03_range ( );
  }
  else if ( prob == 4 )
  {
    range = p04_range ( );
  }
  else if ( prob == 5 )
  {
    range = p05_range ( );
  }
  else if ( prob == 6 )
  {
    range = p06_range ( );
  }
  else if ( prob == 7 )
  {
    range = p07_range ( );
  }
  else if ( prob == 8 )
  {
    range = p08_range ( );
  }
  else if ( prob == 9 )
  {
    range = p09_range ( );
  }
  else if ( prob == 10 )
  {
    range = p10_range ( );
  }
  else if ( prob == 11 )
  {
    range = p11_range ( );
  }
  else if ( prob == 12 )
  {
    range = p12_range ( );
  }
  else if ( prob == 13 )
  {
    range = p13_range ( );
  }
  else if ( prob == 14 )
  {
    range = p14_range ( );
  }
  else if ( prob == 15 )
  {
    range = p15_range ( );
  }
  else if ( prob == 16 )
  {
    range = p16_range ( );
  }
  else if ( prob == 17 )
  {
    range = p17_range ( );
  }
  else if ( prob == 18 )
  {
    range = p18_range ( );
  }
  else if ( prob == 19 )
  {
    range = p19_range ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_RANGE - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return range;
}
/******************************************************************************/

double p00_root ( int prob, int i )

/******************************************************************************/
/*
  Purpose:

    P00_ROOT returns a known root for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Input, int I, the index of the requested root.

    Output, double P00_ROOT, the value of the I-th root.
*/
{
  double root;

  if ( prob == 1 )
  {
    root = p01_root ( i );
  }
  else if ( prob == 2 )
  {
    root = p02_root ( i );
  }
  else if ( prob == 3 )
  {
    root = p03_root ( i );
  }
  else if ( prob == 4 )
  {
    root = p04_root ( i );
  }
  else if ( prob == 5 )
  {
    root = p05_root ( i );
  }
  else if ( prob == 6 )
  {
    root = p06_root ( i );
  }
  else if ( prob == 7 )
  {
    root = p07_root ( i );
  }
  else if ( prob == 8 )
  {
    root = p08_root ( i );
  }
  else if ( prob == 9 )
  {
    root = p09_root ( i );
  }
  else if ( prob == 10 )
  {
    root = p10_root ( i );
  }
  else if ( prob == 11 )
  {
    root = p11_root ( i );
  }
  else if ( prob == 12 )
  {
    root = p12_root ( i );
  }
  else if ( prob == 13 )
  {
    root = p13_root ( i );
  }
  else if ( prob == 14 )
  {
    root = p14_root ( i );
  }
  else if ( prob == 15 )
  {
    root = p15_root ( i );
  }
  else if ( prob == 16 )
  {
    root = p16_root ( i );
  }
  else if ( prob == 17 )
  {
    root = p17_root ( i );
  }
  else if ( prob == 18 )
  {
    root = p18_root ( i );
  }
  else if ( prob == 19 )
  {
    root = p19_root ( i );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_ROOT - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p00_root_num ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_ROOT_NUM returns the number of known roots for a problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Output, int P00_ROOT_NUM, the number of known roots.
    This value may be zero.
*/
{
  int root_num;

  if ( prob == 1 )
  {
    root_num = p01_root_num ( );
  }
  else if ( prob == 2 )
  {
    root_num = p02_root_num ( );
  }
  else if ( prob == 3 )
  {
    root_num = p03_root_num ( );
  }
  else if ( prob == 4 )
  {
    root_num = p04_root_num ( );
  }
  else if ( prob == 5 )
  {
    root_num = p05_root_num ( );
  }
  else if ( prob == 6 )
  {
    root_num = p06_root_num ( );
  }
  else if ( prob == 7 )
  {
    root_num = p07_root_num ( );
  }
  else if ( prob == 8 )
  {
    root_num = p08_root_num ( );
  }
  else if ( prob == 9 )
  {
    root_num = p09_root_num ( );
  }
  else if ( prob == 10 )
  {
    root_num = p10_root_num ( );
  }
  else if ( prob == 11 )
  {
    root_num = p11_root_num ( );
  }
  else if ( prob == 12 )
  {
    root_num = p12_root_num ( );
  }
  else if ( prob == 13 )
  {
    root_num = p13_root_num ( );
  }
  else if ( prob == 14 )
  {
    root_num = p14_root_num ( );
  }
  else if ( prob == 15 )
  {
    root_num = p15_root_num ( );
  }
  else if ( prob == 16 )
  {
    root_num = p16_root_num ( );
  }
  else if ( prob == 17 )
  {
    root_num = p17_root_num ( );
  }
  else if ( prob == 18 )
  {
    root_num = p18_root_num ( );
  }
  else if ( prob == 19 )
  {
    root_num = p19_root_num ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_ROOT_NUM - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return root_num;
}
/******************************************************************************/

double p00_start ( int prob, int i )

/******************************************************************************/
/*
  Purpose:

    P00_START returns starting point for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Input, int I, the index of the requested starting point.

    Output, double P00_ROOT, the value of the I-th starting point.
*/
{
  double start;

  if ( prob == 1 )
  {
    start = p01_start ( i );
  }
  else if ( prob == 2 )
  {
    start = p02_start ( i );
  }
  else if ( prob == 3 )
  {
    start = p03_start ( i );
  }
  else if ( prob == 4 )
  {
    start = p04_start ( i );
  }
  else if ( prob == 5 )
  {
    start = p05_start ( i );
  }
  else if ( prob == 6 )
  {
    start = p06_start ( i );
  }
  else if ( prob == 7 )
  {
    start = p07_start ( i );
  }
  else if ( prob == 8 )
  {
    start = p08_start ( i );
  }
  else if ( prob == 9 )
  {
    start = p09_start ( i );
  }
  else if ( prob == 10 )
  {
    start = p10_start ( i );
  }
  else if ( prob == 11 )
  {
    start = p11_start ( i );
  }
  else if ( prob == 12 )
  {
    start = p12_start ( i );
  }
  else if ( prob == 13 )
  {
    start = p13_start ( i );
  }
  else if ( prob == 14 )
  {
    start = p14_start ( i );
  }
  else if ( prob == 15 )
  {
    start = p15_start ( i );
  }
  else if ( prob == 16 )
  {
    start = p16_start ( i );
  }
  else if ( prob == 17 )
  {
    start = p17_start ( i );
  }
  else if ( prob == 18 )
  {
    start = p18_start ( i );
  }
  else if ( prob == 19 )
  {
    start = p19_start ( i );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_START - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p00_start_num ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_START_NUM returns the number of starting points for a problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Output, int P00_START_NUM, the number of starting points.
*/
{
  int start_num;

  if ( prob == 1 )
  {
    start_num = p01_start_num ( );
  }
  else if ( prob == 2 )
  {
    start_num = p02_start_num ( );
  }
  else if ( prob == 3 )
  {
    start_num = p03_start_num ( );
  }
  else if ( prob == 4 )
  {
    start_num = p04_start_num ( );
  }
  else if ( prob == 5 )
  {
    start_num = p05_start_num ( );
  }
  else if ( prob == 6 )
  {
    start_num = p06_start_num ( );
  }
  else if ( prob == 7 )
  {
    start_num = p07_start_num ( );
  }
  else if ( prob == 8 )
  {
    start_num = p08_start_num ( );
  }
  else if ( prob == 9 )
  {
    start_num = p09_start_num ( );
  }
  else if ( prob == 10 )
  {
    start_num = p10_start_num ( );
  }
  else if ( prob == 11 )
  {
    start_num = p11_start_num ( );
  }
  else if ( prob == 12 )
  {
    start_num = p12_start_num ( );
  }
  else if ( prob == 13 )
  {
    start_num = p13_start_num ( );
  }
  else if ( prob == 14 )
  {
    start_num = p14_start_num ( );
  }
  else if ( prob == 15 )
  {
    start_num = p15_start_num ( );
  }
  else if ( prob == 16 )
  {
    start_num = p16_start_num ( );
  }
  else if ( prob == 17 )
  {
    start_num = p17_start_num ( );
  }
  else if ( prob == 18 )
  {
    start_num = p18_start_num ( );
  }
  else if ( prob == 19 )
  {
    start_num = p19_start_num ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_START_NUM - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return start_num;
}
/******************************************************************************/

char *p00_title ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_TITLE returns the title for a given problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Output, char *P00_TITLE, the title of the given problem.
*/
{
  char *title;

  if ( prob == 1 )
  {
    title = p01_title ( );
  }
  else if ( prob == 2 )
  {
    title = p02_title ( );
  }
  else if ( prob == 3 )
  {
    title = p03_title ( );
  }
  else if ( prob == 4 )
  {
    title = p04_title ( );
  }
  else if ( prob == 5 )
  {
    title = p05_title ( );
  }
  else if ( prob == 6 )
  {
    title = p06_title ( );
  }
  else if ( prob == 7 )
  {
    title = p07_title ( );
  }
  else if ( prob == 8 )
  {
    title = p08_title ( );
  }
  else if ( prob == 9 )
  {
    title = p09_title ( );
  }
  else if ( prob == 10 )
  {
    title = p10_title ( );
  }
  else if ( prob == 11 )
  {
    title = p11_title ( );
  }
  else if ( prob == 12 )
  {
    title = p12_title ( );
  }
  else if ( prob == 13 )
  {
    title = p13_title ( );
  }
  else if ( prob == 14 )
  {
    title = p14_title ( );
  }
  else if ( prob == 15 )
  {
    title = p15_title ( );
  }
  else if ( prob == 16 )
  {
    title = p16_title ( );
  }
  else if ( prob == 17 )
  {
    title = p17_title ( );
  }
  else if ( prob == 18 )
  {
    title = p18_title ( );
  }
  else if ( prob == 19 )
  {
    title = p19_title ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_TITLE - Fatal error!\n" );
    printf ( "  Illegal problem number = %d\n", prob );
    exit ( 1 );
  }
  return title;
}
/******************************************************************************/

double p01_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P01_FX evaluates sin ( x ) - x / 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P01_FX, the value of the function at X.
//
{
  double fx;

  fx = sin ( x ) - 0.5 * x;

  return fx;
}
/******************************************************************************/

double p01_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P01_FX1 evaluates the derivative of the function for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P0_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = cos ( x ) - 0.5;

  return fx1;
}
/******************************************************************************/

double p01_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P01_FX2 evaluates the second derivative of the function for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P0_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = - sin ( x );

  return fx2;
}
/******************************************************************************/

double *p01_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P01_RANGE returns an interval bounding the root for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P01_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 1000.0;
  range[1] =   1000.0;

  return range;
}
/******************************************************************************/

double p01_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P01_ROOT returns a root for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P01_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = - 1.895494267033981;
  }
  else if ( i == 2 )
  {
    root = 0.0;
  }
  else if ( i == 3 )
  {
    root = 1.895494267033981;
  }
  else
  {
    printf ( "\n" );
    printf ( "P01_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p01_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P01_ROOT_NUM returns the number of known roots for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P01_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 3;

  return root_num;
}
/******************************************************************************/

double p01_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P01_START returns a starting point for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P01_START, the starting point.
//
{
  static double pi = 3.141592653589793;
  double start;

  if ( i == 1 )
  {
    start = 0.5 * pi;
  }
  else if ( i == 2 )
  {
    start = pi;
  }
  else
  {
    printf ( "\n" );
    printf ( "P01_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p01_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P01_START_NUM returns the number of starting point for problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P01_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p01_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P01_TITLE returns the title of problem 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P01_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = SIN(X) - 0.5 * X" );

  return title;
}
/******************************************************************************/

double p02_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P02_FX evaluates 2 * x - exp ( - x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P02_FX, the value of the function at X.
//
{
  double fx;

  fx = 2.0 * x - exp ( - x );

  return fx;
}
/******************************************************************************/

double p02_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P02_FX1 evaluates the derivative of the function for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P02_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = 2.0 + exp ( - x );

  return fx1;
}
/******************************************************************************/

double p02_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P02_FX2 evaluates the second derivative of the function for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P02_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = - exp ( - x );

  return fx2;
}
/******************************************************************************/

double *p02_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P02_RANGE returns an interval bounding the root for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P02_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] =  - 10.0;
  range[1] =   100.0;

  return range;
}
/******************************************************************************/

double p02_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P02_ROOT returns a root for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P02_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.35173371124919584;
  }
  else
  {
    printf ( "\n" );
    printf ( "P02_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p02_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P02_ROOT_NUM returns the number of known roots for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P02_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p02_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P02_START returns a starting point for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P02_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.0;
  }
  else if ( i == 2 )
  {
    start = 1.0;
  }
  else if ( i == 3 )
  {
    start = - 5.0;
  }
  else if ( i == 4 )
  {
    start = 10.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P02_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p02_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P02_START_NUM returns the number of starting point for problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P02_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 4;

  return start_num;
}
/******************************************************************************/

char *p02_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P02_TITLE returns the title of problem 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P02_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = 2 * X - EXP ( - X )" );

  return title;
}
/******************************************************************************/

double p03_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P03_FX evaluates x * exp ( - x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P03_FX, the value of the function at X.
//
{
  double fx;

  fx = x * exp ( - x );

  return fx;
}
/******************************************************************************/

double p03_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P03_FX1 evaluates the derivative of the function for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P03_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = exp ( - x ) * ( 1.0 - x );

  return fx1;
}
/******************************************************************************/

double p03_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P03_FX2 evaluates the second derivative of the function for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P03_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = exp ( - x ) * ( x - 2.0 );

  return fx2;
}
/******************************************************************************/

double *p03_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P03_RANGE returns an interval bounding the root for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P03_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] =  - 10.0;
  range[1] =   100.0;

  return range;
}
/******************************************************************************/

double p03_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P03_ROOT returns a root for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P03_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P03_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p03_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P03_ROOT_NUM returns the number of known roots for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P03_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p03_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P03_START returns a starting point for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P03_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = - 1.0;
  }
  else if ( i == 2 )
  {
    start = 0.5;
  }
  else if ( i == 3 )
  {
    start = 2.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P03_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p03_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P03_START_NUM returns the number of starting point for problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P03_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p03_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P03_TITLE returns the title of problem 3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P03_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = X * EXP ( - X )" );

  return title;
}
/******************************************************************************/

double p04_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P04_FX evaluates exp ( x ) - 1 / ( 10 * x )^2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P04_FX, the value of the function at X.
//
{
  double fx;

  fx = exp ( x ) - 1.0 / ( 10.0 * x ) / ( 10.0 * x );

  return fx;
}
/******************************************************************************/

double p04_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P04_FX1 evaluates the derivative of the function for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P04_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = exp ( x ) + 2.0 / ( 100.0 * x * x * x );

  return fx1;
}
/******************************************************************************/

double p04_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P04_FX2 evaluates the second derivative of the function for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P04_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = exp ( x ) - 6.0 / ( 100.0 * x * x * x * x );

  return fx2;
}
/******************************************************************************/

double *p04_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P04_RANGE returns an interval bounding the root for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P04_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] =  0.00001;
  range[1] = 20.0;

  return range;
}
/******************************************************************************/

double p04_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P04_ROOT returns a root for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P04_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.09534461720025875;
  }
  else
  {
    printf ( "\n" );
    printf ( "P04_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p04_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P04_ROOT_NUM returns the number of known roots for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P04_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p04_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P04_START returns a starting point for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P04_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.03;
  }
  else if ( i == 2 )
  {
    start = 1.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P04_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p04_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P04_START_NUM returns the number of starting point for problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P04_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p04_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P04_TITLE returns the title of problem 4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P04_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = EXP ( X ) - 1 / ( 10 * X )^2" );

  return title;
}
/******************************************************************************/

double p05_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P05_FX evaluates ( x + 3 ) * ( x - 1 )^2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P05_FX, the value of the function at X.
//
{
  double fx;

  fx = ( x + 3.0 ) * ( x - 1.0 ) * ( x - 1.0 );

  return fx;
}
/******************************************************************************/

double p05_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P05_FX1 evaluates the derivative of the function for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P05_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = ( 3.0 * x + 5.0 ) * ( x - 1.0 );

  return fx1;
}
/******************************************************************************/

double p05_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P05_FX2 evaluates the second derivative of the function for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P05_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = 6.0 * x + 2.0;

  return fx2;
}
/******************************************************************************/

double *p05_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P05_RANGE returns an interval bounding the root for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P05_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 1000.0;
  range[1] =   1000.0;

  return range;
}
/******************************************************************************/

double p05_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P05_ROOT returns a root for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P05_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = - 3.0;
  }
  else if ( i == 2 )
  {
    root = 1.0;
  }
  else if ( i == 3 )
  {
    root = 1.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P05_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p05_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P05_ROOT_NUM returns the number of known roots for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P05_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 3;

  return root_num;
}
/******************************************************************************/

double p05_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P05_START returns a starting point for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P05_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 2.0;
  }
  else if ( i == 2 )
  {
    start = - 5.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P05_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p05_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P05_START_NUM returns the number of starting point for problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P05_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p05_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P05_TITLE returns the title of problem 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P05_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = ( X + 3 ) * ( X - 1 )^2" );

  return title;
}
/******************************************************************************/

double p06_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P06_FX evaluates exp ( x ) - 2 - 1 / ( 10 * x )^2 + 2 / ( 100 * x )^3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P06_FX, the value of the function at X.
//
{
  double fx;

  fx = exp ( x ) - 2.0 - 1.0 / ( 100.0 * x * x ) 
    + 2.0 / ( 1000000.0 * x * x * x );

  return fx;
}
/******************************************************************************/

double p06_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P06_FX1 evaluates the derivative of the function for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P06_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = exp ( x ) + 2.0 / ( 100.0 * pow ( x, 3 ) ) 
    - 6.0 / ( 1000000.0 * pow ( x, 4 ) );

  return fx1;
}
/******************************************************************************/

double p06_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P06_FX2 evaluates the second derivative of the function for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P06_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = exp ( x ) - 6.0 / ( 100.0 * pow ( x, 4 ) ) 
    + 24.0 / ( 1000000.0 * pow ( x, 5 ) );

  return fx2;
}
/******************************************************************************/

double *p06_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P06_RANGE returns an interval bounding the root for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P06_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] =  0.00001;
  range[1] = 20.0;

  return range;
}
/******************************************************************************/

double p06_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P06_ROOT returns a root for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P06_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.7032048403631358;
  }
  else
  {
    printf ( "\n" );
    printf ( "P06_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p06_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P06_ROOT_NUM returns the number of known roots for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P06_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p06_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P06_START returns a starting point for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P06_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.0002;
  }
  else if ( i == 2 )
  {
    start = 2.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P06_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p06_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P06_START_NUM returns the number of starting point for problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P06_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p06_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P06_TITLE returns the title of problem 6.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P06_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = EXP(X) - 2 - 1 / ( 10 * X )^2 + 2 / ( 100 * X )^3" );

  return title;
}
/******************************************************************************/

double p07_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P07_FX evaluates x^3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P07_FX, the value of the function at X.
//
{
  double fx;

  fx = x * x * x;

  return fx;
}
/******************************************************************************/

double p07_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P07_FX1 evaluates the derivative of the function for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P07_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = 3.0 * x * x;

  return fx1;
}
/******************************************************************************/

double p07_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P07_FX2 evaluates the second derivative of the function for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P07_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = 6.0 * x;

  return fx2;
}
/******************************************************************************/

double *p07_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P07_RANGE returns an interval bounding the root for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P07_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 1000.0;
  range[1] =   1000.0;

  return range;
}
/******************************************************************************/

double p07_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P07_ROOT returns a root for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P07_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P07_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p07_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P07_ROOT_NUM returns the number of known roots for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P07_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p07_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P07_START returns a starting point for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P07_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 1.0;
  }
  else if ( i == 2 )
  {
    start = - 1000.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P07_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p07_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P07_START_NUM returns the number of starting point for problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P07_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p07_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P07_TITLE returns the title of problem 7.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P07_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = X^3, only linear Newton convergence." );

  return title;
}
/******************************************************************************/

double p08_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P08_FX evaluates cos ( x ) - x.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P08_FX, the value of the function at X.
//
{
  double fx;

  fx = cos ( x ) - x;

  return fx;
}
/******************************************************************************/

double p08_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P08_FX1 evaluates the derivative of the function for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P08_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = - sin ( x ) - 1.0;

  return fx1;
}
/******************************************************************************/

double p08_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P08_FX2 evaluates the second derivative of the function for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P08_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = - cos ( x );

  return fx2;
}
/******************************************************************************/

double *p08_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P08_RANGE returns an interval bounding the root for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P08_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 10.0;
  range[1] =   10.0;

  return range;
}
/******************************************************************************/

double p08_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P08_ROOT returns a root for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P08_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.7390851332151607;
  }
  else
  {
    printf ( "\n" );
    printf ( "P08_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p08_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P08_ROOT_NUM returns the number of known roots for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P08_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p08_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P08_START returns a starting point for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P08_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 1.0;
  }
  else if ( i == 2 )
  {
    start = 0.5;
  }
  else if ( i == 3 )
  {
    start = - 1.6;
  }
  else
  {
    printf ( "\n" );
    printf ( "P08_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p08_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P08_START_NUM returns the number of starting point for problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P08_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p08_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P08_TITLE returns the title of problem 8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P08_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "F(X) = COS(X) - X" );

  return title;
}
/******************************************************************************/

double p09_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P09_FX evaluates the Newton Baffler.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P09_FX, the value of the function at X.
//
{
  double fx;

  if ( ( x - 6.25 ) < - 0.25 )
  {
    fx = 0.75 * ( x - 6.25 ) - 0.3125;
  }
  else if ( ( x - 6.25 ) < 0.25 )
  {
    fx = 2.0 * ( x - 6.25 );
  }
  else
  {
    fx = 0.75 * ( x - 6.25 ) + 0.3125;
  }

  return fx;
}
/******************************************************************************/

double p09_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P09_FX1 evaluates the derivative of the function for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P09_FX1, the first derivative of the function at X.
//
{
  double fx1;

  if ( x - 6.25 < - 0.25 )
  {
    fx1 = 0.75;
  }
  else if ( x - 6.25 < 0.25 )
  {
    fx1 = 2.0;
  }
  else
  {
    fx1 = 0.75;
  }

  return fx1;
}
/******************************************************************************/

double p09_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P09_FX2 evaluates the second derivative of the function for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P09_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = 0.0;

  return fx2;
}
/******************************************************************************/

double *p09_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P09_RANGE returns an interval bounding the root for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P09_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 5.00;
  range[1] =  16.00;

  return range;
}
/******************************************************************************/

double p09_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P09_ROOT returns a root for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P09_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 6.25;
  }
  else
  {
    printf ( "\n" );
    printf ( "P09_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p09_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P09_ROOT_NUM returns the number of known roots for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P09_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p09_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P09_START returns a starting point for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P09_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 6.25 + 5.0;
  }
  else if ( i == 2 )
  {
    start = 6.25 - 1.0;
  }
  else if ( i == 3 )
  {
    start = 6.25 + 0.1;
  }
  else
  {
    printf ( "\n" );
    printf ( "P09_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p09_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P09_START_NUM returns the number of starting point for problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P09_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p09_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P09_TITLE returns the title of problem 9.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P09_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "The Newton Baffler" );

  return title;
}
/******************************************************************************/

double p10_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P10_FX evaluates the Repeller.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P10_FX, the value of the function at X.
//
{
  double fx;

  fx = 20.0 * x / ( 100.0 * x * x + 1.0 );

  return fx;
}
/******************************************************************************/

double p10_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P10_FX1 evaluates the derivative of the function for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P10_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = ( 1.0 - 10.0 * x ) * ( 1.0 + 10.0 * x ) 
    / pow ( 100.0 * x * x + 1.0, 2 );

  return fx1;
}
/******************************************************************************/

double p10_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P10_FX2 evaluates the second derivative of the function for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P10_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = - 200.0 * x * ( 3.0 - 100.0 * x * x )
    / pow ( 100.0 * x * x + 1.0, 3 );

  return fx2;
}
/******************************************************************************/

double *p10_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P10_RANGE returns an interval bounding the root for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P10_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 10.0;
  range[1] =   10.0;

  return range;
}
/******************************************************************************/

double p10_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P10_ROOT returns a root for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P10_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P10_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p10_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P10_ROOT_NUM returns the number of known roots for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P10_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p10_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P10_START returns a starting point for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P10_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 1.0;
  }
  else if ( i == 2 )
  {
    start = - 0.14;
  }
  else if ( i == 3 )
  {
    start = 0.041;
  }
  else
  {
    printf ( "\n" );
    printf ( "P10_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p10_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P10_START_NUM returns the number of starting point for problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P10_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p10_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P10_TITLE returns the title of problem 10.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P10_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "The Repeller" );

  return title;
}
/******************************************************************************/

double p11_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P11_FX evaluates the Pinhead.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P11_FX, the value of the function at X.
//
{
  static double epsilon = 0.00001;
  double fx;

  fx = ( 4.0 + x * x ) * ( 2.0 + x ) * ( 2.0 - x ) 
    / ( 16.0 * x * x * x * x + epsilon );

  return fx;
}
/******************************************************************************/

double p11_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P11_FX1 evaluates the derivative of the function for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P11_FX1, the first derivative of the function at X.
//
{
  static double epsilon = 0.00001;
  double fx1;

  fx1 = - 4.0 * x * x * x * ( epsilon + 256.0 ) 
    / pow ( 16.0 * x * x * x * x + epsilon, 2 );

  return fx1;
}
/******************************************************************************/

double p11_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P11_FX2 evaluates the second derivative of the function for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P11_FX2, the second derivative of the function at X.
//
{
  static double epsilon = 0.00001;
  double fx2;

  fx2 = - 4.0 * ( epsilon + 256.0 ) 
    * ( 3.0 * epsilon - 80.0 * x * x * x * x ) * x * x
    / pow ( 16.0 * x * x * x * x + epsilon, 3 );

  return fx2;
}
/******************************************************************************/

double *p11_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P11_RANGE returns an interval bounding the root for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P11_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] =  0.0;
  range[1] = 10.0;

  return range;
}
/******************************************************************************/

double p11_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P11_ROOT returns a root for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P11_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = - 2.0;
  }
  else if ( i == 2 )
  {
    root = 2.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P11_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p11_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P11_ROOT_NUM returns the number of known roots for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P11_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 2;

  return root_num;
}
/******************************************************************************/

double p11_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P11_START returns a starting point for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P11_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.25;
  }
  else if ( i == 2 )
  {
    start = 5.0;
  }
  else if ( i == 3 )
  {
    start = 1.1;
  }
  else
  {
    printf ( "\n" );
    printf ( "P11_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p11_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P11_START_NUM returns the number of starting point for problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P11_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p11_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P11_TITLE returns the title of problem 11.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P11_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "The Pinhead" );

  return title;
}
/******************************************************************************/

double p12_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P12_FX evaluates Flat Stanley.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P12_FX, the value of the function at X.
//
{
  static double factor = 1000.0;
  double fx;
  double s;
  double y;

  if ( x == 1.0 )
  {
    fx = 0.0;
  }
  else
  {
    y = x - 1.0;
    s = r8_sign ( y );

    fx = s * exp ( log ( factor ) + log ( r8_abs ( y ) ) - 1.0 / y / y );
  }

  return fx;
}
/******************************************************************************/

double p12_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P12_FX1 evaluates the derivative of the function for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P12_FX1, the first derivative of the function at X.
//
{
  static double factor = 1000.0;
  double fx1;
  double y;

  if ( x == 1.0 )
  {
    fx1 = 0.0;
  }
  else
  {
    y = x - 1.0;
    fx1 = factor * exp ( - 1.0 / y / y ) * ( y * y + 2.0 ) / y / y;
  }

  return fx1;
}
/******************************************************************************/

double p12_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P12_FX2 evaluates the second derivative of the function for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P12_FX2, the second derivative of the function at X.
//
{
  static double factor = 1000.0;
  double fx2;
  double y;

  if ( x == 1.0 )
  {
    fx2 = 0.0;
  }
  else
  {
    y = x - 1.0;
    fx2 = - 2.0 * factor * exp ( - 1.0 / y / y ) 
      * ( y * y - 2.0 ) / pow ( y, 5 );
  }

  return fx2;
}
/******************************************************************************/

double *p12_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P12_RANGE returns an interval bounding the root for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P12_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 4.0;
  range[1] =   4.0;

  return range;
}
/******************************************************************************/

double p12_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P12_ROOT returns a root for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P12_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 1.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P12_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p12_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P12_ROOT_NUM returns the number of known roots for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P12_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p12_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P12_START returns a starting point for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P12_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 2.0;
  }
  else if ( i == 2 )
  {
    start = 0.5;
  }
  else if ( i == 3 )
  {
    start = 4.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P12_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p12_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P12_START_NUM returns the number of starting point for problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P12_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p12_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P12_TITLE returns the title of problem 12.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P12_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "Flat Stanley (ALL derivatives are zero at the root.)" );

  return title;
}
/******************************************************************************/

double p13_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P13_FX evaluates Lazy Boy.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P13_FX, the value of the function at X.
//
{
  double fx;
  static double slope = 0.00000000001;

  fx = slope * ( x - 100.0 );

  return fx;
}
/******************************************************************************/

double p13_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P13_FX1 evaluates the derivative of the function for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P13_FX1, the first derivative of the function at X.
//
{

  double fx1;
  static double slope = 0.00000000001;

  fx1 = slope;

  return fx1;
}
/******************************************************************************/

double p13_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P13_FX2 evaluates the second derivative of the function for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P13_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = 0.0;

  return fx2;
}
/******************************************************************************/

double *p13_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P13_RANGE returns an interval bounding the root for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P13_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 1.0E+13;
  range[1] =   1.0E+13;

  return range;
}
/******************************************************************************/

double p13_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P13_ROOT returns a root for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P13_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 100.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P13_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p13_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P13_ROOT_NUM returns the number of known roots for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P13_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p13_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P13_START returns a starting point for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P13_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 100000000.0;
  }
  else if ( i == 2 )
  {
    start = 100000013.0;
  }
  else if ( i == 3 )
  {
    start = - 100000000000.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P13_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p13_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P13_START_NUM returns the number of starting point for problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P13_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p13_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P13_TITLE returns the title of problem 13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P13_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "Lazy Boy (Linear function, almost flat.)" );

  return title;
}
/******************************************************************************/

double p14_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P14_FX evaluates the Camel.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P14_FX, the value of the function at X.
//
{
  double fx;

  fx =   1.0 / ( ( x - 0.3 ) * ( x - 0.3 ) + 0.01 ) 
       + 1.0 / ( ( x - 0.9 ) * ( x - 0.9 ) + 0.04 ) + 2.0 * x - 5.2;

  return fx;
}
/******************************************************************************/

double p14_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P14_FX1 evaluates the derivative of the function for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P14_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = - 2.0 * ( x - 0.3 ) / pow ( ( pow ( x - 0.3, 2 ) + 0.01 ), 2 )
        - 2.0 * ( x - 0.9 ) / pow ( ( pow ( x - 0.9, 2 ) + 0.04 ), 2 )
        + 2.0;

  return fx1;
}
/******************************************************************************/

double p14_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P14_FX2 evaluates the second derivative of the function for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P14_FX2, the second derivative of the function at X.
//
{
  double b1;
  double b2;
  double fx2;
  double t1;
  double t2;

  t1 = - 2.0 * pow ( ( pow ( x - 0.3, 2 ) + 0.01 ), 2 ) 
       + 2.0 * ( x - 0.3 ) * 2.0 * ( pow ( x - 0.3, 2 ) + 0.01 ) 
       * ( 2.0 * ( x - 0.3 ) + 0.01 );

  b1 = pow ( ( pow ( x - 0.3, 2 ) + 0.01 ), 4 );

  t2 = - 2.0 * pow ( ( pow ( x - 0.9, 2 ) + 0.04 ), 2 ) 
       + 2.0 * ( x - 0.9 ) * 2.0 * ( pow ( x - 0.9, 2 ) + 0.04 )
       * ( 2.0 * ( x - 0.9 ) + 0.04 );

  b2 = pow ( ( pow ( x - 0.9, 2 ) + 0.04 ), 4 );

  fx2 = t1 / b1 + t2 / b2;

  return fx2;
}
/******************************************************************************/

double *p14_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P14_RANGE returns an interval bounding the root for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P14_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 10.0;
  range[1] =   10.0;

  return range;
}
/******************************************************************************/

double p14_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P14_ROOT returns a root for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P14_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = - 0.1534804948126991;
  }
  else if ( i == 2 )
  {
    root = 1.8190323925159182;
  }
  else if ( i == 3 )
  {
    root = 2.1274329318603367;
  }
  else
  {
    printf ( "\n" );
    printf ( "P14_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p14_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P14_ROOT_NUM returns the number of known roots for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P14_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 3;

  return root_num;
}
/******************************************************************************/

double p14_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P14_START returns a starting point for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P14_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 3.0;
  }
  else if ( i == 2 )
  {
    start = - 0.5;
  }
  else if ( i == 3 )
  {
    start = 0.0;
  }
  else if ( i == 4 )
  {
    start = 2.12742;
  }
  else
  {
    printf ( "\n" );
    printf ( "P14_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p14_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P14_START_NUM returns the number of starting point for problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P14_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 4;

  return start_num;
}
/******************************************************************************/

char *p14_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P14_TITLE returns the title of problem 14.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P14_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "The Camel (double hump and some shallow roots.)" );

  return title;
}
/******************************************************************************/

double p15_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P15_FX evaluates a pathological function for Newton's method.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    George Donovan, Arnold Miller, Timothy Moreland,
//    Pathological Functions for Newton's Method,
//    American Mathematical Monthly, January 1993, pages 53-58.
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P15_FX, the value of the function at X.
//
{
  double fx;

  fx = r8_cube_root ( x ) * exp ( - x * x );

  return fx;
}
/******************************************************************************/

double p15_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P15_FX1 evaluates the derivative of the function for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P15_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = ( 1.0 - 6.0 * x * x ) * r8_cube_root ( x ) 
    * exp ( - x * x ) / ( 3.0 * x );

  return fx1;
}
/******************************************************************************/

double p15_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P15_FX2 evaluates the second derivative of the function for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P15_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = ( - 2.0 - 30.0 * x * x + 36.0 * x * x * x * x ) * r8_cube_root ( x ) 
    * exp ( - x * x ) / ( 9.0 * x * x );

  return fx2;
}
/******************************************************************************/

double *p15_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P15_RANGE returns an interval bounding the root for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P15_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = - 10.0;
  range[1] =   10.0;

  return range;
}
/******************************************************************************/

double p15_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P15_ROOT returns a root for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P15_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P15_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p15_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P15_ROOT_NUM returns the number of known roots for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P15_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p15_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P15_START returns a starting point for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P15_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.01;
  }
  else if ( i == 2 )
  {
    start = - 0.25;
  }
  else
  {
    printf ( "\n" );
    printf ( "P15_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p15_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P15_START_NUM returns the number of starting point for problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P15_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p15_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P15_TITLE returns the title of problem 15.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P15_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "Donovan/Miller/Moreland Pathological Function" );

  return title;
}
/******************************************************************************/

double p16_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P16_FX evaluates Kepler's Equation.
//
//  Discussion:
//
//    This is Kepler's equation.  The equation has the form:
//
//      X = M + E * sin ( X )
//
//    X represents the eccentric anomaly of a planet, the angle between the
//    perihelion (the point on the orbit nearest to the sun)
//    through the sun to the center of the ellipse, and the
//    line from the center of the ellipse to the planet.
//
//    There are two parameters:
//
//    E is the eccentricity of the orbit, which should be between 0 and 1.0;
//
//    M is the angle from the perihelion made by a fictitious planet traveling
//    on a circular orbit centered at the sun, and traveling at a constant
//    angular velocity equal to the average angular velocity of the true planet.
//    M is usually between 0 and 180 degrees, but can have any value.
//
//    For convenience, X and M are measured in degrees.
//
//    Sample results:
//
//    E        M      X
//    -----  ---  ----------
//    0.100    5    5.554589
//    0.200    5    6.246908
//    0.300    5    7.134960
//    0.400    5    8.313903
//    0.500    5    9.950063
//    0.600    5   12.356653
//    0.700    5   16.167990
//    0.800    5   22.656579
//    0.900    5   33.344447
//    0.990    5   45.361023
//    0.990    1   24.725822
//    0.990   33   89.722155
//    0.750   70  110.302
//    0.990    2   32.361007
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Peter Colwell,
//    Solving Kepler's Equation Over Three Centuries,
//    Willmann-Bell, 1993
//
//    Jean Meeus,
//    Astronomical Algorithms,
//    Willman-Bell, Inc, 1991,
//    QB51.3.E43M42
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P16_FX, the value of the function at X.
//
{
  double e;
  double fx;
  double m;
  static double pi = 3.141592653589793;

  e = 0.8;
  m = 5.0;

  fx = ( pi * ( x - m ) / 180.0 ) - e * sin ( pi * x / 180.0 );

  return fx;
}
/******************************************************************************/

double p16_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P16_FX1 evaluates the derivative of the function for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P16_FX1, the first derivative of the function at X.
//
{
  double e;
  double fx1;
  const static double pi = 3.141592653589793;

  e = 0.8;

  fx1 = ( pi / 180.0 ) 
    - e * pi * cos ( pi * x / 180.0  ) / 180.0;

  return fx1;
}
/******************************************************************************/

double p16_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P16_FX2 evaluates the second derivative of the function for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P16_FX2, the second derivative of the function at X.
//
{
  double e;
  double fx2;
  static double pi = 3.141592653589793;

  e = 0.8;


  fx2 = e * pi * pi * sin ( pi * x / 180.0  ) / 180.0 / 180.0;

  return fx2;
}
/******************************************************************************/

double *p16_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P16_RANGE returns an interval bounding the root for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P16_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double m;
  double *range;

  m = 5.0;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = m - 180.0;
  range[1] = m + 180.0;

  return range;
}
/******************************************************************************/

double p16_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P16_ROOT returns a root for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P16_ROOT, the value of the root.
//
{
  printf ( "\n" );
  printf ( "P16_ROOT - Fatal error!\n" );
  printf ( "  Illegal root index = %d\n", i );
  exit ( 1 );
}
/******************************************************************************/

int p16_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P16_ROOT_NUM returns the number of known roots for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P16_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 0;

  return root_num;
}
/******************************************************************************/

double p16_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P16_START returns a starting point for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P16_START, the starting point.
//
{
  double m;
  double start;

  m = 5.0;

  if ( i == 1 )
  {
    start = 0.0;
  }
  else if ( i == 2 )
  {
    start = m;
  }
  else if ( i == 3 )
  {
    start = m + 180.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P16_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p16_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P16_START_NUM returns the number of starting point for problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P16_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p16_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P16_TITLE returns the title of problem 16.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P16_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "Kepler's Eccentric Anomaly Equation, in degrees" );

  return title;
}
/******************************************************************************/

double p17_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P17_FX evaluates the function for problem 17.
//
//  Discussion:
//
//    This simple example is of historical interest, since it was used
//    by Wallis to illustrate the use of Newton's method, and has been
//    a common example ever since.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P17_FX, the value of the function at X.
//
{
  double fx;

  fx = x * x * x - 2.0 * x - 5.0;

  return fx;
}
/******************************************************************************/

double p17_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P17_FX1 evaluates the derivative of the function for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P17_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = 3.0 * x * x - 2.0;

  return fx1;
}
/******************************************************************************/

double p17_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P17_FX2 evaluates the second derivative of the function for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P17_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = 6.0 * x;

  return fx2;
}
/******************************************************************************/

double *p17_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P17_RANGE returns an interval bounding the root for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P17_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = 2.0;
  range[1] = 3.0;

  return range;
}
/******************************************************************************/

double p17_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P17_ROOT returns a root for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P17_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 2.0945514815423265;
  }
  else
  {
    printf ( "\n" );
    printf ( "P17_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p17_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P17_ROOT_NUM returns the number of known roots for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P17_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p17_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P17_START returns a starting point for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P17_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 2.0;
  }
  else if ( i == 2 )
  {
    start = 3.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P17_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p17_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P17_START_NUM returns the number of starting point for problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P17_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p17_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P17_TITLE returns the title of problem 17.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 May 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P17_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "The Wallis example, x^3-2x-5=0" );

  return title;
}
/******************************************************************************/

double p18_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P18_FX evaluates the function for problem P18.
//
//  Discussion:
//
//    F(X) = 10^14 * (x-1)^7, but is written in term by term form.
//
//    This polynomial becomes difficult to evaluate accurately when 
//    written this way.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P18_FX, the value of the function at X.
//
{
  double fx;

  fx = 1.0E14 * ( 
               pow ( x, 7 )
      -  7.0 * pow ( x, 6 )
      + 21.0 * pow ( x, 5 )
      - 35.0 * pow ( x, 4 )
      + 35.0 * pow ( x, 3 )
      - 21.0 * pow ( x, 2 )
      +  7.0 * x    
      -  1.0 );

  return fx;
}
/******************************************************************************/

double p18_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P18_FX1 evaluates the derivative of the function for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P18_FX1, the first derivative of the function at X.
//
{
  double fx1;

  fx1 = 1.0E+14 * ( 
          7.0 * pow ( x, 6 )
      -  42.0 * pow ( x, 5 )
      + 105.0 * pow ( x, 4 )
      - 140.0 * pow ( x, 3 )
      + 105.0 * pow ( x, 2 )
      -  42.0 * x    
      +   7.0 );

  return fx1;
}
/******************************************************************************/

double p18_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P18_FX2 evaluates the second derivative of the function for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P18_FX2, the second derivative of the function at X.
//
{
  double fx2;

  fx2 = 1.0E+14 * ( 
         42.0 * pow ( x, 5 )
      - 210.0 * pow ( x, 4 )
      + 420.0 * pow ( x, 3 ) 
      - 420.0 * pow ( x, 2 )
      + 210.0 * x    
      -  42.0 );

  return fx2;
}
/******************************************************************************/

double *p18_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P18_RANGE returns an interval bounding the root for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P18_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = 0.988;
  range[1] = 1.012;

  return range;
}
/******************************************************************************/

double p18_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P18_ROOT returns a root for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P18_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 1.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "P18_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p18_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P18_ROOT_NUM returns the number of known roots for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P18_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p18_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P18_START returns a starting point for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P18_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.990;
  }
  else if ( i == 2 )
  {
    start = 1.013;
  }
  else
  {
    printf ( "\n" );
    printf ( "P18_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p18_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P18_START_NUM returns the number of starting point for problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P18_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 2;

  return start_num;
}
/******************************************************************************/

char *p18_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P18_TITLE returns the title of problem P18.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P18_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "10^14 * (x-1)^7, written term by term." );

  return title;
}
/******************************************************************************/

double p19_fx ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P19_FX evaluates the function for problem P19.
//
//  Discussion:
//
//    This function looks like an elevated cosine curve, connected by a 
//    sudden drop to a submerged cosine curve.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the point at which F is to be evaluated.
//
//    Output, double P19_FX, the value of the function at X.
//
{
  double fx;

  fx = cos ( 100.0 * x ) - 4.0 * erf ( 30.0 * x - 10.0 );

  return fx;
}
/******************************************************************************/

double p19_fx1 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P19_FX1 evaluates the derivative of the function for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P19_FX1, the first derivative of the function at X.
//
{
  double arg;
  double pi = 3.141592653589793;
  double fx1;

  arg = - pow ( 10.0 - 30.0 * x, 2 );
  fx1 = - 100.0 * sin ( 100.0 * x ) + 240.0 * exp ( arg ) / sqrt ( pi );

  return fx1;
}
/******************************************************************************/

double p19_fx2 ( double x )

/******************************************************************************/
//
//  Purpose:
//
//    P19_FX2 evaluates the second derivative of the function for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the abscissa.
//
//    Output, double P19_FX2, the second derivative of the function at X.
//
{
  double arg;
  double pi = 3.141592653589793;
  double fx2;

  arg = - pow ( 10.0 - 30.0 * x, 2 );
  fx2 = - 10000.0 * cos ( 100.0 * x ) 
    + 14400.0 * exp ( arg ) * ( 10.0 - 30.0 * x ) / sqrt ( pi );

  return fx2;
}
/******************************************************************************/

double *p19_range ( )

/******************************************************************************/
//
//  Purpose:
//
//    P19_RANGE returns an interval bounding the root for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P19_RANGE[2], the minimum and maximum values of
//    an interval containing the root.
//
{
  double *range;

  range = ( double * ) malloc ( 2 * sizeof ( double ) );

  range[0] = 0.0;
  range[1] = 1.0;

  return range;
}
/******************************************************************************/

double p19_root ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P19_ROOT returns a root for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested root.
//
//    Output, double P19_ROOT, the value of the root.
//
{
  double root;

  if ( i == 1 )
  {
    root = 0.33186603357456253747;
  }
  else
  {
    printf ( "\n" );
    printf ( "P19_ROOT - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return root;
}
/******************************************************************************/

int p19_root_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P19_ROOT_NUM returns the number of known roots for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P19_ROOT_NUM, the number of known roots.
//
{
  int root_num;

  root_num = 1;

  return root_num;
}
/******************************************************************************/

double p19_start ( int i )

/******************************************************************************/
//
//  Purpose:
//
//    P19_START returns a starting point for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the index of the requested starting point.
//
//    Output, double P19_START, the starting point.
//
{
  double start;

  if ( i == 1 )
  {
    start = 0.0;
  }
  else if ( i == 2 )
  {
    start = 1.0;
  }
  else if ( i == 3 )
  {
    start = 0.5;
  }
  else
  {
    printf ( "\n" );
    printf ( "P19_START - Fatal error!\n" );
    printf ( "  Illegal root index = %d\n", i );
    exit ( 1 );
  }
  return start;
}
/******************************************************************************/

int p19_start_num ( )

/******************************************************************************/
//
//  Purpose:
//
//    P19_START_NUM returns the number of starting point for problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int P19_START_NUM, the number of starting points.
//
{
  int start_num;

  start_num = 3;

  return start_num;
}
/******************************************************************************/

char *p19_title ( )

/******************************************************************************/
//
//  Purpose:
//
//    P19_TITLE returns the title of problem P19.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, char *P19_TITLE, the title of the problem.
//
{
  char *title;

  title = ( char * ) malloc ( 80 * sizeof ( char ) );

  strcpy ( title, "The jumping cosine." );

  return title;
}
/******************************************************************************/

double r8_abs ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_ABS returns the absolute value of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 November 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the quantity whose absolute value is desired.

    Output, double R8_ABS, the absolute value of X.
*/
{
  double value;

  if ( 0.0 <= x )
  {
    value = + x;
  }
  else
  {
    value = - x;
  }
  return value;
}
/******************************************************************************/

double complex r8_csqrt ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_CSQRT returns the complex square root of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 October 2005

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number whose square root is desired.

    Output, double complex R8_CSQRT, the square root of X:
*/
{
  double argument;
  double magnitude;
  double pi = 3.141592653589793;
  double complex value;

  if ( 0.0 < x )
  {
    magnitude = x;
    argument = 0.0;
  }
  else if ( 0.0 == x )
  {
    magnitude = 0.0;
    argument = 0.0;
  }
  else if ( x < 0.0 )
  {
    magnitude = -x;
    argument = pi;
  }

  magnitude = sqrt ( magnitude );
  argument = argument / 2.0;

  value = magnitude * ( cos ( argument ) + sin ( argument ) * I );

  return value;
}
/******************************************************************************/

double r8_cube_root ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_CUBE_ROOT returns the cube root of an R8.

  Discussion:

    This routine is designed to avoid the possible problems that can occur
    when formulas like 0.0^(1/3) or (-1.0)^(1/3) are to be evaluated.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2004

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number whose cube root is desired.

    Output, double R8_CUBE_ROOT, the cube root of X.
*/
{
  double e;
  double value;

  e = 1.0 / 3.0;

  if ( 0.0 < x )
  {
    value = pow ( x, e );
  }
  else if ( x == 0.0 )
  {
    value = 0.0;
  }
  else
  {
    value = - pow ( r8_abs ( x ), e );
  }

  return value;
}
/******************************************************************************/

double r8_epsilon ( )

/******************************************************************************/
/*
  Purpose:

    R8_EPSILON returns the R8 round off unit.

  Discussion:

    R8_EPSILON is a number R which is a power of 2 with the property that,
    to the precision of the computer's arithmetic,
      1 < 1 + R
    but
      1 = ( 1 + R / 2 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 September 2012

  Author:

    John Burkardt

  Parameters:

    Output, double R8_EPSILON, the R8 round-off unit.
*/
{
  const double value = 2.220446049250313E-016;

  return value;
}
/******************************************************************************/

double r8_huge ( )

/******************************************************************************/
/*
  Purpose:

    R8_HUGE returns a "huge" R8.

  Discussion:

    The value returned by this function is NOT required to be the
    maximum representable R8.  This value varies from machine to machine,
    from compiler to compiler, and may cause problems when being printed.
    We simply want a "very large" but non-infinite number.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 October 2007

  Author:

    John Burkardt

  Parameters:

    Output, double R8_HUGE, a "huge" R8 value.
*/
{
  double value;

  value = 1.0E+30;

  return value;
}
/******************************************************************************/

double r8_max ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    R8_MAX returns the maximum of two R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2004

  Author:

    John Burkardt

  Parameters:

    Input, double X, Y, the quantities to compare.

    Output, double R8_MAX, the maximum of X and Y.
*/
{
  double value;

  if ( y < x )
  {
    value = x;
  }
  else
  {
    value = y;
  }
  return value;
}
/******************************************************************************/

double r8_sign ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_SIGN returns the sign of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 October 2004

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number whose sign is desired.

    Output, double R8_SIGN, the sign of X.
*/
{
  double value;

  if ( x < 0.0 )
  {
    value = -1.0;
  }
  else
  {
    value = 1.0;
  }
  return value;
}
/******************************************************************************/

void r8poly2_rroot ( double a, double b, double c, double *r1, double *r2 )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_RROOT returns the real parts of the roots of a quadratic polynomial.

  Example:

    A    B    C       roots              R1   R2
   --   --   --     ------------------   --   --
    1   -4    3     1          3          1    3
    1    0    4     2*i      - 2*i        0    0
    2   -6    5     3 +   i    3 -   i    3    3

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 October 2005

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, C, the coefficients of the quadratic
    polynomial A * X^2 + B * X + C = 0 whose roots are desired.
    A must not be zero.

    Output, double *R1, *R2, the real parts of the roots
    of the polynomial.
*/
{
  double disc;
  double q;

  if ( a == 0.0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8POLY2_RROOT - Fatal error!\n" );
    fprintf ( stderr, "  The coefficient A is zero.\n" );
    exit ( 1 );
  }

  disc = b * b - 4.0 * a * c;
  disc = r8_max ( disc, 0.0 );

  q = ( b + r8_sign ( b ) * sqrt ( disc ) );
  *r1 = -0.5 * q / a;
  *r2 = -2.0 * c / q;

  return;
}
/******************************************************************************/

void regula_falsi ( double fatol, int step_max, int prob, double xatol,
  double *xa, double *xb, double *fxa, double *fxb )

/******************************************************************************/
/*
  Purpose:

    REGULA_FALSI carries out the Regula Falsi method to seek a root of F(X) = 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, double FATOL, an absolute error tolerance for the
    function value of the root.  If an approximate root X satisfies
      ABS ( F ( X ) ) <= FATOL, then X will be accepted as the
    root and the iteration will be terminated.

    Input, int STEP_MAX, the maximum number of steps allowed
    for an iteration.

    Input, int PROB, the index of the function whose root is
    to be sought.

    Input, double XATOL, absolute error tolerance for the root.

    Input/output, double *XA, *XB, two points at which the
    function differs in sign.  On output, these values have been adjusted
    to a smaller interval.

    Input/output, double *FXA, *FXB, the value of the function
    at XA and XB.
*/
{
  double fxc;
  int step_num;
  double t;
  double xc;
/*
  The method requires a change-of-sign interval.
*/
  if ( r8_sign ( *fxa ) == r8_sign ( *fxb ) )
  {
    printf ( "\n" );
    printf ( "REGULA_FALSI - Fatal error!\n" );
    printf ( "  Function does not change sign at endpoints.\n" );
    exit ( 1 );
  }
/*
  Make A the root with negative F, B the root with positive F.
*/
  t = *xa;
  *xa = *xb;
  *xb = t;

  t = *fxa;
  *fxa = *fxb;
  *fxb = t;

  printf ( "\n" );
  printf ( "REGULA FALSI\n" );
  printf ( "\n" );
  printf ( "  Step      XA            XB             F(XA)         F(XB)\n" );
  printf ( "\n" );

  step_num = 0;

  printf ( "  %4d  %14g  %14g  %14g  %14g\n", step_num, *xa, *xb, *fxa, *fxb );

  for ( step_num = 1; step_num <= step_max; step_num++ )
  {
    if ( r8_abs ( *xa - *xb ) < xatol )
    {
      printf ( "\n" );
      printf ( "  Interval small enough for convergence.\n" );
      return;
    }

    if ( r8_abs ( *fxa ) <= fatol || r8_abs ( *fxb ) <= fatol )
    {
      printf ( "\n" );
      printf ( "  Function small enough for convergence.\n" );
      return;
    }

    xc = ( *fxa * *xb - *fxb * *xa ) / ( *fxa - *fxb );
    fxc = p00_fx ( prob, xc );

    if ( fxc < 0.0 )
    {
      *xa = xc;
      *fxa = fxc;
    }
    else
    {
      *xb = xc;
      *fxb = fxc;
    }

    printf ( "  %4d  %14g  %14g  %14g  %14g\n", step_num, *xa, *xb, *fxa, *fxb );
  }

  printf ( "\n" );
  printf ( "  Took maximum number of steps without convergence.\n" );

  return;
}
/******************************************************************************/

void secant ( double fatol, int step_max, int prob, double xatol, double xmin, 
  double xmax, double *xa, double *xb, double *fxa, double *fxb )

/******************************************************************************/
/*
  Purpose:

    SECANT carries out the secant method to seek a root of F(X) = 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, double FATOL, an absolute error tolerance for the
    function value of the root.  If an approximate root X satisfies
      ABS ( F ( X ) ) <= FATOL, then X will be accepted as the
    root and the iteration will be terminated.

    Input, int STEP_MAX, the maximum number of steps allowed
    for an iteration.

    Input, int PROB, the index of the function whose root is
    to be sought.

    Input, double XATOL, an absolute error tolerance for the root.

    Input, double XMIN, XMAX, the interval in which the root should
    be sought.

    Input/output, double *XA, *XB, two points at which the
    function differs in sign.  On output, these values have been adjusted
    to a smaller interval.

    Input/output, double *FXA, *FXB, the value of the function
    at XA and XB.
*/
{
  double fxc;
  int step_num;
  double xc;

  printf ( "\n" );
  printf ( "SECANT\n" );
  printf ( "\n" );
  printf ( "  Step         X             F(X)\n" );
  printf ( "\n" );

  step_num = -1;
  printf ( "  %4d  %10g  %10g\n", step_num, *xa, *fxa );

  if ( r8_abs ( *fxa ) <= fatol )
  {
    printf ( "\n" );
    printf ( "  Function small enough for convergence.\n" );
    return;
  }

  step_num = 0;

  printf ( "  %4d  %10g  %10g\n", step_num, *xb, *fxb );

  for ( step_num = 1; step_num <= step_max; step_num++ )
  {
    if ( r8_abs ( *fxb ) <= fatol )
    {
      printf ( "\n" );
      printf ( "  Function small enough for convergence.\n" );
      return;
    }

    if ( r8_abs ( *xa - *xb ) < xatol )
    {
      printf ( "\n" );
      printf ( "  Interval small enough for convergence.\n" );
      return;
    }

    if ( *xb < xmin || xmax < *xb )
    {
      printf ( "\n" );
      printf ( "  Iterate has left the region [XMIN,XMAX].\n" );
      return;
    }

    if ( *fxa == *fxb )
    {
      printf ( "\n" );
      printf ( "  F(A) = F(B), algorithm fails.\n" );
      return;
    }

    xc = ( *fxa * *xb - *fxb * *xa ) / ( *fxa - *fxb );

    fxc = p00_fx ( prob, xc );

    *xa = *xb;
    *fxa = *fxb;
    *xb = xc;
    *fxb = fxc;

    printf ( "  %4d  %10g  %10g\n", step_num, *xb, *fxb );
  }

  printf ( "\n" );
  printf ( "  Took maximum number of steps.\n" );

  return;
}
/******************************************************************************/

void timestamp ( void )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
