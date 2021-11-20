# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "pdflib.h"
# include "rnglib.h"

int main ( );
void i4_binomial_pdf_test ( );
void i4_binomial_sample_test ( );
void i4_uniform_sample_test ( );
void r8_chi_sample_test ( );
void r8po_fa_test ( );
void r8vec_multinormal_pdf_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PDFLIB_TEST.

  Discussion:

    PDFLIB_TEST tests the PDFLIB library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 January 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "PDFLIB_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the PDFLIB library.\n" );

  i4_binomial_pdf_test ( );
  i4_binomial_sample_test ( );
  i4_uniform_sample_test ( );
  r8_chi_sample_test ( );
  r8po_fa_test ( );
  r8vec_multinormal_pdf_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "PDFLIB_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void i4_binomial_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_BINOMIAL_PDF_TEST calls I4_BINOMIAL_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 January 2018

  Author:

    John Burkardt
*/
{
  int k;
  int n;
  double p;
  double prob;

  initialize ( );

  printf ( "\n" );
  printf ( "I4_BINOMIAL_PDF_TEST\n" );
  printf ( "  I4_BINOMIAL_PDF reports\n" );
  printf ( "  PROB, the probability that\n" );
  printf ( "  N trials, with\n" );
  printf ( "  P probability of success result in\n" );
  printf ( "  K successes.\n" );
  printf ( "\n" );
  printf ( "   N         P   K         PDF\n" );
  printf ( "\n" );

  n = 5;
  p = 0.25;
 
  for ( k = 0; k <= n; k++ )
  {
    prob = i4_binomial_pdf ( n, p, k );
    printf ( "  %2d  %8.4f  %2d  %14.6f\n", n, p, k, prob );
  }

  return;
}
/******************************************************************************/

void i4_binomial_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_BINOMIAL_SAMPLE_TEST calls I4_BINOMIAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 January 2018

  Author:

    John Burkardt
*/
{
  int i;
  int k;
  int n;
  double p;
  double pdf;

  initialize ( );

  printf ( "\n" );
  printf ( "I4_BINOMIAL_SAMPLE_TEST\n" );
  printf ( "  I4_BINOMIAL_SAMPLE samples the binomial distribution.\n" );
  printf ( "\n" );
  printf ( "   N         P   K        PDF\n" );
  printf ( "\n" );
 
  for ( i = 1; i <= 10; i++ )
  {
    n = i4_uniform_sample ( 1, 20 );
    p = r8_uniform_sample ( 0.0, 1.0 );
    k = i4_binomial_sample ( n, p );
    pdf = i4_binomial_pdf ( n, p, k );
    printf ( "  %2d  %8.4f  %2d  %14.6f\n", n, p, k, pdf );
  }

  return;
}
/******************************************************************************/

void i4_uniform_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_UNIFORM_SAMPLE_TEST calls I4_UNIFORM_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 January 2018

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int c;
  int i;

  initialize ( );

  printf ( "\n" );
  printf ( "I4_UNIFORM_SAMPLE_TEST\n" );
  printf ( "  I4_UNIFORM_SAMPLE samples the uniform distribution on integers.\n" );
  printf ( "  Generate integer C between limits A and B.\n" );
  printf ( "\n" );
  printf ( "    A    B   C\n" );
  printf ( "\n" );
 
  for ( i = 1; i <= 10; i++ )
  {
    a = i4_uniform_sample ( -10, +10 );
    b = i4_uniform_sample ( a, 20 );
    c = i4_uniform_sample ( a, b );
    printf ( "  %3d  %3d  %3d\n", a, b, c );
  }

  return;
}
/******************************************************************************/

void r8_chi_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CHI_SAMPLE_TEST calls R8_CHI_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 August 2013

  Author:

    John Burkardt
*/
{
  double df;
  int g;
  int i;
  double u;

  initialize ( );

  printf ( "\n" );
  printf ( "R8_CHI_SAMPLE_TEST\n" );
  printf ( "  R8_CHI_SAMPLE ( DF ) samples the Chi distribution with\n" );
  printf ( "  DF degrees of freedom.\n" );
/*
  Set the current generator index to #2 (which, this being C, has index 1!).
*/
  g = 1;
  cgn_set ( g );
  printf ( "\n" );
  printf ( "  Current generator index = %d\n", g );
/*
  Repeatedly call R8_CHI_SAMPLE ( DF ).
*/
  printf ( "\n" );
  printf ( "   I       DF       R8_CHI_SAMPLE ( DF )\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    df = 5.0 * r8_uniform_01_sample ( ) + 1.0;
    u = r8_chi_sample ( df );
    printf ( "  %2d  %14.6g  %14.6g\n", i, df, u );
  }

  return;
}
/******************************************************************************/

void r8po_fa_test ( )

/******************************************************************************/
/*
  Purpose:

    R8PO_FA_TEST tests R8PO_FA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 June 2013

  Author:

    John Burkardt
*/
{
  double *a;
  double diff;
  int i;
  int j;
  int n = 5;
  double *r1;
  double *r2;

  initialize ( );

  printf ( "\n" );
  printf ( "R8PO_FA_TEST\n" );
  printf ( "  R8PO_FA computes the Cholesky factor R of a\n" );
  printf ( "  positive definite matrix A, so that A = R' * R.\n" );
  printf ( "\n" );
  printf ( "  Start with random R1;\n" );
  printf ( "  Compute A = R1' * R1.\n" );
  printf ( "  Call R8PO_FA and see if you recover R2 = R1.\n" );
/*
  Generate a random upper triangular matrix with positive diagonal.
*/
  r1 = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      r1[i+j*n] = r8_uniform_01_sample ( );
    }
    for ( i = j + 1; i < n; i++ )
    {
      r1[i+j*n] = 0.0;
    }
  }
  r8ge_print ( n, n, r1, "  R1:" );
/*
  Compute a positive definite symmetric matrix A.
*/
  a = r8ge_mtm ( n, r1, r1 );

  r8ge_print ( n, n, a, "  A:" );

  r2 = r8po_fa ( n, a );

  diff = r8mat_norm_fro_affine ( n, n, r1, r2 );

  printf ( "\n" );
  printf ( "  Frobenius difference between R1 and R2 = %g\n", diff );

  free ( a );
  free ( r1 );
  free ( r2 );

  return;
}
/******************************************************************************/

void r8vec_multinormal_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MULTINORMAL_PDF_TEST tests R8VEC_MULTINORMAL_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 June 2013

  Author:

    John Burkardt
*/
{
  double *c;
  double c_det;
  double *c_inv;
  double eps;
  int i;
  int j;
  double *mu;
  int n = 5;
  double pdf1;
  double pdf2;
  const double r8_pi = 3.141592653589793;
  double *r1;
  double *r2;
  double *x;
  double xcx;
  double *y;

  initialize ( );

  printf ( "\n" );
  printf ( "R8VEC_MULTINORMAL_PDF_TEST\n" );
  printf ( "  R8VEC_MULTINORMAL_PDF evaluates the PDF for the\n" );
  printf ( "  multinormal distribution.\n" );
  printf ( "\n" );
  printf ( "  The covariance matrix is C.\n" );
  printf ( "  The definition uses the inverse of C;\n" );
  printf ( "  R8VEC_MULTINORMAL_PDF uses the Cholesky factor.\n" );
  printf ( "  Verify that the algorithms are equivalent.\n" );
/*
  Generate a random upper triangular matrix with positive diagonal.
*/
  r1 = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      r1[i+j*n] = r8_uniform_01_sample ( );
    }
    for ( i = j + 1; i < n; i++ )
    {
      r1[i+j*n] = 0.0;
    }
  }
  r8ge_print ( n, n, r1, "  R1:" );
/*
  Compute a positive definite symmetric matrix C.
*/
  c = r8ge_mtm ( n, r1, r1 );
  r8ge_print ( n, n, c, "  C:" );
/*
  Compute the Cholesky factor.
*/
  r2 = r8mat_pofac ( n, c );
  r8ge_print ( n, n, r2, "  R2:" );
/*
  Compute the determinant of C.
*/
  c_det = r8mat_podet ( n, r2 );
  printf ( "\n" );
  printf ( "  Determinant of C = %g\n", c_det );
/*
  Compute the inverse of C.
*/
  c_inv = r8mat_poinv ( n, r2 );
  r8ge_print ( n, n, c_inv, "  C_INV:" );
/*
  Compute a random set of means.
*/
  mu = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    mu[i] = r8_normal_01_sample ( );
  }
/*
  Compute X as small variations from MU.
*/
  x = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    eps = 0.01 * r8_normal_01_sample ( );
    x[i] = ( 1.0 + eps ) * mu[i];
  }
/*
  Compute PDF1 from the function.
*/
  pdf1 = r8vec_multinormal_pdf ( n, mu, r2, c_det, x );
/*
  Compute PDF2 from the definition.
*/
  y = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    y[i] = x[i] - mu[i];
  }

  xcx = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i <= j )
      {
        xcx = xcx + y[i] * c_inv[i+j*n] * y[j];
      }
      else
      {
        xcx = xcx + y[i] * c_inv[j+i*n] * y[j];
      }
    }
  }

  pdf2 = 1.0 / sqrt ( pow ( 2.0 * r8_pi, n ) ) 
    * 1.0 / sqrt ( c_det ) 
    * exp ( - 0.5 * xcx );

  printf ( "\n" );
  printf ( "  PDF1 = %g\n", pdf1 );
  printf ( "  PDF2 = %g\n", pdf2 );
/*
  Free memory.
*/
  free ( c );
  free ( c_inv );
  free ( mu );
  free ( r1 );
  free ( r2 );
  free ( x );
  free ( y );

  return;
}
