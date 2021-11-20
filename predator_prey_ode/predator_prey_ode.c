# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "predator_prey_ode.h"

/******************************************************************************/

double *predator_prey_conserved ( int n, double rf[] )

/******************************************************************************/
/*
  Purpose:

    predator_prey_conserved evaluates a conserved quantity.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 April 2020

  Author:

    John Burkardt

  Reference:

    George Lindfield, John Penny,
    Numerical Methods Using MATLAB,
    Second Edition,
    Prentice Hall, 1999,
    ISBN: 0-13-012641-1,
    LC: QA297.P45.

  Input:

    int N: the number of sets of variables.

    double RF[N*2]: the current solution variables, rabbits and foxes.

  Output:

    double PREDATOR_PREY_CONSERVED[N]: the value of the conserved quantity.
*/
{
  double alpha;
  double beta;
  double delta;
  double gamma;
  double *h;
  int i;

  predator_prey_parameters ( &alpha, &beta, &gamma, &delta );

  h = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    h[i] = delta * rf[0+i*2] - gamma * log ( rf[0+i*2] ) 
         + beta  * rf[1+i*2] - alpha * log ( rf[1+i*2] );
  }

  return h;
}
/******************************************************************************/

double *predator_prey_deriv ( double t, double rf[] )

/******************************************************************************/
/*
  Purpose:

    predator_prey_deriv evaluates the right hand side of the system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 October 2020

  Author:

    John Burkardt

  Input:

    double T: the current time.

    double RF[2]: the current solution variables, rabbits and foxes.

  Output:

    double PREDATOR_PREY_DERIV[2]: the right hand side of the 2 ODE's.
*/
{
  double alpha;
  double beta;
  double delta;
  double *drfdt;
  double gamma;

  predator_prey_parameters ( &alpha, &beta, &gamma, &delta );

  drfdt = ( double * ) malloc ( 2 * sizeof ( double ) );

  drfdt[0] =   alpha * rf[0] - beta  * rf[0] * rf[1];
  drfdt[1] = - gamma * rf[1] + delta * rf[0] * rf[1];

  return drfdt;
}
/******************************************************************************/

void predator_prey_parameters ( double *alpha, double *beta, double *gamma,
  double *delta )

/******************************************************************************/
/*
  Purpose:

    predator_prey_parameters returns the problem parameters.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 October 2020

  Author:

    John Burkardt

  Output:

    double *ALPHA, *BETA, *GAMMA, *DELTA, the coefficient values.
*/
{
  *alpha = 2.0;
  *beta = 0.001;
  *gamma = 10.0;
  *delta = 0.002;

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
