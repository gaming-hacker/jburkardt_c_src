# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "square_minimal_rule.h"

int main ( );
void square_minimal_rule_print_test ( int degree );
void square_minimal_rule_order_test ( );
void square_minimal_rule_error_max_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SQUARE_MINIMAL_RULE_TEST.

  Discussion:

    SQUARE_MINIMAL_RULE_TEST tests the SQUARE_MINIMAL_RULE library.
    
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    John Burkardt
*/
{
  int degree;

  timestamp ( );
  printf ( "\n" );
  printf ( "SQUARE_MINIMAL_RULE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SQUARE_MINIMAL_RULE library.\n" );

  degree = 8;
  square_minimal_rule_print_test ( degree );

  square_minimal_rule_order_test ( );

  square_minimal_rule_error_max_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SQUARE_MINIMAL_RULE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void square_minimal_rule_print_test ( int degree )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE_PRINT_TEST tests SQUARE_MINIMAL_RULE_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    John Burkardt
*/
{
  double area;
  double d;
  int j;
  int order;
  double *xyw;

  printf ( "\n" );
  printf ( "SQUARE_MINIMAL_RULE_PRINT_TEST\n" );
  printf ( "  SQUARE_MINIMAL_RULE_PRINT prints a quadrature rule\n" );
  printf ( "  for the symmetric unit square.\n" );
  printf ( "  Minimal quadrature rule for a square.\n" );
  printf ( "  Polynomial exactness degree DEGREE = %d\n", degree );
/*
  Retrieve and print a symmetric quadrature rule.
*/
  xyw = square_minimal_rule ( degree );

  order = square_minimal_rule_order ( degree );

  printf ( "\n" );
  printf ( "  Number of nodes N = %d\n", order );

  printf ( "\n" );
  printf ( "     J          X               Y               W\n" );
  printf ( "\n" );
  for ( j = 0; j < order; j++ )
  {
    printf ( "  %4d  %14.6g  %14.6g  %14.6g\n", 
      j, xyw[0+j*3], xyw[1+j*3], xyw[2+j*3] );
  }

  d = 0.0;
  for ( j = 0; j < order; j++ )
  {
    d = d + xyw[2+j*3];
  }

  printf ( "\n" );
  printf ( "   Sum  %14.6g\n", d );
  area = squaresym_area ( );
  printf ( "  Area  %14.6g\n", area );

  free ( xyw );

  return;
}
/******************************************************************************/

void square_minimal_rule_order_test ( )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE_ORDER_TEST tests SQUARE_MINIMAL_RULE_ORDER.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    21 February 2018

  Author:

    John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.
*/
{
  int degree;
  int degree_max;
  int order;

  printf ( "\n" );
  printf ( "SQUARE_MINIMAL_RULE_ORDER_TEST\n" );
  printf ( "  Print the order (number of points) for each\n" );
  printf ( "  minimal square rule.\n" );

  degree_max = square_minimal_rule_degree_max ( );

  printf ( "\n" );
  printf ( " Degree  Order\n" );
  printf ( "\n" );
  for ( degree = 0; degree <= degree_max; degree++ )
  {
    order = square_minimal_rule_order ( degree );
    printf ( "  %4d  %4d\n", degree, order );
  }

  return;
}
/******************************************************************************/

void square_minimal_rule_error_max_test ( )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE_ERROR_MAX_TEST tests SQUARE_MINIMAL_RULE_ERROR_MAX.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    21 February 2018

  Author:

    John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.
*/
{
  int degree;
  int degree_max;
  double error_max;
  int m_num;

  printf ( "\n" );
  printf ( "SQUARE_MINIMAL_RULE_ERROR_MAX_TEST\n" );
  printf ( "  SQUARE_MINIMAL_RULE_ERROR_MAX computes the maximum\n" );
  printf ( "  error for a rule that should be exact for all monomials\n" );
  printf ( "  up to a given value of DEGREE.\n" );

  degree_max = square_minimal_rule_degree_max ( );

  printf ( "\n" );
  printf ( " Degree  Monomials  Error Max\n" );
  printf ( "\n" );

  for ( degree = 0; degree <= degree_max; degree++ )
  {
    error_max = square_minimal_rule_error_max ( degree );
    m_num = ( ( degree + 1 ) * ( degree + 2 ) ) / 2;
    printf ( "   %4d       %4d  %g\n", degree, m_num, error_max );
  }

  return;
}

