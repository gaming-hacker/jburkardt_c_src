# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "row_echelon_integer.h"

int main ( );
void i4_gcd_test ( );
void i4_max_test ( );
void i4_min_test ( );
void i4mat_print_test ( );
void i4mat_print_some_test ( );
void i4mat_ref_test ( );
void i4mat_row_reduce_test ( );
void i4mat_row_swap_test ( );
void i4mat_rref_test ( );
void i4mat_u_solve_test ( );
void i4vec_binary_next_test ( );
void i4vec_is_binary_test ( );
void i4vec_print_test ( );
void i4vec_red_test ( );
void i4vec_transpose_print_test ( );
void ksub_next4_test ( );
void r8vec_is_integer_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ROW_ECHELON_INTEGER_TEST.

  Discussion:

    ROW_ECHELON_INTEGER_TEST tests the ROW_ECHELON_INTEGER library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ROW_ECHELON_INTEGER_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ROW_ECHELON_INTEGER library.\n" );

  i4_gcd_test ( );
  i4_max_test ( );
  i4_min_test ( );

  i4mat_print_test ( );
  i4mat_print_some_test ( );
  i4mat_ref_test ( );
  i4mat_row_reduce_test ( );
  i4mat_row_swap_test ( );
  i4mat_rref_test ( );
  i4mat_u_solve_test ( );

  i4vec_binary_next_test ( );
  i4vec_is_binary_test ( );
  i4vec_print_test ( );
  i4vec_red_test ( );
  i4vec_transpose_print_test ( );

  ksub_next4_test ( );

  r8vec_is_integer_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ROW_ECHELON_INTEGER_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void i4_gcd_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_GCD_TEST tests I4_GCD.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2010

  Author:

    John Burkardt
*/
{
# define TEST_NUM 7

  int i;
  int i_test[TEST_NUM] = { 36, 49, 0, 12, 36, 1, 91 };
  int j;
  int j_test[TEST_NUM] = { 30, -7, 71, 12, 49, 42, 28 };
  int test;

  printf ( "\n" );
  printf ( "I4_GCD_TEST\n" );
  printf ( "  I4_GCD computes the greatest common divisor of two I4s\n" );
  printf ( "\n" );
  printf ( "     I     J   I4_GCD\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    i = i_test[test];
    j = j_test[test];
    printf ( "  %6d  %6d  %6d\n", i, j, i4_gcd ( i, j ) );
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void i4_max_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_MAX_TEST tests I4_MAX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2018

  Author:

    John Burkardt
*/
{
  int a;
  int a_test[] = { -57,  66, -17, -49, -92, -88, -20,   60,  80, -81 };
  int b;
  int b_test[] = {  92,  12, -87, -78,  27, -10,  51, -100, -30, -98 };
  int c;
  int i;

  printf ( "\n" );
  printf ( "I4_MAX_TEST\n" );
  printf ( "  I4_MAX returns the maximum of two I4's.\n" );
  printf ( "\n" );
  printf ( "       A       B      C=I4_MAX(A,B)\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    a = a_test[i];
    b = b_test[i];
    c = i4_max ( a, b );
    printf ( "  %8d  %8d  %8d\n", a, b, c );
  }

  return;
}
/******************************************************************************/

void i4_min_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_MIN_TEST tests I4_MIN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2018

  Author:

    John Burkardt
*/
{
  int a;
  int a_test[] = { -57,  66, -17, -49, -92, -88, -20,   60,  80, -81 };
  int b;
  int b_test[] = {  92,  12, -87, -78,  27, -10,  51, -100, -30, -98 };
  int c;
  int i;

  printf ( "\n" );
  printf ( "I4_MIN_TEST\n" );
  printf ( "  I4_MIN returns the minimum of two I4's.\n" );
  printf ( "\n" );
  printf ( "       A       B      C=I4_MIN(A,B)\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    a = a_test[i];
    b = b_test[i];
    c = i4_min ( a, b );
    printf ( "  %8d  %8d  %8d\n", a, b, c );
  }

  return;
}
/******************************************************************************/

void i4mat_print_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_PRINT_TEST tests I4MAT_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 August 2018

  Author:

    John Burkardt
*/
{
  int a[5*4];
  int i;
  int j;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "I4MAT_PRINT_TEST\n" );
  printf ( "  I4MAT_PRINT prints an I4MAT.\n" );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( i + 1 ) * 10 + ( j + 1 );
    }
  }

  i4mat_print ( m, n, a, "  The matrix:" );

  return;
}
/******************************************************************************/

void i4mat_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_PRINT_SOME_TEST tests I4MAT_PRINT_SOME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 August 2018

  Author:

    John Burkardt
*/
{
  int a[5*4];
  int i;
  int j;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "I4MAT_PRINT_SOME_TEST\n" );
  printf ( "  I4MAT_PRINT_SOME prints some of an I4MAT.\n" );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( i + 1 ) * 10 + ( j + 1 );
    }
  }

  i4mat_print_some ( m, n, a, 1, 0, 3, 1, "  The I4MAT, rows 1:3, cols 0:1:" );

  return;
}
/******************************************************************************/

void i4mat_ref_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_REF_TEST tests I4MAT_REF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2018

  Author:

    John Burkardt
*/
{
  int a[4*7] = {
    1, -2, 3, -1,
    3, -6, 9, -3,
    0,  0, 0,  0,
    2, -2, 0,  1,
    6, -8, 6,  0,
    3,  3, 6,  9,
    1,  1, 2,  3 };
  int det;
  int m = 4;
  int n = 7;

  printf ( "\n" );
  printf ( "I4MAT_REF_TEST\n" );
  printf ( "  I4MAT_REF computes the \n" );
  printf ( "  integer row echelon form (IREF) of a matrix.\n" );

  i4mat_print ( m, n, a, "  Input A:" );

  det = i4mat_ref ( m, n, a );

  printf ( "\n" );
  printf ( "  Pseudo-determinant = %d\n", det );

  i4mat_print ( m, n, a, "  IREF form:" );

  return;
}
/******************************************************************************/

void i4mat_row_reduce_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_ROW_REDUCE_TEST tests I4MAT_ROW_REDUCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2018

  Author:

    John Burkardt
*/
{
  int a[5*3] = {
    12,   4, -12, 30, 0, 
    88,   8,  88, 18, 4, 
     9, 192,  94, 42, 8 };
  int i;
  int m = 5;
  int n = 3;

  printf ( "\n" );
  printf ( "I4MAT_ROW_REDUCE_TEST\n" );
  printf ( "  I4MAT_ROW_REDUCE divides a common factor from row I of an I4MAT;\n" );

  i4mat_print ( m, n, a, "  Original matrix:" );

  for ( i = m - 1; 0 <= i; i-- )
  {
    i4mat_row_reduce ( m, n, i, a );

    i4mat_print ( m, n, a, "  After reducing a row:" );
  }

  return;
}
/******************************************************************************/

void i4mat_row_swap_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_ROW_SWAP_TEST tests I4MAT_ROW_SWAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2018

  Author:

    John Burkardt
*/
{
  int a[5*4];
  int i;
  int i1;
  int i2;
  int j;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "I4MAT_ROW_SWAP_TEST\n" );
  printf ( "  I4MAT_ROW_SWAP swaps two rows of an I4MAT.\n" );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i+j*m] = 10 * ( i + 1 ) + j + 1;
    }
  }

  i4mat_print ( m, n, a, "  Input A:" );

  i1 = 1;
  i2 = 4;
  printf ( "\n" );
  printf ( "  Swap rows %d and %d\n", i1, i2 );

  i4mat_row_swap ( m, n, a, i1, i2 );

  i4mat_print ( m, n, a, "  Modified matrix:" );

  return;
}
/******************************************************************************/

void i4mat_rref_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_RREF_TEST tests I4MAT_RREF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2018

  Author:

    John Burkardt
*/
{
  int a[4*7] = {
    1, -2, 3, -1,
    3, -6, 9, -3,
    0,  0, 0,  0,
    2, -2, 0,  1,
    6, -8, 6,  0,
    3,  3, 6,  9,
    1,  1, 2,  3 };
  int det;
  int m = 4;
  int n = 7;

  printf ( "\n" );
  printf ( "I4MAT_RREF_TEST\n" );
  printf ( "  I4MAT_RREF computes the \n" );
  printf ( "  integer row reduced echelon form IRREF) of a matrix.\n" );

  i4mat_print ( m, n, a, "  Input A:" );

  det = i4mat_rref ( m, n, a );

  printf ( "\n" );
  printf ( "  Pseudo-determinant = %d\n", det );

  i4mat_print ( m, n, a, "  IREF form:" );

  return;
}
/******************************************************************************/

void i4mat_u_solve_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_U_SOLVE_TEST tests I4MAT_U_SOLVE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 July 2015

  Author:

    John Burkardt
*/
{
/*
  Each row of this definition is a COLUMN of the matrix.
*/
  int a[4*4] = {
    1, 0, 0,  0,
    2, 3, 0,  0,
    4, 5, 6,  0,
    7, 8, 9, 10 };
  int b[4] = { 45, 53, 54, 40 };
  int i;
  int j;
  int n = 4;
  double *r;
  double rnorm;
  double *x;

  printf ( "\n" );
  printf ( "I4MAT_U_SOLVE_TEST\n" );
  printf ( "  I4MAT_U_SOLVE solves an upper triangular system.\n" );

  i4mat_print ( n, n, a, "  Input matrix A:" );

  i4vec_print ( n, b, "  Right hand side b:" );

  x = i4mat_u_solve ( n, a, b );

  r8vec_print ( n, x, "  Solution x:" );

  r = ( double * ) malloc ( n * sizeof ( double ) );
  rnorm = 0.0;
  for ( i = 0; i < n; i++ )
  {
    r[i] = ( double ) b[i];
    for ( j = 0; j < n; j++ )
    {
      r[i] = r[i] - ( double ) a[i+j*n] * x[j];
    }
    rnorm = rnorm + r[i] * r[i];
  }
  rnorm = sqrt ( rnorm );

  printf ( "\n" );
  printf ( "  Norm of residual = %g\n", rnorm );

  free ( r );
  free ( x );

  return;
}
/******************************************************************************/

void i4vec_binary_next_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_BINARY_NEXT_TEST tests I4VEC_BINARY_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2018

  Author:

    John Burkardt
*/
{
  int bvec[3];
  int i;
  int n = 3;

  printf ( "\n" );
  printf ( "I4VEC_BINARY_NEXT_TEST\n" );
  printf ( "  I4VEC_BINARY_NEXT generates the next binary vector.\n" );
  printf ( "\n" );
 
  for ( i = 0; i < n; i++ )
  {
    bvec[i] = 0;
  }

  while ( true )
  {
    i4vec_transpose_print ( n, bvec, "" );

    if ( i4vec_is_one ( n, bvec ) )
    {
      break;
    }

    i4vec_binary_next ( n, bvec );
  }

  return;
}
/******************************************************************************/

void i4vec_is_binary_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_IS_BINARY_TEST tests I4VEC_IS_BINARY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 March 2018

  Author:

    John Burkardt
*/
{
  int n = 3;
  int x1[3] = { 0, 0, 0 };
  int x2[3] = { 1, 0, 1 };
  int x3[3] = { 0, 2, 1 };

  printf ( "\n" );
  printf ( "I4VEC_IS_BINARY_TEST\n" );
  printf ( "  I4VEC_IS_BINARY is TRUE if an I4VEC only contains\n" );
  printf ( "  0 or 1 entries.\n" );

  printf ( "\n" );
  i4vec_transpose_print ( n, x1, "  X:" );
  if ( i4vec_is_binary ( n, x1 ) )
  {
    printf ( "  X is binary.\n" );
  }
  else
  {
    printf ( "  X is NOT binary.\n" );
  }

  printf ( "\n" );
  i4vec_transpose_print ( n, x2, "  X:" );
  if ( i4vec_is_binary ( n, x2 ) )
  {
    printf ( "  X is binary.\n" );
  }
  else
  {
    printf ( "  X is NOT binary.\n" );
  }

  printf ( "\n" );
  i4vec_transpose_print ( n, x3, "  X:" );
  if ( i4vec_is_binary ( n, x3 ) )
  {
    printf ( "  X is binary.\n" );
  }
  else
  {
    printf ( "  X is NOT binary.\n" );
  }

  return;
}
/******************************************************************************/

void i4vec_print_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PRINT_TEST tests I4VEC_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 October 2014

  Author:

    John Burkardt
*/
{
  int n = 4;
  int v[4] = { 91, 92, 93, 94 };

  printf ( "\n" );
  printf ( "I4VEC_PRINT_TEST\n" );
  printf ( "  I4VEC_PRINT prints an I4VEC\n" );

  i4vec_print ( n, v, "  Here is the I4VEC:" );

  return;
}
/******************************************************************************/

void i4vec_red_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_RED_TEST tests I4VEC_RED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2018

  Author:

    John Burkardt
*/
{
  int a[5*3] = {
    12,   4, -12, 30, 0, 
    88,   8,  88, 18, 4, 
     9, 192,  94, 42, 8 };
  int i;
  int j;
  int m = 5;
  int n = 3;
  int row[3];

  printf ( "\n" );
  printf ( "I4VEC_RED_TEST\n" );
  printf ( "  I4VEC_RED divides out any common factors in the\n" );
  printf ( "  entries of an I4VEC.\n" );

  i4mat_print ( m, n, a, "  Apply I4VEC_RED to each row of this matrix:" );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      row[j] = a[i+j*m];
    }
    i4vec_red ( n, row );
    for ( j = 0; j < n; j++ )
    {
      a[i+j*m] = row[j];
    }
  }

  i4mat_print ( m, n, a, "  Reduced matrix:" );

  return;
}
/******************************************************************************/

void i4vec_transpose_print_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_TRANSPOSE_PRINT_TEST tests I4VEC_TRANSPOSE_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 September 2013

  Author:

    John Burkardt
*/
{
  int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  int n = 12;

  printf ( "\n" );
  printf ( "I4VEC_TRANSPOSE_PRINT_TEST\n" );
  printf ( "  I4VEC_TRANSPOSE_PRINT prints an I4VEC\n" );
  printf ( "  with 5 entries to a row, and an optional title.\n" );

  i4vec_print ( n, a, "  Output from I4VEC_PRINT:" );

  printf ( "\n" );
  printf ( "  Now call I4VEC_TRANSPOSE_PRINT with a short title:\n" );
  printf ( "\n" );

  i4vec_transpose_print ( n, a, "  My array:  " );

  printf ( "\n" );
  printf ( "  Now call I4VEC_TRANSPOSE_PRINT with no title:\n" );
  printf ( "\n" );

  i4vec_transpose_print ( n, a, " " );

  return;
}
/******************************************************************************/

void ksub_next4_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_NEXT4_TEST tests KSUB_NEXT4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int done;
  int i;
  int n = 5;
  int rank;

  printf ( "\n" );
  printf ( "KSUB_NEXT4_TEST\n" );
  printf ( "  KSUB_NEXT4 generates K subsets of an N set.\n" );
  printf ( "  N = %d\n", n );
  printf ( "  K = %d\n", K );
  printf ( "\n" );
  printf ( "Rank    Subset\n" );
  printf ( "\n" );

  done = 1;
  rank = 0;
 
  for ( ; ; )
  {
    ksub_next4 ( n, K, a, &done );
 
    if ( done )
    {
      break;
    }

    rank = rank + 1;
    printf ( "%4d  ", rank );
    printf ( "  " );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );

  }
 
  return;
# undef K
}
/******************************************************************************/

void r8vec_is_integer_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_IS_INTEGER_TEST tests R8VEC_IS_INTEGER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 August 2018

  Author:

    John Burkardt
*/
{
  int n = 6;
  double x1[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
  double x2[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.5 };
  double x3[6] = { 1.0, 2.0, 3.0000001, 4.0, 5.0, 6.0 };
  double x4[6] = { 1.0, 2.0, 300000000.2, 4.0, 5.0, 6.0 };

  printf ( "\n" );
  printf ( "R8VEC_IS_INTEGER_TEST\n" );
  printf ( "  R8VEC_IS_INTEGER is TRUE if an R8VEC only contains\n" );
  printf ( "  integer entries.\n" );

  printf ( "\n" );
  printf ( "  Example 1: Obviously integer:\n" );
  printf ( "\n" );
  r8vec_transpose_print ( n, x1, "  X:" );
  if ( r8vec_is_integer ( n, x1 ) )
  {
    printf ( "  X is integer.\n" );
  }
  else
  {
    printf ( "  X is NOT integer.\n" );
  }

  printf ( "\n" );
  printf ( "  Example 2: Obviously NOT integer:\n" );
  printf ( "\n" );
  r8vec_transpose_print ( n, x2, "  X:" );
  if ( r8vec_is_integer ( n, x2 ) )
  {
    printf ( "  X is integer.\n" );
  }
  else
  {
    printf ( "  X is NOT integer.\n" );
  }

  printf ( "\n" );
  printf ( "  Example 3: Not obviously not integer:\n" );
  printf ( "\n" );
  r8vec_transpose_print ( n, x3, "  X:" );
  if ( r8vec_is_integer ( n, x3 ) )
  {
    printf ( "  X is integer.\n" );
  }
  else
  {
    printf ( "  X is NOT integer.\n" );
  }

  printf ( "\n" );
  printf ( "  Example 4: Not obviously not integer:\n" );
  printf ( "\n" );
  r8vec_transpose_print ( n, x4, "  X:" );
  if ( r8vec_is_integer ( n, x4 ) )
  {
    printf ( "  X is integer.\n" );
  }
  else
  {
    printf ( "  X is NOT integer.\n" );
  }

  return;
}

