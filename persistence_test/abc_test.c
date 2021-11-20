# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "abc.h"

int main ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    abc_test() tests abc().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2021

  Author:

    John Burkardt
*/
{
  double a_in;
  double a_out;
  double b_in;
  double b_out;
  double c_in;
  double c_out;
  double *p = NULL;

  timestamp ( );
  printf ( "\n" );
  printf ( "abc_test():\n" );
  printf ( "  C version\n" );
  printf ( "  Test abc(), with the interface:\n" );
  printf ( "  abc(a_in,b_in,c_in,a_out,b_out,c_out)\n" );

  abc ( p, p, p, &a_out, &b_out, &c_out );
  printf ( "\n" );
  printf ( "    abc ( NULL, NULL, NULL, &a_out, &b_out, &c_out )\n" );
  printf ( "    a_out = %g, b_out = %g, c_out = %g\n", a_out, b_out, c_out );

  a_in = a_out;
  b_in = 19;
  c_in = c_out;
  abc ( &a_in, &b_in, &c_in, p, p, p );
  printf ( "\n" );
  printf ( "    a_in = %g, b_in = %g, c_in = %g\n", a_in, b_in, c_in );
  printf ( "    abc ( &a_in, &b_in, &c_in, NULL, NULL, NULL )\n" );

  abc ( p, p, p, &a_out, &b_out, &c_out );
  printf ( "\n" );
  printf ( "    abc ( NULL, NULL, NULL, &a_out, &b_out, &c_out )\n" );
  printf ( "    a_out = %g, b_out = %g, c_out = %g\n", a_out, b_out, c_out );

  a_in = 50;
  b_in = 60;
  c_in = 70;
  abc ( &a_in, &b_in, &c_in, &a_out, &b_out, &c_out );
  printf ( "\n" );
  printf ( "    a_in = %g, b_in = %g, c_in = %g\n", a_in, b_in, c_in );
  printf ( "    abc ( &a_in, &b_in, &c_in, &a_out, &b_out, &c_out );\n" );
  printf ( "    a_out = %g, b_out = %g, c_out = %g\n", a_out, b_out, c_out );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "abc_test():\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
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
