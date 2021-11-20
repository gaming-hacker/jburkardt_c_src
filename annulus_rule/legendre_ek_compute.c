# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "annulus_rule.h"

/******************************************************************************/

void legendre_ek_compute ( int n, double x[], double w[] )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_EK_COMPUTE: Legendre quadrature rule by the Elhay-Kautsky method.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 March 2014

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

    Input, int N, the order.

    Output, double X[N], the abscissas.

    Output, double W[N], the weights.
*/
{
  double *bj;
  int i;
  double ip1;
  double zemu;
/*
  Define the zero-th moment.
*/
  zemu = 2.0;
/*
  Define the Jacobi matrix.
*/
  bj = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    ip1 = ( double ) ( i + 1 );
    bj[i] = sqrt ( ip1 * ip1 / ( 4.0 * ip1 * ip1 - 1.0 ) );
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

