# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>
# include <math.h>

# include "line_felippa_rule.h"

/******************************************************************************/

double line_monomial ( double a, double b, int expon )

/******************************************************************************/
/*
  Purpose:

    LINE_MONOMIAL: monomial integral over a line segment in 1D.

  Discussion:

    This function returns the integral of X^EXPON.

    The integration region is:
    A <= X <= B

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2014

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Input, double A, B, the lower and upper limits.

    Input, int EXPON, the exponent of X.  The exponent must not be -1.

    Output, double LINE_MONOMIAL, the integral of X^ALPHA.
*/
{
  double value;

  if ( expon == - 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "LINE_UNIT_MONOMIAL - Fatal error!\n" );
    fprintf ( stderr, "  Exponent = -1 is not a legal input.\n" );
    exit ( 1 );
  }

  value = ( pow ( b, expon + 1 ) - pow ( a, expon + 1 ) ) 
    / ( double ) ( expon + 1 );

  return value;
}
/******************************************************************************/

void line_monomial_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    LINE_MONOMIAL_TEST tests LINE_UNIT_MONOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the
    monomials to check.
*/
{
  double a = 0.0;
  double b = 1.0;
  int expon;
  double value;

  printf ( "\n" );
  printf ( "LINE_MONOMIAL_TEST\n" );
  printf ( "  For a line segment in 1D,\n" );
  printf ( "  LINE_MONOMIAL returns the exact value of the\n" );
  printf ( "  integral of X^EXPON\n" );
  printf ( "\n" );
  printf ( "  Volume = %g\n", line_volume ( a, b ) );
  printf ( "\n" );
  printf ( "     EXPON      INTEGRAL\n" );
  printf ( "\n" );

  for ( expon = 0; expon <= degree_max; expon++ )
  {
    value = line_monomial ( a, b, expon );

    printf ( "  %8d  %14.6g\n", expon, value );
  }

  return;
}
/******************************************************************************/

void line_quad_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    LINE_QUAD_TEST tests the rules for a line segment in 1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the
    monomials to check.
*/
{
  double a = 0.0;
  double b = 1.0;
  int expon;
  int j;
  int order;
  double quad;
  double *v;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LINE_QUAD_TEST\n" );
  printf ( "  For a line segment in 1D,\n" );
  printf ( "  we approximate monomial integrals with:\n" );
  printf ( "  LINE_UNIT_O01, a 1 point rule.\n" );
  printf ( "  LINE_UNIT_O02, a 2 point rule.\n" );
  printf ( "  LINE_UNIT_O03, a 3 point rule.\n" );
  printf ( "  LINE_UNIT_O04, a 4 point rule.\n" );
  printf ( "  LINE_UNIT_O05, a 5 point rule.\n" );

  for ( expon = 0; expon <= degree_max; expon++ )
  {
    printf ( "\n" );
    printf ( "  Monomial exponent:   %2d", expon );
    printf ( "\n" );

    for ( order = 1; order <= 5; order++ )
    {
      v = ( double * ) malloc ( order * sizeof ( double ) );
      w = ( double * ) malloc ( order * sizeof ( double ) );
      x = ( double * ) malloc ( order * sizeof ( double ) );

      line_rule ( a, b, order, w, x );
      for ( j = 0; j < order; j++ )
      {
        v[j] = pow ( x[j], expon );
      }
      quad = r8vec_dot_product ( order, w, v );
      printf ( "  %6d  %14.6g\n", order, quad );
      free ( v );
      free ( w );
      free ( x );
    }
    printf ( "\n" );
    quad = line_monomial ( a, b, expon );
    printf ( "   Exact  %14.6g\n", quad );
  }

  return;
}
/******************************************************************************/

void line_rule ( double a, double b, int order, double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_RULE returns a quadrature rule for a line segment in 1D.

  Discussion:

    The integration region is:
      A <= X <= B

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2014

  Author:

    John Burkardt

  Reference:

    Carlos Felippa,
    A compendium of FEM integration formulas for symbolic work,
    Engineering Computation,
    Volume 21, Number 8, 2004, pages 867-890.

  Parameters:

    Input, double A, B, the lower and upper limits.

    Input, int ORDER, the order of the rule.

    Output, double W[ORDER], the weights.

    Output, double X[ORDER], the abscissas.
*/
{
  int j;

  if ( order == 1 )
  {
    line_unit_o01 ( w, x );
  }
  else if ( order == 2 )
  {
    line_unit_o02 ( w, x );
  }
  else if ( order == 3 )
  {
    line_unit_o03 ( w, x );
  }
  else if ( order == 4 )
  {
    line_unit_o04 ( w, x );
  }
  else if ( order == 5 )
  {
    line_unit_o05 ( w, x );
  }
  else
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "LINE_RULE - Fatal error!\n" );
    fprintf ( stderr, "  Illegal value of ORDER.\n" );
    exit ( 1 );
  }
/*
  Transform from [-1,+1] to [A,B]
*/
  for ( j = 0; j < order; j++ )
  {
    w[j] = w[j] * ( b - a ) / 2.0;
    x[j] = ( ( 1.0 - x[j] ) * a   
           + ( 1.0 + x[j] ) * b ) 
           /   2.0;
  }

  return;
}
/******************************************************************************/

void line_unit_o01 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O01 returns a 1 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[1], the weights.

    Output, double X[1], the abscissas.
*/
{
  int order = 1;
  double w_save[1] = { 2.0 };
  double x_save[1] = { 0.0 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o02 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O02 returns a 2 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[2], the weights.

    Output, double X[2], the abscissas.
*/
{
  int order = 2;
  double w_save[2] = {
    1.0000000000000000000,
    1.0000000000000000000 };
  double x_save[2] = {
    -0.57735026918962576451,
     0.57735026918962576451 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o03 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O03 returns a 3 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[3], the weights.

    Output, double X[3], the abscissas.
*/
{
  int order = 3;
  double w_save[3] = {
    0.55555555555555555556,
    0.88888888888888888889,
    0.55555555555555555556 };
  double x_save[3] = {
    -0.77459666924148337704,
     0.00000000000000000000,
     0.77459666924148337704 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o04 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O04 returns a 4 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[4], the weights.

    Output, double X[4], the abscissas.
*/
{
  int order = 4;
  double w_save[4] = {
    0.34785484513745385737,
    0.65214515486254614263,
    0.65214515486254614263,
    0.34785484513745385737 };
  double x_save[4] = {
    -0.86113631159405257522,
    -0.33998104358485626480,
     0.33998104358485626480,
     0.86113631159405257522 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o05 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O05 returns a 5 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[5], the weights.

    Output, double X[5], the abscissas.
*/
{
  int order = 5;
  double w_save[5] = {
    0.23692688505618908751,
    0.47862867049936646804,
    0.56888888888888888889,
    0.47862867049936646804,
    0.23692688505618908751 };
  double x_save[5] = {
    -0.90617984593866399280,
    -0.53846931010568309104,
     0.00000000000000000000,
     0.53846931010568309104,
     0.90617984593866399280 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

double line_volume ( double a, double b )

/******************************************************************************/
/*
  Purpose:

    LINE_VOLUME: volume of a line segment in 1D.

  Discussion:

    The integration region is:
    A <= X <= B

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, the lower and upper limits.

    Output, double LINE_VOLUME, the volume of the line.
*/
{
  double volume;

  volume = b - a;

  return volume;
}
/******************************************************************************/

void r8vec_copy ( int n, double a1[], double a2[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_COPY copies an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 July 2005

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], the vector to be copied.

    Input, double A2[N], the copy of A1.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return;
}
/******************************************************************************/

double r8vec_dot_product ( int n, double a1[], double a2[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_DOT_PRODUCT computes the dot product of a pair of R8VEC's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2007

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], A2[N], the two vectors to be considered.

    Output, double R8VEC_DOT_PRODUCT, the dot product of the vectors.
*/
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a1[i] * a2[i];
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

