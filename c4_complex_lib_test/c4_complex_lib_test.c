# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "c4_complex_lib.h"

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
void test13 ( );
void test14 ( );
void test15 ( );
void test16 ( );
void test17 ( );
void test18 ( );
void test19 ( );
void test20 ( );
void test21 ( );
void test22 ( );
void test23 ( );
void test24 ( );
void test25 ( );
void test26 ( );
void test27 ( );
void test28 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for C4_COMPLEX_LIB_TEST.

  Discussion:

    C4_COMPLEX_LIB_TEST tests the C4_COMPLEX_LIB library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 October 2010

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "C4_COMPLEX_LIB_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the C4_COMPLEX_LIB library.\n" );

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
  test13 ( );
  test14 ( );
  test15 ( );
  test16 ( );
  test17 ( );
  test18 ( );
  test19 ( );

  test20 ( );
  test21 ( );
  test22 ( );
  test23 ( );
  test24 ( );
  test25 ( );
  test26 ( );
  test27 ( );
  test28 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "C4_COMPLEX_LIB_TEST\n" );
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

    TEST01 tests C4_ABS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  int i;
  float r2;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  C4_ABS computes the absolute value of a C4.\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          R2=C4_ABS(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    r2 = c4_abs ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f\n", 
      c1->real, c1->imag, r2 );

    free ( c1 );
  }

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests C4_ACOS and C4_COS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  C4_ACOS computes the inverse cosine;\n" );
  printf ( "  C4_COS computes the cosine;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_ACOS(C1)           C3 = C4_COS(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_acos ( c1 );
    c3 = c4_cos ( c2 );
    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests C4_ACOSH and C4_COSH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  C4_ACOSH computes the inverse hyperbolic cosine;\n" );
  printf ( "  C4_COSH computes the hyperbolic cosine;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_ACOSH(C1)          C3 = C4_COSH(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_acosh ( c1 );
    c3 = c4_cosh ( c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test04 ( )

/******************************************************************************/
/*
  Purpose:

    TEST04 tests C4_ADD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  C4_ADD computes C3 = C1 + C2.\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2=C4_UNIFORM_01          C3 = C4_ADD(C1,C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_uniform_01 ( &seed );
    c3 = c4_add ( c1, c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test05 ( )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests C4_ARG.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  float r2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  C4_ARG computes the argument of a C4 value.\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          R2=C4_ARG(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    r2 = c4_arg ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f\n", 
      c1->real, c1->imag, r2 );

    free ( c1 );
  }

  return;
}
/******************************************************************************/

void test06 ( )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests C4_ASIN and C4_SIN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  C4_ASIN computes the inverse sine;\n" );
  printf ( "  C4_SIN computes the sine;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_ASIN(C1)           C3 = C4_SIN(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_asin ( c1 );
    c3 = c4_sin ( c2 );
    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test07 ( )

/******************************************************************************/
/*
  Purpose:

    TEST07 tests C4_ASINH and C4_SINH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  C4_ASINH computes the inverse hyperbolic sine;\n" );
  printf ( "  C4_SINH computes the hyperbolic sine;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_ASINH(C1)          C3 = C4_SINH(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_asinh ( c1 );
    c3 = c4_sinh ( c2 );
    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test08 ( )

/******************************************************************************/
/*
  Purpose:

    TEST08 tests C4_ATAN and C4_TAN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  C4_ATAN computes the inverse tangent;\n" );
  printf ( "  C4_TAN computes the tangent;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_ATAN(C1)          C3 = C4_TAN(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_atan ( c1 );
    c3 = c4_tan ( c2 );
    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test09 ( )

/******************************************************************************/
/*
  Purpose:

    TEST09 tests C4_ATANH and C4_TANH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST09\n" );
  printf ( "  C4_ATANH computes the inverse hyperbolic tangent;\n" );
  printf ( "  C4_TANH computes the hyperbolic tangent;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_ATANH(C1)         C3 = C4_TANH(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_atanh ( c1 );
    c3 = c4_tanh ( c2 );
    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test10 ( )

/******************************************************************************/
/*
  Purpose:

    TEST10 tests C4_CONJ.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST10\n" );
  printf ( "  C4_CONJ computes C2 = conj ( C1 ).\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2=C4_CONJ(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_conj ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }

  return;
}
/******************************************************************************/

void test11 ( )

/******************************************************************************/
/*
  Purpose:

    TEST11 tests C4_COS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST11\n" );
  printf ( "  C4_COS computes the cosine of a C4;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_COS(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_cos ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }

  return;
}
/******************************************************************************/

void test12 ( )

/******************************************************************************/
/*
  Purpose:

    TEST12 tests C4_COSH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST12\n" );
  printf ( "  C4_COSH computes the hyperbolic cosine of a C4;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_COSH(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_cosh ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }

  return;
}
/******************************************************************************/

void test13 ( )

/******************************************************************************/
/*
  Purpose:

    TEST13 tests C4_CUBE_ROOT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  struct c4_complex *c4;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST13\n" );
  printf ( "  C4_CUBE_ROOT computes C2 = cube root ( C1 ).\n" );
  printf ( "  Check by C3 = C2 * C2.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_CUBE_ROOT(C1)      C3=C2*C2*C2\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_cube_root ( c1 );
    c3 = c4_mul ( c2, c2 );
    c4 = c4_mul ( c3, c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c4->real, c4->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
    free ( c4 );
  }

  return;
}
/******************************************************************************/

void test14 ( )

/******************************************************************************/
/*
  Purpose:

    TEST14 tests C4_DIV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST14\n" );
  printf ( "  C4_DIV computes C3 = C1 / C2.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_UNIFORM_01          C3=C4_DIV(C1,C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_uniform_01 ( &seed );
    c3 = c4_div ( c1, c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test15 ( )

/******************************************************************************/
/*
  Purpose:

    TEST15 tests C4_EXP.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST15\n" );
  printf ( "  C4_EXP computes C2 = e ^ C1.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_EXP(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_exp ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }
  return;
}
/******************************************************************************/

void test16 ( )

/******************************************************************************/
/*
  Purpose:

    TEST16 tests C4_INV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST16\n" );
  printf ( "  C4_INV computes C2 = 1 / C1.\n" );
  printf ( "  Check by C3 = 1 / C2.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_INV(C1)             C3=C4_INV(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_inv ( c1 );
    c3 = c4_inv ( c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test17 ( )

/******************************************************************************/
/*
  Purpose:

    TEST17 tests C4_LOG.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST17\n" );
  printf ( "  C4_LOG computes log ( Z ).\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_LOG(C1)             C3=C4_EXP(C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_log ( c1 );
    c3 = c4_exp ( c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test18 ( )

/******************************************************************************/
/*
  Purpose:

    TEST18 tests C4_MAG.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  float r2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST18\n" );
  printf ( "  C4_MAG computes the magnitude of a C4.\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          R2=C4_MAG(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    r2 = c4_mag ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f\n", 
      c1->real, c1->imag, r2 );

    free ( c1 );
  }

  return;
}
/******************************************************************************/

void test19 ( )

/******************************************************************************/
/*
  Purpose:

    TEST19 tests C4_MUL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST19\n" );
  printf ( "  C4_MUL computes C3 = C1 * C2.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_UNIFORM_01          C3=C4_MUL(C1,C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_uniform_01 ( &seed );
    c3 = c4_mul ( c1, c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test20 ( )

/******************************************************************************/
/*
  Purpose:

    TEST20 tests C4_NORMAL_01.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST20\n" );
  printf ( "  C4_NORMAL_01 generates unit pseudonormal C4's\n" );
  printf ( "\n" );
  printf ( "       C1=C4_NORMAL_01(SEED)\n" );
  printf ( "     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c = c4_normal_01 ( &seed );

    printf ( "  %12.6f%12.6f\n", c->real, c->imag );

    free ( c );
  }

  return;
}
/******************************************************************************/

void test21 ( )

/******************************************************************************/
/*
  Purpose:

    TEST21 tests C4_SIN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST21\n" );
  printf ( "  C4_SIN computes the sine of a C4;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_SIN(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_sin ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }

  return;
}
/******************************************************************************/

void test22 ( )

/******************************************************************************/
/*
  Purpose:

    TEST22 tests C4_SINH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST22\n" );
  printf ( "  C4_SINH computes the hyperbolic sine of a C4;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_SINH(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_sinh ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }

  return;
}
/******************************************************************************/

void test23 ( )

/******************************************************************************/
/*
  Purpose:

    TEST23 tests C4_SQRT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST23\n" );
  printf ( "  C4_SQRT computes C2 = sqrt ( C1 ).\n" );
  printf ( "  Check by C3 = C2 * C2.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01          C2=C4_SQRT(C1)            C3=C2*C2\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_sqrt ( c1 );
    c3 = c4_mul ( c2, c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test24 ( )

/******************************************************************************/
/*
  Purpose:

    TEST24 tests C4_SUB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  struct c4_complex *c3;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST24\n" );
  printf ( "  C4_SUB computes C3 = C1 - C2.\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2=C4_UNIFORM_01          C3 = C4_SUB(C1,C2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_uniform_01 ( &seed );
    c3 = c4_sub ( c1, c2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag, c3->real, c3->imag );

    free ( c1 );
    free ( c2 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test25 ( )

/******************************************************************************/
/*
  Purpose:

    TEST25 tests C4_TAN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c2;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST25\n" );
  printf ( "  C4_TAN computes the tangent of a C4;\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01          C2 = C4_TAN(C1)\n" );
  printf ( "     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c2 = c4_tan ( c1 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, c2->real, c2->imag );

    free ( c1 );
    free ( c2 );
  }

  return;
}
/******************************************************************************/

void test26 ( )

/******************************************************************************/
/*
  Purpose:

    TEST26 tests C4_TO_CARTESIAN and CARTESIAN_TO_C4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;
  struct c4_complex *c3;
  int i;
  int seed;
  float x2;
  float y2;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST26\n" );
  printf ( "  C4_TO_CARTESIAN computes C4 -> ( X, Y ).\n" );
  printf ( "  CARTESIAN_TO_C4 computes ( X, Y ) -> C4.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01    (X2,Y2)=C4_TO_CARTESIAN(C1)     C3=CARTESIAN_TO_C4(X2,Y2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c4_to_cartesian ( c1, &x2, &y2 );
    c3 = cartesian_to_c4 ( x2, y2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, x2, y2, c3->real, c3->imag );

    free ( c1 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test27 ( )

/******************************************************************************/
/*
  Purpose:

    TEST27 tests C4_TO_POLAR and POLAR_TO_C4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c1;

  struct c4_complex *c3;
  int i;
  float r2;
  int seed;
  float t2;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST27\n" );
  printf ( "  C4_TO_POLAR computes C4 -> ( R, T ).\n" );
  printf ( "  POLAR_TO_C4 computes ( R, T ) -> C4.\n" );
  printf ( "\n" );
  printf ( "        C1=C4_UNIFORM_01     (X2,Y2)=C4_TO_POLAR(C1)     C3=POLAR_TO_C4(X2,Y2)\n" );
  printf ( "     ---------------------     ---------------------     ---------------------\n" );

  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c1 = c4_uniform_01 ( &seed );
    c4_to_polar ( c1, &r2, &t2 );
    c3 = polar_to_c4 ( r2, t2 );

    printf ( "  %12.6f%12.6f  %12.6f%12.6f  %12.6f%12.6f\n", 
      c1->real, c1->imag, r2, t2, c3->real, c3->imag );

    free ( c1 );
    free ( c3 );
  }

  return;
}
/******************************************************************************/

void test28 ( )

/******************************************************************************/
/*
  Purpose:

    TEST28 tests C4_UNIFORM_01.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2008

  Author:

    John Burkardt
*/
{
  struct c4_complex *c;
  int i;
  int seed;

  seed = 123456789;

  printf ( "\n" );
  printf ( "TEST28\n" );
  printf ( "  C4_UNIFORM_01 returns a uniformly random \"unit\" C4\n" );
  printf ( "\n" );
  printf ( "       C1=C4_UNIFORM_01(SEED)\n" );
  printf ( "     ---------------------\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    c = c4_uniform_01 ( &seed );

    printf ( "  %12.6f%12.6f\n", c->real, c->imag );

    free ( c );
  }

  return;
}
