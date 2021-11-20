# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "asa183.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( );
void test11 ( );
void test12 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ASA183_TEST.

  Discussion:

    ASA183_TEST tests the ASA183 library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ASA183_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ASA183 library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );

  test10 ( );
  test11 ( );
  test12 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ASA183_TEST\n" );
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

    TEST01 tests R4_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  float r;
  int s1;
  int s2;
  int s3;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  R4_RANDOM computes pseudorandom values.\n" );
  printf ( "  Three seeds, S1, S2, and S3, are used.\n" );

  s1 = 12345;
  s2 = 34567;
  s3 = 56789;

  printf ( "\n" );
  printf ( "      R                 S1        S2        S3\n" );
  printf ( "\n" );
  printf ( "                  %8d  %8d  %8d\n", s1, s2, s3 );

  for ( i = 0; i < 10; i++ )
  {
    r = r4_random ( &s1, &s2, &s3 );
    printf ( "  %14f  %8d  %8d  %8d\n", r, s1, s2, s3 );
  }
  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests R4_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  int n = 100000;
  int s1;
  int s2;
  int s3;
  float *u;
  float u_avg;
  float u_var;

  u = ( float * ) malloc ( n * sizeof ( float ) );

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Examine the average and variance of a\n" );
  printf ( "  sequence generated by R4_RANDOM.\n" );
/*
  Start with known seeds.
*/
  s1 = 12345;
  s2 = 34567;
  s3 = 56789;

  printf ( "\n" );
  printf ( "  Now compute %d elements.\n", n );

  u_avg = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u[i] = r4_random ( &s1, &s2, &s3 );
    u_avg = u_avg + u[i];
  }

  u_avg = u_avg / ( float ) ( n );

  u_var = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u_var = u_var + ( u[i] - u_avg ) * ( u[i] - u_avg );
  }

  u_var = u_var / ( float ) ( n - 1 );

  printf ( "\n" );
  printf ( "  Average value = %f\n", u_avg );
  printf ( "  Expecting       %f\n", 0.5 );;

  printf ( "\n" );
  printf ( "  Variance =      %f\n", u_var );
  printf ( "  Expecting       %f\n", 1.0 / 12.0 );

  free ( u );

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests R4_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  float r;
  int s1;
  int s1_save;
  int s2;
  int s2_save;
  int s3;
  int s3_save;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Show how the seeds used by R4_RANDOM,\n" );
  printf ( "  which change on each step, can be reset to\n" );
  printf ( "  restore any part of the sequence.\n" );

  s1_save = 12345;
  s2_save = 34567;
  s3_save = 56789;

  s1 = s1_save;
  s2 = s2_save;
  s3 = s3_save;

  printf ( "\n" );
  printf ( "  Begin sequence with following seeds\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "  S3 = %d\n", s3 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2            S3\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r4_random ( &s1, &s2, &s3 );
    printf ( "  %8d  %14f  %12d  %12d  %12d\n", i, r, s1, s2, s3 );

    if ( i == 5 )
    {
      s1_save = s1;
      s2_save = s2;
      s3_save = s3;
    }
  }
  s1 = s1_save;
  s2 = s2_save;
  s3 = s3_save;

  printf ( "\n" );
  printf ( "  Restart the sequence, using the seeds\n" );
  printf ( "  produced after step 5:\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "  S3 = %d\n", s3 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2            S3\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r4_random ( &s1, &s2, &s3 );
    printf ( "  %8d  %14f  %12d  %12d  %12d\n", i, r, s1, s2, s3 );
  }
  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 tests R4_UNI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  float r;
  int s1;
  int s2;

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  R4_UNI computes pseudorandom values.\n" );
  printf ( "  Two seeds, S1 and S2, are used.\n" );

  s1 = 12345;
  s2 = 34567;

  printf ( "\n" );
  printf ( "      R                     S1            S2\n" );
  printf ( "\n" );
  printf ( "                  %12d  %12d\n", s1, s2 );

  for ( i = 0; i < 10; i++ )
  {
    r = r4_uni ( &s1, &s2 );
    printf ( "  %14f  %12d  %12d\n", r, s1, s2 );
  }
  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests R4_UNI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  int n = 100000;
  int s1;
  int s2;
  float *u;
  float u_avg;
  float u_var;

  u = ( float * ) malloc ( n * sizeof ( float ) );

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  Examine the average and variance of a\n" );
  printf ( "  sequence generated by R4_UNI.\n" );
/*
  Start with known seeds.
*/
  s1 = 12345;
  s2 = 34567;

  printf ( "\n" );
  printf ( "  Now compute %d elements.\n", n );

  u_avg = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u[i] = r4_uni ( &s1, &s2 );
    u_avg = u_avg + u[i];
  }

  u_avg = u_avg / ( float ) ( n );

  u_var = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u_var = u_var + ( u[i] - u_avg ) * ( u[i] - u_avg );
  }

  u_var = u_var / ( float ) ( n - 1 );

  printf ( "\n" );
  printf ( "  Average value = %f\n", u_avg );
  printf ( "  Expecting       %f\n", 0.5 );;

  printf ( "\n" );
  printf ( "  Variance =      %f\n", u_var );
  printf ( "  Expecting       %f\n", 1.0 / 12.0 );

  free ( u );

  return;
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests R4_UNI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  float r;
  int s1;
  int s1_save;
  int s2;
  int s2_save;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  Show how the seeds used by R4_UNI,\n" );
  printf ( "  which change on each step, can be reset to\n" );
  printf ( "  restore any part of the sequence.\n" );

  s1_save = 12345;
  s2_save = 34567;

  s1 = s1_save;
  s2 = s2_save;

  printf ( "\n" );
  printf ( "  Begin sequence with following seeds\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r4_uni ( &s1, &s2 );
    printf ( "  %8d  %14f  %12d  %12d\n", i, r, s1, s2 );

    if ( i == 5 )
    {
      s1_save = s1;
      s2_save = s2;
    }
  }
  s1 = s1_save;
  s2 = s2_save;

  printf ( "\n" );
  printf ( "  Restart the sequence, using the seeds\n" );
  printf ( "  produced after step 5:\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r4_uni ( &s1, &s2 );
    printf ( "  %8d  %14f  %12d  %12d\n", i, r, s1, s2 );
  }
  return;
}
/******************************************************************************/

void test07 ( )

/******************************************************************************/
/*
  Purpose:

    TEST07 tests R8_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  double r;
  int s1;
  int s2;
  int s3;

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  R8_RANDOM computes pseudorandom values.\n" );
  printf ( "  Three seeds, S1, S2, and S3, are used.\n" );

  s1 = 12345;
  s2 = 34567;
  s3 = 56789;

  printf ( "\n" );
  printf ( "      R                 S1        S2        S3\n" );
  printf ( "\n" );
  printf ( "                  %8d  %8d  %8d\n", s1, s2, s3 );

  for ( i = 0; i < 10; i++ )
  {
    r = r8_random ( &s1, &s2, &s3 );
    printf ( "  %14f  %8d  %8d  %8d\n", r, s1, s2, s3 );
  }
  return;
}
/******************************************************************************/

void test08 ( )

/******************************************************************************/
/*
  Purpose:

    TEST08 tests R8_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  int n = 100000;
  int s1;
  int s2;
  int s3;
  double *u;
  double u_avg;
  double u_var;

  u = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  Examine the average and variance of a\n" );
  printf ( "  sequence generated by R8_RANDOM.\n" );
/*
  Start with known seeds.
*/
  s1 = 12345;
  s2 = 34567;
  s3 = 56789;

  printf ( "\n" );
  printf ( "  Now compute %d elements.\n", n );

  u_avg = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u[i] = r8_random ( &s1, &s2, &s3 );
    u_avg = u_avg + u[i];
  }

  u_avg = u_avg / ( double ) ( n );

  u_var = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u_var = u_var + ( u[i] - u_avg ) * ( u[i] - u_avg );
  }

  u_var = u_var / ( double ) ( n - 1 );

  printf ( "\n" );
  printf ( "  Average value = %f\n", u_avg );
  printf ( "  Expecting       %f\n", 0.5 );

  printf ( "\n" );
  printf ( "  Variance =      %f\n", u_var );
  printf ( "  Expecting       %f\n", 1.0 / 12.0 );

  free ( u );

  return;
}
/******************************************************************************/

void test09 ( )

/******************************************************************************/
/*
  Purpose:

    TEST09 tests R8_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  double r;
  int s1;
  int s1_save;
  int s2;
  int s2_save;
  int s3;
  int s3_save;

  printf ( "\n" );
  printf ( "TEST09\n" );
  printf ( "  Show how the seeds used by R8_RANDOM,\n" );
  printf ( "  which change on each step, can be reset to\n" );
  printf ( "  restore any part of the sequence.\n" );

  s1_save = 12345;
  s2_save = 34567;
  s3_save = 56789;

  s1 = s1_save;
  s2 = s2_save;
  s3 = s3_save;

  printf ( "\n" );
  printf ( "  Begin sequence with following seeds\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "  S3 = %d\n", s3 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2            S3\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_random ( &s1, &s2, &s3 );
    printf ( "  %8d  %14f  %12d  %12d  %12d\n", i, r, s1, s2, s3 );

    if ( i == 5 )
    {
      s1_save = s1;
      s2_save = s2;
      s3_save = s3;
    }
  }
  s1 = s1_save;
  s2 = s2_save;
  s3 = s3_save;

  printf ( "\n" );
  printf ( "  Restart the sequence, using the seeds\n" );
  printf ( "  produced after step 5:\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "  S3 = %d\n", s3 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2            S3\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_random ( &s1, &s2, &s3 );
    printf ( "  %8d  %14f  %12d  %12d  %12d\n", i, r, s1, s2, s3 );
  }
  return;
}
/******************************************************************************/

void test10 ( )

/******************************************************************************/
/*
  Purpose:

    TEST10 tests R8_UNI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  double r;
  int s1;
  int s2;

  printf ( "\n" );
  printf ( "TEST10\n" );
  printf ( "  R8_UNI computes pseudorandom values.\n" );
  printf ( "  Two seeds, S1 and S2, are used.\n" );

  s1 = 12345;
  s2 = 34567;

  printf ( "\n" );
  printf ( "      R                     S1            S2\n" );
  printf ( "\n" );
  printf ( "                  %12d  %12d\n", s1, s2 );

  for ( i = 0; i < 10; i++ )
  {
    r = r8_uni ( &s1, &s2 );
    printf ( "  %14f  %12d  %12d\n", r, s1, s2 );
  }
  return;
}
/******************************************************************************/

void test11 ( )

/******************************************************************************/
/*
  Purpose:

    TEST11 tests R8_UNI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  int n = 100000;
  int s1;
  int s2;
  double *u;
  double u_avg;
  double u_var;

  u = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "TEST11\n" );
  printf ( "  Examine the average and variance of a\n" );
  printf ( "  sequence generated by R8_UNI.\n" );
/*
  Start with known seeds.
*/
  s1 = 12345;
  s2 = 34567;

  printf ( "\n" );
  printf ( "  Now compute %d elements.\n", n );

  u_avg = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u[i] = r8_uni ( &s1, &s2 );
    u_avg = u_avg + u[i];
  }

  u_avg = u_avg / ( float ) ( n );

  u_var = 0.0;
  for ( i = 0; i < n; i++ )
  {
    u_var = u_var + ( u[i] - u_avg ) * ( u[i] - u_avg );
  }

  u_var = u_var / ( float ) ( n - 1 );

  printf ( "\n" );
  printf ( "  Average value = %f\n", u_avg );
  printf ( "  Expecting       %f\n", 0.5 );;

  printf ( "\n" );
  printf ( "  Variance =      %f\n", u_var );
  printf ( "  Expecting       %f\n", 1.0 / 12.0 );

  free ( u );

  return;
}
/******************************************************************************/

void test12 ( )

/******************************************************************************/
/*
  Purpose:

    TEST12 tests R8_UNI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2008

  Author:

    John Burkardt
*/
{
  int i;
  double r;
  int s1;
  int s1_save;
  int s2;
  int s2_save;

  printf ( "\n" );
  printf ( "TEST12\n" );
  printf ( "  Show how the seeds used by R8_UNI,\n" );
  printf ( "  which change on each step, can be reset to\n" );
  printf ( "  restore any part of the sequence.\n" );

  s1_save = 12345;
  s2_save = 34567;

  s1 = s1_save;
  s2 = s2_save;

  printf ( "\n" );
  printf ( "  Begin sequence with following seeds\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_uni ( &s1, &s2 );
    printf ( "  %8d  %14f  %12d  %12d\n", i, r, s1, s2 );

    if ( i == 5 )
    {
      s1_save = s1;
      s2_save = s2;
    }
  }
  s1 = s1_save;
  s2 = s2_save;

  printf ( "\n" );
  printf ( "  Restart the sequence, using the seeds\n" );
  printf ( "  produced after step 5:\n" );
  printf ( "\n" );
  printf ( "  S1 = %d\n", s1 );
  printf ( "  S2 = %d\n", s2 );
  printf ( "\n" );
  printf ( "         I      R                     S1            S2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_uni ( &s1, &s2 );
    printf ( "  %8d  %14f  %12d  %12d\n", i, r, s1, s2 );
  }
  return;
}
