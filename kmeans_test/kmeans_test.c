# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "kmeans.h"

int main ( );

void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( );
void test11 ( );
void test12 ( );
void test13 ( );
void test14 ( );
void test15 ( );
void test16 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for KMEANS_TEST.

  Discussion:

    KMEANS_TEST tests the KMEANS library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "KMEANS_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the KMEANS library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );
  test10 ( );
  test11 ( );
  test12 ( );
  test13 ( );
  test14 ( );
  test15 ( );
  test16 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "KMEANS_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 tries out the HMEANS_01 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test01_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test01_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Test the HMEANS_01 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  hmeans_01 ( dim_num, point_num, cluster_num, it_max, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num,
    cluster_num, point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tries out the HMEANS_02 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test02_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test02_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Test the HMEANS_02 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  hmeans_02 ( dim_num, point_num, cluster_num, it_max, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy, &seed );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num,
    cluster_num, point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tries out the KMEANS_01 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test03_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test03_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Test the KMEANS_01 algorithm.\n" );
  printf ( "  (Applied Statistics Algorithm #58)\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num, point,
    &seed );

  kmeans_01 ( dim_num, point_num, cluster_num, it_max, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of KMEANS_01 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 tries out the KMEANS_02 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test04_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test04_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  Test the KMEANS_02 algorithm.\n" );
  printf ( "  (Applied Statistics Algorithm #136)\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_1 ( dim_num, point_num, cluster_num, point );

  kmeans_02 ( dim_num, point_num, cluster_num, it_max, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tries out the KMEANS_03 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test05_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test05_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Test the KMEANS_03 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_1 ( dim_num, point_num, cluster_num,
    point );

  kmeans_03 ( dim_num, point_num, cluster_num, it_max, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tries out the HMEANS_01 + KMEANS_01 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test06_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test06_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_max_h;
  int it_max_k;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  Test the HMEANS_01 + KMEANS_01 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;
  it_max_h = 3;
  it_max_k = it_max;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of HMEANS_01 iterations allowed is %d\n", it_max_h );
  printf ( "  Number of KMEANS_01 iterations allowed is %d\n", it_max_k );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  hmeans_01 ( dim_num, point_num, cluster_num, it_max_h, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of HMEANS_01 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  kmeans_01 ( dim_num, point_num, cluster_num, it_max_k, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of KMEANS_01 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test07 ( )

/******************************************************************************/
/*
  Purpose:

    TEST07 tries out the HMEANS_01 + KMEANS_02 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test07_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test07_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_max_h;
  int it_max_k;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  Test the HMEANS_01 + KMEANS_02 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  it_max_h = 3;
  it_max_k = it_max;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of HMEANS_01 iterations allowed is %d\n", it_max_h );
  printf ( "  Number of KMEANS_02 iterations allowed is %d\n", it_max_k );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  hmeans_01 ( dim_num, point_num, cluster_num, it_max_h, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of HMEANS_01 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  kmeans_02 ( dim_num, point_num, cluster_num, it_max_k, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of KMEANS_02 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test08 ( )

/******************************************************************************/
/*
  Purpose:

    TEST08 tries out the HMEANS_01 + KMEANS_03 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test08_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test08_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_max_h;
  int it_max_k;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  Test the HMEANS_01 + KMEANS_03 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;
  it_max_h = 3;
  it_max_k = it_max;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Initialize by using a few steps of HMEANS_02:\n" );
  printf ( "  Number of HMEANS_01 iterations allowed is %d\n", it_max_h );
  printf ( "  Number of KMEANS_03 iterations allowed is %d\n", it_max_k );
/*
  Initialize the centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );
/*
  Initialize the clusters.
*/
  hmeans_01 ( dim_num, point_num, cluster_num, it_max_h, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of HMEANS_01 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  kmeans_03 ( dim_num, point_num, cluster_num, it_max_k, &it_num, point,
    cluster, cluster_center, cluster_population, cluster_energy );

  printf ( "\n" );
  printf ( "  Number of KMEANS_03 iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );

  return;
}
/******************************************************************************/

void test09 ( )

/******************************************************************************/
/*
  Purpose:

    TEST09 tries out the HMEANS_W_01 routine.

  Discussion:

    The weights are all equal, so the results should
    be identical to those for HMEANS_01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test09_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test09_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_equal_100.txt";

  printf ( "\n" );
  printf ( "TEST09\n" );
  printf ( "  Test the HMEANS_W_01 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  hmeans_w_01 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test10 ( )

/******************************************************************************/
/*
  Purpose:

    TEST10 tries out the HMEANS_W_02 routine.

  Discussion:

    The weights are all equal, so the results should
    be identical to those for HMEANS_02.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test10_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test10_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_equal_100.txt";

  printf ( "\n" );
  printf ( "TEST10\n" );
  printf ( "  Test the HMEANS_W_02 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  hmeans_w_02 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy, &seed );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population,
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test11 ( )

/******************************************************************************/
/*
  Purpose:

    TEST11 tries out the KMEANS_W_01 routine.

  Discussion:

   The weights are all equal, so the results should
    be identical to those for KMEANS_01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test11_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test11_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_equal_100.txt";

  printf ( "\n" );
  printf ( "TEST11\n" );
  printf ( "  Test the KMEANS_W_01 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  kmeans_w_01 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test12 ( )

/******************************************************************************/
/*
  Purpose:

    TEST12 tries out the KMEANS_W_03 routine.

  Discussion:

    The weights are all equal, so the results should
    be identical to those for KMEANS_03.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test12_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test12_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_equal_100.txt";

  printf ( "\n" );
  printf ( "TEST12\n" );
  printf ( "  Test the KMEANS_W_03 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_1 ( dim_num, point_num, cluster_num,
    point );

  kmeans_w_03 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test13 ( )

/******************************************************************************/
/*
  Purpose:

    TEST13 tries out the HMEANS_W_01 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test13_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test13_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_unequal_100.txt";

  printf ( "\n" );
  printf ( "TEST13\n" );
  printf ( "  Test the HMEANS_W_01 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  hmeans_w_01 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test14 ( )

/******************************************************************************/
/*
  Purpose:

    TEST14 tries out the HMEANS_W_02 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test14_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test14_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_unequal_100.txt";

  printf ( "\n" );
  printf ( "TEST14\n" );
  printf ( "  Test the HMEANS_W_02 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  hmeans_w_02 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy, &seed );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test15 ( )

/******************************************************************************/
/*
  Purpose:

    TEST15 tries out the KMEANS_W_01 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test15_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test15_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  int seed;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_unequal_100.txt";

  printf ( "\n" );
  printf ( "TEST15\n" );
  printf ( "  Test the KMEANS_W_01 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num,
    point, &seed );

  kmeans_w_01 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
/******************************************************************************/

void test16 ( )

/******************************************************************************/
/*
  Purpose:

    TEST16 tries out the KMEANS_W_03 routine.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 March 2018

  Author:

    John Burkardt
*/
{
  char *center_filename = "test16_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  char *cluster_filename = "test16_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  char *point_filename = "points_100.txt";
  int point_num;
  double *weight;
  int weight_dim;
  int weight_num;
  char *weight_filename = "weights_unequal_100.txt";

  printf ( "\n" );
  printf ( "TEST16\n" );
  printf ( "  Test the KMEANS_W_03 algorithm.\n" );
/*
  Read the data points.
*/
  printf ( "\n" );
  printf ( "  Data points will be read from \"%s\"\n", point_filename );

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  printf ( "\n" );
  printf ( "  Point spatial dimension = %d\n", dim_num  );
  printf ( "  Number of points = %d\n", point_num );

  point = r8mat_data_read ( point_filename, dim_num, point_num );
/*
  Read the weights.
*/
  printf ( "\n" );
  printf ( "  Weights will be read from \"%s\"\n", weight_filename );

  r8mat_header_read ( weight_filename, &weight_dim, &weight_num );

  if ( weight_dim != 1 )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Spatial dimension of weight array is not 1.\n" );
    exit ( 1 );
  }

  if ( weight_num != point_num )
  {
    printf ( "\n" );
    printf ( "Fatal error!\n" );
    printf ( "  Number of weights not equal to number of points.\n" );
    exit ( 1 );
  }

  weight = r8mat_data_read ( weight_filename, weight_dim, weight_num );
/*
  Clustering parameters.
*/
  cluster_num = 5;
  it_max = 20;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = ( double * ) malloc ( cluster_num * sizeof ( double ) );
  cluster_population = ( int * ) malloc ( cluster_num * sizeof ( int ) );

  printf ( "\n" );
  printf ( "  Number of iterations allowed is %d\n", it_max );
/*
  Initialize the cluster centers.
*/
  cluster_center = cluster_initialize_1 ( dim_num, point_num, cluster_num, point );

  kmeans_w_03 ( dim_num, point_num, cluster_num, it_max, &it_num,
    point, weight, cluster, cluster_center, cluster_population,
    cluster_energy );

  printf ( "\n" );
  printf ( "  Number of iterations taken is %d\n", it_num );

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num,
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num,
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  printf ( "\n" );
  printf ( "  Cluster centers written to \"%s\"\n", center_filename );

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  printf ( "  Cluster assignments written to \"%s\"\n", cluster_filename );

  free ( cluster );
  free ( cluster_center );
  free ( cluster_energy );
  free ( cluster_population );
  free ( cluster_variance );
  free ( point );
  free ( weight );

  return;
}
