# include <stdio.h>
# include <time.h>

# include <gsl/gsl_errno.h>
# include <gsl/gsl_matrix.h>
# include <gsl/gsl_odeiv2.h>

int main ( );
int func ( double t, const double y[], double f[], void *params );
int jac ( double t, const double y[], double *dfdy, double dfdt[], 
  void *params );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    midpoint_gl_test() demonsrates the GSL midpoint ODE solver.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 May 2021

  Author:

    Taken from the GSL reference manual.
    Modifications by John Burkardt.
*/
{
  double dt;
  FILE *data;
  char *data_filename = "midpoint_gsl_data.txt";
  double epsabs = 1e-6;
  double epsrel = 0.0;
  double h_start = 1e-6;
  int i;
  double mu = 10.0;
  int n = 100;
  double t = 0.0;
  double t0 = 0.0;
  double tstop = 100.0;
  double y[2] = { 1.0, 0.0 };
/*
  Define "sys", the definition of the ODE data.
*/
  gsl_odeiv2_system sys = { func, jac, 2, &mu };
/*
  Define "d", a pointer to the ODE driver to be used.
  Here, "gsl_odeiv2_step_rk2imp" specifies we want to use the GSL midpoint driver.
*/
  gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new ( 
    &sys, gsl_odeiv2_step_rk2imp, h_start, epsabs, epsrel );

  timestamp ( );
  printf ( "\n" );
  printf ( "midpoint_gsl_test:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the GSL implicit midpoint method ODE solver.\n" );

  printf ( "\n" );
  printf ( "  Parameter values:\n" );
  printf ( "    mu    = %g\n", mu );
  printf ( "    t0    = %g\n", t0 );
  printf ( "    y0    = (%g,%g)\n", y[0], y[1] );
  printf ( "    tstop = %g\n", tstop );
  printf ( "    n     = %d\n", n );

  data = fopen ( data_filename, "wt" );
  fprintf ( data, "  %g  %g  %g\n", t0, y[0], y[1] );

  dt = ( tstop - t0 ) / n;

  for ( i = 1; i <= n; i++ )
  {
    double ti = i * dt;
    int status = gsl_odeiv2_driver_apply ( d, &t, ti, y );
    if ( status != GSL_SUCCESS )
    {
      printf ( "error, return value = %d\n", status );
      break;
    }
    printf ("%.5e %.5e %.5e\n", t, y[0], y[1]);
    fprintf ( data, "  %g  %g  %g\n", t, y[0], y[1] );
  }

  fclose ( data );
  printf ( "\n" );
  printf ( "  Solution data stored in '%s'.\n", data_filename );
/*
  Free memory.
*/
  gsl_odeiv2_driver_free ( d );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "midpoint_gsl_test():\n" );
  printf ( "  Normal end of execution.\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

int func ( double t, const double y[], double f[], void *params )

/******************************************************************************/
/*
  Purpose:

    func() evaluates the right hand side of the ODE.

  Discussion:

    This function defines the right hand side of the van der Pol equation:

      u'' + mu u' (u^2-1) + u = 0

    rewritten in first order form as:

      u' = v
      v' = - u + mu v ( 1 - u^2)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 May 2021

  Author:

    Taken from the GSL reference manual.
    Modifications by John Burkardt.

  Input:

    double T: the current time.

    const double Y[]: the current solution value.

    void *PARAMS: user-specified parameters.

  Output:

    int FUNC: returns GSL_SUCCESS indicating a successful computation.

    double F[]: the right hand side of the ODE at T, Y.
*/
{
/*
  Declare t to avoid unused parameter warning.
*/
  (void) (t);
  double mu = *(double *) params;

  f[0] = y[1];
  f[1] = - y[0] - mu * y[1] * ( y[0] * y[0] - 1.0 );

  return GSL_SUCCESS;
}
/******************************************************************************/

int jac ( double t, const double y[], double *dfdy, double dfdt[], 
  void *params )

/******************************************************************************/
/*
  Purpose:

    jac() evaluates the jacobian of the ODE.

  Discussion:

    This function defines the jacobian of the van der Pol equation:

      f(u,v) = ( v              )
               ( -u+mu*v*(1-u^2 )

      df     = ( 0 )
      dt       ( 0 )

      df     = (   0          1          )
      dy       ( -1-2*mu*v*u  mu*(1-u^2) )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 May 2021

  Author:

    Taken from the GSL reference manual.
    Modifications by John Burkardt.

  Input:

    double T: the current time.

    const double Y[]: the current solution value.

    void *PARAMS: user-specified parameters.

  Output:

    int JAC: returns GSL_SUCCESS indicating a successful computation.

    double *DFDY[]: the Jacobian matrix.

    double DFDT[]: the time derivative of F.
*/
{
/*
  Declare t to avoid unused parameter warning.
*/
  (void) (t);
  double mu = *(double *) params;
/*
  Allocate a 2x2 matrix for dfdy.
*/
  gsl_matrix_view dfdy_mat = gsl_matrix_view_array ( dfdy, 2, 2 );
/*
  Let "m" be a pointer to this matrix.
*/
  gsl_matrix * m = &dfdy_mat.matrix;
/*
  Set dFdY
*/
  gsl_matrix_set ( m, 0, 0, 0.0 );
  gsl_matrix_set ( m, 0, 1, 1.0 );
  gsl_matrix_set ( m, 1, 0, -2.0*mu*y[0]*y[1] - 1.0 );
  gsl_matrix_set ( m, 1, 1, -mu*(y[0]*y[0] - 1.0) );
/*
  Set dFdT
*/
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;

  return GSL_SUCCESS;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    timestamp() prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 May 2021

  Author:

    John Burkardt
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

