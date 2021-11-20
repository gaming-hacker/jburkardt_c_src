# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "atbash.h"

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    ATBASH_TEST tests ATBASH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 March 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );

  printf ( "\n" );
  printf ( "ATBASH_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ATBASH_ENCRYPT encrypts a plain text using the Atbash\n" );
  printf ( "  substitution cipher.\n" );

  atbash_test01 ( );
  atbash_test02 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ATBASH_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void atbash_test01 ( )

/******************************************************************************/
/*
  Purpose:

    ATBASH_TEST01 tests ATBASH with a short phrase.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 March 2018

  Author:

    John Burkardt
*/
{
  char *crypt;
  char *decrypt;
  char *plain = "A man, a plan, a canal - Panama!";

  printf ( "\n" );
  printf ( "ATBASH_TEST01\n" );
  printf ( "  Apply ATBASH to a short phrase.\n" );

  crypt = atbash_encrypt ( plain );
  decrypt = atbash_encrypt ( crypt );
  printf ( "\n" );
  printf ( "PLAIN:   '%s'\n", plain );
  printf ( "CRYPT:   '%s'\n", crypt );
  printf ( "DECRYPT: '%s'\n", decrypt );

  free ( crypt );
  free ( decrypt );

  return;
}
/******************************************************************************/

void atbash_test02 ( )

/******************************************************************************/
/*
  Purpose:

    ATBASH_TEST02 tests ATBASH with another phrase.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 March 2018

  Author:

    John Burkardt
*/
{
  char *crypt;
  char *decrypt;
  char *plain = "There are a thousand hacking at the branches of evil for every one who is striking at its root.";

  printf ( "\n" );
  printf ( "ATBASH_TEST02\n" );
  printf ( "  Apply ATBASH to a longer phrase.\n" );

  crypt = atbash_encrypt ( plain );
  decrypt = atbash_encrypt ( crypt );
  printf ( "\n" );
  printf ( "PLAIN:   '%s'\n", plain );
  printf ( "CRYPT:   '%s'\n", crypt );
  printf ( "DECRYPT: '%s'\n", decrypt );

  free ( crypt );
  free ( decrypt );

  return;
}

