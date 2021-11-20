# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "f2c.h"
# include "blaswrap.h"
# include "clapack.h"

int main ( );
void dasum_test ( );
void daxpy_test ( );
void dcopy_test ( );
void ddot_test ( );
void dnrm2_test ( );
void drot_test ( );
void drotg_test ( );
void dscal_test ( );
void dswap_test ( );
void idamax_test ( );
void r8vec_print ( int n, double a[], char *title );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CBLAS_TEST.

  Discussion:

    CBLAS_TEST tests the CBLAS library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "CBLAS_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the CBLAS library.\n" );
/*
  Test the double precision real level 1 CBLAS:
*/
  dasum_test ( );
  daxpy_test ( );
  dcopy_test ( );
  ddot_test ( );
  dnrm2_test ( );
  drot_test ( );
  drotg_test ( );
  dscal_test ( );
  dswap_test ( );
  idamax_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CBLAS_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void dasum_test ( )

/******************************************************************************/
/*
  Purpose:

    DASUM_TEST tests DASUM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
# define LDA 6
# define MA 5
# define NA 4
# define NX 10

  doublereal a[LDA*NA];
  integer i;
  integer INCX;
  integer j;
  integer N;
  doublereal x[NX];

  for ( i = 0; i < NX; i++ )
  {
    x[i] = pow ( -1.0, i + 1 ) * ( doublereal ) ( 2 * ( i + 1 ) );
  }

  printf ( "\n" );
  printf ( "DASUM_TEST\n" );
  printf ( "  DASUM adds the absolute values of elements of a vector.\n" );
  printf ( "\n" );
  printf ( "  X = \n" );
  printf ( "\n" );
  for ( i = 0; i < NX; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }

  printf ( "\n" );

  N = NX;
  INCX = 1;
  printf ( "  DASUM ( NX,   X, 1 ) =    %f\n", dasum_ ( &N, x, &INCX ) );

  N = NX / 2;
  INCX = 2;
  printf ( "  DASUM ( NX/2, X, 2 ) =    %f\n", dasum_ ( &N, x, &INCX ) );

  N = 2;
  INCX = NX / 2;
  printf ( "  DASUM ( 2,    X, NX/2 ) = %f\n", dasum_ ( &N, x, &INCX ) );

  for ( i = 0; i < MA; i++ )
  {
    for ( j = 0; j < NA; j++ )
    {
      a[i+j*LDA] = pow ( -1.0, i + 1 + j + 1)
        * ( double ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  printf ( "\n" );
  printf ( "  Demonstrate with a matrix A:\n" );
  printf ( "\n" );
  for ( i = 0; i < MA; i++ )
  {
    for ( j = 0; j < NA; j++ )
    {
      printf ( "  %14f", a[i+j*LDA] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  N = MA;
  INCX = 1;
  printf ( "  DASUM(MA,A(1,2),1) =   %f\n", dasum_ ( &N, a+0+1*LDA, &INCX ) );

  N = NA;
  INCX = LDA;
  printf ( "  DASUM(NA,A(2,1),LDA) = %f\n", dasum_ ( &N, a+1+0*LDA, &INCX ) );

  return;
# undef LDA
# undef MA
# undef NA
# undef NX
}
/******************************************************************************/

void daxpy_test ( )

/******************************************************************************/
/*
  Purpose:

    DAXPY_TEST tests DAXPY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  doublereal da;
  integer i;
  integer INCX;
  integer INCY;
  integer N;
  doublereal x[6];
  doublereal y[6];

  for ( i = 0; i < 6; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  printf ( "\n" );
  printf ( "DAXPY_TEST\n" );
  printf ( "  DAXPY adds a multiple of vector X to vector Y.\n" );
  printf ( "\n" );
  printf ( "  X =\n" );
  printf ( "\n" );
  for ( i = 0; i < 6; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 6; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  N = 6;
  da = 1.0;
  INCX = 1;
  INCY = 1;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DAXPY ( N, %f, X, 1, Y, 1 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 6; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 6;
  da = -2.0;
  INCX = 1;
  INCY = 1;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DAXPY ( N, %14f, X, 1, Y, 1 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 6; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 3;
  da = 3.0;
  INCX = 2;
  INCY = 1;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DAXPY ( 3, %f, X, 2, Y, 1 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 6; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 3;
  da = -4.0;
  INCX = 1;
  INCY = 2;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DAXPY ( 3, %f, X, 1, Y, 2 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 6; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  return;
}
/******************************************************************************/

void dcopy_test ( )

/******************************************************************************/
/*
  Purpose:

    DCOPY_TEST tests DCOPY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  doublereal a[5*5];
  integer i;
  integer INCX;
  integer INCY;
  integer j;
  integer N;
  doublereal x[10];
  doublereal y[10];

  printf ( "\n" );
  printf ( "DCOPY_TEST\n" );
  printf ( "  DCOPY copies one vector into another.\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( doublereal ) ( 10 * ( i + 1 ) );
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( doublereal ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  printf ( "\n" );
  printf ( "  X =\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }
  printf ( "\n" );
  printf ( "  A =\n" );
  printf ( "\n" );
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      printf ( "  %14f", a[i+j*5] );
    }
      printf ( "\n" );
  }

  N = 5;
  INCX = 1;
  INCY = 1;
  dcopy_ ( &N, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DCOPY ( 5, X, 1, Y, 1 )\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( doublereal ) ( 10 * ( i + 1 ) );
  }

  N = 3;
  INCX = 2;
  INCY = 3;
  dcopy_ ( &N, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DCOPY ( 3, X, 2, Y, 3 )\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, y[i] );
  }

  N = 5;
  INCX = 1;
  INCY = 1;
  dcopy_ ( &N, x, &INCX, a, &INCY );
  printf ( "\n" );
  printf ( "  DCOPY ( 5, X, 1, A, 1 )\n" );
  printf ( "\n" );
  printf ( "  A =\n" );
  printf ( "\n" );
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      printf ( "  %14f", a[i+j*5] );
    }
      printf ( "\n" );
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( doublereal ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  N = 5;
  INCX = 2;
  INCY = 5;
  dcopy_ ( &N, x, &INCX, a, &INCY );
  printf ( "\n" );
  printf ( "  DCOPY ( 5, X, 2, A, 5 )\n" );
  printf ( "\n" );
  printf ( "  A =\n" );
  printf ( "\n" );
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      printf ( "  %14f", a[i+j*5] );
    }
      printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void ddot_test ( )

/******************************************************************************/
/*
  Purpose:

    DDOT_TEST demonstrates DDOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
# define LDA 10
# define LDB 7
# define LDC 6

  doublereal a[LDA*LDA];
  doublereal b[LDB*LDB];
  doublereal c[LDC*LDC];
  integer i;
  integer INCX;
  integer INCY;
  integer j;
  integer N;
  doublereal sum1;
  doublereal x[10];
  doublereal y[10];

  printf ( "\n" );
  printf ( "DDOT_TEST\n" );
  printf ( "  DDOT computes the dot product of vectors.\n" );
  printf ( "\n" );

  N = 10;
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = - ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*LDA] = ( doublereal ) ( i + 1 + j + 1 );
    }
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      b[i+j*LDB] = ( doublereal ) ( ( i + 1 ) - ( j + 1 ) );
    }
  }

  N = 10;
  INCX = 1;
  INCY = 1;
  sum1 = ddot_ ( &N, x, &INCX, y, &INCY );

  printf ( "\n" );
  printf ( "  Dot product of X and Y is %f\n", sum1 );
/*
  To multiply a ROW of a matrix A times a vector X, we need to
  specify the increment between successive entries of the row of A:
*/
  N = 10;
  INCX = LDA;
  INCY = 1;
  sum1 = ddot_ ( &N, a+1+0*LDA, &INCX, x, &INCY );

  printf ( "\n" );
  printf ( "  Product of row 2 of A and X is %f\n", sum1 );
/*
  Product of a column of A and a vector is simpler:
*/
  N = 10;
  INCX = 1;
  INCY = 1;
  sum1 = ddot_ ( &N, a+0+1*LDA, &INCX, x, &INCY );

  printf ( "\n" );
  printf ( "  Product of column 2 of A and X is %f\n", sum1 );
/*
  Here's how matrix multiplication, c = a*b, could be done with DDOT:
*/
  N = 10;
  INCX = LDA;
  INCY = 1;

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      c[i+j*LDC] = ddot_ ( &N, a+i, &INCX, b+0+j*LDB, &INCY );
    }
  }

  printf ( "\n" );
  printf ( "  Matrix product computed with DDOT:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      printf ( "  %7.0f", c[i+j*LDC] );
    }
    printf ( "\n" );
  }

  return;
# undef LDA
# undef LDB
# undef LDC
}
/******************************************************************************/

void dnrm2_test ( )

/******************************************************************************/
/*
  Purpose:

    DNRM2_TEST tests DNRM2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  doublereal *X;
  integer INCX;
  integer N;
  doublereal VALUE;

  N = 3;
  X = ( doublereal * ) malloc ( N * sizeof ( doublereal ) );
  X[0] = 1.0;
  X[1] = 2.0;
  X[2] = 3.0;
  INCX = 1;

  printf ( "\n" );
  printf ( "DNRM2_TEST\n" );
  printf ( "  For a double precision real vector (D)\n" );
  printf ( "  DNRM2 computes the Euclidean norm.\n" );

  r8vec_print ( N, X, "  The vector X:" );

  VALUE = dnrm2_ ( &N, X, &INCX );

  printf ( "\n" );
  printf ( "  VALUE = %g\n", VALUE );

  return;
}
/******************************************************************************/

void drot_test ( )

/******************************************************************************/
/*
  Purpose:

    DROT_TEST tests DROT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  doublereal c;
  integer i;
  integer INCX;
  integer INCY;
  integer N;
  doublereal s;
  doublereal x[6];
  doublereal y[6];

  N = 6;
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( ( i + 1 ) * ( i + 1 ) - 12 );
  }

  printf ( "\n" );
  printf ( "DROT_TEST\n" );
  printf ( "  DROT carries out a Givens rotation.\n" );
  printf ( "\n" );
  printf ( "  X and Y\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f  %14f\n", i+1, x[i], y[i] );
  }

  N = 6;
  INCX = 1;
  INCY = 1;
  c = 0.5;
  s = sqrt ( 1.0 - c * c );

  drot_ ( &N, x, &INCX, y, &INCY, &c, &s );

  printf ( "\n" );
  printf ( "  DROT ( N, X, 1, Y, 1, %f, %f )\n", c, s );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f  %14f\n", i+1, x[i], y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( doublereal ) ( ( i + 1 ) * ( i + 1 ) - 12 );
  }

  N = 6;
  INCX = 1;
  INCY = 1;
  c = x[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );
  s = y[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );

  drot_ ( &N, x, &INCX, y, &INCY, &c, &s );

  printf ( "\n" );
  printf ( "  DROT ( N, X, 1, Y, 1, %f, %f )\n", c, s );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f  %14f\n", i+1, x[i], y[i] );
  }

  return;
}
/******************************************************************************/

void drotg_test ( )

/******************************************************************************/
/*
  Purpose:

    DROTG_TEST tests DROTG.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  doublereal a;
  doublereal b;
  doublereal c;
  doublereal r;
  doublereal s;
  doublereal sa;
  doublereal sb;
  integer test;
  doublereal z;

  printf ( "\n" );
  printf ( "DROTG_TEST\n" );
  printf ( "  DROTG generates a real Givens rotation\n" );
  printf ( "    (  C  S ) * ( A ) = ( R )\n" );
  printf ( "    ( -S  C )   ( B )   ( 0 )\n" );
  printf ( "\n" );

  for ( test = 1; test <= 5; test++ )
  {
    if ( test == 1 )
    {
      a =  0.218418;
      b =  0.956318;
    }
    else if ( test == 2 )
    {
      a =  0.829509;
      b =  0.561695;
    }
    else if ( test == 3 )
    {
      a =  0.415307;
      b =  0.066119;
    }
    else if ( test == 4 )
    {
      a =  0.257578;
      b =  0.109957;
    }
    else if ( test == 5 )
    {
      a =  0.043829;
      b =  0.633966;
    }

    sa = a;
    sb = b;

    drotg_ ( &sa, &sb, &c, &s );

    r = sa;
    z = sb;

    printf ( "\n" );
    printf ( "  A =  %f,  B =  %f\n", a, b );
    printf ( "  C =  %f,  S =  %f\n", c, s );
    printf ( "  R =  %f,  Z =  %f\n", r, z );
    printf ( "   C*A+S*B = %f\n",  c * a + s * b );
    printf ( "  -S*A+C*B = %f\n", -s * a + c * b );
  }

  return;
}
/******************************************************************************/

void dscal_test ( )

/******************************************************************************/
/*
  Purpose:

    DSCAL_TEST tests DSCAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  doublereal da;
  integer i;
  integer INCX;
  integer N;
  doublereal x[6];

  N = 6;
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  printf ( "\n" );
  printf ( "DSCAL_TEST\n" );
  printf ( "  DSCAL multiplies a vector by a scalar.\n" );
  printf ( "\n" );
  printf ( "  X =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }

  N = 6;
  da = 5.0;
  INCX = 1;
  dscal_ ( &N, &da, x, &INCX );
  printf ( "\n" );
  printf ( "  DSCAL ( N, %f, X, 1 )\n", da );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  N = 3;
  da = -2.0;
  INCX = 2;
  dscal_ ( &N, &da, x, &INCX );

  N = 6;
  printf ( "\n" );
  printf ( "  DSCAL ( 3, %f, X, 2 )\n", da );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }

  return;
# undef N
}
/******************************************************************************/

void dswap_test ( )

/******************************************************************************/
/*
  Purpose:

    DSWAP_TEST tests DSWAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  integer i;
  integer INCX;
  integer INCY;
  integer N;
  double x[6];
  double y[6];

  N = 6;
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  printf ( "\n" );
  printf ( "DSWAP_TEST\n" );
  printf ( "  DSWAP swaps two vectors.\n" );
  printf ( "\n" );
  printf ( "  X and Y:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f  %14f\n", i+1, x[i], y[i] );
  }

  N = 6;
  INCX = 1;
  INCY = 1;
  dswap_ ( &N, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DSWAP ( N, X, 1, Y, 1 )\n" );
  printf ( "\n" );
  printf ( "  X and Y:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f  %14f\n", i+1, x[i], y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 3;
  INCX = 2;
  INCY = 1;
  dswap_ ( &N, x, &INCX, y, &INCY );
  printf ( "\n" );
  printf ( "  DSWAP ( 3, X, 2, Y, 1 )\n" );

  N = 6;
  printf ( "\n" );
  printf ( "  X and Y:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6ld  %14f  %14f\n", i+1, x[i], y[i] );
  }

  return;
}
/******************************************************************************/

void idamax_test ( )

/******************************************************************************/
/*
  Purpose:

    IDAMAX_TEST demonstrates IDAMAX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2018

  Author:

    John Burkardt
*/
{
  integer i;
  integer i1;
  integer incx;
  integer n = 11;
  doublereal *x;;

  x = ( doublereal * ) malloc ( n * sizeof ( doublereal ) );

  printf ( "\n" );
  printf ( "IDAMAX_TEST\n" );
  printf ( "  IDAMAX returns the index of maximum magnitude;\n" );

  for ( i = 1; i <= n; i++ )
  {
    x[i-1] = ( doublereal ) ( ( 7 * i ) % 11 ) - ( doublereal ) ( n / 2 );
  }

  printf ( "\n" );
  printf ( "  The vector X:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %6ld  %14f\n", i+1, x[i] );
  }

  incx = 1;

  i1 = idamax_ ( &n, x, &incx );

  printf ( "\n" );
  printf ( "  The index of maximum magnitude = %ld\n", i1 );

  free ( x );

  return;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %8d: %14f\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

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

