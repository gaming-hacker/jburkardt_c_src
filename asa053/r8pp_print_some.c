# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa053.h"

/******************************************************************************/

void r8pp_print_some ( int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8PP_PRINT_SOME prints some of a R8PP matrix.

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

    Input, int ILO, JLO, IHI, JHI, designate the first row and
    column, and the last row and column to be printed.

    Input, char *TITLE, a title.
*/
{
# define INCX 5

  double aij;
  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  printf ( "\n" );
  printf ( "%s\n", title );
/*
  Print the columns of the matrix, in strips of 5.
*/
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    printf ( "\n" );
    printf ( "  Col: " );
    for ( j = j2lo; j <= j2hi; j++ )
    {
      printf ( "%7d       ", j );
    }
    printf ( "\n" );
    printf ( "  Row\n" );
    printf ( "  ---\n" );
/*
  Determine the range of the rows in this strip.
*/
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )
    {
      printf ( "%6d  ", i );
/*
  Print out (up to) 5 entries in row I, that lie in the current strip.
*/
      for ( j = j2lo; j <= j2hi; j++ )
      {
        if ( i <= j )
        {
          aij = a[i-1+(j*(j-1))/2];
        }
        else
        {
          aij = a[j-1+(i*(i-1))/2];
        }

        printf ( "%12g  ", aij );
      }
      printf ( "\n" );
    }
  }

  return;
# undef INCX
}

