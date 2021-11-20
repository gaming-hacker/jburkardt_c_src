# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa053.h"

/******************************************************************************/

void r8pp_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8PP_PRINT prints a R8PP matrix.

  Discussion:

    The R8PP storage format is appropriate for a symmetric positive
    definite matrix.  Only the upper triangle of the matrix is stored,
    by successive partial columns, in an array of length (N*(N+1))/2,
    which contains (A11,A12,A22,A13,A23,A33,A14,...,ANN)  

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 February 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[(N*(N+1))/2], the R8PP matrix.

    Input, char *TITLE, a title.
*/
{
  r8pp_print_some ( n, a, 1, 1, n, n, title );

  return;
}

