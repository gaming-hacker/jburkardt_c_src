# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "root_rc.h"

int main ( );
void test01 ( );
void test02 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ROOT_RC_TEST.

  Discussion:

    ROOT_RC_TEST tests the ROOT_RC library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2016

  Author:

    John Burkardt
*/
{
  double ferr;
  double fx;
  int i;
  int it;
  int it_max;
  double q[9];
  double x;
  double xerr;

  timestamp ( );
  printf ( "\n" );
  printf ( "ROOT_RC_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  ROOT_RC searches for an\n" );
  printf ( "  approximate solution of F(X) = 0, using reverse communication.\n" );
  printf ( "\n" );
  printf ( "       X              XERR            FX              FERR\n" );
  printf ( "\n" );
/*
  Initialization.
*/
  it = 0;
  it_max = 30;
  for ( i = 0; i < 9; i++ )
  {
    q[i] = 0.0;
  }
  x = - 2.1;
/*
  Each call takes one more step of improvement.
*/
  for ( ; ; )
  {
    fx = cos ( x ) - x;

    if ( it == 0 )
    {
      printf ( "  %14.6g                  %14.6g\n", x, fx );
    }
    else
    {
      printf ( "  %14.6g  %14.6g  %14.6g  %14.6g\n", x, xerr, fx, ferr );
    }

    x = root_rc ( x, fx, &ferr, &xerr, q );

    if ( ferr < 1.0E-08 )
    {
      printf ( "\n" );
      printf ( "  Uncertainty in F(X) less than tolerance\n" );
      break;
    }

    if ( xerr < 1.0E-08 )
    {
      printf ( "\n" );
      printf ( "  Width of X interal less than tolerance.\n" );
      break;
    }

    if ( it_max < it )
    {
      printf ( "\n" );
      printf ( "  Too many iterations!'\n" );
      break;
    }
    it = it + 1;     
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ROOT_RC_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}

