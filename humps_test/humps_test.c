# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "humps.h"

int main ( );
void humps_antideriv_test ( );
void humps_deriv_test ( );
void humps_deriv2_test ( );
void humps_fun_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for humps_test.

  Discussion:

    humps_test tests humps.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "humps_test\n" );
  printf ( "  C version\n" );
  printf ( "  test humps.\n" );

  humps_antideriv_test ( );
  humps_fun_test ( );
  humps_deriv_test ( );
  humps_deriv2_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "humps_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void humps_antideriv_test ( )

/******************************************************************************/
/*
  Purpose:

    humps_antideriv_test tests humps_antideriv.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 August 2019

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "humps_antideriv_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test humps_antideriv.\n" );

  a = 0.0;
  b = 2.0;
  n = 101;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_antideriv ( x[i] );
  }
  plot_xy ( n, x, y, "humps_antideriv" );

  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void humps_fun_test ( )

/******************************************************************************/
/*
  Purpose:

    humps_fun_test tests humps_fun.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 August 2019

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "humps_fun_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test humps_fun.\n" );

  a = 0.0;
  b = 2.0;
  n = 101;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_fun ( x[i] );
  }
  plot_xy ( n, x, y, "humps_fun" );

  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void humps_deriv_test ( )

/******************************************************************************/
/*
  Purpose:

    humps_deriv_test tests humps_deriv.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 August 2019

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "humps_deriv_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test humps_deriv.\n" );

  a = 0.0;
  b = 2.0;
  n = 101;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_deriv ( x[i] );
  }
  plot_xy ( n, x, y, "humps_deriv" );

  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void humps_deriv2_test ( )

/******************************************************************************/
/*
  Purpose:

    humps_deriv2_test tests humps_deriv2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 August 2019

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "humps_deriv2_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test humps_deriv2.\n" );

  a = 0.0;
  b = 2.0;
  n = 101;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_deriv2 ( x[i] );
  }
  plot_xy ( n, x, y, "humps_deriv2" );

  free ( x );
  free ( y );

  return;
}
