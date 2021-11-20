# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "upc.h"

int main ( );
void ch_is_digit_test ( );
void ch_to_digit_test ( );
void s_to_digits_test ( );
void upc_check_digit_calculate_test ( );
void upc_is_valid_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for UPC_TEST.

  Discussion:

    UPC_TEST tests the UPC library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "UPC_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the UPC library.\n" );

  ch_is_digit_test ( );
  ch_to_digit_test ( );
  s_to_digits_test ( );
  upc_check_digit_calculate_test ( );
  upc_is_valid_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "UPC_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void ch_is_digit_test ( )

/******************************************************************************/
/*
  Purpose:

    CH_IS_DIGIT_TEST tests CH_IS_DIGIT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  char c;
  char c_test[13] = { 
    '0', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', 
    'X', '?', ' ' };
  int i;
  int value;

  printf ( "\n" );
  printf ( "CH_IS_DIGIT_TEST\n" );
  printf ( "  CH_IS_DIGIT is TRUE if a character represents a digit.\n" );
  printf ( "\n" );
  printf ( "       C  CH_IS_DIGIT(C)\n" );
  printf ( "\n" );

  for ( i = 0; i < 13; i++ )
  {
    c = c_test[i];
    value = ch_is_digit ( c );
    printf ( "  %2d  '%1c'      %d\n", i, c, value );
  }

  return;
}
/******************************************************************************/

void ch_to_digit_test ( )

/******************************************************************************/
/*
  Purpose:

    CH_TO_DIGIT_TEST tests CH_TO_DIGIT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  char c;
  char c_test[13] = { 
    '0', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', 
    'X', '?', ' ' };
  int i;
  int i2;

  printf ( "\n" );
  printf ( "CH_TO_DIGIT_TEST\n" );
  printf ( "  CH_TO_DIGIT: character -> decimal digit\n" );
  printf ( "\n" );

  for ( i = 0; i < 13; i++ )
  {
    c = c_test[i];
    i2 = ch_to_digit ( c );
    printf ( "  %6d     %1c  %6d\n", i, c, i2 );
  }

  return;
}
/******************************************************************************/

void s_to_digits_test ( )

/******************************************************************************/
/*
  Purpose:

    S_TO_DIGITS_TEST tests S_TO_DIGITS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  int *dvec;
  int n;
  char s[255];

  printf ( "\n" );
  printf ( "S_TO_DIGITS_TEST\n" );
  printf ( "  S_TO_DIGITS: string -> digit vector\n" );

  strcpy ( s, "34E94-70.6" );
  printf ( "\n" );
  printf ( "  Test string: '%s'\n", s );
  n = 5;
  dvec = s_to_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 5 digits:" );
  free ( dvec );

  strcpy ( s, "34E94-70.6" );
  printf ( "\n" );
  printf ( "  Test string: '%s'\n", s );
  n = 7;
  dvec = s_to_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 7 digits:" );
  free ( dvec );

  return;
}
/******************************************************************************/

void upc_check_digit_calculate_test ( )

/******************************************************************************/
/*
  Purpose:

    UPC_CHECK_DIGIT_CALCULATE_TEST tests UPC_CHECK_DIGIT_CALCULATE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  int d1;
  int d2;
  char s1[255];

  printf ( "\n" );
  printf ( "UPC_CHECK_DIGIT_CALCULATE_TEST\n" );
  printf ( "  UPC_CHECK_DIGIT_CALCULATE calculates the 12-th digit\n" );
  printf ( "  (the check digit) of a UPC.\n" );
  printf ( "\n" );
/*
  Supply the full code, with dashes.
*/
  strcpy ( s1, "6-39382-00039-3" );
  d1 = 3;
  d2 = upc_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );
/*
  Supply a partial code, with spaces.
*/
  strcpy ( s1, "0 43000 18170" );
  d1 = 6;
  d2 = upc_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );
/*
  Supply a partial code, no spaces.
*/
  strcpy ( s1, "30074660601" );
  d1 = 7;
  d2 = upc_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );
/*
  Supply a partial code, no spaces.
*/
  strcpy ( s1, "24689753124" );
  d1 = 5;
  d2 = upc_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );
/*
  Supply a partial code, no spaces.
*/
  strcpy ( s1, "13579864213" );
  d1 = 9;
  d2 = upc_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );

  return;
}
/******************************************************************************/

void upc_is_valid_test ( )

/******************************************************************************/
/*
  Purpose:

    UPC_IS_VALID_TEST tests UPC_IS_VALID.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  char s1[255];
  int value1;
  int value2;

  printf ( "\n" );
  printf ( "UPC_IS_VALID_TEST\n" );
  printf ( "  UPC_IS_VALID reports whether a UPC is valid.\n" );
  printf ( "\n" );
/*
  Supply a valid code, with dashes.
*/
  strcpy ( s1, "6-39382-00039-3" );
  value1 = 1;
  value2 = upc_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );
/*
  Modify one digit.
*/
  strcpy ( s1, "6-39352-00039-3" );
  value1 = 0;
  value2 = upc_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );
/*
  Supply a valid code, with spaces.
*/
  strcpy ( s1, "0 43000 18170 6" );
  value1 = 1;
  value2 = upc_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );
/*
  Modify the check digit.
*/
  strcpy ( s1, "0 43000 18170 9" );
  value1 = 0;
  value2 = upc_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );

  return;
}
