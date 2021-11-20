# include <stdlib.h>
# include <stdio.h>

# include "unicycle.h"

int main ( );
void perm_is_unicycle_test ( );
void unicycle_enum_test ( );
void unicycle_index_test ( );
void unicycle_index_to_sequence_test ( );
void unicycle_inverse_test ( );
void unicycle_next_test ( );
void unicycle_random_test ( );
void unicycle_rank_test ( );
void unicycle_unrank_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for UNICYCLE_TEST.

  Discussion:

    UNICYCLE_TEST tests the UNICYCLE library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2012

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "UNICYCLE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the UNICYCLE library.\n" );

  perm_is_unicycle_test ( );
  unicycle_enum_test ( );
  unicycle_index_test ( );
  unicycle_index_to_sequence_test ( );
  unicycle_inverse_test ( );
  unicycle_next_test ( );
  unicycle_random_test ( );
  unicycle_rank_test ( );
  unicycle_unrank_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "UNICYCLE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void perm_is_unicycle_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM_IS_UNICYCLE_TEST tests PERM_IS_UNICYCLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2012

  Author:

    John Burkardt
*/
{
  int n = 5;
  int *p;
  int seed;
  int test;
  int test_num = 10;
  int *u;
  int value;

  seed = 123456789;

  printf ( "\n" );
  printf ( "PERM_IS_UNICYCLE_TEST\n" );
  printf ( "  PERM_IS_UNICYCLE determines whether a permutation\n" );
  printf ( "  is a unicyle\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    p = perm_random ( n, &seed );

    value = perm_is_unicycle ( n, p );

    if ( value )
    {
      perm_print ( n, p, "  This permutation is a unicycle" );
      u = unicycle_index_to_sequence ( n, p );
      unicycle_print ( n, u, "  The permutation in sequence form" );
      free ( u );
    }
    else
    {
      perm_print ( n, p, "  This permutation is NOT a unicycle" );
    }
  }
  return;
}
/******************************************************************************/

void unicycle_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_ENUM_TEST tests UNICYCLE_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
  int n;
  int n_max = 10;
  int num;

  printf ( "\n" );
  printf ( "UNICYCLE_ENUM_TEST\n" );
  printf ( "  UNICYCLE_ENUM enumerates the unicycles of N objects.\n" );
  printf ( "\n" );
  printf ( "  N    Number\n" );
  printf ( "\n" );

  for ( n = 0; n <= n_max; n++ )
  {
    num = unicycle_enum ( n );
    printf ( "  %3d  %8d\n", n, num );
  }
  return;
}
/******************************************************************************/

void unicycle_index_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_INDEX_TEST tests UNICYCLE_INDEX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2012

  Author:

    John Burkardt
*/
{
  int n = 6;
  int *u;
  int *u_index;
  int *u2;
  int seed;
  int test;
  int test_num = 5;

  seed = 123456789;

  printf ( "\n" );
  printf ( "UNICYCLE_INDEX_TEST\n" );
  printf ( "  UNICYCLE_INDEX converts a unicycle to index form.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    u = unicycle_random ( n, &seed );

    unicycle_print ( n, u, "  The unicycle:" );

    u_index = unicycle_index ( n, u );
    
    unicycle_index_print ( n, u_index, "  The index form:" );

    u2 = unicycle_index_to_sequence ( n, u_index );

    unicycle_print ( n, u2, "  The unicycle recovered:" );

    free ( u );
    free ( u_index );
    free ( u2 );
  }
  return;
}
/******************************************************************************/

void unicycle_index_to_sequence_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_INDEX_TO_SEQUENCE_TEST tests UNICYCLE_INDEX_TO_SEQUENCE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2012

  Author:

    John Burkardt
*/
{
  int n = 6;
  int *u;
  int *u_index;
  int *u2;
  int seed;
  int test;
  int test_num = 5;

  seed = 123456789;

  printf ( "\n" );
  printf ( "UNICYCLE_INDEX_TO_SEQUENCE_TEST\n" );
  printf ( "  UNICYCLE_INDEX_TO_SEQUENCE converts an index to unicycle form.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    u = unicycle_random ( n, &seed );

    unicycle_print ( n, u, "  The unicycle:" );

    u_index = unicycle_index ( n, u );
    
    unicycle_index_print ( n, u_index, "  The index form:" );

    u2 = unicycle_index_to_sequence ( n, u_index );

    unicycle_print ( n, u2, "  The unicycle recovered:" );

    free ( u );
    free ( u_index );
    free ( u2 );
  }
  return;
}
/******************************************************************************/

void unicycle_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

     tests UNICYCLE_INVERSE;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 January 2012

  Author:

    John Burkardt
*/
{
  int n = 7;
  int u[7] = { 1, 7, 6, 2, 4, 3, 5 };
  int *u_inverse;

  printf ( "\n" );
  printf ( "UNICYCLE_INVERSE_TEST\n" );
  printf ( "  UNICYCLE_INVERSE inverts a unicycle;\n" );

  unicycle_print ( n, u, "  The original unicycle:" );
 
  u_inverse = unicycle_inverse ( n, u );
 
  unicycle_print ( n, u_inverse, "  The inverse unicycle:" );
 
  free ( u_inverse );

  return;
}
/******************************************************************************/

void unicycle_next_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_NEXT_TEST tests UNICYCLE_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2012

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  int rank;
  int *u;

  u = ( int * ) malloc ( n * sizeof ( int ) );

  printf ( "\n" );
  printf ( "UNICYCLE_NEXT_TEST\n" );
  printf ( "  UNICYCLE_NEXT generates unicycles in lex order.\n" );
  printf ( "\n" );
  rank = -1;
 
  for ( ; ; )
  {
    unicycle_next ( n, u, &rank );

    if ( rank == -1 )
    {
      break;
    }

    printf ( "  %3d:", rank );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d", u[i] );
    }
    printf ( "\n" );
  }

  free ( u );

  return;
}
/******************************************************************************/

void unicycle_random_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_RANDOM_TEST tests UNICYCLE_RANDOM;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2012

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  int seed;
  int *u;

  printf ( "\n" );
  printf ( "UNICYCLE_RANDOM_TEST\n" );
  printf ( "  UNICYCLE_RANDOM produces a random unicyle\n" );;
  printf ( "  For this test, N = %d\n", n );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    u = unicycle_random ( n, &seed );
    unicycle_print ( n, u, " " );
    free ( u );
  }
  return;
}
/******************************************************************************/

void unicycle_rank_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_RANK_TEST tests UNICYCLE_RANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
  int n = 5;
  int rank;
  int u[5] = { 1, 5, 2, 3, 4 };

  printf ( "\n" );
  printf ( "UNICYCLE_RANK_TEST\n" );
  printf ( "  UNICYCLE_RANK ranks a unicycle.\n" );

  unicycle_print ( n, u, "  The unicycle:" );
 
  rank = unicycle_rank ( n, u );
 
  printf ( "\n" );
  printf ( "  The rank is: %d\n", rank );
 
  return;
}
/******************************************************************************/

void unicycle_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_UNRANK_TEST tests UNICYCLE_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
  int n = 5;
  int rank;
  int *u;

  printf ( "\n" );
  printf ( "UNICYCLE_UNRANK_TEST\n" );
  printf ( "  UNICYCLE_UNRANK, given a rank, computes the\n" );
  printf ( "  corresponding unicycle.\n" );
  printf ( "\n" );
  rank = 6;
  printf ( "  The requested rank is %d\n", rank );
 
  u = unicycle_unrank ( n, rank );
 
  unicycle_print ( n, u, "  The unicycle:" );
 
  free ( u );

  return;
}

