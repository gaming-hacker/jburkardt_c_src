# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "local_min.h"

int main ( );
void local_min_example ( double a, double b, double f ( double x ), 
  char *title );
double g_01 ( double x );
double g_02 ( double x );
double g_03 ( double x );
double g_04 ( double x );
double g_05 ( double x );
double g_06 ( double x );
double g_07 ( double x );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    local_min_test() tests local_min().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2021

  Author:

    John Burkardt
*/
{
  double a;
  double b;

  timestamp ( );
  printf ( "\n" );
  printf ( "local_min_test():\n" );
  printf ( "  C version\n" );
  printf ( "  local_min() seeks a local minimizer of\n" );
  printf ( "  a function F(X) in an interval [A,B].\n" );

  a = 0.0;
  b = 3.141592653589793;
  local_min_example ( a, b, g_01, "g_01(x) = ( x - 2 ) * ( x - 2 ) + 1" );

  a = 0.0;
  b = 1.0;
  local_min_example ( a, b, g_02, "g_02(x) = x * x + exp ( - x )" );

  a = -2.0;
  b =  2.0;
  local_min_example ( a, b, g_03, "g_03(x) = x^4 + 2x^2 + x + 3" );

  a =  0.0001;
  b =  1.0;
  local_min_example ( a, b, g_04, "g_04(x) = exp ( x ) + 1 / ( 100 x )" );

  a =  0.0002;
  b = 2.0;
  local_min_example ( a, b, g_05, 
    "g_05(x) = exp ( x ) - 2x + 1/(100x) - 1/(1000000x^2)" );

  a = 1.8;
  b = 1.9;
  local_min_example ( a, b, g_06, 
    "g_06(x) = -x*sin(10*pi*x)-1.0" );

  a = -1.2;
  b = 2.7;
  local_min_example ( a, b, g_07, 
    "g_07(x) = max(-2(x-1),8(x-1)) + 25*(x-1)^2" );

/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "local_min_test():\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void local_min_example ( double a, double b, double f ( double x ), 
  char *title )

/******************************************************************************/
/*
  Purpose:

    local_min_example() tests local_min() on one test function.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2021

  Author:

    John Burkardt

  Input:

    double A, B, the endpoints of the interval.

    double F ( double x ), the name of a user-supplied
    function, whose local minimum is being sought.

    char *TITLE, a title for the problem.
*/
{
  int calls;
  double eps;
  double fa;
  double fb;
  double fx;
  double t;
  double x;

  eps = DBL_EPSILON;
  t = sqrt ( eps );

  fx = local_min ( a, b, eps, t, f, &x, &calls );
  fa = f ( a );
  fb = f ( b );

  printf ( "\n" );
  printf ( "  %s\n", title );
  printf ( "\n" );
  printf ( "      A                 Z             B\n" );
  printf ( "    F(A)              F(Z)          F(B)\n" );
  printf ( "\n" );
  printf ( "  %14f  %14f  %14f\n",  a,  x,  b );
  printf ( "  %14e  %14e  %14e\n", fa, fx, fb );
  printf ( "  Number of calls to F = %d\n", calls );

  return;
}
/******************************************************************************/

double g_01 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_01() evaluates (x-2)^2 + 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_01, the value of the function at X.
*/
{
  double value;

  value = ( x - 2.0 ) * ( x - 2.0 ) + 1.0;

  return value;
}
/******************************************************************************/

double g_02 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_02() evaluates x^2 + exp ( - x ).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_02, the value of the function at X.
*/
{
  double value;

  value = x * x + exp ( - x );

  return value;
}
/******************************************************************************/

double g_03 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_03() evaluates x^4+2x^2+x+3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_03, the value of the function at X.
*/
{
  double value;

  value = ( ( x * x + 2.0 ) * x + 1.0 ) * x + 3.0;

  return value;
}
/******************************************************************************/

double g_04 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_04() evaluates exp(x)+1/(100X)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_04, the value of the function at X.
*/
{
  double value;

  value = exp ( x ) + 0.01 / x;

  return value;
}
/******************************************************************************/

double g_05 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_05() evaluates exp(x) - 2x + 1/(100x) - 1/(1000000x^2)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2008

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_05, the value of the function at X.
*/
{
  double value;

  value = exp ( x ) - 2.0 * x + 0.01 / x - 0.000001 / x / x;

  return value;
}
/******************************************************************************/

double g_06 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_06() evaluates - x * sin(10 pi x ) - 1.0;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2021

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_06, the value of the function at X.
*/
{
  double r8_pi = 3.141592653589793;
  double value;

  value = - x * sin ( 10.0 * r8_pi * x ) - 1.0;

  return value;
}
/******************************************************************************/

double g_07 ( double x )

/******************************************************************************/
/*
  Purpose:

    g_07() evaluates max(-2(x-1), 8(x-1)) + 25 (x-1)^2

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2021

  Author:

    John Burkardt

  Input:

    double X, the evaluation point.

  Output:

    double G_07, the value of the function at X.
*/
{
  double value;

  value = fmax ( -2.0 * ( x - 1 ), 8.0 * ( x - 1 ) ) 
          + 25.0 * pow ( x - 1.0, 2 );

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
 
