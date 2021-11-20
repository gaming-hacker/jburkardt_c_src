# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "newton_interp_1d.h"

/******************************************************************************/

double *newton_coef_1d ( int nd, double xd[], double yd[] )

/******************************************************************************/
/*
  Purpose:

    NEWTON_COEF_1D computes coefficients of a Newton 1D interpolant.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2015

  Author:

    John Burkardt

  Reference:

    Carl deBoor,
    A Practical Guide to Splines,
    Springer, 2001,
    ISBN: 0387953663,
    LC: QA1.A647.v27.

  Parameters:

    Input, int ND, the number of data points.

    Input, double XD[ND], the X values at which data was taken.
    These values must be distinct.

    Input, double YD[ND], the corresponding Y values.

    Output, double NEWTON_COEF_1D[ND], the divided difference coefficients.
*/
{
  double *cd;
  int i;
  int j;
/*
  Copy the data values.
*/
  cd = ( double * ) malloc ( nd * sizeof ( double ) );

  for ( i = 0; i < nd; i++ )
  {
    cd[i] = yd[i];
  }
/*
  Make sure the abscissas are distinct.
*/
  for ( i = 0; i < nd; i++ )
  {
    for ( j = i + 1; j < nd; j++ )
    {
      if ( xd[i] - xd[j] == 0.0 )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "NEWTON_COEF_1D - Fatal error!\n" );
        fprintf ( stderr, "  Two entries of XD are equal!\n" );
        fprintf ( stderr, "  XD[%d] = %f\n", i, xd[i] );
        fprintf ( stderr, "  XD[%d] = %f\n", j, xd[j] );
        exit ( 1 );
      }
    }
  }
/*
  Compute the divided differences.
*/
  for ( i = 1; i <= nd - 1; i++ )
  {
    for ( j = nd - 1; i <= j; j-- )
    {
      cd[j] = ( cd[j] - cd[j-1] ) / ( xd[j] - xd[j-i] );
    }
  }
  return cd;
}
/******************************************************************************/

double *newton_value_1d ( int nd, double xd[], double cd[], int ni, double xi[] )

/******************************************************************************/
/*
  Purpose:

    NEWTON_VALUE_1D evaluates a Newton 1D interpolant.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2015

  Author:

    John Burkardt

  Reference:

    Carl deBoor,
    A Practical Guide to Splines,
    Springer, 2001,
    ISBN: 0387953663,
    LC: QA1.A647.v27.

  Parameters:

    Input, int ND, the order of the difference table.

    Input, double XD[ND], the X values of the difference table.

    Input, double CD[ND], the divided differences.

    Input, int NI, the number of interpolation points.

    Input, double XI[NI], the interpolation points.

    Output, double NEWTON_VALUE_1D[NI], the interpolation values.
*/
{
  int i;
  int j;
  double *yi;

  yi = ( double * ) malloc ( ni * sizeof ( double ) );

  for ( j = 0; j < ni; j++ )
  {
    yi[j] = cd[nd-1];
    for ( i = 2; i <= nd; i++ )
    {
      yi[j] = cd[nd-i] + ( xi[j] - xd[nd-i] ) * yi[j];
    }
  }
  return yi;
}
/******************************************************************************/

double *r8vec_copy_new ( int n, double a1[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_COPY_NEW copies an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], the vector to be copied.

    Output, double R8VEC_COPY_NEW[N], the copy of A1.
*/
{
  double *a2;
  int i;

  a2 = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return a2;
}
/******************************************************************************/

double *r8vec_linspace_new ( int n, double a, double b )

/******************************************************************************/
/*
  Purpose:

    R8VEC_LINSPACE_NEW creates a vector of linearly spaced values.

  Discussion:

    An R8VEC is a vector of R8's.

    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
 
    In other words, the interval is divided into N-1 even subintervals,
    and the endpoints of intervals are used as the points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A, B, the first and last entries.

    Output, double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
*/
{
  int i;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  if ( n == 1 )
  {
    x[0] = ( a + b ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( ( double ) ( n - 1 - i ) * a 
             + ( double ) (         i ) * b ) 
             / ( double ) ( n - 1     );
    }
  }
  return x;
}
/******************************************************************************/

double r8vec_max ( int n, double r8vec[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MAX returns the value of the maximum element in a R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, double R8VEC[N], a pointer to the first entry of the array.

    Output, double R8VEC_MAX, the value of the maximum element.  This
    is set to 0.0 if N <= 0.
*/
{
  int i;
  double value;

  if ( n <= 0 )
  {
    value = 0.0;
    return value;
  }

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < r8vec[i] )
    {
      value = r8vec[i];
    }
  }
  return value;
}
/******************************************************************************/

double r8vec_min ( int n, double r8vec[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MIN returns the value of the minimum element in a R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, double R8VEC[N], the array to be checked.

    Output, double R8VEC_MIN, the value of the minimum element.
*/
{
  int i;
  double value;

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( r8vec[i] < value )
    {
      value = r8vec[i];
    }
  }
  return value;
}
/******************************************************************************/

double r8vec_norm_affine ( int n, double v0[], double v1[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORM_AFFINE returns the affine L2 norm of an R8VEC.

  Discussion:

    The affine vector L2 norm is defined as:

      R8VEC_NORM_AFFINE(V0,V1)
        = sqrt ( sum ( 1 <= I <= N ) ( V1(I) - V0(I) )^2 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the dimension of the vectors.

    Input, double V0[N], the base vector.

    Input, double V1[N], the vector whose affine L2 norm is desired.

    Output, double R8VEC_NORM_AFFINE, the affine L2 norm of V1.
*/
{
  int i;
  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )
  {
    value = value + ( v1[i] - v0[i] ) * ( v1[i] - v0[i] );
  }
  value = sqrt ( value );

  return value;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

void r8vec2_print ( int n, double a1[], double a2[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC2_PRINT prints an R8VEC2.

  Discussion:

    An R8VEC2 is a dataset consisting of N pairs of real values, stored
    as two separate vectors A1 and A2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A1[N], double A2[N], the vectors to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %4d: %14g  %14g\n", i, a1[i], a2[i] );
  }

  return;
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

