# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "unicycle.h"

/******************************************************************************/

int i4_factorial ( int n )

/******************************************************************************/
/*
  Purpose:

    I4_FACTORIAL computes the factorial of N.

  Discussion:

    factorial ( N ) = product ( 1 <= I <= N ) I

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the argument of the factorial function.
    If N is less than 1, the function value is returned as 1.
    0 <= N <= 13 is required.

    Output, int I4_FACTORIAL, the factorial of N.
*/
{
  int i;
  int value;

  value = 1;

  if ( 13 < n )
  {
    fprintf ( stderr, "I4_FACTORIAL - Fatal error!\n" );
    fprintf ( stderr, "  I4_FACTORIAL(N) cannot be computed as an integer\n" );
    fprintf ( stderr, "  for 13 < N.\n" );
    fprintf ( stderr, "  Input value N = %d\n", n );
    exit ( 1 );
  }

  for ( i = 1; i <= n; i++ )
  {
    value = value * i;
  }

  return value;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

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

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

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

int i4_modp ( int i, int j )

/******************************************************************************/
/*
  Purpose:

    I4_MODP returns the nonnegative remainder of I4 division.

  Discussion:

    If
      NREM = I4_MODP ( I, J )
      NMULT = ( I - NREM ) / J
    then
      I = J * NMULT + NREM
    where NREM is always nonnegative.

    The MOD function computes a result with the same sign as the
    quantity being divided.  Thus, suppose you had an angle A,
    and you wanted to ensure that it was between 0 and 360.
    Then mod(A,360) would do, if A was positive, but if A
    was negative, your result would be between -360 and 0.

    On the other hand, I4_MODP(A,360) is between 0 and 360, always.

  Example:

        I         J     MOD  I4_MODP   I4_MODP Factorization

      107        50       7       7    107 =  2 *  50 + 7
      107       -50       7       7    107 = -2 * -50 + 7
     -107        50      -7      43   -107 = -3 *  50 + 43
     -107       -50      -7      43   -107 =  3 * -50 + 43

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 January 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, the number to be divided.

    Input, int J, the number that divides I.

    Output, int I4_MODP, the nonnegative remainder when I is
    divided by J.
*/
{
  int value;

  if ( j == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4_MODP - Fatal error!\n" );
    fprintf ( stderr, "  I4_MODP ( I, J ) called with J = %d\n", j );
    exit ( 1 );
  }

  value = i % j;

  if ( value < 0 )
  {
    value = value + abs ( j );
  }

  return value;
}
/******************************************************************************/

int i4_uniform_ab ( int a, int b, int *seed )

/******************************************************************************/
/*
  Purpose:

    I4_UNIFORM_AB returns a scaled pseudorandom I4 between A and B.

  Discussion:

    The pseudorandom number should be uniformly distributed
    between A and B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 May 2012

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

    Input, int A, B, the limits of the interval.

    Input/output, int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, int I4_UNIFORM_AB, a number between A and B.
*/
{
  int c;
  const int i4_huge = 2147483647;
  int k;
  float r;
  int value;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4_UNIFORM_AB - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }
/*
  Guaranteee A <= B.
*/
  if ( b < a )
  {
    c = a;
    a = b;
    b = c;
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( float ) ( *seed ) * 4.656612875E-10;
/*
  Scale R to lie between A-0.5 and B+0.5.
*/
  r = ( 1.0 - r ) * ( ( float ) ( a ) - 0.5 ) 
    +         r   * ( ( float ) ( b ) + 0.5 );
/*
  Round R to the nearest integer.
*/
  value = round ( r );
/*
  Guarantee that A <= VALUE <= B.
*/
  if ( value < a )
  {
    value = a;
  }
  if ( b < value )
  {
    value = b;
  }

  return value;
}
/******************************************************************************/

int i4_wrap ( int ival, int ilo, int ihi )

/******************************************************************************/
/*
  Purpose:

    I4_WRAP forces an I4 to lie between given limits by wrapping.

  Example:

    ILO = 4, IHI = 8

    I   Value

    -2     8
    -1     4
     0     5
     1     6
     2     7
     3     8
     4     4
     5     5
     6     6
     7     7
     8     8
     9     4
    10     5
    11     6
    12     7
    13     8
    14     4

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int IVAL, an integer value.

    Input, int ILO, IHI, the desired bounds for the integer value.

    Output, int I4_WRAP, a "wrapped" version of IVAL.
*/
{
  int jhi;
  int jlo;
  int value;
  int wide;

  jlo = i4_min ( ilo, ihi );
  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )
  {
    value = jlo;
  }
  else
  {
    value = jlo + i4_modp ( ival - jlo, wide );
  }

  return value;
}
/******************************************************************************/

void i4vec_indicator ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_INDICATOR sets an I4VEC to the indicator vector.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of elements of A.

    Output, int A[N], the initialized array.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a[i] = i + 1;
  }
  return;
}
/******************************************************************************/

int *i4vec_indicator_new ( int n )

/******************************************************************************/
/*
  Purpose:

    I4VEC_INDICATOR_NEW sets an I4VEC to the indicator vector.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of elements of A.

    Output, int I4VEC_INDICATOR_NEW[N], the array.
*/
{
  int *a;
  int i;

  a = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    a[i] = i + 1;
  }
  return a;
}
/******************************************************************************/

void i4vec_reverse ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_REVERSE reverses the elements of an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Example:

    Input:

      N = 5,
      A = ( 11, 12, 13, 14, 15 ).

    Output:

      A = ( 15, 14, 13, 12, 11 ).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 June 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input/output, int A[N], the array to be reversed.
*/
{
  int i;
  int j;

  for ( i = 0; i < n / 2; i++ )
  {
    j        = a[i];
    a[i]     = a[n-1-i];
    a[n-1-i] = j;
  }

  return;
}
/******************************************************************************/

void perm_check ( int n, int p[] )

/******************************************************************************/
/*
  Purpose:

    PERM_CHECK checks that a vector represents a permutation.

  Discussion:

    The routine verifies that each of the integers from 1
    to N occurs among the N entries of the permutation.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries.

    Input, int P[N], the permutation, in standard index form.
*/
{
  int error;
  int ifind;
  int iseek;

  for ( iseek = 1; iseek <= n; iseek++ )
  {
    error = 1;

    for ( ifind = 1; ifind <= n; ifind++ )
    {
      if ( p[ifind-1] == iseek )
      {
        error = 0;
        break;
      }
    }

    if ( error )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "PERM_CHECK - Fatal error!\n" );
      fprintf ( stderr, "  Could not locate the value %d\n", iseek );
      exit ( 1 );
    }
  }

  return;
}
/******************************************************************************/

int perm_enum ( int n )

/******************************************************************************/
/*
  Purpose:

    PERM_ENUM enumerates the permutations on N digits.
 
  Licensing:
 
    This code is distributed under the GNU LGPL license.
 
  Modified:
 
    24 July 2011
 
  Author:
 
    John Burkardt
 
  Parameters:
 
    Input, int N, the number of values being permuted.
    N must be nonnegative.
 
    Output, int PERM_ENUM, the number of distinct elements.
*/ 
{
  int value;

  value = i4_factorial ( n );

  return value;
}
/******************************************************************************/

int *perm_inverse ( int n, int p[] )

/******************************************************************************/
/*
  Purpose:

    PERM_INVERSE computes the inverse of a permutation.
 
  Licensing:
 
    This code is distributed under the GNU LGPL license.
 
  Modified:
 
    25 July 2011
 
  Author:
 
    John Burkardt
 
  Reference:
 
    Donald Kreher, Douglas Simpson,
    Combinatorial Algorithms,
    CRC Press, 1998,
    ISBN: 0-8493-3988-X,
    LC: QA164.K73.
 
  Parameters:
 
    Input, int N, the number of values being permuted.
    N must be positive.
 
    Input, int P[N], describes the permutation.
    P(I) is the item which is permuted into the I-th place
    by the permutation.
 
    Output, int PERM_INVERSE[N], the inverse permutation.
*/ 
{
  int i;
  int *pinv;
/*
  Check.
*/ 
  perm_check ( n, p );

  pinv = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    pinv[p[i]-1] = i + 1;
  }

  return pinv;
}
/******************************************************************************/

int perm_is_unicycle ( int n, int p[] )

/******************************************************************************/
/*
  Purpose:

    PERM_IS_UNICYCLE is TRUE if a permutation is a unicycle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of objects in the permutation.

    Input, int P[N], the permutation.

    Output, int PERM_IS_UNICYCLE, is TRUE if the permutation is a unicycle.
*/
{
  int i;
  int j;
  int value;

  value = 0;

  perm_check ( n, p );
/*
  From 1, you must be able to take N-1 steps without reaching 1...
*/
  i = 1;
  for ( j = 1; j <= n - 1; j++ )
  {
    i = p[i-1];
    if ( i == 1 )
    {
      return value;
    }
  }
/*
  ...and the N-th step must reach 1.
*/
  i = p[i-1];
  if ( i == 1 )
  {
    value = 1;
  }

  return value;
}
/******************************************************************************/

void perm_lex_next ( int n, int p[], int *rank )

/******************************************************************************/
/*
  Purpose:

    PERM_LEX_NEXT computes the lexicographic permutation successor.
 
  Example:
 
    RANK  Permutation
 
       0  1 2 3 4
       1  1 2 4 3
       2  1 3 2 4
       3  1 3 4 2
       4  1 4 2 3
       5  1 4 3 2
       6  2 1 3 4
       ...
      23  4 3 2 1
 
  Licensing:
 
    This code is distributed under the GNU LGPL license.
 
  Modified:
 
    26 July 2011
 
  Author:
 
    John Burkardt
 
  Reference:
 
    Donald Kreher, Douglas Simpson,
    Combinatorial Algorithms,
    CRC Press, 1998,
    ISBN: 0-8493-3988-X,
    LC: QA164.K73.
 
  Parameters:
 
    Input, int N, the number of values being permuted.
    N must be positive.
 
    Input/output, int P[N], describes the permutation.
    P(I) is the item which is permuted into the I-th place
    by the permutation.
 
    Input/output, int *RANK, the rank.
    If RANK = -1 on input, then the routine understands that this is
    the first call, and that the user wishes the routine to supply
    the first element in the ordering, which has RANK = 0.
    In general, the input value of RANK is increased by 1 for output,
    unless the very last element of the ordering was input, in which
    case the output value of RANK is 0.
*/ 
{
  int i;
  int j;
  int temp;
/*
  Return the first element.
*/ 
  if ( *rank == -1 )
  {
    i4vec_indicator ( n, p );
    rank = 0;
    return;
  }
/*
  Check.
*/ 
  perm_check ( n, p );
/* 
  Seek I, the highest index for which the next element is bigger.
*/ 
  i = n - 1;

  for ( ; ; )
  {
    if ( i <= 0 )
    {
      break;
    }

    if ( p[i-1] <= p[i] )
    {
      break;
    }
    i = i - 1;
  }
/*
  If no I could be found, then we have reach the final permutation,
  N, N-1, ..., 2, 1.  Time to start over again.
*/ 
  if ( i == 0 )
  {
    i4vec_indicator ( n, p );
    *rank = -1;
  }
  else
  {
/*
  Otherwise, look for the the highest index after I whose element
  is bigger than I''s.  We know that I+1 is one such value, so the
  loop will never fail.
*/ 
    j = n;
    while ( p[j-1] < p[i-1] )
    {
      j = j - 1;
    }
/*
  Interchange elements I and J.
*/ 
    temp = p[i-1];
    p[i-1] = p[j-1];
    p[j-1] = temp;
/* 
  Reverse the elements from I+1 to N.
*/ 
    i4vec_reverse ( n - i, p+i );

    *rank = *rank + 1;
  }

  return;
}
/******************************************************************************/

int perm_lex_rank ( int n, int p[] )

/******************************************************************************/
/*
  Purpose:

    PERM_LEX_RANK computes the lexicographic rank of a permutation.
 
  Discussion:
 
    The original code altered the input permutation.
 
  Licensing:
 
    This code is distributed under the GNU LGPL license.
 
  Modified:
 
    25 July 2011
 
  Author:
 
    John Burkardt
 
  Reference:
 
    Donald Kreher, Douglas Simpson,
    Combinatorial Algorithms,
    CRC Press, 1998,
    ISBN: 0-8493-3988-X,
    LC: QA164.K73.
 
  Parameters:
 
    Input, int N, the number of values being permuted.
    N must be positive.
 
    Input, int P[N], describes the permutation.
    P[I] is the item which is permuted into the I-th place
    by the permutation.
 
    Output, int PERM_LEX_RANK, the rank of the permutation.
*/ 
{
  int i;
  int j;
  int *pcopy;
  int rank;
/*
  Check.
*/ 
  perm_check ( n, p );

  rank = 0;
  pcopy = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    pcopy[i] = p[i];
  }

  for ( j = 0; j < n; j++ )
  {
    rank = rank + ( pcopy[j] - 1 ) * i4_factorial ( n - 1 - j );
    for ( i = j + 1; i < n; i++ )
    {
      if ( pcopy[j] < pcopy[i] )
      {
        pcopy[i] = pcopy[i] - 1;
      }
    }
  }
  free ( pcopy );

  return rank;
}
/******************************************************************************/

int *perm_lex_unrank ( int n, int rank )

/******************************************************************************/
/*
  Purpose:

    PERM_LEX_UNRANK computes the permutation of given lexicographic rank.
 
  Licensing:
 
    This code is distributed under the GNU LGPL license.
 
  Modified:
 
    17 June 2012
 
  Author:
 
    John Burkardt
 
  Reference:
 
    Donald Kreher, Douglas Simpson,
    Combinatorial Algorithms,
    CRC Press, 1998,
    ISBN: 0-8493-3988-X,
    LC: QA164.K73.
 
  Parameters:
 
    Input, int N, the number of values being permuted.
    N must be positive.
 
    Input, int RANK, the rank of the permutation.
 
    Output, int PERM_LEX_UNRANK[N], describes the permutation.
*/ 
{
  int d;
  int i;
  int j;
  int nperm;
  int *p;
  int rank_copy;
/* 
  Check.
*/ 
  if ( n < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "PERM_LEX_UNRANK - Fatal error!\n" );
    fprintf ( stderr, "  Input N is illegal.\n" );
    exit ( 1 );
  }

  nperm = perm_enum ( n );

  if ( rank < 0 || nperm < rank )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "PERM_LEX_UNRANK - Fatal error!\n" );
    fprintf ( stderr, "  The input rank is illegal.\n" );
    exit ( 1 );
  }

  rank_copy = rank;

  p = ( int * ) malloc ( n * sizeof ( int ) );

  p[n-1] = 1;

  for ( j = 1; j <= n - 1; j++ )
  {
    d = ( rank_copy % i4_factorial ( j + 1 ) ) / i4_factorial ( j );
    rank_copy = rank_copy - d * i4_factorial ( j );
    p[n-j-1] = d + 1;

    for ( i = n - j + 1; i <= n; i++ )
    {
      if ( d < p[i-1] )
      {
        p[i-1] = p[i-1] + 1;
      }
    }
  }
  return p;
}
/******************************************************************************/

void perm_print ( int n, int p[], char *title )

/******************************************************************************/
/*
  Purpose:

    PERM_PRINT prints a permutation.

  Discussion:

    The permutation is assumed to be 0-based.

  Example:

    Input:

      P = 6 1 3 0 4 2 5

    Printed output:

      "This is the permutation:"

      0 1 2 3 4 5 6
      6 1 3 0 4 2 5

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of objects permuted.

    Input, int P[N], the permutation, in standard index form.

    Input, char *TITLE, an optional title.
    If no title is supplied, then only the permutation is printed.
*/
{
  int i;
  int ihi;
  int ilo;
  int inc = 20;

  if ( s_len_trim ( title ) != 0 )
  {
    printf ( "\n" );
    printf ( "%s\n", title );

    for ( ilo = 0; ilo < n; ilo = ilo + inc )
    {
      ihi = ilo + inc;
      if ( n < ihi ) 
      {
        ihi = n;
      }
      printf ( "\n" );
      printf ( "  " );
      for ( i = ilo; i < ihi; i++ )
      {
        printf ( "%4d", i );
      }
      printf ( "\n" );
      printf ( "  " );
      for ( i = ilo; i < ihi; i++ )
      {
        printf ( "%4d", p[i] );
      }
      printf ( "\n" );
    }
  }
  else
  {
    for ( ilo = 0; ilo < n; ilo = ilo + inc )
    {
      ihi = ilo + inc;
      if ( n < ihi ) 
      {
        ihi = n;
      }
      printf ( "  " );
      for ( i = ilo; i < ihi; i++ )
      {
        printf ( "%4d", p[i] );
      }
      printf ( "\n" );
    }
  }

  return;
}
/******************************************************************************/

int *perm_random ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    PERM_RANDOM selects a random permutation of N objects.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 August 2012

  Author:

    Original FORTRAN77 version by Albert Nijenhuis, Herbert Wilf.
    C version by John Burkardt.

  Reference:

    Albert Nijenhuis, Herbert Wilf,
    Combinatorial Algorithms for Computers and Calculators,
    Second Edition,
    Academic Press, 1978,
    ISBN: 0-12-519260-6,
    LC: QA164.N54.

  Parameters:

    Input, int N, the number of objects to be permuted.

    Input/output, int *SEED, a seed for the random number generator.

    Output, int PERM_RANDOM[N], a permutation of (1, 2, ..., N).
*/
{
  int i;
  int j;
  int k;
  int *p;

  p = i4vec_indicator_new ( n );

  for ( i = 0; i < n; i++ )
  {
    j = i4_uniform_ab ( i, n - 1, seed );
    k    = p[i];
    p[i] = p[j];
    p[j] = k;
  }

  return p;
}
/******************************************************************************/

int s_len_trim ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_LEN_TRIM returns the length of a string to the last nonblank.

  Discussion:

    It turns out that I also want to ignore the '\n' character!

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2014

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a pointer to a string.

    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
    If S_LEN_TRIM is 0, then the string is entirely blank.
*/
{
  int n;
  char *t;

  n = strlen ( s );
  t = s + strlen ( s ) - 1;

  while ( 0 < n )
  {
    if ( *t != ' ' && *t != '\n' )
    {
      return n;
    }
    t--;
    n--;
  }

  return n;
}
/******************************************************************************/

void timestamp ( )

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
/******************************************************************************/

void unicycle_check ( int n, int u[] )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_CHECK checks that a vector represents a unicycle.

  Discussion:

    A unicycle is a permutation with a single cycle.  This might be called
    a cyclic permutation, except that that name is used with at least two
    other meanings.  So, to be clear, a unicycle is a permutation of N
    objects in which each object is returned to itself precisely after 
    N applications of the permutation.

    This routine verifies that each of the integers from 1
    to N occurs among the N entries of the permutation.

    Any permutation of the integers 1 to N describes a unicycle.
    The permutation ( 3, 4, 2, 1 ) indicates that the unicycle
    sends 3 to 4, 4 to 2, 2 to 1 and 1 to 3.  This is the sequential
    description of a unicycle.

    The standard sequence "rotates" the permutation so that it begins
    with 1.  The above sequence becomes a standard sequence when
    written as ( 1, 3, 4, 2 ).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries.

    Input, int U[N], the unicycle sequence vector
*/
{
  int error;
  int i;
  int iseek;

  for ( iseek = 1; iseek <= n; iseek++ )
  {
    error = 1;

    for ( i = 0; i < n; i++ )
    {
      if ( u[i] == iseek )
      {
        error = 0;
        break;
      }
    }

    if ( error )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "UNICYCLE_CHECK - Fatal error!\n" );
      fprintf ( stderr, "  The input array does not represent\n" );
      fprintf ( stderr, "  a unicycle.  In particular, the\n" );
      fprintf ( stderr, "  array is missing the value %d\n", iseek );
      exit ( 1 );
    }
  }
  return;
}
/******************************************************************************/

int unicycle_enum ( int n )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_ENUM enumerates the unicycles.

  Discussion:

    Each standard sequence corresponds to a unique unicycle.  Since the
    first element of a standard sequence is always 1, the number of standard
    sequences, and hence the number of unicycles, is (n-1)!.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicyle.

    Output, int UNICYCLE_ENUM, the number of unicycles.
*/
{
  int num;

  num = i4_factorial ( n - 1 );

  return num;
}
/******************************************************************************/

int *unicycle_index ( int n, int u[] )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_INDEX returns the index form of a unicycle.

  Example:

    N = 4

    U       = 1 3 4 2
    U_INDEX = 3 1 4 2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicycles.

    Input, int U[N], the unicycle sequence vector.

    Output, int UNICYCLE_INDEX[N], the unicycle index vector.
*/
{
  int i;
  int ip1;
  int *u_index;

  u_index = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    ip1 = i4_wrap ( i + 1, 0, n - 1 );
    u_index[u[i]-1] = u[ip1];
  }
  
  return u_index;
}
/******************************************************************************/

void unicycle_index_print ( int n, int u_index[], char *title )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_INDEX_PRINT prints a unicycle given in index form.

  Example:

    Input:

      U_INDEX = 7 1 4 5 2 3 6

    Printed output:

      1 2 3 4 5 6 7
      7 1 4 5 2 3 6

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicycle.

    Input, int U_INDEX(N), the unicycle index vector.

    Input, char *TITLE, a title.
*/
{
  int i;
  int ihi;
  int ilo;
  int inc = 20;

  if ( 0 < s_len_trim ( title ) )
  {
    printf ( "\n" );
    printf ( "%s\n", title );
  }

  for ( ilo = 0; ilo < n; ilo = ilo + inc )
  {
    ihi = i4_min ( n, ilo + inc - 1 );
    printf ( "\n" );
    printf ( "  " );
    for ( i = ilo; i < ihi; i++ )
    {
      printf ( "%4d", i + 1 );
    }
    printf ( "\n" );
    printf ( "  " );
    for ( i = ilo; i < ihi; i++ )
    {
      printf ( "%4d", u_index[i] );
    }
    printf ( "\n" );
  }
  return;
}
/******************************************************************************/

int *unicycle_index_to_sequence ( int n, int u_index[] )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_INDEX_TO_SEQUENCE converts a unicycle from index to sequence form.

  Example:

    N = 4

    U_INDEX = 3 1 4 2
    U       = 1 3 4 2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicycles.

    Output, int U_INDEX(N), the unicycle index vector.

    Input, int U(N), the unicycle sequence vector.
*/
{
  int i;
  int j;
  int *u;

  u = ( int * ) malloc ( n * sizeof ( int ) );

  u[0] = 1;
  i = 1;

  for ( j = 1; j < n; j++ )
  {
    i = u_index[i-1];
    u[j] = i;

    if ( i == 1 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "UNICYCLE_INDEX_TO_SEQUENCE - Fatal error!\n" );
      fprintf ( stderr, "  The index vector does not represent a unicycle.\n" );
      fprintf ( stderr, "  On step %d, u_index(%d) = 1.\n", j, i );
      exit ( 1 );
    }
  }
  
  return u;
}
/******************************************************************************/

int *unicycle_inverse ( int n, int u[] )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_INVERSE returns the inverse of a unicycle.

  Example:

    N = 4

    U         = 1 3 4 2
    U_INVERSE = 1 2 4 3

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicycles.

    Input, int U[N], the unicycle sequence vector.

    Output, int UNICYCLE_INVERSE[N], the inverse unicycle.
*/
{
  int i;
  int *u_inverse;

  u_inverse = ( int * ) malloc ( n * sizeof ( int ) );

  u_inverse[0] = 1;
  for ( i = 1; i < n; i++ )
  {
    u_inverse[i] = u[n-i];
  }
  return u_inverse;
}
/******************************************************************************/

void unicycle_next ( int n, int u[], int *rank )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_NEXT generates unicycles in lexical order, one at a time.

  Example:

    N = 4

    1   1 2 3 4
    2   1 2 4 3
    3   1 3 2 4
    4   1 3 4 2
    5   1 4 2 3
    6   1 4 3 2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicycles.

    Input/output, int U[N]; on first call with MORE = FALSE,
    this value is not used.  Otherwise, the input value is the previous
    unicycle.  The output value is the next unicycle.

    Input/output, int *RANK, the rank.
    If RANK = -1 on input, then the routine understands that this is
    the first call, and that the user wishes the routine to supply
    the first element in the ordering, which has RANK = 0.
    In general, the input value of RANK is increased by 1 for output,
    unless the very last element of the ordering was input, in which
    case the output value of RANK is -1.
*/
{
  int i;
  int *p;

  p = ( int * ) malloc ( ( n - 1 ) * sizeof ( int ) );

  if ( *rank == -1 )
  {
    u[0] = 1;
  }
  else
  {
    for ( i = 0; i < n - 1; i++ )
    {
      p[i] = u[i+1] - 1;
    }
  }

  perm_lex_next ( n - 1, p, rank );
 
  for ( i = 0; i < n - 1; i++ )
  {
    u[i+1] = p[i] + 1;
  }
  free ( p );

  return;
}
/******************************************************************************/

void unicycle_print ( int n, int u[], char *title )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_PRINT prints a unicycle given in sequence form.

  Example:

    Input:

      U = 7 1 4 5 2 3 6

    Printed output:

      7 1 4 5 2 3 6

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the unicycle.

    Input, int U[N], the unicycle sequence vector.

    Input, char *TITLE, a title.
*/
{
  int i;
  int ihi;
  int ilo;
  int inc = 20;

  if ( s_len_trim ( title ) != 0 )
  {
    printf ( "\n" );
    printf ( "%s\n", title );
    printf ( "\n" );
  }

  for ( ilo = 0; ilo < n; ilo = ilo + inc )
  {
    ihi = ilo + inc;
    if ( n < ihi ) 
    {
      ihi = n;
    }
    printf ( "  " );
    for ( i = ilo; i < ihi; i++ )
    {
      printf ( "%4d", u[i] );
    }
    printf ( "\n" );
  }
  return;
}
/******************************************************************************/

int *unicycle_random ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_RANDOM selects a random unicycle of N objects.

  Discussion:

    The routine assumes the objects are labeled 1, 2, ... N.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt.

  Reference:

    Albert Nijenhuis, Herbert Wilf,
    Combinatorial Algorithms for Computers and Calculators,
    Second Edition,
    Academic Press, 1978,
    ISBN: 0-12-519260-6,
    LC: QA164.N54.

  Parameters:

    Input, int N, the number of objects to be permuted.

    Input/output, int *SEED, a seed for the random number
    generator.

    Output, int UNICYCLE_RANDOM[N], a unicycle in sequence form.
*/
{
  int i;
  int j;
  int *u;
  int t;

  u = i4vec_indicator_new ( n );

  for ( i = 1; i < n; i++ )
  {
    j = i4_uniform_ab ( i, n - 1, seed );
    t = u[i];
    u[i] = u[j];
    u[j] = t;
  }

  return u;
}
/******************************************************************************/

int unicycle_rank ( int n, int u[] )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_RANK computes the rank of a unicycle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt.

  Parameters:

    Input, int N, the order of the unicycle.

    Input, int U[N], a unicycle in sequence form.

    Output, int UNICYLE_RANK, the rank of the unicycle.
*/
{
  int i;
  int *p;
  int rank;

  p = ( int * ) malloc ( ( n - 1 ) * sizeof ( int ) );

  for ( i = 0; i < n - 1; i++ )
  {
    p[i] = u[i+1] - 1;
  }

  rank = perm_lex_rank ( n - 1, p );

  free ( p );

  return rank;
}
/******************************************************************************/

int *unicycle_unrank ( int n, int rank )

/******************************************************************************/
/*
  Purpose:

    UNICYCLE_UNRANK "unranks" a unicycle.

  Discussion:

    That is, given a rank, it computes the corresponding unicycle.

    The value of the rank should be between 0 and (N-1)!-1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 June 2012

  Author:

    John Burkardt.

  Reference:

    Dennis Stanton, Dennis White,
    Constructive Combinatorics,
    Springer, 1986,
    ISBN: 0387963472,
    LC: QA164.S79.

  Parameters:

    Input, int N, the number of elements in the set.

    Input, int RANK, the desired rank of the permutation.

    Output, int UNICYCLE_UNRANK[N], the unicycle.
*/
{
  int i;
  int *p;
  int *u;

  p = perm_lex_unrank ( n - 1, rank );

  u = ( int * ) malloc ( n * sizeof ( int ) );

  u[0] = 1;
  for ( i = 0; i < n - 1; i++ )
  {
    u[i+1] = p[i] + 1;
  }
  free ( p );

  return u;
}
