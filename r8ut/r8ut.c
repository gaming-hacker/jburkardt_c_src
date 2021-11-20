# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "r8ut.h"

/******************************************************************************/

int i4_log_10 ( int i )

/******************************************************************************/
/*
  Purpose:

    I4_LOG_10 returns the integer part of the logarithm base 10 of an I4.

  Example:

        I  I4_LOG_10
    -----  --------
        0    0
        1    0
        2    0
        9    0
       10    1
       11    1
       99    1
      100    2
      101    2
      999    2
     1000    3
     1001    3
     9999    3
    10000    4

  Discussion:

    I4_LOG_10 ( I ) + 1 is the number of decimal digits in I.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, the number whose logarithm base 10 is desired.

    Output, int I4_LOG_10, the integer part of the logarithm base 10 of
    the absolute value of X.
*/
{
  int i_abs;
  int ten_pow;
  int value;

  if ( i == 0 )
  {
    value = 0;
  }
  else
  {
    value = 0;
    ten_pow = 10;

    i_abs = abs ( i );

    while ( ten_pow <= i_abs )
    {
      value = value + 1;
      ten_pow = ten_pow * 10;
    }
  }
  return value;
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

int i4_power ( int i, int j )

/******************************************************************************/
/*
  Purpose:

    I4_POWER returns the value of I^J.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, J, the base and the power.  J should be nonnegative.

    Output, int I4_POWER, the value of I^J.
*/
{
  int k;
  int value;

  if ( j < 0 )
  {
    if ( i == 1 )
    {
      value = 1;
    }
    else if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I4_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J negative.\n" );
      exit ( 1 );
    }
    else
    {
      value = 0;
    }
  }
  else if ( j == 0 )
  {
    if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I4_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J = 0.\n" );
      exit ( 1 );
    }
    else
    {
      value = 1;
    }
  }
  else if ( j == 1 )
  {
    value = i;
  }
  else
  {
    value = 1;
    for ( k = 1; k <= j; k++ )
    {
      value = value * i;
    }
  }
  return value;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a unit pseudorandom R8.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + 2147483647;
  }
/*
  Although SEED can be represented exactly as a 32 bit integer,
  it generally cannot be represented exactly as a 32 bit real number!
*/
  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

void r8ge_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8GE_PRINT prints an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8GE matrix.

    Input, char *TITLE, a title.
*/
{
  r8ge_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8ge_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8GE_PRINT_SOME prints some of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8GE matrix.

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

  printf ( "\n" );
  printf ( "%s\n", title );
/*
  Print the columns of the matrix, in strips of 5.
*/
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    printf ( "\n" );
/*
  For each column J in the current range...

  Write the header.
*/
    printf ( "  Col:    " );
    for ( j = j2lo; j <= j2hi; j++ )
    {
      printf ( "%7d       ", j );
    }
    printf ( "\n" );
    printf ( "  Row\n" );
    printf ( "  ---\n" );
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
      printf ( "%5d  ", i );
      for ( j = j2lo; j <= j2hi; j++ )
      {
        printf ( "%12g  ", a[i-1+(j-1)*m] );
      }
      printf ( "\n" );
    }
  }
  return;
# undef INCX
}
/******************************************************************************/

double *r8ge_random ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8GE_RANDOM randomizes an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8GE_RANDOM[M*N], the randomized M by N matrix, 
    with entries between 0 and 1.
*/
{
  double *a;
  int i;
  int j;

  a = r8vec_zeros_new ( m * n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = r8_uniform_01 ( seed );
    }
  }
  return a;
}
/******************************************************************************/

double *r8ge_to_r8ut ( int m, int n, double a_ge[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8UT copies an R8GE matrix to an R8UT matrix.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, double A_GE[M,N], the R8GE matrix.

    Output, double R8GE_TO_R8UT[M,N], the R8UT matrix.
*/
{
  double *a_ut;
  int i;
  int j;

  a_ut = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( i <= j ) 
      {
        a_ut[i+j*m] = a_ge[i+j*m];
      }
      else
      {
        a_ut[i+j*m] = 0.0;
      }
    }
  }

  return a_ut;
}
/******************************************************************************/

double r8ut_det ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_DET computes the determinant of an R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[N*N], the R8UT matrix.

    Output, double R8UT_DET, the determinant of the matrix.
*/
{
  double det;
  int i;

  det = 1.0;

  for ( i = 0; i < n; i++ )
  {
    det = det * a[i+i*n];
  }

  return det;
}
/******************************************************************************/

double *r8ut_indicator ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8UT_INDICATOR sets up an R8UT indicator matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of the matrix.
    M and N must be positive.

    Output, double R8UT_INDICATOR[M*N], the R8UT matrix.
*/
{
  double *a;
  int fac;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= m; i++ )
  {
    for ( j = 1; j <= i4_min ( i-1, n ); j++ )
    {
      a[i-1+(j-1)*m] = 0.0;
    }
    for ( j = i; j <= n; j++ )
    {
      a[i-1+(j-1)*m] = ( double ) ( fac * i + j );
    }
  }

  return a;
}
/******************************************************************************/

double *r8ut_inverse ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_INVERSE computes the inverse of an R8UT matrix.

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

    Output, double R8UT_INVERSE[N*N], the inverse of the upper triangular matrix.
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

double *r8ut_mm ( int n, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_MM computes C = A * B, where A and B are R8UT matrices.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

    The product will also be an R8UT matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrices.
    N must be positive.

    Input, double A[N*N], B[N*N], the factors.

    Output, double R8UT_MM[N*N], the product.
*/
{
  double *c;
  int i;
  int j;
  int k;

  c = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      c[i+j*n] = 0.0;
    }
    for ( j = i; j < n; j++ )
    {
      c[i+j*n] = 0.0;
      for ( k = i; k <= j; k++ )
      {
        c[i+j*n] = c[i+j*n] + a[i+k*n] * b[k+j*n];
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8ut_mtm ( int n, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_MTM computes C = A' * B, where A and B are R8UT matrices.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

    The product C will NOT be an R8UT matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrices.
    N must be positive.

    Input, double A[N*N], B[N*N], the R8UT factor matrices.

    Output, double R8UT_MTM[N*N], the R8UT product matrix.
*/
{
  double *c;
  int i;
  int j;
  int k;
  int k_hi;

  c = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      k_hi = i4_min ( i, j );
      c[i+j*n] = 0.0;
      for ( k = 0; k <= k_hi; k++ )
      {
        c[i+j*n] = c[i+j*n] + a[k+i*n] * b[k+j*n];
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8ut_mtv ( int m, int n, double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_MTV multiplies a vector times an R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8UT matrix.

    Input, double X[M], the vector to be multiplied by A.

    Output, double R8UT_MTV[N], the product A' * x.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    b[j] = 0.0;
    for ( i = 0; i <= j && i < m; i++ )
    {
      b[j] = b[j] + x[i] * a[i+j*m];
    }
  }

  return b;
}
/******************************************************************************/

double *r8ut_mv ( int m, int n, double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_MV multiplies an R8UT matrix times a vector.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8UT matrix.

    Input, double X[N], the vector to be multiplied by A.

    Output, double R8UT_MV[M], the product A * x.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( m * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
    for ( j = i; j < n; j++ )
    {
      b[i] = b[i] + a[i+j*m] * x[j];
    }
  }

  return b;
}
/******************************************************************************/

void r8ut_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8UT_PRINT prints an R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8UT matrix.

    Input, char *TITLE, a title.
*/
{
  r8ut_print_some ( m, n, a, 0, 0, m - 1, n - 1, title );

  return;
}
/******************************************************************************/

void r8ut_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8UT_PRINT_SOME prints some of an R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8UT matrix.

    Input, int ILO, JLO, IHI, JHI, designate the first row and
    column, and the last row and column to be printed.
    0 <= ILO <= IHI < M.
    0 <= JLO <= JHI < N.

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

  printf ( "\n" );
  printf ( "%s\n", title );
/*
  Print the columns of the matrix, in strips of 5.
*/
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n - 1 );
    j2hi = i4_min ( j2hi, jhi );

    printf ( "\n" );
    printf ( "  Col: " );

    for ( j = j2lo; j <= j2hi; j++ )
    {
      printf ( "%7d       ", j );
    }
    printf ( "\n" );
    printf ( "  Row\n" );
    printf ( "  ---\n" );
/*
  Determine the range of the rows in this strip.
*/
    i2lo = i4_max ( ilo, 0 );
    i2hi = i4_min ( ihi, m - 1 );

    for ( i = i2lo; i <= i2hi; i++ )
    {
/*
  Print out (up to) 5 entries in row I, that lie in the current strip.
*/
      printf ( "%4d  ", i );

      for ( j = j2lo; j <= j2hi; j++ )
      {
        if ( j < i )
        {
          printf ( "              " );
        }
        else
        {
          printf ( "%12g  ", a[i+j*m] );
        }
      }
      printf ( "\n" );
    }
  }

  return;
# undef INCX
}
/******************************************************************************/

double *r8ut_random ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8UT_RANDOM randomizes an R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of the matrix.
    M and N must be positive.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8UT_RANDOM[M*N], the R8UT matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= i4_min ( j, m - 1 ); i++ )
    {
      a[i+j*m] = r8_uniform_01 ( seed );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }

  return a;
}
/******************************************************************************/

double *r8ut_sl ( int n, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_SL solves a linear system A*x=b with R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

    No factorization of the upper triangular matrix is required.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N*N], the R8UT matrix.

    Input, double B[N], the right hand side.

    Output, double R8UT_SL[N], the solution vector.
*/
{
  int i;
  int j;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    x[i] = b[i];
  }

  for ( j = n-1; 0 <= j; j-- )
  {
    x[j] = x[j] / a[j+j*n];
    for ( i = 0; i < j; i++ )
    {
      x[i] = x[i] - a[i+j*n] * x[j];
    }
  }

  return x;
}
/******************************************************************************/

double *r8ut_slt ( int n, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_SLT solves a linear system A'*x=b with R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

    No factorization of the upper triangular matrix is required.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N*N], the R8UT matrix.

    Input, double B[N], the right hand side.

    Output, double R8UT_SLT[N], the solution vector.
*/
{
  int i;
  int j;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    x[i] = b[i];
  }

  for ( j = 0; j < n; j++ )
  {
    x[j] = x[j] / a[j+j*n];
    for ( i = j+1; i < n; i++ )
    {
      x[i] = x[i] - a[j+i*n] * x[j];
    }
  }
  return x;
}
/******************************************************************************/

double *r8ut_to_r8ge ( int m, int n, double a_ut[] )

/******************************************************************************/
/*
  Purpose:

    R8UT_TO_R8GE copies an R8UT matrix to an R8GE matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, double A_UT[M,N], the R8UT matrix.

    Output, double R8UT_TO_R8GE[M,N], the R8GE matrix.
*/
{
  double *a_ge;
  int i;
  int j;

  a_ge = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( i <= j ) 
      {
        a_ge[i+j*m] = a_ut[i+j*m];
      }
      else
      {
        a_ge[i+j*m] = 0.0;
      }
    }
  }

  return a_ge;
}
/******************************************************************************/

double *r8ut_zeros ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8UT_ZEROS zeros an R8UT matrix.

  Discussion:

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Output, double R8UT_ZEROS[M*N], the R8UT matrix.
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

double *r8vec_indicator1_new ( int n )

/******************************************************************************/
/*
  Purpose:

    R8VEC_INDICATOR1_NEW sets an R8VEC to the indicator1 vector {1,2,3...}.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 August 2008

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

  for ( i = 0; i <= n-1; i++ ) 
  {
    a[i] = ( double ) ( i + 1 );
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

  printf ( "\n" );
  printf ( "%s\n", title );
  printf ( "\n" );

  for ( i = 0; i < n; i++ ) 
  {
    printf ( "  %8d  %14f\n", i, a[i] );
  }

  return;
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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
