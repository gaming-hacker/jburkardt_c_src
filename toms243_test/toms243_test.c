# include <complex.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "toms243.h"

int main ( );
void c8_log_values ( int *n_data, double complex *z, double complex *fz );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    TOMS243_TEST tests TOMS243.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 January 2018

  Author:

    John Burkardt
*/
{
  double complex fx1;
  double complex fx2;
  int n_data;
  double complex x;

  timestamp ( );
  printf ( "\n" );
  printf ( "TOMS243_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  TOMS243 computes the natural logarithm of a complex value.\n" );
  printf ( "\n" );
  printf ( "               X                               FX exact\n" );
  printf ( "                                               FX computed\n" );
  printf ( "\n" );

  n_data = 0;

  while ( true )
  {
    c8_log_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = toms243 ( x );

    printf ( "  ( %8.4f,%8.4f)  (%18.12f,%18.12f)\n",
      creal ( x ), cimag ( x ), creal ( fx1 ), cimag ( fx1 ) );
    printf ( "                        (%18.12f,%18.12f)\n",
                                creal ( fx2 ), cimag ( fx2 ) );
  }

  printf ( "\n" );
  printf ( "TOMS243_TEST:\n" );
  printf ( "  Normal end of execution:\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void c8_log_values ( int *n_data, double complex *z, double complex *fz )

/******************************************************************************/
/*
  Purpose:

    C8_LOG_VALUES: natural logarithm function for complex values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 January 2019

  Author:

    John Burkardt

  Reference:

    David Collens,
    Algorithm 243: Logarithm of a Complex Number,
    Communications of the Association for Computing Machinery,
    Volume 7, Number 11, November 1964, page 660.

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, double complex *Z, the argument of the function.

    Output, double complex *FZ, the value of the function.
*/
{
# define N_MAX 12

  static double complex fz_vec[N_MAX] = {
    1.039720770839918 - 2.356194490192345 * I,
    0.804718956217050 + 2.677945044588987 * I,
    0.346573590279973 - 2.356194490192345 * I,
    0.000000000000000 + 3.141592653589793 * I,
    0.693147180559945 - 1.570796326794897 * I,
    0.000000000000000 - 1.570796326794897 * I,
    0.000000000000000 + 1.570796326794897 * I,
    0.693147180559945 + 1.570796326794897 * I,
    0.346573590279973 - 0.785398163397448 * I,
    0.000000000000000 + 0.000000000000000 * I,
    1.039720770839918 - 0.785398163397448 * I,
    0.804718956217050 + 0.463647609000806 * I };

  static double complex z_vec[N_MAX] = {
     -2.0 - 2.0 * I,
     -2.0 + 1.0 * I,
     -1.0 - 1.0 * I,
     -1.0 + 0.0 * I,
      0.0 - 2.0 * I,
      0.0 - 1.0 * I,
      0.0 + 1.0 * I,
      0.0 + 2.0 * I,
      1.0 - 1.0 * I,
      1.0 + 0.0 * I,
      2.0 - 2.0 * I,
      2.0 + 1.0 * I };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *z = 0.0 + 0.0 * I;
    *fz = 0.0 + 0.0 * I;
  }
  else
  {
    *z  = z_vec[*n_data-1];
    *fz = fz_vec[*n_data-1];
  }

  return;
# undef N_MAX
}

