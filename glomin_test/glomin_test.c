# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "glomin.h"

int main ( );
void test_glomin_all ( );
void glomin_example ( double a, double b, double c, double m,  double e, 
  double t, double f ( double x ), char *title );
double h_01 ( double x );
double h_02 ( double x );
double h_03 ( double x );
double h_04 ( double x );
double h_05 ( double x );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    glomin_test() tests glomin().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2021

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double e;
  double m;
  double t;

  timestamp ( );
  printf ( "\n" );
  printf ( "glomin_test():\n" );
  printf ( "  GCC version %d.%d.%d\n", 
    __GNUC__, __GNUC_MINOR__,__GNUC_PATCHLEVEL__ );
  printf ( "  glomin() seeks a global minimizer of a function F(X)\n" );
  printf ( "  in an interval [A,B], given some upper bound M \n" );
  printf ( "  for the second derivative of F.\n" );

  e = sqrt ( DBL_EPSILON );
  t = sqrt ( DBL_EPSILON );

  printf ( "\n" );
  printf ( "  Tolerances:\n" );
  printf ( "  e = %g\n", e );
  printf ( "  t = %g\n", t );

  a = 7.0;
  b = 9.0;
  c = ( a + b ) / 2.0;
  m = 0.0;
  glomin_example ( a, b, c, m, e, t, h_01, 
    "h_01(x) = 2 - x" );

  a = 7.0;
  b = 9.0;
  c = ( a + b ) / 2.0;
  m = 100.0;
  glomin_example ( a, b, c, m, e, t, h_01, 
    "h_01(x) = 2 - x" );

  a = -1.0;
  b = +2.0;
  c = ( a + b ) / 2.0;
  m = 2.0;
  glomin_example ( a, b, c, m, e, t, h_02, 
    "h_02(x) = x * x" );

  a = -1.0;
  b = +2.0;
  c = ( a + b ) / 2.0;
  m = 2.1;
  glomin_example ( a, b, c, m, e, t, h_02, 
    "h_02(x) = x * x" );

  a = -0.5;
  b =  +2.0;
  c = ( a + b ) / 2.0;
  m = 14.0;
  glomin_example ( a, b, c, m, e, t, h_03, 
    "h_03(x) = x^3 + x^2" );

  a = -0.5;
  b =  +2.0;
  c = ( a + b ) / 2.0;
  m = 28.0;
  glomin_example ( a, b, c, m, e, t, h_03, 
    "h_03(x) = x^3 + x^2" );

  a = -10.0;
  b = +10.0;
  c = ( a + b ) / 2.0;
  m = 72.0;
  glomin_example ( a, b, c, m, e, t, h_04, 
    "h_04(x) = ( x + sin(x) ) * exp(-x*x)" );

  a = -10.0;
  b = +10.0;
  c = ( a + b ) / 2.0;
  m = 72.0;
  glomin_example ( a, b, c, m, e, t, h_05, 
    "h_05(x) = ( x - sin(x) ) * exp(-x*x)" );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "glomin_test():\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void glomin_example ( double a, double b, double c, double m, double e, 
  double t, double f ( double x ), char *title )

/******************************************************************************/
/*
  Purpose:

    glomin_example() tests glomin() on one test function.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

  Author:

    John Burkardt

  Input:

    double A, B, the endpoints of the interval.

    double C, an initial guess for the global
    minimizer.  If no good guess is known, C = A or B is acceptable.

    double M, the bound on the second derivative.

    double E, a positive tolerance, a bound for the
    absolute error in the evaluation of F(X) for any X in [A,B].

    double T, a positive absolute error tolerance.

    double F ( double x ), the name of a user-supplied
    function whose global minimum is being sought.

    char *TITLE, a title for the problem.
*/
{
  int calls;
  double fa;
  double fb;
  double fx;
  double x;

  fx = glomin ( a, b, c, m, e, t, f, &x, &calls );
  fa = f ( a );
  fb = f ( b );

  printf ( "\n" );
  printf ( "  %s\n", title );
  printf ( "  m = %g\n", m );
  printf ( "\n" );
  printf ( "      A                 X             B\n" );
  printf ( "    F(A)              F(X)          F(B)\n" );
  printf ( "\n" );
  printf ( "  %14f  %14f  %14f\n",  a,  x,  b );
  printf ( "  %14e  %14e  %14e\n", fa, fx, fb );
  printf ( "  Number of calls to F = %d\n", calls );

  return;
}
/******************************************************************************/

double h_01 ( double x )

/******************************************************************************/
/*
  Purpose:

    h_01() evaluates 2 - x.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double H_01, the value of the function at X.
*/
{
  double value;

  value = 2.0 - x;

  return value;
}
/******************************************************************************/

double h_02 ( double x )

/******************************************************************************/
/*
  Purpose:

    h_02() evaluates x^2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double H_02, the value of the function at X.
*/
{
  double value;

  value = x * x;

  return value;
}
/******************************************************************************/

double h_03 ( double x )

/******************************************************************************/
/*
  Purpose:

    h_03() evaluates x^3+x^2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double H_03, the value of the function at X.
*/
{
  double value;

  value = x * x * ( x + 1.0 );

  return value;
}
/******************************************************************************/

double h_04 ( double x )

/******************************************************************************/
/*
  Purpose:

    h_04() evaluates ( x + sin ( x ) ) * exp ( - x * x ).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double H_04, the value of the function at X.
*/
{
  double value;

  value = ( x + sin ( x ) ) * exp ( - x * x );

  return value;
}
/******************************************************************************/

double h_05 ( double x )

/******************************************************************************/
/*
  Purpose:

    h_05() evaluates ( x - sin ( x ) ) * exp ( - x * x ).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double H_05, the value of the function at X.
*/
{
  double value;

  value = ( x - sin ( x ) ) * exp ( - x * x );

  return value;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    timestamp() prints the current YMDHMS date as a time stamp.

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
 
