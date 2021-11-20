# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa053.h"

/******************************************************************************/

double *wshrt ( double d[], int n, int np, int *seed )

/******************************************************************************/
/*
  Purpose:

    WSHRT returns a random Wishart variate.

  Discussion:

    This routine is a Wishart variate generator.  

    On output, SA is an upper-triangular matrix of size NP * NP,
    written in linear form, column ordered, whose elements have a 
    Wishart(N, SIGMA) distribution.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2014

  Author:

    Original FORTRAN77 version by William Smith, Ronald Hocking.
    This C version by John Burkardt.

  Reference:

    William Smith, Ronald Hocking,
    Algorithm AS 53, Wishart Variate Generator,
    Applied Statistics,
    Volume 21, Number 3, pages 341-345, 1972.

  Parameters:

    Input, double D[NP*(NP+1)/2], the upper triangular array that
    represents the Cholesky factor of the correlation matrix SIGMA.
    D is stored in column-major form.

    Input, int N, the number of degrees of freedom.
    1 <= N <= NP.

    Input, int NP, the size of variables.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double WSHART[NP*(NP+1)/2], a sample from the 
    Wishart distribution.
*/
{
  double c;
  double df;
  int i;
  int ii;
  int ip;
  int j;
  int k;
  int nnp;
  int nq;
  int nr;
  int ns;
  double rn;
  double *sa;
  double *sb;
  double u1;
  double u2;

  k = 0;
  nnp = ( np * ( np + 1 ) ) / 2;
/*
  Load SB with independent normal (0, 1) variates.
*/
  sb = ( double * ) malloc ( nnp * sizeof ( double ) );

  while ( k < nnp )
  {
    rnorm ( seed, &u1, &u2 );

    sb[k] = u1;
    k = k + 1;

    if ( k < nnp )
    {
      sb[k] = u2;
      k = k + 1;
    }
  }
/*
  Load diagonal elements with square root of chi-square variates.
*/
  ns = 0;

  for ( i = 1; i <= np; i++ )
  {
    df = ( double ) ( np - i + 1 );
    ns = ns + i;
    u1 = 2.0 / ( 9.0 * df );
    u2 = 1.0 - u1;
    u1 = sqrt ( u1 );
/*
  Wilson-Hilferty formula for approximating chi-square variates:
  The original code did not take the absolute value!
*/
    sb[ns-1] = sqrt ( df * fabs ( pow ( u2 + sb[ns-1] * u1, 3 ) ) );
  }

  sa = ( double * ) malloc ( nnp * sizeof ( double ) );

  rn = ( double ) ( n );
  nr = 1;

  for ( i = 1; i <= np; i++ )
  {
    nr = nr + i - 1;
    for ( j = i; j <= np; j++ )
    {
      ip = nr;
      nq = ( j * ( j - 1 ) ) / 2 + i - 1;
      c = 0.0;
      for ( k = i; k <= j; k++ )
      {
        ip = ip + k - 1;
        nq = nq + 1;
        c = c + sb[ip-1] * d[nq-1];
      }
      sa[ip-1] = c;
    }
  }

  for ( i = 1; i <= np; i++ )
  {
    ii = np - i + 1;
    nq = nnp - np;
    for ( j = 1; j <= i; j++ )
    {
      ip = ( ii * ( ii - 1 ) ) / 2;
      c = 0.0;
      for ( k = i; k <= np; k++ )
      {
        ip = ip + 1;
        nq = nq + 1;
        c = c + sa[ip-1] * sa[nq-1];
      }
      sa[nq-1] = c / rn;
      nq = nq - 2 * np + i + j - 1;
    }
  }

  free ( sb );

  return sa;
}

