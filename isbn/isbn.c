# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "isbn.h"

/******************************************************************************/

int ch_is_digit ( char c )

/******************************************************************************/
/*
  Purpose:

    CH_IS_DIGIT returns TRUE if a character is a decimal digit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 January 2014

  Author:

    John Burkardt

  Parameters:

    Input, char C, the character to be analyzed.

    Output, int CH_IS_DIGIT, is TRUE if C is a digit.
*/
{
  int value;

  if ( '0' <= c && c <= '9' )
  {
    value = 1;
  }
  else
  {
    value = 0;
  }
  return value;
}
/******************************************************************************/

int ch_is_isbn_digit ( char c )

/******************************************************************************/
/*
  Purpose:

    CH_IS_ISBN_DIGIT returns TRUE if a character is an ISBN digit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char C, the character to be analyzed.

    Output, int CH_IS_ISBN_DIGIT, is TRUE if C is an ISBN digit.
*/
{
  int value;

  if ( '0' <= c && c <= '9' )
  {
    value = 1;
  }
  else if ( c == 'X' || c == 'x' )
  {
    value = 1;
  }
  else
  {
    value = 0;
  }
  return value;
}
/******************************************************************************/

int ch_to_digit ( char ch )

/******************************************************************************/
/*
  Purpose:

    CH_TO_DIGIT returns the integer value of a base 10 digit.

  Example:

     CH  DIGIT
    ---  -----
    '0'    0
    '1'    1
    ...  ...
    '9'    9
    ' '   -1
    'X'   -1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 June 2003

  Author:

    John Burkardt

  Parameters:

    Input, char CH, the decimal digit, '0' through '9'.

    Output, int CH_TO_DIGIT, the corresponding integer value.  If the
    character was 'illegal', then DIGIT is -1.
*/
{
  int digit;

  if ( '0' <= ch && ch <= '9' )
  {
    digit = ch - '0';
  }
  else
  {
    digit = -1;
  }

  return digit;
}
/******************************************************************************/

char i4_to_isbn_digit ( int i )

/******************************************************************************/
/*
  Purpose:

    I4_TO_ISBN_DIGIT converts an I4 to an ISBN digit.

  Discussion:

    Only the integers 0 through 10 can be input.  The representation
    of 10 is 'X'.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, int I, an integer between 0 and 10.

    Output, char I4_TO_ISBN_DIGIT, the ISBN character code of the integer.
    If I is illegal, then the value is set to '?'.
*/
{
       if ( i == 0 )
  {
    return '0';
  }
  else if ( i == 1 )
  {
    return '1';
  }
  else if ( i == 2 )
  {
    return '2';
  }
  else if ( i == 3 )
  {
    return '3';
  }
  else if ( i == 4 )
  {
    return '4';
  }
  else if ( i == 5 )
  {
    return '5';
  }
  else if ( i == 6 )
  {
    return '6';
  }
  else if ( i == 7 )
  {
    return '7';
  }
  else if ( i == 8 )
  {
    return '8';
  }
  else if ( i == 9 )
  {
    return '9';
  }
  else if ( i == 10 )
  {
    return 'X';
  }
  else
  {
    return '?';
  }
}
/******************************************************************************/

void i4vec_print ( int n, int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PRINT prints an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 November 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %6d: %8d\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

char isbn_check_digit_calculate ( char *s )

/******************************************************************************/
/*
  Purpose:

    ISBN_CHECK_DIGIT_CALCULATE determines the check digit for an ISBN.

  Discussion:

    ISBN stands for International Standard Book Number.  A unique ISBN
    is assigned to each new book.  The ISBN includes 10 digits.  There is
    an initial digit, then a dash, then a set of digits which are a
    code for the publisher, another digit, and then the check digit:

      initial-publisher-book-check

    The number of digits used for the publisher and book codes can vary,
    but the check digit is always one digit, and the total number of
    digits is always 10.

    The check digit is interesting, because it is a way of trying to
    make sure that an ISBN has not been incorrectly copied.  Specifically,
    if the ISBN is correct, then its ten digits will satisfy

       10 * A + 9 * B + 8 * C + 7 * D + 6 * E
      + 5 * F * 4 * G * 3 * H + 2 * I +     J  = 0 mod 11.

    Here, we've taken 'A' to represent the first digit and 'J' the
    last (which is the check digit).  In order for the code to work,
    the value of J must be allowed to be anything from 0 to 10.  In
    cases where J works out to be 10, the special digit 'X' is used.
    An 'X' digit can only occur in this last check-digit position
    on an ISBN.

  Example:

    S  => 0-8493-9640-?
    D <=  9

    meaning the ISBN is 0-8493-9640-9

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a string.  Dashes and spaces and other
    nonnumeric data is ignored, but at least 9 digits are expected, and only
    the first 9 digits will be examined.

    Output, character ISBN_CHECK_DIGIT_CALCULATE, the ISBN 
    check digit that should be appended to form the full 10 digit ISBN.
*/
{
  char c;
  int d;
  int *dvec;
  int i;
  int n;
/*
  Extract first 9 digits.
*/
  n = 9;
  dvec = s_to_digits ( s, n );
/*
  Compute the check digit.
*/
  d = 0;
  for ( i = 0; i < 9; i++ )
  {
    d = d + ( 10 - i ) * dvec[i];
  }

  d = ( ( 11 - ( d % 11 ) ) % 11 );
/*
  Convert digits 0 through 9, 10 to characters '0' through '9', 'X'.
*/
  c = i4_to_isbn_digit ( d );

  return c;
}
/******************************************************************************/

int isbn_digit_to_i4 ( char c )

/******************************************************************************/
/*
  Purpose:

    ISBN_DIGIT_TO_I4 converts an ISBN digit into an I4.

  Discussion:

    The characters '0' through '9' stand for themselves, but
    the character 'X' or 'x' stands for 10.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char C, the ISBN character code to be converted.

    Output, int ISBN_DIGIT_TO_I4, the numeric value of the character
    code, between 0 and 10.  This value is returned as -1 if C is
    not a valid character code.
*/
{
  int value;

  if ( '0' <= c && c <= '9' )
  {
    value = c - '0';
  }
  else if ( c == 'X' || c == 'x' )
  {
    value = 10;
  }
  else
  {
    value = -1;
  }

  return value;
}
/******************************************************************************/

int isbn_is_valid ( char *s )

/******************************************************************************/
/*
  Purpose:

    ISBN_IS_VALID reports whether an ISBN is valid.

  Discussion:

    ISBN stands for International Standard Book Number.  A unique ISBN
    is assigned to each new book.  The ISBN includes 10 digits.  There is
    an initial digit, then a dash, then a set of digits which are a
    code for the publisher, another digit, and then the check digit:

      initial-publisher-book-check

    The number of digits used for the publisher and book codes can vary,
    but the check digit is always one digit, and the total number of
    digits is always 10.

    The check digit is interesting, because it is a way of trying to
    make sure that an ISBN has not been incorrectly copied.  Specifically,
    if the ISBN is correct, then its ten digits will satisfy

       10 * A + 9 * B + 8 * C + 7 * D + 6 * E
      + 5 * F * 4 * G * 3 * H + 2 * I +     J  = 0 mod 11.

    Here, we've taken 'A' to represent the first digit and 'J' the
    last (which is the check digit).  In order for the code to work,
    the value of J must be allowed to be anything from 0 to 10.  In
    cases where J works out to be 10, the special digit 'X' is used.
    An 'X' digit can only occur in this last check-digit position
    on an ISBN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a string containing 12 digits.
    Dashes and other characters will be ignored.

    Output, int ISBN_IS_VALID, is TRUE if the string is valid.
*/
{
  char c1;
  int d1;
  int d2;
  int *dvec;
  int n;
  int value;

  n = 10;
  dvec = s_to_isbn_digits ( s, n );

  c1 = isbn_check_digit_calculate ( s );
  d1 = isbn_digit_to_i4 ( c1 );

  d2 = dvec[9];

  if ( d1 == d2 )
  {
    value = 1;
  }
  else
  {
    value = 0;
  }

  free ( dvec );

  return value;
}
/******************************************************************************/

int *s_to_digits ( char *s, int n )

/******************************************************************************/
/*
  Purpose:

    S_TO_DIGITS extracts N digits from a string.

  Discussion:

    The string may include spaces, letters, and dashes, but only the
    digits 0 through 9 will be extracted.

  Example:

    S  => 34E94-70.6
    N  => 5
    D <=  (/ 3, 4, 9, 4, 7 /)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string.

    Input, int N, the number of digits to extract.

    Output, int S_TO_DIGITS[N], the extracted digits.
*/
{
  char c;
  int d;
  int d_pos;
  int *dvec;
  int s_len;
  int s_pos;

  dvec = ( int * ) malloc ( n * sizeof ( int ) );

  s_len = strlen ( s );

  s_pos = 0;
  d_pos = 0;

  while ( d_pos < n )
  {

    if ( s_len <= s_pos )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "S_TO_DIGITS - Fatal error!\n" );
      fprintf ( stderr, "  Could not read enough data from string.\n" );
      exit ( 1 );
    }

    c = s[s_pos];
    s_pos = s_pos + 1;

    if ( ch_is_digit ( c ) )
    {
      d = ch_to_digit ( c );
      dvec[d_pos] = d;
      d_pos = d_pos + 1;
    }
  }

  return dvec;
}
/******************************************************************************/

int *s_to_isbn_digits ( char *s, int n )

/******************************************************************************/
/*
  Purpose:

    S_TO_ISBN_DIGITS extracts N ISBN digits from a string.

  Discussion:

    The string may include spaces, letters, and dashes, but only the
    digits 0 through 9 and 'X' or 'x' will be extracted.

  Example:

    S  => 34E9X-70.6
    N  => 5
    D <=  (/ 3, 4, 9, 10, 7 /)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string.

    Input, int N, the number of digits to extract.

    Output, int S_TO_ISBN_DIGITS[N], the extracted digits.
*/
{
  char c;
  int d;
  int d_pos;
  int *dvec;
  int s_len;
  int s_pos;

  dvec = ( int * ) malloc ( n * sizeof ( int ) );

  s_len = strlen ( s );

  s_pos = 0;
  d_pos = 0;

  while ( d_pos < n )
  {

    if ( s_len <= s_pos )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "S_TO_ISBN_DIGITS - Fatal error!\n" );
      fprintf ( stderr, "  Could not read enough data from string.\n" );
      exit ( 1 );
    }

    c = s[s_pos];
    s_pos = s_pos + 1;

    if ( ch_is_isbn_digit ( c ) )
    {
      d = isbn_digit_to_i4 ( c );
      dvec[d_pos] = d;
      d_pos = d_pos + 1;
    }
  }

  return dvec;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
