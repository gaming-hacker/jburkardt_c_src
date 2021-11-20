# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "stochastic_diffusion.h"

/******************************************************************************/

double *diffusivity_1d_pwc ( int nc, double xc[], double vc[], int np, 
  double xp[] )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_1D_PWC: piecewise constant diffusivity function in 1D.

  Discussion:

    A piecewise constant function is defined over NC intervals, 
    with interval IC associated with constant value VC(I),
    separated by NC-1 ascending sorted breakpoints.

    The function is to be evaluated at NP points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 March 2019

  Author:

    John Burkardt

  Parameters:

    Input, int NC, the number of function values.

    Input, double XC[NC-1], the breakpoints, in ascending order.

    Input, double VC[NC], the function values over each interval.

    Input, int NP, the number of evaluation points.

    Input, double XP[NP], the evaluation points.

    Output, double DIFFUSIVITY_1D_PWC[NP], the function value at the 
    evaluation points.
*/
{
  int ic;
  int ip;
  int kc;
  double *vp;

  vp = ( double * ) malloc ( np * sizeof ( double ) );

  for ( ip = 0; ip < np; ip++ )
  {
    kc = 0;
    for ( ic = 0; ic < nc - 1; ic++ )
    {
      if ( xp[ip] < xc[ic] )
      {
        break;
      }
      kc = kc + 1;
    }
    vp[ip] = vc[kc];
  }

  return vp;
}
/******************************************************************************/

double *diffusivity_1d_xk ( double dc0, int m, double omega[], int n,
  double x[] )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_1D_XK evaluates a 1D stochastic diffusivity function.

  Discussion:

    The 1D diffusion equation has the form

      - d/dx ( DC(X) Del U(X) ) = F(X)

    where DC(X) is a function called the diffusivity.

    In the stochastic version of the problem, the diffusivity function
    includes the influence of stochastic parameters:

      - d/dx ( DC(X;OMEGA) d/dx U(X) ) = F(X).

    In this function, the domain is assumed to be the unit interval [0.1].


    For DC0 = 1 and F(X) = 0, with boundary conditions U(0:OMEGA) = 0,
    U(1;OMEGA) = 1, the exact solution is

    If OMEGA ~= 0:

      U(X;OMEGA) = log ( 1 + OMEGA * X ) / log ( 1 + OMEGA )

    If OMEGA = 0:

      U(X;OMEGA) = X

    In the numerical experiments described in the paper, OMEGA was taken
    to be a random variable with a Beta, or Uniform, or Gaussian or 
    Poisson or Binomial distribution.

    For the Gaussian and Poisson distributions, the positivity requirement 
    could not be guaranteed, and the experiments were simply made with a 
    "small" variance of 0.1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Dongbin Xiu, George Karniadakis,
    Modeling uncertainty in steady state diffusion problems via
    generalized polynomial chaos,
    Computer Methods in Applied Mechanics and Engineering,
    Volume 191, 2002, pages 4927-4948.

  Parameters:

    Input, double DC0, the constant term in the expansion of the 
    diffusion coefficient.

    Input, int M, the number of stochastic parameters.

    Input, double OMEGA[M], the stochastic parameters.  

    Input, int N, the number of evaluation points.

    Input, double X[N], the point where the diffusion coefficient 
    is to be evaluated.

    Output, double DIFFUSIVITY_1D_XK[N], the value of the diffusion coefficient 
    at X.
*/
{
  double *dc;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;
  double w;

  k = 0;
  w = 1.0;

  dc = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    dc[j] = 0.0;
  }

  while ( k < m )
  {
    if ( k < m )
    {
      k = k + 1;
      for ( j = 0; j < n; j++ )
      {
        dc[j] = dc[j] + omega[k-1] * sin ( w * r8_pi * x[j] );
      }
    }

    if ( k < m )
    {
      k = k + 1;
      for ( j = 0; j < n; j++ )
      {
        dc[j] = dc[j] + omega[k-1] * cos ( w * r8_pi * x[j] );    
      }
    }

    w = w + 1.0;

  }

  for ( j = 0; j < n; j++ )
  {
    dc[j] = exp ( - 0.125 ) * dc[j];
  }

  for ( j = 0; j < n; j++ )
  {
    dc[j] = dc0 + exp ( dc[j] );
  }

  return dc;
}
/******************************************************************************/

double *diffusivity_2d_bnt ( double dc0, double omega[], int n, double x[], 
  double y[] )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_BNT evaluates a 2D stochastic diffusivity function.

  Discussion:

    The 2D diffusion equation has the form

      - Del ( DC(X,Y) Del U(X,Y) ) = F(X,Y)

    where DC(X,Y) is a function called the diffusivity.

    In the stochastic version of the problem, the diffusivity function
    includes the influence of stochastic parameters:

      - Del ( DC(X,Y;OMEGA) Del U(X,Y;OMEGA) ) = F(X,Y).

    In this function, the domain is the rectangle [-1.5,0]x[-0.4,0.8].

    The four stochastic parameters OMEGA(1:4) are assumed to be independent
    identically distributed random variables with mean value zero and 
    variance 1.  The distribution is typically taken to be Gaussian or
    uniform.

    A collocation approach to this problem would then use the roots of
    Hermite or Legendre polynomials.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Ivo Babuska, Fabio Nobile, Raul Tempone,
    A stochastic collocation method for elliptic partial differential equations
    with random input data,
    SIAM Journal on Numerical Analysis,
    Volume 45, Number 3, 2007, pages 1005-1034.

  Parameters:

    Input, double DC0, the constant term in the expansion of the 
    diffusion coefficient.  Take DC0 = 10.

    Input, double OMEGA[4], the stochastic parameters.

    Input, int N, the number of evaluation points.

    Input, double X[N], Y[N], the points where the diffusion 
    coefficient is to be evaluated.

    Output, double DIFFUSIVITY_2D_BNT[N], the value of the diffusion coefficient 
    at (X,Y).
*/
{
  double *arg;
  double *dc;
  int j;
  const double r8_pi = 3.141592653589793;

  arg = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    arg[j] = omega[0] * cos ( r8_pi * x[j] ) 
           + omega[1] * sin ( r8_pi * x[j] ) 
           + omega[2] * cos ( r8_pi * y[j] ) 
           + omega[3] * sin ( r8_pi * y[j] );
  }

  for ( j = 0; j < n; j++ )
  {
    arg[j] = exp ( - 0.125 ) * arg[j];
  }

  dc = ( double * ) malloc ( n * sizeof ( double ) );
  for ( j = 0; j < n; j++ )
  {
    dc[j] = dc0 + exp ( arg[j] );
  }

  free ( arg );

  return dc;
}
/******************************************************************************/

double *diffusivity_2d_elman ( double a, double cl, double dc0, int m_1d, 
  double omega[], int n1, int n2, double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_ELMAN evaluates a 2D stochastic diffusivity function.

  Discussion:

    The 2D diffusion equation has the form

      - Del ( DC(X,Y) Del U(X,Y) ) = F(X,Y)

    where DC(X,Y) is a function called the diffusivity.

    In the stochastic version of the problem, the diffusivity function
    includes the influence of stochastic parameters:

      - Del ( DC(X,Y;OMEGA) Del U(X,Y;OMEGA) ) = F(X,Y).

    In this function, the domain is assumed to be the square [-A,+A]x[-A,+A].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Howard Elman, Darran Furnaval,
    Solving the stochastic steady-state diffusion problem using multigrid,
    IMA Journal on Numerical Analysis,
    Volume 27, Number 4, 2007, pages 675-688.

    Roger Ghanem, Pol Spanos,
    Stochastic Finite Elements: A Spectral Approach,
    Revised Edition,
    Dover, 2003,
    ISBN: 0486428184,
    LC: TA347.F5.G56.

  Parameters:

    Input, double A, the "radius" of the square region.  The region
    is assumed to be [-A,+A]x[-A,+A].
    0 < A.

    Input, double CL, the correlation length.
    0 < CL.

    Input, double DC0, the constant term in the expansion of the 
    diffusion coefficient.  Take DC0 = 10.

    Input, int M_1D, the first and second dimensions of the
    stochastic parameter array.

    Input, double OMEGA[M_1D*M_1D], the stochastic parameters.

    Input, int N1, N2, the dimensions of the X and Y arrays.

    Input, double X[N1*N2], Y[N1*N2], the points where the diffusion 
    coefficient is to be evaluated.

    Output, double DIFFUSIVITY_2D_ELMAN[N1*N2], the value of the diffusion 
    coefficient at X.
*/
{
  double *c_1dx;
  double *c_1dy;
  double *dc;
  int i;
  int i1;
  int i2;
  int j;
  int k;
  double *lambda_1d;
  double *theta_1d;
/*
  Compute THETA.
*/
  theta_1d = theta_solve ( a, cl, m_1d );
/*
  Compute LAMBDA_1D.
*/
  lambda_1d = ( double * ) malloc ( m_1d * sizeof ( double ) );

  for ( i = 0; i < m_1d; i++ )
  {
    lambda_1d[i] = 2.0 * cl / ( 1.0 + cl * cl * theta_1d[i] * theta_1d[i] );
  }
/*
  Compute C_1DX(1:M1D) and C_1DY(1:M1D) at (X,Y).
*/
  c_1dx = ( double * ) malloc ( m_1d * n1 * n2 * sizeof ( double ) );
  c_1dy = ( double * ) malloc ( m_1d * n1 * n2 * sizeof ( double ) );

  for ( k = 0; k < n2; k++ )
  {
    for ( j = 0; j < n1; j++ )
    {
      for ( i = 0; i < m_1d; i++ )
      {
        c_1dx[i+j*m_1d+k*m_1d*n1] = 0.0;
        c_1dy[i+j*m_1d+k*m_1d*n1] = 0.0;
      }
    }
  }

  i = 0;

  for ( ; ; )
  {
    if ( m_1d <= i )
    {
      break;
    }

    for ( k = 0; k < n2; k++ )
    {
      for ( j = 0; j < n1; j++ )
      {
        c_1dx[i+j*m_1d+k*m_1d*n1] = cos ( theta_1d[i] * a * x[j+k*n1] ) 
          / sqrt ( a + sin ( 2.0 * theta_1d[i] * a ) 
          / ( 2.0 * theta_1d[i] ) );

        c_1dy[i+j*m_1d+k*m_1d*n1] = cos ( theta_1d[i] * a * y[j+k*n1] ) 
          / sqrt ( a + sin ( 2.0 * theta_1d[i] * a ) 
          / ( 2.0 * theta_1d[i] ) );
      }
    }

    i = i + 1;

    if ( m_1d <= i )
    {
      break;
    }

    for ( k = 0; k < n2; k++ )
    {
      for ( j = 0; j < n1; j++ )
      {
        c_1dx[i+j*m_1d+k*m_1d*n1] = sin ( theta_1d[i] * a * x[j+k*n1] ) 
          / sqrt ( a - sin ( 2.0 * theta_1d[i] * a ) 
          / ( 2.0 * theta_1d[i] ) );

        c_1dy[i+j*m_1d+k*m_1d*n1] = sin ( theta_1d[i] * a * y[j+k*n1] ) 
          / sqrt ( a - sin ( 2.0 * theta_1d[i] * a ) 
          / ( 2.0 * theta_1d[i] ) );
      }
    }

    i = i + 1;
  }
/*
  Evaluate the diffusion coefficient DC at (X,Y).
*/
  dc = ( double * ) malloc ( n1 * n2 * sizeof ( double ) );

  for ( k = 0; k < n2; k++ )
  {
    for ( j = 0; j < n1; j++ )
    {
      dc[j+k*n1] = dc0;
      for ( i2 = 0; i2 < m_1d; i2++ )
      {
        for ( i1 = 0; i1 < m_1d; i1++ )
        {
          dc[j+k*n1] = dc[j+k*n1] + sqrt ( lambda_1d[i1] * lambda_1d[i2] ) 
            * c_1dx[i1+j*m_1d+k*m_1d*n1] * c_1dy[i2+j*m_1d+k*m_1d*n1] * omega[i1+i2*m_1d];
        }
      }
    }
  }
/*
  Free memory.
*/
  free ( c_1dx );
  free ( c_1dy );
  free ( lambda_1d );
  free ( theta_1d );

  return dc;
}
/******************************************************************************/

double *diffusivity_2d_ntw ( double cl, double dc0, int m, double omega[], 
  int n, double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_NTW evaluates a 2D stochastic diffusivity function.

  Discussion:

    The 2D diffusion equation has the form

      - Del ( DC(X,Y) Del U(X,Y) ) = F(X,Y)

    where DC(X,Y) is a function called the diffusivity.

    In the stochastic version of the problem, the diffusivity function
    includes the influence of stochastic parameters:

      - Del ( DC(X,Y;OMEGA) Del U(X,Y;OMEGA) ) = F(X,Y).

    In this function, the domain is the rectangle [0,D]x[0,D] where D = 1.

    Note that in this problem the diffusivity has a one-dimensional
    spatial dependence on X, but not on Y

    The random variables OMEGA are independent, have zero mean and unit
    variance, and are uniformly distributed in [-sqrt(3),+sqrt(3)].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Xiang Ma, Nicholas Zabaras,
    An adaptive hierarchical sparse grid collocation algorithm for the solution
    of stochastic differential equations,
    Journal of Computational Physics,
    Volume 228, pages 3084-3113, 2009.

    Fabio Nobile, Raul Tempone, Clayton Webster,
    A Sparse Grid Stochastic Collocation Method for Partial Differential
    Equations with Random Input Data,
    SIAM Journal on Numerical Analysis,
    Volume 46, Number 5, 2008, pages 2309-2345.

  Parameters:

    Input, double CL, the desired physical correlation length for 
    the coefficient.

    Input, double DC0, the constant term in the expansion of the 
    diffusion coefficient.  Take DC0 = 0.5.

    Input, int M, the number of terms in the expansion.

    Input, double OMEGA[M], the stochastic parameters.

    Input, int N, the number of evaluation points.

    Input, double X[N], Y[N], the points where the diffusion 
    coefficient is to be evaluated.

    Output, double DIFFUSIVITY_2D_NTW[N], the value of the diffusion coefficient
    at (X,Y).
*/
{
  double d;
  double *dc;
  double *dc_arg;
  int i;
  double ihalf_r8;
  int j;
  double l;
  double lp;
  double *phi;
  const double r8_pi = 3.141592653589793;
  double zeta;
  double zeta_arg;

  d = 1.0;
  lp = r8_max ( d, 2.0 * cl );
  l = cl / lp;

  dc_arg = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    dc_arg[j] = 1.0 + omega[0] * sqrt ( sqrt ( r8_pi ) * l / 2.0 );
  }

  dc = ( double * ) malloc ( n * sizeof ( double ) );
  phi = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 2; i <= m; i++ )
  {
    ihalf_r8 = ( double ) ( i / 2 );
    zeta_arg = - pow ( ihalf_r8 * r8_pi * l, 2 ) / 8.0;
    zeta = sqrt ( sqrt ( r8_pi ) * l ) * exp ( zeta_arg );

    if ( ( i % 2 ) == 0 )
    {
      for ( j = 0; j < n; j++ )
      {
        phi[j] = sin ( ihalf_r8 * r8_pi * x[j] / lp );
      }
    }
    else
    {
      for ( j = 0; j < n; j++ )
      {
        phi[j] = cos ( ihalf_r8 * r8_pi * x[j] / lp );
      }
    }

    for ( j = 0; j < n; j++ )
    {
      dc_arg[j] = dc_arg[j] + zeta * phi[j] * omega[i-1];
    }
  }

  for ( j = 0; j < n; j++ )
  {
    dc[j] = dc0 + exp ( dc_arg[j] );
  }

  free ( dc_arg );
  free ( phi );

  return dc;
}
/******************************************************************************/

double *diffusivity_2d_pwc ( int h, int w, double a, double b, double c, 
  double d, double omega[], int n, double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_PWC: piecewise constant diffusivity function.

  Discussion:

    The 2D stochastic diffusion equation has the form

      - Del ( RHO(X,Y;OMEGA) Del U(X,Y;OMEGA) ) = F(X,Y).

    Here, the diffusivity RHO is assumed to be a piecewise constant function,
    defined on rectangular grid over [A,B]x[C,D] that is H cells high
    and W cells wide.  The parameters OMEGA(H*W) are assumed to be given 
    positive values that are bounded away from 0.

    The underlying grid is assumed to be equally spaced, so each cell
    is (D-C)/M units high and (B-A)/N wide.

       ^  ^  +-------+-------+-------+-------+
       D  H  | (H,1) | (H,2) | ----- | (H,W) |
       |  |  +-------+-------+-------+-------+
             | ----- | ----- | (I,J) | ----- |
       Y  I  +-------+-------+-------+-------+
             | (2,1) | (2,2) | ----- | (2,W) |
       |  |  +-------+-------+-------+-------+
       |  |  | (1,1) | (1,2) | ----- | (1,W) |
       C  1  +-------+-------+-------+-------+
       |  |
       +--+--1-------------- J --------------W->
       +--+--A-------------- X --------------B->

    Indexing is tricky, since our (X,Y) coordinate system indexing and
    conventions for indexing an array and for ordering indices do not
    match up.  An arbitrary choice must be made, and here we associate
    "width" and "X" and "J", as well as "height" and "Y" and "I".
    We start in the lower left corner, and proceed right first, and
    then move up one row.

    The following coordinate systems are available:

    * cell index (I,J):  (1,1) <= (I,J) <= (H,W). 
      I refers to "height" and J to "width".

    * cell counter K:    1     <= K     <= H*W
      Count from lower left to lower right, then
      go up one row.

    * physical cell center coordinates (XC,YC)
      the (X,Y) coordinates of the centers of a cell

    * physical coordinates (X,Y) in [A,B]x[C,D].
      the (X,Y) coordinates of any point
      
    * normalized coordinates (X01,Y01) in [0,1]x[0,1].
   
    Transformations from one coordinate system to another:

    * (I,J) --> (XC,YC)
                X01 = (2*J-1)/2/W
                Y01 = (2*I-1)/2/H
                XC = A + (B-A) * X01
                YC = C + (D-C) * Y01

    * (I,J) --> K
                K = (I-1)*W+J

    * K     --> (I,J)
                I = floor ( K - 1 ) / W ) + 1
                J = mod ( K - 1, W ) + 1

    * K     --> (XC,YC)
                I = floor ( K - 1 ) / W ) + 1
                J = mod ( K - 1, W ) + 1
                X01 = (2*J-1)/2/W
                Y01 = (2*I-1)/2/H
                XC = A + (B-A) * X01
                YC = C + (D-C) * Y01

    * (X,Y) --> (I,J)
                X01 = ( X - A ) / ( B - A )
                Y01 = ( Y - C ) / ( D - C )
                I = round ( ( 2 * h * Y01 + 1 ) / 2 );
                J = round ( ( 2 * w * X01 + 1 ) / 2 );

    * (X,Y) --> K
                X01 = ( X - A ) / ( B - A )
                Y01 = ( Y - C ) / ( D - C )
                I = round ( ( 2 * h * Y01 + 1 ) / 2 );
                J = round ( ( 2 * w * X01 + 1 ) / 2 );
                K = (I-1)*W+J

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 March 2019

  Author:

    John Burkardt

  Reference:

    Ivo Babuska, Fabio Nobile, Raul Tempone,
    A stochastic collocation method for elliptic partial differential equations
    with random input data,
    SIAM Journal on Numerical Analysis,
    Volume 45, Number 3, 2007, pages 1005-1034.

  Parameters:

    Input, int H, W, specifies the number of elements.

    Input, double A, B, the lower and upper limits of X.

    Input, double C, D, the lower and upper limits of Y.

    Input, double OMEGA[H*W], the parameters.

    Input, int N, the number of evaluation points.

    Input, double X[N], Y[N], the points where the diffusion coefficient is to 
    be evaluated.

    Output, double DIFFUSIVITY_2D_PWC[N], the value of the diffusion 
    coefficient at each point.
*/
{
  int i;
  int ij;
  int j;
  int k;
  double *rho;
  double x01;
  double y01;

  rho = ( double * ) malloc ( n * sizeof ( double ) );

  for ( ij = 0; ij < n; ij++ )
  {
    x01 = ( x[ij] - a ) / ( b - a );
    y01 = ( y[ij] - c ) / ( d - c );

    i = ( int ) round ( ( 2 * h * y01 - 1 ) / 2 );
    i = i4_max ( i, 0 );
    i = i4_min ( i, h - 1 );

    j = ( int ) round ( ( 2 * w * x01 - 1 ) / 2 );
    j = i4_max ( j, 0 );
    j = i4_min ( j, w - 1 );

    k = i * w + j;
    rho[ij] = omega[k];
 }

  return rho;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
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

double r8_max ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    R8_MAX returns the maximum of two R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2006

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

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a pseudorandom R8 scaled to [0,1].

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  int i4_huge = 2147483647;
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

double r8mat_max ( int m, int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_MAX returns the maximum entry of an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, double A[M*N], the M by N matrix.

    Output, double R8MAT_MAX, the maximum entry of A.
*/
{
  int i;
  int j;
  double value;

  value = a[0+0*m];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( value < a[i+j*m] )
      {
        value = a[i+j*m];
      }
    }
  }
  return value;
}
/******************************************************************************/

double *r8vec_linspace_new ( int n, double a, double b )

/******************************************************************************/
/*
  Purpose:

    R8VEC_LINSPACE_NEW creates a vector of linearly spaced values.

  Discussion:

    An R8VEC is a vector of R8's.

    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
 
    In other words, the interval is divided into N-1 even subintervals,
    and the endpoints of intervals are used as the points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A, B, the first and last entries.

    Output, double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
*/
{
  int i;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  if ( n == 1 )
  {
    x[0] = ( a + b ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( ( double ) ( n - 1 - i ) * a 
             + ( double ) (         i ) * b ) 
             / ( double ) ( n - 1     );
    }
  }
  return x;
}
/******************************************************************************/

double r8vec_max ( int n, double r8vec[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MAX returns the value of the maximum element in a R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, double R8VEC[N], a pointer to the first entry of the array.

    Output, double R8VEC_MAX, the value of the maximum element.  This
    is set to 0.0 if N <= 0.
*/
{
  int i;
  double value;

  if ( n <= 0 )
  {
    value = 0.0;
    return value;
  }

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < r8vec[i] )
    {
      value = r8vec[i];
    }
  }
  return value;
}
/******************************************************************************/

void r8vec_mesh_2d ( int nx, int ny, double xvec[], double yvec[], 
  double xmat[], double ymat[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MESH_2D creates a 2D mesh from X and Y vectors.

  Discussion:

    An R8VEC is a vector of R8's.

    NX = 2
    XVEC = ( 1, 2, 3 )
    NY = 3
    YVEC = ( 4, 5 )

    XMAT = (
      1, 2, 3
      1, 2, 3 )

    YMAT = (
      4, 4, 4
      5, 5, 5 ) 
    
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2013

  Parameters:

    Input, int NX, NY, the number of X and Y values.

    Input, double XVEC[NX], YVEC[NY], the X and Y coordinate
    values.

    Output, double XMAT[NX*NY], YMAT[NX*NY], the coordinate
    values of points on an NX by NY mesh.
*/
{
  int i;
  int j;

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      xmat[i+j*nx] = xvec[i];
    }
  }

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      ymat[i+j*nx] = yvec[j];
    }
  }

 return;
}
/******************************************************************************/

void r8vec_normal_01 ( int n, int *seed, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORMAL_01 returns a unit pseudonormal R8VEC.

  Discussion:

    The standard normal probability distribution function (PDF) has
    mean 0 and standard deviation 1.

    This routine can generate a vector of values on one call.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of values desired.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double X[N], a sample of the standard normal PDF.

  Local parameters:

    Local, double R[N+1], is used to store some uniform random values.
    Its dimension is N+1, but really it is only needed to be the
    smallest even number greater than or equal to N.

    Local, int X_LO, X_HI, records the range of entries of
    X that we need to compute.
*/
{
  int i;
  int m;
  const double r8_pi = 3.141592653589793;
  double *r;
  int x_hi;
  int x_lo;
/*
  Record the range of X we need to fill in.
*/
  x_lo = 1;
  x_hi = n;
/*
  If we need just one new value, do that here to avoid null arrays.
*/
  if ( x_hi - x_lo + 1 == 1 )
  {
    r = r8vec_uniform_01_new ( 2, seed );

    x[x_hi-1] = sqrt ( - 2.0 * log ( r[0] ) ) * cos ( 2.0 * r8_pi * r[1] );

    free ( r );
  }
/*
  If we require an even number of values, that's easy.
*/
  else if ( ( x_hi - x_lo + 1 ) % 2 == 0 )
  {
    m = ( x_hi - x_lo + 1 ) / 2;

    r = r8vec_uniform_01_new ( 2*m, seed );

    for ( i = 0; i <= 2*m-2; i = i + 2 )
    {
      x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * r8_pi * r[i+1] );
      x[x_lo+i  ] = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * r8_pi * r[i+1] );
    }
    free ( r );
  }
/*
  If we require an odd number of values, we generate an even number,
  and handle the last pair specially, storing one in X(N), and
  saving the other for later.
*/
  else
  {
    x_hi = x_hi - 1;

    m = ( x_hi - x_lo + 1 ) / 2 + 1;

    r = r8vec_uniform_01_new ( 2*m, seed );

    for ( i = 0; i <= 2*m-4; i = i + 2 )
    {
      x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * r8_pi * r[i+1] );
      x[x_lo+i  ] = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * r8_pi * r[i+1] );
    }

    i = 2*m - 2;

    x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * r8_pi * r[i+1] );
  }

  return;
}
/******************************************************************************/

double *r8vec_normal_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORMAL_01_NEW returns a unit pseudonormal R8VEC.

  Discussion:

    The standard normal probability distribution function (PDF) has
    mean 0 and standard deviation 1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of values desired.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_NORMAL_01_NEW[N], a sample of the standard normal PDF.
*/
{
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  r8vec_normal_01 ( n, seed, x );

  return x;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %8d: %14f\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

void r8vec_uniform_01 ( int n, int *seed, double r[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01 returns a unit pseudorandom R8VEC.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R[N], the vector of pseudorandom values.
*/
{
  int i;
  int i4_huge = 2147483647;
  int k;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01 - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return;
}
/******************************************************************************/

double *r8vec_uniform_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
}
/******************************************************************************/

double *r8vec_uniform_ab_new ( int n, double a, double b, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_AB_NEW returns a scaled pseudorandom R8VEC.

  Discussion:

    Each dimension ranges from A to B.

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 January 2005

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A, B, the lower and upper limits of the pseudorandom values.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_AB_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  const int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_AB_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = a + ( b - a ) * ( ( double ) ( *seed ) * 4.656612875E-10 );
  }

  return r;
}
/******************************************************************************/

double *theta_solve ( double a, double cl, int m )

/******************************************************************************/
/*
  Purpose:

    THETA_SOLVE solves a pair of transcendental equations.

  Discussion:

    The vector THETA returned by this function is needed in order to define
    the terms in a Karhunen-Loeve expansion of a diffusion coefficient.

    The two equations are:

      1/CL - THETA * TAN ( A * THETA ) = 0
      THETA - 1/CL * TAN ( A * THETA ) = 0

    A and CL are taken to be positive.  Over each open interval 

      ( n - 1/2 pi, n + 1/2 pi ) / A, for N = 0, 1, ...

    the function TAN ( A * THETA ) monotonically rises from -oo to +00; 
    therefore, it can be shown that there is one root of each equation 
    in every interval of this form.  Moreover, because of the positivity
    of A and CL, we can restrict our search to the interval 

      [ n pi, n + 1/2 pi ) / A, for N = 0, 1, ...

    This function computes K such roots, starting in the first interval,
    finding those two roots, moving to the next interval, and so on, until
    the requested number of roots have been found.  Odd index roots will
    correspond to the first equation, and even index roots to the second.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Howard Elman, Darran Furnival,
    Solving the Stochastic Steady-State Diffusion Problem Using Multigrid,
    University of Maryland Department of Computer Science,
    Technical Report TR-4786.

  Parameters:

    Input, double A, the "radius" of the domain, D = (-A,A)x(-A,A).
    0 < A.

    Input, double CL, the correlation length.
    0 < CL.

    Input, int M, the number of values to compute.

    Output, double THETA_SOLVE[M], the values of Theta.
*/
{
  double bmatol;
  double eps;
  double fa;
  double fc;
  double ftol;
  int k;
  const double r8_pi = 3.141592653589793;
  double *theta;
  double xa;
  double xa_init;
  double xb;
  double xb_init;
  double xc;

  theta = ( double * ) malloc ( m * sizeof ( double ) );
  for ( k = 0; k < m; k++ )
  {
    theta[k] = 0.0;
  }
/*
  [ XA_INIT, XB_INIT] = [ n * pi, n+1/2 pi ] / a, n = 0, 1, 2, ...
*/
  xa_init = 0.0;
  xb_init = ( r8_pi / 2.0 ) / a;
  eps = r8_epsilon ( );

  k = 0;
  for ( ; ; )
  {
/*
  Seek root of equation 1 in interval.
*/
    if ( m <= k )
    {
      break;
    }

    k = k + 1;
    xa = xa_init;
    fa = 1.0 / cl - xa * tan ( a * xa );
    ftol = eps * ( fabs ( fa ) + 1.0 );
    xb = xb_init;
    fc = fa;
    bmatol = 100.0 * eps * ( fabs ( xa ) + fabs ( xb ) );

    while ( bmatol < xb - xa )
    {
      xc = ( xa + xb ) / 2.0;
      fc = 1.0 / cl - xc * tan ( a * xc );

      if ( fabs ( fc ) <= ftol )
      {
        break;
      }
      else if ( 0.0 < fc )
      {
        xa = xc;
      }
      else
      {
        xb = xc;
      }
    }

    theta[k-1] = xc;
/*
  Seek root of equation 2 in interval.
*/
    if ( m <= k )
    {
      break;
    }

    k = k + 1;
/*
  In the first interval, we need to skip the zero root of equation 2.
*/
    if ( k == 2 )
    {
      k = k - 1;
    }
    else
    {
      xa = xa_init;
      fa = xa - tan ( a * xa ) / cl;
      ftol = eps * ( fabs ( fa ) + 1.0 );
      xb = xb_init;

      while ( bmatol < xb - xa )
      {
        xc = ( xa + xb ) / 2.0;
        fc = xc - tan ( a * xc ) / cl;

        if ( fabs ( fc ) <= ftol )
        {
          break;
        }
        else if ( 0.0 < fc )
        {
          xa = xc;
        }
        else
        {
          xb = xc;
        }
      }
      theta[k-1] = xc;
    }
/*
  Advance the interval.
*/
    xa_init = xa_init + r8_pi / a;
    xb_init = xb_init + r8_pi / a;
  }

  return theta;
}
/******************************************************************************/

void timestamp ( )

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
