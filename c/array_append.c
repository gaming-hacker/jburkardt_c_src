# include <stdio.h>
# include <stdlib.h>

int main ( );
void i4vec_append ( int *n, int **a, int value );
void i4vec_print ( int n, int a[], char *title );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ARRAY_APPEND.

  Discussion:

    Given an existing array of length N, we wish to append one entry
    to the end.  This requires creating a new array one entry longer,
    copying the data, and switching names.

    This time, I didn't need Miro's help.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 May 2018

  Author:

    John Burkardt
*/
{
  int *a;
  int i;
  int n;
  int value;

  printf ( "\n" );
  printf ( "ARRAY_APPEND:\n" );
  printf ( "  C version\n" );
  printf ( "  Append one entry to an array.\n" );
/*
  Initialize the array.
*/
  n = 5;
  a = ( int * ) malloc ( n * sizeof ( int ) );
  for ( i = 0; i < n; i++ )
  {
    a[i] = i;
  }
/*
  Display the current array.
*/
  i4vec_print ( n, a, "  A, as initialized:" );
/*
  Append the value 17 to the array.
*/
  value = 17;
  i4vec_append ( &n, &a, value );
/*
  Display the modified array.
*/
  i4vec_print ( n, a, "  A, after appending" );
/*
  Free memory.
*/
  free ( a );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ARRAY_APPEND:\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
/******************************************************************************/

void i4vec_append ( int *n, int **a, int value )

/******************************************************************************/
/*
  Purpose:

    I4VEC_APPEND appends an entry to an I4VEC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 May 2018

  Author:

    John Burkardt

  Parameters:

    Input/output, int *N, the current size of the array.  On output,
    the array is one entry longer.

    Input/output, int **A, the array.  On output, the array has had 
    VALUE appended.

    Input, int VALUE, a value to be appended to A.
*/
{
  int *a_old;
  int i;
/*
  Save a pointer to the old array.
*/
  a_old = *a;
/*
  Create a new array.
*/
  ( *a ) = ( int * ) malloc ( ( *n + 1 ) * sizeof ( int ) );
/*
  Copy the old data and append the new item.
*/
  for ( i = 0; i < *n; i++ )
  {
    (*a)[i] = a_old[i];
  }
  (*a)[*n] = value;
/*
  Increase N.
*/
  *n = *n + 1;
/*
  Free memory.
*/
  free ( a_old );

  return;
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

    This code is distributed under the GNU LGPL license.

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
