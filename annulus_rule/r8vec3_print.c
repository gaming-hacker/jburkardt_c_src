# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "annulus_rule.h"

/******************************************************************************/

void r8vec3_print ( int n, double a1[], double a2[], double a3[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC3_PRINT prints a triple of real vectors.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A1[N], double A2[N], double A3[N], the vectors
    to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  printf ( "\n" );
  printf ( "%s\n", title );
  printf ( "\n" );
  for ( i = 0; i < n; i++ )
  {
    printf ( "  %4d  %10g  %10g  %10g\n", i, a1[i], a2[i], a3[i] );
  }

  return;
}

