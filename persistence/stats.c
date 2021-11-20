# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "stats.h"

/******************************************************************************/

void stats ( double *x,  int *n, double *x_sum, double *x_min, double *x_mean, 
  double *x_max, double *x_var, double *x_std )

/******************************************************************************/
/*
  Purpose:

    stats() does stats.

  Discussion:

    This function computes statistical quantities for a sequence of values
    X which are supplied one at a time, like a data stream.  The statistical
    quantities are updated every time a new value of X is supplied.

    Because we are dealing with a data stream, and not saving the previous
    data values, it is not possible to compute the median and mode.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2021

  Author:

    John Burkardt

  Input:

    double *X, the next item in the sequence.
    If X is set to INFINITY, as defined in <math.h>, then its value 
    is ignored, and the current data is returned.
    If X is set to NULL, then all internal data is reset to 0.

  Output:

    int *N: the number of items in the sequence.

    double *X_SUM: the sum of the values.

    double *X_MIN, X_MEAN, X_MAX: the minimum, mean, and maximum values.

    double *X_VAR, X_STD: the variance and standard deviation.
*/
{
  static double n_internal = 0;
  static double x_max_internal = - INFINITY;
  static double x_mean_internal = 0.0;
  static double x_min_internal = INFINITY;
  static double x_std_internal = 0.0;
  static double x_sum_internal = 0.0;
  static double x_var_internal = 0.0;

  double x_mean_old;
/*
  No input.  Reset internal data to 0.
*/
  if ( ! x )
  {
    n_internal = 0;
    x_max_internal = - INFINITY;
    x_mean_internal = 0.0;
    x_min_internal = INFINITY;
    x_std_internal = 0.0;
    x_sum_internal = 0.0;
    x_var_internal = 0.0;
  }
/*
  Input, not equal to infinity.  Process X.
*/
  else if ( isfinite ( *x ) )
  {
    n_internal = n_internal + 1;
    if ( x_max_internal < *x )
    {
      x_max_internal = *x;
    }
    if ( *x < x_min_internal )
    {
      x_min_internal = *x;
    }
    x_sum_internal = x_sum_internal + *x;
    x_mean_old = x_mean_internal;
    x_mean_internal = x_sum_internal / n_internal;
    if ( n_internal == 1 )
    {
      x_var_internal = 0.0;
      x_std_internal = 0.0;
    }
    else
    {
      x_var_internal = ( x_var_internal * ( n_internal - 2 )
        + ( *x - x_mean_old ) * ( *x - x_mean_internal ) ) 
        / ( n_internal - 1 );
      x_std_internal = sqrt ( x_var_internal );
    }
  }
/*
  Set the output.
*/
  if ( n )
  {
    *n      = n_internal;
  }
  if ( x_max )
  {
    *x_max  = x_max_internal;
  }
  if ( x_min )
  {
    *x_min  = x_min_internal;
  }
  if ( x_sum )
  {
    *x_sum  = x_sum_internal;
  }
  if ( x_mean )
  {
    *x_mean = x_mean_internal;
  }
  if ( x_var )
  {
    *x_var  = x_var_internal;
  }
  if ( x_std )
  {
    *x_std  = x_std_internal;
  }

  return;
}

