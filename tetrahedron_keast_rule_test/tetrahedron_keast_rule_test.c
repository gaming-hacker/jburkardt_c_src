# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "tetrahedron_keast_rule.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TETRAHEDRON_KEAST_RULE_TEST.

  Discussion:

    TETRAHEDRON_KEAST_RULE_TEST tests the TETRAHEDRON_KEAST_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2007

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TETRAHEDRON_KEAST_RULE_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TETRAHEDRON_KEAST_RULE library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TETRAHEDRON_KEAST_RULE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests KEAST_RULE_NUM, KEAST_DEGREE, KEAST_ORDER_NUM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 December 2006

  Author:

    John Burkardt
*/
{
  int degree;
  int order_num;
  int rule;
  int rule_num;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  KEAST_RULE_NUM returns the number of rules;\n" );
  printf ( "  KEAST_DEGREE returns the degree of a rule;\n" );
  printf ( "  KEAST_ORDER_NUM returns the order of a rule.\n" );

  rule_num = keast_rule_num ( );

  printf ( "\n" );
  printf ( "  Number of available rules = %d\n", rule_num );
  printf ( "\n" );
  printf ( "      Rule    Degree     Order\n" );
  printf ( "\n" );

  for ( rule = 1; rule <= rule_num; rule++ )
  {
    order_num = keast_order_num ( rule );
    degree = keast_degree ( rule );
    printf ( "  %8d  %8d  %8d\n", rule, degree, order_num );
  }

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests KEAST_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 December 2006

  Author:

    John Burkardt
*/
{
  int order;
  int order_num;
  int rule;
  int rule_num;
  double *wtab;
  double wtab_sum;
  double *xyztab;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  KEAST_RULE returns the points and weights\n" );
  printf ( "  of a Keast rule for the triangle.\n" );
  printf ( "\n" );
  printf ( "  In this test, we simply check that the weights\n" );
  printf ( "  sum to 1.\n" );

  rule_num = keast_rule_num ( );

  printf ( "\n" );
  printf ( "  Number of available rules = %d\n", rule_num );

  printf ( "\n" );
  printf ( "      Rule      Order     Sum of weights\n" );
  printf ( "\n" );

  for ( rule = 1; rule <= rule_num; rule++ )
  {
    order_num = keast_order_num ( rule );

    xyztab = ( double * ) malloc ( 3 * order_num * sizeof ( double ) );
    wtab = ( double * ) malloc ( order_num * sizeof ( double ) );

    keast_rule ( rule, order_num, xyztab, wtab );

    wtab_sum = 0.0;
    for ( order = 0; order < order_num; order++ )
    {
      wtab_sum = wtab_sum + wtab[order];
    }

    printf ( "  %8d  %8d  %14.6g\n", rule, order_num, wtab_sum );

    free ( wtab );
    free ( xyztab );
  }
  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests KEAST_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 December 2006

  Author:

    John Burkardt
*/
{
  int rule;
  int rule_num;
  int suborder;
  int suborder_num;
  double *suborder_w;
  double *suborder_xyzz;
  double xyzz_sum;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  KEAST_RULE returns the points and weights\n" );
  printf ( "  of a Keast rule for the triangle.\n" );
  printf ( "\n" );
  printf ( "  In this test, we simply check that, for each\n" );
  printf ( "  quadrature point, the barycentric coordinates\n" );
  printf ( "  add up to 1.\n" );

  rule_num = keast_rule_num ( );

  printf ( "\n" );
  printf ( "      Rule    Suborder    Sum of coordinates\n" );
  printf ( "\n" );

  for ( rule = 1; rule <= rule_num; rule++ )
  {
    suborder_num = keast_suborder_num ( rule );

    suborder_xyzz = ( double * ) malloc ( 4 * suborder_num * sizeof ( double ) );
    suborder_w = ( double * ) malloc ( suborder_num * sizeof ( double ) );

    keast_subrule ( rule, suborder_num, suborder_xyzz, suborder_w );

    printf ( "\n" );
    printf ( "  %8d  %8d\n", rule, suborder_num );

    for ( suborder = 0; suborder < suborder_num; suborder++ )
    {
      xyzz_sum = suborder_xyzz[0+suborder*4]
               + suborder_xyzz[1+suborder*4]
               + suborder_xyzz[2+suborder*4]
               + suborder_xyzz[3+suborder*4];
     printf ( "                      %25.16g\n", xyzz_sum );
    }

    free ( suborder_w );
    free ( suborder_xyzz );
  }
  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 demonstrates TETRAHEDRON_REFERENCE_TO_PHYSICAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 December 2006

  Author:

    John Burkardt
*/
{
# define NODE_NUM 4

  int node;
  double node_xyz[3*NODE_NUM] = {
    0.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0 };
  double node_xyz2[3*NODE_NUM] = {
    1.0, 2.0, 3.0,
    2.0, 2.0, 3.0,
    1.0, 3.0, 3.0,
    1.0, 2.0, 9.0 };
  int order;
  int order_num;
  int rule;
  double volume;
  double volume2;
  double *w;
  double *xyz;
  double *xyz2;

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  TETRAHEDRON_REFERENCE_TO_PHYSICAL transforms a rule\n" );
  printf ( "  on the unit (reference) tetrahedron to a rule on \n" );
  printf ( "  an arbitrary (physical) tetrahedron.\n" );

  rule = 2;

  order_num = keast_order_num ( rule );

  xyz = ( double * ) malloc ( 3 * order_num * sizeof ( double ) );
  xyz2 = ( double * ) malloc ( 3 * order_num * sizeof ( double ) );
  w = ( double * ) malloc ( order_num * sizeof ( double ) );

  keast_rule ( rule, order_num, xyz, w );
/*
  Here is the reference tetrahedron, and its rule.
*/
  printf ( "\n" );
  printf ( "  The reference tetrahedron:\n" );
  printf ( "\n" );

  for ( node = 0; node < NODE_NUM; node++ )
  {
    printf ( "  %8d  %14.6g  %14.6g  %14.6g\n", 
      node+1, node_xyz[0+node*3], node_xyz[1+node*3], node_xyz[2+node*3] );
  }

  volume = tetrahedron_volume ( node_xyz );

  printf ( "\n" );
  printf ( "  Rule %d for reference tetrahedron\n", rule );
  printf ( "  with volume = %g\n", volume );
  printf ( "\n" );
  printf ( "                X               Y               Z             W\n" );
  printf ( "\n" );

  for ( order = 0; order < order_num; order++ )
  {
    printf ( "  %8d  %14.6g  %14.6g  %14.6g  %14.6g\n",
      order, xyz[0+order*3], xyz[1+order*3], xyz[2+order*3], w[order] );
  }
/*
  Transform the rule.
*/
  tetrahedron_reference_to_physical ( node_xyz2, order_num, xyz, xyz2 );
/*
  Here is the physical tetrahedron, and its transformed rule.
*/
  printf ( "\n" );
  printf ( "  The physical tetrahedron:\n" );
  printf ( "\n" );

  for ( node = 0; node < NODE_NUM; node++ )
  {
    printf ( "  %8d  %14.6g  %14.6g  %14.6g\n",
      node+1, node_xyz2[0+node*3], node_xyz2[1+node*3], node_xyz2[2+node*3] );
  }

  volume2 = tetrahedron_volume ( node_xyz2 );

  printf ( "\n" );
  printf ( "  Rule %d for physical tetrahedron\n", rule );
  printf ( "  with volume = %g\n", volume2 );
  printf ( "\n" );
  printf ( "                X               Y               Z             W\n" );
  printf ( "\n" );

  for ( order = 0; order < order_num; order++ )
  {
    printf ( "  %8d  %14.6g  %14.6g  %14.6g  %14.6g\n",
      order, xyz2[0+order*3], xyz2[1+order*3], xyz2[2+order*3], w[order] );
  }

  free ( w );
  free ( xyz );
  free ( xyz2 );

  return;
# undef NODE_NUM
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests KEAST_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 July 2008

  Author:

    John Burkardt
*/
{
  int degree;
  int degree_max = 3;
  int dim_num = 3;
  int expon[3];
  int h;
  double *mono;
  bool more;
  int order_num;
  double quad;
  int rule;
  int rule_num;
  int t;
  double *w;
  double *xyz;

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Demonstrate the KEAST rules on a sequence of\n" );
  printf ( "  monomial integrands X^A Y^B Z^C\n" );
  printf ( "  on the unit tetrahedron.\n" );

  rule_num = keast_rule_num ( );

  printf ( "\n" );
  printf ( "      Rule     Order     Quad\n" );
  printf ( "\n" );

  for ( degree = 0; degree <= degree_max; degree++ )
  {
    more = false;
    h = 0;
    t = 0;

    for ( ; ; )
    {
      comp_next ( degree, dim_num, expon, &more, &h, &t );

      printf ( "\n" );
      printf ( "  F(X,Y,Z) = X^%d * Y^%d * Z^%d\n", expon[0], expon[1], expon[2] );
      printf ( "\n" );

      for ( rule = 1; rule <= rule_num; rule++ )
      {
        order_num = keast_order_num ( rule );

        xyz = ( double * ) malloc ( 3 * order_num * sizeof ( double ) );
        w = ( double * ) malloc ( order_num * sizeof ( double ) );

        keast_rule ( rule, order_num, xyz, w );

        mono = monomial_value ( dim_num, order_num, xyz, expon );

        quad = r8vec_dot ( order_num, w, mono );

        printf ( "  %8d  %8d  %14.6g\n", rule, order_num, quad );

        free ( mono );
        free ( w );
        free ( xyz );
      }
      if ( !more )
      {
        break;
      }
    }
  }
  return;
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests KEAST_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2007

  Author:

    John Burkardt
*/
{
  int degree;
  int order;
  int order_num;
  int rule;
  double *w;
  double *xyz;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  KEAST_RULE returns the points and weights\n" );
  printf ( "  of a Keast rule for the triangle.\n" );
  printf ( "\n" );
  printf ( "  In this test, we simply print a rule.\n" );

  rule = 10;
  degree = keast_degree ( rule );
  order_num = keast_order_num ( rule );

  printf ( "\n" );
  printf ( "  Rule =   %d\n", rule );
  printf ( "  Degree = %d\n", degree );
  printf ( "  Order =  %d\n", order_num );

  printf ( "\n" );
  printf ( "         I      W               X               Y               Z\n" );
  printf ( "\n" );

  xyz = ( double * ) malloc ( 3 * order_num * sizeof ( double ) );
  w = ( double * ) malloc ( order_num * sizeof ( double ) );

  keast_rule ( rule, order_num, xyz, w );

  for ( order = 0; order < order_num; order++ )
  {
    printf ( "  %8d  %14.6g  %14.6g  %14.6g  %14.6g\n",
      order, w[order], xyz[0+order*3], xyz[1+order*3], xyz[2+order*3] );
  }

  free ( w );
  free ( xyz );

  return;
}
