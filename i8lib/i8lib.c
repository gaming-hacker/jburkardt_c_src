# include <complex.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "i8lib.h"

/******************************************************************************/

long long int i8_abs ( long long int i )

/******************************************************************************/
/*
  Purpose:

    I8_ABS returns the absolute value of an I8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2019

  Author:

    John Burkardt

  Parameters:

    Input, long long int I, an integer.

    Output, long long int I8_ABS, the absolute value of the integer.
*/
{
  long long int value;

  if ( 0 <= i )
  {
    value = i;
  }
  else
  {
    value = - i;
  }
  return value;
}
/******************************************************************************/

long long int i8_choose ( long long int n, long long int k )

/******************************************************************************/
/*
  Purpose:

    I8_CHOOSE computes the binomial coefficient C(N,K) as an I8.

  Discussion:

    The value is calculated in such a way as to avoid overflow and
    roundoff.

    The formula used is:

      C(N,K) = N! / ( K! * (N-K)! )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 June 2010

  Author:

    John Burkardt

  Reference:

    ML Wolfson, HV Wright,
    Algorithm 160:
    Combinatorial of M Things Taken N at a Time,
    Communications of the ACM,
    Volume 6, Number 4, April 1963, page 161.

  Parameters:

    Input, long long int N, K, the values of N and K.

    Output, long long int I8_CHOOSE, the number of combinations of N
    things taken K at a time.
*/
{
  long long int i;
  long long mn;
  long long mx;
  long long value;

  mn = i8_min ( k, n - k );

  if ( mn < 0 )
  {
    value = 0;
  }
  else if ( mn == 0 )
  {
    value = 1;
  }
  else
  {
    mx = i8_max ( k, n - k );
    value = mx + 1;

    for ( i = 2; i <= mn; i++ )
    {
      value = ( value * ( mx + i ) ) / i;
    }
  }
  return value;
}
/******************************************************************************/

long long int i8_huge ( )

/******************************************************************************/
/*
  Purpose:

    I8_HUGE returns a "huge" I8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 January 2007

  Author:

    John Burkardt

  Parameters:

    Output, long long int I8_HUGE, a "huge" I8.
*/
{
  long long int value;

  value = 9223372036854775807LL;

  return value;
}
/******************************************************************************/

double i8_huge_normalizer ( )

/******************************************************************************/
/*
  Purpose:

    I8_HUGE_NORMALIZER returns the "normalizer" for I8_HUGE.

  Discussion:

    The value returned is 1 / ( I8_HUGE + 1 ).

    For any I8, it should be the case that

     -1 < I8 * I8_HUGE_NORMALIZER < 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 June 2010

  Author:

    John Burkardt

  Parameters:

    Output, double I8_HUGE_NORMALIZER, the "normalizer" for I8_HUGE.
*/
{
  double value = 1.084202172485504434007E-19;

  return value;
}
/******************************************************************************/

long long int i8_max ( long long int i1, long long int i2 )

/******************************************************************************/
/*
  Purpose:

    I8_MAX returns the maximum of two I8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 January 2007

  Author:

    John Burkardt

  Parameters:

    Input, long long int I1, I2, two integers to be compared.

    Output, long long int I8_MAX, the larger of I1 and I2.
*/
{
  long long int value;

  if ( i2 < i1 ) 
  {
    value = i1;
  }
  else 
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

long long int i8_min ( long long int i1, long long int i2 )

/******************************************************************************/
/*
  Purpose:

    I8_MIN returns the smaller of two I8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 January 2007

  Author:

    John Burkardt

  Parameters:

    Input, long long int I1, I2, two integers to be compared.

    Output, long long int I8_MIN, the smaller of I1 and I2.
*/
{
  long long int value;

  if ( i1 < i2 ) 
  {
    value = i1;
  }
  else 
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

long long int i8_power ( long long int i, long long int j )

/******************************************************************************/
/*
  Purpose:

    I8_POWER returns the value of I^J.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, long long int I, J, the base and the power.  
    J should be nonnegative.

    Output, long long int I8_POWER, the value of I^J.
*/
{
  long long int k;
  long long int value;

  if ( j < 0 )
  {
    if ( i == 1 )
    {
      value = 1;
    }
    else if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I8_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J negative.\n" );
      exit ( 1 );
    }
    else
    {
      value = 0;
    }
  }
  else if ( j == 0 )
  {
    if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I8_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J = 0.\n" );
      exit ( 1 );
    }
    else
    {
      value = 1;
    }
  }
  else if ( j == 1 )
  {
    value = i;
  }
  else
  {
    value = 1;
    for ( k = 1; k <= j; k++ )
    {
      value = value * i;
    }
  }
  return value;
}
/******************************************************************************/

long long int i8_uniform_ab ( long long int a, long long int b, 
  long long int *seed )

/******************************************************************************/
/*
  Purpose:

    i8_uniform_ab returns a scaled pseudorandom I8.

  Discussion:

    The pseudorandom number should be uniformly distributed
    between A and B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 January 2007

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, long long int A, B, the limits of the interval.

    Input/output, long long int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, long long int i8_uniform_ab, a number between A and B.
*/
{
  int i4_huge = 2147483647;
  long long int k;
  double r;
  long long int value;

  if ( *seed == 0 )
  {
    printf ( "\n" );
    printf ( "i8_uniform_ab - Fatal error!\n" );
    printf ( "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( double ) ( *seed ) * 4.656612875E-10;
/*
  Scale R to lie between A-0.5 and B+0.5.
*/
  r = ( 1.0 - r ) * ( ( double ) ( i8_min ( a, b ) ) - 0.5 ) 
    +         r   * ( ( double ) ( i8_max ( a, b ) ) + 0.5 );
/*
  Use rounding to convert R to an integer between A and B.
*/
  value = r8_nint ( r );

  value = i8_max ( value, i8_min ( a, b ) );
  value = i8_min ( value, i8_max ( a, b ) );

  return value;
}
/******************************************************************************/

unsigned long long int i8_xor ( unsigned long long int i, 
  unsigned long long int j )

/******************************************************************************/
/*
  Purpose:

    I8_XOR calculates the exclusive OR of two I8's.

  Discussion:

    C provides the operator "^" which produces the same result, faster.
    This code is simply provided for illustration.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2010

  Author:

    John Burkardt

  Parameters:

    Input, unsigned long long int I, J, two values whose exclusive OR is needed.

    Output, unsigned long long int I8_XOR, the exclusive OR of I and J.
*/
{
  unsigned long long int i2;
  unsigned long long int j2;
  unsigned long long int k;
  unsigned long long int l;

  k = 0;
  l = 1;

  while ( i != 0 || j != 0 )
  {
    i2 = i / 2;
    j2 = j / 2;

    if ( 
      ( ( i == 2 * i2 ) && ( j != 2 * j2 ) ) ||
      ( ( i != 2 * i2 ) && ( j == 2 * j2 ) ) )
    {
      k = k + l;
    }

    i = i2;
    j = j2;
    l = 2 * l;
  }

  return k;
}
/******************************************************************************/

void i8vec_print ( long long int n, long long int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I8VEC_PRINT prints an I8VEC.

  Discussion:

    An I8VEC is a vector of I8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 August 2017

  Author:

    John Burkardt

  Parameters:

    Input, long long int N, the number of components of the vector.

    Input, long long int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  long long int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %6lld: %8lld\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

int r8_nint ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_NINT returns the nearest integer to an R8.

  Example:

        X         R8_NINT

      1.3         1
      1.4         1
      1.5         1 or 2
      1.6         2
      0.0         0
     -0.7        -1
     -1.1        -1
     -1.6        -2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the value.

    Output, int R8_NINT, the nearest integer to X.
*/
{
  int s;
  int value;

  if ( x < 0.0 )
  {
    s = - 1;
  }
  else
  {
    s = + 1;
  }
  value = s * ( int ) ( fabs ( x ) + 0.5 );

  return value;
}
/******************************************************************************/

double r8i8_uniform_ab ( double a, double b, long long int *seed )

/******************************************************************************/
/*
  Purpose:

    r8i8_uniform_ab returns a scaled pseudorandom R8 using an I8 seed.

  Discussion:

    An R8 is a double precision real value.

    An I8 is an double precision integer value.

    The pseudorandom number should be uniformly distributed
    between A and B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, the limits of the interval.

    Input/output, long long int *SEED, the "seed" value, which should
    NOT be 0.  On output, SEED has been updated.

    Output, double r8i8_uniform_ab, a number strictly between A and B.
*/
{
  long long int k;
  double value;

  if ( seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "r8i8_uniform_ab - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  k = *seed / 127773LL;

  *seed = 16807LL * ( *seed - k * 127773LL ) - k * 2836LL;

  if ( *seed < 0 )
  {
    *seed = *seed + i8_huge ( );
  }

  value = a + ( b - a ) * ( double ) ( *seed ) * 4.656612875E-10;

  return value;
}
/******************************************************************************/

double r8i8_uniform_01 ( long long int *seed )

/******************************************************************************/
/*
  Purpose:

    R8I8_UNIFORM_01 returns a unit pseudorandom R8 using an I8 seed.

  Discussion:

    An R8 is a double precision real value.

    An I8 is an double precision integer value.

    This routine implements the recursion

      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8I8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 June 2010

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input/output, long long int *SEED, the "seed" value, which should
    NOT be 0. On output, SEED has been updated.

    Output, double R8I8_UNIFORM_01, a new pseudorandom variate,
    strictly between 0 and 1.
*/
{
  long long int k;
  double value;

  if ( seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8I8_UNIFORM_01 - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  k = *seed / 127773LL;

  *seed = 16807LL * ( *seed - k * 127773LL ) - k * 2836LL;

  if ( *seed < 0 )
  {
    *seed = *seed + i8_huge ( );
  }

  value = ( double ) ( *seed )  * 4.656612875E-10;

  return value;
}
/******************************************************************************/

void timestamp ( void )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
