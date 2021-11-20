# include <stdlib.h>
# include <stdio.h>

# include "disk_monte_carlo.h"

int main ( );
void disk_area_test ( );
void disk_sample_test ( double center[2], double r );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for DISK_MONTE_CARLO_TEST.

  Discussion:

    DISK_MONTE_CARLO_TEST tests the DISK_MONTE_CARLO library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 July 2018

  Author:

    John Burkardt
*/
{
  double center[2];
  double r;

  timestamp ( );
  printf ( "\n" );
  printf ( "DISK_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the DISK_MONTE_CARLO library.\n" );

  disk_area_test ( );

  center[0] = 0.0;
  center[1] = 0.0;
  r = 1.0;
  disk_sample_test ( center, r );

  center[0] = 1.0;
  center[1] = 0.0;
  r = 1.0;
  disk_sample_test ( center, r );

  center[0] = 1.0;
  center[1] = 2.0;
  r = 3.0;
  disk_sample_test ( center, r );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "DISK_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void disk_area_test ( )

/******************************************************************************/
/*
  Purpose:

    DISK_AREA_TEST test DISK_AREA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 July 2018

  Author:

    John Burkardt
*/
{
  double area;
  double center[2];
  double *data;
  int i;
  double r;
  int seed;

  printf ( "\n" );
  printf ( "DISK_AREA_TEST\n" );
  printf ( "  DISK_AREA computes the area of a disk with\n" );
  printf ( "  center = (CX,CY) and radius R.\n" );
  
  seed = 123456789;

  printf ( "\n" );
  printf ( "  (   CX        CY     )    R          Area\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    data = r8vec_uniform_01_new ( 3, &seed );
    center[0] = 10.0 * data[0] - 5.0;
    center[1] = 10.0 * data[1] - 5.0;
    r = data[2];
    area = disk_area ( center, r );
    printf ( "  (%9.6f,%9.6f)  %9.6f  %9.6f\n", 
      center[0], center[1], r, area );
    free ( data );
  }

  return;
}
/******************************************************************************/

void disk_sample_test ( double center[2], double r )

/******************************************************************************/
/*
  Purpose:

    DISK_SAMPLE_TEST uses DISK_SAMPLE to estimate integrals.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 July 2018

  Author:

    John Burkardt
*/
{
  int e[2];
  int e_test[2*7] = {
    0, 0, 
    2, 0, 
    0, 2, 
    4, 0, 
    2, 2, 
    0, 4, 
    6, 0 };
  int i;
  int j;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "DISK_SAMPLE_TEST\n" );
  printf ( "  Use DISK_SAMPLE to estimate integrals in the disk\n" );
  printf ( "  with center (%g,%g) and radius %g.\n", center[0], center[1], r );

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N        1              X^2             Y^2" );
  printf ( "             X^4             X^2Y^2           Y^4             X^6\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    x = disk_sample ( center, r, n, &seed );

    printf ( "  %8d", n );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }
      value = monomial_value ( 2, n, e, x );

      result = disk_area ( center, r ) * r8vec_sum ( n, value ) / ( double ) ( n );
      printf ( "  %14.6g", result );

      free ( value );
    }
    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  if (
    center[0] == 0.0 &&
    center[1] == 0.0 &&
    r == 1.0 )
  {
    printf ( "\n" );
    printf ( "     Exact" );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
       e[i] = e_test[i+j*2];
     }
     result = disk01_monomial_integral ( e );
      printf ( "  %14.6g", result );
    }
    printf ( "\n" );
  }

  return;
}
