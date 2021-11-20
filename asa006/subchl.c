# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa006.h"

/******************************************************************************/

void subchl ( double a[], int b[], int n, double u[], int *nullty, 
  int *ifault, int ndim, double *det )

/******************************************************************************/
/*
  Purpose:

    SUBCHL computes the Cholesky factorization of a (subset of a) PDS matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 February 2008

  Author:

    Original FORTRAN77 version by Michael Healy, PR Freeman.
    C version by  John Burkardt.

  Reference:

    PR Freeman,
    Remark AS R44:
    A Remark on AS 6 and AS7: Triangular decomposition of a symmetric matrix
    and Inversion of a positive semi-definite symmetric matrix,
    Applied Statistics,
    Volume 31, Number 3, 1982, pages 336-339.

    Michael Healy,
    Algorithm AS 6:
    Triangular decomposition of a symmetric matrix,
    Applied Statistics,
    Volume 17, Number 2, 1968, pages 195-197.

  Parameters:

    Input, double A((M*(M+1))/2), a positive definite matrix
    stored by rows in lower triangular form as a one dimensional array,
    in the sequence
    A(1,1),
    A(2,1), A(2,2),
    A(3,1), A(3,2), A(3,3), and so on.
    In the simplest case, M, the order of A, is equal to N.

    Input, int B(N), indicates the order in which the
    rows and columns of A are to be used.  In the simplest case,
    B = (1,2,3...,N).

    Input, int N, the order of the matrix, that is,
    the matrix formed by using B to select N rows and columns of A.

    Output, double U((N*(N+1))/2), an upper triangular matrix,
    stored by columns, which is the Cholesky factor of A.  The program is
    written in such a way that A and U can share storage.

    Output, int *NULLTY, the rank deficiency of A.
    If NULLTY is zero, the matrix is judged to have full rank.

    Output, int *IFAULT, an error indicator.
    0, no error was detected;
    1, if N < 1;
    2, if A is not positive semi-definite.

    Input, int NDIM, the dimension of A and U, which might
    be presumed to be (N*(N+1))/2.

    Output, double *DET, the determinant of the matrix.
*/
{
  int i;
  int icol;
  int ii;
  int ij;
  int irow;
  int j;
  int jj;
  int k;
  int kk;
  int l;
  int m;
  const double r8_epsilon = 2.220446049250313E-016;
  double w;
  double x;

  *ifault = 0;
  *nullty = 0;
  *det = 1.0;

  if ( n <= 0 )
  {
    *ifault = 1;
    return;
  }

  *ifault = 2;
  j = 1;
  k = 0;

  for ( icol = 1; icol <= n; icol++ )
  {
    ij = ( b[icol-1] * ( b[icol-1] - 1 ) ) / 2;
    ii = ij + b[icol-1];
    x = r8_epsilon * r8_epsilon * a[ii-1];
    l = 0;

    for ( irow = 1; irow <= icol; irow++ )
    {
      kk = ( b[irow-1] * ( b[irow-1] + 1 ) ) / 2;
      k = k + 1;
      jj = ij + b[irow-1];
      w = a[jj-1];
      m = j;

      for ( i = 1; i <= irow - 1; i++ )
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
        if ( fabs ( x * a[kk-1] ) < w * w )
        {
          *ifault = 2;
          return;
        }

        u[k-1] = 0.0;
      }
    }

    if ( fabs ( r8_epsilon * a[kk-1] ) <= fabs ( w ) )
    {
      if ( w < 0.0 )
      {
        *ifault = 2;
        return;
      }

      u[k-1] = sqrt ( w );
    }
    else
    {
      u[k-1] = 0.0;
      *nullty = *nullty + 1;
    }
    j = j + icol;
    *det = *det * u[k-1] * u[k-1];
  }

  return;
}

