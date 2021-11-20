# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

int main ( );
double cpu_time ( );
int *find_closest1 ( int m, int nr, double r[], int ns, double s[] );
double *r8mat_uniform_01_new ( int m, int n, int *seed );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    TEST_NEAREST compares the performance of nearest neighbor routines.

  Discussion:

    We are given R, a set of NR points in M dimensions.

    We are given S, a set of NS points in M dimensions.

    For each S(I) in S, we seek the index J of the point R(J)
    which is nearest to S(I) over all points in R.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2012

  Author:

    John Burkardt

  Local parameters:

    Local, int M, the spatial dimension.

    Local, int NR, the number of data points.

    Local, int NS, the number of sample points.

    Local, double R[M*NR], the data points.

    Local, double S[M*NS], the sample points. 
*/
{
  int m;
  int m_test;
  int m_test_data[3] = { 2, 4, 8 };
  int m_test_num = 3;
  int *nearest;
  int nr;
  int nr_test_data[6] = {
    1000000, 100000, 10000,  1000,    100,      10 };
  int n_test_num = 6;
  int ns;
  int ns_test_data[6] = {
      10,    100,  1000, 10000, 100000, 1000000 };
  double *r;
  double *s;
  int seed;
  double t1;
  double t2;
  int test;

  timestamp ( );
  printf ( "\n" );
  printf ( "TEST_NEAREST:\n" );
  printf ( "  C version\n" );
  printf ( "  Consider various nearest neighbor algorithms.\n" );

  for ( m_test = 0; m_test < m_test_num; m_test++ )
  {
    m = m_test_data[m_test];

    for ( test = 0; test < n_test_num; test++ )
    {
      nr = nr_test_data[test];
      ns = ns_test_data[test];

      seed = 123456789;
      s = r8mat_uniform_01_new ( m, ns, &seed );
      r = r8mat_uniform_01_new ( m, nr, &seed );

      printf ( "\n" );
      printf ( "  M = %d, NR = %d,  NS = %d\n", m, nr, ns );

      t1 = cpu_time ( );
      nearest = find_closest1 ( m, nr, r, ns, s );
      t2 = cpu_time ( );
      printf ( "  #1 time: %g,  size = %d,  i[0] = %d\n", t2 - t1, ns, nearest[0] );

      free ( nearest );
      free ( r );
      free ( s );
    }
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TEST_NEAREST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

double cpu_time ( )

/******************************************************************************/
/*
  Purpose:

    CPU_TIME returns the current reading on the CPU clock.

  Discussion:

    The CPU time measurements available through this routine are often
    not very accurate.  In some cases, the accuracy is no better than
    a hundredth of a second.  

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 June 2005

  Author:

    John Burkardt

  Parameters:

    Output, double CPU_TIME, the current reading of the CPU clock, in seconds.
*/
{
  double value;

  value = ( double ) clock ( ) 
        / ( double ) CLOCKS_PER_SEC;

  return value;
}
/******************************************************************************/

int *find_closest1 ( int m, int nr, double r[], int ns, double s[] )

/******************************************************************************/
/*
  Purpose:

    FIND_CLOSEST1 finds the nearest R point to each S point.

  Discussion:

    We are given R, a set of NR points in M dimensions.

    We are given S, a set of NS points in M dimensions.

    For each S(I) in S, we seek the index J of the point R(J)
    which is nearest to S(I) over all points in R.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int NR, the number of data points.

    Input, double R[M*NR], the data points.

    Input, int NS, the number of sample points.

    Input, double S[M*NS], the sample points.

    Output, int FIND_CLOSEST1[NS], the index of the nearest data point.
*/
{
  double dist_sq;
  double dist_sq_min;
  int i;
  int jr;
  int js;
  int *nearest;
  static double r8_huge = 1.0E+30;

  nearest = ( int * ) malloc ( ns * sizeof ( int ) );

  for ( js = 0; js < ns; js++ )
  {
    dist_sq_min = r8_huge;
    nearest[js] = -1;
    for ( jr = 0; jr < nr; jr++ )
    {
      dist_sq = 0.0;
      for ( i = 0; i < m; i++ )
      {
        dist_sq = dist_sq + pow ( r[i+jr*m] - s[i+js*m], 2 );
      }
      if ( dist_sq < dist_sq_min )
      {
        dist_sq_min = dist_sq;
        nearest[js] = jr;
      }
    }
  }

  return nearest;
}
/******************************************************************************/

double *r8mat_uniform_01_new ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8MAT_UNIFORM_01_NEW fills an R8MAT with pseudorandom values scaled to [0,1].

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 June 2009

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    Philip Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0, otherwise the output value of SEED
    will still be 0, and R8_UNIFORM will be 0.  On output, SEED has
    been updated.

    Output, double R8MAT_UNIFORM_01_NEW[M*N], a matrix of pseudorandom values.
*/
{
  int i;
  int j;
  int k;
  double *r;

  r = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = *seed / 127773;

      *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

      if ( *seed < 0 )
      {
        *seed = *seed + 2147483647;
      }
      r[i+j*m] = ( double ) ( *seed ) * 4.656612875E-10;
    }
  }

  return r;
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

