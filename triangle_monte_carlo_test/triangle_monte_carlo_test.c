# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "triangle_monte_carlo.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
double *triangle_integrand_user ( int p_num, double p[], int f_num );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TRIANGLE_MONTE_CARLO_TEST.

  Discussion:

    TRIANGLE_MONTE_CARLO_TEST tests the TRIANGLE_MONTE_CARLO library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TRIANGLE_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TRIANGLE_MONTE_CARLO library.\n" );
/*
  Try each sampler on the unit triangle, integrating X^2, X*Y, Y^2.
*/
  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
/*
  Try each sampler on a general triangle, integrating a selection of functions.
*/
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TRIANGLE_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 uses TRIANGLE_SAMPLE_01 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 3;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    1.0, 0.0,
    0.0, 1.0,
    0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_01\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a \"bad\" sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             Y^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_01,
      triangle_integrand_03, &seed );

    printf ( "  %8d  %14g  %14g  %14g\n", p_num, result[0], result[1], result[2] );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 uses TRIANGLE_SAMPLE_02 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 3;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    1.0, 0.0,
    0.0, 1.0,
    0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_02\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             Y^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_02,
      triangle_integrand_03, &seed );

    printf ( "  %8d  %14g  %14g  %14g\n", p_num, result[0], result[1], result[2] );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 uses TRIANGLE_SAMPLE_03 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 3;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    1.0, 0.0,
    0.0, 1.0,
    0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_03\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             Y^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_03,
      triangle_integrand_03, &seed );

    printf ( "  %8d  %14g  %14g  %14g\n", p_num, result[0], result[1], result[2] );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 uses TRIANGLE_SAMPLE_04 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 3;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    1.0, 0.0,
    0.0, 1.0,
    0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_04\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             Y^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_04,
      triangle_integrand_03, &seed );

    printf ( "  %8d  %14g  %14g  %14g\n", p_num, result[0], result[1], result[2] );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 uses TRIANGLE_SAMPLE_01 on a general triangle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 8;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    4.0, 1.0,
    8.0, 3.0,
    0.0, 9.0 };

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_01\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a \"bad\" sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_01,
      triangle_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %12g", result[i] );
    }
    printf ( "\n" );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 uses TRIANGLE_SAMPLE_02 on a general triangle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 8;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    4.0, 1.0,
    8.0, 3.0,
    0.0, 9.0 };

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_02\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a \"good\" sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_02,
      triangle_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %12g", result[i] );
    }
    printf ( "\n" );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test07 ( )

/******************************************************************************/
/*
  Purpose:

    TEST07 uses TRIANGLE_SAMPLE_03 on a general triangle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 August 2009

  Author:

    John Burkardt
*/
{
  int f_num = 8;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    4.0, 1.0,
    8.0, 3.0,
    0.0, 9.0 };

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_03\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a \"good\" sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_03,
      triangle_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %12g", result[i] );
    }
    printf ( "\n" );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

void test08 ( )

/******************************************************************************/
/*
  Purpose:

    TEST08 uses TRIANGLE_SAMPLE_04 on a general triangle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 8;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[2*3] = {
    4.0, 1.0,
    8.0, 3.0,
    0.0, 9.0 };

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  Sample using TRIANGLE_UNIT_SAMPLE_04\n" );
  printf ( "  Integrate TRIANGLE_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general triangle.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a \"good\" sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = triangle_monte_carlo ( t, p_num, f_num, triangle_unit_sample_04,
      triangle_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %12g", result[i] );
    }
    printf ( "\n" );

    p_num = 2 * p_num;

    free ( result );
  }

  return;
}
/******************************************************************************/

double *triangle_integrand_user ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_INTEGRAND_USER evaluates 8 integrand functions defined by the user.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 January 2014

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P(2,P_NUM), the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double FP(F_NUM,P_NUM), the integrand values.
*/
{
  double *fp;
  int j;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[0+j*f_num] = 1.0;
    fp[1+j*f_num] = p[0+j*2];
    fp[2+j*f_num] = p[1+j*2];
    fp[3+j*f_num] = p[0+j*2] * p[0+j*2];
    fp[4+j*f_num] = p[0+j*2] * p[1+j*2];
    fp[5+j*f_num] = p[1+j*2] * p[1+j*2];
    fp[6+j*f_num] = p[0+j*2] * p[0+j*2] * p[1+j*2];
    fp[7+j*f_num] = p[0+j*2] * p[0+j*2] * p[1+j*2] * p[1+j*2];
  }
  return fp;
}

