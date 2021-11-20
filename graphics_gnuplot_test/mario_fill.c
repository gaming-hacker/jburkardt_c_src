# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for MARIO_FILL.

  Discussion:

    MARIO_FILL creates an image of Mario using colored squares.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 April 2018

  Author:

    John Burkardt
*/
{
  char color[16];
  int color_index[16*13] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 5, 5, 0, 0, 6, 
     0, 0, 0, 6, 6, 6, 0, 0, 2, 2, 5, 5, 5, 0, 6, 6, 
     0, 2, 6, 5, 5, 6, 0, 2, 2, 2, 2, 5, 3, 3, 6, 6, 
     2, 2, 6, 6, 6, 5, 5, 2, 2, 2, 3, 3, 3, 3, 6, 6, 
     2, 2, 6, 5, 6, 5, 5, 3, 3, 3, 4, 3, 3, 3, 0, 0, 
     2, 2, 5, 5, 5, 5, 5, 2, 2, 3, 3, 3, 3, 0, 0, 0, 
     2, 2, 5, 5, 5, 5, 5, 2, 2, 3, 3, 3, 3, 0, 0, 0, 
     2, 2, 5, 5, 5, 5, 5, 2, 3, 3, 4, 3, 3, 3, 0, 0, 
     2, 2, 1, 1, 5, 1, 5, 2, 2, 2, 3, 3, 3, 3, 6, 6, 
     0, 2, 5, 5, 1, 1, 5, 0, 2, 2, 2, 5, 3, 3, 6, 6, 
     0, 2, 0, 5, 5, 1, 5, 0, 2, 2, 5, 5, 5, 0, 6, 6, 
     0, 2, 0, 5, 5, 1, 0, 0, 0, 2, 5, 5, 5, 0, 0, 6, 
     0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  char command_filename[] = "mario_commands.txt";
  FILE *command_unit;
  int i;
  int i_reverse;
  int j;
  int k;
  int m = 16;
  int n = 13;
  char plot_filename[] = "mario_fill.png";

  printf ( "\n" );
  printf ( "MARIO_FILL\n" );
  printf ( "  C version\n" );
  printf ( "  Create a GNUPLOT input file that will draw a\n" );
  printf ( "  picture of Mario, using colored squares.\n" );
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );
  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output '%s'\n", plot_filename );
  fprintf ( command_unit, "set title 'MARIO'\n" );
/*
  Trying to get a plot with TRUE SQUARES was exasperatingly awkward.
*/
  fprintf ( command_unit, "set xrange [ -1.5 : 14.5 ]\n" );
  fprintf ( command_unit, "set yrange [ 0 : 16 ]\n" );
  fprintf ( command_unit, "set size square\n" );
  fprintf ( command_unit, "unset border\n" );
  fprintf ( command_unit, "unset tics\n" );
  fprintf ( command_unit, "set nokey\n" );

  k = 0;
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      k = k + 1;

      if ( color_index[i+j*m] == 0 )
      {
        strcpy ( color, "white" );
      }
      else if ( color_index[i+j*m] == 1 )
      {
        strcpy ( color, "black" );
      }
      else if ( color_index[i+j*m] == 2 )
      {
        strcpy ( color, "red" );
      }
      else if ( color_index[i+j*m] == 3 )
      {
        strcpy ( color, "blue" );
      }
      else if ( color_index[i+j*m] == 4 )
      {
        strcpy ( color, "yellow" );
      }
/*
  The next color should be 'blanchedalmond' but stoopid GNUPLOT won't take
  it as a string.'
*/
      else if ( color_index[i+j*m] == 5 )
      {
        strcpy ( color, "#FFEBCD" );
      }
      else if ( color_index[i+j*m] == 6 )
      {
        strcpy ( color, "brown" );
      }

      i_reverse = m - 1 - i;
      fprintf ( command_unit, 
        "set object %d rect from %d, %d  to %d, %d back\n",
        k, j, i_reverse, j + 1, i_reverse + 1 );
      fprintf ( command_unit, 
        "set object %d rect fc rgb '%s' fillstyle solid 1.0\n", k, color );
    }
  }
/*
  If you don't have some bogus PLOT command here, all the previous work
  results in no plot all.  Way to go, gnuplot!
  Here, we plot the function y = -1, which is out of range and won't show up.
*/
  fprintf ( command_unit, "plot -1 with lines\n" );
  fclose ( command_unit );

  printf ( "  Created command file '%s'\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "MARIO_FILL:\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
