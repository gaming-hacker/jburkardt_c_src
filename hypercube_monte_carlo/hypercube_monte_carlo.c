# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "hypercube_monte_carlo.h"

/******************************************************************************/

double hypercube01_monomial_integral ( int m, int e[] )

/******************************************************************************/
/*
  Purpose:

    HYPERCUBE01_MONOMIAL_INTEGRAL: integrals over unit hypercube in M dimensions.

  Discussion:

    The integration region is 

      0 <= X(1:M) <= 1.

    The monomial is F(X) = product ( 1 <= I <= M ) X(I)^E(I).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 January 2014

  Author:

    John Burkardt

  Reference:

    Philip Davis, Philip Rabinowitz,
    Methods of Numerical Integration,
    Second Edition,
    Academic Press, 1984, page 263.

  Parameters:

    Input, int M, the spatial dimension.

    Input, int E[M], the exponents.  
    Each exponent must be nonnegative.

    Output, double HYPERCUBE01_MONOMIAL_INTEGRAL, the integral.
*/
{
  int i;
  double integral;

  for ( i = 0; i < m; i++ )
  {
    if ( e[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "HYPERCUBE01_MONOMIAL_INTEGRAL - Fatal error!\n" );
      fprintf ( stderr, "  All exponents must be nonnegative.\n" );
      fprintf ( stderr, "  E[%d] = %d\n", i, e[i] );
      exit ( 1 );
    }
  }

  integral = 1.0;

  for ( i = 0; i < m; i++ )
  {
    integral = integral / ( double ) ( e[i] + 1 );
  }

  return integral;
}
/******************************************************************************/

double *hypercube01_sample ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    HYPERCUBE01_SAMPLE samples points in the unit hypercube in M dimensions.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 January 2014

  Author:

    John Burkardt

  Reference:

    Russell Cheng,
    Random Variate Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998, pages 168.

    Reuven Rubinstein,
    Monte Carlo Optimization, Simulation, and Sensitivity 
    of Queueing Networks,
    Krieger, 1992,
    ISBN: 0894647644,
    LC: QA298.R79.

  Parameters:

    Input, int M, the spatial dimension.

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double X[M*N], the points.
*/
{
  double *x;

  x = r8mat_uniform_01_new ( m, n, seed );

  return x;
}
/******************************************************************************/

double hypercube01_volume ( int m )

/******************************************************************************/
/*
  Purpose:

    HYPERCUBE01_VOLUME: volume of the unit hypercube in M dimensions.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 January 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Output, double HYPERCUBE01_VOLUME, the volume.
*/
{
  double volume;

  volume = 1.0;

  return volume;
}
/******************************************************************************/

double *monomial_value ( int m, int n, int e[], double x[] )

/******************************************************************************/
/*
  Purpose:

    MONOMIAL_VALUE evaluates a monomial.

  Discussion:

    This routine evaluates a monomial of the form

      product ( 1 <= i <= m ) x(i)^e(i)

    where the exponents are nonnegative integers.  Note that
    if the combination 0^0 is encountered, it should be treated
    as 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 May 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int N, the number of points at which the
    monomial is to be evaluated.

    Input, int E[M], the exponents.

    Input, double X[M*N], the point coordinates.

    Output, double MONOMIAL_VALUE[N], the value of the monomial.
*/
{
  int i;
  int j;
  double *v;

  v = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    v[j] = 1.0;
  }

  for ( i = 0; i < m; i++ )
  {
    if ( 0 != e[i] )
    {
      for ( j = 0; j < n; j++ )
      {
        v[j] = v[j] * pow ( x[i+j*m], e[i] );
      }
    }
  }

  return v;
}
/******************************************************************************/

double *r8mat_uniform_01_new ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8MAT_UNIFORM_01_NEW fills an R8MAT with pseudorandom values scaled to [0,1].

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 June 2009

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

    Philip Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0, otherwise the output value of SEED
    will still be 0, and R8_UNIFORM will be 0.  On output, SEED has
    been updated.

    Output, double R8MAT_UNIFORM_01_NEW[M*N], a matrix of pseudorandom values.
*/
{
  int i;
  int j;
  int k;
  double *r;

  r = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = *seed / 127773;

      *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

      if ( *seed < 0 )
      {
        *seed = *seed + 2147483647;
      }
      r[i+j*m] = ( double ) ( *seed ) * 4.656612875E-10;
    }
  }

  return r;
}
/******************************************************************************/

double r8vec_sum ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SUM returns the sum of an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A[N], the vector.

    Output, double R8VEC_SUM, the sum of the vector.
*/
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i];
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

