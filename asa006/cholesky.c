# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa006.h"

/******************************************************************************/

void cholesky ( double a[], int n, int nn, double u[], int *nullty, 
  int *ifault )

/******************************************************************************/
/*
  Purpose:

    CHOLESKY computes the Cholesky factorization of a PDS matrix.

  Discussion:

    For a positive definite symmetric matrix A, the Cholesky factor U
    is an upper triangular matrix such that A = U' * U.

    This routine was originally named "CHOL", but that conflicted with
    a built in MATLAB routine name.

    The missing initialization "II = 0" has been added to the code.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 January 2017

  Author:

    Original FORTRAN77 version by Michael Healy.
    Modifications by AJ Miller.
    C version by John Burkardt.

  Reference:

    Michael Healy,
    Algorithm AS 6:
    Triangular decomposition of a symmetric matrix,
    Applied Statistics,
    Volume 17, Number 2, 1968, pages 195-197.

  Parameters:

    Input, double A((N*(N+1))/2), a positive definite matrix 
    stored by rows in lower triangular form as a one dimensional array, 
    in the sequence
    A(1,1),
    A(2,1), A(2,2),
    A(3,1), A(3,2), A(3,3), and so on.

    Input, int N, the order of A.

    Input, int NN, the dimension of the array used to store A, 
    which should be at least (N*(N+1))/2.

    Output, double U((N*(N+1))/2), an upper triangular matrix,
    stored by columns, which is the Cholesky factor of A.  The program is
    written in such a way that A and U can share storage.

    Output, int NULLTY, the rank deficiency of A.  If NULLTY is zero,
    the matrix is judged to have full rank.

    Output, int IFAULT, an error indicator.
    0, no error was detected;
    1, if N < 1;
    2, if A is not positive semi-definite.
    3, if NN < (N*(N+1))/2.

  Local Parameters:

    Local, double R8_EPSILON, should be set equal to the smallest positive
    value such that 1.0 + R8_EPSILON is calculated as being greater than 1.0 in the
    accuracy being used.
*/
{

  int i;
  int icol;
  int ii;
  int irow;
  int j;
  int k;
  int kk;
  int l;
  int m;
  const double r8_epsilon = 2.220446049250313E-016;
  double w;
  double x;

  *ifault = 0;
  *nullty = 0;

  if ( n <= 0 )
  {
    *ifault = 1;
    return;
  }

  if ( nn < ( n * ( n + 1 ) ) / 2 )
  {
    *ifault = 3;
    return;
  }

  j = 1;
  k = 0;
  ii = 0;
/*
  Factorize column by column, ICOL = column number.
*/
  for ( icol = 1; icol <= n; icol++ )
  {
    ii = ii + icol;
    x = r8_epsilon * r8_epsilon * a[ii-1];
    l = 0;
    kk = 0;
/*
  IROW = row number within column ICOL.
*/
    for ( irow = 1; irow <= icol; irow++ )
    {
      kk = kk + irow;
      k = k + 1;
      w = a[k-1];
      m = j;

      for ( i = 1; i < irow; i++ )
      {
        l = l + 1;
        w = w - u[l-1] * u[m-1];
        m = m + 1;
      }

      l = l + 1;

      if ( irow == icol ) 
      {
        break;
      }

      if ( u[l-1] != 0.0 )
      {
        u[k-1] = w / u[l-1];
      }
      else
      {
        u[k-1] = 0.0;

        if ( fabs ( x * a[k-1] ) < w * w )
        {
          *ifault = 2;
          return;
        }
      }
    }
/*
  End of row, estimate relative accuracy of diagonal element.
*/
    if ( fabs ( w ) <= fabs ( r8_epsilon * a[k-1] ) )
    {
      u[k-1] = 0.0;
      *nullty = *nullty + 1;
    }
    else
    {
      if ( w < 0.0 )
      {
        *ifault = 2;
        return;
      }
      u[k-1] = sqrt ( w );
    }
    j = j + icol;
  }
  return;
}

