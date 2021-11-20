# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "luhn.h"

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

int luhn_check_digit_calculate ( char *s )

/******************************************************************************/
/*
  Purpose:

    LUHN_CHECK_DIGIT_CALCULATE determines the Luhn check digit of a string.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2015

  Reference:

    https://en.wikipedia.org/wiki/Luhn_algorithm

  Parameters:

    Input, char *S, the string of digits to be checked.

    Output, integer LUHN_CHECK_DIGIT_CALCULATE, the Luhn check digit for 
    this string.
*/
{
  int s_len;
  char *s2;
  int value;

  s_len = strlen ( s );
  s2 = ( char * ) malloc ( ( s_len + 2 ) * sizeof ( char ) );

  strcpy ( s2, s );
  strcat ( s2, "0" );

  value = luhn_checksum ( s2 );

  if ( value != 0 )
  {
    value = 10 - value;
  }

  free ( s2 );

  return value;
}
/******************************************************************************/

int luhn_checksum ( char *s )

/******************************************************************************/
/*
  Purpose:

    LUHN_CHECKSUM determines the Luhn checksum of a string.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2015

  Reference:

    https://en.wikipedia.org/wiki/Luhn_algorithm

  Parameters:

    Input, char *S, the string of digits to be checked.

    Output, int VALUE, is the Luhn checksum for this string.
*/
{
  int d2;
  int *dvec;
  int i;
  int n;
  int value;
/*
  Count the digits in S.
*/
  n = s_digits_count ( s );
/*
  Extract the digits from S.
*/
  dvec = s_to_digits ( s, n );
/*
  Starting with the last-th digit, and going down by 2's, 
  add the digit to the sum.
*/
  value = 0;
  for ( i = n - 1; 0 <= i; i = i - 2 )
  {
    value = value + dvec[i];
  }
/*
  Starting with the next to the last digit, and going down by 2's, 
  double the digit, and ADD THE DIGITS to the sum.
*/
  for ( i = n - 2; 0 <= i; i = i - 2 )
  {
    d2 = 2 * dvec[i];
    value = value + ( d2 / 10 ) +( d2 % 10 );
  }

  value = ( value % 10 );

  free ( dvec );

  return value;
}
/******************************************************************************/

int luhn_is_valid ( char *s )

/******************************************************************************/
/*
  Purpose:

    LUHN_IS_VALID determines whether a string with Luhn check digit is valid.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2015

  Reference:

    https://en.wikipedia.org/wiki/Luhn_algorithm

  Parameters:

    Input, char *S, the string of digits to be checked.

    Output, int LUHN_IS_VALID, TRUE if the string is valid.
*/
{
  int d;
  int value;

  d = luhn_checksum ( s );

  if ( d == 0 )
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

int s_digits_count ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_DIGITS_COUNT counts the digits in a string.

  Discussion:

    The string may include spaces, letters, and dashes, but only the
    digits 0 through 9 will be counted.

  Example:

    S  => 34E94-70.6
    N <=  7

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string.

    Output, int S_DIGITS_COUNT, the number of digits.
*/
{
  char c;
  int n;
  int s_len;
  int s_pos;

  s_len = strlen ( s );

  s_pos = 0;
  n = 0;

  while ( s_pos < s_len )
  {

    c = s[s_pos];
    s_pos = s_pos + 1;

    if ( ch_is_digit ( c ) )
    {
      n = n + 1;
    }
  }

  return n;
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
