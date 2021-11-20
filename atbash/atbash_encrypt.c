# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "atbash.h"

/******************************************************************************/

char *atbash_encrypt ( char *plain )

/******************************************************************************/
/*
  Purpose:

    ATBASH_ENCRYPT encrypts a string using the ATBASH code.

  Discussion:

    Only the alphabetic characters will be encrypted.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, char *PLAIN, the string to be encrypted.

    Output, char *ATBASH_ENCRYPT, the encrypted version of the string.
*/
{
  char *crypt;
  char *crypt_pointer;
/*
  Create space for the encrypted string.
*/
  crypt = ( char * ) malloc ( ( strlen ( plain ) + 1 ) * sizeof ( char ) );
  crypt_pointer = crypt;
/*
  Convert plain text characters to unsigned integers,
  and reverse the index.
*/
  while ( *plain != '\0' )
  {
    if ( 'a' <= *plain && *plain <= 'z' )
    {
      *crypt_pointer = 'a' + 'z' - *plain;
    }
    else if ( 'A' <= *plain && *plain <= 'Z' )
    {
      *crypt_pointer = 'A' + 'Z' - *plain;
    }
    else
    {
      *crypt_pointer = *plain;
    }
    plain++;
    crypt_pointer++;
  }

  *crypt_pointer = '\0';

  return crypt;
}

