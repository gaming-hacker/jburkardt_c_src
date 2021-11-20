# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "van_der_corput.h"

int main ( );
void vdc_test ( );
void vdc_inverse_test ( );
void vdc_sequence_test ( );
void vdc_base_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    VAN_DER_CORPUT_TEST tests the VAN_DER_CORPUT library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 August 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "VAN_DER_CORPUT_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the VAN_DER_CORPUT library.\n" );

  vdc_test ( );
  vdc_inverse_test ( );
  vdc_sequence_test ( );
  vdc_base_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "VAN_DER_CORPUT_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void vdc_base_test ( )

/******************************************************************************/
/*
  Purpose:

    VDC_BASE_TEST tests VDC_BASE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  double r2;
  double r3;
  double r5;

  printf ( "\n" );
  printf ( "VDC_BASE_TEST\n" );
  printf ( "  VDC_BASE returns the I-th element of a van der Corput\n" );
  printf ( "  sequence in base B.\n" );
  printf ( "\n" );
  printf ( "    I          VDC_BASE(I,2)   VDC_BASE(I,3)   VDC_BASE(I,5)\n" );
  printf ( "\n" );

  for ( i = -10; i <= 10; i++ )
  {
    r2 = vdc_base ( i, 2 );
    r3 = vdc_base ( i, 3 );
    r5 = vdc_base ( i, 5 );
    printf ( "  %3d        %14.8g  %14.8g  %14.8g\n", i, r2, r3, r5 );
  }

  return;
}
/******************************************************************************/

void vdc_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    VDC_INVERSE_TEST tests VDC_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  int i2;
  double r;

  printf ( "\n" );
  printf ( "VDC_INVERSE_TEST\n" );
  printf ( "  VDC_INVERSE inverts an element of a van der Corput sequence.\n" );
  printf ( "\n" );
  printf ( "    I        R=VDC(I)  VDC_INVERSE(R)\n" );
  printf ( "\n" );

  for ( i = -10; i <= 10; i++ )
  {
    r = vdc ( i );
    i2 = vdc_inverse ( r );
    printf ( "  %3d  %14.8g  %3d\n", i, r, i2 );
  }

  return;
}
/******************************************************************************/

void vdc_sequence_test ( )

/******************************************************************************/
/*
  Purpose:

    VDC_SEQUENCE_TEST tests VDC_SEQUENCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 August 2016

  Author:

    John Burkardt
*/
{
  int i1;
  int i2;
  int n;
  double *r;

  printf ( "\n" );
  printf ( "VDC_SEQUENCE_TEST\n" );
  printf ( "  VDC_SEQUENCE returns elements I1 through I2 of\n" );
  printf ( "  a van der Corput sequence.\n" );

  i1 = 7;
  i2 = 7;
  n = abs ( i2 - i1 ) + 1;
  r = vdc_sequence ( i1, i2 );
  printf ( "\n" );
  r8vec_transpose_print ( n, r, "  R=VDC_SEQUENCE(  7,  7):" );
  free ( r );

  i1 = 0;
  i2 = 8;
  n = abs ( i2 - i1 ) + 1;
  r = vdc_sequence ( i1, i2 );
  printf ( "\n" );
  r8vec_transpose_print ( n, r, "  R=VDC_SEQUENCE(  0,  8):" );
  free ( r );

  i1 = 8;
  i2 = 0;
  n = abs ( i2 - i1 ) + 1;
  r = vdc_sequence ( i1, i2 );
  printf ( "\n" );
  r8vec_transpose_print ( n, r, "  R=VDC_SEQUENCE(  8,  0):" );
  free ( r );

  i1 = -3;
  i2 = +5;
  n = abs ( i2 - i1 ) + 1;
  r = vdc_sequence ( i1, i2 );
  printf ( "\n" );
  r8vec_transpose_print ( n, r, "  R=VDC_SEQUENCE( -3,  5):" );
  free ( r );

  i1 = 100;
  i2 = 105;
  n = abs ( i2 - i1 ) + 1;
  r = vdc_sequence ( i1, i2 );
  printf ( "\n" );
  r8vec_transpose_print ( n, r, "  R=VDC_SEQUENCE(100,105):" );
  free ( r );

  return;
}
/******************************************************************************/

void vdc_test ( )

/******************************************************************************/
/*
  Purpose:

    VDC_TEST tests VDC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 August 2016

  Author:

    John Burkardt
*/
{
  int i;
  double r;

  printf ( "\n" );
  printf ( "VDC_TEST\n" );
  printf ( "  VDC returns the I-th element of a van der Corput sequence.\n" );
  printf ( "\n" );
  printf ( "    I          VDC(I)\n" );
  printf ( "\n" );

  for ( i = -10; i <= 10; i++  )
  {
    r = vdc ( i );
    printf ( "  %3d  %14.8g\n", i, r );
  }

  return;
}
