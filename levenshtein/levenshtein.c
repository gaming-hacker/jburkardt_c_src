# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "levenshtein.h"

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

   MAIN is the main program for LEVENSHTEIN_TEST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "LEVENSHTEIN_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LEVENSHTEIN library.\n" );

  levenshtein_distance_test ( );
  levenshtein_matrix_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LEVENSHTEIN_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
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

int levenshtein_distance ( int m, char *s, int n, char *t )

/******************************************************************************/
/*
  Purpose:

   LEVENSHTEIN_DISTANCE computes the Levenshtein distance between strings.

  Discussion:

    Let S and T be source and target strings.  Consider the task of
    converting S to T in the minimal number of steps, involving
    * Insertion: insert a new character
    * Deletion: delete a character
    * Substitution: swap one character for another.
    The Levenshtein distance from S to T is the minimal number of such
    steps required to transform S into T.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 March 2018

  Author:

    John Burkardt

  Parameters:

    Input, int M, the length of string S.

    Input, char *S, the first string.

    Input, int N, the length of string T.

    Input, char *T, the second string.

    Output, int LEVENSHTEIN_DISTANCE, the Levenshtein distance between the
    two strings.
*/
{
  int *d;
  int distance;
  int i;
  int j;
  int substitution_cost;

  d = ( int * ) malloc ( ( m + 1 ) * ( n + 1 ) * sizeof ( int ) );

  d[0+0*(m+1)] = 0;
/*
  Source prefixes can be transformed into empty string by
  dropping all characters,
*/
  for ( i = 1; i <= m; i++ )
  {
    d[i+0*(m+1)] = i;
  }
/*
  Target prefixes can be reached from empty source prefix
  by inserting every character.
*/
  for ( j = 1; j <= n; j++ )
  {
    d[0+j*(m+1)] = j;
  }

  for ( j = 1; j <= n; j++ )
  {
    for ( i = 1; i <= m; i++ )
    {
      if ( s[i-1] == t[j-1] )
      {
        substitution_cost = 0;
      }
      else
      {
        substitution_cost = 1;
      }
      d[i+j*(m+1)] = i4_min ( d[i-1+j*(m+1)] + 1, 
                     i4_min ( d[i+(j-1)*(m+1)] + 1, 
                              d[i-1+(j-1)*(m+1)] + substitution_cost ) );
    }
  }
 
  distance = d[m+n*(m+1)];

  free ( d );

  return distance;
}
/******************************************************************************/

void levenshtein_distance_test ( )

/******************************************************************************/
/*
  Purpose:

   LEVENSHTEIN_DISTANCE_TEST tests LEVENSHTEIN_DISTANCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 March 2018

  Author:

    John Burkardt
*/
{
  int d1;
  int d2;
  int m;
  int n;
  char *s1 = "water";
  char *s2 = "kitten";
  char *s3 = "saturday";
  char *s4 = "pheromones";
  char *t1 = "wine";
  char *t2 = "sitting";
  char *t3 = "sunday";
  char *t4 = "photographer";

  printf ( "\n" );
  printf ( "LEVENSHTEIN_DISTANCE_TEST:\n" );
  printf ( "  LEVENSHTEIN_DISTANCE computes the Levenshtein distance\n" );
  printf ( "  between two strings.\n" );

  m = strlen ( s1 );
  n = strlen ( t1 );
  d1 = levenshtein_distance ( m, s1, n, t1 );
  d2 = 3;
  printf ( "\n" );
  printf ( "  S = '%s'\n", s1 );
  printf ( "  T = '%s'\n", t1 );
  printf ( "  Computed distance = %d\n", d1 );
  printf ( "  Correct distance  = %d\n", d2 );

  m = strlen ( s2 );
  n = strlen ( t2 );
  d1 = levenshtein_distance ( m, s2, n, t2 );
  d2 = 3;
  printf ( "\n" );
  printf ( "  S = '%s'\n", s2 );
  printf ( "  T = '%s'\n", t2 );
  printf ( "  Computed distance = %d\n", d1 );
  printf ( "  Correct distance  = %d\n", d2 );

  m = strlen ( s3 );
  n = strlen ( t3 );
  d1 = levenshtein_distance ( m, s3, n, t3 );
  d2 = 3;
  printf ( "\n" );
  printf ( "  S = '%s'\n", s3 );
  printf ( "  T = '%s'\n", t3 );
  printf ( "  Computed distance = %d\n", d1 );
  printf ( "  Correct distance  = %d\n", d2 );

  m = strlen ( s4 );
  n = strlen ( t4 );
  d1 = levenshtein_distance ( m, s4, n, t4 );
  d2 = 8;
  printf ( "\n" );
  printf ( "  S = '%s'\n", s4 );
  printf ( "  T = '%s'\n", t4 );
  printf ( "  Computed distance = %d\n", d1 );
  printf ( "  Correct distance  = %d\n", d2 );

  return;
}
/******************************************************************************/

int *levenshtein_matrix ( int m, char *s, int n, char *t )

/******************************************************************************/
/*
  Purpose:

   LEVENSHTEIN_MATRIX computes the Levenshtein distance matrix between strings.

  Discussion:

    Let S and T be source and target strings.  Consider the task of
    converting S to T in the minimal number of steps, involving
    * Insertion: insert a new character
    * Deletion: delete a character
    * Substitution: swap one character for another.
    The Levenshtein distance from S to T is the minimal number of such
    steps required to transform S into T.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 March 2018

  Author:

    John Burkardt

  Parameters:

  Parameters:

    Input, int M, the length of string S.

    Input, char *S, the first string.

    Input, int N, the length of string T.

    Input, char *T, the second string.

    Output, int D[(M+1)*(N+1)], the Levenshtein matrix.
*/
{
  int *d;
  int i;
  int j;
  int substitution_cost;

  d = ( int * ) malloc ( ( m + 1 ) * ( n + 1 ) * sizeof ( int ) );

  d[0+0*(m+1)] = 0;
/*
  Source prefixes can be transformed into empty string by
  dropping all characters,
*/
  for ( i = 1; i <= m; i++ )
  {
    d[i+0*(m+1)] = i;
  }
/*
  Target prefixes can be reached from empty source prefix
  by inserting every character.
*/
  for ( j = 1; j <= n; j++ )
  {
    d[0+j*(m+1)] = j;
  }

  for ( j = 1; j <= n; j++ )
  {
    for ( i = 1; i <= m; i++ )
    {
      if ( s[i-1] == t[j-1] )
      {
        substitution_cost = 0;
      }
      else
      {
        substitution_cost = 1;
      }
      d[i+j*(m+1)] = i4_min ( d[i-1+j*(m+1)] + 1, 
                     i4_min ( d[i+(j-1)*(m+1)] + 1, 
                              d[i-1+(j-1)*(m+1)] + substitution_cost ) );
    }
  }
 
  return d;
}
/******************************************************************************/

void levenshtein_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

   LEVENSHTEIN_MATRIX_TEST tests LEVENSHTEIN_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 March 2018

  Author:

    John Burkardt
*/
{
  int *d;
  int i;
  int j;
  int m;
  int n;
  char *s1 = "water";
  char *s2 = "kitten";
  char *s3 = "saturday";
  char *s4 = "pheromones";
  char *t1 = "wine";
  char *t2 = "sitting";
  char *t3 = "sunday";
  char *t4 = "photographer";

  printf ( "\n" );
  printf ( "LEVENSHTEIN_MATRIX_TEST:\n" );
  printf ( "  LEVENSHTEIN_MATRIX computes the Levenshtein matrix\n" );
  printf ( "  associated with the computation of the Levenshtein\n" );
  printf ( "  distance between two strings.\n" );

  m = strlen ( s1 );
  n = strlen ( t1 );
  d = levenshtein_matrix ( m, s1, n, t1 );
  printf ( "\n" );
  printf ( "  S = '%s'\n", s1 );
  printf ( "  T = '%s'\n", t1 );
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      printf ( " %2d", d[i+j*(m+1)] );
    }
    printf ( "\n" );
  }
  free ( d );

  m = strlen ( s2 );
  n = strlen ( t2 );
  d = levenshtein_matrix ( m, s2, n, t2 );
  printf ( "\n" );
  printf ( "  S = '%s'\n", s2 );
  printf ( "  T = '%s'\n", t2 );
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      printf ( " %2d", d[i+j*(m+1)] );
    }
    printf ( "\n" );
  }
  free ( d );

  m = strlen ( s3 );
  n = strlen ( t3 );
  d = levenshtein_matrix ( m, s3, n, t3 );
  printf ( "\n" );
  printf ( "  S = '%s'\n", s3 );
  printf ( "  T = '%s'\n", t3 );
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      printf ( " %2d", d[i+j*(m+1)] );
    }
    printf ( "\n" );
  }
  free ( d );

  m = strlen ( s4 );
  n = strlen ( t4 );
  d = levenshtein_matrix ( m, s4, n, t4 );
  printf ( "\n" );
  printf ( "  S = '%s'\n", s4 );
  printf ( "  T = '%s'\n", t4 );
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      printf ( " %2d", d[i+j*(m+1)] );
    }
    printf ( "\n" );
  }
  free ( d );

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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
