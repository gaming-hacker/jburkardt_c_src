# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "hermite_product_polynomial.h"

/******************************************************************************/

int comp_enum ( int n, int k )

/******************************************************************************/
/*
  Purpose:

    COMP_ENUM returns the number of compositions of the integer N into K parts.

  Discussion:

    A composition of the integer N into K parts is an ordered sequence
    of K nonnegative integers which sum to N.  The compositions (1,2,1)
    and (1,1,2) are considered to be distinct.

    The 28 compositions of 6 into three parts are:

      6 0 0,  5 1 0,  5 0 1,  4 2 0,  4 1 1,  4 0 2,
      3 3 0,  3 2 1,  3 1 2,  3 0 3,  2 4 0,  2 3 1,
      2 2 2,  2 1 3,  2 0 4,  1 5 0,  1 4 1,  1 3 2,
      1 2 3,  1 1 4,  1 0 5,  0 6 0,  0 5 1,  0 4 2,
      0 3 3,  0 2 4,  0 1 5,  0 0 6.

    The formula for the number of compositions of N into K parts is

      Number = ( N + K - 1 )! / ( N! * ( K - 1 )! )

    Describe the composition using N '1's and K-1 dividing lines '|'.
    The number of distinct permutations of these symbols is the number
    of compositions.  This is equal to the number of permutations of
    N+K-1 things, with N identical of one kind and K-1 identical of another.

    Thus, for the above example, we have:

      Number = ( 6 + 3 - 1 )! / ( 6! * (3-1)! ) = 28

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 December 2013

  Author:

    John Burkardt

  Reference:

    Albert Nijenhuis, Herbert Wilf,
    Combinatorial Algorithms for Computers and Calculators,
    Second Edition,
    Academic Press, 1978,
    ISBN: 0-12-519260-6,
    LC: QA164.N54.

  Parameters:

    Input, integer ( kind = 4 ) N, the integer whose compositions are desired.

    Input, integer ( kind = 4 ) K, the number of parts in the composition.

    Output, int COMP_ENUM, the number of compositions of N
    into K parts.
*/
{
  int number;

  number = i4_choose ( n + k - 1, n );

  return number;
}
/******************************************************************************/

void comp_next_grlex ( int kc, int xc[] )

/******************************************************************************/
/*
  Purpose:

    COMP_NEXT_GRLEX returns the next composition in grlex order.

  Discussion:

    Example:

    KC = 3

    #   XC(1) XC(2) XC(3)  Degree
      +------------------------
    1 |  0     0     0        0
      |
    2 |  0     0     1        1
    3 |  0     1     0        1
    4 |  1     0     0        1
      |
    5 |  0     0     2        2
    6 |  0     1     1        2
    7 |  0     2     0        2
    8 |  1     0     1        2
    9 |  1     1     0        2
   10 |  2     0     0        2
      |
   11 |  0     0     3        3
   12 |  0     1     2        3
   13 |  0     2     1        3
   14 |  0     3     0        3
   15 |  1     0     2        3
   16 |  1     1     1        3
   17 |  1     2     0        3
   18 |  2     0     1        3
   19 |  2     1     0        3
   20 |  3     0     0        3

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int KC, the number of parts of the composition.
    1 <= KC.

    Input/output, int XC[KC], the current composition.
    Each entry of XC must be nonnegative.
    On return, XC has been replaced by the next composition in the
    grlex order.
*/
{
  int i;
  int im1;
  int j;
  int t;
/*
  Ensure that 1 <= KC.
*/
  if ( kc < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_NEXT_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  KC < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that 0 <= XC(I).
*/
  for ( i = 0; i < kc; i++ )
  {
    if ( xc[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "COMP_NEXT_GRLEX - Fatal error!\n" );
      fprintf ( stderr, "  XC[I] < 0\n" );
      exit ( 1 );
    }
  }
/*
  Find I, the index of the rightmost nonzero entry of X.
*/
  i = 0;
  for ( j = kc; 1 <= j; j-- )
  {
    if ( 0 < xc[j-1] )
    {
      i = j;
      break;
    }
  }
/*
  set T = X(I)
  set XC(I) to zero,
  increase XC(I-1) by 1,
  increment XC(KC) by T-1.
*/
  if ( i == 0 )
  {
    xc[kc-1] = 1;
    return;
  }
  else if ( i == 1 )
  {
    t = xc[0] + 1;
    im1 = kc;
  }
  else if ( 1 < i )
  {
    t = xc[i-1];
    im1 = i - 1;
  }

  xc[i-1] = 0;
  xc[im1-1] = xc[im1-1] + 1;
  xc[kc-1] = xc[kc-1] + t - 1;

  return;
}
/******************************************************************************/

int *comp_random_grlex ( int kc, int rank1, int rank2, int *seed, int *rank )

/******************************************************************************/
/*
  Purpose:

    COMP_RANDOM_GRLEX: random composition with degree less than or equal to NC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int KC, the number of parts in the composition.

    Input, int RANK1, RANK2, the minimum and maximum ranks.
    1 <= RANK1 <= RANK2.

    Input/output, int *SEED, the random number seed.

    Output, int *RANK, the rank of the composition.

    Output, int COMP_RANDOM_GRLEX[KC], the random composition.
*/
{
  int *xc;
/*
  Ensure that 1 <= KC.
*/
  if ( kc < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_RANDOM_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  KC < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that 1 <= RANK1.
*/
  if ( rank1 < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_RANDOM_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  RANK1 < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that RANK1 <= RANK2.
*/
  if ( rank2 < rank1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_RANDOM_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  RANK2 < RANK1\n" );
    exit ( 1 );
  }
/*
  Choose RANK between RANK1 and RANK2.
*/
  *rank = i4_uniform_ab ( rank1, rank2, seed );
/*
  Recover the composition of given RANK.
*/
  xc = comp_unrank_grlex ( kc, *rank );

  return xc;
}
/******************************************************************************/

int comp_rank_grlex ( int kc, int xc[] )

/******************************************************************************/
/*
  Purpose:

    COMP_RANK_GRLEX computes the graded lexicographic rank of a composition.

  Discussion:

    The graded lexicographic ordering is used, over all KC-compositions
    for NC = 0, 1, 2, ...

    For example, if KC = 3, the ranking begins:

    Rank  Sum    1  2  3
    ----  ---   -- -- --
       1    0    0  0  0

       2    1    0  0  1
       3    1    0  1  0
       4    1    1  0  1

       5    2    0  0  2
       6    2    0  1  1
       7    2    0  2  0
       8    2    1  0  1
       9    2    1  1  0
      10    2    2  0  0

      11    3    0  0  3
      12    3    0  1  2
      13    3    0  2  1
      14    3    0  3  0
      15    3    1  0  2
      16    3    1  1  1
      17    3    1  2  0
      18    3    2  0  1
      19    3    2  1  0
      20    3    3  0  0

      21    4    0  0  4
      ..   ..   .. .. ..

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int KC, the number of parts in the composition.
    1 <= KC.

    Input, int XC[KC], the composition.
    For each 1 <= I <= KC, we have 0 <= XC(I).

    Output, int COMP_RANK_GRLEX, the rank of the composition.
*/
{
  int i;
  int j;
  int ks;
  int n;
  int nc;
  int ns;
  int rank;
  int tim1;
  int *xs;
/*
  Ensure that 1 <= KC.
*/
  if ( kc < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_RANK_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  KC < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that 0 <= XC(I).
*/
  for ( i = 0; i < kc; i++ )
  {
    if ( xc[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "COMP_RANK_GRLEX - Fatal error!\n" );
      fprintf ( stderr, "  XC[I] < 0\n" );
      exit ( 1 );
    }
  }
/*
  NC = sum ( XC )
*/
  nc = i4vec_sum ( kc, xc );
/*
  Convert to KSUBSET format.
*/
  ns = nc + kc - 1;
  ks = kc - 1;
  xs = ( int * ) malloc ( ks * sizeof ( int ) );
  xs[0] = xc[0] + 1;
  for ( i = 2; i < kc; i++ )
  {
    xs[i-1] = xs[i-2] + xc[i-1] + 1;
  }
/*
  Compute the rank.
*/
  rank = 1;

  for ( i = 1; i <= ks; i++ )
  {
    if ( i == 1 )
    {
      tim1 = 0;
    }
    else
    {
      tim1 = xs[i-2];
    }

    if ( tim1 + 1 <= xs[i-1] - 1 )
    {
      for ( j = tim1 + 1; j <= xs[i-1] - 1; j++ )
      {
        rank = rank + i4_choose ( ns - j, ks - i );
      }
    }
  }

  for ( n = 0; n < nc; n++ )
  {
    rank = rank + i4_choose ( n + kc - 1, n );
  }

  free ( xs );

  return rank;
}
/******************************************************************************/

int *comp_unrank_grlex ( int kc, int rank )

/******************************************************************************/
/*
  Purpose:

    COMP_UNRANK_GRLEX computes the composition of given grlex rank.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int KC, the number of parts of the composition.
    1 <= KC.

    Input, int RANK, the rank of the composition.
    1 <= RANK.

    Output, int COMP_UNRANK_GRLEX[KC], the composition XC of the given rank.
    For each I, 0 <= XC[I] <= NC, and 
    sum ( 1 <= I <= KC ) XC[I] = NC.
*/
{
  int i;
  int j;
  int ks;
  int nc;
  int ns;
  int r;
  int rank1;
  int rank2;
  int *xc;
  int *xs;
/*
  Ensure that 1 <= KC.
*/
  if ( kc < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_UNRANK_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  KC < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that 1 <= RANK.
*/
  if ( rank < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COMP_UNRANK_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  RANK < 1\n" );
    exit ( 1 );
  }
/*
  Determine the appropriate value of NC.
  Do this by adding up the number of compositions of sum 0, 1, 2, 
  ..., without exceeding RANK.  Moreover, RANK - this sum essentially
  gives you the rank of the composition within the set of compositions
  of sum NC.  And that's the number you need in order to do the
  unranking.
*/
  rank1 = 1;
  nc = -1;
  for ( ; ; )
  {
    nc = nc + 1;
    r = i4_choose ( nc + kc - 1, nc );
    if ( rank < rank1 + r )
    {
      break;
    }
    rank1 = rank1 + r;
  }

  rank2 = rank - rank1;
/*
  Convert to KSUBSET format.
  Apology: an unranking algorithm was available for KSUBSETS,
  but not immediately for compositions.  One day we will come back
  and simplify all this.
*/
  ks = kc - 1;
  ns = nc + kc - 1;
  xs = ( int * ) malloc ( ks * sizeof ( int ) );

  j = 1;

  for ( i = 1; i <= ks; i++ )
  {
    r = i4_choose ( ns - j, ks - i );

    while ( r <= rank2 && 0 < r )
    {
      rank2 = rank2 - r;
      j = j + 1;
      r = i4_choose ( ns - j, ks - i );
    }
    xs[i-1] = j;
    j = j + 1;
  }
/*
  Convert from KSUBSET format to COMP format.
*/
  xc = ( int * ) malloc ( kc * sizeof ( int ) );
  xc[0] = xs[0] - 1;
  for ( i = 2; i < kc; i++ )
  {
    xc[i-1] = xs[i-1] - xs[i-2] - 1;
  }
  xc[kc-1] = ns - xs[ks-1];

  free ( xs );

  return xc;
}
/******************************************************************************/

void hep_coefficients ( int n, int *o, double c[], int f[] )

/******************************************************************************/
/*
  Purpose:

    HEP_COEFFICIENTS: coefficients of Hermite polynomials He(n,x).

  Discussion:

    He(i,x) represents the probabilist's Hermite polynomial.

  First terms:

    N/K     0     1      2      3       4     5      6    7      8    9   10

     0      1
     1      0     1
     2     -1     0      1
     3      0    -3      0      1
     4      3     0     -6      0       1
     5      0    15      0    -10       0     1
     6    -15     0     45      0     -15     0      1
     7      0  -105      0    105       0   -21      0     1
     8    105     0   -420      0     210     0    -28     0      1
     9      0   945      0  -1260       0   378      0   -36      0   1
    10   -945     0   4725      0   -3150     0    630     0    -45   0    1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 October 2014

  Author:

    John Burkardt

  Reference:

    Milton Abramowitz, Irene Stegun,
    Handbook of Mathematical Functions,
    National Bureau of Standards, 1964,
    ISBN: 0-486-61272-4,
    LC: QA47.A34.

    Daniel Zwillinger, editor,
    CRC Standard Mathematical Tables and Formulae,
    30th Edition,
    CRC Press, 1996.

  Parameters:

    Input, int N, the highest order polynomial to evaluate.
    Note that polynomials 0 through N will be evaluated.

    Output, int *O, the number of coefficients.

    Output, double C[(N+2)/2], the coefficients of the Hermite
    polynomial of degree N.

    Output, int F[(N+2)/2], the exponents.
*/
{
  double *ct;
  int i;
  int j;
  int k;

  ct = ( double * ) malloc ( (n+1)*(n+1) * sizeof ( double ) );;

  for ( i = 0; i <= n; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      ct[i+j*(n+1)] = 0.0;
    }
  }

  ct[0+0*(n+1)] = 1.0;

  if ( 0 < n )
  {
    ct[1+1*(n+1)] = 1.0;

    for ( i = 2; i <= n; i++ )
    {
      ct[i+0*(n+1)] =                       - ( double ) ( i - 1 ) * ct[i-2+0*(n+1)];
      for ( j = 1; j <= i - 2; j++ )
      {
        ct[i+j*(n+1)] = ct[i-1+(j-1)*(n+1)] - ( double ) ( i - 1 ) * ct[i-2+j*(n+1)];
      }
      ct[i+(i-1)*(n+1)] =   ct[i-1+(i-2)*(n+1)];
      ct[i+ i   *(n+1)] =   ct[i-1+(i-1)*(n+1)];
    }
  }
/*
  Extract the nonzero data from the alternating columns of the last row.
*/
  *o = ( n + 2 ) / 2;

  k = *o;
  for ( j = n; 0 <= j; j = j - 2 )
  {
    k = k - 1;
    c[k] = ct[n+j*(n+1)];
    f[k] = j;
  }

  free ( ct );

  return;
}
/******************************************************************************/

double *hep_value ( int n, int o, double x[] )

/******************************************************************************/
/*
  Purpose:

    HEP_VALUE evaluates the Hermite polynomials He(i,x).

  Discussion:

    He(i,x) represents the probabilist's Hermite polynomial.

    1
    X
    X^2  -  1
    X^3  -  3 X
    X^4  -  6 X^2 +   3
    X^5  - 10 X^3 +  15 X
    X^6  - 15 X^4 +  45 X^2 -   15
    X^7  - 21 X^5 + 105 X^3 -  105 X
    X^8  - 28 X^6 + 210 X^4 -  420 X^2 +  105
    X^9  - 36 X^7 + 378 X^5 - 1260 X^3 +  945 X
    X^10 - 45 X^8 + 630 X^6 - 3150 X^4 + 4725 X^2 - 945

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2013

  Author:

    John Burkardt

  Reference:

    Milton Abramowitz, Irene Stegun,
    Handbook of Mathematical Functions,
    National Bureau of Standards, 1964,
    ISBN: 0-486-61272-4,
    LC: QA47.A34.

    Daniel Zwillinger, editor,
    CRC Standard Mathematical Tables and Formulae,
    30th Edition,
    CRC Press, 1996.

  Parameters:

    Input, int N, the number of evaluation points.

    Input, int O, the degree of the polynomial.

    Input, double X[N], the evaluation points.

    Output, double HEP_VALUE[N], the value of the Hermite polynomial 
    of degree N at the points X.
*/
{
  int i;
  int j;
  double *v;
  double *vtable;

  vtable = ( double * ) malloc ( n*(o+1) * sizeof ( double ) );;

  for ( i = 0; i < n; i++ )
  {
    vtable[i+0*n] = 1.0;
  }

  if ( 1 <= o )
  {
    for ( i = 0; i < n; i++ )
    {
      vtable[i+1*n] = x[i];
    }

    for ( j = 2; j <= o; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        vtable[i+j*n] = x[i] * vtable[i+(j-1)*n] 
          - ( double ) ( j - 1 ) * vtable[i+(j-2)*n];
      }
    }
  }

  v = ( double * ) malloc ( n * sizeof ( double ) );;

  for ( i = 0; i < n; i++ )
  {
    v[i] = vtable[i+o*n];
  }

  free ( vtable );

  return v;
}
/******************************************************************************/

void hep_values ( int *n_data, int *n, double *x, double *fx )

/******************************************************************************/
/*
  Purpose:

    HEP_VALUES returns values of the Hermite polynomials He(n,x).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2013

  Author:

    John Burkardt

  Reference:

    Milton Abramowitz, Irene Stegun,
    Handbook of Mathematical Functions,
    National Bureau of Standards, 1964,
    ISBN: 0-486-61272-4,
    LC: QA47.A34.

    Stephen Wolfram,
    The Mathematica Book,
    Fourth Edition,
    Cambridge University Press, 1999,
    ISBN: 0-521-64314-7,
    LC: QA76.95.W65.

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, int *N, the order of the function.

    Output, double *X, the point where the function is evaluated.

    Output, double *FX, the value of the function.
*/
{
# define N_MAX 18

  static double fx_vec[N_MAX] = {
    1.000000000000000E+00,
    5.000000000000000E+00,
    24.00000000000000E+00,
    110.0000000000000E+00,
    478.0000000000000E+00,
    1950.000000000000E+00,
    7360.000000000000E+00,
    25100.00000000000E+00,
    73980.00000000000E+00,
    169100.0000000000E+00,
    179680.0000000000E+00,
   -792600.0000000000E+00,
   -5939480.000000000E+00,
    0.000000000000000E+00,
    6.281250000000000E+00,
    6.000000000000000E+00,
    18.00000000000000E+00,
    90150.00000000000E+00 };

  static int n_vec[N_MAX] = {
     0,  1,  2,
     3,  4,  5,
     6,  7,  8,
     9, 10, 11,
    12,  5,  5,
     5,  5,  5 };

  static double x_vec[N_MAX] = {
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     5.0E+00,
     0.0E+00,
     0.5E+00,
     1.0E+00,
     3.0E+00,
     1.0E+01 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *n = 0;
    *x = 0.0;
    *fx = 0.0;
  }
  else
  {
    *n = n_vec[*n_data-1];
    *x = x_vec[*n_data-1];
    *fx = fx_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void hepp_to_polynomial ( int m, int l[], int o_max, int *o, double c[], int e[] )

/******************************************************************************/
/*
  Purpose:

    HEPP_TO_POLYNOMIAL writes a Hermite Product Polynomial as a polynomial.

  Discussion:

    He(i,x) represents the probabilist's Hermite polynomial.

    For example, if 
      M = 3,
      L = ( 1, 0, 2 ),
    then
      He(1,0,2)(X,Y,Z) 
      = He(1)(X) * He(0)(Y) * He(2)(Z)
      = X * 1 * ( Z^3-3Z)
      = - 3XZ + X Z^3
    so
      O = 2 (2 nonzero terms)
      C = -3.0
           1.0
      E =  8   <-- index in 3-space of exponent (1,0,1)
          23   <-- index in 3-space of exponent (1,0,3)

    The output value of O is no greater than
      O_MAX = product ( 1 <= I <= M ) (L(I)+2)/2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int L[M], the index of each Hermite product 
    polynomial factor.  0 <= L(*).

    Input, int O_MAX, an upper limit on the size of the 
    output arrays.
      O_MAX = product ( 1 <= I <= M ) (L(I)+2)/2.

    Output, int *O, the "order" of the polynomial product.

    Output, double C[O], the coefficients of the polynomial product.

    Output, int E[O], the indices of the exponents of the 
    polynomial product.
*/
{
  double *c1;
  double *c2;
  int *e1;
  int *e2;
  int *f2;
  int i;
  int i1;
  int i2;
  int j1;
  int j2;
  int o1;
  int o2;
  int *p;
  int *pp;

  c1 = ( double * ) malloc ( o_max * sizeof ( double ) );
  c2 = ( double * ) malloc ( o_max * sizeof ( double ) );
  e1 = ( int * ) malloc ( o_max * sizeof ( int ) );
  e2 = ( int * ) malloc ( o_max * sizeof ( int ) );
  f2 = ( int * ) malloc ( o_max * sizeof ( int ) );
  pp = ( int * ) malloc ( m * sizeof ( int ) );

  o1 = 1;
  c1[0] = 1.0;
  e1[0] = 1;
/*
  Implicate one factor at a time.
*/
  for ( i = 0; i < m; i++ )
  {
    hep_coefficients ( l[i], &o2, c2, f2 );
 
    *o = 0;

    for ( j2 = 0; j2 < o2; j2++ )
    {
      for ( j1 = 0; j1 < o1; j1++ )
      {
        c[*o] = c1[j1] * c2[j2];
        if ( 0 < i )
        {
          p = mono_unrank_grlex ( i, e1[j1] );
        }
        for ( i2 = 0; i2 < i; i2++ )
        {
          pp[i2] = p[i2];
        }
        pp[i] = f2[j2];
        e[*o] = mono_rank_grlex ( i + 1, pp );
        *o = *o + 1;
        if ( 0 < i )
        {
          free ( p );
        }
      }
    }

    polynomial_sort ( *o, c, e );
    polynomial_compress ( *o, c, e, o, c, e );

    o1 = *o;
    for ( i1 = 0; i1 < *o; i1++ )
    {
      c1[i1] = c[i1];
      e1[i1] = e[i1];
    }
  }

  free ( c1 );
  free ( c2 );
  free ( e1 );
  free ( e2 );
  free ( f2 );
  free ( pp );

  return;
}
/******************************************************************************/

double *hepp_value ( int m, int n, int o[], double x[] )

/******************************************************************************/
/*
  Purpose:

    HEPP_VALUE evaluates a Hermite Product Polynomial.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int N, the number of evaluation points.

    Input, int O[M], the degree of the polynomial factors.
    0 <= O(*).

    Input, double X[M*N], the evaluation points.

    Output, double HEPP_VALUE[N], the value of the Hermite Product 
    Polynomial of degree O at the points X.
*/
{
  int i;
  int j;
  double *v;
  double *vi;
  double *xi;

  v = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    v[j] = 1.0;
  }

  xi = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      xi[j] = x[i+j*m];
    }
    vi = hep_value ( n, o[i], xi );
    for ( j = 0; j < n; j++ )
    {
      v[j] = v[j] * vi[j];
    }
    free ( vi );
  }

  free ( xi );

  return v;
}
/******************************************************************************/

int i4_choose ( int n, int k )

/******************************************************************************/
/*
  Purpose:

    I4_CHOOSE computes the binomial coefficient C(N,K).

  Discussion:

    The value is calculated in such a way as to avoid overflow and
    roundoff.  The calculation is done in integer arithmetic.

    The formula used is:

      C(N,K) = N! / ( K! * (N-K)! )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 May 2008

  Author:

    John Burkardt

  Reference:

    ML Wolfson, HV Wright,
    Algorithm 160:
    Combinatorial of M Things Taken N at a Time,
    Communications of the ACM,
    Volume 6, Number 4, April 1963, page 161.

  Parameters:

    Input, int N, K, are the values of N and K.

    Output, int I4_CHOOSE, the number of combinations of N
    things taken K at a time.
*/
{
  int i;
  int mn;
  int mx;
  int value;

  mn = i4_min ( k, n - k );

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
    mx = i4_max ( k, n - k );
    value = mx + 1;

    for ( i = 2; i <= mn; i++ )
    {
      value = ( value * ( mx + i ) ) / i;
    }
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

void i4vec_permute ( int n, int p[], int base, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PERMUTE permutes an I4VEC in place.

  Discussion:

    An I4VEC is a vector of I4's.

    This routine permutes an array of integer "objects", but the same
    logic can be used to permute an array of objects of any arithmetic
    type, or an array of objects of any complexity.  The only temporary
    storage required is enough to store a single object.  The number
    of data movements made is N + the number of cycles of order 2 or more,
    which is never more than N + N/2.

  Example:

    Input:

      N = 5
      P = (   1,   3,   4,   0,   2 )
      A = (   1,   2,   3,   4,   5 )

    Output:

      A    = (   2,   4,   5,   1,   3 ).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of objects.

    Input, int P[N], the permutation.  P(I) = J means
    that the I-th element of the output array should be the J-th
    element of the input array.

    Input, int BASE, the base, which is 0 or 1.

    Input/output, int A[N], the array to be permuted.
*/
{
  int a_temp;
  int i;
  int iget;
  int iput;
  int istart;

  if ( !perm_check ( n, p, base ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4VEC_PERMUTE - Fatal error!\n" );
    fprintf ( stderr, "  PERM_CHECK rejects this permutation.\n" );
    exit ( 1 );
  }
/*
  In order for the sign negation trick to work, we need to assume that the
  entries of P are strictly positive.  Presumably, the lowest number is BASE.
  So temporarily add 1 to each entry to force positivity.
*/
  for ( i = 0; i < n; i++ )
  {
    p[i] = p[i] + 1;
  }
/*
  Search for the next element of the permutation that has not been used.
*/
  for ( istart = 1; istart <= n; istart++ )
  {
    if ( p[istart-1] < 0 )
    {
      continue;
    }
    else if ( p[istart-1] == istart )
    {
      p[istart-1] = - p[istart-1];
      continue;
    }
    else
    {
      a_temp = a[istart-1];
      iget = istart;
/*
  Copy the new value into the vacated entry.
*/
      for ( ; ; )
      {
        iput = iget;
        iget = p[iget-1];

        p[iput-1] = - p[iput-1];

        if ( iget < 1 || n < iget )
        {
          fprintf ( stderr, "\n" );
          fprintf ( stderr, "I4VEC_PERMUTE - Fatal error!\n" );
          fprintf ( stderr, "  Entry IPUT = %d of the permutation has\n", iput );
          fprintf ( stderr, "  an illegal value IGET = %d.\n", iget );
          exit ( 1 );
        }

        if ( iget == istart )
        {
          a[iput-1] = a_temp;
          break;
        }
        a[iput-1] = a[iget-1];
      }
    }
  }
/*
  Restore the signs of the entries.
*/
  for ( i = 0; i < n; i++ )
  {
    p[i] = - p[i];
  }
/*
  Restore the base of the entries.
*/
  for ( i = 0; i < n; i++ )
  {
    p[i] = p[i] - 1;
  }

  return;
}
/******************************************************************************/

void i4vec_print ( int n, int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PRINT prints an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 November 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %6d: %8d\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

int *i4vec_sort_heap_index_a ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_SORT_HEAP_INDEX_A does an indexed heap ascending sort of an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

    The sorting is not actually carried out.  Rather an index array is
    created which defines the sorting.  This array may be used to sort
    or index the array, or to sort or index related arrays keyed on the
    original array.

    Once the index array is computed, the sorting can be carried out
    "implicitly:

      a(indx(*))

    or explicitly, by the call

      i4vec_permute ( n, indx, a )

    after which a(*) is sorted.

    Note that the index vector is 0-based.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 June 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, int A[N], an array to be index-sorted.

    Output, int I4VEC_SORT_HEAP_INDEX_A[N], contains the sort index.  The
    I-th element of the sorted array is A(INDX(I)).
*/
{
  int aval;
  int i;
  int *indx;
  int indxt;
  int ir;
  int j;
  int l;

  if ( n < 1 )
  {
    return NULL;
  }

  indx = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    indx[i] = i;
  }

  if ( n == 1 )
  {
    indx[0] = indx[0];
    return indx;
  }

  l = n / 2 + 1;
  ir = n;

  for ( ; ; )
  {

    if ( 1 < l )
    {
      l = l - 1;
      indxt = indx[l-1];
      aval = a[indxt];
    }
    else
    {
      indxt = indx[ir-1];
      aval = a[indxt];
      indx[ir-1] = indx[0];
      ir = ir - 1;

      if ( ir == 1 )
      {
        indx[0] = indxt;
        break;
      }
    }

    i = l;
    j = l + l;

    while ( j <= ir )
    {
      if ( j < ir )
      {
        if ( a[indx[j-1]] < a[indx[j]] )
        {
          j = j + 1;
        }
      }

      if ( aval < a[indx[j-1]] )
      {
        indx[i-1] = indx[j-1];
        i = j;
        j = j + j;
      }
      else
      {
        j = ir + 1;
      }
    }
    indx[i-1] = indxt;
  }

  return indx;
}
/******************************************************************************/

int i4vec_sum ( int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_SUM sums the entries of an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Example:

    Input:

      A = ( 1, 2, 3, 4 )

    Output:

      I4VEC_SUM = 10

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 May 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, int A[N], the vector to be summed.

    Output, int I4VEC_SUM, the sum of the entries of A.
*/
{
  int i;
  int sum;

  sum = 0;
  for ( i = 0; i < n; i++ )
  {
    sum = sum + a[i];
  }

  return sum;
}
/******************************************************************************/

int mono_rank_grlex ( int m, int x[] )

/******************************************************************************/
/*
  Purpose:

    MONO_RANK_GRLEX computes the graded lexicographic rank of a monomial.

  Discussion:

    The graded lexicographic ordering is used, over all monomials in 
    M dimensions, for total degree = 0, 1, 2, ...

    For example, if M = 3, the ranking begins:

    Rank  Sum    1  2  3
    ----  ---   -- -- --
       1    0    0  0  0

       2    1    0  0  1
       3    1    0  1  0
       4    1    1  0  1

       5    2    0  0  2
       6    2    0  1  1
       7    2    0  2  0
       8    2    1  0  1
       9    2    1  1  0
      10    2    2  0  0

      11    3    0  0  3
      12    3    0  1  2
      13    3    0  2  1
      14    3    0  3  0
      15    3    1  0  2
      16    3    1  1  1
      17    3    1  2  0
      18    3    2  0  1
      19    3    2  1  0
      20    3    3  0  0

      21    4    0  0  4
      ..   ..   .. .. ..

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.
    1 <= M.

    Input, int X[M], the composition.
    For each 1 <= I <= M, we have 0 <= X(I).

    Output, int MONO_RANK_GRLEX, the rank.
*/
{
  int i;
  int j;
  int ks;
  int n;
  int nm;
  int ns;
  int rank;
  int tim1;
  int *xs;
/*
  Ensure that 1 <= M.
*/
  if ( m < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "MONO_RANK_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  M < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that 0 <= X(I).
*/
  for ( i = 0; i < m; i++ )
  {
    if ( x[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "MONO_RANK_GRLEX - Fatal error!\n" );
      fprintf ( stderr, "  X[I] < 0\n" );
      exit ( 1 );
    }
  }
/*
  NM = sum ( X )
*/
  nm = i4vec_sum ( m, x );
/*
  Convert to KSUBSET format.
*/
  ns = nm + m - 1;
  ks = m - 1;
  xs = ( int * ) malloc ( ks * sizeof ( int ) );
  xs[0] = x[0] + 1;
  for ( i = 2; i < m; i++ )
  {
    xs[i-1] = xs[i-2] + x[i-1] + 1;
  }
/*
  Compute the rank.
*/
  rank = 1;

  for ( i = 1; i <= ks; i++ )
  {
    if ( i == 1 )
    {
      tim1 = 0;
    }
    else
    {
      tim1 = xs[i-2];
    }

    if ( tim1 + 1 <= xs[i-1] - 1 )
    {
      for ( j = tim1 + 1; j <= xs[i-1] - 1; j++ )
      {
        rank = rank + i4_choose ( ns - j, ks - i );
      }
    }
  }

  for ( n = 0; n < nm; n++ )
  {
    rank = rank + i4_choose ( n + m - 1, n );
  }

  free ( xs );

  return rank;
}
/******************************************************************************/

int *mono_unrank_grlex ( int m, int rank )

/******************************************************************************/
/*
  Purpose:

    MONO_UNRANK_GRLEX computes the monomial of given grlex rank.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 January 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.
    1 <= M.

    Input, int RANK, the rank of the composition.
    1 <= RANK.

    Output, int COMP_UNRANK_GRLEX[M], the composition X of the given rank.
    For each I, 0 <= X[I] <= NM, and 
    sum ( 1 <= I <= M ) X[I] = NM.
*/
{
  int i;
  int j;
  int ks;
  int nm;
  int ns;
  int r;
  int rank1;
  int rank2;
  int *x;
  int *xs;
/*
  Ensure that 1 <= M.
*/
  if ( m < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "MONO_UNRANK_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  M < 1\n" );
    exit ( 1 );
  }
/*
  Ensure that 1 <= RANK.
*/
  if ( rank < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "MONO_UNRANK_GRLEX - Fatal error!\n" );
    fprintf ( stderr, "  RANK < 1\n" );
    exit ( 1 );
  }
/*
  Special case M == 1.
*/
  if ( m == 1 )
  {
    x = ( int * ) malloc ( m * sizeof ( int ) );
    x[0] = rank - 1;
    return x;
  }
/*
  Determine the appropriate value of NM.
  Do this by adding up the number of compositions of sum 0, 1, 2, 
  ..., without exceeding RANK.  Moreover, RANK - this sum essentially
  gives you the rank of the composition within the set of compositions
  of sum NM.  And that's the number you need in order to do the
  unranking.
*/
  rank1 = 1;
  nm = -1;
  for ( ; ; )
  {
    nm = nm + 1;
    r = i4_choose ( nm + m - 1, nm );
    if ( rank < rank1 + r )
    {
      break;
    }
    rank1 = rank1 + r;
  }

  rank2 = rank - rank1;
/*
  Convert to KSUBSET format.
  Apology: an unranking algorithm was available for KSUBSETS,
  but not immediately for compositions.  One day we will come back
  and simplify all this.
*/
  ks = m - 1;
  ns = nm + m - 1;
  xs = ( int * ) malloc ( ks * sizeof ( int ) );

  j = 1;

  for ( i = 1; i <= ks; i++ )
  {
    r = i4_choose ( ns - j, ks - i );

    while ( r <= rank2 && 0 < r )
    {
      rank2 = rank2 - r;
      j = j + 1;
      r = i4_choose ( ns - j, ks - i );
    }
    xs[i-1] = j;
    j = j + 1;
  }
/*
  Convert from KSUBSET format to COMP format.
*/
  x = ( int * ) malloc ( m * sizeof ( int ) );
  x[0] = xs[0] - 1;
  for ( i = 2; i < m; i++ )
  {
    x[i-1] = xs[i-1] - xs[i-2] - 1;
  }
  x[m-1] = ns - xs[ks-1];

  free ( xs );

  return x;
}
/******************************************************************************/

double *mono_value ( int m, int n, int f[], double x[] )

/******************************************************************************/
/*
  Purpose:

    MONO_VALUE evaluates a monomial.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int N, the number of evaluation points.

    Input, int F[M], the exponents of the monomial.

    Input, double X[M*N], the coordinates of the evaluation points.

    Output, double MONO_VALUE[N], the value of the monomial at X.
*/
{
  int i;
  int j;
  double *v;

  v = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    v[j] = 1.0;
    for ( i = 0; i < m; i++ )
    {
      v[j] = v[j] * pow ( x[i+j*m], f[i] );
    }
  }

  return v;
}
/******************************************************************************/

int perm_check ( int n, int p[], int base )

/******************************************************************************/
/*
  Purpose:

    PERM_CHECK checks that a vector represents a permutation.

  Discussion:

    The routine verifies that each of the integers from 0 to
    to N-1 occurs among the N entries of the permutation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries.

    Input, int P[N], the array to check.

    Input, int BASE, the base.

    Output, int PERM_CHECK, is TRUE if the permutation is OK.
*/
{
  int found;
  int i;
  int seek;

  for ( seek = base+0; seek < base+n; seek++ )
  {
    found = 0;

    for ( i = 0; i < n; i++ )
    {
      if ( p[i] == seek )
      {
        found = 1;
        break;
      }
    }

    if ( found == 0 )
    {
      return 0;
    }

  }

  return 1;
}
/******************************************************************************/

void polynomial_compress ( int o1, double c1[], int e1[], int *o2, double c2[], 
  int e2[] )

/******************************************************************************/
/*
  Purpose:

    POLYNOMIAL_COMPRESS compresses a polynomial.

  Discussion:

    The function polynomial_sort ( ) should be called first.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 January 2014

  Author:

    John Burkardt

  Parameters:

    Input, int O1, the "order" of the polynomial.

    Input, double C1[O1], the coefficients of the polynomial.

    Input, int E1[O1], the indices of the exponents of 
    the polynomial.

    Output, int *O2, the "order" of the polynomial.

    Output, double C2[*O2], the coefficients of the polynomial.

    Output, int E2[*O2], the indices of the exponents of 
    the polynomial.
*/
{
  int get;
  int put;
  const double r8_epsilon_sqrt = 0.1490116119384766E-07;

  get = 0;
  put = 0;

  while ( get < o1 )
  {
    get = get + 1;

    if ( fabs ( c1[get-1] ) <= r8_epsilon_sqrt )
    {
      continue;
    }

    if ( 0 == put )
    {
      put = put + 1;
      c2[put-1] = c1[get-1];
      e2[put-1] = e1[get-1];
    }
    else
    {
      if ( e2[put-1] == e1[get-1] )
      {
        c2[put-1] = c2[put-1] + c1[get-1];
      }
      else
      {
        put = put + 1;
        c2[put-1] = c1[get-1];
        e2[put-1] = e1[get-1];
       }
    }
  }
 
  *o2 = put;

  return;
}
/******************************************************************************/

void polynomial_print ( int m, int o, double c[], int e[], char *title )

/******************************************************************************/
/*
  Purpose:

    POLYNOMIAL_PRINT prints a polynomial.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int O, the "order" of the polynomial, that is,
    simply the number of terms.

    Input, double C[O], the coefficients.

    Input, int E[O], the indices of the exponents.

    Input, char *TITLE, a title.
*/
{
  int *f;
  int i;
  int j;

  printf ( "%s\n", title );

  if ( o == 0 )
  {
    printf ( "      0.\n" );
  }
  else
  {
    for ( j = 0; j < o; j++ )
    {
      printf ( "    " );
      if ( c[j] < 0.0 )
      {
        printf ( "- " );
      }
      else
      {
        printf ( "+ " );
      }
      printf ( "%g * x^(", fabs ( c[j] ) );

      f = mono_unrank_grlex ( m, e[j] );
      for ( i = 0; i < m; i++ )
      {
        printf ( "%d", f[i] );
        if ( i < m - 1 )
        {
          printf ( "," );
        }
        else
        {
          printf ( ")" );
        }
      }
      free ( f );

      if ( j == o - 1 )
      {
        printf ( "." );
      }
      printf ( "\n" );
    }
  }

  return;
}
/******************************************************************************/

void polynomial_sort ( int o, double c[], int e[] )

/******************************************************************************/
/*
  Purpose:

    POLYNOMIAL_SORT sorts the information in a polynomial.

  Discussion

    The coefficients C and exponents E are rearranged so that 
    the elements of E are in ascending order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int O, the "order" of the polynomial.

    Input/output, double C[O], the coefficients of the polynomial.

    Input/output, int E[O], the indices of the exponents of 
    the polynomial.
*/
{
  const int base = 0;
  int *indx;

  indx = i4vec_sort_heap_index_a ( o, e );

  i4vec_permute ( o, indx, base, e );
  r8vec_permute ( o, indx, base, c );

  free ( indx );

  return;
}
/******************************************************************************/

double *polynomial_value ( int m, int o, double c[], int e[], int nx, 
  double x[] )

/******************************************************************************/
/*
  Purpose:

    POLYNOMIAL_VALUE evaluates a polynomial.

  Discussion:

    The polynomial is evaluated term by term, and no attempt is made to
    use an approach such as Horner's method to speed up the process.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int O, the "order" of the polynomial.

    Input, double C[O], the coefficients of the polynomial.

    Input, int E[O], the indices of the exponents 
    of the polynomial.

    Input, int NX, the number of evaluation points.

    Input, double X[M*NX], the coordinates of the evaluation points.

    Output, double POLYNOMIAL_VALUE[NX], the value of the polynomial at X.
*/
{
  int *f;
  int j;
  int k;
  double *p;
  double *v;

  p = ( double * ) malloc ( nx * sizeof ( double ) );

  for ( k = 0; k < nx; k++ )
  {
    p[k] = 0.0;
  }

  for ( j = 0; j < o; j++ )
  {
    f = mono_unrank_grlex ( m, e[j] );
    v = mono_value ( m, nx, f, x );
    for ( k = 0; k < nx; k++ )
    {
      p[k] = p[k] + c[j] * v[k];
    }
    free ( f );
  }

  return p;
}
/******************************************************************************/

void r8vec_permute ( int n, int p[], int base, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PERMUTE permutes an R8VEC in place.

  Discussion:

    An R8VEC is a vector of R8's.

    This routine permutes an array of real "objects", but the same
    logic can be used to permute an array of objects of any arithmetic
    type, or an array of objects of any complexity.  The only temporary
    storage required is enough to store a single object.  The number
    of data movements made is N + the number of cycles of order 2 or more,
    which is never more than N + N/2.

  Example:

    Input:

      N = 5
      P = (   2,   4,   5,   1,   3 )
      A = ( 1.0, 2.0, 3.0, 4.0, 5.0 )
      BASE = 1

    Output:

      A    = ( 2.0, 4.0, 5.0, 1.0, 3.0 ).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of objects.

    Input, int P[N], the permutation.

    Input, int BASE, is 0 for a 0-based permutation and 1 for a 1-based permutation.

    Input/output, double A[N], the array to be permuted.
*/
{
  double a_temp;
  int i;
  int iget;
  int iput;
  int istart;

  if ( !perm_check ( n, p, base ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_PERMUTE - Fatal error!\n" );
    fprintf ( stderr, "  PERM_CHECK rejects this permutation.\n" );
    exit ( 1 );
  }
/*
  In order for the sign negation trick to work, we need to assume that the
  entries of P are strictly positive.  Presumably, the lowest number is BASE.
  So temporarily add 1-BASE to each entry to force positivity.
*/
  for ( i = 0; i < n; i++ )
  {
    p[i] = p[i] + 1 - base;
  }
/*
  Search for the next element of the permutation that has not been used.
*/
  for ( istart = 1; istart <= n; istart++ )
  {
    if ( p[istart-1] < 0 )
    {
      continue;
    }
    else if ( p[istart-1] == istart )
    {
      p[istart-1] = - p[istart-1];
      continue;
    }
    else
    {
      a_temp = a[istart-1];
      iget = istart;
/*
  Copy the new value into the vacated entry.
*/
      for ( ; ; )
      {
        iput = iget;
        iget = p[iget-1];

        p[iput-1] = - p[iput-1];

        if ( iget < 1 || n < iget )
        {
          fprintf ( stderr, "\n" );
          fprintf ( stderr, "R8VEC_PERMUTE - Fatal error!\n" );
          fprintf ( stderr, "  A permutation index is out of range.\n" );
          fprintf ( stderr, "  P(%d) = %d\n", iput, iget );
          exit ( 1 );
        }

        if ( iget == istart )
        {
          a[iput-1] = a_temp;
          break;
        }
        a[iput-1] = a[iget-1];
      }
    }
  }
/*
  Restore the signs of the entries.
*/
  for ( i = 0; i < n; i++ )
  {
    p[i] = - p[i];
  }
/*
  Restore the base of the entries.
*/
  for ( i = 0; i < n; i++ )
  {
    p[i] = p[i] - 1 +  base;
  }
  return;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

double *r8vec_uniform_ab_new ( int n, double a, double b, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_AB_NEW returns a scaled pseudorandom R8VEC.

  Discussion:

    Each dimension ranges from A to B.

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 January 2005

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

    Input, int N, the number of entries in the vector.

    Input, double A, B, the lower and upper limits of the pseudorandom values.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_AB_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  const int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_AB_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = a + ( b - a ) * ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
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

