# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>

int main ( int argc, char *argv[] );
char ch_cap ( char ch );
int ch_eqi ( char ch1, char ch2 );
int ch_to_digit ( char ch );
int file_column_count ( char *input_filename );
int file_row_count ( char *input_filename );
double hermite_integral ( int n, int option );
double hermite_monomial_quadrature ( int expon, int order, int option,
  double w[], double x[] );
double r8_factorial2 ( int n );
double *r8mat_data_read ( char *input_filename, int m, int n );
void r8mat_header_read ( char *input_filename, int *m, int *n );
int s_len_trim ( char *s );
int s_to_i4 ( char *s, int *last, int *error );
double s_to_r8 ( char *s, int *lchar, int *error );
int s_to_r8vec ( char *s, int n, double rvec[] );
int s_word_count ( char *s );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for HERMITE_EXACTNESS.

  Discussion:

    This program investigates a standard Gauss-Hermite quadrature rule
    by using it to integrate monomials over (-oo,+oo), and comparing the
    approximate result to the known exact value.

    The user specifies:
    * the "root" name of the R, W and X files that specify the rule;
    * DEGREE_MAX, the maximum monomial degree to be checked.
    * the OPTION (unweighted/physicist weight/probabilist weight)

    OPTION indicates the weight function and normalization:
    0, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
    1, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
    2, Integral ( -oo < x < +oo ) x^n exp(-x*x/2)             dx.
    3, Integral ( -oo < x < +oo ) x^n exp(-x*x)   / sqrt (pi) dx.
    4, Integral ( -oo < x < +oo ) x^n exp(-x*x/2) / sqrt(2pi) dx.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 May 2014

  Author:

    John Burkardt
*/
{
  int degree;
  int degree_max;
  int dim_num;
  int dim_num2;
  int i;
  int option;
  int order;
  int point_num;
  int point_num2;
  double quad_error;
  char quad_filename[255];
  char quad_r_filename[255];
  char quad_w_filename[255];
  char quad_x_filename[255];
  double *r;
  double *w;
  double *x;

  timestamp ( );
  printf ( "\n" );
  printf ( "HERMITE_EXACTNESS\n" );
  printf ( "  C version\n" );
  printf ( "\n" );
  printf ( "  Investigate the polynomial exactness of a Gauss-Hermite\n" );
  printf ( "  quadrature rule by integrating exponentially weighted\n" );
  printf ( "  monomials up to a given degree over the (-oo,+oo) interval.\n" );
/*
  Get the quadrature file rootname.
*/
  if ( 1 < argc )
  {
    strcpy ( quad_filename, argv[1] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter the quadrature file rootname:\n" );
    scanf ( "%s", quad_filename );
  }

  printf ( "\n" );
  printf ( "  The quadrature file rootname is \"%s\".\n", quad_filename );
/*
  Create the names of:
    the quadrature X file;
    the quadrature W file;
    the quadrature R file;
*/
  strcpy ( quad_w_filename, quad_filename );
  strcat ( quad_w_filename, "_w.txt" );
  strcpy ( quad_x_filename, quad_filename );
  strcat ( quad_x_filename, "_x.txt" );
  strcpy ( quad_r_filename, quad_filename );
  strcat ( quad_r_filename, "_r.txt" );
/*
  Get the maximum degree:
*/
  if ( 2 < argc )
  {
    degree_max = atoi ( argv[2] );

  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter DEGREE_MAX, the maximum monomial degree to check.\n" );
    scanf ( "%d", &degree_max );
  }
  printf ( "\n" );
  printf ( "  The requested maximum monomial degree is = %d\n", degree_max );
/*
  The third command line argument is OPTION.
*/
  if ( 3 < argc )
  {
    option = atoi ( argv[3] );
  }
  else
  {
    printf ( "\n" );
    printf ( "HERMITE_EXACTNESS:\n" );
    printf ( "  OPTION specifies the weight function rho(x):\n" );
    printf ( "\n" );
    printf ( "  0, rho(x) = 1\n" );
    printf ( "  1, rho(x) = exp ( -x*x  )\n" );
    printf ( "  2, rho(x) = exp ( -x*x/2)\n" );
    printf ( "  3, rho(x) = exp ( -x*x  ) / sqrt( pi)\n" );
    printf ( "  4, rho(x) = exp ( -x*x/2) / sqrt(2pi)\n" );
    printf ( "\n" );
    printf ( "  Please enter OPTION:\n" );
    scanf ( "%d", &option );
  }

  if ( option < 0 || 4 < option )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "HERMITE_EXACTNESS - Fatal error!\n" );
    fprintf ( stderr, "  Illegal value of OPTION.\n" );
    exit ( 1 );
  }
/*
  Summarize the input.
*/
  printf ( "\n" );
  printf ( "HERMITE_EXACTNESS: User input:\n" );
  printf ( "  Quadrature rule X file = \"%s\".\n", quad_x_filename );
  printf ( "  Quadrature rule W file = \"%s\".\n", quad_w_filename );
  printf ( "  Quadrature rule R file = \"%s\".\n", quad_r_filename );
  printf ( "  Maximum degree to check = %d\n", degree_max );
/*
  Read the X file.
*/
  r8mat_header_read ( quad_x_filename, &dim_num, &order );

  if ( dim_num != 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "HERMITE_EXACTNESS - Fatal error!\n" );
    fprintf ( stderr, "  The spatial dimension of X should be 1.\n" );
    fprintf ( stderr, " The implicit input dimension was DIM_NUM = %d\n", dim_num );
    exit ( 1 );
  }

  printf ( "\n" );
  printf ( "  Spatial dimension = %d\n", dim_num );
  printf ( "  Number of points  = %d\n", order );

  x = r8mat_data_read ( quad_x_filename, dim_num, order );
/*
  Read the W file.
*/
  r8mat_header_read ( quad_w_filename, &dim_num2, &point_num );

  if ( dim_num2 != 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "HERMITE_EXACTNESS - Fatal error!\n" );
    fprintf ( stderr, "  The quadrature weight file should have exactly\n" );
    fprintf ( stderr, "  one value on each line.\n" );
    exit ( 1 );
  }

  if ( point_num != order )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "HERMITE_EXACTNESS - Fatal error!\n" );
    fprintf ( stderr, "  The quadrature weight file should have exactly\n" );
    fprintf ( stderr, "  the same number of lines as the abscissa file.\n" );
    exit ( 1 );
  }

  w = r8mat_data_read ( quad_w_filename, dim_num, order );
/*
  Read the R file.
*/
  r8mat_header_read ( quad_r_filename, &dim_num2, &point_num2 );

  if ( dim_num2 != dim_num )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "HERMITE_EXACTNESS - Fatal error!\n" );
    fprintf ( stderr, "  The quadrature region file should have the\n" );
    fprintf ( stderr, "  same number of values on each line as the\n" );
    fprintf ( stderr, "  abscissa file does.\n" );
    exit ( 1 );
  }

  if ( point_num2 != 2 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "HERMITE_EXACTNESS - Fatal error!\n" );
    fprintf ( stderr, "  The quadrature region file should have two lines.\n" );
    exit ( 1 );
  }

  r = r8mat_data_read ( quad_r_filename, dim_num, point_num2 );
/*
  Print the input quadrature rule.
*/
  printf ( "\n" );
  printf ( "  The quadrature rule to be tested is\n" );
  printf ( "  a Gauss-Hermite rule\n" );
  printf ( "  ORDER = %d\n", order );
  printf ( "\n" );
  if ( option == 0 )
  {
    printf ( "  OPTION = 0, the unweighted rule for:\n" );
    printf ( "  Integral ( -oo < x < +oo ) f(x) dx\n" );
  }
  else if ( option == 1 )
  {
    printf ( "  OPTION = 1, the physicist weighted rule for:\n" );
    printf ( "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x) dx\n" );
  }
  else if ( option == 2 )
  {
    printf ( "  OPTION = 2, the probabilist weighted rule for:\n" );
    printf ( "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x/2) dx\n" );
  }
  else if ( option == 3 )
  {
    printf ( "  OPTION = 3, the physicist normalized weighted rule for:\n" );
    printf ( "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x) / sqrt(pi) dx\n" );
  }
  else if ( option == 4 )
  {
    printf ( "  OPTION = 4, the probabilist normalized weighted rule for:\n" );
    printf ( "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x/2) / sqrt(2 pi) dx\n" );
  }
  printf ( "\n" );
  printf ( "  Weights W:\n" );
  printf ( "\n" );
  for ( i = 0; i < order; i++ )
  {
    printf ( "  w[%d] = %g\n", i, w[i] );
  }
  printf ( "\n" );
  printf ( "  Abscissas X:\n" );
  printf ( "\n" );
  for ( i = 0; i < order; i++ )
  {
    printf ( "  x[%d] = %g\n", i, x[i] );
  }
  printf ( "\n" );
  printf ( "  Region R:\n" );
  printf ( "\n" );

  for ( i = 0; i < 2; i++ )
  {
    printf ( "  r[%d] = %g\n", i, r[i] );
  }
//
//  Explore the monomials.
//
  printf ( "\n" );
  printf ( "  A Gauss-Hermite rule would be able to exactly\n" );
  printf ( "  integrate monomials up to and including degree = %d\n",
   2 * order - 1 );
  printf ( "\n" );
  printf ( "  Degree          Error\n" );
  printf ( "\n" );

  for ( degree = 0; degree <= degree_max; degree++ )
  {
    quad_error = hermite_monomial_quadrature ( degree, order, option, w, x );

    printf ( "  %2d  %24.16g\n", degree, quad_error );
  }
//
//  Free memory.
//
  free ( w );
  free ( x );
  free ( r );
//
//  Terminate.
//
  printf ( "\n" );
  printf ( "HERMITE_EXACTNESS:\n" );
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

double hermite_integral ( int n, int option )

/******************************************************************************/
/*
  Purpose:

    HERMITE_INTEGRAL evaluates a monomial Hermite integral.

  Discussion:

    H(n,1) = Integral ( -oo < x < oo ) x^n exp(-x^2) dx
    H(n,1) is 0 for n odd.
    H(n,1) = (n-1)!! * sqrt(pi) / 2^(n/2) for n even.

    H(n,2) = Integral ( -oo < x < +oo ) x^n exp(-x^2/2) dx
    H(n,2) is 0 for n odd.
    H(n,2) = (n-1)!! * sqrt(2*pi) for n even.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 June 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the integral.  
    0 <= N.

    Input, int OPTION, the integral has the form:
    0, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
    1, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
    2, Integral ( -oo < x < +oo ) x^n exp(-x*x/2)             dx.
    3, Integral ( -oo < x < +oo ) x^n exp(-x*x)   / sqrt (pi) dx.
    4, Integral ( -oo < x < +oo ) x^n exp(-x*x/2) / sqrt(2pi) dx.

    Output, double HERMITE_INTEGRAL, the value of the integral.
*/
{
  const double r8_huge = 1.0E+10;
  const double r8_pi = 3.141592653589793;
  double value;

  if ( n < 0 )
  {
    value = - r8_huge;
  }
  else if ( ( n % 2 ) == 1 )
  {
    value = 0.0;
  }
  else if ( option == 0 )
  {
    value = r8_factorial2 ( n - 1 ) * sqrt ( r8_pi ) / pow ( 2.0, n / 2 );
  }
  else if ( option == 1 )
  {
    value = r8_factorial2 ( n - 1 ) * sqrt ( r8_pi ) / pow ( 2.0, n / 2 );
  }
  else if ( option == 2 )
  {
    value = r8_factorial2 ( n - 1 ) * sqrt ( 2.0 * r8_pi );
  }
  else if ( option == 3 )
  {
    value = r8_factorial2 ( n - 1 ) / pow ( 2.0, n / 2 );
  }
  else if ( option == 4 )
  {
    value = r8_factorial2 ( n - 1 );
  }
  return value;
}
/******************************************************************************/

double hermite_monomial_quadrature ( int expon, int order, int option,
  double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    HERMITE_MONOMIAL_QUADRATURE applies a quadrature rule to a monomial.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 June 2013

  Author:

    John Burkardt

  Parameters:

    Input, int EXPON, the exponent.

    Input, int ORDER, the number of points in the rule.

    Input, int OPTION, the integral has the form:
    0, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
    1, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
    2, Integral ( -oo < x < +oo ) x^n exp(-x*x/2)             dx.
    3, Integral ( -oo < x < +oo ) x^n exp(-x*x)   / sqrt (pi) dx.
    4, Integral ( -oo < x < +oo ) x^n exp(-x*x/2) / sqrt(2pi) dx.

    Input, double W[ORDER], the quadrature weights.

    Input, double X[ORDER], the quadrature points.

    Output, double HERMITE_MONOMIAL_QUADRATURE, the quadrature error.
*/
{
  double exact;
  int i;
  double quad;
  double quad_error;
//
//  Get the exact value of the integral of the unscaled monomial.
//
  exact = hermite_integral ( expon, option );
//
//  Evaluate the unweighted monomial at the quadrature points.
//
  quad = 0.0;
  if ( option == 0 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * exp ( - x[i] * x[i] ) * pow ( x[i], expon );
    }
  }
  else if ( option == 1 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
  else if ( option == 2 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
  else if ( option == 3 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
  else if ( option == 4 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
/*
  Absolute error for cases where exact integral is zero,
  Relative error otherwise.
*/
  if ( exact == 0.0 )
  {
    quad_error = fabs ( quad );
  }
  else
  {
    quad_error = fabs ( quad - exact ) / fabs ( exact );
  }
  return quad_error;
}
/******************************************************************************/

double r8_factorial2 ( int n )

/******************************************************************************/
/*
  Purpose:

    R8_FACTORIAL2 computes the double factorial function.

  Discussion:

    FACTORIAL2( N ) = Product ( N * (N-2) * (N-4) * ... * 2 )  (N even)
                    = Product ( N * (N-2) * (N-4) * ... * 1 )  (N odd)

     N Value
    -- -----
     0     1
     1     1
     2     2
     3     3
     4     8
     5    15
     6    48
     7   105
     8   384
     9   945
    10  3840

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the argument of the double factorial
    function.  If N is less than 1, R8_FACTORIAL2 is returned as 1.0.

    Output, double R8_FACTORIAL2, the value of Factorial2(N).
*/
{
  int n_copy;
  double value;

  value = 1.0;

  if ( n < 1 )
  {
    return value;
  }

  n_copy = n;

  while ( 1 < n_copy )
  {
    value = value * ( double ) n_copy;
    n_copy = n_copy - 2;
  }

  return value;
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

int s_len_trim ( char *s )

/******************************************************************************/
/*
  Purpose:

    S_LEN_TRIM returns the length of a string to the last nonblank.

  Discussion:

    It turns out that I also want to ignore the '\n' character!

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 October 2014

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
    if ( *t != ' ' && *t != '\n' )
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
