# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "random_sorted.h"

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

double normal_01_cdf_inv ( double p )

/******************************************************************************/
/*
  Purpose:

    NORMAL_01_CDF_INV inverts the standard normal CDF.

  Discussion:

    The result is accurate to about 1 part in 10**16.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 December 2004

  Author:

    Original FORTRAN77 version by Michael Wichura.
    C version by John Burkardt.

  Reference:

    Michael Wichura,
    The Percentage Points of the Normal Distribution,
    Algorithm AS 241,
    Applied Statistics,
    Volume 37, Number 3, pages 477-484, 1988.

  Parameters:

    Input, double P, the value of the cumulative probability
    densitity function.  0 < P < 1.  If P is outside this range, an
    "infinite" value is returned.

    Output, double NORMAL_01_CDF_INV, the normal deviate value
    with the property that the probability of a standard normal deviate being
    less than or equal to this value is P.
*/
{
  double a[8] = {
    3.3871328727963666080,     1.3314166789178437745e+2,
    1.9715909503065514427e+3,  1.3731693765509461125e+4,
    4.5921953931549871457e+4,  6.7265770927008700853e+4,
    3.3430575583588128105e+4,  2.5090809287301226727e+3 };
  double b[8] = {
    1.0,                       4.2313330701600911252e+1,
    6.8718700749205790830e+2,  5.3941960214247511077e+3,
    2.1213794301586595867e+4,  3.9307895800092710610e+4,
    2.8729085735721942674e+4,  5.2264952788528545610e+3 };
  double c[8] = {
    1.42343711074968357734,     4.63033784615654529590,
    5.76949722146069140550,     3.64784832476320460504,
    1.27045825245236838258,     2.41780725177450611770e-1,
    2.27238449892691845833e-2,  7.74545014278341407640e-4 };
  double const1 = 0.180625;
  double const2 = 1.6;
  double d[8] = {
    1.0,                        2.05319162663775882187,
    1.67638483018380384940,     6.89767334985100004550e-1,
    1.48103976427480074590e-1,  1.51986665636164571966e-2,
    5.47593808499534494600e-4,  1.05075007164441684324e-9 };
  double e[8] = {
    6.65790464350110377720,     5.46378491116411436990,
    1.78482653991729133580,     2.96560571828504891230e-1,
    2.65321895265761230930e-2,  1.24266094738807843860e-3,
    2.71155556874348757815e-5,  2.01033439929228813265e-7 };
  double f[8] = {
    1.0,                        5.99832206555887937690e-1,
    1.36929880922735805310e-1,  1.48753612908506148525e-2,
    7.86869131145613259100e-4,  1.84631831751005468180e-5,
    1.42151175831644588870e-7,  2.04426310338993978564e-15 };
  double q;
  double r;
  const double r8_huge = 1.0E+30;
  double split1 = 0.425;
  double split2 = 5.0;
  double value;

  if ( p <= 0.0 )
  {
    value = - r8_huge;
    return value;
  }

  if ( 1.0 <= p )
  {
    value = r8_huge;
    return value;
  }

  q = p - 0.5;

  if ( fabs ( q ) <= split1 )
  {
    r = const1 - q * q;
    value = q * r8poly_value_horner ( 7, a, r ) / r8poly_value_horner ( 7, b, r );
  }
  else
  {
    if ( q < 0.0 )
    {
      r = p;
    }
    else
    {
      r = 1.0 - p;
    }

    if ( r <= 0.0 )
    {
      value = r8_huge;
    }
    else
    {
      r = sqrt ( - log ( r ) );

      if ( r <= split2 )
      {
        r = r - const2;
        value = r8poly_value_horner ( 7, c, r ) / r8poly_value_horner ( 7, d, r );
       }
       else
       {
         r = r - split2;
         value = r8poly_value_horner ( 7, e, r ) / r8poly_value_horner ( 7, f, r );
      }
    }

    if ( q < 0.0 )
    {
      value = - value;
    }

  }

  return value;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a pseudorandom R8 scaled to [0,1].

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

double r8poly_value_horner ( int m, double c[], double x )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE_HORNER evaluates a polynomial using Horner's method.

  Discussion:

    The polynomial 

      p(x) = c0 + c1 * x + c2 * x^2 + ... + cm * x^m

    is to be evaluated at the value X.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, the degree of the polynomial.

    Input, double C[M+1], the coefficients of the polynomial.
    C[0] is the constant term.

    Input, double X, the point at which the polynomial is to be evaluated.

    Output, double R8POLY_VALUE_HORNER, the value of the polynomial at X.
*/
{
  int i;
  double value;

  value = c[m];

  for ( i = m - 1; 0 <= i; i-- )
  {
    value = value * x + c[i];
  }

  return value;
}
/******************************************************************************/

double *r8vec_normal_01_sorted ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORMAL_01_SORTED returns a sorted normal 01 random vector.

  Discussion:

    The Normal 01 distribution has mean 0 and standard deviation 1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt

  Reference:

    Jon Bentley, James Saxe,
    Generating sorted lists of random numbers,
    ACM Transactions on Mathematical Software,
    Volume 6, Number 3, September 1980, pages 359-364.

  Parameters:

    Input, int N, the number of values to generate.

    Input/output, int *SEED, the integer "seed" used to 
    generate the output random number.  SEED should not be 0.  On output,
    the seed has been updated.

    Output, double R8VEC_NORMAL_01_SORTED[N], a vector of normal 01 random 
    values in ascending order.
*/
{
  double *cdfvec;
  int i;
  double *r8vec;

  cdfvec = r8vec_uniform_01_sorted1 ( n, seed );
 
  r8vec = ( double * ) malloc ( n * sizeof ( double ) );
 
  for ( i = 0; i < n; i++ )
  {
    r8vec[i] = normal_01_cdf_inv ( cdfvec[i] );
  }

  free ( cdfvec );

  return r8vec;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2004

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  printf ( "\n" );
  printf ( "%s\n", title );
  printf ( "\n" );
  for ( i = 0; i <= n-1; i++ )
  {
    printf ( "%6d  %14g\n", i + 1, a[i] );
  }

  return;
}
/******************************************************************************/

void r8vec_transpose_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_TRANSPOSE_PRINT prints an R8VEC "transposed".

  Discussion:

    An R8VEC is a vector of R8's.

  Example:

    A = (/ 1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 10.9, 11.0 /)
    TITLE = 'My vector:  '

    My vector:   1.0    2.1    3.2    4.3    5.4
                 6.5    7.6    8.7    9.8   10.9
                11.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 May 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;
  int ihi;
  int ilo;
  int title_length;

  title_length = s_len_trim ( title );

  for ( ilo = 0; ilo < n; ilo = ilo + 5 )
  {
    if ( ilo == 0 )
    {
      printf ( "%s", title );
    }
    else
    {
      for ( i = 0; i < title_length; i++ )
      {
        printf ( " " );
      }
    }
    printf ( "  " );

    ihi = i4_min ( ilo + 5, n );
    for ( i = ilo; i < ihi; i++ )
    {
      printf ( "  %12g", a[i] );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

double *r8vec_uniform_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_01[N], the vector of pseudorandom values.
*/
{
  int i;
  int k;
  double *r;

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + 2147483647;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
}
/******************************************************************************/

double *r8vec_uniform_01_sorted1 ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_SORTED1 returns a sorted real random vector in [0,1].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt

  Reference:

    Jon Bentley, James Saxe,
    Generating sorted lists of random numbers,
    ACM Transactions on Mathematical Software,
    Volume 6, Number 3, September 1980, pages 359-364.

  Parameters:

    Input, int N, the number of values to generate.

    Input, int *SEED, the integer "seed" used to 
    generate the output random number.  SEED should not be 0.
    On output, SEED has been updated.

    Output, double R8VEC_UNIFORM_01_SORTED2[N], a real vector of random values
    in ascending order.
*/
{
  int i;
  double r;
  double *r8vec;
  double s;

  r8vec = ( double * ) malloc ( n * sizeof ( double ) );

  s = 0.0;

  for ( i = 0; i <= n; i++ )
  {
    r = r8_uniform_01 ( seed );
    s = s - log ( r );
    if ( i == n )
    {
      break;
    }
    r8vec[i] = s;
  }
  
  for ( i = 0; i < n; i++ )
  {
    r8vec[i] = r8vec[i] / s;
  }

  return r8vec;
}
/******************************************************************************/

double *r8vec_uniform_01_sorted2 ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_SORTED2 returns a sorted real random vector in [0,1].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt

  Reference:

    Jon Bentley, James Saxe,
    Generating sorted lists of random numbers,
    ACM Transactions on Mathematical Software,
    Volume 6, Number 3, September 1980, pages 359-364.

  Parameters:

    Input, int N, the number of values to generate.

    Input, int *SEED, the integer "seed" used to 
    generate the output random number.  SEED should not be 0.
    On output, the updated seed.

    Output, double R8VEC_UNIFORM_01_SORTED2[N], a vector of random values
    in ascending order.
*/
{
  double curmax;
  int i;
  double *r;
  double *r8vec;

  r = r8vec_uniform_01_new ( n, seed );

  r8vec = ( double * ) malloc ( n * sizeof ( double ) );

  curmax = 1.0;

  for ( i = n - 1; 0 <= i; i-- )
  {
    curmax = curmax * exp ( log ( r[i] ) / ( double ) ( i + 1 ) );
    r8vec[i] = curmax;
  }

  return r8vec;
}
/******************************************************************************/

int s_len_trim ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_LEN_TRIM returns the length of a string to the last nonblank.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 April 2003

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
    if ( *t != ' ' )
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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
