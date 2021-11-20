# include <stdlib.h>
# include <stdio.h>

# include "machar.h"

int main ( );
void r4_machar_test ( );
void r8_machar_test ( );

/**********************************************************************/

int main ( )

/**********************************************************************/
/*
  Purpose:

    MAIN is the main program for MACHAR_TEST.

  Discussion:

    MACHAR_TEST tests the MACHAR library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 November 2006

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "MACHAR_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the MACHAR library.\n" );

  r4_machar_test ( );
  r8_machar_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "MACHAR_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/**********************************************************************/

void r4_machar_test ( )

/**********************************************************************/
/*
  Purpose:

    R4_MACHAR_TEST tests R4_MACHAR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 November 2006

  Author:

    John Burkardt
*/
{
  float eps;
  float epsneg;
  long int ibeta;
  long int iexp;
  long int irnd;
  long int it;
  long int machep;
  long int maxexp;
  long int minexp;
  long int negep;
  long int ngrd;
  float xmax;
  float xmin;

  printf ( "\n" );
  printf ( "R4_MACHAR_TEST\n" );
  printf ( "  R4_MACHAR computes single\n" );
  printf ( "  precision machine constants.\n" );

  r4_machar ( &ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp,
    &minexp, &maxexp, &eps, &epsneg, &xmin, &xmax );

  printf ( "\n" );
  printf ( "  IBETA =  %ld\n", ibeta );
  printf ( "  IT =     %ld\n", it );
  printf ( "  IRND =   %ld\n", irnd );
  printf ( "  NGRD =   %ld\n", ngrd );
  printf ( "  MACHEP = %ld\n", machep );
  printf ( "  NEGEP =  %ld\n", negep );
  printf ( "  IEXP =   %ld\n", iexp );
  printf ( "  MINEXP = %ld\n", minexp );
  printf ( "  MAXEXP = %ld\n", maxexp );
  printf ( "  EPS =    %e\n", eps );
  printf ( "  EPSNEG = %e\n", epsneg );
  printf ( "  XMIN =   %e\n", xmin );
  printf ( "  XMAX =   %e\n", xmax );

  return;
}
/**********************************************************************/

void r8_machar_test ( )

/**********************************************************************/
/*
  Purpose:

    R8_MACHAR_TEST tests R8_MACHAR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 November 2006

  Author:

    John Burkardt
*/
{
  double eps;
  double epsneg;
  long int ibeta;
  long int iexp;
  long int irnd;
  long int it;
  long int machep;
  long int maxexp;
  long int minexp;
  long int negep;
  long int ngrd;
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "R8_MACHAR_TEST\n" );
  printf ( "  R8_MACHAR computes double\n" );
  printf ( "  precision machine constants.\n" );

  r8_machar ( &ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp,
    &minexp, &maxexp, &eps, &epsneg, &xmin, &xmax );

  printf ( "\n" );
  printf ( "  IBETA =  %ld\n", ibeta );
  printf ( "  IT =     %ld\n", it );
  printf ( "  IRND =   %ld\n", irnd );
  printf ( "  NGRD =   %ld\n", ngrd );
  printf ( "  MACHEP = %ld\n", machep );
  printf ( "  NEGEP =  %ld\n", negep );
  printf ( "  IEXP =   %ld\n", iexp );
  printf ( "  MINEXP = %ld\n", minexp );
  printf ( "  MAXEXP = %ld\n", maxexp );
  printf ( "  EPS =    %e\n", eps );
  printf ( "  EPSNEG = %e\n", epsneg );
  printf ( "  XMIN =   %e\n", xmin );
  printf ( "  XMAX =   %e\n", xmax );

  return;
}
