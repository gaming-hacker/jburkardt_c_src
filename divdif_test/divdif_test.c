# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "divdif.h"

int main ( );
void test01 ( );
void test02 ( );
void dif_basis_test ( );
void test05 ( );
void test06 ( );
void r8poly_basis_test ( );
void r8poly_shift_test ( );
void ncc_rule_test ( );
void nco_rule_test ( );
void test18 ( );
void roots_to_r8poly_test ( );
void dif_derivk_table_test ( );
void dif_basis_deriv_test ( );
void dif_basis_derivk_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for divdif_test.

  Discussion:

    DIVDIF_TEST tests DIVDIF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 October 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "divdif_test:\n" );
  printf ( "  C version\n" );
  printf ( "  Test DIVDIF.\n" );

  test01 ( );
  test02 ( );

  dif_basis_test ( );

  test05 ( );
  test06 ( );

  r8poly_basis_test ( );
  r8poly_shift_test ( );
  ncc_rule_test ( );
  nco_rule_test ( );

  test18 ( );

  roots_to_r8poly_test ( );
  dif_derivk_table_test ( );
  dif_basis_deriv_test ( );
  dif_basis_derivk_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "DIVDIF_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests DIF*;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 June 2013

  Author:

    John Burkardt
*/
{
# define MAXTAB 10

  double diftab[MAXTAB];
  double diftab2[MAXTAB];
  double diftab3[MAXTAB];
  int i;
  int ntab;
  int ntab2;
  int ntab3;
  double xtab[MAXTAB];
  double xtab2[MAXTAB];
  double xtab3[MAXTAB];
  double xval;
  double ytab[MAXTAB];
  double yval;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  DATA_TO_DIF_DISPLAY sets up a difference table\n" );
  printf ( "  and displays intermediate calculations;\n" );
  printf ( "  DIF_APPEND appends a new data point;\n" );
  printf ( "  DIF_ANTIDERIV computes the antiderivative;\n" );
  printf ( "  DIF_DERIV_TABLE computes the derivative;\n" );
  printf ( "  DIF_SHIFT_ZERO shifts all the abscissas to 0;\n" );
  printf ( "  DIF_VAL evaluates at a point;\n" );
  printf ( "\n" );
/*
  Set XTAB, YTAB to X, X^2.
*/
  ntab = 4;

  for ( i = 0; i < ntab; i++ )
  {
    xtab[i] = ( double ) ( i + 1 );
    ytab[i] = xtab[i] * xtab[i];
  }

  data_to_dif_display ( ntab, xtab, ytab, diftab );

  dif_print ( ntab, xtab, diftab, "  The divided difference polynomial:" );
/*
  Add (5,25) to the table.
*/
  printf ( "\n" );
  printf ( "  DIF_APPEND can add the data (5,25) to the table.\n" );
  printf ( "\n" );

  xval = 5.0;
  yval = 25.0;

  dif_append ( ntab, xtab, diftab, xval, yval, &ntab, xtab, diftab );

  dif_print ( ntab, xtab, diftab,
    "  The updated divided difference polynomial:" );
/*
  Evaluate the polynomial at 2.5.
*/
  printf ( "\n" );
  printf ( "  DIF_VAL can evaluate the table at a point.\n" );
  printf ( "\n" );

  xval = 2.5;

  yval = dif_val ( ntab, xtab, diftab, xval );

  printf ( "\n" );
  printf ( "  DIF_VAL reports P(%f) = %f\n", xval, yval );
/*
  Shift the base to zero.
*/
  dif_shift_zero ( ntab, xtab, diftab );

  dif_print ( ntab, xtab, diftab,
    "  The divided difference table after DIF_SHIFT_ZERO:" );
/*
  Compute a table for the derivative.
*/
  ntab2 = ntab - 1;
  dif_deriv_table ( ntab, xtab, diftab, xtab2, diftab2 );

  dif_print ( ntab2, xtab2, diftab2,
    "  The divided difference table for the derivative:" );

  yval = dif_val ( ntab2, xtab2, diftab2, xval );

  printf ( "\n" );
  printf ( "  DIF_VAL reports P'(%f) = %f\n", xval, yval );
/*
  Compute the antiderivative.
*/
  dif_antideriv ( ntab, xtab, diftab, &ntab3, xtab3, diftab3 );

  dif_print ( ntab3, xtab3, diftab3,
    "  The divided difference table for the antiderivative:" );

  yval = dif_val ( ntab3, xtab3, diftab3, xval );

  printf ( "\n" );
  printf ( "  DIF_VAL reports (Anti)P(%f) = %f\n", xval, yval );

  return;
# undef MAXTAB
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests DATA_TO_DIF and DIF_VAL.

  Discussion:

    This routine demonstrates how divided difference approximation 
    improves with N.

    Evaluate these polynomials at 2.5.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define MAXTAB 8

  double diftab[MAXTAB];
  double error;
  int j;
  int ntab;
  double true_value;
  double xtab[MAXTAB];
  double xval;
  double ytab[MAXTAB];
  double yval;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Approximate Y = EXP(X) using orders 1 to %d.\n", MAXTAB );

  printf ( "\n" );
  printf ( "  Original data:\n" );
  printf ( "\n" );
  printf ( "       X          Y\n" );
  printf ( "\n" );
  for ( j = 0; j < MAXTAB; j++ )
  {
    xtab[j] = ( double ) j;
    ytab[j] = exp ( xtab[j] );

    printf ( "  %10f  %10f\n", xtab[j], ytab[j] );
  }

  xval = 2.5;
  true_value = exp ( xval );
  printf ( "\n" );
  printf ( "  Evaluate at X = %f where EXP(X) = %f\n", xval, true_value );
  printf ( "\n" );
  printf ( "  Order  Approximate Y     Error\n" );
  printf ( "\n" );

  for ( ntab = 1; ntab <= MAXTAB; ntab++ )
  {

    for ( j = 0; j < ntab; j++ )
    {
      xtab[j] = ( double ) j;
      ytab[j] = exp ( xtab[j] );
    }

    data_to_dif ( ntab, xtab, ytab, diftab );

    yval = dif_val ( ntab, xtab, diftab, xval );

    error = yval - true_value;

    printf ( "  %6d  %10f  %10f\n", ntab, yval, error );

  }

  return;
# undef MAXTAB
}
/******************************************************************************/

void dif_basis_test ( )

/******************************************************************************/
/*
  Purpose:

    dif_basis_test tests dif_basis().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define NTAB 5

  double *diftab;
  int i;
  int j;
  int nstep = 9;
  double *pointer;
  int set = 3;
  double xhi;
  double xlo;
  double xtab[NTAB];
  double xval;
  double yval;

  printf ( "\n" );
  printf ( "dif_basis_test\n" );
  printf ( "  dif_basis() computes Lagrange basis polynomials\n" );
  printf ( "  in difference form.\n" );
  printf ( "\n" );
/*
  Set the base points.
*/
  r8vec_indicator ( NTAB, xtab );

  r8vec_print ( NTAB, xtab, "  The base points:" );
/*
  Get the difference tables for the basis polynomials and print them.
*/
  diftab = ( double * ) malloc ( NTAB * NTAB * sizeof ( double ) );

  dif_basis ( NTAB, xtab, diftab );

  printf ( "\n" );
  printf ( "  The table of difference vectors defining the basis polynomials.\n" );
  printf ( "  Each ROW represents a polynomial.\n" );
  printf ( "\n" );

  pointer = diftab;

  for ( i = 0; i < NTAB; i++ )
  {
    printf ( "  " );
    for ( j = 0; j < NTAB; j++ )
    {
      printf ( "%10f  ", *pointer );
      pointer++;
    }
    printf ( "\n" );
  }
/*
  Evaluate basis polynomial 3 at a set of points.
*/
  printf ( "\n" );
  printf ( "  Evaluate basis polynomial #%d at a set of points.\n", set );
  printf ( "\n" );
  printf ( "      X        Y\n" );
  printf ( "\n" );

  xhi = ( double ) NTAB;
  xlo = 1.0;
/*
  Advance pointer to beginning of data for basis polynomial SET.
*/
  pointer = diftab;
  for ( i = 1; i < set; i++ )
  {
    for ( j = 1; j <= NTAB; j++ )
    {
      pointer++;
    }
  }

  for ( i = 1; i <= nstep; i++ )
  {

    xval = ( ( double ) ( nstep - i     ) * xlo
           + ( double ) (         i - 1 ) * xhi )
           / ( double ) ( nstep     - 1 );

    yval = dif_val ( NTAB, xtab, pointer, xval );

    printf ( "  %10f  %10f\n", xval, yval );

  }

  free ( diftab );

  return;
# undef NTAB
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests DATA_TO_DIF_DISPLAY, DIF_PRINT, DIF_SHIFT_ZERO, DIF_TO_R8POLY;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define MAXTAB 10

  double c[MAXTAB];
  double diftab1[MAXTAB];
  double diftab2[MAXTAB];
  int i;
  int ntab;
  double x;
  double xtab1[MAXTAB];
  double xtab2[MAXTAB];
  double ytab1[MAXTAB];
  double ytab2[MAXTAB];

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  DIF_TO_R8POLY converts a difference table to a polynomial;\n" );
  printf ( "  DIF_SHIFT_ZERO shifts a divided difference table to 0;\n" );
  printf ( "\n" );
  printf ( "  These are equivalent operations\n" );
  printf ( "\n" );
/*
  Set XTAB, YTAB to X, F(X)
*/
  ntab = 4;
  for ( i = 0; i < ntab; i++ )
  {
    x = ( double ) ( i + 1 );
    xtab1[i] = x;
    xtab2[i] = x;
    ytab1[i] = - 4.0 + x * ( 3.0 + x * ( - 2.0 + x ) );
    ytab2[i] = ytab1[i];
  }
/*
  Compute and display the finite difference table.
*/
  data_to_dif_display ( ntab, xtab1, ytab1, diftab1 );

  data_to_dif_display ( ntab, xtab2, ytab2, diftab2 );
/*
  Examine the corresponding polynomial.
*/
  dif_print ( ntab, xtab1, diftab1, "  The divided difference table:" );
/*
  Shift to zero using DIF_SHIFT_ZERO.
*/
  dif_shift_zero ( ntab, xtab1, diftab1 );

  r8poly_print ( ntab, diftab1, "  The polynomial using DIF_SHIFT_ZERO:" );
/*
  Shift to zero using DIF_TO_R8POLY.
*/
  dif_to_r8poly ( ntab, xtab2, diftab2, c );

  r8poly_print ( ntab, c, "  The polynomial using DIF_TO_R8POLY:" );

  return;

# undef MAXTAB
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests R8POLY*.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define N 5

  int i;
  double poly_cof[N];
  double poly_cof2[N+1];
  double poly_cof3[N-1];
  double xval;
  double yval;
  double yval2;
  double yval3;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  R8POLY_ANT_COF computes the coefficients of the\n" );
  printf ( "  antiderivative of a polynomial;\n" );
  printf ( "  R8POLY_ANT_VAL evaluates the antiderivative of\n" );
  printf ( "  a polynomial;\n" );
  printf ( "  R8POLY_DER_COF computes the coefficients of the\n" );
  printf ( "  derivative of a polynomial;\n" );
  printf ( "  R8POLY_DER_VAL evaluates the derivative of\n" );
  printf ( "  a polynomial;\n" );
  printf ( "  R8POLY_PRINT prints a polynomial;\n" );
  printf ( "  R8POLY_VAL evaluates a polynomial.\n" );

  for ( i = 0; i <= N; i++ )
  {
    poly_cof[i] = ( double ) ( i + 1 );
  }

  r8poly_print ( N, poly_cof, "  The initial polynomial:" );

  r8poly_ant_cof ( N, poly_cof, poly_cof2 );

  r8poly_print ( N+1, poly_cof2, "  The antiderivative polynomial:" );

  r8poly_der_cof ( N, poly_cof, poly_cof3 );

  r8poly_print ( N-1, poly_cof3, "  The derivative polynomial:" );

  printf ( "\n" );
  printf ( "  Evaluate the polynomial, antiderivative and\n" );
  printf ( "  derivative, using only the original polynomial\n" );
  printf ( "  coefficients:\n" );
  printf ( "\n" );
  printf ( "  X   P(X)   Anti_P(X)     P'(X)\n" );
  printf ( "\n" );

  for ( i = 0; i <= 2; i++ )
  {
    xval = ( double ) i;

    yval = r8poly_val_horner ( N, poly_cof, xval );

    yval2 = r8poly_ant_val ( N, poly_cof, xval );

    yval3 = r8poly_der_val ( N, poly_cof, xval );

    printf ( "  %10f  %10f  %10f  %10f\n", xval, yval, yval2, yval3 );
  }

  return;
# undef N
}
/******************************************************************************/

void r8poly_basis_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_basis_test tests r8poly_basis().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define NTAB 5

  int i;
  int j;
  int nstep = 9;
  double *pointer;
  double *polcof;
  int set = 3;
  double xhi;
  double xlo;
  double xtab[NTAB];
  double xval;
  double yval;

  printf ( "\n" );
  printf ( "r8poly_basis_test\n" );
  printf ( "  r8poly_basis() computes Lagrange basis polynomials\n" );
  printf ( "  in standard form.\n" );
  printf ( "\n" );

  polcof = ( double * ) malloc ( NTAB * NTAB * sizeof ( double ) );
/*
  Set the base points.
*/
  r8vec_indicator ( NTAB, xtab );
/*
  Get the difference tables for the basis polynomials and print them.
*/
  r8poly_basis ( NTAB, xtab, polcof );

  printf ( "\n" );
  printf ( "  The table of difference vectors defining the basis polynomials.\n" );
  printf ( "  Each ROW represents a polynomial.\n" );
  printf ( "\n" );

  pointer = polcof;

  for ( i = 0; i < NTAB; i++ )
  {
    for ( j = 0; j < NTAB; j++ )
    {
      printf ( "%10f  ", *pointer );
      pointer++;
    }
    printf ( "\n" );
  }
/*
  Advance the pointer to the beginning of the data for basis polynomial SET.
*/
  pointer = polcof;
  for ( i = 1; i < set; i++ )
  {
    for ( j = 1; j <= NTAB; j++ )
    {
      pointer++;
    }
  }
/*
  Print basis polynomial SET in polynomial form.
*/
  r8poly_print ( NTAB, pointer, "  One basis polynomial in standard form:" );
/*
  Evaluate basis polynoimial SET at a set of points.
*/
  printf ( "\n" );
  printf ( "  Evaluate basis polynomial #%d at a set of points.\n", set );
  printf ( "\n" );
  printf ( "      X        Y\n" );
  printf ( "\n" );

  xhi = ( double ) NTAB;
  xlo = 1.0;

  for ( i = 1; i <= nstep; i++ )
  {

    xval = ( ( double ) ( nstep - i     ) * xlo
           + ( double ) (         i - 1 ) * xhi )
           / ( double ) ( nstep     - 1 );

    yval = r8poly_val_horner ( NTAB, pointer, xval );

    printf ( "  %10f  %10f\n", xval, yval );

  }

  free ( polcof );

  return;
# undef NTAB
}
/******************************************************************************/

void r8poly_shift_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_shift_test tests r8poly_shift().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define N 3

  int i;
  double poly_cof[N];
  double scale;
  double shift;

  scale = 2.0;
  shift = +3.0;
  poly_cof[0] = +6.0;
  poly_cof[1] = -1.0;
  poly_cof[2] =  2.0;

  printf ( "\n" );
  printf ( "r8poly_shift_test\n" );
  printf ( "  r8poly_shift shifts polynomial coefficients.\n" );
  printf ( "\n" );
  printf ( "  Polynomial coefficients for argument X\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %10f\n", i, poly_cof[i] );
  }

  r8poly_shift ( scale, shift, N, poly_cof );

  printf ( "\n" );
  printf ( "  SCALE = %f\n", scale );
  printf ( "  SHIFT = %f\n", shift );
  printf ( "\n" );
  printf ( "  Polynomial coefficients for argument Z = SCALE * X + SHIFT:\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %10f\n", i, poly_cof[i] );
  }

  return;

# undef N
}
/******************************************************************************/

void ncc_rule_test ( )

/******************************************************************************/
/*
  Purpose:

    ncc_rule_test tests ncc_rule();

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define NORDER 8

  int i;
  double weight[NORDER];
  double xtab[NORDER];

  printf ( "\n" );
  printf ( "ncc_rule_test\n" );
  printf ( "  ncc_rule() computes closed Newton Cotes formulas;\n" );
  printf ( "\n" );

  ncc_rule ( NORDER, xtab, weight );

  printf ( "\n" );
  printf ( "  Newton-Cotes Closed Quadrature Rule:\n" );
  printf ( "\n" );
  printf ( "    Abscissa       Weight\n" );
  printf ( "\n" );

  for ( i = 0; i < NORDER; i++ )
  {
    printf ( "  %6d  %10f  %10f\n", i+1, xtab[i], weight[i] );
  }

  return;
# undef NORDER
}
/******************************************************************************/

void nco_rule_test ( )

/******************************************************************************/
/*
  Purpose:

    nco_rule_test tests nco_rule().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 October 2019

  Author:

    John Burkardt
*/
{
# define NORDER 8

  int i;
  double weight[NORDER];
  double xtab[NORDER];

  printf ( "\n" );
  printf ( "nco_rule_test\n" );
  printf ( "  nco_rule() computes open Newton Cotes formulas.\n" );
  printf ( "\n" );

  nco_rule ( NORDER, xtab, weight );

  printf ( "\n" );
  printf ( "  Newton-Cotes Open Quadrature Rule:\n" );
  printf ( "\n" );
  printf ( "    Abscissa       Weight\n" );
  printf ( "\n" );

  for ( i = 0; i < NORDER; i++ )
  {
    printf ( "  %6d  %10f  %10f\n", i+1, xtab[i], weight[i] );
  }

  return;
# undef NORDER
}
/******************************************************************************/

void test18 ( )

/******************************************************************************/
/*
  Purpose:

    TEST18 tests ROOTS_TO_DIF and DIF_TO_R8POLY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define MAXROOTS 4

  double c[MAXROOTS+1];
  double diftab[MAXROOTS+1];
  int nroots;
  int ntab;
  double roots[MAXROOTS];
  double xtab[MAXROOTS+1];

  printf ( "\n" );
  printf ( "TEST18\n" );
  printf ( "  ROOTS_TO_DIF computes a divided difference\n" );
  printf ( "  polynomial with the given roots;\n" );
  printf ( "  DIF_TO_R8POLY converts it to a standard form polynomial.\n" );
  printf ( "\n" );

  nroots = 1;
  roots[0] = 3.0;
  r8vec_print ( nroots, roots, "  The roots:" );

  roots_to_dif ( nroots, roots, &ntab, xtab, diftab );
  dif_to_r8poly ( ntab, xtab, diftab, c );
  r8poly_print ( ntab, c, "  The polynomial:" );

  nroots = 2;
  roots[0] = 3.0;
  roots[1] = 1.0;
  r8vec_print ( nroots, roots, "  The roots:" );

  roots_to_dif ( nroots, roots, &ntab, xtab, diftab );
  dif_to_r8poly ( ntab, xtab, diftab, c );
  r8poly_print ( ntab, c, "  The polynomial:" );

  nroots = 3;
  roots[0] = 3.0;
  roots[1] = 1.0;
  roots[2] = 2.0;
  r8vec_print ( nroots, roots, "  The roots:" );

  roots_to_dif ( nroots, roots, &ntab, xtab, diftab );
  dif_to_r8poly ( ntab, xtab, diftab, c );
  r8poly_print ( ntab, c, "  The polynomial:" );

  nroots = 4;
  roots[0] = 3.0;
  roots[1] = 1.0;
  roots[2] = 2.0;
  roots[3] = 4.0;
  r8vec_print ( nroots, roots, "  The roots:" );

  roots_to_dif ( nroots, roots, &ntab, xtab, diftab );
  dif_to_r8poly ( ntab, xtab, diftab, c );
  r8poly_print ( ntab, c, "  The polynomial:" );

  return;
# undef MAXTAB
}
/******************************************************************************/

void roots_to_r8poly_test ( )

/******************************************************************************/
/*
  Purpose:

    roots_to_r8poly_test tests roots_to_r8poly.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2011

  Author:

    John Burkardt
*/
{
# define MAXROOT 5

  double c[MAXROOT+1];
  int nc;
  int nroot;
  double roots[MAXROOT];

  printf ( "\n" );
  printf ( "roots_to_r8poly_test\n" );
  printf ( "  roots_to_r8poly() computes polynomial coefficients from roots.\n" );
  printf ( "\n" );

  nroot = 1;
  roots[0] = 3.0;
  r8vec_print ( nroot, roots, "  The roots:" );

  roots_to_r8poly ( nroot, roots, &nc, c );

  r8poly_print ( nc, c, "  The polynomial:" );

  nroot = 2;
  roots[0] = 3.0;
  roots[1] = 1.0;
  r8vec_print ( nroot, roots, "  The roots:" );

  roots_to_r8poly ( nroot, roots, &nc, c );

  r8poly_print ( nc, c, "  The polynomial:" );

  nroot = 3;
  roots[0] = 3.0;
  roots[1] = 1.0;
  roots[2] = 2.0;
  r8vec_print ( nroot, roots, "  The roots:" );

  roots_to_r8poly ( nroot, roots, &nc, c );

  r8poly_print ( nc, c, "  The polynomial:" );

  nroot = 4;
  roots[0] = 3.0;
  roots[1] = 1.0;
  roots[2] = 2.0;
  roots[3] = 4.0;
  r8vec_print ( nroot, roots, "  The roots:" );

  roots_to_r8poly ( nroot, roots, &nc, c );

  r8poly_print ( nc, c, "  The polynomial:" );

  return;

# undef MAXROOT
}
/******************************************************************************/

void dif_derivk_table_test ( )

/******************************************************************************/
/*
  Purpose:

    dif_derivk_table_test tests dif_derivk_table();

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 June 2013

  Author:

    John Burkardt
*/
{
  double *c0;
  double *d0;
  double *d1;
  double *d2;
  double *d3;
  double *d4;
  double *f0;
  int i;
  int j;
  int k;
  int n0;
  int n1;
  int n2;
  int n3;
  int n4;
  double x;
  double *x0;
  double *x1;
  double *x2;
  double *x3;
  double *x4;
  double y0;
  double y1;
  double y2;
  double y3;
  double y4;

  printf ( "\n" );
  printf ( "dif_derivk_table_test\n" );
  printf ( "  dif_derivk_table() computes the K-th derivative\n" );
  printf ( "  for a divided difference table.\n" );
/*
  Set the 0 data points.
*/
  n0 = 5;
  x0 = ( double * ) malloc ( n0 * sizeof ( double ) );
  f0 = ( double * ) malloc ( n0 * sizeof ( double ) );
  for ( i = 0; i < 5; i++ )
  {
    x0[i] = ( double ) ( i - 2 );
  }
/*
  Set data for x^4/24+x^3/3+x^2/2+x+1
*/
  for ( j = 0; j < n0; j++ )
  {
    f0[j] = 1.0;
    for ( i = 4; 1 <= i; i-- )
    {
      f0[j] = f0[j] * x0[j] / ( double ) ( i ) + 1.0;
    }
  }
/*
  Compute the difference table.
*/
  d0 = ( double * ) malloc ( n0 * sizeof ( double ) );
  data_to_dif ( n0, x0, f0, d0 );
  dif_print ( n0, x0, d0, "  The divided difference polynomial P0:" );

  c0 = ( double * ) malloc ( n0 * sizeof ( double ) );
  dif_to_r8poly ( n0, x0, d0, c0 );

  r8poly_print ( n0, c0, "  Using DIF_TO_R8POLY" );
/*
  Compute the difference table for the K=1 derivative.
*/
  k = 1;
  n1 = n0 - k;
  x1 = ( double * ) malloc ( n1 * sizeof ( double ) );
  d1 = ( double * ) malloc ( n1 * sizeof ( double ) );
  dif_derivk_table ( n0, x0, d0, k, x1, d1 );
/*
  Compute the difference table for the K=2 derivative.
*/
  k = 2;
  n2 = n0 - k;
  x2 = ( double * ) malloc ( n2 * sizeof ( double ) );
  d2 = ( double * ) malloc ( n2 * sizeof ( double ) );
  dif_derivk_table ( n0, x0, d0, k, x2, d2 );
/*
  Compute the difference table for the K=3 derivative.
*/
  k = 3;
  n3 = n0 - k;
  x3 = ( double * ) malloc ( n3 * sizeof ( double ) );
  d3 = ( double * ) malloc ( n3 * sizeof ( double ) );
  dif_derivk_table ( n0, x0, d0, k, x3, d3 );
/*
  Compute the difference table for the K=4 derivative.
*/
  k = 4;
  n4 = n0 - k;
  x4 = ( double * ) malloc ( n4 * sizeof ( double ) );
  d4 = ( double * ) malloc ( n4 * sizeof ( double ) );
  dif_derivk_table ( n0, x0, d0, k, x4, d4 );
/*
  Evaluate all 5 polynomials.
*/
  printf ( "\n" );
  printf ( "  Evaluate difference tables for the function P0\n" );
  printf ( "  and its first four derivatives, P1...P4.\n" );
  printf ( "\n" );
  printf ( "      X         P0        P1        P2        P3        P4\n" );
  printf ( "\n" );

  for ( i = 0; i <= 10; i++ )
  {
    x = ( double ) ( i ) / 5.0;
    y0 = dif_val ( n0, x0, d0, x );
    y1 = dif_val ( n1, x1, d1, x );
    y2 = dif_val ( n2, x2, d2, x );
    y3 = dif_val ( n3, x3, d3, x );
    y4 = dif_val ( n4, x4, d4, x );
    printf ( "  %8.4f  %8.4f  %8.4f  %8.4f  %8.4f  %8.4f\n",
      x, y0, y1, y2, y3, y4 );
  }

  free ( c0 );
  free ( d0 );
  free ( d1 );
  free ( d2 );
  free ( d3 );
  free ( d4 );
  free ( f0 );
  free ( x0 );
  free ( x1 );
  free ( x2 );
  free ( x3 );
  free ( x4 );

  return;
}
/******************************************************************************/

void dif_basis_deriv_test ( )

/******************************************************************************/
/*
  Purpose:

    dif_basis_deriv_test tests dif_basis_deriv;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 October 2019

  Author:

    John Burkardt
*/
{
  double *c;
  double *ddp;
  int nd = 3;
  double *xd;
  double *xdp;

  printf ( "\n" );
  printf ( "dif_basis_deriv_test\n" );
  printf ( "  dif_basis_deriv() computes difference tables for\n" );
  printf ( "  the first derivative of each Lagrange basis.\n" );
  
  xd = ( double * ) malloc ( nd * sizeof ( double ) );
  xdp = ( double * ) malloc ( ( nd - 1 ) * sizeof ( double ) );
  ddp = ( double * ) malloc ( ( nd - 1 ) * nd * sizeof ( double ) );

  xd[0] = -2.0;
  xd[1] = 1.0;
  xd[2] = 5.0;

  dif_basis_deriv ( nd, xd, xdp, ddp );
/*
  Because the difference tables were shifted to all 0 abscissas,
  they contain the polynomial coefficients.
*/
  r8mat_transpose_print ( nd - 1, nd, ddp, 
    "  Lagrange basis derivative polynomial coefficients:" );

  c = ( double * ) malloc ( ( nd - 1 ) * sizeof ( double ) );
  dif_to_r8poly ( nd - 1, xdp, ddp+0*(nd-1), c );
  r8poly_print ( nd - 1, c, "  P1'=-(2x-6)/21" );

  dif_to_r8poly ( nd - 1, xdp, ddp+1*(nd-1), c );
  r8poly_print ( nd - 1, c, "  P2'=-(2x-3)/12" );

  dif_to_r8poly ( nd - 1, xdp, ddp+2*(nd-1), c );
  r8poly_print ( nd - 1, c, "  P3'=(2x+1)/28" );

  free ( c );
  free ( ddp );
  free ( xd );
  free ( xdp );

  return;
}
/******************************************************************************/

void dif_basis_derivk_test ( )

/******************************************************************************/
/*
  Purpose:

    dif_basis_derivk_test tests DIF_BASIS_DERIVK;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2013

  Author:

    John Burkardt
*/
{
  double *c;
  double *ddp;
  int k = 2;
  int nd = 5;
  double *xd;
  double *xdp;

  printf ( "\n" );
  printf ( "dif_basis_derivk_test\n" );
  printf ( "  DIF_BASIS_DERIVK computes difference tables for\n" );
  printf ( "  the K-th derivative of each Lagrange basis.\n" );
  
  xd = ( double * ) malloc ( nd * sizeof ( double ) );
  xdp = ( double * ) malloc ( ( nd - k ) * sizeof ( double ) );
  ddp = ( double * ) malloc ( ( nd - k ) * nd * sizeof ( double ) );

  xd[0] = 1.0;
  xd[1] = 2.0;
  xd[2] = 3.0;
  xd[3] = 4.0;
  xd[4] = 5.0;

  dif_basis_derivk ( nd, xd, k, xdp, ddp );
/*
  Because the difference tables were shifted to all 0 abscissas,
  they contain the polynomial coefficients.
*/
  r8mat_transpose_print ( nd - k, nd, ddp, 
    "  Lagrange basis K-th derivative polynomial coefficients:" );

  c = ( double * ) malloc ( ( nd - k ) * sizeof ( double ) );

  dif_to_r8poly ( nd - k, xdp, ddp+0*(nd-k), c );
  r8poly_print ( nd - k, c, "  P1''=(12x^2-84x+142)/24" );

  dif_to_r8poly ( nd - k, xdp, ddp+1*(nd-k), c );
  r8poly_print ( nd - k, c, "  P2''=-2x^2+13x-59/3" );

  dif_to_r8poly ( nd - k, xdp, ddp+2*(nd-k), c );
  r8poly_print ( nd - k, c, "  P3''=3x^2-18x+49/2" );

  dif_to_r8poly ( nd - k, xdp, ddp+3*(nd-k), c );
  r8poly_print ( nd - k, c, "  P4''=-2x^2+11x-41/3" );

  dif_to_r8poly ( nd - k, xdp, ddp+4*(nd-k), c );
  r8poly_print ( nd - k, c, "  P5''=(6x^2-30x+35)/12" );

  free ( c );
  free ( ddp );
  free ( xd );
  free ( xdp );

  return;
}
