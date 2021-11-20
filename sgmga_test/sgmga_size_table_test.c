# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "sandia_rules.h"
# include "sgmga.h"

int main ( );

typedef void ( *GWPointer ) ( int order, int np, double p[], double w[] );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for sgmga_size_table_test.

  Discussion:

    sgmga_size_table_test tests sgmga_size_table.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 December 2009

  Author:

    John Burkardt
*/
{
  double ctime;
  int dim_max;
  int dim_min;
  int level_max_max;
  int level_max_min;
  int np_1d;
  double *p_1d;
  int rule_1d;

  timestamp ( );
  printf ( "\n" );
  printf ( "sgmga_size_table_test\n" );
  printf ( "  C version\n" );
  printf ( "  Make tables of point counts.\n" );
  printf ( "  Print the CPU time required for each table.\n" );
/*
  For the Clenshaw-Curtis Grid (rule 1), compute some point counts
  for dimensions DIM_MIN to DIM_MAX, levels LEVE_MAX_MIN to LEVEL_MAX_MAX.
*/
  rule_1d = 1;
  np_1d = 0;
  p_1d = ( double * ) malloc ( np_1d * sizeof ( double ) );
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 7;
  ctime = cpu_time ( );
  sgmga_size_table ( rule_1d, np_1d, p_1d, dim_min, dim_max, level_max_min, 
    level_max_max, clenshaw_curtis_compute_points_np );
  ctime = cpu_time ( ) - ctime;
  printf ( "\n" );
  printf ( "  CPU Time = %f\n", ctime );
  free ( p_1d );
/*
  Code is not efficient for this case.
*/
  if ( 0 )
  {
    rule_1d = 1;
    np_1d = 0;
    p_1d = ( double * ) malloc ( np_1d * sizeof ( double ) );
    dim_min = 6;
    dim_max = 10;
    level_max_min = 0;
    level_max_max = 7;
    ctime = cpu_time ( );
    sgmga_size_table ( rule_1d, np_1d, p_1d, dim_min, dim_max, level_max_min, 
      level_max_max, clenshaw_curtis_compute_points_np );
    ctime = cpu_time ( ) - ctime;
    printf ( "\n" );
    printf ( "  CPU Time = %f\n", ctime );
    free ( p_1d );
  }
/*
  Code is not efficient for this case.
*/
  if ( 0 ) 
  {
    rule_1d = 1;
    np_1d = 0;
    p_1d = ( double * ) malloc ( np_1d * sizeof ( double ) );
    dim_min = 100;
    dim_max = 100;
    level_max_min = 0;
    level_max_max = 2;
    ctime = cpu_time ( );
    sgmga_size_table ( rule_1d, np_1d, p_1d, dim_min, dim_max, level_max_min, 
      level_max_max, clenshaw_curtis_compute_points_np );
    ctime = cpu_time ( ) - ctime;
    printf ( "\n" );
    printf ( "  CPU Time = %f\n", ctime );
    free ( p_1d );
  }
/*
  For the Clenshaw-Curtis Grid with "slow exponential growth", (rule 11), 
  compute some point counts
  for dimensions DIM_MIN to DIM_MAX, levels LEVE_MAX_MIN to LEVEL_MAX_MAX.
*/
  rule_1d = 11;
  np_1d = 0;
  p_1d = ( double * ) malloc ( np_1d * sizeof ( double ) );
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 7;
  ctime = cpu_time ( );
  sgmga_size_table ( rule_1d, np_1d, p_1d, dim_min, dim_max, level_max_min, 
    level_max_max, clenshaw_curtis_compute_points_np );
  ctime = cpu_time ( ) - ctime;
  printf ( "\n" );
  printf ( "  CPU Time = %f\n", ctime );
  free ( p_1d );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "sgmga_size_table_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );
  
  return 0;
}

