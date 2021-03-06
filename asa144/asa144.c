# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "asa144.h"

/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 October 1998

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

    I4_MIN returns the minimum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 October 1998

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

void i4mat_print ( int m, int n, int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I4MAT_PRINT prints an I4MAT.

  Discussion:

    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, int A[M*N], the M by N matrix.

    Input, char *TITLE, a title.
*/
{
  i4mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi, 
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    I4MAT_PRINT_SOME prints some of an I4MAT.

  Discussion:

    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].

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

    Input, int A[M*N], the matrix.

    Input, int ILO, JLO, IHI, JHI, designate the first row and
    column, and the last row and column to be printed.

    Input, char *TITLE, a title.
*/
{
# define INCX 10

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
  Print the columns of the matrix, in strips of INCX.
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
    fprintf ( stdout, "  Col:" );
    for ( j = j2lo; j <= j2hi; j++ )
    {
      fprintf ( stdout, "  %6d", j - 1 );
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
  Print out (up to INCX) entries in row I, that lie in the current strip.
*/
      fprintf ( stdout, "%5d:", i - 1 );
      for ( j = j2lo; j <= j2hi; j++ )
      {
        fprintf ( stdout, "  %6d", a[i-1+(j-1)*m] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef INCX
}
/******************************************************************************/

void i4vec_print ( int n, int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PRINT prints an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 November 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ ) 
  {
    fprintf ( stdout, "  %6d: %8d\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 is a unit pseudorandom R8.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 August 2004

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

  Parameters:

    Input/output, int *SEED, a seed for the random number generator.

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

  r = ( double ) ( *seed ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

void rcont ( int nrow, int ncol, int nrowt[], int ncolt[], int nsubt[], 
  int matrix[], int *key, int *ifault )

/******************************************************************************/
/*
  Purpose:

    RCONT generates a random two-way table with given marginal totals.

  Discussion:

    Each time the program is called, another table will be randomly
    generated.

    Note that it should be the case that the sum of the row totals
    is equal to the sum of the column totals.  However, this program
    does not check for that condition.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 November 2010

  Author:

    Original FORTRAN77 version by James Boyett.
    C version by John Burkardt.

  Reference:

    James Boyett,
    Algorithm AS 144:
    Random R x C Tables with Given Row and Column Totals,
    Applied Statistics,
    Volume 28, Number 3, pages 329-332, 1979.

  Parameters:

    Input, int NROW, the number of rows in the observed matrix.

    Input, int NCOL, the number of columns in the observed matrix.

    Input, int NROWT[NROW], the row totals of the observed matrix.

    Input, int NCOLT[NCOL], the column totals of the observed matrix.

    Input/output, int NSUBT[NCOL], used by RCONT for partial column sums.
    Must not be changed by the calling program.

    Output, int MATRIX[NROW*NCOL], the randomly generated matrix.

    Input/output, int *KEY, should be set to FALSE by the user before
    the initial call.  RCONT will reset it to TRUE, and it should be left
    at that value for subsequent calls in which the same values of NROW,
    NCOL, NROWT and NCOLT are being used.

    Output, int *IFAULT, fault indicator.
    0, no error occured.
    1, NROW <= 0.
    2, NCOL <= 1.
    3, some entry of NROWT is less than 0.
    4, some entry of NCOLT is less than 0.
*/
{
  int i;
  int ii;
  int j;
  int k;
  int limit;
  int *nnvect;
  int noct;
  int ntemp;
  static int ntotal;
  static int *nvect = NULL;
  static int seed = 0;

  *ifault = 0;

  if ( !(*key) )
  {
/*
  Set KEY for subsequent calls.
*/
    *key = 1;
    seed = 123456789;
/*
  Check for faults and prepare for future calls.
*/
    if ( nrow <= 0 )
    {
      *ifault = 1;
      return;
    }

    if ( ncol <= 1 )
    {
      *ifault = 2;
      return;
    }

    for ( i = 0; i < nrow; i++ )
    {
      if ( nrowt[i] <= 0 )
      {
        *ifault = 3;
        return;
      }
    }

    if ( ncolt[0] <= 0 )
    {
      *ifault = 4;
      return;
    }

    nsubt[0] = ncolt[0];

    for ( j = 1; j < ncol; j++ )
    {
      if ( ncolt[j] <= 0 )
      {
        *ifault = 4;
        return;
      }
      nsubt[j] = nsubt[j-1] + ncolt[j];
    }

    ntotal = nsubt[ncol-1];

    if ( nvect )
    {
      free ( nvect );
    }
    nvect = ( int * ) malloc ( ntotal * sizeof ( int ) );
/*
  Initialize vector to be permuted.
*/
    for ( i = 0; i < ntotal; i++ )
    {
      nvect[i] = i + 1;
    }
  }
/*
  Initialize vector to be permuted.
*/
  nnvect = ( int * ) malloc ( ntotal * sizeof ( int ) );

  for ( i = 0; i < ntotal; i++ )
  {
    nnvect[i] = nvect[i];
  }
/*
  Permute vector.
*/
  ntemp = ntotal;

  for ( i = 0; i < ntotal; i++ )
  {
    noct = ( int ) ( r8_uniform_01 ( &seed ) * ( double ) ( ntemp ) + 1.0 );
    nvect[i] = nnvect[noct-1];
    nnvect[noct-1] = nnvect[ntemp-1];
    ntemp = ntemp - 1;
  }
/*
  Construct random matrix.
*/
  for ( j = 0; j < ncol; j++ )
  {
    for ( i = 0; i < nrow; i++ )
    {
      matrix[i+j*nrow] = 0;
    }
  }

  ii = 0;

  for ( i = 0; i < nrow; i++ )
  {
    limit = nrowt[i];

    for ( k = 0; k < limit; k++ )
    {
      for ( j = 0; j < ncol; j++ )
      {
        if ( nvect[ii] <= nsubt[j] )
        {
          ii = ii + 1;
          matrix[i+j*nrow] = matrix[i+j*nrow] + 1;
          break;
        }
      }
    }
  }

  free ( nnvect );

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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
