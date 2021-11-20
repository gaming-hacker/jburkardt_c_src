# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "minpack.h"

int main ( );
void chkder_test ( );
void chkder_f ( int n, double x[], double fvec[], double fjac[], int ldfjac,
  int iflag );
void hybrd1_test ( );
void hybrd1_f ( int n, double x[], double fvec[], int *iflag );
void qform_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    minpack_test() tests minpack().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "minpack_test():\n" );
  printf ( "  C version:\n" );
  printf ( "  Test minpack().\n" );

  chkder_test ( );
  hybrd1_test ( );
  qform_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "minpack_test()\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void chkder_test ( )

/******************************************************************************/
/*
  Purpose:

    chkder_test() tests chkder().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt
*/
{
  double *err;
  double *fjac;
  double *fvec;
  double *fvecp;
  int i;
  int ido;
  int iflag;
  int j;
  int ldfjac;
  int m;
  int mode;
  int n;
  int seed;
  double *x;
  double *xp;

  m = 5;
  n = 5;
  ldfjac = n;
  err = ( double * ) malloc ( m * sizeof ( double ) );
  fjac = ( double * ) malloc ( ldfjac * n * sizeof ( double ) );
  fvec = ( double * ) malloc ( m * sizeof ( double ) );
  fvecp = ( double * ) malloc ( m * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  xp = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "chkder_test():\n" );
  printf ( "  chkder() compares a user supplied jacobian\n" );
  printf ( "  and a finite difference approximation to it\n" );
  printf ( "  and judges whether the jacobian is correct.\n" );

  for ( ido = 1; ido <= 2; ido++ )
  {
    seed = 123456789;
    if ( ido == 1 )
    {
      printf ( "\n" );
      printf ( "  On the first test, use a correct jacobian.\n" );
    }
    else if ( ido == 2 )
    {
       printf ( "\n" );
       printf ( "  Repeat the test, but use a bad jacobian\n" );
       printf ( "  and see if the routine notices.\n" );
    }
/*
  Set the point at which the test is to be made:
*/
    for ( i = 0; i < n; i++ )
    {
      x[i] = r8_uniform_01 ( &seed );
    }

    printf ( "\n" );
    printf ( "  Evaluation point X:\n" );
    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %14f\n", x[i] );
    }

    mode = 1;
    chkder ( m, n, x, fvec, fjac, ldfjac, xp, fvecp, mode, err );

    iflag = 1;
    chkder_f ( n, x, fvec, fjac, ldfjac, iflag );
    chkder_f ( n, xp, fvecp, fjac, ldfjac, iflag );

    printf ( "\n" );
    printf ( "  Sampled function values F(X) and F(XP)\n" );
    printf ( "\n" );
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %8d  %14f  %14f\n", i, fvec[i], fvecp[i] );
    }
    iflag = 2;
    chkder_f ( n, x, fvec, fjac, ldfjac, iflag );
/*
  Here's where we put a mistake into the jacobian, on purpose.
*/
    if ( ido == 2 )
    {
      fjac[0+0*ldfjac] = 1.01 * fjac[0+0*ldfjac];
      fjac[1+2*ldfjac] = - fjac[1+2*ldfjac];
    }

    printf ( "\n" );
    printf ( "  Computed jacobian:\n" );
    printf ( "\n" );
    for ( i = 0; i < m; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        printf ( "  %14f", fjac[i+j*ldfjac] );
      }
      printf ( "\n" );
    }

    mode = 2;
    chkder ( m, n, x, fvec, fjac, ldfjac, xp, fvecp, mode, err );

    printf ( "\n" );
    printf ( "  chkder() gradient component error estimates:\n" );
    printf ( "     > 0.5, the component is probably correct.\n" );
    printf ( "     < 0.5, the component is probably incorrect.\n" );
    printf ( "\n" );
    for ( i = 0; i < m; i++ )
    {
      printf ( "  %8d  %14f\n", i, err[i] );
    }
  }
/*
  Free memory.
*/
  free ( err );
  free ( fjac );
  free ( fvec );
  free ( fvecp );
  free ( x );
  free ( xp );

  return;
}
/******************************************************************************/

void chkder_f ( int n, double x[], double fvec[], double fjac[], int ldfjac,
  int iflag )

/******************************************************************************/
/*
  Purpose:

    chkder_f() is a function/jacobian routine for the chkder() test.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt

  Input:

    int N, the number of variables.

    double X[N], the variable values.

    int LDFJAC, the leading dimension of FJAC, which must
    be at least N.

    int IFLAG:
    1, please compute F(I) (X).
    2, please compute FJAC(I,J) (X).

  Output:

    double FVEC[N], the function values at X, if IFLAG = 1.

    double FJAC[LDFJAC*N], the N by N jacobian at X, if IFLAG = 2.
*/
{
  int i;
  int j;
  double x_prod;
  double x_sum;
/*
  If IFLAG is 1, we are supposed to evaluate F(X).
*/
  if ( iflag == 1 )
  {
    x_sum = 0.0;
    x_prod = 1.0;
    for ( i = 0; i < n; i++ )
    {
      x_sum = x_sum + x[i];
      x_prod = x_prod * x[i];
    }

    for ( i = 0; i < n - 1; i++ )
    {
      fvec[i] = x[i] - ( double ) ( n + 1 ) + x_sum;
    }
    fvec[n-1] = x_prod - 1.0;
  }
/*
  If IFLAG is 2, we are supposed to evaluate FJAC(I,J) = d F(I)/d X(J)
*/
  else if ( iflag == 2 )
  {
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n - 1; i++ )
      {
        fjac[i+j*ldfjac] = 1.0;
      }
    }
    for ( i = 0; i < n - 1; i++ )
    {
      fjac[i+i*ldfjac] = 2.0;
    }
    x_prod = 1.0;
    for ( i = 0; i < n; i++ )
    {
      x_prod = x_prod * x[i];
    }
    for ( j = 0; j < n; j++ )
    {
      fjac[n-1+j*ldfjac] = x_prod / x[j];
    }
  }

  return;
}
/******************************************************************************/

void hybrd1_test ( )

/******************************************************************************/
/*
  Purpose:

    hybrd1_test () tests hybrd1().

  Discussion:

    This is an example of what your main program would look
    like if you wanted to use MINPACK to solve N nonlinear equations
    in N unknowns.  In this version, we avoid computing the jacobian
    matrix, and request that MINPACK approximate it for us.

    The set of nonlinear equations is:

      x1 * x1 - 10 * x1 + x2 * x2 + 8 = 0
      x1 * x2 * x2 + x1 - 10 * x2 + 8 = 0

    with solution x1 = x2 = 1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt
*/
{
  double *fvec;
  int iflag;
  int info;
  int lwa;
  int n = 2;
  double tol = 0.00001;
  double *wa;
  double *x;

  lwa = ( n * ( 3 * n + 13 ) ) / 2;
  fvec = ( double * ) malloc ( n * sizeof ( double ) );
  wa = ( double * ) malloc ( lwa * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "hybrd1_test():\n" );
  printf ( "  hybrd1() solves a nonlinear system of equations.\n" );

  x[0] = 3.0;
  x[1] = 0.0;
  r8vec_print ( n, x, "  Initial X" );
  iflag = 1;
  hybrd1_f ( n, x, fvec, &iflag );

  r8vec_print ( n, fvec, "  F(X)" );

  info = hybrd1 ( hybrd1_f, n, x, fvec, tol, wa, lwa );

  printf ( "\n" );
  printf ( "  Returned value of INFO = %d", info );
  r8vec_print ( n, x, "  X" );
  r8vec_print ( n, fvec, "  F(X)" );
/*
  Free memory.
*/
  free ( fvec );
  free ( wa );
  free ( x );

  return;
}
/******************************************************************************/

void hybrd1_f ( int n, double x[], double fvec[], int *iflag )

/******************************************************************************/
/*
  Purpose:

    hybrd1_f() is a function routine for use with hybrd1_test().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt

  Input:

    int N, the number of variables.

    double X[N], the variable values.

  Output:

    double FVEC[N], the function values.

    int *IFLAG, is nonzero if the evaluation failed.
*/
{
  fvec[0] = x[0] * x[0] - 10.0 * x[0] + x[1] * x[1] + 8.0;
  fvec[1] = x[0] * x[1] * x[1] + x[0] - 10.0 * x[1] + 8.0;
  *iflag = 0;

  return;
}
/******************************************************************************/

void qform_test ( )

/******************************************************************************/
/*
  Purpose:

    qform_test() tests qform().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2021

  Author:

    John Burkardt
*/
{
  double *a;
  double *a2;
  double *acnorm;
  int i;
  int *ipivot;
  int j;
  int k;
  int lda = 5;
  int lipvt;
  int m = 5;
  int n = 7;
  bool pivot;
  double *q;
  double *r;
  double *rdiag;
  int seed;

  printf ( "\n" );
  printf ( "qform_test():\n" );
  printf ( "  qform() constructs the Q factor explicitly after qrfac().\n" );
/*
  Set the matrix A.
*/
  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  seed = 123456789;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = r8_uniform_01 ( &seed );
    }
  }
  r8mat_print ( m, n, a, "  Matrix A:" );
/*
  Compute the QR factors.
*/
  pivot = false;
  ipivot = ( int * ) malloc ( n * sizeof ( int ) );
  lipvt = n;
  rdiag = ( double * ) malloc ( n * sizeof ( double ) );
  acnorm = ( double * ) malloc ( n * sizeof ( double ) );

  qrfac ( m, n, a, lda, pivot, ipivot, lipvt, rdiag, acnorm );
/*
  Extract the R factor.
*/
  r = ( double * ) malloc ( m * n * sizeof ( double ) );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      r[i+j*m] = 0.0;
    }
  }

  for ( k = 0; k < i4_min ( m, n ); k++ )
  {
    r[k+k*m] = rdiag[k];
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < i4_min ( j, m ); i++ )
    {
      r[i+j*m] = a[i+j*m];
    }
  }
  r8mat_print ( m, n, r, "  Matrix R:" );
/*
  Call QRFORM to form the Q factor.
*/
  q = ( double * ) malloc ( m * m * sizeof ( double ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      q[i+j*m] = 0.0;
    }
  }

  for ( j = 0; j < i4_min ( m, n ); j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      q[i+j*m] = a[i+j*m];
    }
  }
  qform ( m, n, q, m );

  r8mat_print ( m, m, q, "  Matrix Q:" );
/*
  Compute Q*R.
*/
  a2 = r8mat_mm_new ( m, m, n, q, r );
/*
  Compare Q*R to A.
*/
  r8mat_print ( m, n, a2, "  Matrix A2 = Q * R:" );
/*
  Free memory.
*/
  free ( a );
  free ( a2 );
  free ( acnorm );
  free ( ipivot );
  free ( q );
  free ( r );
  free ( rdiag );

  return;
}

