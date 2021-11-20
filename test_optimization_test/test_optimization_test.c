# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

# include "test_optimization.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TEST_OPTIMIZATION_TEST.

  Discussion:

    TEST_OPTIMIZATION_TEST tests the TEST_OPTIMIZATION library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2012

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TEST_OPTIMIZATION_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TEST_OPTIMIZATION library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TEST_OPTIMIZATION_TEST\n" );
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

    TEST01 simply prints the title of each problem.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2012

  Author:

    John Burkardt
*/
{
  int problem;
  int problem_num;
  char title[100];

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  For each problem, print the title.\n" );
/*
  Get the number of problems.
*/
  problem_num = p00_problem_num ( );

  printf ( "\n" );
  printf ( "  Problem  Title\n" );
  printf ( "\n" );

  for ( problem = 1; problem <= problem_num; problem++ )
  {
    p00_title ( problem, title );
    printf ( "  %7d  %s\n", problem, title );
  }
  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 samples the function at 1,000 points and prints the minimum.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2012

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  double *f;
  double f_min;
  int know;
  int m = 2;
  int n = 1000;
  int problem;
  int problem_num;
  int seed;
  double *x;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  For each problem, using dimension M = 2\n" );
  printf ( "  sample the function at N = 1000 points,\n" );
  printf ( "  and print the minimum and maximum.\n" );

  seed = 123456789;
/*
  Get the number of problems.
*/
  problem_num = p00_problem_num ( );

  printf ( "\n" );
  printf ( "  Problem     Minimum  Sample Minimum  Sample Maximum\n" );
  printf ( "\n" );

  for ( problem = 1; problem <= problem_num; problem++ )
  {
    know = 0;
    x = p00_sol ( problem, m, &know );
    if ( know != 0 )
    {
      f = p00_f ( problem, m, 1, x );
      f_min = f[0];
      free ( x );
      free ( f );
    }

    a = ( double * ) malloc ( m * sizeof ( double ) );
    b = ( double * ) malloc ( m * sizeof ( double ) );
    p00_ab ( problem, m, a, b );
    x = r8col_uniform_new ( m, n, a, b, &seed );
    f = p00_f ( problem, m, n, x );
    if ( know != 0 )
    {
      printf ( "  %7d  %14g  %14g  %14g\n",
        problem, f_min, r8vec_min ( n, f ), r8vec_max ( n, f ) );
    }
    else
    {
      printf ( "  %7d                  %14g  %14g\n",
        problem, r8vec_min ( n, f ), r8vec_max ( n, f ) );
    }
    free ( a );
    free ( b );
    free ( x );
    free ( f );
  }
  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tries Compass Search on each problem.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2012

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  double delta_init;
  double delta_tol;
  double *fv;
  double fx;
  int i;
  int k;
  int k_max;
  int know;
  int m = 2;
  int problem;
  int problem_num;
  double s;
  int seed;
  double *x;
  double *x0;

  delta_tol = 0.000001;
  k_max = 20000;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  For each problem, using dimension M = 2\n" );
  printf ( "  try compass search.\n" );
/*
  Get the number of problems.
*/
  problem_num = p00_problem_num ( );

  for ( problem = 1; problem <= problem_num; problem++ )
  {
    seed = 123456789;

    a = ( double * ) malloc ( m * sizeof ( double ) );
    b = ( double * ) malloc ( m * sizeof ( double ) );
    p00_ab ( problem, m, a, b );
    x0 = r8col_uniform_new ( m, 1, a, b, &seed );
    fv = p00_f ( problem, m, 1, x0 );
    s = 0.0;
    for ( i = 0; i < m; i++ )
    {
      s = s + x0[i] * x0[i];
    }
    delta_init = 0.3 * sqrt ( s ) / ( double ) ( m );
    delta_init = r8_max ( delta_init, 1000.0 * delta_tol );
    printf ( "\n" );
    printf ( "  Problem %2d   DELTA_INIT = %14g\n", problem, delta_init );
    printf ( "  Initial:%14g  %14g  %14g\n", x0[0], x0[1], fv[0] );
    x = p00_compass_search ( problem, m, x0, delta_tol, delta_init, 
      k_max, &fx, &k );
    printf ( "  Final:  %14g  %14g  %14g  Steps = %d\n", x[0], x[1], fx, k ); 
    free ( fv );
    free ( x );

    know = 0;
    for ( ; ; )
    {
      x = p00_sol ( problem, m, &know );
      if ( know == 0 )
      {
        break;
      }
      fv = p00_f ( problem, m, 1, x );
      printf ( "  Exact:  %14g  %14g  %14g\n", x[0], x[1], fv[0] );
      free ( fv );
      free ( x );
    }

    free ( a );
    free ( b );
    free ( x0 );
  }
  return;
}
