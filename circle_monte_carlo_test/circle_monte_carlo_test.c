# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "circle_monte_carlo.h"

int main ( );
void circle01_sample_ergodic_test ( );
void circle01_sample_random_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CIRCLE_MONTE_CARLO_TEST.

  Discussion:

    CIRCLE_MONTE_CARLO_TEST tests the CIRCLE_MONTE_CARLO library.
    
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 June 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "CIRCLE_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the CIRCLE_MONTE_CARLO library.\n" );

  circle01_sample_random_test ( );
  circle01_sample_ergodic_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CIRCLE_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void circle01_sample_random_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE01_SAMPLE_RANDOM_TEST uses CIRCLE01_SAMPLE_RANDOM with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 January 2014

  Author:

    John Burkardt
*/
{
  int e[2];
  int e_test[2*7] = {
    0, 0, 
    2, 0, 
    0, 2, 
    4, 0, 
    2, 2, 
    0, 4,
    6, 0 };
  double exact;
  int i;
  int j;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "CIRCLE01_SAMPLE_RANDOM_TEST:\n" );
  printf ( "  CIRCLE01_SAMPLE_RANDOM randomly samples the unit circle.\n" );
  printf ( "  Use it to estimate integrals.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N        1              X^2             Y^2" );
  printf ( "             X^4           X^2Y^2          Y^4          X^6\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    x = circle01_sample_random ( n, &seed );
    printf ( "  %8d", n );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }

      value = monomial_value ( 2, n, e, x );

      result = circle01_length ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
      printf ( "  %14.10g", result );

      free ( value );
    }
    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  printf ( "\n" );
  printf ( "     Exact" );
  for ( j = 0; j < 7; j++ )
  {
    for ( i = 0; i < 2; i++ )
    {
      e[i] = e_test[i+j*2];
    }
    exact = circle01_monomial_integral ( e );
    printf ( "  %14.10g", exact );
  }
  printf ( "\n" );

  return;
}
/******************************************************************************/

void circle01_sample_ergodic_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE01_SAMPLE_ERGODIC_TEST uses CIRCLE01_SAMPLE_ERGODIC with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 June 2017

  Author:

    John Burkardt
*/
{
  double angle;
  int e[2];
  int e_test[2*7] = {
    0, 0, 
    2, 0, 
    0, 2, 
    4, 0, 
    2, 2, 
    0, 4,
    6, 0 };
  double exact;
  int i;
  int j;
  int n;
  double result;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "CIRCLE01_SAMPLE_ERGODIC_TEST:\n" );
  printf ( "  CIRCLE01_SAMPLE_ERGODIC ergodically samples the unit circle.\n" );
  printf ( "  Use it to estimate integrals.\n" );

  printf ( "\n" );
  printf ( "         N        1              X^2             Y^2" );
  printf ( "             X^4           X^2Y^2          Y^4          X^6\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    angle = 0.0;
    x = circle01_sample_ergodic ( n, &angle );
    printf ( "  %8d", n );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }

      value = monomial_value ( 2, n, e, x );

      result = circle01_length ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
      printf ( "  %14.10g", result );

      free ( value );
    }
    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  printf ( "\n" );
  printf ( "     Exact" );
  for ( j = 0; j < 7; j++ )
  {
    for ( i = 0; i < 2; i++ )
    {
      e[i] = e_test[i+j*2];
    }
    exact = circle01_monomial_integral ( e );
    printf ( "  %14.10g", exact );
  }
  printf ( "\n" );

  return;
}
