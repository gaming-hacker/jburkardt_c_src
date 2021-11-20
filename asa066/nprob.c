# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa066.h"

/******************************************************************************/

void nprob ( double z, double *p, double *q, double *pdf )

/******************************************************************************/
/*
  Purpose:

    NPROB computes the cumulative density of the standard normal distribution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2013

  Author:

    Original FORTRAN77 version by AG Adams.
    C version by John Burkardt.

  Reference:

    AG Adams,
    Algorithm 39:
    Areas Under the Normal Curve,
    Computer Journal,
    Volume 12, Number 2, May 1969, pages 197-198.

  Parameters:

    Input, double Z, divides the real line into 
    two semi-infinite intervals, over each of which the standard normal 
    distribution is to be integrated.

    Output, double *P, *Q, the integrals of the standard normal
    distribution over the intervals ( - Infinity, Z] and 
    [Z, + Infinity ), respectively.

    Output, double *PDF, the value of the standard normal
    distribution at Z.
*/
{
  double a0 = 0.5;
  double a1 = 0.398942280444;
  double a2 = 0.399903438504;
  double a3 = 5.75885480458;
  double a4 = 29.8213557808;
  double a5 = 2.62433121679;
  double a6 = 48.6959930692;
  double a7 = 5.92885724438;
  double b0 = 0.398942280385;
  double b1 = 0.000000038052;
  double b2 = 1.00000615302;
  double b3 = 0.000398064794;
  double b4 = 1.98615381364;
  double b5 = 0.151679116635;
  double b6 = 5.29330324926;
  double b7 = 4.8385912808;
  double b8 = 15.1508972451;
  double b9 = 0.742380924027;
  double b10 = 30.789933034;
  double b11 = 3.99019417011;
  double y;
  double zabs;

  zabs = fabs ( z );
/*
  |Z| between 0 and 1.28
*/
  if ( zabs <= 1.28 )
  {
    y = a0 * z * z;
    *pdf = exp ( - y ) * b0;

    *q = a0 - zabs * ( a1 - a2 * y 
      / ( y + a3 - a4 
      / ( y + a5 + a6 
      / ( y + a7 ))));
  }
/*
  |Z| between 1.28 and 12.7
*/
  else if ( zabs <= 12.7 )
  {
    y = a0 * z * z;
    *pdf = exp ( - y ) * b0;

    *q = *pdf 
      / ( zabs - b1 + b2 
      / ( zabs + b3 + b4 
      / ( zabs - b5 + b6 
      / ( zabs + b7 - b8 
      / ( zabs + b9 + b10 
      / ( zabs + b11 ))))));
  }
/*
  Z far out in tail.
*/
  else
  {
    *q = 0.0;
    *pdf = 0.0;
  }

  if ( z < 0.0 )
  {
    *p = *q;
    *q = 1.0 - *p;
  }
  else
  {
   *p = 1.0 - *q;
  }

  return;
}

