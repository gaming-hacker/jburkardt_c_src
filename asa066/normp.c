# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa066.h"

/******************************************************************************/

void normp ( double z, double *p, double *q, double *pdf )

/******************************************************************************/
/*
  Purpose:

    NORMP computes the cumulative density of the standard normal distribution.

  Discussion:

    This is algorithm 5666 from Hart, et al.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 November 2010

  Author:

    Original FORTRAN77 version by Alan Miller.
    C++ version by John Burkardt.

  Reference:

    John Hart, Ward Cheney, Charles Lawson, Hans Maehly, 
    Charles Mesztenyi, John Rice, Henry Thacher, 
    Christoph Witzgall,
    Computer Approximations,
    Wiley, 1968,
    LC: QA297.C64.

  Parameters:

    Input, double Z, divides the real line into two 
    semi-infinite intervals, over each of which the standard normal 
    distribution is to be integrated.

    Output, double *P, *Q, the integrals of the standard normal
    distribution over the intervals ( - Infinity, Z] and 
    [Z, + Infinity ), respectively.

    Output, double *PDF, the value of the standard normal distribution
    at Z.
*/
{
  double cutoff = 7.071;
  double expntl;
  double p0 = 220.2068679123761;
  double p1 = 221.2135961699311;
  double p2 = 112.0792914978709;
  double p3 = 33.91286607838300;
  double p4 = 6.373962203531650;
  double p5 = 0.7003830644436881;
  double p6 = 0.03526249659989109;
  double q0 = 440.4137358247522;
  double q1 = 793.8265125199484;
  double q2 = 637.3336333788311;
  double q3 = 296.5642487796737;
  double q4 = 86.78073220294608;
  double q5 = 16.06417757920695;
  double q6 = 1.755667163182642;
  double q7 = 0.08838834764831844;
  double root2pi = 2.506628274631001;
  double zabs;

  zabs = fabs ( z );
/*
  37 < |Z|.
*/
  if ( 37.0 < zabs )
  {
    *pdf = 0.0;
    *p = 0.0;
  }
/*
  |Z| <= 37.
*/
  else
  {
    expntl = exp ( - 0.5 * zabs * zabs );
    *pdf = expntl / root2pi;
/*
  |Z| < CUTOFF = 10 / sqrt(2).
*/
    if ( zabs < cutoff )
    {
      *p = expntl * (((((( 
          p6   * zabs 
        + p5 ) * zabs 
        + p4 ) * zabs 
        + p3 ) * zabs 
        + p2 ) * zabs 
        + p1 ) * zabs 
        + p0 ) / ((((((( 
          q7   * zabs 
        + q6 ) * zabs 
        + q5 ) * zabs 
        + q4 ) * zabs 
        + q3 ) * zabs 
        + q2 ) * zabs 
        + q1 ) * zabs 
      + q0 );
    }
/*
  CUTOFF <= |Z|.
*/
    else
    {
      *p = *pdf / ( 
        zabs + 1.0 / ( 
        zabs + 2.0 / ( 
        zabs + 3.0 / ( 
        zabs + 4.0 / ( 
        zabs + 0.65 )))));
    }
  }

  if ( z < 0.0 )
  {
    *q = 1.0 - *p;
  }
  else
  {
    *q = *p;
    *p = 1.0 - *q;
  }

  return;
}

