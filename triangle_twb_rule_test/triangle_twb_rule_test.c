# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "triangle_twb_rule.h"

int main ( );
void triangle_unit_quad_test ( int degree_max );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    triangle_twb_rule_test tests triangle_twb_rule.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 April 2019

  Author:

    John Burkardt
*/
{
  int degree_max;

  timestamp ( );
  printf ( "\n" );
  printf ( "triangle_twb_rule_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test triangle_twb_rule.\n" );

  degree_max = 5;
  triangle_unit_quad_test ( degree_max );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "triangle_twb_rule_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void triangle_unit_quad_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    triangle_unit_quad_test tests rules for the unit triangle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2019

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the monomials to check.
*/
{
  int degree;
  int ex;
  int ey;
  int n;
  double q;
  int strength;
  double *v;
  double *w;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "triangle_unit_quad_test\n" );
  printf ( "  Approximate monomial integrals in triangle with TWB rules.\n" );

  degree = 0;
  ex = 0;
  ey = degree;

  while ( true )
  {
    printf ( "\n" );
    printf ( "  Monomial: x^%d y^%d\n", ex, ey );

    for ( strength = 1; strength <= 25; strength++ )
    {
      n = twb_rule_n ( strength );
      if ( n < 1 )
      {
        continue;
      }
      w = twb_rule_w ( strength );
      x = twb_rule_x ( strength );
      y = twb_rule_y ( strength );
      v = monomial_value_2d ( n, ex, ey, x, y );
      q = r8vec_dot_product ( n, w, v );
      printf ( "  %6d  %6d %14.6g\n", strength, n, q );

      free ( v );
      free ( w );
      free ( x );
      free ( y );
    }

    q = triangle_unit_monomial ( ex, ey );
    printf ( "   Exact         %14.6g\n", q );

    if ( ex < degree )
    {
      ex = ex + 1;
      ey = ey - 1;
    }
    else if ( degree < degree_max )
    {
      degree = degree + 1;
      ex = 0;
      ey = degree;
    }
    else
    {
      break;
    }
  }

  return;
}
