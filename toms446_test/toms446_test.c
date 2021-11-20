# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "toms446.h"

int main ( );
void cheby_test ( );
void dfrnt_test ( );
void echeb_test ( );
void edcheb_test ( );
void mltply_test ( );
void ntgrt_test ( );
double *functn ( double x );
double *functn_d ( double x );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TOMS446_TEST.

  Discussion:

    TOMS446_TEST tests the TOMS446 library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TOMS446_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TOMS446 library.\n" );

  cheby_test ( );
  dfrnt_test ( );
  echeb_test ( );
  edcheb_test ( );
  mltply_test ( );
  ntgrt_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TOMS446_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void cheby_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBY_TEST tests CHEBY, which computes Chebyshev series.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int nf = 5;
  int npl = 10;
  double *x;

  printf ( "\n" );
  printf ( "CHEBY_TEST\n" );
  printf ( "  CHEBY computes the Chebyshev series for several functions.\n" );

  x = cheby ( nf, npl, functn );

  printf ( "\n" );
  printf ( "          Sin(x)          Cos(x)        Sin(2x)         Cos(2x)           X^5\n" );
  printf ( "\n" );

  for ( i = 0; i < npl; i++ )
  {
    for ( j = 0; j < nf; j++ )
    {
      printf ( "  %14f", x[i+j*npl] );
    }
    printf ( "\n" );
  }
  free ( x );

  return;
}
/******************************************************************************/

void mltply_test ( )

/******************************************************************************/
/*
  Purpose:

    MLTPLY_TEST tests MLTPLY, which multiplies two Chebyshev series.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  int i;
  int nf = 5;
  int npl = 10;
  double *x;
  double *x1;
  double *x2;
  double *x3;

  printf ( "\n" );
  printf ( "MLTPLY_TEST\n" );
  printf ( "  MLTPLY computes the product of two Chebyshev series.\n" );
  printf ( "\n" );
  printf ( "  Multiply series for SIN(X) and COS(X)\n" );
  printf ( "  and compare with series for 1/2*SIN(2X).\n" );

  x = cheby ( nf, npl, functn );

  x1 = ( double * ) malloc ( npl * sizeof ( double ) );
  x2 = ( double * ) malloc ( npl * sizeof ( double ) );

  for ( i = 0; i < npl; i++ )
  {
    x1[i] = x[i+0*npl];
    x2[i] = x[i+1*npl];
    x[i+2*npl] = 0.5 * x[i+2*npl];
  }
  x3 = mltply_new ( x1, x2, npl );

  printf ( "\n" );
  printf ( "          Sin(x)          Cos(x)       1/2*Sin(2x)         RESULT\n" );
  printf ( "\n" );

  for ( i = 0; i < npl; i++ )
  {
    printf ( "  %14g  %14g  %14g  %14g\n", x[i+0*npl], x[i+1*npl], x[i+2*npl], x3[i] );
  }
  free ( x );
  free ( x1 );
  free ( x2 );
  free ( x3 );

  return;
}
/******************************************************************************/

void echeb_test ( )

/******************************************************************************/
/*
  Purpose:

    ECHEB_TEST tests ECHEB, which evaluates a Chebyshev series.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  double fval;
  double *fxj;
  int i;
  int j;
  int k;
  int nf = 5;
  int npl = 10;
  int nx;
  double *x;
  double *x2;
  double xval;

  nx = 6;

  printf ( "\n" );
  printf ( "ECHEB_TEST\n" );
  printf ( "  ECHEB evaluates a Chebyshev series.\n" );

  x = cheby ( nf, npl, functn );
  x2 = ( double * ) malloc ( npl * sizeof ( double ) );

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }

    printf ( "\n" );
    if ( j == 0 )
    {
      printf ( "  Sin(x)\n" );
    }
    else if ( j == 1 )
    {
      printf ( "  Cos(x)\n" );
    }
    else if ( j == 2 )
    {
      printf ( "  Sin(2x)\n" );
    }
    else if ( j == 3 )
    {
      printf ( "  Cos(2x)\n" );
    }
    else if ( j == 4 )
    {
      printf ( "  x^5\n" );
    }

    printf ( "\n" );

    for ( k = 0; k < nx; k++ )
    {
      xval = 2.0 * ( double ) ( k ) / ( double ) ( nx - 1 ) - 1.0;

      fxj = functn ( xval );

      fval = echeb ( xval, x2, npl );

      printf ( "  %14g  %14g  %14g\n", xval, fxj[j], fval );
      free ( fxj );
    }
  }
  free ( x );
  free ( x2 );

  return;
}
/******************************************************************************/

void edcheb_test ( )

/******************************************************************************/
/*
  Purpose:

    EDCHEB_TEST tests EDCHEB, which evaluates the derivative of a Chebyshev series.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  double fval;
  double *fxj;
  int i;
  int j;
  int k;
  int nf = 5;
  int npl = 10;
  int nx;
  double *x;
  double *x2;
  double xval;

  nx = 6;

  printf ( "\n" );
  printf ( "EDCHEB_TEST\n" );
  printf ( "  EDCHEB evaluates the derivative of a Chebyshev series.\n" );

  x = cheby ( nf, npl, functn );
  x2 = ( double * ) malloc ( npl * sizeof ( double ) );

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }

    printf ( "\n" );
    if ( j == 0 )
    {
      printf ( "  Sin(x)\n" );
    }
    else if ( j == 1 )
    {
      printf ( "  Cos(x)\n" );
    }
    else if ( j == 2 )
    {
      printf ( "  Sin(2x)\n" );
    }
    else if ( j == 3 )
    {
      printf ( "  Cos(2x)\n" );
    }
    else if ( j == 4 )
    {
      printf ( "  x^5\n" );
    }

    printf ( "\n" );

    for ( k = 0; k < nx; k++ )
    {
      xval = 2.0 * ( double ) ( k ) / ( double ) ( nx - 1 ) - 1.0;

      fxj = functn_d ( xval );

      fval = edcheb ( xval, x2, npl );

      printf ( "  %14g  %14g  %14g\n", xval, fxj[j], fval );
      free ( fxj );
    }
  }
  free ( x );
  free ( x2 );

  return;
}
/******************************************************************************/

void dfrnt_test ( )

/******************************************************************************/
/*
  Purpose:

    DFRNT_TEST tests DFRNT, which computes the Chebyshev series of a derivative.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int nf = 5;
  int npl = 10;
  double *x;
  double *x2;
  double *x3;

  printf ( "\n" );
  printf ( "DFRNT_TEST\n" );
  printf ( "  DFRNT computes the Chebyshev series for the derivative\n" );
  printf ( "  of several functions.\n" );

  x = cheby ( nf, npl, functn );
  x2 = ( double * ) malloc ( npl * sizeof ( double ) );

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }
    x3 = dfrnt ( x2, npl );
    for ( i = 0; i < npl; i++ )
    {
      x[i+j*npl] = x3[i];
    }
    free ( x3 );
  }

  printf ( "\n" );
  printf ( "  Chebyshev series for d/dx of:\n" );
  printf ( "\n" );
  printf ( "        Sin(x)      Cos(x)    Sin(2x)     Cos(2x)       X^5\n" );
  printf ( "\n" );

  for ( i = 0; i < npl; i++ )
  {
    for ( j = 0; j < nf; j++ )
    {
      printf ( "  %14g", x[i+j*npl] );
    }
    printf ( "\n" );
  }

  free ( x );
  free ( x2 );

  return;
}
/******************************************************************************/

void ntgrt_test ( )

/******************************************************************************/
/*
  Purpose:

    NTGRT_TEST tests NTGRT, which computes the Chebyshev series of an indefinite integral.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int nf = 5;
  int npl = 10;
  double *x;
  double *x2;
  double *x3;

  printf ( "\n" );
  printf ( "NTGRT_TEST\n" );
  printf ( "  NTGRT computes the Chebyshev series for the indefinite\n" );
  printf ( "  integral of several functions.\n" );

  x = cheby ( nf, npl, functn );
  x2 = ( double * ) malloc ( npl * sizeof ( double ) );

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }
    x3 = ntgrt ( x2, npl );
    for ( i = 0; i < npl; i++ )
    {
      x[i+j*npl] = x3[i];
    }
    free ( x3 );
  }

  printf ( "\n" );
  printf ( "  Chebyshev series for indefinite integral of:\n" );
  printf ( "\n" );
  printf ( "        Sin(x)      Cos(x)    Sin(2x)     Cos(2x)       X^5\n" );
  printf ( "\n" );

  for ( i = 0; i < npl; i++ )
  {
    for ( j = 0; j < nf; j++ )
    {
      printf ( "  %14g", x[i+j*npl] );
    }
    printf ( "\n" );
  }
  free ( x );
  free ( x2 );

  return;
}
/******************************************************************************/

double *functn ( double x )

/******************************************************************************/
/*
  Purpose:

    FUNCTN evaluates several functions at X.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, double X, the evaluation point.

    Output, double FXJ[5], the derivative values.
*/
{
  double *fxj;
  
  fxj = ( double * ) malloc ( 5 * sizeof ( double ) );

  fxj[0] = sin ( x );
  fxj[1] = cos ( x );
  fxj[2] = sin ( 2.0 * x );
  fxj[3] = cos ( 2.0 * x );
  fxj[4] = pow ( x, 5 );

  return fxj;
}
/******************************************************************************/

double *functn_d ( double x )

/******************************************************************************/
/*
  Purpose:

    FUNCTN_D evaluates the derivatives of several functions at X.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, double X, the evaluation point.

    Output, double FXJ[5], the derivative values.
*/
{
  double *fxj;

  fxj = ( double * ) malloc ( 5 * sizeof ( double ) );

  fxj[0] =  cos ( x );
  fxj[1] = -sin ( x );
  fxj[2] =  2.0 * cos ( 2.0 * x );
  fxj[3] = -2.0 * sin ( 2.0 * x );
  fxj[4] =  5.0 * pow ( x, 4 );

  return fxj;
}
