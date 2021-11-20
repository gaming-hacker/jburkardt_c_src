# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "byname.h"

int main ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    byname_test() tests byname().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2021

  Author:

    John Burkardt
*/
{
  double alpha;
  double beta;
  double gamma;
  double value_in;
  char *pc = NULL;
  double *pd = NULL;

  timestamp ( );
  printf ( "\n" );
  printf ( "byname_test():\n" );
  printf ( "  C version\n" );
  printf ( "  Test byname(), with the interface:\n" );
  printf ( "    value_out = byname(action,name,value_in)\n" );
/*
  May need a null pointer!
*/
  printf ( "\n" );
  printf ( "    byname ( 'print', '*', NULL );\n" );
  byname ( "print", "*", pd );

  value_in = 1.0;
  printf ( "    alpha = byname ( 'set', 'alpha', 1.0 );\n" );
  alpha = byname ( "set", "alpha", &value_in );

  value_in = 99.0;
  printf ( "    beta = byname ( 'set', 'beta', 99 );\n" );
  beta = byname ( "set", "beta", &value_in );

  value_in = alpha + beta;
  printf ( "    byname ( 'set', 'gamma', alpha + beta );\n" );
  byname ( "set", "gamma", &value_in );

  printf ( "    byname ( 'print', '*' );\n" );
  byname ( "print", "*", pd );

  printf ( "    gamma = byname ( 'get', 'gamma' );\n" );
  gamma = byname ( "get", "gamma", pd );

  value_in = 2.0 * gamma;
  printf ( "    byname ( 'set', 'gamma', 2.0*gamma );\n" );
  byname ( "set", "gamma", &value_in );

  printf ( "    byname ( 'print', 'gamma' );\n" );
  byname ( "print", "gamma", pd );

  printf ( "    byname ( 'print', '*' );\n" );
  byname ( "print", "*", pd );

  printf ( "    byname ( 'reset', NULL, NULL );\n" );
  byname ( "reset", pc, pd );

  printf ( "    byname ( 'print', '*', NULL );\n" );
  byname ( "print", "*", pd );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "byname_test():\n" );
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

