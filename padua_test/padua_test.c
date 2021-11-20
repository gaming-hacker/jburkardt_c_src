# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "padua.h"

int main ( );
void padua_order_test ( );
void padua_plot_test ( );
void padua_points_test ( );
void padua_points_set_test ( );
void padua_weights_test ( );
void padua_weights_set_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PADUA_TEST.

  Discussion:

    PADUA_TEST tests the PADUA library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "PADUA_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the PADUA library.\n" );

  padua_order_test ( );
  padua_plot_test ( );
  padua_points_test ( );
  padua_points_set_test ( );
  padua_weights_test ( );
  padua_weights_set_test ( );
/*
  Terminate.
*/
  printf ( " \n" );
  printf ( "PADUA_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( " \n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void padua_order_test ( )

/******************************************************************************/
/*
  Purpose:

    PADUA_ORDER_TEST tests PADUA_ORDER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2016

  Author:

    John Burkardt
*/
{
  int l;
  int n;

  printf ( " \n" );
  printf ( "PADUA_ORDER_TEST\n" );
  printf ( "  PADUA_ORDER converts the level L into the order N\n" );
  printf ( "  of any Padua rule.\n" );
  printf ( " \n" );
  printf ( "     L         N\n" );
  printf ( " \n" );

  for ( l = 0; l <= 10; l++ )
  {
    n = padua_order ( l );
    printf ( "  %4d  %8d\n", l, n );
  }

  return;
}
/******************************************************************************/

void padua_plot_test ( )

/******************************************************************************/
/*
  Purpose:

    PADUA_PLOT_TEST tests PADUA_PLOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 September 2016

  Author:

    John Burkardt
*/
{
  char filename[255];
  int l;
 
  printf ( " \n" );
  printf ( "PADUA_PLOT_TEST\n" );
  printf ( "  PADUA_PLOT plots the Padua points.\n" );

  strcpy ( filename, "padua_00" );

  for ( l = 0; l <= 10; l++ )
  {
    padua_plot ( l, filename );
    filename_inc ( filename );
  }

  return;
}
/******************************************************************************/

void padua_points_test ( )

/******************************************************************************/
/*
  Purpose:

    PADUA_POINTS_TEST tests PADUA_POINTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2016

  Author:

    John Burkardt
*/
{
  int l;
  char label[255];
  int n;
  double *xy;

  printf ( " \n" );
  printf ( "PADUA_POINTS_TEST\n" );
  printf ( "  PADUA_POINTS returns the points of a Padua rule.\n" );

  for ( l = 0; l <= 10; l++ )
  {
    n = padua_order ( l );
    xy = padua_points ( l );
    sprintf ( label, "  Level %d Padua points:", l );
    r8mat_transpose_print ( 2, n, xy, label );
    free ( xy );
  }

  return;
}
/******************************************************************************/

void padua_points_set_test ( )

/******************************************************************************/
/*
  Purpose:

    PADUA_POINTS_SET_TEST tests PADUA_POINTS_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2016

  Author:

    John Burkardt
*/
{
  int j;
  int l;
  int n;
  double *xy1;
  double *xy2;

  printf ( " \n" );
  printf ( "PADUA_POINTS_SET_TEST\n" );
  printf ( "  PADUA_POINTS_SET looks up Padua points in a table.\n" );

  for ( l = 3; l <= 4; l++ )
  {
    n = padua_order ( l );
    xy1 = padua_points ( l );
    xy2 = padua_points_set ( l );
    printf ( "\n" );
    printf ( "  Level %d Padua points\n", l );
    printf ( "\n" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d  %14.6g  %14.6g\n", j, xy1[0+j*2], xy1[1+j*2] );
      printf ( "        %14.6g  %14.6g\n",   xy2[0+j*2], xy2[1+j*2] );
    }
    free ( xy1 );
    free ( xy2 );
  }

  return;
}
/******************************************************************************/

void padua_weights_test ( )

/******************************************************************************/
/*
  Purpose:

    PADUA_WEIGHTS_TEST tests PADUA_WEIGHTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2016

  Author:

    John Burkardt
*/
{
  int l;
  char label[255];
  int n;
  double *w;

  printf ( " \n" );
  printf ( "PADUA_WEIGHTS_TEST\n" );
  printf ( "  PADUA_WEIGHTS returns the weights of a Padua rule.\n" );

  for ( l = 0; l <= 10; l++ )
  {
    n = padua_order ( l );
    w = padua_weights ( l );
    sprintf ( label, "  Level %d Padua weights:", l );
    r8vec_print ( n, w, label );
    free ( w );
  }

  return;
}
/******************************************************************************/

void padua_weights_set_test ( )

/******************************************************************************/
/*
  Purpose:

    PADUA_WEIGHTS_SET_TEST tests PADUA_WEIGHTS_SET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2016

  Author:

    John Burkardt
*/
{
  double diff;
  int j;
  int l;
  int n;
  double *w1;
  double *w2;

  printf ( " \n" );
  printf ( "PADUA_WEIGHTS_SET_TEST\n" );
  printf ( "  PADUA_WEIGHTS_SET looks up Padua weights in a table.\n" );

  for ( l = 3; l <= 4; l++ )
  {
    n = padua_order ( l );
    w1 = padua_weights ( l );
    w2 = padua_weights_set ( l );
    printf ( "\n" );
    printf ( "  Level %d Padua weights\n", l );
    printf ( "              Computed          Lookup\n" );
    printf ( "\n" );
    diff = 0.0;
    for ( j = 0; j < n; j++ )
    {
      diff = r8_max ( diff, fabs ( w1[j] - w2[j] ) );
      printf ( "  %4d  %14.6g  %14.6g\n", j, w1[j], w2[j] );
    }
    printf ( "\n" );
    printf ( "  Maximum difference = %g\n", diff );
    free ( w1 );
    free ( w2 );
  }

  return;
}

