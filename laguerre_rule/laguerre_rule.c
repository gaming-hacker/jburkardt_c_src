# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <string.h>

int main ( int argc, char *argv[] );
void cdgqf ( int nt, int kind, double alpha, double beta, double t[], 
  double wts[] );
void cgqf ( int nt, int kind, double alpha, double beta, double a, double b, 
  double t[], double wts[] );
double class_matrix ( int kind, int m, double alpha, double beta, double aj[], 
  double bj[] );
void imtqlx ( int n, double d[], double e[], double z[] );
void parchk ( int kind, int m, double alpha, double beta );
double r8_abs ( double x );
double r8_epsilon ( );
double r8_huge ( );
double r8_sign ( double x );
void r8mat_write ( char *output_filename, int m, int n, double table[] );
void rule_write ( int order, char *filename, double x[], double w[], 
  double r[] );
void scqf ( int nt, double t[], int mlt[], double wts[], int nwts, int ndx[], 
  double swts[], double st[], int kind, double alpha, double beta, double a, 
  double b );
void sgqf ( int nt, double aj[], double bj[], double zemu, double t[], 
  double wts[] );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LAGUERRE_RULE.

  Discussion:

    This program computes a standard or exponentially weighted 
    Gauss-Laguerre quadrature rule and writes it to a file.

    The user specifies:
    * the N (number of points) in the rule;
    * A, the left endpoint;
    * B, the scale factor;
    * FILENAME, the root name of the output files.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 May 2014

  Author:

    John Burkardt
*/
{
  double a;
  double alpha;
  double b;
  double beta;
  char filename[255];
  int kind;
  int n;
  double *r;
  double *w;
  double *x;

  timestamp ( );
  printf ( "\n" );
  printf ( "LAGUERRE_RULE\n" );
  printf ( "  C version\n" );
  printf ( "\n" );
  printf ( "  Compute a Gauss-Laguerre quadrature rule for\n" );
  printf ( "    Integral ( A <= x < +oo ) exp(-b*(x-a)) f(x) dx\n" );
  printf ( "  of order N.\n" );
  printf ( "\n" );
  printf ( "  The user specifies N, A, B, and FILENAME.\n" );
  printf ( "\n" );
  printf ( "  N is the number of points;\n" );
  printf ( "  A is the left endpoint, usually 0.0:\n" );
  printf ( "  B is a scale factor, usually 1.0;\n" );
  printf ( "  FILENAME is used to generate 3 files:\n" );
  printf ( "  * filename_w.txt - the weight file\n" );
  printf ( "  * filename_x.txt - the abscissa file.\n" );
  printf ( "  * filename_r.txt - the region file.\n" );
/*
  Initialize parameters;
*/
  alpha = 0.0;
  beta = 0.0;
/*
  Get N.
*/
  if ( 1 < argc )
  {
    n = atoi ( argv[1] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter N (1 or greater)\n" );
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
    printf ( "  Enter A, the left point (default 0)\n" );
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
    printf ( "  Enter B, the scale (default 1)\n" );
    scanf ( "%lf", &b );
  }
/*
  Get FILENAME:
*/
  if ( 4 < argc )
  {
    strcpy ( filename, argv[5] );
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
  printf ( "  N = %d\n", n );
  printf ( "  A = %g\n", a );
  printf ( "  B = %g\n", b );
  printf ( "  FILENAME = \"%s\"\n", filename );
/*
  Construct the rule.
*/
  w = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  
  kind = 5;
  cgqf ( n, kind, alpha, beta, a, b, x, w );
/*
  Set the R values.
*/
  r = ( double * ) malloc ( 2 * sizeof ( double ) );
  r[0] = a;
  r[1] = r8_huge ( );
/*
  Write the rule to a file.
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
  printf ( "LAGUERRE_RULE:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void cdgqf ( int nt, int kind, double alpha, double beta, double t[], 
  double wts[] )

/******************************************************************************/
/*
  Purpose:

    CDGQF computes a Gauss quadrature formula with default A, B and simple knots.

  Discussion:

    This routine computes all the knots and weights of a Gauss quadrature
    formula with a classical weight function with default values for A and B,
    and only simple knots.

    There are no moments checks and no printing is done.

    Use routine EIQFS to evaluate a quadrature computed by CGQFS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int NT, the number of knots.

    Input, int KIND, the rule.
    1, Legendre,             (a,b)       1.0
    2, Chebyshev Type 1,     (a,b)       ((b-x)*(x-a))^(-0.5)
    3, Gegenbauer,           (a,b)       ((b-x)*(x-a))^alpha
    4, Jacobi,               (a,b)       (b-x)^alpha*(x-a)^beta
    5, Generalized Laguerre, (a,inf)     (x-a)^alpha*exp(-b*(x-a))
    6, Generalized Hermite,  (-inf,inf)  |x-a|^alpha*exp(-b*(x-a)^2)
    7, Exponential,          (a,b)       |x-(a+b)/2.0|^alpha
    8, Rational,             (a,inf)     (x-a)^alpha*(x+b)^beta

    Input, double ALPHA, the value of Alpha, if needed.

    Input, double BETA, the value of Beta, if needed.

    Output, double T[NT], the knots.

    Output, double WTS[NT], the weights.
*/
{
  double *aj;
  double *bj;
  double zemu;

  parchk ( kind, 2 * nt, alpha, beta );
/*
  Get the Jacobi matrix and zero-th moment.
*/
  aj = ( double * ) malloc ( nt * sizeof ( double ) );
  bj = ( double * ) malloc ( nt * sizeof ( double ) );

  zemu = class_matrix ( kind, nt, alpha, beta, aj, bj );
/*
  Compute the knots and weights.
*/
  sgqf ( nt, aj, bj, zemu, t, wts );

  free ( aj );
  free ( bj );

  return;
}
/******************************************************************************/

void cgqf ( int nt, int kind, double alpha, double beta, double a, double b, 
  double t[], double wts[] )

/******************************************************************************/
/*
  Purpose:

    CGQF computes knots and weights of a Gauss quadrature formula.

  Discussion:

    The user may specify the interval (A,B).

    Only simple knots are produced.

    The user may request that the routine print the knots and weights,
    and perform a moment check.

    Use routine EIQFS to evaluate this quadrature formula.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 September 2013

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int NT, the number of knots.

    Input, int KIND, the rule.
    1, Legendre,             (a,b)       1.0
    2, Chebyshev Type 1,     (a,b)       ((b-x)*(x-a))^-0.5)
    3, Gegenbauer,           (a,b)       ((b-x)*(x-a))^alpha
    4, Jacobi,               (a,b)       (b-x)^alpha*(x-a)^beta
    5, Generalized Laguerre, (a,inf)     (x-a)^alpha*exp(-b*(x-a))
    6, Generalized Hermite,  (-inf,inf)  |x-a|^alpha*exp(-b*(x-a)^2)
    7, Exponential,          (a,b)       |x-(a+b)/2.0|^alpha
    8, Rational,             (a,inf)     (x-a)^alpha*(x+b)^beta

    Input, double ALPHA, the value of Alpha, if needed.

    Input, double BETA, the value of Beta, if needed.

    Input, double A, B, the interval endpoints.

    Output, double T[NT], the knots.

    Output, double WTS[NT], the weights.
*/
{
  int i;
  int *mlt;
  int *ndx;
/*
  Compute the Gauss quadrature formula for default values of A and B.
*/
  cdgqf ( nt, kind, alpha, beta, t, wts );
/*
  Prepare to scale the quadrature formula to other weight function with 
  valid A and B.
*/
  mlt = ( int * ) malloc ( nt * sizeof ( int ) );
  for ( i = 0; i < nt; i++ )
  {
    mlt[i] = 1;
  }
  ndx = ( int * ) malloc ( nt * sizeof ( int ) );
  for ( i = 0; i < nt; i++ )
  {
    ndx[i] = i + 1;
  }
  scqf ( nt, t, mlt, wts, nt, ndx, wts, t, kind, alpha, beta, a, b );

  free ( mlt );
  free ( ndx );

  return;
}
/******************************************************************************/

double class_matrix ( int kind, int m, double alpha, double beta, double aj[], 
  double bj[] )

/******************************************************************************/
/*
  Purpose:

    CLASS_MATRIX computes the Jacobi matrix for a quadrature rule.

  Discussion:

    This routine computes the diagonal AJ and sub-diagonal BJ
    elements of the order M tridiagonal symmetric Jacobi matrix
    associated with the polynomials orthogonal with respect to
    the weight function specified by KIND.

    For weight functions 1-7, M elements are defined in BJ even
    though only M-1 are needed.  For weight function 8, BJ(M) is
    set to zero.

    The zero-th moment of the weight function is returned in ZEMU.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int KIND, the rule.
    1, Legendre,             (a,b)       1.0
    2, Chebyshev Type 1,     (a,b)       ((b-x)*(x-a))^(-0.5)
    3, Gegenbauer,           (a,b)       ((b-x)*(x-a))^alpha
    4, Jacobi,               (a,b)       (b-x)^alpha*(x-a)^beta
    5, Generalized Laguerre, (a,inf)     (x-a)^alpha*exp(-b*(x-a))
    6, Generalized Hermite,  (-inf,inf)  |x-a|^alpha*exp(-b*(x-a)^2)
    7, Exponential,          (a,b)       |x-(a+b)/2.0|^alpha
    8, Rational,             (a,inf)     (x-a)^alpha*(x+b)^beta

    Input, int M, the order of the Jacobi matrix.

    Input, double ALPHA, the value of Alpha, if needed.

    Input, double BETA, the value of Beta, if needed.

    Output, double AJ[M], BJ[M], the diagonal and subdiagonal
    of the Jacobi matrix.

    Output, double CLASS_MATRIX, the zero-th moment.
*/
{
  double a2b2;
  double ab;
  double aba;
  double abi;
  double abj;
  double abti;
  double apone;
  int i;
  const double pi = 3.14159265358979323846264338327950;
  double temp;
  double temp2;
  double zemu;

  temp = r8_epsilon ( );

  parchk ( kind, 2 * m - 1, alpha, beta );

  temp2 = 0.5;

  if ( 500.0 * temp < r8_abs ( pow ( tgamma ( temp2 ), 2 ) - pi ) )
  {
    printf ( "\n" );
    printf ( "CLASS_MATRIX - Fatal error!\n" );
    printf ( "  Gamma function does not match machine parameters.\n" );
    exit ( 1 );
  }

  if ( kind == 1 )
  {
    ab = 0.0;

    zemu = 2.0 / ( ab + 1.0 );

    for ( i = 0; i < m; i++ )
    {
      aj[i] = 0.0;
    }

    for ( i = 1; i <= m; i++ )
    {
      abi = i + ab * ( i % 2 );
      abj = 2 * i + ab;
      bj[i-1] = sqrt ( abi * abi / ( abj * abj - 1.0 ) );
    }
  }
  else if ( kind == 2 )
  {
    zemu = pi;

    for ( i = 0; i < m; i++ )
    {
      aj[i] = 0.0;
    }

    bj[0] =  sqrt ( 0.5 );
    for ( i = 1; i < m; i++ )
    {
      bj[i] = 0.5;
    }
  }
  else if ( kind == 3 )
  {
    ab = alpha * 2.0;
    zemu = pow ( 2.0, ab + 1.0 ) * pow ( tgamma ( alpha + 1.0 ), 2 )
      / tgamma ( ab + 2.0 );

    for ( i = 0; i < m; i++ )
    {
      aj[i] = 0.0;
    }

    bj[0] = sqrt ( 1.0 / ( 2.0 * alpha + 3.0 ) );
    for ( i = 2; i <= m; i++ )
    {
      bj[i-1] = sqrt ( i * ( i + ab ) / ( 4.0 * pow ( i + alpha, 2 ) - 1.0 ) );
    }
  }
  else if ( kind == 4 )
  {
    ab = alpha + beta;
    abi = 2.0 + ab;
    zemu = pow ( 2.0, ab + 1.0 ) * tgamma ( alpha + 1.0 ) 
      * tgamma ( beta + 1.0 ) / tgamma ( abi );
    aj[0] = ( beta - alpha ) / abi;
    bj[0] = sqrt ( 4.0 * ( 1.0 + alpha ) * ( 1.0 + beta ) 
      / ( ( abi + 1.0 ) * abi * abi ) );
    a2b2 = beta * beta - alpha * alpha;

    for ( i = 2; i <= m; i++ )
    {
      abi = 2.0 * i + ab;
      aj[i-1] = a2b2 / ( ( abi - 2.0 ) * abi );
      abi = abi * abi;
      bj[i-1] = sqrt ( 4.0 * i * ( i + alpha ) * ( i + beta ) * ( i + ab ) 
        / ( ( abi - 1.0 ) * abi ) );
    }
  }
  else if ( kind == 5 )
  {
    zemu = tgamma ( alpha + 1.0 );

    for ( i = 1; i <= m; i++ )
    {
      aj[i-1] = 2.0 * i - 1.0 + alpha;
      bj[i-1] = sqrt ( i * ( i + alpha ) );
    }
  }
  else if ( kind == 6 )
  {
    zemu = tgamma ( ( alpha + 1.0 ) / 2.0 );

    for ( i = 0; i < m; i++ )
    {
      aj[i] = 0.0;
    }

    for ( i = 1; i <= m; i++ )
    {
      bj[i-1] = sqrt ( ( i + alpha * ( i % 2 ) ) / 2.0 );
    }
  }
  else if ( kind == 7 )
  {
    ab = alpha;
    zemu = 2.0 / ( ab + 1.0 );

    for ( i = 0; i < m; i++ )
    {
      aj[i] = 0.0;
    }

    for ( i = 1; i <= m; i++ )
    {
      abi = i + ab * ( i % 2 );
      abj = 2 * i + ab;
      bj[i-1] = sqrt ( abi * abi / ( abj * abj - 1.0 ) );
    }
  }
  else if ( kind == 8 )
  {
    ab = alpha + beta;
    zemu = tgamma ( alpha + 1.0 ) * tgamma ( - ( ab + 1.0 ) ) 
      / tgamma ( - beta );
    apone = alpha + 1.0;
    aba = ab * apone;
    aj[0] = - apone / ( ab + 2.0 );
    bj[0] = - aj[0] * ( beta + 1.0 ) / ( ab + 2.0 ) / ( ab + 3.0 );
    for ( i = 2; i <= m; i++ )
    {
      abti = ab + 2.0 * i;
      aj[i-1] = aba + 2.0 * ( ab + i ) * ( i - 1 );
      aj[i-1] = - aj[i-1] / abti / ( abti - 2.0 );
    }

    for ( i = 2; i <= m - 1; i++ )
    {
      abti = ab + 2.0 * i;
      bj[i-1] = i * ( alpha + i ) / ( abti - 1.0 ) * ( beta + i ) 
        / ( abti * abti ) * ( ab + i ) / ( abti + 1.0 );
    }
    bj[m-1] = 0.0;
    for ( i = 0; i < m; i++ )
    {
      bj[i] =  sqrt ( bj[i] );
    }
  }
  else
  {
    printf ( "\n" );
    printf ( "CLASS_MATRIX - Fatal error!\n" );
    printf ( "  Illegal value of KIND = %d.\n", kind );
    exit ( 1 );
  }

  return zemu;
}
/******************************************************************************/

void imtqlx ( int n, double d[], double e[], double z[] )

/******************************************************************************/
/*
  Purpose:

    IMTQLX diagonalizes a symmetric tridiagonal matrix.

  Discussion:

    This routine is a slightly modified version of the EISPACK routine to 
    perform the implicit QL algorithm on a symmetric tridiagonal matrix. 

    The authors thank the authors of EISPACK for permission to use this
    routine. 

    It has been modified to produce the product Q' * Z, where Z is an input 
    vector and Q is the orthogonal matrix diagonalizing the input matrix.  
    The changes consist (essentially) of applying the orthogonal transformations
    directly to Z as they are generated.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

    Roger Martin, James Wilkinson,
    The Implicit QL Algorithm,
    Numerische Mathematik,
    Volume 12, Number 5, December 1968, pages 377-383.

  Parameters:

    Input, int N, the order of the matrix.

    Input/output, double D(N), the diagonal entries of the matrix.
    On output, the information in D has been overwritten.

    Input/output, double E(N), the subdiagonal entries of the 
    matrix, in entries E(1) through E(N-1).  On output, the information in
    E has been overwritten.

    Input/output, double Z(N).  On input, a vector.  On output,
    the value of Q' * Z, where Q is the matrix that diagonalizes the
    input symmetric tridiagonal matrix.
*/
{
  double b;
  double c;
  double f;
  double g;
  int i;
  int ii;
  int itn = 30;
  int j;
  int k;
  int l;
  int m;
  int mml;
  double p;
  double prec;
  double r;
  double s;

  prec = r8_epsilon ( );

  if ( n == 1 )
  {
    return;
  }

  e[n-1] = 0.0;

  for ( l = 1; l <= n; l++ )
  {
    j = 0;
    for ( ; ; )
    {
      for ( m = l; m <= n; m++ )
      {
        if ( m == n )
        {
          break;
        }

        if ( r8_abs ( e[m-1] ) <= prec * ( r8_abs ( d[m-1] ) + r8_abs ( d[m] ) ) )
        {
          break;
        }
      }
      p = d[l-1];
      if ( m == l )
      {
        break;
      }
      if ( itn <= j )
      {
        printf ( "\n" );
        printf ( "IMTQLX - Fatal error!\n" );
        printf ( "  Iteration limit exceeded\n" );
        exit ( 1 );
      }
      j = j + 1;
      g = ( d[l] - p ) / ( 2.0 * e[l-1] );
      r =  sqrt ( g * g + 1.0 );
      g = d[m-1] - p + e[l-1] / ( g + r8_abs ( r ) * r8_sign ( g ) );
      s = 1.0;
      c = 1.0;
      p = 0.0;
      mml = m - l;

      for ( ii = 1; ii <= mml; ii++ )
      {
        i = m - ii;
        f = s * e[i-1];
        b = c * e[i-1];

        if ( r8_abs ( g ) <= r8_abs ( f ) )
        {
          c = g / f;
          r =  sqrt ( c * c + 1.0 );
          e[i] = f * r;
          s = 1.0 / r;
          c = c * s;
        }
        else
        {
          s = f / g;
          r =  sqrt ( s * s + 1.0 );
          e[i] = g * r;
          c = 1.0 / r;
          s = s * c;
        }
        g = d[i] - p;
        r = ( d[i-1] - g ) * s + 2.0 * c * b;
        p = s * r;
        d[i] = g + p;
        g = c * r - b;
        f = z[i];
        z[i] = s * z[i-1] + c * f;
        z[i-1] = c * z[i-1] - s * f;
      }
      d[l-1] = d[l-1] - p;
      e[l-1] = g;
      e[m-1] = 0.0;
    }
  }
/*
  Sorting.
*/
  for ( ii = 2; ii <= m; ii++ )
  {
    i = ii - 1;
    k = i;
    p = d[i-1];

    for ( j = ii; j <= n; j++ )
    {
      if ( d[j-1] < p )
      {
         k = j;
         p = d[j-1];
      }
    }

    if ( k != i )
    {
      d[k-1] = d[i-1];
      d[i-1] = p;
      p = z[i-1];
      z[i-1] = z[k-1];
      z[k-1] = p;
    }
  }
  return;
}
/******************************************************************************/

void parchk ( int kind, int m, double alpha, double beta )

/******************************************************************************/
/*
  Purpose:

    PARCHK checks parameters ALPHA and BETA for classical weight functions. 

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int KIND, the rule.
    1, Legendre,             (a,b)       1.0
    2, Chebyshev Type 1,     (a,b)       ((b-x)*(x-a))^(-0.5)
    3, Gegenbauer,           (a,b)       ((b-x)*(x-a))^alpha
    4, Jacobi,               (a,b)       (b-x)^alpha*(x-a)^beta
    5, Generalized Laguerre, (a,inf)     (x-a)^alpha*exp(-b*(x-a))
    6, Generalized Hermite,  (-inf,inf)  |x-a|^alpha*exp(-b*(x-a)^2)
    7, Exponential,          (a,b)       |x-(a+b)/2.0|^alpha
    8, Rational,             (a,inf)     (x-a)^alpha*(x+b)^beta

    Input, int M, the order of the highest moment to
    be calculated.  This value is only needed when KIND = 8.

    Input, double ALPHA, BETA, the parameters, if required
    by the value of KIND.
*/
{
  double tmp;

  if ( kind <= 0 )
  {
    printf ( "\n" );
    printf ( "PARCHK - Fatal error!\n" );
    printf ( "  KIND <= 0.\n" );
    exit ( 1 );
  }
/*
  Check ALPHA for Gegenbauer, Jacobi, Laguerre, Hermite, Exponential.
*/
  if ( 3 <= kind && alpha <= -1.0 )
  {
    printf ( "\n" );
    printf ( "PARCHK - Fatal error!\n" );
    printf ( "  3 <= KIND and ALPHA <= -1.\n" );
    exit ( 1 );
  }
/*
  Check BETA for Jacobi.
*/
  if ( kind == 4 && beta <= -1.0 )
  {
    printf ( "\n" );
    printf ( "PARCHK - Fatal error!\n" );
    printf ( "  KIND == 4 and BETA <= -1.0.\n" );
    exit ( 1 );
  }
/*
  Check ALPHA and BETA for rational.
*/
  if ( kind == 8 )
  {
    tmp = alpha + beta + m + 1.0;
    if ( 0.0 <= tmp || tmp <= beta )
    {
      printf ( "\n" );
      printf ( "PARCHK - Fatal error!\n" );
      printf ( "  KIND == 8 but condition on ALPHA and BETA fails.\n" );
      exit ( 1 );
    }
  }
  return;
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

    14 November 2006

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
    value = x;
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

double r8_sign ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_SIGN returns the sign of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 October 2004

  Author:

    John Burkardt

  Parameters:

    Input, double X, the number whose sign is desired.

    Output, double R8_SIGN, the sign of X.
*/
{
  double value;

  if ( x < 0.0 )
  {
    value = -1.0;
  } 
  else
  {
    value = 1.0;
  }
  return value;
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

void rule_write ( int order, char *filename, double x[], double w[], 
  double r[] )

/******************************************************************************/
/*
  Purpose:

    RULE_WRITE writes a quadrature rule to three files.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 February 2014

  Author:

    John Burkardt

  Parameters:

    Input, int ORDER, the order of the rule.

    Input, char *FILENAME, specifies the output filenames.
    "filename_w.txt", "filename_x.txt", "filename_r.txt" 
    defining weights, abscissas, and region.
*/
{
  char filename_r[255];
  char filename_w[255];
  char filename_x[255];

  strcpy ( filename_r, filename );
  strcat ( filename_r, "_r.txt" );
  strcpy ( filename_w, filename );
  strcat ( filename_w, "_w.txt" );
  strcpy ( filename_x, filename );
  strcat ( filename_x, "_x.txt" );

  printf ( "\n" );
  printf ( "  Creating quadrature files.\n" );
  printf ( "\n" );
  printf ( "  Root file name is     \"%s\"\n", filename );
  printf ( "\n" );
  printf ( "  Weight file will be   \"%s\"\n", filename_w  );
  printf ( "  Abscissa file will be \"%s\"\n", filename_x  );
  printf ( "  Region file will be   \"%s\"\n", filename_r  );
            
  r8mat_write ( filename_w, 1, order, w );
  r8mat_write ( filename_x, 1, order, x );
  r8mat_write ( filename_r, 1, 2,     r );
  
  return;
}
/******************************************************************************/

void scqf ( int nt, double t[], int mlt[], double wts[], int nwts, int ndx[], 
  double swts[], double st[], int kind, double alpha, double beta, double a, 
  double b )

/******************************************************************************/
/*
  Purpose:

    SCQF scales a quadrature formula to a nonstandard interval.

  Discussion:

    The arrays WTS and SWTS may coincide.

    The arrays T and ST may coincide.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int NT, the number of knots.

    Input, double T[NT], the original knots.

    Input, int MLT[NT], the multiplicity of the knots.

    Input, double WTS[NWTS], the weights.

    Input, int NWTS, the number of weights.

    Input, int NDX[NT], used to index the array WTS.  
    For more details see the comments in CAWIQ.

    Output, double SWTS[NWTS], the scaled weights.

    Output, double ST[NT], the scaled knots.

    Input, int KIND, the rule.
    1, Legendre,             (a,b)       1.0
    2, Chebyshev Type 1,     (a,b)       ((b-x)*(x-a))^(-0.5)
    3, Gegenbauer,           (a,b)       ((b-x)*(x-a))^alpha
    4, Jacobi,               (a,b)       (b-x)^alpha*(x-a)^beta
    5, Generalized Laguerre, (a,inf)     (x-a)^alpha*exp(-b*(x-a))
    6, Generalized Hermite,  (-inf,inf)  |x-a|^alpha*exp(-b*(x-a)^2)
    7, Exponential,          (a,b)       |x-(a+b)/2.0|^alpha
    8, Rational,             (a,inf)     (x-a)^alpha*(x+b)^beta

    Input, double ALPHA, the value of Alpha, if needed.

    Input, double BETA, the value of Beta, if needed.

    Input, double A, B, the interval endpoints.
*/
{
  double al;
  double be;
  int i;
  int k;
  int l;
  double p;
  double shft;
  double slp;
  double temp;
  double tmp;

  temp = r8_epsilon ( );

  parchk ( kind, 1, alpha, beta );

  if ( kind == 1 )
  {
    al = 0.0;
    be = 0.0;
    if ( ( b - a ) <= temp )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B - A too small.\n" );
      exit ( 1 );
    }
    shft = ( a + b ) / 2.0;
    slp = ( b - a ) / 2.0;
  }
  else if ( kind == 2 )
  {
    al = -0.5;
    be = -0.5;
    if ( ( b - a ) <= temp )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B - A too small.\n" );
      exit ( 1 );
    }
    shft = ( a + b ) / 2.0;
    slp = ( b - a ) / 2.0;
  }
  else if ( kind == 3 )
  {
    al = alpha;
    be = alpha;
    if ( ( b - a ) <= temp )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B - A too small.\n" );
      exit ( 1 );
    }
    shft = ( a + b ) / 2.0;
    slp = ( b - a ) / 2.0;
  }
  else if ( kind == 4 )
  {
    al = alpha;
    be = beta;

    if ( ( b - a ) <= temp )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B - A too small.\n" );
      exit ( 1 );
    }
    shft = ( a + b ) / 2.0;
    slp = ( b - a ) / 2.0;
  }
  else if ( kind == 5 )
  {
    if ( b <= 0.0 )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B <= 0\n" );
      exit ( 1 );
    }
    shft = a;
    slp = 1.0 / b;
    al = alpha;
    be = 0.0;
  }
  else if ( kind == 6 )
  {
    if ( b <= 0.0 )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B <= 0.\n" );
      exit ( 1 );
    }
    shft = a;
    slp = 1.0 / sqrt ( b );
    al = alpha;
    be = 0.0;
  }
  else if ( kind == 7 )
  {
    al = alpha;
    be = 0.0;
    if ( ( b - a ) <= temp )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  B - A too small.\n" );
      exit ( 1 );
    }
    shft = ( a + b ) / 2.0;
    slp = ( b - a ) / 2.0;
  }
  else if ( kind == 8 )
  {
    if ( a + b <= 0.0 )
    {
      printf ( "\n" );
      printf ( "SCQF - Fatal error!\n" );
      printf ( "  A + B <= 0.\n" );
      exit ( 1 );
    }
    shft = a;
    slp = a + b;
    al = alpha;
    be = beta;
  }

  p = pow ( slp, al + be + 1.0 );

  for ( k = 0; k < nt; k++ )
  {
    st[k] = shft + slp * t[k];
    l = abs ( ndx[k] );

    if ( l != 0 )
    {
      tmp = p;
      for ( i = l - 1; i <= l - 1 + mlt[k] - 1; i++ )
      {
        swts[i] = wts[i] * tmp;
        tmp = tmp * slp;
      }
    }
  }
  return;
}
/******************************************************************************/

void sgqf ( int nt, double aj[], double bj[], double zemu, double t[], 
  double wts[] )

/******************************************************************************/
/*
  Purpose:

    SGQF computes knots and weights of a Gauss Quadrature formula.

  Discussion:

    This routine computes all the knots and weights of a Gauss quadrature
    formula with simple knots from the Jacobi matrix and the zero-th
    moment of the weight function, using the Golub-Welsch technique.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
    C version by John Burkardt.

  Reference:

    Sylvan Elhay, Jaroslav Kautsky,
    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
    Interpolatory Quadrature,
    ACM Transactions on Mathematical Software,
    Volume 13, Number 4, December 1987, pages 399-415.

  Parameters:

    Input, int NT, the number of knots.

    Input, double AJ[NT], the diagonal of the Jacobi matrix.

    Input/output, double BJ[NT], the subdiagonal of the Jacobi 
    matrix, in entries 1 through NT-1.  On output, BJ has been overwritten.

    Input, double ZEMU, the zero-th moment of the weight function.

    Output, double T[NT], the knots.

    Output, double WTS[NT], the weights.
*/
{
  int i;
/*
  Exit if the zero-th moment is not positive.
*/
  if ( zemu <= 0.0 )
  {
    printf ( "\n" );
    printf ( "SGQF - Fatal error!\n" );
    printf ( "  ZEMU <= 0.\n" );
    exit ( 1 );
  }
/*
  Set up vectors for IMTQLX.
*/
  for ( i = 0; i < nt; i++ )
  {
    t[i] = aj[i];
  }
  wts[0] = sqrt ( zemu );
  for ( i = 1; i < nt; i++ )
  {
    wts[i] = 0.0;
  }
/*
  Diagonalize the Jacobi matrix.
*/
  imtqlx ( nt, t, bj, wts );

  for ( i = 0; i < nt; i++ )
  {
    wts[i] = wts[i] * wts[i];
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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
