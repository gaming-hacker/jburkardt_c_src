# include <stdlib.h>
# include <stdio.h>

int main ( );
void leaker ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TEST03.

  Discussion:

    TEST03 has a "memory leak".

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 May 2017

  Author:

    John Burkardt
*/
{
  printf ( "\n" );
  printf ( "TEST03:\n" );
  printf ( "  C version\n" );
  printf ( "  A sample code for analysis by VALGRIND.\n" );

  leaker ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
/******************************************************************************/

void leaker ( )

/******************************************************************************/
/*
  Purpose:

    LEAKER malloc's memory but doesn't free it later.

  Discussion:

    Here we allocate an array, but we do not free it before
    leaving the function.  VALGRIND will point out this memory leak.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 May 2017

  Author:

    John Burkardt
*/
{
  int i;
  int *x;

  x = ( int * ) malloc ( 10 * sizeof ( int ) );

  x[0] = 1;
  for ( i = 1; i < 10; i++ )
  {
    x[i] = i * x[i-1];
  }

  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %d! = %d\n", i, x[i] );
  }
/*
  Here's where we should have a "free ( x );" statement
  to return the memory.
*/

  return;
}
