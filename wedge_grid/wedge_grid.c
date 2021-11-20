# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

# include "wedge_grid.h"

/******************************************************************************/

void r8vec_copy ( int n, double a1[], double a2[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_COPY copies an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 July 2005

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], the vector to be copied.

    Input, double A2[N], the copy of A1.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
/******************************************************************************/

double *wedge_grid ( int n, int ng )  

/******************************************************************************/
/*
  Purpose:

    WEDGE_GRID computes grid points in the unit wedge in 3D.

  Discussion:

    The interior of the unit wedge in 3D is defined by the constraints:
      0 <= X
      0 <= Y
           X + Y <= 1
     -1 <= Z <= +1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 August 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of subintervals.
    0 <= N.

    Input, int NG, the number of grid points.
    This can be computed by WEDGE_GRID_SIZE, or else determined by
    NG =(N+1)*((N+1)*(N+2))/2.

    Output, double WEDGE+GRID[3*NG], the coordinates of the grid points.
*/
{
  int i;
  double ir;
  int j;
  double jr;
  int k;
  double kr;
  double nr;
  int p;
  double *g;

  g = ( double * ) malloc ( 3 * ng * sizeof ( double ) );

  if ( n == 0 )
  {
    g[0+0*3] = 0.5;
    g[1+0*3] = 0.5;
    g[2+0*3] = 0.0;
    return g;
  }

  p = 0;
  nr = ( double ) ( n );

  for ( k = 0; k <= n; k++ )
  {
    kr = ( double ) ( 2 * k - n ) / nr;
    for ( j = 0; j <= n; j++ )
    {
      jr = ( double ) ( j ) / nr;
      for ( i = 0; i <= n - j; i++ )
      {
        ir = ( double ) ( i ) / nr;
        g[0+p*3] = ir;
        g[1+p*3] = jr;
        g[2+p*3] = kr;
        p = p + 1;
      }
    }
  }

  return g;
}
/******************************************************************************/

int wedge_grid_size ( int n )  

/******************************************************************************/
/*
  Purpose:

    WEDGE_GRID_SIZE counts the points in a grid of the unit wedge in 3D.

  Discussion:

    The interior of the unit wedge in 3D is defined by the constraints:
      0 <= X
      0 <= Y
           X + Y <= 1
     -1 <= Z <= +1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of subintervals.
    0 <= N.

    Output, int WEDGE_GRID_SIZE, the number of grid points.
*/
{
  int ng;

  ng = ( n + 1 ) * ( ( n + 1 ) * ( n + 2 ) ) / 2;

  return ng;
}
/******************************************************************************/

void wedge_grid_plot ( int n, int ng, double g[], char *header )

/******************************************************************************/
/*
  Purpose:

    WEDGE_GRID_PLOT sets up a GNUPLOT plot of a unit wedge grid.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 August 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of subintervals.

    Input, int NG, the number of nodes.

    Input, double G[3*NG], the grid point coordinates.

    Input, char *HEADER, the header for the files.
*/
{
  char command_filename[255];
  FILE *command_unit;
  int j;
  char node_filename[255];
  FILE *node_unit;
  char plot_filename[255];
  double v1[3];
  double v2[3];
  double v3[3];
  double v4[3];
  double v5[3];
  double v6[3];
  char vertex_filename[255];
  FILE *vertex_unit;
/*
  Create the vertex file.
*/
  wedge_vertices ( v1, v2, v3, v4, v5, v6 );

  strcpy ( vertex_filename, header );
  strcat ( vertex_filename, "_vertices.txt" );
  vertex_unit = fopen ( vertex_filename, "wt" );

  fprintf ( vertex_unit, "%g  %g  %g\n", v1[0], v1[1], v1[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v2[0], v2[1], v2[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v3[0], v3[1], v3[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v1[0], v1[1], v1[2] );
  fprintf ( vertex_unit, "\n" );

  fprintf ( vertex_unit, "%g  %g  %g\n", v4[0], v4[1], v4[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v5[0], v5[1], v5[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v6[0], v6[1], v6[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v4[0], v4[1], v4[2] );
  fprintf ( vertex_unit, "\n" );

  fprintf ( vertex_unit, "%g  %g  %g\n", v1[0], v1[1], v1[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v4[0], v4[1], v4[2] );
  fprintf ( vertex_unit, "\n" );

  fprintf ( vertex_unit, "%g  %g  %g\n", v2[0], v2[1], v2[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v5[0], v5[1], v5[2] );
  fprintf ( vertex_unit, "\n" );

  fprintf ( vertex_unit, "%g  %g  %g\n", v3[0], v3[1], v3[2] );
  fprintf ( vertex_unit, "%g  %g  %g\n", v6[0], v6[1], v6[2] );
  fprintf ( vertex_unit, "\n" );

  fclose ( vertex_unit );
  printf ( "\n" );
  printf ( "  Created vertex file '%s'\n", vertex_filename );
/*
  Create the node file.
*/
  strcpy ( node_filename, header );
  strcat ( node_filename, "_nodes.txt" );

  node_unit = fopen ( node_filename, "wt" );
  for ( j = 0; j < ng; j++ )
  {
    fprintf ( node_unit, "%g  %g  %g\n", g[0+j*3], g[1+j*3], g[2+j*3] );
  }
  fclose ( node_unit );
  printf ( "  Created node file '%s'\n", node_filename );
/*
  Create the command file.
*/
  strcpy ( command_filename, header );
  strcat ( command_filename, "_commands.txt" );

  command_unit = fopen ( command_filename, "wt" );
  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );

  strcpy ( plot_filename, header );
  strcat ( plot_filename, ".png" );

  fprintf ( command_unit, "set output '%s'\n", plot_filename );
  fprintf ( command_unit, "set xlabel '<--- X --->'\n" );
  fprintf ( command_unit, "set ylabel '<--- Y --->'\n" );
  fprintf ( command_unit, "set zlabel '<--- Z --->'\n" );
  fprintf ( command_unit, "set title '%s'\n", header );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set key off\n" );
  fprintf ( command_unit, "#set view equal xyz\n" );
  fprintf ( command_unit, "set view 80, 85\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "set timestamp\n" );
  fprintf ( command_unit, "splot '%s' with lines lt 3, \\\n", vertex_filename );
  fprintf ( command_unit, "      '%s' with points pt 7 lt 0\n", node_filename );
  fclose ( command_unit );

  printf ( "  Created command file '%s'\n", command_filename );

  return;
}
/******************************************************************************/

void wedge_vertices ( double v1[], double v2[], double v3[], double v4[], 
  double v5[], double v6[] )

/******************************************************************************/
/*
  Purpose:

    WEDGE_VERTICES returns the vertices of the unit wege.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2014

  Author:

    John Burkardt

  Parameters:

    Output, double V1[3], V2[3], V3[3], V4[3], V5[3], V6[3],
    the vertices.
*/
{
  static double v1_save[3] = {  0.0,  0.0, -1.0 };
  static double v2_save[3] = {  1.0,  0.0, -1.0 };
  static double v3_save[3] = {  0.0,  1.0, -1.0 };
  static double v4_save[3] = {  0.0,  0.0, +1.0 };
  static double v5_save[3] = {  1.0,  0.0, +1.0 };
  static double v6_save[3] = {  0.0,  1.0, +1.0 };

  r8vec_copy ( 3, v1_save, v1 );
  r8vec_copy ( 3, v2_save, v2 );
  r8vec_copy ( 3, v3_save, v3 );
  r8vec_copy ( 3, v4_save, v4 );
  r8vec_copy ( 3, v5_save, v5 );
  r8vec_copy ( 3, v6_save, v6 );

  return;
}
