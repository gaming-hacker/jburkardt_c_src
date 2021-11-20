# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "tetrahedron_felippa_rule.h"

int main ( );
void tetrahedron_unit_monomial_test ( int degree_max );
void tetrahedron_unit_quad_test ( int degree_max );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TETRAHEDRON_FELIPPA_RULE_TEST.

  Discussion:

    TETRAHEDRON_FELIPPA_RULE_TEST tests the TETRAHEDRON_FELIPPA_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2014

  Author:

    John Burkardt
*/
{
  int degree_max;

  timestamp ( );
  printf ( "\n" );
  printf ( "TETRAHEDRON_FELIPPA_RULE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TETRAHEDRON_FELIPPA_RULE library.\n" );

  degree_max = 4;
  tetrahedron_unit_monomial_test ( degree_max );

  degree_max = 4;
  tetrahedron_unit_quad_test ( degree_max );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TETRAHEDRON_FELIPPA_RULE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void tetrahedron_unit_monomial_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_UNIT_MONOMIAL_TEST tests TETRAHEDRON_UNIT_MONOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the
    monomials to check.
*/
{
  int alpha;
  int beta;
  int expon[3];
  int gamma;
  double value;

  printf ( "\n" );
  printf ( "TETRAHEDRON_UNIT_MONOMIAL_TEST\n" );
  printf ( "  For the unit tetrahedron,\n" );
  printf ( "  TETRAHEDRON_UNIT_MONOMIAL returns the exact value of the\n" );
  printf ( "  integral of X^ALPHA Y^BETA Z^GAMMA\n" );
  printf ( "\n" );
  printf ( "  Volume = %g\n", tetrahedron_unit_volume ( ) );
  printf ( "\n" );
  printf ( "     ALPHA      BETA     GAMMA      INTEGRAL\n" );
  printf ( "\n" );

  for ( alpha = 0; alpha <= degree_max; alpha++ )
  {
    expon[0] = alpha;
    for ( beta = 0; beta <= degree_max - alpha; beta++ )
    {
      expon[1] = beta;
      for ( gamma = 0; gamma <= degree_max - alpha - beta; gamma++ )
      {
        expon[2] = gamma;

        value = tetrahedron_unit_monomial ( expon );

        printf ( "  %8d  %8d  %8d  %14.6g\n", 
          expon[0], expon[1], expon[2], value );
      }
    }
  }

  return;
}
/******************************************************************************/

void tetrahedron_unit_quad_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_UNIT_QUAD_TEST tests the rules for the unit tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 April 2008

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the
    monomials to check.
*/
{
# define DIM_NUM 3

  int dim;
  int dim_num = DIM_NUM;
  int expon[DIM_NUM];
  int h;
  int more;
  int order;
  double quad;
  int t;
  double *v;
  double *w;
  double *xyz;

  printf ( "\n" );
  printf ( "TETRAHEDRON_UNIT_QUAD_TEST\n" );
  printf ( "  For the unit tetrahedron,\n" );
  printf ( "  we approximate monomial integrals with:\n" );
  printf ( "  TETRAHEDRON_UNIT_O01,\n" );
  printf ( "  TETRAHEDRON_UNIT_O04,\n" );
  printf ( "  TETRAHEDRON_UNIT_O08,\n" );
  printf ( "  TETRAHEDRON_UNIT_O08b,\n" );
  printf ( "  TETRAHEDRON_UNIT_O14,\n" );
  printf ( "  TETRAHEDRON_UNIT_O14b,\n" );
  printf ( "  TETRAHEDRON_UNIT_O15,\n" );
  printf ( "  TETRAHEDRON_UNIT_O15b,\n" );
  printf ( "  TETRAHEDRON_UNIT_O24,\n" );

  more = 0;

  for ( ; ; )
  {
    subcomp_next ( degree_max, dim_num, expon, &more, &h, &t );

    printf ( "\n" );
    printf ( "  Monomial exponents: " );
    for ( dim = 0; dim < dim_num; dim++ )
    {
      printf ( "  %2d", expon[dim] );
    }
    printf ( "\n" );
    printf ( "\n" );

    order = 1;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o01 ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 4;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o04 ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 8;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o08 ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 8;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o08b ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 14;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o14 ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 14;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o14b ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 15;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o15 ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 15;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o15b ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    order = 24;
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xyz = ( double * ) malloc ( dim_num * order * sizeof ( double ) );
    tetrahedron_unit_o24 ( w, xyz );
    v = monomial_value ( dim_num, order, expon, xyz );
    quad = tetrahedron_unit_volume ( ) * r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %14.6g\n", order, quad );
    free ( v );
    free ( w );
    free ( xyz );

    printf ( "\n" );
    quad = tetrahedron_unit_monomial ( expon );
    printf ( "   Exact  %14.6g\n", quad );

    if ( !more )
    {
      break;
    }
  }

  return;
# undef DIM_NUM
}
