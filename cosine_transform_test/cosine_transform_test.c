# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "cosine_transform.h"

int main ( );
void cosine_transform_test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for COSINE_TRANSFORM_TEST.

  Discussion:

    COSINE_TRANSFORM_TEST tests the COSINE_TRANSFORM library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "COSINE_TRANSFORM_TEST\n" );
  printf ( "  C version.\n" );
  printf ( "  Test the COSINE_TRANSFORM library.\n" );

  cosine_transform_test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "COSINE_TRANSFORM_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void cosine_transform_test01 ( )

/******************************************************************************/
/*
  Purpose:

    COSINE_TRANSFORM_TEST01 applies the DCT and its inverse.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 August 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n = 10;
  int seed;
  double *r;
  double *s;
  double *t;

  seed = 123456789;

  printf ( "\n" );
  printf ( "COSINE_TRANSFORM_TEST01:\n" );
  printf ( "  COSINE_TRANSFORM_DATA does a cosine transform of data\n" );
  printf ( "  defined by a vector.\n" );
  printf ( "\n" );
  printf ( "  Apply the transform, then its inverse.\n" );
  printf ( "  Let R be a random N vector.\n" );
  printf ( "  Let S be the transform of D.\n" );
  printf ( "  Let T be the transform of E.\n" );
  printf ( "  Then R and T will be equal.\n" );

  r = r8vec_uniform_01_new ( n, &seed );
  s = cosine_transform_data ( n, r );
  t = cosine_transform_inverse ( n, s );

  printf ( "\n" );
  printf ( "     I      R(I)        S(I)        T(I)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %4d  %10f  %10f  %10f\n", i, r[i], s[i], t[i] );
  }

  free ( r );
  free ( s );
  free ( t );

  return;
}

