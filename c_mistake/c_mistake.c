# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main ( );
void c_mistake1 ( );
void c_mistake2 ( );
void c_mistake3 ( );
void c_mistake4 ( );
void c_mistake5 ( );
void c_mistake6 ( );
void c_mistake7 ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for C_MISTAKE.

  Discussion:

    C_MISTAKE calls functions that illustrate some mistakes in C programming.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "C_MISTAKE:\n" );
  printf ( "  C version\n" );
  printf ( "  Demonstrate some programming mistakes that are easy to" );
  printf ( "  make when programming in C.\n" );

  c_mistake1 ( );
  c_mistake2 ( );
  c_mistake3 ( );
  c_mistake4 ( );
  c_mistake5 ( );
  c_mistake6 ( );
  c_mistake7 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "C_MISTAKE:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );
 
  return 0;
}
/******************************************************************************/

void c_mistake1 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE1 tries to make a table of integer powers.

  Discussion:

    The table I^J should look like something like this (but it doesn't!):

        0  1  2  3   4    5
    -----------------------
    1:  1  1  1  1   1    1
    2:  1  2  4  8  16   32
    3:  1  3  9 27  81  243
    4:  1  4 16 64 256 1024
    ...

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 July 2016

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int value;

  printf ( "\n" );
  printf ( "C_MISTAKE1:\n" );
  printf ( "  We want a table of I^J, for I = 1 to 10, and J = 0 to 5.\n" );
  printf ( "  We don't get it.\n" );
  printf ( "\n" );
  printf ( " I:     I^0     I^1     I^2     I^3     I^4     I^5\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    printf ( "%2d:", i );

    for ( j = 0; j <= 5; j++ )
    {
      if ( j == 0 )
      {
        value = 1;
      }
      else if ( j == 1 )
      {
        value = i;
      }
      else
      {
        value = 1;
        for ( k = 1; k <= j; k++ );
        {
          value = value * i;
        }
      }
      printf ( "  %6d", value );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void c_mistake2 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE2 tries to determine the sign (-1, 0, or +1) of real numbers.

  Discussion:

    The table should look like something like this (but it doesn't!):

           R   Sign
    -----------------------
    1:  -1.00  -1
    2:  -0.75  -1
    3:   0.50  -1
    4:   0.25  -1
    5:   0.00   0
    6:   0.25   1
    7:   0.50   1
    8:   0.75   1
    9:   1.00   1

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 July 2016

  Author:

    John Burkardt
*/
{
  int i;
  double r;
  int s;

  printf ( "\n" );
  printf ( "C_MISTAKE2:\n" );
  printf ( "  Test a function that returns the sign (-1, 0, or +1)\n" );
  printf ( "  of a real number R:\n" );
  printf ( "\n" );
  printf ( "   I   R    Sign\n" );
  printf ( "\n" );

  for ( i = 1; i <= 9; i++ )
  {
    r = ( double ) ( i - 5 ) / 4.0;
    printf ( "  %2d  %5.2f", i, r );

    if ( r = 0.0 )
    {
      s = 0;
    }
    else if ( r < 0.0 )
    {
      s = -1;
    }
    else
    {
      s = +1;
    }
    printf ( "  %2d\n", s );
  }

  return;
}
/******************************************************************************/

void c_mistake3 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE3 sums 100 random numbers but isn't close to 50.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  double s;

  printf ( "\n" );
  printf ( "C_MISTAKE3:\n" );
  printf ( "  Add up 100 random numbers, and expect a result near 50.\n" );

  s = 0.0;
  for ( i = 0; i < 100; i++ )
  {
    s = s + rand ( );
  }
  printf ( "\n" );
  printf ( "  Sum of 100 random numbers is %g\n", s );

  return;
}
/******************************************************************************/

void c_mistake4 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE4 sums 100 random numbers but isn't close to 50.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  double s;

  printf ( "\n" );
  printf ( "C_MISTAKE4:\n" );
  printf ( "  Add up 100 random numbers, and expect a result near 50.\n" );

  s = 0.0;
  for ( i = 0; i < 100; i++ )
  {
    s = s + rand ( ) / RAND_MAX;
  }
  printf ( "\n" );
  printf ( "  Sum of 100 random numbers is %g\n", s );

  return;
}
/******************************************************************************/

void c_mistake5 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE5 sums 100 random numbers but isn't close to 50.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  double s;

  printf ( "\n" );
  printf ( "C_MISTAKE5:\n" );
  printf ( "  Add up 100 random numbers, and expect a result near 50.\n" );

  s = 0.0;
  for ( i = 0; i < 100; i++ );
  {
    s = s + rand ( ) / ( double ) ( RAND_MAX );
  }
  printf ( "\n" );
  printf ( "  Sum of 100 random numbers is %g\n", s );

  return;
}
/******************************************************************************/

void c_mistake6 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE6 sums row 10 of Pascal's triangle.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2018

  Author:

    John Burkardt
*/
{
  int i;
  double s;
  double w[11] = {1,10,45,120,210,252,210.120,45,10,1};

  printf ( "\n" );
  printf ( "C_MISTAKE6:\n" );
  printf ( "  The 11 elements of row 10 of Pascal's triangle add up to 1024.\n" );

  s = 0.0;
  for ( i = 0; i < 11; i++ )
  {
    s = s + w[i];
  }
  printf ( "\n" );
  printf ( "  Sum of row 10 is %g\n", s );

  return;
}
/******************************************************************************/

void c_mistake7 ( )

/******************************************************************************/
/*
  Purpose:

    C_MISTAKE7 takes the absolute value of sin(x).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2018

  Author:

    John Burkardt
*/
{
  float asx;
  int i;
  float sx;
  float x;

  printf ( "\n" );
  printf ( "C_MISTAKE7:\n" );
  printf ( "  Compute sin(x) and abs(sin(x)) at 10 random values.\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    x = 10.0 * rand ( ) / ( float ) ( RAND_MAX );
    sx = sin ( x );
    asx = abs ( sx );
    printf ( "  %g  %g  %g\n", x, sx, asx );
  }

  return;
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

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

