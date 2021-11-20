# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "fsolve.h"

int main ( );
void fsolve_test1 ( );
void f1 ( int n, double x[], double fx[] );
void fsolve_test2 ( );
void f2 ( int n, double x[], double fx[] );
void fsolve_test3 ( );
void f3 ( int n, double x[], double fx[] );
void fsolve_test4 ( );
void f4 ( int n, double x[], double fx[] );
void r8vec2_print ( int n, double a1[], double a2[], char *title );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    fsolve_test() tests fsolve().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "fsolve_test():\n" );
  printf ( "  C version:\n" );
  printf ( "  Test fsolve().\n" );

  fsolve_test1 ( );
  fsolve_test2 ( );
  fsolve_test3 ( );
  fsolve_test4 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "fsolve_test()\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void fsolve_test1 ( )

/******************************************************************************/
/*
  Purpose:

    fsolve_test1() tests fsolve on a system of 1 equations.

  Discussion:

    This is a version of Kepler's equation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt
*/
{
  double *fx;
  int info;
  int n = 1;
  double tol = 0.00001;
  double *x;

  fx = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "fsolve_test1():\n" );
  printf ( "  fsolve() solves a nonlinear system of 1 equation.\n" );

  x[0] = 0.0;

  f1 ( n, x, fx );

  r8vec2_print ( n, x, fx, "  Initial X, F(X)" );

  info = fsolve ( f1, n, x, fx, tol );

  printf ( "\n" );
  printf ( "  Returned value of INFO = %d", info );
  r8vec2_print ( n, x, fx, "  Final X, FX" );
/*
  Free memory.
*/
  free ( fx );
  free ( x );

  return;
}
/******************************************************************************/

void f1 ( int n, double x[], double fx[] )

/******************************************************************************/
/*
  Purpose:

    f1() evaluates a nonlinear system of 1 equation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt

  Input:

    int N, the number of variables.

    double X[N], the variable values.

  Output:

    double FX[N], the function values.
*/
{
  double e;
  double m;

  e = 0.8;
  m = 5.0;

  fx[0] = x[0] - m - e * sin ( x[0] );

  return;
}
/******************************************************************************/

void fsolve_test2 ( )

/******************************************************************************/
/*
  Purpose:

    fsolve_test2() tests fsolve on a system of 2 equations.

  Discussion:

    The set of nonlinear equations is:

      x1 * x1 - 10 * x1 + x2 * x2 + 8 = 0
      x1 * x2 * x2 + x1 - 10 * x2 + 8 = 0

    with solution x1 = x2 = 1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt
*/
{
  double *fx;
  int info;
  int n = 2;
  double tol = 0.00001;
  double *x;

  fx = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "fsolve_test2():\n" );
  printf ( "  fsolve() solves a nonlinear system of 2 equations.\n" );

  x[0] = 3.0;
  x[1] = 0.0;

  f2 ( n, x, fx );

  r8vec2_print ( n, x, fx, "  Initial X, F(X)" );

  info = fsolve ( f2, n, x, fx, tol );

  printf ( "\n" );
  printf ( "  Returned value of INFO = %d", info );
  r8vec2_print ( n, x, fx, "  Final X, FX" );
/*
  Free memory.
*/
  free ( fx );
  free ( x );

  return;
}
/******************************************************************************/

void f2 ( int n, double x[], double fx[] )

/******************************************************************************/
/*
  Purpose:

    f2() evaluates a nonlinear system of 2 equations.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt

  Input:

    int N, the number of variables.

    double X[N], the variable values.

  Output:

    double FX[N], the function values.
*/
{
  fx[0] = x[0] * x[0] - 10.0 * x[0] + x[1] * x[1] + 8.0;
  fx[1] = x[0] * x[1] * x[1] + x[0] - 10.0 * x[1] + 8.0;

  return;
}
/******************************************************************************/

void fsolve_test3 ( )

/******************************************************************************/
/*
  Purpose:

    fsolve_test3() tests fsolve on a system of 4 equations.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt
*/
{
  double *fx;
  int i;
  int info;
  int n = 4;
  double tol = 0.00001;
  double *x;

  fx = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "fsolve_test3():\n" );
  printf ( "  fsolve() solves a nonlinear system of 4 equations.\n" );

  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }

  f3 ( n, x, fx );

  r8vec2_print ( n, x, fx, "  Initial X, F(X)" );

  info = fsolve ( f3, n, x, fx, tol );

  printf ( "\n" );
  printf ( "  Returned value of INFO = %d", info );
  r8vec2_print ( n, x, fx, "  Final X, FX" );
/*
  Free memory.
*/
  free ( fx );
  free ( x );

  return;
}
/******************************************************************************/

void f3 ( int n, double x[], double fx[] )

/******************************************************************************/
/*
  Purpose:

    f3() evaluates a nonlinear system of 4 equations.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt

  Input:

    int N, the number of variables.

    double X[N], the variable values.

  Output:

    double FX[N], the function values.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    fx[i] = pow ( x[i] - ( i + 1 ), 2 );
  }

  return;
}
/******************************************************************************/

void fsolve_test4 ( )

/******************************************************************************/
/*
  Purpose:

    fsolve_test4() tests fsolve on a system of 8 equations.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt
*/
{
  double *fx;
  int i;
  int info;
  int n = 8;
  double tol = 0.00001;
  double *x;

  fx = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "fsolve_test4():\n" );
  printf ( "  fsolve() solves a nonlinear system of 8 equations.\n" );

  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }

  f4 ( n, x, fx );

  r8vec2_print ( n, x, fx, "  Initial X, F(X)" );

  info = fsolve ( f4, n, x, fx, tol );

  printf ( "\n" );
  printf ( "  Returned value of INFO = %d", info );
  r8vec2_print ( n, x, fx, "  Final X, FX" );
/*
  Free memory.
*/
  free ( fx );
  free ( x );

  return;
}
/******************************************************************************/

void f4 ( int n, double x[], double fx[] )

/******************************************************************************/
/*
  Purpose:

    f4() evaluates a nonlinear system of 8 equations.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2021

  Author:

    John Burkardt

  Input:

    int N, the number of variables.

    double X[N], the variable values.

  Output:

    double FX[N], the function values.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    fx[i] = ( 3.0 - 2.0 * x[i] ) * x[i] + 1.0;

    if ( 0 < i )
    {
      fx[i] = fx[i] - x[i-1];
    }

    if ( i < n - 1 )
    {
      fx[i] = fx[i] - 2.0 * x[i+1];
    }
  }

  return;
}
/******************************************************************************/

void r8vec2_print ( int n, double a1[], double a2[], char *title )

/******************************************************************************/
/*
  Purpose:

    r8vec2_print() prints an R8VEC2.

  Discussion:

    An R8VEC2 is a dataset consisting of N pairs of real values, stored
    as two separate vectors A1 and A2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2009

  Author:

    John Burkardt

  Input:

    int N, the number of components of the vector.

    double A1[N], double A2[N], the vectors to be printed.

    char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %4d: %14g  %14g\n", i, a1[i], a2[i] );
  }

  return;
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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

