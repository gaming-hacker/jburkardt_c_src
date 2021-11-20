# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "zero.h"

int main ( );
void zero_example ( double a, double b, double f ( double x ), char *title );
double f_01 ( double x );
double f_02 ( double x );
double f_03 ( double x );
double f_04 ( double x );
double f_05 ( double x );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    zero_test() tests zero().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 May 2021

  Author:

    John Burkardt
*/
{
  double a;
  double b;

  timestamp ( );
  printf ( "\n" );
  printf ( "zero_test():\n" );
  printf ( "  C version\n" );
  printf ( "  zero() seeks a root of a function F(X)\n" );
  printf ( "  in an interval [A,B].\n" );

  a = 1.0;
  b = 2.0;
  zero_example ( a, b, f_01, "f_01(x) = sin ( x ) - x / 2" );

  a = 0.0;
  b = 1.0;
  zero_example ( a, b, f_02, "f_02(x) = 2 * x - exp ( - x )" );

  a = -1.0;
  b =  0.5;
  zero_example ( a, b, f_03, "f_03(x) = x * exp ( - x )" );

  a =  0.0001;
  b =  20.0;
  zero_example ( a, b, f_04, "f_04(x) = exp ( x ) - 1 / ( 100 * x * x )" );

  a = -5.0;
  b =  2.0;
  zero_example ( a, b, f_05, "f_05(x) = (x+3) * (x-1) * (x-1)" );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "zero_test():\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void zero_example ( double a, double b, double f ( double x ), char *title )

/******************************************************************************/
/*
  Purpose:

    zero_example() tests zero() on one test function.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 May 2021

  Author:

    John Burkardt

  Input:

    double A, B, the endpoints of the change of sign interval.

    double F ( double x ), the name of a user-supplied
    function which evaluates the function whose zero is being sought.

    char *TITLE, a title for the problem.
*/
{
  int calls;
  double fa;
  double fb;
  double fx;
  double t;
  double x;
  
  t = DBL_EPSILON;

  x = zero ( a, b, t, f, &calls );
  fx = f ( x );
  fa = f ( a );
  fb = f ( b );

  printf ( "\n" );
  printf ( "  %s\n", title );
  printf ( "\n" );
  printf ( "      A                 X             B\n" );
  printf ( "    F(A)              F(X)          F(B)\n" );
  printf ( "\n" );
  printf ( "  %14f  %14f  %14f\n", a, x, b );
  printf ( "  %14e  %14e  %14e\n", fa, fx, fb );
  printf ( "  Number of calls to F = %d\n", calls );

  return;
}
/******************************************************************************/

double f_01 ( double x )

/******************************************************************************/
/*
  Purpose:

    f_01() evaluates sin ( x ) - x / 2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output: 

    double F_01, the value of the function at X.
*/
{
  double value;

  value = sin ( x ) - 0.5 * x;

  return value;
}
/******************************************************************************/

double f_02 ( double x )

/******************************************************************************/
/*
  Purpose:

    f_02() evaluates 2*x-exp(-x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output: 

    double F_02, the value of the function at X.
*/
{
  double value;

  value = 2.0 * x - exp ( - x );

  return value;
}
/******************************************************************************/

double f_03 ( double x )

/******************************************************************************/
/*
  Purpose:

    f_03() evaluates x*exp(-x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output: 

    double F_03, the value of the function at X.
*/
{
  double value;

  value = x * exp ( - x );

  return value;
}
/******************************************************************************/

double f_04 ( double x )

/******************************************************************************/
/*
  Purpose:

    f_04() evaluates exp(x) - 1 / (100*x*x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output: 

    double F_04, the value of the function at X.
*/
{
  double value;

  value = exp ( x ) - 1.0 / 100.0 / x / x;

  return value;
}
/******************************************************************************/

double f_05 ( double x )

/******************************************************************************/
/*
  Purpose:

    f_05() evaluates (x+3)*(x-1)*(x-1).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output: 

    double F_05, the value of the function at X.
*/
{
  double value;

  value = ( x + 3.0 ) * ( x - 1.0 ) * ( x - 1.0 );

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
 
