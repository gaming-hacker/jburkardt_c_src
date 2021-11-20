# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "fd2d_heat_steady.h"

/******************************************************************************/

double *fd2d_heat_steady ( int nx, int ny, double x[], double y[], 
  double d ( double x, double y ), double f ( double x, double y ) )

/******************************************************************************/
/*
  Purpose:

    FD2D_HEAT_STEADY solves the steady 2D heat equation.

  Discussion:

    Nodes are assigned a single index K, which increases as:

    (NY-1)*NX+1  (NY-1)*NX+2  ...  NY * NX
           ....         ....  ...    .....
           NX+1         NX+2  ...   2 * NX
              1            2  ...       NX

    Therefore, the neighbors of an interior node numbered C are

             C+NY
              |
      C-1 --- C --- C+1
              |
             C-NY

    Nodes on the lower boundary satisfy:
      1 <= K <= NX
    Nodes on the upper boundary satisfy:
      (NY-1)*NX+1 <= K <= NY * NX
    Nodes on the left boundary satisfy:
      mod ( K, NX ) = 1
    Nodes on the right boundary satisfy:
      mod ( K, NX ) = 0

    If we number rows from bottom I = 1 to top I = NY
    and columns from left J = 1 to right J = NX, we have
      K = ( I - 1 ) * NX + J
    and
      J = 1 + mod ( K - 1, NX )
      I = 1 + ( K - J ) / NX
      
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2013

  Author:

    John Burkardt

  Parameters:

    Input, int NX, NY, the number of grid points in X and Y.

    Input, double X[NX], Y[NY], the coordinates of grid lines.

    Input, double D ( X, Y ), evaluates the thermal
    conductivity.

    Input, double F ( X, Y ), evaluates the heat 
    source term.

    Output, double FD2D_HEAT_STEADY[NX*NY], the approximation to the solution
    at the grid points.
*/
{
  double *a;
  int n;
  double *u;
/*
  Set the total number of unknowns.
*/
  n = nx * ny;
/*
  Set up the matrix and right hand side.
*/
  a = ( double * ) malloc ( n * n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
/*
  Define the matrix at interior points.
*/
  interior ( nx, ny, x, y, d, f, n, a, u );
/*
  Handle boundary conditions.
*/
  boundary ( nx, ny, x, y, n, a, u );
/*
  Solve the linear system.
*/
  r8mat_fs ( n, a, u );
/*
  Free memory.
*/
  free ( a );

  return u;
}
/******************************************************************************/

void interior ( int nx, int ny, double x[], double y[], 
  double d ( double x, double y ), double f ( double x, double y ), int n, 
  double a[], double rhs[] )

/******************************************************************************/
/*
  Purpose:

    INTERIOR sets up the matrix and right hand side at interior nodes.

  Discussion:

    Nodes are assigned a single index K, which increases as:

    (NY-1)*NX+1  (NY-1)*NX+2  ...  NY * NX
           ....         ....  ...    .....
           NX+1         NX+2  ...   2 * NX
              1            2  ...       NX

    Therefore, the neighbors of an interior node numbered C are

             C+NY
              |
      C-1 --- C --- C+1
              |
             C-NY

    If we number rows from bottom I = 1 to top I = NY
    and columns from left J = 1 to right J = NX, then the relationship
    between the single index K and the row and column indices I and J is:
      K = ( I - 1 ) * NX + J
    and
      J = 1 + mod ( K - 1, NX )
      I = 1 + ( K - J ) / NX
      
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2013

  Author:

    John Burkardt

  Parameters:

    Input, int NX, NY, the number of grid points in X and Y.

    Input, double X[NX], Y[NY], the coordinates of grid lines.

    Input, double D ( double X, double Y ), evaluates the thermal
    conductivity.

    Input, double function F ( double X, double Y ), evaluates the heat 
    source term.

    Input, int N, the number of nodes.

    Output, double A[N*N], the system matrix, with the entries for 
    the interior nodes filled in.

    Output, double RHS[N], the system right hand side, with the 
    entries for the interior nodes filled in.
*/
{
  double dce;
  double dcn;
  double dcs;
  double dcw;
  double dx;
  double dy;
  int ic;
  int in;
  int is;
  int jc;
  int je;
  int jw;
  int kc;
  int ke;
  int kn;
  int ks;
  int kw;
/*
  For now, assume X and Y are equally spaced.
*/
  dx = x[1] - x[0];
  dy = y[1] - y[0];

  for ( ic = 1; ic < ny - 1; ic++ )
  {
    for ( jc = 1; jc < nx - 1; jc++ )
    {
      in = ic + 1;
      is = ic - 1;
      je = jc + 1;
      jw = jc - 1;

      kc = ic * nx + jc;
      ke = kc + 1;
      kw = kc - 1;
      kn = kc + nx;
      ks = kc - nx;

      dce = d ( 0.5 * ( x[jc] + x[je] ),         y[ic] );
      dcw = d ( 0.5 * ( x[jc] + x[jw] ),         y[ic] );
      dcn = d (         x[jc],           0.5 * ( y[ic] + y[in] ) );
      dcs = d (         x[jc],           0.5 * ( y[ic] + y[is] ) );

      a[kc+kc*n] = ( dce + dcw ) / dx / dx + ( dcn + dcs ) / dy / dy;
      a[kc+ke*n] = - dce         / dx / dx;
      a[kc+kw*n] =       - dcw   / dx / dx;
      a[kc+kn*n] =                           - dcn         / dy / dy;
      a[kc+ks*n] =                                 - dcs   / dy / dy;

      rhs[kc] = f ( x[jc], y[ic] );
    }
  }

  return;
}
/******************************************************************************/

double r8_abs ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_ABS returns the absolute value of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the quantity whose absolute value is desired.

    Output, double R8_ABS, the absolute value of X.
*/
{
  double value;

  if ( 0.0 <= x )
  {
    value = + x;
  }
  else
  {
    value = - x;
  }
  return value;
}
/******************************************************************************/

void r8mat_fs ( int n, double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_FS factors and solves a system with one right hand side.

  Discussion:

    This routine uses partial pivoting, but no pivot vector is required.

    This routine differs from R8MAT_FSS in two ways:
    * only one right hand side is allowed;
    * the input matrix A is not modified.

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 January 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[N*N], the coefficient matrix of the linear system.

    Input/output, double X[N], on input, the right hand side of the
    linear system.  On output, the solution of the linear system.
*/
{
  double *a2;
  int i;
  int ipiv;
  int j;
  int jcol;
  double piv;
  double t;

  a2 = ( double * ) malloc ( n * n * sizeof ( double ) );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a2[i+j*n] = a[i+j*n];
    }
  }

  for ( jcol = 1; jcol <= n; jcol++ )
  {
/*
  Find the maximum element in column I.
*/
    piv = r8_abs ( a2[jcol-1+(jcol-1)*n] );
    ipiv = jcol;
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( piv < r8_abs ( a2[i-1+(jcol-1)*n] ) )
      {
        piv = r8_abs ( a2[i-1+(jcol-1)*n] );
        ipiv = i;
      }
    }

    if ( piv == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8MAT_FS - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", jcol );
      exit ( 1 );
    }
/*
  Switch rows JCOL and IPIV, and X.
*/
    if ( jcol != ipiv )
    {
      for ( j = 1; j <= n; j++ )
      {
        t                  = a2[jcol-1+(j-1)*n];
        a2[jcol-1+(j-1)*n] = a2[ipiv-1+(j-1)*n];
        a2[ipiv-1+(j-1)*n] = t;
      }
      t         = x[jcol-1];
      x[jcol-1] = x[ipiv-1];
      x[ipiv-1] = t;
    }
/*
  Scale the pivot row.
*/
    t = a2[jcol-1+(jcol-1)*n];
    a2[jcol-1+(jcol-1)*n] = 1.0;
    for ( j = jcol+1; j <= n; j++ )
    {
      a2[jcol-1+(j-1)*n] = a2[jcol-1+(j-1)*n] / t;
    }
    x[jcol-1] = x[jcol-1] / t;
/*
  Use the pivot row to eliminate lower entries in that column.
*/
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( a2[i-1+(jcol-1)*n] != 0.0 )
      {
        t = - a2[i-1+(jcol-1)*n];
        a2[i-1+(jcol-1)*n] = 0.0;
        for ( j = jcol+1; j <= n; j++ )
        {
          a2[i-1+(j-1)*n] = a2[i-1+(j-1)*n] + t * a2[jcol-1+(j-1)*n];
        }
        x[i-1] = x[i-1] + t * x[jcol-1];
      }
    }
  }
/*
  Back solve.
*/
  for ( jcol = n; 2 <= jcol; jcol-- )
  {
    for ( i = 1; i < jcol; i++ )
    {
      x[i-1] = x[i-1] - a2[i-1+(jcol-1)*n] * x[jcol-1];
    }
  }

  free ( a2 );

  return;
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

void r8vec_mesh_2d ( int nx, int ny, double xvec[], double yvec[], 
  double xmat[], double ymat[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MESH_2D creates a 2D mesh from X and Y vectors.

  Discussion:

    An R8VEC is a vector of R8's.

    NX = 2
    XVEC = ( 1, 2, 3 )
    NY = 3
    YVEC = ( 4, 5 )

    XMAT = (
      1, 2, 3
      1, 2, 3 )

    YMAT = (
      4, 4, 4
      5, 5, 5 ) 
    
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2013

  Parameters:

    Input, int NX, NY, the number of X and Y values.

    Input, double XVEC[NX], YVEC[NY], the X and Y coordinate
    values.

    Output, double XMAT[NX*NY], YMAT[NX*NY], the coordinate
    values of points on an NX by NY mesh.
*/
{
  int i;
  int j;

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      xmat[i+j*nx] = xvec[i];
    }
  }

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      ymat[i+j*nx] = yvec[j];
    }
  }

 return;
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
    fprintf ( stdout, "  %8d: %14f\n", i, a[i] );
  }

  return;
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

