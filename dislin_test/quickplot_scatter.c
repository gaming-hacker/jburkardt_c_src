# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "dislin_d.h"

int main ( int argc, char *argv[] );
double r8_uniform_01 ( int *seed );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    QUICKPLOT_SCATTER demonstrates the DISLIN quickplot command QPLOT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:
 
    28 February 2014

  Author:

    This C version by John Burkardt.

  Reference:

    Helmut Michels,
    The Data Plotting Software DISLIN - version 10.4,
    Shaker Media GmbH, January 2010,
    ISBN13: 978-3-86858-517-9.
*/
{
  int i;
  int j;
  int n = 100;
  double s;
  int seed;
  double *xvec;
  double *yvec;

  timestamp ( );
  printf ( "\n" );
  printf ( "QUICKPLOT_SCATTER:\n" );
  printf ( "  C version\n" );
  printf ( "  Demonstrate the DISLIN \"quickplot\" command QPLSCA\n" );
  printf ( "  to make a scatter plot.\n" );
/*
  Generate the data.  
  We average 4 random values to get data that tends to cluster
  near (0.5,0.5).
*/
  seed = 123456789;

  xvec = ( double * ) malloc ( n * sizeof ( double ) );
  yvec = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    s = 0.0;
    for ( j = 1; j <= 4 ; j++ )
    {
      s = s + r8_uniform_01 ( &seed );
    }
    xvec[i] = s / 4.0;
  }

  for ( i = 0; i < n; i++ )
  {
    s = 0.0;
    for ( j = 1; j <= 4 ; j++ )
    {
      s = s + r8_uniform_01 ( &seed );
    }
    yvec[i] = s / 4.0;
  }
/*
  Specify the format of the output file.
*/
  metafl ( "png" );
/*
  Indicate that new data overwrites old data.
*/
  filmod ( "delete" );
/*
  Specify the name of the output graphics file.
*/
  setfil ( "quickplot_scatter.png" );
/*
  Choose the page size and orientation.
*/
  setpag ( "usal" );
/*
  For PNG output, reverse the default black background to white.
*/
  scrmod ( "reverse" );
/*
  Open DISLIN.
*/
  disini ( );
/*
  Label the axes and the plot.
*/
  name ( "<-- X -->", "X" );
  name ( "<-- Y -->", "Y" );
  titlin ( "Quick plot by QPLSCA", 2 );
/*
  Draw the curve.
*/
  qplsca ( xvec, yvec, n );
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Free memory.
*/
  free ( xvec );
  free ( yvec );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "QUICKPLOT_SCATTER:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a pseudorandom R8 scaled to [0,1].

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

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
