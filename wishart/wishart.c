# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>

# include "wishart.h"
# include "pdflib.h"
# include "rnglib.h"

/******************************************************************************/

double *bartlett_sample ( int m, int df, double sigma[] )

/******************************************************************************/
/*
  Purpose:

    BARTLETT_SAMPLE samples the Bartlett distribution.

  Discussion:

    If the matrix T is sampled from the Bartlett distribution, then 
    the matrix W = T' * T is a sample from the Wishart distribution.
 
    This function requires functions from the PDFLIB and RNGLIB libraries.

    The "initialize()" function from RNGLIB must be called before using
    this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 July 2013

  Author:

    John Burkardt

  Reference:

    Patrick Odell, Alan Feiveson,
    A numerical procedure to generate a sample covariance matrix,
    Journal of the American Statistical Association,
    Volume 61, Number 313, March 1966, pages 199-203.

    Stanley Sawyer,
    Wishart Distributions and Inverse-Wishart Sampling,
    Washington University,
    30 April 2007, 12 pages.

  Parameters:

    Input, int M, the order of the matrix.

    Input, int DF, the number of degrees of freedom.
    M <= DF.

    Input, double SIGMA[M*M], the covariance matrix, which should be 
    a symmetric positive definite matrix.

    Output, double BARTLETT_SAMPLE[M*M], the sample matrix from 
    the Bartlett distribution.
*/
{
  int flag;
  double *r;
  double *t;
  double *tu;

  if ( df < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "BARTLETT_SAMPLE - Fatal error!\n" );
    fprintf ( stderr, "  DF = %d < M = %d.\n", df, m );
    exit ( 1 );
  }
/*
  Get the upper triangular Cholesky factor of SIGMA.
*/
  r = r8mat_cholesky_factor_upper ( m, sigma, &flag );

  if ( flag != 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "BARTLETT_SAMPLE - Fatal error!\n" );
    fprintf ( stderr, 
      "  Unexpected error return from R8MAT_CHOLESKY_FACTOR_UPPER.\n" );
    fprintf ( stderr, "  FLAG = %d\n", flag );
    exit ( 1 );
  }
/*
  Sample the unit Bartlett distribution.
*/
  tu = bartlett_unit_sample ( m, df );
/*
  Construct the matrix T = TU * R.
*/
  t = r8mat_mm_new ( m, m, m, tu, r );
/*
  Free memory.
*/
  free ( r );
  free ( tu );

  return t;
}
/******************************************************************************/

double *bartlett_unit_sample ( int m, int df )

/******************************************************************************/
/*
  Purpose:

    BARTLETT_UNIT_SAMPLE samples the unit Bartlett distribution.

  Discussion:

    If the matrix T is sampled from the unit Bartlett distribution, then 
    the matrix W = T' * T is a sample from the unit Wishart distribution.
 
    This function requires functions from the PDFLIB and RNGLIB libraries.

    The "initialize()" function from RNGLIB must be called before using
    this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 October 2013

  Author:

    John Burkardt

  Reference:

    Patrick Odell, Alan Feiveson,
    A numerical procedure to generate a sample covariance matrix,
    Journal of the American Statistical Association,
    Volume 61, Number 313, March 1966, pages 199-203.

    Stanley Sawyer,
    Wishart Distributions and Inverse-Wishart Sampling,
    Washington University,
    30 April 2007, 12 pages.

  Parameters:

    Input, int M, the order of the matrix.

    Input, int DF, the number of degrees of freedom.
    M <= DF.

    Output, double BARTLETT_UNIT_SAMPLE[M*M], the sample matrix from the 
    unit Bartlett distribution.
*/
{
  double df_chi;
  int i;
  int j;
  double *t;

  if ( df < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "BARTLETT_UNIT_SAMPLE - Fatal error!\n" );
    fprintf ( stderr, "  DF = %d < M = %d.\n", df, m );
    exit ( 1 );
  }

  t = ( double * ) malloc ( m * m * sizeof ( double ) );
  
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      t[i+j*m] = 0.0;
    }
    df_chi = ( double ) ( df - i );
    t[i+i*m] = sqrt ( r8_chi_sample ( df_chi ) );
    for ( j = i + 1; j < m; j++ )
    {
      t[i+j*m] = r8_normal_01_sample ( );
    }
  }

  return t;
}
/******************************************************************************/

void jacobi_eigenvalue ( int n, double a[], int it_max, double v[], 
  double d[], int *it_num, int *rot_num )

/******************************************************************************/
/*
  Purpose:

    JACOBI_EIGENVALUE carries out the Jacobi eigenvalue iteration.

  Discussion:

    This function computes the eigenvalues and eigenvectors of a
    real symmetric matrix, using Rutishauser's modfications of the classical
    Jacobi rotation method with threshold pivoting. 

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N*N], the matrix, which must be square, real,
    and symmetric.

    Input, int IT_MAX, the maximum number of iterations.

    Output, double V[N*N], the matrix of eigenvectors.

    Output, double D[N], the eigenvalues, in descending order.

    Output, int *IT_NUM, the total number of iterations.

    Output, int *ROT_NUM, the total number of rotations.
*/
{
  double *bw;
  double c;
  double g;
  double gapq;
  double h;
  int i;
  int j;
  int k;
  int l;
  int m;
  int p;
  int q;
  double s;
  double t;
  double tau;
  double term;
  double termp;
  double termq;
  double theta;
  double thresh;
  double w;
  double *zw;

  r8mat_identity ( n, v );

  r8mat_diag_get_vector ( n, a, d );

  bw = ( double * ) malloc ( n * sizeof ( double ) );
  zw = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    bw[i] = d[i];
    zw[i] = 0.0;
  }
  *it_num = 0;
  *rot_num = 0;

  while ( *it_num < it_max )
  {
    *it_num = *it_num + 1;
/*
  The convergence threshold is based on the size of the elements in
  the strict upper triangle of the matrix.
*/
    thresh = 0.0;
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < j; i++ )
      {
        thresh = thresh + a[i+j*n] * a[i+j*n];
      }
    }

    thresh = sqrt ( thresh ) / ( double ) ( 4 * n );

    if ( thresh == 0.0 )
    {
      break;
    }

    for ( p = 0; p < n; p++ )
    {
      for ( q = p + 1; q < n; q++ )
      {
        gapq = 10.0 * fabs ( a[p+q*n] );
        termp = gapq + fabs ( d[p] );
        termq = gapq + fabs ( d[q] );
/*
  Annihilate tiny offdiagonal elements.
*/
        if ( 4 < *it_num &&
             termp == fabs ( d[p] ) &&
             termq == fabs ( d[q] ) )
        {
          a[p+q*n] = 0.0;
        }
/*
  Otherwise, apply a rotation.
*/
        else if ( thresh <= fabs ( a[p+q*n] ) )
        {
          h = d[q] - d[p];
          term = fabs ( h ) + gapq;

          if ( term == fabs ( h ) )
          {
            t = a[p+q*n] / h;
          }
          else
          {
            theta = 0.5 * h / a[p+q*n];
            t = 1.0 / ( fabs ( theta ) + sqrt ( 1.0 + theta * theta ) );
            if ( theta < 0.0 )
            {
              t = - t;
            }
          }
          c = 1.0 / sqrt ( 1.0 + t * t );
          s = t * c;
          tau = s / ( 1.0 + c );
          h = t * a[p+q*n];
/*
  Accumulate corrections to diagonal elements.
*/
          zw[p] = zw[p] - h;                 
          zw[q] = zw[q] + h;
          d[p] = d[p] - h;
          d[q] = d[q] + h;

          a[p+q*n] = 0.0;
/*
  Rotate, using information from the upper triangle of A only.
*/
          for ( j = 0; j < p; j++ )
          {
            g = a[j+p*n];
            h = a[j+q*n];
            a[j+p*n] = g - s * ( h + g * tau );
            a[j+q*n] = h + s * ( g - h * tau );
          }

          for ( j = p + 1; j < q; j++ )
          {
            g = a[p+j*n];
            h = a[j+q*n];
            a[p+j*n] = g - s * ( h + g * tau );
            a[j+q*n] = h + s * ( g - h * tau );
          }

          for ( j = q + 1; j < n; j++ )
          {
            g = a[p+j*n];
            h = a[q+j*n];
            a[p+j*n] = g - s * ( h + g * tau );
            a[q+j*n] = h + s * ( g - h * tau );
          }
/*
  Accumulate information in the eigenvector matrix.
*/
          for ( j = 0; j < n; j++ )
          {
            g = v[j+p*n];
            h = v[j+q*n];
            v[j+p*n] = g - s * ( h + g * tau );
            v[j+q*n] = h + s * ( g - h * tau );
          }
          *rot_num = *rot_num + 1;
        }
      }
    }

    for ( i = 0; i < n; i++ )
    {
      bw[i] = bw[i] + zw[i];
      d[i] = bw[i];
      zw[i] = 0.0;
    }
  }
/*
  Restore upper triangle of input matrix.
*/
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      a[i+j*n] = a[j+i*n];
    }
  }
/*
  Descending sort the eigenvalues and eigenvectors.
*/
  for ( k = 0; k < n - 1; k++ )
  {
    m = k;
    for ( l = k + 1; l < n; l++ )
    {
      if ( d[m] < d[l] )
      {
        m = l;
      }
    }

    if ( m != k )
    {
      t    = d[m];
      d[m] = d[k];
      d[k] = t;
      for ( i = 0; i < n; i++ )
      {
        w        = v[i+m*n];
        v[i+m*n] = v[i+k*n];
        v[i+k*n] = w;
      }
    }
  }

  free ( bw );
  free ( zw );

  return;
}
/******************************************************************************/

void r8mat_add ( int m, int n, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_ADD adds one R8MAT to another.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 July 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double A[M*N], the matrix to add.

    Input/output, double B[M*N], the matrix to be incremented.
*/
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[i+j*m] = b[i+j*m] + a[i+j*m];
    }
  }
  return;
}
/******************************************************************************/

double *r8mat_cholesky_factor_upper ( int n, double a[], int *flag )

/******************************************************************************/
/*
  Purpose:

    R8MAT_CHOLESKY_FACTOR_UPPER: upper Cholesky factor of a symmetric R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    The matrix must be symmetric and positive semidefinite.

    For a positive semidefinite symmetric matrix A, the Cholesky factorization
    is an upper triangular matrix R such that:

      A = R' * R

    Note that the usual Cholesky factor is a LOWER triangular matrix L
    such that

      A = L * L'

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of rows and columns of the matrix A.

    Input, double A[N*N], the N by N matrix.

    Output, int *FLAG, an error flag.
    0, no error was detected.
    1, the matrix was not positive definite.  A NULL factor was returned.

    Output, double R8MAT_CHOLESKY_FACTOR_UPPER[N*N], the N by N upper triangular
    "Choresky" factor.
*/
{
  double *c;
  int i;
  int j;
  int k;
  double sum2;

  *flag = 0;

  c = r8mat_copy_new ( n, n, a );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      c[j+i*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      sum2 = c[i+j*n];
      for ( k = 0; k < j; k++ )
      {
        sum2 = sum2 - c[k+j*n] * c[k+i*n];
      }
      if ( i == j )
      {
        if ( sum2 <= 0.0 )
        {
          *flag = 1;
          return NULL;
        }
        c[j+i*n] = sqrt ( sum2 );
      }
      else
      {
        if ( c[j+j*n] != 0.0 )
        {
          c[j+i*n] = sum2 / c[j+j*n];
        }
        else
        {
          c[j+i*n] = 0.0;
        }
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8mat_copy_new ( int m, int n, double a1[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_COPY_NEW copies one R8MAT to a "new" R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double A1[M*N], the matrix to be copied.

    Output, double R8MAT_COPY_NEW[M*N], the copy of A1.
*/
{
  double *a2;
  int i;
  int j;

  a2 = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }

  return a2;
}
/******************************************************************************/

void r8mat_diag_get_vector ( int n, double a[], double v[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DIAG_GET_VECTOR gets the value of the diagonal of an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 July 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of rows and columns of the matrix.

    Input, double A[N*N], the N by N matrix.

    Output, double V[N], the diagonal entries
    of the matrix.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    v[i] = a[i+i*n];
  }

  return;
}
/******************************************************************************/

double *r8mat_diagonal_new ( int n, double diag[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DIAGONAL_NEW returns a diagonal matrix.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 July 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of A.

    Input, double DIAG[N], the diagonal entries.

    Output, double R8MAT_DIAGONAL_NEW[N*N], the N by N identity matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = diag[i];
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }

  return a;
}
/******************************************************************************/

void r8mat_divide ( int m, int n, double s, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DIVIDE divides an R8MAT by a scalar.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 July 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double S, the divisor

    Input/output, double A[M*N], the matrix to be scaled.
*/
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = a[i+j*m] / s;
    }
  }
  return;
}
/******************************************************************************/

void r8mat_identity  ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_IDENTITY sets an R8MAT to the identity matrix.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2005

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of A.

    Output, double A[N*N], the N by N identity matrix.
*/
{
  int i;
  int j;
  int k;

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[k] = 1.0;
      }
      else
      {
        a[k] = 0.0;
      }
      k = k + 1;
    }
  }

  return;
}
/******************************************************************************/

double *r8mat_identity_new ( int n )

/******************************************************************************/
/*
  Purpose:

    R8MAT_IDENTITY_NEW returns an identity matrix.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2005

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of A.

    Output, double R8MAT_IDENTITY_NEW[N*N], the N by N identity matrix.
*/
{
  double *a;
  int i;
  int j;
  int k;

  a = ( double * ) malloc ( n * n * sizeof ( double ) );

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[k] = 1.0;
      }
      else
      {
        a[k] = 0.0;
      }
      k = k + 1;
    }
  }

  return a;
}
/******************************************************************************/

double *r8mat_mm_new ( int n1, int n2, int n3, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_MM_NEW multiplies two matrices.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    For this routine, the result is returned as the function value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, the order of the matrices.

    Input, double A[N1*N2], double B[N2*N3], the matrices to multiply.

    Output, double R8MAT_MM[N1*N3], the product matrix C = A * B.
*/
{
  double *c;
  int i;
  int j;
  int k;

  c = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  for ( i = 0; i < n1; i++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[k+j*n2];
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8mat_mmt_new ( int n1, int n2, int n3, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_MMT_NEW computes C = A * B'.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    For this routine, the result is returned as the function value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 November 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, the order of the matrices.

    Input, double A[N1*N2], double B[N3*N2], the matrices to multiply.

    Output, double R8MAT_MMT[N1*N3], the product matrix C = A * B'.
*/
{
  double *c;
  int i;
  int j;
  int k;

  c = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  for ( i = 0; i < n1; i++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[j+k*n3];
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8mat_mtm_new ( int n1, int n2, int n3, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_MTM_NEW computes C = A' * B.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    For this routine, the result is returned as the function value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, the order of the matrices.

    Input, double A[N2*N1], double B[N2*N3], the matrices to multiply.

    Output, double R8MAT_MTM_NEW[N1*N3], the product matrix C = A' * B.
*/
{
  double *c;
  int i;
  int j;
  int k;

  c = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  for ( i = 0; i < n1; i++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[k+i*n2] * b[k+j*n2];
      }
    }
  }

  return c;
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
        fprintf ( stdout, "  %14f", a[i-1+(j-1)*m] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef INCX
}
/******************************************************************************/

double *r8mat_zero_new ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8MAT_ZERO_NEW returns a new zeroed R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 September 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Output, double R8MAT_ZERO_NEW[M*N], the new zeroed matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }
  return a;
}
/******************************************************************************/

double *r8ut_inverse ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_INVERSE computes the inverse of a R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2013

  Author:

    John Burkardt

  Reference:

    Albert Nijenhuis, Herbert Wilf,
    Combinatorial Algorithms,
    Academic Press, 1978, second edition,
    ISBN 0-12-519260-6

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N*N], the R8UT matrix.

    Output, double R8UT_INVERSE[N*N], the inverse of the upper 
    triangular matrix.
*/
{
  double *b;
  int i;
  int j;
  int k;
/*
  Check.
*/
  for ( i = 0; i < n; i++ )
  {
    if ( a[i+i*n] == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8UT_INVERSE - Fatal error!\n" );
      fprintf ( stderr, "  Zero diagonal element.\n" );
      exit ( 1 );
    }
  }

  b = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( j = n-1; 0 <= j; j-- )
  {
    for ( i = n-1; 0 <= i; i-- )
    {
      if ( j < i )
      {
        b[i+j*n] = 0.0;
      }
      else if ( i == j )
      {
        b[i+j*n] = 1.0 / a[i+j*n];
      }
      else if ( i < j )
      {
        b[i+j*n] = 0.0;

        for ( k = i+1; k <= j; k++ )
        {
          b[i+j*n] = b[i+j*n] - a[i+k*n] * b[k+j*n];
        }
        b[i+j*n] = b[i+j*n] / a[i+i*n];
      }
    }
  }

  return b;
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

double *wishart_sample ( int m, int df, double sigma[] )

/******************************************************************************/
/*
  Purpose:

    WISHART_SAMPLE samples the Wishart distribution.

  Discussion:

    This function requires functions from the PDFLIB and RNGLIB libraries.

    The "initialize()" function from RNGLIB must be called before using
    this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 July 2013

  Author:

    John Burkardt

  Reference:

    Patrick Odell, Alan Feiveson,
    A numerical procedure to generate a sample covariance matrix,
    Journal of the American Statistical Association,
    Volume 61, Number 313, March 1966, pages 199-203.

    Stanley Sawyer,
    Wishart Distributions and Inverse-Wishart Sampling,
    Washington University,
    30 April 2007, 12 pages.

  Parameters:

    Input, int M, the order of the matrix.

    Input, int DF, the number of degrees of freedom.
    M <= DF.

    Input, double SIGMA[M*M], the covariance matrix, which should be 
    a symmetric positive definite matrix.

    Output, double WISHART_SAMPLE[M*M], the sample matrix from 
    the Wishart distribution.
*/
{
  double *a;
  double *au;
  double *aur;
  int flag;
  double *r;

  if ( df < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WISHART_SAMPLE - Fatal error!\n" );
    fprintf ( stderr, "  DF = %d < M = %d.\n", df, m );
    exit ( 1 );
  }
/*
  Get R, the upper triangular Cholesky factor of SIGMA.
*/
  r = r8mat_cholesky_factor_upper ( m, sigma, &flag );

  if ( flag != 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WISHART_SAMPLE - Fatal error!\n" );
    fprintf ( stderr, 
      "  Unexpected error return from R8MAT_CHOLESKY_FACTOR_UPPER.\n" );
    fprintf ( stderr, "  FLAG = %d\n", flag );
    exit ( 1 );
  }
/*
  Get AU, a sample from the unit Wishart distribution.
*/
  au = wishart_unit_sample ( m, df );
/*
  Construct the matrix A = R' * AU * R.
*/
  aur = r8mat_mm_new ( m, m, m, au, r );
  a = r8mat_mtm_new ( m, m, m, r, aur );
/*
  Free memory.
*/
  free ( au );
  free ( aur );
  free ( r );

  return a;
}
/******************************************************************************/

double *wishart_sample_inverse ( int m, int df, double sigma[] )

/******************************************************************************/
/*
  Purpose:

    WISHART_SAMPLE_INVERSE returns the inverse of a sample Wishart matrix.

  Discussion:

    This function requires functions from the PDFLIB and RNGLIB libraries.

    The "initialize()" function from RNGLIB must be called before using
    this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 October 2013

  Author:

    John Burkardt

  Reference:

    Patrick Odell, Alan Feiveson,
    A numerical procedure to generate a sample covariance matrix,
    Journal of the American Statistical Association,
    Volume 61, Number 313, March 1966, pages 199-203.

    Stanley Sawyer,
    Wishart Distributions and Inverse-Wishart Sampling,
    Washington University,
    30 April 2007, 12 pages.

  Parameters:

    Input, int M, the order of the matrix.

    Input, int DF, the number of degrees of freedom.
    M <= DF.

    Input, double SIGMA[M*M], the covariance matrix, which should be 
    a symmetric positive definite matrix.

    Output, double WISHART_SAMPLE[M*M], the inverse of a sample matrix from 
    the Wishart distribution.
*/
{
  double *a;
  int flag;
  double *r;
  double *s;
  double *ua;
  double *uas;

  if ( df < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WISHART_SAMPLE_INVERSE - Fatal error!\n" );
    fprintf ( stderr, "  DF = %d < M = %d.\n", df, m );
    exit ( 1 );
  }
/*
  Get R, the upper triangular Cholesky factor of SIGMA.
*/
  r = r8mat_cholesky_factor_upper ( m, sigma, &flag );

  if ( flag != 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WISHART_SAMPLE_INVERSE - Fatal error!\n" );
    fprintf ( stderr, 
      "  Unexpected error return from R8MAT_CHOLESKY_FACTOR_UPPER.\n" );
    fprintf ( stderr, "  FLAG = %d\n", flag );
    exit ( 1 );
  }
/*
  Get S, the inverse of R.
*/
  s = r8ut_inverse ( m, r );
/*
  Get UA, the inverse of a sample from the unit Wishart distribution.
*/
  ua = wishart_unit_sample_inverse ( m, df );
/*
  Construct the matrix A = S * UA * S'.
*/
  uas = r8mat_mmt_new ( m, m, m, ua, s );
  a = r8mat_mm_new ( m, m, m, s, uas );
/*
  Free memory.
*/
  free ( r );
  free ( s );
  free ( ua );
  free ( uas );

  return a;
}
/******************************************************************************/

double *wishart_unit_sample ( int m, int df )

/******************************************************************************/
/*
  Purpose:

    WISHART_UNIT_SAMPLE samples the unit Wishart distribution.

  Discussion:

    This function requires functions from the PDFLIB and RNGLIB libraries.

    The "initialize()" function from RNGLIB must be called before using
    this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 October 2013

  Author:

    John Burkardt

  Reference:

    Patrick Odell, Alan Feiveson,
    A numerical procedure to generate a sample covariance matrix,
    Journal of the American Statistical Association,
    Volume 61, Number 313, March 1966, pages 199-203.

    Stanley Sawyer,
    Wishart Distributions and Inverse-Wishart Sampling,
    Washington University,
    30 April 2007, 12 pages.

  Parameters:

    Input, int M, the order of the matrix.

    Input, int DF, the number of degrees of freedom.
    M <= DF.

    Output, double WISHART_UNIT_SAMPLE[M*M], the sample matrix from the 
    unit Wishart distribution.
*/
{
  double *a;
  double *c;
  double df_chi;
  int i;
  int j;

  if ( df < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WISHART_UNIT_SAMPLE - Fatal error!\n" );
    fprintf ( stderr, "  DF = %d < M = %d.\n", df, m );
    exit ( 1 );
  }

  c = ( double * ) malloc ( m * m * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      c[i+j*m] = 0.0;
    }
    df_chi = ( double ) ( df - i );
    c[i+i*m] = sqrt ( r8_chi_sample ( df_chi ) );
    for ( j = i + 1; j < m; j++ )
    {
      c[i+j*m] = r8_normal_01_sample ( );
    }
  }

  a = r8mat_mtm_new ( m, m, m, c, c );
/*
  Free memory.
*/
  free ( c );

  return a;
}
/******************************************************************************/

double *wishart_unit_sample_inverse ( int m, int df )

/******************************************************************************/
/*
  Purpose:

    WISHART_UNIT_SAMPLE_INVERSE inverts a unit Wishart sample matrix.

  Discussion:

    This function requires functions from the PDFLIB and RNGLIB libraries.

    The "initialize()" function from RNGLIB must be called before using
    this function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 October 2013

  Author:

    John Burkardt

  Reference:

    Patrick Odell, Alan Feiveson,
    A numerical procedure to generate a sample covariance matrix,
    Journal of the American Statistical Association,
    Volume 61, Number 313, March 1966, pages 199-203.

    Stanley Sawyer,
    Wishart Distributions and Inverse-Wishart Sampling,
    Washington University,
    30 April 2007, 12 pages.

  Parameters:

    Input, int M, the order of the matrix.

    Input, int DF, the number of degrees of freedom.
    M <= DF.

    Output, double WISHART_UNIT_SAMPLE_INVERSE[M*M], the inverse of a
    sample matrix from the unit Wishart distribution.
*/
{
  double *a;
  double *b;
  double *c;
  double df_chi;
  int i;
  int j;

  if ( df < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WISHART_UNIT_SAMPLE_INVERSE - Fatal error!\n" );
    fprintf ( stderr, "  DF = %d < M = %d.\n", df, m );
    exit ( 1 );
  }

  c = ( double * ) malloc ( m * m * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      c[i+j*m] = 0.0;
    }
    df_chi = ( double ) ( df - i );
    c[i+i*m] = sqrt ( r8_chi_sample ( df_chi ) );
    for ( j = i + 1; j < m; j++ )
    {
      c[i+j*m] = r8_normal_01_sample ( );
    }
  }
/*
  Compute B, the inverse of C.
*/
  b = r8ut_inverse ( m, c );
/*
  The inverse of the Wishart sample matrix C'*C is inv(C) * C'.
*/
  a = r8mat_mmt_new ( m, m, m, b, b );
/*
  Free memory.
*/
  free ( b );
  free ( c );

  return a;
}
