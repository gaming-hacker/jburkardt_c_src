# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "asa082.h"

int main ( );
void detq_test ( );
double *helmert_matrix ( int n );
double helmert_determinant ( int n );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for asa082_test.

  Discussion:

    asa082_test tests asa082.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 January 2020

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "asa082_test\n" );
  printf ( "  C version\n" );
  printf ( "  asa082 computes the determinant of\n" );
  printf ( "  an orthogonal matrix.\n" );

  detq_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "asa082_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void detq_test ( )

/******************************************************************************/
/*
  Purpose:

    detq_test tests detq.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 January 2020

  Author:

    John Burkardt
*/
{
  double *a;
  double d1;
  double d2;
  int ifault;
  int n;

  for ( n = 5; n <= 10; n++ )
  {
    a = helmert_matrix ( n );
    printf ( "\n" );
    printf ( "  Helmert matrix of order %d\n", n );
    if ( 0 )
    {
      r8mat_print ( n, n, a, "  Helmert matrix:" );
    }
    d1 = helmert_determinant ( n );
    printf ( "  determinant =      %g\n", d1 );
    detq ( a, n, &d2, &ifault );
    if ( ifault == 1 )
    {
      printf ( "  DETQ failed for this case.\n" );
    }
    else
    {
      printf ( "  DETQ determinant = %g\n", d2 );
    }
    free ( a );
  }

  return;
}
/******************************************************************************/

double *helmert_matrix ( int n )

/******************************************************************************/
/*
  Purpose:

    helmert_matrix returns the HELMERT matrix.

  Formula:

    If I = 1 then
      A(I,J) = 1 / sqrt ( N )
    else if J < I then
      A(I,J) = 1 / sqrt ( I * ( I - 1 ) )
    else if J = I then
      A(I,J) = (1-I) / sqrt ( I * ( I - 1 ) )
    else
      A(I,J) = 0

  Discussion:

    The matrix given above by Helmert is the classic example of
    a family of matrices which are now called Helmertian or
    Helmert matrices.

    A matrix is a (standard) Helmert matrix if it is orthogonal,
    and the elements which are above the diagonal and below the
    first row are zero.

    If the elements of the first row are all strictly positive,
    then the matrix is a strictly Helmertian matrix.

    It is possible to require in addition that all elements below
    the diagonal be strictly positive, but in the reference, this
    condition is discarded as being cumbersome and not useful.

    A Helmert matrix can be regarded as a change of basis matrix
    between a pair of orthonormal coordinate bases.  The first row
    gives the coordinates of the first new basis vector in the old
    basis.  Each later row describes combinations of (an increasingly
    extensive set of) old basis vectors that constitute the new
    basis vectors.

    Helmert matrices have important applications in statistics.

  Example:

    N = 5

    0.4472    0.4472    0.4472    0.4472    0.4472
    0.7071   -0.7071         0         0         0
    0.4082    0.4082   -0.8165         0         0
    0.2887    0.2887    0.2887   -0.8660         0
    0.2236    0.2236    0.2236    0.2236   -0.8944

  Properties:

    A is generally not symmetric: A' /= A.

    A is orthogonal: A' * A = A * A' = I.

    Because A is orthogonal, it is normal: A' * A = A * A'.

    A is not symmetric: A' /= A.

    det ( A ) = (-1)^(N+1)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2008

  Author:

    John Burkardt

  Reference:

    HO Lancaster,
    The Helmert Matrices,
    American Mathematical Monthly,
    Volume 72, 1965, pages 4-12.

  Parameters:

    Input, int N, the order of the matrix.

    Output, double HELMERT[N*N], the matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( n * n * sizeof ( double ) );
/*
  A begins with the first row, diagonal, and lower triangle set to 1.
*/
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        a[i+j*n] = 1.0 / sqrt ( ( double ) ( n ) );
      }
      else if ( j < i )
      {
        a[i+j*n] = 1.0 / sqrt ( ( double ) ( i * ( i + 1 ) ) );
      }
      else if ( i == j )
      {
        a[i+j*n] = - sqrt ( ( double ) ( i     ) )
                   / sqrt ( ( double ) ( i + 1 ) );
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

double helmert_determinant ( int n )

/******************************************************************************/
/*
  Purpose:

    HELMERT_DETERMINANT returns the determinant of the HELMERT matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Output, double HELMERT_DETERMINANT, the determinant.
*/
{
  double determ;

  if ( ( n % 2 ) == 0 )
  {
    determ = -1.0;
  }
  else
  {
    determ = +1.0;
  }

  return determ;
}
