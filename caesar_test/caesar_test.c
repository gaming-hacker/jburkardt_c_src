# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "caesar.h"

int main ( );
void s_to_caesar_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CAESAR_TEST.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 January 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "CAESAR_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the CAESAR library.\n" );

  s_to_caesar_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CAESAR_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void s_to_caesar_test ( )

/******************************************************************************/
/*
  Purpose:

    S_TO_CAESAR_TEST tests the S_TO_CAESAR library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 January 2016

  Author:

    John Burkardt
*/
{
  int k;
  char s1[80];
  char *s2;
  char *s3;

  printf ( "\n" );
  printf ( "S_TO_CAESAR_TEST\n" );
  printf ( "  S_TO_CAESAR applies a Caesar Shift cipher to a string.\n" );

  printf ( "\n" );
  printf ( "  S2 = S_TO_CAESAR ( S1, K ), varying K.\n" );
  printf ( "\n" );
  printf ( "   K  ---------------S1----------------  ---------------S2----------------\n" );
  printf ( "\n" );
  for ( k = -5; k <= 5; k++ )
  {
    strcpy ( s1, "A man, a plan, a canal: Panama!" );
    s2 = s_to_caesar ( s1, k );
    printf ( "  %2d  '%s'  '%s'\n", k, s1, s2 );
    free ( s2 );
  }

  printf ( "\n" );
  printf ( "  S2 = S_TO_CAESAR ( S1,  K ).\n" );
  printf ( "  S3 = S_TO_CAESAR ( S2, -K )\n" );
  printf ( "\n" );
  printf ( "   K  ------------S1------------  ------------S2------------  ------------S3------------\n" );
  printf ( "\n" );
  for ( k = -5; k <= 5; k++ )
  {
    strcpy ( s1, "The key is under the mat" );
    s2 = s_to_caesar ( s1, k );
    s3 = s_to_caesar ( s2, -k );
    printf ( "  %2d  '%s'  '%s'  '%s'\n", k, s1, s2, s3 );
    free ( s2 );
    free ( s3 );
  }

  return;
}
