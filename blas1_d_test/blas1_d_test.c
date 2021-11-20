# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "blas1_d.h"

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
double r8_uniform_01 ( int *seed );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BLAS1_D_TEST.

  Discussion:

    BLAS1_D_TEST tests the BLAS1_D library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 March 2007

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BLAS1_D_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BLAS1_D library.\n" );

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
  printf ( "BLAS1_D_TEST:\n" );
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

    30 March 2007

  Author:

    John Burkardt
*/
{
# define LDA 6
# define MA 5
# define NA 4
# define NX 10

  double a[LDA*NA];
  int i;
  int j;
  double x[NX];

  for ( i = 0; i < NX; i++ )
  {
    x[i] = pow ( -1.0, i + 1 ) * ( double ) ( 2 * ( i + 1 ) );
  }

  printf ( "\n" );
  printf ( "DASUM_TEST\n" );
  printf ( "  DASUM adds the absolute values of elements of a vector.\n" );
  printf ( "\n" );
  printf ( "  X = \n" );
  printf ( "\n" );
  for ( i = 0; i < NX; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }

  printf ( "\n" );
  printf ( "  DASUM ( NX,   X, 1 ) =    %f\n", dasum ( NX,   x, 1 ) );
  printf ( "  DASUM ( NX/2, X, 2 ) =    %f\n", dasum ( NX/2, x, 2 ) );
  printf ( "  DASUM ( 2,    X, NX/2 ) = %f\n", dasum ( 2,    x, NX/2 ) );

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
  printf ( "  DASUM(MA,A(1,2),1) =   %f\n", dasum ( MA, a+0+1*LDA, 1 ) );
  printf ( "  DASUM(NA,A(2,1),LDA) = %f\n", dasum ( NA, a+1+0*LDA, LDA ) );

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

    30 March 2007

  Author:

    John Burkardt
*/
{
# define N 6

  double da;
  int i;
  double x[N];
  double y[N];

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  printf ( "\n" );
  printf ( "DAXPY_TEST\n" );
  printf ( "  DAXPY adds a multiple of vector X to vector Y.\n" );
  printf ( "\n" );
  printf ( "  X =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  da = 1.0;
  daxpy ( N, da, x, 1, y, 1 );
  printf ( "\n" );
  printf ( "  DAXPY ( N, %f, X, 1, Y, 1 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  da = -2.0;
  daxpy ( N, da, x, 1, y, 1 );
  printf ( "\n" );
  printf ( "  DAXPY ( N, %14f, X, 1, Y, 1 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  da = 3.0;
  daxpy ( 3, da, x, 2, y, 1 );
  printf ( "\n" );
  printf ( "  DAXPY ( 3, %f, X, 2, Y, 1 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  da = -4.0;
  daxpy ( 3, da, x, 1, y, 2 );
  printf ( "\n" );
  printf ( "  DAXPY ( 3, %f, X, 1, Y, 2 )\n", da );
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  return;
# undef N
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

    30 March 2007

  Author:

    John Burkardt
*/
{
  double a[5*5];
  int i;
  int j;
  double x[10];
  double y[10];

  printf ( "\n" );
  printf ( "DCOPY_TEST\n" );
  printf ( "  DCOPY copies one vector into another.\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( double ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  printf ( "\n" );
  printf ( "  X =\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }
  printf ( "\n" );
  printf ( "  Y =\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
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

  dcopy ( 5, x, 1, y, 1 );
  printf ( "\n" );
  printf ( "  DCOPY ( 5, X, 1, Y, 1 )\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }

  dcopy ( 3, x, 2, y, 3 );
  printf ( "\n" );
  printf ( "  DCOPY ( 3, X, 2, Y, 3 )\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, y[i] );
  }

  dcopy ( 5, x, 1, a, 1 );
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
      a[i+j*5] = ( double ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  dcopy ( 5, x, 2, a, 5 );
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

    30 March 2007

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA 10
# define LDB 7
# define LDC 6

  double a[LDA*LDA];
  double b[LDB*LDB];
  double c[LDC*LDC];
  int i;
  int j;
  double sum1;
  double x[N];
  double y[N];

  printf ( "\n" );
  printf ( "DDOT_TEST\n" );
  printf ( "  DDOT computes the dot product of vectors.\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = - ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*LDA] = ( double ) ( i + 1 + j + 1 );
    }
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      b[i+j*LDB] = ( double ) ( ( i + 1 ) - ( j + 1 ) );
    }
  }

  sum1 = ddot ( N, x, 1, y, 1 );

  printf ( "\n" );
  printf ( "  Dot product of X and Y is %f\n", sum1 );
/*
  To multiply a ROW of a matrix A times a vector X, we need to
  specify the increment between successive entries of the row of A:
*/
  sum1 = ddot ( N, a+1+0*LDA, LDA, x, 1 );

  printf ( "\n" );
  printf ( "  Product of row 2 of A and X is %f\n", sum1 );
/*
  Product of a column of A and a vector is simpler:
*/
  sum1 = ddot ( N, a+0+1*LDA, 1, x, 1 );

  printf ( "\n" );
  printf ( "  Product of column 2 of A and X is %f\n", sum1 );
/*
  Here's how matrix multiplication, c = a*b, could be done
  with DDOT:
*/
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      c[i+j*LDC] = ddot ( N, a+i, LDA, b+0+j*LDB, 1 );
    }
  }

  printf ( "\n" );
  printf ( "  Matrix product computed with DDOT:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      printf ( "  %14f", c[i+j*LDC] );
    }
    printf ( "\n" );
  }

  return;
# undef N
# undef LDA
# undef LDB
# undef LDC
}
/******************************************************************************/

void dnrm2_test ( )

/******************************************************************************/
/*
  Purpose:

    DNRM2_TEST demonstrates DNRM2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 March 2007

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA 10
/*
  These parameters illustrate the fact that matrices are typically
  dimensioned with more space than the user requires.
*/
  double a[LDA*LDA];
  int i;
  int j;
  double x[N];

  printf ( "\n" );
  printf ( "DNRM2_TEST\n" );
  printf ( "  DNRM2 computes the Euclidean norm of a vector.\n" );
  printf ( "\n" );
/*
  Compute the euclidean norm of a vector:
*/
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  printf ( "\n" );
  printf ( "  X =\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }
  printf ( "\n" );
  printf ( "  The 2-norm of X is %f\n", dnrm2 ( N, x, 1 ) );
/*
  Compute the euclidean norm of a row or column of a matrix:
*/
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*LDA] = ( double ) ( i + 1 + j + 1 );
    }
  }

  printf ( "\n" );
  printf ( "  The 2-norm of row 2 of A is %f\n",
    dnrm2 ( N, a+1+0*LDA, LDA ) );

  printf ( "\n" );
  printf ( "  The 2-norm of column 2 of A is %f\n",
    dnrm2 ( N, a+0+1*LDA, 1 ) );

  return;
# undef N
# undef LDA
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

    30 March 2007

  Author:

    John Burkardt
*/
{
# define N 6

  double c;
  int i;
  double s;
  double x[N];
  double y[N];

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
    printf ( "  %6d  %14f  %14f\n", i+1, x[i], y[i] );
  }

  c = 0.5;
  s = sqrt ( 1.0 - c * c );
  drot ( N, x, 1, y, 1, c, s );
  printf ( "\n" );
  printf ( "  DROT ( N, X, 1, Y, 1, %f, %f )\n", c, s );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f  %14f\n", i+1, x[i], y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( ( i + 1 ) * ( i + 1 ) - 12 );
  }

  c = x[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );
  s = y[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );
  drot ( N, x, 1, y, 1, c, s );
  printf ( "\n" );
  printf ( "  DROT ( N, X, 1, Y, 1, %f, %f )\n", c, s );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f  %14f\n", i+1, x[i], y[i] );
  }

  return;
# undef N
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

    30 March 2007

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double r;
  double s;
  double sa;
  double sb;
  int seed;
  int test;
  int test_num = 5;
  double z;

  printf ( "\n" );
  printf ( "DROTG_TEST\n" );
  printf ( "  DROTG generates a real Givens rotation\n" );
  printf ( "    (  C  S ) * ( A ) = ( R )\n" );
  printf ( "    ( -S  C )   ( B )   ( 0 )\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( test = 1; test <= test_num; test++ )
  {
    a = r8_uniform_01 ( &seed );
    b = r8_uniform_01 ( &seed );

    sa = a;
    sb = b;

    drotg ( &sa, &sb, &c, &s );

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

    30 March 2007

  Author:

    John Burkardt
*/
{
# define N 6

  double da;
  int i;
  double x[N];

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
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }

  da = 5.0;
  dscal ( N, da, x, 1 );
  printf ( "\n" );
  printf ( "  DSCAL ( N, %f, X, 1 )\n", da );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  da = -2.0;
  dscal ( 3, da, x, 2 );
  printf ( "\n" );
  printf ( "  DSCAL ( 3, %f, X, 2 )\n", da );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
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

    30 March 2007

  Author:

    John Burkardt
*/
{
# define N 6

  int i;
  double x[N];
  double y[N];

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  printf ( "\n" );
  printf ( "DSWAP_TEST\n" );
  printf ( "  DSWAP swaps two vectors.\n" );
  printf ( "\n" );
  printf ( "  X and Y:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f  %14f\n", i+1, x[i], y[i] );
  }

  dswap ( N, x, 1, y, 1 );
  printf ( "\n" );
  printf ( "  DSWAP ( N, X, 1, Y, 1 )\n" );
  printf ( "\n" );
  printf ( "  X and Y:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f  %14f\n", i+1, x[i], y[i] );
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  dswap ( 3, x, 2, y, 1 );
  printf ( "\n" );
  printf ( "  DSWAP ( 3, X, 2, Y, 1 )\n" );

  printf ( "\n" );
  printf ( "  X and Y:\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %14f  %14f\n", i+1, x[i], y[i] );
  }

  return;
# undef N
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

    01 March 2017

  Author:

    John Burkardt
*/
{
  int i;
  int i1;
  int incx;
  int n = 11;
  double *x;;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "IDAMAX_TEST\n" );
  printf ( "  IDAMAX returns the index of maximum magnitude;\n" );

  for ( i = 1; i <= n; i++ )
  {
    x[i-1] = ( double ) ( ( 7 * i ) % 11 ) - ( double ) ( n / 2 );
  }

  printf ( "\n" );
  printf ( "  The vector X:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %6d  %14f\n", i+1, x[i] );
  }

  incx = 1;

  i1 = idamax ( n, x, incx );

  printf ( "\n" );
  printf ( "  The index of maximum magnitude = %d\n", i1 );

  free ( x );

  return;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a pseudorandom R8 scaled to [0,1].

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8_UNIFORM_01 - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0\n" );
    exit ( 1 );
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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

