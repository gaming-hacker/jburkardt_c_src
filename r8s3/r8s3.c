# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "r8s3.h"

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

void r8s3_diagonal ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_DIAGONAL reorders an R8S3 matrix so diagonal entries are first.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

    This routine reorders the entries of A so that the first N entries
    are exactly the diagonal entries of the matrix, in order.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in 
    the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and 
    column indices of the nonzero elements.

    Input/output, double A[NZ_NUM], the nonzero elements 
    of the matrix.
*/
{
  int found;
  int i;
  int j;
  int k;
  double t;

  found = 0;

  for ( k = 0; k < nz_num; k++ )
  {
    while ( row[k] == col[k] )
    {
      if ( row[k] == k )
      {
        found = found + 1;
        break;
      }

      i = row[k];

      j      = row[i];
      row[i] = row[k];
      row[k] = j;

      j      = col[i];
      col[i] = col[k];
      col[k] = j;

      t    = a[i];
      a[i] = a[k];
      a[k] = t;
 
      found = found + 1;

      if ( i4_min ( m, n ) <= found )
      {
        break;
      }
    }

    if ( i4_min ( m, n ) <= found )
    {
      break;
    }
  }

  if ( found < i4_min ( m, n ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8S3_DIAGONAL - Warning!\n" );
    fprintf ( stderr,
      "  Number of diagonal entries expected: %d\n", i4_min ( m, n ) );
    fprintf ( stderr, "  Number found was %d\n", found );
  }

  return;
}
/******************************************************************************/

void r8s3_dif2 ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_DIF2 sets up an R8S3 second difference matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero entries.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Output, int ROW[NZ_NUM], COL[NZ_NUM], the row and column
    indices of the nonzero elements.

    Output, double A[NZ_NUM], the indicator matrix.
*/
{
  int i;
  int j;
  int k;

  k = 0;
/*
  Diagonal entries.
*/
  for ( j = 0; j < n; j++ )
  {
    i = j;
    row[k] = i;
    col[k] = j;
    a[k] = 2.0;
    k = k + 1;
  }
/*
  Offdiagonal nonzeros, by column.
*/
  for ( j = 0; j < n; j++ )
  {
    if ( sym != 1 )
    {
      if ( 0 < j )
      {
        i = j - 1;
        row[k] = i;
        col[k] = j;
        a[k] = -1.0;
        k = k + 1;
      }
    }

    if ( j + 1 <= m - 1 )
    {
      i = j + 1;
      row[k] = i;
      col[k] = j;
      a[k] = -1.0;
      k = k + 1;
    }
  }

  return;
}
/******************************************************************************/

double *r8s3_indicator ( int m, int n, int nz_num, int sym, int row[], 
  int col[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_INDICATOR sets up an R8S3 indicator matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero entries.

    Input, int SYM, is 0 if the matrix is not symmetric, and 1
    if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    Output, double R8S3_INDICATOR[NZ_NUM], the indicator matrix.
*/
{
  double *a;
  int fac;
  int i;
  int j;
  int k;

  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( k = 0; k < nz_num; k++ )
  {
    i = row[k];
    j = col[k];
    a[k] = ( double ) ( fac * ( i + 1 ) + ( j + 1 ) );
  }

  return a;
}
/******************************************************************************/

void r8s3_jac_sl ( int n, int nz_num, int sym, int row[], int col[], 
  double a[], double b[], double x[], int it_max )

/******************************************************************************/
/*
  Purpose:

    R8S3_JAC_SL solves an R8S3 system using Jacobi iteration.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

    This routine REQUIRES that the matrix be square, that the matrix
    have nonzero diagonal entries, and that the first N entries of
    the array A be exactly the diagonal entries of the matrix, in order.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in 
    the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column 
    indices of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements of the matrix.

    Input, double B[N], the right hand side of the linear system.

    Input/output, double X[N], an approximate solution 
    to the system.

    Input, int IT_MAX, the maximum number of iterations.
*/
{
  int i;
  int it_num;
  int j;
  int k;
  double *x_new;

  x_new = ( double * ) malloc ( n * sizeof ( double ) );

  for ( it_num = 1; it_num <= it_max; it_num++ )
  {
/*
  Initialize to right hand side.
*/
    for ( j = 0; j < n; j++ )
    {
      x_new[j] = b[j];
    }
/*
  Subtract off-diagonal terms.
*/
    for ( k = n; k < nz_num; k++ )
    {
      i = row[k];
      j = col[k];
      x_new[i] = x_new[i] - a[k] * x[j];
      if ( sym == 1 )
      {
        x_new[j]= x_new[j] - a[k] * x[i];
      }
    }
/*
  Divide by diagonal terms and update.
*/
    for ( j = 0; j < n; j++ )
    {
      x[j] = x_new[j] / a[j];
    }
  }

  free ( x_new );

  return;
}
/******************************************************************************/

double *r8s3_mtv ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_MTV multiplies an R8VEC times an R8S3 matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in
    the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column
    indices of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements of the matrix.

    Input, double X[M], the vector to be multiplied by A'.

    Output, double B[N], the product A' * x.
*/
{
  double *b;
  int i;
  int j;
  int k;

  b = r8vec_zeros_new ( n );

  for ( k = 0; k < nz_num; k++ )
  {
    i = col[k];
    j = row[k];
    b[i] = b[i] + a[k] * x[j];
  }
/*
  Handle the symmetric option.
*/
  if ( sym == 1 && m == n )
  {
    for ( k = 0; k < nz_num; k++ )
    {
      i = row[k];
      j = col[k];
      if ( i != j )
      {
        b[i] = b[i] + a[k] * x[j];
      }
    }
  }

  return b;
}
/******************************************************************************/

double *r8s3_mv ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_MV multiplies an R8S3 matrix by an R8VEC.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in 
    the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column 
    indices of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements of the matrix.

    Input, double X[N], the vector to be multiplied by A.

    Output, double B[M], the product A * x.
*/
{
  double *b;
  int i;
  int j;
  int k;

  b = r8vec_zeros_new ( m );

  for ( k = 0; k < nz_num; k++ )
  {
    i = row[k];
    j = col[k];
    b[i] = b[i] + a[k] * x[j];
  }
/*
  Handle the symmetric option.
*/
  if ( sym == 1 && m == n )
  {
    for ( k = 0; k < nz_num; k++ )
    {
      i = col[k];
      j = row[k];
      if ( i != j )
      {
        b[i] = b[i] + a[k] * x[j];
      }
    }
  }

  return b;
}
/******************************************************************************/

void r8s3_print ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8S3_PRINT prints an R8S3 matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, and 1
    if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements 
    of the matrix.

    Input, char *TITLE, a title.
*/
{
  r8s3_print_some ( m, n, nz_num, sym, row, col, a, 0, 0, m - 1, n - 1, title );

  return;
}
/******************************************************************************/

void r8s3_print_some ( int m, int n, int nz_num, int sym, int row[], 
  int col[], double a[], int ilo, int jlo, int ihi, int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8S3_PRINT_SOME prints some of an R8S3 matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M,  N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, and 1
    if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements 
    of the matrix.

    Input, int ILO, JLO, IHI, JHI, the first row and
    column, and the last row and column to be printed.

    Input, char *TITLE, a title.
*/
{
# define INCX 5

  double aij;
  int i;
  int i2hi;
  int i2lo;
  int inc;
  int index[INCX];
  int j;
  int j2;
  int j2hi;
  int j2lo;
  int k;
  int nonzero;

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

    inc = j2hi + 1 - j2lo;

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
      nonzero = 0;
 
      for ( j2 = 0; j2 < inc; j2++ )
      {
        index[j2] = -1;
      }

      for ( k = 0; k < nz_num; k++ )
      {
        if ( i == row[k] && j2lo <= col[k] && col[k] <= j2hi )
        {
          j2 = col[k] - j2lo + 1;

          if ( a[k] != 0.0 )
          {
            index[j2-1] = k;
            nonzero = 1;
          }
        }
        else if ( sym == 1 && m == n &&
          i == col[k] && j2lo <= row[k] && row[k] <= j2hi )
        {
          j2 = row[k] - j2lo + 1;

          if ( a[k] != 0.0 )
          {
            index[j2-1] = k;
            nonzero = 1;
          }
        }
      }

      if ( nonzero )
      {
        printf ( "%5d ", i );
        for ( j2 = 0; j2 < inc; j2++ )
        {
          if ( 0 <= index[j2] )
          {
            aij = a[index[j2]];
          }
          else
          {
            aij = 0.0;
          }
          printf ( "%14g", aij );
        }
        printf ( "\n" );
      }
    }
  }
  printf ( "\n" );

  return;
# undef INCX
}
/******************************************************************************/

double *r8s3_random ( int m, int n, int nz_num, int sym, int row[], int col[],
  int *seed )

/******************************************************************************/
/*
  Purpose:

    R8S3_RANDOM randomizes an R8S3 matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero entries.

    Input, int SYM, is 0 if the matrix is not symmetric, and 1
    if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    input/output, int *SEED, a seed for the random number generator.

    Output, double R8S3_RANDOM[NZ_NUM], the matrix.
*/
{
  double *a;
  int k;

  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  for ( k = 0; k < nz_num; k++ )
  {
    a[k] = r8_uniform_01 ( seed );
  }

  return a;
}
/******************************************************************************/

void r8s3_read ( char *input_file, int m, int n, int nz_num, int row[], 
  int col[], double a[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_READ reads a square R8S3 matrix from a file.

  Discussion:

    This routine needs the value of NZ_NUM, which can be determined
    by a call to R8S3_READ_SIZE.

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 April 2013

  Author:

    John Burkardt

  Parameters:

    Input, char *INPUT_FILE, the name of the file to be read.

    Unused, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in the matrix.

    Output, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    Output, double A[NZ_NUM], the nonzero elements of the matrix.
*/
{
  FILE *input;
  int k;

  input = fopen ( input_file, "rt" );

  if ( !input )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8S3_READ - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n", input_file );
    exit ( 1 );
  }

  for ( k = 0; k < nz_num; k++ )
  {
    fscanf ( input, "%d%d%lf\n", row+k, col+k, a+k );
  }

  fclose ( input );

  return;
}
/******************************************************************************/

void r8s3_read_size ( char *input_file, int *m, int *n, int *nz_num )

/******************************************************************************/
/*
  Purpose:

    R8S3_READ_SIZE reads the size of a square R8S3 matrix from a file.

  Discussion:

    The value of NZ_NUM is simply the number of records in the input file.

    The values of M and N are determined as the maximum entry in the row 
    and column vectors.

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 April 2013

  Author:

    John Burkardt

  Parameters:

   Input, char *INPUT_FILE, the name of the file to 
   be read.

    Output, int *M, *N, the order of the matrix.

    Output, int *NZ_NUM, the number of nonzero elements in the matrix.
*/
{
  double a_k;
  int col_k;
  int flag;
  FILE *input;
  int row_k;

  *nz_num = 0;
  *m = 0;
  *n = 0;

  input = fopen ( input_file, "rt" );

  if ( !input )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8S3_READ_SIZE - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n", input_file );
    exit ( 1 );
  }

  for ( ; ; )
  {
    flag = fscanf ( input, "%d%d%lf\n", &row_k, &col_k, &a_k );

    if ( flag == EOF )
    {
      break;
    }

    *nz_num = *nz_num + 1;
    *m = i4_max ( *m, row_k + 1 );
    *n = i4_max ( *n, col_k + 1 );
  }

  fclose ( input );

  return;
}
/******************************************************************************/

double *r8s3_res ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[], double x[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_RES computes the residual R = B-A*X for R8S3 matrices.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in 
    the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  The symmetric case only makes sense
    if the matrix is also square, that is, M = N.  In this case, only
    the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column
    indices of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements of the matrix.

    Input, double X[N], the vector to be multiplied by A.

    Input, double B[M], the desired result A * x.

    Output, double R8S3_RES[M], the residual R = B - A * X.
*/
{
  int i;
  double *r;

  r = r8s3_mv ( m, n, nz_num, sym, row, col, a, x );

  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
/******************************************************************************/

double *r8s3_to_r8ge ( int m, int n, int nz_num, int sym, int row[], 
  int col[], double a[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_TO_R8GE copies an R8S3 matrix to an R8GE matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in 
    the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, 
    and 1 if the matrix is symmetric.  The symmetric case only makes sense
    if the matrix is also square, that is, M = N.  In this case, only
    the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column
    indices of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements of the matrix.

    Output, double B[M*N], the R8GE matrix.
*/
{
  double *b;
  int i;
  int j;
  int k;

  b = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[i+j*m] = 0.0;
    }
  }

  for ( k = 0; k < nz_num; k++ )
  {
    i = row[k];
    j = col[k];
    b[i+j*m] = b[i+j*m] + a[k];
    if ( sym == 1 && m == n && i != j )
    {
      b[j+i*m] = b[j+i*m] + a[k];
    }
  }

  return b;
}
/******************************************************************************/

void r8s3_write ( int m, int n, int nz_num, int sym, int row[], int col[], 
  double a[], char *output_file )

/******************************************************************************/
/*
  Purpose:

    R8S3_WRITE writes a square R8S3 matrix to a file.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

    There is a symmetry option for square matrices.  If the symmetric storage
    option is used, the format specifies that only nonzeroes on the diagonal
    and lower triangle are stored.  However, this routine makes no attempt
    to enforce this.  The only thing it does is to "reflect" any nonzero
    offdiagonal value.  Moreover, no check is made for the erroneous case
    in which both A(I,J) and A(J,I) are specified, but with different values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 April 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero elements in the matrix.

    Input, int SYM, is 0 if the matrix is not symmetric, and 1
    if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    Input, double A[NZ_NUM], the nonzero elements 
    of the matrix.

    Input, char *OUTPUT_FILE, the name of the file to which
    the information is to be written.
*/
{
  int k;
  FILE *output_unit;

  output_unit = fopen ( output_file, "wt" );

  if ( !output_unit )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8S3_WRITE - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the output file.\n" );
    exit ( 1 );
  }

  for ( k = 0; k < nz_num; k++ )
  {
    fprintf ( output_unit, "  %8d  %8d  %12g\n", row[k], col[k], a[k] );
  }

  fclose ( output_unit );

  return;
}
/******************************************************************************/

double *r8s3_zeros ( int m, int n, int nz_num, int sym, int row[], int col[] )

/******************************************************************************/
/*
  Purpose:

    R8S3_ZEROS zeros an R8S3 matrix.

  Discussion:

    The R8S3 storage format corresponds to the sparse triplet format.

    The R8S3 storage format stores the row, column and value of each nonzero
    entry of a sparse matrix.  The entries may be given in any order.  No
    check is made for the erroneous case in which a given matrix entry is
    specified more than once.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, int NZ_NUM, the number of nonzero entries.

    Input, int SYM, is 0 if the matrix is not symmetric, and 1
    if the matrix is symmetric.  If the matrix is symmetric, then
    only the nonzeroes on the diagonal and in the lower triangle are stored.

    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
    of the nonzero elements.

    Output, double R8S3_ZEROS[NZ_NUM], the matrix.
*/
{
  double *a;
  int k;

  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  for ( k = 0; k < nz_num; k++ )
  {
    a[k] = 0.0;
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
