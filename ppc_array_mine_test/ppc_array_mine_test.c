# include <stdio.h>
# include <stdlib.h>

# include "ppc_array_mine.h"

int main ( );
void matrix_double_test ( );
void matrix_float_test ( );
void vector_double_test ( );
void vector_float_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    ppc_array_mine_test tests ppc_array_mine.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ppc_array_mine_test:\n" );
  printf ( "  C version\n" );
  printf ( "  Test functions for creating vectors and arrays.\n" );

  vector_float_test ( );
  vector_double_test ( );
  matrix_float_test ( );
  matrix_double_test ( );
/*
 Terminate.
*/
  printf ( "\n" );
  printf ( "ppc_array_mine_test:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void matrix_double_test ( )

/******************************************************************************/
/*
  Purpose:

    matrix_double_test tests make_matrix_double() and free_matrix_double.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt
*/
{
  double **h;
  int i;
  int j;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "matrix_double_test:\n" );
  printf ( "  Test make_matrix_double() and free_matrix_double().\n" );

  h = make_matrix_double ( m, n );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      h[i][j] = 1.0 / ( double ) ( i + j + 1 );
    }
  }

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %10f", h[i][j] );
    }
    printf ( "\n" );
  }

  free_matrix_double ( h );

  return;
}
/******************************************************************************/

void matrix_float_test ( )

/******************************************************************************/
/*
  Purpose:

    matrix_double_test tests make_matrix_double() and free_matrix_double.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt
*/
{
  float **h;
  int i;
  int j;
  int m = 5;
  int n = 4;

  printf ( "\n" );
  printf ( "matrix_float_test:\n" );
  printf ( "  Test make_matrix_float() and free_matrix_float().\n" );

  h = make_matrix_float ( m, n );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      h[i][j] = 1.0 / ( float ) ( i + j + 1 );
    }
  }

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %10f", h[i][j] );
    }
    printf ( "\n" );
  }

  free_matrix_float ( h );

  return;
}
/******************************************************************************/

void vector_double_test ( )

/******************************************************************************/
/*
  Purpose:

    vector_double_test tests make_vector_double() and free_vector_double().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  double *v;

  printf ( "\n" );
  printf ( "vector_double_test:\n" );
  printf ( "  Test make_vector_double and free_vector_double.\n" );

  v = make_vector_double ( n );

  for ( i = 0; i < n; i++ )
  {
    v[i] = 1.0 / ( double ) ( i + 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %10f\n", v[i] );
  }
  free_vector_double ( v );

  return;
}
/******************************************************************************/

void vector_float_test ( )

/******************************************************************************/
/*
  Purpose:

    vector_float_test tests make_vector_float() and free_vector_float().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  float *v;

  printf ( "\n" );
  printf ( "vector_float_test:\n" );
  printf ( "  Test make_vector_float and free_vector_float.\n" );

  v = make_vector_float ( n );

  for ( i = 0; i < n; i++ )
  {
    v[i] = 1.0 / ( float ) ( i + 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %10f\n", v[i] );
  }
  free_vector_float ( v );

  return;
}
