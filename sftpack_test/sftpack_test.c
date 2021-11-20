# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "sftpack.h"

int main ( );

void c4mat_sft_test ( );
void c4vec_sft_test ( );
void c8mat_sft_test ( );
void c8vec_sft_test ( );
void r4vec_sft_test ( );
void r8vec_sct_test ( );
void r8vec_sft_test ( );
void r8vec_sht_test ( );
void r8vec_sqct_test ( );
void r8vec_sqst_test ( );
void r8vec_sst_test ( );
void r8vec_swt_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SFTPACK_TEST.

  Discussion:

    SFTPACK_TEST tests the SFTPACK library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

   27 June 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SFTPACK_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SFTPACK library.\n" );

  c4mat_sft_test ( );
  c4vec_sft_test ( );

  c8mat_sft_test ( );
  c8vec_sft_test ( );

  r4vec_sft_test ( );

  r8vec_sct_test ( );
  r8vec_sft_test ( );
  r8vec_sht_test ( );
  r8vec_sqct_test ( );
  r8vec_sqst_test ( );
  r8vec_sst_test ( );
  r8vec_swt_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SFTPACK_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void c4mat_sft_test ( )

/******************************************************************************/
/*
  Purpose:

    C4MAT_SFT_TEST tests C4MAT_SFTB and C4MAT_SFTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 June 2010

  Author:

    John Burkardt
*/
{
  int n1 = 10;
  int n2 = 4;
  int seed;
  complex *x;
  complex *x2;
  complex *y;

  printf ( "\n" );
  printf ( "C4MAT_SFT_TEST\n" );
  printf ( "  C4MAT_SFTF computes the forward slow Fourier transform.\n" );
  printf ( "  C4MAT_SFTB computes the backward  slow Fourier transform.\n" );
  printf ( "\n" );
  printf ( "  The data has dimensions N1 = %d by N2 = %d\n", n1, n2 );

  seed = 123456789;

  x = c4mat_uniform_01_new ( n1, n2, &seed );

  c4mat_print_some ( n1, n2, x, 1, 1, 10, 10, "  The original data:" );
/*
  Compute the slow Fourier transform of the data.
*/
  y = c4mat_sftf ( n1, n2, x );

  c4mat_print_some ( n1, n2, y, 1, 1, 10, 10, "  The Fourier coefficients:" );
/*
  Now try to retrieve the data from the coefficients.
*/
  x2 = c4mat_sftb ( n1, n2, y );

  c4mat_print_some ( n1, n2, x2, 1, 1, 10, 10, "  The retrieved data:" );

  free ( x );
  free ( x2 );
  free ( y );

  return;
}
/******************************************************************************/

void c4vec_sft_test ( )

/******************************************************************************/
/*
  Purpose:

    C4VEC_SFT_TEST tests C4VEC_SFTB and C4VEC_SFTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2010

  Author:

    John Burkardt
*/
{
  int n = 36;
  int seed;
  complex *x;
  complex *x2;
  complex *y;

  printf ( "\n" );
  printf ( "C4VEC_SFT_TEST\n" );
  printf ( "  C4VEC_SFTF computes the forward slow Fourier transform.\n" );
  printf ( "  C4VEC_SFTB computes the backward slow Fourier transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data values, N = %d\n", n );

  seed = 123456789;

  x = c4vec_uniform_01_new ( n, &seed );

  c4vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the slow Fourier transform of the data.
*/
  y = c4vec_sftf ( n, x );

  c4vec_print_part ( n, y, 10, "  The Fourier coefficients:" );
/*
  Now try to retrieve the data from the coefficients.
*/
  x2 = c4vec_sftb ( n, y );

  c4vec_print_part ( n, x2, 10, "  The retrieved data:" );

  free ( x );
  free ( x2 );
  free ( y );

  return;
}
/******************************************************************************/

void c8mat_sft_test ( )

/******************************************************************************/
/*
  Purpose:

    C8MAT_SFT_TEST tests C8MAT_SFTB and C8MAT_SFTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 June 2010

  Author:

    John Burkardt
*/
{
  int n1 = 10;
  int n2 = 4;
  int seed;
  doublecomplex *x;
  doublecomplex *x2;
  doublecomplex *y;

  printf ( "\n" );
  printf ( "C8MAT_SFT_TEST\n" );
  printf ( "  C8MAT_SFTF computes the forward slow Fourier transform.\n" );
  printf ( "  C8MAT_SFTB computes the backward slow Fourier transform.\n" );
  printf ( "\n" );
  printf ( "  The data has dimensions N1 = %d by N2 = %d\n", n1, n2 );

  seed = 123456789;

  x = c8mat_uniform_01_new ( n1, n2, &seed );

  c8mat_print_some ( n1, n2, x, 1, 1, 10, 10, "  The original data:" );
/*
  Compute the slow Fourier transform of the data.
*/
  y = c8mat_sftf ( n1, n2, x );

  c8mat_print_some ( n1, n2, y, 1, 1, 10, 10, "  The Fourier coefficients:" );
/*
  Now try to retrieve the data from the coefficients.
*/
  x2 = c8mat_sftb ( n1, n2, y );

  c8mat_print_some ( n1, n2, x2, 1, 1, 10, 10, "  The retrieved data:" );

  free ( x );
  free ( x2 );
  free ( y );

  return;
}
/******************************************************************************/

void c8vec_sft_test ( )

/******************************************************************************/
/*
  Purpose:

    C8VEC_SFT_TEST tests C8VEC_SFTB and C8VEC_SFTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2010

  Author:

    John Burkardt
*/
{
  int n = 36;
  int seed;
  doublecomplex *x;
  doublecomplex *x2;
  doublecomplex *y;

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  C4VEC_SFTF computes the forward slow Fourier transform.\n" );
  printf ( "  C4VEC_SFTB computes the backward slow Fourier transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data values, N = %d\n", n );

  seed = 123456789;

  x = c8vec_uniform_01_new ( n, &seed );

  c8vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the slow Fourier transform of the data.
*/
  y = c8vec_sftf ( n, x );

  c8vec_print_part ( n, y, 10, "  The Fourier coefficients:" );
/*
  Now try to retrieve the data from the coefficients.
*/
  x2 = c8vec_sftb ( n, y );

  c8vec_print_part ( n, x2, 10, "  The retrieved data:" );

  free ( x );
  free ( x2 );
  free ( y );

  return;
}
/******************************************************************************/

void r4vec_sft_test ( )

/******************************************************************************/
/*
  Purpose:

    R4VEC_SFT_TEST tests R4VEC_SFTB and R4VEC_SFTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2010

  Author:

    John Burkardt
*/
{
  float *a;
  float ahi = 5.0;
  float alo = 0.0;
  float azero;
  float *b;
  int i;
  int n = 36;
  int seed;
  float *x;
  float *z;

  printf ( "\n" );
  printf ( "R4VEC_SFT_TEST\n" );
  printf ( "  R4VEC_SFTF computes the forward slow Fourier transform.\n" );
  printf ( "  R4VEC_SFTB computes the backward slow Fourier transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data values, N = %d\n", n );

  seed = 123456789;

  x = r4vec_uniform_ab_new ( n, alo, ahi, &seed );

  r4vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the slow Fourier transform of the data.
*/
  a = ( float * ) malloc ( ( n / 2 ) * sizeof ( float ) );
  b = ( float * ) malloc ( ( n / 2 ) * sizeof ( float ) );

  r4vec_sftf ( n, x, &azero, a, b );

  printf ( "\n" );
  printf ( "  A (cosine) coefficients:\n" );
  printf ( "\n" );

  printf ( "  %4d  %14f\n", 0, azero );

  for ( i = 0; i < ( n / 2 ); i++ )
  {
    printf ( "  %4d  %14f\n", i, a[i] );
  }

  printf ( "\n" );
  printf ( "  B (sine) coefficients:\n" );
  printf ( "\n" );

  for ( i = 0; i < ( n / 2 ); i++ )
  {
    printf ( "  %4d  %14f\n", i, b[i] );
  }
/*
  Now try to retrieve the data from the coefficients.
*/
  z = r4vec_sftb ( n, azero, a, b );

  r4vec_print_part ( n, z, 10, "  The retrieved data:" );

  free ( a );
  free ( b );
  free ( x );
  free ( z );

  return;
}
/******************************************************************************/

void r8vec_sct_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SCT_TEST tests R8VEC_SCT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2010

  Author:

    John Burkardt
*/
{
  double ahi = 5.0;
  double alo = 0.0;
  double *c;
  double *d;
  double *e;
  int i;
  int n = 256;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_SCT_TEST\n" );;
  printf ( "  R8VEC_SCT does a forward or backward slow cosine transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data items is N = %d\n", n );
/*
  Set the data values.
*/
  seed = 123456789;

  c = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, c, 10, "  The original data:" );
/*
  Compute the coefficients.
*/
  d = r8vec_sct ( n, c );

  r8vec_print_part ( n, d, 10, "  The cosine coefficients:" );
/*
  Now compute inverse transform of coefficients.  Should get back the
  original data.
*/
  e = r8vec_sct ( n, d );

  for ( i = 0; i < n; i++ )
  {
    e[i] = e[i] / ( double ) ( 2 * n );
  }

  r8vec_print_part ( n, e, 10, "  The retrieved data:" );

  free ( c );
  free ( d );
  free ( e );

  return;
}
/******************************************************************************/

void r8vec_sft_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SFT_TEST tests R8VEC_SFTB and R8VEC_SFTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2010

  Author:

    John Burkardt
*/
{
  double *a;
  double ahi = 5.0;
  double alo = 0.0;
  double azero;
  double *b;
  int i;
  int n = 36;
  int seed;
  double *x;
  double *z;

  printf ( "\n" );
  printf ( "R8VEC_SFT_TEST\n" );
  printf ( "  R8VEC_SFTF computes the forward slow Fourier transform.\n" );
  printf ( "  R8VEC_SFTB computes the backward slow Fourier transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data values, N = %d\n", n );

  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the slow Fourier transform of the data.
*/
  a = ( double * ) malloc ( ( n / 2 ) * sizeof ( double ) );
  b = ( double * ) malloc ( ( n / 2 ) * sizeof ( double ) );

  r8vec_sftf ( n, x, &azero, a, b );

  printf ( "\n" );
  printf ( "  A (cosine) coefficients:\n" );
  printf ( "\n" );

  printf ( "  %4d  %14f\n", 0, azero );

  for ( i = 0; i < ( n / 2 ); i++ )
  {
    printf ( "  %4d  %14f\n", i, a[i] );
  }

  printf ( "\n" );
  printf ( "  B (sine) coefficients:\n" );
  printf ( "\n" );

  for ( i = 0; i < ( n / 2 ); i++ )
  {
    printf ( "  %4d  %14f\n", i, b[i] );
  }
/*
  Now try to retrieve the data from the coefficients.
*/
  z = r8vec_sftb ( n, azero, a, b );

  r8vec_print_part ( n, z, 10, "  The retrieved data:" );

  free ( a );
  free ( b );
  free ( x );
  free ( z );

  return;
}
/******************************************************************************/

void r8vec_sht_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SHT_TEST tests R8VEC_SHT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2010

  Author:

    John Burkardt
*/
{
  double ahi = 5.0;
  double alo = 0.0;
  double *c;
  double *d;
  double *e;
  int n = 17;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_SHT_TEST\n" );
  printf ( "  R8VEC_SHT does a forward or backward slow Hartley transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data items is N = %d\n", n );
/*
  Set the data values.
*/
  seed = 123456789;

  c = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, c, 10, "  The original data:" );
/*
  Compute the coefficients.
*/
  d = r8vec_sht ( n, c );

  r8vec_print_part ( n, d, 10, "  The Hartley coefficients:" );
/*
  Now compute inverse transform of coefficients.  Should get back the
  original data.
*/
  e = r8vec_sht ( n, d );

  r8vec_print_part ( n, e, 10, "  The retrieved data:" );

  free ( c );
  free ( d );
  free ( e );

  return;
}
/******************************************************************************/

void r8vec_sqct_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SQCT_TEST tests R8VEC_SQCTB and R8VEC_SQCTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2010

  Author:

    John Burkardt
*/
{
  double ahi = 5.0;
  double alo = 0.0;
  int n = 256;
  int seed;
  double *x;
  double *y;
  double *z;

  printf ( "\n" );
  printf ( "R8VEC_SQCT_TEST\n" );
  printf ( "  R8VEC_SQCTF does a forward slow quarter wave cosine transform;\n" );
  printf ( "  R8VEC_SQCTB does a backward slow quarter wave cosine transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data items is N = %d\n", n );
/*
  Set the data values.
*/
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the coefficients.
*/
  y = r8vec_sqctf ( n, x );

  r8vec_print_part ( n, y, 10, "  The cosine coefficients:" );
/*
  Now compute inverse transform of coefficients.  Should get back the
  original data.
*/
  z = r8vec_sqctb ( n, y );

  r8vec_print_part ( n, z, 10, "  The retrieved data:" );

  free ( x );
  free ( y );
  free ( z );

  return;
}
/******************************************************************************/

void r8vec_sqst_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SQST_TEST tests R8VEC_SQSTB and R8VEC_SQSTF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2010

  Author:

    John Burkardt
*/
{
  double ahi = 5.0;
  double alo = 0.0;
  int n = 256;
  int seed;
  double *x;
  double *y;
  double *z;

  printf ( "\n" );
  printf ( "R8VEC_SQST_TEST\n" );
  printf ( "  R8VEC_SQSTF does a forward slow quarter wave sine transform;\n" );
  printf ( "  R8VEC_SQSTB does a backward slow quarter wave sine transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data items is N = %d\n", n );
/*
  Set the data values.
*/
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the coefficients.
*/
  y = r8vec_sqstf ( n, x );

  r8vec_print_part ( n, y, 10, "  The sine coefficients:" );
/*
  Now compute inverse transform of coefficients.  Should get back the
  original data.
*/
  z = r8vec_sqstb ( n, y );

  r8vec_print_part ( n, z, 10, "  The retrieved data:" );

  free ( x );
  free ( y );
  free ( z );

  return;
}
/******************************************************************************/

void r8vec_sst_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SST_TEST tests R8VEC_SST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2010

  Author:

    John Burkardt
*/
{
  double ahi = 5.0;
  double alo = 0.0;
  double *c;
  double *d;
  double *e;
  int i;
  int n = 256;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_SST_TEST\n" );
  printf ( "  R8VEC_SST does a forward or backward slow sine transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data items is N = %d\n", n );
/*
  Set the data values.
*/
  seed = 123456789;

  c = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, c, 10, "  The original data:" );
/*
  Compute the coefficients;
*/
  d = r8vec_sst ( n, c );

  r8vec_print_part ( n, d, 10, "  The sine coefficients:" );
/*
  Now compute inverse transform of coefficients.  Should get back the
  original data.
*/
  e = r8vec_sst ( n, d );

  for ( i = 0; i < n; i++ )
  {
    e[i] = e[i] / ( double ) ( 2 * ( n + 1 ) );
  }

  r8vec_print_part ( n, e, 10, "  The retrieved data:" );

  free ( c );
  free ( d );
  free ( e );

  return;
}
/******************************************************************************/

void r8vec_swt_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SWT_TEST tests R8VEC_SWTB and R8VEC_SWTF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 June 2015

  Author:

    John Burkardt
*/
{
  double ahi;
  double alo;
  double *d;
  int i;
  int n = 36;
  int np1h;
  double *s;
  int seed;
  double *x;

  alo = 0.0;
  ahi = 5.0;

  printf ( "\n" );
  printf ( "R8VEC_SWT_TEST\n" );
  printf ( "  R8VEC_SWTF computes the forward slow wavelet transform.\n" );
  printf ( "  R8VEC_SWTB computes the backward slow wavelet transform.\n" );
  printf ( "\n" );
  printf ( "  The number of data values, N = %d\n", n );

  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, alo, ahi, &seed );

  r8vec_print_part ( n, x, 10, "  The original data:" );
/*
  Compute the slow wavelet transform of the data.
*/
  np1h = ( ( n + 1 ) / 2 );
  s = ( double * ) malloc ( np1h * sizeof ( double ) );
  d = ( double * ) malloc ( np1h * sizeof ( double ) );

  r8vec_swtf ( n, x, s, d );

  printf ( "\n" );
  printf ( "     I          S(I)            D(I)\n" );
  printf ( "\n" );
  for ( i = 0; i < np1h; i++ )
  {
    printf ( "  %4d  %14.6g  %14.6g\n", i, s[i], d[i] );
  }
/*
  Now try to retrieve the data from the coefficients.
*/
  free ( x );

  x = r8vec_swtb ( n, s, d );

  r8vec_print_part ( n, x, 10, "  The retrieved data:" );

  free ( d );
  free ( s );
  free ( x );

  return;
}

