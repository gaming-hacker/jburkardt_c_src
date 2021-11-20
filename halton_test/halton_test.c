# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "halton.h"

int main ( );
void halton_test ( );
void halton_sequence_test ( );
void halton_inverse_test ( );
void halton_base_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for HALTON_TEST.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "HALTON_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the HALTON library\n" );

  halton_test ( );
  halton_sequence_test ( );
  halton_inverse_test ( );
  halton_base_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "HALTON_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void halton_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_TEST tests HALTON.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m;
  double *r;

  printf ( "\n" );
  printf ( "HALTON_TEST\n" );
  printf ( "  HALTON returns the I-th element of an M-dimensional\n" );
  printf ( "  Halton sequence.\n" );
  printf ( "\n" );
  printf ( "    I          HALTON(I)\n" );

  for ( m = 1; m <= 3; m++ )
  {
    printf ( "\n" );
    printf ( "  Use M = %d\n", m );
    printf ( "\n" );
    for ( i = 0; i <= 10; i++ )
    {
      r =  halton ( i, m );
      printf ( "  %3d", i );
      for ( j = 0; j < m; j++ )
      {
        printf ( "  %14.8g", r[j] );
      }
      printf ( "\n" );
      free ( r );
    }
  }

  return;
}
/******************************************************************************/

void halton_base_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_BASE_TEST tests HALTON_BASE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int b1[3] = { 2, 3, 5 };
  int b2[3] = { 3, 10, 2 };
  int i;
  int j;
  int m;
  double *r;

  printf ( "\n" );
  printf ( "HALTON_BASE_TEST\n" );
  printf ( "  HALTON_BASE returns the I-th element of an M-dimensional\n" );
  printf ( "  Halton sequence, using user-specified bases.\n" );

  m = 3;
  printf ( "\n" );
  printf ( "  M = %d\n", m );
  printf ( "  B:" );
  for ( j = 0; j < m; j++ )
  {
    printf ( "  %14d", b1[j] );
  }
  printf ( "\n" );
  printf ( "\n" );
  for ( i = 0; i <= 10; i++ )
  {
    r = halton_base ( i, m, b1 );
    printf ( "  %3d", i );
    for ( j = 0; j < m; j++ )
    {
      printf ( "  %14.8g", r[j] );
    }
    printf ( "\n" );
    free ( r );
  }

  m = 3;
  printf ( "\n" );
  printf ( "  M = %d\n", m );
  printf ( "  B:" );
  for ( j = 0; j < m; j++ )
  {
    printf ( "  %14d", b2[j] );
  }
  printf ( "\n" );
  printf ( "\n" );
  for ( i = 0; i <= 10; i++ )
  {
    r = halton_base ( i, m, b2 );
    printf ( "  %3d", i );
    for ( j = 0; j < m; j++ )
    {
      printf ( "  %14.8g", r[j] );
    }
    printf ( "\n" );
    free ( r );
  }

  return;
}
/******************************************************************************/

void halton_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_INVERSE_TEST tests HALTON_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  int i2;
  int j;
  int m;
  double *r;

  printf ( "\n" );
  printf ( "HALTON_INVERSE_TEST\n" );
  printf ( "  HALTON_INVERSE inverts an element of a Halton sequence.\n" );
  printf ( "\n" );
  printf ( "    I        R=HALTON(I,3)  HALTON_INVERSE(R,3)\n" );
  printf ( "\n" );

  m = 3;

  for ( i = 0; i <= 10; i++ )
  {
    r = halton ( i, m );
    i2 = halton_inverse ( r, m );
    printf ( "  %3d", i );
    for ( j = 0; j < m; j++ )
    {
      printf ( "  %14.8g", r[j] );
    }
    printf ( "  %3d\n", i2 );
    free ( r );
  }

  return;
}
/******************************************************************************/

void halton_sequence_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_SEQUENCE_TEST tests HALTON_SEQUENCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2016

  Author:

    John Burkardt
*/
{
  int m;
  double *r;

  printf ( "\n" );
  printf ( "HALTON_SEQUENCE_TEST\n" );
  printf ( "  HALTON_SEQUENCE returns the elements I1 through I2\n" );
  printf ( "  of an M-dimensional Halton sequence.\n" );

  for ( m = 1; m <= 3; m++ )
  {
    printf ( "\n" );
    printf ( "  HALTON_SEQUENCE(0,10,%d,R):\n", m );
    r = halton_sequence ( 0, 10, m );
    r8mat_print ( m, 11, r, "  R:" );
    free ( r );
  }

  m = 3;
  printf ( "\n" );
  printf ( "  HALTON_SEQUENCE(10,0,%d,R):\n", m );
  r = halton_sequence ( 10, 0, m );
  r8mat_print ( m, 11, r, "  R:" );
  free ( r );

  return;
}

