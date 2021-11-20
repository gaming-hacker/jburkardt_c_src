# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "hammersley.h"

int main ( );
void hammersley_test ( );
void hammersley_inverse_test ( );
void hammersley_sequence_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for HAMMERSLEY_TEST.

  Discussion:

    HAMMERSLEY_TEST tests the HAMMERSLEY library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "HAMMERSLEY_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the HAMMERSLEY library.\n" );

  hammersley_test ( );
  hammersley_inverse_test ( );
  hammersley_sequence_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "HAMMERSLEY_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void hammersley_test ( )

/******************************************************************************/
/*
  Purpose:

    HAMMERSLEY_TEST tests HAMMERSLEY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m;
  int n;
  double *r;

  printf ( "\n" );
  printf ( "HAMMERSLEY_TEST\n" );
  printf ( "  HAMMERSLEY returns the I-th element of an M-dimensional\n" );
  printf ( "  Hammersley sequence.\n" );
  printf ( "\n" );
  printf ( "    I          HAMMERSLEY(I)\n" );

  n = 16;

  for ( m = 1; m <= 3; m++ )
  {
    printf ( "\n" );
    printf ( "  Use M = %d\n", m );
    printf ( "      N = %d\n", n );
    printf ( "\n" );
    for ( i = 0; i <= 10; i++ )
    {
      printf ( "  %3d", i );
      r = hammersley ( i, m, n );
      for ( j = 0; j < m; j++ )
      {
        printf ( "  %14g", r[j] );
      }
      printf ( "\n" );
      free ( r );
    }
  }

  return;
}
/******************************************************************************/

void hammersley_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    HAMMERSLEY_INVERSE_TEST tests HAMMERSLEY_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  int i2;
  int j;
  int m;
  int n;
  double *r;

  printf ( "\n" );
  printf ( "HAMMERSLEY_INVERSE_TEST\n" );
  printf ( "  HAMMERSLEY_INVERSE inverts an element of a Hammersley sequence.\n" );
  printf ( "\n" );
  printf ( "    I        R=HAMMERSLEY(I,3)  HAMMERSLEY_INVERSE(R,3)\n" );
  printf ( "\n" );

  m = 3;
  n = 16;

  for ( i = 0; i <= 10; i++ )
  {
    printf ( "  %3d", i );
    r = hammersley ( i, m, n );
    for ( j = 0; j < m; j++ )
    {
      printf ( "  %14g", r[j] );
    }
    i2 = hammersley_inverse ( r, m, n );
    printf ( "  %3d\n", i2 );
    free ( r );
  }

  return;
}
/******************************************************************************/

void hammersley_sequence_test ( )

/******************************************************************************/
/*
  Purpose:

    HAMMERSLEY_SEQUENCE_TEST tests HAMMERSLEY_SEQUENCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2016

  Author:

    John Burkardt
*/
{
  int m;
  int n;
  double *r;

  printf ( "\n" );
  printf ( "HAMMERSLEY_SEQUENCE_TEST\n" );
  printf ( "  HAMMERSLEY_SEQUENCE returns the elements I1 through I2\n" );
  printf ( "  of an M-dimensional Hammersley sequence.\n" );

  n = 16;

  for ( m = 1; m <= 3; m++ )
  {
    printf ( "\n" );
    printf ( "  HAMMERSLEY_SEQUENCE(0,10,%d,N,R):\n", m );
    r = hammersley_sequence ( 0, 10, m, n );
    r8mat_print ( m, 11, r, "  R:" );
    free ( r );
  }

  m = 3;
  n = 16;
  printf ( "\n" );
  printf ( "  HAMMERSLEY_SEQUENCE(10,0,%d,N,R)\n", m );
  r = hammersley_sequence ( 10, 0, m, n );
  r8mat_print ( m, 11, r, "  R:" );
  free ( r );

  return;
}

