# include <stdio.h>

# include "constants.h"

/******************************************************************************/

void constants ( double *g, double *c, double *h )

/******************************************************************************/
/*
  Purpose:

    constants() stores, and returns constants "g", "c" and "h".

  Discussion:

    Calling [g,c,h]=constants() returns the values of g, c, and h.

    Because the values never change, and don't need to be computed,
    we use assignment statements here, instead of persistent data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 May 2021

  Author:

    John Burkardt

  Output:

    double *G: gravitational constant m^3/s^2/kg

    double *C: light speed, m/s.

    double *H: Planck's constant, j s;
*/
{
  *g = 6.67384E-11;
  *c = 2.99792458E+8;
  *h = 6.626070040E-34;

  return;
}

