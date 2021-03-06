# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

int main ( int argc, char *argv[] );
char ch_cap ( char ch );
int ch_eqi ( char ch1, char ch2 );
int ch_to_digit ( char ch );
int file_column_count ( char *input_filename );
int file_row_count ( char *input_filename );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
double r8_abs ( double x );
double r8_acos ( double c );
double r8_huge ( );
double r8_max ( double x, double y );
double r8_min ( double x, double y );
void r8_swap ( double *x, double *y );
double *r8mat_data_read ( char *input_filename, int m, int n );
double r8mat_det_4d ( double a[] );
void r8mat_header_read ( char *input_filename, int *m, int *n );
int r8mat_solve ( int n, int rhs_num, double a[] );
void r8mat_transpose_print ( int m, int n, double a[], char *title );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 
  int ihi, int jhi, char *title );
double r8vec_angle_3d ( double u[], double v[] );
double *r8vec_cross_3d ( double v1[3], double v2[3] );
double r8vec_dot_product ( int n, double a1[], double a2[] );
double r8vec_max ( int n, double r8vec[] );
double r8vec_norm ( int dim_num, double x[] );
void r8vec_print ( int n, double a[], char *title );
void r8vec_transpose_print ( int n, double a[], char *title );
void r8vec_zero ( int n, double a[] );
int s_len_trim ( char *s );
double s_to_r8 ( char *s, int *lchar, int *error );
int s_to_r8vec ( char *s, int n, double rvec[] );
int s_word_count ( char *s );
double *tetrahedron_centroid ( double tetra[3*4] );
void tetrahedron_circumsphere ( double tetra[3*4], double *r, double pc[3] );
double *tetrahedron_dihedral_angles ( double tetra[] );
double *tetrahedron_edge_length ( double tetra[3*4] );
void tetrahedron_edges ( double tetra[3*4], double ab[], double ac[],
  double ad[], double bc[], double bd[], double cd[] );
void tetrahedron_face_angles ( double tetra[], double angles[] );
void tetrahedron_face_areas ( double tetra[], double areas[] );
void tetrahedron_insphere ( double tetra[3*4], double *r, double pc[3] );
double tetrahedron_quality1 ( double tetra[3*4] );
double tetrahedron_quality2 ( double tetra[3*4] );
double tetrahedron_quality3 ( double tetra[3*4] );
double tetrahedron_quality4 ( double tetra[3*4] );
double *tetrahedron_solid_angles ( double tetra[] );
double tetrahedron_volume ( double tetra[3*4] );
void timestamp ( );
void triangle_angles_3d ( double t[3*3], double angle[3] );
double triangle_area_3d ( double t[3*3] );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TETRAHEDRON_PROPERTIES.


  Discussion:

    TETRAHEDRON_PROPERTIES reports properties of a tetrahedron.

  Usage:

    tetrahedron_properties filename

    where "filename" is a file containing the coordinates of the vertices.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 May 2014

  Author:

    John Burkardt
*/
{
  double ab[3];
  double ac[3];
  double ad[3];
  double bc[3];
  double bd[3];
  double cd[3];
  double *centroid;
  double circum_center[3];
  double circum_radius;
  double *dihedral_angles;
  int dim_num;
  double *edge_length;
  double face_angles[3*4];
  double face_areas[4];
  int i;
  int j;
  double in_center[3];
  double in_radius;
  char node_filename[255];
  int node_num;
  double *node_xyz;
  double quality1;
  double quality2;
  double quality3;
  double quality4;
  const double r8_pi = 3.141592653589793;
  double *solid_angles;
  double volume;

  timestamp ( );

  if ( 1 < argc )
  {
    strcpy ( node_filename, argv[1] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Please enter the name of the node coordinate file.\n" );
    scanf ( "%s", node_filename );
  }
/*
  Read the node data.
*/
  r8mat_header_read ( node_filename, &dim_num, &node_num );

  printf ( "\n" );
  printf ( "  Read the header of \"%s\".\n", node_filename );
  printf ( "\n" );
  printf ( "  Spatial dimension DIM_NUM = %d\n", dim_num );
  printf ( "  Number of points NODE_NUM = %d\n", node_num );

  printf ( "\n" );
  printf ( "TETRAHEDRON_PROPERTIES:\n" );
  printf ( "  C version:\n" );
  printf ( "  Determine properties of a tetrahedron.\n" );

  if ( dim_num != 3 )
  {
    printf ( "\n" );
    printf ( "TETRAHEDRON_PROPERTIES - Fatal error!\n" );
    printf ( "  Dataset must have spatial dimension 3.\n" );
    exit ( 1 );
  }

  if ( node_num != 4 )
  {
    printf ( "\n" );
    printf ( "TETRAHEDRON_PROPERTIES - Fatal error!\n" );
    printf ( "  Dataset must have 4 nodes.\n" );
    exit ( 1 );
  }

  node_xyz = r8mat_data_read ( node_filename, dim_num, node_num );

  printf ( "\n" );
  printf ( "  Read the data in \"%s\".\n", node_filename );

  r8mat_transpose_print ( dim_num, node_num, node_xyz, "  Node coordinates:" );
/*
  CIRCUMSPHERE
*/
  tetrahedron_circumsphere ( node_xyz, &circum_radius, circum_center );

  printf ( "\n" );
  printf ( "  CIRCUM_RADIUS = %g\n", circum_radius );
  printf ( "  CIRCUM_CENTER: %g  %g  %g\n", 
    circum_center[0], circum_center[1], circum_center[2] );
/*
  CENTROID
*/
  centroid = tetrahedron_centroid ( node_xyz );

  printf ( "\n" );
  printf ( "  CENTROID: %g  %g  %g\n",
    centroid[0], centroid[1], centroid[2] );
/*
  DIHEDRAL ANGLES
*/
  dihedral_angles = tetrahedron_dihedral_angles ( node_xyz );

  r8vec_print ( 6, dihedral_angles, "  DIHEDRAL_ANGLES (radians)" );

  for ( i = 0; i < 6; i++ )
  {
    dihedral_angles[i] = dihedral_angles[i] * 180.0 / r8_pi;
  }

  r8vec_print ( 6, dihedral_angles, "  DIHEDRAL_ANGLES (degrees)" );
/*
  EDGES
*/
  tetrahedron_edges ( node_xyz, ab, ac, ad, bc, bd, cd );

  printf ( "\n" );
  r8vec_transpose_print ( 3, ab, "  EDGE AB:" );
  r8vec_transpose_print ( 3, ac, "  EDGE AC:" );
  r8vec_transpose_print ( 3, ad, "  EDGE AD:" );
  r8vec_transpose_print ( 3, bc, "  EDGE BC:" );
  r8vec_transpose_print ( 3, bd, "  EDGE BD:" );
  r8vec_transpose_print ( 3, cd, "  EDGE CD:" );
/*
  EDGE LENGTHS
*/
  edge_length = tetrahedron_edge_length ( node_xyz );

  r8vec_print ( 6, edge_length, "  EDGE_LENGTHS" );
/*
  FACE ANGLES
*/
  tetrahedron_face_angles ( node_xyz, face_angles );

  r8mat_transpose_print ( 3, 4, face_angles, "  FACE_ANGLES (radians)" );

  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      face_angles[i+j*3] = face_angles[i+j*3] * 180.0 / r8_pi;
    }
  }
  r8mat_transpose_print ( 3, 4, face_angles, "  FACE_ANGLES (degrees)" );
/*
  FACE AREAS
*/
  tetrahedron_face_areas ( node_xyz, face_areas );

  r8vec_print ( 4, face_areas, "  FACE_AREAS" );
/*
  INSPHERE
*/
  tetrahedron_insphere ( node_xyz, &in_radius, in_center );

  printf ( "\n" );
  printf ( "  IN_RADIUS = %g\n", in_radius );
  printf ( "  IN_CENTER: %g  %g  %g\n",
    in_center[0], in_center[1], in_center[2] );
/*
  QUALITY1
*/
  quality1 = tetrahedron_quality1 ( node_xyz );

  printf ( "\n" );
  printf ( "  QUALITY1 = %g\n", quality1 );
/*
  QUALITY2
*/
  quality2 = tetrahedron_quality2 ( node_xyz );

  printf ( "\n" );
  printf ( "  QUALITY2 = %g\n", quality2 );
/*
  QUALITY3
*/
  quality3 = tetrahedron_quality3 ( node_xyz );

  printf ( "\n" );
  printf ( "  QUALITY3 = %g\n", quality3 );
/*
  QUALITY4
*/
  quality4 = tetrahedron_quality4 ( node_xyz );

  printf ( "\n" );
  printf ( "  QUALITY4 = %g\n", quality4 );
/*
  SOLID ANGLES
*/
  solid_angles = tetrahedron_solid_angles ( node_xyz );

  r8vec_print ( 4, solid_angles, "  SOLID_ANGLES (steradians)" );
/*
  VOLUME
*/
  volume = tetrahedron_volume ( node_xyz );

  printf ( "\n" );
  printf ( "  VOLUME = %g\n", volume );
/*
  Free memory.
*/
  free ( centroid );
  free ( dihedral_angles );
  free ( edge_length );
  free ( node_xyz );
  free ( solid_angles );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TETRAHEDRON_PROPERTIES:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
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

int ch_eqi ( char ch1, char ch2 )

/******************************************************************************/
/*
  Purpose:

    CH_EQI is TRUE (1) if two characters are equal, disregarding case.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2003

  Author:

    John Burkardt

  Parameters:

    Input, char CH1, CH2, the characters to compare.

    Output, int CH_EQI, is TRUE (1) if the two characters are equal,
    disregarding case and FALSE (0) otherwise.
*/
{
  int value;

  if ( 97 <= ch1 && ch1 <= 122 ) 
  {
    ch1 = ch1 - 32;
  } 
  if ( 97 <= ch2 && ch2 <= 122 ) 
  {
    ch2 = ch2 - 32;
  }     
  if ( ch1 == ch2 )
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

    Input, char CH, the decimal digit, '0' through '9' or blank are legal.

    Output, int CH_TO_DIGIT, the corresponding integer value.  If the 
    character was 'illegal', then DIGIT is -1.
*/
{
  int digit;

  if ( '0' <= ch && ch <= '9' )
  {
    digit = ch - '0';
  }
  else if ( ch == ' ' )
  {
    digit = 0;
  }
  else
  {
    digit = -1;
  }

  return digit;
}
/******************************************************************************/

int file_column_count ( char *input_filename )

/******************************************************************************/
/*
  Purpose:

    FILE_COLUMN_COUNT counts the number of columns in the first line of a file.

  Discussion:

    The file is assumed to be a simple text file.

    Most lines of the file is presumed to consist of COLUMN_NUM words, separated
    by spaces.  There may also be some blank lines, and some comment lines,
    which have a "#" in column 1.

    The routine tries to find the first non-comment non-blank line and
    counts the number of words in that line.

    If all lines are blanks or comments, it goes back and tries to analyze
    a comment line.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2003

  Author:

    John Burkardt

  Parameters:

    Input, char *INPUT_FILENAME, the name of the file.

    Output, int FILE_COLUMN_COUNT, the number of columns assumed 
    to be in the file.
*/
{
# define LINE_MAX 255

  int column_num;
  char *error;
  FILE *input;
  int got_one;
  char line[LINE_MAX];
/*
  Open the file.
*/
  input = fopen ( input_filename, "r" );

  if ( !input )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "FILE_COLUMN_COUNT - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n",
      input_filename );
    exit ( 1 );
  }
/*
  Read one line, but skip blank lines and comment lines.
*/
  got_one = 0;

  for ( ; ; )
  {
    error = fgets ( line, LINE_MAX, input );

    if ( !error )
    {
      break;
    }

    if ( s_len_trim ( line ) == 0 )
    {
      continue;
    }

    if ( line[0] == '#' )
    {
      continue;
    }

    got_one = 1;
    break;

  }

  if ( got_one == 0 )
  {
    fclose ( input );

    input = fopen ( input_filename, "r" );

    for ( ; ; )
    {
      error = fgets ( line, LINE_MAX, input );

      if ( !error )
      {
        break;
      }

      if ( s_len_trim ( line ) == 0 )
      {
        continue;
      }

      got_one = 1;
      break;
    }
  }

  fclose ( input );

  if ( got_one == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "FILE_COLUMN_COUNT - Warning!\n" );
    fprintf ( stderr, "  The file does not seem to contain any data.\n" );
    exit ( 1 );
  }

  column_num = s_word_count ( line );

  return column_num;

# undef LINE_MAX
}
/******************************************************************************/

int file_row_count ( char *input_filename )

/******************************************************************************/
/*
  Purpose:

    FILE_ROW_COUNT counts the number of row records in a file.

  Discussion:

    It does not count lines that are blank, or that begin with a
    comment symbol '#'.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2003

  Author:

    John Burkardt

  Parameters:

    Input, char *INPUT_FILENAME, the name of the input file.

    Output, int FILE_ROW_COUNT, the number of rows found.
*/
{
# define LINE_MAX 255

  int comment_num;
  char *error;
  FILE *input;
  char line[LINE_MAX];
  int record_num;
  int row_num;

  row_num = 0;
  comment_num = 0;
  record_num = 0;

  input = fopen ( input_filename, "r" );

  if ( !input )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "FILE_ROW_COUNT - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n",
      input_filename );
    exit ( 1 );
  }

  for ( ; ; )
  {
    error = fgets ( line, LINE_MAX, input );

    if ( !error )
    {
      break;
    }

    record_num = record_num + 1;

    if ( line[0] == '#' )
    {
      comment_num = comment_num + 1;
      continue;
    }

    if ( s_len_trim ( line ) == 0 )
    {
      comment_num = comment_num + 1;
      continue;
    }

    row_num = row_num + 1;
  }

  fclose ( input );

  return row_num;

# undef LINE_MAX
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

double r8_abs ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_ABS returns the absolute value of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the quantity whose absolute value is desired.

    Output, double R8_ABS, the absolute value of X.
*/
{
  double value;

  if ( 0.0 <= x )
  {
    value = + x;
  }
  else
  {
    value = - x;
  }
  return value;
}
/******************************************************************************/

double r8_acos ( double c )

/******************************************************************************/
/*
  Purpose:

    R8_ACOS computes the arc cosine function, with argument truncation.

  Discussion:

    If you call your system ACOS routine with an input argument that is
    outside the range [-1.0, 1.0 ], you may get an unpleasant surprise.
    This routine truncates arguments outside the range.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2002

  Author:

    John Burkardt

  Parameters:

    Input, double C, the argument, the cosine of an angle.

    Output, double R8_ACOS, an angle whose cosine is C.
*/
{
  double angle;
  const double r8_pi = 3.141592653589793;

  if ( c <= -1.0 )
  {
    angle = r8_pi;
  } 
  else if ( 1.0 <= c )
  {
    angle = 0.0;
  }
  else
  {
    angle = acos ( c );
  }
  return angle;
}
/******************************************************************************/

double r8_huge ( )

/******************************************************************************/
/*
  Purpose:

    R8_HUGE returns a "huge" R8.

  Discussion:

    The value returned by this function is NOT required to be the
    maximum representable R8.  This value varies from machine to machine,
    from compiler to compiler, and may cause problems when being printed.
    We simply want a "very large" but non-infinite number.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 October 2007

  Author:

    John Burkardt

  Parameters:

    Output, double R8_HUGE, a "huge" R8 value.
*/
{
  double value;

  value = 1.0E+30;

  return value;
}
/******************************************************************************/

double r8_max ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    R8_MAX returns the maximum of two R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, Y, the quantities to compare.

    Output, double R8_MAX, the maximum of X and Y.
*/
{
  double value;

  if ( y < x )
  {
    value = x;
  }
  else
  {
    value = y;
  }
  return value;
}
/******************************************************************************/

double r8_min ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    R8_MIN returns the minimum of two R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, Y, the quantities to compare.

    Output, double R8_MIN, the minimum of X and Y.
*/
{
  double value;

  if ( y < x )
  {
    value = y;
  }
  else
  {
    value = x;
  }
  return value;
}
/******************************************************************************/

void r8_swap ( double *x, double *y )

/******************************************************************************/
/*
  Purpose:

    R8_SWAP switches two R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 March 2009

  Author:

    John Burkardt

  Parameters:

    Input/output, double *X, *Y.  On output, the values of X and
    Y have been interchanged.
*/
{
  double z;

  z = *x;
  *x = *y;
  *y = z;

  return;
}
/******************************************************************************/

double *r8mat_data_read ( char *input_filename, int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DATA_READ reads the data from an R8MAT file.

  Discussion:

    An R8MAT is an array of R8's.

    The file is assumed to contain one record per line.

    Records beginning with the '#' character are comments, and are ignored.
    Blank lines are also ignored.

    Each line that is not ignored is assumed to contain exactly (or at least)
    M real numbers, representing the coordinates of a point.

    There are assumed to be exactly (or at least) N such records.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 January 2005

  Author:

    John Burkardt

  Parameters:

    Input, char *INPUT_FILENAME, the name of the input file.

    Input, int M, the number of spatial dimensions.

    Input, int N, the number of points.  The program
    will stop reading data once N values have been read.

    Output, double R8MAT_DATA_READ[M*N], the data.
*/
{
# define LINE_MAX 255

  int error;
  char *got_string;
  FILE *input;
  int i;
  int j;
  char line[255];
  double *table;
  double *x;

  input = fopen ( input_filename, "r" );

  if ( !input )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8MAT_DATA_READ - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n", input_filename );
    exit ( 1 );
  }

  table = ( double * ) malloc ( m * n * sizeof ( double ) );

  x = ( double * ) malloc ( m * sizeof ( double ) );

  j = 0;

  while ( j < n )
  {
    got_string = fgets ( line, LINE_MAX, input );

    if ( !got_string )
    {
      break;
    }

    if ( line[0] == '#' || s_len_trim ( line ) == 0 )
    {
      continue;
    }

    error = s_to_r8vec ( line, m, x );

    if ( error == 1 )
    {
      continue;
    }

    for ( i = 0; i < m; i++ )
    {
      table[i+j*m] = x[i];
    }
    j = j + 1;

  }

  fclose ( input );

  free ( x );

  return table;

# undef LINE_MAX
}
/******************************************************************************/

double r8mat_det_4d ( double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DET_4D computes the determinant of a 4 by 4 R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, double A[4*4], the matrix whose determinant is desired.

    Output, double R8MAT_DET_4D, the determinant of the matrix.
*/
{
  double det;

  det =
      a[0+0*4] * (
          a[1+1*4] * ( a[2+2*4] * a[3+3*4] - a[2+3*4] * a[3+2*4] )
        - a[1+2*4] * ( a[2+1*4] * a[3+3*4] - a[2+3*4] * a[3+1*4] )
        + a[1+3*4] * ( a[2+1*4] * a[3+2*4] - a[2+2*4] * a[3+1*4] ) )
    - a[0+1*4] * (
          a[1+0*4] * ( a[2+2*4] * a[3+3*4] - a[2+3*4] * a[3+2*4] )
        - a[1+2*4] * ( a[2+0*4] * a[3+3*4] - a[2+3*4] * a[3+0*4] )
        + a[1+3*4] * ( a[2+0*4] * a[3+2*4] - a[2+2*4] * a[3+0*4] ) )
    + a[0+2*4] * (
          a[1+0*4] * ( a[2+1*4] * a[3+3*4] - a[2+3*4] * a[3+1*4] )
        - a[1+1*4] * ( a[2+0*4] * a[3+3*4] - a[2+3*4] * a[3+0*4] )
        + a[1+3*4] * ( a[2+0*4] * a[3+1*4] - a[2+1*4] * a[3+0*4] ) )
    - a[0+3*4] * (
          a[1+0*4] * ( a[2+1*4] * a[3+2*4] - a[2+2*4] * a[3+1*4] )
        - a[1+1*4] * ( a[2+0*4] * a[3+2*4] - a[2+2*4] * a[3+0*4] )
        + a[1+2*4] * ( a[2+0*4] * a[3+1*4] - a[2+1*4] * a[3+0*4] ) );

  return det;
}
/******************************************************************************/
 
void r8mat_header_read ( char *input_filename, int *m, int *n )
 
/******************************************************************************/
/*
  Purpose:

    R8MAT_HEADER_READ reads the header from an R8MAT file.

  Discussion:

    An R8MAT is an array of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 June 2004

  Author:

    John Burkardt

  Parameters:

    Input, char *INPUT_FILENAME, the name of the input file.

    Output, int *M, the number of spatial dimensions.

    Output, int *N, the number of points.
*/
{
  *m = file_column_count ( input_filename );

  if ( *m <= 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8MAT_HEADER_READ - Fatal error!\n" );
    fprintf ( stderr, "  FILE_COLUMN_COUNT failed.\n" );
    exit ( 1 );
  }

  *n = file_row_count ( input_filename );

  if ( *n <= 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8MAT_HEADER_READ - Fatal error!\n" );
    fprintf ( stderr, "  FILE_ROW_COUNT failed.\n" );
    exit ( 1 );
  }

  return;
}
/******************************************************************************/

int r8mat_solve ( int n, int rhs_num, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_SOLVE uses Gauss-Jordan elimination to solve an N by N linear system.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    Entry A(I,J) is stored as A[I+J*N]

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Input, int RHS_NUM, the number of right hand sides.  RHS_NUM
    must be at least 0.

    Input/output, double A[N*(N+RHS_NUM)], contains in rows and columns 1
    to N the coefficient matrix, and in columns N+1 through
    N+RHS_NUM, the right hand sides.  On output, the coefficient matrix
    area has been destroyed, while the right hand sides have
    been overwritten with the corresponding solutions.

    Output, int R8MAT_SOLVE, singularity flag.
    0, the matrix was not singular, the solutions were computed;
    J, factorization failed on step J, and the solutions could not
    be computed.
*/
{
  double apivot;
  double factor;
  int i;
  int ipivot;
  int j;
  int k;
  double temp;

  for ( j = 0; j < n; j++ )
  {
/*
  Choose a pivot row.
*/
    ipivot = j;
    apivot = a[j+j*n];

    for ( i = j; i < n; i++ )
    {
      if ( fabs ( apivot ) < fabs ( a[i+j*n] ) )
      {
        apivot = a[i+j*n];
        ipivot = i;
      }
    }

    if ( apivot == 0.0 )
    {
      return j;
    }
/*
  Interchange.
*/
    for ( i = 0; i < n + rhs_num; i++ )
    {
      temp          = a[ipivot+i*n];
      a[ipivot+i*n] = a[j+i*n];
      a[j+i*n]      = temp;
    }
/*
  A(J,J) becomes 1.
*/
    a[j+j*n] = 1.0;
    for ( k = j; k < n + rhs_num; k++ )
    {
      a[j+k*n] = a[j+k*n] / apivot;
    }
/*
  A(I,J) becomes 0.
*/
    for ( i = 0; i < n; i++ )
    {
      if ( i != j )
      {
        factor = a[i+j*n];
        a[i+j*n] = 0.0;
        for ( k = j; k < n + rhs_num; k++ )
        {
          a[i+k*n] = a[i+k*n] - factor * a[j+k*n];
        }
      }
    }
  }

  return 0;
}
/******************************************************************************/

void r8mat_transpose_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_TRANSPOSE_PRINT prints an R8MAT, transposed.

  Discussion:

    An R8MAT is an array of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double A[M*N], an M by N matrix to be printed.

    Input, char *TITLE, a title.
*/
{
  r8mat_transpose_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 
  int ihi, int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_TRANSPOSE_PRINT_SOME prints some of an R8MAT, transposed.

  Discussion:

    An R8MAT is an array of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double A[M*N], an M by N matrix to be printed.

    Input, int ILO, JLO, the first row and column to print.

    Input, int IHI, JHI, the last row and column to print.

    Input, char *TITLE, a title.
*/
{
# define INCX 5

  int i;
  int i2;
  int i2hi;
  int i2lo;
  int inc;
  int j;
  int j2hi;
  int j2lo;

  printf ( "\n" );
  printf ( "%s\n", title );
 
  for ( i2lo = i4_max ( ilo, 1 ); i2lo <= i4_min ( ihi, m ); i2lo = i2lo + INCX )
  {
    i2hi = i2lo + INCX - 1;
    i2hi = i4_min ( i2hi, m );
    i2hi = i4_min ( i2hi, ihi );

    inc = i2hi + 1 - i2lo;

    printf ( "\n" );
    printf ( "  Row:" );
    for ( i = i2lo; i <= i2hi; i++ )
    {
      printf ( "  %7d     ", i );
    }
    printf ( "\n" );
    printf ( "  Col\n" );
    printf ( "\n" );

    j2lo = i4_max ( jlo, 1 );
    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )
    {
      printf ( "%5d", j );
      for ( i2 = 1; i2 <= inc; i2++ )
      {
        i = i2lo - 1 + i2;
        printf ( "  %14f", a[(i-1)+(j-1)*m] );
      }
      printf ( "\n" );
    }
  }
  printf ( "\n" );

  return;
# undef INCX
}
/******************************************************************************/

double r8vec_angle_3d ( double u[], double v[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_ANGLE_3D computes the angle between two vectors in 3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 July 2009

  Author:

    John Burkardt

  Parameters:

    Input, double U[3], V[3], the vectors.

    Output, double ANGLE, the angle between the two vectors.
*/
{
  double angle;
  double angle_cos;
  double u_norm;
  double uv_dot;
  double v_norm;

  uv_dot = r8vec_dot_product ( 3, u, v );

  u_norm = r8vec_norm ( 3, u );

  v_norm = r8vec_norm ( 3, v );

  angle_cos = uv_dot / u_norm / v_norm;

  angle = r8_acos ( angle_cos );

  return angle;
}
/******************************************************************************/

double *r8vec_cross_3d ( double v1[3], double v2[3] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_CROSS_3D computes the cross product of two R8VEC's in 3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 August 2005

  Author:

    John Burkardt

  Parameters:

    Input, double V1[3], V2[3], the coordinates of the vectors.

    Output, double R8VEC_CROSS_3D[3], the cross product vector.
*/
{
  double *v3;

  v3 = ( double * ) malloc ( 3 * sizeof ( double ) );

  v3[0] = v1[1] * v2[2] - v1[2] * v2[1];
  v3[1] = v1[2] * v2[0] - v1[0] * v2[2];
  v3[2] = v1[0] * v2[1] - v1[1] * v2[0];

  return v3;
}
/******************************************************************************/

double r8vec_dot_product ( int n, double a1[], double a2[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_DOT_PRODUCT computes the dot product of a pair of R8VEC's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2007

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], A2[N], the two vectors to be considered.

    Output, double R8VEC_DOT_PRODUCT, the dot product of the vectors.
*/
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a1[i] * a2[i];
  }
  return value;
}
/******************************************************************************/

double r8vec_max ( int n, double r8vec[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MAX returns the value of the maximum element in a R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, double R8VEC[N], a pointer to the first entry of the array.

    Output, double R8VEC_MAX, the value of the maximum element.  This
    is set to 0.0 if N <= 0.
*/
{
  int i;
  double value;

  if ( n <= 0 )
  {
    value = 0.0;
    return value;
  }

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < r8vec[i] )
    {
      value = r8vec[i];
    }
  }
  return value;
}
/******************************************************************************/

double r8vec_norm ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORM returns the L2 norm of an R8VEC.

  Discussion:

    The vector L2 norm is defined as:

      R8VEC_NORM = sqrt ( sum ( 1 <= I <= N ) A(I)^2 ).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 March 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in A.

    Input, double A[N], the vector whose L2 norm is desired.

    Output, double R8VEC_NORM, the L2 norm of A.
*/
{
  int i;
  double v;

  v = 0.0;

  for ( i = 0; i < n; i++ )
  {
    v = v + a[i] * a[i];
  }
  v = sqrt ( v );

  return v;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

void r8vec_transpose_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_TRANSPOSE_PRINT prints an R8VEC "transposed".

  Discussion:

    An R8VEC is a vector of R8's.

  Example:

    A = (/ 1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 10.9, 11.0 /)
    TITLE = 'My vector:  '

    My vector:   1.0    2.1    3.2    4.3    5.4
                 6.5    7.6    8.7    9.8   10.9
                11.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 May 2014

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;
  int ihi;
  int ilo;
  int title_length;

  title_length = s_len_trim ( title );

  for ( ilo = 0; ilo < n; ilo = ilo + 5 )
  {
    if ( ilo == 0 )
    {
      printf ( "%s", title );
    }
    else
    {
      for ( i = 0; i < title_length; i++ )
      {
        printf ( " " );
      }
    }
    printf ( "  " );

    ihi = i4_min ( ilo + 5, n );
    for ( i = ilo; i < ihi; i++ )
    {
      printf ( "  %12g", a[i] );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void r8vec_zero ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_ZERO zeroes an R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Output, double A[N], a vector of zeroes.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return;
}
/******************************************************************************/

int s_len_trim ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_LEN_TRIM returns the length of a string to the last nonblank.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 April 2003

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a pointer to a string.

    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
    If S_LEN_TRIM is 0, then the string is entirely blank.
*/
{
  int n;
  char *t;

  n = strlen ( s );
  t = s + strlen ( s ) - 1;

  while ( 0 < n ) 
  {
    if ( *t != ' ' )
    {
      return n;
    }
    t--;
    n--;
  }

  return n;
}
/******************************************************************************/

double s_to_r8 ( char *s, int *lchar, int *error )

/******************************************************************************/
/*
  Purpose:

    S_TO_R8 reads an R8 value from a string.

  Discussion:

    We have had some trouble with input of the form 1.0E-312.
    For now, let's assume anything less than 1.0E-20 is zero.

    This routine will read as many characters as possible until it reaches
    the end of the string, or encounters a character which cannot be
    part of the real number.

    Legal input is:

       1 blanks,
       2 '+' or '-' sign,
       2.5 spaces
       3 integer part,
       4 decimal point,
       5 fraction part,
       6 'E' or 'e' or 'D' or 'd', exponent marker,
       7 exponent sign,
       8 exponent integer part,
       9 exponent decimal point,
      10 exponent fraction part,
      11 blanks,
      12 final comma or semicolon.

    with most quantities optional.

  Example:

    S                 R

    '1'               1.0
    '     1   '       1.0
    '1A'              1.0
    '12,34,56'        12.0
    '  34 7'          34.0
    '-1E2ABCD'        -100.0
    '-1X2ABCD'        -1.0
    ' 2E-1'           0.2
    '23.45'           23.45
    '-4.2E+2'         -420.0
    '17d2'            1700.0
    '-14e-2'         -0.14
    'e2'              100.0
    '-12.73e-9.23'   -12.73 * 10.0^(-9.23)

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 June 2005

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string containing the
    data to be read.  Reading will begin at position 1 and
    terminate at the end of the string, or when no more
    characters can be read to form a legal real.  Blanks,
    commas, or other nonnumeric data will, in particular,
    cause the conversion to halt.

    Output, int *LCHAR, the number of characters read from
    the string to form the number, including any terminating
    characters such as a trailing comma or blanks.

    Output, int *ERROR, is TRUE (1) if an error occurred and FALSE (0)
    otherwise.

    Output, double S_TO_R8, the value that was read from the string.
*/
{
  char c;
  int ihave;
  int isgn;
  int iterm;
  int jbot;
  int jsgn;
  int jtop;
  int nchar;
  int ndig;
  double r;
  double rbot;
  double rexp;
  double rtop;
  char TAB = 9;

  nchar = s_len_trim ( s );
  *error = 0;
  r = 0.0;
  *lchar = -1;
  isgn = 1;
  rtop = 0.0;
  rbot = 1.0;
  jsgn = 1;
  jtop = 0;
  jbot = 1;
  ihave = 1;
  iterm = 0;

  for ( ; ; )
  {
    c = s[*lchar+1];
    *lchar = *lchar + 1;
/*
  Blank or TAB character.
*/
    if ( c == ' ' || c == TAB )
    {
      if ( ihave == 2 )
      {
      }
      else if ( ihave == 6 || ihave == 7 )
      {
        iterm = 1;
      }
      else if ( 1 < ihave )
      {
        ihave = 11;
      }
    }
/*
  Comma.
*/
    else if ( c == ',' || c == ';' )
    {
      if ( ihave != 1 )
      {
        iterm = 1;
        ihave = 12;
        *lchar = *lchar + 1;
      }
    }
/*
  Minus sign.
*/
    else if ( c == '-' )
    {
      if ( ihave == 1 )
      {
        ihave = 2;
        isgn = -1;
      }
      else if ( ihave == 6 )
      {
        ihave = 7;
        jsgn = -1;
      }
      else
      {
        iterm = 1;
      }
    }
/*
  Plus sign.
*/
    else if ( c == '+' )
    {
      if ( ihave == 1 )
      {
        ihave = 2;
      }
      else if ( ihave == 6 )
      {
        ihave = 7;
      }
      else
      {
        iterm = 1;
      }
    }
/*
  Decimal point.
*/
    else if ( c == '.' )
    {
      if ( ihave < 4 )
      {
        ihave = 4;
      }
      else if ( 6 <= ihave && ihave <= 8 )
      {
        ihave = 9;
      }
      else
      {
        iterm = 1;
      }
    }
/*
  Exponent marker.
*/
    else if ( ch_eqi ( c, 'E' ) || ch_eqi ( c, 'D' ) )
    {
      if ( ihave < 6 )
      {
        ihave = 6;
      }
      else
      {
        iterm = 1;
      }
    }
/*
  Digit.
*/
    else if ( ihave < 11 && '0' <= c && c <= '9' )
    {
      if ( ihave <= 2 )
      {
        ihave = 3;
      }
      else if ( ihave == 4 )
      {
        ihave = 5;
      }
      else if ( ihave == 6 || ihave == 7 )
      {
        ihave = 8;
      }
      else if ( ihave == 9 )
      {
        ihave = 10;
      }

      ndig = ch_to_digit ( c );

      if ( ihave == 3 )
      {
        rtop = 10.0 * rtop + ( double ) ndig;
      }
      else if ( ihave == 5 )
      {
        rtop = 10.0 * rtop + ( double ) ndig;
        rbot = 10.0 * rbot;
      }
      else if ( ihave == 8 )
      {
        jtop = 10 * jtop + ndig;
      }
      else if ( ihave == 10 )
      {
        jtop = 10 * jtop + ndig;
        jbot = 10 * jbot;
      }
    }
/*
  Anything else is regarded as a terminator.
*/
    else
    {
      iterm = 1;
    }
/*
  If we haven't seen a terminator, and we haven't examined the
  entire string, go get the next character.
*/
    if ( iterm == 1 || nchar <= *lchar + 1 )
    {
      break;
    }

  }
/*
  If we haven't seen a terminator, and we have examined the
  entire string, then we're done, and LCHAR is equal to NCHAR.
*/
  if ( iterm != 1 && (*lchar) + 1 == nchar )
  {
    *lchar = nchar;
  }
/*
  Number seems to have terminated.  Have we got a legal number?
  Not if we terminated in states 1, 2, 6 or 7!
*/
  if ( ihave == 1 || ihave == 2 || ihave == 6 || ihave == 7 )
  {
    *error = 1;
    return r;
  }
/*
  Number seems OK.  Form it.

  We have had some trouble with input of the form 1.0E-312.
  For now, let's assume anything less than 1.0E-20 is zero.
*/
  if ( jtop == 0 )
  {
    rexp = 1.0;
  }
  else
  {
    if ( jbot == 1 )
    {
      if ( jsgn * jtop < -20 )
      {
        rexp = 0.0;
      }
      else
      {
        rexp = pow ( ( double ) 10.0, ( double ) ( jsgn * jtop ) );
      }
    }
    else
    {
      if ( jsgn * jtop < -20 * jbot )
      {
        rexp = 0.0;
      }
      else
      {
        rexp = jsgn * jtop;
        rexp = rexp / jbot;
        rexp = pow ( ( double ) 10.0, ( double ) rexp );
      }
    }

  }

  r = isgn * rexp * rtop / rbot;

  return r;
}
/******************************************************************************/

int s_to_r8vec ( char *s, int n, double rvec[] )

/******************************************************************************/
/*
  Purpose:

    S_TO_R8VEC reads an R8VEC from a string.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 February 2001

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string to be read.

    Input, int N, the number of values expected.

    Output, double RVEC[N], the values read from the string.

    Output, int S_TO_R8VEC, is TRUE (1) if an error occurred and FALSE (0)
    otherwise.
*/
{
  int error;
  int i;
  int lchar;

  error = 0;

  for ( i = 0; i < n; i++ )
  {
    rvec[i] = s_to_r8 ( s, &lchar, &error );

    if ( error )
    {
      return error;
    }

    s = s + lchar;

  }

  return error;
}
/******************************************************************************/

int s_word_count ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_WORD_COUNT counts the number of "words" in a string.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2015

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string to be examined.

    Output, int S_WORD_COUNT, the number of "words" in the string.
    Words are presumed to be separated by one or more blanks.
*/
{
  int blank;
  int word_num;
  char *t;

  word_num = 0;
  blank = 1;
  t = s;

  while ( *t )
  {
    if ( *t == ' ' || *t == '\n' )
    {
      blank = 1;
    }
    else if ( blank )
    {
      word_num = word_num + 1;
      blank = 0;
    }
    t++;
  }

  return word_num;
}
/******************************************************************************/

double *tetrahedron_centroid ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_CENTROID computes the centroid of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 July 2005

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double TETRAHEDRON_CENTROID[3], the coordinates of the centroid.
*/
{
  double *centroid;
  int i;

  centroid = ( double * ) malloc ( 3 * sizeof ( double ) );

  centroid[0] = ( tetra[0+0*3] + tetra[0+1*3] 
                + tetra[0+2*3] + tetra[0+3*3] );
  centroid[1] = ( tetra[1+0*3] + tetra[1+1*3] 
                + tetra[1+2*3] + tetra[1+3*3] );
  centroid[2] = ( tetra[2+0*3] + tetra[2+1*3] 
                + tetra[2+2*3] + tetra[2+3*3] );

  for ( i = 0; i < 3; i++ )
  {
    centroid[i] = centroid[i] / 4.0;
  }

  return centroid;
}
/******************************************************************************/

void tetrahedron_circumsphere ( double tetra[3*4], double *r, double pc[3] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_CIRCUMSPHERE computes the circumsphere of a tetrahedron.

  Discussion:

    The circumsphere, or circumscribed sphere, of a tetrahedron is the 
    sphere that passes through the four vertices.  The circumsphere is not
    necessarily the smallest sphere that contains the tetrahedron.

    Surprisingly, the diameter of the sphere can be found by solving
    a 3 by 3 linear system.  This is because the vectors P2 - P1,
    P3 - P1 and P4 - P1 are secants of the sphere, and each forms a
    right triangle with the diameter through P1.  Hence, the dot product of
    P2 - P1 with that diameter is equal to the square of the length
    of P2 - P1, and similarly for P3 - P1 and P4 - P1.  This determines
    the diameter vector originating at P1, and hence the radius and
    center.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 August 2005

  Author:

    John Burkardt

  Reference:

    Adrian Bowyer, John Woodwark,
    A Programmer's Geometry,
    Butterworths, 1983.

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double *R, PC[3], the coordinates of the center of the
    circumscribed sphere, and its radius.  If the linear system is
    singular, then R = -1, PC[] = 0.
*/
{
  double a[3*4];
  int info;
/*
  Set up the linear system.
*/
  a[0+0*3] = tetra[0+1*3] - tetra[0+0*3];
  a[0+1*3] = tetra[1+1*3] - tetra[1+0*3];
  a[0+2*3] = tetra[2+1*3] - tetra[2+0*3];
  a[0+3*3] = pow ( tetra[0+1*3] - tetra[0+0*3], 2 ) 
           + pow ( tetra[1+1*3] - tetra[1+0*3], 2 ) 
           + pow ( tetra[2+1*3] - tetra[2+0*3], 2 );

  a[1+0*3] = tetra[0+2*3] - tetra[0+0*3];
  a[1+1*3] = tetra[1+2*3] - tetra[1+0*3];
  a[1+2*3] = tetra[2+2*3] - tetra[2+0*3];
  a[1+3*3] = pow ( tetra[0+2*3] - tetra[0+0*3], 2 ) 
           + pow ( tetra[1+2*3] - tetra[1+0*3], 2 ) 
           + pow ( tetra[2+2*3] - tetra[2+0*3], 2 );

  a[2+0*3] = tetra[0+3*3] - tetra[0+0*3];
  a[2+1*3] = tetra[1+3*3] - tetra[1+0*3];
  a[2+2*3] = tetra[2+3*3] - tetra[2+0*3];
  a[2+3*3] = pow ( tetra[0+3*3] - tetra[0+0*3], 2 ) 
           + pow ( tetra[1+3*3] - tetra[1+0*3], 2 ) 
           + pow ( tetra[2+3*3] - tetra[2+0*3], 2 );
/*
  Solve the linear system.
*/
  info = r8mat_solve ( 3, 1, a );
/*
  If the system was singular, return a consolation prize.
*/
  if ( info != 0 )
  {
    *r = -1.0;
    r8vec_zero ( 3, pc );
    return;
  }
/*
  Compute the radius and center.
*/
  *r = 0.5 * sqrt 
    ( a[0+3*3] * a[0+3*3] 
    + a[1+3*3] * a[1+3*3] 
    + a[2+3*3] * a[2+3*3] );

  pc[0] = tetra[0+0*3] + 0.5 * a[0+3*3];
  pc[1] = tetra[1+0*3] + 0.5 * a[1+3*3];
  pc[2] = tetra[2+0*3] + 0.5 * a[2+3*3];

  return;
}
/******************************************************************************/

double *tetrahedron_dihedral_angles ( double tetra[] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_DIHEDRAL_ANGLES computes dihedral angles of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2009

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron,
    which can be labeled as A, B, C and D.

    Output, double TETRAHEDRON_DIHEDRAL_ANGLES[6], the dihedral angles 
    along the axes AB, AC, AD, BC, BD and CD, respectively.
*/
{
  double ab[3];
  double *abc_normal;
  double *abd_normal;
  double ac[3];
  double *acd_normal;
  double ad[3];
  double *angle;
  double bc[3];
  double *bcd_normal;
  double bd[3];
  double cd[3];
  int i;
  const double r8_pi = 3.141592653589793;

  tetrahedron_edges ( tetra, ab, ac, ad, bc, bd, cd );

  abc_normal = r8vec_cross_3d ( ac, ab );
  abd_normal = r8vec_cross_3d ( ab, ad );
  acd_normal = r8vec_cross_3d ( ad, ac );
  bcd_normal = r8vec_cross_3d ( bc, bd );

  angle = ( double * ) malloc ( 6 * sizeof ( double ) );

  angle[0] = r8vec_angle_3d ( abc_normal, abd_normal );
  angle[1] = r8vec_angle_3d ( abc_normal, acd_normal );
  angle[2] = r8vec_angle_3d ( abd_normal, acd_normal );
  angle[3] = r8vec_angle_3d ( abc_normal, bcd_normal );
  angle[4] = r8vec_angle_3d ( abd_normal, bcd_normal );
  angle[5] = r8vec_angle_3d ( acd_normal, bcd_normal );

  for ( i = 0; i < 6; i++ )
  {
    angle[i] = r8_pi - angle[i];
  }

  free ( abc_normal );
  free ( abd_normal );
  free ( acd_normal );
  free ( bcd_normal );

  return angle;
}
/******************************************************************************/

double *tetrahedron_edge_length ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_EDGE_LENGTH returns edge lengths of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 August 2005

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the tetrahedron vertices.

    Output, double EDGE_LENGTH[6], the length of the edges.
*/
{
  double *edge_length;
  int i;
  int j1;
  int j2;
  int k;
  double v[3];

  edge_length = ( double * ) malloc ( 6 * sizeof ( double ) );

  k = 0;
  for ( j1 = 0; j1 < 3; j1++ )
  {
    for ( j2 = j1 + 1; j2 < 4; j2++ )
    {
      for ( i = 0; i < 3; i++ )
      {
        v[i] = tetra[i+j2*3] - tetra[i+j1*3];
      }
      edge_length[k] = r8vec_norm ( 3, v );
      k = k + 1;
    }
  }

  return edge_length;
}
/******************************************************************************/

void tetrahedron_edges ( double tetra[3*4], double ab[], double ac[],
  double ad[], double bc[], double bd[], double cd[] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_EDGES returns the edges of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 May 2014

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the tetrahedron vertices.

    Output, double AB[3], AC[3], AD[3], BC[3], BD[3], CD[3], the edges.
*/
{
  int i;
/*
  Compute the vectors that represent the sides.
*/
  for ( i = 0; i < 3; i++ )
  {
    ab[i] = tetra[i+1*3] - tetra[i+0*3];
    ac[i] = tetra[i+2*3] - tetra[i+0*3];
    ad[i] = tetra[i+3*3] - tetra[i+0*3];
    bc[i] = tetra[i+2*3] - tetra[i+1*3];
    bd[i] = tetra[i+3*3] - tetra[i+1*3];
    cd[i] = tetra[i+3*3] - tetra[i+2*3];
  }

  return;
}
/******************************************************************************/

void tetrahedron_face_angles ( double tetra[], double angles[] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_FACE_ANGLES returns the 12 face angles of a tetrahedron.

  Discussion:

    The tetrahedron has 4 triangular faces.  This routine computes the
    3 planar angles associated with each face.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 July 2009

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4] the tetrahedron vertices.

    Output, double ANGLES[3*4], the face angles.
*/
{
  double *tri;

  tri = ( double * ) malloc ( 3 * 3 * sizeof ( double ) );
/*
  Face 123
*/
  tri[0+0*3] = tetra[0+0*3];
  tri[1+0*3] = tetra[1+0*3];
  tri[2+0*3] = tetra[2+0*3];
  tri[0+1*3] = tetra[0+1*3];
  tri[1+1*3] = tetra[1+1*3];
  tri[2+1*3] = tetra[2+1*3];
  tri[0+2*3] = tetra[0+2*3];
  tri[1+2*3] = tetra[1+2*3];
  tri[2+2*3] = tetra[2+2*3];

  triangle_angles_3d ( tri, angles );
/*
  Face 124
*/
  tri[0+0*3] = tetra[0+0*3];
  tri[1+0*3] = tetra[1+0*3];
  tri[2+0*3] = tetra[2+0*3];
  tri[0+1*3] = tetra[0+1*3];
  tri[1+1*3] = tetra[1+1*3];
  tri[2+1*3] = tetra[2+1*3];
  tri[0+2*3] = tetra[0+3*3];
  tri[1+2*3] = tetra[1+3*3];
  tri[2+2*3] = tetra[2+3*3];

  triangle_angles_3d ( tri, angles+3 );
/*
  Face 134
*/
  tri[0+0*3] = tetra[0+0*3];
  tri[1+0*3] = tetra[1+0*3];
  tri[2+0*3] = tetra[2+0*3];
  tri[0+1*3] = tetra[0+2*3];
  tri[1+1*3] = tetra[1+2*3];
  tri[2+1*3] = tetra[2+2*3];
  tri[0+2*3] = tetra[0+3*3];
  tri[1+2*3] = tetra[1+3*3];
  tri[2+2*3] = tetra[2+3*3];

  triangle_angles_3d ( tri, angles+6 );
/*
  Face 234
*/
  tri[0+0*3] = tetra[0+1*3];
  tri[1+0*3] = tetra[1+1*3];
  tri[2+0*3] = tetra[2+1*3];
  tri[0+1*3] = tetra[0+2*3];
  tri[1+1*3] = tetra[1+2*3];
  tri[2+1*3] = tetra[2+2*3];
  tri[0+2*3] = tetra[0+3*3];
  tri[1+2*3] = tetra[1+3*3];
  tri[2+2*3] = tetra[2+3*3];

  triangle_angles_3d ( tri, angles+9 );

  free ( tri );

  return;
}
/******************************************************************************/

void tetrahedron_face_areas ( double tetra[], double areas[] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_FACE_AREAS returns the 4 face areas of a tetrahedron.

  Discussion:

    The tetrahedron has 4 triangular faces.  This routine computes the
    areas associated with each face.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 July 2009

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4] the tetrahedron vertices.

    Output, double AREAS[4], the face areas.
*/
{
  double *tri;

  tri = ( double * ) malloc ( 3 * 3 * sizeof ( double ) );
/*
  Face 123
*/
  tri[0+0*3] = tetra[0+0*3];
  tri[1+0*3] = tetra[1+0*3];
  tri[2+0*3] = tetra[2+0*3];
  tri[0+1*3] = tetra[0+1*3];
  tri[1+1*3] = tetra[1+1*3];
  tri[2+1*3] = tetra[2+1*3];
  tri[0+2*3] = tetra[0+2*3];
  tri[1+2*3] = tetra[1+2*3];
  tri[2+2*3] = tetra[2+2*3];

  areas[0] = triangle_area_3d ( tri );
/*
  Face 124
*/
  tri[0+0*3] = tetra[0+0*3];
  tri[1+0*3] = tetra[1+0*3];
  tri[2+0*3] = tetra[2+0*3];
  tri[0+1*3] = tetra[0+1*3];
  tri[1+1*3] = tetra[1+1*3];
  tri[2+1*3] = tetra[2+1*3];
  tri[0+2*3] = tetra[0+3*3];
  tri[1+2*3] = tetra[1+3*3];
  tri[2+2*3] = tetra[2+3*3];

  areas[1] = triangle_area_3d ( tri );
/*
  Face 134
*/
  tri[0+0*3] = tetra[0+0*3];
  tri[1+0*3] = tetra[1+0*3];
  tri[2+0*3] = tetra[2+0*3];
  tri[0+1*3] = tetra[0+2*3];
  tri[1+1*3] = tetra[1+2*3];
  tri[2+1*3] = tetra[2+2*3];
  tri[0+2*3] = tetra[0+3*3];
  tri[1+2*3] = tetra[1+3*3];
  tri[2+2*3] = tetra[2+3*3];

  areas[2] = triangle_area_3d ( tri );
/*
  Face 234
*/
  tri[0+0*3] = tetra[0+1*3];
  tri[1+0*3] = tetra[1+1*3];
  tri[2+0*3] = tetra[2+1*3];
  tri[0+1*3] = tetra[0+2*3];
  tri[1+1*3] = tetra[1+2*3];
  tri[2+1*3] = tetra[2+2*3];
  tri[0+2*3] = tetra[0+3*3];
  tri[1+2*3] = tetra[1+3*3];
  tri[2+2*3] = tetra[2+3*3];

  areas[3] = triangle_area_3d ( tri );

  free ( tri );

  return;
}
/******************************************************************************/

void tetrahedron_insphere ( double tetra[3*4], double *r, double pc[3] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INSPHERE finds the insphere of a tetrahedron.

  Discussion:

    The insphere of a tetrahedron is the inscribed sphere, which touches
    each face of the tetrahedron at a single point.

    The points of contact are the centroids of the triangular faces
    of the tetrahedron.  Therefore, the point of contact for a face
    can be computed as the average of the vertices of that face.

    The sphere can then be determined as the unique sphere through
    the four given centroids.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 August 2005

  Author:

    John Burkardt

  Reference:

    Philip Schneider, David Eberly,
    Geometric Tools for Computer Graphics,
    Elsevier, 2002,
    ISBN: 1558605940,
    LC: T385.G6974.

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double &R, PC[3], the radius and the center
    of the sphere.
*/
{
  double b[4*4];
  double gamma;
  int i;
  int j;
  double l123;
  double l124;
  double l134;
  double l234;
  double *n123;
  double *n124;
  double *n134;
  double *n234;
  double v21[3];
  double v31[3];
  double v41[3];
  double v32[3];
  double v42[3];
  double v43[3];

  tetrahedron_edges ( tetra, v21, v31, v41, v32, v42, v43 );

  n123 = r8vec_cross_3d ( v21, v31 );
  n124 = r8vec_cross_3d ( v41, v21 );
  n134 = r8vec_cross_3d ( v31, v41 );
  n234 = r8vec_cross_3d ( v42, v32 );

  l123 = r8vec_norm ( 3, n123 );
  l124 = r8vec_norm ( 3, n124 );
  l134 = r8vec_norm ( 3, n134 );
  l234 = r8vec_norm ( 3, n234 );

  free ( n123 );
  free ( n124 );
  free ( n134 );
  free ( n234 );

  for ( i = 0; i < 3; i++ )
  {
    pc[i] = ( l234 * tetra[i+0*3]
            + l134 * tetra[i+1*3]
            + l124 * tetra[i+2*3]
            + l123 * tetra[i+3*3] )
            / ( l234 + l134 + l124 + l123 );
  }

  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      b[i+j*4] = tetra[i+j*3];
    }
    b[3+j*4] = 1.0;
  }
  
  gamma = r8_abs ( r8mat_det_4d ( b ) );

  *r = gamma / ( l234 + l134 + l124 + l123 );

  return;
}
/******************************************************************************/

double tetrahedron_quality1 ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_QUALITY1: "quality" of a tetrahedron.

  Discussion:

    The quality of a tetrahedron is 3.0 times the ratio of the radius of
    the inscribed sphere divided by that of the circumscribed sphere.

    An equilateral tetrahredron achieves the maximum possible quality of 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 September 2005

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the tetrahedron vertices.

    Output, double TETRAHEDRON_QUALITY1, the quality of the tetrahedron.
*/
{
  double pc[3];
  double quality;
  double r_in;
  double r_out;

  tetrahedron_circumsphere ( tetra, &r_out, pc );

  tetrahedron_insphere ( tetra, &r_in, pc );

  quality = 3.0 * r_in / r_out;

  return quality;
}
/******************************************************************************/

double tetrahedron_quality2 ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_QUALITY2: "quality" of a tetrahedron.

  Discussion:

    The quality measure #2 of a tetrahedron is:

      QUALITY2 = 2 * sqrt ( 6 ) * RIN / LMAX

    where

      RIN = radius of the inscribed sphere;
      LMAX = length of longest side of the tetrahedron.

    An equilateral tetrahredron achieves the maximum possible quality of 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 August 2005

  Author:

    John Burkardt

  Reference:

    Qiang Du, Desheng Wang,
    The Optimal Centroidal Voronoi Tesselations and the Gersho's
    Conjecture in the Three-Dimensional Space,
    Computers and Mathematics with Applications,
    Volume 49, 2005, pages 1355-1373.

  Parameters:

    Input, double TETRA[3*4], the tetrahedron vertices.

    Output, double TETRAHEDRON_QUALITY2, the quality of the tetrahedron.
*/
{
  double *edge_length;
  double l_max;
  double pc[3];
  double quality2;
  double r_in;

  edge_length = tetrahedron_edge_length ( tetra );

  l_max = r8vec_max ( 6, edge_length );

  tetrahedron_insphere ( tetra, &r_in, pc );

  quality2 = 2.0 * sqrt ( 6.0 ) * r_in / l_max;

  free ( edge_length );

  return quality2;
}
/******************************************************************************/

double tetrahedron_quality3 ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_QUALITY3 computes the mean ratio of a tetrahedron.

  Discussion:

    This routine computes QUALITY3, the eigenvalue or mean ratio of
    a tetrahedron.

      QUALITY3 = 12 * ( 3 * volume )^(2/3) / (sum of square of edge lengths).

    This value may be used as a shape quality measure for the tetrahedron.

    For an equilateral tetrahedron, the value of this quality measure
    will be 1.  For any other tetrahedron, the value will be between
    0 and 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 August 2005

  Author:

    Original FORTRAN77 version by Barry Joe.
    C version by John Burkardt.

  Reference:

    Barry Joe,
    GEOMPACK - a software package for the generation of meshes
    using geometric algorithms,
    Advances in Engineering Software,
    Volume 13, pages 325-331, 1991.

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double TETRAHEDRON_QUALITY3, the mean ratio of the tetrahedron.
*/
{
  double ab[3];
  double ac[3];
  double ad[3];
  double bc[3];
  double bd[3];
  double cd[3];
  double denom;
  double lab;
  double lac;
  double lad;
  double lbc;
  double lbd;
  double lcd;
  double quality3;
  double volume;
/*
  Compute the vectors representing the sides of the tetrahedron.
*/
  tetrahedron_edges ( tetra, ab, ac, ad, bc, bd, cd );
/*
  Compute the squares of the lengths of the sides.
*/
  lab = pow ( ab[0], 2 ) + pow ( ab[1], 2 ) + pow ( ab[2], 2 );
  lac = pow ( ac[0], 2 ) + pow ( ac[1], 2 ) + pow ( ac[2], 2 );
  lad = pow ( ad[0], 2 ) + pow ( ad[1], 2 ) + pow ( ad[2], 2 );
  lbc = pow ( bc[0], 2 ) + pow ( bc[1], 2 ) + pow ( bc[2], 2 );
  lbd = pow ( bd[0], 2 ) + pow ( bd[1], 2 ) + pow ( bd[2], 2 );
  lcd = pow ( cd[0], 2 ) + pow ( cd[1], 2 ) + pow ( cd[2], 2 );
/*
  Compute the volume.
*/
  volume = r8_abs ( 
      ab[0] * ( ac[1] * ad[2] - ac[2] * ad[1] ) 
    + ab[1] * ( ac[2] * ad[0] - ac[0] * ad[2] ) 
    + ab[2] * ( ac[0] * ad[1] - ac[1] * ad[0] ) ) / 6.0;

  denom = lab + lac + lad + lbc + lbd + lcd;

  if ( denom == 0.0 )
  {
    quality3 = 0.0;
  }
  else
  {
    quality3 = 12.0 * pow ( 3.0 * volume, 2.0 / 3.0 ) / denom;
  }

  return quality3;
}
/******************************************************************************/

double tetrahedron_quality4 ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_QUALITY4 computes the minimum solid angle of a tetrahedron.

  Discussion:

    This routine computes a quality measure for a tetrahedron, based
    on the sine of half the minimum of the four solid angles.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 August 2005

  Author:

    Original FORTRAN77 version by Barry Joe.
    C version by John Burkardt.

  Reference:

    Barry Joe,
    GEOMPACK - a software package for the generation of meshes
    using geometric algorithms,
    Advances in Engineering Software,
    Volume 13, pages 325-331, 1991.

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double QUALITY4, the value of the quality measure.
*/
{
  double ab[3];
  double ac[3];
  double ad[3];
  double bc[3];
  double bd[3];
  double cd[3];
  double denom;
  double l1;
  double l2;
  double l3;
  double lab;
  double lac;
  double lad;
  double lbc;
  double lbd;
  double lcd;
  double quality4;
  double volume;
/*
  Compute the edges.
*/
  tetrahedron_edges ( tetra, ab, ac, ad, bc, bd, cd );
/*
  Compute the lengths of the sides.
*/
  lab = r8vec_norm ( 3, ab );
  lac = r8vec_norm ( 3, ac );
  lad = r8vec_norm ( 3, ad );
  lbc = r8vec_norm ( 3, bc );
  lbd = r8vec_norm ( 3, bd );
  lcd = r8vec_norm ( 3, cd );
/*
  Compute the volume.
*/
  volume = r8_abs ( 
      ab[0] * ( ac[1] * ad[2] - ac[2] * ad[1] ) 
    + ab[1] * ( ac[2] * ad[0] - ac[0] * ad[2] ) 
    + ab[2] * ( ac[0] * ad[1] - ac[1] * ad[0] ) ) / 6.0;

  quality4 = 1.0;

  l1 = lab + lac;
  l2 = lab + lad;
  l3 = lac + lad;

  denom = ( l1 + lbc ) * ( l1 - lbc ) 
        * ( l2 + lbd ) * ( l2 - lbd ) 
        * ( l3 + lcd ) * ( l3 - lcd );

  if ( denom <= 0.0 )
  {
    quality4 = 0.0;
  }
  else
  {
    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );
  }

  l1 = lab + lbc;
  l2 = lab + lbd;
  l3 = lbc + lbd;

  denom = ( l1 + lac ) * ( l1 - lac ) 
        * ( l2 + lad ) * ( l2 - lad ) 
        * ( l3 + lcd ) * ( l3 - lcd );

  if ( denom <= 0.0 )
  {
    quality4 = 0.0;
  }
  else
  {
    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );
  }

  l1 = lac + lbc;
  l2 = lac + lcd;
  l3 = lbc + lcd;

  denom = ( l1 + lab ) * ( l1 - lab ) 
        * ( l2 + lad ) * ( l2 - lad ) 
        * ( l3 + lbd ) * ( l3 - lbd );

  if ( denom <= 0.0 )
  {
    quality4 = 0.0;
  }
  else
  {
    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );
  }

  l1 = lad + lbd;
  l2 = lad + lcd;
  l3 = lbd + lcd;

  denom = ( l1 + lab ) * ( l1 - lab ) 
        * ( l2 + lac ) * ( l2 - lac ) 
        * ( l3 + lbc ) * ( l3 - lbc );

  if ( denom <= 0.0 )
  {
    quality4 = 0.0;
  }
  else
  {
    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );
  }

  quality4 = quality4 * 1.5 * sqrt ( 6.0 );

  return quality4;
}
/******************************************************************************/

double *tetrahedron_solid_angles ( double tetra[] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_SOLID_ANGLES computes solid angles of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 July 2009

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double TETRAHEDRON_SOLID_ANGLES[4], the solid angles.
*/
{
  double *angle;
  double *dihedral_angles;
  const double r8_pi = 3.141592653589793;

  dihedral_angles = tetrahedron_dihedral_angles ( tetra );

  angle = ( double * ) malloc ( 4 * sizeof ( double ) );

  angle[0] = dihedral_angles[0] 
           + dihedral_angles[1] 
           + dihedral_angles[2] - r8_pi;

  angle[1] = dihedral_angles[0] 
           + dihedral_angles[3] 
           + dihedral_angles[4] - r8_pi;

  angle[2] = dihedral_angles[1] 
           + dihedral_angles[3] 
           + dihedral_angles[5] - r8_pi;

  angle[3] = dihedral_angles[2] 
           + dihedral_angles[4] 
           + dihedral_angles[5] - r8_pi;

  free ( dihedral_angles );

  return angle;
}
/******************************************************************************/

double tetrahedron_volume ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_VOLUME computes the volume of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 August 2005

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the vertices of the tetrahedron.

    Output, double TETRAHEDRON_VOLUME, the volume of the tetrahedron.
*/
{
  double a[4*4];
  int i;
  int j;
  double volume;

  for ( i = 0; i < 3; i++ )
  {
    for ( j = 0; j < 4; j++ )
    { 
      a[i+j*4] = tetra[i+j*3];
    }
  }

  i = 3;
  for ( j = 0; j < 4; j++ )
  {
    a[i+j*4] = 1.0;
  }

  volume = r8_abs ( r8mat_det_4d ( a ) ) / 6.0;

  return volume;
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
/******************************************************************************/

void triangle_angles_3d ( double t[3*3], double angle[3] )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_ANGLES_3D computes the angles of a triangle in 3D.

  Discussion:

    The law of cosines is used:

      C * C = A * A + B * B - 2 * A * B * COS ( GAMMA )

    where GAMMA is the angle opposite side C.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 July 2005

  Author:

    John Burkardt

  Parameters:

    Input, double T[3*3], the triangle vertices.

    Output, double ANGLE[3], the angles opposite
    sides P1-P2, P2-P3 and P3-P1, in radians.
*/
{
  double a;
  double b;
  double c;
  const double r8_pi = 3.141592653589793;

  a = sqrt ( pow ( t[0+1*3] - t[0+0*3], 2 ) 
           + pow ( t[1+1*3] - t[1+0*3], 2 )
           + pow ( t[2+1*3] - t[2+0*3], 2 ) );

  b = sqrt ( pow ( t[0+2*3] - t[0+1*3], 2 ) 
           + pow ( t[1+2*3] - t[1+1*3], 2 )
           + pow ( t[2+2*3] - t[2+1*3], 2 ) );

  c = sqrt ( pow ( t[0+0*3] - t[0+2*3], 2 ) 
           + pow ( t[1+0*3] - t[1+2*3], 2 )
           + pow ( t[2+0*3] - t[2+2*3], 2 ) );
/*
  Take care of a ridiculous special case.
*/
  if ( a == 0.0 && b == 0.0 && c == 0.0 )
  {
    angle[0] = 2.0 * r8_pi / 3.0;
    angle[1] = 2.0 * r8_pi / 3.0;
    angle[2] = 2.0 * r8_pi / 3.0;
    return;
  }

  if ( c == 0.0 || a == 0.0 )
  {
    angle[0] = r8_pi;
  }
  else
  {
    angle[0] = r8_acos ( ( c * c + a * a - b * b ) / ( 2.0 * c * a ) );
  }

  if ( a == 0.0 || b == 0.0 )
  {
    angle[1] = r8_pi;
  }
  else
  {
    angle[1] = r8_acos ( ( a * a + b * b - c * c ) / ( 2.0 * a * b ) );
  }

  if ( b == 0.0 || c == 0.0 )
  {
    angle[2] = r8_pi;
  }
  else
  {
    angle[2] = r8_acos ( ( b * b + c * c - a * a ) / ( 2.0 * b * c ) );
  }

  return;
}
/******************************************************************************/

double triangle_area_3d ( double t[3*3] )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_AREA_3D computes the area of a triangle in 3D.

  Discussion:

    This routine uses the fact that the norm of the cross product vector
    is the area of the parallelogram they form.  The triangle they
    form has half that area.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 October 2005

  Author:

    John Burkardt

  Reference:

    Adrian Bowyer, John Woodwark,
    A Programmer's Geometry,
    Butterworths, 1983.

  Parameters:

    Input, double T[3*3], the vertices of the triangle.

    Output, double TRIANGLE_AREA_3D, the area of the triangle.
*/
{
  double area;
  double *cross;
  int i;
/*
  Compute the cross product vector.
*/
  cross = ( double * ) malloc ( 3 * sizeof ( double ) );

  cross[0] = ( t[1+1*3] - t[1+0*3] ) 
           * ( t[2+2*3] - t[2+0*3] ) 
           - ( t[2+1*3] - t[2+0*3] ) 
           * ( t[1+2*3] - t[1+0*3] );

  cross[1] = ( t[2+1*3] - t[2+0*3] ) 
           * ( t[0+2*3] - t[0+0*3] ) 
           - ( t[0+1*3] - t[0+0*3] ) 
           * ( t[2+2*3] - t[2+0*3] );

  cross[2] = ( t[0+1*3] - t[0+0*3] ) 
           * ( t[1+2*3] - t[1+0*3] ) 
           - ( t[1+1*3] - t[1+0*3] ) 
           * ( t[0+2*3] - t[0+0*3] );

  area = 0.0;
  for ( i = 0; i < 3; i++ )
  {
    area = area + pow ( cross[i], 2 );
  }
  
  area = 0.5 * sqrt ( area );

  free ( cross );

  return area;
}
