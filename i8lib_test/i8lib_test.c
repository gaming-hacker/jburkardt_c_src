# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <complex.h>

# include "i8lib.h"

int main ( );

void i8_abs_test ( );
void i8_choose_test ( );
void i8_xor_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for I8LIB_TEST.

  Discussion:

    I8LIB_TEST tests the I8LIB library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "I8LIB_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the I8LIB routines.\n" );

  i8_abs_test ( );
  i8_choose_test ( );
  i8_xor_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "I8LIB_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void i8_abs_test ( )

/******************************************************************************/
/*
  Purpose:

    i8_abs_test tests i8_abs.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2019

  Author:

    John Burkardt
*/
{
  long long int a;
  long long int b;
  long long int i;
  long long int i4_hi;
  long long int i4_lo;
  long long int seed;

  printf ( "\n" );
  printf ( "i8_abs_test\n" );
  printf ( "  i8_abs() returns the absolute value of an I8.\n" );
  printf ( "\n" );
  printf ( "       a       b=i8_abs(a)\n" );
  printf ( "\n" );

  i4_lo = -100LL;
  i4_hi = +100LL;
  seed = 123456789LL;

  for ( i = 0LL; i < 10LL; i++ )
  {
    a = i8_uniform_ab ( i4_lo, i4_hi, &seed );
    b = i8_abs ( a );
    printf ( "  %8lld  %8lld\n", a, b );
  }

  return;
}
/******************************************************************************/

void i8_choose_test ( )

/******************************************************************************/
/*
  Purpose:

    i8_choose_test tests I8_CHOOSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 June 2010

  Author:

    John Burkardt
*/
{
  long long int cnk;
  long long int k;
  long long int n;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "i8_choose_test\n" );
  fprintf ( stdout, "  I8_CHOOSE evaluates C(N,K).\n" );
  fprintf ( stdout, "\n" );
  fprintf ( stdout, "     N     K    CNK\n" );
  fprintf ( stdout, "\n" );

  for ( n = 0; n <= 4; n++ )
  {
    for ( k = 0; k <= n; k++ )
    {
      cnk = i8_choose ( n, k );

      fprintf ( stdout, "%6lld  %6lld  %6lld\n", n, k, cnk );
    }
  }

  return;
}
/******************************************************************************/

void i8_xor_test ( )

/******************************************************************************/
/*
  Purpose:

    i8_xor_test tests I8_XOR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 June 2010

  Author:

    John Burkardt
*/
{
  long long int i;
  long long int i_lo = 0LL;
  long long int i_hi = 100LL;
  long long int j;
  long long int k;
  long long int l;
  long long int seed;
  int test;
  int test_num = 10;

  seed = 123456789LL;

  printf ( "\n" );
  printf ( "i8_xor_test\n" );
  printf ( "  I8_XOR returns the bitwise exclusive OR of\n" );
  printf ( "  two I8's.\n" );
  printf ( "  The operator ^ should generally be used instead.\n" );
  printf ( "\n" );
  printf ( "       I       J  I8_XOR     I^J\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    i = i8_uniform_ab ( i_lo, i_hi, &seed );
    j = i8_uniform_ab ( i_lo, i_hi, &seed );
    k = i8_xor ( i, j );
    l = i ^ j;

    printf ( "  %6lld  %6lld  %6lld  %6lld\n", i, j, k, l );
  }

  return;
}
