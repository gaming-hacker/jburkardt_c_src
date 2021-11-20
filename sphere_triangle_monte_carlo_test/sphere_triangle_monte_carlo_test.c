# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

# include "sphere_triangle_monte_carlo.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SPHERE_TRIANGLE_MONTE_CARLO_TEST.

  Discussion:

    SPHERE_TRIANGLE_MONTE_CARLO_TEST tests the SPHERE_TRIANGLE_MONTE_CARLO 
    library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SPHERE_TRIANGLE_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SPHERE_TRIANGLE_MONTE_CARLO library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SPHERE_TRIANGLE_MONTE_CARLO_TEST\n" );
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

    TEST01 uses SPHERE_TRIANGLE_SAMPLE_01 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2014

  Author:

    John Burkardt
*/
{
# define M 3

  double area;
  int e[M];
  int e_test[M*7] = {
    0, 0, 0, 
    2, 0, 0, 
    0, 2, 0, 
    0, 0, 2, 
    4, 0, 0, 
    2, 2, 0, 
    0, 0, 4 };
  int i;
  int j;
  int k;
  int m = M;
  int n;
  double result;
  int seed;
  double shrink;
  double v1[M];
  double v2[M];
  double v3[M];
  double wc[M];
  double *w1;
  double *w2;
  double *w3;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Estimate monomial integrals over a sphere triangle\n" );
  printf ( "  using the Monte Carlo method.\n" );

  seed = 123456789;
/*
  Choose three points at random to define a spherical triangle.
*/
  w1 = sphere01_sample ( 1, &seed );
  w2 = sphere01_sample ( 1, &seed );
  w3 = sphere01_sample ( 1, &seed );

  for ( i = 0; i < m; i++ )
  {
    wc[i] = ( w1[i] + w2[i] + w3[i] ) / 3.0;
  }
  r8vec_normalize ( m, wc );
/*
  Shrink triangle by factor F.
*/
  shrink = 2.0;

  for ( k = 1; k <= 3; k++ )
  {
    shrink = shrink / 2.0;

    for ( i = 0; i < m; i++ )
    {
      v1[i] = wc[i] + shrink * ( w1[i] - wc[i] );
      v2[i] = wc[i] + shrink * ( w2[i] - wc[i] );
      v3[i] = wc[i] + shrink * ( w3[i] - wc[i] );
    }
    r8vec_normalize ( m, v1 );
    r8vec_normalize ( m, v2 );
    r8vec_normalize ( m, v3 );

    area = sphere01_triangle_vertices_to_area ( v1, v2, v3 );

    printf ( "\n" );
    printf ( "  Vertices of random spherical triangle\n" );
    printf ( "  with shrink factor = %g\n", shrink );
    printf ( "  and area = %g\n", area );
    printf ( "\n" );
    r8vec_transpose_print ( m, v1, "  V1:" );
    r8vec_transpose_print ( m, v2, "  V2:" );
    r8vec_transpose_print ( m, v3, "  V3:" );
/*
  Estimate integrals.
*/
    printf ( "\n" );
    printf ( "         N        1              X^2             Y^2" );
    printf ( "             Z^2             X^4           X^2Y^2           Z^4\n" );
    printf ( "\n" );

    n = 1;

    while ( n <= 4 * 65536 )
    {
      x = sphere01_triangle_sample ( n, v1, v2, v3, &seed );

      printf ( "  %8d", n );
      for ( j = 0; j < 7; j++ )
      {
        for ( i = 0; i < m; i++ )
        {
          e[i] = e_test[i+j*m];
        }
        value = monomial_value ( m, n, e, x );

        result = area * r8vec_sum ( n, value ) / ( double ) ( n );
        printf ( "  %14.6g", result );
      }

      printf ( "\n" );

      free ( value );
      free ( x );

      n = 2 * n;
    }
  }

  free ( w1 );
  free ( w2 );
  free ( w3 );

  return;
# undef M
}
