# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "test_interp.h"
# include "r8lib.h"

/******************************************************************************/

double *data_copy_new ( int m, int n, double a1[] )

/******************************************************************************/
/*
  Purpose:

    DATA_COPY_NEW copies a data array.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double A1[M*N], the matrix to be copied.

    Output, double DATA_COPY_NEW[M*N], the copy of A1.
*/
{
  double *a2;
  int i;
  int j;

  a2 = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }

  return a2;
}
/******************************************************************************/

double *p00_data ( int prob, int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P00_DATA returns the data for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P00_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;

  if ( prob == 1 )
  {
    p_data = p01_data ( dim_num, data_num );
  }
  else if ( prob == 2 )
  {
    p_data = p02_data ( dim_num, data_num );
  }
  else if ( prob == 3 )
  {
    p_data = p03_data ( dim_num, data_num );
  }
  else if ( prob == 4 )
  {
    p_data = p04_data ( dim_num, data_num );
  }
  else if ( prob == 5 )
  {
    p_data = p05_data ( dim_num, data_num );
  }
  else if ( prob == 6 )
  {
    p_data = p06_data ( dim_num, data_num );
  }
  else if ( prob == 7 )
  {
    p_data = p07_data ( dim_num, data_num );
  }
  else if ( prob == 8 )
  {
    p_data = p08_data ( dim_num, data_num );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_DATA - Fatal error!\n" );
    printf ( "  Unexpected input value of PROB.\n" );
    exit ( 1 );
  }

  return p_data;
}
/******************************************************************************/

int p00_data_num ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_DATA_NUM returns the number of data points for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2012

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Output, int P00_DATA_NUM, the number of data points.
*/
{
  int data_num;

  if ( prob == 1 )
  {
    data_num = p01_data_num ( );
  }
  else if ( prob == 2 )
  {
    data_num = p02_data_num ( );
  }
  else if ( prob == 3 )
  {
    data_num = p03_data_num ( );
  }
  else if ( prob == 4 )
  {
    data_num = p04_data_num ( );
  }
  else if ( prob == 5 )
  {
    data_num = p05_data_num ( );
  }
  else if ( prob == 6 )
  {
    data_num = p06_data_num ( );
  }
  else if ( prob == 7 )
  {
    data_num = p07_data_num ( );
  }
  else if ( prob == 8 )
  {
    data_num = p08_data_num ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_DATA_NUM - Fatal error!\n" );
    printf ( "  Unexpected input value of PROB.\n" );
    exit ( 1 );
  }

  return data_num;
}
/******************************************************************************/

int p00_dim_num ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_DIM_NUM returns the spatial dimension for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2012

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.

    Output, int P00_DIM_NUM, the spatial dimension of the
    dependent variables.
*/
{
  int dim_num;

  if ( prob == 1 )
  {
    dim_num = p01_dim_num ( );
  }
  else if ( prob == 2 )
  {
    dim_num = p02_dim_num ( );
  }
  else if ( prob == 3 )
  {
    dim_num = p03_dim_num ( );
  }
  else if ( prob == 4 )
  {
    dim_num = p04_dim_num ( );
  }
  else if ( prob == 5 )
  {
    dim_num = p05_dim_num ( );
  }
  else if ( prob == 6 )
  {
    dim_num = p06_dim_num ( );
  }
  else if ( prob == 7 )
  {
    dim_num = p07_dim_num ( );
  }
  else if ( prob == 8 )
  {
    dim_num = p08_dim_num ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_DIM_NUM - Fatal error!\n" );
    printf ( "  Unexpected input value of PROB.\n" );
    exit ( 1 );
  }

  return dim_num;
}
/******************************************************************************/

int p00_prob_num ( )

/******************************************************************************/
/*
  Purpose:

    P00_PROB_NUM returns the number of test problems.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P00_PROB_NUM, the number of test problems.
*/
{
  int prob_num;

  prob_num = 8;

  return prob_num;
}
/******************************************************************************/

void p00_story ( int prob )

/******************************************************************************/
/*
  Purpose:

    P00_STORY prints the "story" for any problem.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2012

  Author:

    John Burkardt

  Parameters:

    None
*/
{
  if ( prob == 1 )
  {
    p01_story ( );
  }
  else if ( prob == 2 )
  {
    p02_story ( );
  }
  else if ( prob == 3 )
  {
    p03_story ( );
  }
  else if ( prob == 4 )
  {
    p04_story ( );
  }
  else if ( prob == 5 )
  {
    p05_story ( );
  }
  else if ( prob == 6 )
  {
    p06_story ( );
  }
  else if ( prob == 7 )
  {
    p07_story ( );
  }
  else if ( prob == 8 )
  {
    p08_story ( );
  }
  else
  {
    printf ( "\n" );
    printf ( "P00_STORY - Fatal error!\n" );
    printf ( "  Unexpected input value of PROB.\n" );
    exit ( 1 );
  }

  return;
}
/******************************************************************************/

double *p01_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P01_DATA returns the data for problem p01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P01_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*18] = {
    0.0, 4.0, 
    1.0, 5.0, 
    2.0, 6.0, 
    4.0, 6.0, 
    5.0, 5.0, 
    6.0, 3.0, 
    7.0, 1.0, 
    8.0, 1.0, 
    9.0, 1.0, 
   10.0, 3.0, 
   11.0, 4.0, 
   12.0, 4.0, 
   13.0, 3.0, 
   14.0, 3.0, 
   15.0, 4.0, 
   16.0, 4.0, 
   17.0, 3.0, 
   18.0, 0.0 };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p01_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P01_DATA_NUM returns the number of data points for problem p01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P01_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 18;

  return data_num;
}
/******************************************************************************/

int p01_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P01_DIM_NUM returns the spatial dimension for problem p01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P01_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p01_story ( )

/******************************************************************************/
/*
  Purpose:

    P01_STORY prints the "story" for problem p01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Reference:

    Hans-Joerg Wenz,
    Interpolation of Curve Data by Blended Generalized Circles,
    Computer Aided Geometric Design,
    Volume 13, Number 8, November 1996, pages 673-680.

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This example is due to Hans-Joerg Wenz.\n" );
  printf ( "  It is an example of good data, which is dense enough in areas\n" );
  printf ( "  where the expected curvature of the interpolant is large.\n" );
  printf ( "  Good results can be expected with almost any reasonable\n" );
  printf ( "  interpolation method.\n" );

  return;
}
/******************************************************************************/

double *p02_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P02_DATA returns the data for problem p02.

  Discussion:

    Two pairs of identical X values have now been slightly separated.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P02_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*18] = {
     0.00,   0.00, 
     1.34,   5.00, 
     5.00,   8.66, 
    10.00,  10.00, 
    10.60,  10.40, 
    10.70,  12.00, 
    10.705, 28.60, 
    10.80,  30.20, 
    11.40,  30.60, 
    19.60,  30.60, 
    20.20,  30.20, 
    20.295, 28.60, 
    20.30,  12.00, 
    20.40,  10.40, 
    21.00,  10.00, 
    26.00,   8.66, 
    29.66,   5.00, 
    31.00,   0.00  };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p02_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P02_DATA_NUM returns the number of data points for problem p02.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P02_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 18;

  return data_num;
}
/******************************************************************************/

int p02_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P02_DIM_NUM returns the spatial dimension for problem p02.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P02_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p02_story ( )

/******************************************************************************/
/*
  Purpose:

    P02_STORY prints the "story" for problem p02.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Reference:

    ETY Lee,
    Choosing Nodes in Parametric Curve Interpolation,
    Computer-Aided Design,
    Volume 21, Number 6, July/August 1989, pages 363-370.

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This example is due to ETY Lee of Boeing.\n" );
  printf ( "  Data near the corners is more dense than in regions of small curvature.\n" );
  printf ( "  A local interpolation method will produce a more plausible\n" );
  printf ( "  interpolant than a nonlocal interpolation method, such as\n" );
  printf ( "  cubic splines.\n" );

  return;
}
/******************************************************************************/

double *p03_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P03_DATA returns the data for problem p03.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P03_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;

  static double p_data_save[2*11] = { 
     0.0,  0.0, 
     2.0, 10.0, 
     3.0, 10.0, 
     5.0, 10.0, 
     6.0, 10.0, 
     8.0, 10.0, 
     9.0, 10.5, 
    11.0, 15.0, 
    12.0, 50.0, 
    14.0, 60.0, 
    15.0, 85.0 };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p03_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P03_DATA_NUM returns the number of data points for problem p03.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P03_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 11;

  return data_num;
}
/******************************************************************************/

int p03_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P03_DIM_NUM returns the spatial dimension for problem p03.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P03_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p03_story ( )

/******************************************************************************/
/*
  Purpose:

    P03_STORY prints the "story" for problem p03.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Reference:

    Fred Fritsch, Ralph Carlson,
    Monotone Piecewise Cubic Interpolation,
    SIAM Journal on Numerical Analysis,
    Volume 17, Number 2, April 1980, pages 238-246.

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This example is due to Fred Fritsch and Ralph Carlson.\n" );
  printf ( "  This data can cause problems for interpolation methods.\n" );
  printf ( "  There are sudden changes in direction, and at the same time,\n" );
  printf ( "  sparsely-placed data.  This can cause an interpolant to overshoot\n" );
  printf ( "  the data in a way that seems implausible.\n" );

  return;
}
/******************************************************************************/

double *p04_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P04_DATA returns the data for problem p04.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P04_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*8] = { 
    0.00,  0.00, 
    0.05,  0.70, 
    0.10,  1.00, 
    0.20,  1.00, 
    0.80,  0.30, 
    0.85,  0.05, 
    0.90,  0.10, 
    1.00,  1.00 };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p04_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P04_DATA_NUM returns the number of data points for problem p04.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P04_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 8;

  return data_num;
}
/******************************************************************************/

int p04_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P04_DIM_NUM returns the spatial dimension for problem p04.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P04_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p04_story ( )

/******************************************************************************/
/*
  Purpose:

    P04_STORY prints the "story" for problem p04.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Reference:

    Larry Irvine, Samuel Marin, Philip Smith,
    Constrained Interpolation and Smoothing,
    Constructive Approximation,
    Volume 2, Number 1, December 1986, pages 129-151.

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This example is due to Larry Irvine, Samuel Marin and Philip Smith.\n" );
  printf ( "  This data can cause problems for interpolation methods.\n" );
  printf ( "  There are sudden changes in direction, and at the same time,\n" );
  printf ( "  sparsely-placed data.  This can cause an interpolant to overshoot\n" );
  printf ( "  the data in a way that seems implausible.\n" );

  return;
}
/******************************************************************************/

double *p05_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P05_DATA returns the data for problem p05.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P05_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*9] = {
    0.00, 0.00, 
    0.10, 0.90, 
    0.20, 0.95, 
    0.30, 0.90, 
    0.40, 0.10, 
    0.50, 0.05, 
    0.60, 0.05, 
    0.80, 0.20, 
    1.00, 1.00 };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p05_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P05_DATA_NUM returns the number of data points for problem p05.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P05_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 9;

  return data_num;
}
/******************************************************************************/

int p05_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P05_DIM_NUM returns the spatial dimension for problem p05.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P05_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p05_story ( )

/******************************************************************************/
/*
  Purpose:

    P05_STORY prints the "story" for problem p05.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Reference:

    Larry Irvine, Samuel Marin, Philip Smith,
    Constrained Interpolation and Smoothing,
    Constructive Approximation,
    Volume 2, Number 1, December 1986, pages 129-151.

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This example is due to Larry Irvine, Samuel Marin and Philip Smith.\n" );
  printf ( "  This data can cause problems for interpolation methods.\n" );
  printf ( "  There are sudden changes in direction, and at the same time,\n" );
  printf ( "  sparsely-placed data.  This can cause an interpolant to overshoot\n" );
  printf ( "  the data in a way that seems implausible.\n" );

  return;
}
/******************************************************************************/

double *p06_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P06_DATA returns the data for problem p06.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P06_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*49] = { 
   595.0, 0.644, 
   605.0, 0.622, 
   615.0, 0.638, 
   625.0, 0.649, 
   635.0, 0.652, 
   645.0, 0.639, 
   655.0, 0.646, 
   665.0, 0.657, 
   675.0, 0.652, 
   685.0, 0.655, 
   695.0, 0.644, 
   705.0, 0.663, 
   715.0, 0.663, 
   725.0, 0.668, 
   735.0, 0.676, 
   745.0, 0.676, 
   755.0, 0.686, 
   765.0, 0.679, 
   775.0, 0.678, 
   785.0, 0.683, 
   795.0, 0.694, 
   805.0, 0.699, 
   815.0, 0.710, 
   825.0, 0.730, 
   835.0, 0.763, 
   845.0, 0.812, 
   855.0, 0.907, 
   865.0, 1.044, 
   875.0, 1.336, 
   885.0, 1.881, 
   895.0, 2.169, 
   905.0, 2.075, 
   915.0, 1.598, 
   925.0, 1.211, 
   935.0, 0.916, 
   945.0, 0.746, 
   955.0, 0.672, 
   965.0, 0.627, 
   975.0, 0.615, 
   985.0, 0.607, 
   995.0, 0.606, 
  1005.0, 0.609, 
  1015.0, 0.603, 
  1025.0, 0.601, 
  1035.0, 0.603, 
  1045.0, 0.601, 
  1055.0, 0.611, 
  1065.0, 0.601, 
  1075.0, 0.608 };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p06_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P06_DATA_NUM returns the number of data points for problem p06.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P06_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 49;

  return data_num;
}
/******************************************************************************/

int p06_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P06_DIM_NUM returns the spatial dimension for problem p06.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P06_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p06_story ( )

/******************************************************************************/
/*
  Purpose:

    P06_STORY prints the "story" for problem p06.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 February 2012

  Author:

    John Burkardt

  Reference:

    Carl DeBoor, John Rice,
    Least-squares cubic spline approximation II - variable knots. 
    Technical Report CSD TR 21, 
    Purdue University, Lafayette, Indiana, 1968.

    Carl DeBoor,
    A Practical Guide to Splines,
    Springer, 2001,
    ISBN: 0387953663,
    LC: QA1.A647.v27.

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  The data is due to deBoor and Rice.\n" );
  printf ( "  The data represents a temperature dependent property of titanium.\n" );
  printf ( "  The data has been used extensively as an example in spline\n" );
  printf ( "  approximation with variably-spaced knots.\n" );
  printf ( "  DeBoor considers two sets of knots:\n" );
  printf ( "  (595,675,755,835,915,995,1075)\n" );
  printf ( "  and\n" );
  printf ( "  (595,725,850,910,975,1040,1075).\n" );

  return;
}
/******************************************************************************/

double *p07_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P07_DATA returns the data for problem p07.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P07_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*4] = { 
   0.0, 1.0, 
   1.0, 2.0, 
   4.0, 2.0, 
   5.0, 1.0 };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p07_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P07_DATA_NUM returns the number of data points for problem p07.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P07_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 4;

  return data_num;
}
/******************************************************************************/

int p07_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P07_DIM_NUM returns the spatial dimension for problem p07.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P07_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p07_story ( )

/******************************************************************************/
/*
  Purpose:

    P07_STORY prints the "story" for problem p07.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This data is a simple symmetric set of 4 points,\n" );
  printf ( "  for which it is interesting to develop the Shepard\n" );
  printf ( "  interpolants for varying values of the exponent p.\n" );

  return;
}
/******************************************************************************/

double *p08_data ( int dim_num, int data_num )

/******************************************************************************/
/*
  Purpose:

    P08_DATA returns the data for problem p08.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2012

  Author:

    John Burkardt

  Parameters:

    Input, int DIM_NUM, the spatial dimension of the dependent
    variables.

    Input, int DATA_NUM, the number of data points.

    Output, double P08_DATA[DIM_NUM*DATA_NUM], the data.
*/
{
  double *p_data;
  static double p_data_save[2*12] = { 
   -1.0, 1.00, 
   -0.8, 0.64, 
   -0.6, 0.36, 
   -0.4, 0.16, 
   -0.2, 0.04, 
    0.0, 0.00, 
    0.2, 0.04, 
    0.20001, 0.05, 
    0.4, 0.16, 
    0.6, 0.36, 
    0.8, 0.64, 
    1.0, 1.00  };

  p_data = data_copy_new ( dim_num, data_num, p_data_save );

  return p_data;
}
/******************************************************************************/

int p08_data_num ( )

/******************************************************************************/
/*
  Purpose:

    P08_DATA_NUM returns the number of data points for problem p08.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P08_DATA_NUM, the number of data points.
*/
{
  int data_num;

  data_num = 12;

  return data_num;
}
/******************************************************************************/

int p08_dim_num ( )

/******************************************************************************/
/*
  Purpose:

    P08_DIM_NUM returns the spatial dimension for problem p08.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2012

  Author:

    John Burkardt

  Parameters:

    Output, int P08_DIM_NUM, the spatial dimension of the 
    dependent variables.
*/
{
  int dim_num;

  dim_num = 2;

  return dim_num;
}
/******************************************************************************/

void p08_story ( )

/******************************************************************************/
/*
  Purpose:

    P08_STORY prints the "story" for problem p08.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2012

  Author:

    John Burkardt

  Parameters:

    None
*/
{
  printf ( "\n" );
  printf ( "  This is equally spaced data for y = x^2,\n" );
  printf ( "  except for one extra point whose x value is\n" );
  printf ( "  close to another, but whose y value is not so close.\n" );
  printf ( "  A small disagreement in nearby data can be disaster.\n" );

  return;
}
