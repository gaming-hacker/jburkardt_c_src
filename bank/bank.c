# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "bank.h"

/******************************************************************************/

int bank_check_digit_calculate ( char *s )

/******************************************************************************/
/*
  Purpose:

    BANK_CHECK_DIGIT_CALCULATE returns the check digit of a Bank checksum.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 October 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a string containing at least 8 digits.
    Dashes and other characters will be ignored.  A 9th digit may be
    included, but it will be ignored.

    Output, int BANK_CHECK_DIGIT_CALCULATE, the check digit.
*/
{
  int d;
  int *dvec;
  int n;

  n = 8;
  dvec = s_to_digits ( s, n );

  d = 3 * ( dvec[0] + dvec[3] + dvec[6] )
    + 7 * ( dvec[1] + dvec[4] + dvec[7] )
    +     ( dvec[2] + dvec[5] );

  d = ( d % 10 );

  d = ( ( 10 - d ) % 10 );

  free ( dvec );

  return d;
}
/******************************************************************************/

int bank_is_valid ( char *s )

/******************************************************************************/
/*
  Purpose:

    BANK_IS_VALID reports whether a bank checksum is valid.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 October 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a string containing 9 digits.
    Dashes and other characters will be ignored.

    Output, int BANK_IS_VALID, is TRUE if the string is valid.
*/
{
  int d1;
  int d2;
  int *dvec;
  int n;
  int value;

  n = 9;
  dvec = s_to_digits ( s, n );

  d1 = bank_check_digit_calculate ( s );
  d2 = dvec[8];

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
    ' '    0
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

