# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "simplex_gm_rule.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SIMPLEX_GM_RULE_TEST.

  Discussion:

    SIMPLEX_GM_RULE_TEST tests the SIMPLEX_GM_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SIMPLEX_GM_RULE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SIMPLEX_GM_RULE library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );
  test10 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SIMPLEX_GM_RULE_TEST\n" );
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

    TEST01 tests SIMPLEX_UNIT_TO_GENERAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m = 2;
  int n = 10;
  double *phy;
  double phy_unit[2*(2+1)];
  double *ref;
  int seed = 123456789;
  double t[2*(2 + 1 )] = {
    1.0, 1.0,
    3.0, 1.0,
    2.0, 5.0 };
  double t_unit[2*(2 + 1 )] = {
    0.0, 0.0,
    1.0, 0.0,
    0.0, 1.0 };

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  SIMPLEX_UNIT_TO_GENERAL\n" );
  printf ( "  maps points in the unit simplex to a general simplex.\n" );
  printf ( "\n" );
  printf ( "  Here we consider a simplex in 2D, a triangle.\n" );
  printf ( "\n" );
  printf ( "  The vertices of the general triangle are:\n" );
  printf ( "\n" );
  for ( j = 0; j < m + 1; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %8g", t[i+j*m] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "   (  XSI     ETA )   ( X       Y  )\n" );
  printf ( "\n" );

  simplex_unit_to_general ( m, m + 1, t, t_unit, phy_unit );

  for ( j = 0; j < m + 1; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %9g", t_unit[i+j*m] );
    }
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %9g", phy_unit[i+j*m] );
    }
    printf ( "\n" );
  }
  ref = simplex_unit_sample ( m, n, &seed );
  phy = ( double * ) malloc ( m * n * sizeof ( double ) );

  simplex_unit_to_general ( m, n, t, ref, phy );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %9g", ref[i+j*m] );
    }
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %9g", phy[i+j*m] );
    }
    printf ( "\n" );
  }

  free ( phy );
  free ( ref );

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests SIMPLEX_UNIT_TO_GENERAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
  int dim;
  int vertex_num = 3 + 1;
  int j;
  int m = 3;
  int n = 10;
  double *phy;
  double phy_unit[3*(3+1)];
  double *ref;
  int seed = 123456789;
  double t[3*(3 + 1 )] = {
    1.0, 1.0, 1.0,
    3.0, 1.0, 1.0,
    1.0, 4.0, 1.0,
    1.0, 1.0, 5.0 };
  double t_unit[3*(3 + 1 )] = {
    0.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0 };

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  SIMPLEX_UNIT_TO_GENERAL\n" );
  printf ( "  maps points in the unit simplex to a general simplex.\n" );
  printf ( "\n" );
  printf ( "  Here we consider a simplex in 3D, a tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  The vertices of the general tetrahedron are:\n" );
  printf ( "\n" );
  for ( j = 0; j < vertex_num; j++ )
  {
    for ( dim = 0; dim < m; dim++ )
    {
      printf ( "  %8g", t[dim+j*m] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "   (  XSI     ETA     MU )    ( X       Y       Z )\n" );
  printf ( "\n" );

  simplex_unit_to_general ( m, m+1, t, t_unit, phy_unit );

  for ( j = 0; j < m + 1; j++ )
  {
    for ( dim = 0; dim < m; dim++ )
    {
      printf ( "  %9g", t_unit[dim+j*m] );
    }
    for ( dim = 0; dim < m; dim++ )
    {
      printf ( "  %9g", phy_unit[dim+j*m] );
    }
    printf ( "\n" );
  }

  ref = simplex_unit_sample ( m, n, &seed );
  phy = ( double * ) malloc ( m * n * sizeof ( double ) );

  simplex_unit_to_general ( m, n, t, ref, phy );

  for ( j = 0; j < n; j++ )
  {
    for ( dim = 0; dim < m; dim++ )
    {
      printf ( "  %9g", ref[dim+j*m] );
    }
    for ( dim = 0; dim < m; dim++ )
    {
      printf ( "  %9g", phy[dim+j*m] );
    }
    printf ( "\n" );
  }

  free ( phy );
  free ( ref );

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests GM_RULE_SIZE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
# define TEST_NUM 4

  int degree;
  int m;
  int m_test[TEST_NUM] = { 2, 3, 5, 10 };
  int n;
  int rule;
  int test;
  int test_num = TEST_NUM;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  GM_RULE_SIZE returns N, the number of points\n" );
  printf ( "  associated with a Grundmann-Moeller quadrature rule\n" );
  printf ( "  for the unit simplex of dimension M\n" );
  printf ( "  with rule index RULE\n" );
  printf ( "  and degree of exactness DEGREE = 2*RULE+1.\n" );

  printf ( "\n" );
  printf ( "         M      RULE    DEGREE      N\n" );

  for ( test = 0; test < test_num; test++ )
  {
    m = m_test[test];

    printf ( "\n" );

    for ( rule = 0; rule <= 5; rule++ )
    {
      n = gm_rule_size ( rule, m );
      degree = 2 * rule + 1;

      printf ( "  %8d  %8d  %8d  %8d\n", m, rule, degree, n );
    }
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 tests GM_UNIT_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
  int dim;
  int m;
  int n;
  int point;
  int rule;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  GM_UNIT_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional unit simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );

  m = 3;
  rule = 2;

  printf ( "\n" );
  printf ( "  Here we use M = %d\n", m );
  printf ( "  RULE = %d\n", rule );
  printf ( "  DEGREE = %d\n", 2 * rule + 1 );

  n = gm_rule_size ( rule, m );

  w = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( m * n * sizeof ( double ) );

  gm_unit_rule_set ( rule, m, n, w, x );

  printf ( "\n" );
  printf ( "     POINT        W             X             Y             Z\n" );
  printf ( "\n" );

  for ( point = 0; point < n; point++ )
  {
    printf ( "  %8d  %12g", point + 1, w[point] );
    for ( dim = 0; dim < m; dim++ )
    {
      printf ( "  %12g", x[dim+point*m] );
    }
    printf ( "\n" );
  }

  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests GM_UNIT_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
# define TEST_NUM 4

  int m;
  int m_test[TEST_NUM] = { 2, 3, 5, 10 };
  int n;
  int point;
  int rule;
  int test;
  int test_num = TEST_NUM;
  double *w;
  double w_sum;
  double *x;

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  GM_UNIT_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional unit simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );
  printf ( "\n" );
  printf ( "  In this test, we compute various rules, and simply\n" );
  printf ( "  report the number of points, and the sum of weights.\n" );

  printf ( "\n" );
  printf ( "         M      RULE           N  WEIGHT SUM\n" );

  for ( test = 0; test < test_num; test++ )
  {
    m = m_test[test];

    printf ( "\n" );

    for ( rule = 0; rule <= 5; rule++ )
    {
      n = gm_rule_size ( rule, m );

      w = ( double * ) malloc ( n * sizeof ( double ) );
      x = ( double * ) malloc ( m * n * sizeof ( double ) );

      gm_unit_rule_set ( rule, m, n, w, x );

      w_sum = 0.0;
      for ( point = 0; point < n; point++ )
      {
        w_sum = w_sum + w[point];
      }

      printf ( "  %8d  %8d  %8d  %24.16g\n", m, rule, n, w_sum );

      free ( w );
      free ( x );
    }
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests GM_UNIT_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
  int dim;
  int m;
  int n;
  int point;
  int rule;
  double *w;
  char w_file[127];
  FILE *w_unit;
  double *x;
  char x_file[127];
  FILE *x_unit;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  GM_UNIT_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional unit simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );
  printf ( "\n" );
  printf ( "  In this test, we write a rule to a file.\n" );

  m = 3;
  rule = 2;

  printf ( "\n" );
  printf ( "  Here we use M = %d\n", m  );
  printf ( "  RULE = %d\n", rule );
  printf ( "  DEGREE = %d\n", 2 * rule + 1 );

  n = gm_rule_size ( rule, m );

  w = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( m * n * sizeof ( double ) );

  gm_unit_rule_set ( rule, m, n, w, x );

  sprintf ( w_file, "gm%d_%dd_w.txt", rule, m );

  w_unit = fopen ( w_file, "wt" );

  for ( point = 0; point < n; point++ )
  {
    fprintf ( w_unit, "%20.16g\n", w[point] );
  }

  fclose ( w_unit );

  sprintf ( x_file, "gm%d_%dd_x.txt", rule, m );

  x_unit = fopen ( x_file, "wt" );

  for ( point = 0; point < n; point++ )
  {
    for ( dim = 0; dim < m; dim++ )
    {
      fprintf ( x_unit, "%20.16g", x[dim+point*m] );
    }
    fprintf ( x_unit, "\n" );
  }

  fclose ( x_unit );

  printf ( "\n" );
  printf ( "  Wrote rule %d to \"%s\" and \"%s\".\n", rule, w_file, x_file );

  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void test07 ( )

/******************************************************************************/
/*
  Purpose:

    TEST07 tests GM_UNIT_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2012

  Author:

    John Burkardt
*/
{
  int degree;
  int degree_max = 4;
  int *expon;
  int h;
  int m = 5;
  double *mono;
  int more;
  int n;
  double quad_error;
  int rule;
  int rule_max = 3;
  int t;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  GM_UNIT_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional unit simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );
  printf ( "\n" );
  printf ( "  In this test, look at all the monomials up to\n" );
  printf ( "  some maximum degree, choose a few low order rules\n" );
  printf ( "  and determine the quadrature error for each.\n" );
  printf ( "\n" );
  printf ( "  Here we use M = %d\n", m );

  printf ( "\n" );
  printf ( "      Rule     Order     Quad_Error\n" );
  printf ( "\n" );

  expon = ( int * ) malloc ( m * sizeof ( int ) );

  for ( degree = 0; degree <= degree_max; degree++ )
  {
    more = 0;

    for ( ; ; )
    {
      comp_next ( degree, m, expon, &more, &h, &t );

      printf ( "\n" );
      printf ( "  F(X) = X1^%d * X2^%d * X3^%d * X4^%d * X5^%d\n", 
        expon[0], expon[1], expon[2], expon[3], expon[4] );
      printf ( "\n" );

      for ( rule = 0; rule <= rule_max; rule++ )
      {
        n = gm_rule_size ( rule, m );

        mono = ( double * ) malloc ( n * sizeof ( double ) );
        w = ( double * ) malloc ( n * sizeof ( double ) );
        x = ( double * ) malloc ( m * n * sizeof ( double ) );

        gm_unit_rule_set ( rule, m, n, w, x );

        quad_error = simplex_unit_monomial_quadrature ( m, expon,
          n, x, w );

        printf ( "  %8d  %8d  %14g\n", rule, n, quad_error );

        free ( mono );
        free ( w );
        free ( x );
      }

      if ( ! more )
      {
        break;
      }
    }
  }

  free ( expon );

  return;
}
/******************************************************************************/

void test08 ( )

/******************************************************************************/
/*
  Purpose:

    TEST08 tests GM_GENERAL_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2017

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m;
  int n;
  int rule;
  double t[3*4] = {
    1.0, 0.0, 0.0, 
    2.0, 0.0, 0.0, 
    1.0, 2.0, 0.0, 
    1.0, 0.0, 3.0 };
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  GM_GENERAL_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional general simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );

  m = 3;
  rule = 2;

  printf ( "\n" );
  printf ( "  Here we use M = %d\n", m );
  printf ( "  RULE = %d\n", rule );
  printf ( "  DEGREE = %d\n", 2 * rule + 1 );

  printf ( "\n" );
  printf ( "  Simplex vertices:\n" );
  printf ( "\n" );
  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      printf ( "  %14.6g", t[i+j*3] );
    }
    printf ( "\n" );
  }

  n = gm_rule_size ( rule, m );

  w = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( m * n * sizeof ( double ) );

  gm_general_rule_set ( rule, m, n, t, w, x );

  printf ( "\n" );
  printf ( "     POINT        W             X             Y             Z\n" );
  printf ( "\n" );

  for ( j = 0; j < n; j++ )
  {
    printf ( "  %8d  %12g", j, w[j] );
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %12g", x[i+j*m] );
    }
    printf ( "\n" );
  }

  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void test09 ( )

/******************************************************************************/
/*
  Purpose:

    TEST09 tests GM_UNIT_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2017

  Author:

    John Burkardt
*/
{
  int e[3];
  int e_test[3*10] = {
    0, 0, 0, 
    1, 0, 0, 
    0, 1, 0, 
    0, 0, 1, 
    2, 0, 0,
    1, 1, 0, 
    1, 0, 1, 
    0, 2, 0,
    0, 1, 1, 
    0, 0, 2 };
  int i;
  int k;
  int m = 3;
  int n;
  double result;
  int rule;
  double *value;
  double volume;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "TEST09\n" );
  printf ( "  GM_UNIT_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional unit simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );

  printf ( "\n" );
  printf ( "  In this test, look at all the monomials up to\n" );
  printf ( "  some maximum degree, choose a few low order rules\n" );
  printf ( "  and determine the quadrature error for each.\n" );

  volume = simplex_unit_volume ( m );
  printf ( "\n" );
  printf ( "  Simplex volume = %g\n", volume );

  printf ( "\n" );
  printf ( "  Here we use M = %d\n", m );

  printf ( "\n" );
  printf ( "         N        1               X               Y " );
  printf ( "              Z               X^2              XY             XZ" );
  printf ( "              Y^2             YZ               Z^2\n" );
  printf ( "\n" );

  for ( rule = 0; rule <= 5; rule++ )
  {
    n = gm_rule_size ( rule, m );

    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( m * n * sizeof ( double ) );

    gm_unit_rule_set ( rule, m, n, w, x );

    printf ( "  %8d", n );

    for ( k = 0; k < 10; k++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+k*m];
      }
      value = monomial_value ( m, n, e, x );

      result = r8vec_dot_product ( n, w, value );

      printf ( "  %14.6g", result );

      free ( value );
    }

    printf ( "\n" );

    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void test10 ( )

/******************************************************************************/
/*
  Purpose:

    TEST10 tests GM_GENERAL_RULE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2017

  Author:

    John Burkardt
*/
{
  int e[3];
  int e_test[3*10] = {
    0, 0, 0, 
    1, 0, 0, 
    0, 1, 0, 
    0, 0, 1, 
    2, 0, 0,
    1, 1, 0, 
    1, 0, 1, 
    0, 2, 0,
    0, 1, 1, 
    0, 0, 2 };
  int i;
  int j;
  int k;
  int m = 3;
  int n;
  double result;
  int rule;
  double t[3*4] = {
    1.0, 0.0, 0.0, 
    2.0, 0.0, 0.0, 
    1.0, 2.0, 0.0, 
    1.0, 0.0, 3.0 };
  double *value;
  double volume;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "TEST10\n" );
  printf ( "  GM_GENERAL_RULE_SET determines the weights and abscissas\n" );
  printf ( "  of a Grundmann-Moeller quadrature rule for\n" );
  printf ( "  the M dimensional general simplex,\n" );
  printf ( "  using a rule of index RULE,\n" );
  printf ( "  which will have degree of exactness 2*RULE+1.\n" );

  printf ( "\n" );
  printf ( "  In this test, look at all the monomials up to\n" );
  printf ( "  some maximum degree, choose a few low order rules\n" );
  printf ( "  and determine the quadrature error for each.\n" );

  volume = simplex_general_volume ( m, t );
  printf ( "\n" );
  printf ( "  Simplex volume = %g\n", volume );

  printf ( "\n" );
  printf ( "  Here we use M = %d\n", m );

  printf ( "\n" );
  printf ( "  Simplex vertices:\n" );
  printf ( "\n" );
  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      printf ( "  %14.6g", t[i+j*3] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "         N        1               X               Y " );
  printf ( "              Z               X^2              XY             XZ" );
  printf ( "              Y^2             YZ               Z^2\n" );
  printf ( "\n" );

  for ( rule = 0; rule <= 5; rule++ )
  {
    n = gm_rule_size ( rule, m );

    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( m * n * sizeof ( double ) );

    gm_general_rule_set ( rule, m, n, t, w, x );

    printf ( "  %8d", n );

    for ( k = 0; k < 10; k++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+k*m];
      }
      value = monomial_value ( m, n, e, x );

      result = r8vec_dot_product ( n, w, value );

      printf ( "  %14.6g", result );

      free ( value );
    }

    printf ( "\n" );

    free ( w );
    free ( x );
  }

  return;
}
