# include <stdio.h>
# include <time.h>

# include "constants.h"

int main ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    constants_test() tests constants().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 May 2021

  Author:

    John Burkardt
*/
{
  double c;
  double g;
  double h;

  printf ( "\n" );
  printf ( "constants_test():\n" );
  printf ( "  C version\n" );
  printf ( "  Test constants(), with the interface:\n" );
  printf ( "    [g,c,h] = constants()\n" );
  printf ( "\n" );

  constants ( &g, &c, &h );

  printf ( "    constants ( %g, %g, %g )\n", g, c, h );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "constants_test():\n" );
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

