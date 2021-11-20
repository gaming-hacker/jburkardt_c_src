# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "blend.h"

int main ( );
double cubic_rs ( double r, double s, int i );
double identity_r ( double r, int i );
double identity_rs ( double r, double s, int i );
double identity_rst ( double r, double s, double t, int i );
double powers_r ( double r, int i );
double quad_rst ( double r, double s, double t, int i );
double stretch_r ( double r, int i );
double stretch_rs ( double r, double s, int i );
double stretch_rst ( double r, double s, double t, int i );
void blend_101_test ( );
void blend_102_test ( );
void blend_103_test ( );
void blend_112_test ( );
void blend_113_test ( );
void blend_123_test ( );
void blend_i_0d1_test ( );
void blend_ij_0d1_test ( );
void blend_ij_1d1_test ( );
void blend_ij_w_1d1_test ( );
void blend_ijk_0d1_test ( );
void blend_ijk_1d1_test ( );
void blend_ijk_2d1_test ( );
void blend_r_0dn_test ( );
void blend_r_0dn_identity_test ( );
void blend_r_0dn_stretch_test ( );
void blend_rs_0dn_test ( );
void blend_rs_0dn_identity_test ( );
void blend_rs_0dn_stretch_test ( );
void blend_rs_1dn_test ( );
void blend_rs_1dn_identity_test ( );
void blend_rs_1dn_stretch_test ( );
void blend_rst_0dn_identity_test ( );
void blend_rst_0dn_stretch_test ( );
void blend_rst_1dn_identity_test ( );
void blend_rst_1dn_stretch_test ( );
void blend_rst_2dn_identity_test ( );
void blend_rst_2dn_stretch_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BLEND_TEST.

  Discussion:

    BLEND_TEST tests the BLEND library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 October 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BLEND_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BLEND library.\n" );

  blend_101_test ( );
  blend_102_test ( );
  blend_103_test ( );

  blend_112_test ( );
  blend_113_test ( );

  blend_123_test ( );

  blend_i_0d1_test ( );

  blend_ij_0d1_test ( );
  blend_ij_1d1_test ( );
  blend_ij_w_1d1_test ( );

  blend_ijk_0d1_test ( );
  blend_ijk_1d1_test ( );
  blend_ijk_2d1_test ( );

  blend_r_0dn_test ( );
  blend_r_0dn_identity_test ( );
  blend_r_0dn_stretch_test ( );

  blend_rs_0dn_test ( );
  blend_rs_0dn_identity_test ( );
  blend_rs_0dn_stretch_test ( );

  blend_rs_1dn_test ( );
  blend_rs_1dn_identity_test ( );
  blend_rs_1dn_stretch_test ( );

  blend_rst_0dn_identity_test ( );
  blend_rst_0dn_stretch_test ( );

  blend_rst_1dn_identity_test ( );
  blend_rst_1dn_stretch_test ( );

  blend_rst_2dn_identity_test ( );
  blend_rst_2dn_stretch_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BLEND_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void blend_101_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_101_TEST tests BLEND_101.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 October 2018

  Author:

    John Burkardt
*/
{
  double *d;
  int i;
  int n1;
  double r;

  n1 = 10;
  d = r8vec_zeros_new ( n1 );

  for ( i = 0; i < n1; i++ )
  {
    if ( i == 0 || i == n1 - 1 )
    {
      d[i] = ( double ) ( i + 1 );
    }
  }

  printf ( "\n" );
  printf ( "BLEND_101_TEST\n" );
  printf ( "  BLEND_101 blends endpoint values into a list.\n" );

  r8vec_print ( n1, d, "  Initial data list" );

  for ( i = 0; i < n1; i++ )
  {
    if ( i != 0 && i != n1 - 1 )
    {
      r = ( double ) ( i ) / ( double ) ( n1 - 1 );
      d[i] = blend_101 ( r, d[0], d[n1-1] );
    }
  }

  r8vec_print ( n1, d, "  Interpolated data list" );

  free ( d );

  return;
}
/******************************************************************************/

void blend_102_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_102_TEST tests BLEND_102.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 October 2008

  Author:

    John Burkardt
*/
{
  double *d;
  int i;
  int j;
  int n1;
  int n2;
  double r;
  double s;

  n1= 5;
  n2 = 5;
  d = r8mat_zeros_new ( n1, n2 );

  for ( i = 1; i <= n1; i++ )
  {
    for ( j = 1; j <= n2; j++ )
    {
      if (
        ( i == 1 || i == n1 ) &&
        ( j == 1 || j == n2 ) )
      {
        d[i-1+(j-1)*n1] = ( double ) ( i + j );
      }
    }
  }

  printf ( "\n" );
  printf ( "BLEND_102_TEST\n" );
  printf ( "  BLEND_102 blends corner values into a table.\n" );

  r8mat_print ( n1, n2, d, "  Initial data array" );

  for ( i = 1; i <= n1; i++ )
  {
    r = ( double ) (  i - 1 )
      / ( double ) ( n1 - 1 );

    for ( j = 1; j <= n2; j++ )
    {
      s = ( double ) (  j - 1 )
        / ( double ) ( n2 - 1 );

      if ( 
        ( i == 1 || i == n1 ) &&
        ( j == 1 || j == n2 ) )
      {
        continue;
      }
      d[i-1+(j-1)*n1] = blend_102 ( r, s, d[0+0*n1], d[0+(n2-1)*n1], 
        d[n1-1+0*n1], d[n1-1+(n2-1)*n1] );
    }
  }

  r8mat_print ( n1, n2, d, "  Interpolated data array" );

  free ( d );

  return;
}
/******************************************************************************/

void blend_103_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_103_TEST tests BLEND_103.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 October 2008

  Author:

    John Burkardt

*/
{
  double *d;
  int i;
  int j;
  int k;
  int n1;
  int n2;
  int n3;
  double r;
  double s;
  double t;

  n1 = 3;
  n2 = 5;
  n3 = 4;
  d = r8block_zeros_new ( n1, n2, n3 );

  for ( i = 1; i <= n1; i++ )
  {
    for ( j = 1; j <= n2; j++ )
    {
      for ( k = 1; k <= n3; k++ )
      {
        if (
          ( i == 1 || i == n1 ) &&
          ( j == 1 || j == n2 ) &&
          ( k == 1 || k == n3  ) )
        {
          d[i-1+(j-1)*n1+(k-1)*n1*n2] = ( double ) ( i + j + k );
        }
      }
    }
  }

  printf ( "\n" );
  printf ( "BLEND_103_TEST\n" );
  printf ( "  BLEND_103 blends corner values into a table.\n" );

  r8block_print ( n1, n2, n3, d, "  Initial data array" );

  for ( i = 1; i <= n1; i++ )
  {
    r = ( double ) (  i - 1 )
      / ( double ) ( n1 - 1 );

    for ( j = 1; j <= n2; j++ )
    {
      s = ( double ) (  j - 1 ) 
        / ( double ) ( n2 - 1 );

      for ( k = 1; k <= n3; k++ )
      {
        t = ( double ) (  k - 1 ) 
          / ( double ) ( n3 - 1 );

        if ( 
          ( i == 1 || i == n1 ) && 
          ( j == 1 || j == n2 ) && 
          ( k == 1 || k == n3  ) )
        {
          continue;
        }

        d[i-1+(j-1)*n1+(k-1)*n1*n2] = blend_103 ( r, s, t, 
          d[   0+    0 *n1+    0 *n1*n2], 
          d[   0+    0 *n1+(n3-1)*n1*n2], 
          d[   0+(n2-1)*n1+    0 *n1*n2], 
          d[   0+(n2-1)*n1+(n3-1)*n1*n2], 
          d[n1-1+    0 *n1+    0 *n1*n2], 
          d[n1-1+    0 *n1+(n3-1)*n1*n2], 
          d[n1-1+(n2-1)*n1+    0 *n1*n2], 
          d[n1-1+(n2-1)*n1+(n3-1)*n1*n2] );
      }
    }
  }

  r8block_print ( n1, n2, n3, d, "  Interpolated data array" );

  free ( d );

  return;
}
/******************************************************************************/

void blend_112_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_112_TEST tests BLEND_112.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 October 2018

  Author:

    John Burkardt
*/
{
  double *d;
  int i;
  int j;
  int n1;
  int n2;
  double r;
  double s;

  n1 = 5;
  n2 = 5;
  d = r8mat_zeros_new ( n1, n2 );

  for ( i = 1; i <= n1; i++ )
  {
    for ( j = 1; j <= n2; j++ )
    {
      if ( i == 1 || i == n1 || j == 1 || j == n2 )
      {
        d[i-1+(j-1)*n1] = ( double ) ( i + j );
      }
    }
  }

  printf ( "\n" );
  printf ( "BLEND_112_TEST\n" );
  printf ( "  BLEND_112 blends side values into a table.\n" );

  r8mat_print ( n1, n2, d, "  Initial data array" );

  for ( i = 1; i <= n1; i++ )
  {
    r = ( double ) (  i - 1 ) / ( double ) ( n1 - 1 );

    for ( j = 1; j <= n2; j++ )
    {
      s = ( double ) (  j - 1 ) / ( double ) ( n2 - 1 );

      if ( i == 1 || i == n1 || j == 1 || j == n2 )
      {
        continue;
      }

      d[i-1+(j-1)*n1] = blend_112 ( r, s, 
        d[   0+    0 *n1], 
        d[   0+(n2-1)*n1], 
        d[n1-1+    0 *n1], 
        d[n1-1+(n2-1)*n1], 
        d[ i-1+    0 *n1], 
        d[ i-1+(n2-1)*n1], 
        d[   0+ (j-1)*n1], 
        d[n1-1+ (j-1)*n1] );
    }
  }

  r8mat_print ( n1, n2, d, "  Interpolated data array" );

  free ( d );

  return;
}
/******************************************************************************/

void blend_113_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_113_TEST tests BLEND_113.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 October 2018

  Author:

    John Burkardt
*/
{
  double *d;
  int i;
  int j;
  int k;
  int n1;
  int n2;
  int n3;
  double r;
  double s;
  double t;

  n1 = 3;
  n2 = 5;
  n3 = 4;

  d = r8block_zeros_new ( n1, n2, n3 );

  for ( i = 1; i <= n1; i++ )
  {
    for ( j = 1; j <= n2; j++ )
    {
      for ( k = 1; k <= n3; k++ )
      {
        if ( 
          ( ( i == 1 || i == n1 ) && ( j == 1 || j == n2 ) ) ||
          ( ( i == 1 || i == n1 ) && ( k == 1 || k == n3 ) ) ||
          ( ( j == 1 || j == n2 ) && ( k == 1 || k == n3 ) ) )
        {
          d[i-1+(j-1)*n1+(k-1)*n1*n2] = ( double ) ( i + j + k );
        }
      }
    }
  }

  printf ( "\n" );
  printf ( "BLEND_113_TEST\n" );
  printf ( "  BLEND_113 blends edge values into a table.\n" );

  r8block_print ( n1, n2, n3, d, "  Initial data array" );

  for ( i = 1; i <= n1; i++ )
  {
    r = ( double ) (  i - 1 ) / ( double ) ( n1 - 1 );

    for ( j = 1; j <= n2; j++ )
    {
      s = ( double ) (  j - 1 ) / ( double ) ( n2 - 1 );

      for ( k = 1; k <= n3; k++ )
      {
        t = ( double ) (  k - 1 ) / ( double ) ( n3 - 1 );

        if ( 
          ( ( i == 1 || i == n1 ) && ( j == 1 || j == n2 ) ) || 
          ( ( i == 1 || i == n1 ) && ( k == 1 || k == n3 ) ) ||
          ( ( j == 1 || j == n2 ) && ( k == 1 || k == n3 ) ) )
        {
          continue;
        }

        d[i-1+(j-1)*n1+(k-1)*n1*n2] = blend_113 ( r, s, t, 
          d[   0+    0 *n1+    0 *n1*n2],
          d[   0+    0 *n1+(n3-1)*n1*n2],
          d[   0+(n2-1)*n1+    0 *n1*n2],
          d[   0+(n2-1)*n1+(n3-1)*n1*n2], 
          d[n1-1+    0 *n1+    0 *n1*n2],
          d[n1-1+    0 *n1+(n3-1)*n1*n2],
          d[n1-1+(n2-1)*n1+    0 *n1*n2],
          d[n1-1+(n2-1)*n1+(n3-1)*n1*n2], 
          d[ i-1+    0 *n1+    0 *n1*n2],
          d[ i-1+    0 *n1+(n3-1)*n1*n2],
          d[ i-1+(n2-1)*n1+    0 *n1*n2],
          d[ i-1+(n2-1)*n1+(n3-1)*n1*n2], 
          d[   0+ (j-1)*n1+    0 *n1*n2],
          d[   0+ (j-1)*n1+(n3-1)*n1*n2],
          d[n1-1+ (j-1)*n1+    0 *n1*n2],
          d[n1-1+ (j-1)*n1+(n3-1)*n1*n2], 
          d[   0+    0 *n1+ (k-1)*n1*n2],
          d[   0+(n2-1)*n1+ (k-1)*n1*n2],
          d[n1-1+    0 *n1+ (k-1)*n1*n2],
          d[n1-1+(n2-1)*n1+ (k-1)*n1*n2] );
      }
    }
  }

  r8block_print ( n1, n2, n3, d, "  Interpolated data array" );

  return;
}
/******************************************************************************/

void blend_123_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_123_TEST tests BLEND_123.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 October 2008

  Author:

    John Burkardt
*/
{
  double *d;
  int i;
  int j;
  int k;
  int n1;
  int n2;
  int n3;
  double r;
  double s;
  double t;

  n1 = 3;
  n2 = 5;
  n3 = 4;

  d = r8block_zeros_new ( n1, n2, n3 );

  for ( i = 1; i <= n1; i++ )
  {
    for ( j = 1; j <= n2; j++ )
    {
      for ( k = 1; k <= n3; k++ )
      {
        if ( 
          ( i == 1 || i == n1 ) ||
          ( j == 1 || j == n2 ) ||
          ( k == 1 || k == n3  ) )
        {
          d[i-1+(j-1)*n1+(k-1)*n1*n2] = ( double ) ( i + j + k );
        }
      }
    }
  }

  printf ( "\n" );
  printf ( "BLEND_123_TEST\n" );
  printf ( "  BLEND_123 blends face values into a table.\n" );

  r8block_print ( n1, n2, n3, d, "  Initial data array" );

  for ( i = 1; i <= n1; i++ )
  {
    r = ( double ) (  i - 1 ) / ( double ) ( n1 - 1 );

    for ( j = 1; j <= n2; j++ )
    {
      s = ( double ) (  j - 1 ) / ( double ) ( n2 - 1 );

      for ( k = 1; k <= n3; k++ )
      {
        t = ( double ) (  k - 1 ) / ( double ) ( n3 - 1 );

        if ( 
          ( i == 1 || i == n1 ) ||
          ( j == 1 || j == n2 ) ||
          ( k == 1 || k == n3  ) )
        {
          continue;
        }

        d[i-1+(j-1)*n1+(k-1)*n1*n2] = blend_123 ( r, s, t, 
          d[   0+    0 *n1+    0 *n1*n2],
          d[   0+    0 *n1+(n3-1)*n1*n2],
          d[   0+(n2-1)*n1+    0 *n1*n2],
          d[   0+(n2-1)*n1+(n3-1)*n1*n2], 
          d[n1-1+    0 *n1+    0 *n1*n2],
          d[n1-1+    0 *n1+(n3-1)*n1*n2],
          d[n1-1+(n2-1)*n1+    0 *n1*n2],
          d[n1-1+(n2-1)*n1+(n3-1)*n1*n2], 
          d[ i-1+    0 *n1+    0 *n1*n2],
          d[ i-1+    0 *n1+(n3-1)*n1*n2],
          d[ i-1+(n2-1)*n1+    0 *n1*n2],
          d[ i-1+(n2-1)*n1+(n3-1)*n1*n2], 
          d[   0+( j-1)*n1+    0 *n1*n2],
          d[   0+( j-1)*n1+(n3-1)*n1*n2],
          d[n1-1+( j-1)*n1+    0 *n1*n2],
          d[n1-1+( j-1)*n1+(n3-1)*n1*n2], 
          d[   0+    0 *n1+( k-1)*n1*n2],
          d[   0+(n2-1)*n1+( k-1)*n1*n2],
          d[n1-1+    0 *n1+( k-1)*n1*n2],
          d[n1-1+(n2-1)*n1+( k-1)*n1*n2], 
          d[   0+( j-1)*n1+( k-1)*n1*n2],
          d[n1-1+( j-1)*n1+( k-1)*n1*n2],
          d[ i-1+    0 *n1+( k-1)*n1*n2],
          d[ i-1+(n2-1)*n1+( k-1)*n1*n2],
          d[ i-1+( j-1)*n1+    0 *n1*n2],
          d[ i-1+( j-1)*n1+(n3-1)*n1*n2] );
      }
    }
  }

  r8block_print ( n1, n2, n3, d, "  Interpolated data array" );

  free ( d );

  return;
}
/******************************************************************************/

void blend_i_0d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_I_0D1 tests BLEND_I_0D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int m;
  double x[5];

  m = 5;
  x[0] = 100.0;
  x[m-1] = 100.0 + ( m - 1 ) * 5;

  printf ( "\n" );
  printf ( "BLEND_I_0D1\n" );
  printf ( "  BLEND_I_0D1 interpolates data in a vector.\n" );
  printf ( "\n" );
  printf ( "  X[0] = %g\n", x[0] );
  printf ( "  X(%d)= %g\n", m - 1, x[m-1] );
  printf ( "\n" );
  printf ( "  Interpolated values:\n" );
  printf ( "\n" );

  blend_i_0d1 ( x, m );

  for ( i = 0; i < m; i++ )
  {
    printf ( "  %6d  %8g\n", i, x[i] );
  }
  return;
}
/******************************************************************************/

void blend_ij_0d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJ_0D1_TEST tests BLEND_IJ_0D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m1 = 5;
  int m2 = 4;
  double r;
  double s;
  double x[20];

  printf ( "\n" );
  printf ( "BLEND_IJ_0D1_TEST\n" );
  printf ( "  BLEND_IJ_0D1 interpolates data in a table,\n" );
  printf ( "  from corner data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns.\n", m1, m2 );
/*
  Load data in the corners only.
*/
  i = 0;
  j = 0;
  r = ( double ) i / ( double ) ( m1 - 1 );
  s = ( double ) j / ( double ) ( m2 - 1 );
  x[i*m2+j] = cubic_rs ( r, s, 1 );

  i = m1 - 1;
  j = 0;
  r = ( double ) i / ( double ) ( m1 - 1 );
  s = ( double ) j / ( double ) ( m2 - 1 );
  x[i*m2+j] = cubic_rs ( r, s, 1 );

  i = 0;
  j = m2 - 1;
  r = ( double ) i / ( double ) ( m1 - 1 );
  s = ( double ) j / ( double ) ( m2 - 1 );
  x[i*m2+j] = cubic_rs ( r, s, 1 );

  i = m1 - 1;
  j = m2 - 1;
  r = ( double ) i / ( double ) ( m1 - 1 );
  s = ( double ) j / ( double ) ( m2 - 1 );
  x[i*m2+j] = cubic_rs ( r, s, 1 );

  blend_ij_0d1 ( x, m1, m2 );

  printf ( "\n" );
  printf ( "  Values interpolated by BLEND_IJ_0D1:\n" );
  printf ( "\n" );

  for ( i = 0; i < m1; i++ )
  {
    printf ( "  %8g  %8g  %8g  %8g\n", x[i*m2], x[i*m2+1], x[i*m2+2], x[i*m2+3] );
  }

  return;
}
/******************************************************************************/

void blend_ij_1d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJ_1D1_TEST tests BLEND_IJ_1D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m1 = 5;
  int m2 = 4;
  double r;
  double s;
  double x[20];

  printf ( "\n" );
  printf ( "BLEND_IJ_1D1_TEST\n" );
  printf ( "  BLEND_IJ_1D1 interpolates data in a table,\n" );
  printf ( "  from edge data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns.\n", m1, m2 );
/*
  Load data in the edges only.
*/
  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    j = 0;
    s = ( double ) j / ( double ) ( m2 - 1 );
    x[i*m2+j] = cubic_rs ( r, s, 1 );

    j = m2 - 1;
    s = ( double ) j / ( double ) ( m2 - 1 );
    x[i*m2+j] = cubic_rs ( r, s, 1 );
  }

  for ( j = 0; j < m2; j++ )
  {
    s = ( double ) j / ( double ) ( m2 - 1 );

    i = 0;
    r = ( double ) i / ( double ) ( m1 - 1 );
    x[i*m2+j] = cubic_rs ( r, s, 1 );

    i = m1 - 1;
    r = ( double ) i / ( double ) ( m1 - 1 );
    x[i*m2+j] = cubic_rs ( r, s, 1 );
  }

  blend_ij_1d1 ( x, m1, m2 );

  printf ( "\n" );
  printf ( "  Values interpolated by BLEND_IJ_1D1:\n" );
  printf ( "\n" );

  for ( i = 0; i < m1; i++ )
  {
    printf ( "  %8g  %8g  %8g  %8g\n", x[i*m2], x[i*m2+1], x[i*m2+2], x[i*m2+3] );
  }

  return;
}
/******************************************************************************/

void blend_ij_w_1d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJ_W_1D1_TEST tests BLEND_IJ_W_1D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int n1 = 5;
  int n2 = 5;
  double r[5];
  double rad;
  double rr;
  const double r8_pi = 3.141592653589793;
  double s[5];
  double ss;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "BLEND_IJ_W_1D1_TEST\n" );
  printf ( "  BLEND_IJ_W_1D1 uses weighted blending to fill in the\n" );
  printf ( "  integerior of a table.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns.\n", n1, n2 );

  rad = 3.0;

  x = r8mat_zeros_new ( n1, n2 );
  y = r8mat_zeros_new ( n1, n2 );
/*
  Set the boundary values.

  It turns out that our values correspond to the X and Y
  coordinates of a quarter circle of radius 3, although
  it is by no means necessary that a formula for the data
  be known.
*/
  for ( i = 0; i < n1; i++ )
  {
    rr = pow ( ( double ) ( i ) / ( double ) ( n1 - 1 ), 2 );
    r[i] = rr;
    x[i*n2+0] = 0.0;
    y[i*n2+0] = 0.0;
    x[i*n2+n2-1] = rad * cos ( 0.5 * r8_pi * ( 1.0 - rr ) );
    y[i*n2+n2-1] = rad * sin ( 0.5 * r8_pi * ( 1.0 - rr ) );
  }

  for ( j = 0; j < n2; j++ )
  {
    ss = pow ( ( double ) ( j ) / ( double ) ( n2 - 1 ), 2 );
    s[j] = ss;
    x[0*n2+j] = 0.0;
    y[0*n2+j] = rad * ss;
    x[(n1-1)*n2+j] = rad * ss;
    y[(n1-1)*n2+j] = 0.0;
  }

  blend_ij_w_1d1 ( x, r, s, n1, n2 );
  blend_ij_w_1d1 ( y, r, s, n1, n2 );

  printf ( "\n" );
  printf ( "     R           S           X           Y\n" );
  printf ( "\n" );

  for ( i = 0; i < n1; i++ )
  {
    printf ( "\n" );
    for ( j = 0; j < n2; j++ )
    {
      printf ( "  %8g  %8g  %8g  %8g\n", r[i], s[j], x[i*n2+j], y[i*n2+j] );
    }
  }

  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void blend_ijk_0d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJK_0D1_TEST tests BLEND_IJK_0D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int m1 = 4;
  int m2 = 3;
  int m3 = 3;
  int num_extreme;
  double r;
  double s;
  double t;
  double temp;
  double x[36];

  printf ( "\n" );
  printf ( "BLEND_IJK_0D1_TEST\n" );
  printf ( "  BLEND_IJK_0D1 interpolates data in a 3D table,\n" );
  printf ( "  from corner data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns by %d layers.\n", m1, m2, m3 );
/*
  Load data in the faces only.
*/
  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );
      for ( k = 0; k < m3; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );
        num_extreme = 0;
        if ( i == 0 || i == m1 - 1 )
        {
          num_extreme = num_extreme + 1;
        }
        if ( j == 0 || j == m2 - 1 )
        {
          num_extreme = num_extreme + 1;
        }
        if ( k == 0 || k == m3 - 1 )
        {
          num_extreme = num_extreme + 1;
        }
        if ( num_extreme >= 3 )
        {
          temp = quad_rst ( r, s, t, 1 );
        }
        else
        {
          temp = 0.0;
        }
        x[(i*m3+j)*m2+k] = temp;
      }
    }
  }

  printf ( "\n" );
  printf ( "  Data given to BLEND_IJK_0D1:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }
  blend_ijk_0d1 ( x, m1, m2, m3 );

  printf ( "\n" );
  printf ( "  Values interpolated by BLEND_IJK_0D1:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }

  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );
      for ( k = 0; k < m3; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );
        x[(i*m3+j)*m2+k] = quad_rst ( r, s, t, 1 );;
      }
    }
  }

  printf ( "\n" );
  printf ( "  Exact data:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }
  return;
}
/******************************************************************************/

void blend_ijk_1d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJK_1D1_TEST tests BLEND_IJK_1D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int m1 = 4;
  int m2 = 3;
  int m3 = 3;
  int num_extreme;
  double r;
  double s;
  double t;
  double temp;
  double x[36];

  printf ( "\n" );
  printf ( "BLEND_IJK_1D1_TEST\n" );
  printf ( "  BLEND_IJK_1D1 interpolates data in a 3D table,\n" );
  printf ( "  from edge data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns by %d layers.\n", m1, m2, m3 );
/*
  Load data in the faces only.
*/
  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );
      for ( k = 0; k < m3; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );
        num_extreme = 0;
        if ( i == 0 || i == m1 - 1 )
        {
          num_extreme = num_extreme + 1;
        }
        if ( j == 0 || j == m2 - 1 )
        {
          num_extreme = num_extreme + 1;
        }
        if ( k == 0 || k == m3 - 1 )
        {
          num_extreme = num_extreme + 1;
        }
        if ( num_extreme >= 2 )
        {
          temp = quad_rst ( r, s, t, 1 );
        }
        else
        {
          temp = 0.0;
        }
        x[(i*m3+j)*m2+k] = temp;
      }
    }
  }

  printf ( "\n" );
  printf ( "  Data given to BLEND_IJK_1D1:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }
  blend_ijk_1d1 ( x, m1, m2, m3 );

  printf ( "\n" );
  printf ( "  Values interpolated by BLEND_IJK_1D1:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }

  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );
      for ( k = 0; k < m3; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );
        x[(i*m3+j)*m2+k] = quad_rst ( r, s, t, 1 );
      }
    }
  }

  printf ( "\n" );
  printf ( "  Exact data:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }
  return;
}
/******************************************************************************/

void blend_ijk_2d1_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJK_2D1_TEST tests BLEND_IJK_2D1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int m1 = 4;
  int m2 = 3;
  int m3 = 3;
  double r;
  double s;
  double t;
  double temp;
  double x[36];

  printf ( "\n" );
  printf ( "BLEND_IJK_2D1_TEST\n" );
  printf ( "  BLEND_IJK_2D1 interpolates data in a 3D table,\n" );
  printf ( "  from face data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns by %d layers.\n", m1, m2, m3 );
/*
  Load data in the faces only.
*/
  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );
      for ( k = 0; k < m3; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );
        if ( i == 0 || i == m1 - 1 ||
             j == 0 || j == m2 - 1 ||
             k == 0 || k == m3 - 1 )
        {
          temp = quad_rst ( r, s, t, 1 );
        }
        else
        {
          temp = 0.0;
        }
        x[(i*m3+j)*m2+k] = temp;
      }
    }
  }

  printf ( "\n" );
  printf ( "  Data given to BLEND_IJK_2D1:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }
  blend_ijk_2d1 ( x, m1, m2, m3 );

  printf ( "\n" );
  printf ( "  Values interpolated by BLEND_IJK_2D1:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }

  for ( i = 0; i < m1; i++ )
   {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );
      for ( k = 0; k < m3; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );
        x[(i*m3+j)*m2+k] = quad_rst ( r, s, t, 1 );
      }
    }
  }

  printf ( "\n" );
  printf ( "  Exact data:\n" );
  printf ( "\n" );

  for ( k = 0; k < m3; k++ )
  {
    printf ( "\n" );
    printf ( "  Layer K = %d\n", k );
    printf ( "\n" );

    for ( i = 0; i < m1; i++ )
    {
      printf ( "  %8g  %8g  %8g\n", x[(i*m3+0)*m2+k], x[(i*m3+1)*m2+k],
        x[(i*m3+2)*m2+k] );
    }
  }
  return;
}
/******************************************************************************/

void blend_r_0dn_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_R_0DN_TEST tests BLEND_R_0DN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  const int m = 11;
  const int n = 2;
  double r;
  double *x;

  printf ( "\n" );
  printf ( "BLEND_R_0DN_TEST\n" );
  printf ( "  BLEND_R_0DN interpolates endpoint vector data\n" );
  printf ( "  into a list.\n" );
  printf ( "\n" );
  printf ( "  The list is %d rows long.\n", m );
  printf ( "  Each vector has length %d.\n", n );

  x = r8mat_zeros_new ( m, n );

  for ( i = 0; i < m; i++ )
  {
    r = ( double ) ( i ) / ( double ) ( m - 1 );
    blend_r_0dn ( r, x+i*n, n, powers_r );
  }

  r8mat_print ( n, m, x, "  Data blended by BLEND_R_0DN:" );
/*
  Load all data.
*/
  for ( i = 0; i < m; i++ )
  {
    r = ( double ) ( i ) / ( double ) ( m - 1 );
    for ( j = 0; j < n; j++ )
    {
      x[i*n+j] = powers_r ( r, j );
    }
  }

  r8mat_print ( n, m, x, "  Exact data:" );

  free ( x );

  return;
}
/******************************************************************************/

void blend_r_0dn_identity_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_R_0DN_IDENTITY_TEST tests BLEND_R_0DN on the identity map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double x[1];

  printf ( "\n" );
  printf ( "BLEND_R_0DN_IDENTITY_TEST\n" );
  printf ( "  Identity test on BLEND_R_0DN.\n" );

  n = 1;

  r = 0.0;
  blend_r_0dn ( r, x, n, identity_r );
  printf ( "  %8g  %8g\n", r, x[0] );

  r = 1.0;
  blend_r_0dn ( r, x, n, identity_r );
  printf ( "  %8g  %8g\n", r, x[0] );

  r = 0.5;
  blend_r_0dn ( r, x, n, identity_r );
  printf ( "  %8g  %8g\n", r, x[0] );

  return;
}
/******************************************************************************/

void blend_r_0dn_stretch_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_R_0DN_STRETCH_TEST tests BLEND_R_0DN on the stretch map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double x[1];

  printf ( "\n" );
  printf ( "BLEND_R_0DN_STRETCH\n" );
  printf ( "  Stretch test on BLEND_R_0DN.\n" );

  n = 1;

  r = 0.0;
  blend_r_0dn ( r, x, n, stretch_r );
  printf ( "  %8g  %8g\n", r, x[0] );

  r = 1.0;
  blend_r_0dn ( r, x, n, stretch_r );
  printf ( "  %8g  %8g\n", r, x[0] );

  r = 0.5;
  blend_r_0dn ( r, x, n, stretch_r );
  printf ( "  %8g  %8g\n", r, x[0] );

  return;
}
/******************************************************************************/

void blend_rs_0dn_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_0DN_TEST tests BLEND_RS_0DN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 October 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  const int m1 = 5;
  const int m2 = 4;
  double r;
  double s;
  double *x;

  printf ( "\n" );
  printf ( "BLEND_RS_0DN_TEST\n" );
  printf ( "  BLEND_RS_0DN interpolates data in a table,\n" );
  printf ( "  from corner data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns.\n", m1, m2 );

  x = r8mat_zeros_new ( m1, m2 );

  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) (  i ) / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) (  j ) / ( double ) ( m2 - 1 );
      blend_rs_0dn ( r, s, x+i*m2+j, 1, cubic_rs );
    }
  }

  printf ( "\n" );
  printf ( "  Data blended by BLEND_RS_0DN:\n" );
  printf ( "\n" );

  for ( i = 0; i < m1; i++ )
  {
    for ( j = 0; j < m2; j++ )
    {
      printf ( "%14.6g", x[i*m2+j] );
    }
    printf ( "\n" );
  }
/*
  Load all data.
*/
  for ( i = 0; i < m1; i++ )
  {
    for ( j = 0; j < m2; j++ )
    {
      r = ( double ) (  i ) / ( double ) ( m1 - 1 );
      s = ( double ) (  j ) / ( double ) ( m2 - 1 );
      x[i*m2+j] = cubic_rs ( r, s, 1 );
    }
  }

  printf ( "\n" );
  printf ( "  Exact data:\n" );
  printf ( "\n" );

  for ( i = 0; i < m1; i++ )
  {
    for ( j = 0; j < m2; j++ )
    {
      printf ( "%14.6g", x[i*m2+j] );
    }
    printf ( "\n" );
  }

  free ( x );

  return;
}
/******************************************************************************/

void blend_rs_0dn_identity_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_0DN_IDENTITY_TEST tests BLEND_RS_0DN on the identity map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double x[2];

  printf ( "\n" );
  printf ( "BLEND_RS_0DN_IDENTITY_TEST\n" );
  printf ( "  Identity test on BLEND_RS_0DN.\n" );

  n = 2;

  r = 0.0;
  s = 0.0;
  blend_rs_0dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 0.0;
  blend_rs_0dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.0;
  s = 1.0;
  blend_rs_0dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 1.0;
  blend_rs_0dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.5;
  s = 0.5;
  blend_rs_0dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  return;
}
/******************************************************************************/

void blend_rs_0dn_stretch_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_0DN_STRETCH tests BLEND_RS_0DN on the stretch map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double x[2];

  printf ( "\n" );
  printf ( "BLEND_RS_0DN_STRETCH\n" );
  printf ( "  Stretch test on BLEND_RS_0DN.\n" );

  n = 2;

  r = 0.0;
  s = 0.0;
  blend_rs_0dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 0.0;
  blend_rs_0dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.0;
  s = 1.0;
  blend_rs_0dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 1.0;
  blend_rs_0dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.5;
  s = 0.5;
  blend_rs_0dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  return;
}
/******************************************************************************/

void blend_rs_1dn_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_1DN_TEST tests BLEND_RS_1DN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 October 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  const int m1 = 5;
  const int m2 = 4;
  double r;
  double s;
  double *x;

  printf ( "\n" );
  printf ( "BLEND_RS_1DN_TEST\n" );
  printf ( "  BLEND_RS_1DN interpolates data in a table,\n" );
  printf ( "  from edge data.\n" );
  printf ( "\n" );
  printf ( "  The table is %d rows by %d columns.\n", m1, m2 );

  x = r8mat_zeros_new ( m1, m2 );

  for ( i = 0; i < m1; i++ )
  {
    r = ( double ) (  i ) / ( double ) ( m1 - 1 );
    for ( j = 0; j < m2; j++ )
    {
      s = ( double ) (  j ) / ( double ) ( m2 - 1 );
      blend_rs_1dn ( r, s, x+i*m2+j, 1, cubic_rs );
    }
  }

  printf ( "\n" );
  printf ( "  Data blended by BLEND_RS_1DN:\n" );
  printf ( "\n" );

  for ( i = 0; i < m1; i++ )
  {
    for ( j = 0; j < m2; j++ )
    {
      printf ( "%14.6g", x[i*m2+j] );
    }
    printf ( "\n" );
  }
/*
  Load all data.
*/
  for ( i = 0; i < m1; i++ )
  {
    for ( j = 0; j < m2; j++ )
    {
      r = ( double ) (  i ) / ( double ) ( m1 - 1 );
      s = ( double ) (  j ) / ( double ) ( m2 - 1 );
      x[i*m2+j] = cubic_rs ( r, s, 1 );
    }
  }

  printf ( "\n" );
  printf ( "  Exact data:\n" );
  printf ( "\n" );

  for ( i = 0; i < m1; i++ )
  {
    for ( j = 0; j < m2; j++ )
    {
      printf ( "%14.6g", x[i*m2+j] );
    }
    printf ( "\n" );
  }

  free ( x );

  return;
}
/******************************************************************************/

void blend_rs_1dn_identity_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_1DN_IDENTITY_TEST tests BLEND_RS_1DN on the identity map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double x[2];

  printf ( "\n" );
  printf ( "BLEND_RS_1DN_IDENTITY_TEST\n" );
  printf ( "  Identity test on BLEND_RS_1DN.\n" );

  n = 2;

  r = 0.0;
  s = 0.0;
  blend_rs_1dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 0.0;
  blend_rs_1dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.0;
  s = 1.0;
  blend_rs_1dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 1.0;
  blend_rs_1dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.5;
  s = 0.5;
  blend_rs_1dn ( r, s, x, n, identity_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  return;
}
/******************************************************************************/

void blend_rs_1dn_stretch_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_1DN_STRETCH tests BLEND_RS_1DN on the stretch map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double x[2];

  printf ( "\n" );
  printf ( "BLEND_RS_1DN_STRETCH\n" );
  printf ( "  Stretch test on BLEND_RS_1DN.\n" );

  n = 2;

  r = 0.0;
  s = 0.0;
  blend_rs_1dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 0.0;
  blend_rs_1dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.0;
  s = 1.0;
  blend_rs_1dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 1.0;
  s = 1.0;
  blend_rs_1dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  r = 0.5;
  s = 0.5;
  blend_rs_1dn ( r, s, x, n, stretch_rs );
  printf ( "  %8g  %8g  %8g  %8g\n", r, s, x[0], x[1] );

  return;
}
/******************************************************************************/

void blend_rst_0dn_identity_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_0DN_IDENTITY_TEST tests BLEND_RST_0DN on the identity map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double t;
  double x[3];

  printf ( "\n" );
  printf ( "BLEND_RST_0DN_IDENTITY_TEST\n" );
  printf ( "  Identity test on BLEND_RST_0DN.\n" );

  n = 3;

  r = 0.0;
  s = 0.0;
  t = 0.0;
  blend_rst_0dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 0.0;
  t = 0.0;
  blend_rst_0dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 1.0;
  t = 0.0;
  blend_rst_0dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 0.0;
  t = 1.0;
  blend_rst_0dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 1.0;
  t = 1.0;
  blend_rst_0dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.5;
  s = 0.5;
  t = 0.5;
  blend_rst_0dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  return;
}
/******************************************************************************/

void blend_rst_0dn_stretch_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_0DN_STRETCH tests BLEND_RST_0DN on the stretch map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double t;
  double x[3];

  printf ( "\n" );
  printf ( "BLEND_RST_0DN_STRETCH\n" );
  printf ( "  Stretch test on BLEND_RST_0DN.\n" );

  n = 3;

  r = 0.0;
  s = 0.0;
  t = 0.0;
  blend_rst_0dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 0.0;
  t = 0.0;
  blend_rst_0dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 1.0;
  t = 0.0;
  blend_rst_0dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 0.0;
  t = 1.0;
  blend_rst_0dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 1.0;
  t = 1.0;
  blend_rst_0dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.5;
  s = 0.5;
  t = 0.5;
  blend_rst_0dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  return;
}
/******************************************************************************/

void blend_rst_1dn_identity_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_1DN_IDENTITY_TEST tests BLEND_RST_1DN on the identity map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double t;
  double x[3];

  printf ( "\n" );
  printf ( "BLEND_RST_1DN_IDENTITY_TEST\n" );
  printf ( "  Identity test on BLEND_RST_1DN.\n" );

  n = 3;

  r = 0.0;
  s = 0.0;
  t = 0.0;
  blend_rst_1dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 0.0;
  t = 0.0;
  blend_rst_1dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 1.0;
  t = 0.0;
  blend_rst_1dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 0.0;
  t = 1.0;
  blend_rst_1dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 1.0;
  t = 1.0;
  blend_rst_1dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.5;
  s = 0.5;
  t = 0.5;
  blend_rst_1dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  return;
}
/******************************************************************************/

void blend_rst_1dn_stretch_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_1DN_STRETCH tests BLEND_RST_1DN on the stretch map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double t;
  double x[3];

  printf ( "\n" );
  printf ( "BLEND_RST_1DN_STRETCH\n" );
  printf ( "  Stretch test on BLEND_RST_1DN.\n" );

  n = 3;

  r = 0.0;
  s = 0.0;
  t = 0.0;
  blend_rst_1dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 0.0;
  t = 0.0;
  blend_rst_1dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 1.0;
  t = 0.0;
  blend_rst_1dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 0.0;
  t = 1.0;
  blend_rst_1dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 1.0;
  t = 1.0;
  blend_rst_1dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.5;
  s = 0.5;
  t = 0.5;
  blend_rst_1dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  return;
}
/******************************************************************************/

void blend_rst_2dn_identity_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_2DN_IDENTITY_TEST tests BLEND_RST_2DN on the identity map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double t;
  double x[3];

  printf ( "\n" );
  printf ( "BLEND_RST_2DN_IDENTITY_TEST\n" );
  printf ( "  Identity test on BLEND_RST_2DN.\n" );

  n = 3;

  r = 0.0;
  s = 0.0;
  t = 0.0;
  blend_rst_2dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 0.0;
  t = 0.0;
  blend_rst_2dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 1.0;
  t = 0.0;
  blend_rst_2dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 0.0;
  t = 1.0;
  blend_rst_2dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 1.0;
  t = 1.0;
  blend_rst_2dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.5;
  s = 0.5;
  t = 0.5;
  blend_rst_2dn ( r, s, t, x, n, identity_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  return;
}
/******************************************************************************/

void blend_rst_2dn_stretch_test ( )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_2DN_STRETCH tests BLEND_RST_2DN on the stretch map.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt
*/
{
  int n;
  double r;
  double s;
  double t;
  double x[3];

  printf ( "\n" );
  printf ( "BLEND_RST_2DN_STRETCH\n" );
  printf ( "  Stretch test on BLEND_RST_2DN.\n" );

  n = 3;

  r = 0.0;
  s = 0.0;
  t = 0.0;
  blend_rst_2dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 0.0;
  t = 0.0;
  blend_rst_2dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 1.0;
  t = 0.0;
  blend_rst_2dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.0;
  s = 0.0;
  t = 1.0;
  blend_rst_2dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 1.0;
  s = 1.0;
  t = 1.0;
  blend_rst_2dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  r = 0.5;
  s = 0.5;
  t = 0.5;
  blend_rst_2dn ( r, s, t, x, n, stretch_rst );
  printf ( "  %8g  %8g  %8g  %8g  %8g  %8g\n", r, s, t, x[0], x[1], x[2] );

  return;
}
/******************************************************************************/

double cubic_rs ( double r, double s, int i )

/******************************************************************************/
/*
  Purpose:

    CUBIC_RS evaluates a function of R and S used for some tests.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt
*/
{
  double xi;

  xi = 20.0 * ( r * r * s * s * s );

  return xi;
}
/******************************************************************************/

double quad_rst ( double r, double s, double t, int i )

/******************************************************************************/
/*
  Purpose:

    QUAD_RST evaluates a function of R, S and T used for some tests.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt
*/
{
  double xi;

  xi = 18.0 * ( r * r + s + t );

  return xi;
}
/******************************************************************************/

double identity_r ( double r, int i )

/******************************************************************************/
/*
  Purpose:

    IDENTITY_R returns a data component given (R).

  Discussion:

    This is a dummy routine, which simply returns (R).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, double R, the coordinate of a point that lies on the
    boundary of the cube.

    Input, int I, the component of the data which is to be returned.

    Output, double IDENTITY_R, the I-th component of the data vector X, 
    evaluated at the point (R), which is an endpoint of the unit line segment.
*/
{
  double xi;

  if ( i == 0 )
  {
    xi = r;
  }
  else
  {
    printf ( "\n" );
    printf ( "IDENTITY_R - Fatal error!\n" );
    printf ( "  Illegal component index I = %d\n", i );
    xi = 0.0;
  }

  return xi;
}
/******************************************************************************/

double identity_rs ( double r, double s, int i )

/******************************************************************************/
/*
  Purpose:

    IDENTITY_RS returns a data component given (R,S).

  Discussion:

    This is a dummy routine, which simply returns (R,S).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, double R, S, the coordinates of a point that lies on the
    boundary of the square.

    Input, int I, the component of the data which is to be returned.

    Output, double IDENTITY_RS, the I-th component of the data vector X, 
    evaluated at (R,S), which is on a corner, or edge, of the unit square.
*/
{
  double xi;

  if ( i == 0 )
  {
    xi = r;
  }
  else if ( i == 1 )
  {
    xi = s;
  }
  else
  {
    printf ( "\n" );
    printf ( "IDENTITY_RS - Fatal error!\n" );
    printf ( "  Illegal component index I = %d\n", i );
    xi = 0.0;
  }

  return xi;
}
/******************************************************************************/

double identity_rst ( double r, double s, double t, int i )

/******************************************************************************/
/*
  Purpose:

    IDENTITY_RST returns a data component given (R,S,T).

  Discussion:

    This is a dummy routine, which simply returns (R,S,T).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, double R, S, T, the coordinates of a point that lies on the
    boundary of the cube.

    Input, int I, the component of the data which is to be returned.

    Output, double IDENTITY_RST, the I-th component of the data vector X, evaluated
    at the point (R,S), which is on a corner, edge or face of the unit cube.
*/
{
  double xi;

  if ( i == 0 )
  {
    xi = r;
  }
  else if ( i == 1 )
  {
    xi = s;
  }
  else if ( i == 2 )
  {
    xi = t;
  }
  else
  {
    printf ( "\n" );
    printf ( "IDENTITY_RST - Fatal error!\n" );
    printf ( "  Illegal component index I = %d\n", i );
    xi = 0.0;
  }

  return xi;
}
/******************************************************************************/

double powers_r ( double r, int j )

/******************************************************************************/
/*
  Purpose:

    POWERS_R returns a data component given (R).

  Discussion:

    X(R,J) = R^(J+1)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, double R, the coordinate of a point.

    Input, int J, the component of the data.

    Output, double X, the J-th component of the data vector X, evaluated
    at the point (R).
*/
{
  double x;

  x = pow ( r, j + 1 );

  return x;
}
/******************************************************************************/

double stretch_r ( double r, int i )

/******************************************************************************/
/*
  Purpose:

    STRETCH_R returns a data component given (R).

  Discussion:

    This routine shifts by 1 and stretches by 2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, double R, the coordinate of a point that lies on the
    boundary of the cube.

    Input, int I, the component of the data which is to be returned.

    Output, double STRETCH_R, the I-th component of the data vector X, evaluated
    at the point (R), which is on an endpoint of the unit line segment.
*/
{
  double xi;

  if ( i == 0 )
  {
    xi = 2.0 * r + 1.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "STRETCH_R - Fatal error\n" );
    printf ( "  Illegal component index I = %d\n", i );
    xi = 0.0;
  }

  return xi;
}
/******************************************************************************/

double stretch_rs ( double r, double s, int i )

/******************************************************************************/
/*
  Purpose:

    STRETCH_RS returns a data component given (R,S).

  Discussion:

    This routine shifts by (1,2) and stretches by (3,4).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, double R, S, the coordinates of a point that lies on the
    boundary of the square.

    Input, int I, the component of the data which is to be returned.

    Output, double STRETCH_RS, the I-th component of the data vector X, 
    evaluated at (R,S), which is on a corner, or edge, of the unit square.
*/
{
  double xi;

  if ( i == 0 )
  {
    xi = 3.0 * r + 1.0;
  }
  else if ( i == 1 )
  {
    xi = 4.0 * s + 2.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "STRETCH_RS - Fatal error!\n" );
    printf ( "  Illegal component index I = %d\n", i );
    xi = 0.0;
  }

  return xi;
}
/******************************************************************************/

double stretch_rst ( double r, double s, double t, int i )

/******************************************************************************/
/*
  Purpose:

    STRETCH_RST returns a data component given (R,S,T).

  Discussion:

    This routine shifts by (1,2,3) and stretches by (4,5,6)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, double R, S, T, the coordinates of a point that lies on the
    boundary of the cube.

    Input, int I, the component of the data which is to be returned.

    Output, double STRETCH_RST, the I-th component of the data vector X, evaluated
    at the point (R,S), which is on a corner, edge or face of the unit cube.
*/
{
  double xi;

  if ( i == 0 )
  {
    xi = 4.0 * r + 1.0;
  }
  else if ( i == 1 )
  {
    xi = 5.0 * s + 2.0;
  }
  else if ( i == 2 )
  {
    xi = 6.0 * t + 3.0;
  }
  else
  {
    printf ( "\n" );
    printf ( "STRETCH_RST - Fatal error\n" );
    printf ( "  Illegal component index I = %d\n", i );
    xi = 0.0;
  }

  return xi;
}
