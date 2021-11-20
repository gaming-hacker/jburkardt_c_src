# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "polyominoes.h"

int main ( );
void pentomino_matrix_test ( );
void pentomino_plot_test ( );
void polyomino_condense_test ( );
void polyomino_condense_demo ( int mp, int np, int p[] );
void polyomino_embed_test ( );
void polyomino_embed_list_test ( );
void polyomino_embed_number_test ( );
void polyomino_enumerate_test ( );
void polyomino_enumerate_chiral_test ( );
void polyomino_enumerate_fixed_test ( );
void polyomino_enumerate_free_test ( );
void polyomino_index_test ( );
void polyomino_lp_write_test ( );
void polyomino_transform_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for polyominoes_test.

  Discussion:

    polyominoes_test tests polyominoes().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 April 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "polyominoes_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test polyominoes().\n" );

  pentomino_matrix_test ( );
  pentomino_plot_test ( );
  polyomino_condense_test ( );
  polyomino_embed_test ( );
  polyomino_enumerate_test ( );
  polyomino_index_test ( );
  polyomino_lp_write_test ( );
  polyomino_transform_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "polyominoes_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void pentomino_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    PENTOMINO_MATRIX_TEST tests PENTOMINO_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 April 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  char name;
  int *p;
  int p_m;
  int p_n;
  char polyominoes[12] = 
    { 'F', 'I', 'L', 'N', 'P', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

  printf ( "\n" );
  printf ( "PENTOMINO_MATRIX_TEST\n" );
  printf ( "  PENTOMINO_MATRIX returns a 0/1 matrix representing a pentomino.\n" );

  for ( k = 0; k < 12; k++ )
  {
    name = polyominoes[k];
    pentomino_matrix ( name, &p_m, &p_n, &p );
    printf ( "\n" );
    printf ( "  %c pentomino (%d,%d):\n", name, p_m, p_n );
    printf ( "\n" );
    for ( i = 0; i < p_m; i++ )
    {
      printf ( "    " );
      for ( j = 0; j < p_n; j++ )
      {
        printf ( "%d", p[i*p_n+j] );
      }
      printf ( "\n" );
    }
    free ( p );
  }

  return;
}
/******************************************************************************/

void pentomino_plot_test ( )

/******************************************************************************/
/*
  Purpose:

    PENTOMINO_PLOT_TEST tests PENTOMINO_PLOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 April 2018

  Author:

    John Burkardt
*/
{
  int k;
  char label[2];
  char name;
  int *p;
  int p_m;
  int p_n;
  char polyominoes[12] = 
    { 'F', 'I', 'L', 'N', 'P', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

  printf ( "\n" );
  printf ( "PENTOMINO_PLOT_TEST\n" );
  printf ( "  PENTOMINO_PLOT plots a pentomino.\n" );

  for ( k = 0; k < 12; k++ )
  {
    name = polyominoes[k];
    sprintf ( label, "%c", name );
    pentomino_matrix ( name, &p_m, &p_n, &p );
    pentomino_plot ( p_m, p_n, p, label );
  }

  return;
}
/******************************************************************************/

void polyomino_condense_test ( )

/******************************************************************************/
/*
  Purpose:

    polyomino_condense_test tests POLYOMINO_CONDENSE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 April 2018

  Author:

    John Burkardt

  Local parameters:

    Local, int MP, NP, the number of rows and columns in the representation
    of the polyomino P.

    Local, int P[MP*NP], a matrix representing the polyomino.  
*/
{
  int mp;
  int np;
  int p1[] = { 0, 1, 1, 1, 1, 0, 0, 1, 0 };
  int p2[] = { 0, 1, 2, 1, 3, 0, 0, -9, 0 };
  int p3[] = { 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0 };
  int p4[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

  timestamp ( );
  printf ( "\n" );
  printf ( "POLYOMINO_CONDENSE_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  POLYOMINO_CONDENSE 'cleans up' a matrix that is supposed\n" );
  printf ( "  to represent a polyomino:\n" );
  printf ( "  * nonzero entries are set to 1;\n" );
  printf ( "  * initial and final zero rows and columns are deleted.\n" );
/*
  Nothing happens:
*/
  mp = 3;
  np = 3;
  polyomino_condense_demo ( mp, np, p1 );
/*
  Nonzero, but non-one entries are set to 1.
*/
  mp = 3;
  np = 3;
  polyomino_condense_demo ( mp, np, p2 );
/*
  Extraneous zero rows and columns are removed.
*/
  mp = 3;
  np = 4;
  polyomino_condense_demo ( mp, np, p3 );
/*
  Null matrices are detected.
*/
  mp = 2;
  np = 4;
  polyomino_condense_demo ( mp, np, p4 );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYOMINO_CONDENSE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return;
}
/******************************************************************************/

void polyomino_condense_demo ( int mp, int np, int p[] )

/******************************************************************************/
/*
  Purpose:

    polyomino_condense_demo demonstrates polyomino_condense.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 April 2018

  Author:

    John Burkardt

  Parameters:

    Input, int MP, NP, the number of rows and columns in the representation
    of the polyomino P.

    Input, int P[MP*NP], a matrix representing the polyomino.  

    Local, int MQ, NQ, the number of rows and columns in the representation
    of the condensed polyomino Q.

    Local, int Q[MQ*NQ], a matrix representing the condensed polyomino.  
*/
{
  char label[80];
  int mq;
  int nq;
  int *q;

  sprintf ( label, "  The initial (%d,%d) polynomino P:", mp, np );
  polyomino_print ( mp, np, p, label );

  polyomino_condense ( mp, np, p, &mq, &nq, &q );

  sprintf ( label, "  The condensed (%d,%d) polynomino Q:", mq, nq );
  polyomino_print ( mq, nq, q, label );
  free ( q );

  return;
}
/******************************************************************************/

void polyomino_embed_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYOMINO_EMBED_TEST tests POLYOMINO_EMBED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 May 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "POLYOMINO_EMBED_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the POLYOMINO_EMBED library.\n" );

  polyomino_embed_number_test ( );
  polyomino_embed_list_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYOMINO_EMBED_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return;
}
/******************************************************************************/

void polyomino_embed_list_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYOMINO_EMBED_LIST_TEST tests POLYOMINO_EMBED_LIST.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 May 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int *list;
  int mk;
  int nk;
  int mp = 3;
  int mq;
  int mr = 4;
  int np = 2;
  int nq;
  int nr = 4;
  int number;
  int p[3*2] = {
    0, 0, 1,
    1, 1, 1 };
  int q[4*4];
  int r[4*4] = { 
    0, 1, 1, 1,
    1, 1, 1, 0,
    1, 0, 1, 1,
    1, 1, 1, 1 };

  printf ( "\n" );
  printf ( "POLYOMINO_EMBED_LIST_TEST:\n" );
  printf ( "  POLYOMINO_EMBED_LIST lists the offsets used\n" );
  printf ( "  to embed a fixed polyomino in a region.\n" );

  polyomino_print ( mr, nr, r, "  The given region R:" );

  polyomino_print ( mp, np, p, "  The given polyomino P:" );
/*
  Get the number of embeddings.
*/
  number = polyomino_embed_number ( mr, nr, r, mp, np, p );

  printf ( "\n" );
  printf ( "  As a fixed polyomino, P can be embedded in R in %d ways\n", number );
/*
  Get the list of embeddings.
*/
  list = polyomino_embed_list ( mr, nr, r, mp, np, p, number );

  for ( k = 0; k < number; k++ )
  {
    mk = list[k+0*number];
    nk = list[k+1*number];
    mq = mr;
    nq = nr;

    for ( j = 0; j < nq; j++ )
    {
      for ( i = 0; i < mq; i++ )
      {
        q[i+j*mq] = r[i+j*mr];
      }
    }

    for ( j = 0; j < np; j++ )
    {
      for ( i = 0; i < mp; i++ )
      {
        q[i+mk+(j+nk)*mq] = q[i+mk+(j+nk)*mq] + p[i+j*mp];
      }
    }

    printf ( "\n" );
    printf ( "  Embedding number %d:\n", k );
    printf ( "\n" );
    for ( i = 0; i < mq; i++ )
    {
      for ( j = 0; j < nq; j++ )
      {
        printf ( " %d", q[i+j*mq] );
      }
      printf ( "\n" );
    }
  }

  free ( list );

  return;
}
/******************************************************************************/

void polyomino_embed_number_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYOMINO_EMBED_NUMBER_TEST tests POLYOMINO_EMBED_NUMBER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 May 2018

  Author:

    John Burkardt
*/
{
  int mp = 3;
  int mr = 4;
  int np = 2;
  int nr = 4;
  int number;
  int p[3*2] = {
    0, 0, 1,
    1, 1, 1 };
  int r[4*4] = { 
    0, 1, 1, 1,
    1, 1, 1, 0,
    1, 0, 1, 1,
    1, 1, 1, 1 };

  printf ( "\n" );
  printf ( "POLYOMINO_EMBED_NUMBER_TEST:\n" );
  printf ( "  POLYOMINO_EMBED_NUMBER reports the number of ways a\n" );
  printf ( "  fixed polyomino can be embedded in a region.\n" );

  polyomino_print ( mr, nr, r, "  The given region R:" );

  polyomino_print ( mp, np, p, "  The given polyomino P:" );

  number = polyomino_embed_number ( mr, nr, r, mp, np, p );

  printf ( "\n" );
  printf ( "  As a fixed polyomino, P can be embedded in R in %d ways\n", number );

  return;
}
/******************************************************************************/

void polyomino_enumerate_test ( )

/******************************************************************************/
/*
  Purpose:

    polyomino_enumerate_test tests the POLYOMINO_ENUMERATE library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 May 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "POLYOMINO_ENUMERATE_TEST:\n" );
  printf ( "  C version,\n" );
  printf ( "  POLYOMINO_ENUMERATE enumerates several types of polyomino.\n" );

  polyomino_enumerate_chiral_test ( );
  polyomino_enumerate_fixed_test ( );
  polyomino_enumerate_free_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYOMINO_ENUMERATE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return;
}
/******************************************************************************/

void polyomino_enumerate_chiral_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYOMINO_ENUMERATE_CHIRAL_TEST tests POLYOMINO_CHIRAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 May 2018

  Author:

    John Burkardt
*/
{
  int n_data;
  long long int number;
  int order;

  printf ( "\n" );
  printf ( "POLYOMINO_ENUMERATE_CHIRAL_TEST:\n" );
  printf ( "  POLYOMINO_ENUMERATE_CHIRAL returns the number of chiral\n" );
  printf ( "  polyominoes of a given order;\n" );

  n_data = 0;
  printf ( "\n" );
  printf ( "   Order      Number\n" );
  printf ( "\n" );

  for ( ; ; )
  {
    polyomino_enumerate_chiral ( &n_data, &order, &number );

    if ( n_data == 0 )
    {
      break;
    }

    printf ( "  %4d  %24lld\n", order, number );
  }
  return;
}
/******************************************************************************/

void polyomino_enumerate_fixed_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYOMINO_ENUMERATE_FIXED_TEST tests POLYOMINO_FIXED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 May 2018

  Author:

    John Burkardt
*/
{
  int n_data;
  long long int number;
  int order;

  printf ( "\n" );
  printf ( "POLYOMINO_ENUMERATE_FIXED_TEST:\n" );
  printf ( "  POLYOMINO_ENUMERATE_FIXED returns the number of fixed\n" );
  printf ( "  polyominoes of a given order;\n" );

  n_data = 0;
  printf ( "\n" );
  printf ( "   Order      Number\n" );
  printf ( "\n" );

  for ( ; ; )
  {
    polyomino_enumerate_fixed ( &n_data, &order, &number );

    if ( n_data == 0 )
    {
      break;
    }

    printf ( "  %4d  %24lld\n", order, number );
  }
  return;
}
/******************************************************************************/

void polyomino_enumerate_free_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYOMINO_ENUMERATE_FREE_TEST tests POLYOMINO_ENUMERATE_FREE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 May 2018

  Author:

    John Burkardt
*/
{
  int n_data;
  long long int number;
  int order;

  printf ( "\n" );
  printf ( "POLYOMINO_ENUMERATE_FREE_TEST:\n" );
  printf ( "  POLYOMINO_ENUMERATE_FREE returns the number of free\n" );
  printf ( "  polyominoes of a given order;\n" );

  n_data = 0;
  printf ( "\n" );
  printf ( "   Order      Number\n" );
  printf ( "\n" );

  for ( ; ; )
  {
    polyomino_enumerate_free ( &n_data, &order, &number );

    if ( n_data == 0 )
    {
      break;
    }

    printf ( "  %4d  %24lld\n", order, number );
  }
  return;
}
/******************************************************************************/

void polyomino_index_test ( )

/******************************************************************************/
/*
  Purpose:

    polyomino_index_test tests POLYOMINO_INDEX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 April 2018

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m = 3;
  int n = 4;
/*
  P is listed in column-major order;
*/
  int p[3*4] = { 
    1, 1, 0,
    0, 1, 1,
    1, 1, 1,
    1, 0, 0 };
  int *pin;

  timestamp ( );
  printf ( "\n" );
  printf ( "POLYOMINO_INDEX_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  POLYOMINO_INDEX assigns an index to each nonzero entry\n" );
  printf ( "  of a polyomino.\n" );

  polyomino_print ( m, n, p, "  The polyomino P:" );

  pin = polyomino_index ( m, n, p );

  printf ( "\n" );
  printf ( "  PIN: Index vector for P:\n" );
  printf ( "\n" );
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( " %d", pin[i+j*m] );
    }
    printf ( "\n" );
  }
/*
  Free memory.
*/
  free ( pin );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYOMINO_INDEX_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return;
}
/******************************************************************************/

void polyomino_lp_write_test ( )

/******************************************************************************/
/*
  Purpose:

    polyomino_lp_write_test tests POLYOMINO_LP_WRITE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 May 2018

  Author:

    John Burkardt
*/
{
  int *a;
  int *b;
  char filename[] = "reid.lp";
  char label[] = "\\ LP file for the Reid example, created by POLYOMINO_LP_WRITE.";
  int m;
  int n;

  timestamp ( );
  printf ( "\n" );
  printf ( "POLYOMINO_LP_WRITE_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  POLYOMINO_LP_WRITE writes an LP file associated\n" );
  printf ( "  with a binary programming problem for tiling a region\n" );
  printf ( "  with copies of a single polyomino.\n" );
/*
  Get the coefficients and right hand side for the Reid system.
*/
  polyomino_monohedral_example_reid_size ( &m, &n );

  a = ( int * ) malloc ( m * n * sizeof ( int ) );
  b = ( int * ) malloc ( m * sizeof ( int ) );

  polyomino_monohedral_example_reid_system ( m, n, a, b );
/*
  Create the LP file.
*/
  polyomino_lp_write ( filename, label, m, n, a, b );

  printf ( "\n" );
  printf ( "  Created the LP file '%s'\n", filename );
/*
  Free memory.
*/
  free ( a );
  free ( b );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYOMINO_LP_WRITE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return;
}
/******************************************************************************/

void polyomino_transform_test ( )

/******************************************************************************/
/*
  Purpose:

    polyomino_transform_test tests POLYOMINO_TRANSFORM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 April 2018

  Author:

    John Burkardt

  Local parameters:

    Local, int M, N, the number of rows and columns in the representation
    of the polyomino P.

    Local, int P[M*N], a matrix of 0's and 1's representing the 
    polyomino.  The matrix should be "tight", that is, there should be a
    1 in row 1, and in column 1, and in row M, and in column N.
*/
{
  char label[80];
  int m = 3;
  int mq;
  int n = 3;
  int nq;
/*
  P is given by columns, not rows.
*/
  int p[3*3] = { 
    0, 1, 0,
    1, 1, 1,
    1, 0, 0 }; 
  int *q;
  int reflect;
  int rotate;

  timestamp ( );
  printf ( "\n" );
  printf ( "POLYOMINO_TRANSFORM_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  POLYOMINO_TRANSFORM can transform a polyomino.\n" );
  printf ( "  Generate all 8 combinations of rotation and reflection\n" );
  printf ( "  applied to a polyomino represented by a binary matrix.\n" );

  polyomino_print ( m, n, p, "  The given polyomino P:" );

  for ( reflect = 0; reflect <= 1; reflect ++ )
  {
    for ( rotate = 0; rotate <= 3; rotate++ )
    {
      polyomino_transform ( m, n, p, rotate, reflect, &mq, &nq, &q );

      sprintf ( label, "  P after %d reflections and %d rotations:", reflect, rotate );
      polyomino_print ( mq, nq, q, label );
      free ( q );
    }
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYOMINO_TRANSFORM_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return;
}
