# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

# include "ellipsoid_grid.h"

/******************************************************************************/

double *ellipsoid_grid ( int n, double r[3], double c[3], int ng )

/******************************************************************************/
/*
  Purpose:

    ELLIPSOID_GRID generates the grid points inside an ellipsoid.

  Discussion:

    The ellipsoid is specified as

      ( ( X - C1 ) / R1 )^2 
    + ( ( Y - C2 ) / R2 )^2 
    + ( ( Z - C3 ) / R3 )^2 = 1

    The user supplies a number N.  There will be N+1 grid points along
    the shortest axis.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of subintervals.

    Input, double R[3], the half axis lengths.

    Input, double C[3], the center of the ellipsoid.

    Input, int NG, the number of grid points.

    Output, double XYZ[3*NG], the grid point coordinates.
*/
{
  double h;
  int ii;
  int i;
  int j;
  int k;
  int m;
  int ng2;
  int ni;
  int nj;
  int nk;
  int np;
  double p[3*8];
  double rmin;
  double x;
  double *xyz;
  double y;
  double z;

  ng2 = 0;

  xyz = ( double * ) malloc ( 3 * ng * sizeof ( double ) );

  rmin = r8vec_min ( 3, r );

  if ( r[0] == rmin )
  {
    h = 2.0 * r[0] / ( double ) ( 2 * n + 1 );
    ni = n;
    nj = i4_ceiling ( r[1] / r[0] ) * ( double ) ( n );
    nk = i4_ceiling ( r[2] / r[0] ) * ( double ) ( n );
  }
  else if ( r[1] == rmin )
  {
    h = 2.0 * r[1] / ( double ) ( 2 * n + 1 );
    nj = n;
    ni = i4_ceiling ( r[0] / r[1] ) * ( double ) ( n );
    nk = i4_ceiling ( r[2] / r[1] ) * ( double ) ( n );
  }
  else
  {
    h = 2.0 * r[2] / ( double ) ( 2 * n + 1 );
    nk = n;
    ni = i4_ceiling ( r[0] / r[2] ) * ( double ) ( n );
    nj = i4_ceiling ( r[1] / r[2] ) * ( double ) ( n );
  }

  for ( k = 0; k <= nk; k++ )
  {
    z = c[2] + ( double ) ( k ) * h;
    for ( j = 0; j <= nj; j++ )
    {
      y = c[1] + ( double ) ( j ) * h;
      for ( i = 0; i <= ni; i++ )
      {
        x = c[0] + ( double ) ( i ) * h;
/*
  If we have left the ellipsoid, the I loop is completed.
*/
        if ( 1.0 < pow ( ( x - c[0] ) / r[0], 2 )
                 + pow ( ( y - c[1] ) / r[1], 2 )
                 + pow ( ( z - c[2] ) / r[2], 2 ) )
        {
          break;
        }
/*
  At least one point is generated, but more possible by symmetry.
*/
        np = 0;
        p[0+np*3] = x;
        p[1+np*3] = y;
        p[2+np*3] = z;

        np = 1;

        if ( 0 < i )
        {
          for ( m = 0; m < np; m++ )
          {
            p[0+(np+m)*3] = 2.0 * c[0] - p[0+m*3];
            p[1+(np+m)*3] = p[1+m*3];
            p[2+(np+m)*3] = p[2+m*3];
          }
          np = 2 * np;
        }

        if ( 0 < j )
        {
          for ( m = 0; m < np; m++ )
          {
            p[0+(np+m)*3] = p[0+m*3];
            p[1+(np+m)*3] = 2.0 * c[1] - p[1+m*3];
            p[2+(np+m)*3] = p[2+m*3];
          }
          np = 2 * np;
        }

        if ( 0 < k )
        {
          for ( m = 0; m < np; m++ )
          {
            p[0+(np+m)*3] = p[0+m*3];
            p[1+(np+m)*3] = p[1+m*3];
            p[2+(np+m)*3] = 2.0 * c[2] - p[2+m*3];
          }
          np = 2 * np;
        }
   
        for ( m = 0; m < np; m++ )
        {
          for ( ii = 0; ii < 3; ii++ )
          {
            xyz[ii+(ng2+m)*3] = p[ii+m*3];
          }
        }
        ng2 = ng2 + np;
      }
    }
  }
  return xyz;
}
/******************************************************************************/

int ellipsoid_grid_count ( int n, double r[3], double c[3] )

/******************************************************************************/
/*
 ELLIPSOID_GRID_COUNT counts the grid points inside an ellipsoid.

  Discussion:

    The ellipsoid is specified as

      ( ( X - C1 ) / R1 )^2 
    + ( ( Y - C2 ) / R2 )^2 
    + ( ( Z - C3 ) / R3 )^2 = 1

    The user supplies a number N.  There will be N+1 grid points along
    the shortest axis.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of subintervals.

    Input, double R[3], the half axis lengths.

    Input, double C[3], the center of the ellipsoid.

    Output, int ELLIPSOID_GRID_COUNT, the number of grid points.
*/
{
  double h;
  int i;
  int j;
  int k;
  int ng;
  int ni;
  int nj;
  int nk;
  int np;
  double rmin;
  double x;
  double y;
  double z;

  ng = 0;

  rmin = r8vec_min ( 3, r );

  if ( r[0] == rmin )
  {
    h = 2.0 * r[0] / ( double ) ( 2 * n + 1 );
    ni = n;
    nj = i4_ceiling ( r[1] / r[0] ) * ( double ) ( n );
    nk = i4_ceiling ( r[2] / r[0] ) * ( double ) ( n );
  }
  else if ( r[1] == rmin )
  {
    h = 2.0 * r[1] / ( double ) ( 2 * n + 1 );
    nj = n;
    ni = i4_ceiling ( r[0] / r[1] ) * ( double ) ( n );
    nk = i4_ceiling ( r[2] / r[1] ) * ( double ) ( n );
  }
  else
  {
    h = 2.0 * r[2] / ( double ) ( 2 * n + 1 );
    nk = n;
    ni = i4_ceiling ( r[0] / r[2] ) * ( double ) ( n );
    nj = i4_ceiling ( r[1] / r[2] ) * ( double ) ( n );
  }

  for ( k = 0; k <= nk; k++ )
  {
    z = c[2] + ( double ) ( k ) * h;
    for ( j = 0; j <= nj; j++ )
    {
      y = c[1] + ( double ) ( j ) * h;
      for ( i = 0; i <= ni; i++ )
      {
        x = c[0] + ( double ) ( i ) * h;
//
//  If we have left the ellipsoid, the I loop is completed.
//
        if ( 1.0 < pow ( ( x - c[0] ) / r[0], 2 )
                 + pow ( ( y - c[1] ) / r[1], 2 )
                 + pow ( ( z - c[2] ) / r[2], 2 ) )
        {
          break;
        }
//
//  At least one point is generated, but more possible by symmetry.
//
        np = 1;
        if ( 0 < i )
        {
          np = 2 * np;
        }
        if ( 0 < j )
        {
          np = 2 * np;
        }
        if ( 0 < k )
        {
          np = 2 * np;
        }
        ng = ng + np;
      }
    }
  }
  return ng;
}
/******************************************************************************/

int i4_ceiling ( double x )

/******************************************************************************/
/*
  Purpose:

    I4_CEILING rounds an R8 up to the nearest I4.

  Discussion:

    The "ceiling" of X is the value of X rounded towards plus infinity.

  Example:

    X        I4_CEILING(X)

   -1.1      -1
   -1.0      -1
   -0.9       0
   -0.1       0
    0.0       0
    0.1       1
    0.9       1
    1.0       1
    1.1       2
    2.9       3
    3.0       3
    3.14159   4

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number whose ceiling is desired.

    Output, int I4_CEILING, the ceiling of X.
*/
{
  int value;

  value = ( int ) x;

  if ( value < x )
  {
    value = value + 1;
  }

  return value;
}
/******************************************************************************/

void r83vec_print_part ( int n, double a[], int max_print, char *title )

/******************************************************************************/
/*
  Purpose:

    R83VEC_PRINT_PART prints "part" of an R83VEC.

  Discussion:

    The user specifies MAX_PRINT, the maximum number of lines to print.

    If N, the size of the vector, is no more than MAX_PRINT, then
    the entire vector is printed, one entry per line.

    Otherwise, if possible, the first MAX_PRINT-2 entries are printed,
    followed by a line of periods suggesting an omission,
    and the last entry.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries of the vector.

    Input, double A[3*N], the vector to be printed.

    Input, int MAX_PRINT, the maximum number of lines
    to print.

    Input, char *TITLE, a title.
*/
{
  int i;

  if ( max_print <= 0 )
  {
    return;
  }

  if ( n <= 0 )
  {
    return;
  }

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  if ( n <= max_print )
  {
    for ( i = 0; i < n; i++ )
    {
      fprintf ( stdout, "  %8d: %14g  %14g  %14g\n", i, a[0+i*3], a[1+i*3], a[2+i*3] );
    }
  }
  else if ( 3 <= max_print )
  {
    for ( i = 0; i < max_print - 2; i++ )
    {
      fprintf ( stdout, "  %8d: %14g  %14g  %14g\n", i, a[0+i*3], a[1+i*3], a[2+i*3] );
    }
    fprintf ( stdout, "  ........  ..............  ..............  ..............\n" );
    i = n - 1;
    fprintf ( stdout, "  %8d: %14g  %14g  %14g\n", i, a[0+i*3], a[1+i*3], a[2+i*3] );
  }
  else
  {
    for ( i = 0; i < max_print - 1; i++ )
    {
      fprintf ( stdout, "  %8d: %14g  %14g  %14g\n", i, a[0+i*3], a[1+i*3], a[2+i*3] );
    }
    i = max_print - 1;
    fprintf ( stdout, "  %8d: %14g  %14g  %14g  ...more entries...\n", 
      i, a[0+i*3], a[1+i*3], a[2+i*3] );
  }

  return;
}
/******************************************************************************/

void r8mat_write ( char *output_filename, int m, int n, double table[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_WRITE writes an R8MAT file.

  Discussion:

    An R8MAT is an array of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 June 2009

  Author:

    John Burkardt

  Parameters:

    Input, char *OUTPUT_FILENAME, the output filename.

    Input, int M, the spatial dimension.

    Input, int N, the number of points.

    Input, double TABLE[M*N], the data.
*/
{
  int i;
  int j;
  FILE *output;
/*
  Open the file.
*/
  output = fopen ( output_filename, "wt" );

  if ( !output )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8MAT_WRITE - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the output file.\n" );
    exit ( 1 );
  }
/*
  Write the data.
*/
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      fprintf ( output, "  %24.16g", table[i+j*m] );
    }
    fprintf ( output, "\n" );
  }
/*
  Close the file.
*/
  fclose ( output );

  return;
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

    12 November 2011

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

void timestamp ( void )

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
