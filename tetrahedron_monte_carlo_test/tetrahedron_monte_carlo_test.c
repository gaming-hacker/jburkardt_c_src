# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "tetrahedron_monte_carlo.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
double *tetrahedron_integrand_user ( int p_num, double p[], int f_num );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TETRAHEDRON_MONTE_CARLO_TEST.

  Discussion:

    TETRAHEDRON_MONTE_CARLO_TEST tests the TETRAHEDRON_MONTE_CARLO library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TETRAHEDRON_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TETRAHEDRON_MONTE_CARLO library.\n" );
/*
  Try each sampler on the unit tetrahedron, integrating quadratics.
*/
  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
/*
  Try each sampler on a general tetrahedron, integrating a selection of functions.
*/
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TETRAHEDRON_MONTE_CARLO_TEST\n" );
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

    TEST01 uses TETRAHEDRON_SAMPLE_01 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_01\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a \"bad\" sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             X*Z" );
  printf ( "             Y^2             Y*Z             Z^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_01, tetrahedron_integrand_03, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
    }
    printf ( "\n" );

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

    TEST02 uses TETRAHEDRON_SAMPLE_02 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_02\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             X*Z" );
  printf ( "             Y^2             Y*Z             Z^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_02, tetrahedron_integrand_03, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
    }
    printf ( "\n" );

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

    TEST03 uses TETRAHEDRON_SAMPLE_03 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_03\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             X*Z" );
  printf ( "             Y^2             Y*Z             Z^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_03, tetrahedron_integrand_03, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
    }
    printf ( "\n" );

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

    TEST04 uses TETRAHEDRON_SAMPLE_04 with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 0.0 };

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_04\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_03\n" );
  printf ( "  Integration region is the unit tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     P_NUM      X^2             X*Y             X*Z" );
  printf ( "             Y^2             Y*Z             Z^2\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_04, tetrahedron_integrand_03, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
    }
    printf ( "\n" );

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

    TEST05 uses TETRAHEDRON_SAMPLE_01 on a general tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 2.0, 3.0,
    4.0, 1.0, 2.0,
    2.0, 4.0, 4.0,
    3.0, 2.0, 5.0 };

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_01\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a bad sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 3, 4, t, "  Tetrahedron vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_01, tetrahedron_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
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

    TEST06 uses TETRAHEDRON_SAMPLE_02 on a general tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 2.0, 3.0,
    4.0, 1.0, 2.0,
    2.0, 4.0, 4.0,
    3.0, 2.0, 5.0 };

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_02\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 3, 4, t, "  Tetrahedron vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_02, tetrahedron_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
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

    TEST07 uses TETRAHEDRON_SAMPLE_03 on a general tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 2.0, 3.0,
    4.0, 1.0, 2.0,
    2.0, 4.0, 4.0,
    3.0, 2.0, 5.0 };

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_03\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 3, 4, t, "  Tetrahedron vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_03, tetrahedron_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
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

    TEST08 uses TETRAHEDRON_SAMPLE_04 on a general tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int f_num = 6;
  int i;
  int p_num;
  double *result;
  int seed;
  double t[3*4] = {
    1.0, 2.0, 3.0,
    4.0, 1.0, 2.0,
    2.0, 4.0, 4.0,
    3.0, 2.0, 5.0 };

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  Sample using TETRAHEDRON_UNIT_SAMPLE_04\n" );
  printf ( "  Integrate TETRAHEDRON_UNIT_INTEGRAND_USER\n" );
  printf ( "  Integration region is over a general tetrahedron.\n" );
  printf ( "\n" );
  printf ( "  Use an increasing number of points P_NUM.\n" );
  printf ( "  Note that the sample routine is a good sampler.\n" );

  seed = 123456789;

  r8mat_transpose_print ( 3, 4, t, "  Tetrahedron vertices:" );

  printf ( "\n" );
  printf ( "     P_NUM\n" );
  printf ( "\n" );

  p_num = 1;

  while ( p_num <= 65536 )
  {
    result = tetrahedron_monte_carlo ( t, p_num, f_num,
      tetrahedron_unit_sample_04, tetrahedron_integrand_user, &seed );

    printf ( "  %8d", p_num );
    for ( i = 0; i < f_num; i++ )
    {
      printf ( "  %14g", result[i] );
    }
    printf ( "\n" );

    p_num = 2 * p_num;

    free ( result );
  }
  return;
}
/******************************************************************************/

double *tetrahedron_integrand_user ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INTEGRAND_USER evaluates 6 integrand functions defined by the user.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P[3*P_NUM], the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double TETRAHEDRON_INTEGRAND_USER[F_NUM*P_NUM], the integrand values.
*/
{
  int j;
  double *fp;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[0+j*f_num] = 1.0;
    fp[1+j*f_num] =       p[0+j*3];
    fp[2+j*f_num] =                       pow ( p[1+j*3], 2 );
    fp[3+j*f_num] =                                             pow ( p[2+j*3], 3 );
    fp[4+j*f_num] =       p[0+j*3]      *       p[1+j*3]      * pow ( p[2+j*3], 2 );
    fp[5+j*f_num] = pow ( p[0+j*3], 2 ) * pow ( p[1+j*3], 2 ) * pow ( p[2+j*3], 2 );
  }
  return fp;
}

