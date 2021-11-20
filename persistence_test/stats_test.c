# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "r8lib.h"
# include "stats.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    stats_test() tests stats().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2021

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  int nvec = 10;
  double x_max;
  double x_max2;
  double x_mean;
  double x_mean2;
  double x_min;
  double x_min2;
  double x_std;
  double x_std2;
  double x_sum;
  double x_sum2;
  double x_var;
  double x_var2;
  double x;
  double *xvec;
  int *i_null = NULL;
  double *d_null = NULL;

  timestamp ( );
  printf ( "\n" );
  printf ( "stats_test():\n" );
  printf ( "  C version\n" );
  printf ( "  Test stats(), with the interface:\n" );
  printf ( "  stats(x,n,x_sum,x_min,x_mean,x_max,x_var,x_std)\n" );
  printf ( "\n" );
  printf ( "  Call 10 times with random values;\n" );
  printf ( "  Compare results with vector calculation.\n" );

  printf ( "\n" );
  xvec = ( double * ) malloc ( nvec * sizeof ( double ) );
  for ( i = 0; i < nvec; i++ )
  {
    xvec[i] = drand48 ( );
    printf ( "    x[%d] = %g\n", i, xvec[i] );
  }
/*
  Zero everything out.
*/
  stats ( d_null, i_null, d_null, d_null, d_null, d_null, d_null, d_null );
/*
  Load 10 values of X, but don't ask for output.
*/
  for ( i = 0; i < nvec; i++ )
  {
    x = xvec[i];
    stats ( &x, i_null, d_null, d_null, d_null, d_null, d_null, d_null );
  }
/*
  Only get output at end.
*/
  x = INFINITY;
  stats ( &x, &n, &x_sum, &x_min, &x_mean, &x_max, &x_var, &x_std );
/*
  Recompute data using a vector.
*/
  x_sum2 = r8vec_sum ( nvec, xvec );
  x_min2 = r8vec_min ( nvec, xvec );
  x_mean2 = r8vec_mean ( nvec, xvec );
  x_max2 = r8vec_max ( nvec, xvec );
  x_var2 = r8vec_variance_sample ( nvec, xvec );
  x_std2 = r8vec_std_sample ( nvec, xvec );

  printf ( "\n" );
  printf ( "    n1    = %d, n2    = %d\n", n,      nvec );
  printf ( "    sum1  = %g, sum2  = %g\n", x_sum,  x_sum2 );
  printf ( "    min1  = %g, min2  = %g\n", x_min,  x_min2 );
  printf ( "    mean1 = %g, mean2 = %g\n", x_mean, x_mean2 );
  printf ( "    max1  = %g, max2  = %g\n", x_max,  x_max2 );
  printf ( "    var1  = %g, var2  = %g\n", x_var,  x_var2 );
  printf ( "    std1  = %g, std2  = %g\n", x_std,  x_std2 );

  free ( xvec );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "stats_test():\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}

