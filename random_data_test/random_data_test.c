# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "random_data.h"

int main ( );
void bad_in_simplex01_test ( );
void brownian_test ( );
void r8_normal_01_test ( );
void r8_uniform_01_test ( );
void grid_in_cube01_test ( );
void halton_in_circle01_accept_test ( );
void halton_in_circle01_map_test ( );
void halton_in_cube01_test ( );
void hammersley_in_cube01_test ( );
void normal_test ( );
int dpofa ( double a[], int lda, int n );
void normal_circular_test ( );
void normal_simple_test ( );
void uniform_in_annulus_test ( );
void uniform_in_annulus_accept_test ( );
void uniform_in_annulus_sector_test ( );
void uniform_in_circle01_map_test ( );
void uniform_in_cube01_test ( );
void uniform_in_ellipsoid_map_test ( );
void uniform_in_parallelogram_map_test ( );
void uniform_in_polygon_map_test ( );
void uniform_in_sector_map_test ( );
void uniform_in_simplex01_map_test ( );
void uniform_in_sphere01_map_test ( );
void uniform_in_tetrahedron_test ( );
void uniform_in_triangle_map1_test ( );
void uniform_in_triangle_map2_test ( );
void uniform_in_triangle01_map_test ( );
void uniform_on_cube01_test ( );
void uniform_on_ellipsoid_map_test ( );
void uniform_on_hemisphere01_phong_test ( );
void uniform_on_simplex01_map_test ( );
void uniform_on_sphere01_map_test ( );
void uniform_on_sphere01_patch_tp_test ( );
void uniform_on_sphere01_patch_xyz_test ( );
void uniform_on_sphere01_triangle_xyz_test ( );
void uniform_walk_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for RANDOM_DATA_TEST.

  Discussion:

    RANDOM_DATA_TEST tests the RANDOM_DATA library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 January 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "RANDOM_DATA_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the RANDOM_DATA library.\n" );

  bad_in_simplex01_test ( );
  brownian_test ( );
  r8_normal_01_test ( );
  r8_uniform_01_test ( );
  grid_in_cube01_test ( );
  halton_in_circle01_accept_test ( );
  halton_in_circle01_map_test ( );
  halton_in_cube01_test ( );
  hammersley_in_cube01_test ( );
  normal_test ( );
  normal_circular_test ( );
  normal_simple_test ( );
  uniform_in_annulus_test ( );
  uniform_in_annulus_accept_test ( );
  uniform_in_annulus_sector_test ( );
  uniform_in_circle01_map_test ( );
  uniform_in_cube01_test ( );
  uniform_in_ellipsoid_map_test ( );
  uniform_in_parallelogram_map_test ( );
  uniform_in_polygon_map_test ( );
  uniform_in_sector_map_test ( );
  uniform_in_simplex01_map_test ( );
  uniform_in_sphere01_map_test ( );
  uniform_in_tetrahedron_test ( );
  uniform_in_triangle_map1_test ( );
  uniform_in_triangle_map2_test ( );
  uniform_in_triangle01_map_test ( );
  uniform_on_cube01_test ( );
  uniform_on_ellipsoid_map_test ( );
  uniform_on_hemisphere01_phong_test ( );
  uniform_on_simplex01_map_test ( );
  uniform_on_sphere01_map_test ( );
  uniform_on_sphere01_patch_tp_test ( );
  uniform_on_sphere01_patch_xyz_test ( );
  uniform_on_sphere01_triangle_xyz_test ( );
  uniform_walk_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "RANDOM_DATA_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void bad_in_simplex01_test ( )

/******************************************************************************/
/*
  Purpose:

    BAD_IN_SIMPLEX01_TEST tests BAD_IN_SIMPLEX01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
  int dim_num;
  int n;
  char output_filename[80];
  int seed;
  double *x;

  printf ( "\n" );
  printf ( "BAD_IN_SIMPLEX01_TEST:\n" );
  printf ( "  BAD_IN_SIMPLEX01 is a \"bad\" sampling technique\n" );
  printf ( "  for the unit simplex.\n" );


  for ( dim_num = 2; dim_num <= 3; dim_num++ )
  {
    seed = 123456789;
    n = 10000;
    if ( dim_num == 2 )
    {
      strcpy ( output_filename, "bad_in_triangle.txt" );
    }
    else if ( dim_num == 3 )
    {
      strcpy ( output_filename, "bad_in_tetrahedron.txt" );
    }

    printf ( "\n" );
    printf ( "  Spatial dimension DIM_NUM =  %d\n", dim_num );
    printf ( "  Number of points N =         %d\n", n );
    printf ( "  Initial random number SEED = %d\n", seed );

    x = bad_in_simplex01 ( dim_num, n, &seed );

    r8mat_write ( output_filename, dim_num, n, x );

    printf ( "\n" );
    printf ( "  Data written to file \"%s\".\n", output_filename );

    free ( x );
  }

  return;
}
/******************************************************************************/

void brownian_test ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests BROWNIAN

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 100

  char output_filename[] = "brownian.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "BROWNIAN_TEST:\n" );
  printf ( "  BROWNIAN generates Brownian motion points.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = brownian ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  scale_to_block01 ( DIM_NUM, N, x );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void r8_normal_01_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_NORMAL_01_TEST tests R8_NORMAL_01

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int seed = 123456789;
  int seed_in;
  double x;

  printf ( "\n" );
  printf ( "R8_NORMAL_01_TEST:\n" );
  printf ( "  R8_NORMAL_01 generates a single normal \n" );
  printf ( "  pseudorandom value.\n" );
  printf ( "\n" );
  printf ( "     Seed          Seed       R8_NORMAL_01\n" );
  printf ( "    (Input)       (Output)\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    seed_in = seed;
    x = r8_normal_01 ( &seed );

    printf ( "  %12d  %12d  %12g\n", seed_in, seed, x );
  }

  return;
}
/******************************************************************************/

void r8_uniform_01_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01_TEST tests R8_UNIFORM_01

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
  int i;
  int seed = 123456789;
  int seed_in;
  double x;

  printf ( "\n" );
  printf ( "R8_UNIFORM_01_TEST:\n" );
  printf ( "  R8_UNIFORM_01 generates a single uniform \n" );
  printf ( "  pseudorandom value.\n" );
  printf ( "\n" );
  printf ( "     Seed          Seed       R8_UNIFORM_01\n" );
  printf ( "    (Input)       (Output)\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    seed_in = seed;
    x = r8_uniform_01 ( &seed );

    printf ( "  %12d  %12d  %12g\n", seed_in, seed, x );
  }

  return;
}
/******************************************************************************/

void grid_in_cube01_test ( )

/******************************************************************************/
/*
  Purpose:

    GRID_IN_CUBE01_TEST tests GRID_IN_CUBE01

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 85

  int center = 1;
  char output_filename[] = "grid_in_cube01.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "GRID_IN_CUBE01_TEST\n" );
  printf ( "  GRID_IN_CUBE01 generates grid points in the unit hypercube.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  CENTER option =              %d\n", center );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = grid_in_cube01 ( DIM_NUM, N, center, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void halton_in_circle01_accept_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_IN_CIRCLE01_ACCEPT_TEST tests HALTON_IN_CIRCLE01_ACCEPT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "halton_in_circle01_accept.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "HALTON_IN_CIRCLE01_ACCEPT_TEST\n" );
  printf ( "  HALTON_IN_CIRCLE01_ACCEPT accepts \n" );
  printf ( "  Halton points in the unit circle.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = halton_in_circle01_accept ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void halton_in_circle01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_IN_CIRCLE01_MAP_TEST tests HALTON_IN_CIRCLE01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "halton_in_circle01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "HALTON_IN_CIRCLE01_MAP_TEST\n" );
  printf ( "  HALTON_IN_CIRCLE01_MAP maps \n" );
  printf ( "  Halton points into the unit circle.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = halton_in_circle01_map ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void halton_in_cube01_test ( )

/******************************************************************************/
/*
  Purpose:

    HALTON_IN_CUBE01_TEST tests HALTON_IN_CUBE01

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 100

  char output_filename[] = "halton_in_cube01.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "HALTON_IN_CUBE01_TEST\n" );
  printf ( "  HALTON_IN_CUBE01 generates Halton points\n" );
  printf ( "  in the unit hypercube.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = halton_in_cube01 ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void hammersley_in_cube01_test ( )

/******************************************************************************/
/*
  Purpose:

    HAMMERSLEY_IN_CUBE01_TEST tests HAMMERSLEY_IN_CUBE01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 100

  char output_filename[] = "hammersley_in_cube01.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "HAMMERSLEY_IN_CUBE01_TEST\n" );
  printf ( "  HAMMERSLEY_IN_CUBE01 generates Hammersley points\n" );
  printf ( "  in the unit hypercube.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = hammersley_in_cube01 ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void normal_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TEST tests NORMAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "normal.txt";
  int i;
  int info;
  int j;
  double mu[DIM_NUM] = { 6.0, 100.0 };
  double r[DIM_NUM*DIM_NUM];
  int seed = 123456789;
  double v[DIM_NUM*DIM_NUM] = { 5.0, 2.0, 2.0, 1.0 };
  double *x;

  printf ( "\n" );
  printf ( "NORMAL_TEST\n" );
  printf ( "  NORMAL generates normal points\n" );
  printf ( "  in M dimensions, using a nonzero mean, and with\n" );
  printf ( "  user-specified variance-covariance matrix.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  r8vec_print ( DIM_NUM, mu, "  Mean vector MU:" );

  r8mat_print ( DIM_NUM, DIM_NUM, v, "  Variance-covariance matrix V:" );

  for ( i = 0; i < DIM_NUM; i++ )
  {
    for ( j = 0; j < DIM_NUM; j++ )
    {
      r[i+j*DIM_NUM] = v[i+j*DIM_NUM];
    }
  }

  info = dpofa ( r, DIM_NUM, DIM_NUM );

  if ( info != 0 )
  {
    printf ( "\n" );
    printf ( "TEST04 - Fatal error!\n" );
    printf ( "  Variance-covariance matrix factorization failed.\n" );
    exit ( 1 );
  }

  r8mat_print ( DIM_NUM, DIM_NUM, r, "  Cholesky factor R:" );

  x = normal ( DIM_NUM, N, r, mu, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  scale_to_block01 ( DIM_NUM, N, x );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

int dpofa ( double a[], int lda, int n )

/******************************************************************************/
/*
  Purpose:

    DPOFA factors a real symmetric positive definite matrix.

  Discussion:

    DPOFA is usually called by DPOCO, but it can be called
    directly with a saving in time if RCOND is not needed.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 May 2005

  Author:

    Original FORTRAN77 version by Jack Dongarra, Cleve Moler, Jim Bunch, 
    Pete Stewart,
    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, double A[LDA*N].  On input, the symmetric matrix
    to be  factored.  Only the diagonal and upper triangle are used.
    On output, an upper triangular matrix R so that A = R'*R
    where R' is the transpose.  The strict lower triangle is unaltered.
    If INFO /= 0, the factorization is not complete.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Output, int DPOFA, error flag.
    0, for normal return.
    K, signals an error condition.  The leading minor of order K is not
    positive definite.
*/
{
  int info;
  int j;
  int k;
  double s;
  double t;

  for ( j = 1; j <= n; j++ )
  {
    s = 0.0;

    for ( k = 1; k <= j-1; k++ )
    {
      t = a[k-1+(j-1)*lda] - ddot ( k-1, a+0+(k-1)*lda, 1, a+0+(j-1)*lda, 1 );
      t = t / a[k-1+(k-1)*lda];
      a[k-1+(j-1)*lda] = t;
      s = s + t * t;
    }

    s = a[j-1+(j-1)*lda] - s;

    if ( s <= 0.0 )
    {
      info = j;
      return info;
    }

    a[j-1+(j-1)*lda] = sqrt ( s );
  }

  info = 0;

  return info;
}
/******************************************************************************/

void normal_circular_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_CIRCULAR_TEST tests NORMAL_CIRCULAR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 2000

  char output_filename[] = "normal_circular.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "NORMAL_CIRCULAR_TEST\n" );
  printf ( "  NORMAL_CIRCULAR generates points in 2D\n" );
  printf ( "  distributed according to a circular normal.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = normal_circular ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  scale_to_block01 ( DIM_NUM, N, x );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void normal_simple_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_SIMPLE_TEST tests NORMAL_SIMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "normal_simple.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "NORMAL_SIMPLE_TEST\n" );
  printf ( "  NORMAL_SIMPLE generates normal points\n" );
  printf ( "  in M dimensions, using a zero mean, and with\n" );
  printf ( "  the identity as the variance-covariance matrix.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = normal_simple ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  scale_to_block01 ( DIM_NUM, N, x );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_annulus_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_ANNULUS_TEST tests UNIFORM_IN_ANNULUS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2005

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "uniform_in_annulus.txt";
  double pc[DIM_NUM] = { 10.0, 5.0 };
  double r1 = 1.0;
  double r2 = 3.0;
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_ANNULUS_TEST\n" );
  printf ( "  UNIFORM_IN_ANNULUS generates uniform\n" );
  printf ( "  points in an annulus by mapping.\n" );
  printf ( "\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Center PC(1:2) =             %g  %g\n", pc[0], pc[1] );
  printf ( "  Inner radius is R1 =         %g\n", r1 );
  printf ( "  Outer radius is R2 =         %g\n", r2 );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_annulus ( pc, r1, r2, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_annulus_accept_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_ANNULUS_ACCEPT_TEST tests UNIFORM_IN_ANNULUS_ACCEPT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2005

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "uniform_in_annulus_accept.txt";
  double pc[DIM_NUM] = { 10.0, 5.0 };
  double r1 = 1.0;
  double r2 = 3.0;
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_ANNULUS_ACCEPT_TEST\n" );
  printf ( "  UNIFORM_IN_ANNULUS_ACCEPT generates uniform\n" );
  printf ( "  points in an annulus by acceptance/rejection.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Center PC(1:2) =             %g  %g\n", pc[0], pc[1] );
  printf ( "  Inner radius is R1 =         %g\n", r1 );
  printf ( "  Outer radius is R2 =         %g\n", r2 );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_annulus_accept ( pc, r1, r2, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_annulus_sector_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_ANNULUS_SECTOR_TEST tests UNIFORM_IN_ANNULUS_SECTOR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "uniform_in_annulus_sector.txt";
  double pc[DIM_NUM] = { 10.0, 5.0 };
  double r1 = 1.0;
  double r2 = 3.0;
  int seed = 123456789;
  double theta1 = 0.0;
  double theta2 = 1.5707964;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_ANNULUS_SECTOR_TEST\n" );
  printf ( "  UNIFORM_IN_ANNULUS_SECTOR generates uniform \n" );
  printf ( "  points in an annular sector by mapping.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Center PC(1:2) =             %g  %g\n", pc[0], pc[1] );
  printf ( "  Inner radius is R1 =         %g\n", r1 );
  printf ( "  Outer radius is R2 =         %g\n", r2 );
  printf ( "  THETA1 =                     %g\n", theta1 );
  printf ( "  THETA2 =                     %g\n", theta2 );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_annulus_sector ( pc, r1, r2, theta1, theta2, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_circle01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_CIRCLE01_TEST tests UNIFORM_IN_CIRCLE01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "uniform_in_circle01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_CIRCLE01_TEST\n" );
  printf ( "  UNIFORM_IN_CIRCLE01_MAP maps uniform \n" );
  printf ( "  points into the unit circle.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_circle01_map ( N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_cube01_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_CUBE01_TEST tests UNIFORM_IN_CUBE01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "uniform_in_cube01.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_CUBE01_TEST\n" );
  printf ( "  UNIFORM_IN_CUBE01 generates uniform\n" );
  printf ( "  points in the unit hypercube.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_cube01 ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_ellipsoid_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_ELLIPSOID_MAP_TEST tests UNIFORM_IN_ELLIPSOID_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  double a[DIM_NUM*DIM_NUM] = { 3.0, 1.0, 1.0, 2.0 };
  int fail_num;
  char output_filename[] = "uniform_in_ellipsoid_map.txt";
  int i;
  int j;
  int k;
  double r = 1.0;
  double r2;
  int seed = 123456789;
  int success_num;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_ELLIPSOID_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_ELLIPSOID_MAP maps uniform\n" );
  printf ( "  points into an ellipsoid.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_ellipsoid_map ( DIM_NUM, N, a, r, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );
/*
  Test the data.
*/
  fail_num = 0;
  success_num = 0;

  for ( j = 0; j < N; j++ )
  {

    r2 = 0.0;
    for ( i = 0; i < DIM_NUM; i++ )
    {
      for ( k = 0; k < DIM_NUM; k++ )
      {
        r2 = r2 + x[i+j*DIM_NUM] * a[i+k*DIM_NUM] * x[k+j*DIM_NUM];
      }
    }
    r2 = sqrt ( r2 );

    if ( r < r2 )
    {
      fail_num = fail_num + 1;
    }
    else
    {
      success_num = success_num + 1;
    }
  }

  printf ( "\n" );
  printf ( "  %d points failed the ellipsoid test.\n", fail_num );

  printf ( "  %d points satisfy the ellipsoid test.\n", success_num );

  free ( x );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_parallelogram_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_PARALLELOGRAM_MAP_TEST tests UNIFORM_IN_PARALLELOGRAM_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "uniform_in_parallelogram_map.txt";
  int seed = 123456789;
  double v1[DIM_NUM] = { 0.75E+00, 0.90E+00 };
  double v2[DIM_NUM] = { 0.00E+00, 0.20E+00 };
  double v3[DIM_NUM] = { 1.10E+00, 0.65E+00 };
  double v4[DIM_NUM];
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_PARALLELOGRAM_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_PARALLELOGRAM_MAP maps uniform\n" );
  printf ( "  points into a parallelogram.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  v4[0] = v3[0] + v2[0] - v1[0];
  v4[1] = v3[1] + v2[1] - v1[1];

  printf ( "\n" );
  printf ( "  V1 = %g, %g\n", v1[0], v1[1] );
  printf ( "  V2 = %g, %g\n", v2[0], v2[1] );
  printf ( "  V3 = %g, %g\n", v3[0], v3[1] );
  printf ( "  V4 = %g, %g\n", v4[0], v4[1] );

  x = uniform_in_parallelogram_map ( v1, v2, v3, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  scale_to_block01 ( DIM_NUM, N, x );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_polygon_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_POLYGON_MAP_TEST tests UNIFORM_IN_POLYGON_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000
# define NV 10

  char output_filename[] = "uniform_in_polygon_map.txt";
  int seed = 123456789;
  double v[DIM_NUM*NV] = {
    0.0E+00, 0.0E+00,
    0.5E+00, 0.3E+00,
    1.0E+00, 0.0E+00,
    0.7E+00, 0.4E+00,
    1.0E+00, 0.6E+00,
    0.6E+00, 0.6E+00,
    0.5E+00, 1.0E+00,
    0.4E+00, 0.6E+00,
    0.0E+00, 0.6E+00,
    0.3E+00, 0.4E+00 };
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_POLYGON_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_POLYGON_MAP maps uniform\n" );
  printf ( "  points into a polygon.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  r8mat_print ( DIM_NUM, NV, v, "  Polygonal vertices:" );

  x = uniform_in_polygon_map ( NV, v, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( "polygon_vertices.txt", DIM_NUM, NV, v );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
# undef NV
}
/******************************************************************************/

void uniform_in_sector_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_SECTOR_MAP_TEST tests UNIFORM_IN_SECTOR_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 300

  char output_filename[] = "uniform_in_sector_map.txt";
  double r1 = 1.0;
  double r2 = 2.0;
  int seed = 123456789;
  double t1 = 0.78;
  double t2 = 2.35;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_SECTOR_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_SECTOR_MAP maps uniform\n" );
  printf ( "  points into a circular sector.\n" );
  printf ( "\n" );
  printf ( "  R1 = %g\n", r1 );
  printf ( "  R2 = %g\n", r2 );
  printf ( "  T1 = %g\n", t1 );
  printf ( "  T2 = %g\n", t2 );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_sector_map ( r1, r2, t1, t2, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_simplex01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_SIMPLEX01_MAP_TEST tests UNIFORM_IN_SIMPLEX01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "uniform_in_simplex01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_SIMPLEX01_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_SIMPLEX01_MAP maps uniform\n" );
  printf ( "  points into the unit simplex\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_simplex01_map ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_sphere01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_SPHERE01_MAP_TEST tests UNIFORM_IN_SPHERE01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "uniform_in_sphere01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_SPHERE01_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_SPHERE01_MAP maps uniform\n" );
  printf ( "  points into the unit sphere.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_sphere01_map ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_tetrahedron_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_TETRAHEDRON_TEST tests UNIFORM_IN_TETRAHEDRON.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 August 2009

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3
# define N 1000

  char output_filename[] = "uniform_in_tetrahedron.txt";
  int seed = 123456789;
  double v[3*4] = {
    1.0,  2.0,  3.0,
    4.0,  1.0,  2.0,
    2.0,  4.0,  4.0,
    3.0,  2.0,  5.0  };
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_TETRAHEDRON_TEST\n" );
  printf ( "  UNIFORM_IN_TETRAHEDRON returns uniform\n" );
  printf ( "  points from a tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  r8mat_print ( 3, 4, v, "  Tetrahedron vertices:" );

  x = uniform_in_tetrahedron ( v, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_triangle_map1_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_TRIANGLE_MAP1_TEST tests UNIFORM_IN_TRIANGLE_MAP1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2016

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "uniform_in_triangle_map1.txt";
  int seed = 123456789;
  double v1[DIM_NUM] = { 0.75E+00, 0.90E+00 };
  double v2[DIM_NUM] = { 0.00E+00, 0.20E+00 };
  double v3[DIM_NUM] = { 0.95E+00, 0.65E+00 };
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_TRIANGLE_MAP1_TEST\n" );
  printf ( "  UNIFORM_IN_TRIANGLE_MAP1 maps uniform\n" );
  printf ( "  points into a triangle, by Turk 1 mapping.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  printf ( "\n" );
  printf ( "  V1 = %g, %g\n", v1[0], v1[1] );
  printf ( "  V2 = %g, %g\n", v2[0], v2[1] );
  printf ( "  V3 = %g, %g\n", v3[0], v3[1] );

  x = uniform_in_triangle_map1 ( v1, v2, v3, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_triangle_map2_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_TRIANGLE_MAP2_TEST tests UNIFORM_IN_TRIANGLE_MAP2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 1000

  char output_filename[] = "uniform_in_triangle_map2.txt";
  int seed = 123456789;
  double v1[DIM_NUM] = { 0.75E+00, 0.90E+00 };
  double v2[DIM_NUM] = { 0.00E+00, 0.20E+00 };
  double v3[DIM_NUM] = { 0.95E+00, 0.65E+00 };
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_TRIANGLE_MAP2_TEST\n" );
  printf ( "  UNIFORM_IN_TRIANGLE_MAP2 maps uniform\n" );
  printf ( "  points into a triangle, by Turk 2 mapping.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  printf ( "\n" );
  printf ( "  V1 = %g, %g\n", v1[0], v1[1] );
  printf ( "  V2 = %g, %g\n", v2[0], v2[1] );
  printf ( "  V3 = %g, %g\n", v3[0], v3[1] );

  x = uniform_in_triangle_map2 ( v1, v2, v3, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_in_triangle01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_TRIANGLE01_MAP_TEST tests UNIFORM_IN_TRIANGLE01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 2000

  char output_filename[] = "uniform_in_triangle01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_IN_TRIANGLE01_MAP_TEST\n" );
  printf ( "  UNIFORM_IN_TRIANGLE01_MAP maps uniform\n" );
  printf ( "  points into the unit triangle.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_in_triangle01_map ( N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_on_cube01_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_CUBE01_TEST tests UNIFORM_ON_CUBE01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 April 2013

  Author:

    John Burkardt
*/
{
# define M 2
# define N 200

  char output_filename[] = "uniform_on_cube01.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_ON_CUBE01_TEST\n" );
  printf ( "  UNIFORM_ON_CUBE01 samples N uniform points on\n" );
  printf ( "  the surface of the unit M-dimensional cube.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension M =        %d\n", M );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_on_cube01 ( M, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, M, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef M
# undef N
}
/******************************************************************************/

void uniform_on_ellipsoid_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_ELLIPSOID_MAP_TEST tests UNIFORM_ON_ELLIPSOID_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 200

  double a[DIM_NUM*DIM_NUM] = { 3.0, 1.0, 1.0, 2.0 };
  char output_filename[] = "uniform_on_ellipsoid_map.txt";
  double r = 1.0;
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_ON_ELLIPSOID_MAP_TEST\n" );
  printf ( "  UNIFORM_ON_ELLIPSOID_MAP maps uniform\n" );
  printf ( "  points onto an ellipsoid.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_on_ellipsoid_map ( DIM_NUM, N, a, r, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_on_hemisphere01_phong_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_HEMISPHERE01_PHONG_TEST tests UNIFORM_ON_HEMISPHERE01_PHONG.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2005

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3
# define N 50

  char output_filename[] = "uniform_on_hemisphere01_phong.txt";
  int m = 2;
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_ON_HEMISPHERE01_PHONG_TEST\n" );
  printf ( "  UNIFORM_ON_HEMISPHERE01_PHONG maps uniform\n" );
  printf ( "  points onto the unit hemisphere with Phong density.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Phong exponent M =           %d\n", m );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_on_hemisphere01_phong ( N, m, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_on_simplex01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_SIMPLEX01_MAP_TEST tests UNIFORM_ON_SIMPLEX01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 50

  char output_filename[] = "uniform_on_simplex01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_ON_SIMPLEX01_MAP_TEST\n" );
  printf ( "  UNIFORM_ON_SIMPLEX01_MAP maps uniform \n" );
  printf ( "  points onto the unit simplex.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_on_simplex01_map ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_on_sphere01_map_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_SPHERE01_MAP_TEST tests UNIFORM_ON_SPHERE01_MAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 50

  char output_filename[] = "uniform_on_sphere01_map.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_ON_SPHERE01_MAP_TEST\n" );
  printf ( "  UNIFORM_ON_SPHERE01_MAP maps uniform\n" );
  printf ( "  points onto the unit sphere.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_on_sphere01_map ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_on_sphere01_patch_tp_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_SPHERE01_PATCH_TP_TEST tests UNIFORM_ON_SPHERE01_PATCH_TP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2010

  Author:

    John Burkardt
*/
{
# define N 50
# define PI 3.141592653589793

  char output_filename[] = "uniform_on_sphere01_patch_tp.txt";
  double phi1;
  double phi2;
  int seed = 123456789;
  double theta1;
  double theta2;
  double *tp;

  phi1 = 75.0 * ( PI / 180.0 );
  phi2 = 90.0 * ( PI / 180.0 );
  theta1 =  0.0 * ( PI / 360.0 );
  theta2 = 30.0 * ( PI / 360.0 );

  printf ( "\n" );
  printf ( "UNIFORM_ON_SPHERE01_PATCH_TP_TEST\n" );
  printf ( "  UNIFORM_ON_SPHERE01_PATCH_TP maps uniform\n" );
  printf ( "  points onto a TP (THETA,PHI) patch of the unit sphere.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  3\n" );
  printf ( "  Data dimension =             2\n" );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Latitudinal angle PHI1 =     %g\n", phi1 );
  printf ( "  Latitudinal angle PHI2 =     %g\n", phi2 );
  printf ( "  Longitudinal angle THETA1 =  %g\n", theta1 );
  printf ( "  Longitudinal angle THETA2 =  %g\n", theta2 );
  printf ( "  Initial random number SEED = %d\n", seed );

  tp = uniform_on_sphere01_patch_tp ( N, phi1, phi2, theta1, theta2, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, 2, N, tp );

  free ( tp );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef N
# undef PI
}
/******************************************************************************/

void uniform_on_sphere01_patch_xyz_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_SPHERE01_PATCH_XYZ_TEST tests UNIFORM_ON_SPHERE01_PATCH_XYZ.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 August 2005

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3
# define N 50
# define PI 3.141592653589793

  char output_filename[] = "uniform_on_sphere01_patch_xyz.txt";
  double phi1;
  double phi2;
  int seed = 123456789;
  double theta1;
  double theta2;
  double *x;

  phi1 = 75.0 * ( PI / 180.0 );
  phi2 = 90.0 * ( PI / 180.0 );
  theta1 =  0.0 * ( PI / 360.0 );
  theta2 = 30.0 * ( PI / 360.0 );

  printf ( "\n" );
  printf ( "UNIFORM_ON_SPHERE01_PATCH_XYZ_TEST\n" );
  printf ( "  UNIFORM_ON_SPHERE01_PATCH_XYZ maps uniform\n" );
  printf ( "  points onto an XYZ patch of the unit sphere.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Latitudinal angle PHI1 =     %g\n", phi1 );
  printf ( "  Latitudinal angle PHI2 =     %g\n", phi2 );
  printf ( "  Longitudinal angle THETA1 =  %g\n", theta1 );
  printf ( "  Longitudinal angle THETA2 =  %g\n", theta2 );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_on_sphere01_patch_xyz ( N, phi1, phi2, theta1, theta2, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
# undef PI
}
/******************************************************************************/

void uniform_on_sphere01_triangle_xyz_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_ON_SPHERE01_TRIANGLE_XYZ_TEST tests UNIFORM_ON_SPHERE01_TRIANGLE_XYZ.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 August 2005

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3
# define N 500

  char output_filename[] = "uniform_on_sphere01_triangle_xyz.txt";
  int seed = 123456789;
  double *v1;
  double *v2;
  double *v3;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_ON_SPHERE01_TRIANGLE_XYZ_TEST\n" );
  printf ( "  UNIFORM_ON_SPHERE01_TRIANGLE_XYZ maps uniform\n" );
  printf ( "  points onto a spherical triangle using XYZ coordinates.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  3\n" );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  if ( true )
  {
    v1 = uniform_on_sphere01_map ( 3, 1, &seed );
    v2 = uniform_on_sphere01_map ( 3, 1, &seed );
    v3 = uniform_on_sphere01_map ( 3, 1, &seed );
  }
  else
  {
    v1 = r8vec_zero_new ( 3 );
    v1[0] = 1.0;
    v2 = r8vec_zero_new ( 3 );
    v2[1] = 1.0;
    v3 = r8vec_zero_new ( 3 );
    v3[2] = 1.0;
  }

  printf ( "\n" );
  printf ( "  Vertices of spherical triangle:\n" );
  printf ( "\n" );
  printf ( "  V1: (%g,%g,%g)\n", v1[0], v1[1], v1[2] );
  printf ( "  V2: (%g,%g,%g)\n", v2[0], v2[1], v2[2] );
  printf ( "  V3: (%g,%g,%g)\n", v3[0], v3[1], v3[2] );

  x = uniform_on_sphere01_triangle_xyz ( N, v1, v2, v3, &seed );

  printf ( "\n" );
  printf ( "  Final random number SEED =   %d\n", seed );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  free ( v1 );
  free ( v2 );
  free ( v3 );

  return;
# undef DIM_NUM
# undef N
}
/******************************************************************************/

void uniform_walk_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_WALK_TEST tests UNIFORM_WALK

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 December 2013

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define N 400

  char output_filename[] = "uniform_walk.txt";
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_WALK_TEST:\n" );
  printf ( "  UNIFORM_WALK generates uniform random walk points.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM =  %d\n", DIM_NUM );
  printf ( "  Number of points N =         %d\n", N );
  printf ( "  Initial random number SEED = %d\n", seed );

  x = uniform_walk ( DIM_NUM, N, &seed );

  printf ( "  Final random number SEED =   %d\n", seed );

  scale_to_block01 ( DIM_NUM, N, x );

  r8mat_write ( output_filename, DIM_NUM, N, x );

  free ( x );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", output_filename );

  return;
# undef DIM_NUM
# undef N
}
