# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "humps.h"

/******************************************************************************/

double humps_antideriv ( double x )

/******************************************************************************/
/*
  Purpose:

    humps_antideriv evaluates the antiderivative of the humps function.

  Discussion:

    y = 1.0 / ( r8_square ( x - 0.3 ) + 0.01 ) 
      + 1.0 / ( r8_square ( x - 0.9 ) + 0.04 ) 
      - 6.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x: the argument.

  Output:

    double humps_antideriv: the value of the antiderivative at x.
*/
{
  double ya;

  ya = ( 1.0 / 0.1 ) * atan ( ( x - 0.3 ) / 0.1 )
     + ( 1.0 / 0.2 ) * atan ( ( x - 0.9 ) / 0.2 )
     - 6.0 * x;

  return ya;
}
/******************************************************************************/

double humps_deriv ( double x )

/******************************************************************************/
/*
  Purpose:

    humps_deriv evaluates the derivative of the humps function.

  Discussion:

    y = 1.0 / ( ( x - 0.3 )^2 + 0.01 )
      + 1.0 / ( ( x - 0.9 )^2 + 0.04 )
      - 6.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x: the argument.

  Output:

    double humps_deriv: the value of the derivative at x.
*/
{
  double yp;

  yp = - 2.0 * ( x - 0.3 ) / r8_square ( r8_square ( x - 0.3 ) + 0.01 )
       - 2.0 * ( x - 0.9 ) / r8_square ( r8_square ( x - 0.9 ) + 0.04 );

  return yp;
}
/******************************************************************************/

double humps_deriv2 ( double x )

/******************************************************************************/
/*
  Purpose:

    humps_deriv2 evaluates the second derivative of the humps function.

  Discussion:

    y = 1.0 / ( ( x - 0.3 )^2 + 0.01 )
      + 1.0 / ( ( x - 0.9 )^2 + 0.04 )
      - 6.0;

    yp = - 2.0 * ( x - 0.3 ) / ( ( x - 0.3 )^2 + 0.01 )^2
         - 2.0 * ( x - 0.9 ) / ( ( x - 0.9 )^2 + 0.04 )^2;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x: the argument.

  Output:

    double humps_deriv2: the value of the second derivative at x.
*/
{
  double u1;
  double u1p;
  double u2;
  double u2p;
  double v1;
  double v1p;
  double v2;
  double v2p;
  double ypp;

  u1 = - 2.0 * ( x - 0.3 );
  v1 = r8_square ( r8_square ( x - 0.3 ) + 0.01 );
  u2 = - 2.0 * ( x - 0.9 );
  v2 = r8_square ( r8_square ( x - 0.9 ) + 0.04 );

  u1p = - 2.0;
  v1p = 2.0 * ( r8_square ( x - 0.3 ) + 0.01 ) * 2.0 * ( x - 0.3 ); 
  u2p = - 2.0;
  v2p = 2.0 * ( r8_square ( x - 0.9 ) + 0.04 ) * 2.0 * ( x - 0.9 );

  ypp = ( u1p * v1 - u1 * v1p ) / v1 / v1
      + ( u2p * v2 - u2 * v2p ) / v2 / v2;

  return ypp;
}
/******************************************************************************/

double humps_fun ( double x )

/******************************************************************************/
/*
  Purpose:

    humps_fun evaluates the humps function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x: the evaluation point.

  Output:

    double y: the function value.
*/
{
  double y;

  y = 1.0 / ( r8_square ( x - 0.3 ) + 0.01 )
    + 1.0 / ( r8_square ( x - 0.9 ) + 0.04 )
    - 6.0;

  return y;
}
/******************************************************************************/

double humps_ode ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    humps_ode evaluates the derivative of the humps function for an ODE solver.

  Discussion:

    This verion of "humps_deriv" appends the input argument "y", as expected 
    by most ODE solving software.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x: the argument.

    double y: the value of the dependent variable.

  Output:

    double humps_ode: the value of the derivative of the humps function.
*/
{
  double yp;

  yp = - 1.0 / r8_square ( r8_square ( x - 0.3 ) + 0.01 )
       * 2.0 * ( x - 0.3 )
       - 1.0 / r8_square ( r8_square ( x - 0.9 ) + 0.04 )
       * 2.0 * ( x - 0.9 );

  return yp;
}
/******************************************************************************/

void plot_xy ( int n, double x[], double y[], char *prefix )

/******************************************************************************/
/*
  Purpose:

    plot_xy plots xy data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    int n, the number of data points.

    double x[n], y[n], the data points.

    char *prefix, the prefix for the plot names.
*/
{
  char command_filename[255];
  FILE *command_unit;
  char data_filename[255];
  FILE *data_unit;
  int i;
  char output_filename[255];
  char *prefix2;
/*
  Create the data file.
*/
  sprintf ( data_filename, "%s_data.txt", prefix );
  data_unit = fopen ( data_filename, "wt" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( data_unit, "%g  %g\n", x[i], y[i] );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'.\n", data_filename );
/*
  Plot the selected data.
*/
  sprintf ( command_filename, "%s_commands.txt", prefix );
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set nokey\n" );
  sprintf ( output_filename, "%s.png", prefix );
  fprintf ( command_unit, "set output '%s'\n", output_filename );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Y(X)--->'\n" );
  prefix2 = s_escape_tex ( prefix );
  fprintf ( command_unit, "set title '%s'\n", prefix2 );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot '%s' using 1:2 lw 3 linecolor rgb 'blue'\n", data_filename );

  fclose ( command_unit );
  printf ( "  Created graphics command file '%s'.\n", command_filename );

  free ( prefix2 );

  return;
}
/******************************************************************************/

double r8_square ( double x )

/******************************************************************************/
/*
  Purpose:

    r8_square returns the square of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x: the argument.

  Output:

    double r8_square: the square of x.
*/
{
  double value;

  value = x * x;

  return value;
}
/******************************************************************************/

char *s_escape_tex ( char *s1 )

/******************************************************************************/
/*
  Purpose:

    S_ESCAPE_TEX de-escapes TeX escape sequences.

  Discussion:

    In particular, every occurrence of the characters '\', '_',
    '^', '{' and '}' will be replaced by '\\', '\_', '\^',
    '\{' and '\}'.  A TeX interpreter, on seeing these character
    strings, is then likely to return the original characters.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2007

  Author:

    John Burkardt

  Parameters:

    Input, char *S1, the string to be de-escaped.

    Output, char *S_ESCAPE_TEX, a copy of the string,
    modified to avoid TeX escapes.
*/
{
  char ch;
  int s1_length;
  int s1_pos;
  char *s2;
  int s2_length;
  int s2_pos;
  int slash_count;

  s1_length = strlen ( s1 );
/*
 We need to know how many slashes occur in S1, so we
  can allocate S2.

  Note that, alas, the backslash is also the escape in C++,
  so we have to say '\\' when we mean '\'!
*/
  slash_count = 0;
  for ( s1_pos = 0; s1_pos < s1_length; s1_pos++ )
  {
    ch = s1[s1_pos];

    if ( ch == '\\' ||
         ch == '_' ||
         ch == '^' ||
         ch == '{' ||
         ch == '}' )
    {
      slash_count = slash_count + 1;
    }
  }

  s2_length = s1_length + slash_count;
  s2 = ( char * ) malloc ( ( s2_length + 1 ) * sizeof ( char ) );
/*
  Now copy S1 into S2.
*/
  s1_pos = 0;
  s2_pos = 0;

  for ( s1_pos = 0; s1_pos < s1_length; s1_pos++ )
  {
    ch = s1[s1_pos];

    if ( ch == '\\' ||
         ch == '_' ||
         ch == '^' ||
         ch == '{' ||
         ch == '}' )
    {
      s2[s2_pos] = '\\';
      s2_pos = s2_pos + 1;
    }

    s2[s2_pos] = ch;
    s2_pos = s2_pos + 1;
  }

  s2[s2_pos] = '\0';
  s2_pos = s2_pos + 1;

  return s2;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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

  strftime ( time_buffer, TIME_SIZE, "d B Y I:M:S p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

