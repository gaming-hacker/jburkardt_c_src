# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "r8s3.h"

int main ( );
void r8s3_diagonal_test ( );
void r8s3_dif2_test ( );
void r8s3_indicator_test ( );
void r8s3_jac_sl_test ( );
void r8s3_mtv_test ( );
void r8s3_mv_test ( );
void r8s3_print_test ( );
void r8s3_print_some_test ( );
void r8s3_random_test ( );
void r8s3_read_test ( );
void r8s3_res_test ( );
void r8s3_to_r8ge_test ( );
void r8s3_write_test ( );
void r8s3_zeros_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for R8S3_TEST.

  Discussion:

    R8S3_TEST tests R8S3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "R8S3_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test R8S3.\n" );

  r8s3_diagonal_test ( );
  r8s3_dif2_test ( );
  r8s3_indicator_test ( );
  r8s3_jac_sl_test ( );
  r8s3_mtv_test ( );
  r8s3_mv_test ( );
  r8s3_print_test ( );
  r8s3_print_some_test ( );
  r8s3_random_test ( );
  r8s3_read_test ( );
  r8s3_res_test ( );
  r8s3_to_r8ge_test ( );
  r8s3_write_test ( );
  r8s3_zeros_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "R8S3_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void r8s3_diagonal_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_DIAGONAL_TEST tests R8S3_DIAGONAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int col[20] = {
    4, 5, 1, 1, 1, 3, 3, 4, 0, 5, 
    3, 5, 4, 0, 5, 2, 0, 1, 0, 2 };
  int k;
  int m;
  int n;
  int nz_num;
  int row[20] = {
    0, 2, 3, 5, 4, 1, 5, 2, 0, 1, 
    3, 5, 4, 3, 3, 2, 5, 1, 2, 3 };
  int sym;

  printf ( "\n" );
  printf ( "R8S3_DIAGONAL_TEST\n" );
  printf ( "  R8S3_DIAGONAL rearranges an R8S3 matrix\n" );
  printf ( "  so that the diagonal is listed first.\n" );

  m = 6;
  n = 6;
  nz_num = 20;
  sym = 0;

  printf ( "\n" );
  printf ( "  Matrix order M =         %d\n", m );
  printf ( "  Matrix order N =         %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM =    %d\n", sym );

  a = r8s3_indicator ( m, n, nz_num, sym, row, col );

  printf ( "\n" );
  printf ( "  Before rearrangement:\n" );
  printf ( "       K  ROW(K)  COL(K)      A(K)\n" );
  printf ( "\n" );
  for ( k = 0; k < nz_num; k++ )
  {
    printf ( "  %8d  %8d  %8d  %14.6g\n", k, row[k], col[k], a[k] );
  }

  r8s3_diagonal ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  After rearrangement:\n" );
  printf ( "       K  ROW(K)  COL(K)      A(K)\n" );
  printf ( "\n" );
  for ( k = 0; k < nz_num; k++ )
  {
    printf ( "  %8d  %8d  %8d  %14.6g\n", k, row[k], col[k], a[k] );
  }

  free ( a );

  return;
}
/******************************************************************************/

void r8s3_dif2_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_DIF2_TEST tests R8S3_DIF2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int *col;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_DIF2_TEST\n" );
  printf ( "  R8S3_DIF2 sets an R8S3 matrix to the second difference.\n" );
/*
  Do not assume symmetry.
*/
  m = 5;
  n = 5;
  nz_num = 3 * n - 2;
  sym = 0;

  printf ( "\n" );
  printf ( "  Matrix order M =         %d\n", m );
  printf ( "  Matrix order N =         %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM =    %d\n", sym );

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  r8s3_print ( m, n, nz_num, sym, row, col, a, "  R8S3 matrix A:" );

  free ( a );
  free ( col );
  free ( row );
/*
  Try symmetry option.
*/
  m = 5;
  n = 5;
  nz_num = 2 * n - 1;
  sym = 1;

  printf ( "\n" );
  printf ( "  Matrix order M =         %d\n", m );
  printf ( "  Matrix order N =         %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM =    %d\n", sym );

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  r8s3_print ( m, n, nz_num, sym, row, col, a, "  R8S3 matrix A:" );

  free ( a );
  free ( col );
  free ( row );

  return;
}
/******************************************************************************/

void r8s3_indicator_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_INDICATOR_TEST tests R8S3_INDICATOR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int col[20] = {
    4, 5, 1, 1, 2, 3, 3, 4, 0, 5, 
    3, 5, 4, 0, 5, 2, 0, 1, 0, 2 };
  int m;
  int n;
  int nz_num = 20;
  int sym;
  int row[20] = {
    0, 2, 3, 5, 4, 1, 5, 2, 0, 1, 
    3, 5, 4, 3, 3, 2, 5, 1, 2, 3 };

  printf ( "\n" );
  printf ( "R8S3_INDICATOR\n" );
  printf ( "  R8S3_INDICATOR sets up an R8S3 indicator matrix.\n" );

  m = 6;
  n = 6;
  sym = 0;

  printf ( "\n" );
  printf ( "  Matrix order M =         %d\n", m );
  printf ( "  Matrix order N =         %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM =    %d\n", sym );

  a = r8s3_indicator ( m, n, nz_num, sym, row, col );

  r8s3_print ( m, n, nz_num, sym, row, col, a, 
    "  The R8S3 indicator matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8s3_jac_sl_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_JAC_SL_TEST tests R8S3_JAC_SL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int *col;
  int i;
  int it_max;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;
  double *x;

  printf ( "\n" );
  printf ( "R8S3_JAC_SL_TEST\n" );
  printf ( "  R8S3_JAC_SL uses Jacobi iteration to solve a linear system\n" );
  printf ( "  with an R8S3 matrix.\n" );

  m = 10;
  n = 10;
  nz_num = 3 * n - 2;
  sym = 0;
  it_max = 25;

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );
  printf ( "  Iterations per call    = %d\n", it_max );
/*
  Set the matrix values.
*/
  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );
/*
  Set the desired solution.
*/
  x = r8vec_indicator1_new ( n );
/*
  Compute the corresponding right hand side.
*/
  b = r8s3_mv ( n, n, nz_num, sym, row, col, a, x );
/*
  Set the starting solution.
*/
  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }
/*
  Solve the linear system.
*/
  for ( i = 1; i <= 3; i++ )
  {
    r8s3_jac_sl ( n, nz_num, sym, row, col, a, b, x, it_max );

    r8vec_print ( n, x, "  Current solution estimate:" );
  }

  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void r8s3_mtv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_MTV_TEST tests R8S3_MTV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int *col;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;
  double *x;

  printf ( "\n" );
  printf ( "R8S3_MTV_TEST\n" );
  printf ( "  R8S3_MTV computes b=A'*x, where A is an R8S3 matrix.\n" );

  m = 5;
  n = 4;
  if ( m == n )
  {
    nz_num = 3 * n - 2;
  }
  else
  {
    nz_num = 3 * n - 1;
  }
  sym = 0;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  x = r8vec_indicator1_new ( m );
  r8vec_print ( m, x, "  x:" );

  b = r8s3_mtv ( m, n, nz_num, sym, row, col, a, x );

  r8vec_print ( n, b, "  b=A'*x:" );

  free ( a );
  free ( b );
  free ( col );
  free ( row );
  free ( x );
/*
  Try symmetric option.
*/
  m = 5;
  n = 5;
  nz_num = 2 * n - 1;
  sym = 1;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  x = r8vec_indicator1_new ( m );
  r8vec_print ( m, x, "  x:" );

  b = r8s3_mtv ( m, n, nz_num, sym, row, col, a, x );

  r8vec_print ( n, b, "  b=A'*x:" );

  free ( a );
  free ( b );
  free ( col );
  free ( row );
  free ( x );

  return;
}
/******************************************************************************/

void r8s3_mv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_MV_TEST tests R8S3_MV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int *col;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;
  double *x;

  printf ( "\n" );
  printf ( "R8S3_MV_TEST\n" );
  printf ( "  R8S3_MV computes b=A*x, where A is an R8S3 matrix.\n" );

  m = 5;
  n = 4;
  if ( m == n )
  {
    nz_num = 3 * n - 2;
  }
  else
  {
    nz_num = 3 * n - 1;
  }
  sym = 0;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  x:" );

  b = r8s3_mv ( m, n, nz_num, sym, row, col, a, x );

  r8vec_print ( m, b, "  b=A*x:" );

  free ( a );
  free ( b );
  free ( col );
  free ( row );
  free ( x );
/*
  Try symmetric option.
*/
  m = 5;
  n = 5;
  nz_num = 2 * n - 1;
  sym = 1;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  x:" );

  b = r8s3_mv ( m, n, nz_num, sym, row, col, a, x );

  r8vec_print ( m, b, "  b=A*x:" );

  free ( a );
  free ( b );
  free ( col );
  free ( row );
  free ( x );

  return;
}
/******************************************************************************/

void r8s3_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_PRINT_TEST tests R8S3_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int *col;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_PRINT_TEST\n" );
  printf ( "  R8S3_PRINT prints an R8S3 matrix.\n" );

  m = 5;
  n = 5;
  nz_num = 3 * n - 2;
  sym = 0;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num, sym, row, col, a, "The matrix" );

  free ( a );
  free ( col );
  free ( row );

  m = 5;
  n = 5;
  nz_num = 2 * n - 1;
  sym = 1;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num, sym, row, col, a, "The matrix" );

  free ( a );
  free ( col );
  free ( row );

  return;
}
/******************************************************************************/

void r8s3_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_PRINT_SOME_TEST tests R8S3_PRINT_SOME.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int *col;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_PRINT_SOME_TEST\n" );
  printf ( "  R8S3_PRINT_SOME prints some of an R8S3 matrix.\n" );

  m = 5;
  n = 5;
  nz_num = 3 * n - 2;
  sym = 0;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print_some ( m, n, nz_num, sym, row, col, a, 1, 2, 3, 4, "  Rows 1:3, Cols 2:4:" );

  free ( a );
  free ( col );
  free ( row );

  m = 5;
  n = 5;
  nz_num = 2 * n - 1;
  sym = 1;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print_some ( m, n, nz_num, sym, row, col, a, 1, 2, 3, 4, "  Rows 1:3, Cols 2:4:" );

  free ( a );
  free ( col );
  free ( row );

  return;
}
/******************************************************************************/

void r8s3_random_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_RANDOM_TEST tests R8S3_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int col1[13] = { 0, 1, 2, 3, 4, 1, 3, 1, 4, 0, 4, 0, 2 };
  int col2[10] = { 0, 1, 2, 3, 4, 1, 0, 0, 2 };
  int m;
  int n;
  int nz_num1 = 13;
  int nz_num2 = 10;
  int row1[13] = { 0, 1, 2, 3, 4, 0, 1, 2, 2, 3, 3, 4, 4 };
  int row2[10] = { 0, 1, 2, 3, 4, 2, 3, 4, 4 };
  int seed;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_RANDOM_TEST\n" );
  printf ( "  R8S3_RANDOM randomizes an R8S3 matrix.\n" );

  m = 5;
  n = 5;
  sym = 0;
  seed = 123456789;

  a = r8s3_random ( m, n, nz_num1, sym, row1, col1, &seed );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num1 );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num1, sym, row1, col1, a, "  R8S3 matrix:" );

  free ( a );

  m = 5;
  n = 5;
  sym = 1;
  seed = 123456789;
 
  a = r8s3_random ( m, n, nz_num2, sym, row2, col2, &seed );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num2 );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num2, sym, row2, col2, a, "  R8S3 matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void r8s3_read_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_READ_TEST tests R8S3_READ.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 April 2013

  Author:

    John Burkardt
*/
{
  double *a;
  int *col;
  int m;
  int n;
  int nz_num;
  char *input_file = "r8s3_matrix.txt";
  int *row;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_READ_TEST\n" );
  printf ( "  R8S3_READ reads an R8S3 matrix from a file.\n" );
  printf ( "  R8S3_READ_SIZE reads the size of the matrix from a file.\n" );

  r8s3_read_size ( input_file, &m, &n, &nz_num );
  sym = 0;

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_read ( input_file, m, n, nz_num, row, col, a );

  r8s3_print_some ( m, n, nz_num, sym, row, col, a, 1, 1, 
    10, 10, "  Initial 10x10 block of R8S3 matrix:" );

  free ( a );
  free ( col );
  free ( row );

  return;
}
/******************************************************************************/

void r8s3_res_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_RES_TEST tests R8S3_RES.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  int *col;
  int m;
  int n;
  int nz_num;
  double *r;
  int *row;
  int sym;
  double *x;

  printf ( "\n" );
  printf ( "R8S3_RES_TEST\n" );
  printf ( "  R8S3_RES computes r=b-A*x, where A is an R8S3 matrix.\n" );

  m = 5;
  n = 4;
  if ( m == n )
  {
    nz_num = 3 * n - 2;
  }
  else
  {
    nz_num = 3 * n - 1;
  }
  sym = 0;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  x:" );

  b = r8s3_mv ( m, n, nz_num, sym, row, col, a, x );

  r = r8s3_res ( m, n, nz_num, sym, row, col, a, x, b );

  r8vec_print ( m, r, "  r=b-A*x:" );

  free ( a );
  free ( b );
  free ( col );
  free ( r );
  free ( row );
  free ( x );
/*
  Try symmetric option.
*/
  m = 5;
  n = 5;
  nz_num = 2 * n - 1;
  sym = 1;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  x:" );

  b = r8s3_mv ( m, n, nz_num, sym, row, col, a, x );

  r = r8s3_res ( m, n, nz_num, sym, row, col, a, x, b );

  r8vec_print ( m, r, "  r=b-A*x:" );

  free ( a );
  free ( b );
  free ( col );
  free ( r );
  free ( row );
  free ( x );

  return;
}
/******************************************************************************/

void r8s3_to_r8ge_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_TO_R8GE_TEST tests R8S3_TO_R8GE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a_r8s3;
  double *a_r8ge;
  int *col;
  int m;
  int n;
  int nz_num;
  int *row;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_TO_R8GE_TEST\n" );
  printf ( "  R8S3_TO_R8GE converts an R8S3 matrix to R8GE format.\n" );

  m = 5;
  n = 5;
  nz_num = 3 * n - 2;
  sym = 0;

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a_r8s3 = ( double * ) malloc ( nz_num * sizeof ( double ) );

  r8s3_dif2 ( m, n, nz_num, sym, row, col, a_r8s3 );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num, sym, row, col, a_r8s3, "  R8S3 matrix A:" );

  a_r8ge = r8s3_to_r8ge ( m, n, nz_num, sym, row, col, a_r8s3 );

  r8ge_print ( m, n, a_r8ge, "  R8GE matrix A:" );

  free ( a_r8ge );
  free ( a_r8s3 );
  free ( col );
  free ( row );

  return;
}
/******************************************************************************/

void r8s3_write_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_WRITE_TEST tests R8S3_WRITE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int *col;
  int m;
  int n;
  int nz_num;
  char *output_file = "r8s3_matrix.txt";
  int *row;
  int sym;

  printf ( "\n" );
  printf ( "R8S3_WRITE_TEST\n" );
  printf ( "  R8S3_WRITE writes an R8S3 matrix to a file.\n" );

  m = 100;
  n = 100;
  nz_num = 3 * n - 2;
  sym = 0;

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  row = ( int * ) malloc ( nz_num * sizeof ( int ) );
  col = ( int * ) malloc ( nz_num * sizeof ( int ) );
  a = ( double * ) malloc ( nz_num * sizeof ( double ) );
/*
  Set the matrix values.
*/
  r8s3_dif2 ( m, n, nz_num, sym, row, col, a );
/*
  Print a portion of the matrix.
*/
  r8s3_print_some ( m, n, nz_num, sym, row, col, a, 1, 1, 
    10, 10, "  Initial 10x10 block of R8S3 matrix:" );
/*
  Write it to a file.
*/
  r8s3_write ( m, n, nz_num, sym, row, col, a, output_file );

  printf ( "\n" );
  printf ( "  Matrix data written to \"%s\".\n", output_file );

  free ( a );
  free ( col );
  free ( row );

  return;
}
/******************************************************************************/

void r8s3_zeros_test ( )

/******************************************************************************/
/*
  Purpose:

    R8S3_ZEROS_TEST tests R8S3_ZEROS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 September 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int col1[13] = { 0, 1, 2, 3, 4, 1, 3, 1, 4, 0, 4, 0, 2 };
  int col2[10] = { 0, 1, 2, 3, 4, 1, 0, 0, 2 };
  int m;
  int n;
  int nz_num1 = 13;
  int nz_num2 = 10;
  int row1[13] = { 0, 1, 2, 3, 4, 0, 1, 2, 2, 3, 3, 4, 4 };
  int row2[10] = { 0, 1, 2, 3, 4, 2, 3, 4, 4 };
  int sym;

  printf ( "\n" );
  printf ( "R8S3_ZEROS_TEST\n" );
  printf ( "  R8S3_ZEROS sets an R8S3 matrix to zeros.\n" );

  m = 5;
  n = 5;
  sym = 0;
 
  a = r8s3_zeros ( m, n, nz_num1, sym, row1, col1 );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num1 );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num1, sym, row1, col1, a, "  R8S3 matrix:" );

  free ( a );

  m = 5;
  n = 5;
  sym = 1;
 
  a = r8s3_zeros ( m, n, nz_num2, sym, row2, col2 );

  printf ( "\n" );
  printf ( "  Matrix order M         = %d\n", m );
  printf ( "  Matrix order N         = %d\n", n );
  printf ( "  Matrix nonzeros NZ_NUM = %d\n", nz_num2 );
  printf ( "  Symmetry option SYM    = %d\n", sym );

  r8s3_print ( m, n, nz_num2, sym, row2, col2, a, "  R8S3 matrix:" );

  free ( a );

  return;
}
