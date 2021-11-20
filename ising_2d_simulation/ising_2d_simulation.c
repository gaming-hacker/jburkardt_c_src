# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>

int main ( int argc, char *argv[] );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_modp ( int i, int j );
int i4_wrap ( int ival, int ilo, int ihi );
void ising_2d_agree ( int m, int n, int c1[], int c5[] );
int *ising_2d_initialize ( int m, int n, double thresh, int *seed );
void ising_2d_stats ( int step, int m, int n, int c1[] );
void neighbor_2d_stats ( int step, int m, int n, int c1[], int c5[] );
void plot_file ( int m, int n, int c1[], char *title, char *plot_filename,
  char *png_filename );
void r8mat_uniform_01 ( int m, int n, int *seed, double r[] );
void timestamp ( );
void transition ( int m, int n, int iterations, double prob[], 
  double thresh, int *seed, int c1[] );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ISING_2D_SIMULATION.

  Usage:

    ising_2d_simulation  m  n  iterations  thresh  seed

    * M, N, the number of rows and columns.
    * ITERATIONS, the number of iterations.
    * THRESH, the threshhold.
    * SEED, a seed for the random number generator.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 June 2013

  Author:

    John Burkardt
*/
{
  int *c1;
  int i;
  int iterations;
  int m;
  int n;
  double prob[5] = { 0.98, 0.85, 0.50, 0.15, 0.02 };
  int seed;
  double thresh;

  timestamp ( );
  printf ( "\n" );
  printf ( "ISING_2D_SIMULATION\n" );
  printf ( "  C version\n" );
  printf ( "  Monte Carlo simulation of a 2D Ising model.\n" );
/*
  Get input.
*/
  if ( 1 < argc )
  {
    m = atoi ( argv[1] );
  }
  else
  {
    m = 10;
  }
  if ( 2 < argc )
  {
    n = atoi ( argv[2] );
  }
  else
  {
    n = 10;
  }
  if ( 3 < argc )
  {
    iterations = atoi ( argv[3] );
  }
  else
  {
    iterations = 15;
  }
  if ( 4 < argc )
  {
    thresh = atof ( argv[4] );
  }
  else
  {
    thresh = 0.50;
  }
  if ( 5 < argc )
  {
    seed = atoi ( argv[5] );
  }
  else
  {
    seed = 123456789;
  }
  printf ( "\n" );
  printf ( "  The number of rows is M = %d\n", m );
  printf ( "  The number of columns is N = %d\n", n );
  printf ( "  The number of iterations taken is ITERATIONS = %d\n", iterations );
  printf ( "  The threshhold THRESH = %f\n", thresh );
  printf ( "  The seed SEED = %d\n", seed );
  printf ( "\n" );
  printf ( "  The transition probability table, based on the number of\n" );
  printf ( "  neighbors with the same spin.\n" );
  printf ( "\n" );
  printf ( "      1         2         3         4         5\n" );
  printf ( "\n" );
  for ( i = 0; i < 5; i++ )
  {
    printf ( "%10.4f", prob[i] );
  }
  printf ( "\n" );
/*
  Initialize the system.
*/
  c1 = ising_2d_initialize ( m, n, thresh, &seed );
/*
  Write the initial state to a gnuplot file.
*/
  plot_file ( m, n, c1, "Initial Configuration", "ising_2d_initial.txt", 
    "ising_2d_initial.png" );
/*
  Do the simulation.
*/
  transition ( m, n, iterations, prob, thresh, &seed, c1 );
/*
  Write the final state to a gnuplot file.
*/
  plot_file ( m, n, c1, "Final Configuration", "ising_2d_final.txt", 
    "ising_2d_final.png" );
/*
  Free memory.
*/
  free ( c1 );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ISING_2D_SIMULATION\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_modp ( int i, int j )

/******************************************************************************/
/*
  Purpose:

    I4_MODP returns the nonnegative remainder of I4 division.

  Discussion:

    If
      NREM = I4_MODP ( I, J )
      NMULT = ( I - NREM ) / J
    then
      I = J * NMULT + NREM
    where NREM is always nonnegative.

    The MOD function computes a result with the same sign as the
    quantity being divided.  Thus, suppose you had an angle A,
    and you wanted to ensure that it was between 0 and 360.
    Then mod(A,360) would do, if A was positive, but if A
    was negative, your result would be between -360 and 0.

    On the other hand, I4_MODP(A,360) is between 0 and 360, always.

  Example:

        I         J     MOD  I4_MODP   I4_MODP Factorization

      107        50       7       7    107 =  2 *  50 + 7
      107       -50       7       7    107 = -2 * -50 + 7
     -107        50      -7      43   -107 = -3 *  50 + 43
     -107       -50      -7      43   -107 =  3 * -50 + 43

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 January 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, the number to be divided.

    Input, int J, the number that divides I.

    Output, int I4_MODP, the nonnegative remainder when I is
    divided by J.
*/
{
  int value;

  if ( j == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4_MODP - Fatal error!\n" );
    fprintf ( stderr, "  I4_MODP ( I, J ) called with J = %d\n", j );
    exit ( 1 );
  }

  value = i % j;

  if ( value < 0 )
  {
    value = value + abs ( j );
  }

  return value;
}
/******************************************************************************/

int i4_wrap ( int ival, int ilo, int ihi )

/******************************************************************************/
/*
  Purpose:

    I4_WRAP forces an I4 to lie between given limits by wrapping.

  Example:

    ILO = 4, IHI = 8

    I   Value

    -2     8
    -1     4
     0     5
     1     6
     2     7
     3     8
     4     4
     5     5
     6     6
     7     7
     8     8
     9     4
    10     5
    11     6
    12     7
    13     8
    14     4

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int IVAL, an integer value.

    Input, int ILO, IHI, the desired bounds for the integer value.

    Output, int I4_WRAP, a "wrapped" version of IVAL.
*/
{
  int jhi;
  int jlo;
  int value;
  int wide;

  jlo = i4_min ( ilo, ihi );
  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )
  {
    value = jlo;
  }
  else
  {
    value = jlo + i4_modp ( ival - jlo, wide );
  }

  return value;
}
/******************************************************************************/

void ising_2d_agree ( int m, int n, int c1[], int c5[] )

/******************************************************************************/
/*
  Purpose:

    ISING_2D_AGREE returns the number of neighbors agreeing with each cell.

  Discussion:

    The count includes the cell itself, so it is between 1 and 5.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 Noveber 2011

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of cells in each 
    spatial dimension.

    Input, int C1[M*N], an array of 1's and -1's.

    Output, int C5[M*N], the number of neighbors 
    that agree.  1, 2, 3, 4, or 5.
*/
{
  int i;
  int im;
  int ip;
  int j;
  int jm;
  int jp;

  for ( j = 0; j < n; j++ )
  {
    jp = i4_wrap ( j + 1, 0, n - 1 );
    jm = i4_wrap ( j - 1, 0, n - 1 );
    for ( i = 0; i < m; i++ )
    {
      ip = i4_wrap ( i + 1, 0, m - 1 );
      im = i4_wrap ( i - 1, 0, m - 1 );
      c5[i+j*m] = c1[i+j*m] + c1[ip+j*m] + c1[im+j*m] + c1[i+jm*m] + c1[i+jp*m];
      if ( 0 < c1[i+j*m] )
      {
        c5[i+j*m] = ( 5 + c5[i+j*m] ) / 2;
      }
      else
      {
        c5[i+j*m] = ( 5 - c5[i+j*m] ) / 2;
      }
    }
  }
  return;
}
/******************************************************************************/

int *ising_2d_initialize ( int m, int n, double thresh, int *seed )

/******************************************************************************/
/*
  Purpose:

    ISING_2D_INITIALIZE initializes the Ising array.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double THRESH, the threshhold.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, in ISING_2D_INITIALIZE[M*N], the initial Ising array.
*/
{
  int *c1;
  int i;
  int j;
  double *r;

  r = ( double * ) malloc ( m * n * sizeof ( double ) );

  r8mat_uniform_01 ( m, n, seed, r );

  c1 = ( int * ) malloc ( m * n * sizeof ( int ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( r[i+j*m] <= thresh )
      {
        c1[i+j*m] = -1;
      }
      else
      {
        c1[i+j*m] = +1;
      }
    }
  }
  free ( r );

  return c1;
}
/******************************************************************************/

void ising_2d_stats ( int step, int m, int n, int c1[] )

/******************************************************************************/
/*
  Purpose:

    ISING_2D_STATS prints information about the current step.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int STEP, the step number.

    Input, int M, N, the number of rows and columns.

    Input, int C1[M*N], the current state of the system.
*/
{
  int i;
  int j;
  int pos_count;
  double pos_percent;
  int neg_count;
  double neg_percent;

  if ( step == 0 )
  {
    printf ( "\n" );
    printf ( "  Step     Positives       Negatives\n" );
    printf ( "             #    %%          #    %%\n" );
    printf ( "\n" );
  }

  pos_count = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( 0 < c1[i+j*m] )
      {
        pos_count = pos_count + 1;
      }
    }
  }
  neg_count = m * n - pos_count;
  pos_percent = ( double ) ( 100 * pos_count ) / ( double ) ( m * n );
  neg_percent = ( double ) ( 100 * neg_count ) / ( double ) ( m * n );

  printf ( "  %4d  %6d  %6.2f  %6d  %6.2f\n",
    step, pos_count, pos_percent, neg_count, neg_percent );

  return;
}
/******************************************************************************/

void neighbor_2d_stats ( int step, int m, int n, int c1[], int c5[] )

/******************************************************************************/
/*
  Purpose:

    NEIGHBOR_2D_STATS prints neighbor statistics about the current step.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int STEP, the step number.

    Input, int M, N, the number of rows and columns.

    Input, int C1[M*N], the current state of the system.

    Input, int C5[M*N], the number of agreeable neighbors.
*/
{
  int i;
  int j;
  int stats[11];

  if ( step == 0 )
  {
    printf ( "\n" );
    printf ( "  Step     Neighborhood Charge:\n" );
    printf ( "           -5    -4    -3    -2    -1     +1    +2    +3    +4    +5\n" );
    printf ( "\n" );
  }

  for ( i = - 5; i <= 5; i++ )
  {
    stats[i+5] = 0;
  }

  for (j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      stats[c5[i+j*m]-1+5] = stats[c5[i+j*m]-1+5] + 1;
    }
  }
  printf ( "  %4d", step );
  for ( i = - 5; i <= 5; i++ )
  {
    if ( i != 0 )
    {
      printf ( "  %4d", stats[i+5] );
    }
  }
  printf ( "\n" );
      
  return;
}
/******************************************************************************/

void plot_file ( int m, int n, int c1[], char *title, char *plot_filename,
  char *png_filename )

/******************************************************************************/
/*
  Purpose:

    PLOT_FILE writes the current configuration to a GNUPLOT plot file.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 June 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, int C1[M*N], the current state of the system.

    Input, char *TITLE, a title for the plot.

    Input, char *PLOT_FILENAME, a name for the GNUPLOT
    command file to be created.

    Input, char *PNG_FILENAME, the name of the PNG graphics
    file to be created.
*/
{
  int i;
  int j;
  FILE *plot_unit;
  double ratio;
  int x1;
  int x2;
  int y1;
  int y2;

  plot_unit = fopen ( plot_filename, "wt" );

  ratio = ( double ) ( n ) / ( double ) ( m );

  fprintf ( plot_unit, "set term png\n" );
  fprintf ( plot_unit, "set output \"%s\"\n", png_filename );
  fprintf ( plot_unit, "set xrange [ 0 : %d ]\n", m );
  fprintf ( plot_unit, "set yrange [ 0 : %d ]\n", n );
  fprintf ( plot_unit, "set nokey\n" );
  fprintf ( plot_unit, "set title \"%s\"\n", title );
  fprintf ( plot_unit, "unset tics\n" );

  fprintf  ( plot_unit, "set size ratio %g\n", ratio );
  for ( j = 0; j < n; j++ )
  {
    y1 = j;
    y2 = j + 1;
    for ( i = 0; i < m; i++ )
    {
      x1 = m - i - 1;
      x2 = m - i;
      if ( c1[i+j*m] < 0 )
      {
        fprintf ( plot_unit, 
          "set object rectangle from %d, %d to %d, %d fc rgb 'blue'\n", 
          x1, y1, x2, y2 );
      }
      else
      {
        fprintf ( plot_unit, 
          "set object rectangle from %d, %d to %d, %d fc rgb 'red'\n", 
          x1, y1, x2, y2 );
      }
    }
  }

  fprintf  ( plot_unit, "plot 1\n" );
  fprintf  ( plot_unit, "quit\n" );

  fclose ( plot_unit );

  printf ( "\n" );
  printf ( "  Created the gnuplot graphics file \"%s\"\n", plot_filename );

  return;
}
/******************************************************************************/

void r8mat_uniform_01 ( int m, int n, int *seed, double r[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_UNIFORM_01 fills an R8MAT with unit pseudorandom values.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values,  stored as a vector
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

    Output, double R[M*N], a matrix of pseudorandom values.
*/
{
  int i;
  int j;
  int k;

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

void transition ( int m, int n, int iterations, double prob[], 
  double thresh, int *seed, int c1[] )

/******************************************************************************/
/*
  Purpose:

    TRANSITION carries out a Monte Carlo simulation of a 3D Ising model.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, int ITERATIONS, the number of iterations.

    Input, double PROB[5].  PROB[I-1] represents the probability 
    that the spin of a given cell will be reversed, given that it has I 
    immediate neighbors (including itself) with spin the same as its own.

    Input, double THRESH, the threshhold.

    Input/output, int *SEED, a seed for the random number 
    generator.

    Input/output, int *C1[M*N], the current state of the system.
*/
{
  int *c5;
  int i;
  int j;
  double *r;
  int step;

  c5 = ( int * ) malloc ( m * n * sizeof ( int ) );
  r = ( double * ) malloc ( m * n * sizeof ( double ) );

  step = 0;
  ising_2d_stats ( step, m, n, c1 );

  for ( step = 1; step <= iterations; step++ )
  {
/*
  C5 contains 1 through 5, the number of cells that agree with the center cell.
*/
    ising_2d_agree ( m, n, c1, c5 );

    if ( 0 )
    {
      neighbor_2d_stats ( step, m, n, c1, c5 );
    }
/*
  Determine the chances of flipping cell (I,J).
*/
    r8mat_uniform_01 ( m, n, seed, r );

    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        if ( r[i+j*m] < prob[c5[i+j*m]-1] )
        {
          c1[i+j*m] = - c1[i+j*m];
        }
      }
    }
    ising_2d_stats ( step, m, n, c1 );
  }
  free ( c5 );
  free ( r );

  return;
}
