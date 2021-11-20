# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BIG 4096

# define NAMELENGTH 31

# define MAX_RECORD 255

int blkdatano = 0;

int main ( int argc, char **argv );
int compare ( char **s0, char *t );
int endcard ( char *s );
void get_name ( char *s, char *f );
void split_file ( FILE *file_input );

/******************************************************************************/

int main ( int argc, char **argv )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for F90SPLIT.

  Discussion:

    F90SPLIT splits a file of FORTRAN90 modules into individual files. 

    Procedure X is put in file X.f90.

    Comments preceding a procedure, and not associated with a 
    preceding procedure, are included with that procedure.

    You cannot use the more elaborate END statements that include the
    procedure definition, such as "END FUNCTION ALPHA".

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 December 2007

  Author:

    John Burkardt
*/
{
  FILE *file_input;
  int i;

  for ( i = 1; i < argc; ++i ) 
  {    
    printf ( "Splitting '%s'.\n", argv[i] );

    file_input = fopen ( argv[i], "r" );

    if ( file_input == NULL ) 
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "FSPLIT90: Error!\n" );
      fprintf ( stderr, "  Cannot open '%s'\n", argv[i] );
      continue;
    }

    split_file ( file_input );

    fclose ( file_input );
  }

  return 0;
}
/******************************************************************************/

int compare ( char **s0, char *t )

/******************************************************************************/
/* 
  Purpose:

    compare() compares two strings for equality.  

  Discussion:

    Assume that t is all lower case.  
    Ignore blanks and decase s during comparison. 

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 December 2007

  Author:

    John Burkardt

  Input:

    char **s0: the first string.

    char *t: the second string.

  Output:

    char **s0: points to next character after successful comparison.

    int compare: true if the strings are equal.
*/
{
  char *s;
  int s1;
  bool value;
  
  s = *s0;
  
  while ( *t ) 
  {
    while ( isspace ( *s ) ) 
    {
      ++s;
    }
    s1 = *s++;

    if ( isupper ( s1 ) ) 
    {
      s1 = tolower ( s1 );
    }

    if ( s1 != *t++ ) 
    {
      value = false;
      return value;
    }

  }
  *s0 = s;
  value = true;
  return value;
}
/******************************************************************************/
 
int endcard ( char *s )

/******************************************************************************/
/*
  Purpose:

    ENDCARD checks to see whether the current record is an END statement.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 December 2007

  Author:

    John Burkardt

  Input:

    char *s: the current record.

  Output:

    int endcard: true if this record is a kind of END statement.
*/
{
  bool value;
/*  
  Column 1 of card image              
*/
  char *s0 = s;                
 
  if ( *s == 0 ) 
  {
    value = true;
    return value;
  } 
/*
  Search for "end" statement somewhere in the card image
*/
  while ( isspace ( *s ) ) 
  {
    ++s;
  }

  if ( *s != 'e' && *s != 'E' )
  {
    value = false;
    return value;
  }

  s++; 

  while ( isspace(*s) )
  {
    ++s;
  }

  if ( *s != 'n' && *s != 'N' )
  {
    value = false;
    return value;
  }

  s++; 
  while ( isspace(*s) )  
  {
    ++s;
  }

  if ( *s != 'd' && *s != 'D' ) 
  {
    value = false;
    return value;
  }

  s++; 
  while ( isspace(*s) ) 
  {
    ++s;
  }
 
/*      
  Legitimate ending to "END" card?
  This must be modified to handle lines like "END FUNCTION".
*/
  if ( *s == '\0' || *s == '!' || *s == '\n' || MAX_RECORD <= ( s - s0 ) ) 
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

void get_name ( char *s, char *f )

/******************************************************************************/
/*
  Purpose:

    get_name() creates a file name based on the name of the current module.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 December 2007

  Author:

    John Burkardt

  Input:

    char *s: a record that presumably contains a module name.

    char *f:
*/
{
  int i;
/*
  *S0 is the address of the first column of the card.
*/
  int count = 0;
  char *s0 = s;

  loop:

    if      ( compare ( &s, "function" ) ) 
    {
      goto bot;
    }
    else if ( compare ( &s, "module" ) ) 
    {
      goto bot;
    }
    else if ( compare ( &s, "procedure" ) ) 
    {
      goto bot;
    }
    else if ( compare ( &s, "program" ) ) 
    {
      goto bot;
    }
    else if ( compare ( &s, "subroutine" ) ) 
    {
      goto bot;
    }
    else if ( compare ( &s, "character" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "complex" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "double" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "integer" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "logical" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "precision" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "real" ) ) 
    {
      goto loop;
    }
    else if ( compare ( &s, "recursive" ) ) 
    {
      goto loop;
    }
/* 
  Handle size complications like "complex *16" or "character *12".
*/
    else if ( compare ( &s, "*") )
    {
      for ( ++s ; isdigit ( *s ) || isspace ( *s )  ; ++s)
        ;
        goto loop;
      }
    else if ( compare ( &s, "blockdata" ) ) 
    {
      while ( isspace ( *s ) ) ++s;
/* 
  No block data name given.  Use "BLOCKDATA".
*/
      if (*s == '\0')
      {
        sprintf ( f, "BLOCKDATA%d.%s", ++blkdatano, "f90" );
        return;
      }
      goto bot;
    }
    else
    {
      s = "";
    }
 
  bot:

  while ( isspace ( *s ) ) 
  {
    ++s;
  }
/*
  Extract the module name.
*/
  for ( i = 0; isalpha ( *s ) || isdigit ( *s ) || *s == '_' ; i++ ) 
  {
    if ( NAMELENGTH <= i || MAX_RECORD <= ( s - s0 ) ) 
    {
      break;
    }
    f[i] = tolower ( *s++ );
    while ( isspace ( *s ) )
    {
      ++s;
    }
  }

/*
  Tack on the period and suffix to form the filename.
*/ 
  if ( 0 < i ) 
  {
    f[i++] = '.';
    f[i++] = 'f';
    f[i++] = '9';
    f[i++] = '0';
    f[i++] = '\0';
  }
  else
  {
    count = count + 1;
    sprintf ( f, "main%d.%s", count, "f90" );
  }

  return;
}
/******************************************************************************/

void split_file ( FILE *file_input )

/******************************************************************************/
/*
  Purpose:

    split_file() splits up the modules contained in a single file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 December 2007

  Author:

    John Burkardt
*/
{
  char file_out_name[NAMELENGTH];
  char file_temp_name[NAMELENGTH];
  FILE *file_temp;
  int i;
  char in[BIG];
  int nline;
/*
  Set FILE_TEMP_NAME to a template name.
*/
  strcpy ( file_temp_name, "fsplit.XXXXX" );
/*
  MKSTEMP replaces the 'X' characters in FILE_TEMP_NAME by characters that
  result in a unique file name.
*/
  ( void ) mkstemp ( file_temp_name );
/*
  Open the temporary file for write access.
*/
  file_temp = fopen ( file_temp_name, "w" );

  if ( file_temp == NULL ) 
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "FSPLIT90: Error!\n" );
    fprintf ( stderr, "  Can't open temporary file '%s'.\n", file_temp_name );
    exit ( EXIT_FAILURE );
  }
/*
  Read a line from the input unit.
*/
  nline = 0;

  while ( fgets ( in, BIG, file_input ) != NULL ) 
  {  
    nline = nline + 1;
/*
  If the line is a comment line, output it, and get the next line.
  We're really hoping to see a module name.
*/
    if ( *in=='c' || *in=='C' || *in=='*' || *in=='!' ) 
    {
      fputs ( in, file_temp );
      continue;
    }
    
    for ( i = 0; i < MAX_RECORD; i++ ) 
    {
      if ( in[i] == '\0' || in[i] == '\n')
      {
        i = MAX_RECORD;
        break;
      }
      
      if (in[i] != ' ' && in[i] != '\t')  
      {
        break;
      }      
    }
    
    if ( i == MAX_RECORD ) 
    {
      fputs ( in, file_temp );
      continue;
    }

    get_name ( in, file_out_name );

    if ( unlink(file_out_name),link(file_temp_name, file_out_name) == -1 || 
         unlink(file_temp_name) == -1) 
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "FSPLIT90: Error!\n" );
      fprintf ( stderr, "  Cannot move '%s' to '%s'\n", 
        file_temp_name, file_out_name );
      exit ( EXIT_FAILURE );
    }

    printf ( "%s\n", file_out_name );
      
    fputs ( in, file_temp );
/*
  Write all subsequent lines to this file until an END statement is encountered.
*/
    while ( !endcard(in) && fgets ( in, BIG, file_input ) ) 
    {    
      fputs ( in, file_temp );
    }
/*
  Close the current file, and open the next temporary file.
*/
    ( void ) fclose ( file_temp );

    file_temp = fopen ( file_temp_name, "w" );

    if ( file_temp == NULL )  
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "FSPLIT90: Error:\n" );
      fprintf ( stderr, "  Can't open temporary file '%s'.", file_temp_name );
      exit ( EXIT_FAILURE );
    }

  }
    
  if ( unlink ( file_temp_name ) == -1)
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "FSPLIT90: Error:\n" );
    fprintf ( stderr, "  Couldn't remove the temp file '%s'\n", file_temp_name );
    exit ( EXIT_FAILURE );
  }

  return;
}

