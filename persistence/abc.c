# include <stdlib.h>

# include "abc.h"

/******************************************************************************/

void abc ( double *a_in, double *b_in, double *c_in, double *a_out, 
  double *b_out, double *c_out )

/******************************************************************************/
/*
  Purpose:

    abc() stores, saves, and returns varables "a", "b" and "c".

  Discussion:

    Calling abc() with no input arguments returns the current
    values of A, B, and C.

    Calling abc(a_in,b_in,c_in) supplies new values for A, B,
    and C which overwrite the current values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 May 2021

  Author:

    John Burkardt

  Input:

    double A_IN: a new value for A.

    double B_IN: a new value for B.

    double C_IN: a new value for C.

  Local static:

    double A_DEFAULT: the current value of A.

    double B_DEFAULT: the current value of B.

    double C_DEFAULT: the current value of C.

  Output:

    double A_OUT: the current value of A.

    double B_OUT: the current value of B.

    double C_OUT: the current value or C.
*/
{
  static double a_default = 1.0;
  static double b_default = 2.0;
  static double c_default = 3.0;
/*
  New values, if supplied on input, overwrite the current values.
*/
  if ( a_in )
  {
    a_default = *a_in;
  }

  if ( b_in )
  {
    b_default = *b_in;
  }

  if ( c_in )
  {
    c_default = *c_in;
  }
/*
  The current values are copied to the output.
*/
  if ( a_out )
  {
    *a_out = a_default;
  }
  if ( b_out )
  {
    *b_out = b_default;
  }
  if ( c_out )
  {
    *c_out = c_default;
  }

  return;
}

