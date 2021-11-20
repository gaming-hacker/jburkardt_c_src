# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "chrpak.h"

int main ( );
void ch_cap_test ( );
void ch_is_digit_test ( );
void ch_is_isbn_digit_test ( );
void ch_to_digit_test ( );
void digit_to_ch_test ( );
void i4_to_isbn_digit_test ( );
void isbn_digit_to_i4_test ( );
void s_digits_count_test ( );
void s_len_trim_test ( );
void s_reverse_test ( );
void s_scrabble_points_test ( );
void s_to_caesar_test ( );
void s_to_digits_test ( );
void s_to_isbn_digits_test ( );
void s_to_rot13_test ( );
void s_word_count_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CHRPAK_TEST.

  Discussion:

    CHRPAK_TEST tests the CHRPAK library.

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
  printf ( "CHRPAK_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the CHRPAK library.\n" );

  ch_cap_test ( );
  ch_is_digit_test ( );
  ch_is_isbn_digit_test ( );
  ch_to_digit_test ( );
  digit_to_ch_test ( );
  i4_to_isbn_digit_test ( );
  isbn_digit_to_i4_test ( );
  s_digits_count_test ( );
  s_len_trim_test ( );
  s_reverse_test ( );
  s_scrabble_points_test ( );
  s_to_caesar_test ( );
  s_to_digits_test ( );
  s_to_isbn_digits_test ( );
  s_to_rot13_test ( );
  s_word_count_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CHRPAK_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void ch_cap_test ( )

/******************************************************************************/
/*
  Purpose:

    CH_CAP_TEST tests CH_CAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2007

  Author:

    John Burkardt
*/
{
  char c;

  printf ( "\n" );
  printf ( "CH_CAP_TEST\n" );
  printf ( "  CH_CAP uppercases a character.\n" );
  printf ( "\n" );
  printf ( "  C  CH_CAP(C)\n" );
  printf ( "\n" );

  c = 'F';
  printf ( "  %c  %c\n", c, ch_cap ( c ) );
  c = 'f';
  printf ( "  %c  %c\n", c, ch_cap ( c ) );
  c = '1';
  printf ( "  %c  %c\n", c, ch_cap ( c ) );
  c = 'b';
  printf ( "  %c  %c\n", c, ch_cap ( c ) );
  c = 'B';
  printf ( "  %c  %c\n", c, ch_cap ( c ) );

  return;
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
    printf ( "  '%1c'      %d\n", c, value );
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

void digit_to_ch_test ( )

/******************************************************************************/
/*
  Purpose:

    DIGIT_TO_CH_TEST tests DIGIT_TO_CH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 January 2015

  Author:

    John Burkardt
*/
{
  char c;
  int i;
  int i2;

  printf ( "\n" );
  printf ( "DIGIT_TO_CH_TEST\n" );
  printf ( "  DIGIT_TO_CH: decimal digit -> character\n" );
  printf ( "\n" );

  for ( i = -2; i <= 11; i++ )
  {
    c = digit_to_ch ( i );
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

void s_len_trim_test ( )

/******************************************************************************/
/*
  Purpose:

    S_LEN_TRIM_TEST tests S_LEN_TRIM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2007

  Author:

    John Burkardt
*/
{
  char s[11];
  int test;

  printf ( "\n" );
  printf ( "S_LEN_TRIM_TEST\n" );
  printf ( "  S_LEN_TRIM reports the length of a string to the last nonblank.\n" );
  printf ( "\n" );
  printf ( "  Here are some strings, and their lengths:\n" );
  printf ( "\n" );

  for ( test = 0; test < 4; test++ )
  {
    if ( test == 0 )
    {
      strcpy ( s, "HELLO" );
    }
    else if ( test == 1 )
    {
      strcpy ( s, "  B la nk" );
    }
    else if ( test == 2 )
    {
      strcpy ( s, " ");
    }
    else if ( test == 3 )
    {
      strcpy ( s, "1234567890" );
    }
    printf ( "  \"%s\"  %d\n", s, s_len_trim ( s )  );
  }

  return;
}
/******************************************************************************/

void s_reverse_test ( )

/******************************************************************************/
/*
  Purpose:

    S_REVERSE_TEST tests S_REVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 January 2010

  Author:

    John Burkardt
*/
{
  char *s = "A man, a plan, a canal, Panama!";
  char *s2;

  printf ( "\n" );
  printf ( "S_REVERSE_TEST\n" );
  printf ( "  S_REVERSE reverses a string.\n" );
  printf ( "\n" );
  printf ( "  Before: \"%s\".\n", s );
  s2 = s_reverse ( s );
  printf ( "  After:  \"%s\".\n", s2 );
 
  return;
}
/******************************************************************************/

void s_scrabble_points_test ( )

/******************************************************************************/
/*
  Purpose:

    S_SCRABBLE_POINTS_TEST tests S_SCRABBLE_POINTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2013

  Author:

    John Burkardt
*/
{
  int i;
  char *s;
  int value;

  printf ( "\n" );
  printf ( "S_SCRABBLE_POINTS_TEST\n" );
  printf ( "  S_SCRABBLE_POINTS returns the value of a string\n" );
  printf ( "  as a Scrabble word.\n" );
  printf ( "\n" );
  printf ( "   I  ----S-------   Value\n" );
  printf ( "\n" );
  for ( i = 1; i <= 12; i++ )
  {
    s = i4_to_month_name ( i );
    value = s_scrabble_points ( s );
    printf ( "  %2d  %9s    %4d\n", i, s, value );
    free ( s );
  }

  return;
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
/******************************************************************************/

void s_to_rot13_test ( )

/******************************************************************************/
/*
  Purpose:

    S_TO_ROT13_TEST tests S_TO_ROT13.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 January 2016

  Author:

    John Burkardt
*/
{
  char s1[80];
  char *s2;
  char *s3;

  printf ( "\n" );
  printf ( "S_TO_ROT13_TEST\n" );
  printf ( "  S_TO_ROT13 applies the ROT13 cipher to a string.\n" );

  printf ( "\n" );
  printf ( "  S2 = S_TO_ROT13 ( S1 ).\n" );
  printf ( "\n" );
  printf ( "  -------------------S1-------------------  -------------------S2-------------------\n" );
  printf ( "\n" );

  strcpy ( s1, "abcdefghijklmnopqrstuvwxyz" );
  s2 = s_to_rot13 ( s1 );
  printf ( "  %-40s  %-40s\n", s1, s2 );
  free ( s2 );

  strcpy ( s1, "Cher" );
  s2 = s_to_rot13 ( s1 );
  printf ( "  %-40s  %-40s\n", s1, s2 );
  free ( s2 );

  strcpy ( s1, "James Thurston Howell III" );
  s2 = s_to_rot13 ( s1 );
  printf ( "  %-40s  %-40s\n", s1, s2 );
  free ( s2 );

  strcpy ( s1, "The bill is $1,205,837.49 so pay now!" );
  s2 = s_to_rot13 ( s1 );
  printf ( "  %-40s  %-40s\n", s1, s2 );
  free ( s2 );

  printf ( "\n" );
  printf ( "  S2 = S_TO_ROT13 ( S1 ).\n" );
  printf ( "  S3 = S_TO_ROT13 ( S2 ).\n" );
  printf ( "\n" );
  printf ( "  -------------------S1-------------------  -------------------S3-------------------\n" );
  printf ( "\n" );

  strcpy ( s1, "abcdefghijklmnopqrstuvwxyz" );
  s2 = s_to_rot13 ( s1 );
  s3 = s_to_rot13 ( s2 );
  printf ( "  %-40s  %-40s\n", s1, s3 );
  free ( s2 );
  free ( s3 );

  strcpy ( s1, "Cher" );
  s2 = s_to_rot13 ( s1 );
  s3 = s_to_rot13 ( s2 );
  printf ( "  %-40s  %-40s\n", s1, s3 );
  free ( s2 );
  free ( s3 );

  strcpy ( s1, "James Thurston Howell III" );
  s2 = s_to_rot13 ( s1 );
  s3 = s_to_rot13 ( s2 );
  printf ( "  %-40s  %-40s\n", s1, s3 );
  free ( s2 );
  free ( s3 );

  strcpy ( s1, "The bill is $1,205,837.49 so pay now!" );
  s2 = s_to_rot13 ( s1 );
  s3 = s_to_rot13 ( s2 );
  printf ( "  %-40s  %-40s\n", s1, s3 );
  free ( s2 );
  free ( s3 );

  return;
}
/******************************************************************************/

void s_word_count_test ( )

/******************************************************************************/
/*
  Purpose:

    S_WORD_COUNT_TEST tests S_WORD_COUNT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2007

  Author:

    John Burkardt
*/
{
  char s[40];

  printf ( "\n" );
  printf ( "S_WORD_COUNT_TEST\n" );
  printf ( "  S_WORD_COUNT counts the words in a string\n" );
  printf ( "\n" );
  printf ( "  STRING                      Words\n" );
  printf ( "\n" );
 
  strcpy ( s, "?" );
  printf ( "  %32s  %d\n", s, s_word_count ( s ) );

  strcpy ( s, "A man, a plan, a canal - Panama!" );
  printf ( "  %32s  %d\n", s, s_word_count ( s ) );

  strcpy ( s, " justone!word,-@#$ " );
  printf ( "  %32s  %d\n", s, s_word_count ( s ) );

  strcpy ( s, "How about a day in the park?" );
  printf ( "  %32s  %d\n", s, s_word_count ( s ) );

  return;
}
