# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

int main ( int argc, char *argv[] );
char ch_cap ( char ch );
int ch_eqi ( char ch1, char ch2 );
int ch_to_digit ( char ch );
double *fem1d_approximate ( int sample_node_num, int sample_value_dim, 
  double sample_node_x[], double sample_value[], int fem_node_num, 
  double fem_node_x[], int fem_element_order, int fem_element_num, 
  int fem_value_dim, int fem_value_num );
int file_column_count ( char *input_filename );
int file_row_count ( char *input_filename );
int *i4mat_data_read ( char *input_filename, int m, int n );
void i4mat_header_read ( char *input_filename, int *m, int *n );
double piecewise_linear_product_quad ( double a, double b, int f_num, 
  double f_x[], double f_v[], int g_num, double g_x[], double g_v[] );
double r8_abs ( double x );
double r8_epsilon ( );
double r8_min ( double x, double y );
int r83_np_fa ( int n, double a[] );
double *r83_np_sl ( int n, double a_lu[], double b[], int job );
double *r8mat_data_read ( char *input_filename, int m, int n );
void r8mat_header_read ( char *input_filename, int *m, int *n );
void r8mat_write ( char *output_filename, int m, int n, double table[] );
double *r8mat_zero_new ( int m, int n );
void r8vec_bracket3 ( int n, double t[], double tval, int *left );
int s_len_trim ( char *s );
int s_to_i4 ( char *s, int *last, int *error );
int s_to_i4vec ( char *s, int n, int ivec[] );
double s_to_r8 ( char *s, int *lchar, int *error );
int s_to_r8vec ( char *s, int n, double rvec[] );
int s_word_count ( char *s );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for FEM1D_PROJECT.

  Discussion:

    FEM1D_PROJECT reads files defining a sampling of a (scalar or vector)
    function of 1 argument, and a list of nodes and elements to use for
    a finite element representation of the data.

    It computes a set of finite element coefficients to be associated with
    the given finite element mesh, and writes that information to a file
    so that an FEM representation is formed by the node, element and value 
    files.

  Usage:

    fem1d_project sample_prefix fem_prefix

    where 'sample_prefix' is the common prefix for the SAMPLE files:

    * sample_prefix_nodes.txt,  the node coordinates where samples were taken,
    * sample_prefix_values.txt, the sample values.

    and 'fem_prefix' is the common prefix for the FEM files:

    * fem_prefix_nodes.txt,    the node coordinates.
    * fem_prefix_elements.txt, the nodes that make up each element;
    * fem_prefix_values.txt,   the values defined at each node.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 July 2019

  Author:

    John Burkardt
*/
{
  char fem_element_filename[255];
  int *fem_element_node;
  int fem_element_num;
  int fem_element_order;
  int fem_node_dim;
  char fem_node_filename[255];
  int fem_node_num;
  double *fem_node_x;
  char fem_prefix[255];
  double *fem_value;
  int fem_value_dim;
  char fem_value_filename[255];
  int fem_value_num;
  char sample_prefix[255];
  int sample_node_dim;
  char sample_node_filename[255];
  int sample_node_num;
  double *sample_node_x;
  int sample_value_dim;
  int sample_value_num;
  double *sample_value;
  char sample_value_filename[255];

  timestamp ( );

  printf ( "\n" );
  printf ( "FEM1D_PROJECT\n" );
  printf ( "  C version.\n" );
  printf ( "\n" );
  printf ( "  Read files defining a sampling of a function of 1 argument.\n" );
  printf ( "  Read files defining a finite element mesh.\n" );
  printf ( "  Project the sample data onto the mesh, and\n" );
  printf ( "  write a file of FEM coefficient values.\n" );
/*
  Get the number of command line arguments.
*/
  if ( 1 < argc )
  {
    strcpy ( sample_prefix, argv[1] );
  }
  else
  {
    printf ( "\n" );
    printf ( "Enter the sample file prefix:\n" );
    scanf ( "%s", sample_prefix );
  }

  if ( 2 < argc )
  {
    strcpy ( fem_prefix, argv[2] );
  }
  else
  {
    printf ( "\n" );
    printf ( "Enter the FEM file prefix:\n" );
    scanf ( "%s", fem_prefix );
  }
/*
  Create the filenames.
*/
  strcpy ( sample_node_filename, sample_prefix );
  strcat ( sample_node_filename, "_nodes.txt" );
  strcpy ( sample_value_filename, sample_prefix );
  strcat ( sample_value_filename, "_values.txt" );

  strcpy ( fem_node_filename, fem_prefix );
  strcat ( fem_node_filename, "_nodes.txt" );
  strcpy ( fem_element_filename, fem_prefix );
  strcat ( fem_element_filename, "_elements.txt" );
  strcpy ( fem_value_filename, fem_prefix );
  strcat ( fem_value_filename, "_values.txt" );
/*
  Read the SAMPLE data.
*/
  r8mat_header_read ( sample_node_filename, &sample_node_dim, 
    &sample_node_num );

  sample_node_x = r8mat_data_read ( sample_node_filename, sample_node_dim, 
    sample_node_num );

  printf ( "\n" );
  printf ( "  Sample node spatial dimension is %d\n", sample_node_dim );
  printf ( "  Sample node number is            %d\n", sample_node_num );

  if ( sample_node_dim != 1 )
  {
    printf ( "\n" );
    printf ( "FEM1D_PROJECT - Fatal error!\n" );
    printf ( "  Spatial dimension of the sample nodes is not 1.\n" );
    exit ( 1 );
  }

  r8mat_header_read ( sample_value_filename, &sample_value_dim,
    &sample_value_num );

  printf ( "  The SAMPLE value dimension is    %d\n", sample_value_dim );
  printf ( "  the SAMPLE value number is        %d\n", sample_value_num );

  if ( sample_value_num != sample_node_num )
  {
    printf ( "\n" );
    printf ( "FEM1D_PROJECT - Fatal error!\n" );
    printf ( "  Number of sample values and nodes differ.\n" );
    exit ( 1 );
  }
  sample_value = r8mat_data_read ( sample_value_filename, sample_value_dim, 
    sample_value_num );
/*
  Read the FEM data.
*/
  r8mat_header_read ( fem_node_filename, &fem_node_dim, &fem_node_num );

  printf ( "\n" );
  printf ( "  The FEM node dimension is        %d\n", fem_node_dim );
  printf ( "  The FEM node number is           %d\n", fem_node_num );

  if ( fem_node_dim != 1 )
  {
    printf ( "\n" );
    printf ( "FEM1D_PROJECT - Fatal error!\n" );
    printf ( "  Spatial dimension of the nodes is not 1.\n" );
    exit ( 1 );
  }

  fem_node_x = r8mat_data_read ( fem_node_filename, fem_node_dim, fem_node_num );

  i4mat_header_read ( fem_element_filename, &fem_element_order, &fem_element_num );

  printf ( "  The FEM element order is         %d\n", fem_element_order );
  printf ( "  The FEM element number is        %d\n", fem_element_num );

  fem_element_node = i4mat_data_read ( fem_element_filename, fem_element_order, 
    fem_element_num );
/*
  Compute the FEM values.
*/
  fem_value_dim = sample_value_dim;
  fem_value_num = fem_node_num;

  fem_value = fem1d_approximate ( sample_node_num, sample_value_dim, sample_node_x, 
    sample_value, fem_node_num, fem_node_x, fem_element_order, 
    fem_element_num, fem_value_dim, fem_value_num );
/*
  Write the FEM values.
*/
  r8mat_write ( fem_value_filename, fem_value_dim, fem_value_num, 
    fem_value );

  printf ( "\n" );
  printf ( "  Projected FEM values written to \"%s\"\n", fem_value_filename );
/*
  Free memory.
*/
  free ( fem_element_node );
  free ( fem_node_x );
  free ( fem_value );
  free ( sample_node_x );
  free ( sample_value );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "FEM1D_PROJECT\n" );
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

double *fem1d_approximate ( int sample_node_num, int sample_value_dim, 
  double sample_node_x[], double sample_value[], int fem_node_num, 
  double fem_node_x[], int fem_element_order, int fem_element_num, 
  int fem_value_dim, int fem_value_num )

/******************************************************************************/
/*
  Purpose:

    FEM1D_APPROXIMATE approximates data at sample points with an FEM function.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 July 2013

  Author:

    John Burkardt

  Parameters:

    Input, int SAMPLE_NODE_NUM, the number of sample points.

    Input, int SAMPLE_VALUE_DIM, the value dimension.

    Input, double SAMPLE_NODE_X[SAMPLE_NODE_NUM], the sample nodes.

    Input, double SAMPLE_VALUE[VALUE_DIM*SAMPLE_NODE_NUM],
    the values at sample nodes.

    Input, int FEM_NODE_NUM, the number of FEM nodes.

    Input, double FEM_NODE_X[FEM_NODE_NUM], the FEM nodes.  

    Input, int FEM_ELEMENT_ORDER, the element order.

    Input, int FEM_ELEMENT_NUM, the number of elements.

    Input, int FEM_VALUE_DIM, the FEM value dimension.

    Input, int FEM_VALUE_NUM, the number of FEM values.

    Output, double FEM1D_APPROXIMATE[FEM_VALUE_DIM*FEM_VALUE_NUM], 
    the FEM values.
*/
{
# define QUAD_NUM 2

  double *a;
  double a1;
  double *b;
  double b1;
  int dim;
  double *fem_value;
  int i;
  double integral;
  int j;
  int job;
  int l;
  int phi_num;
  double phi_v[3];
  double phi_x[3];
  double phil;
  double phir;
  int quad;
  int quad_num = QUAD_NUM;
  double quad_x[QUAD_NUM] = {
    -0.577350269189625764509148780502, 
     0.577350269189625764509148780502 };
  double quad_w[QUAD_NUM] = { 1.0, 1.0 };
  int r;
  double *v;
  double wq;
  double *x;
  double xl;
  double xq;
  double xr;
/*
  Set up the matrix A.
*/
  a = r8mat_zero_new ( 3, fem_node_num );

  for ( l = 0; l < fem_node_num - 1; l++ )
  {
    r = l + 1;
    xl = fem_node_x[l];
    xr = fem_node_x[r];

    for ( quad = 0; quad < quad_num; quad++ )
    {
      xq = ( ( 1.0 - quad_x[quad] ) * xl   
           + ( 1.0 + quad_x[quad] ) * xr ) 
           /   2.0;

      wq = quad_w[quad] * ( xr - xl ) / 2.0;

      phil = (      xq - xr ) 
           / ( xl      - xr );

      phir = ( xl - xq      ) 
           / ( xl      - xr );

      a[1+l*3] = a[1+l*3] + wq * phil * phil;
      a[2+l*3] = a[2+l*3] + wq * phil * phir;

      a[0+r*3] = a[0+r*3] + wq * phir * phil;
      a[1+r*3] = a[1+r*3] + wq * phir * phir;
    }
  }
  r83_np_fa ( fem_node_num, a );
/*
  Set up the right hand side b.
*/
  b = ( double * ) malloc ( fem_node_num * sizeof ( double ) );
  v = ( double * ) malloc ( sample_node_num * sizeof ( double ) );
  fem_value = ( double * ) malloc ( fem_value_dim * fem_value_num * sizeof ( double ) );

  for ( dim = 0; dim < fem_value_dim; dim++ )
  {
    for ( i = 0; i < fem_node_num; i++ )
    {
      if ( i == 0 )
      {
        phi_num = 2;
        phi_x[0] = fem_node_x[0];
        phi_x[1] = fem_node_x[1];
        phi_v[0] = 1.0;
        phi_v[1] = 0.0;
      }
      else if ( i < fem_node_num - 1 )
      {
        phi_num = 3;
        phi_x[0] = fem_node_x[i-1];
        phi_x[1] = fem_node_x[i];
        phi_x[2] = fem_node_x[i+1];
        phi_v[0] = 0.0;
        phi_v[1] = 1.0;
        phi_v[2] = 0.0;
      }
      else if ( i == fem_node_num - 1 )
      {
        phi_num = 2;
        phi_x[0] = fem_node_x[fem_node_num-2];
        phi_x[1] = fem_node_x[fem_node_num-1];
        phi_v[0] = 0.0;
        phi_v[1] = 1.0;
      }

      a1 = phi_x[0];
      b1 = phi_x[phi_num-1];

      for ( j = 0; j < sample_node_num; j++ )
      {
        v[j] = sample_value[dim+j*sample_value_dim];
      }

      integral = piecewise_linear_product_quad ( a1, b1, phi_num, phi_x, 
        phi_v, sample_node_num, sample_node_x, v );

      b[i] = integral;
    }
    job = 0;
    x = r83_np_sl ( fem_node_num, a, b, job );

    for ( i = 0; i < fem_node_num; i++ )
    {
      fem_value[dim+i*fem_value_dim] = x[i];
    }
    free ( x );
  }

  free ( a );
  free ( b );
  free (  v );

  return fem_value;
# undef QUAD_NUM
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
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n", input_filename );
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
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n", input_filename );
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

int *i4mat_data_read ( char *input_filename, int m, int n )

/******************************************************************************/
/*
  Purpose:

    I4MAT_DATA_READ reads the data from an I4MAT file.

  Discussion:

    An I4MAT is an array of I4's.

    The file is assumed to contain one record per line.

    Records beginning with the '#' character are comments, and are ignored.
    Blank lines are also ignored.

    Each line that is not ignored is assumed to contain exactly (or at least)
    M real numbers, representing the coordinates of a point.

    There are assumed to be exactly (or at least) N such records.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2008

  Author:

    John Burkardt

  Parameters:

    Input, char *INPUT_FILENAME, the name of the input file.

    Input, int M, the number of spatial dimensions.

    Input, int N, the number of points.  The program
    will stop reading data once N values have been read.

    Output, int I4MAT_DATA_READ[M*N], the data.
*/
{
# define LINE_MAX 255

  int error;
  char *got_string;
  FILE *input;
  int i;
  int j;
  char line[255];
  int *table;
  int *x;

  input = fopen ( input_filename, "r" );

  if ( !input )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4MAT_DATA_READ - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the input file: \"%s\"\n", input_filename );
    exit ( 1 );
  }

  table = ( int * ) malloc ( m * n * sizeof ( int ) );

  x = ( int * ) malloc ( m * sizeof ( int ) );

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

    error = s_to_i4vec ( line, m, x );

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
 
void i4mat_header_read ( char *input_filename, int *m, int *n )
 
/******************************************************************************/
/*
  Purpose:

    I4MAT_HEADER_READ reads the header from an I4MAT file.

  Discussion:

    An I4MAT is an array of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2008

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
    fprintf ( stderr, "I4MAT_HEADER_READ - Fatal error!\n" );
    fprintf ( stderr, "  FILE_COLUMN_COUNT failed.\n" );
    exit ( 1 );
  }

  *n = file_row_count ( input_filename );

  if ( *n <= 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4MAT_HEADER_READ - Fatal error!\n" );
    fprintf ( stderr, "  FILE_ROW_COUNT failed.\n" );
    exit ( 1 );
  }

  return;
}
/******************************************************************************/

double piecewise_linear_product_quad ( double a, double b, int f_num, 
  double f_x[], double f_v[], int g_num, double g_x[], double g_v[] )

/******************************************************************************/
/*
  Purpose:

    PIECEWISE_LINEAR_PRODUCT_QUAD: piecewise linear product integral.

  Discussion:

    We are given two piecewise linear functions F(X) and G(X) and we wish
    to compute the exact value of the integral

      INTEGRAL = Integral ( A <= X <= B ) F(X) * G(X) dx

    The functions F(X) and G(X) are defined as tables of coordinates X and
    values V.  A piecewise linear function is evaluated at a point X by 
    evaluating the interpolant to the data at the endpoints of the interval 
    containing X.  

    It must be the case that A <= B.

    It must be the case that the node coordinates F_X(*) and G_X(*) are
    given in ascending order.

    It must be the case that:

      F_X(1) <= A and B <= F_X(F_NUM)
      G_X(1) <= A and B <= G_X(G_NUM)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 July 2013

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, the limits of integration.

    Input, int F_NUM, the number of nodes for F.

    Input, double F_X[F_NUM], the node coordinates for F.

    Input, double F_V[F_NUM], the nodal values for F.

    Input, int G_NUM, the number of nodes for G.

    Input, double G_X[G_NUM], the node coordinates for G.

    Input, double G_V[G_NUM], the nodal values for G.

    Output, double INTEGRAL, the integral of F(X) * G(X)
    from A to B.
*/
{
  double bit;
  int f_left;
  double f0;
  double f1;
  double fl;
  double fr;
  int g_left;
  double g0;
  double g1;
  double gl;
  double gr;
  double h0;
  double h1;
  double h2;
  int i;
  double integral;
  double xl;
  double xr;
  double xr_max;

  integral = 0.0;

  if ( f_x[f_num-1] <= a || g_x[g_num-1] <= a )
  {
    return integral;
  }

  if ( f_num < 2 || g_num < 2 )
  {
    return integral;
  }

  xr = a;

  f_left = 0;
  r8vec_bracket3 ( f_num, f_x, xr, &f_left );
  fr = f_v[f_left] + ( xr - f_x[f_left] ) * ( f_v[f_left+1] - f_v[f_left] ) 
    / ( f_x[f_left+1] - f_x[f_left] );

  g_left = 0;
  r8vec_bracket3 ( g_num, g_x, xr, &g_left );
  gr = g_v[g_left] + ( xr - g_x[g_left] ) * ( g_v[g_left+1] - g_v[g_left] ) 
    / ( g_x[g_left+1] - g_x[g_left] );

  xr_max = b;
  xr_max = r8_min ( xr_max, f_x[f_num-1] );
  xr_max = r8_min ( xr_max, g_x[g_num-1] );

  while ( xr < xr_max )
  {
/*
  Shift right values to left.
*/
    xl = xr;
    fl = fr;
    gl = gr;
/*
  Determine the new right values.
  The hard part is figuring out how to advance XR some, but not too much.
*/
    xr = xr_max;

    for ( i = 1; i <= 2; i++ )
    {
      if ( f_left + i <= f_num - 1 )
      {
        if ( xl < f_x[f_left+i] && f_x[f_left+i] < xr )
        {
          xr = f_x[f_left+i];
          break;
        }
      }
    }

    for ( i = 1; i <= 2; i++ )
    {
      if ( g_left + i <= g_num - 1 )
      {
        if ( xl < g_x[g_left+i] && g_x[g_left+i] < xr )
        {
          xr = g_x[g_left+i];
          break;
        }
      }
    }

    r8vec_bracket3 ( f_num, f_x, xr, &f_left );
    fr = f_v[f_left] + ( xr - f_x[f_left] ) * ( f_v[f_left+1] - f_v[f_left] ) 
      / ( f_x[f_left+1] - f_x[f_left] );

    r8vec_bracket3 ( g_num, g_x, xr, &g_left );
    gr = g_v[g_left] + ( xr - g_x[g_left] ) * ( g_v[g_left+1] - g_v[g_left] ) 
      / ( g_x[g_left+1] - g_x[g_left] );
/*
  Form the linear polynomials for F(X) and G(X) over [XL,XR],
  then the product H(X), integrate H(X) and add to the running total.
*/
    if ( r8_epsilon ( ) <= r8_abs ( xr - xl ) )
    {
      f1 = fl - fr;
      f0 = fr * xl - fl * xr;

      g1 = gl - gr;
      g0 = gr * xl - gl * xr;

      h2 = f1 * g1;
      h1 = f1 * g0 + f0 * g1;
      h0 = f0 * g0;

      h2 = h2 / 3.0;
      h1 = h1 / 2.0;

      bit = ( ( h2 * xr + h1 ) * xr + h0 ) * xr 
          - ( ( h2 * xl + h1 ) * xl + h0 ) * xl;

      integral = integral + bit / ( xr - xl ) / ( xr - xl );
    }
  }

  return integral;
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

double r8_epsilon ( )

/******************************************************************************/
/*
  Purpose:

    R8_EPSILON returns the R8 round off unit.

  Discussion:

    R8_EPSILON is a number R which is a power of 2 with the property that,
    to the precision of the computer's arithmetic,
      1 < 1 + R
    but
      1 = ( 1 + R / 2 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 September 2012

  Author:

    John Burkardt

  Parameters:

    Output, double R8_EPSILON, the R8 round-off unit.
*/
{
  const double value = 2.220446049250313E-016;

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

int r83_np_fa ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R83_NP_FA factors a R83 system without pivoting.

  Discussion:

    The R83 storage format is used for a tridiagonal matrix.
    The superdiagonal is stored in entries (1,2:N), the diagonal in
    entries (2,1:N), and the subdiagonal in (3,1:N-1).  Thus, the
    original matrix is "collapsed" vertically into the array.

    Because this routine does not use pivoting, it can fail even when
    the matrix is not singular, and it is liable to make larger
    errors.

    R83_NP_FA and R83_NP_SL may be preferable to the corresponding
    LINPACK routine SGTSL for tridiagonal systems, which factors and solves
    in one step, and does not save the factorization.

  Example:

    Here is how a R83 matrix of order 5 would be stored:

       *  A12 A23 A34 A45
      A11 A22 A33 A44 A55
      A21 A32 A43 A54  *

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be at least 2.

    Input/output, double A[3*N].
    On input, the tridiagonal matrix.  On output, factorization information.

    Output, int R83_NP_FA, singularity flag.
    0, no singularity detected.
    nonzero, the factorization failed on the INFO-th step.
*/
{
  int i;

  for ( i = 1; i <= n-1; i++ )
  {
    if ( a[1+(i-1)*3] == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R83_NP_FA - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", i );
      return i;
    }
/*
  Store the multiplier in L.
*/
    a[2+(i-1)*3] = a[2+(i-1)*3] / a[1+(i-1)*3];
/*
  Modify the diagonal entry in the next column.
*/
    a[1+i*3] = a[1+i*3] - a[2+(i-1)*3] * a[0+i*3];
  }

  if ( a[1+(n-1)*3] == 0.0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R83_NP_FA - Fatal error!\n" );
    fprintf ( stderr, "  Zero pivot on step %d\n", n );
    return n;
  }

  return 0;
}
/******************************************************************************/

double *r83_np_sl ( int n, double a_lu[], double b[], int job )

/******************************************************************************/
/*
  Purpose:

    R83_NP_SL solves a R83 system factored by R83_NP_FA.

  Discussion:

    The R83 storage format is used for a tridiagonal matrix.
    The superdiagonal is stored in entries (1,2:N), the diagonal in
    entries (2,1:N), and the subdiagonal in (3,1:N-1).  Thus, the
    original matrix is "collapsed" vertically into the array.

  Example:

    Here is how a R83 matrix of order 5 would be stored:

       *  A12 A23 A34 A45
      A11 A22 A33 A44 A55
      A21 A32 A43 A54  *

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be at least 2.

    Input, double A_LU[3*N], the LU factors from R83_NP_FA.

    Input, double B[N], the right hand side of the linear system.
    On output, B contains the solution of the linear system.

    Input, int JOB, specifies the system to solve.
    0, solve A * x = b.
    nonzero, solve A' * x = b.

    Output, double R83_NP_SL[N], the solution of the linear system.
*/
{
  int i;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    x[i] = b[i];
  }

  if ( job == 0 )
  {
/*
  Solve L * Y = B.
*/
    for ( i = 1; i < n; i++ )
    {
      x[i] = x[i] - a_lu[2+(i-1)*3] * x[i-1];
    }
/*
  Solve U * X = Y.
*/
    for ( i = n; 1 <= i; i-- )
    {
      x[i-1] = x[i-1] / a_lu[1+(i-1)*3];
      if ( 1 < i )
      {
        x[i-2] = x[i-2] - a_lu[0+(i-1)*3] * x[i-1];
      }
    }
  }
  else
  {
/*
  Solve U' * Y = B
*/
    for ( i = 1; i <= n; i++ )
    {
      x[i-1] = x[i-1] / a_lu[1+(i-1)*3];
      if ( i < n )
      {
        x[i] = x[i] - a_lu[0+i*3] * x[i-1];
      }
    }
/*
  Solve L' * X = Y.
*/
    for ( i = n-1; 1 <= i; i-- )
    {
      x[i-1] = x[i-1] - a_lu[2+(i-1)*3] * x[i];
    }
  }

  return x;
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

void r8mat_write ( char *output_filename, int m, int n, double table[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_WRITE writes an R8MAT file.

  Discussion:

    An R8MAT is an array of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 June 2009

  Author:

    John Burkardt

  Parameters:

    Input, char *OUTPUT_FILENAME, the output filename.

    Input, int M, the spatial dimension.

    Input, int N, the number of points.

    Input, double TABLE[M*N], the data.
*/
{
  int i;
  int j;
  FILE *output;
/*
  Open the file.
*/
  output = fopen ( output_filename, "wt" );

  if ( !output )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8MAT_WRITE - Fatal error!\n" );
    fprintf ( stderr, "  Could not open the output file.\n" );
    exit ( 1 );
  }
/*
  Write the data.
*/
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      fprintf ( output, "  %24.16g", table[i+j*m] );
    }
    fprintf ( output, "\n" );
  }
/*
  Close the file.
*/
  fclose ( output );

  return;
}
/******************************************************************************/

double *r8mat_zero_new ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8MAT_ZERO_NEW returns a new zeroed R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 September 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Output, double R8MAT_ZERO_NEW[M*N], the new zeroed matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }
  return a;
}
/******************************************************************************/

void r8vec_bracket3 ( int n, double t[], double tval, int *left )

/******************************************************************************/
/*
  Purpose:

    R8VEC_BRACKET3 finds the interval containing or nearest a given value.

  Discussion:

    An R8VEC is a vector of R8's.

    The routine always returns the index LEFT of the sorted array
    T with the property that either
    *  T is contained in the interval [ T[LEFT], T[LEFT+1] ], or
    *  T < T[LEFT] = T[0], or
    *  T > T[LEFT+1] = T[N-1].

    The routine is useful for interpolation problems, where
    the abscissa must be located within an interval of data
    abscissas for interpolation, or the "nearest" interval
    to the (extreme) abscissa must be found so that extrapolation
    can be carried out.

    This version of the function has been revised so that the value of
    LEFT that is returned uses the 0-based indexing natural to C++.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, length of the input array.

    Input, double T[N], an array that has been sorted into ascending order.

    Input, double TVAL, a value to be bracketed by entries of T.

    Input/output, int *LEFT.
    On input, if 0 <= LEFT <= N-2, LEFT is taken as a suggestion for the
    interval [ T[LEFT-1] T[LEFT] ] in which TVAL lies.  This interval
    is searched first, followed by the appropriate interval to the left
    or right.  After that, a binary search is used.
    On output, LEFT is set so that the interval [ T[LEFT], T[LEFT+1] ]
    is the closest to TVAL; it either contains TVAL, or else TVAL
    lies outside the interval [ T[0], T[N-1] ].
*/
{
  int high;
  int low;
  int mid;
/*
  Check the input data.
*/
  if ( n < 2 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_BRACKET3 - Fatal error\n" );
    fprintf ( stderr, "  N must be at least 2.\n" );
    exit ( 1 );
  }
/*
  If *LEFT is not between 0 and N-2, set it to the middle value.
*/
  if ( *left < 0 || n - 2 < *left )
  {
    *left = ( n - 1 ) / 2;
  }
/*
  CASE 1: TVAL < T[*LEFT]:
  Search for TVAL in (T[I],T[I+1]), for I = 0 to *LEFT-1.
*/
  if ( tval < t[*left] )
  {
    if ( *left == 0 )
    {
      return;
    }
    else if ( *left == 1 )
    {
      *left = 0;
      return;
    }
    else if ( t[*left-1] <= tval )
    {
      *left = *left - 1;
      return;
    }
    else if ( tval <= t[1] )
    {
      *left = 0;
      return;
    }
/*
  ...Binary search for TVAL in (T[I],T[I+1]), for I = 1 to *LEFT-2.
*/
    low = 1;
    high = *left - 2;

    for ( ; ; )
    {
      if ( low == high )
      {
        *left = low;
        return;
      }

      mid = ( low + high + 1 ) / 2;

      if ( t[mid] <= tval )
      {
        low = mid;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
/*
  CASE 2: T[*LEFT+1] < TVAL:
  Search for TVAL in (T[I],T[I+1]) for intervals I = *LEFT+1 to N-2.
*/
  else if ( t[*left+1] < tval )
  {
    if ( *left == n - 2 )
    {
      return;
    }
    else if ( *left == n - 3 )
    {
      *left = *left + 1;
      return;
    }
    else if ( tval <= t[*left+2] )
    {
      *left = *left + 1;
      return;
    }
    else if ( t[n-2] <= tval )
    {
      *left = n - 2;
      return;
    }
/*
  ...Binary search for TVAL in (T[I],T[I+1]) for intervals I = *LEFT+2 to N-3.
*/
    low = *left + 2;
    high = n - 3;

    for ( ; ; )
    {

      if ( low == high )
      {
        *left = low;
        return;
      }

      mid = ( low + high + 1 ) / 2;

      if ( t[mid] <= tval )
      {
        low = mid;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
/*
  CASE 3: T[*LEFT] <= TVAL <= T[*LEFT+1]:
  T is just where the user said it might be.
*/
  else
  {
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

int s_to_i4 ( char *s, int *last, int *error )

/******************************************************************************/
/*
  Purpose:

    S_TO_I4 reads an I4 from a string.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2003

  Author:

    John Burkardt

  Parameters:

    Input, char *S, a string to be examined.

    Output, int *LAST, the last character of S used to make IVAL.

    Output, int *ERROR is TRUE (1) if an error occurred and FALSE (0) otherwise.

    Output, int *S_TO_I4, the integer value read from the string.
    If the string is blank, then IVAL will be returned 0.
*/
{
  char c;
  int i;
  int isgn;
  int istate;
  int ival;

  *error = 0;
  istate = 0;
  isgn = 1;
  i = 0;
  ival = 0;

  while ( *s ) 
  {
    c = s[i];
    i = i + 1;
/*
  Haven't read anything.
*/
    if ( istate == 0 )
    {
      if ( c == ' ' )
      {
      }
      else if ( c == '-' )
      {
        istate = 1;
        isgn = -1;
      }
      else if ( c == '+' )
      {
        istate = 1;
        isgn = + 1;
      }
      else if ( '0' <= c && c <= '9' )
      {
        istate = 2;
        ival = c - '0';
      }
      else
      {
        *error = 1;
        return ival;
      }
    }
/*
  Have read the sign, expecting digits.
*/
    else if ( istate == 1 )
    {
      if ( c == ' ' )
      {
      }
      else if ( '0' <= c && c <= '9' )
      {
        istate = 2;
        ival = c - '0';
      }
      else
      {
        *error = 1;
        return ival;
      }
    }
/*
  Have read at least one digit, expecting more.
*/
    else if ( istate == 2 )
    {
      if ( '0' <= c && c <= '9' )
      {
        ival = 10 * (ival) + c - '0';
      }
      else
      {
        ival = isgn * ival;
        *last = i - 1;
        return ival;
      }

    }
  }
/*
  If we read all the characters in the string, see if we're OK.
*/
  if ( istate == 2 )
  {
    ival = isgn * ival;
    *last = s_len_trim ( s );
  }
  else
  {
    *error = 1;
    *last = 0;
  }

  return ival;
}
/******************************************************************************/

int s_to_i4vec ( char *s, int n, int ivec[] )

/******************************************************************************/
/*
  Purpose:

    S_TO_I4VEC reads an I4VEC from a string.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 February 2001

  Author:

    John Burkardt

  Parameters:

    Input, char *S, the string to be read.

    Input, int N, the number of values expected.

    Output, int IVEC[N], the values read from the string.

    Output, int S_TO_I4VEC, is TRUE (1) if an error occurred and
    FALSE (0) otherwise.
*/
{
  int error;
  int i;
  int lchar;

  error = 0;

  for ( i = 0; i < n; i++ )
  {
    ivec[i] = s_to_i4 ( s, &lchar, &error );

    if ( error )
    {
      return error;
    }

    s = s + lchar;

  }

  return error;
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
