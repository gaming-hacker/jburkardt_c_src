# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

int main ( );
int i4_min ( int i1, int i2 );
double *r8vec_even ( int n, double alo, double ahi );
void report ( int step, int step_num, int n, double x[], double t, double u[] );
void timestamp ( );
double u_a ( double x, double t );
double u_b ( double x, double t );
void u_init ( int n, double x[], double t, double u[] );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    FD1D_BURGERS_LEAP solves the nonviscous Burgers equation using leapfrogging.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2010

  Author:

    John Burkardt

  Parameters:

    None
*/
{
  double a;
  double b;
  double dt;
  double dx;
  int i;
  int ihi;
  int ilo;
  int n;
  int step;
  int step_num;
  double t;
  double t_init;
  double t_last;
  double *uc;
  double *un;
  double *uo;
  double *x;

  timestamp ( );

  printf ( "\n" );
  printf ( "FD1D_BURGERS_LEAP:\n" );
  printf ( "  C version\n" );
  printf ( "  Solve the non-viscous time-dependent Burgers equation,\n" );
  printf ( "  using the leap-frog method.\n" );
  printf ( "\n" );
  printf ( "  Equation to be solved:\n" );
  printf ( "\n" );
  printf ( "    du/dt + u * du/dx = 0\n" );
  printf ( "\n" );
  printf ( "  for x in [ a, b ], for t in [t_init, t_last]\n" );
  printf ( "\n" );
  printf ( "  with initial conditions:\n" );
  printf ( "\n" );
  printf ( "    u(x,o) = u_init\n" );
  printf ( "\n" );
  printf ( "  and boundary conditions:\n" );
  printf ( "\n" );
  printf ( "    u(a,t) = u_a(t), u(b,t) = u_b(t)\n" );
/*
  Set and report the problem parameters.
*/
  n = 21;
  a = -1.0;
  b = +1.0;
  dx = ( b - a ) / ( double ) ( n - 1 );
  step_num = 30;
  t_init = 0.0;
  t_last = 3.0;
  dt = ( t_last - t_init ) / ( double ) ( step_num );

  printf ( "\n" );
  printf ( "  %f <= X <= %f\n", a, b );
  printf ( "  Number of nodes = %d\n", n );
  printf ( "  DX = %f\n", dx );
  printf ( "\n" );
  printf ( "  %f <= T <= %f\n", t_init, t_last );
  printf ( "  Number of time steps = %d\n", step_num );
  printf ( "  DT = %f\n", dt );

  uc = ( double * ) malloc ( n * sizeof ( double ) );
  un = ( double * ) malloc ( n * sizeof ( double ) );
  uo = ( double * ) malloc ( n * sizeof ( double ) );

  x = r8vec_even ( n, a, b );

  printf ( "\n" );
  printf ( "  X:\n" );
  printf ( "\n" );
  for ( ilo = 0; ilo < n; ilo = ilo + 5 )
  {
    ihi = i4_min ( ilo + 5, n - 1 );
    for ( i = ilo; i <= ihi; i++ )
    {
      printf ( "  %14f", x[i] );
    }
    printf ( "\n" );
  }
/*
  Set the initial condition,
  and apply boundary conditions to first and last entries.
*/
  step = 0;
  t = t_init;
  u_init ( n, x, t, un );
  un[0] = u_a ( x[0], t );
  un[n-1] = u_b ( x[n-1], t );

  report ( step, step_num, n, x, t, un );
/*
  Use Euler's method to get the first step.
*/
  step = 1;
  t = ( ( double ) ( step_num - step ) * t_init   
      + ( double ) (            step ) * t_last ) 
      / ( double ) ( step_num        );

  for ( i = 0; i < n; i++ )
  {
    uc[i] = un[i];
  }

  for ( i = 1; i < n - 1; i++ )
  {
    un[i] = uc[i] - dt * uc[i] * ( uc[i+1] - uc[i-1] ) / 2.0 / dx;
  }
  un[0] = u_a ( x[0], t );
  un[n-1] = u_b ( x[n-1], t );

  report ( step, step_num, n, x, t, un );
/*
  Subsequent steps use the leapfrog method.
*/
  for ( step = 2; step <= step_num; step++ )
  {
    t = ( ( double ) ( step_num - step ) * t_init   
        + ( double ) (            step ) * t_last ) 
        / ( double ) ( step_num        );

    for ( i = 0; i < n; i++ )
    {
      uo[i] = uc[i];
      uc[i] = un[i];
    }

    for ( i = 1; i < n - 1; i++ )
    {
      un[i] = uo[i] - dt * uc[i] * ( uc[i+1] - uc[i-1] ) / dx;
    }

    un[0] = u_a ( x[0], t );
    un[n-1] = u_b ( x[n-1], t );

    report ( step, step_num, n, x, t, un );
  }

  free ( uc );
  free ( un );
  free ( uo );
  free ( x );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "FD1D_BURGERS_LEAP:\n" );
  printf ( "  Normal end of execution.\n" );

  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the minimum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2010

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

double *r8vec_even ( int n, double alo, double ahi )

/******************************************************************************/
/*
  Purpose:

    R8VEC_EVEN returns an R8VEC of values evenly spaced between ALO and AHI.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of values.

    Input, double ALO, AHI, the low and high values.

    Output, double R8VEC_EVEN[N], N evenly spaced values.
    Normally, A[0] = ALO and A[N-1] = AHI.
    However, if N = 1, then A[0] = 0.5*(ALO+AHI).
*/
{
  double *a;
  int i;

  a = ( double * ) malloc ( n * sizeof ( double ) );

  if ( n == 1 )
  {
    a[0] = 0.5 * ( alo + ahi );
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      a[i] = ( ( double ) ( n - i - 1 ) * alo 
             + ( double ) (     i     ) * ahi ) 
             / ( double ) ( n     - 1 );
    }
  }

  return a;
}
/******************************************************************************/

void report ( int step, int step_num, int n, double x[], double t, double u[] )

/******************************************************************************/
/*
  Purpose:

    REPORT prints or plots or saves the data at the current time step.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, int STEP, the index of the current step,
    between 0 and STEP_NUM.

    Input, int STEP_NUM, the number of steps to take.

    Input, int N, the number of nodes.

    Input, double X[N], the coordinates of the nodes.

    Input, double T, the current time.

    Input, double U[N], the initial values U(X,T).
*/
{
  int i;
  int ihi;
  int ilo;

  printf ( "\n" );
  printf ( "  STEP = %d\n", step );
  printf ( "  TIME = %f\n", t );
  printf ( "\n" );
  for ( ilo = 0; ilo < n; ilo = ilo + 5 )
  {
    ihi = i4_min ( ilo + 4, n - 1 );
    for ( i = ilo; i <= ihi; i++ )
    {
      printf ( "  %14f", u[i] );
    }
    printf ( "\n" );
  }

  return;
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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
/******************************************************************************/

double u_a ( double x, double t )

/******************************************************************************/
/*
  Purpose:

    U_A sets the boundary condition for U at A.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, double X, T, the position and time.

    Output, double U_A, the prescribed value of U(X,T).
*/
{
  double ua;

  ua = + 0.5;

  return ua;
}
/******************************************************************************/

double u_b ( double x, double t )

/******************************************************************************/
/*
  Purpose:

    U_B sets the boundary condition for U at B.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, double X, T, the position and time.

    Output, double U_B, the prescribed value of U(X,T).
*/
{
  double ub;

  ub = - 0.5;

  return ub;
}
/******************************************************************************/

void u_init ( int n, double x[], double t, double u[] )

/******************************************************************************/
/*
  Purpose:

    U_INIT sets the initial condition for U.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of nodes.

    Input, double X[N], the coordinates of the nodes.

    Input, double T, the current time.

    Output, double U[N], the initial values U(X,T).
*/
{
  int i;
  double pi = 3.141592653589793;
  double q;
  double r;
  double s;
  double ua;
  double ub;

  ua = u_a ( x[0], t );
  ub = u_b ( x[n-1], t );

  q = 2.0 * ( ua - ub ) / pi;
  r = ( ua + ub ) / 2.0;
/*
  S can be varied.  It is the slope of the initial condition at the midpoint.
*/
  s = 1.0;

  for ( i = 0; i < n; i++ )
  {
    u[i] = - q * atan ( s * ( 2.0 * x[i] - x[0] - x[n-1] ) 
      / ( x[n-1] - x[0] ) ) + r;
  }

  return;
}

