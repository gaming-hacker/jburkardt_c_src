# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "burgers_solution.h"

/******************************************************************************/

double *burgers_viscous_time_exact1 ( double nu, int vxn, double vx[], int vtn, 
  double vt[] )

/******************************************************************************/
/*
  Purpose:

    BURGERS_VISCOUS_TIME_EXACT1 evaluates solution #1 to the Burgers equation.

  Discussion:

    The form of the Burgers equation considered here is

      du       du        d^2 u
      -- + u * -- = nu * -----
      dt       dx        dx^2

    for -1.0 < x < +1.0, and 0 < t.

    Initial conditions are u(x,0) = - sin(pi*x).  Boundary conditions
    are u(-1,t) = u(+1,t) = 0.  The viscosity parameter nu is taken
    to be 0.01 / pi, although this is not essential.

    The authors note an integral representation for the solution u(x,t),
    and present a better version of the formula that is amenable to
    approximation using Hermite quadrature.  

    This program library does little more than evaluate the exact solution
    at a user-specified set of points, using the quadrature rule.
    Internally, the order of this quadrature rule is set to 8, but the
    user can easily modify this value if greater accuracy is desired.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 November 2011

  Author:

    John Burkardt.

  Reference:

    Claude Basdevant, Michel Deville, Pierre Haldenwang, J Lacroix, 
    J Ouazzani, Roger Peyret, Paolo Orlandi, Anthony Patera,
    Spectral and finite difference solutions of the Burgers equation,
    Computers and Fluids,
    Volume 14, Number 1, 1986, pages 23-41.

  Parameters:

    Input, double NU, the viscosity.

    Input, int VXN, the number of spatial grid points.

    Input, double VX[VXN], the spatial grid points.

    Input, int VTN, the number of time grid points.

    Input, double VT[VTN], the time grid points.

    Output, double BURGERS_VISCOUS_TIME_EXACT1[VXN*VTN], the solution 
    of the Burgers equation at each space and time grid point.
*/
{
  double bot;
  double c;
  double r8_pi = 3.141592653589793;
  int qi;
  int qn = 8;
  double *qw;
  double *qx;
  int vti;
  int vxi;
  double *vu;
  double top;
/*
  Compute the rule.
*/
  qx = ( double * ) malloc ( qn * sizeof ( double ) );
  qw = ( double * ) malloc ( qn * sizeof ( double ) );

  hermite_ek_compute ( qn, qx, qw );
/*
  Evaluate U(X,T) for later times.
*/
  vu = ( double * ) malloc ( vxn * vtn * sizeof ( double ) );

  for ( vti = 0; vti < vtn; vti++ )
  {
    if ( vt[vti] == 0.0 )
    {
      for ( vxi = 0; vxi < vxn; vxi++ )
      {
        vu[vxi+vti*vxn] = - sin ( r8_pi * vx[vxi] );
      }
    }
    else
    {
      for ( vxi = 0; vxi < vxn; vxi++ )
      {
        top = 0.0;
        bot = 0.0;
        for ( qi = 0; qi < qn; qi++ )
        {
          c = 2.0 * sqrt ( nu * vt[vti] );

          top = top - qw[qi] * c * sin ( r8_pi * ( vx[vxi] - c * qx[qi] ) ) 
            * exp ( - cos ( r8_pi * ( vx[vxi] - c * qx[qi]  ) ) 
            / ( 2.0 * r8_pi * nu ) );

          bot = bot + qw[qi] * c 
            * exp ( - cos ( r8_pi * ( vx[vxi] - c * qx[qi]  ) ) 
            / ( 2.0 * r8_pi * nu ) );

          vu[vxi+vti*vxn] = top / bot;
        }
      }
    }
  }
  free ( qw );
  free ( qx );

  return vu;
}
/******************************************************************************/

double *burgers_viscous_time_exact2 ( double nu, int xn, double x[], int tn, 
  double t[] )

/******************************************************************************/
/*
  Purpose:

    BURGERS_VISCOUS_TIME_EXACT1 evaluates solution #2 to the Burgers equation.

  Discussion:

    The form of the Burgers equation considered here is

      du       du        d^2 u
      -- + u * -- = nu * -----
      dt       dx        dx^2

    for 0.0 < x < 2 Pi and 0 < t.

    The initial condition is

      u(x,0) = 4 - 2 * nu * dphi(x,0)/dx / phi(x,0)

    where

      phi(x,t) = exp ( - ( x-4*t      ) / ( 4*nu*(t+1) ) )
               + exp ( - ( x-4*t-2*pi ) / ( 4*nu*(t+1) ) )

    The boundary conditions are periodic:

      u(0,t) = u(2 Pi,t)

    The viscosity parameter nu may be taken to be 0.01, but other values
    may be chosen.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2015

  Author:

    John Burkardt.

  Parameters:

    Input, double NU, the viscosity.

    Input, int XN, the number of spatial grid points.

    Input, double X[XN], the spatial grid points.

    Input, int TN, the number of time grid points.

    Input, double T[TN], the time grid points.

    Output, double BURGERS_VISCOUS_TIME_EXACT2[XN*TN], the solution 
    of the Burgers equation at each space and time grid point.
*/
{
  double a;
  double b;
  double c;
  double dphi;
  int i;
  int j;
  double phi;
  double r8_pi = 3.141592653589793;
  double *u;

  u = ( double * ) malloc ( xn * tn * sizeof ( double ) );

  for ( j = 0; j < tn; j++ )
  {
    for ( i = 0; i < xn; i++ )
    {
      a = ( x[i] - 4.0 * t[j] );
      b = ( x[i] - 4.0 * t[j] - 2.0 * r8_pi );
      c = 4.0 * nu * ( t[j] + 1.0 );
      phi = exp ( - a * a / c ) + exp ( - b * b / c );
      dphi = - 2.0 * a * exp ( - a * a / c ) / c 
             - 2.0 * b * exp ( - b * b / c ) / c;
      u[i+j*xn] = 4.0 - 2.0 * nu * dphi / phi;
    }
  }

  return u;
}
/******************************************************************************/

void hermite_ek_compute ( int n, double x[], double w[] )

/******************************************************************************/
/*
  Purpose:

    HERMITE_EK_COMPUTE computes a Gauss-Hermite quadrature rule.

  Discussion:

    The code uses an algorithm by Elhay and Kautsky.

    The abscissas are the zeros of the N-th order Hermite polynomial.

    The integral:

      integral ( -oo < x < +oo ) exp ( - x * x ) * f(x) dx

    The quadrature rule:

      sum ( 1 <= i <= n ) w(i) * f ( x(i) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 April 2011

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int N, the number of abscissas.

    Output, double X[N], the abscissas.

    Output, double W[N], the weights.
*/
{
  double arg;
  double *bj;
  int i;
  double zemu;
/*
  Define the zero-th moment.
*/
  arg = 0.5;
  zemu = tgamma ( arg );
/*
  Define the Jacobi matrix.
*/
  bj = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    bj[i] = sqrt ( ( double ) ( i + 1 ) / 2.0 );
  }

  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }

  w[0] = sqrt ( zemu );
  for ( i = 1; i < n; i++ )
  {
    w[i] = 0.0;
  }
/*
  Diagonalize the Jacobi matrix.
*/
  imtqlx ( n, x, bj, w );

  for ( i = 0; i < n; i++ )
  {
    w[i] = w[i] * w[i];
  }

  free ( bj );

  return;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

void imtqlx ( int n, double d[], double e[], double z[] )

/******************************************************************************/
/*
  Purpose:

    IMTQLX diagonalizes a symmetric tridiagonal matrix.

  Discussion:

    This routine is a slightly modified version of the EISPACK routine to 
    perform the implicit QL algorithm on a symmetric tridiagonal matrix. 

    The authors thank the authors of EISPACK for permission to use this
    routine. 

    It has been modified to produce the product Q' * Z, where Z is an input 
    vector and Q is the orthogonal matrix diagonalizing the input matrix.  
    The changes consist (essentially) of applying the orthogonal transformations
    directly to Z as they are generated.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

    Roger Martin, James Wilkinson,
    The Implicit QL Algorithm,
    Numerische Mathematik,
    Volume 12, Number 5, December 1968, pages 377-383.

  Parameters:

    Input, int N, the order of the matrix.

    Input/output, double D(N), the diagonal entries of the matrix.
    On output, the information in D has been overwritten.

    Input/output, double E(N), the subdiagonal entries of the 
    matrix, in entries E(1) through E(N-1).  On output, the information in
    E has been overwritten.

    Input/output, double Z(N).  On input, a vector.  On output,
    the value of Q' * Z, where Q is the matrix that diagonalizes the
    input symmetric tridiagonal matrix.
*/
{
  double b;
  double c;
  double f;
  double g;
  int i;
  int ii;
  int itn = 30;
  int j;
  int k;
  int l;
  int m;
  int mml;
  double p;
  double prec;
  double r;
  double s;

  prec = r8_epsilon ( );

  if ( n == 1 )
  {
    return;
  }

  e[n-1] = 0.0;

  for ( l = 1; l <= n; l++ )
  {
    j = 0;
    for ( ; ; )
    {
      for ( m = l; m <= n; m++ )
      {
        if ( m == n )
        {
          break;
        }

        if ( r8_abs ( e[m-1] ) <= prec * ( r8_abs ( d[m-1] ) + r8_abs ( d[m] ) ) )
        {
          break;
        }
      }
      p = d[l-1];
      if ( m == l )
      {
        break;
      }
      if ( itn <= j )
      {
        printf ( "\n" );
        printf ( "IMTQLX - Fatal error!\n" );
        printf ( "  Iteration limit exceeded\n" );
        exit ( 1 );
      }
      j = j + 1;
      g = ( d[l] - p ) / ( 2.0 * e[l-1] );
      r =  sqrt ( g * g + 1.0 );
      g = d[m-1] - p + e[l-1] / ( g + r8_abs ( r ) * r8_sign ( g ) );
      s = 1.0;
      c = 1.0;
      p = 0.0;
      mml = m - l;

      for ( ii = 1; ii <= mml; ii++ )
      {
        i = m - ii;
        f = s * e[i-1];
        b = c * e[i-1];

        if ( r8_abs ( g ) <= r8_abs ( f ) )
        {
          c = g / f;
          r =  sqrt ( c * c + 1.0 );
          e[i] = f * r;
          s = 1.0 / r;
          c = c * s;
        }
        else
        {
          s = f / g;
          r =  sqrt ( s * s + 1.0 );
          e[i] = g * r;
          c = 1.0 / r;
          s = s * c;
        }
        g = d[i] - p;
        r = ( d[i-1] - g ) * s + 2.0 * c * b;
        p = s * r;
        d[i] = g + p;
        g = c * r - b;
        f = z[i];
        z[i] = s * z[i-1] + c * f;
        z[i-1] = c * z[i-1] - s * f;
      }
      d[l-1] = d[l-1] - p;
      e[l-1] = g;
      e[m-1] = 0.0;
    }
  }
/*
  Sorting.
*/
  for ( ii = 2; ii <= m; ii++ )
  {
    i = ii - 1;
    k = i;
    p = d[i-1];

    for ( j = ii; j <= n; j++ )
    {
      if ( d[j-1] < p )
      {
         k = j;
         p = d[j-1];
      }
    }

    if ( k != i )
    {
      d[k-1] = d[i-1];
      d[i-1] = p;
      p = z[i-1];
      z[i-1] = z[k-1];
      z[k-1] = p;
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

    14 November 2006

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
    value = x;
  } 
  else
  {
    value = - x;
  }
  return value;
}
/******************************************************************************/

double r8_epsilon ( )

/******************************************************************************/
/*
  Purpose:

    R8_EPSILON returns the R8 round off unit.

  Discussion:

    R8_EPSILON is a number R which is a power of 2 with the property that,
    to the precision of the computer's arithmetic,
      1 < 1 + R
    but
      1 = ( 1 + R / 2 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 September 2012

  Author:

    John Burkardt

  Parameters:

    Output, double R8_EPSILON, the R8 round-off unit.
*/
{
  const double value = 2.220446049250313E-016;

  return value;
}
/******************************************************************************/

double r8_sign ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_SIGN returns the sign of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number whose sign is desired.

    Output, double R8_SIGN, the sign of X.
*/
{
  double value;

  if ( x < 0.0 )
  {
    value = - 1.0;
  }
  else
  {
    value = + 1.0;
  }
  return value;
}
/******************************************************************************/

void r8mat_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT prints an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8's, which
    may be stored as a vector in column-major order.

    Entry A(I,J) is stored as A[I+J*M]

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 May 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, double A[M*N], the M by N matrix.

    Input, char *TITLE, a title.
*/
{
  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT_SOME prints some of an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8's, which
    may be stored as a vector in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the matrix.

    Input, int ILO, JLO, IHI, JHI, designate the first row and
    column, and the last row and column to be printed.

    Input, char *TITLE, a title.
*/
{
# define INCX 5

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );

  if ( m <= 0 || n <= 0 )
  {
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  (None)\n" );
    return;
  }
/*
  Print the columns of the matrix, in strips of 5.
*/
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    fprintf ( stdout, "\n" );
/*
  For each column J in the current range...

  Write the header.
*/
    fprintf ( stdout, "  Col:  ");
    for ( j = j2lo; j <= j2hi; j++ )
    {
      fprintf ( stdout, "  %7d     ", j - 1 );
    }
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Row\n" );
    fprintf ( stdout, "\n" );
/*
  Determine the range of the rows in this strip.
*/
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )
    {
/*
  Print out (up to) 5 entries in row I, that lie in the current strip.
*/
      fprintf ( stdout, "%5d:", i - 1 );
      for ( j = j2lo; j <= j2hi; j++ )
      {
        fprintf ( stdout, "  %14f", a[i-1+(j-1)*m] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef INCX
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

double *r8vec_even_new ( int n, double alo, double ahi )

/******************************************************************************/
/*
  Purpose:

    R8VEC_EVEN_NEW returns an R8VEC of values evenly spaced between ALO and AHI.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 February 2004

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of values.

    Input, double ALO, AHI, the low and high values.

    Output, double R8VEC_EVEN_NEW[N], N evenly spaced values.
*/
{
  double *a;
  int i;

  a = ( double * ) malloc ( n * sizeof ( double ) );

  if ( n == 1 )
  {
    a[0] = 0.5 * ( alo + ahi );
  }
  else
  {
    for ( i = 1; i <= n; i++ )
    {
      a[i-1] = ( ( double ) ( n - i     ) * alo
               + ( double ) (     i - 1 ) * ahi )
               / ( double ) ( n     - 1 );
    }
  }

  return a;
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
