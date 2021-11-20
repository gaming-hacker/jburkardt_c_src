# include <stdio.h>

# include "ppc_array.h"

int main ( );
void make_matrix_float_test ( );
void make_matrix_double_test ( );
void make_vector_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    ppc_array_test tests ppc_array.

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
  printf ( "ppc_array_test:\n" );
  printf ( "  C version\n" );
  printf ( "  Test functions for creating vectors and arrays.\n" );

  make_vector_test ( );
  make_matrix_double_test ( );
  make_matrix_float_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ppc_array_test:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void make_matrix_float_test ( )

/******************************************************************************/
/*
  Purpose:

    make_matrix_float_test tests make_matrix_float().

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
  size_t m = 5;
  size_t n = 4;

  printf ( "\n" );
  printf ( "make_matrix_float_test:\n" );
  printf ( "  Test make_matrix_float() and free_matrix_float().\n" );

  h = make_matrix_float(m,n);

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
  free_matrix_float(h);

  return;
}
/******************************************************************************/

void make_matrix_double_test ( )

/******************************************************************************/
/*
  Purpose:

    make_matrix_double_test tests make_matrix_double().

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
  size_t m = 5;
  size_t n = 4;

  printf ( "\n" );
  printf ( "make_matrix_double_test:\n" );
  printf ( "  Test make_matrix_double() and free_matrix_double().\n" );

  h = make_matrix_double(m,n);

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
  free_matrix_double(h);

  return;
}
/******************************************************************************/

void make_vector_test ( )

/******************************************************************************/
/*
  Purpose:

    make_vector_test tests make_vector().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt
*/
{
  int i;
  size_t n = 5;
  double *v;

  printf ( "\n" );
  printf ( "make_vector_test:\n" );
  printf ( "  Test make_vector() and free_vector().\n" );

  make_vector(v,n);

  for ( i = 0; i < n; i++ )
  {
    v[i] = 1.0 / ( double ) ( i + 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %10f\n", v[i] );
  }
  free_vector(v);

  return;
}
