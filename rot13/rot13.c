# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int main ( int argc, char *argv[] );
char ch_to_rot13 ( char ch );
void handle ( char *input_filename, char *output_filename );
char *s_to_rot13 ( char *s );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ROT13.

  Discussion:

    ROT13 applies the "rot13" transformation to a file.

    This program reads a file, and writes a copy in which characters have
    been "rotated" 13 positions and digits have been "rotated" 5 positions.

  Usage:

    rot13 file1.txt

    creates a rotated copy named "svyr6.gkg"

    rot13 svyr5.gkg

    recovers the original file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 January 2016

  Author:

    John Burkardt
*/
{
  char input_filename[512];
  char *output_filename;
  bool VERBOSE = false;

  if ( VERBOSE )
  {
    timestamp ( );
    printf ( "\n" );
    printf ( "ROT13:\n" );
    printf ( "  C++ version\n" );
	printf ( "\n" );
    printf ( "  Copy a file, applying the rot13 rotation to characters,\n" );
	printf ( "  as well as a rot5 rotation to digits.\n" );
    printf ( "\n" );
    printf ( "  Compiled on %s at %s.\n", __DATE__, __TIME__ );
  }
/*
  If the input file was not on the command line, get it now.
*/
  if ( argc < 2 ) 
  {
    printf ( "\n" );
    printf ( "ROT13:\n" );
    printf ( "  Please enter the INPUT file name:\n" );
    scanf ( "%s", input_filename );
  }
  else 
  {
    strcpy ( input_filename, argv[1] );
  }
/*
  Create the output file name.
*/
  output_filename = s_to_rot13 ( input_filename );
  
  printf ( "\n" );
  printf ( "  Output file name is \"%s\".\n", output_filename );
/*
  Now we know the input and output file names, so go to it.
*/
  handle ( input_filename, output_filename );
/*
  Terminate.
*/
  if ( VERBOSE )
  {
    printf ( "\n" );
    printf ( "ROT13:\n" );
    printf ( "  Normal end of execution.\n" );
    printf ( "\n" );
    timestamp ( );
  }

  return 0;
}
/******************************************************************************/

char ch_to_rot13 ( char ch )

/******************************************************************************/
/*
  Purpose:

    CH_TO_ROT13 converts a character to its ROT13 equivalent.

  Discussion:

    Two applications of CH_TO_ROT13 to a character will return the original.!

    As a further scrambling, digits are similarly rotated using
    a "ROT5" scheme.

  Example:

    Input:  Output:

    a       n
    C       P
    J       W
    1       6
    5       0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2008

  Author:

    John Burkardt

  Parameters:

    Input, char CH, the character to be converted.

    Output, char CH_TO_ROT13, the ROT13 equivalent of the character.
*/
{
  char rot13;
/*
  [0:4] -> [5:9]
*/
  if ( '0' <= ch && ch <= '4' )
  {
    rot13 = ch + 5;
  }
/*
  [5:9] -> [0:4]
*/
  else if ( '5' <= ch && ch <= '9' )
  {
    rot13 = ch - 5;
  }
/*
  [A:M] -> [N:Z]
*/
  else if ( 'A' <= ch && ch <= 'M' )
  {
    rot13 = ch + 13;
  }
/*
  [N:Z] -> [A:M]
*/
  else if ( 'N' <= ch && ch <= 'Z' )
  {
    rot13 = ch - 13;
  }
/*
  [a:m] -> [n:z]
*/
  else if ( 'a' <= ch && ch <= 'm' )
  {
    rot13 = ch + 13;
  }
/*
  [n:z] -> [a:m]
*/
  else if ( 'n' <= ch && ch <= 'z' )
  {
    rot13 = ch - 13;
  }
  else
  {
    rot13 = ch;
  }

  return rot13;
}
/******************************************************************************/

void handle ( char *input_filename, char *output_filename )

/******************************************************************************/
/*
  Purpose:

    HANDLE makes a copy of a file after applying ROT13 to it.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 January 2016

  Author:

    John Burkardt

  Parameters:

    Input, string INPUT_FILENAME, the name of the input file.

    Input, string OUTPUT_FILENAME, the name of the output file.
*/
{
  char c1;
  char c2;
  int char_num;
  FILE *input;
  FILE *output;
  int line_num;
  bool VERBOSE = true;
/*
  Open the input and output files.
*/
  input = fopen ( input_filename, "rt" );

  if ( !input )
  {
    printf ( "\n" );
    printf ( "ROT13::HANDLE - Fatal error!\n" );
    printf ( "  Cannot open the input file \"%s\".\n", input_filename );
    exit ( 1 );
  }

  output = fopen ( output_filename, "wt" );

  if ( !output ) 
  {
    printf ( "\n" );
    printf ( "ROT13::HANDLE - Fatal error!\n" );
    printf ( "  Cannot open the output file \"%s\".\n", output_filename );
    exit ( 1 );
  }
/*
  Transfer characters from the input file to the output file.
*/
  char_num = 0;
  line_num = 0;

  while ( true ) 
  {
    c1 = getc ( input );

    if ( c1 == EOF )
    {
      break;
    }

    char_num = char_num + 1;

    if ( c1 == '\n' ) 
    {
      line_num = line_num + 1;
    }
	
	c2 = ch_to_rot13 ( c1 );

    putc ( c2, output );
  }
/*
  Close the files.
*/
  fclose ( input );

  fclose ( output );
/*
  Report.
*/
  if ( VERBOSE )
  {
    printf ( "\n" );
    printf ( "  The input file \"%s\" contains:\n", input_filename );
    printf ( "  %d characters.\n", char_num );
    printf ( "  %d lines.\n", line_num );
  }

  return;
}
/******************************************************************************/

char *s_to_rot13 ( char *s1 )

/******************************************************************************/
/*
  Purpose:

    S_TO_ROT13 "rotates" the alphabetical characters in a string by 13 positions.

  Discussion:

    Two applications of the routine will return the original string.

  Example:

    Input:                      Output:

    abcdefghijklmnopqrstuvwxyz  nopqrstuvwxyzabcdefghijklm
    Cher                        Pure
    James Thurston Howell       Wnzrf Guhefgba Ubjryy
    0123456789                  5678901234

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 January 2016

  Author:

    John Burkardt

  Parameters:

    Input, char *S1, a string to be "rotated".

    Output, char *S_TO_ROT13, the rotated string.
*/
{
  int s_len;
  char *s2;
  char *c2;

  s_len = strlen ( s1 );

  s2 = ( char * ) malloc ( ( s_len + 1 ) * sizeof ( char ) );
  c2 = s2;
  
  while ( *s1 != 0 )
  {
    *c2 = ch_to_rot13 ( *s1 );
    s1++;
    c2++;
  }
  *c2 = '\0';

  return s2;
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
