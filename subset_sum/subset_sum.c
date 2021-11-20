# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "subset_sum.h"

/******************************************************************************/

int backup_one ( int n, int u[], int told )

/******************************************************************************/
/*
  Purpose:

    BACKUP_ONE seeks the last 1 in the subarray U[0:TOLD-1].

  Licensing:

    I don't care what you do with this code.

  Modified:

    15 July 2017

  Author:

    John Burkardt

  Parameters:

    Input, int N, the full size of the U array.

    Input, int U[N], the array to be checked.

    Input, int TOLD, a value between 0 and N-1.

    Output, int BACKUP_ONE, the highest index in U, between 0 and TOLD-1,
    for which U is 1.  If no such value is found, T is -1.
*/
{
  int i;
  int t;

  t = -1;
  
  for ( i = told - 1; 0 <= i; i-- )
  {
    if ( u[i] == 1 )
    {
      t = i;
      break;
    }
  }

  return t;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    I don't care what you do with this code.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    I don't care what you do with this code.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_power ( int i, int j )

/******************************************************************************/
/*
  Purpose:

    I4_POWER returns the value of I^J.

  Licensing:

    I don't care what you do with this code.

  Modified:

    23 October 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, J, the base and the power.  J should be nonnegative.

    Output, int I4_POWER, the value of I^J.
*/
{
  int k;
  int value;

  if ( j < 0 )
  {
    if ( i == 1 )
    {
      value = 1;
    }
    else if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I4_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J negative.\n" );
      exit ( 1 );
    }
    else
    {
      value = 0;
    }
  }
  else if ( j == 0 )
  {
    if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I4_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J = 0.\n" );
      exit ( 1 );
    }
    else
    {
      value = 1;
    }
  }
  else if ( j == 1 )
  {
    value = i;
  }
  else
  {
    value = 1;
    for ( k = 1; k <= j; k++ )
    {
      value = value * i;
    }
  }
  return value;
}
/******************************************************************************/

int *i4_to_digits_binary ( int i, int n )

/******************************************************************************/
/*
  Purpose:

    I4_TO_DIGITS_BINARY produces the binary digits of an I4.

  Example:

     I    N     C               Binary
    --  ---   ---         ------------
     0    1   0                      0
     0    2   0, 0                  00
     1    3   1, 0, 0              100
     2    3   0, 1, 0              010
     3    3   1, 1, 0              011
     4    3   0, 0, 1              100
     8    3   0, 0, 0           (1)000
     8    5   0, 0, 0, 1, 0      01000
    -8    5   0, 0, 0, 1, 0  (-) 01000

     0    3   0, 0, 0
     1    3   1, 0, 0
     2    3   0, 1, 0
     3    3   1, 1, 0
     4    3   0, 0, 1
     5    3   1, 0, 1
     6    3   0, 1, 1
     7    3   1, 1, 1

  Licensing:

    I don't care what you do with this code.

  Modified:

    19 December 2011

  Author:

    John Burkardt

  Parameters:

    Input, int I, the integer to be analyzed.

    Input, int N, the number of digits to determine.

    Output, int I4_TO_DIGITS_BINARY[N], the first N binary digits of I.
    Entry 0 is the units digit.
*/
{
  int *c;
  int j;

  c = ( int * ) malloc ( n * sizeof ( int ) );

  i = abs ( i );

  for ( j = 0; j < n; j++ )
  {
    c[j] = i % 2;
    i = ( i - c[j] ) / 2;
  }

  return c;
}
/******************************************************************************/

int *i4vec_copy_new ( int n, int a1[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_COPY_NEW copies an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, int A1[N], the vector to be copied.

    Output, int I4VEC_COPY_NEW[N], the copy of A1.
*/
{
  int *a2;
  int i;

  a2 = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return a2;
}
/******************************************************************************/

int i4vec_dot_product ( int n, int x[], int y[] )

/******************************************************************************/
/*
  Purpose:

    I4VEC_DOT_PRODUCT computes the dot product of two I4VEC's.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    I don't care what you do with this code.

  Modified:

    19 December 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the size of the array.

    Input, int X[N], Y[N], the arrays.

    Output, int I4VEC_DOT_PRODUCT, the dot product of X and Y.
*/
{
  int i;
  int value;

  value = 0;
  for ( i = 0; i < n; i++ )
  {
    value = value + x[i] * y[i];
  }

  return value;
}
/******************************************************************************/

void i4vec_print ( int n, int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PRINT prints an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    I don't care what you do with this code.

  Modified:

    14 November 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %6d: %8d\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

int subset_sum_count ( int n, int w[], int t, int ind_min, int ind_max )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_COUNT counts solutions to the subset sum problem in a range.

  Licensing:

    I don't care what you do with this code.

  Modified:

    02 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the size of the subset.

    Input, int W[N], a set of weights.  The length of this
    array must be no more than 31.

    Input, int T, the target value.

    Input, int IND_MIN, IND_MAX, the lower and upper
    limits to be searched.  0 <= IND_MIN <= IND_MAX <= (2^N)-1.

    Output, int SUBSET_SUM_COUNT, the number of distinct
    solutions of the subset sum problem found within the given range.
*/
{
  int *c;
  int ind;
  int ind_max2;
  int ind_min2;
  int solution_num;
/*
  Check the data.
*/
  if ( n < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "SUBSET_SUM_COUNT - Fatal error!\n" );
    fprintf ( stderr, "  N < 1.\n" );
    exit ( 1 );
  }

  if ( 31 < n )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "SUBSET_SUM_COUNT - Fatal error!\n" );
    fprintf ( stderr, "  31 < N.\n" );
    exit ( 1 );
  }

  ind_min2 = i4_max ( ind_min, 0 );
  ind_max2 = i4_min ( ind_max, i4_power ( 2, n ) - 1 );
/*
  Run through the range.
*/
  printf ( "\n" );
  printf ( "  Searching from IND_MIN = %d", ind_min2 );
  printf ( "  through IND_MAX = %d\n", ind_max2 );

  solution_num = 0;

  for ( ind = ind_min2; ind <= ind_max2; ind++ )
  {
/*
  Convert INDEX into vector of indices in W.
*/
    c = i4_to_digits_binary ( ind, n );
/*
  If the sum of those weights matches the target, return combination.
*/
    if ( i4vec_dot_product ( n, c, w ) == t )
    {
      solution_num = solution_num + 1;
    }

    free ( c );
  }

  return solution_num;
}
/******************************************************************************/

void subset_sum_count_test ( int n, int w[], int t, int ind_min, int ind_max )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_COUNT_TEST tests SUBSET_SUM_COUNT.

  Licensing:

    I don't care what you do with this code.

  Modified:

    10 November 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of weights.

    Input, int W[N], a set of weights.  The length of this
    array must be no more than 31.

    Input, int T, the target value.

    Input, int IND_MIN, IND_MAX, the lower and upper
    limits to be searched.
*/
{
  int solution_num;

  printf ( "\n" );
  printf ( "SUBSET_SUM_COUNT_TESTS:\n" );
  printf ( "  SUBSET_SUM_COUNT_TEST calls SUBSET_SUM_COUNT with\n" );
  printf ( "  a particular set of problem data.\n" );

  printf ( "\n" );
  printf ( "  Target value T = %d\n", t );
  i4vec_print ( n, w, "  Weight vector W:" );

  solution_num = subset_sum_count ( n, w, t, ind_min, ind_max );

  printf ( "\n" );
  printf ( "  Number of solutions = %d\n", solution_num );

  return;
}
/******************************************************************************/

void subset_sum_count_tests ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_COUNT_TESTS tests SUBSET_SUM_COUNT_TEST.

  Licensing:

    I don't care what you do with this code.

  Modified:

    10 November 2015

  Author:

    John Burkardt
*/
{
  int ind_max;
  int ind_min;
  int n;
  int t;
  int test;
  int test_num = 9;
  int *w;
  static int w01[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w02[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w03[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w04[10] = { 267,  493,  869,  961, 1000, 1153, 1246, 1598, 1766, 1922 };
  static int w05[21] = {518533, 1037066, 2074132, 1648264, 796528, 
             1593056,  686112, 1372224,  244448, 488896, 
              977792, 1955584, 1411168,  322336, 644672, 
             1289344,   78688,  157376,  314752, 629504, 
             1259008};
  static int w06[10] = { 41, 34, 21, 20,  8,  7,  7,  4,  3,  3 };
  static int w07[9] = { 81, 80, 43, 40, 30, 26, 12, 11, 9 };
  static int w08[6] = { 1, 2, 4, 8, 16, 32 };
  static int w09[10] = { 25, 27, 3, 12, 6, 15, 9, 30, 21, 19 };

  printf ( "\n" );
  printf ( "SUBSET_SUM_COUNT_TESTS:\n" );
  printf ( "  SUBSET_SUM_COUNT_TEST calls SUBSET_SUM_COUNT with\n" );
  printf ( "  a particular set of problem data.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    if ( test == 1 )
    {
      n = 8;
      w = i4vec_copy_new ( n, w01 );
      t = 53;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 2 )
    {
      n = 8;
      w = i4vec_copy_new ( n, w02 );
      t = 53;
      ind_min = 68;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 3 )
    {
      n = 8;
      w = i4vec_copy_new ( n, w03 );
      t = 53;
      ind_min = 167;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 4 )
    {
      n = 10;
      w = i4vec_copy_new ( n, w04 );
      t = 5842;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 5 )
    {
      n = 21;
      w = i4vec_copy_new ( n, w05 );
      t = 2463098;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 6 )
    {
      n = 10;
      w = i4vec_copy_new ( n, w06 );
      t = 50;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 7 )
    {
      n = 9;
      w = i4vec_copy_new ( n, w07 );
      t = 100;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 8 )
    {
      n = 6;
      w = i4vec_copy_new ( n, w08 );
      t = 22;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 9 )
    {
      n = 10;
      w = i4vec_copy_new ( n, w09 );
      t = 50;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }

    subset_sum_count_test ( n, w, t, ind_min, ind_max );

    free ( w );
  }

  return;
}
/******************************************************************************/

int *subset_sum_find ( int n, int w[], int t, int ind_min, int ind_max, 
  int *ind )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM seeks a subset of a set that has a given sum.

  Discussion:

    This function tries to compute a target value as the sum of
    a selected subset of a given set of weights.

    This function works by brute force, that is, it tries every
    possible subset to see if it sums to the desired value.

    Given N weights, every possible selection can be described by
    one of the N-digit binary numbers from 0 to 2^N-1.

    This function includes a range, which allows the user to
    control which subsets are to be checked.  Thus, if there are
    N weights, specifying a range of [ 0, 2^N-1] indicates that
    all subsets should be checked.  On the other hand, this full
    range could be broken down into smaller subranges, each of
    which could be checked independently.

    It is possible that, in the given range, there may be multiple
    solutions of the problem.  This function will only return
    one such solution, if found.  However, the function may be called
    again, with an appropriate restriction of the range, to continue
    the search for other solutions.

  Example:

    w = [ 1, 2, 4, 8, 16, 32 ];
    t = 22;
    r = [ 0, 2^6 - 1 ];

    call subset_sum ( w, t, r, c, ind )

    c = [ 2, 3, 5 ]
    index = 22

  Licensing:

    I don't care what you do with this code.

  Modified:

    02 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the size of the subset.

    Input, int W[N], a set of weights.  The length of this
    array must be no more than 31.

    Input, int T, the target value.

    Input, int IND_MIN, IND_MAX, the lower and upper
    limits to be searched.  0 <= IND_MIN <= IND_MAX <= (2^N)-1.

    Output, int *IND, the index of the solution.
    If IND is -1, no solution was found in the range.

    Output, int SUBSET_SUM_FIND[N], indicates the solution, assuming
    that IND is not -1.  In that case, the sum T is made by selecting
    those weights W(I) for which C(I) is 1.  In fact,
    T = sum ( 1 <= I <= N ) C(I) * W(I).
*/
{
  int *c;
  int ind_max2;
  int ind_min2;
/*
  Check the data.
*/
  if ( n < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "SUBSET_SUM_FIND - Fatal error!\n" );
    fprintf ( stderr, "  N < 1.\n" );
    exit ( 1 );
  }

  if ( 31 < n )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "SUBSET_SUM_FIND - Fatal error!\n" );
    fprintf ( stderr, "  31 < N.\n" );
    exit ( 1 );
  }

  ind_min2 = i4_max ( ind_min, 0 );
  ind_max2 = i4_min ( ind_max, i4_power ( 2, n ) - 1 );
/*
  Run through the range.
*/
  printf ( "\n" );
  printf ( "  Searching from IND_MIN = %d", ind_min2 );
  printf ( "  through IND_MAX = %d\n", ind_max2 );

  for ( *ind = ind_min2; *ind <= ind_max2; (*ind)++ )
  {
/*
  Convert INDEX into vector of indices in W.
*/
    c = i4_to_digits_binary ( *ind, n );
/*
  If the sum of those weights matches the target, return combination.
*/
    if ( i4vec_dot_product ( n, c, w ) == t )
    {
      return c;
    }

    free ( c );
  }

  *ind = - 1;

  return NULL;
}
/******************************************************************************/

int subset_sum_find_test ( int n, int w[], int t, int ind_min, int ind_max )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_FIND_TEST tests SUBSET_SUM_FIND.

  Licensing:

    I don't care what you do with this code.

  Modified:

    10 November 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of weights.

    Input, int W[N], a set of weights.  The length of this
    array must be no more than 31.

    Input, int T, the target value.

    Input, int IND_MIN, IND_MAX, the lower and upper
    limits to be searched.

    Output, int SUBSET_SUM_FIND_TEST, the index of a solution, if found,
    or the value -1 otherwise.
*/
{
  int *c;
  int ind;

  printf ( "\n" );
  printf ( "SUBSET_SUM_FIND_TEST:\n" );
  printf ( "  SUBSET_SUM_FIND seeks a subset of W that sums to T.\n" );
  printf ( "\n" );
  printf ( "  Target value T = %d\n", t );
  i4vec_print ( n, w, "  Weight vector W:" );

  c = subset_sum_find ( n, w, t, ind_min, ind_max, &ind );

  if ( ind == -1 )
  {
    printf ( "\n" );
    printf ( "  No solution was found.\n" );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Solution index = %d\n", ind );
    i4vec_print ( n, c, "  Solution:" );
  }
  free ( c );

  return ind;
}
/******************************************************************************/

void subset_sum_find_tests ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_FIND_TESTS tests SUBSET_SUM_FIND_TEST.

  Licensing:

    I don't care what you do with this code.

  Modified:

    10 November 2015

  Author:

    John Burkardt
*/
{
  int ind;
  int ind_max;
  int ind_min;
  int n;
  int t;
  int test;
  int test_num = 9;
  int *w;
  static int w01[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w02[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w03[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w04[10] = { 267,  493,  869,  961, 1000, 1153, 1246, 1598, 1766, 1922 };
  static int w05[21] = {518533, 1037066, 2074132, 1648264, 796528, 
             1593056,  686112, 1372224,  244448, 488896, 
              977792, 1955584, 1411168,  322336, 644672, 
             1289344,   78688,  157376,  314752, 629504, 
             1259008};
  static int w06[10] = { 41, 34, 21, 20,  8,  7,  7,  4,  3,  3 };
  static int w07[9] = { 81, 80, 43, 40, 30, 26, 12, 11, 9 };
  static int w08[6] = { 1, 2, 4, 8, 16, 32 };
  static int w09[10] = { 25, 27, 3, 12, 6, 15, 9, 30, 21, 19 };

  printf ( "\n" );
  printf ( "SUBSET_SUM_FIND_TESTS:\n" );
  printf ( "  SUBSET_SUM_FIND_TEST calls SUBSET_SUM_FIND\n" );
  printf ( "  with a particular set of problem data.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    if ( test == 1 )
    {
      n = 8;
      w = i4vec_copy_new ( n, w01 );
      t = 53;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 2 )
    {
      n = 8;
      w = i4vec_copy_new ( n, w02 );
      t = 53;
      ind_min = ind + 1;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 3 )
    {
      n = 8;
      w = i4vec_copy_new ( n, w03 );
      t = 53;
      ind_min = ind + 1;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 4 )
    {
      n = 10;
      w = i4vec_copy_new ( n, w04 );
      t = 5842;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 5 )
    {
      n = 21;
      w = i4vec_copy_new ( n, w05 );
      t = 2463098;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 6 )
    {
      n = 10;
      w = i4vec_copy_new ( n, w06 );
      t = 50;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 7 )
    {
      n = 9;
      w = i4vec_copy_new ( n, w07 );
      t = 100;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 8 )
    {
      n = 6;
      w = i4vec_copy_new ( n, w08 );
      t = 22;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }
    else if ( test == 9 )
    {
      n = 10;
      w = i4vec_copy_new ( n, w09 );
      t = 50;
      ind_min = 0;
      ind_max = i4_power ( 2, n ) - 1;
    }

    ind = subset_sum_find_test ( n, w, t, ind_min, ind_max );

    free ( w );
  }

  return;
}
/******************************************************************************/

void subset_sum_next ( int s, int n, int v[], bool *more, int u[], int *t )
 
/******************************************************************************/
/*
  Purpose:
  
    SUBSET_SUM_NEXT seeks, one at a time, subsets of V that sum to S.

  Licensing:

    I don't care what you do with this code.

  Modified:

    15 July 2017

  Author:

    John Burkardt

  Parameters:

    Input, int S, the desired sum.

    Input, int N, the number of values.

    Input, int V[N], the values.
    These must be nonnegative, and sorted in ascending order.  
    Duplicate values are allowed.

    Input/output, bool *MORE, should be set to FALSE before the first call.
    Thereafter, on output, MORE is TRUE if a solution is being returned,
    and FALSE if there are no more solutions.

    Input/output, int U[N], should be set to 0 before the 
    first call.  On output with MORE TRUE, U indexes the selected entries
    of V that form a solution.

    Input/output, int *T, should be set to -1 before the first 
    call.  On output, if MORE is true, T is the highest index of the selected 
    values, although this is of little interest to the user.
*/
{
  int i;
  int su;

  if ( ! *more )
  {
    *t = -1;
    for ( i = 0; i < n; i++ )
    {
      u[i] = 0;
    }
  }
  else
  {
    *more = false;
    u[*t] = 0;

    *t = backup_one ( n, u, *t );
    
    if ( *t < 0 )
    {
      return;
    }

    u[*t] = 0;
    *t = *t + 1;
    u[*t] = 1;   
  }
    
  while ( true )
  {
    su = i4vec_dot_product ( n, u, v );
  
    if ( su < s && *t < n - 1 )
    {
      *t = *t + 1;
      u[*t] = 1;
    }
    else
    {
      if ( su == s )
      {
        *more = true;
        return;
      }

      u[*t] = 0;

      *t = backup_one ( n, u, *t );
      
      if ( *t < 0 )
      {
        break;
      }

      u[*t] = 0;
      *t = *t + 1;
      u[*t] = 1; 
    }
  }

  return;
}
/******************************************************************************/

void subset_sum_next_test ( int s, int n, int v[] )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_NEXT_TEST tests the SUBSET_SUM_NEXT library.

  Licensing:

    I don't care what you do with this code.

  Modified:

    15 July 2017

  Author:

    John Burkardt

  Parameters:

    Input, int S, the desired sum.

    Input, int N, the number of values.

    Input, int V[N], the values.
    These must be nonnegative, and sorted in ascending order.  
    Duplicate values are allowed.
*/
{
  int i;
  int k;
  bool more;
  bool plus;
  int t;
  int *u;

  printf ( "\n" );
  printf ( "SUBSET_SUM_NEXT_TEST:\n" );
  printf ( "  SUBSET_SUM_NEXT finds the next subset of the values V\n" );
  printf ( "  which sum to the desired total S.\n" );

  more = false;
  u = ( int * ) malloc ( n * sizeof ( int ) );
  for ( i = 0; i < n; i++ )
  {
    u[i] = 0;
  }
  t = -1;
  
  printf ( "\n" );
  printf ( "  Desired sum S = %d\n", s );
  printf ( "  Number of targets = %d\n", n );
  printf ( "  Targets:" );
  for ( i = 0; i < n; i++ )
  {
    printf ( " %d", v[i] );
  }
  printf ( "\n" );
  printf ( "\n" );

  k = 0;
  
  while ( true )
  {
    subset_sum_next ( s, n, v, &more, u, &t );
    if ( ! more )
    {
      break;
    }
    k = k + 1;
    printf ( "  %d:  %d =", k, s );
    plus = false;
    for ( i = 0; i < n; i++ )
    {
      if ( u[i] != 0 )
      {
        if ( plus )
        {
          printf ( " +" );
        }
        printf ( " %d", v[i] );
        plus = true;
      }
    }
    printf ( "\n" );
  }
   
  free ( u );

  return;
}
/******************************************************************************/

void subset_sum_next_tests ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_NEXT_TESTS calls SUBSET_SUM_NEXT_TEST with various values.

  Licensing:

    I don't care what you do with this code.

  Modified:

    15 July 2017

  Author:

    John Burkardt
*/
{
  int n;
  int s;
  int *v;
  static int v01[5] = { 1, 2, 3, 5, 7 };
  static int v02[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  static int v03[9] = { 1, 2, 3, 3, 5, 6, 7, 8, 9 };
  static int v04[5] = { 1, 2, 3, 5, 7 };
  static int v05[10] = { 267, 493, 869, 961, 1000, 1153, 1246, 1598, 1766, 1922 };

  printf ( "\n" );
  printf ( "SUBSET_SUM_NEXT_TESTS:\n" );
  printf ( "  SUBSET_SUM_NEXT_TEST solves the subset sum problem\n" );
  printf ( "  for specific values of S, N and V.\n" );
  
  s = 9;
  n = 5;
  v = i4vec_copy_new ( n, v01 );
  subset_sum_next_test ( s, n, v );
  free ( v );
  
  s = 8;
  n = 9;
  v = i4vec_copy_new ( n, v02 );
  subset_sum_next_test ( s, n, v );
  free ( v );
/*
  What happens with a repeated target?
*/
  s = 8;
  n = 9;
  v = i4vec_copy_new ( n, v03 );
  subset_sum_next_test ( s, n, v );
  free ( v );
/*
  What happens with a target that needs all the values?
*/
  s = 18;
  n = 5;
  v = i4vec_copy_new ( n, v04 );
  subset_sum_next_test ( s, n, v );
  free ( v );
/*
  A larger S.
*/
  s = 5842;
  n = 10;
  v = i4vec_copy_new ( n, v05 );
  subset_sum_next_test ( s, n, v );
  free ( v );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SUBSET_SUM_NEXT_TESTS:\n" );
  printf ( "  Normal end of execution.\n" );
  
  return;
}
/******************************************************************************/

int *subset_sum_table ( int t, int n, int w[] )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_TABLE sets a subset sum table.

  Discussion:

    The subset sum problem seeks to construct the value T by summing a 
    subset of the values W.

    This function seeks a solution by constructing a table TABLE of length T,
    so that TABLE(I) = J means that the sum I can be constructed, and that
    the last member of the sum is an entry of W equal to J.

  Example:

    w = [ 1, 2, 4, 8, 16, 32 ];
    t = 22;

    table = subset_sum ( w, t, r )
    table = [ 1, 2, 2, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 
      16, 16, 16, 16, 16, 16, 16 ]

  Licensing:

    I don't care what you do with this code.

  Modified:

    11 November 2015

  Author:

    John Burkardt

  Parameters:

    Input, int T, the target value.

    Input, int N, the number of weights.

    Input, int W[N], the weights.

    Output, int SUBSET_SUM_TABLE[T], the subset sum table.  TABLE(I) is 
    0 if the target value I cannot be formed.  It is J if the value I can 
    be formed, with the last term in the sum being the value J.
*/
{
  int i;
  int j;
  int *table;

  table = ( int * ) malloc ( ( t + 1 ) * sizeof ( int ) );

  for ( i = 0; i <= t; i++ )
  {
    table[i] = 0;
  }

  for ( i = 0; i < n; i++ )
  {
    for ( j = t - w[i]; 0 <= j; j-- )
    {
      if ( j == 0 )
      {
        if ( table[w[i]] == 0 )
        {
          table[w[i]] = w[i];
        }
      }
      else if ( table[j] != 0 && table[j+w[i]] == 0 )
      {
        table[j+w[i]] = w[i];
      }
    }
  }
  
  return table;
}
/******************************************************************************/

void subset_sum_table_test ( int t, int n, int w[] )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_TABLE_TEST tests SUBSET_SUM_TABLE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    11 November 2015

  Author:

    John Burkardt

  Parameters:

    Input, int T, the target value.

    Input, int N, the number of weights.

    Input, int W[N], a set of weights.  The length of this
    array must be no more than 31.
*/
{
  int i;
  int *list;
  int m;
  int *table;

  printf ( "\n" );
  printf ( "SUBSET_SUM_TABLE_TEST:\n" );
  printf ( "  SUBSET_SUM_TABLE seeks a subset of W that sums to T.\n" );
  printf ( "\n" );
  printf ( "  Target value T = %d\n", t );
  i4vec_print ( n, w, "  Weight vector W:" );

  table = subset_sum_table ( t, n, w );

  m = subset_sum_table_to_list_length ( t, table );

  printf ( "\n" );

  if ( m == 0 )
  {
    printf ( "  No solution was found.\n" );
  }
  else
  {
    list = subset_sum_table_to_list ( t, table, m );
    printf ( "  %d = ", t );
    for ( i = 0; i < m; i++ )
    {
      if ( 0 < i )
      {
        printf ( " + " );
      }
      printf ( "%d", list[i] );
    }
    printf ( "\n" );
    free ( list );
  }
  free ( table );

  return;
}
/******************************************************************************/

void subset_sum_table_tests ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_TABLE_TESTS tests SUBSET_SUM_TABLE_TEST.

  Licensing:

    I don't care what you do with this code.

  Modified:

    11 November 2015

  Author:

    John Burkardt
*/
{
  int n;
  int t;
  int test;
  int test_num = 7;
  int *w;
  static int w01[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  static int w02[10] = { 267,  493,  869,  961, 1000, 1153, 1246, 1598, 1766, 1922 };
  static int w03[21] = {
              518533, 1037066, 2074132, 1648264, 796528, 
             1593056,  686112, 1372224,  244448, 488896, 
              977792, 1955584, 1411168,  322336, 644672, 
             1289344,   78688,  157376,  314752, 629504, 
             1259008};
  static int w04[10] = { 41, 34, 21, 20,  8,  7,  7,  4,  3,  3 };
  static int w05[9] = { 81, 80, 43, 40, 30, 26, 12, 11, 9 };
  static int w06[6] = { 1, 2, 4, 8, 16, 32 };
  static int w07[10] = { 25, 27, 3, 12, 6, 15, 9, 30, 21, 19 };

  printf ( "\n" );
  printf ( "SUBSET_SUM_COUNT_TESTS:\n" );
  printf ( "  SUBSET_SUM_COUNT_TEST calls SUBSET_SUM_COUNT with\n" );
  printf ( "  a particular set of problem data.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    if ( test == 1 )
    {
      t = 53;
      n = 8;
      w = i4vec_copy_new ( n, w01 );
    }
    else if ( test == 2 )
    {
      t = 5842;
      n = 10;
      w = i4vec_copy_new ( n, w02 );
    }
    else if ( test == 3 )
    {
      t = 2463098;
      n = 21;
      w = i4vec_copy_new ( n, w03 );
    }
    else if ( test == 4 )
    {
      t = 50;
      n = 10;
      w = i4vec_copy_new ( n, w04 );
    }
    else if ( test == 5 )
    {
      t = 100;
      n = 9;
      w = i4vec_copy_new ( n, w05 );
    }
    else if ( test == 6 )
    {
      t = 22;
      n = 6;
      w = i4vec_copy_new ( n, w06 );
    }
    else if ( test == 7 )
    {
      t = 50;
      n = 10;
      w = i4vec_copy_new ( n, w07 );
    }

    subset_sum_table_test ( t, n, w );

    free ( w );
  }

  return;
}
/******************************************************************************/

int *subset_sum_table_to_list ( int t, int table[], int m )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_TABLE_TO_LIST converts a subset sum table to a list.

  Discussion:

    The subset sum problem seeks to construct the value T by summing a 
    subset of the values W.

    This function takes a table computed by subset_sum_table() and converts
    it to the corresponding list of values that form the sum.

  Example:

    t = 22
    n = 6
    w = [ 1, 2, 4, 8, 16, 32 ]
    call subset_sum ( t, n, w, table )
    table = [ 1, 2, 2, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 
      16, 16, 16, 16, 16, 16, 16 ]

    call subset_sum_table_to_list ( t, table, m, list )
    m = 3
    list = [ 2, 4, 16 ]

  Licensing:

    I don't care what you do with this code.

  Modified:

    11 November 2015

  Author:

    John Burkardt

  Parameters:

    Input, int T, the target value.

    Input, int TABLE(T), the subset sum table.

    Input, int M, the number of items in the list.

    Output, int LIST[M], the weights that sum to T.
*/
{
  int i;
  int *list;
/*
  Create list.
*/
  list = ( int * ) malloc ( m * sizeof ( int ) );
/*
  Populate list.
*/
  i = t;
  m = 0;
  while ( 0 < i )
  {
    list[m] = table[i];
    m = m + 1;
    i = i - table[i];
  }
  return list;
}
/******************************************************************************/

int subset_sum_table_to_list_length ( int t, int table[] )

/******************************************************************************/
/*
  Purpose:

    SUBSET_SUM_TABLE_TO_LIST_LENGTH returns the length of a list.

  Discussion:

    The subset sum problem seeks to construct the value T by summing a 
    subset of the values W.

    This function takes a table computed by subset_sum_table() and converts
    it to the corresponding list of values that form the sum.

  Example:

    t = 22
    n = 6
    w = [ 1, 2, 4, 8, 16, 32 ]
    call subset_sum ( t, n, w, table )
    table = [ 1, 2, 2, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 
      16, 16, 16, 16, 16, 16, 16 ]

    call subset_sum_table_to_list ( t, table, m, list )
    m = 3
    list = [ 2, 4, 16 ]

  Licensing:

    I don't care what you do with this code.

  Modified:

    11 November 2015

  Author:

    John Burkardt

  Parameters:

    Input, integer T, the target value.

    Input, integer TABLE[T], the subset sum table.

    Output, int SUBSET_SUM_TABLE_TO_LIST_LENGTH, the number of items in the list.
    If M == 0, then no solution was found and the list is empty.
*/
{
  int i;
  int m;
/*
  Determine length of list.
*/
  i = t;
  m = 0;
  while ( 0 < i )
  {
    m = m + 1;
    i = i - table[i];
  }
  return m;
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

    I don't care what you do with this code.

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
