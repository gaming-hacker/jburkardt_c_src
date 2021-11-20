# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>

int main ( int argc, char *argv[] );
void clenshaw_curtis_ab ( int n, double a, double b, double x[], 
  double w[] );
void clenshaw_curtis_m1p1 ( int n, double xtab[], double weight[] );
void r8mat_write ( char *output_filename, int m, int n, double table[] );
void rule_write ( int n, char *filename, double x[], double w[],
  double r[] );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CLENSHAW_CURTIS_RULE.

  Discussion:

    This program computes a standard Clenshaw Curtis quadrature rule
    and writes it to a file.

    The user specifies:
    * n (number of points) in the rule;
    * A, the left endpoint;
    * B, the right endpoint;
    * FILENAME, which defines the output filenames.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 October 2019

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  char filename[255];
  int n;
  double *r;
  double *w;
  double *x;

  timestamp ( );
  printf ( "\n" );
  printf ( "CLENSHAW_CURTIS_RULE\n" );
  printf ( "  C version\n" );
  printf ( "\n" );
  printf ( "  Compute a Clenshaw Curtis rule for approximating\n" );
  printf ( "    Integral ( -1 <= x <= +1 ) f(x) dx\n" );
  printf ( "  of n n.\n" );
  printf ( "\n" );
  printf ( "  The user specifies n, A, B and FILENAME.\n" );
  printf ( "\n" );
  printf ( "  n is the number of points.\n" );
  printf ( "  A is the left endpoint.\n" );
  printf ( "  B is the right endpoint.\n" );
  printf ( "  FILENAME is used to generate 3 files:\n" );
  printf ( "    filename_w.txt - the weight file\n" );
  printf ( "    filename_x.txt - the abscissa file.\n" );
  printf ( "    filename_r.txt - the region file.\n" );
/*
  Get n.
*/
  if ( 1 < argc )
  {
    n = atoi ( argv[1] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter the value of n (1 or greater)\n" );
    scanf ( "%d", &n );
  }
/*
  Get A.
*/
  if ( 2 < argc )
  {
    a = atof ( argv[2] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter the left endpoint A:\n" );
    scanf ( "%lf", &a );
  }
/*
  Get B.
*/
  if ( 3 < argc )
  {
    b = atof ( argv[3] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter the right endpoint B:\n" );
    scanf ( "%lf", &b );
  }
/*
  Get FILENAME:
*/
  if ( 4 < argc )
  {
    strcpy ( filename, argv[4] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter FILENAME, the \"root name\" of the quadrature files).\n" );
    scanf ( "%s", filename );
  }
/*
  Input summary.
*/
  printf ( "\n" );
  printf ( "  n = %d\n", n );
  printf ( "  A = %g\n", a );
  printf ( "  B = %g\n", b );
  printf ( "  FILENAME = \"%s\".\n", filename );
/*
  Construct the rule.
*/
  r = ( double * ) malloc ( 2 * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  r[0] = a;
  r[1] = b;

  clenshaw_curtis_ab ( n, a, b, x, w );
/*
  Output the rule.
*/
  rule_write ( n, filename, x, w, r );
/*
  Free memory.
*/
  free ( r );
  free ( w );
  free ( x );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CLENSHAW_CURTIS_RULE:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void clenshaw_curtis_ab ( int n, double a, double b, double x[], double w[] )

/******************************************************************************/
/*
  Purpose:

    clenshaw_curtis_ab computes a Clenshaw Curtis quadrature rule for [a,b].

  Discussion:

    The integration interval is [ a, b ].

    The weight function is w(x) = 1.0.

    The integral to approximate:

      Integral ( a <= X <= b ) F(X) dX

    The quadrature rule:

      Sum ( 1 <= I <= n ) W(I) * F ( X(I) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 October 2012

  Author:

    John Burkardt

  Parameters:

    Input, int n, the order of the rule.
    1 <= n.

    Output, double X[n], the abscissas.

    Output, double W[n], the weights.
*/
{
  int i;

  clenshaw_curtis_m1p1 ( n, x, w );

  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( a + b ) + ( b - a ) * x[i] ) / 2.0;
  }
  for ( i = 0; i < n; i++ )
  {
    w[i] = ( b - a ) * w[i] / 2.0;
  }

  return;
}
/******************************************************************************/

void clenshaw_curtis_m1p1 ( int n, double x[], double w[] )

/******************************************************************************/
/*
  Purpose:

    clenshaw_curtis_m1p1 computes a Clenshaw Curtis quadrature rule for [-1,+1].

  Discussion:

    The integration interval is [ -1, 1 ].

    The weight function is w(x) = 1.0.

    The integral to approximate:

      Integral ( -1 <= X <= 1 ) F(X) dX

    The quadrature rule:

      Sum ( 1 <= I <= n ) W(I) * F ( X(I) )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 October 2012

  Author:

    John Burkardt

  Parameters:

    Input, int n, the order of the rule.  1 <= n.

    Output, double X[n], the abscissas.

    Output, double W[n], the weights.
*/
{
  double b;
  int i;
  int j;
  double pi = 3.141592653589793;
  double theta;

  if ( n < 1 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "clenshaw_curtis_m1p1 - Fatal error!\n" );
    fprintf ( stderr, "  Illegal value of n = %d\n", n );
    exit ( 1 );
  }
  else if ( n == 1 )
  {
    x[0] = 0.0;
    w[0] = 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] =  cos ( ( double ) ( n - 1 - i ) * pi
                  / ( double ) ( n - 1     ) );
    }
    x[0] = -1.0;
    if ( ( n % 2 ) == 1 )
    {
      x[(n-1)/2] = 0.0;
    }
    x[n-1] = +1.0;

    for ( i = 0; i < n; i++ )
    {
      theta = ( double ) ( i ) * pi / ( double ) ( n - 1 );

      w[i] = 1.0;

      for ( j = 1; j <= ( n - 1 ) / 2; j++ )
      {
        if ( 2 * j == ( n - 1 ) )
        {
          b = 1.0;
        }
        else
        {
          b = 2.0;
        }

        w[i] = w[i] - b * cos ( 2.0 * ( double ) ( j ) * theta )
          / ( double ) ( 4 * j * j - 1 );
      }
    }

    w[0] = w[0] / ( double ) ( n - 1 );
    for ( i = 1; i < n - 1; i++ )
    {
      w[i] = 2.0 * w[i] / ( double ) ( n - 1 );
    }
    w[n-1] = w[n-1] / ( double ) ( n - 1 );
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

void rule_write ( int n, char *filename, double x[], double w[],
  double r[] )

/******************************************************************************/
/*
  Purpose:

    RULE_WRITE writes a quadrature rule to three files.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 October 2012

  Author:

    John Burkardt

  Parameters:

    Input, int n, the order of the rule.

    Input, double A, the left endpoint.

    Input, double B, the right endpoint.

    Input, char *FILENAME, specifies the output filenames.
    "filename_w.txt", "filename_x.txt", "filename_r.txt"
    defining weights, abscissas, and region.
*/
{
  char filename_r[80];
  char filename_w[80];
  char filename_x[80];

  strcpy ( filename_r, filename );
  strcat ( filename_r, "_r.txt" );
  strcpy ( filename_w, filename );
  strcat ( filename_w, "_w.txt" );
  strcpy ( filename_x, filename );
  strcat ( filename_x, "_x.txt" );

  printf ( "\n" );
  printf ( "  Creating quadrature files.\n" );
  printf ( "\n" );
  printf ( "  Root file name is     \"%s\".\n", filename );
  printf ( "\n" );
  printf ( "  Weight file will be   \"%s\".\n", filename_w );
  printf ( "  Abscissa file will be \"%s\".\n", filename_x );
  printf ( "  Region file will be   \"%s\".\n", filename_r );

  r8mat_write ( filename_w, 1, n, w );
  r8mat_write ( filename_x, 1, n, x );
  r8mat_write ( filename_r, 1, 2, r );

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

