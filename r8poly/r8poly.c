# include <complex.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "r8poly.h"

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

void r82poly2_print ( double a, double b, double c, double d, double e,
  double f )

/******************************************************************************/
/*
  Purpose:

    R82POLY2_PRINT prints a second order polynomial in two variables.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, C, D, E, F, the coefficients.
*/
{
  printf ( "  %g * x^2 + %g * y^2 + %g * xy +\n", a, b, c );
  printf ( "  %g * x + %g * y + %g\n", d, e, f );

  return;
}
/******************************************************************************/

int r82poly2_type ( double a, double b, double c, double d, double e, double f )

/******************************************************************************/
/*
  Purpose:

    R82POLY2_TYPE analyzes a second order polynomial in two variables.

  Discussion:

    The polynomial has the form

      A x^2 + B y^2 + C xy + Dx + Ey + F = 0

    The possible types of the solution set are:

     1: a hyperbola;
        9x^2 -  4y^2       -36x - 24y -  36 = 0
     2: a parabola;
        4x^2 +  1y^2 - 4xy + 3x -  4y +   1 = 0;
     3: an ellipse;
        9x^2 + 16y^2       +36x - 32y -  92 = 0;
     4: an imaginary ellipse (no real solutions);
         x^2 +   y^2       - 6x - 10y + 115 = 0;
     5: a pair of intersecting lines;
                        xy + 3x -   y -   3 = 0
     6: one point;
         x^2 +  2y^2       - 2x + 16y +  33 = 0;
     7: a pair of distinct parallel lines;
                 y^2            -  6y +   8 = 0
     8: a pair of imaginary parallel lines (no real solutions);
                 y^2            -  6y +  10 = 0
     9: a pair of coincident lines.
                 y^2            -  2y +   1 = 0
    10: a single line;
                             2x -   y +   1 = 0;
    11; all space;
                                          0 = 0;
    12; no solutions;
                                          1 = 0;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 May 2011

  Author:

    John Burkardt

  Reference:

    Daniel Zwillinger, editor,
    CRC Standard Mathematical Tables and Formulae,
    CRC Press, 30th Edition, 1996, pages 282-284.

  Parameters:

    Input, double A, B, C, D, E, F, the coefficients.

    Output, int TYPE, indicates the type of the solution set.
*/
{
  double delta;
  double j;
  double k;
  int type;
/*
  Handle the degenerate case.
*/
  if ( a == 0.0 && b == 0.0 && c == 0.0 )
  {
    if ( d == 0.0 && e == 0.0 )
    {
      if ( f == 0.0 )
      {
        type = 11;
      }
      else
      {
        type = 12;
      }
    }
    else
    {
      type = 10;
    }
    return type;
  }

  delta =
      8.0 * a * b * f
    + 2.0 * c * e * d
    - 2.0 * a * e * e
    - 2.0 * b * d * d
    - 2.0 * f * c * c;

  j = 4.0 * a * b - c * c;

  if ( delta != 0.0 )
  {
    if ( j < 0.0 )
    {
      type = 1;
    }
    else if ( j == 0.0 )
    {
      type = 2;
    }
    else if ( 0.0 < j )
    {
      if ( r8_sign ( delta ) != r8_sign ( a + b ) )
      {
        type = 3;
      }
      else if ( r8_sign ( delta ) == r8_sign ( a + b ) )
      {
        type = 4;
      }
    }
  }
  else if ( delta == 0.0 )
  {
    if ( j < 0.0 )
    {
      type = 5;
    }
    else if ( 0.0 < j )
    {
      type = 6;
    }
    else if ( j == 0.0 )
    {
      k = 4.0 * ( a + b ) * f - d * d - e * e;

      if ( k < 0.0 )
      {
        type = 7;
      }
      else if ( 0.0 < k )
      {
        type = 8;
      }
      else if ( k == 0.0 )
      {
        type = 9;
      }
    }
  }

  return type;
}
/******************************************************************************/

void r82poly2_type_print ( int type )

/******************************************************************************/
/*
  Purpose:

    R82POLY2_TYPE_PRINT prints the meaning of the output from R82POLY2_TYPE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 May 2011

  Author:

    John Burkardt

  Parameters:

    Input, int TYPE, the type index returned by R82POLY2_TYPE.
*/
{
  if ( type == 1 )
  {
    printf ( "  The set of solutions forms a hyperbola.\n" );
  }
  else if ( type == 2 )
  {
    printf ( "  The set of solutions forms a parabola.\n" );
  }
  else if ( type == 3 )
  {
    printf ( "  The set of solutions forms an ellipse.\n" );
  }
  else if ( type == 4 )
  {
    printf ( "  The set of solutions forms an imaginary ellipse.\n" );
    printf ( "  (There are no real solutions).\n" );
  }
  else if ( type == 5 )
  {
    printf ( "  The set of solutions forms a pair of intersecting lines.\n" );
  }
  else if ( type == 6 )
  {
    printf ( "  The set of solutions is a single point.\n" );
  }
  else if ( type == 7 )
  {
    printf ( "  The set of solutions form a pair of distinct parallel lines.\n" );
  }
  else if ( type == 8 )
  {
    printf ( "  The set of solutions forms a pair of imaginary parallel lines.\n" );
    printf ( "  (There are no real solutions).\n" );
  }
  else if ( type == 9 )
  {
    printf ( "  The set of solutions forms a pair of coincident lines.\n" );
  }
  else if ( type == 10 )
  {
    printf ( "  The set of solutions forms a single line.\n" );
  }
  else if ( type == 11 )
  {
    printf ( "  The set of solutions is all space.\n" );
  }
  else if ( type == 12 )
  {
    printf ( "  The set of solutions is empty.\n" );
  }
  else
  {
    printf ( "  This type index is unknown.\n" );
  }
  return;
}
/******************************************************************************/

double r8mat_det_3d ( double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DET_3D computes the determinant of a 3 by 3 R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    The determinant of a 3 by 3 matrix is

        a11 * a22 * a33 - a11 * a23 * a32
      + a12 * a23 * a31 - a12 * a21 * a33
      + a13 * a21 * a32 - a13 * a22 * a31

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, double A[3*3], the matrix whose determinant is desired.

    Output, double R8MAT_DET_3D, the determinant of the matrix.
*/
{
  double det;

  det =
      a[0+0*3] * ( a[1+1*3] * a[2+2*3] - a[1+2*3] * a[2+1*3] )
    + a[0+1*3] * ( a[1+2*3] * a[2+0*3] - a[1+0*3] * a[2+2*3] )
    + a[0+2*3] * ( a[1+0*3] * a[2+1*3] - a[1+1*3] * a[2+0*3] );

  return det;
}
/******************************************************************************/

double *r8mat_inverse_3d ( double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_INVERSE_3D inverts a 3 by 3 R8MAT using Cramer's rule.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    If the determinant is zero, A is singular, and does not have an
    inverse.  In that case, the output is set to NULL.

    If the determinant is nonzero, its value is an estimate
    of how nonsingular the matrix A is.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, double A[3*3], the matrix to be inverted.

    Output, double R8MAT3_INVERSE[3*3], the inverse of the matrix A.
*/
{
  double *b;
  double det;
/*
  Compute the determinant of A.
*/
  det =
     a[0+0*3] * ( a[1+1*3] * a[2+2*3] - a[1+2*3] * a[2+1*3] )
   + a[0+1*3] * ( a[1+2*3] * a[2+0*3] - a[1+0*3] * a[2+2*3] )
   + a[0+2*3] * ( a[1+0*3] * a[2+1*3] - a[1+1*3] * a[2+0*3] );

  if ( det == 0.0 )
  {
    return NULL;
  }

  b = ( double * ) malloc ( 3 * 3 * sizeof ( double ) );

  b[0+0*3] =   ( a[1+1*3] * a[2+2*3] - a[1+2*3] * a[2+1*3] ) / det;
  b[0+1*3] = - ( a[0+1*3] * a[2+2*3] - a[0+2*3] * a[2+1*3] ) / det;
  b[0+2*3] =   ( a[0+1*3] * a[1+2*3] - a[0+2*3] * a[1+1*3] ) / det;

  b[1+0*3] = - ( a[1+0*3] * a[2+2*3] - a[1+2*3] * a[2+0*3] ) / det;
  b[1+1*3] =   ( a[0+0*3] * a[2+2*3] - a[0+2*3] * a[2+0*3] ) / det;
  b[1+2*3] = - ( a[0+0*3] * a[1+2*3] - a[0+2*3] * a[1+0*3] ) / det;

  b[2+0*3] =   ( a[1+0*3] * a[2+1*3] - a[1+1*3] * a[2+0*3] ) / det;
  b[2+1*3] = - ( a[0+0*3] * a[2+1*3] - a[0+1*3] * a[2+0*3] ) / det;
  b[2+2*3] =   ( a[0+0*3] * a[1+1*3] - a[0+1*3] * a[1+0*3] ) / det;

  return b;
}
/******************************************************************************/

void r8mat_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT prints an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

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

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2013

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
    if ( n < j2hi )
    {
      j2hi = n;
    }
    if ( jhi < j2hi )
    {
      j2hi = jhi;
    }

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
    if ( 1 < ilo )
    {
      i2lo = ilo;
    }
    else
    {
      i2lo = 1;
    }
    if ( m < ihi )
    {
      i2hi = m;
    }
    else
    {
      i2hi = ihi;
    }

    for ( i = i2lo; i <= i2hi; i++ )
    {
/*
  Print out (up to) 5 entries in row I, that lie in the current strip.
*/
      fprintf ( stdout, "%5d:", i - 1 );
      for ( j = j2lo; j <= j2hi; j++ )
      {
        fprintf ( stdout, "  %14g", a[i-1+(j-1)*m] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef INCX
}
/******************************************************************************/

double *r8poly_add ( int na, double a[], int nb, double b[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_ADD adds two R8POLY's.

  Discussion:

    The polynomials are in power sum form.

    The power sum form is:

      p(x) = a(0) + a(1)*x + ... + a(n-1)*x^(n-1) + a(n)*x^(n)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 November 2013

  Author:

    John Burkardt

  Parameters:

    Input, int NA, the degree of polynomial A.

    Input, double A[NA+1], the coefficients of the first
    polynomial factor.

    Input, int NB, the degree of polynomial B.

    Input, double B[NB+1], the coefficients of the
    second polynomial factor.

    Output, double C[max(NA,NB)+1], the coefficients of A + B.
*/
{
  int i;
  double *c;

  c = ( double * ) malloc ( ( i4_max ( na, nb ) + 1 ) * sizeof ( double ) );

  if ( nb == na )
  {
    for ( i = 0; i <= na; i++ )
    {
      c[i] = a[i] + b[i];
    }
  }
  else if ( nb < na )
  {
    for ( i = 0; i <= nb; i++ )
    {
      c[i] = a[i] + b[i];
    }
    for ( i = nb + 1; i <= na; i++ )
    {
      c[i] = a[i];
    }
  }
  else if ( na < nb )
  {
    for ( i = 0; i <= na; i++ )
    {
      c[i] = a[i] + b[i];
    }
    for ( i = na + 1; i <= nb; i++ )
    {
      c[i] = b[i];
    }
  }

  return c;
}
/******************************************************************************/

double *r8poly_ant_coef ( int n, double poly_cof[] )

/******************************************************************************/
/*
  Purpose:

    r8poly_ant_coef integrates a polynomial in standard form.

  Discussion:

    The antiderivative of a polynomial P(X) is any polynomial Q(X)
    with the property that d/dX Q(X) = P(X).

    This routine chooses the antiderivative whose constant term is zero.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 October 2019

  Author:

    John Burkardt

  Input:

    int N, the order of the polynomial.

    double POLY_COF[0:N], the polynomial coefficients.
    POLY_COF[0] is the constant term, and POLY_COF[N] is the
    coefficient of X^(N).

  Output:

    double POLY_COF2[0:N+1], the coefficients of
    the antiderivative polynomial, in standard form.  The constant
    term is set to zero.
*/
{
  int i;
  double *poly_cof2;

  poly_cof2 = ( double * ) malloc ( ( n + 2 ) * sizeof ( double ) );
/*
  Set the constant term.
*/
  poly_cof2[0] = 0.0;
/*
  Integrate the polynomial.
*/
  for ( i = 1; i < n + 2; i++ )
  {
    poly_cof2[i] = poly_cof[i-1] / ( double ) ( i );
  }

  return poly_cof2;
}
/******************************************************************************/

double r8poly_ant_value ( int n, double poly_cof[], double xval )

/******************************************************************************/
/*
  Purpose:

    r8poly_ant_value evaluates the antiderivative of a polynomial.

  Discussion:

    The constant term of the antiderivative is taken to be zero.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 October 2019

  Author:

    John Burkardt

  Input:

    int N, the order of the polynomial.

    double POLY_COF[0:N], the polynomial coefficients.
    POLY_COF[0] is the constant term, and POLY_COF[N] is the coefficient of
    X^(N).

    real XVAL, the evaluation point.

  Output:

    real r8poly_ant_value, the value of the antiderivative at XVAL.
*/
{
  int i;
  double yval;

  yval = 0.0;
  for ( i = n; 0 <= i; i-- )
  {
    yval = ( yval + poly_cof[i] / ( double ) ( i + 1 ) ) * xval;
  }

  return yval;
}
/******************************************************************************/

int r8poly_degree ( int na, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_DEGREE returns the degree of a polynomial.

  Discussion:

    The degree of a polynomial is the index of the highest power
    of X with a nonzero coefficient.

    The degree of a constant polynomial is 0.  The degree of the
    zero polynomial is debatable, but this routine returns the
    degree as 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, int NA, the dimension of A.

    Input, double A[NA+1], the coefficients of the polynomials.

    Output, int R8POLY_DEGREE, the degree of A.
*/
{
  int degree;

  degree = na;

  while ( 0 < degree )
  {
    if ( a[degree] != 0.0 )
    {
      return degree;
    }
    degree = degree - 1;
  }

  return degree;
}
/******************************************************************************/

double *r8poly_deriv ( int n, double c[], int p )

/******************************************************************************/
/*
  Purpose:

    R8POLY_DERIV returns the derivative of a polynomial.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the degree of the polynomial.

    Input, double C[N+1], the polynomial coefficients.
    C[I] is the coefficient of X^I.

    Input, int P, the order of the derivative.
    0 means no derivative is taken.
    1 means first derivative,
    2 means second derivative and so on.
    Values of P less than 0 are meaningless.  Values of P greater
    than N are meaningful, but the code will behave as though the
    value of P was N+1.

    Output, double R8POLY_DERIV CP[N-P+1], the polynomial coefficients of
    the derivative.
*/
{
  double *cp;
  double *cp_temp;
  int d;
  int i;

  if ( n < p )
  {
    return NULL;
  }
  cp_temp = r8vec_copy_new ( n + 1, c );

  for ( d = 1; d <= p; d++ )
  {
    for ( i = 0; i <= n-d; i++ )
    {
      cp_temp[i] = ( double ) ( i + 1 ) * cp_temp[i+1];
    }
    cp_temp[n-d+1] = 0.0;
  }

  cp = r8vec_copy_new ( n - p + 1, cp_temp );

  free ( cp_temp );

  return cp;
}
/******************************************************************************/

void r8poly_division ( int na, double a[], int nb, double b[], int *nq, 
  double q[], int *nr, double r[] )

/******************************************************************************/
/*
  Purpose:

    r8poly_division computes the quotient and remainder of two R8POLY's.

  Discussion:

    The polynomials are assumed to be stored in power sum form.

    The power sum form is:

      p(x) = a(0) + a(1)*x + ... + a(n-1)*x^(n-1) + a(n)*x^(n)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 October 2019

  Author:

    John Burkardt

  Input:

    int NA, the dimension of A.

    double A[NA+1], the coefficients of the polynomial to be divided.

    int NB, the dimension of B.

    double B[NB+1], the coefficients of the divisor polynomial.

  Output:

    int *NQ, the degree of Q.
    If the divisor polynomial is zero, NQ is returned as -1.

    double Q[NA+1-NB], contains the quotient of A/B.
    If A and B have full degree, Q should be dimensioned Q(0:NA-NB).
    In any case, Q(0:NA) should be enough.

    int *NR, the degree of R.
    If the divisor polynomial is zero, NR is returned as -1.

    double R[NB], contains the remainder of A/B.
    If B has full degree, R should be dimensioned R(0:NB-1).
    Otherwise, R will actually require less space.
*/
{
  double *a2;
  int i;
  int j;
  int na2;
  int nb2;

  na2 = r8poly_degree ( na, a );
  nb2 = r8poly_degree ( nb, b );

  if ( b[nb2] == 0.0 )
  {
    *nq = -1;
    *nr = -1;
    return;
  }

  a2 = ( double * ) malloc ( ( na + 1 ) * sizeof ( double ) );

  for ( i = 0; i <= na; i++ )
  {
    a2[i] = a[i];
  }

  *nq = na2 - nb2;
  *nr = nb2 - 1;

  for ( i = *nq; 0 <= i; i-- )
  {
    q[i] = a2[i+nb2] / b[nb2];
    a2[i+nb2] = 0.0;
    for ( j = 0; j <= nb2-1; j++ )
    {
      a2[i+j] = a2[i+j] - q[i] * b[j];
    }
  }

  for ( i = 0; i <= *nr; i++ )
  {
    r[i] = a2[i];
  }

  free ( a2 );

  return;
}
/******************************************************************************/

double r8poly_lagrange_0 ( int npol, double xpol[], double xval )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_0 evaluates the Lagrange factor at a point.

  Discussion:

    W(X) = Product ( 1 <= I <= NPOL ) ( X - XPOL(I) )

  Discussion:

    For a set of points XPOL(I), 1 <= I <= NPOL, the IPOL-th Lagrange basis
    polynomial L(IPOL)(X), has the property:

      L(IPOL)( XPOL(J) ) = delta ( IPOL, J )

    and may be expressed as:

      L(IPOL)(X) = W(X) / ( ( X - XPOL(IPOL) ) * W'(XPOL(IPOL)) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int NPOL, the number of abscissas.
    NPOL must be at least 1.

    Input, double XPOL[NPOL], the abscissas, which should be distinct.

    Input, double XVAL, the point at which the Lagrange factor is to be
    evaluated.

    Output, double R8POLY_LAGRANGE_0, the value of the Lagrange factor at XVAL.
*/
{
  int i;
  double wval;

  wval = 1.0;
  for ( i = 0; i < npol; i++ )
  {
    wval = wval * ( xval - xpol[i] );
  }

  return wval;
}
/******************************************************************************/

double r8poly_lagrange_1 ( int npol, double xpol[], double xval )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_1 evaluates the first derivative of the Lagrange factor.

  Discussion:

    W(XPOL(1:NPOL))(X) = Product ( 1 <= I <= NPOL ) ( X - XPOL(I) )

    W'(XPOL(1:NPOL))(X)
      = Sum ( 1 <= J <= NPOL ) Product ( I /= J ) ( X - XPOL(I) )

    We also have the recursion:

      W'(XPOL(1:NPOL))(X) = d/dX ( ( X - XPOL(NPOL) ) * W(XPOL(1:NPOL-1))(X) )
                    = W(XPOL(1:NPOL-1))(X)
                    + ( X - XPOL(NPOL) ) * W'(XPOL(1:NPOL-1))(X)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int NPOL, the number of abscissas.

    Input, double XPOL[NPOL], the abscissas, which should be distinct.

    Input, double XVAL, the point at which the Lagrange factor is to be
    evaluated.

    Output, double R8POLY_LAGRANGE_1, the derivative of W with respect to XVAL.
*/
{
  double dwdx;
  int i;
  double w;

  dwdx = 0.0;
  w = 1.0;

  for ( i = 0; i < npol; i++ )
  {
    dwdx = w + ( xval - xpol[i] ) * dwdx;
    w = w * ( xval - xpol[i] );
  }

  return dwdx;
}
/******************************************************************************/

double r8poly_lagrange_2 ( int npol, double xpol[], double xval )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_2 evaluates the second derivative of the Lagrange factor.

  Discussion:

    W(X)  = Product ( 1 <= I <= NPOL ) ( X - XPOL(I) )

    W'(X) = Sum ( 1 <= J <= NPOL )
            Product ( I /= J ) ( X - XPOL(I) )

    W"(X) = Sum ( 1 <= K <= NPOL )
            Sum ( J =/ K )
            Product ( I /= K, J ) ( X - XPOL(I) )

    For a set of points XPOL(I), 1 <= I <= NPOL, the IPOL-th Lagrange basis
    polynomial L(IPOL)(X), has the property:

      L(IPOL)( XPOL(J) ) = delta ( IPOL, J )

    and may be expressed as:

      L(IPOL)(X) = W(X) / ( ( X - XPOL(IPOL) ) * W'(XPOL(IPOL)) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 January 2004

  Author:

    John Burkardt

  Parameters:

    Input, int NPOL, the number of abscissas.
    NPOL must be at least 1.

    Input, double XPOL[NPOL], the abscissas, which should be distinct.

    Input, double XVAL, the point at which the Lagrange factor is to be
    evaluated.

    Output, double R8POLY_LAGRANGE_2, the second derivative of W with 
    respect to XVAL.
*/
{
  double dw2dx2;
  int i;
  int j;
  int k;
  double term;

  dw2dx2 = 0.0;

  for ( k = 0; k < npol; k++ )
  {
    for ( j = 0; j < npol; j++ )
    {
      if ( j != k )
      {
        term = 1.0;
        for ( i = 0; i < npol; i++ )
        {
          if ( i != j && i != k )
          {
            term = term * ( xval - xpol[i] );
          }
        }
        dw2dx2 = dw2dx2 + term;
      }
    }
  }

  return dw2dx2;
}
/******************************************************************************/

double *r8poly_lagrange_coef ( int npol, int ipol, double xpol[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_COEF returns the coefficients of a Lagrange polynomial.

  Discussion:

    Given NPOL distinct abscissas, XPOL(*), the IPOL-th Lagrange
    polynomial P(IPOL)(X) is defined as the polynomial of degree
    NPOL - 1 which is 1 at XPOL(IPOL) and 0 at the NPOL - 1 other
    abscissas.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int NPOL, the number of abscissas.
    NPOL must be at least 1.

    Input, int IPOL, the index of the polynomial to evaluate.
    IPOL must be between 1 and NPOL.

    Input, double XPOL[NPOL], the abscissas of the Lagrange polynomials.
    The entries in XPOL must be distinct.

    Output, double R8POLY_LAGRANGE_COEF[NPOL], the polynomial coefficients
    of the IPOL-th Lagrange polynomial.
*/
{
  int i;
  int index;
  int j;
  double *pcof;
/*
  Make sure IPOL is legal.
*/
  if ( ipol < 1 || npol < ipol )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8POLY_LAGRANGE_COEF - Fatal error!\n" );
    fprintf ( stderr, "  1 <= IPOL <= NPOL is required.\n" );
    fprintf ( stderr, "  but IPOL = %d\n", ipol );
    fprintf ( stderr, "  and NPOL = %d\n", npol );
    exit ( 1 );
  }
/*
  Check that the abscissas are distinct.
*/
  if ( ! r8vec_is_distinct ( npol, xpol ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8POLY_LAGRANGE_COEF - Fatal error!\n" );
    fprintf ( stderr, "  Two entries of XPOL are equal:\n" );
    exit ( 1 );
  }

  pcof = ( double * ) malloc ( npol * sizeof ( double ) );

  pcof[0] = 1.0;
  for ( i = 1; i < npol; i++ )
  {
    pcof[i] = 0.0;
  }

  index = 0;

  for ( i = 1; i <= npol; i++ )
  {
    if ( i != ipol )
    {
      index = index + 1;

      for ( j = index; 0 <= j; j-- )
      {
        pcof[j] = - xpol[i-1] * pcof[j] / ( xpol[ipol-1] - xpol[i-1] );

        if ( 0 < j )
        {
          pcof[j] = pcof[j] + pcof[j-1] / ( xpol[ipol-1] - xpol[i-1] );
        }
      }
    }
  }

  return pcof;
}
/******************************************************************************/

void r8poly_lagrange_factor ( int npol, double xpol[], double xval,
  double *wval, double *dwdx )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_FACTOR evaluates the polynomial Lagrange factor at a point.

  Discussion:

    Suppose F(X) is at least N times continuously differentiable in the
    interval [A,B].  Pick NPOL distinct points XPOL(I) in [A,B] and compute
    the interpolating polynomial P(X) of order NPOL ( and degree NPOL-1)
    which passes through all the points ( XPOL(I), F(XPOL(I)) ).
    Then in the interval [A,B], the maximum error

      abs ( F(X) - P(X) )

    is bounded by:

      C * FNMAX * W(X)

    where

      C is a constant,
      FNMAX is the maximum value of the NPOL-th derivative of F in [A,B],
      W(X) is the Lagrange factor.

    Thus, the value of W(X) is useful as part of an estimated bound
    for the interpolation error.

    The formula is:

      W(X) = Product ( 1 <= I <= NPOL ) ( X - XPOL(I) )

    Note that the Chebyshev abscissas have the property that they minimize
    the value of W(X) over the interval [A,B].  Hence, if the abscissas may
    be chosen arbitrarily, the Chebyshev abscissas have this advantage over
    other choices.

    For a set of points XPOL[I], 0 <= I <= NPOL-1, the IPOL-th Lagrange basis
    polynomial L(IPOL)(X), has the property:

      L(IPOL)( XPOL(J) ) = delta ( IPOL, J )

    and may be expressed as:

      L(IPOL)(X) = W(X) / ( ( X - XPOL[IPOL] ) * W'(XPOL[IPOL]) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int NPOL, the number of abscissas.
    NPOL must be at least 1.

    Input, double XPOL[NPOL], the abscissas, which should be distinct.

    Input, double XVAL, the point at which the Lagrange factor is to be
    evaluated.

    Output, double *WVAL, the value of the Lagrange factor at XVAL.

    Output, double *DWDX, the derivative of W with respect to XVAL.
*/
{
  int i;
  int j;
  double term;

  *wval = 1.0;
  for ( i = 0; i < npol; i++ )
  {
    *wval = *wval * ( xval - xpol[i] );
  }

  *dwdx = 0.0;

  for ( i = 0; i < npol; i++ )
  {
    term = 1.0;

    for ( j = 0; j < npol; j++ )
    {
      if ( i != j )
      {
        term = term * ( xval - xpol[j] );
      }
    }
    *dwdx = *dwdx + term;
  }

  return;
}
/******************************************************************************/

int r8poly_lagrange_value ( int npol, int ipol, double xpol[], double xval,
  double *pval, double *dpdx )

/******************************************************************************/
/*
  Purpose:

    r8poly_lagrange_value evaluates the IPOL-th Lagrange polynomial.

  Discussion:

    Given NPOL distinct abscissas, XPOL[*], the IPOL-th Lagrange
    polynomial P(IPOL)(X) is defined as the polynomial of degree
    NPOL - 1 which is 1 at XPOL[IPOL] and 0 at the NPOL - 1 other
    abscissas.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int NPOL, the number of abscissas.
    NPOL must be at least 1.

    Input, int IPOL, the index of the polynomial to evaluate.
    IPOL must be between 0 and NPOL-1.

    Input, double XPOL[NPOL], the abscissas of the Lagrange polynomials.
    The entries in XPOL must be distinct.

    Input, double XVAL, the point at which the IPOL-th Lagrange polynomial
    is to be evaluated.

    Output, double *PVAL, the value of the IPOL-th Lagrange polynomial at XVAL.

    Output, double *DPDX, the derivative of the IPOL-th Lagrange polynomial 
    at XVAL.

    Output, int r8poly_lagrange_value, 0 if no error.
*/
{
  int i;
  int j;
  double p2;
/*
  Make sure IPOL is legal.
*/
  if ( ipol < 0 || npol-1 < ipol )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "r8poly_lagrange_value - Fatal error!\n" );
    fprintf ( stderr, "  0 <= IPOL <= NPOL-1 is required.\n" );
    exit ( 1 );
  }
/*
  Check that the abscissas are distinct.
*/
  for ( i = 1; i < npol; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      if ( xpol[i] == xpol[j] )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "r8poly_lagrange_value - Fatal error!\n" );
        fprintf ( stderr, "  Two entries of XPOL are equal:\n" );
        fprintf ( stderr, "  XPOL(%d) = %g.\n", i, xpol[i] );
        fprintf ( stderr, "  XPOL(%d) = %g.\n", j, xpol[j] );
        exit ( 1 );
      }
    }
  }
/*
  Evaluate the polynomial.
*/
  *pval = 1.0;

  for ( i = 0; i < npol; i++ )
  {
    if ( i != ipol )
    {
      *pval = *pval * ( xval - xpol[i] ) / ( xpol[ipol] - xpol[i] );
    }
  }
/*
  Evaluate the derivative, which can be found by summing up the result
  of differentiating one factor at a time, successively.
*/
  *dpdx = 0.0;

  for ( i = 0; i < npol; i++ )
  {
    if ( i != ipol )
    {
      p2 = 1.0;

      for ( j = 0; j < npol; j++ )
      {
        if ( j == i )
        {
          p2 = p2                      / ( xpol[ipol] - xpol[j] );
        }
        else if ( j != ipol )
        {
          p2 = p2 * ( xval - xpol[j] ) / ( xpol[ipol] - xpol[j] );
        }
      }
      *dpdx = *dpdx + p2;
    }
  }

  return 0;
}
/******************************************************************************/

void r8poly_multiply ( int na, double a[], int nb, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    r8poly_multiply computes the product of two polynomials.

  Discussion:

    The polynomials are in power sum form.

    The power sum form is:

      p(x) = a(0) + a(1)*x + ... + a(n-1)*x^(n-1) + a(n)*x^(n)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int NA, the dimension of A.

    Input, double A[NA+1], the coefficients of the first polynomial factor.

    Input, int NB, the dimension of B.

    Input, double B[NB+1], the coefficients of the second polynomial factor.

    Output, double C[NA+NB+1], the coefficients of A * B.
*/
{
  double *d;
  int i;
  int j;

  d = ( double * ) malloc ( ( na + nb + 1 ) * sizeof ( double ) );

  for ( i = 0; i <= na + nb; i++ )
  {
    d[i] = 0.0;
  }

  for ( i = 0; i <= na; i++ )
  {
    for ( j = 0; j <= nb; j++ )
    {
      d[i+j] = d[i+j] + a[i] * b[j];
    }
  }

  for ( i = 0; i <= na + nb; i++ )
  {
    c[i] = d[i];
  }

  free ( d );

  return;
}
/******************************************************************************/

void r8poly_power ( int na, double a[], int p, double b[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_POWER computes a positive integer power of a polynomial.

  Discussion:

    The power sum form is:

      p(x) = a(0) + a(1)*x + ... + a(n-1)*x^(n-1) + a(n)*x^(n)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2015

  Author:

    John Burkardt

  Parameters:

    Input, int NA, the dimension of A.

    Input, double A[NA+1], the polynomial to be raised to the power.

    Input, int P, the nonnegative power to which A is raised.

    Output, double B[P*NA+1], the power of the polynomial.
*/
{
  int i;
  int j;
  int nonzer;
/*
  Zero out B.
*/
  for ( i = 0; i <= p * na; i++ )
  {
    b[i] = 0.0;
  }
/*
  Search for the first nonzero element in A.
*/
  nonzer = -1;

  for ( i = 0; i <= na; i++ )
  {
    if ( a[i] != 0.0 )
    {
      nonzer = i;
      break;
    }
  }

  if ( nonzer == -1 )
  {
    return;
  }

  b[0] = pow ( a[nonzer], p );

  for ( i = 1; i <= p * ( na - nonzer ); i++ )
  {
    if ( i + nonzer <= na )
    {
      b[i] = ( double ) ( i * p ) * b[0] * a[i+nonzer];
    }
    else
    {
      b[i] = 0.0;
    }

    for ( j = 1; j <= i-1; j++ )
    {
      if ( j+nonzer <= na )
      {
        b[i] = b[i] - ( double ) ( i - j ) * a[j+nonzer] * b[i-j];
      }

      if ( i-j+nonzer <= na )
      {
        b[i] = b[i] + ( double ) ( i - j ) * ( double ) p * b[j] * a[i-j+nonzer];
      }
    }

    b[i] = b[i] / ( ( double ) i  * a[nonzer] );
  }
/*
  Shift B up.
*/
  for ( i = p*nonzer; i <= p*na; i++ )
  {
    b[i] = b[i-p*nonzer];
  }

  for ( i = 0; i <= p * nonzer-1; i++ )
  {
    b[i] = 0.0;
  }

  return;
}
/******************************************************************************/

void r8poly_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8POLY_PRINT prints out a polynomial.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 July 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the dimension of A.

    Input, double A[N+1], the polynomial coefficients.
    A(0) is the constant term and
    A(N) is the coefficient of X**N.

    Input, char *TITLE, a title.
*/
{
  int i;
  double mag;
  char plus_minus;

  if ( 0 < s_len_trim ( title ) )
  {
    printf ( "\n" );
    printf ( "%s\n", title );
  }
  printf ( "\n" );

  if ( n < 0 )
  {
    printf ( "  p(x) = 0\n" );
    return;
  }

  if ( a[n] < 0.0 )
  {
    plus_minus = '-';
  }
  else
  {
    plus_minus = ' ';
  }

  mag = fabs ( a[n] );

  if ( 2 <= n )
  {
    printf ( "  p(x) = %c%g * x^%d\n", plus_minus, mag, n );
  }
  else if ( n == 1 )
  {
    printf ( "  p(x) = %c%g * x\n", plus_minus, mag );
  }
  else if ( n == 0 )
  {
    printf ( "  p(x) = %c%g\n", plus_minus, mag );
  }

  for ( i = n - 1; 0 <= i; i-- )
  {
    if ( a[i] < 0.0 )
    {
      plus_minus = '-';
    }
    else
    {
      plus_minus = '+';
    }

    mag = fabs ( a[i] );

    if ( mag != 0.0 )
    {
      if ( 2 <= i )
      {
        printf ( "         %c%g * x^%d\n", plus_minus, mag, i );
      }
      else if ( i == 1 )
      {
        printf ( "         %c%g * x\n", plus_minus, mag );
      }
      else if ( i == 0 )
      {
        printf ( "         %c%g\n", plus_minus, mag );
      }
    }
  }
  return;
}
/******************************************************************************/

void r8poly_shift ( double scale, double shift, int n, double poly_cof[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_SHIFT adjusts the coefficients of a polynomial for a new argument.

  Discussion:

    Assuming P(X) is a polynomial in the argument X, of the form:

      P(X) =
          C(N) * X^N
        + ...
        + C(1) * X
        + C(0),

    and that Z is related to X by the formula:

      Z = SCALE * X + SHIFT

    then this routine computes coefficients C for the polynomial Q(Z):

      Q(Z) =
          C(N) * Z^N
        + ...
        + C(1) * Z
        + C(0)

    so that:

      Q(Z(X)) = P(X)

  Example:

    P(X) = 2 * X^2 - X + 6

    Z = 2.0 * X + 3.0

    Q(Z) = 0.5 *         Z^2 -  3.5 * Z + 12

    Q(Z(X)) = 0.5 * ( 4.0 * X^2 + 12.0 * X +  9 )
            - 3.5 * (              2.0 * X +  3 )
                                           + 12

            = 2.0         * X^2 -  1.0 * X +  6

            = P(X)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 August 2011

  Reference:

    Press, Flannery, Teukolsky, Vetterling,
    Numerical Recipes: The Art of Scientific Computing,
    Cambridge University Press.

  Parameters:

    Input, double SHIFT, SCALE, the shift and scale applied to X,
    so that Z = SCALE * X + SHIFT.

    Input, int N, the number of coefficients.

    Input/output, double POLY_COF[N+1].
    On input, the coefficient array in terms of the X variable.
    On output, the coefficient array in terms of the Z variable.
*/
{
  int i;
  int j;

  for ( i = 1; i <= n; i++ )
  {
    for ( j = i; j <= n; j++ )
    {
      poly_cof[j] = poly_cof[j] / scale;
    }
  }

  for ( i = 0; i <= n - 1; i++ )
  {
    for ( j = n - 1; i <= j; j-- )
    {
      poly_cof[j] = poly_cof[j] - shift * poly_cof[j+1];
    }
  }

  return;
}
/******************************************************************************/

double r8poly_value ( int m, double c[], double x )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE evaluates a polynomial using a naive method.

  Discussion:

    The polynomial 

      p(x) = c0 + c1 * x + c2 * x^2 + ... + cm * x^m

    is to be evaluated at the value X.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 August 2017

  Author:

    John Burkardt

  Parameters:

    Input, int M, the degree of the polynomial.

    Input, double C[M+1], the coefficients of the polynomial.
    C[0] is the constant term.

    Input, double X, the point at which the polynomial is to be evaluated.

    Output, double R8POLY_VALUE, the value of the polynomial at X.
*/
{
  int i;
  double value;
  double xi;

  value = c[0];
  xi = 1.0;

  for ( i = 1; i <= m; i++ )
  {
    xi = xi * x;
    value = value + c[i] * xi;
  }

  return value;
}
/******************************************************************************/

double r8poly_value_horner ( int m, double c[], double x )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE_HORNER evaluates a polynomial using Horner's method.

  Discussion:

    The polynomial 

      p(x) = c0 + c1 * x + c2 * x^2 + ... + cm * x^m

    is to be evaluated at the value X.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, the degree of the polynomial.

    Input, double C[M+1], the coefficients of the polynomial.
    C[0] is the constant term.

    Input, double X, the point at which the polynomial is to be evaluated.

    Output, double R8POLY_VALUE_HORNER, the value of the polynomial at X.
*/
{
  int i;
  double value;

  value = c[m];

  for ( i = m - 1; 0 <= i; i-- )
  {
    value = value * x + c[i];
  }

  return value;
}
/******************************************************************************/

double *r8poly_values_horner ( int m, double c[], int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUES_HORNER evaluates a polynomial using Horner's method.

  Discussion:

    The polynomial 

      p(x) = c0 + c1 * x + c2 * x^2 + ... + cm * x^m

    is to be evaluated at the vector of values X.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 December 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the degree.

    Input, double C[M+1], the polynomial coefficients.  
    C[I] is the coefficient of X^I.

    Input, int N, the number of evaluation points.

    Input, double X[N], the evaluation points.

    Output, double R8POLY_VALUES_HORNER[N], the polynomial values.
*/
{
  int i;
  int j;
  double *p;

  p = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    p[j] = c[m];
  }

  for ( i = m - 1; 0 <= i; i-- )
  {
    for ( j = 0; j < n; j++ )
    {
      p[j] = p[j] * x[j] + c[i];
    }
  }
  return p;
}
/******************************************************************************/

double *r8poly_value_2d ( int m, double c[], int n, double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE_2D evaluates a polynomial in 2 variables, X and Y.

  Discussion:

    We assume the polynomial is of total degree M, and has the form:

      p(x,y) = c00 
             + c10 * x                + c01 * y
             + c20 * x^2   + c11 * xy + c02 * y^2
             + ...
             + cm0 * x^(m) + ...      + c0m * y^m.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 September 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the degree of the polynomial.

    Input, double C[T(M+1)], the polynomial coefficients.  
    C[0] is the constant term.  T(M+1) is the M+1-th triangular number.
    The coefficients are stored consistent with the following ordering
    of monomials: 1, X, Y, X^2, XY, Y^2, X^3, X^2Y, XY^2, Y^3, X^4, ...

    Input, int N, the number of evaluation points.

    Input, double X[N], Y[N], the evaluation points.

    Output, double R8POLY_VALUE_2D[N], the value of the polynomial at the 
    evaluation points.
*/
{
  int ex;
  int ey;
  int i;
  int j;
  double *p;
  int s;

  p = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    p[i] = 0.0;
  }

  j = 0;
  for ( s = 0; s <= m; s++ )
  {
    for ( ex = s; 0 <= ex; ex-- )
    {
      ey = s - ex;
      for ( i = 0; i < n; i++ )
      {
        p[i] = p[i] + c[j] * pow ( x[i], ex ) * pow ( y[i], ey );
      }
      j = j + 1;
    }
  }
  return p;
}
/******************************************************************************/

int r8poly2_ex ( double x1, double y1, double x2, double y2, double x3,
  double y3, double *x, double *y )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_EX finds the extremal point of a parabola determined by three points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, double X1, Y1, X2, Y2, X3, Y3, the coordinates of three points
    on the parabola.  X1, X2 and X3 must be distinct.

    Output, double *X, *Y, the X coordinate of the extremal point of the
    parabola, and the value of the parabola at that point.

    Output, int R8POLY2_EX, error flag.
    0, no error.
    1, two of the X values are equal.
    2, the data lies on a straight line; there is no finite extremal
    point.
    3, the data lies on a horizontal line; every point is "extremal".
*/
{
  double bot;

  *x = 0.0;
  *y = 0.0;

  if ( x1 == x2 || x2 == x3 || x3 == x1 )
  {
    return 1;
  }

  if ( y1 == y2 && y2 == y3 && y3 == y1 )
  {
    *x = x1;
    *y = y1;
    return 3;
  }

  bot = ( x2 - x3 ) * y1 + ( x3 - x1 ) * y2 + ( x1 - x2 ) * y3;

  if ( bot == 0.0 )
  {
    return 2;
  }

  *x = 0.5 * (
      x1 * x1 * ( y3 - y2 )
    + x2 * x2 * ( y1 - y3 )
    + x3 * x3 * ( y2 - y1 ) ) /
    ( ( x2 - x3 ) * y1 + ( x3 - x1 ) * y2 + ( x1 - x2 ) * y3 );

  *y = - (
      ( *x - x2 ) * ( *x - x3 ) * ( x2 - x3 ) * y1
    + ( *x - x1 ) * ( *x - x3 ) * ( x3 - x1 ) * y2
    + ( *x - x1 ) * ( *x - x2 ) * ( x1 - x2 ) * y3 ) /
    ( ( x1 - x2 ) * ( x2 - x3 ) * ( x3 - x1 ) );

  return 0;
}
/******************************************************************************/

int r8poly2_ex2 ( double x1, double y1, double x2, double y2, double x3,
  double y3, double *x, double *y, double *a, double *b, double *c )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_EX2 finds the extremal point of a parabola determined by three points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, double X1, Y1, X2, Y2, X3, Y3, the coordinates of three points
    on the parabola.  X1, X2 and X3 must be distinct.

    Output, double *X, *Y, the X coordinate of the extremal point of the
    parabola, and the value of the parabola at that point.

    Output, double *A, *B, *C, the coefficients that define the parabola:
    P(X) = A * X**2 + B * X + C.

    Output, int R8POLY2_EX2, error flag.
    0, no error.
    1, two of the X values are equal.
    2, the data lies on a straight line; there is no finite extremal
    point.
    3, the data lies on a horizontal line; any point is an "extremal point".
*/
{
  double v[3*3];
  double *w;

  *a = 0.0;
  *b = 0.0;
  *c = 0.0;
  *x = 0.0;
  *y = 0.0;

  if ( x1 == x2 || x2 == x3 || x3 == x1 )
  {
    return 1;
  }

  if ( y1 == y2 && y2 == y3 && y3 == y1 )
  {
    *x = x1;
    *y = y1;
    return 3;
  }
/*
  Set up the Vandermonde matrix.
*/
  v[0+0*3] = 1.0;
  v[0+1*3] = x1;
  v[0+2*3] = x1 * x1;

  v[1+0*3] = 1.0;
  v[1+1*3] = x2;
  v[1+2*3] = x2 * x2;

  v[2+0*3] = 1.0;
  v[2+1*3] = x3;
  v[2+2*3] = x3 * x3;
/*
  Get the inverse.
*/
  w = r8mat_inverse_3d ( v );
/*
  Compute the parabolic coefficients.
*/
  *c = w[0+0*3] * y1 + w[0+1*3] * y2 + w[0+2*3] * y3;
  *b = w[1+0*3] * y1 + w[1+1*3] * y2 + w[1+2*3] * y3;
  *a = w[2+0*3] * y1 + w[2+1*3] * y2 + w[2+2*3] * y3;
/*
  Determine the extremal point.
*/
  if ( *a == 0.0 )
  {
    return 2;
  }

  *x = - *b / ( 2.0 * *a );
  *y = *a * *x * *x + *b * *x + *c;

  return 0;
}
/******************************************************************************/

void r8poly2_root ( double a, double b, double c, double complex *r1, 
  double complex *r2 )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_ROOT returns the two roots of a quadratic polynomial.

  Discussion:

    The polynomial has the form:

      A * X * X + B * X + C = 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, C, the coefficients of the polynomial.
    A must not be zero.

    Output, double complex *R1, *R2, the roots of the polynomial, which
    might be real and distinct, real and equal, or complex conjugates.
*/
{
  double complex disc;
  double complex q;

  if ( a == 0.0 )
  {
    printf ( "\n" );
    printf ( "R8POLY2_ROOT - Fatal error!\n" );
    printf ( "  The coefficient A is zero.\n" );
    exit ( 1 );
  }
  disc = b * b - 4.0 * a * c;
  q = - 0.5 * ( b + r8_sign ( b ) * csqrt ( disc ) );
  *r1 = q / a;
  *r2 = c / q;

  return;
}
/******************************************************************************/

void r8poly2_rroot ( double a, double b, double c, double *r1, double *r2 )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_RROOT returns the real parts of the roots of a quadratic polynomial.

  Example:

    A    B    C       roots              R1   R2
   --   --   --     ------------------   --   --
    1   -4    3     1          3          1    3
    1    0    4     2*i      - 2*i        0    0
    1   -6   10     3 +   i    3 -   i    3    3

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 December 2016

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, C, the coefficients of the quadratic
    polynomial A * X^2 + B * X + C = 0 whose roots are desired.
    A must not be zero.

    Output, double *R1, *R2, the real parts of the roots
    of the polynomial.
*/
{
  double disc;
  double q;

  if ( a == 0.0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8POLY2_RROOT - Fatal error!\n" );
    fprintf ( stderr, "  The coefficient A is zero.\n" );
    exit ( 1 );
  }

  disc = b * b - 4.0 * a * c;
  if ( 0.0 <= disc )
  {
    q = ( b + r8_sign ( b ) * sqrt ( disc ) );
    *r1 = -0.5 * q / a;
    *r2 = -2.0 * c / q;
  }
  else
  {
    *r1 = b / 2.0 / a;
    *r2 = b / 2.0 / a;
  }

  return;
}
/******************************************************************************/

void r8poly2_val ( double x1, double y1, double x2, double y2,
  double x3, double y3, double x, double *y, double *yp, double *ypp )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_VAL evaluates a parabola defined by three data values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, double X1, Y1, X2, Y2, X3, Y3, three pairs of data values.
    If the X values are distinct, then all the Y values represent
    actual values of the parabola.

    Three special cases are allowed:

      X1 = X2 =/= X3: Y2 is the derivative at X1;
      X1 =/= X2 = X3: Y3 is the derivative at X3;
      X1 = X2 = X3:   Y2 is the derivative at X1, and
                      Y3 is the second derivative at X1.

    Input, double X, an abscissa at which the parabola is to be
    evaluated.

    Output, double *Y, *YP, *YPP, the values of the parabola and
    its first and second derivatives at X.
*/
{
  int distinct;
  double dif1;
  double dif2;
  double temp;
/*
  If any X's are equal, put them and the Y data first.
*/
  if ( x1 == x2 && x2 == x3 )
  {
    distinct = 1;
  }
  else if ( x1 == x2 )
  {
    distinct = 2;
  }
  else if ( x1 == x3 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8POLY2_VAL - Fatal error!\n" );
    fprintf ( stderr, "  X1 = X3 =/= X2.\n" );
    return;
  }
  else if ( x2 == x3 )
  {
    distinct = 2;
    temp = x1;
    x1 = x3;
    x3 = temp;
    temp = y1;
    y1 = y2;
    y2 = y3;
    y3 = y1;
  }
  else
  {
    distinct = 3;
  }
/*
  Set up the coefficients.
*/
  if ( distinct == 1 )
  {
    dif1 = y2;
    dif2 = 0.5 * y3;
  }
  else if ( distinct == 2 )
  {
    dif1 = y2;
    dif2 = ( ( y3 - y1 ) / ( x3 - x1 )
             - y2 ) / ( x3 - x2 );
  }
  else if ( distinct == 3 )
  {
    dif1 = ( y2 - y1 ) / ( x2 - x1 );
    dif2 = ( ( y3 - y1 ) / ( x3 - x1 )
           - ( y2 - y1 ) / ( x2 - x1 ) ) / ( x3 - x2 );
  }
/*
  Evaluate.
*/
  *y = y1 + ( x - x1 ) * dif1 + ( x - x1 ) * ( x - x2 ) * dif2;
  *yp = dif1 + ( 2.0 * x - x1 - x2 ) * dif2;
  *ypp = 2.0 * dif2;

  return;
}
/******************************************************************************/

void r8poly2_val2 ( int ndata, double tdata[],
  double ydata[], int left, double tval, double *yval )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_VAL2 evaluates a parabolic function through 3 points in a table.

  Discussion:

    This routine is a utility routine used by OVERHAUSER_SPLINE_VAL.
    It constructs the parabolic interpolant through the data in
    3 consecutive entries of a table and evaluates this interpolant
    at a given abscissa value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int NDATA, the number of data points.
    NDATA must be at least 3.

    Input, double TDATA[NDATA], the abscissas of the data points.  The
    values in TDATA must be in strictly ascending order.

    Input, double YDATA[NDATA], the data points corresponding to
    the abscissas.

    Input, int LEFT, the location of the first of the three
    consecutive data points through which the parabolic interpolant
    must pass.  0 <= LEFT <= NDATA - 3.

    Input, double TVAL, the value of T at which the parabolic interpolant
    is to be evaluated.  Normally, TDATA[0] <= TVAL <= T[NDATA-1], and
    the data will be interpolated.  For TVAL outside this range,
    extrapolation will be used.

    Output, double *YVAL, the value of the parabolic interpolant
    at TVAL.
*/
{
  double dif1;
  double dif2;
  double t1;
  double t2;
  double t3;
  double y1;
  double y2;
  double y3;
/*
  Check.
*/
  if ( left < 0 || ndata-3 < left )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "RPOLY2_VAL2 - Fatal error!\n" );
    fprintf ( stderr, "  LEFT < 0 or NDATA-3 < LEFT.\n" );
    exit ( 1 );
  }
/*
  Copy out the three abscissas.
*/
  t1 = tdata[left];
  t2 = tdata[left+1];
  t3 = tdata[left+2];

  if ( t2 <= t1 || t3 <= t2 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "RPOLY2_VAL2 - Fatal error!\n" );
    fprintf ( stderr, "  T2 <= T1 or T3 <= T2.\n" );
    fprintf ( stderr, "  T1 = %g\n", t1 );
    fprintf ( stderr, "  T2 = %g\n", t2 );
    fprintf ( stderr, "  T3 = %g\n", t3 );
    exit ( 1 );
  }
/*
  Construct and evaluate a parabolic interpolant for the data.
*/
  y1 = ydata[left];
  y2 = ydata[left+1];
  y3 = ydata[left+2];

  dif1 = ( y2 - y1 ) / ( t2 - t1 );
  dif2 =
    ( ( y3 - y1 ) / ( t3 - t1 )
    - ( y2 - y1 ) / ( t2 - t1 ) ) / ( t3 - t2 );

  *yval = y1 + ( tval - t1 ) * ( dif1 + ( tval - t2 ) * dif2 );

  return;
}
/******************************************************************************/

void r8poly3_root ( double a, double b, double c, double d, double complex *r1, 
  double complex *r2, double complex *r3 )

/******************************************************************************/
/*
  Purpose:

    R8POLY3_ROOT returns the three roots of a cubic polynomial.

  Discussion:

    The polynomial has the form

      A * X^3 + B * X^2 + C * X + D = 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Parameters:

    Input, double A, B, C, D, the coefficients of the polynomial.
    A must not be zero.

    Output, double complex *R1, *R2, *R3, the roots of the polynomial, which
    will include at least one real root.
*/
{
  double complex i;
  double complex one;
  double q;
  double r;
  const double r8_pi = 3.141592653589793;
  double s1;
  double s2;
  double temp;
  double theta;

  if ( a == 0.0 )
  {
    printf ( "\n" );
    printf ( "R8POLY3_ROOT - Fatal error!\n" );
    printf ( "  A must not be zero!\n" );
    exit ( 1 );
  }

  one = 1.0;
  i = I;

  q = ( ( b / a ) * ( b / a ) - 3.0 * ( c / a ) ) / 9.0;

  r = ( 2.0 * ( b / a ) * ( b / a ) * ( b / a ) - 9.0 * ( b / a ) * ( c / a ) 
      + 27.0 * ( d / a ) ) / 54.0;

  if ( r * r < q * q * q )
  {
    theta = acos ( r / sqrt ( q * q * q ) );
    *r1 = - 2.0 * csqrt ( q ) * cos (   theta                 / 3.0 );
    *r2 = - 2.0 * csqrt ( q ) * cos ( ( theta + 2.0 * r8_pi ) / 3.0 );
    *r3 = - 2.0 * csqrt ( q ) * cos ( ( theta + 4.0 * r8_pi ) / 3.0 );
  }
  else if ( q * q * q <= r * r )
  {
    temp = - r + sqrt ( r * r - q * q * q );
    s1 = r8_sign ( temp ) * pow ( fabs ( temp ), 1.0 / 3.0 );

    temp = - r - sqrt ( r * r - q * q * q );
    s2 = r8_sign ( temp ) * pow ( fabs ( temp ), 1.0 / 3.0 );

    *r1 = s1 + s2;
    *r2 = - 0.5 * ( s1 + s2 ) + i * 0.5 * sqrt ( 3.0 ) * ( s1 - s2 );
    *r3 = - 0.5 * ( s1 + s2 ) - i * 0.5 * sqrt ( 3.0 ) * ( s1 - s2 );
  }

  *r1 = *r1 - b / ( 3.0 * a );
  *r2 = *r2 - b / ( 3.0 * a );
  *r3 = *r3 - b / ( 3.0 * a );

  return;
}
/******************************************************************************/

void r8poly4_root ( double a, double b, double c, double d, double e, 
  double complex *r1, double complex *r2, double complex *r3, 
  double complex *r4 )

/******************************************************************************/
/*
  Purpose:

    R8POLY4_ROOT returns the four roots of a quartic polynomial.

  Discussion:

    The polynomial has the form:

      A * X^4 + B * X^3 + C * X^2 + D * X + E = 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Parameters:

    Input, double A, B, C, D, E, the coefficients of the polynomial.
    A must not be zero.

    Output, double complex *R1, *R2, *R3, *R4, the roots of the polynomial.
*/
{
  double a3;
  double a4;
  double b3;
  double b4;
  double c3;
  double c4;
  double d3;
  double d4;
  double complex p;
  double complex q;
  double complex r;
  double complex zero;

  zero = 0.0;

  if ( a == 0.0 )
  {
    printf ( "\n" );
    printf ( "R8POLY4_ROOT - Fatal error!\n" );
    printf ( "  A must not be zero!\n" );
    exit ( 1 );
  }

  a4 = b / a;
  b4 = c / a;
  c4 = d / a;
  d4 = e / a;
/*
  Set the coefficients of the resolvent cubic equation.
*/
  a3 = 1.0;
  b3 = - b4;
  c3 = a4 * c4 - 4.0 * d4;
  d3 = - a4 * a4 * d4 + 4.0 * b4 * d4 - c4 * c4;
/*
  Find the roots of the resolvent cubic.
*/
  r8poly3_root ( a3, b3, c3, d3, r1, r2, r3 );
/*
  Choose one root of the cubic, here R1.

  Set R = sqrt ( 0.25 * A4 ^ 2 - B4 + R1 )
*/
  r = csqrt ( 0.25 * a4 * a4 - b4 + *r1 );

  if ( r != zero )
  {
    p = csqrt ( 0.75 * a4 * a4 - r * r - 2.0 * b4
        + 0.25 * ( 4.0 * a4 * b4 - 8.0 * c4 - a4 * a4 * a4 ) / r );

    q = csqrt ( 0.75 * a4 * a4 - r * r - 2.0 * b4 
        - 0.25 * ( 4.0 * a4 * b4 - 8.0 * c4 - a4 * a4 * a4 ) / r );
  }
  else
  {
    p = csqrt ( 0.75 * a4 * a4 - 2.0 * b4 + 2.0 * sqrt ( *r1 * *r1 - 4.0 * d4 ) );

    q = csqrt ( 0.75 * a4 * a4 - 2.0 * b4 - 2.0 * sqrt ( *r1 * *r1 - 4.0 * d4 ) );
  }
/*
  Set the roots.
*/
  *r1 = -0.25 * a4 + 0.5 * r + 0.5 * p;
  *r2 = -0.25 * a4 + 0.5 * r - 0.5 * p;
  *r3 = -0.25 * a4 - 0.5 * r + 0.5 * q;
  *r4 = -0.25 * a4 - 0.5 * r - 0.5 * q;

  return;
}
/******************************************************************************/

void r8r8_print ( double a1, double a2, char *title )

/******************************************************************************/
/*
  Purpose:

    R8R8_PRINT prints an R8R8.

  Discussion:

    An R8R8 is a pair of R8 values, regarded as a single item.

    A format is used which suggests a coordinate pair:

  Example:

    Center : ( 1.23, 7.45 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, double A1, A2, the coordinates of the vector.

    Input, char *TITLE, a title.
*/
{
  fprintf ( stdout, "%s: ( %g, %g )\n", title, a1, a2 );

  return;
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

double r8vec_even_select ( int n, double xlo, double xhi, int ival )

/******************************************************************************/
/*
  Purpose:

    R8VEC_EVEN_SELECT returns the I-th of N evenly spaced values in [ XLO, XHI ].

  Discussion:

    An R8VEC is a vector of R8's.

    XVAL = ( (N-IVAL) * XLO + (IVAL-1) * XHI ) / ( N - 1 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of values.

    Input, double XLO, XHI, the low and high values.

    Input, int IVAL, the index of the desired point.
    IVAL is normally between 1 and N, but may be any integer value.

    Output, double R8VEC_EVEN_SELECT, the IVAL-th of N evenly spaced values
    between XLO and XHI.
    Unless N = 1, X(1) = XLO and X(N) = XHI.
    If N = 1, then X(1) = 0.5*(XLO+XHI).
*/
{
  double xval;

  if ( n == 1 )
  {
    xval = 0.5 * ( xlo + xhi );
  }
  else
  {
    xval = ( ( double ) ( n - ival     ) * xlo
           + ( double ) (     ival - 1 ) * xhi )
           / ( double ) ( n        - 1 );
  }

  return xval;
}
/******************************************************************************/

double *r8vec_indicator1_new ( int n )

/******************************************************************************/
/*
  Purpose:

    R8VEC_INDICATOR1_NEW sets an R8VEC to the indicator vector {1,2,3,...}.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of elements of A.

    Output, double R8VEC_INDICATOR1_NEW[N], the array.
*/
{
  double *a;
  int i;

  a = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    a[i] = ( double ) ( i + 1 );
  }

  return a;
}
/******************************************************************************/

bool r8vec_is_distinct ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_IS_DISTINCT is true if the entries in an R8VEC are distinct.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 March 2018

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double X[N], the vector to be checked.

    Output, bool R8VEC_IS_DISTINCT is true if all N elements of X
    are distinct.
*/
{
  int i;
  int j;
  bool value;

  value = true;

  for ( i = 1; i < n; i++ )
  { 
    for ( j = 0; j < i; j++ )
    {
      if ( x[i] == x[j] )
      {
        value = false;
        break;
      }
    }
  }
  return value;
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

void r8vec_transpose_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_TRANSPOSE_PRINT prints an R8VEC "transposed".

  Discussion:

    An R8VEC is a vector of R8's.

  Example:

    A = (/ 1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 10.9, 11.0 /)
    TITLE = 'My vector:  '

    My vector:   1.0    2.1    3.2    4.3    5.4
                 6.5    7.6    8.7    9.8   10.9
                11.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 May 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;
  int ihi;
  int ilo;
  int title_length;

  title_length = s_len_trim ( title );

  for ( ilo = 0; ilo < n; ilo = ilo + 5 )
  {
    if ( ilo == 0 )
    {
      printf ( "%s", title );
    }
    else
    {
      for ( i = 0; i < title_length; i++ )
      {
        printf ( " " );
      }
    }
    printf ( "  " );

    ihi = i4_min ( ilo + 5, n );
    for ( i = ilo; i < ihi; i++ )
    {
      printf ( "  %12g", a[i] );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

double *r8vec_uniform_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  const int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
}
/******************************************************************************/

double *r8vec_zeros_new ( int n )

/******************************************************************************/
/*
  Purpose:

    R8VEC_ZEROS_NEW creates and zeroes an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Output, double R8VEC_ZEROS_NEW[N], a vector of zeroes.
*/
{
  double *a;
  int i;

  a = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return a;
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

double *roots_to_r8poly ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    ROOTS_TO_R8POLY converts polynomial roots to polynomial coefficients.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 July 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of roots specified.

    Input, double X[N], the roots.

    Output, double ROOTS_TO_R8POLY[N+1], the coefficients of the polynomial.
*/
{
  double *c;
  int i;
  int j;

  c = r8vec_zeros_new ( n + 1 );
/*
  Initialize C to (0, 0, ..., 0, 1).
  Essentially, we are setting up a divided difference table.
*/
  c[n] = 1.0;
/*
  Convert to standard polynomial form by shifting the abscissas
  of the divided difference table to 0.
*/
  for ( j = 1; j <= n; j++ )
  {
    for ( i = 1; i <= n + 1 - j; i++ )
    {
      c[n-i] = c[n-i] - x[n+1-i-j] * c[n-i+1];
    }
  }
  return c;
}
/******************************************************************************/

int s_len_trim ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_LEN_TRIM returns the length of a string to the last nonblank.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 April 2003

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a pointer to a string.

    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
    If S_LEN_TRIM is 0, then the string is entirely blank.
*/
{
  int n;
  char *t;

  n = strlen ( s );
  t = s + strlen ( s ) - 1;

  while ( 0 < n )
  {
    if ( *t != ' ' )
    {
      return n;
    }
    t--;
    n--;
  }

  return n;
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

