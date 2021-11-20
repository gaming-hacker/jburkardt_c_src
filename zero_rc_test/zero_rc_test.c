# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "zero_rc.h"

int main ( );
void example_test ( double a, double b, double t, double f ( double x ), 
  char *title );
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

    zero_rc_test() tests zero_rc().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double t;

  timestamp ( );
  printf ( "\n" );
  printf ( "zero_rc_test()\n" );
  printf ( "  C version\n" );
  printf ( "  zero_rc() seeks a root of a function F(X)\n" );
  printf ( "  in an interval [A,B], using reverse communication (RC).\n" );

  t = DBL_EPSILON;

  a = 1.0;
  b = 2.0;
  example_test ( a, b, t, f_01, "f_01(x) = sin ( x ) - x / 2" );

  a = 0.0;
  b = 1.0;
  example_test ( a, b, t, f_02, "f_02(x) = 2 * x - exp ( - x )" );

  a = -1.0;
  b =  0.5;
  example_test ( a, b, t, f_03, "f_03(x) = x * exp ( - x )" );

  a =  0.0001;
  b =  20.0;
  example_test ( a, b, t, f_04, "f_04(x) = exp ( x ) - 1 / ( 100 * x * x )" );

  a = -5.0;
  b =  2.0;
  example_test ( a, b, t, f_05, "f_05(x) = (x+3) * (x-1) * (x-1)" );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "zero_rc_test():\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void example_test ( double a, double b, double t, double f ( double x ), 
  char *title )

/******************************************************************************/
/*
  Purpose:

    example_test() tests zero_rc() on one test function.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

  Author:

    John Burkardt

  Input:

    double A, B, the endpoints of the change of sign interval.

    double T, the error tolerance.

    double F ( double x ), the function whose zero is being sought.

    char *TITLE, a title for the problem.
*/
{
  double arg;
  int status;
  double value;

  printf ( "\n" );
  printf ( "  %s\n", title );
  printf ( "\n" );
  printf ( "    STATUS      X               F(X)\n" );
  printf ( "\n" );

  status = 0;

  for ( ; ; ) 
  {
    zero_rc ( a, b, t, &arg, &status, value );

    if ( status < 0 )
    {
      printf ( "\n" );
      printf ( "  zero_rc() returned an error flag!\n" );
      break;
    }

    value = f ( arg );

    printf ( "  %8d  %24.16e  %10e\n", status, arg, value );

    if ( status == 0 )
    {
      break;
    }
  }

  return;
}
/******************************************************************************/

double f_01 ( double x )

/******************************************************************************/
/*
  Purpose:

    F_01() evaluates sin ( x ) - x / 2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

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

    F_02() evaluates 2*x-exp(-x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

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

    F_03() evaluates x*exp(-x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

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

    F_04() evaluates exp(x) - 1 / (100*x*x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

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

    F_05() evaluates (x+3)*(x-1)*(x-1).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2021

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

