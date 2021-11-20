# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "calpak.h"

/******************************************************************************/

char ch_cap ( char ch )

/******************************************************************************/
/*
  Purpose:

    CH_CAP capitalizes a single character.

  Discussion:

    This routine should be equivalent to the library "toupper" function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 July 1998

  Author:

    John Burkardt

  Parameters:

    Input, char CH, the character to capitalize.

    Output, char CH_CAP, the capitalized character.
*/
{
  if ( 97 <= ch && ch <= 122 )
  {
    ch = ch - 32;
  }

  return ch;
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

double datenum_to_jed ( double dn )

/******************************************************************************/
/*
  Purpose:

    DATENUM_TO_JED converts a MATLAB date number to a JED.

  Discussion:

    The MATLAB "datenum" function accepts a string defining
    a date and returns a MATLAB date number:

      dn = datenum ( 'Aug 17 1939' )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double DN, a MATLAB date number.

    Output, double JED, the Julian Ephemeris Date.
*/
{
  double jed;

  jed = dn + epoch_to_jed_datenum ( );

  return jed;
}
/******************************************************************************/

void datenum_to_jed_test ( )

/******************************************************************************/
/*
  Purpose:

    DATENUM_TO_JED_TEST tests DATENUM_TO_JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt
*/
{
  double date_num;
  int i;
  double jed1;
  double jed3;
  double jed_epoch;

  printf ( "\n" );
  printf ( "DATENUM_TO_JED_TEST\n" );
  printf ( "  DATENUM_TO_JED: Matlab DATENUM -> JED.\n" );
  printf ( "\n" );
  printf ( "  JED (in)    DATENUM             JED (out)\n" );
  printf ( "\n" );

  jed_epoch = epoch_to_jed_datenum ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      date_num = jed_to_datenum ( jed1 );
      jed3 = datenum_to_jed ( date_num );

      printf ( "  %11.2f  %11.2f  %11.2f\n", jed1, date_num, jed3 );
    }
  }

  return;
}
/******************************************************************************/

void datenum_values ( int *n_data, int *y, int *m, int *d, double *date_num )

/******************************************************************************/
/*
  Purpose:

    DATENUM_VALUES returns the MATLAB DATENUM for various dates.

  Discussion:

    The MATLAB datenum function returns a numeric value for a given date,
    which is 1 for the (fictitious) date 1 January 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 December 2015

  Author:

    John Burkardt

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0
    before the first call.  On each call, the routine increments N_DATA by 1,
    and returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, int *Y, *M, *D, the Common Era date.

    Output, double *DATE_NUM, the datenum.
*/
{
# define N_MAX 11

  static int d_vec[N_MAX] = {
     1,
     1,
     1,
     1,
    17,
     9,
    10,
    12,
     6,
    25,
     1 };

  static double date_num_vec[N_MAX] = {
         1.0,
       367.0,
     36526.0,
    365244.0,
    708434.0,
    710284.0,
    713023.0,
    718199.0,
    723186.0,
    729080.0,
    730486.0 };

  static int m_vec[N_MAX] = {
     1,
     1,
     1,
     1,
     8,
     9,
     3,
     5,
     1,
     2,
     1 };

  static int y_vec[N_MAX] = {
        0,
        1,
      100,
     1000,
     1939,
     1944,
     1952,
     1966,
     1980,
     1996,
     2000 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *y = 0;
    *m = 0;
    *d = 0;
    *date_num = 0;
  }
  else
  {
    *y = y_vec[*n_data-1];
    *m = m_vec[*n_data-1];
    *d = d_vec[*n_data-1];
    *date_num = date_num_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void datenum_values_test ( )

/******************************************************************************/
/*
  Purpose:

    DATENUM_VALUES_TEST tests DATENUM_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 December 2017

  Author:

    John Burkardt
*/
{
  int d;
  double date_num;
  int m;
  int n_data;
  int y;

  printf ( "\n" );
  printf ( "DATENUM_VALUES_TEST:\n" );
  printf ( "  DATENUM_VALUES returns values of \n" );
  printf ( "  the MATLAB datenum for a given Y/M/D date\n" );
  printf ( "\n" );
  printf ( "     Y     M     D  DATENUM\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    datenum_values ( &n_data, &y, &m, &d, &date_num );

    if ( n_data == 0 )
    {
      break;
    }
    printf ( "  %4d  %4d  %4d  %11.2f\n", y, m, d, date_num );
  }
  return;
}
/******************************************************************************/

void day_borrow_common ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DAY_BORROW_COMMON borrows days from months in a Common date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, a year, month, and day
    representing a date.  On input, D might be negative.  On output,
    M should have decreased by one month, and D gone up by the
    number of days in the month we "cashed in".  Y may be affected
    if the input value of M was 1.
*/
{
  int days;

  while ( *d <= 0 )
  {
    *m = *m - 1;

    month_borrow_common ( y, m );

    days = month_length_common ( *y, *m );

    *d = *d + days;
  }

  return;
}
/******************************************************************************/

void day_borrow_gregorian ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DAY_BORROW_GREGORIAN borrows days from months in a Gregorian date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, a year, month, and day
    representing a date.  On input, D might be negative.  On output,
    M should have decreased by one month, and D gone up by the
    number of days in the month we "cashed in".  Y may be affected
    if the input value of M was 1.
*/
{
  int days;

  while ( *d <= 0 )
  {
    *m = *m - 1;

    month_borrow_gregorian ( y, m );

    days = month_length_gregorian ( *y, *m );

    *d = *d + days;
  }
  return;
}
/******************************************************************************/

void day_borrow_julian ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DAY_BORROW_JULIAN borrows days from months in a Julian date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Parameters:

    Input/output, int &Y, &M, &D, a year, month, and day
    representing a date.  On input, D might be negative.  On output,
    M should have decreased by one month, and D gone up by the
    number of days in the month we "cashed in".  Y may be affected
    if the input value of M was 1.
*/
{
  int days;

  while ( *d <= 0 )
  {
    *m = *m - 1;

    month_borrow_julian ( y, m );

    days = month_length_julian ( *y, *m );

    *d = *d + days;
  }
  return;
}
/******************************************************************************/

void day_carry_common ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DAY_CARRY_COMMON carries days to months in a Common date.

  Discussion:

    While ( number of days in M ) < D:
      decrease the day D by the number of days in the month M;
      increase M by 1;
      if necessary, adjust Y.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2010

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, int *D, the YMD date.
    On output, D is between 1 and the number of days in M.
*/
{
  int days;
/*
  If the date is in the transition month, deflate it,
  so we can perform ordinary arithmetic.
*/
  deflate_common ( y, m, d );

  days = month_length_common ( *y, *m );

  while ( days < *d )
  {
    *d = *d - days;
    *m = *m + 1;
    days = month_length_common ( *y, *m );
/*
  Make sure the month is not too big.
*/
    month_carry_common ( y, m );
  }
/*
  If the date is in the transition month, inflate it.
*/
  inflate_common ( y, m, d );

  return;
}
/******************************************************************************/

void day_carry_gregorian ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DAY_CARRY_GREGORIAN carries days to months in a Gregorian date.

  Discussion:

    While ( number of days in M ) < D:
      decrease the day D by the number of days in the month M;
      increase M by 1;
      if necessary, adjust Y.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date.
    On output, D is between 1 and the number of days in M.
*/
{
  int days;

  days = month_length_gregorian ( *y, *m );

  while ( days < *d )
  {
    *d = *d - days;
    *m = *m + 1;
    days = month_length_gregorian ( *y, *m );
/*
  Make sure the month is not too big.
*/
    month_carry_gregorian ( y, m );
  }
  return;
}
/******************************************************************************/

void day_carry_julian ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DAY_CARRY_JULIAN carries days to months in a Julian date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date.
    On output, D is between 1 and the number of days in M.
*/
{
  int days;

  days = month_length_julian ( *y, *m );

  while ( days < *d )
  {
    *d = *d - days;
    *m = *m + 1;
    days = month_length_julian ( *y, *m );
/*
  Make sure the month is not too big.
*/
    month_carry_julian ( y, m );
  }
  return;
}
/******************************************************************************/

void day_list_common ( int y1, int m1, int d1, int y2, int m2, int d2 )

/******************************************************************************/
/*
  Purpose:

    DAY_LIST_COMMON prints a list of days between two dates.

  Discussion:

    Given the dates of September 25, 2005 and October 2, 2005,
    the routine should print out:

    Sun, 25 Sep 2005 
    Mon, 26 Sep 2005 
    Tue, 27 Sep 2005 
    Wed, 28 Sep 2005 
    Thu, 29 Sep 2005 
    Fri, 30 Sep 2005 
    Sat,  1 Oct 2005 
    Sun,  2 Oct 2005 

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y1, M1, D1, the first date.

    Input, int Y2, M2, D2, the second date.
*/
{
  char cmp;
  int d;
  double f;
  int m;
  char *m_name;
  int w;
  char *w_name;
  int y;

  y = y1;
  m = m1;
  d = d1;
  f = 0.0;

  cmp = '<';
  
  while ( cmp != '>' )
  {
    w = ymdf_to_weekday_common ( y, m, d, f );

    w_name = weekday_to_name_common3 ( w );

    m_name = month_to_month_name_common3 ( m );

    printf ( "%s, %2d %s %d\n", w_name, d, m_name, y );

    ymdf_next_common ( y, m, d, f, &y, &m, &d, &f );

    cmp = ymdf_compare ( y, m, d, f, y2, m2, d2, f );

    free ( m_name );
    free ( w_name );
  }

  return;
}
/******************************************************************************/

void day_list_common_test ( )

/******************************************************************************/
/*
  Purpose:

    DAY_LIST_COMMON_TEST tests DAY_LIST_COMMON.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2017

  Author:

    John Burkardt
*/
{
  int d1;
  int d2;
  int m1;
  int m2;
  char *s;
  int y1;
  int y2;

  d1 = 1;
  d2 = 31;
  m1 = 9;
  m2 = 12;
  y1 = 2012;
  y2 = 2012;

  printf ( "\n" );
  printf ( "DAY_LIST_COMMON_TEST\n" );
  printf ( "  DAY_LIST_COMMON prints a list of days between\n" );
  printf ( "  two given YMD dates in the common calendar.\n" );
  printf ( "\n" );

  s = ymd_to_s_common ( y1, m1, d1 );
  printf ( "  Initial date: %s\n", s );
  free ( s );

  s = ymd_to_s_common ( y2, m2, d2 );
  printf ( "  Final date:   %s\n", s );
  free ( s );

  printf ( "\n" );

  day_list_common ( y1, m1, d1, y2, m2, d2 );

  return;
}
/******************************************************************************/

void deflate_common ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    DEFLATE_COMMON "deflates" dates in the Common Calendar transition month.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date.
*/
{
  if ( *y == 1582 )
  {
    if ( *m == 10 )
    {
      if ( 15 <= *d )
      {
        *d = *d - 10;
      }
    }
  }
  return;
}
/******************************************************************************/

char digit_to_ch ( int i )

/******************************************************************************/
/*
  Purpose:

    DIGIT_TO_CH returns the base 10 digit character corresponding to a digit.

  Example:

     I     C
   -----  ---
     0    '0'
     1    '1'
   ...    ...
     9    '9'  
    10    '*'
   -83    '*'

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2003

  Author:

    John Burkardt

  Parameters:

    Input, int I, the digit, which should be between 0 and 9.

    Output, char DIGIT_TO_CH, the appropriate character '0' 
    through '9' or '*'.
*/
{
  char c;

  if ( 0 <= i && i <= 9 )
  {
    c = '0' + i;
  }
  else
  {
    c = '*';
  }

  return c;
}
/******************************************************************************/

void easter_gregorian_ds ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_DS computes the month and day of Easter for a Common year.

  Example:

    Input:

      Y = 2000

    Output:

      M = 4
      D = 23

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2017

  Author:

    John Burkardt

  Reference:

    Peter Duffett-Smith,
    Practical Astronomy With Your Calculator,
    Third Edition,
    Cambridge University Press, 1996,
    ISBN: 0-521-35699-7,
    LC: QB62.5.D83.

  Parameters:

    Input, int Y, the year, which must be 1583 or greater.
    (The formula is only valid for years after the Gregorian calendar
    was adopted.)

    Output, int *M, *D, the month and day of Easter.
*/
{
  int a;
  int b;
  int c;
  int dd;
  int e;
  int f;
  int g;
  int h;
  int i;
  int k;
  int l;
  int mm;

  if ( y <= 0 )
  {
    *m = -1;
    *d = -1;
    return;
  }

  a = year_to_golden_number ( y );

  a = a - 1;

  b = y / 100;
  c = y % 100;

  dd = b / 4;
  e = b % 4;

  f = ( b + 8 ) / 25;
  g = ( b - f + 1 ) / 3;
  h = ( 19 * a + b - dd - g + 15 ) % 30;

  i = c / 4;
  k = c % 4;

  l = ( 32 + 2 * e + 2 * i - h - k ) % 7;
  mm = ( a + 11 * h + 22 * l ) / 451;

  *m = ( h + l - 7 * mm + 114 ) / 31;
  *d = ( ( h + l - 7 * mm + 114 ) % 31 ) + 1;

  return;
}
/******************************************************************************/

void easter_gregorian_ds_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_DS_TEST tests EASTER_GREGORIAN_DS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2017

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_GREGORIAN_DS_TEST\n" );
  printf ( "  For the Gregorian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_GREGORIAN_DS uses Duffett-Smith's algorithm.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT: %s\n", s );
    free ( s );

    easter_gregorian_ds ( y, &m, &d );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  COMPUTED: %s\n", s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void easter_gregorian_egr ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_EGR computes the month and day of Easter for a Common year.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 June 2010

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm O,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, page 375.

  Parameters:

    Input, int Y, the year.

    Output, int *M, *D, the month and day of Easter.
*/
{
  int c;
  int e;
  int g;
  int h;
  int n;
  int p;
  int q;
  int r;
  int s;
  int u;
  int vp;

  if ( y <= 0 )
  {
    *m = -1;
    *d = -1;
    return;
  }

  p = y + ( y / 4 ) - ( y / 100 ) + ( y / 400 ) - 1;
  n = 7 - ( p % 7 );
  h = y / 100;
  q = h - h / 4;
  g = 1 + ( y % 19 );
  e = ( 57 + 11 * g - q + ( h - ( h - 17 ) / 25 ) / 3 ) % 30;
  u = ( 53 - e ) % 30;
  vp = ( g - 1 + 11 * u ) / 319;
  r = 22 + u - vp;
  c = i4_wrap ( r + 3, 1, 7 );
  s = r + ( ( 7 + n - c ) % 7 );

  *m = 3 + ( s / 32 );
  *d = i4_wrap ( s, 1, 31 );

  return;
}
/******************************************************************************/

void easter_gregorian_egr_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_EGR_TEST tests EASTER_GREGORIAN_EGR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2017

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_GREGORIAN_EGR_TEST\n" );
  printf ( "  For the Gregorian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_GREGORIAN_EGR uses Richards's algorithm #1.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT: %s\n", s );
    free ( s );

    easter_gregorian_egr ( y, &m, &d );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  COMPUTED: %s\n", s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void easter_gregorian_egr2 ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_EGR2 computes the month and day of Easter for a Common year.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2018

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm P,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, page 376.

  Parameters:

    Input, int Y, the year.

    Output, int *M, *D, the month and day of Easter.
*/
{
  int a;
  int b;
  int c;
  int dd;
  int e;
  int s;

  if ( y <= 0 )
  {
    *m = -1;
    *d = -1;
    return;
  }

  a = y / 100;
  b = a - ( a / 4 );
  c = ( y % 19 );
  dd = ( 15 + 19 * c + b - ( a - ( a - 17 ) / 25 ) / 3 ) % 30;
  e = dd - ( c + 11 * dd ) / 319;
  s = 22 + e + ( 140004 - y - ( y / 4 ) + b - e ) % 7;

  *m = 3 + ( s / 32 );
  *d = i4_wrap ( s, 1, 31 );

  return;
}
/******************************************************************************/

void easter_gregorian_egr2_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_EGR2_TEST tests EASTER_GREGORIAN_EGR2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2018

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_GREGORIAN_EGR2_TEST\n" );
  printf ( "  For the Gregorian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_GREGORIAN_EGR uses Richards's algorithm #2.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT: %s\n", s );
    free ( s );

    easter_gregorian_egr2 ( y, &m, &d );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  COMPUTED: %s\n", s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void easter_gregorian_knuth ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_KNUTH computes the month and day of Easter for a Gregorian year.

  Discussion:

    Knuth attributes the algorithm to Aloysius Lilius and Christopher Clavius
    in the late 16th century.  The algorithm is for use with the Gregorian
    calendar.

  Example:

    Input:

      Y = 2000

    Output:

      M = 4
      D = 23

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 January 2018

  Author:

    John Burkardt

  Reference:

    Donald Knuth,
    The Art of Computer Programming,
    Volume 1: Fundamental Algorithms,
    Addison Wesley, 1968, pages 155-156.

    Donald Knuth,
    The Calculation of Easter,
    Communications of the ACM,
    Volume 5, Number 4, April 1962, pages 209-210.

    Thomas O'Beirne,
    Puzzles and Paradoxes,
    Oxford University Press, 1965, chapter 10.

  Parameters:

    Input, int Y, the year, which must be 1583 or greater.
    (The formula is only valid for years after the Gregorian calendar
    was adopted.)

    Output, int *M, *D, the month and day of Easter.
*/
{
  int c;
  int dd;
  int e;
  int g;
  int n;
  int x;
  int z;

  if ( y <= 0 )
  {
    *m = -1;
    *d = -1;
    return;
  }
/*
  E1: Set the golden number of the year in the 19-year Metonic cycle.
*/
  g = year_to_golden_number ( y );
/*
  E2: Set the century.
*/
  c = ( y / 100 ) + 1;
/*
  E3: Corrections.
  X is the number of years divisible by 100 in which leap year was dropped.
  Z is a special correction to synchronize Easter with the moon's orbit.
*/
  x = ( 3 * c / 4 ) - 12;
  z = ( 8 * c + 5 ) / 25 - 5;
/*
  E4: Find Sunday.
*/
  dd = ( 5 * y / 4 ) - x - 10;
/*
  E5: Epact
*/
  e = i4_modp ( 11 * g + 20 + z - x, 30 );

  if ( ( e == 25 && 11 < g ) || ( e == 24 ) )
  {
    e = e + 1;
  }
/*
  E6: Find the full moon.
*/
  n = 44 - e;
  if ( n < 21 )
  {
    n = n + 30;
  }
/*
  E7: Advance to Sunday.
*/
  n = n + 7 - ( ( dd + n ) % 7 );
/*
  E8: Get month.
*/
  if ( 31 < n )
  {
    *d = n - 31;
    *m = 4;
  }
  else
  {
    *d = n;
    *m = 3;
  }

  return;
}
/******************************************************************************/

void easter_gregorian_knuth_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_KNUTH_TEST tests EASTER_GREGORIAN_KNUTH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2018

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_GREGORIAN_KNUTH_TEST\n" );
  printf ( "  For the Gregorian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_GREGORIAN_KNUTH uses Knuth's algorithm.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT: %s\n", s );
    free ( s );

    easter_gregorian_knuth ( y, &m, &d );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  COMPUTED: %s\n", s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void easter_gregorian_stewart ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_STEWART computes the month and day of Easter for a Gregorian year.

  Example:

    Y = 2001

    A = 6
    B = 20
    C = 1
    DD = 5
    E = 0
    G = 6
    H = 18
    MM = 0
    J = 0
    K = 1
    L = 6
    M = 4
    D = 15

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 January 2018

  Author:

    John Burkardt

  Reference:

    Thomas O'Beirne,
    Puzzles and Paradoxes,
    Oxford University Press, 1965.

    Ian Stewart,
    Easter is a Quasicrystal,
    Scientific American,
    March 2001, pages 80-83.

  Parameters:

    Input, int Y, the year.

    Output, int *M, *D, the month and day of Easter.
*/
{
  int a;
  int b;
  int c;
  int dd;
  int e;
  int g;
  int h;
  int j;
  int k;
  int l;
  int mm;

  a = ( y % 19 );
  b = y / 100;
  c = ( y % 100 );
  dd = b / 4;
  e = ( b % 4 );
  g = ( 8 * b + 13 ) / 25;
  h = ( ( 19 * a + b - dd - g + 15 ) % 30 );
  mm = ( a + 11 * h ) / 319;
  j = c / 4;
  k = ( c % 4 );
  l = ( ( 2 * e + 2 * j - k - h + mm + 32 ) % 7 );

  *m = ( h - mm + l + 90 ) / 25;
  *d = ( ( h - mm + l + ( *m ) + 19 ) % 32 );

  return;
}
/******************************************************************************/

void easter_gregorian_stewart_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_GREGORIAN_STEWART_TEST tests EASTER_GREGORIAN_STEWART.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2018

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_GREGORIAN_STEWART_TEST\n" );
  printf ( "  For the Gregorian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_GREGORIAN_STEWART uses Stewart's algorithm.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT: %s\n", s );
    free ( s );

    easter_gregorian_stewart ( y, &m, &d );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  COMPUTED: %s\n", s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void easter_julian_egr ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_JULIAN_EGR computes the date of Easter in the Julian calendar.

  Discussion:

    This computation for the date of Easter uses the Dionysian
    canon that applied to the Julian calendar.  The determination
    of the date of Easter changed at the same time that the calendar
    was modified to use the Gregorian system.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 January 201i

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm M,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, page 365.

  Parameters:

    Input, int Y, the year.

    Output, int *M, *D, the month and day of the Julian 
    calendar on which Easter occurs.
*/
{
  int c;
  int e;
  int n;
  int p;
  int r;
  int s;

  if ( y <= 0 )
  {
    *m = -1;
    *d = -1;
    return;
  }

  p = y + ( y / 4 ) + 4;
  n = 7 - ( p % 7 );

  e = year_to_epact_julian ( y );

  r = 22 + ( ( 53 - e ) % 30 );

  c = i4_wrap ( r + 3, 1, 7 );

  s = r + ( ( 7 + n - c ) % 7 );

  *m = 3 + ( s / 32 );
/*
  Use wrapping so that 1 <= D <= 31.
*/
  *d = i4_wrap ( s, 1, 31 );

  return;
}
/******************************************************************************/

void easter_julian_egr_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_JULIAN_EGR_TEST tests EASTER_JULIAN_EGR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 January 2018

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    27,    19,   11,  30,   15,    5,   27,   11,    1,   23 };
  double f;
  int i;
  double jed;
  int m;
  int m_test[10] = {
    4,     4,    4,    4,    4,    5,    4,    4,    5,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_JULIAN_EGR_TEST\n" );
  printf ( "  For the Julian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_JULIAN_EGR uses Richards''s algorithm #1.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];
    f = 0.5;

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT (Gregorian): %s\n", s );
    free ( s );

    jed = ymdf_to_jed_gregorian ( y, m, d, f );
    jed_to_ymdf_julian ( jed, &y, &m, &d, &f );

    s = ymd_to_s_julian ( y, m, d );
    printf ( "  CORRECT (Julian):    %s\n", s );
    free ( s );

    easter_julian_egr ( y, &m, &d );
    s = ymd_to_s_julian ( y, m, d );
    printf ( "  COMPUTED             %s\n", s);
    free ( s );
  }

  return;
}
/******************************************************************************/

void easter_julian_egr2 ( int y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    EASTER_JULIAN_EGR2 computes the date of Easter in the Julian calendar.

  Discussion:

    This computation for the date of Easter uses the Dionysian
    canon that applied to the Julian calendar.  The determination
    of the date of Easter changed at the same time that the calendar
    was modified to use the Gregorian system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2018

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm N,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, page 365.

  Parameters:

    Input, int Y, the year.

    Output, int *M, *D, the month and day of the Julian calendar
    on which Easter occurs.
*/
{
  int a;
  int b;
  int s;

  if ( y <= 0 )
  {
    *m = -1;
    *d = -1;
    return;
  }

  a = year_to_golden_number ( y );
  a = a - 1;

  b = 22 + ( ( 225 - 11 * a ) % 30 );
  s = b + ( ( 56 + 6 * y - ( y / 4 ) - b ) % 7 );

  *m = 3 + ( s / 32 );
/*
  Use wrapping to ensure that 1 <= D <= 31.
*/
  *d = i4_wrap ( s, 1, 31 );

  return;
}
/******************************************************************************/

void easter_julian_egr2_test ( )

/******************************************************************************/
/*
  Purpose:

    EASTER_JULIAN_EGR2_TEST tests EASTER_JULIAN_EGR2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 January 2018

  Author:

    John Burkardt
*/
{
  int d;
  int d_test[10] = {
    27,    19,   11,  30,   15,    5,   27,   11,    1,   23 };
  double f;
  int i;
  double jed;
  int m;
  int m_test[10] = {
    4,     4,    4,    4,    4,    5,    4,    4,    5,    4 };
  const int ntest = 10;
  char *s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  printf ( "\n" );
  printf ( "EASTER_JULIAN_EGR2_TEST\n" );
  printf ( "  For the Julian calendar,\n" );
  printf ( "  for a given year, compute the day and month of Easter.\n" );
  printf ( "  EASTER_JULIAN_EGR2 uses Richards''s algorithm #2.\n" );
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];
    f = 0.5;

    printf ( "\n" );
    s = ymd_to_s_gregorian ( y, m, d );
    printf ( "  CORRECT (Gregorian): %s\n", s );
    free ( s );

    jed = ymdf_to_jed_gregorian ( y, m, d, f );
    jed_to_ymdf_julian ( jed, &y, &m, &d, &f );

    s = ymd_to_s_julian ( y, m, d );
    printf ( "  CORRECT (Julian):    %s\n", s );
    free ( s );

    easter_julian_egr2 ( y, &m, &d );
    s = ymd_to_s_julian ( y, m, d );
    printf ( "  COMPUTED             %s\n", s);
    free ( s );
  }

  return;
}
/******************************************************************************/

double epoch_to_jed_akbar ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_AKBAR: epoch of the Akbar calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_AKBAR, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2289425.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_alexandrian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ALEXANDRIAN: epoch of the Alexandrian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ALEXANDRIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1713262.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_armenian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ARMENIAN: epoch of the Armenian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ARMENIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1922867.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_bahai ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_BAHAI: epoch of the Bahai calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_BAHAI, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2394646.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_bessel ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_BESSEL: epoch of the Bessel calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_BESSEL, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2415020.31352;

  return value;
}
/******************************************************************************/

double epoch_to_jed_chinese ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_CHINESE: epoch of the Chinese calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_CHINESE, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 758325.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_common ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_COMMON: epoch of the Common calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_COMMON, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1721423.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_coptic ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_COPTIC: epoch of the Coptic calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_COPTIC, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1825029.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_datenum ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_DATENUM: epoch of the MATLAB DATENUM calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_DATENUM, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1721058.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_deccan ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_DECCAN: epoch of the Fasli Deccan calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_DECCAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1936747.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_eg_civil ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_EG_CIVIL: epoch of the Egyptian Civil calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_EG_CIVIL, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1448637.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_eg_lunar ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_EG_LUNAR: epoch of the Egyptian Lunar calendar as a JED.

  Discussion:

    This is just a fake value, making the Egyptian Lunar calendar start
    at the same data as the Egyptian Civil calendar.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_EG_LUNAR, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1448637.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_english ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ENGLISH: epoch of the English calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ENGLISH, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1721423.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_ethiopian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ETHIOPIAN: epoch of the Ethiopian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ETHIOPIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1724220.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_gps ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_GPS: epoch of the GPS calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_GPS, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2444244.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_greek ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_GREEK: epoch of the Greek calendar as a JED.

  Discussion:

    The Greek Olympiad calendar began on 9 July 776 BC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_GREEK, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1438178.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_gregorian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_GREGORIAN: epoch of the Gregorian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_GREGORIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1721425.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_hebrew ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_HEBREW: epoch of the Hebrew calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_HEBREW, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 347998.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_hindu_lunar ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_HINDU_LUNAR: epoch of the Hindu lunar calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_HINDU_LUNAR, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1741959.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_hindu_solar ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_HINDU_SOLAR: epoch of the Hindu solar calendar as a JED.

  Discussion:

    This is the beginning of the Kali Yuga era.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_HINDU_SOLAR, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 588465.75;

  return value;
}
/******************************************************************************/

double epoch_to_jed_islamic_a ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ISLAMIC_A: epoch of the Islamic A calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ISLAMIC_A, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1948438.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_islamic_b ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ISLAMIC_B: epoch of the Islamic B calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ISLAMIC_B, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1948439.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_jed ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_JED: epoch of the JED calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_JED, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 0.0;

  return value;
}
/******************************************************************************/

double epoch_to_jed_jelali ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_JELALI: epoch of the Jelali calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_JELALI, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2114872.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_julian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_JULIAN: epoch of the Julian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_JULIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1721423.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_khwarizmian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_KHWARIZMIAN: epoch of the Khwarizmian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_KHWARIZMIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1952067.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_macedonian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_MACEDONIAN: epoch of the Macedonian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_MACEDONIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1607708.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_mayan_long ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_MAYAN_LONG: epoch of the Mayan long count calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_MAYAN_LONG, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 584282.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_mjd ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_MJD: epoch of the MJD calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_MJD, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2400000.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_nyt ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_NYT: epoch of the NYT calendar as a JED.

  Discussion:

    The "epoch" of the NYT calendar is the mythical date when issue "0"
    would have been printed, namely, a tad past midnight, 17 September 1851.

    Volume #1, Issue #1 was printed on 18 September 1851.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_NYT, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2397382.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_nyt_50000 ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_NYT_50000: epoch of the NYT 50000 calendar as a JED.

  Discussion:

    The "epoch" of the NYT 50000 calendar is the date when issue "50,000"
    was printed.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_NYT_50000, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

 value = 2449790.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_persian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_PERSIAN: epoch of the Persian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_PERSIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1952062.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_persian_solar ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_PERSIAN_SOLAR: epoch of the Persian solar calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_PERSIAN_SOLAR, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1948320.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_rd ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_RD: epoch of the RD calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_RD, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1721425.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_republican ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_REPUBLICAN: epoch of the Republican calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_REPUBLICAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2375839.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_roman ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ROMAN: epoch of the Roman calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

     10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ROMAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1446389.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_saka ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_SAKA: epoch of the Saka calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_SAKA, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1749994.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_soor_san ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_SOOR_SAN: epoch of the Fasli Soor San calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_SOOR_SAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1940351.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_syrian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_SYRIAN: epoch of the Syrian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_SYRIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1607738.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_unix ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_UNIX: epoch of the UNIX calendar as a JED.

  Discussion:

    The UNIX Epoch is taken to be the first second of 1 January 1970.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double JED, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2440587.50;

  return value;
}
/******************************************************************************/

double epoch_to_jed_y2k ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_Y2K: epoch of the Y2K calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_Y2K, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 2451544.5;

  return value;
}
/******************************************************************************/

double epoch_to_jed_zoroastrian ( )

/******************************************************************************/
/*
  Purpose:

    EPOCH_TO_JED_ZOROASTRIAN: epoch of the Zoroastrian calendar as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double EPOCH_TO_JED_ZOROASTRIAN, the Julian Ephemeris Date of the epoch.
*/
{
  double value;

  value = 1862836.5;

  return value;
}
/******************************************************************************/

double gps_to_jed ( int c, int w, double s )

/******************************************************************************/
/*
  Purpose:

    GPS_TO_JED converts a GPS date to a JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int C, int W, double S, 
    the GPS cycle/week/second date.

    Output, double GPS_TO_JED, the corresponding Julian Ephemeris Date.
*/
{
  double d;
  double jed;
  double jed_epoch;

  jed_epoch = epoch_to_jed_gps ( );

  d = ( double ) ( 7 * ( 1024 * c + w ) ) + s / ( 24.0 * 60.0 * 60.0 );

  jed = jed_epoch + d;

  return jed;
}
/******************************************************************************/

void gps_to_jed_test ( )

/******************************************************************************/
/*
  Purpose:

    GPS_TO_JED_TEST tests GPS_TO_JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 December 2017

  Author:

    John Burkardt
*/
{
  int c2;
  int i;
  double jed_epoch;
  double jed1;
  double jed3;
  double sec2;
  int w2;

  printf ( "\n" );
  printf ( "GPS_TO_JED_TEST\n" );
  printf ( "  GPS_TO_JED: GPS -> JED.\n" );
  printf ( "\n" );
  printf ( "   JED (in)       GPS (C/W/S)                   JED (out)\n" );
  printf ( "\n" );

  jed_epoch = epoch_to_jed_gps ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      jed_to_gps ( jed1, &c2, &w2, &sec2 );

      jed3 = gps_to_jed ( c2, w2, sec2 );

      printf ( "  %11.2f  %d/%d/%11.2f (GPS)  %11.2f\n", jed1, c2, w2, sec2, jed3 );
    }
  }

  return;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_modp ( int i, int j )

/******************************************************************************/
/*
  Purpose:

    I4_MODP returns the nonnegative remainder of I4 division.

  Discussion:

    If
      NREM = I4_MODP ( I, J )
      NMULT = ( I - NREM ) / J
    then
      I = J * NMULT + NREM
    where NREM is always nonnegative.

    The MOD function computes a result with the same sign as the
    quantity being divided.  Thus, suppose you had an angle A,
    and you wanted to ensure that it was between 0 and 360.
    Then mod(A,360) would do, if A was positive, but if A
    was negative, your result would be between -360 and 0.

    On the other hand, I4_MODP(A,360) is between 0 and 360, always.

  Example:

        I         J     MOD  I4_MODP   I4_MODP Factorization

      107        50       7       7    107 =  2 *  50 + 7
      107       -50       7       7    107 = -2 * -50 + 7
     -107        50      -7      43   -107 = -3 *  50 + 43
     -107       -50      -7      43   -107 =  3 * -50 + 43

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 January 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, the number to be divided.

    Input, int J, the number that divides I.

    Output, int I4_MODP, the nonnegative remainder when I is
    divided by J.
*/
{
  int value;

  if ( j == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4_MODP - Fatal error!\n" );
    fprintf ( stderr, "  I4_MODP ( I, J ) called with J = %d\n", j );
    exit ( 1 );
  }

  value = i % j;

  if ( value < 0 )
  {
    value = value + abs ( j );
  }

  return value;
}
/******************************************************************************/

void i4_modp_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_MODP_TEST tests I4_MODP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 July 2010

  Author:

    John Burkardt
*/
{
# define TEST_NUM 4

  int ndivid[TEST_NUM] = { 50, -50, 50, -50 };
  int nmult;
  int nrem;
  int number[TEST_NUM] = { 107, 107, -107, -107 };
  int test;

  printf ( "\n" );
  printf ( "I4_MODP_TEST\n" );
  printf ( "  I4_MODP factors a number\n" );
  printf ( "  into a multiple and a remainder.\n" );
  printf ( "\n" );
  printf ( "    Number   Divisor  Multiple Remainder\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    nrem = i4_modp ( number[test], ndivid[test] );
    nmult = number[test] / ndivid[test];

    printf ( "  %10d  %10d  %10d  %10d\n",
      number[test], ndivid[test], nmult, nrem );
  }

  printf ( "\n" );
  printf ( "  Repeat using C percent operator:\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    nrem = ( number[test] % ndivid[test] );
    nmult = number[test] / ndivid[test];

    printf ( "  %10d  %10d  %10d  %10d\n",
      number[test], ndivid[test], nmult, nrem );
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

int i4_normal_ab ( double a, double b, int *seed )

/******************************************************************************/
/*
  Purpose:

    I4_NORMAL_AB returns a scaled pseudonormal I4.

  Discussion:

    The normal probability distribution function (PDF) is sampled,
    with mean A and standard deviation B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 July 2006

  Author:

    John Burkardt

  Parameters:

    Input, double A, the mean of the PDF.

    Input, double B, the standard deviation of the PDF.

    Input/output, int *SEED, a seed for the random number generator.

    Output, int I4_NORMAL_AB, a sample of the normal PDF.
*/
{
  double r1;
  double r2;
  const double r8_pi = 3.141592653589793;
  int value;
  double x;

  r1 = r8_uniform_01 ( seed );
  r2 = r8_uniform_01 ( seed );
  x = sqrt ( - 2.0 * log ( r1 ) ) * cos ( 2.0 * r8_pi * r2 );

  value = ( int ) round ( a + b * x );

  return value;
}
/**********************************************************************/

void i4_normal_ab_test ( )

/**********************************************************************/
/*
  Purpose:

    I4_NORMAL_AB_TEST tests I4_NORMAL_AB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 July 2006

  Author:

    John Burkardt
*/
{
  int i;
  double mu;
  int r;
  int seed;
  double sigma;

  printf ( "\n" );
  printf ( "I4_NORMAL_AB_TEST\n" );
  printf ( "  I4_NORMAL_AB computes pseudonormal integers\n" );
  printf ( "  with mean MU and standard deviation SIGMA.\n" );

  mu = 70.0;
  sigma = 10.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "  The mean = %f\n", mu );
  printf ( "  The standard deviation = %f\n", sigma );
  printf ( "  SEED = %d\n", seed );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = i4_normal_ab ( mu, sigma, &seed );
    printf ( "  %8d  %8d\n", i, r );
  }

  return;
}
/******************************************************************************/

int i4_uniform_ab ( int a, int b, int *seed )

/******************************************************************************/
/*
  Purpose:

    I4_UNIFORM_AB returns a scaled pseudorandom I4 between A and B.

  Discussion:

    The pseudorandom number should be uniformly distributed
    between A and B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 May 2012

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int A, B, the limits of the interval.

    Input/output, int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, int I4_UNIFORM_AB, a number between A and B.
*/
{
  int c;
  const int i4_huge = 2147483647;
  int k;
  float r;
  int value;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4_UNIFORM_AB - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }
/*
  Guaranteee A <= B.
*/
  if ( b < a )
  {
    c = a;
    a = b;
    b = c;
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( float ) ( *seed ) * 4.656612875E-10;
/*
  Scale R to lie between A-0.5 and B+0.5.
*/
  r = ( 1.0 - r ) * ( ( float ) ( a ) - 0.5 ) 
    +         r   * ( ( float ) ( b ) + 0.5 );
/*
  Round R to the nearest integer.
*/
  value = round ( r );
/*
  Guarantee that A <= VALUE <= B.
*/
  if ( value < a )
  {
    value = a;
  }
  if ( b < value )
  {
    value = b;
  }

  return value;
}
/******************************************************************************/

void i4_uniform_ab_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_UNIFORM_AB_TEST tests I4_UNIFORM_AB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2014

  Author:

    John Burkardt
*/
{
  int a = -100;
  int b = 200;
  int i;
  int j;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "I4_UNIFORM_AB_TEST\n" );
  printf ( "  I4_UNIFORM_AB computes pseudorandom values\n" );
  printf ( "  in an interval [A,B].\n" );

  printf ( "\n" );
  printf ( "  The lower endpoint A = %d\n", a );
  printf ( "  The upper endpoint B = %d\n", b );
  printf ( "  The initial seed is %d\n", seed );
  printf ( "\n" );

  for ( i = 1; i <= 20; i++ )
  {
    j = i4_uniform_ab ( a, b, &seed );
    printf ( "  %8d  %d\n", i, j );
  }

  return;
}
/******************************************************************************/

int i4_wrap ( int ival, int ilo, int ihi )

/******************************************************************************/
/*
  Purpose:

    I4_WRAP forces an I4 to lie between given limits by wrapping.

  Example:

    ILO = 4, IHI = 8

    I   Value

    -2     8
    -1     4
     0     5
     1     6
     2     7
     3     8
     4     4
     5     5
     6     6
     7     7
     8     8
     9     4
    10     5
    11     6
    12     7
    13     8
    14     4

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int IVAL, an integer value.

    Input, int ILO, IHI, the desired bounds for the integer value.

    Output, int I4_WRAP, a "wrapped" version of IVAL.
*/
{
  int jhi;
  int jlo;
  int value;
  int wide;

  jlo = i4_min ( ilo, ihi );
  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )
  {
    value = jlo;
  }
  else
  {
    value = jlo + i4_modp ( ival - jlo, wide );
  }

  return value;
}
/******************************************************************************/

void i4_wrap_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_WRAP_TEST tests I4_WRAP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 July 2010

  Author:

    John Burkardt
*/
{
  int i;
  int ihi = 8;
  int ilo = 4;

  printf ( "\n" );
  printf ( "I4_WRAP_TEST\n" );
  printf ( "  I4_WRAP forces an integer to lie within given limits.\n" );
  printf ( "\n" );
  printf ( "  ILO = %d\n", ilo );
  printf ( "  IHI = %d\n", ihi );
  printf ( "\n" );
  printf ( "     I  I4_WRAP(I)\n" );
  printf ( "\n" );

  for ( i = -10; i <= 20; i++ )
  {
    printf ( "  %6d  %6d\n", i, i4_wrap ( i, ilo, ihi )  );
  }

  return;
}
/******************************************************************************/

void inflate_common ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    INFLATE_COMMON "inflates" dates in the Common Calendar transition month.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 May 2010

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date.
*/
{
  if ( *y == 1582 )
  {
    if ( *m == 10 )
    {
      if ( 5 <= *d )
      {
        *d = *d + 10;
      }
    }
  }

  return;
}
/******************************************************************************/

void jed_ce_values ( int *n_data, double *jed, int *y, int *m, int *d,
  double *f )

/******************************************************************************/
/*
  Purpose:

    JED_CE_VALUES returns the Common Era dates for Julian Ephemeris Dates.

  Discussion:

    The JED (Julian Ephemeris Date) is a calendrical system which counts days,
    starting from noon on 1 January 4713 BCE.

    The CE or Common Era is the day, month and year under the
    hybrid Julian/Gregorian Calendar, with a transition from Julian
    to Gregorian.  The day after 04 October 1582 was 15 October 1582.

    The year before 1 AD or CE is 1 BC or BCE.  In this data set,
    years BC/BCE are indicated by a negative year value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 May 2006

  Author:

    John Burkardt

  Reference:

    Edward Reingold and Nachum Dershowitz,
    Calendrical Calculations: The Millennium Edition,
    Cambridge University Press, 2001,
    ISBN: 0 521 77752 6

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, double *JED, the Julian Ephemeris Date.

    Output, int *Y, *M, *D, the Common Era date.

    Output, double *F, the fractional part of the day.
*/
{
# define N_MAX 51

  static int d_vec[N_MAX] = {
    1,
    2,
    26,
    8,
    6,
    18,
    8,
    9,
    1,
    26,
    26,
    1,
    1,
    29,
    31,
    1,
    3,
    3,
    29,
    24,
    24,
    29,
    3,
    11,
    12,
    24,
    19,
    15,
    16,
    16,
    21,
    17,
    9,
    4,
    15,
    4,
    13,
    14,
    18,
    22,
    21,
    24,
    17,
    31,
    1,
    6,
    25,
    1,
    9,
    23,
    1 };
  static double f_vec[N_MAX] = {
    0.50,
    0.50,
    0.50,
    0.00,
    0.00,
    0.25,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.50,
    0.50,
    0.00,
    0.50,
    0.50,
    0.00,
    0.00,
    0.00,
    0.00,
    0.00,
    0.81,
    0.00,
    0.00,
    0.00,
    0.00,
    0.33,
    0.00,
    0.50 };
  static double jed_vec[N_MAX] = {
           0.00,
           1.00,
      259261.00,
      347998.50,
      584282.50,
      588465.75,
      758325.50,
     1438178.50,
     1446389.50,
     1448637.50,
     1448637.50,
     1607708.50,
     1607738.50,
     1713262.50,
     1721422.50,
     1721423.50,
     1721425.50,
     1721425.50,
     1724220.50,
     1741959.50,
     1749994.50,
     1825029.50,
     1862836.50,
     1922867.50,
     1936747.50,
     1940351.50,
     1948320.50,
     1948438.50,
     1948439.50,
     1952062.50,
     1952067.50,
     2114872.50,
     2289425.50,
     2299160.00,
     2299161.00,
     2333269.50,
     2361221.00,
     2361222.00,
     2372547.50,
     2375839.50,
     2394646.50,
     2394710.50,
     2400000.50,
     2415020.31,
     2440587.50,
     2444244.50,
     2450138.50,
     2451544.50,
     2453073.83,
     2456284.50,
     2913943.00 };
  static int m_vec[N_MAX] = {
     1,
     1,
     10,
     10,
     9,
     2,
     3,
     7,
     1,
     2,
     2,
     9,
     10,
     8,
     12,
     1,
     1,
     1,
     8,
     3,
     3,
     8,
     3,
     7,
     7,
     5,
     3,
     7,
     7,
     6,
     6,
     3,
     2,
     10,
     10,
     3,
     9,
     9,
     9,
     9,
     3,
     5,
     11,
     12,
     1,
     1,
     2,
     1,
     3,
     12,
     1 };
  static int y_vec[N_MAX] = {
    -4713,
    -4713,
    -4004,
    -3761,
    -3114,
    -3102,
    -2637,
     -776,
     -753,
     -747,
     -747,
     -312,
     -312,
      -23,
       -1,
        1,
        1,
        1,
        8,
       57,
       79,
      284,
      388,
      552,
      590,
      600,
      622,
      622,
      622,
      632,
      632,
     1078,
     1556,
     1582,
     1582,
     1676,
     1752,
     1752,
     1783,
     1792,
     1844,
     1844,
     1858,
     1899,
     1970,
     1980,
     1996,
     2000,
     2004,
     2012,
     3266 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *jed = 0.0;
    *y = 0;
    *m = 0;
    *d = 0;
    *f = 0.0;
  }
  else
  {
    *jed = jed_vec[*n_data-1];
    *y = y_vec[*n_data-1];
    *m = m_vec[*n_data-1];
    *d = d_vec[*n_data-1];
    *f = f_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void jed_ce_values_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_CE_VALUES_TEST tests JED_CE_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 May 2006

  Author:

    John Burkardt
*/
{
  int d;
  double f;
  double jed;
  int n_data;
  int m;
  int y;

  printf ( "\n" );
  printf ( "JED_CE_VALUES_TEST:\n" );
  printf ( "  JED_CE_VALUES returns:\n" );
  printf ( "  JED, a Julian Ephemeris Date, and\n" );
  printf ( "  YMDF, the corresponding year, month, day, fraction.\n" );
  printf ( "\n" );
  printf ( "        JED          Y   M   D    F\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    jed_ce_values ( &n_data, &jed, &y, &m, &d, &f );

    if ( n_data == 0 )
    {
      break;
    }
    printf ( "  %12g  %6d  %2d  %2d  %6f\n", jed, y, m, d, f );
  }
  return;
}
/******************************************************************************/

bool jed_is_legal ( double jed )

/******************************************************************************/
/*
  Purpose:

    JED_IS_LEGAL determines if a Julian Ephemeris Date is legal.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, bool JED_IS_LEGAL, true if JED is legal.
*/
{
  bool value;

  value = ( 0.0 <= jed );

  return value;
}
/******************************************************************************/

void jed_is_legal_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_IS_LEGAL_TEST tests JED_IS_LEGAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  double jed;
  int jed_num = 7;
  double jed_values[7] = { -100.0, -1.0, 0.0, 1.0, 1.5, 100.0, 50000.0 };
  bool legal;

  printf ( "\n" );
  printf ( "JED_IS_LEGAL_TEST\n" );
  printf ( "  JED_IS_LEGAL determines if a JED is legal.\n" );
  printf ( "\n" );
  printf ( "               JED  JED_IS_LEGAL:\n" );
  printf ( "\n" );
  for ( i = 0; i < jed_num; i++ )
  {
    jed = jed_values[i];
    legal = jed_is_legal ( jed );
    if ( legal )
    {
      printf ( "  %16g  True\n", jed );
    }
    else
    {
      printf ( "  %16g  False\n", jed );
    }
  }

  return;
}
/******************************************************************************/

void jed_mjd_values ( int *n_data, double *jed, double *mjd )

/******************************************************************************/
/*
  Purpose:

    JED_MJD_VALUES returns the MJD for Julian Ephemeris Dates.

  Discussion:

    The JED (Julian Ephemeris Date) is a calendrical system which counts days,
    starting from noon on 1 January 4713 BCE.

    The MJD (Modified Julian Day) counts days starting from midnight,
    17 November 1858.  This essentially subtracts 2400000.5 days from the JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2004

  Author:

    John Burkardt

  Reference:

    Edward Reingold and Nachum Dershowitz,
    Calendrical Calculations: The Millennium Edition,
    Cambridge University Press, 2001,
    ISBN: 0 521 77752 6

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, double *JED, the Julian Ephemeris Date.

    Output, double *MJD, the Modified Julian Ephemeris Date.
*/
{
# define N_MAX 33

  static double jed_vec[N_MAX] = {
     1507231.5E+00,
     1660037.5E+00,
     1746893.5E+00,
     1770641.5E+00,
     1892731.5E+00,
     1931579.5E+00,
     1974851.5E+00,
     2091164.5E+00,
     2121509.5E+00,
     2155779.5E+00,
     2174029.5E+00,
     2191584.5E+00,
     2195261.5E+00,
     2229274.5E+00,
     2245580.5E+00,
     2266100.5E+00,
     2288542.5E+00,
     2290901.5E+00,
     2323140.5E+00,
     2334848.5E+00,
     2348020.5E+00,
     2366978.5E+00,
     2385648.5E+00,
     2392825.5E+00,
     2416223.5E+00,
     2425848.5E+00,
     2430266.5E+00,
     2430833.5E+00,
     2431004.5E+00,
     2448698.5E+00,
     2450138.5E+00,
     2465737.5E+00,
     2486076.5E+00 };

  static double mjd_vec[N_MAX] = {
     -892769.0E+00,
     -739963.0E+00,
     -653107.0E+00,
     -629359.0E+00,
     -507269.0E+00,
     -468421.0E+00,
     -425149.0E+00,
     -308836.0E+00,
     -278491.0E+00,
     -244221.0E+00,
     -225971.0E+00,
     -208416.0E+00,
     -204739.0E+00,
     -170726.0E+00,
     -154420.0E+00,
     -133900.0E+00,
     -111458.0E+00,
     -109099.0E+00,
      -76860.0E+00,
      -65152.0E+00,
      -51980.0E+00,
      -33022.0E+00,
      -14352.0E+00,
       -7175.0E+00,
       16223.0E+00,
       25848.0E+00,
       30266.0E+00,
       30833.0E+00,
       31004.0E+00,
       48698.0E+00,
       50138.0E+00,
       65737.0E+00,
       86076.0E+00 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *jed = 0.0;
    *mjd = 0.0;
  }
  else
  {
    *jed = jed_vec[*n_data-1];
    *mjd = mjd_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void jed_mjd_values_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_MJD_VALUES_TEST tests JED_MJD_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 June 2007

  Author:

    John Burkardt
*/
{
  double jed;
  int n_data;
  double mjd;

  printf ( "\n" );
  printf ( "JED_MJD_VALUES_TEST:\n" );
  printf ( "  JED_MJD_VALUES returns:\n" );
  printf ( "  JED, a Julian Ephemeris Date, and\n" );
  printf ( "  MJD, the corresponding Modified Julian Day count.\n" );
  printf ( "\n" );
  printf ( "   JED      MJD\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    jed_mjd_values ( &n_data, &jed, &mjd );

    if ( n_data == 0 )
    {
      break;
    }
    printf ( "  %12g  %12g\n", jed, mjd );
  }
  return;
}
/******************************************************************************/

void jed_rd_values ( int *n_data, double *jed, double *rd )

/******************************************************************************/
/*
  Purpose:

    JED_RD_VALUES returns the RD for Julian Ephemeris Dates.

  Discussion:

    The JED (Julian Ephemeris Date) is a calendrical system which counts days,
    starting from noon on 1 January 4713 BCE.

    The RD is the Reingold Dershowitz Date, which counts days from
    midnight, 1 January year 1 in the Gregorian calendar.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2004

  Author:

    John Burkardt

  Reference:

    Edward Reingold and Nachum Dershowitz,
    Calendrical Calculations: The Millennium Edition,
    Cambridge University Press, 2001,
    ISBN: 0 521 77752 6

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, double *JED, the Julian Ephemeris Date.

    Output, double *RD, the Reingold Dershowitz Date.
*/
{
# define N_MAX 33

  static double jed_vec[N_MAX] = {
    1507231.5E+00,
    1660037.5E+00,
    1746893.5E+00,
    1770641.5E+00,
    1892731.5E+00,
    1931579.5E+00,
    1974851.5E+00,
    2091164.5E+00,
    2121509.5E+00,
    2155779.5E+00,
    2174029.5E+00,
    2191584.5E+00,
    2195261.5E+00,
    2229274.5E+00,
    2245580.5E+00,
    2266100.5E+00,
    2288542.5E+00,
    2290901.5E+00,
    2323140.5E+00,
    2334848.5E+00,
    2348020.5E+00,
    2366978.5E+00,
    2385648.5E+00,
    2392825.5E+00,
    2416223.5E+00,
    2425848.5E+00,
    2430266.5E+00,
    2430833.5E+00,
    2431004.5E+00,
    2448698.5E+00,
    2450138.5E+00,
    2465737.5E+00,
    2486076.5E+00 };

  static double rd_vec[N_MAX] = {
    -214193.0E+00,
     -61387.0E+00,
      25469.0E+00,
      49217.0E+00,
     171307.0E+00,
     210155.0E+00,
     253427.0E+00,
     369740.0E+00,
     400085.0E+00,
     434355.0E+00,
     452605.0E+00,
     470160.0E+00,
     473837.0E+00,
     507850.0E+00,
     524156.0E+00,
     544676.0E+00,
     567118.0E+00,
     569477.0E+00,
     601716.0E+00,
     613424.0E+00,
     626596.0E+00,
     645554.0E+00,
     664224.0E+00,
     671401.0E+00,
     694799.0E+00,
     704424.0E+00,
     708842.0E+00,
     709409.0E+00,
     709580.0E+00,
     727274.0E+00,
     728714.0E+00,
     744313.0E+00,
     764652.0E+00 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *jed = 0.0;
    *rd = 0.0;
  }
  else
  {
    *jed = jed_vec[*n_data-1];
    *rd = rd_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void jed_rd_values_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_RD_VALUES_TEST tests JED_RD_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 June 2007

  Author:

    John Burkardt
*/
{
  double jed;
  int n_data;
  double rd;

  printf ( "\n" );
  printf ( "JED_RD_VALUES_TEST:\n" );
  printf ( "  JED_RD_VALUES returns:\n" );
  printf ( "  JED, a Julian Ephemeris Date, and\n" );
  printf ( "  RD, the corresponding Reingold Dershowitz Day count.\n" );
  printf ( "\n" );
  printf ( "   JED      RD\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    jed_rd_values ( &n_data, &jed, &rd );

    if ( n_data == 0 )
    {
      break;
    }
    printf ( "  %12g  %12g\n", jed, rd );
  }
  return;
}
/******************************************************************************/

double jed_test ( int i )

/******************************************************************************/
/*
  Purpose:

    JED_TEST returns some "interesting" JED's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 May 2012

  Author:

    John Burkardt

  Reference:

    Bonnie Blackburn, Leofranc Holford-Stevens,
    The Oxford Companion to the Year,
    Oxford, 1999.

    Frank Parise, editor,
    The Book of Calendars,
    Facts on File, Inc, 1982,
    CE11.K4 / 529.3.

    Edward Reingold, Nachum Dershowitz,
    Calendrical Calculations, the Millennium Edition,
    Cambridge, 2002,
    CE12.R45 / 529.3-dc21

    Edward Richards,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999.

  Parameters:

    Input, int I, the test date requested.

    Output, double JED_TEST, the Julian Ephemeris Date.
    If I is less than 1, or greater than the number of test dates
    available, JED is returned as -1.0.
*/
{
  double jed;
  double jed_epoch_50000;
/*
  JED Epoch:
  Beginning of current Scaliger cycle.
  Monday, Noon, 1 January 4713 BCE/Julian
*/
  if ( i == 1 )
  {
    jed = epoch_to_jed_jed ( );
  }
/*
  The day after the JED Epoch.
  Tuesday, Noon, 2 January 4713 BCE/Julian
*/
  else if ( i == 2 )
  {
    jed = epoch_to_jed_jed ( );
    jed = jed + 1.0;
  }
/*
  Archbishop James Ussher's estimate of the date of Creation,
  (Noon), 23 October 4004 BCE/Julian
*/
  else if ( i == 3 )
  {
    jed = 259258.000;
  }
/*
  Hebrew Epoch.
  7 October 3761 BCE/Julian
*/
  else if ( i == 4 )
  {
    jed = epoch_to_jed_hebrew ( );
  }
/*
  Mayan Long Count Epoch.
  6 September 3114 BCE/Julian
  (Reingold and Dershowitz)
*/
  else if ( i == 5 )
  {
    jed = epoch_to_jed_mayan_long ( );
  }
/*
  Hindu Solar Epoch.
  Beginning of the Kali Yuga age.
  18 February 3102 BCE/Julian
*/
  else if ( i == 6 )
  {
    jed = epoch_to_jed_hindu_solar ( );
  }
/*
  Chinese Epoch.
  8 March 2637 BCE/Julian
*/
  else if ( i == 7 )
  {
    jed = epoch_to_jed_chinese ( );
  }
/*
  Greek Olympiad Epoch
  9 July 776 BCE/Julian
*/
  else if ( i == 8 )
  {
    jed = epoch_to_jed_greek ( );
  }
/*
  Roman Epoch
  Ab Urbe Condita
  1 January 753 BCE/Julian
*/
  else if ( i == 9 )
  {
    jed = epoch_to_jed_roman ( );
  }
/*
  Egyptian Civil Calendar Epoch.
  Ascension of Nabonassar to throne of Babylon.
  26 February 747 BCE/Julian
*/
  else if ( i == 10 )
  {
    jed = epoch_to_jed_eg_civil ( );
  }
/*
  Egyptian Lunar Calendar Epoch.
  (Don't really know where to set this...)
  Ascension of Nabonassar to throne of Babylon.
  26 February 747 BCE/Julian
*/
  else if ( i == 11 )
  {
    jed = epoch_to_jed_eg_lunar ( );
  }
/*
  Macedonian Epoch
  1 September 312 BCE/Julian
*/
  else if ( i == 12 )
  {
    jed = epoch_to_jed_macedonian ( );
  }
/*
  Syrian Epoch
  1 October 312 BCE/Julian
*/
  else if ( i == 13 )
  {
    jed = epoch_to_jed_syrian ( );
  }
/*
  Alexandrian Epoch
  29 August 23 BCE/Julian
*/
  else if ( i == 14 )
  {
    jed = epoch_to_jed_alexandrian ( );
  }
/*
  "1 January, 0 BC"?  MATLAB DATENUM epoch.
*/
  else if ( i == 15 )

    jed = epoch_to_jed_datenum ( );
/*
  Julian Epoch MINUS ONE DAY
  Friday, 31 December 1 BCE/Julian
*/
  else if ( i == 16 )
  {
    jed = epoch_to_jed_julian ( );
    jed = jed - 1.0;
  }
/*
  Julian Epoch
  Saturday, 1 January 1 CE/Julian
*/
  else if ( i == 17 )
  {
    jed = epoch_to_jed_julian ( );
  }
/*
  Gregorian Epoch
  Monday, 3 January 1 CE/Julian
  Monday, 1 January 1 Gregorian
*/
  else if ( i == 18 )
  {
    jed = epoch_to_jed_gregorian ( );
  }
/*
  RD: Reingold and Dershowitz Epoch
  Monday, 3 January 1 CE/Julian
  Monday, 1 January 1 Gregorian
*/
  else if ( i == 19 )
  {
    jed = epoch_to_jed_rd ( );
  }
/*
  Ethiopian Epoch
  29 August 8 CE/Julian
  (Reingold and Dershowitz)
*/
  else if ( i == 20 )
  {
    jed = epoch_to_jed_ethiopian ( );
  }
/*
  Hindu Lunar Epoch, the Vikrama
  24 March 57 CE/Julian
  (The actual day and month are not specified by RD)
  (Reingold and Dershowitz)
*/
  else if ( i == 21 )
  {
    jed = epoch_to_jed_hindu_lunar ( );
  }
/*
  Saka Epoch
  4 March 79 CE/Julian
*/
  else if ( i == 22 )
  {
    jed = epoch_to_jed_saka ( );
  }
/*
  Coptic Epoch
  29 August 284 CE/Julian
*/
  else if ( i == 23 )
  {
    jed = epoch_to_jed_coptic ( );
  }
/*
  Zoroastrian Epoch.
  3 March 388 CE/Julian
*/
   else if ( i == 24 )
  {
     jed = epoch_to_jed_zoroastrian ( );
  }
/*
  Armenian Epoch
  11 July 552 CE/Julian
*/
  else if ( i == 25 )
  {
    jed = epoch_to_jed_armenian ( );
  }
/*
  Fasli Deccan Epoch
  12 July 590 CE/Julian
*/
   else if ( i == 26 )
  {
     jed = epoch_to_jed_deccan ( );
  }
/*
  Fasli Soor San Epoch
  24 May 600 CE/Julian
*/
   else if ( i == 27 )
  {
     jed = epoch_to_jed_soor_san ( );
  }
/*
  Persian Solar Epoch
  19 March 622 CE/Julian
*/
  else if ( i == 28 )
  {
    jed = epoch_to_jed_persian_solar ( );
  }
/*
  Islamic A Epoch
  Thursday, 15 July 622 CE/Julian
*/
  else if ( i == 29 )
  {
    jed = epoch_to_jed_islamic_a ( );
  }
/*
  Islamic B Epoch
  Friday, 16 July 622 CE/Julian
*/
  else if ( i == 30 )
  {
    jed = epoch_to_jed_islamic_b ( );
  }
/*
  Yazdegerd Epoch
  16 June 632 CE
*/
  else if ( i == 31 )
  {
    jed = epoch_to_jed_persian ( );
  }
/*
  Khwarizmian Epoch
  21 June 632 CE/Julian
*/
  else if ( i == 32 )
  {
    jed = epoch_to_jed_khwarizmian ( );
  }
/*
  Battle of Hastings.
  Saturday, 14 October 1066 CE/Julian.
           (20 October 1066 Gregorian.)
*/
  else if ( i == 33 )
  {
    jed = 2110700.5;
  }
/*
  Jelali Epoch
  17 March 1078 CE/Julian
*/
  else if ( i == 34 )
  {
    jed = epoch_to_jed_jelali ( );
  }
/*
  Akbar Epoch
  9 February 1556 CE/Julian
  19 February 1556 Gregorian
*/
  else if ( i == 35 )
  {
    jed = epoch_to_jed_akbar ( );
  }
/*
  Common Era calendar transition:
  Noon of the last day of Julian calendar usage.
  Thursday, 04 October 1582 CE/English/Julian
  Thursday, 14 October 1582 Gregorian
*/
  else if ( i == 36 )
  {
    jed = transition_to_jed_common ( );
    jed = jed - 0.5;
  }
/*
  Common Era calendar transition:
  Noon of the first day of Gregorian calendar usage.
  Friday, 05 October 1582 English/Julian
  Friday, 15 October 1582 CE/Gregorian
*/
  else if ( i == 37 )
  {
    jed = transition_to_jed_common ( );
    jed = jed + 0.5;
  }
/*/
  A day chosen by Lewis Carroll to test his day-of-the-week algorithm,
  Wednesday, 4 March 1676 CE/Gregorian
  Wednesday, 23 February 1676 English/Julian
*/
  else if ( i == 38 )
  {
    jed = 2333269.5;
  }
/*
  English calendar
  noon of the last day of Julian calendar usage.
  02 September 1752 English/Julian
  13 September 1752 CE/Gregorian
*/
  else if ( i == 39 )
  {
    jed = transition_to_jed_english ( );
    jed = jed - 0.5;
  }
/*
  English calendar,
  noon of the first day of Gregorian calendar usage.
  03 September 1752 Julian
  14 September 1752 CE/English/Gregorian
*/
  else if ( i == 40 )
  {
    jed = transition_to_jed_english ( );
    jed = jed + 0.5;
  }
/*
  A day chosen by Lewis Carroll to test his day-of-the-week algorithm,
  Thursday, 18 September 1783 CE/Gregorian
*/
  else if ( i == 41 )
  {
    jed = 2372547.5;
  }
/*
  French Republican Epoch
  Saturday, 11 September 1792 Julian
  Saturday, 22 September 1792 CE/Gregorian
*/
  else if ( i == 42 )
  {
    jed = epoch_to_jed_republican ( );
  }
/*
  Bahai Epoch.
  9 March 1844 Julian
  21 March 1844 CE/Gregorian
*/
  else if ( i == 43 )
  {
    jed = epoch_to_jed_bahai ( );
  }
/*
  Clive James Lucas test date.
*/
  else if ( i == 44 )
  {
    jed = 2394710.50;
  }
/*
  New York Times "epoch" date,
  fictitious Volume 1, issue #0,
  17 September 1851
  (issue #1 was on 18 September 1851):
*/
  else if ( i == 45 )
  {
    jed = 2397383.50;
  }
/*
  Modified Julian Date Epoch.
  17 November 1858 CE/Gregorian
*/
  else if ( i == 46 )
  {
    jed = epoch_to_jed_mjd ( );
  }
/*
  NYT issue 10,000
  24 September 1883
*/
  else if ( i == 47 )
  {
    jed_epoch_50000 = 2449790.5;
    jed = jed_epoch_50000 - 40000.0 - 88.0;
  }
/*
  Bessel Year Count Epoch.
  1 January 1900 CE/Gregorian
*/
  else if ( i == 48 )
  {
    jed = epoch_to_jed_bessel ( );
  }
/*
  NYT issue 30,000
  14 March 1940
*/
  else if ( i == 49 )
  {
    jed_epoch_50000 = 2449790.5;
    jed = jed_epoch_50000 - 20000.0 - 88.0;
  }
/*
  NYT issue 40,000
  ???
*/
  else if ( i == 50 )
  {
    jed_epoch_50000 = 2449790.5;
    jed = jed_epoch_50000 - 10000.0 - 88.0;
  }
/*
  UNIX epoch.
  1 January 1970 CE/Gregorian.
*/
  else if ( i == 51 )
  {
    jed = epoch_to_jed_unix ( );
  }
/*
  NYT issue 44027
  ???
*/
  else if ( i == 52 )
  {
    jed_epoch_50000 = 2449790.5;
    jed = jed_epoch_50000 - 5973;
  }
/*
  NYT issue 44028
  ???
*/
  else if ( i == 53 )
  {
    jed_epoch_50000 = 2449790.5;
    jed = jed_epoch_50000 - 5972;
  }
/*
  GPS epoch.
  6 January 1980 CE/Gregorian
*/
  else if ( i == 54 )
  {
    jed = epoch_to_jed_gps ( );
  }
/*
  NYT issue 50,000
  14 March 1995
*/
  else if ( i == 55 )
  {
    jed_epoch_50000 = 2449790.5;
    jed = jed_epoch_50000;
  }
/*
  25 February 1996
  A Reingold/Dershowitz test date.
*/
  else if ( i == 56 )
  {
    jed = 2450138.5;
  }
/*
  Y2K day
  1 January 2000 CE/Gregorian
*/
  else if ( i == 57 )
  {
    jed = epoch_to_jed_y2k ( );
  }
/*
  Today
*/
  else if ( i == 58 )
  {
    jed = now_to_jed ( );
  }
/*
  End of Current Mayan Great Cycle
  21 December 2012 CE/Gregorian
*/
  else if ( i == 59 )
  {
    jed = transition_to_jed_mayan_long ( );
  }
/*
  Scaliger cycle repeats.
  1 January 3266 CE/Gregorian
*/
  else if ( i == 60 )
  {
    jed = transition_to_jed_jed ( );
  }
  else
  {
    jed = -1.0;
  }

  return jed;
}
/******************************************************************************/

double jed_to_datenum ( double jed )

/******************************************************************************/
/*
  Purpose:

    JED_TO_DATENUM converts a JED to a MATLAB date number.

  Discussion:

    The MATLAB "datenum" function accepts a string defining
    a date and returns a datenumber:

      dn = datenum ( 'Aug 17 1939' )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, double JED_TO_DATENUM, a MATLAB date number.
*/
{
  double dn;

  dn = jed - 1721058.5;

  return dn;
}
/******************************************************************************/

void jed_to_datenum_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_TO_DATENUM_TEST tests JED_TO_DATENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt
*/
{
  double date_num;
  int i;
  double jed1;
  double jed3;
  double jed_epoch;

  printf ( "\n" );
  printf ( "JED_TO_DATENUM_TEST\n" );
  printf ( "  JED_TO_DATENUM: Matlab DATENUM -> JED.\n" );
  printf ( "\n" );
  printf ( "  JED (in)    DATENUM             JED (out)\n" );
  printf ( "\n" );

  jed_epoch = epoch_to_jed_datenum ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      date_num = jed_to_datenum ( jed1 );
      jed3 = datenum_to_jed ( date_num );

      printf ( "  %11.2f  %11.2f  %11.2f\n", jed1, date_num, jed3 );
    }
  }

  return;
}
/******************************************************************************/

void jed_to_gps ( double jed, int *c, int *w, double *s )

/******************************************************************************/
/*
  Purpose:

    JED_TO_GPS converts a JED to a GPS date.

  Discussion:

    The GPS time keeping is in terms of seconds, weeks, and cycles
    of 1024 weeks.  The weeks and cycles begin numbering at 0.

    The computation is only valid for dates after the GPS epoch,
    that is, after 6 January 1980.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, int *C, *W, double *S, the 
    corresponding GPS cycles/weeks/seconds date.
*/
{
  double d;
  double jed_epoch;

  jed_epoch = epoch_to_jed_gps ( );

  d = jed - jed_epoch;

  if ( d < 0.0 )
  {
    *s = -1.0;
    *w = -1;
    *c = -1;
    return;
  }

  *w = ( int ) ( d ) / 7;
  d = d - ( double ) ( 7 * ( *w ) );

  *c = *w / 1024;
  *w = *w - 1024 * ( *c );

  *s = d * ( double ) ( 24.0 * 60.0 * 60.0 );

  return;
}
/******************************************************************************/

void jed_to_gps_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_TO_GPS_TEST tests JED_TO_GPS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 December 2017

  Author:

    John Burkardt
*/
{
  int c2;
  int i;
  double jed_epoch;
  double jed1;
  double jed3;
  double sec2;
  int w2;

  printf ( "\n" );
  printf ( "JED_TO_GPS_TEST\n" );
  printf ( "  JED_TO_GPS: JED => GPS.\n" );
  printf ( "\n" );
  printf ( "   JED (in)       GPS (C/W/S)                   JED (out)\n" );
  printf ( "\n" );

  jed_epoch = epoch_to_jed_gps ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      jed_to_gps ( jed1, &c2, &w2, &sec2 );

      jed3 = gps_to_jed ( c2, w2, sec2 );

      printf ( "  %11.2f  %d/%d/%11.2f (GPS)  %11.2f\n", jed1, c2, w2, sec2, jed3 );
    }
  }

  return;
}
/******************************************************************************/

double jed_to_noon_nearest ( double jed1 )

/******************************************************************************/
/*
  Purpose:

    JED_TO_NOON_NEAREST converts a JED to the JED of the nearest noon.

  Discussion:

    This is primarily to make a fair test of the weekday routines,
    which have trouble when the JED is at midnight.

    Note that noon corresponds to an integral JED value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double JED1, the Julian Ephemeris Date.

    Output, double JED_TO_NOON_NEAREST, the Julian Ephemeris Date
    of the nearest noon.
*/
{
  double jed2;

  jed2 = ( double ) r8_nint ( jed1 );

  return jed2;
}
/******************************************************************************/

void jed_to_noon_nearest_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_TO_NOON_NEAREST_TEST tests JED_TO_NOON_NEAREST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt
*/
{
  int d1;
  int d2;
  double f1;
  double f2;
  int i;
  double jed1;
  double jed2;
  int m1;
  int m2;
  char *s1;
  char *s2;
  int y1;
  int y2;

  printf ( "\n" );
  printf ( "JED_TO_NOON_NEAREST_TEST\n" );
  printf ( "  JED_TO_NOON_NEAREST: JED => JED (nearest noon).\n" );
  printf ( "\n" );
  printf ( "   JED        JED (nearest noon)\n" );
  printf ( "\n" );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    jed_to_ymdf_common ( jed1, &y1, &m1, &d1, &f1 );

    s1 = ymdf_to_s_common ( y1, m1, d1, f1 );

    jed2 = jed_to_noon_nearest ( jed1 );

    jed_to_ymdf_common ( jed2, &y2, &m2, &d2, &f2 );

    s2 = ymdf_to_s_common ( y2, m2, d2, f2 );
    
    printf ( "%11f  %s  %11f  %s\n", jed1, s1, jed2, s2 );

    free ( s1 );
    free ( s2 );
  }

  return;
}
/******************************************************************************/

double jed_to_noon_next ( double jed1 )

/******************************************************************************/
/*
  Purpose:

    JED_TO_NOON_NEXT converts a JED to the JED of the next noon.

  Discussion:

    This is primarily to make a fair test of the weekday routines,
    which have trouble when the JED is at midnight.

    Note that noon corresponds to an integral JED value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double JED1, the Julian Ephemeris Date.

    Output, double JED_TO_NOON_NEXT, the Julian Ephemeris Date
    of the next noon.
*/
{
  double jed2;

  jed2 = floor ( jed1 );
/*
  The integer part of JED1 is one of the two integers that
  bracket JED1.  If it's the smaller one (which it should
  be as long as JED1 is positive), make it the bigger one.

  This correctly leaves undisturbed cases where JED1 is
  already an integer, and where JED1 is negative (which
  is not a case we expect to occur often).
*/
  if ( jed2 < jed1 )
  {
    jed2 = jed2 + 1.0;
  }

  return jed2;
}
/******************************************************************************/

void jed_to_noon_next_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_TO_NOON_NEXT_TEST tests JED_TO_NOON_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt
*/
{
  int d1;
  int d2;
  double f1;
  double f2;
  int i;
  double jed1;
  double jed2;
  int m1;
  int m2;
  char *s1;
  char *s2;
  int y1;
  int y2;

  printf ( "\n" );
  printf ( "JED_TO_NOON_NEXT_TEST\n" );
  printf ( "  JED_TO_NOON_NEXT: JED => JED (next noon).\n" );
  printf ( "\n" );
  printf ( "   JED        JED (next noon)\n" );
  printf ( "\n" );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    jed_to_ymdf_common ( jed1, &y1, &m1, &d1, &f1 );

    s1 = ymdf_to_s_common ( y1, m1, d1, f1 );

    jed2 = jed_to_noon_next ( jed1 );

    jed_to_ymdf_common ( jed2, &y2, &m2, &d2, &f2 );

    s2 = ymdf_to_s_common ( y2, m2, d2, f2 );
    
    printf ( "%11f  %s  %11f  %s\n", jed1, s1, jed2, s2 );

    free ( s1 );
    free ( s2 );
  }

  return;
}
/******************************************************************************/

void jed_to_weekday ( double jed, int *w, double *f )

/******************************************************************************/
/*
  Purpose:

    JED_TO_WEEKDAY computes the day of the week from a JED.

  Discussion:

    BC 4713/01/01 => JED = 0.0 was noon on a Monday.

    jedmod = mod ( 0.0, 7.0 ) = 0.0
    j = mod ( nint ( 0 ), 7 ) = 0
    f = ( 0.0 + 0.5 ) - real ( j ) = 0.5
    w = i4_wrap ( 0 + 2, 1, 7 ) = 2 = MONDAY

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 November 2002

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999.

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, int W, the day of the week of the date.
    The days are numbered from Sunday through Saturday, 1 through 7.

    Output, double F, the fractional part of the day.
*/
{
  int j;
  double jedmod;

  jedmod = r8_mod ( jed, 7.0 );

  j = ( r8_nint ( jedmod ) ) % 7;

  *f = ( jedmod + 0.5 ) - ( double ) ( j );

  *w = i4_wrap ( j + 2, 1, 7 );

  return;
}
/******************************************************************************/

void jed_to_weekday_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_TO_WEEKDAY_TEST tests JED_TO_WEEKDAY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 July 2017

  Author:

    John Burkardt
*/
{
  double f;
  double jed;
  int n_data;
  int w;
  int w2;

  printf ( "\n" );
  printf ( "JED_TO_WEEKDAY_TEST\n" );
  printf ( "  JED_TO_WEEKDAY determines the weekday\n" );
  printf ( "  corresponding to a JED:\n" );
  printf ( "\n" );
  printf ( "             JED  W     W\n" );
  printf ( "                  True  Computed\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    jed_weekday_values ( &n_data, &jed, &w );

    if ( n_data == 0 )
    {
      break;
    }

    jed_to_weekday ( jed, &w2, &f );

    printf ( "  %14f  %4d  %8d  %8f\n", jed, w, w2, f );
  }
  return;
}
/******************************************************************************/

void jed_to_ymdf_common ( double jed, int *y, int *m, int *d, double *f )

/******************************************************************************/
/*
  Purpose:

    JED_TO_YMDF_COMMON converts a JED to a Common YMDF date.

  Discussion:

    The "common" calendar is meant to be the calendar which is Julian up to
    JED = 2299160.5, and Gregorian thereafter.

    There is no year 0.  BC years are specified using a negative value.

  Example:

        JED            Y    M   D
    -------    ------------------
          0    BCE  4713  Jan   1
    2440000    CE   1968  May  23
    2446065    CE   1984  Dec  31

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, int *Y, *M, *D, double *F, the YMDF date.
*/
{
  double jed_transition;

  jed_transition = transition_to_jed_common ( );

  if ( jed <= jed_transition )
  {
    jed_to_ymdf_julian ( jed, y, m, d, f );
  }
  else
  {
    jed_to_ymdf_gregorian ( jed, y, m, d, f );
  }

  return;
}
/******************************************************************************/

void jed_to_ymdf_gregorian ( double jed, int *y, int *m, int *d, double *f )

/******************************************************************************/
/*
  Purpose:

    JED_TO_YMDF_GREGORIAN converts a JED to a Gregorian YMDF date.

  Discussion:

    This Gregorian calendar is extended backwards in time before
    its actual adoption.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm F,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, pages 324-325.

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, int *Y, *M, *D, double *F,
    the YMDF date.
*/
{
  int d_prime;
  int g;
  int j;
  int j_prime;
  int m_prime;
  int t_prime;
  int y_prime;
/*
  Determine the computational date (Y'/M'/D').
*/
  j = ( int ) ( jed + 0.5 );
  *f = ( jed + 0.5 ) - ( double ) ( j );

  g = ( 3 * ( ( 4 * j + 274277 ) / 146097 ) / 4 ) - 38;
  j_prime = j + 1401 + g;

  y_prime =   ( 4 * j_prime + 3 ) / 1461;
  t_prime = ( ( 4 * j_prime + 3 ) % 1461 ) / 4;
  m_prime =   ( 5 * t_prime + 2 ) / 153;
  d_prime = ( ( 5 * t_prime + 2 ) % 153 ) / 5;
/*
  Convert the computational date to a calendar date.
*/
  *d = d_prime + 1;
  *m = ( ( m_prime + 2 ) % 12 ) + 1;
  *y = y_prime - 4716 + ( 14 - *m ) / 12;
/*
  Any year before 1 AD must be moved one year further back, since
  this calendar does not include a year 0.
*/
  *y = y_astronomical_to_common ( *y );

  return;
}
/******************************************************************************/

void jed_to_ymdf_julian ( double jed, int *y, int *m, int *d, double *f )

/******************************************************************************/
/*
  Purpose:

    JED_TO_YMDF_JULIAN converts a JED to a Julian YMDF date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm F,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, pages 324-325.

  Parameters:

    Input, double JED, the Julian Ephemeris Date.

    Output, int *Y, *M, *D, double *F, the YMDF date.
*/
{
  int d_prime;
  int j;
  int j_prime;
  int m_prime;
  int t_prime;
  int y_prime;
/*
  Determine the computational date (Y'/M'/D').
*/
  j = ( int ) ( jed + 0.5 );
  *f = ( jed + 0.5 ) - ( double ) ( j );

  j_prime = j + 1401;

  y_prime =   ( 4 * j_prime + 3 ) / 1461;
  t_prime = ( ( 4 * j_prime + 3 ) % 1461 ) / 4;
  m_prime =   ( 5 * t_prime + 2 ) / 153;
  d_prime = ( ( 5 * t_prime + 2 ) % 153 ) / 5;
/*
  Convert the computational date to a calendar date.
*/
  *d = d_prime + 1;
  *m = ( ( m_prime + 2 ) % 12 ) + 1;
  *y = y_prime - 4716 + ( 14 - *m ) / 12;
/*
  Any year before 1 AD must be moved one year further back, since
  this calendar does not include a year 0.
*/
  *y = y_astronomical_to_common ( *y );

  return;
}
/******************************************************************************/

void jed_weekday_values ( int *n_data, double *jed, int *weekday )

/******************************************************************************/
/*
  Purpose:

    JED_WEEKDAY_VALUES returns the day of the week for Julian Ephemeris Dates.

  Discussion:

    The JED (Julian Ephemeris Date) is a calendrical system which counts days,
    starting from noon on 1 January 4713 BCE.

    Weekdays are numbered as follows:

    1  Sunday
    2  Monday
    3  Tuesday
    4  Wednesday
    5  Thursday
    6  Friday
    7  Saturday

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 September 2004

  Author:

    John Burkardt

  Reference:

    Edward Reingold and Nachum Dershowitz,
    Calendrical Calculations: The Millennium Edition,
    Cambridge University Press, 2001,
    ISBN: 0 521 77752 6

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, double *JED, the Julian Ephemeris Date.

    Output, int *WEEKDAY, the day of the week.
*/
{
# define N_MAX 33

  static double jed_vec[N_MAX] = {
    1507231.5E+00,
    1660037.5E+00,
    1746893.5E+00,
    1770641.5E+00,
    1892731.5E+00,
    1931579.5E+00,
    1974851.5E+00,
    2091164.5E+00,
    2121509.5E+00,
    2155779.5E+00,
    2174029.5E+00,
    2191584.5E+00,
    2195261.5E+00,
    2229274.5E+00,
    2245580.5E+00,
    2266100.5E+00,
    2288542.5E+00,
    2290901.5E+00,
    2323140.5E+00,
    2334848.5E+00,
    2348020.5E+00,
    2366978.5E+00,
    2385648.5E+00,
    2392825.5E+00,
    2416223.5E+00,
    2425848.5E+00,
    2430266.5E+00,
    2430833.5E+00,
    2431004.5E+00,
    2448698.5E+00,
    2450138.5E+00,
    2465737.5E+00,
    2486076.5E+00 };

  static int weekday_vec[N_MAX] = {
    1, 4, 4, 1, 4,
    2, 7, 1, 1, 6,
    7, 6, 1, 1, 4,
    7, 7, 7, 4, 1,
    6, 1, 2, 4, 1,
    1, 2, 2, 5, 3,
    1, 4, 1 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *jed = 0.0;
    *weekday = 0;
  }
  else
  {
    *jed = jed_vec[*n_data-1];
    *weekday = weekday_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void jed_weekday_values_test ( )

/******************************************************************************/
/*
  Purpose:

    JED_WEEKDAY_VALUE_TEST tests JED_WEEKDAY_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 June 2007

  Author:

    John Burkardt
*/
{
  double jed;
  int n_data;
  int weekday;

  printf ( "\n" );
  printf ( "JED_WEEKDAY_VALUES_TEST:\n" );
  printf ( "  JED_WEEKDAY_VALUES returns Julian Ephemeris Dates \n" );
  printf ( "  (JED) and the corresponding weekday\n" );
  printf ( "\n" );
  printf ( "   JED      #  Weekday\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    jed_weekday_values ( &n_data, &jed, &weekday );

    if ( n_data == 0 )
    {
      break;
    }
    printf ( "  %12g  %d\n", jed, weekday );
  }
  return;
}
/******************************************************************************/

void month_borrow_common ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    MONTH_BORROW_COMMON borrows a year of months on the Common calendar.

  Discussion:

    If the month index is legal, nothing is done.  If the month index
    is too small, then one or more years are "cashed in" to bring the
    month index up to a legal value.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, the YM date.
*/
{
  int months;

  while ( *m <= 0 )
  {
    months = year_length_months_common ( *y );

    *m = *m + months;
    *y = *y - 1;

    if ( *y == 0 )
    {
      *y = - 1;
    }
  }
  return;
}
/******************************************************************************/

void month_borrow_gregorian ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    MONTH_BORROW_GREGORIAN borrows a year of months on the Gregorian calendar.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, the YM date.
*/
{
  int months;

  while ( *m <= 0 )
  {
    months = year_length_months_gregorian ( *y );

    *m = *m + months;
    *y = *y - 1;

    if ( *y == 0 )
    {
      *y = - 1;
    }
  }
  return;
}
/******************************************************************************/

void month_borrow_julian ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    MONTH_BORROW_JULIAN borrows a year of months on the Julian calendar.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, the YM date.
*/
{
  int months;

  while ( *m <= 0 )
  {
    months = year_length_months_julian ( *y );

    *m = *m + months;
    *y = *y - 1;

    if ( *y == 0 )
    {
      *y = - 1;
    }
  }
  return;
}
/******************************************************************************/

void month_carry_common ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    MONTH_CARRY_COMMON carries a year of months on the Common calendar.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, the year and month.
    On output, M is no greater than 12.
*/
{
  int months;

  for ( ; ; )
  {
    months = year_length_months_common ( *y );

    if ( *m <= months )
    {
      break;
    }
    *m = *m - months;
    *y = *y + 1;
  }
  return;
}
/******************************************************************************/

void month_carry_gregorian ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    MONTH_CARRY_GREGORIAN carries a year of months on the Gregorian calendar.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, the year and month.
    On output, M is no greater than 12.
*/
{
  int months;

  for ( ; ; )
  {
    months = year_length_months_gregorian ( *y );

    if ( *m <= months )
    {
      break;
    }
    *m = *m - months;
    *y = *y + 1;
  }
  return;
}
/******************************************************************************/

void month_carry_julian ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    MONTH_CARRY_JULIAN carries a year of months on the Julian calendar.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, the year and month.
    On output, M is no greater than 12.
*/
{
  int months;

  for ( ; ; )
  {
    months = year_length_months_julian ( *y );

    if ( *m <= months )
    {
      break;
    }

    *m = *m - months;
    *y = *y + 1;
  }
  return;
}
/******************************************************************************/

int month_length_common ( int y, int m )

/******************************************************************************/
/*
  Purpose:

    MONTH_LENGTH_COMMON returns the number of days in a Common month.

  Discussion:

    The "common" calendar is meant to be the calendar which is Julian up to
    day JED = 2299160, and Gregorian from day JED = 2299161 and after.

    The routine knows that February has 28 days, except in leap years,
    when it has 29.

    In the Common calendar, October 1582 had only 21 days

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year in which the month occurred.

    Input, int M, the number of the month.

    Output, int MONTH_LENGTH_COMMON, the number of days 
    in the month.
*/
{
  int days;
  int m2;
  int mdays[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int y2;
/*
  Copy the input.
*/
  m2 = m;
  y2 = y;
/*
  Check the input.
*/
  ym_check_common ( &y2, &m2 );
/*
  Take care of the special case.
*/
  if ( y2 == 1582 )
  {
    if ( m2 == 10 )
    {
      days = 21;
      return days;
    }
  }
/*
  Get the number of days in the month.
*/
  days = mdays[m2-1];
/*
  If necessary, add 1 day for February 29.
*/
  if ( m2 == 2 && year_is_leap_common ( y2 ) )
  {
    days = days + 1;
  }
  return days;
}
/******************************************************************************/

int month_length_gregorian ( int y, int m )

/******************************************************************************/
/*
  Purpose:

    MONTH_LENGTH_GREGORIAN returns the number of days in a Gregorian month.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year in which the month occurred.

    Input, int M, the number of the month.

    Output, int MONTH_LENGTH_GREGORIAN, the number of days in the month.
*/
{
  int days;
  int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//  Check the input.
//
  ym_check_gregorian ( &y, &m );
//
//  Get the number of days in the month.
//
  days = mdays[m-1];
//
//  If necessary, add 1 day for February 29.
//
  if ( m == 2 )
  {
    if ( year_is_leap_gregorian ( y ) )
    {
      days = days + 1;
    }
  }
  return days;
}
/******************************************************************************/

int month_length_julian ( int y, int m )

/******************************************************************************/
/*
  Purpose:

    MONTH_LENGTH_JULIAN returns the number of days in a Julian month.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year in which the month occurred.

    Input, int M, the number of the month.

    Output, int MONTH_LENGTH_JULIAN, the number of days in the month.
*/
{
  int days;
  int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//  Get the number of days in the month.
//
  days = mdays[m-1];
//
//  If necessary, add 1 day for February 29.
//
  if ( m == 2 && year_is_leap_julian ( y ) )
  {
    days = days + 1;
  }
  return days;
}
/******************************************************************************/

char *month_to_month_name_common ( int m )

/******************************************************************************/
/*
  Purpose:

    MONTH_TO_MONTH_NAME_COMMON returns the name of a Common month.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int M, the month index.

    Output, char *MONTH_TO_MONTH_NAME_COMMON, the month name.
*/
{
  char *value;
  static char month_name_list[12][10] = { 
    "January\0", "February\0", "March\0", 
    "April\0", "May\0", "June\0", 
    "July\0", "August\0", "September\0", 
    "October\0", "November\0", "December\0" };

  if ( m < 1 || 12 < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "MONTH_TO_MONTH_NAME_COMMON\n" );
    fprintf ( stderr, "  Illegal month index.\n" );
    exit ( 1 );
  }

  value = ( char * ) malloc ( 10 * sizeof ( char ) );
  strcpy ( value, month_name_list[m-1] );

  return value;
}
/******************************************************************************/

void month_to_month_name_common_test ( )

/******************************************************************************/
/*
  Purpose:

    MONTH_TO_MONTH_NAME_COMMON_TEST tests MONTH_TO_MONTH_NAME_COMMON.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  char *s;

  printf ( "\n" );
  printf ( "MONTH_TO_MONTH_NAME_COMMON_TEST\n" );
  printf ( "  WMONTH_TO_MONTH_NAME_COMMON names the months of the year.\n" );
  printf ( "\n" );

  for ( i = 1; i <= 12; i++ )
  {
    s = month_to_month_name_common ( i );
    printf ( "  %4d  %s\n", i, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

char *month_to_month_name_common3 ( int m )

/******************************************************************************/
/*
  Purpose:

    MONTH_TO_MONTH_NAME_COMMON3 returns the name of a Common month.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int M, the month index.

    Output, char *MONTH_TO_MONTH_NAME_COMMON3, the month name.
*/
{
  char *value;
  static char month_name_list[12][4] = { 
    "Jan\0", "Feb\0", "Mar\0", 
    "Apr\0", "May\0", "Jun\0", 
    "Jul\0", "Aug\0", "Sep\0", 
    "Oct\0", "Nov\0", "Dec\0" };

  if ( m < 1 || 12 < m )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "MONTH_TO_MONTH_NAME_COMMON3\n" );
    fprintf ( stderr, "  Illegal month index.\n" );
    exit ( 1 );
  }

  value = ( char * ) malloc ( 4 * sizeof ( char ) );
  strcpy ( value, month_name_list[m-1] );

  return value;
}
/******************************************************************************/

void month_to_month_name_common3_test ( )

/******************************************************************************/
/*
  Purpose:

    MONTH_TO_MONTH_NAME_COMMON3_TEST tests MONTH_TO_MONTH_NAME_COMMON3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  char *s;

  printf ( "\n" );
  printf ( "MONTH_TO_MONTH_NAME_COMMON3_TEST\n" );
  printf ( "  WMONTH_TO_MONTH_NAME_COMMON3 names the months of the year.\n" );
  printf ( "\n" );

  for ( i = 1; i <= 12; i++ )
  {
    s = month_to_month_name_common3 ( i );
    printf ( "  %4d  %s\n", i, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

double now_to_jed ( )

/******************************************************************************/
/*
  Purpose:

    NOW_TO_JED expresses the current date as JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double JED, the Julian Ephemeris Date.
*/
{
  time_t clock;
  int d;
  double f;
  int h;
  double jed;
  struct tm *lt;
  int m;
  int mu;
  int n;
  int s;
  time_t tloc;
  int y;

  clock = time ( &tloc );
  lt = localtime ( &clock );

  y = lt->tm_year + 1900;
  m = lt->tm_mon + 1;
  d = lt->tm_mday + 1;
  h = lt->tm_hour;
  n = lt->tm_min;
  s = lt->tm_sec;
  mu = 0;

  f = ( double ) mu;
  f = ( double ) ( s ) + f / 1000.0;
  f = ( double ) ( n ) + f / 60.0;
  f = ( double ) ( h ) + f / 60.0;
  f = f / 24.0;

  jed = ymdf_to_jed_common ( y, m, d, f );

  return jed;
}
/******************************************************************************/

double r8_mod ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    R8_MOD returns the remainder of R8 division.

  Discussion:

    If
      REM = R8_MOD ( X, Y )
      RMULT = ( X - REM ) / Y
    then
      X = Y * RMULT + REM
    where REM has the same sign as X, and abs ( REM ) < Y.

  Example:

        X         Y     R8_MOD   R8_MOD  Factorization

      107        50       7     107 =  2 *  50 + 7
      107       -50       7     107 = -2 * -50 + 7
     -107        50      -7    -107 = -2 *  50 - 7
     -107       -50      -7    -107 =  2 * -50 - 7

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 June 2007

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number to be divided.

    Input, double Y, the number that divides X.

    Output, double R8_MOD, the remainder when X is divided by Y.
*/
{
  double value;

  if ( y == 0.0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8_MOD - Fatal error!\n" );
    fprintf ( stderr, "  R8_MOD ( X, Y ) called with Y = %f\n", y );
    exit ( 1 );
  }

  value = x - ( ( double ) ( ( int ) ( x / y ) ) ) * y;

  if ( x < 0.0 && 0.0 < value )
  {
    value = value - fabs ( y );
  }
  else if ( 0.0 < x && value < 0.0 )
  {
    value = value + fabs ( y );
  }

  return value;
}
/******************************************************************************/

void r8_mod_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_MOD_TEST tests R8_MOD.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2010

  Author:

    John Burkardt
*/
{
  int seed = 123456789;
  int test;
  int test_num = 10;
  double x;
  double x_hi = 10.0;
  double x_lo = -10.0;
  double y;
  double z1;
  double z2;

  printf ( "\n" );
  printf ( "R8_MOD_TEST\n" );
  printf ( "  R8_MOD returns the remainder after division.\n" );
  printf ( "  R8_MOD ( X, Y ) has the same sign as X.\n" );
  printf ( "\n" );
  printf ( "      X         Y    FMOD(X,Y)    R8_MOD(X,Y)\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    x = r8_uniform_ab ( x_lo, x_hi, &seed );
    y = r8_uniform_ab ( x_lo, x_hi, &seed );

    z1 =   fmod ( x, y );
    z2 = r8_mod ( x, y );

    printf ( "  %12f  %12f  %12f  %12f\n", x, y, z1, z2 );
  }

  return;
}
/******************************************************************************/

int r8_nint ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_NINT returns the nearest integer to an R8.

  Example:

        X         R8_NINT

      1.3         1
      1.4         1
      1.5         1 or 2
      1.6         2
      0.0         0
     -0.7        -1
     -1.1        -1
     -1.6        -2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the value.

    Output, int R8_NINT, the nearest integer to X.
*/
{
  int s;
  int value;

  if ( x < 0.0 )
  {
    s = - 1;
  }
  else
  {
    s = + 1;
  }
  value = s * ( int ) ( fabs ( x ) + 0.5 );

  return value;
}
/******************************************************************************/

void r8_nint_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_NINT_TEST tests R8_NINT

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt
*/
{
  double b;
  double c;
  int seed = 123456789;
  int test;
  int test_num = 10;
  double x;

  printf ( "\n" );
  printf ( "R8_NINT_TEST\n" );
  printf ( "  R8_NINT produces the nearest integer.\n" );
  printf ( "\n" );
  printf ( "       X        R8_NINT(X)\n" );
  printf ( "\n" );

  b = -10.0;
  c = +10.0;

  for ( test = 1; test <= test_num; test++ )
  {
    x = r8_uniform_ab ( b, c, &seed );
    printf ( "   %10f  %6d\n", x, r8_nint ( x ) );
  }

  return;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a pseudorandom R8 scaled to [0,1].

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8_UNIFORM_01 - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0\n" );
    exit ( 1 );
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

void r8_uniform_01_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01_TEST tests R8_UNIFORM_01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt
*/
{
# define N 1000

  int i;
  double max;
  double mean;
  double min;
  int seed = 123456789;
  double x[N];
  double variance;

  printf ( "\n" );
  printf ( "R8_UNIFORM_01_TEST\n" );
  printf ( "  R8_UNIFORM_01 samples a uniform random distribution in [0,1].\n" );
  printf ( "  distributed random numbers.\n" );
  printf ( "  Using initial random number seed = %d\n", seed );

  for ( i = 0; i < N; i++ )
  {
    x[i] = r8_uniform_01 ( &seed );
  }

  printf ( "\n" );
  printf ( "  First few values:\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6d  %14f\n", i, x[i] );
  }
  min = x[0];
  max = x[0];
  mean = 0.0;
  for ( i = 0; i < N; i++ )
  {
    if ( x[i] < min )
    {
      min = x[i];
    }
    if ( max < x[i] )
    {
      max = x[i];
    }
    mean = mean + x[i];
  }
  mean = mean / ( double ) N;

  variance = 0.0;
  for ( i = 0; i < N; i++ )
  {
    variance = variance + pow ( x[i] - mean, 2 );
  }
  variance = variance / ( double ) N;

  printf ( "\n" );
  printf ( "  Number of samples was %d\n", N );
  printf ( "  Minimum value was %f\n", min );
  printf ( "  Maximum value was %f\n", max );
  printf ( "  Average value was %f\n", mean );
  printf ( "  Variance was      %f\n", variance );

  return;
# undef N
}
/******************************************************************************/

double r8_uniform_ab ( double a, double b, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_AB returns a pseudorandom R8 scaled to [A,B].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 November 2004

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, the limits of the interval.

    Input/output, int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, double R8_UNIFORM_AB, a number strictly between A and B.
*/
{
  const int i4_huge = 2147483647;
  int k;
  double r;
  double value;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8_UNIFORM_AB - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0\n" );
    exit ( 1 );
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  value = a + ( b - a ) * r;

  return value;
}
/******************************************************************************/

void r8_uniform_ab_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_AB_TEST tests R8_UNIFORM_AB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  int i;
  int seed;

  b = 10.0;
  c = 25.0;
  seed = 17;

  printf ( "\n" );
  printf ( "R8_UNIFORM_AB_TEST\n" );
  printf ( "  R8_UNIFORM_AB produces a random real in a given range.\n" );
  printf ( "\n" );
  printf ( "  Using range %f <= A <= %f.\n", b, c );
  printf ( "\n" );

  printf ( "\n" );
  printf ( "     I      A\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    a = r8_uniform_ab ( b, c, &seed );
    printf ( "  %4d  %10f\n", i, a );
  }

  return;
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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
/******************************************************************************/

double transition_to_jed_common ( )

/******************************************************************************/
/*
  Purpose:

    TRANSITION_TO_JED_COMMON returns the Common calendar transition as a JED.

  Discussion:

    In the Common calendar, the last moment of the Julian calendar was
      11:59 pm, 4 October 1582 Julian/CE,
      11:59 pm, 14 October 1582 Gregorian.
    The first minute of the Gregorian calendar ended at
      12:01 am, 5 October 1582 Julian,
      12:01 am, 15 October 1582 Gregorian/CE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double TRANSITION_TO_JED_COMMON, the Julian Ephemeris Date 
    of the date.
*/
{
  double jed;

  jed = 2299160.5;

  return jed;
}
/******************************************************************************/

double transition_to_jed_english ( )

/******************************************************************************/
/*
  Purpose:

    TRANSITION_TO_JED_ENGLISH returns the English calendar transition as a JED.

  Discussion:

    In the English calendar, the last moment of the Julian calendar was
      11:59 pm, 2 September 1752 Julian/English,
      11:59 pm, 13 September 1752 Gregorian/CE.
    The first minute of the Gregorian calendar ended at
      12:01 am, 3 September 1752 Julian,
      12:01 am, 15 September 1752 Gregorian/CE/English.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Output, double TRANSITION_TO_JED_ENGLISH, the Julian Ephemeris Date 
    of the date.
*/
{
  double jed;

  jed = 2361221.5;

  return jed;
}
/******************************************************************************/

double transition_to_jed_jed ( )

/******************************************************************************/
/*
  Purpose:

    TRANSITION_TO_JED_JED returns the JED calendar transition as a JED.

  Discussion:

    In Scaliger's design of the JED, three cycles with different periods
    began on JED = 0.  These three cycles coincide once more on the
    transition day.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 May 2010

  Author:

    John Burkardt

  Parameters:

    Output, double TRANSITION_TO_JED_JED, the Julian Ephemeris Date 
    of the date.
*/
{
  double jed;

  jed = 2913943.0;

  return jed;
}
/******************************************************************************/

double transition_to_jed_mayan_long ( )

/******************************************************************************/
/*
  Purpose:

    TRANSITION_TO_JED_MAYAN_LONG: Mayan long count calendar transition as a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 December 2012

  Author:

    John Burkardt

  Parameters:

    Output, double TRANSITION_TO_JED_MAYAN_LONG, the Julian Ephemeris Date 
    of the date.
*/
{
  double jed;

  jed = 2456282.5;

  return jed;
}
/******************************************************************************/

char *weekday_to_name_common ( int w )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_TO_NAME_COMMON returns the name of a Common weekday.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int W, the weekday index.

    Output, char *WEEKDAY_TO_NAME_COMMON, the weekday name.
*/
{
  char *value;
  static char weekday_list[7][10] = { 
    "Sunday\0", "Monday\0", "Tuesday\0", "Wednesday\0", "Thursday\0", 
    "Friday\0", "Saturday\0" };

  if ( w < 1 || 7 < w )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WEEKDAY_TO_NAME_COMMON\n" );
    fprintf ( stderr, "  Illegal weekday.\n" );
    exit ( 1 );
  }

  value = ( char * ) malloc ( 10 * sizeof ( char ) );
  strcpy ( value, weekday_list[w-1] );

  return value;
}
/******************************************************************************/

void weekday_to_name_common_test ( )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_TO_NAME_COMMON_TEST tests WEEKDAY_TO_NAME_COMMON.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  char *s;

  printf ( "\n" );
  printf ( "WEEKDAY_TO_NAME_COMMON_TEST\n" );
  printf ( "  WEEKDAY_TO_NAME_COMMON names the days of the week,\n" );
  printf ( "\n" );

  for ( i = 1; i <= 7; i++ )
  {
    s = weekday_to_name_common ( i );
    printf ( "  %4d  %s\n", i, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

char *weekday_to_name_common2 ( int w )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_TO_NAME_COMMON2 returns the abbreviated name of a Common weekday.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int W, the weekday index.

    Output, char *WEEKDAY_TO_NAME_COMMON2, the weekday name.
*/
{
  char *value;
  static char weekday_list[7][3] = { 
    "Su\0", "M \0", "Tu\0", "W \0", "Th\0", "F \0", "Sa\0" };

  if ( w < 1 || 7 < w )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WEEKDAY_TO_NAME_COMMON2\n" );
    fprintf ( stderr, "  Illegal weekday.\n" );
    exit ( 1 );
  }

  value = ( char * ) malloc ( 3 * sizeof ( char ) );
  strcpy ( value, weekday_list[w-1] );

  return value;
}
/******************************************************************************/

void weekday_to_name_common2_test ( )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_TO_NAME_COMMON2_TEST tests WEEKDAY_TO_NAME_COMMON2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  char *s;

  printf ( "\n" );
  printf ( "WEEKDAY_TO_NAME_COMMON2_TEST\n" );
  printf ( "  WEEKDAY_TO_NAME_COMMON2 names the days of the week,\n" );
  printf ( "\n" );

  for ( i = 1; i <= 7; i++ )
  {
    s = weekday_to_name_common2 ( i );
    printf ( "  %4d  %s\n", i, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

char *weekday_to_name_common3 ( int w )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_TO_NAME_COMMON3 returns the abbreviated name of a Common weekday.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int W, the weekday index.

    Output, char *WEEKDAY_TO_NAME_COMMON, the weekday name.
*/
{
  char *value;
  static char weekday_list[7][4] = { 
    "Sun\0", "Mon\0", "Tue\0", "Wed\0", "Thu\0", "Fri\0", "Sat\0" };

  if ( w < 1 || 7 < w )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "WEEKDAY_TO_NAME_COMMON3\n" );
    fprintf ( stderr, "  Illegal weekday.\n" );
    exit ( 1 );
  }

  value = ( char * ) malloc ( 4 * sizeof ( char ) );
  strcpy ( value, weekday_list[w-1] );

  return value;
}
/******************************************************************************/

void weekday_to_name_common3_test ( )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_TO_NAME_COMMON3_TEST tests WEEKDAY_TO_NAME_COMMON3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  char *s;

  printf ( "\n" );
  printf ( "WEEKDAY_TO_NAME_COMMON3_TEST\n" );
  printf ( "  WEEKDAY_TO_NAME_COMMON3 names the days of the week,\n" );
  printf ( "\n" );

  for ( i = 1; i <= 7; i++ )
  {
    s = weekday_to_name_common3 ( i );
    printf ( "  %4d  %s\n", i, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void weekday_values ( int *n_data, int *y, int *m, int *d, int *w )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_VALUES returns the day of the week for various dates.

  Discussion:

    The CE or Common Era calendar is used, under the
    hybrid Julian/Gregorian Calendar, with a transition from Julian
    to Gregorian.  The day after 04 October 1582 was 15 October 1582.  

    The year before 1 AD or CE is 1 BC or BCE.  In this data set,
    years BC/BCE are indicated by a negative year value.  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 May 2012

  Author:

    John Burkardt

  Reference:

    Edward Reingold, Nachum Dershowitz,
    Calendrical Calculations: The Millennium Edition,
    Cambridge University Press, 2001,
    ISBN: 0 521 77752 6
    LC: CE12.R45.

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 
    before the first call.  On each call, the routine increments N_DATA by 1,
    and returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, int *Y, *M, *D, the Common Era date.

    Output, int *W, the day of the week.  Sunday = 1.
*/
{
# define N_MAX 34

  static int d_vec[N_MAX] = {
    30, 
     8, 
    26, 
     3, 
     7, 
    18, 
     7, 
    19, 
    14,
    18, 
    16, 
     3, 
    26, 
    20, 
     4, 
    25, 
    31, 
     9, 
    24, 
    10, 
    30, 
    24, 
    19, 
     2, 
    27, 
    19, 
    25, 
    29, 
    19, 
     7, 
    17, 
    25, 
    10, 
    18 };
  static int m_vec[N_MAX] = {
     7, 
    12, 
     9, 
    10, 
     1, 
     5, 
    11, 
     4, 
    10,
     5, 
     3, 
     3, 
     3, 
     4, 
     6, 
     1, 
     3, 
     9, 
     2, 
     6, 
     6, 
     7, 
     6, 
     8, 
     3, 
     4, 
     8, 
     9, 
     4, 
    10, 
     3, 
     2, 
    11, 
     7 };
  static int w_vec[N_MAX] = {
    1, 
    4, 
    4, 
    1, 
    4, 
    2, 
    7, 
    1, 
    7,
    1, 
    6, 
    7, 
    6, 
    1, 
    1, 
    4, 
    7, 
    7, 
    7, 
    4, 
    1, 
    6, 
    1, 
    2, 
    4, 
    1, 
    1, 
    2, 
    2, 
    5, 
    3, 
    1, 
    4, 
    1 };
  static int y_vec[N_MAX] = {
    - 587, 
    - 169, 
       70, 
      135, 
      470, 
      576, 
      694, 
     1013, 
     1066,
     1096, 
     1190, 
     1240, 
     1288, 
     1298, 
     1391, 
     1436, 
     1492, 
     1553, 
     1560, 
     1648, 
     1680, 
     1716, 
     1768, 
     1819, 
     1839, 
     1903, 
     1929, 
     1941, 
     1943, 
     1943, 
     1992, 
     1996, 
     2038, 
     2094 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *y = 0;
    *m = 0;
    *d = 0;
    *w = 0;
  }
  else
  {
    *y = y_vec[*n_data-1];
    *m = m_vec[*n_data-1];
    *d = d_vec[*n_data-1];
    *w = w_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void weekday_values_test ( )

/******************************************************************************/
/*
  Purpose:

    WEEKDAY_VALUES_TEST tests WEEKDAY_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 January 2015

  Author:

    John Burkardt
*/
{
  int d;
  int m;
  int n_data;
  int w;
  int y;

  printf ( "\n" );
  printf ( "WEEKDAY_VALUES_TEST:\n" );
  printf ( "  WEEKDAY_VALUES returns values of \n" );
  printf ( "  the weekday for a given Y/M/D date\n" );
  printf ( "\n" );
  printf ( "     Y     M     D     W\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    weekday_values ( &n_data, &y, &m, &d, &w );

    if ( n_data == 0 )
    {
      break;
    }
    printf ( "  %4d  %4d  %4d  %4d\n", y, m, d, w );
  }
  return;
}
/******************************************************************************/

int y_astronomical_to_common ( int y )

/******************************************************************************/
/*
  Purpose:

    Y_ASTRONOMICAL_TO_COMMON converts an Astronomical year to a Common year.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the astronomical year.

    Output, int Y_ASTRONOMICAL_TO_COMMON, the Common year.
*/
{
  int y2;

  if ( y <= 0 )
  {
    y2 = y - 1;
  }
  else
  {
    y2 = y;
  }
  return y2;
}
/******************************************************************************/

void y_check_common ( int y )

/******************************************************************************/
/*
  Purpose:

    Y_CHECK_COMMON checks a Common year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year, which must not be 0.
*/
{
  if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "Y_CHECK_COMMON - Fatal error!\n" );
    fprintf ( stderr, "  Year 0 is illegal.\n" );
    exit ( 1 );
  }
  return;
}
/******************************************************************************/

void y_check_gregorian ( int y )

/******************************************************************************/
/*
  Purpose:

    Y_CHECK_GREGORIAN checks a Gregorian year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year, which must not be 0.
*/
{
  if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "Y_CHECK_GREGORIAN - Fatal error!\n" );
    fprintf ( stderr, "  Year 0 is illegal.\n" );
    exit ( 1 );
  }
  return;
}
/******************************************************************************/

void y_check_julian ( int y )

/******************************************************************************/
/*
  Purpose:

    Y_CHECK_JULIAN checks a Julian year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year, which must not be 0.
*/
{
  if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "Y_CHECK_JULIAN - Fatal error!\n" );
    fprintf ( stderr, "  Year 0 is illegal.\n" );
    exit ( 1 );
  }
  return;
}
/******************************************************************************/

int y_common_to_astronomical ( int y )

/******************************************************************************/
/*
  Purpose:

    Y_COMMON_TO_ASTRONOMICAL converts a Common year to an Astronomical year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the Common year.

    Output, int Y_COMMON_TO_ASTRONOMICAL, the Astronomical year.
*/
{
  int y2;

  if ( y < 0 )
  {
    y2 = y + 1;
  }
  else if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "Y_COMMON_TO_ASTRONOMICAL - Fatal error!\n" );
    fprintf ( stderr, "  Common calendar does not have a year 0.\n" );
    exit ( 1 );
  }
  else
  {
    y2 = y;
  }

  return y2;
}
/******************************************************************************/

char *y_to_s_common ( int y )

/******************************************************************************/
/*
  Purpose:

    Y_TO_S_COMMON writes a Common Y date into a string.

  Format:

    CE YYYY
    BCE YYYY

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the Y date.

    Output, char *Y_TO_S_COMMON, a representation of the date.
*/
{
  char *value;

  value = ( char * ) malloc ( 14 * sizeof ( char ) );

  if ( y < 0 )
  {
    sprintf ( value, "BCE %d", - y );
  }
  else
  {
    sprintf ( value, "CE %d", y );
  }

  return value;
}
/******************************************************************************/

void y_to_s_common_test ( )

/******************************************************************************/
/*
  Purpose:

    Y_TO_S_COMMON_TEST tests Y_TO_S_COMMON.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 December 2017

  Author:

    John Burkardt
*/
{
  int i;
  double mu;
  char *s;
  int seed;
  double sigma;
  int y;

  printf ( "\n" );
  printf ( "Y_TO_S_COMMON_TEST:\n" );
  printf ( "  Y_TO_S_COMMON converts a year Y to a string S.\n" );
  printf ( "\n" );
  printf ( "       Y  'S'\n" );
  printf ( "\n" );

  mu = 0.0;
  sigma = 1000.0;
  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    y = i4_normal_ab ( mu, sigma, &seed );
    s = y_to_s_common ( y );
    printf ( "  %6d  '%s'\n", y, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

bool year_is_leap_common ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_IS_LEAP_COMMON returns TRUE if the Common year was a leap year.

  Discussion:

    The "common" calendar is meant to be the calendar which is Julian up to
    day JED = 2299160, and Gregorian from day JED = 2299161 and after.

  Algorithm:

    If ( the year is less than 0 ) then

      if the year+1 is divisible by 4 then
        the year is a leap year.

    else if ( the year is 0 ) then

      the year is not a leap year ( in fact, it's illegal )

    else if ( the year is no greater than 1582 ) then

      if the year is divisible by 4 then
        the year is a leap year.

    else if (
      the year is divisible by 4 and
      ( the year is not divisible by 100
      or
      the year is divisible by 400 )
      ) then
        the year is a leap year.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2015

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, bool YEAR_IS_LEAP_COMMON, TRUE if the year was a leap year,
    FALSE otherwise.
*/
{
  bool value;
  int y2;

  if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "YEAR_IS_LEAP_COMMON - Fatal error!\n" );
    fprintf ( stderr, "  Year 0 is illegal.\n" );
    exit ( 1 );
  }
/*
  BC years have to have 1 added to them to make a proper leap year evaluation.
*/
  y2 = y_common_to_astronomical ( y );

  if ( y2 <= 1582 )
  {
    if ( i4_modp ( y2, 4 ) == 0 )
    {
      value = true;
    }
    else
    {
      value = false;
    }
  }
  else
  {
    if ( i4_modp ( y2, 400 ) == 0 )
    {
      value = true;
    }
    else if ( i4_modp ( y2, 100 ) == 0 )
    {
      value = false;
    }
    else if ( i4_modp ( y2, 4 ) == 0 )
    {
      value = true;
    }
    else
    {
      value = false;
    }
  }
  return value;
}
/******************************************************************************/

bool year_is_leap_gregorian ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_IS_LEAP_GREGORIAN returns TRUE if the Gregorian year was a leap year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, bool YEAR_IS_LEAP_GREGORIAN, TRUE if the year was a leap year,
    FALSE otherwise.
*/
{
  bool value;

  if ( y == 0 ) 
  {
    value = false;
    return value;
  }
/*
  BC years have to have 1 added to them to make a proper leap year evaluation.
*/
  y = y_common_to_astronomical ( y );

  if ( ( y % 400 ) == 0 )
  {
    value = true;
  }
  else if ( ( y % 100 ) == 0 )
  {
    value = false;
  }
  else if ( ( y % 4 ) == 0 )
  {
    value = true;
  }
  else
  {
    value = false;
  }

  return value;
}
/******************************************************************************/

bool year_is_leap_julian ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_IS_LEAP_JULIAN returns TRUE if the Julian year was a leap year.

  Algorithm:

    If ( Y < 0 and Y+1 is divisible by 4 ) then
      the year is a leap year.
    else if ( Y == 0 ) then
      the year is illegal
    else if ( 0 < Y and Y is divisible by 4 ) then
      the year is a leap year.
    else
      the year is NOT a leap year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, bool YEAR_IS_LEAP_JULIAN, TRUE if the year was a leap year,
    FALSE otherwise.
*/
{
  bool value;

  if ( y == 0 )
  {
    value = false;
    return value;
  }

  y = y_common_to_astronomical ( y );

  if ( i4_modp ( y, 4 ) == 0 )
  {
    value = true;
  }
  else
  {
    value = false;
  }

  return value;
}
/******************************************************************************/

int year_length_days_common ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_LENGTH_DAYS_COMMON returns the number of days in a Common year.

  Discussion:

    The "common" calendar is meant to be the calendar which is Julian up to
    day JED = 2299160, and Gregorian from day JED = 2299161 and after.

    If Y is 0, then the routine returns 0, reflecting the fact that
    there was officially no year 0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 May 2000

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, int YEAR_LENGTH_DAYS_COMMON, the number of
    days in the year.
*/
{
  int value;

  if ( y == 0 )
  {
    value = 0;
  }
  else if ( y == 1582 )
  {
    value = 355;
  }
  else if ( year_is_leap_common ( y ) )
  {
    value = 366;
  }
  else
  {
    value = 365;
  }

  return value;
}
/******************************************************************************/

void year_length_days_common_test ( )

/******************************************************************************/
/*
  Purpose:

    YEAR_LENGTH_DAYS_COMMON_TEST tests YEAR_LENGTH_DAYS_COMMON.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 December 2017

  Author:

    John Burkardt
*/
{
  char *sy;
  int y;

  printf ( "\n" );
  printf ( "YEAR_LENGTH_DAYS_COMMON_TEST\n" );
  printf ( "  For the Common calendar:\n" );
  printf ( "  YEAR_LENGTH_DAYS_COMMON gives the length of a year.\n" );
  printf ( "\n" );
  printf ( "  Year  Length\n" );
  printf ( "\n" );

  for ( y = 1580; y <= 1585; y++ )
  {
    sy = y_to_s_common ( y );
    printf ( "  %10s  %6d\n", sy, year_length_days_common ( y ) );
    free ( sy );
  }

  for ( y = 1750; y <= 1755; y++ )
  {
    sy = y_to_s_common ( y );
    printf ( "  %10s  %6d\n", sy, year_length_days_common ( y ) );
    free ( sy );
  }

  for ( y = 1000; y <= 2000; y = y + 100 )
  {
    sy = y_to_s_common ( y );
    printf ( "  %10s  %6d\n", sy, year_length_days_common ( y ) );
    free ( sy );
  }

  return;
}
/******************************************************************************/

int year_length_months_common ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_LENGTH_MONTHS_COMMON returns the number of months in a Common year.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, int YEAR_LENGTH_MONTHS_COMMON, the number of months
    in the year.
*/
{
  int value;

  value = 12;

  return value;
}
/******************************************************************************/

int year_length_months_gregorian ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_LENGTH_MONTHS_GREGORIAN returns the number of months in a Gregorian year.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, int YEAR_LENGTH_MONTHS_GREGORIAN, the number of months
    in the year.
*/
{
  int value;

  value = 12;

  return value;
}
/******************************************************************************/

int year_length_months_julian ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_LENGTH_MONTHS_JULIAN returns the number of months in a Julian year.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year to be checked.

    Output, int YEAR_LENGTH_MONTHS_JULIAN, the number of months
    in the year.
*/
{
  int value;

  value = 12;

  return value;
}
/******************************************************************************/

int year_to_epact_julian ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_TO_EPACT_JULIAN returns the epact of a Julian year.

  Discussion:

    The epact of a year is the age in days of the notional moon on
    the first day of the year.  If the year begins with a new moon,
    the epact is zero.  If the new moon occurred the day before,
    the epact is 1.  There is a unique epact for every golden number.

    Bear in mind that the notional moon is not the one in the sky,
    but a theoretical one that satisfactorily approximates the behavior
    of the real one, but which is tame enough to be described by a formula.

  Example:

    Year  Golden Number  Epact

      1 BC     1           8
      1 AD     2          19
      2 AD     3           0
      3 AD     4          11
      4 AD     5          22
      5 AD     6           3
      6 AD     7          14
      7 AD     8          25
      8 AD     9           6
      9 AD    10          17
     10 AD    11          28
     11 AD    12           9
     12 AD    13          20
     13 AD    14           1
     14 AD    15          12
     15 AD    16          23
     16 AD    17           4
     17 AD    18          15
     18 AD    19          26
     19 AD     1           8
     20 AD     2          19
   1066 AD     3           0
   1900 AD     1           8
   1919 AD     1           8
   1938 AD     1           8
   1957 AD     1           8
   1976 AD     1           8
   1995 AD     1           8
   2014 AD     1           8

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2018

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999.

  Parameters:

    Input, int Y, the year.  The year 0 is illegal input.

    Output, int YEAR_TO_EPACT_JULIAN, the epact, between 0 and 28.
*/
{
  int e;
  int g;

  if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "YEAR_TO_EPACT_JULIAN - Fatal error!\n" );
    fprintf ( stderr, "  Illegal input Y = 0.\n" );
    exit ( 1 );
  }

  g = year_to_golden_number ( y );

  e = i4_wrap ( 11 * g - 3, 0, 29 );

  return e;
}
/******************************************************************************/

int year_to_golden_number ( int y )

/******************************************************************************/
/*
  Purpose:

    YEAR_TO_GOLDEN_NUMBER returns the golden number of a Common year.

  Discussion:

    Nineteen solar years are very close to 235 lunations.  Calendars
    that try to keep track of both the sun and moon often make use of
    this fact, ascribed to the Greek astronomer Meton.

    While trying to determine a formula for Easter, Dionysus Exiguus
    symbolized the place of each year in its Metonic cycle by a
    "golden number" between 1 and 19.  The numbering began with the
    year 1 BC, assigned the golden number of 1.  The following year,
    1 AD, got the golden number of 2, and after that it gets easier.

    The same golden year calculation is done for years in the Julian
    or Gregorian calendar.

  Example:

    Year  Golden Number

      1 BC     1
      1 AD     2
      2 AD     3
     18 AD    19
     19 AD     1
     20 AD     2
   1066 AD     3
   1900 AD     1
   1919 AD     1
   1938 AD     1
   1957 AD     1
   1976 AD     1
   1995 AD     1
   2014 AD     1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, the year.

    Output, int YEAR_TO_GOLDEN_NUMBER the golden number, between 1 and 19.  
    This records the position of the year in the 19 year Metonic cycle.
*/
{
  int g;
  int y2;

  if ( y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "YEAR_TO_GOLDEN_NUMBER - Fatal error!\n" );
    fprintf ( stderr, "  Illegal input Y = 0.\n" );
    exit ( 1 );
  }
/*
  We assume that BC years come in as negative numbers, and that
  the year before 1 AD is 1 BC.  So add 1 to any negative value
  so that the arithmetic works.
*/
  y2 = y_common_to_astronomical ( y );

  g = i4_wrap ( y2 + 1, 1, 19 );

  return g;
}
/******************************************************************************/

void year_to_golden_number_test ( )

/******************************************************************************/
/*
  Purpose:

    YEAR_TO_GOLDEN_NUMBER_TEST tests YEAR_TO_GOLDEN_NUMBER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 December 2017

  Author:

    John Burkardt
*/
{
  int g;
  char *s;
  int y;

  printf ( "\n" );
  printf ( "YEAR_TO_GOLDEN_NUMBER_TEST\n" );
  printf ( "  YEAR_TO_GOLDEN_NUMBER determines the golden\n" );
  printf ( "  number of a year.\n" );
  printf ( "\n" );
  printf ( "  Year  Golden Number\n" );
  printf ( "\n" );

  for ( y = -2; y <= 20; y++ )
  {
    if ( y != 0 )
    {
      s = y_to_s_common ( y );
      g = year_to_golden_number ( y );
      printf ( "  %s  %d\n", s, g );
    }
  }
  return;
}
/******************************************************************************/

void ym_check_common ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    YM_CHECK_COMMON checks a Common YM date.

  Discussion:

    If the month is less than 1, then the month is incremented
    by 12, and the year decremented by 1, repeatedly, until
    the month is greater than or equal to 1.

    If the month is greater than 12, then the month is decremented
    by 12, and the year incremented by 1, repeatedly, until the
    month is less than or equal to 12.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, the YM date.
*/
{
/*
  Check the year.
*/
  y_check_common ( *y );
/*
  Make sure the month isn't too small or too big.
*/
  month_borrow_common ( y, m );

  month_carry_common ( y, m );

  return;
}
/******************************************************************************/

void ym_check_gregorian ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    YM_CHECK_GREGORIAN checks a Gregorian YM date.

  Discussion:

    If the month is less than 1, then the month is incremented
    by 12, and the year decremented by 1, repeatedly, until
    the month is greater than or equal to 1.

    If the month is greater than 12, then the month is decremented
    by 12, and the year incremented by 1, repeatedly, until the
    month is less than or equal to 12.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, the YM date.
*/
{
  y_check_gregorian ( *y );

  month_borrow_gregorian ( y, m );

  month_carry_gregorian ( y, m );

  return;
}
/******************************************************************************/

void ym_check_julian ( int *y, int *m )

/******************************************************************************/
/*
  Purpose:

    YM_CHECK_JULIAN checks a Julian YM date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2000

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, int *M, the YM date.
*/
{
  y_check_julian ( *y );

  month_borrow_julian ( y, m );

  month_carry_julian ( y, m );

  return;
}
/******************************************************************************/

void ymd_check_common ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    YMD_CHECK_COMMON checks a Common YMD date.

  Discussion:

    Certain simple errors in dates will be corrected, such as
      "31 September 1996"
    which will become
      "1 October 1996".

    The routine also knows that in the Common calendar, the dates
    5 October 1582 through 14 October 1582 are illegal.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date,
    which may be corrected if necessary and possible.
*/
{
/*
  Check the year.
*/
  if ( *y == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "YMD_CHECK_COMMON - Fatal error!\n" );
    fprintf ( stderr, "  Y = 0 is illegal.\n" );
    exit ( 1 );
  }
/*
  Check the month.
*/
  month_borrow_common ( y, m );

  month_carry_common ( y, m );
/*
  Check the day.
*/
  day_borrow_common ( y, m, d );

  day_carry_common ( y, m, d );
/*
  Now make sure that the date does not fall in the
  Julian-to-Gregorian calendar switchover limbo.
*/
  if ( *y == 1582 )
  {
    if ( *m == 10 )
    {
      if ( 5 <= *d && *d <= 14 )
      {
        fprintf ( stderr, "\n" );
        fprintf ( stderr, "YMD_CHECK_COMMON - Fatal error!\n" );
        fprintf ( stderr, "  Illegal date in Julian-to-Gregorian transition.\n" );
        exit ( 1 );
      }
    }
  }
  return;
}
/******************************************************************************/

void ymd_check_gregorian ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    YMD_CHECK_GREGORIAN checks a Gregorian YMD date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date, which may
    be corrected if necessary and possible.
*/
{
/*
  Check the month.
*/
  ym_check_gregorian ( y, m );
/*
  Check the day.
*/
  day_borrow_gregorian ( y, m, d );

  day_carry_gregorian ( y, m, d );

  return;
}
/******************************************************************************/

void ymd_check_julian ( int *y, int *m, int *d )

/******************************************************************************/
/*
  Purpose:

    YMD_CHECK_JULIAN checks a Julian YMD date.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input/output, int *Y, *M, *D, the YMD date, which may
    be corrected if necessary and possible.
*/
{
/*
  Check the month.
*/
  ym_check_julian ( y, m );
/*
  Check the day.
*/
  day_borrow_julian ( y, m, d );

  day_carry_julian ( y, m, d );

  return;
}
/******************************************************************************/

char ymd_compare ( int y1, int m1, int d1, int y2, int m2, int d2 )

/******************************************************************************/
/*
  Purpose:

    YMD_COMPARE compares two YMD dates.

  Discussion:

    The comparison should work for a pair of dates in any calendar.

    No check is made that the dates are actually legitimate.  It is
    assumed that the calling routine has already ensured that the
    dates are properly "normalized".

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y1, int M1, int D1, the first YMD date.

    Input, int Y2, int M2, int D2, the second YMD date.

    Output, char YMD_COMPARE:
    '<' if date 1 precedes date 2;
    '=' if date 1 equals date 2;
    '>' if date 1 follows date 2;
*/
{
  char cmp;

  cmp = '?';

  if ( y1 < y2 )
  {
    cmp = '<';
  }
  else if ( y1 > y2 )
  {
    cmp = '>';
  }
  else
  {
    if ( m1 < m2 )
    {
      cmp = '<';
    }
    else if ( m1 > m2 )
    {
      cmp = '>';
    }
    else
    {
      if ( d1 < d2 )
      {
        cmp = '<';
      }
      else if ( d1 > d2 )
      {
        cmp = '>';
      }
      else
      {
        cmp = '=';
      }
    }
  }
  return cmp;
}
/******************************************************************************/

int ymd_dif_common ( int y1, int m1, int d1, int y2, int m2, int d2 )

/******************************************************************************/
/*
  Purpose:

    YMD_DIF_COMMON gets the day difference between two Common YMD dates.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y1, M1, D1, the first YMD date.

    Input, int Y2, M2, D2, the second YMD date.

    Output, int YMD_DIF_COMMON, the number of days between the dates.
*/
{
  int days;
  double jed1;
  double jed2;

  days = 0;
/*
  Check the dates.
*/
  ymd_check_common ( &y1, &m1, &d1 );

  ymd_check_common ( &y2, &m2, &d2 );

  jed1 = ymd_to_jed_common ( y1, m1, d1 );

  jed2 = ymd_to_jed_common ( y2, m2, d2 );

  days = ( int ) ( round ( jed2 - jed1 ) );

  return days;
}
/******************************************************************************/

double ymd_to_decimal ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_DECIMAL converts a Y/M/D date to a Decimal Y.F date.

  Discussion:

    The day is assumed to be at noon.  In other words, 1983 January 1st has
    a decimal value of 1983 + 0.5 / 365.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, double YMD_TO_DECIMAL, the Decimal date.
*/
{
  int d2;
  int day_max;
  int days;
  double f;
  int m2;
  double yf;
/*
  How many days between January 1st and day D?
*/
  m2 = 1;
  d2 = 1;
  days = ymd_dif_common ( y, m2, d2, y, m, d );
/*
  How many days in this year total?
*/
  day_max = year_length_days_common ( y );
/*
  The decimal part of the year is ( D + 0.5 ) / DMAX.
*/
  f = ( ( double ) ( days ) + 0.5 ) 
      / ( double ) ( day_max );

  yf = ( double ) ( y ) + f;

  return yf;
}
/******************************************************************************/

void ymd_to_decimal_test ( )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_DECIMAL_TEST tests YMD_TO_DECIMAL

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 December 2017

  Author:

    John Burkardt
*/
{
  int d;
  int dhi = 1;
  int dlo = 1;
  double f;
  double fhi = 0.0;
  double flo = 0.0;
  int i;
  int m;
  int mhi = 1;
  int mlo = 1;
  char *s;
  int seed = 123456789;
  int y;
  double yf;
  int yhi = 1970;
  int ylo = 1960;

  printf ( "\n" );
  printf ( "YMD_TO_DECIMAL_TEST\n" );
  printf ( "  YMD_TO_DECIMAL converts a date to a year and decimal.\n" );
  printf ( "\n" );
  printf ( "  YMD                         Y.F\n" );
  printf ( "\n" );
 
  for ( i = 1; i <= 10; i++ )
  {
    ymdf_uniform_common ( ylo, mlo, dlo, flo, yhi, mhi, dhi, fhi, 
      &seed, &y, &m, &d, &f );

    s = ymd_to_s_common ( y, m, d );

    yf = ymd_to_decimal ( y, m, d );

    printf ( "  %13s  %f14.8\n", s, yf );

    free ( s );
  }

  return;
}
/******************************************************************************/

double ymd_to_jed_common ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_JED_COMMON converts a Common YMD date to a JED.

  Discussion:

    The "common" calendar is meant to be the calendar which is Julian up to
    day JED = 2299160, and Gregorian from day JED = 2299161 and after.

    The Julian Ephemeris Date is essentially a count of the number
    of days that have elapsed since noon, 1 January 4713 BC, at
    Greenwich, England.  Strictly speaking, the Julian Ephemeris Date
    is counted from noon, and thus day "0" began at noon on 1 January 4713 BC,
    and ended at noon on 2 January 4713 BC.

    The Julian Ephemeris Date was devised by Joseph Scaliger in 1583.

    The Julian Ephemeris Date has been adopted by astronomers as
    a convenient reference for dates.

  Example:

       Y   M     D         JED
    --------------     -------
    BC 4713 Jan  1           0
    AD 1968 May 23     2440000
    AD 1984 Dec 31     2446065

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 October 2012

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, double YMD_TO_JED_COMMON, the Julian Ephemeris Date.
*/
{
  char cmp;
  int d1;
  int d2;
  double jed;
  int m1;
  int m2;
  int y1;
  int y2;
/*
  Copy the month and year.
*/
  y1 = y;
  m1 = m;
  d1 = d;

  ymd_check_common ( &y1, &m1, &d1 );

  y2 = 1582;
  m2 = 10;
  d2 = 4+1;

  cmp = ymd_compare ( y1, m1, d1, y2, m2, d2 );

  if ( cmp == '<' )
  {
    jed = ymd_to_jed_julian ( y1, m1, d1 );
    return jed;
  }
/*
  Use the Gregorian calendar for dates strictly after 1752/9/13.
*/
  y2 = 1582;
  m2 = 10;
  d2 = 15-1;

  cmp = ymd_compare ( y1, m1, d1, y2, m2, d2 );

  if ( cmp == '>' )
  {
    jed = ymd_to_jed_gregorian ( y1, m1, d1 );
    return jed;
  }

  jed = -1.0;
  fprintf ( stderr, "\n" );
  fprintf ( stderr, "YMD_TO_JED_COMMON - Error!\n" );
  fprintf ( stderr, "  Illegal date!\n" );
  exit ( 1 );
}
/******************************************************************************/

double ymd_to_jed_gregorian ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_JED_GREGORIAN converts a Gregorian YMD date to a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm E,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, pages 323-324.

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, double YMD_TO_JED_GREGORIAN, the corresponding JED.
*/
{
  int d_prime;
  int g;
  double jed;
  int j1;
  int j2;
  int m_prime;
  int y2;
  int y_prime;
/*
  Account for the missing year 0 by moving negative years up one.
*/
  y2 = y_common_to_astronomical ( y );
/*
  Convert the calendar date to a computational date.
*/
  y_prime = y2 + 4716 - ( 14 - m ) / 12;
  m_prime = ( ( m + 9 ) % 12 );
  d_prime = d - 1;
/*
  Convert the computational date to a JED.
*/
  j1 = ( 1461 * y_prime ) / 4;

  j2 = ( 153 * m_prime + 2 ) / 5;

  g = ( 3 * ( ( y_prime + 184 ) / 100 ) / 4 ) - 38;

  jed = ( double ) ( j1 + j2 + d_prime - 1401 - g ) - 0.5;

  return jed;
}
/******************************************************************************/

double ymd_to_jed_julian ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_JED_JULIAN converts a Julian YMD date to a JED.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm E,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, pages 323-324.

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, double YMD_TO_JED_JULIAN, the Julian Ephemeris Date.
*/
{
  int d_prime;
  double jed;
  int j1;
  int j2;
  int m_prime;
  int y2;
  int y_prime;
/*
  Account for the missing year 0 by moving negative years up one.
*/
  y2 = y_common_to_astronomical ( y );
/*
  Convert the calendar date to a computational date.
*/
  y_prime = y2 + 4716 - ( 14 - m ) / 12;
  m_prime = ( ( m + 9 ) % 12 );
  d_prime = d - 1;
/*
  Convert the computational date to a JED.
*/
  j1 = ( 1461 * y_prime ) / 4;

  j2 = ( 153 * m_prime + 2 ) / 5;

  jed = ( double ) ( j1 + j2 + d_prime - 1401 ) - 0.5;

  return jed;
}
/******************************************************************************/

char *ymd_to_s_common ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_S_COMMON writes a Common YMD date into a string.

  Format:

    CE YYYY/MM/DD
    BCE YYYY/MM/DD

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, char *YMD_TO_S_COMMON, a representation of the date.
*/
{
  char *value;

  value = ( char * ) malloc ( 14 * sizeof ( char ) );

  if ( y < 0 )
  {
    sprintf ( value, "BCE %d/%02d/%02d", - y, m, d );
  }
  else
  {
    sprintf ( value, "CE %d/%02d/%02d", y, m, d );
  }

  return value;
}
/******************************************************************************/

char *ymd_to_s_gregorian ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_S_GREGORIAN writes a Gregorian YMD date into a string.

  Format:

    AD YYYY/MM/DD
    BC YYYY/MM/DD

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, char *YMD_TO_S_GREGORIAN, a representation of the date.
*/
{
  char *value;

  value = ( char * ) malloc ( 14 * sizeof ( char ) );

  if ( y < 0 )
  {
    sprintf ( value, "BC %d/%02d/%02d", - y, m, d );
  }
  else
  {
    sprintf ( value, "AD %d/%02d/%02d", y, m, d );
  }

  return value;
}
/******************************************************************************/

char *ymd_to_s_julian ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_S_JULIAN writes a Juian YMD date into a string.

  Format:

    AD YYYY/MM/DD
    BC YYYY/MM/DD

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2018

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, the YMD date.

    Output, char *YMD_TO_S_JULIAN, a representation of the date.
*/
{
  char *value;

  value = ( char * ) malloc ( 14 * sizeof ( char ) );

  if ( y < 0 )
  {
    sprintf ( value, "BC %d/%02d/%02d", - y, m, d );
  }
  else
  {
    sprintf ( value, "AD %d/%02d/%02d", y, m, d );
  }

  return value;
}
/******************************************************************************/

int ymd_to_weekday_common ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_WEEKDAY_COMMON returns the weekday of a Common YMD date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, int M, int D, the YMD date.

    Output, int W, is the week day number of the date, with
    1 for Sunday, through 7 for Saturday.
*/
{
  double f1;
  double f2;
  double jed;
  int w;

  f1 = 0.5;
  jed = ymdf_to_jed_common ( y, m, d, f1 );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
/******************************************************************************/

void ymd_to_weekday_common_test ( )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_WEEKDAY_COMMON_TEST tests YMD_TO_WEEKDAY_COMMON.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 July 2017

  Author:

    John Burkardt
*/
{
  int d;
  int m;
  int n_data;
  char *s1;
  char *s2;
  char *s3;
  int w1;
  int w2;
  int y;

  printf ( "\n" );
  printf ( "YMD_TO_WEEKDAY_COMMON_TEST\n" );
  printf ( "  YMD_TO_WEEKDAY_COMMON returns the day of the week\n" );
  printf ( "  for dates in the Common calendar:\n" );
  printf ( "\n" );
  printf ( "  YMD                   Weekday    Weekday\n" );
  printf ( "                        Tabulated  Computed\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    weekday_values ( &n_data, &y, &m, &d, &w1 );

    if ( n_data == 0 )
    {
      break;
    }

    s3 = ymd_to_s_common ( y, m, d );
    w2 = ymd_to_weekday_common ( y, m, d );
    s1 = weekday_to_name_common ( w1 );
    s2 = weekday_to_name_common ( w2 );

    printf ( "  %20s  %9s  %9s\n", s3, s1, s2 );

    free ( s1 );
    free ( s2 );
    free ( s3 );
  }
  return;
}
/******************************************************************************/

int ymd_to_weekday_english ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_WEEKDAY_ENGLISH returns the weekday of an English YMD date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, int M, int D, the YMD date.

    Output, int W, is the week day number of the date, with
    1 for Sunday, through 7 for Saturday.
*/
{
  double f1;
  double f2;
  double jed;
  int w;

  f1 = 0.5;

  jed = ymdf_to_jed_english ( y, m, d, f1 );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
/******************************************************************************/

int ymd_to_weekday_gregorian ( int y, int m, int d )

/******************************************************************************/
/*
  Purpose:

    YMD_TO_WEEKDAY_GREGORIAN returns the weekday of a Gregorian YMD date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, int M, int D, the YMD date.

    Output, int W, is the week day number of the date, with
    1 for Sunday, through 7 for Saturday.
*/
{
  double f1;
  double f2;
  double jed;
  int w;

  f1 = 0.5;

  jed = ymdf_to_jed_gregorian ( y, m, d, f1 );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
/******************************************************************************/

char ymdf_compare ( int y1, int m1, int d1, double f1, int y2, int m2, int d2, 
  double f2 )

/******************************************************************************/
/*
  Purpose:

    YMDF_COMPARE compares two YMDF dates.

  Discussion:

    The comparison should work for a pair of dates in any calendar.

    No check is made that the dates are actually legitimate.  It is
    assumed that the calling routine has already ensured that the
    dates are properly "normalized".

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y1, int M1, int D1, double F1, the 
    first YMDF date.

    Input, int Y2, int M2, int D2, double F2, the 
    second YMDF date.

    Output, char YMDF_COMPARE:
    '<' if date 1 precedes date 2;
    '=' if date 1 equals date 2;
    '>' if date 1 follows date 2;
*/
{
  char cmp;

  cmp = '?';

  if ( y1 < y2 )
  {
    cmp = '<';
  }
  else if ( y1 > y2 )
  {
    cmp = '>';
  }
  else
  {
    if ( m1 < m2 )
    {
      cmp = '<';
    }
    else if ( m1 > m2 )
    {
      cmp = '>';
    }
    else
    {
      if ( d1 < d2 )
      {
        cmp = '<';
      }
      else if ( d1 > d2 )
      {
        cmp = '>';
      }
      else
      {
        if ( f1 < f2 )
        {
          cmp = '<';
        }
        else if ( f1 > f2 )
        {
          cmp = '>';
        }
        else
        {
          cmp = '=';
        }
      }
    }
  }
  return cmp;
}
/******************************************************************************/

void ymdf_next_common ( int y1, int m1, int d1, double f1, int *y2, int *m2, 
  int *d2, double *f2 )

/******************************************************************************/
/*
  Purpose:

    YMDF_NEXT_COMMON returns the Common YMDF date of the next day.

  Discussion:

    The routine knows that in the Common calendar, the day after
    4 October 1582 was 15 October 1582.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y1, M1, D1, double F1, 
    the YMDF date.

    Output, int *Y2, *M2, *D2, double *F2,
    tomorrow's YMDF date.
*/
{
  *y2 = y1;
  *m2 = m1;
  *d2 = d1 + 1;
  *f2 = f1;

  day_carry_common ( y2, m2, d2 );

  return;
}
/******************************************************************************/

double ymdf_to_jed_common ( int y, int m, int d, double f )

/******************************************************************************/
/*
  Purpose:

    YMDF_TO_JED_COMMON converts a Common YMDF date to a JED.

  Discussion:

    The "common" calendar is meant to be the calendar which is Julian up to
    day JED = 2299160, and Gregorian from day JED = 2299161 and after.

    The Julian Ephemeris Date is essentially a count of the number
    of days that have elapsed since noon, 1 January 4713 BC, at
    Greenwich, England.  Strictly speaking, the Julian Ephemeris Date
    is counted from noon, and thus day "0" began at noon on 1 January 4713 BC,
    and ended at noon on 2 January 4713 BC.

    The Julian Ephemeris Date was devised by Joseph Scaliger in 1583.

    The Julian Ephemeris Date has been adopted by astronomers as
    a convenient reference for dates.

  Example:

       Y   M     D         JED
    --------------     -------
    BC 4713 Jan  1           0
    AD 1968 May 23     2440000
    AD 1984 Dec 31     2446065

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, double F, the YMDF date.

    Output, double YMDF_TO_JED_COMMON, the Julian Ephemeris Date.
*/
{
  char cmp;
  int d1;
  int d2;
  double f1;
  double f2;
  double jed;
  int m1;
  int m2;
  int y1;
  int y2;
/*
  Copy the month and year.
*/
  y1 = y;
  m1 = m;
  d1 = d;
  f1 = f;

  y2 = 1582;
  m2 = 10;
  d2 = 4+1;
  f2 = 0.0;

  cmp = ymdf_compare ( y1, m1, d1, f1, y2, m2, d2, f2 );

  if ( cmp == '<' )
  {
    jed = ymdf_to_jed_julian ( y1, m1, d1, f1 );
    return jed;
  }
/*
  Use the Gregorian calendar for dates strictly after 1752/9/13.
*/
  y2 = 1582;
  m2 = 10;
  d2 = 15-1;
  f2 = 0.0;

  cmp = ymdf_compare ( y1, m1, d1, f1, y2, m2, d2, f2 );

  if ( cmp == '>' )
  {
    jed = ymdf_to_jed_gregorian ( y1, m1, d1, f1 );
    return jed;
  }

  fprintf ( stderr, "\n" );
  fprintf ( stderr, " 'YMDF_TO_JED_COMMON - Fatal error!\n" );
  fprintf ( stderr, "  Illegal date!\n" );
  exit ( 1 );
}
/******************************************************************************/

double ymdf_to_jed_english ( int y, int m, int d, double f )

/******************************************************************************/
/*
  Purpose:

    YMDF_TO_JED_ENGLISH converts an English YMDF date to a JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Parameters:

    Input, int Y, int M, int D, double F, the YMDF date.

    Output, double JED, the Julian Ephemeris Date.
*/
{
  char cmp;
  int d1;
  int d2;
  double f1;
  double f2;
  double jed;
  int m1;
  int m2;
  int y1;
  int y2;
/*
  Use the Julian Calendar for dates strictly before 1752/9/3.
*/
  y1 = 1752;
  m1 = 9;
  d1 = 3;
  f1 = 0.0;

  cmp = ymdf_compare ( y, m, d, f, y1, m1, d1, f1 );

  if ( cmp == '<' )
  {
    jed = ymdf_to_jed_julian ( y, m, d, f );
    return jed;
  }
/*
  Use the Gregorian calendar for dates strictly after 1752/9/13.
*/
  y2 = 1752;
  m2 = 9;
  d2 = 13;
  f2 = 0.0;

  cmp = ymdf_compare ( y, m, d, f, y2, m2, d2, f2 );

  if ( cmp == '>' )
  {
    jed = ymdf_to_jed_gregorian ( y, m, d, f );
    return jed;
  }
/*
  Error return if the date falls between the transition dates.
*/
  fprintf ( stderr, "\n" );
  fprintf ( stderr, "YMDF_TO_JED_ENGLISH - Fatal error!\n" );
  fprintf ( stderr, "  Date is illegal.\n" );
  exit ( 1 );
}
/******************************************************************************/

double ymdf_to_jed_gregorian ( int y, int m, int d, double f )

/******************************************************************************/
/*
  Purpose:

    YMDF_TO_JED_GREGORIAN converts a Gregorian YMDF date to a JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2009

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm E,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, pages 323-324.

  Parameters:

    Input, int Y, int M, int D, double F, the YMDF date.

    Output, double YMDF_TO_JED_GREGORIAN, the corresponding JED.
*/
{
  int d_prime;
  int g;
  double jed;
  int j1;
  int j2;
  int m_prime;
  int y_prime;
/*
  Account for the missing year 0 by moving negative years up one.
*/
  y = y_common_to_astronomical ( y );
/*
  Convert the calendar date to a computational date.
*/
  y_prime = y + 4716 - ( 14 - m ) / 12;
  m_prime = ( ( m + 9 ) % 12 );
  d_prime = d - 1;
/*
  Convert the computational date to a JED.
*/
  j1 = ( 1461 * y_prime ) / 4;

  j2 = ( 153 * m_prime + 2 ) / 5;

  g = ( 3 * ( ( y_prime + 184 ) / 100 ) / 4 ) - 38;

  jed = ( double ) ( j1 + j2 + d_prime - 1401 - g ) - 0.5;
  jed = jed + f;

  return jed;
}
/******************************************************************************/

double ymdf_to_jed_julian ( int y, int m, int d, double f )

/******************************************************************************/
/*
  Purpose:

    YMDF_TO_JED_JULIAN converts a Julian YMDF date to a JED.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 March 2010

  Author:

    John Burkardt

  Reference:

    Edward Richards,
    Algorithm E,
    Mapping Time, The Calendar and Its History,
    Oxford, 1999, pages 323-324.

  Parameters:

    Input, int Y, int M, int D, double F, the YMDF date.

    Output, double YMDF_TO_JED_JULIAN, the Julian Ephemeris Date.
*/
{
  int d_prime;
  double jed;
  int j1;
  int j2;
  int m_prime;
  int y_prime;
/*
  Account for the missing year 0 by moving negative years up one.
*/
  y = y_common_to_astronomical ( y );
/*
  Convert the calendar date to a computational date.
*/
  y_prime = y + 4716 - ( 14 - m ) / 12;
  m_prime = ( ( m + 9 ) % 12 );
  d_prime = d - 1;
/*
  Convert the computational date to a JED.
*/
  j1 = ( 1461 * y_prime ) / 4;

  j2 = ( 153 * m_prime + 2 ) / 5;

  jed = ( double ) ( j1 + j2 + d_prime - 1401 ) - 0.5;
  jed = jed + f;

  return jed;
}
/******************************************************************************/

char *ymdf_to_s_common ( int y, int m, int d, double f )

/******************************************************************************/
/*
  Purpose:

    YMDF_TO_S_COMMON writes a Common YMDF date into a string.

  Format:

    CE YYYY/MM/DD.FF
    BCE YYYY/MM/DD.FF

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, M, D, double F, the YMDF date.

    Output, char *YMDF_TO_S_COMMON, a representation of the date.
*/
{
  char *value;

  value = ( char * ) malloc ( 20 * sizeof ( char ) );

  if ( y < 0 )
  {
    sprintf ( value, "BCE %d/%02d/%02d%.2f", - y, m, d, f );
  }
  else
  {
    sprintf ( value, "CE %d/%02d/%02d%.2f", y, m, d, f );
  }

  return value;
}
/******************************************************************************/

int ymdf_to_weekday_common ( int y, int m, int d, double f )

/******************************************************************************/
/*
  Purpose:

    YMDF_TO_WEEKDAY_COMMON returns the weekday of a Common YMDF date.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y, int M, int D, double F, the YMDF date.

    Output, int W, is the week day number of the date, with
    1 for Sunday, through 7 for Saturday.
*/
{
  double f2;
  double jed;
  int w;

  jed = ymdf_to_jed_common ( y, m, d, f );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
/******************************************************************************/

void ymdf_uniform_common ( int y1, int m1, int d1, double f1, int y2, int m2, 
  int d2, double f2, int *seed, int *y, int *m, int *d, double *f )

/******************************************************************************/
/*
  Purpose:

    YMDF_UNIFORM_COMMON picks a random Common YMDF date between two given dates.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 December 2017

  Author:

    John Burkardt

  Parameters:

    Input, int Y1, M1, D1, double F1, the first YMDF date.

    Input, int Y2, M2, D2, double F2, the second YMDF date.

    Input/output, int *SEED, a seed for the random number generator.

    Output, int *Y, *M, *D, double *F, the random YMDF date.
*/
{
  double jed;
  double jed1;
  double jed2;

  jed1 = ymdf_to_jed_common ( y1, m1, d1, f1 );
  jed2 = ymdf_to_jed_common ( y2, m2, d2, f2 );

  jed = r8_uniform_ab ( jed1, jed2, seed );

  jed_to_ymdf_common ( jed, y, m, d, f );

  return;
}
