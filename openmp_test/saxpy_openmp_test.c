# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <omp.h>

int main ( int argc, char *argv[] );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SAXPY.

  Discussion:

    This program simply shows how a SAXPY operation could be
    marked up for OpenMP execution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 May 2017

  Author:

    John Burkardt
*/
{
  int i;
  int n = 10000000;
  float s = 1.5;
  float *x;
  float *y;
  float *z;

  printf ( "\n" );
  printf ( "SAXPY\n" );
  printf ( "  C/OpenMP version\n" );
  printf ( "\n" );
  printf ( "  A program which adds a multiple of one vector to another.\n" );

  printf ( "\n" );
  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );
/*
  Allocate the vector data.
*/
  x = ( float * ) malloc ( n * sizeof ( float ) );
  y = ( float * ) malloc ( n * sizeof ( float ) );
  z = ( float * ) malloc ( n * sizeof ( float ) );
/*
  Begin the parallel region.
*/
# pragma omp parallel private ( i )
{
/*
  Set the vector data.
*/
# pragma omp for
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( float ) ( ( i + 1 ) % 7 );
    y[i] = ( float ) ( ( i + 1 ) % 3 );
  }
/*
  Perform the SAXPY operation.
*/
# pragma omp for
  for ( i = 0; i < n; i++ )
  {
    z[i] = x[i] + s * y[i];
  }
/*
  End the parallel region.
*/
}
/*
  Print a few entries.
*/
  printf ( "\n" );
  printf ( "   i        x[i]        y[i]      z[i]=x[i]+s*y[i]\n" );
  printf ( "\n" );
  for ( i = 0; i < n && i < 10; i++ )
  {
    printf ( "  %2d  %10.4f  %10.4f  %10.4f\n", i, x[i], y[i], z[i] );
  }
/*
  Free memory.
*/
  free ( x );
  free ( y );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SAXPY\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}

