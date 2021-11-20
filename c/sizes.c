# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <complex.h>
# include <time.h>

int main ( int argc, char *argv[] );
void test01 ( );
void test02 ( );
void test03 ( );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    SIZES returns the size of various data types.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 June 2012

  Author:

    John Burkardt
*/
{
  timestamp ( );

  printf ( "\n" );
  printf ( "SIZES\n" );
  printf ( "  C version\n" );
  printf ( "  Return the size of various data types.\n" );
  printf ( "  Compiled on %s at %s\n", __DATE__, __TIME__ );

  test01 ( );
  test02 ( );
  test03 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SIZES\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 shows that you can ask for the size of a datatype by name.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 June 2012

  Author:

    John Burkardt
*/
{
  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  You can ask for the size of a datatype by name:\n" );
  printf ( "\n" );
  printf ( "  sizeof (            int ) = %lud\n", sizeof ( int ) );
  printf ( "  sizeof (      short int ) = %lud\n", sizeof ( short int ) );
  printf ( "  sizeof (       long int ) = %lud\n", sizeof ( long int ) );
  printf ( "  sizeof (  long long int ) = %lud\n", sizeof ( long long int ) );

  printf ( "  sizeof (          float ) = %lud\n", sizeof ( float ) );
  printf ( "  sizeof (         double ) = %lud\n", sizeof ( double ) );
  printf ( "  sizeof (    long double ) = %lud\n", sizeof ( long double ) );

  printf ( "  sizeof (        complex ) = %lud\n", sizeof ( complex ) );
  printf ( "  sizeof ( double complex ) = %lud\n", sizeof ( double complex ) );
  printf ( "  sizeof (           char ) = %lud\n", sizeof ( char ) );
  printf ( "  sizeof (           bool ) = %lud\n", sizeof ( bool ) );

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 shows that you can ask for the size of a specific variable.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 June 2012

  Author:

    John Burkardt
*/
{
  int a;
  short int b;
  long int c;
  long long int d;
  
  float e;
  double f;
  long double g;

  complex h;
  double complex i;

  char j;
  bool k;

  printf ( "\n" );
  printf ( "TEST02:\n" );
  printf ( "  You can ask for the size of a specific variable:\n" );
  printf ( "\n" );
  printf ( "  sizeof ( a ) = %lud\n", sizeof ( a ) );
  printf ( "  sizeof ( b ) = %lud\n", sizeof ( b ) );
  printf ( "  sizeof ( c ) = %lud\n", sizeof ( c ) );
  printf ( "  sizeof ( d ) = %lud\n", sizeof ( d ) );

  printf ( "  sizeof ( e ) = %lud\n", sizeof ( e ) );
  printf ( "  sizeof ( f ) = %lud\n", sizeof ( f ) );
  printf ( "  sizeof ( g ) = %lud\n", sizeof ( g ) );

  printf ( "  sizeof ( h ) = %lud\n", sizeof ( h ) );
  printf ( "  sizeof ( i ) = %lud\n", sizeof ( i ) );
  printf ( "  sizeof ( j ) = %lud\n", sizeof ( j ) );
  printf ( "  sizeof ( k ) = %lud\n", sizeof ( k ) );

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 shows that you can ask for the size of an array.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 June 2012

  Author:

    John Burkardt
*/
{
  int l[10];
  float m[10];
  double n[10];
  char o[10];

  int p[5][2];
  float q[5][2];
  double r[5][2];
  char s[5][2];

  printf ( "\n" );
  printf ( "TEST03:\n" );
  printf ( "  You can ask for the size of an array:\n" );
  printf ( "\n" );
  printf ( "  sizeof ( l ) = %lud\n", sizeof ( l ) );
  printf ( "  sizeof ( m ) = %lud\n", sizeof ( m ) );
  printf ( "  sizeof ( n ) = %lud\n", sizeof ( n ) );
  printf ( "  sizeof ( o ) = %lud\n", sizeof ( o ) );

  printf ( "  sizeof ( p ) = %lud\n", sizeof ( p ) );
  printf ( "  sizeof ( q ) = %lud\n", sizeof ( q ) );
  printf ( "  sizeof ( r ) = %lud\n", sizeof ( r ) );
  printf ( "  sizeof ( s ) = %lud\n", sizeof ( s ) );

  return;
}
/******************************************************************************/

void timestamp ( void )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    May 31 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 October 2003

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

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
