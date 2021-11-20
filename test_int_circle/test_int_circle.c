# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "test_int_circle.h"

/******************************************************************************/

double circle_unit_area ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_UNIT_AREA returns the area of the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 December 2013

  Author:

    John Burkardt

  Parameters:

    Output, double CIRCLE_UNIT_AREA, the area.
*/
{
  double area;
  const double r = 1.0;
  const double r8_pi = 3.141592653589793;

  area = r8_pi * r * r;

  return area;
}
/******************************************************************************/

double *circle_unit_sample ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_UNIT_SAMPLE returns sample points from the unit circle.

  Discussion:

    The unit circle has center at the origin, and radius 1.

    This routine is valid for spatial dimension DIM_NUM = 2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double CIRCLE_UNIT_SAMPLE[2*N], the points.
*/
{
  int i;
  double *r;
  const double r8_pi = 3.141592653589793;
  double *t;
  double *xy;

  r = r8vec_uniform_01_new ( n, seed );
  for ( i = 0; i < n; i++ )
  {
    r[i] = sqrt ( r[i] );
  }

  t = r8vec_uniform_01_new ( n, seed );
  for ( i = 0; i < n; i++ )
  {
    t[i] = 2.0 * r8_pi * t[i];
  }

  xy = ( double * ) malloc ( 2 * n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    xy[0+i*2] = r[i] * cos ( t[i] );
    xy[1+i*2] = r[i] * sin ( t[i] );
  }

  free ( r );
  free ( t );

  return xy;
}
/******************************************************************************/

double cos_power_int ( double a, double b, int n )

/******************************************************************************/
/*
  Purpose:

    COS_POWER_INT evaluates the cosine power integral.

  Discussion:

    The function is defined by

      COS_POWER_INT(A,B,N) = Integral ( A <= T <= B ) ( cos ( t ))^n dt

    The algorithm uses the following fact:

      Integral cos^n ( t ) = -(1/n) * (
        cos^(n-1)(t) * sin(t) + ( n-1 ) * Integral cos^(n-2) ( t ) dt )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2012

  Author:

    John Burkardt

  Parameters

    Input, double A, B, the limits of integration.

    Input, integer N, the power of the sine function.

    Output, double COS_POWER_INT, the value of the integral.
*/
{
  double ca;
  double cb;
  int m;
  int mlo;
  double sa;
  double sb;
  double value;

  if ( n < 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "COS_POWER_INT - Fatal error!\n" );
    fprintf ( stderr, "  Power N < 0.\n" );
    exit ( 1 );
  }

  sa = sin ( a );
  sb = sin ( b );
  ca = cos ( a );
  cb = cos ( b );

  if ( ( n % 2 ) == 0 )
  {
    value = b - a;
    mlo = 2;
  }
  else
  {
    value = sb - sa;
    mlo = 3;
  }

  for ( m = mlo; m <= n; m = m + 2 )
  {
    value = ( ( double ) ( m - 1 ) * value 
      - pow ( ca, (m-1) ) * sa + pow ( cb, (m-1) ) * sb ) 
      / ( double ) ( m );
  }

  return value;
}
/******************************************************************************/

double p01_exact ( )

/******************************************************************************/
/*
  Purpose:

    P01_EXACT returns the exact integral of function 1 over the unit circle.

  Discussion:

    The integral depends on a parameter E which must be set by calling
    P01_PARAM_SET ( E ) before calling this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 December 2013

  Author:

    John Burkardt

  Parameters:

    Output, double P01_EXACT, the exact integral.
*/
{
  int e;
  const double r8_pi = 3.141592653589793;
  const double r8_zero = 0.0;
  double value;

  e = p01_param_get ( );

  value = cos_power_int ( r8_zero, 2.0 * r8_pi, e ) / ( double ) ( e + 2 );

  return value;
}
/******************************************************************************/

double *p01_f ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    P01_F evaluates test function #1 in the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of variables.

    Input, double X[2*N], the arguments.

    Output, double P01_F[N], the values of the integrand.
*/
{
  int e;
  int i;
  double *fx;

  e = p01_param_get ( );

  fx = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    fx[i] = pow ( x[0+i*2], e );
  }
  return fx;
}
/******************************************************************************/

void p01_param ( char *action, int *e )

/******************************************************************************/
/*
  Purpose:

    P01_PARAM sets or gets the value of the parameter for test function 1.

  Discussion:

    The parameter E is the exponent of X^E.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, char *ACTION, indicates which action is desired.
    'G' will get the parameter value.
    'S' will set the parameter value.

    Input/output, int *E.
    If ACTION is 'S', then on input this is the new value of the parameter,
    If ACTION is 'G', then on output this is the stored value of the parameter.
*/
{
  static int e_saved = 0;

  if ( action[0] == 'g' || action[0] == 'G' )
  {
    *e = e_saved;
  }
  else if ( action[0] == 's' || action[0] == 'S' )
  {
    e_saved = *e;
  }
  else
  {
    printf ( "  E = %d\n", e_saved );
  }

  return;
}
/******************************************************************************/

int p01_param_get ( )

/******************************************************************************/
/*
  Purpose:

    P01_PARAM_GET gets the value of the parameter for test function 1.

  Discussion:

    The parameter E is the exponent of X^E.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Output, int P01_PARAM_GET, the value of the parameter.
*/
{
  int e;

  p01_param ( "GET", &e );

  return e;
}
/******************************************************************************/

void p01_param_set ( int e )

/******************************************************************************/
/*
  Purpose:

    P01_PARAM_SET sets the parameter for test function 1.

  Discussion:

    The parameter E is the exponent of X^E.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int E, the value of the parameter.
*/
{
  p01_param ( "SET", &e );

  return;
}
/******************************************************************************/

double p02_exact ( )

/******************************************************************************/
/*
  Purpose:

    P02_EXACT returns the exact integral of function 2 over the unit circle.

  Discussion:

    The integral depends on a parameter E which must be set by calling
    P02_PARAM_SET ( E ) before calling this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 December 2013

  Author:

    John Burkardt

  Parameters:

    Output, double P02_EXACT, the exact integral.
*/
{
  int e;
  const double r8_pi = 3.141592653589793;
  double value;

  e = p02_param_get ( );

  value = 2.0 * r8_pi / ( double ) ( e + 2 );

  return value;
}
/******************************************************************************/

double *p02_f ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    P02_F evaluates test function #2 in the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of variables.

    Input, double X[2*N], the arguments.

    Output, double P02_F[N], the values of the integrand.
*/
{
  int e;
  double *fx;
  int j;
  double r;

  e = p02_param_get ( );

  fx = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    r = sqrt ( pow ( x[0+j*2], 2 ) + pow ( x[1+j*2], 2 ) );
    fx[j] = pow ( r, e );
  }

  return fx;
}
/******************************************************************************/

void p02_param ( char *action, int *e )

/******************************************************************************/
/*
  Purpose:

    P02_PARAM sets or gets the value of the parameter for test function 2.

  Discussion:

    The parameter E is the exponent of X^E.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, char *ACTION, indicates which action is desired.
    'G' will get the parameter value.
    'S' will set the parameter value.

    Input/output, int *E.
    If ACTION is 'S', then on input this is the new value of the parameter,
    If ACTION is 'G', then on output this is the stored value of the parameter.
*/
{
  static int e_saved = 0;

  if ( action[0] == 'g' || action[0] == 'G' )
  {
    *e = e_saved;
  }
  else if ( action[0] == 's' || action[0] == 'S' )
  {
    e_saved = *e;
  }
  else
  {
    printf ( "  E = %d\n", e_saved );
  }

  return;
}
/******************************************************************************/

int p02_param_get ( )

/******************************************************************************/
/*
  Purpose:

    P02_PARAM_GET gets the value of the parameter for test function 2.

  Discussion:

    The parameter E is the exponent of R^E.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Output, int P02_PARAM_GET, the value of the parameter.
*/
{
  int e;

  p02_param ( "GET", &e );

  return e;
}
/******************************************************************************/

void p02_param_set ( int e )

/******************************************************************************/
/*
  Purpose:

    P02_PARAM_SET sets the parameter for test function 2.

  Discussion:

    The parameter E is the exponent of R^E.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int E, the value of the parameter.
*/
{
  p02_param ( "SET", &e );

  return;
}
/******************************************************************************/

double p03_exact ( )

/******************************************************************************/
/*
  Purpose:

    P03_EXACT returns the exact integral of function 3 over the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Output, double P03_EXACT, the exact integral.
*/
{
  const double r8_pi = 3.141592653589793;
  double value;
  
  value = 2.0 * r8_pi * 0.565159103992485;

  return value;
}
/******************************************************************************/

double *p03_f ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    P03_F evaluates test function #3 in the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of variables.

    Input, double X[2*N], the arguments.

    Output, double P03_F[N], the values of the integrand.
*/
{
  double *fx;
  int i;

  fx = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    fx[i] = exp ( x[0+i*2] );
  }
  return fx;
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

double *r8vec_uniform_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.

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

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
}
/******************************************************************************/

double sin_power_int ( double a, double b, int n )

/******************************************************************************/
/*
  Purpose:

    SIN_POWER_INT evaluates the sine power integral.

  Discussion:

    The function is defined by

      SIN_POWER_INT(A,B,N) = Integral ( A <= T <= B ) ( sin ( t ))^n dt

    The algorithm uses the following fact:

      Integral sin^n ( t ) = (1/n) * (
        sin^(n-1)(t) * cos(t) + ( n-1 ) * Integral sin^(n-2) ( t ) dt )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 September 2004

  Author:

    John Burkardt

  Parameters

    Input, double A, B, the limits of integration.

    Input, integer N, the power of the sine function.

    Output, double SIN_POWER_INT, the value of the integral.
*/
{
  double ca;
  double cb;
  int m;
  int mlo;
  double sa;
  double sb;
  double value;

  if ( n < 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "SIN_POWER_INT - Fatal error!\n" );
    fprintf ( stderr, "  Power N < 0.\n" );
    exit ( 1 );
  }

  sa = sin ( a );
  sb = sin ( b );
  ca = cos ( a );
  cb = cos ( b );

  if ( ( n % 2 ) == 0 )
  {
    value = b - a;
    mlo = 2;
  }
  else
  {
    value = ca - cb;
    mlo = 3;
  }

  for ( m = mlo; m <= n; m = m + 2 )
  {
    value = ( ( double ) ( m - 1 ) * value 
      + pow ( sa, (m-1) ) * ca - pow ( sb, (m-1) ) * cb ) 
      / ( double ) ( m );
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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
