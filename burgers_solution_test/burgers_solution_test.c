# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "burgers_solution.h"

int main ( );
void burgers_viscous_time_exact1_test01 ( );
void burgers_viscous_time_exact1_test02 ( );
void burgers_viscous_time_exact2_test01 ( );
void burgers_viscous_time_exact2_test02 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BURGERS_SOLUTION_TEST.

  Discussion:

    BURGERS_SOLUTION_TEST tests the BURGERS_SOLUTION library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 November 2011

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BURGERS_SOLUTION_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BURGERS_SOLUTION library.\n" );

  burgers_viscous_time_exact1_test01 ( );
  burgers_viscous_time_exact1_test02 ( );

  burgers_viscous_time_exact2_test01 ( );
  burgers_viscous_time_exact2_test02 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BURGERS_SOLUTION_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void burgers_viscous_time_exact1_test01 ( )

/******************************************************************************/
/*
  Purpose:

    BURGERS_VISCOUS_TIME_EXACT1_TEST01 sets up a small test case.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 November 2011

  Author:

    John Burkardt
*/
{
  char *filename = "burgers_solution_test01.txt";
  double nu;
  double r8_pi = 3.141592653589793;
  double thi;
  double tlo;
  double *vu;
  double *vt;
  int vtn = 11;
  double *vx;
  int vxn = 11;
  double xhi;
  double xlo;

  nu = 0.01 / r8_pi;

  printf ( "\n" );
  printf ( "BURGERS_VISCOUS_TIME_EXACT1_TEST01\n" );
  printf ( "  BURGERS_VISCOUS_TIME_EXACT1 evaluates solution #1\n" );
  printf ( "  to the Burgers equation.\n" );
  printf ( "\n" );
  printf ( "  Viscosity NU = %g\n", nu );
  printf ( "  NX = %d\n", vxn );
  printf ( "  NT = %d\n", vtn );

  xlo = -1.0;
  xhi = +1.0;
  vx = r8vec_even_new ( vxn, xlo, xhi );
  r8vec_print ( vxn, vx, "  X grid points:" );

  tlo = 0.0;
  thi = 3.0 / r8_pi;
  vt = r8vec_even_new ( vtn, tlo, thi );
  r8vec_print ( vtn, vt, "  T grid points:" );

  vu = burgers_viscous_time_exact1 ( nu, vxn, vx, vtn, vt );

  r8mat_print ( vxn, vtn, vu, "  U(X,T) at grid points:" );

  r8mat_write ( filename, vxn, vtn, vu );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", filename );

  free ( vt );
  free ( vu );
  free ( vx );

  return;
}
/******************************************************************************/

void burgers_viscous_time_exact1_test02 ( )

/******************************************************************************/
/*
  Purpose:

    BURGERS_VISCOUS_TIME_EXACT1_TEST02 tests sets up a finer test case.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 November 2011

  Author:

    John Burkardt
*/
{
  char *filename = "burgers_solution_test02.txt";
  double nu;
  double r8_pi = 3.141592653589793;
  double thi;
  double tlo;
  double *vu;
  double *vt;
  int vtn = 41;
  double *vx;
  int vxn = 41;
  double xhi;
  double xlo;

  nu = 0.01 / r8_pi;

  printf ( "\n" );
  printf ( "BURGERS_VISCOUS_TIME_EXACT1_TEST02\n" );
  printf ( "  BURGERS_VISCOUS_TIME_EXACT1 evaluates solution #1\n" );
  printf ( "  to the Burgers equation.\n" );
  printf ( "\n" );
  printf ( "  Viscosity NU = %g\n", nu );
  printf ( "  NX = %d\n", vxn );
  printf ( "  NT = %d\n", vtn );

  xlo = -1.0;
  xhi = +1.0;
  vx = r8vec_even_new ( vxn, xlo, xhi );
  r8vec_print ( vxn, vx, "  X grid points:" );

  tlo = 0.0;
  thi = 3.0 / r8_pi;
  vt = r8vec_even_new ( vtn, tlo, thi );
  r8vec_print ( vtn, vt, "  T grid points:" );

  vu = burgers_viscous_time_exact1 ( nu, vxn, vx, vtn, vt );

  r8mat_write ( filename, vxn, vtn, vu );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", filename );

  free ( vt );
  free ( vu );
  free ( vx );

  return;
  return;
}
/******************************************************************************/

void burgers_viscous_time_exact2_test01 ( )

/******************************************************************************/
/*
  Purpose:

    BURGERS_VISCOUS_TIME_EXACT2_TEST01 sets up a small test case.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2015

  Author:

    John Burkardt
*/
{
  char *filename = "burgers_solution_test03.txt";
  double nu;
  double r8_pi = 3.141592653589793;
  double thi;
  double tlo;
  double *vu;
  double *vt;
  int vtn = 11;
  double *vx;
  int vxn = 11;
  double xhi;
  double xlo;

  nu = 0.5;

  printf ( "\n" );
  printf ( "BURGERS_VISCOUS_TIME_EXACT2_TEST01\n" );
  printf ( "  BURGERS_VISCOUS_TIME_EXACT2 evaluates solution #2\n" );
  printf ( "  to the Burgers equation.\n" );
  printf ( "\n" );
  printf ( "  Viscosity NU = %g\n", nu );
  printf ( "  NX = %d\n", vxn );
  printf ( "  NT = %d\n", vtn );

  xlo = 0.0;
  xhi = 2.0 * r8_pi;
  vx = r8vec_even_new ( vxn, xlo, xhi );
  r8vec_print ( vxn, vx, "  X grid points:" );

  tlo = 0.0;
  thi = 1.0;
  vt = r8vec_even_new ( vtn, tlo, thi );
  r8vec_print ( vtn, vt, "  T grid points:" );

  vu = burgers_viscous_time_exact2 ( nu, vxn, vx, vtn, vt );

  r8mat_print ( vxn, vtn, vu, "  U(X,T) at grid points:" );

  r8mat_write ( filename, vxn, vtn, vu );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", filename );

  free ( vt );
  free ( vu );
  free ( vx );

  return;
}
/******************************************************************************/

void burgers_viscous_time_exact2_test02 ( )

/******************************************************************************/
/*
  Purpose:

    BURGERS_VISCOUS_TIME_EXACT2_TEST02 tests sets up a finer test case.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 September 2015

  Author:

    John Burkardt
*/
{
  char *filename = "burgers_solution_test04.txt";
  double nu;
  double r8_pi = 3.141592653589793;
  double thi;
  double tlo;
  double *vu;
  double *vt;
  int vtn = 41;
  double *vx;
  int vxn = 41;
  double xhi;
  double xlo;

  nu = 0.5;

  printf ( "\n" );
  printf ( "BURGERS_VISCOUS_TIME_EXACT2_TEST02\n" );
  printf ( "  BURGERS_VISCOUS_TIME_EXACT2 evaluates solution #2\n" );
  printf ( "  to the Burgers equation.\n" );
  printf ( "\n" );
  printf ( "  Viscosity NU = %g\n", nu );
  printf ( "  NX = %d\n", vxn );
  printf ( "  NT = %d\n", vtn );

  xlo = 0.0;
  xhi = 2.0 * r8_pi;
  vx = r8vec_even_new ( vxn, xlo, xhi );
  r8vec_print ( vxn, vx, "  X grid points:" );

  tlo = 0.0;
  thi = 1.0;
  vt = r8vec_even_new ( vtn, tlo, thi );
  r8vec_print ( vtn, vt, "  T grid points:" );

  vu = burgers_viscous_time_exact2 ( nu, vxn, vx, vtn, vt );

  r8mat_write ( filename, vxn, vtn, vu );

  printf ( "\n" );
  printf ( "  Data written to file \"%s\".\n", filename );

  free ( vt );
  free ( vu );
  free ( vx );

  return;
  return;
}
