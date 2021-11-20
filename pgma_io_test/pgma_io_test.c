# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "pgma_io.h"

int main ( int argc, char *argv[] );
void pgma_write_test ( char *file_name );
void pgma_read_test ( char *file_name );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PGMA_IO_TEST.

  Discussion:

    PGMA_IO_TEST tests the PGMA_IO library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 May 2017

  Author:

    John Burkardt
*/
{
  char file_name[] = "pgma_io_test.ppm";

  timestamp ( );
  printf ( "\n" );
  printf ( "PGMA_IO_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the PGMA_IO library.\n" );

  pgma_write_test ( file_name );
  pgma_read_test ( file_name );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "PGMA_IO_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void pgma_write_test ( char *file_name )  

/******************************************************************************/
/*
  Purpose:

    PGMA_WRITE_TEST tests PGMA_WRITE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 June 2010

  Author:

    John Burkardt
*/
{
  char comment[] = "File created by pgma_write_test.c";
  int *g;
  double gray[11] = { 
    0.000, 0.291, 0.434, 0.540, 0.629,
    0.706, 0.774, 0.837, 0.895, 0.949,
    1.000 };
  int i;
  int j;
  int k;
  int maxval = 255;
  int ngray = 11;
  int xsize = 300;
  int ysize = 300;

  printf ( "\n" );
  printf ( "PGMA_WRITE_TEST:\n" );
  printf ( "  PGMA_WRITE writes an ASCII PGM file.\n" );
  printf ( "\n" );
  printf ( "  In this example, we make a sort of grayscale checkerboard.\n" );

  g = ( int * ) malloc ( xsize * ysize * sizeof ( int ) );

  for ( i = 0; i < xsize; i++ )
  {
    for ( j = 0; j < ysize; j++ )
    {
      k = ( i + j ) * ngray / i4_min ( xsize, ysize );
      k = k % ngray;
      g[i*ysize+j] = ( int ) ( ( float ) ( maxval ) * gray[k] );
    }
  }

  printf ( "  Writing the file \"%s\".\n", file_name );

  pgma_write ( file_name, comment, xsize, ysize, maxval, g );

  printf ( "\n" );
  printf (  "  Created graphics file '%s'\n", file_name );

  free ( g );

  return;
}
/******************************************************************************/

void pgma_read_test ( char *file_name )  

/******************************************************************************/
/*
  Purpose:

    PGMA_READ_TEST tests PGMA_READ_HEADER, PGMA_READ_DATA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 May 2017

  Author:

    John Burkardt
*/
{
  int *g;
  int i;
  int j;
  int k;
  int maxg;
  int xsize;
  int ysize;

  printf ( "\n" );
  printf ( "PGMA_READ_TEST\n" );
  printf ( "  PGMA_READ reads the header and data of an ASCII PGM file.\n" );
  printf ( "\n" );
  printf ( "  Reading the file \"%s\".\n", file_name );

  pgma_read ( file_name, &xsize, &ysize, &maxg, &g );

  printf ( "\n" );
  printf ( "  PGMA_READ read the test data successfully.\n" );

  printf ( "\n" );
  printf ( "  Sample data:\n" );
  printf ( "\n" );
  for ( k = 0; k <= 9; k++ )
  {
    i = ( ( 9 - k ) * 0 + k * ( xsize - 1 ) ) / 9;
    j = ( ( 9 - k ) * 0 + k * ( ysize - 1 ) ) / 9;
    printf ( "%4d  %4d  %6d\n", i, j, g[i*ysize+j] );
  }

  free ( g );

  return;
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

    This code is distributed under the GNU LGPL license. 

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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
