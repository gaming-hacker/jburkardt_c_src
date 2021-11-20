# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "square_integrals.h"

/******************************************************************************/

int *i4vec_uniform_ab_new ( int n, int a, int b, int *seed )

/******************************************************************************/
/*
  Purpose:

    I4VEC_UNIFORM_AB_NEW returns a scaled pseudorandom I4VEC.

  Discussion:

    The pseudorandom numbers should be uniformly distributed
    between A and B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 January 2014

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

    Input, integer N, the dimension of the vector.

    Input, int A, B, the limits of the interval.

    Input/output, int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, int I4VEC_UNIFORM_AB_NEW[N], a vector of random values 
    between A and B.
*/
{
  int c;
  int i;
  const int i4_huge = 2147483647;
  int k;
  float r;
  int value;
  int *x;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4VEC_UNIFORM_AB_NEW - Fatal error!\n" );
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

  x = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
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
    r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 
      +         r   * ( ( float ) b + 0.5 );
/*
  Use rounding to convert R to an integer between A and B.
*/
    value = round ( r );
/*
  Guarantee A <= VALUE <= B.
*/
    if ( value < a )
    {
      value = a;
    }
    if ( b < value )
    {
      value = b;
    }

    x[i] = value;
  }

  return x;
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

double *r8mat_uniform_ab_new ( int m, int n, double a, double b, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8MAT_UNIFORM_AB_NEW returns a scaled pseudorandom R8MAT.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 October 2005

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

    Input, int M, N, the number of rows and columns.

    Input, double A, B, the limits of the pseudorandom values.

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has 
    been updated.

    Output, double R8MAT_UNIFORM_AB_NEW[M*N], a matrix of pseudorandom values.
*/
{
  int i;
  const int i4_huge = 2147483647;
  int j;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8MAT_UNIFORM_AB_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = *seed / 127773;

      *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

      if ( *seed < 0 )
      {
        *seed = *seed + i4_huge;
      }
      r[i+j*m] = a + ( b - a ) * ( double ) ( *seed ) * 4.656612875E-10;
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

double square01_area ( )

/******************************************************************************/
/*
  Purpose:

    SQUARE01_AREA: area of the unit square in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2014

  Author:

    John Burkardt

  Parameters:

    Output, double SQUARE01_AREA, the area.
*/
{
  double area;

  area = 1.0;

  return area;
}
/******************************************************************************/

double square01_monomial_integral ( int e[2] )

/******************************************************************************/
/*
  Purpose:

    SQUARE01_MONOMIAL_INTEGRAL: integrals over the unit square in 2D.

  Discussion:

    The integration region is 

      0 <= X <= 1,
      0 <= Y <= 1.

    The monomial is F(X,Y) = X^E(1) * Y^E(2).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2014

  Author:

    John Burkardt

  Reference:

    Philip Davis, Philip Rabinowitz,
    Methods of Numerical Integration,
    Second Edition,
    Academic Press, 1984, page 263.

  Parameters:

    Input, int E[2], the exponents.  
    Each exponent must be nonnegative.

    Output, double SQUARE01_MONOMIAL_INTEGRAL, the integral.
*/
{
  int i;
  double integral;
  const int m = 2;

  for ( i = 0; i < m; i++ )
  {
    if ( e[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "SQUARE01_MONOMIAL_INTEGRAL - Fatal error!\n" );
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

double *square01_sample ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    SQUARE01_SAMPLE samples points in the unit square in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2014

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

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double X[2*N], the points.
*/
{
  double a;
  double b;
  const int m = 2;
  double *x;

  a = 0.0;
  b = 1.0;
  x = r8mat_uniform_ab_new ( m, n, a, b, seed );

  return x;
}
/******************************************************************************/

double squaresym_area ( )

/******************************************************************************/
/*
  Purpose:

    SQUARESYM_AREA: area of the symmetric unit square in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2018

  Author:

    John Burkardt

  Parameters:

    Output, double SQUARE01_AREA, the area.
*/
{
  double area;

  area = 4.0;

  return area;
}
/******************************************************************************/

double squaresym_monomial_integral ( int e[2] )

/******************************************************************************/
/*
  Purpose:

    SQUARESYM_MONOMIAL_INTEGRAL: integrals over the symmetric unit square in 2D.

  Discussion:

    The integration region is 

      -1 <= X <= 1,
      -1 <= Y <= 1.

    The monomial is F(X,Y) = X^E(1) * Y^E(2).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2018

  Author:

    John Burkardt

  Reference:

    Philip Davis, Philip Rabinowitz,
    Methods of Numerical Integration,
    Second Edition,
    Academic Press, 1984, page 263.

  Parameters:

    Input, int E[2], the exponents.  
    Each exponent must be nonnegative.

    Output, double SQUARESYM_MONOMIAL_INTEGRAL, the integral.
*/
{
  int i;
  double integral;
  const int m = 2;

  for ( i = 0; i < m; i++ )
  {
    if ( e[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "SQUARESYM_MONOMIAL_INTEGRAL - Fatal error!\n" );
      fprintf ( stderr, "  All exponents must be nonnegative.\n" );
      fprintf ( stderr, "  E[%d] = %d\n", i, e[i] );
      exit ( 1 );
    }
  }

  if ( ( e[0] % 2 ) == 1 || ( e[1] % 2 ) == 1 )
  {
    integral = 0.0;
  }
  else
  {
    integral = 4.0
      / ( double ) ( e[0] + 1 ) 
      / ( double ) ( e[1] + 1 );
  }

  return integral;
}
/******************************************************************************/

double *squaresym_sample ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    SQUARESYM_SAMPLE samples points in the symmetric unit square in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2018

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

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double X[2*N], the points.
*/
{
  double a;
  double b;
  const int m = 2;
  double *x;

  a = -1.0;
  b = 1.0;
  x = r8mat_uniform_ab_new ( m, n, a, b, seed );

  return x;
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

