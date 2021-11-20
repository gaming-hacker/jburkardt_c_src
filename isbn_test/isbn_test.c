# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "isbn.h"

int main ( );
void ch_is_digit_test ( );
void ch_is_isbn_digit_test ( );
void ch_to_digit_test ( );
void i4_to_isbn_digit_test ( );
void isbn_check_digit_calculate_test ( );
void isbn_digit_to_i4_test ( );
void isbn_is_valid_test ( );
void s_to_digits_test ( );
void s_to_isbn_digits_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    ISBN_TEST tests the ISBN library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ISBN_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ISBN library.\n" );

  ch_is_digit_test ( );
  ch_is_isbn_digit_test ( );
  ch_to_digit_test ( );
  i4_to_isbn_digit_test ( );
  isbn_check_digit_calculate_test ( );
  isbn_digit_to_i4_test ( );
  isbn_is_valid_test ( );
  s_to_digits_test ( );
  s_to_isbn_digits_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ISBN_TEST\n" );
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

void ch_is_isbn_digit_test ( )

/******************************************************************************/
/*
  Purpose:

    CH_IS_ISBN_DIGIT_TEST tests CH_IS_ISBN_DIGIT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2015

  Author:

    John Burkardt
*/
{
  char c;
  char c_test[16] = { 
    '0', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', 
    'X', 'x', 'Y', '*', '?', 
    ' ' };
  int i;
  int value;

  printf ( "\n" );
  printf ( "CH_IS_ISBN_DIGIT_TEST\n" );
  printf ( "  CH_IS_ISBN_DIGIT is TRUE if a character represents an ISBN digit.\n" );
  printf ( "\n" );
  printf ( "       C  CH_IS_ISBN_DIGIT(C)\n" );
  printf ( "\n" );

  for ( i = 0; i < 16; i++ )
  {
    c = c_test[i];
    value = ch_is_isbn_digit ( c );
    printf ( "  '%1c'      %d\n", c, value );
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

void i4_to_isbn_digit_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_TO_ISBN_DIGIT_TEST tests I4_TO_ISBN_DIGIT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2015

  Author:

    John Burkardt
*/
{
  char c;
  int i4;

  printf ( "\n" );
  printf ( "I4_TO_ISBN_DIGIT_TEST\n" );
  printf ( "  I4_TO_ISBN_DIGIT converts digits 0 to 10 to an ISBN digit.\n" );
  printf ( "\n" );

  for ( i4 = 0; i4 <= 10; i4++ )
  {
    c = i4_to_isbn_digit ( i4 );
    printf ( "      %2d      '%c'\n", i4, c );
  }

  return;
}
/******************************************************************************/

void isbn_check_digit_calculate_test ( )

/******************************************************************************/
/*
  Purpose:

    ISBN_CHECK_DIGIT_CALCULATE_TEST tests ISBN_CHECK_DIGIT_CALCULATE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2015

  Author:

    John Burkardt
*/
{
  char c1;
  char c2;
  char s1[255];

  printf ( "\n" );
  printf ( "ISBN_CHECK_DIGIT_CALCULATE_TEST\n" );
  printf ( "  ISBN_CHECK_DIGIT_CALCULATE calculates the 10-th digit\n" );
  printf ( "  (the check digit) of a 10-digit ISBN.\n" );
  printf ( "\n" );
/*
  Supply the full code, with dashes.
*/
  strcpy ( s1, "0-306-40615-2" );
  c1 = '2';
  c2 = isbn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is '%c', expecting '%c'\n", s1, c2, c1 );
/*
  Supply a partial code, with spaces.
*/
  strcpy ( s1, "0 8493 9640" );
  c1 = '9';
  c2 = isbn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is '%c', expecting '%c'\n", s1, c2, c1 );
/*
  Supply a partial code, no spaces.
*/
  strcpy ( s1, "158488059" );
  c1 = '7';
  c2 = isbn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is '%c', expecting '%c'\n", s1, c2, c1 );
/*
  Supply a partial code, no spaces.
*/
  strcpy ( s1, "246897531" );
  c1 = '6';
  c2 = isbn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is '%c', expecting '%c'\n", s1, c2, c1 );
/*
  Supply a partial code, no spaces.
*/
  strcpy ( s1, "135798642" );
  c1 = '4';
  c2 = isbn_check_digit_calculate ( s1 );
  printf ( "  Check digit of '%s' is '%c', expecting '%c'\n", s1, c2, c1 );

  return;
}
/******************************************************************************/

void isbn_digit_to_i4_test ( )

/******************************************************************************/
/*
  Purpose:

    ISBN_DIGIT_TO_I4_TEST tests ISBN_DIGIT_TO_I4.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2015

  Author:

    John Burkardt
*/
{
  char c;
  char c_test[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'x', 'Y', '?', '*', ' ' };
  int i;
  int i4;

  printf ( "\n" );
  printf ( "ISBN_DIGIT_TO_I4_TEST\n" );
  printf ( "  ISBN_DIGIT_TO_I4 converts an ISBN digit to an I4\n" );
  printf ( "\n" );

  for ( i = 0; i < 16; i++ )
  {
    c = c_test[i];
    i4 = isbn_digit_to_i4 ( c );
    printf ( "  '%c'        %2d\n", c, i4 );
  }

  return;
}
/******************************************************************************/

void isbn_is_valid_test ( )

/******************************************************************************/
/*
  Purpose:

    ISBN_IS_VALID_TEST tests ISBN_IS_VALID.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2015

  Author:

    John Burkardt
*/
{
  char s1[255];
  int value1;
  int value2;

  printf ( "\n" );
  printf ( "ISBN_IS_VALID_TEST\n" );
  printf ( "  ISBN_IS_VALID reports whether a ISBN is valid.\n" );
  printf ( "\n" );
/*
  Supply a valid code, with dashes.
*/
  strcpy ( s1, "0-306-40615-2" );
  value1 = 1;
  value2 = isbn_is_valid ( s1 );
  printf ( "  Validity of '%s' is '%d', expecting '%d'\n", s1, value2, value1 );
/*
  Modify one digit.
*/
  strcpy ( s1, "0-326-40615-2" );
  value1 = 0;
  value2 = isbn_is_valid ( s1 );
  printf ( "  Validity of '%s' is '%d', expecting '%d'\n", s1, value2, value1 );
/*
  Supply a valid code, with spaces.
*/
  strcpy ( s1, "0 8493 9640 9" );
  value1 = 1;
  value2 = isbn_is_valid ( s1 );
  printf ( "  Validity of '%s' is '%d', expecting '%d'\n", s1, value2, value1 );
/*
  Modify the check digit.
*/
  strcpy ( s1, "0 8493 9640 3" );
  value1 = 0;
  value2 = isbn_is_valid ( s1 );
  printf ( "  Validity of '%s' is '%d', expecting '%d'\n", s1, value2, value1 );
/*
  Supply a valid code, with a final digit of 'X'.
*/
  strcpy ( s1, "0-3870-9654-X" );
  value1 = 1;
  value2 = isbn_is_valid ( s1 );
  printf ( "  Validity of '%s' is '%d', expecting '%d'\n", s1, value2, value1 );
/*
  Supply a valid code, with a final digit of 'x'.
*/
  strcpy ( s1, "0-201-38597-x" );
  value1 = 1;
  value2 = isbn_is_valid ( s1 );
  printf ( "  Validity of '%s' is '%d', expecting '%d'\n", s1, value2, value1 );

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

void s_to_isbn_digits_test ( )

/******************************************************************************/
/*
  Purpose:

    S_TO_ISBN_DIGITS_TEST tests S_TO_ISBN_DIGITS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2015

  Author:

    John Burkardt
*/
{
  int *dvec;
  int n;
  char s[255];

  printf ( "\n" );
  printf ( "S_TO_ISBN_DIGITS_TEST\n" );
  printf ( "  S_TO_ISBN_DIGITS: string -> digit vector\n" );

  strcpy ( s, "34E9X-70.6" );
  printf ( "\n" );
  printf ( "  Test string: '%s'\n", s );
  n = 5;
  dvec = s_to_isbn_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 5 digits:" );
  free ( dvec );

  strcpy ( s, "34E9X-70.6" );
  printf ( "\n" );
  printf ( "  Test string: '%s'\n", s );
  n = 7;
  dvec = s_to_isbn_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 7 digits:" );
  free ( dvec );

  return;
}
