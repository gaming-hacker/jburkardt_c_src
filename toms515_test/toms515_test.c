# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "toms515.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TOMS515_TEST.

  Discussion:

    TOMS515_TEST tests the TOMS515 library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TOMS515_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TOMS515 library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TOMS515_TEST\n" );
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

    TEST01 tests COMB by generating all 3-subsets of a 5 set.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  int *c;
  int i;
  int k = 3;
  int l;
  int lmax;
  int n = 5;

  lmax = binom ( n, k );

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Generate all K-subsets of an N set.\n" );
  printf ( "  K = %d\n", k );
  printf ( "  N = %d\n", n );
  printf ( "  LMAX = %d\n", lmax );

  if ( ! i4_choose_check ( n, k ) )
  {
    printf ( "\n" );
    printf ( "TEST01 - Warning!\n" );
    printf ( "  The binomial coefficient cannot be\n" );
    printf ( "  computed in integer arithmetic for\n" );
    printf ( "  this choice of parameters.\n" );
    return;
  }

  printf ( "\n" );

  for ( l = 1; l <= lmax; l++ )
  {
    c = comb ( n, k, l );
    printf ( "  %4d:  ", l );
    for ( i = 0; i < k; i++ )
    {
      printf ( "  %4d", c[i] );
    }
    printf ( "\n" );
    free ( c );
  }

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests COMB by generating 10 random 3-subsets of a 10 set.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  int *c;
  int i;
  int j;
  int k = 3;
  int l;
  int lmax;
  int n = 5;
  int seed;

  lmax = binom ( n, k );

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Generate 10 random K-subsets of an N set.\n" );
  printf ( "  K = %d\n", k );
  printf ( "  N = %d\n", n );
  printf ( "  LMAX = %d\n", lmax );

  if ( ! i4_choose_check ( n, k ) )
  {
    printf ( "\n" );
    printf ( "TEST02 - Warning!\n" );
    printf ( "  The binomial coefficient cannot be\n" );
    printf ( "  computed in integer arithmetic for\n" );
    printf ( "  this choice of parameters.\n" );
    return;
  }

  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 10; j++ )
  {
    l = i4_uniform_ab ( 1, lmax, &seed );
    c = comb ( n, k, l );
    printf ( "  %4d:  ", l );
    for ( i = 0; i < k; i++ )
    {
      printf ( "  %4d", c[i] );
    }
    printf ( "\n" );
    free ( c );
  }

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests COMB by generating 10 random 3-subsets of a 25 set.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  int *c;
  int i;
  int j;
  int k = 3;
  int l;
  int lmax;
  int n = 25;
  int seed;

  lmax = binom ( n, k );

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Generate 10 random K-subsets of an N set.\n" );
  printf ( "  K = %d\n", k );
  printf ( "  N = %d\n", n );
  printf ( "  LMAX = %d\n", lmax );

  if ( ! i4_choose_check ( n, k ) )
  {
    printf ( "\n" );
    printf ( "TEST03 - Warning!\n" );
    printf ( "  The binomial coefficient cannot be\n" );
    printf ( "  computed in integer arithmetic for\n" );
    printf ( "  this choice of parameters.\n" );
    return;
  }

  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 10; j++ )
  {
    l = i4_uniform_ab ( 1, lmax, &seed );
    c = comb ( n, k, l );
    printf ( "  %4d:  ", l );
    for ( i = 0; i < k; i++ )
    {
      printf ( "  %4d", c[i] );
    }
    printf ( "\n" );
    free ( c );
  }

  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 tests COMB by generating 10 random 3-subsets of a 100 set.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  int *c;
  int i;
  int j;
  int k = 3;
  int l;
  int lmax;
  int n = 100;
  int seed;

  lmax = binom ( n, k );

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  Generate 10 random K-subsets of an N set.\n" );
  printf ( "  K = %d\n", k );
  printf ( "  N = %d\n", n );
  printf ( "  LMAX = %d\n", lmax );

  if ( ! i4_choose_check ( n, k ) )
  {
    printf ( "\n" );
    printf ( "TEST04 - Warning!\n" );
    printf ( "  The binomial coefficient cannot be\n" );
    printf ( "  computed in integer arithmetic for\n" );
    printf ( "  this choice of parameters.\n" );
    return;
  }

  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 10; j++ )
  {
    l = i4_uniform_ab ( 1, lmax, &seed );
    c = comb ( n, k, l );
    printf ( "  %6d:  ", l );
    for ( i = 0; i < k; i++ )
    {
      printf ( "  %4d", c[i] );
    }
    printf ( "\n" );
    free ( c );
  }

  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests COMB by generating 10 random 10-subsets of a 100 set.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  int *c;
  int i;
  int j;
  int k = 10;
  int l;
  int lmax;
  int n = 100;
  int seed;

  lmax = binom ( n, k );

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Generate 10 random K-subsets of an N set.\n" );
  printf ( "  K = %d\n", k );
  printf ( "  N = %d\n", n );
  printf ( "  LMAX = %d\n", lmax );
  printf ( "\n" );
  printf ( "  Note that this function is already\n" );
  printf ( "  failing because LMAX is negative.\n" );
  printf ( "  The combinatorial coefficient C(100,10)\n" );
  printf ( "  is too large to store in an integer.\n" );
  printf ( "\n" );
  printf ( "  Although the program continues to give\n" );
  printf ( "  results, they cannot be relied on.\n" );

  if ( ! i4_choose_check ( n, k ) )
  {
    printf ( "\n" );
    printf ( "TEST05 - Warning!\n" );
    printf ( "  The binomial coefficient cannot be\n" );
    printf ( "  computed in integer arithmetic for\n" );
    printf ( "  this choice of parameters.\n" );
    return;
  }

  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 10; j++ )
  {
    l = i4_uniform_ab ( 1, lmax, &seed );
    c = comb ( n, k, l );
    printf ( "  %4d:  ", l );
    for ( i = 0; i < k; i++ )
    {
      printf ( "  %4d", c[i] );
    }
    printf ( "\n" );
    free ( c );
  }

  return;
}

