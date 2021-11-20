# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "toms178.h"

int main ( );
void toms178_test01 ( );
double rosenbrock ( double x[2], int n );
void toms178_test02 ( double rho );
double woods ( double x[2], int n );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for toms178_test.

  Discussion:

    toms178_test tests toms178.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2019

  Author:

    John Burkardt
*/
{
  double rho;

  timestamp ( );
  printf ( "\n" );
  printf ( "toms178\n" );
  printf ( "  C version\n" );
  printf ( "  Test toms178.\n" );

  toms178_test01 ( );

  rho = 0.5;
  toms178_test02 ( rho );

  rho = 0.6;
  toms178_test02 ( rho );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "toms178_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void toms178_test01 ( )

/******************************************************************************/
/*
  Purpose:

    toms178_test01 uses the Rosenbrock function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2019

  Author:

    John Burkardt
*/
{
  double endpt[2];
  double epsilon;
  int it;
  int itermax;
  int nvars = 2;
  double rho;
  double startpt[2];
  double value;

  printf ( "\n" );
  printf ( "toms178_test01\n" );
  printf ( "  hooke seeks a minimizer of F(X).\n" );
  printf ( "  Here we use the Rosenbrock function.\n" );
/*
  Starting guess.
*/
  startpt[0] = -1.2;
  startpt[1] = 1.0;

  printf ( "\n" );
  printf ( "  Initial estimate X0: ( %g, %g )\n", startpt[0], startpt[1] );
  value = rosenbrock ( startpt, nvars );
  printf ( "  F(X0) = %g\n", value );

  itermax = 5000;
  rho = 0.5;
  epsilon = 1.0E-06;

  it = hooke ( nvars, startpt, endpt, rho, epsilon, itermax, rosenbrock );

  printf ( "\n" );
  printf ( "  Number of iterations: %d\n", it );
  printf ( "  Solution estimate X*: ( %g, %g )\n", endpt[0], endpt[1] );
  value = rosenbrock ( endpt, nvars );
  printf ( "  F(X*) = %g\n", value );

  return;
}
/******************************************************************************/

double rosenbrock ( double x[2], int n )

/******************************************************************************/
/*
  Purpose:

    rosenbrock evaluates the Rosenbrock function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2019

  Author:

    John Burkardt

  Input:

    double x[2], the independent variables.

    int n, the number of independent variables.

  Output:

    double rosenbrock, the value of the function.
*/
{
  double a;
  double b; 
  double c;
  double value;

  a = x[0];
  b = x[1];
  c = 100.0 * (b - (a * a)) * (b - (a * a));
  value = (c + ((1.0 - a) * (1.0 - a)));

  return value;
}
/******************************************************************************/

void toms178_test02 ( double rho )

/******************************************************************************/
/*
  Purpose:

    toms178_test02 uses the Woods function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2019

  Author:

    John Burkardt

  Input:

    double rho: a solution parameter.  For this problem, rho = 0.5 produces
    good results, while rho = 0.6 does not.
*/
{
  double endpt[4];
  double epsilon;
  int it;
  int itermax;
  int nvars = 4;
  double startpt[4];
  double value;

  printf ( "\n" );
  printf ( "toms178_test02\n" );
  printf ( "  hooke seeks a minimizer of F(X).\n" );
  printf ( "  Here we use the Woods function.\n" );
  printf ( "  The value of rho = %g\n", rho );
/*
  Starting guess.
*/
  startpt[0] = -3.0;
  startpt[1] = -1.0;
  startpt[0] = -3.0;
  startpt[1] = -1.0;

  printf ( "\n" );
  printf ( "  Initial estimate X0: ( %g, %g, %g, %g )\n", 
    startpt[0], startpt[1], startpt[2], startpt[3] );
  value = woods ( startpt, nvars );
  printf ( "  F(X0) = %g\n", value );

  itermax = 5000;
  epsilon = 1.0E-06;

  it = hooke ( nvars, startpt, endpt, rho, epsilon, itermax, woods );

  printf ( "\n" );
  printf ( "  Number of iterations: %d\n", it );
  printf ( "  Solution estimate X*: ( %g, %g,%g, %g )\n", 
    endpt[0], endpt[1], endpt[2], endpt[3] );
  value = woods ( endpt, nvars );
  printf ( "  F(X*) = %g\n", value );

  endpt[0] = 1.0;
  endpt[1] = 1.0;
  endpt[2] = 1.0;
  endpt[3] = 1.0;
  printf ( "\n" );
  printf ( "  Exact solution X*: ( %g, %g )\n", endpt[0], endpt[1] );
  value = woods ( endpt, nvars );
  printf ( "  F(X*) = %g\n", value );

  return;
}
/******************************************************************************/

double woods ( double x[2], int n )

/******************************************************************************/
/*
  Purpose:

    woods evaluates the Woods function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2019

  Author:

    John Burkardt

  Input:

    double x[2], the independent variables.

    int n, the number of independent variables.

  Output:

    double woods, the value of the function.
*/
{
  double s1;
  double s2;
  double s3;
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double value;

	s1 = x[1] - x[0]*x[0];
	s2 = 1 - x[0];
	s3 = x[1] - 1;
	t1 = x[3] - x[2]*x[2];
	t2 = 1 - x[2];
	t3 = x[3] - 1;
	t4 = s3 + t3;
	t5 = s3 - t3;
  value = 100*(s1*s1) + s2*s2 + 90*(t1*t1) + t2*t2
		+ 10*(t4*t4) + t5*t5/10.;

  return value;
}
