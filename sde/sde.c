# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

# include "sde.h"
# include "qr_solve.h"
# include "r8lib.h"

/******************************************************************************/

double *bpath ( int *seed, int n )

/******************************************************************************/
/*
  Purpose:

    BPATH performs a Brownian path simulation.

  Discussion:

    This routine computes one simulation of discretized Brownian 
    motion over the time interval [0,1] using N time steps.
    The user specifies a random number seed.  Different values of
    the seed will result in different realizations of the path.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2012

  Author:

    Original MATLAB version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input/output, int *SEED, a seed for the random number 
    generator.

    Input, int N, the number of steps.

    Output, double BPATH[N+1], the Brownian path.
*/
{
  double dt;
  double *dw;
  int j;
  double tmax;
  double *w;

  tmax = 1.0;
  dt = tmax / ( double ) ( n );
/*
  Define the increments dW.
*/
  dw = r8vec_normal_01_new ( n, seed );

  for ( j = 0; j < n; j++ )
  {
    dw[j] = sqrt ( dt ) * dw[j];
  }
/*
  W is the sum of the previous increments.
*/
  w = ( double * ) malloc (  ( n + 1 ) * sizeof ( double ) );

  w[0] = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    w[j] = w[j-1] + dw[j];
  }

  free ( dw );

  return w;
}
/******************************************************************************/

void bpath_gnuplot ( int n, double w[] )

/******************************************************************************/
/*
  Purpose:

    BPATH_GNUPLOT writes a GNUPLOT input file to plot BPATH data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int N, the number of steps.

    Input, double W[N+1], the Brownian path.
*/
{
  char command_filename[] = "bpath_commands.txt";
  FILE *command_unit;
  char data_filename[] = "bpath_data.txt";
  FILE *data_unit;
  int i;
  double t;
/*
  Create the data file.
*/
  data_unit = fopen ( data_filename, "wt" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( i ) / ( double ) ( n );
    fprintf ( data_unit, "  %14.6g  %14.6g\n", t, w[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  BPATH data stored in \"%s\".\n", data_filename );
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# bpath_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::bpath_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < bpath_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'bpath.png'\n" );
  fprintf ( command_unit, "set xlabel 't'\n" );
  fprintf ( command_unit, "set ylabel 'W(t)'\n" );
  fprintf ( command_unit, "set title 'Brownian motion by BPATH'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot 'bpath_data.txt' using 1:2\n" );
  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  BPATH plot commands stored in \"%s\".\n", command_filename );

  return;
}
/******************************************************************************/

void bpath_average ( int *seed, int m, int n, double u[], double umean[], 
  double *error )

/******************************************************************************/
/*
  Purpose:

    BPATH_AVERAGE: displays the average of 1000 Brownian paths.

  Discussion:

    This routine computes M simulations of discretized Brownian 
    motion W(t) over the time interval [0,1] using N time steps.
    The user specifies a random number seed.  Different values of
    the seed will result in a different set of realizations of the path.

    Actually, we are interested in a function u(W(t)):

      u(W(t)) = exp ( t + W(t)/2 )

    The routine plots 5 of the simulations, as well as the average
    of all the simulations.  

    The plot of the average should be quite smooth.  Its expected
    value is exp ( 9 * t / 8 ), and we compute the 'error', that is,
    the difference between the averaged value and this expected
    value.  This 'error' should decrease as the number of simulation
    is increased.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input/output, int *SEED, a seed for the random 
    number generator.

    Input, int M, the number of simulations to compute 
    and average.  A typical value is 1000.

    Input, int N, the number of steps.  A typical value
    is 500.

    Output, double U[M*(N+1)], the M paths.

    Output, double UMEAN[N+1], the averaged path.

    Output, double *ERROR, the maximum difference between the
    averaged path and the exact expected value.
*/
{
  double dt;
  double *dw;
  int i;
  int j;
  double *t;
  double tmax;
  double *w;

  tmax = 1.0;
  dt = tmax / ( double ) ( n );

  t = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  for ( j = 0; j <= n; j++ )
  {
    t[j] = ( double ) ( j ) * tmax / ( double ) ( n );
  }

  w = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
/*
  Define the increments dW.
*/
    dw = r8vec_normal_01_new ( n, seed );

    for ( j = 0; j < n; j++ )
    {
      dw[j] = sqrt ( dt ) * dw[j];
    }
/*
  W is the sum of the previous increments.
*/
    w[0] = 0.0;
    for ( j = 1; j <= n; j++ )
    {
      w[j] = w[j-1] + dw[j-1];
    }

    for ( j = 0; j <= n; j++ )
    {
      u[i+j*m] = exp ( t[j] + 0.5 * w[j] );
    }
    free ( dw );
  }
/*
  Average the M estimates of the path.
*/
  for ( j = 0; j <= n; j++ )
  {
    umean[j] = 0.0;
    for ( i = 0; i < m; i++ )
    {
      umean[j] = umean[j] + u[i+j*m];
    }
    umean[j] = umean[j] / ( double ) ( m );
  }

  *error = 0.0;
  for ( j = 0; j <= n; j++ )
  {
    *error = r8_max ( *error, fabs ( umean[j] - exp ( 9.0 * t[j] / 8.0 ) ) );
  }

  free ( t );
  free ( w );

  return;
}
/******************************************************************************/

void bpath_average_gnuplot ( int m, int n, double u[], double umean[] )

/******************************************************************************/
/*
  Purpose:

    BPATH_AVERAGE_GNUPLOT writes a GNUPLOT input file to plot BPATH_AVERAGE data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int M, the number of simulations.

    Input, int N, the number of steps. 

    Input, double U[M*(N+1)], the M paths.

    Input, double UMEAN[N+1], the averaged path.
*/
{
  char command_filename[] = "bpath_average_commands.txt";
  FILE *command_unit;
  char data_filename[] = "bpath_average_data.txt";
  FILE *data_unit;
  int i;
  int j;
  double t;
/*
  Create the data file.
*/
  data_unit = fopen ( data_filename, "wt" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( i ) / ( double ) ( n );
    fprintf ( data_unit, "  %14.6g", t );
    for ( j = 0; j < 5; j++ )
    {
      fprintf ( data_unit, "  %14.6g", u[j+i*m] );
    }
    fprintf ( data_unit, "  %14.6g\n", umean[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  BPATH_AVERAGE data stored in \"%s\".\n", data_filename ); 
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# bpath_average_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::bpath_average_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < bpath_average_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'bpath_average.png'\n" );
  fprintf ( command_unit, "set xlabel 't'\n" );
  fprintf ( command_unit, "set ylabel 'W(t)'\n" );
  fprintf ( command_unit, "set title 'Averaged Brownian paths'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot 'bpath_average_data.txt' using 1:2 title 'sample 1', \\\n" );
  fprintf ( command_unit, "     'bpath_average_data.txt' using 1:3 title 'sample 2', \\\n" );
  fprintf ( command_unit, "     'bpath_average_data.txt' using 1:4 title 'sample 3', \\\n" );
  fprintf ( command_unit, "     'bpath_average_data.txt' using 1:5 title 'sample 4', \\\n" );
  fprintf ( command_unit, "     'bpath_average_data.txt' using 1:6 title 'sample 5', \\\n" );
  fprintf ( command_unit, "     'bpath_average_data.txt' using 1:7 title 'average' lw 3\n" );
  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  BPATH_AVERAGE plot commands stored in \"%s\".\n", command_filename ); 

  return;
}
/******************************************************************************/

void chain ( int *seed, int n, double xem[], double vem[], double *diff )

/******************************************************************************/
/*
  Purpose:

    CHAIN tests the stochastic Chain Rule.

  Discussion:

    This function solves a stochastic differential equation for 

      V = sqrt(X) 

    where X satisfies the stochastic differential equation:
 
      dX = ( alpha - X ) * dt + beta * sqrt(X) dW,
      X(0) = Xzero,

    with 

      alpha = 2,
      beta = 1,
      Xzero = 1.

    From the stochastic Chain Rule, the SDE for V is therefore:

      dV = ( ( 4 * alpha - beta^2 ) / ( 8 * V ) - 1/2 V ) dt + 1/2 beta dW
      V(0) = sqrt ( Xzero ).

    Xem is the Euler-Maruyama solution for X. 

    Vem is the Euler-Maruyama solution of the SDE for V from
    the stochastic Chain Rule.

    Hence, we compare sqrt(Xem) and Vem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int *SEED, a seed for the random number generator.

    Input, int N, the number of time steps.

    Output, double XEM[N+1], the computed value of X.

    Output, double VEM[N+1], the computed value of V.

    Output, double *DIFF, the maximum value of |sqrt(XEM)-V|.
*/
{
  double alpha;
  double beta;
  double dt;
  double dt2;
  double *dw;
  int i;
  int j;
  double tmax;
/*
  Set problem parameters.
*/
  alpha = 2.0;
  beta = 1.0;
/*
  Stepping parameters.
  dt2 is the size of the Euler-Maruyama steps.
*/
  tmax = 1.0;
  dt = tmax / ( double ) ( n );
  dt2 = dt;
/*
  Define the increments dW.
*/
  dw = r8vec_normal_01_new ( n, seed );

  for ( i = 0; i < n; i++ )
  {
    dw[i] = sqrt ( dt ) * dw[i];
  }
/*
  Solve for X(t).
*/
  xem[0] = 1.0;
  for ( j = 1; j <= n; j++ )
  {
    xem[j] = xem[j-1] + ( alpha - xem[j-1] ) * dt2 
                      + beta * sqrt ( xem[j-1] ) * dw[j-1];
  }
/*
  Solve for V(t).
*/
  vem[0] = sqrt ( xem[0] );
  for ( j = 1; j <= n; j++ )
  {
    vem[j] = vem[j-1] 
      + ( ( 4.0 * alpha - beta * beta ) / ( 8.0 * vem[j-1] ) 
      - 0.5 * vem[j-1] ) * dt2 
      + 0.5 * beta * dw[j-1];
  }
/*
  Compare sqrt(X) and V.
*/
  *diff = 0.0;
  for ( i = 0; i <= n; i++ )
  {
    *diff = r8_max ( *diff, fabs ( sqrt ( xem[i] ) - vem[i] ) );
  }

  free ( dw );

  return;
}
/******************************************************************************/

void chain_gnuplot ( int n, double x[], double v[] )

/******************************************************************************/
/*
  Purpose:

    CHAIN_GNUPLOT writes a GNUPLOT input file to plot CHAIN data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int N, the number of steps.

    Input, double X[N+1], the value of X.

    Input, double V[N+1], the value of V.
*/
{
  char command_filename[] = "chain_commands.txt";
  FILE *command_unit;
  char data_filename[] = "chain_data.txt";
  FILE *data_unit;
  int i;
  double t;
/*
  Create the data file.
*/
  data_unit = fopen ( data_filename, "wt" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( i ) / ( double ) ( n );
    fprintf ( data_unit, "  %14.6g  %14.6g  %14.6g\n", t, sqrt ( x[i] ), v[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  CHAIN data stored in \"%s\".\n", data_filename ); 
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# chain_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::chain_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < chain_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'chain.png'\n" );
  fprintf ( command_unit, "set xlabel 't'\n" );
  fprintf ( command_unit, "set ylabel 'Sqrt(X(t)) vs V(X(t))'\n" );
  fprintf ( command_unit, "set title 'V(X(t)) from X(t) and from Chain Rule'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot 'chain_data.txt' using 1:2 title 'Sqrt(X(t))', \\\n" );
  fprintf ( command_unit, "     'chain_data.txt' using 1:3 title 'V(X(t))'\n" );
  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  CHAIN plot commands stored in \"%s\".\n", command_filename ); 

  return;
}
/******************************************************************************/

void em ( int *seed, int n, double t[], double xtrue[], double t2[], 
  double xem[], double *error )

/******************************************************************************/
/*
  Purpose:

    EM applies the Euler-Maruyama method to a linear SDE.

  Discussion:

    The SDE is 

      dX = lambda * X dt + mu * X dW,   
      X(0) = Xzero,

    where 

      lambda = 2,
      mu = 1,
      Xzero = 1.

    The discretized Brownian path over [0,1] uses
    a stepsize dt = 2^(-8).

    The Euler-Maruyama method uses a larger timestep Dt = R*dt,
    where R is an integer.  For an SDE of the form

      dX = f(X(t)) dt + g(X(t)) dW(t)

    it has the form

      X(j) = X(j-1) + f(X(j-1)) * Dt + g(X(j-1)) * ( W(j*Dt) - W((j-1)*Dt) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546

  Parameters:

    Input/output, int *SEED, a seed for the random 
    number generator.

    Input, int N, the number of time steps.  A typical
    value is 2^8.  N should be a multiple of 4.

    Output, double T[N+1], the time values for the exact solution.

    Output, double XTRUE[N+1], the exact solution.

    Output, double T2[N/4+1], the time values for the 
    Euler-Maruyama solution.

    Output, double XEM[N/4+1], the Euler-Maruyama solution.

    Output, double *ERROR, the value of | XEM(T) - XTRUE(T) |.
*/
{
  double dt;
  double dt2;
  double *dw;
  double dw2;
  int i;
  int j;
  int l;
  double lambda;
  double mu;
  int r;
  double tmax;
  double *w;
  double xzero;
/*
  Set problem parameters.
*/
  lambda = 2.0;
  mu = 1.0;
  xzero = 1.0;
/*
  Set stepping parameters.
*/
  tmax = 1.0;
  dt = tmax / ( double ) ( n );
/*
  Define the increments dW.
*/
  dw = r8vec_normal_01_new ( n, seed );

  for ( j = 0; j < n; j++ )
  {
    dw[j] = sqrt ( dt ) * dw[j];
  }
/*
  Sum the Brownian increments.
*/
  w = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  w[0] = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    w[j] = w[j-1] + dw[j-1];
  }

  for ( j = 0; j <= n; j++)
  {
    t[j] = ( double ) ( j ) * tmax / ( double ) ( n );
  }
/*
  Compute the discretized Brownian path.
*/
  for ( j = 0; j <= n; j++ )
  {
    xtrue[j] = xzero * exp ( ( lambda - 0.5 * mu * mu ) * ( t[j] + mu * w[j] ) );
  }
/*
  Set:
  R, the multiplier for the EM step, 
  Dt, the EM stepsize,
  L, the number of EM steps (we need N to be a multiple of R!)
*/
  r = 4;
  dt2 = ( double ) ( r ) * dt;
  l = n / r;

  for ( j = 0; j <= l; j++ )
  {
    t2[j] = ( double ) ( j ) * tmax / ( double ) ( l );
  }
/*
  Compute XEM.
*/
  xem[0] = xzero;
  for ( j = 1; j <= l; j++ )
  {
    dw2 = 0.0;
    for ( i = r * ( j - 1 ); i < r * j; i++ )
    {
      dw2 = dw2 + dw[i];
    }
    xem[j] = xem[j-1] + dt2 * lambda * xem[j-1] + mu * xem[j-1] * dw2;
  }

  *error = fabs ( xem[l] - xtrue[n] );

  free ( dw );
  free ( w );

  return;
}
/******************************************************************************/

void em_gnuplot ( int n, double t[], double xtrue[], double t2[], double xem[] )

/******************************************************************************/
/*
  Purpose:

    EM_GNUPLOT writes a GNUPLOT input file to plot EM data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int N, the number of steps.

    Input, double T[N+1], the time values for the exact solution.

    Input, double XTRUE[N+1], the exact solution.

    Input, double T2[N/4+1], the time values for the 
    Euler-Maruyama solution.

    Input, double XEM[N/4+1], the Euler-Maruyama solution.
*/
{
  char command_filename[] = "em_commands.txt";
  FILE *command_unit;
  char data1_filename[] = "em1_data.txt";
  char data2_filename[] = "em2_data.txt";
  FILE *data_unit;
  int i;
/*
  Create data file #1.
*/
  data_unit = fopen ( data1_filename, "wt" );

  for ( i = 0; i <= n; i++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g\n", t[i], xtrue[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  EM data #1 stored in \"%s\".\n", data1_filename ); 
/*
  Create data file #2.
*/
  data_unit = fopen ( data2_filename, "wt" );

  for ( i = 0; i <= n / 4; i++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g\n", t2[i], xem[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  EM data #2 stored in \"%s\".\n", data2_filename ); 
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# em_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::em_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < em_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'em.png'\n" );
  fprintf ( command_unit, "set xlabel 't'\n" );
  fprintf ( command_unit, "set ylabel 'X(t)'\n" );
  fprintf ( command_unit, "set title 'Exact X(t) and Euler-Maruyama Estimate'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot 'em1_data.txt' using 1:2 title 'Exact X(t))', \\\n" );
  fprintf ( command_unit, "     'em2_data.txt' using 1:2 title 'EM X(t)'\n" );
  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  EM plot commands stored in \"%s\".\n", command_filename ); 

  return;
}
/******************************************************************************/

void emstrong ( int *seed, int m, int n, int p_max, double dtvals[], 
  double xerr[] )

/******************************************************************************/
/*
  Purpose:

    EMSTRONG tests the strong convergence of the EM method.

  Discussion:

    The SDE is 

      dX = lambda * X dt + mu * X dW,   
      X(0) = Xzero,

    where 

      lambda = 2,
      mu = 1,
      Xzero = 1.

    The discretized Brownian path over [0,1] has dt = 2^(-9).

    The Euler-Maruyama method uses 5 different timesteps: 
      16*dt, 8*dt, 4*dt, 2*dt, dt.

    We are interested in examining strong convergence at T=1,
    that is

      E | X_L - X(T) |.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input/output, int *SEED, a seed for the random 
    number generator.

    Input, int M, the number of simulations to perform.
    A typical value is M = 1000.

    Input, int N, the number of time steps to take.
    A typical value is N = 512.

    Input, int P_MAX, the number of time step sizes to use.
    A typical value is 5.

    Output, double DTVALS[P_MAX], the time steps used.

    Output, double XERR[P_MAX], the averaged absolute error in the
    solution estimate at the final time.
*/
{
  double *a;
  double dt;
  double dt2;
  double *dw;
  double e;
  int i;
  int j;
  int k;
  int l;
  double lambda;
  double mu;
  int p;
  int r;
  double resid;
  double *rhs;
  int s;
  double *sol;
  double tmax;
  double *w;
  double winc;
  double xtemp;
  double xtrue;
  double xzero;
/*
  Set problem parameters.
*/
  lambda = 2.0;
  mu = 1.0;
  xzero = 1.0;
/*
  Set stepping parameters.
*/
  tmax = 1.0;
  dt = tmax / ( double ) ( n );

  for ( p = 0; p < p_max; p++ )
  {
    dtvals[p] = dt * pow ( 2.0, p );
  }
/*
  Sample over discrete Brownian paths.
*/
  for ( p = 0; p < p_max; p++ )
  {
    xerr[p] = 0.0;
  }

  for ( s = 0; s < m; s++ )
  {
/*
  Define the increments dW.
*/
    dw = r8vec_normal_01_new ( n, seed );

    for ( j = 0; j < n; j++ )
    {
      dw[j] = sqrt ( dt ) * dw[j];
    }
/*
  Sum the increments to get the Brownian path.
*/
    w = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
    w[0] = 0.0;
    for ( j = 1; j <= n; j++ )
    {
      w[j] = w[j-1] + dw[j-1];
    }
/*
  Determine the true solution.
*/
    xtrue = xzero * exp ( ( lambda - 0.5 * mu * mu ) + mu * w[n] );
/*
  Use the Euler-Maruyama method with 5 different time steps dt2 = r * dt
  to estimate the solution value at time TMAX.
*/
    for ( p = 0; p < p_max; p++ )
    {
      dt2 = dtvals[p];
      r = i4_power ( 2, p );
      l = n / r;
      xtemp = xzero;
      for ( j = 0; j < l; j++ )
      {
        winc = 0.0;
        for ( k = r * j; k < r * ( j + 1 ); k++ )
        {
          winc = winc + dw[k];
        }
        xtemp = xtemp + dt2 * lambda * xtemp + mu * xtemp * winc;
      }
      xerr[p] = xerr[p] + fabs ( xtemp - xtrue );
    }
    free ( dw );
    free ( w );
  }

  for ( p = 0; p < p_max; p++ )
  {
    xerr[p] = xerr[p] / ( double ) ( m );
  }
/*
  Least squares fit of error = c * dt^q.
*/
  a = ( double * ) malloc ( p_max * 2 * sizeof ( double ) );
  rhs = ( double * ) malloc ( p_max * sizeof ( double ) );

  for ( i = 0; i < p_max; i++ )
  {
    a[i+0*p_max] = 1.0;
    a[i+1*p_max] = log ( dtvals[i] );
    rhs[i] = log ( xerr[i] );
  }
  sol = qr_solve ( p_max, 2, a, rhs );

  printf ( "\n" );
  printf ( "EMSTRONG:\n" );
  printf ( "  Least squares solution to Error = c * dt ^ q\n" );
  printf ( "  (Expecting Q to be about 1/2.)\n" );
  printf ( "  Computed Q = %g\n", sol[1] );

  resid = 0.0;
  for ( i = 0; i < p_max; i++ )
  {
    e = a[i+0*p_max] * sol[0] + a[i+1*p_max] * sol[1] - rhs[i];
    resid = resid + e * e;
  }
  resid = sqrt ( resid );
  printf ( "  Residual is %g\n", resid );

  free ( a );
  free ( rhs );
  free ( sol );

  return;
}
/******************************************************************************/

void emstrong_gnuplot ( int p_max, double dtvals[], double xerr[] )

/******************************************************************************/
/*
  Purpose:

    EMSTRONG_GNUPLOT writes a GNUPLOT input file to plot EMSTRONG data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int P_MAX, the number of time step sizes to use.

    Input, double DTVALS(P_MAX), the time steps used.

    Input, double XERR(P_MAX), the averaged absolute error in the
    solution estimate at the final time.
*/
{
  char command_filename[] = "emstrong_commands.txt";
  FILE *command_unit;
  char data_filename[] = "emstrong_data.txt";
  FILE *data_unit;
  int i;
/*
  Create data file.
*/
  data_unit = fopen ( data_filename, "wt" );

  for ( i = 0; i < p_max; i++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g  %14.6g\n", dtvals[i], xerr[i], sqrt ( dtvals[i] ) );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  EMSTRONG data stored in \"%s\".\n", data_filename ); 
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# emstrong_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::emstrong_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < emstrong_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'emstrong.png'\n" );
  fprintf ( command_unit, "set xlabel 'Log(dt)'\n" );
  fprintf ( command_unit, "set ylabel 'Log(Averaged Error at final T)'\n" );
  fprintf ( command_unit, "set logscale xy 10\n" );
  fprintf ( command_unit, "set title 'Euler-Maruyama Error as function of DT'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data linespoints\n" );
  fprintf ( command_unit, "plot 'emstrong_data.txt' using 1:2 title 'Error', \\\n" );
  fprintf ( command_unit, "     'emstrong_data.txt' using 1:3 title 'Slope = 1/2'\n" );
  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  EMSTRONG plot commands stored in \"%s\".\n", command_filename ); 

  return;
}
/******************************************************************************/

void emweak ( int *seed, int method, int m, int p_max, double dtvals[], 
  double xerr[] )

/******************************************************************************/
/*
  Purpose:

    EMWEAK tests the weak convergence of the Euler-Maruyama method.

  Discussion:

    The SDE is 

      dX = lambda * X dt + mu * X dW,   
      X(0) = Xzero,

    where 

      lambda = 2,
      mu = 1,
      Xzero = 1.

    The discretized Brownian path over [0,1] has dt = 2^(-9).

    The Euler-Maruyama method will use 5 different timesteps:

      2^(p-10),  p = 1,2,3,4,5.

    We examine weak convergence at T=1:

      | E (X_L) - E (X(T)) |.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2012

  Author:

    Original MATLAB version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546

  Parameters:

    Input, int *SEED, a seed for the random number generator.

    Input, int METHOD.
    0, use the standard Euler-Maruyama method;
    1, use the weak Euler-Maruyama method.

    Input, int M, the number of simulations to perform.
    A typical value is M = 1000.

    Input, int P_MAX, the number of time step sizes to use.
    A typical value is 5.

    Output, double DTVALS[P_MAX], the time steps used.

    Output, double XERR[P_MAX], the averaged absolute error in the
    solution estimate at the final time.
*/
{
  double *a;
  double dt;
  double e;
  int i;
  int j;
  int l;
  double lambda;
  double mu;
  int p;
  double resid;
  double *rhs;
  double *sol;
  double *winc;
  double *xem;
  double *xtemp;
  double xzero;
/*
  Problem parameters;
*/
  lambda = 2.0;
  mu = 0.1;
  xzero = 1.0;
/*
  Stepping parameters.
*/
  for ( p = 0; p < p_max; p++ )
  {
    dtvals[p] = pow ( 2.0, p - 9 );
  }
/*
  Take various Euler timesteps.
  For stepsize dt, we will need to take L Euler steps to reach time TMAX.
*/
  xtemp = ( double * ) malloc ( m * sizeof ( double ) );
  xem = ( double * ) malloc ( p_max * sizeof ( double ) );

  for ( p = 0; p < p_max; p++ )
  {
    l = i4_power ( 2, 9 - p );
    dt = dtvals[p];

    for ( i = 0; i < m; i++ )
    {
      xtemp[i] = xzero;
    }

    for ( j = 0; j < l; j++ )
    {
      winc = r8vec_normal_01_new ( m, seed );
      if ( method == 0 )
      {
        for ( i = 0; i < m; i++ )
        {
          winc[i] = sqrt ( dt ) * winc[i];
        }
      }
      else
      {
        for ( i = 0; i < m; i++ )
        {
          winc[i] = sqrt ( dt ) * r8_sign ( winc[i] );
        }
      }

      for ( i = 0; i < m; i++ )
      {
        xtemp[i] = xtemp[i] + dt * lambda * xtemp[i] 
          + mu * xtemp[i] * winc[i];
      }
      free ( winc );
    }
/*
  Average the M results for this stepsize.
*/
    xem[p] = r8vec_mean ( m, xtemp );
  }
  free ( xtemp );
/*
  Compute the error in the estimates for each stepsize.
*/
  for ( p = 0; p < p_max; p++ )
  { 
    xerr[p] = fabs ( xem[p] - exp ( lambda ) );
  }
  free ( xem );
/*
  Least squares fit of error = c * dt^q.
*/
  a = ( double * ) malloc ( p_max * 2 * sizeof ( double ) );
  rhs = ( double * ) malloc ( p_max * sizeof ( double ) );

  for ( i = 0; i < p_max; i++ )
  {
    a[i+0*p_max] = 1.0;
    a[i+1*p_max] = log ( dtvals[i] );
    rhs[i] = log ( xerr[i] );
  }
  sol = qr_solve ( p_max, 2, a, rhs );

  printf ( "\n" );
  printf ( "EMWEAK:\n" );
  if ( method == 0 )
  {
    printf ( "  Using standard Euler-Maruyama method.\n" );
  }
  else
  {
    printf ( "  Using weak Euler-Maruyama method.\n" );
  }
  printf ( "  Least squares solution to Error = c * dt ^ q\n" );
  printf ( "  (Expecting Q to be about 1.)\n" );
  printf ( "  Computed Q = %g\n", sol[1] );

  resid = 0.0;
  for ( i = 0; i < p_max; i++ )
  {
    e = a[i+0*p_max] * sol[0] + a[i+1*p_max] * sol[1] - rhs[i];
    resid = resid + e * e;
  }
  resid = sqrt ( resid );
  printf ( "  Residual is %g\n", resid );

  free ( a );
  free ( rhs );
  free ( sol );

  return;
}
/******************************************************************************/

void emweak_gnuplot ( int p_max, double dtvals[], double xerr[], int method )

/******************************************************************************/
/*
  Purpose:

    EMWEAK_GNUPLOT writes a GNUPLOT input file to plot EMWEAK data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int P_MAX, the number of time step sizes to use.

    Input, double DTVALS[P_MAX], the time steps used.

    Input, double XERR[P_MAX], the averaged absolute error in the
    solution estimate at the final time.

    Input, int METHOD.
    0, use the standard Euler-Maruyama method;
    1, use the weak Euler-Maruyama method.
*/
{
  char command_filename[81];
  FILE *command_unit;
  char data_filename[81];
  FILE *data_unit;
  int i;
/*
  Create data file.
*/
  if ( method == 0 )
  {
    strcpy ( data_filename, "emweak0_data.txt" );
  }
  else 
  {
    strcpy ( data_filename, "emweak1_data.txt" );
  }

  data_unit = fopen ( data_filename, "wt" );

  for ( i = 0; i < p_max; i++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g\n", dtvals[i], xerr[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  EMWEAK data stored in \"%s\".\n", data_filename ); 
/*
  Create the command file.
*/
  if ( method == 0 )
  {
    strcpy ( command_filename, "emweak0_commands.txt" );
  }
  else
  {
    strcpy ( command_filename, "emweak1_commands.txt" );
  }

  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "# created by sde::emweak_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  if ( method == 0 )
  {
    fprintf ( command_unit, "set output 'emweak0.png'\n" );
  }
  else
  {
    fprintf ( command_unit, "set output 'emweak1.png'\n" );
  }
  fprintf ( command_unit, "set xlabel 'Log(dt)'\n" );
  fprintf ( command_unit, "set ylabel 'Log(Averaged Error at final T)'\n" );
  fprintf ( command_unit, "set logscale xy 10\n" );
  if ( method == 0 )
  {
    fprintf ( command_unit, "set title 'Standard Euler-Maruyama Error as function of DT'\n" );
  }
  else
  {
    fprintf ( command_unit, "set title 'Weak Euler-Maruyama Error as function of DT'\n" );
  }
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data linespoints\n" );
  if ( method == 0 )
  {
    fprintf ( command_unit, "plot 'emweak0_data.txt' using 1:2 title 'Error', \\\n" );
    fprintf ( command_unit, "     'emweak0_data.txt' using 1:1 title 'Slope = 1'\n" );
  }
  else
  {
    fprintf ( command_unit, "plot 'emweak1_data.txt' using 1:2 title 'Error', \\\n" );
    fprintf ( command_unit, "     'emweak1_data.txt' using 1:1 title 'Slope = 1'\n" );
  }

  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  EMWEAK plot commands stored in \"%s\".\n", command_filename ); 

  return;
}
/******************************************************************************/

void filename_inc ( char *filename )

/******************************************************************************/
/*
  Purpose:

    FILENAME_INC increments a partially numeric file name.

  Discussion:

    It is assumed that the digits in the name, whether scattered or
    connected, represent a number that is to be increased by 1 on
    each call.  If this number is all 9's on input, the output number
    is all 0's.  Non-numeric letters of the name are unaffected.

    If the name is empty, then the routine stops.

    If the name contains no digits, the empty string is returned.

  Example:

      Input            Output
      -----            ------
      "a7to11.txt"     "a7to12.txt"  (typical case.  Last digit incremented)
      "a7to99.txt"     "a8to00.txt"  (last digit incremented, with carry.)
      "a9to99.txt"     "a0to00.txt"  (wrap around)
      "cat.txt"        " "           (no digits to increment)
      " "              STOP!         (error)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 November 2011

  Author:

    John Burkardt

  Parameters:

    Input/output, char *FILENAME, the filename to be incremented.
*/
{
  int change;
  int n;
  char *t;

  n = s_len_trim ( filename );

  if ( n <= 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "FILENAME_INC - Fatal error!\n" );
    fprintf ( stderr, "  The input string is empty.\n" );
    exit ( 1 );
  }

  change = 0;

  t = filename + n - 1;
  
  while ( 0 < n )
  {
    if ( '0' <= *t && *t <= '9' )
    {
      change = change + 1;

      if ( *t == '9' )
      {
        *t = '0';
      }
      else
      {
        *t = *t + 1;
        return;
      }
    }
    t--;
    n--;
  }
/*
  No digits were found.  Return blank.
*/
  if ( change == 0 )
  {
    n = s_len_trim ( filename );
    t = filename + n - 1;
    while ( 0 < n )
    {
      *t = ' ';
      t--;
      n--;
    }
  }

  return;
}
/******************************************************************************/

void milstrong ( int *seed, int p_max, double dtvals[], double xerr[] )

/******************************************************************************/
/*
  Purpose:

    MILSTRONG tests the strong convergence of the Milstein method.

  Discussion:

    This function solves the stochastic differential equation

      dX = sigma * X * ( k - X ) dt + beta * X dW,  
      X(0) = Xzero,

    where 

       sigma = 2, 
       k = 1, 
       beta = 1,
       Xzero = 0.5.

    The discretized Brownian path over [0,1] has dt = 2^(-11).

    The Milstein method uses timesteps 128*dt, 64*dt, 32*dt, 16*dt 
    (also dt for reference).

    We examine strong convergence at T=1:  

      E | X_L - X(T) |.

    The code is vectorized: all paths computed simultaneously.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 September 2012

  Author:

    Original MATLAB version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input/output, int *SEED, a seed for the random 
    number generator.

    Input, int P_MAX, the number of time step sizes to use.
    A typical value is 4.

    Output, double DTVALS[P_MAX], the time steps used.

    Output, double XERR[P_MAX], the averaged absolute error in the
    solution estimate at the final time.
*/
{
  double *a;
  double beta;
  double dt;
  double dtp;
  double *dw;
  double e;
  int i;
  int i2;
  int j;
  double k;
  int l;
  int m;
  int n;
  int p;
  int r;
  double resid;
  double *rhs;
  double sigma;
  double *sol;
  double tmax;
  double winc;
  double *xref;
  double *xtemp;
  double xzero;
/*
  Set problem parameters.
*/
  sigma = 2.0;
  k = 1.0;
  beta = 0.25;
  xzero = 0.5;
/*
  Set stepping parameters.
*/
  tmax = 1.0;
  n = i4_power ( 2, 11 );
  dt = tmax / ( double ) ( n );
/*
  Number of paths sampled.
*/
  m = 500;
/*
  Define the increments dW.
*/
  dw = r8mat_normal_01_new ( m, n, seed );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dw[i+j*m] = sqrt ( dt ) * dw[i+j*m];
    }
  }
/*
  Estimate the reference solution at time T M times.
*/
  xref = ( double * ) malloc ( m * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    xref[i] = xzero;
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      xref[i] = xref[i] 
        + dt * sigma * xref[i] * ( k - xref[i] ) 
        + beta * xref[i] * dw[i+j*m] 
        + 0.5 * beta * beta * xref[i] * ( dw[i+j*m] * dw[i+j*m] - dt );
    }
  }
/*
  Now compute M Milstein approximations at each of 4 timesteps,
  and record the average errors.
*/
  for ( p = 0; p < p_max; p++ )
  {
    dtvals[p] = dt * 8.0 * pow ( 2.0, p + 1 );
  }
  for ( p = 0; p < p_max; p++ )
  {
    xerr[p] = 0.0;
  }
  xtemp = ( double * ) malloc ( m * sizeof ( double ) );
  for ( p = 0; p < p_max; p++ )
  {
    r = 8 * i4_power ( 2, p + 1 );
    dtp = dtvals[p];
    l = n / r;
    for ( i = 0; i < m; i++ )
    {
      xtemp[i] = xzero;
    }
    for ( j = 0; j < l; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        winc = 0.0;
        for ( i2 = r * j; i2 < r * ( j + 1 ); i2++ )
        {
          winc = winc + dw[i+i2*m];
        }
        xtemp[i] = xtemp[i] 
          + dtp * sigma * xtemp[i] * ( k - xtemp[i] ) 
          + beta * xtemp[i] * winc
          + 0.5 * beta * beta * xtemp[i] * ( winc * winc - dtp );
      }
    }

    xerr[p] = 0.0;
    for ( i = 0; i < m; i++ )
    {
      xerr[p] = xerr[p] + fabs ( xtemp[i] - xref[i] );
    }
    xerr[p] = xerr[p] / ( double ) ( m );
  }
/*
  Least squares fit of error = C * dt^q
*/
  a = ( double * ) malloc ( p_max * 2 * sizeof ( double ) );
  rhs = ( double * ) malloc ( p_max * sizeof ( double ) );
  for ( p = 0; p < p_max; p++ )
  {
    a[p+0*p_max] = 1.0;
    a[p+1*p_max] = log ( dtvals[p] );
    rhs[p] = log ( xerr[p] );
  }
  sol = qr_solve ( p_max, 2, a, rhs );

  printf ( "\n" );
  printf ( "MILSTEIN:\n" );
  printf ( "  Least squares solution to Error = c * dt ^ q\n" );
  printf ( "  Expecting Q to be about 1.\n" );
  printf ( "  Computed Q = %g\n", sol[1] );

  resid = 0.0;
  for ( i = 0; i < p_max; i++ )
  {
    e = a[i+0*p_max] * sol[0] + a[i+1*p_max] * sol[1] - rhs[i];
    resid = resid + e * e;
  }
  resid = sqrt ( resid );
  printf ( "  Residual is %g\n", resid );

  free ( a );
  free ( dw );
  free ( rhs );
  free ( sol );
  free ( xref );
  free ( xtemp );

  return;
}
/******************************************************************************/

void milstrong_gnuplot ( int p_max, double dtvals[], double xerr[] )

/******************************************************************************/
/*
  Purpose:

    MILSTRONG_GNUPLOT writes a GNUPLOT input file to plot MILSTRONG data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 September 2012

  Author:

    John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int P_MAX, the number of time step sizes to use.

    Input, double DTVALS(P_MAX), the time steps used.

    Input, double XERR(P_MAX), the averaged absolute error in the
    solution estimate at the final time.
*/
{
  char command_filename[] = "milstrong_commands.txt";
  FILE *command_unit;
  char data_filename[] = "milstrong_data.txt";
  FILE *data_unit;
  int i;
/*
  Create data file.
*/
  data_unit = fopen ( data_filename, "wt" );

  for ( i = 0; i < p_max; i++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g\n", dtvals[i], xerr[i] );
  }
  fclose ( data_unit );

  printf ( "\n" );
  printf ( "  MILSTRONG data stored in \"%s\".\n", data_filename ); 
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# milstrong_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::milstrong_gnuplot.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < milstrong_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'milstrong.png'\n" );
  fprintf ( command_unit, "set xlabel 'Log(dt)'\n" );
  fprintf ( command_unit, "set ylabel 'Log(Averaged Error at final T)'\n" );
  fprintf ( command_unit, "set logscale xy 10\n" );
  fprintf ( command_unit, "set title 'Milstein Error as function of DT'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data linespoints\n" );
  fprintf ( command_unit, "plot 'milstrong_data.txt' using 1:2 title 'Error', \\\n" );
  fprintf ( command_unit, "     'milstrong_data.txt' using 1:1 title 'Slope = 1'\n" );
  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  MILSTRONG plot commands stored in \"%s\".\n", command_filename ); 

  return;
}
/******************************************************************************/

void stab_asymptotic ( int *seed, int n, int p_max )

/******************************************************************************/
/*
  Purpose:

    STAB_ASYMPTOTIC examines asymptotic stability.

  Discussion:

    The function tests the asymptotic stability
    of the Euler-Maruyama method applied to a stochastic differential
    equation (SDE).

    The SDE is

      dX = lambda*X dt + mu*X dW,
      X(0) = Xzero,

    where 

      lambda is a constant,
      mu is a constant,
      Xzero = 1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input/output, int *SEED, a seed for the random 
    number generator.

    Input, int N, the number of time steps for the
    first solution.

    Input, int P_MAX, the number of time step sizes.
*/
{
  char command_filename[] = "stab_asymptotic_commands.txt";
  FILE *command_unit;
  char data_filename[81];
  char data_filename0[] = "stab_asymptotic0_data.txt";
  FILE *data_unit;
  double dt;
  double *dtvals;
  int i;
  int j;
  double lambda;
  double mu;
  int nval;
  int p;
  double t;
  double test;
  double tmax;
  double *u;
  double winc;
  double *xemabs;
  double xmin;
  double xtemp;
  double xzero;

  printf ( "\n" );
  printf ( "STAB_ASYMPTOTIC:\n" );
  printf ( "  Investigate asymptotic stability of Euler-Maruyama\n" );
  printf ( "  solution with stepsize DT and MU.\n" );
  printf ( "\n" );
  printf ( "  SDE is asymptotically stable if\n" );
  printf ( "    Real ( lambda - 1/2 mu^2 ) < 0.\n" );
  printf ( "\n" );
  printf ( "  EM with DT is asymptotically stable if\n" );
  printf ( "    E log ( | 1 + lambda dt - sqrt(dt) mu n(0,1) | ) < 0.\n" );
  printf ( "  where n(0,1) is a normal random value.\n" );
/*
  Problem parameters.
*/
  lambda = 0.5;
  mu = sqrt ( 6.0 );
  xzero = 1.0;
/*
  Test the SDE.
*/
  printf ( "\n" );
  printf ( "  Lambda = %g\n", lambda );
  printf ( "  Mu =     %g\n", mu );
  test = lambda - 0.5 * mu * mu;
  printf ( "  SDE asymptotic stability test = %g\n", test );
/*
  Step parameters.
*/
  tmax = 500.0;
/*
  For each stepsize, compute the Euler-Maruyama solution.
*/
  strcpy ( data_filename, data_filename0 );
  dtvals = ( double * ) malloc ( p_max * sizeof ( double ) );

  for ( p = 0; p < p_max; p++ )
  {
    nval = n * i4_power ( 2, p );
    dt = tmax / ( double ) ( nval );
    dtvals[p] = dt;
/*
  Test the EM for this DT.
*/
    printf ( "\n" );
    printf ( "  dt = %g\n", dt );
    u = r8vec_normal_01_new ( 1000, seed );
    for ( i = 0; i < 1000; i++ )
    {
      u[i] = log ( fabs ( 1.0 + lambda * dt - sqrt ( dt ) * mu * u[i] ) );
    }
    test = r8vec_mean ( 1000, u );
    printf ( "  EM asymptotic test = %g\n", test );
    free ( u );

    xtemp = xzero;
    xemabs = ( double * ) malloc ( ( nval + 1 ) * sizeof ( double ) );
    xemabs[0] = xtemp;

    for ( j = 1; j <= nval; j++ )
    {
      winc = sqrt ( dt ) * r8_normal_01 ( seed );
      xtemp = xtemp + dt * lambda * xtemp + mu * xtemp * winc;
      xemabs[j] = fabs ( xtemp );
    }
/*
  Write this data to a file.
*/
    filename_inc ( data_filename );

    data_unit = fopen ( data_filename, "wt" );
/*
  We have to impose a tiny lower bound on the values because we
  will end up plotting their logs.
*/
    xmin = exp ( -200.0 );
    for ( i = 0; i <= nval; i++ )
    {
      t = tmax * ( double ) ( i ) / ( double ) ( nval );
      fprintf ( data_unit, "  %14.6g  %14.6g\n", t, r8_max ( xemabs[i], xmin ) );
    }
    fclose ( data_unit );

    printf ( "\n" );
    printf ( "  Data for DT = %g stored in '%s'\n", dt, data_filename );

    free ( xemabs );
  }
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# stab_asymptotic_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::stab_asymptotic.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < stab_asymptotic_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'stab_asymptotic.png'\n" );
  fprintf ( command_unit, "set xlabel 't'\n" );
  fprintf ( command_unit, "set ylabel '|X(t)|'\n" );
  fprintf ( command_unit, "set title 'Absolute value of EM Solution'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set logscale y 10\n" );
  fprintf ( command_unit, "set style data lines\n" );

  strcpy ( data_filename, data_filename0 );

  filename_inc ( data_filename );
  fprintf ( command_unit, "plot '%s' using 1:2, \\\n", data_filename );

  for ( p = 1; p < p_max - 1; p++ )
  {
    filename_inc ( data_filename );
    fprintf ( command_unit, "     '%s' using 1:2, \\\n", data_filename );
  }
  filename_inc ( data_filename );
  fprintf ( command_unit, "     '%s' using 1:2\n", data_filename );

  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  STAB_ASYMPTOTIC plot commands stored in \"%s\".\n", command_filename ); 

  free ( dtvals );

  return;
}
/******************************************************************************/

void stab_meansquare ( int *seed )

/******************************************************************************/
/*
  Purpose:

    STAB_MEANSQUARE examines mean-square stability.

  Discussion:

    The function tests the mean-square stability
    of the Euler-Maruyama method applied to a stochastic differential
    equation (SDE).

    The SDE is

      dX = lambda*X dt + mu*X dW,
      X(0) = Xzero,

    where 

      lambda is a constant,
      mu is a constant,
      Xzero = 1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 October 2006

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int *SEED, a seed for the random number generator.
    In the reference, this value is set to 100.
*/
{
  char command_filename[] = "stab_meansquare_commands.txt";
  FILE *command_unit;
  char data_filename0[] = "stab_meansquare0_data.txt";
  char data_filename[81];
  FILE *data_unit;
  double dt;
  int i;
  int j;
  int k;
  double lambda;
  int m;
  double mu;
  int n;
  double t;
  double test;
  double tmax;
  double *winc;
  double *xms;
  double *xtemp;
  double xzero;

  printf ( "\n" );
  printf ( "STAB_MEANSQUARE:\n" );
  printf ( "  Investigate mean square stability of Euler-Maruyama\n" );
  printf ( "  solution with stepsize DT and MU.\n" );
  printf ( "\n" );
  printf ( "  SDE is mean square stable if\n" );
  printf ( "    Real ( lambda + 1/2 |mu|^2 ) < 0.\n" );
  printf ( "\n" );
  printf ( "  EM with DT is mean square stable if\n" );
  printf ( "    |1+dt^2| + dt * |mu|^2 - 1.0 < 0.\n" );
/*
  Set problem parameters.
*/
  tmax = 20.0;
  m = 50000;
  xzero = 1.0 ;
/*
  Problem parameters.
*/
  lambda = -3.0;
  mu = sqrt ( 3.0 );
/*
  Test the SDE.
*/
  printf ( "\n" );
  printf ( "  Lambda = %g\n", lambda );
  printf ( "  Mu =     %g\n", mu );
  test = lambda + 0.5 * mu * mu;
  printf ( "  SDE mean square stability test = %g\n", test );
/*
  XMS is the mean square estimate of M paths.
*/
  strcpy ( data_filename, data_filename0 );

  for ( k = 0; k < 3; k++ )
  {
    dt = pow ( 2.0, - k );
    n = 20 * i4_power ( 2, k );
/*
  Test the EM for this DT.
*/
    printf ( "\n" );           
    printf ( "  dt = %g\n", dt );
    test = pow ( 1.0 + dt * lambda, 2 ) + dt * mu * mu - 1.0;
    printf ( "  EM mean square stability test = %g\n", test );

    xms = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
    xtemp = ( double * ) malloc ( m * sizeof ( double ) );
    for ( i = 0; i < m; i++ )
    {
      xtemp[i] = xzero;
    }
    xms[0] = xzero;

    for ( j = 0; j <= n; j++ )
    {
      winc = r8vec_normal_01_new ( m, seed );
      for ( i = 0; i < m; i++ )
      {
        winc[i] = sqrt ( dt ) * winc[i];
      }
      for ( i = 0; i < m; i++ )
      {
        xtemp[i] = xtemp[i] 
          + dt * lambda * xtemp[i] 
          + mu * xtemp[i] * winc[i];
      }
      xms[j] = 0.0;
      for ( i = 0; i < m; i++ )
      {
        xms[j] = xms[j] + xtemp[i] * xtemp[i];
      }
      xms[j] = xms[j] / ( double ) ( m );
      free ( winc );
    }
/*
  Write this data to a file.
*/
    filename_inc ( data_filename );

    data_unit = fopen ( data_filename, "wt" );

    for ( j = 0; j <= n; j++ )
    {
      t = tmax * ( double ) ( j ) / ( double ) ( n );
      fprintf ( data_unit, "  %14.6g  %14.6g\n", t, xms[j] );
    }
    fclose ( data_unit );

    printf ( "\n" );
    printf ( "  Data for DT = %g stored in '%s'.\n", dt, data_filename );

    free ( xtemp );
    free ( xms );
  }
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# stab_meansquare_commands.txt\n" );
  fprintf ( command_unit, "# created by sde::stab_meansquare.\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < stab_meansquare_commands.txt\n" );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'stab_meansquare.png'\n" );
  fprintf ( command_unit, "set xlabel 't'\n" );
  fprintf ( command_unit, "set ylabel 'E|X^2(t)|'\n" );
  fprintf ( command_unit, "set title 'Mean Square of EM Solution'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set logscale y 10\n" );
  fprintf ( command_unit, "set style data lines\n" );

  strcpy ( data_filename, data_filename0 );

  filename_inc ( data_filename );
  fprintf ( command_unit, "plot '%s' using 1:2, \\\n", data_filename );

  for ( k = 1; k <= 1; k++ )
  {
    filename_inc ( data_filename );
    fprintf ( command_unit, "     '%s' using 1:2, \\\n", data_filename );
  }
  filename_inc ( data_filename );
  fprintf ( command_unit, "     '%s' using 1:2\n", data_filename );

  fprintf ( command_unit, "quit\n" );

  fclose ( command_unit );

  printf ( "  STAB_MEANSQUARE plot commands stored in \"%s\".\n", 
    command_filename ); 

  return;
}
/******************************************************************************/

void stochastic_integral_ito ( int n, int *seed, double *estimate, 
  double *exact, double *error )

/******************************************************************************/
/*
  Purpose:

    STOCHASTIC_INTEGRAL_ITO approximates the Ito integral of W(t) dW.

  Discussion:

    This function estimates the Ito integral of W(t) dW over 
    the interval [0,1].

    The estimates is made by taking N steps.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int N, the number of steps to take.

    Input, int *SEED, a seed for the random number generator.

    Output, double *ESTIMATE, the estimate of the integral.

    Output, double *EXACT, the exact value of the integral.

    Output, double *ERROR, the error in the integral estimate.
*/
{
  double dt;
  double *dw;
  int j;
  double tmax;
  double *w;
/*
  Set step parameters.
*/
  tmax = 1.0;
  dt = tmax / ( double ) ( n );
/*
  Define the increments dW.
*/
  dw = r8vec_normal_01_new ( n, seed );
  for ( j = 0; j < n; j++ )
  {
    dw[j] = sqrt ( dt ) * dw[j];
  }
/*
  Sum the increments to get the Brownian path.
*/
  w = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  w[0] = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    w[j] = w[j-1] + dw[j-1];
  }
/*
  Approximate the Ito integral.
*/
  *estimate = r8vec_dot_product ( n, w, dw );
/*
  Compare with the exact solution.
*/
  *exact = 0.5 * ( w[n] * w[n] - tmax );
  *error = fabs ( *estimate - *exact );

  free ( dw );
  free ( w );

  return;
}
/******************************************************************************/

void stochastic_integral_strat ( int n, int *seed, double *estimate, 
  double *exact, double *error )

/******************************************************************************/
/*
  Purpose:

    STOCHASTIC_INTEGRAL_STRAT approximates the Stratonovich integral of W(t) dW.

  Discussion:

    This function estimates the Stratonovich integral of W(t) dW over 
    the interval [0,1].

    The estimates is made by taking N steps.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2012

  Author:

    Original Matlab version by Desmond Higham.
    C version by John Burkardt.

  Reference:

    Desmond Higham,
    An Algorithmic Introduction to Numerical Simulation of
    Stochastic Differential Equations,
    SIAM Review,
    Volume 43, Number 3, September 2001, pages 525-546.

  Parameters:

    Input, int N, the number of steps to take.

    Input, int *SEED, a seed for the random number generator.

    Output, double *ESTIMATE, the estimate of the integral.

    Output, double *EXACT, the exact value of the integral.

    Output, double *ERROR, the error in the integral estimate.
*/
{
  double dt;
  double *dw;
  int j;
  double tmax;
  double *u;
  double *v;
  double *w;
/*
  Set step parameters.
*/
  tmax = 1.0;
  dt = tmax / ( double ) ( n );
/*
  Define the increments dW.
*/
  dw = r8vec_normal_01_new ( n, seed );

  for ( j = 0; j < n; j++ )
  {
    dw[j] = sqrt ( dt ) * dw[j];
  }
/*
  Sum the increments to get the Brownian path.
*/
  w = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  w[0] = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    w[j] = w[j-1] + dw[j-1];
  }
/*
  Approximate the Stratonovich integral.
*/
  u = r8vec_normal_01_new ( n, seed );

  v = ( double * ) malloc ( n * sizeof ( double ) );
  for ( j = 0; j < n; j++ )
  {
    v[j] = 0.5 * ( w[j] + w[j+1] ) + 0.5 * sqrt ( dt ) * u[j];
  }

  *estimate = r8vec_dot_product ( n, v, dw );
/*
  Compare with the exact solution.
*/
  *exact = 0.5 * w[n-1] * w[n-1];
  *error = fabs ( *estimate - *exact );

  free ( dw );
  free ( u );
  free ( v );
  free ( w );

  return;
}

