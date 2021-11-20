# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "luhn.h"

int main ( );
void ch_is_digit_test ( );
void ch_to_digit_test ( );
void luhn_check_digit_calculate_test ( );
void luhn_is_valid_test ( );
void s_digits_count_test ( );
void s_to_digits_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LUHN_TEST.

  Discussion:

    LUHN_TEST tests the LUHN library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 September 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "LUHN_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LUHN library.\n" );

  ch_is_digit_test ( );
  ch_to_digit_test ( );
  s_digits_count_test ( );
  s_to_digits_test ( );
  luhn_check_digit_calculate_test ( );
  luhn_is_valid_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LUHN_TEST\n" );
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

void luhn_check_digit_calculate_test ( )

/******************************************************************************/
/*
  Purpose:

    LUHN_CHECK_DIGIT_CALCULATE_TEST tests LUHN_CHECK_DIGIT_CALCULATE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2015

  Author:

    John Burkardt
*/
{
  int d1;
  int d2;
  char s1[255];
 
  printf ( "\n" );
  printf ( "LUHN_CHECK_DIGIT_CALCULATE_TEST\n" );
  printf ( "  LUHN_CHECK_DIGIT_CALCULATE calculates the check digit\n" );
  printf ( "  for a string of digits\n" );
  printf ( "\n" );

  strcpy ( s1, "7992739871" );
  d1 = 3;
  d2 = luhn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );

  strcpy ( s1, "9876234510" );
  d1 = 0;
  d2 = luhn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );

  strcpy ( s1, "246897531" );
  d1 = 9;
  d2 = luhn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );

  strcpy ( s1, "135798642" );
  d1 = 9;
  d2 = luhn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is %d, expecting %d\n", s1, d2, d1 );

  return;
}
/******************************************************************************/

void luhn_is_valid_test ( )

/******************************************************************************/
/*
  Purpose:

    LUHN_IS_VALID_TEST tests LUHN_IS_VALID.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2015

  Author:

    John Burkardt
*/
{
  char s1[255];
  int value1;
  int value2;
 
  printf ( "\n" );
  printf ( "LUHN_IS_VALID_TEST\n" );
  printf ( "  LUHN_IS_VALID determines whether a string with final\n" );
  printf ( "  Luhn check digit is valid.\n" );
  printf ( "\n" );

  strcpy ( s1, "79927398713" );
  value1 = 1;
  value2 = luhn_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );
/*
  Change a digit.
*/
  strcpy ( s1, "79924398713" );
  value1 = 0;
  value2 = luhn_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );
/*
  Change a check digit.
*/
  strcpy ( s1, "79927398711" );
  value1 = 0;
  value2 = luhn_is_valid ( s1 );
  printf ( "  Validity of '%s' is %d, expecting %d\n", s1, value2, value1 );

  return;
}
/******************************************************************************/

void s_digits_count_test ( )

/******************************************************************************/
/*
  Purpose:

    S_DIGITS_COUNT_TEST tests S_DIGITS_COUNT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2015

  Author:

    John Burkardt
*/
{
  int n;
  char s[255];
 
  printf ( "\n" );
  printf ( "S_DIGITS_COUNT_TEST\n" );
  printf ( "  S_DIGITS_COUNT counts the digits in a string.\n" );
  printf ( "\n" );

  strcpy ( s, "34E94-70.6" );
  n = s_digits_count ( s );
  printf ( "  We count %d digits in '%s'\n", n, s );

  strcpy ( s, "Not a one!" );
  n = s_digits_count ( s );
  printf ( "  We count %d digits in '%s'\n", n, s );

  strcpy ( s, "!8*k >>>> & SEVEN-0.3" );
  n = s_digits_count ( s );
  printf ( "  We count %d digits in '%s'\n", n, s );

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
