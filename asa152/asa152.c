# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "asa152.h"

/******************************************************************************/

double alnfac ( int n )

/******************************************************************************/
/*
  Purpose:

    ALNFAC computes the logarithm of the factorial of N.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 November 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the argument of the factorial.

    Output, double ALNFAC, the logarithm of the factorial of N.
*/
{
  double value;

  value = lgamma ( ( double ) ( n + 1 ) );

  return value;
}
/******************************************************************************/

double alnorm ( double x, int upper )

/******************************************************************************/
/*
  Purpose:

    ALNORM computes the cumulative density of the standard normal distribution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 November 2010

  Author:

    Original FORTRAN77 version by David Hill.
    C version by John Burkardt.

  Reference:

    David Hill,
    Algorithm AS 66:
    The Normal Integral,
    Applied Statistics,
    Volume 22, Number 3, 1973, pages 424-427.

  Parameters:

    Input, double X, is one endpoint of the semi-infinite interval
    over which the integration takes place.

    Input, int UPPER, determines whether the upper or lower
    interval is to be integrated:
    .TRUE.  => integrate from X to + Infinity;
    .FALSE. => integrate from - Infinity to X.

    Output, double ALNORM, the integral of the standard normal
    distribution over the desired interval.
*/
{
  double a1 = 5.75885480458;
  double a2 = 2.62433121679;
  double a3 = 5.92885724438;
  double b1 = -29.8213557807;
  double b2 = 48.6959930692;
  double c1 = -0.000000038052;
  double c2 = 0.000398064794;
  double c3 = -0.151679116635;
  double c4 = 4.8385912808;
  double c5 = 0.742380924027;
  double c6 = 3.99019417011;
  double con = 1.28;
  double d1 = 1.00000615302;
  double d2 = 1.98615381364;
  double d3 = 5.29330324926;
  double d4 = -15.1508972451;
  double d5 = 30.789933034;
  double ltone = 7.0;
  double p = 0.398942280444;
  double q = 0.39990348504;
  double r = 0.398942280385;
  int up;
  double utzero = 18.66;
  double value;
  double y;
  double z;

  up = upper;
  z = x;

  if ( z < 0.0 )
  {
    up = !up;
    z = - z;
  }

  if ( ltone < z && ( ( !up ) || utzero < z ) )
  {
    if ( up )
    {
      value = 0.0;
    }
    else
    {
      value = 1.0;
    }
    return value;
  }

  y = 0.5 * z * z;

  if ( z <= con )
  {
    value = 0.5 - z * ( p - q * y
      / ( y + a1 + b1
      / ( y + a2 + b2
      / ( y + a3 ))));
  }
  else
  {
    value = r * exp ( - y )
      / ( z + c1 + d1
      / ( z + c2 + d2
      / ( z + c3 + d3
      / ( z + c4 + d4
      / ( z + c5 + d5
      / ( z + c6 ))))));
  }

  if ( !up )
  {
    value = 1.0 - value;
  }

  return value;
}
/******************************************************************************/

double chyper ( int point, int kk, int ll, int mm, int nn, int *ifault )

/******************************************************************************/
/*
  Purpose:

    CHYPER computes point or cumulative hypergeometric probabilities.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 November 2010

  Author:

    Original FORTRAN77 version by Richard Lund.
    C version by John Burkardt.

  Reference:

    PR Freeman,
    Algorithm AS 59:
    Hypergeometric Probabilities,
    Applied Statistics,
    Volume 22, Number 1, 1973, pages 130-133.

    Richard Lund,
    Algorithm AS 152:
    Cumulative hypergeometric probabilities,
    Applied Statistics,
    Volume 29, Number 2, 1980, pages 221-223.

    BL Shea,
    Remark AS R77:
    A Remark on Algorithm AS 152: Cumulative hypergeometric probabilities,
    Applied Statistics,
    Volume 38, Number 1, 1989, pages 199-204.

  Parameters:

    Input, int POINT, is TRUE if the point probability is desired,
    and FALSE if the cumulative probability is desired.

    Input, int KK, the sample size.
    0 <= KK <= MM.

    Input, int LL, the number of successes in the sample.
    0 <= LL <= KK.

    Input, int MM, the population size that was sampled.
    0 <= MM.

    Input, int NN, the number of "successes" in the population.
    0 <= NN <= MM.

    Output, int *IFAULT, error flag.
    0, no error occurred.
    nonzero, an error occurred.

    Output, double CHYPER, the PDF (point probability) of
    exactly LL successes out of KK samples, or the CDF (cumulative
    probability) of up to LL successes out of KK samples.
*/
{
  double arg;
  int dir;
  double elimit = - 88.0;
  int i;
  int j;
  int k;
  int kl;
  int l;
  int m;
  int mbig = 600;
  double mean;
  int mnkl;
  int mvbig = 1000;
  int n;
  int nl;
  double p;
  double pt;
  double rootpi = 2.506628274631001;
  double scale = 1.0E+35;
  double sig;
  double value;

  *ifault = 0;

  k = kk + 1;
  l = ll + 1;
  m = mm + 1;
  n = nn + 1;

  dir = 1;
/*
  Check arguments are within permitted limits.
*/
  value = 0.0;

  if ( n < 1 || m < n || k < 1 || m < k )
  {
    *ifault = 1;
    return value;
  }

  if ( l < 1 || m - n < k - l )
  {
    *ifault = 2;
    return value;
  }

  if ( !point )
  {
    value = 1.0;
  }

  if ( n < l || k < l )
  {
    *ifault = 2;
    return value;
  }

  *ifault = 0;
  value = 1.0;

  if ( k == 1 || k == m || n == 1 || n == m )
  {
    return value;
  }

  if ( !point && ll == i4_min ( kk, nn ) )
  {
    return value;
  }

  p = ( double ) ( nn ) / ( double ) ( mm - nn );

  if ( 16.0 * r8_max ( p, 1.0 / p )
    < ( double ) ( i4_min ( kk, mm - kk ) ) &&
    mvbig < mm && - 100.0 < elimit )
  {
/*
  Use a normal approximation.
*/
    mean = ( double ) ( kk * nn ) / ( double ) ( mm );

    sig = sqrt ( mean * ( ( double ) ( mm - nn ) / ( double ) ( mm ) )
    * ( ( double ) ( mm - kk ) / ( ( double ) ( mm - 1 ) ) ) );

    if ( point )
    {
      arg = - 0.5 * ( pow ( ( ( double ) ( ll ) - mean ) / sig, 2 ) );
      if ( elimit <= arg )
      {
        value = exp ( arg ) / ( sig * rootpi );
      }
      else
      {
        value = 0.0;
      }
    }
    else
    {
      value = alnorm ( ( ( double ) ( ll ) + 0.5 - mean ) / sig, 0 );
    }
  }
  else
  {
/*
  Calculate exact hypergeometric probabilities.
  Interchange K and N if this saves calculations.
*/
    if ( i4_min ( n - 1, m - n ) < i4_min ( k - 1, m - k ) )
    {
      i = k;
      k = n;
      n = i;
    }

    if ( m - k < k - 1 )
    {
      dir = !dir;
      l = n - l + 1;
      k = m - k + 1;
    }

    if ( mbig < mm )
    {
/*
  Take logarithms of factorials.
*/
      p = alnfac ( nn )
        - alnfac ( mm )
        + alnfac ( mm - kk )
        + alnfac ( kk )
        + alnfac ( mm - nn )
        - alnfac ( ll )
        - alnfac ( nn - ll )
        - alnfac ( kk - ll )
        - alnfac ( mm - nn - kk + ll );

      if ( elimit <= p )
      {
        value = exp ( p );
      }
      else
      {
        value = 0.0;
      }
    }
    else
    {
/*
  Use Freeman/Lund algorithm.
*/
      for ( i = 1; i <= l - 1; i++ )
      {
        value = value * ( double ) ( ( k - i ) * ( n - i ) )
        / ( double ) ( ( l - i ) * ( m - i ) );
      }

      if ( l != k )
      {
        j = m - n + l;
        for ( i = l; i <= k - 1; i++ )
        {
          value = value * ( double ) ( j - i ) / ( double ) ( m - i );
        }
      }
    }

    if ( point )
    {
      return value;
    }

    if ( value == 0.0 )
    {
/*
  We must recompute the point probability since it has underflowed.
*/
      if ( mm <= mbig )
      {
        p = alnfac ( nn )
          - alnfac ( mm )
          + alnfac ( kk )
          + alnfac ( mm - nn )
          - alnfac ( ll )
          - alnfac ( nn - ll )
          - alnfac ( kk - ll )
          - alnfac ( mm - nn - kk + ll )
          + alnfac ( mm - kk );
      }

      p = p + log ( scale );

      if ( p < elimit )
      {
        *ifault = 3;
        if ( ( double ) ( nn * kk + nn + kk + 1 )
          / ( double ) ( mm + 2 ) < ( double ) ( ll ) )
        {
          value = 1.0;
        }
        return value;
      }
      else
      {
        p = exp ( p );
      }
    }
    else
/*
  Scale up at this point.
*/
    {
      p = value * scale;
    }

    pt = 0.0;
    nl = n - l;
    kl = k - l;
    mnkl = m - n - kl + 1;

    if ( l <= kl )
    {
      for ( i = 1; i <= l - 1; i++ )
      {
        p = p * ( double ) ( ( l - i ) * ( mnkl - i ) ) /
        ( double ) ( ( nl + i ) * ( kl + i ) );
        pt = pt + p;
      }
    }
    else
    {
      dir = !dir;
      for ( j = 0; j <= kl - 1; j++ )
      {
        p = p * ( double ) ( ( nl - j ) * ( kl - j ) )
        / ( double ) ( ( l + j ) * ( mnkl + j ) );
        pt = pt + p;
      }
    }

    if ( p == 0.0 )
    {
      *ifault = 3;
    }

    if ( dir )
    {
      value = value + ( pt / scale );
    }
    else
    {
      value = 1.0 - ( pt / scale );
    }
  }

  return value;
}
/******************************************************************************/

void hypergeometric_cdf_values ( int *n_data, int *sam, int *suc, int *pop,
  int *n, double *fx )

/******************************************************************************/
/*
  Purpose:

    HYPERGEOMETRIC_CDF_VALUES returns some values of the hypergeometric CDF.

  Discussion:

    CDF(X)(A,B) is the probability of at most X successes in A trials,
    given that the probability of success on a single trial is B.

    In Mathematica, the function can be evaluated by:

      Needs["Statistics`DiscreteDistributions`]
      dist = HypergeometricDistribution [ sam, suc, pop ]
      CDF [ dist, n ]
  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 September 2004

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

    Daniel Zwillinger,
    CRC Standard Mathematical Tables and Formulae,
    30th Edition, CRC Press, 1996, pages 651-652.

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, int *SAM, int *SUC, int *POP, the sample size,
    success size, and population parameters of the function.

    Output, int *N, the argument of the function.

    Output, double *FX, the value of the function.
*/
{
# define N_MAX 16

  double fx_vec[N_MAX] = {
     0.6001858177500578E-01,
     0.2615284665839845E+00,
     0.6695237889132748E+00,
     0.1000000000000000E+01,
     0.1000000000000000E+01,
     0.5332595856827856E+00,
     0.1819495964117640E+00,
     0.4448047017527730E-01,
     0.9999991751316731E+00,
     0.9926860896560750E+00,
     0.8410799901444538E+00,
     0.3459800113391901E+00,
     0.0000000000000000E+00,
     0.2088888139634505E-02,
     0.3876752992448843E+00,
     0.9135215248834896E+00 };

  int n_vec[N_MAX] = {
     7,  8,  9, 10,
     6,  6,  6,  6,
     6,  6,  6,  6,
     0,  0,  0,  0 };

  int pop_vec[N_MAX] = {
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,
    90,  200, 1000, 10000 };

  int sam_vec[N_MAX] = {
    10, 10, 10, 10,
     6,  7,  8,  9,
    10, 10, 10, 10,
    10, 10, 10, 10 };

  int suc_vec[N_MAX] = {
    90, 90, 90, 90,
    90, 90, 90, 90,
    10, 30, 50, 70,
    90, 90, 90, 90 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *sam = 0;
    *suc = 0;
    *pop = 0;
    *n = 0;
    *fx = 0.0;
  }
  else
  {
    *sam = sam_vec[*n_data-1];
    *suc = suc_vec[*n_data-1];
    *pop = pop_vec[*n_data-1];
    *n = n_vec[*n_data-1];
    *fx = fx_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void hypergeometric_pdf_values ( int *n_data, int *sam, int *suc, int *pop,
  int *n, double *fx )

/******************************************************************************/
/*
  Purpose:

    HYPERGEOMETRIC_PDF_VALUES returns some values of the hypergeometric PDF.

  Discussion:

    CDF(X)(A,B) is the probability of X successes in A trials,
    given that the probability of success on a single trial is B.

    In Mathematica, the function can be evaluated by:

      dist = HypergeometricDistribution [ sam, suc, pop ]
      PDF [ dist, n ]

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 January 2008

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

    Daniel Zwillinger,
    CRC Standard Mathematical Tables and Formulae,
    30th Edition, CRC Press, 1996, pages 651-652.

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, int *SAM, int *SUC, int *POP, the sample size,
    success size, and population parameters of the function.

    Output, int *N, the argument of the function.

    Output, double *FX, the value of the function.
*/
{
# define N_MAX 16

  double fx_vec[N_MAX] = {
    0.05179370533242827E+00,
    0.2015098848089788E+00,
    0.4079953223292903E+00,
    0.3304762110867252E+00,
    0.5223047493549780E+00,
    0.3889503452643453E+00,
    0.1505614239732950E+00,
    0.03927689321042477E+00,
    0.00003099828465518108E+00,
    0.03145116093938197E+00,
    0.2114132170316862E+00,
    0.2075776621999210E+00,
    0.0000000000000000E+00,
    0.002088888139634505E+00,
    0.3876752992448843E+00,
    0.9135215248834896E+00 };

  int n_vec[N_MAX] = {
     7,  8,  9, 10,
     6,  6,  6,  6,
     6,  6,  6,  6,
     0,  0,  0,  0 };

  int pop_vec[N_MAX] = {
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,
    90,  200, 1000, 10000 };

  int sam_vec[N_MAX] = {
    10, 10, 10, 10,
     6,  7,  8,  9,
    10, 10, 10, 10,
    10, 10, 10, 10 };

  int suc_vec[N_MAX] = {
    90, 90, 90, 90,
    90, 90, 90, 90,
    10, 30, 50, 70,
    90, 90, 90, 90 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *sam = 0;
    *suc = 0;
    *pop = 0;
    *n = 0;
    *fx = 0.0;
  }
  else
  {
    *sam = sam_vec[*n_data-1];
    *suc = suc_vec[*n_data-1];
    *pop = pop_vec[*n_data-1];
    *n = n_vec[*n_data-1];
    *fx = fx_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the minimum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 October 1998

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

double r8_max ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    R8_MAX returns the maximum of two R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2004

  Author:

    John Burkardt

  Parameters:

    Input, double X, Y, the quantities to compare.

    Output, double R8_MAX, the maximum of X and Y.
*/
{
  double value;

  if ( x < y )
  {
    value = y;
  }
  else
  {
    value = x;
  }
  return value;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
