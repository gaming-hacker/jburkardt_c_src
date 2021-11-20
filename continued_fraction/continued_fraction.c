# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "continued_fraction.h"

/******************************************************************************/

void i4cf_evaluate ( int n, int a[], int b[], int p[], int q[] )

/******************************************************************************/
/*
  Purpose:

    I4CF_EVALUATE evaluates a continued fraction with I4 entries.

  Discussion:

    For convenience, we omit the parentheses or multiline display.

    CF = A(0) + B(1) / A(1) + B(2) / A(2) + ... A(N-1) + B(N) / A(N).

  Licensing:

    I don't care what you do with this code.

  Modified:

    07 August 2017

  Author:

    John Burkardt

  Reference:

    John Hart, Ward Cheney, Charles Lawson, Hans Maehly, Charles Mesztenyi,
    John Rice, Henry Thatcher, Christoph Witzgall,
    Computer Approximations,
    Wiley, 1968.

  Parameters:

    Input, int N, the number of continued fraction
    coefficients.

    Input, int A[N+1], B[N+1], the continued fraction 
    coefficients.

    Output, int P[N+1], Q[N+1], the N+1 successive 
    approximations to the value of the continued fraction.
*/
{
  int i;

  for ( i = 0; i <= n; i++ )
  {
    if ( i == 0 )
    {
      p[i] = a[i] * 1 + 0;
      q[i] = a[i] * 0 + 1;
    }
    else if ( i == 1 )
    {
      p[i] = a[i] * p[i-1] + b[i] * 1;
      q[i] = a[i] * q[i-1] + b[i] * 0;
    }
    else
    {
      p[i] = a[i] * p[i-1] + b[i] * p[i-2];
      q[i] = a[i] * q[i-1] + b[i] * q[i-2];
    }
  }

  return;
}
/******************************************************************************/

void i4cf_evaluate_test ( )

/******************************************************************************/
/*
  Purpose:

    I4CF_EVALUATE_TEST tests I4CF_EVALUATE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    05 August 2017

  Author:

    John Burkardt
*/
{
  int a[20] = {
    3, 
    6, 6, 6, 6, 6, 
    6, 6, 6, 6, 6, 
    6, 6, 6, 6, 6, 
    6, 6, 6, 6 };
  int b[20] = {
      0,
      1,    9,   25,   49,   81, 
    121,  169,  225,  289,  361, 
    441,  529,  625,  729,  841, 
    961, 1089, 1225, 1369 };
  int i;
  int n = 19;
  int *p;
  int *q;
  double t;

  printf ( "\n" );
  printf ( "I4CF_EVALUATE_TEST:\n" );

  p = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );
  q = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );

  i4cf_evaluate ( n, a, b, p, q );

  printf ( "\n" );
  printf ( "  CF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( p[i] ) / ( double ) ( q[i] );
    printf ( "  %2d  %20d  %20d  %24.16g\n", i, p[i], q[i], t );
  }

  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void i4scf_evaluate ( int n, int a[], int p[], int q[] )

/******************************************************************************/
/*
  Purpose:

    I4SCF_EVALUATE evaluates a simple continued fraction with I4 entries.

  Discussion:

    The simple continued fraction with integer coefficients is:

      SCF = A(0) + 1 / ( A(1) + 1 / ( A(2) ... + 1 / A(N) ) )

    This routine returns the successive approximants P[i]/Q[i]
    to the value of the rational number represented by the continued
    fraction, with the value exactly equal to the final ratio P(N)/Q(N).

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt

  Reference:

    John Hart, Ward Cheney, Charles Lawson, Hans Maehly, Charles Mesztenyi,
    John Rice, Henry Thatcher, Christoph Witzgall,
    Computer Approximations,
    Wiley, 1968.

  Parameters:

    Input, int N, the number of continued fraction
    coefficients.

    Input, int A[N+1], the continued fraction coefficients.

    Output, int P[N+1], Q[N+1], the numerators and
    denominators of the successive approximations.
*/
{
  int i;

  for ( i = 0; i <= n; i++ )
  {
    if ( i == 0 )
    {
      p[i] = a[i] * 1 + 0;
      q[i] = a[i] * 0 + 1;
    }
    else if ( i == 1 )
    {
      p[i] = a[i] * p[i-1] + 1;
      q[i] = a[i] * q[i-1] + 0;
    }
    else
    {
      p[i] = a[i] * p[i-1] + p[i-2];
      q[i] = a[i] * q[i-1] + q[i-2];
    }
  }

  return;
}
/******************************************************************************/

void i4scf_evaluate_test ( )

/******************************************************************************/
/*
  Purpose:

    I4SCF_EVALUATE_TEST tests I4SCF_EVALUATE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt
*/
{
  int a[20] = {
    3, 7, 15, 1, 292,
    1, 1,  1, 2,   1, 
    3, 1, 14, 2,   1, 
    1, 2,  2, 2,   2 };
  int i;
  int n = 19;
  int *p;
  int *q;
  double t;

  printf ( "\n" );
  printf ( "I4SCF_EVALUATE_TEST:\n" );

  p = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );
  q = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );

  i4scf_evaluate ( n, a, p, q );

  printf ( "\n" );
  printf ( "  SCF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( p[i] ) / ( double) ( q[i] );
    printf ( "  %2d  %20d  %20d  %24.16g\n", i, p[i], q[i], t );
  }

  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void i4vec_print ( int n, int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PRINT prints an I4VEC.

  Discussion:

    An I4VEC is a vector of I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 November 2003

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %6d: %8d\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

void i8cf_evaluate ( int n, long long a[], long long b[], long long p[], 
  long long q[] )

/******************************************************************************/
/*
  Purpose:

    I8CF_EVALUATE evaluates a continued fraction with I8 entries.

  Discussion:

    For convenience, we omit the parentheses or multiline display.

    CF = A(0) + B(1) / A(1) + B(2) / A(2) + ... A(N-1) + B(N) / A(N).

  Licensing:

    I don't care what you do with this code.

  Modified:

    05 August 2017

  Author:

    John Burkardt

  Reference:

    John Hart, Ward Cheney, Charles Lawson, Hans Maehly, Charles Mesztenyi,
    John Rice, Henry Thatcher, Christoph Witzgall,
    Computer Approximations,
    Wiley, 1968.

  Parameters:

    Input, int N, the number of continued fraction
    coefficients.

    Input, long long int A[N+1], B[N+1], the continued fraction 
    coefficients.

    Output, long long int P[N+1], Q[N+1], the N successive 
    approximations to the value of the continued fraction.
*/
{
  int i;

  for ( i = 0; i <= n; i++ )
  {
    if ( i == 0 )
    {
      p[i] = a[i] * 1 + 0;
      q[i] = a[i] * 0 + 1;
    }
    else if ( i == 1 )
    {
      p[i] = a[i] * p[i-1] + b[i] * 1;
      q[i] = a[i] * q[i-1] + b[i] * 0;
    }
    else
    {
      p[i] = a[i] * p[i-1] + b[i] * p[i-2];
      q[i] = a[i] * q[i-1] + b[i] * q[i-2];
    }
  }

  return;
}
/******************************************************************************/

void i8cf_evaluate_test ( )

/******************************************************************************/
/*
  Purpose:

    I8CF_EVALUATE_TEST tests I8CF_EVALUATE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    05 August 2017

  Author:

    John Burkardt
*/
{
  long long int a[20] = {
    3, 
    6, 6, 6, 6, 6, 
    6, 6, 6, 6, 6, 
    6, 6, 6, 6, 6, 
    6, 6, 6, 6 };
  long long int b[20] = {
      0, 
      1,    9,   25,   49,   81, 
    121,  169,  225,  289,  361, 
    441,  529,  625,  729,  841, 
    961, 1089, 1225, 1369 };
  int i;
  int n = 19;
  long long int *p;
  long long int *q;
  double t;

  printf ( "\n" );
  printf ( "I8CF_EVALUATE_TEST:\n" );

  p = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );
  q = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );

  i8cf_evaluate ( n, a, b, p, q );

  printf ( "\n" );
  printf ( "  CF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( p[i] ) / ( double ) ( q[i] );
    printf ( "  %2d  %20lld  %20lld  %24.16g\n", i, p[i], q[i], t );
  }

  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void i8scf_evaluate ( int n, long long int a[], long long int p[], 
  long long int q[] )

/******************************************************************************/
/*
  Purpose:

    I8SCF_EVALUATE evaluates a simple continued fraction with I8 entries.

  Discussion:

    The simple continued fraction with integer coefficients is:

      SCF = A(0) + 1 / ( A(1) + 1 / ( A(2) ... + 1 / A(N) ) )

    This routine returns the successive approximants P[i]/Q[i]
    to the value of the rational number represented by the continued
    fraction, with the value exactly equal to the final ratio P(N)/Q(N).

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt

  Reference:

    John Hart, Ward Cheney, Charles Lawson, Hans Maehly, Charles Mesztenyi,
    John Rice, Henry Thatcher, Christoph Witzgall,
    Computer Approximations,
    Wiley, 1968.

  Parameters:

    Input, int N, the number of continued fraction
    coefficients.

    Input, long long int A[N+1], the continued fraction coefficients.

    Output, long long int P[N+1], Q[N+1], the numerators and
    denominators of the successive approximations.
*/
{
  int i;

  for ( i = 0; i <= n; i++ )
  {
    if ( i == 0 )
    {
      p[i] = a[i] * 1 + 0;
      q[i] = a[i] * 0 + 1;
    }
    else if ( i == 1 )
    {
      p[i] = a[i] * p[i-1] + 1;
      q[i] = a[i] * q[i-1] + 0;
    }
    else
    {
      p[i] = a[i] * p[i-1] + p[i-2];
      q[i] = a[i] * q[i-1] + q[i-2];
    }
  }

  return;
}
/******************************************************************************/

void i8scf_evaluate_test ( )

/******************************************************************************/
/*
  Purpose:

    I8SCF_EVALUATE_TEST tests I8SCF_EVALUATE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    07 August 2017

  Author:

    John Burkardt
*/
{
  long long int a[20] = {
    3, 7, 15, 1, 292, 
    1, 1,  1, 2,   1, 
    3, 1, 14, 2,   1, 
    1, 2,  2, 2,   2 };
  int i;
  int n = 19;
  long long int *p;
  long long int *q;
  double t;

  printf ( "\n" );
  printf ( "I8SCF_EVALUATE_TEST:\n" );

  p = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );
  q = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );

  i8scf_evaluate ( n, a, p, q );

  printf ( "\n" );
  printf ( "  SCF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( p[i] ) / ( double ) ( q[i] );
    printf ( "  %2d  %20lld  %20lld  %24.16g\n", i, p[i], q[i], t );
  }

  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void i8vec_print ( long long int n, long long int a[], char *title )

/******************************************************************************/
/*
  Purpose:

    I8VEC_PRINT prints an I8VEC.

  Discussion:

    An I8VEC is a vector of I8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 August 2017

  Author:

    John Burkardt

  Parameters:

    Input, long long int N, the number of components of the vector.

    Input, long long int A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  long long int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %6lld: %8lld\n", i, a[i] );
  }
  return;
}
/******************************************************************************/

void r8_to_i4scf ( double r, int n, int a[] )

/******************************************************************************/
/*
  Purpose:

    R8_TO_I4SCF approximates an R8 with an I4 simple continued fraction.

  Discussion:

    The simple continued fraction with real coefficients is:

      SCF = A(0) + 1 / ( A(1) + 1 / ( A(2) ... + 1 / A(N) ) )

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt

  Reference:

    Norman Richert,
    Strang's Strange Figures,
    American Mathematical Monthly,
    Volume 99, Number 2, February 1992, pages 101-107.

  Parameters:

    Input, double R, the real value.

    Input, int N, the number of convergents to compute.

    Output, int A[N+1], the partial quotients.
*/
{
  int i;
  double r2;

  if ( r == 0.0 )
  {
    for ( i = 0; i <= n; i++ )
    {
      a[i] = 0;
    }
    return;
  }

  r2 = r;
  a[0] = ( int ) ( r2 );

  for ( i = 1; i <= n; i++ )
  {
    r2 = 1.0 / ( r2 - ( double ) ( a[i-1] ) );
    a[i] = ( int ) ( r2 );
  }

  return;
}
/******************************************************************************/

void r8_to_i4scf_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_TO_I4SCF_TEST tests R8_TO_I4SCF.

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt
*/
{
  int *a;
  int i;
  int n = 19;
  int *p;
  int *q;
  double r;
  double r8_pi = 3.141592653589793;
  double t;

  printf ( "\n" );
  printf ( "R8_TO_I4SCF_TEST:\n" );

  r = r8_pi;

  a = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );

  r8_to_i4scf ( r, n, a );

  i4vec_print ( n + 1, a, "  SCF coefficients:" );

  p = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );
  q = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );

  i4scf_evaluate ( n, a, p, q );

  printf ( "\n" );
  printf ( "  SCF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( p[i] ) / ( double ) ( q[i] );
    printf ( "  %2d  %20d  %20d  %24.16g\n", i, p[i], q[i], t );
  }

  free ( a );
  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void r8_to_i8scf ( double r, int n, long long int a[] )

/******************************************************************************/
/*
  Purpose:

    R8_TO_I8SCF approximates an R8 with an I8 simple continued fraction.

  Discussion:

    The simple continued fraction with real coefficients is:

      SCF = A(0) + 1 / ( A(1) + 1 / ( A(2) ... + 1 / A(N) ) )

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt

  Reference:

    Norman Richert,
    Strang's Strange Figures,
    American Mathematical Monthly,
    Volume 99, Number 2, February 1992, pages 101-107.

  Parameters:

    Input, double R, the real value.

    Input, int N, the number of convergents to compute.

    Output, long long int A[N+1], the partial quotients.
*/
{
  int i;
  double r2;

  if ( r == 0.0 )
  {
    for ( i = 0; i <= n; i++ )
    {
      a[i] = 0;
    }
    return;
  }

  r2 = r;
  a[0] = ( long long int ) ( r2 );

  for ( i = 1; i <= n; i++ )
  {
    r2 = 1.0 / ( r2 - ( double ) ( a[i-1] ) );
    a[i] = ( long long int ) ( r2 );
  }

  return;
}
/******************************************************************************/

void r8_to_i8scf_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_TO_I8SCF_EVALUATE_TEST tests R8_TO_I8SCF.

  Licensing:

    I don't care what you do with this code.

  Modified:

    04 August 2017

  Author:

    John Burkardt
*/
{
  long long int *a;
  int i;
  int n = 19;
  long long int *p;
  long long int *q;
  double r;
  double r8_pi = 3.141592653589793;
  double t;

  printf ( "\n" );
  printf ( "R8_TO_I8SCF_TEST:\n" );

  r = r8_pi;

  a = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );

  r8_to_i8scf ( r, n, a );

  i8vec_print ( n + 1, a, "  SCF coefficients:" );

  p = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );
  q = ( long long int * ) malloc ( ( n + 1 ) * sizeof ( long long int ) );

  i8scf_evaluate ( n, a, p, q );

  printf ( "\n" );
  printf ( "  SCF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    t = ( double ) ( p[i] ) / ( double ) ( q[i] );
    printf ( "  %2d  %20lld  %20lld  %24.16g\n", i, p[i], q[i], t );
  }

  free ( a );
  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void r8cf_evaluate ( int n, double a[], double b[], double p[], double q[] )

/******************************************************************************/
/*
  Purpose:

    R8CF_EVALUATE evaluates a continued fraction with R8 entries.

  Discussion:

    For convenience, we omit the parentheses or multiline display.

    CF = A(0) + B(1) / A(1) + B(2) / A(2) + ... A(N-1) + B(N) / A(N).

  Licensing:

    I don't care what you do with this code.

  Modified:

    06 August 2017

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of terms.

    Input, double A[N+1], B[N+1], the continued fraction
    terms.

    Output, double P[N+1], Q[N+1], the numerators
    and denominators of the successive partial sums of the continued
    fraction.
*/
{
  int i;

  for ( i = 0; i <= n; i++ )
  {
    if ( i == 0 )
    {
      p[i] = a[i] * 1.0 + 0.0;
      q[i] = a[i] * 0.0 + 1.0;
    }
    else if ( i == 1 )
    {
      p[i] = a[i] * p[i-1] + b[i] * 1.0;
      q[i] = a[i] * q[i-1] + b[i] * 0.0;
    }
    else
    {
      p[i] = a[i] * p[i-1] + b[i] * p[i-2];
      q[i] = a[i] * q[i-1] + b[i] * q[i-2];
    }
  }

  return;
}
/******************************************************************************/

void r8cf_evaluate_test ( )

/******************************************************************************/
/*
  Purpose:

    R8CF_EVALUATE_TEST tests R8CF_EVALUATE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    03 August 2017

  Author:

    John Burkardt
*/
{
  int n = 20;

  double *a;
  double *b;
  int i;
  double *p;
  double *q;
  double t;

  printf ( "\n" );
  printf ( "R8CF_EVALUATE_TEST:\n" );

  a = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  b = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );

  a[0] = 3.0;
  for ( i = 1; i <= n; i++ )
  {
    a[i] = 6.0;
  }
  b[0] = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    t = ( double ) ( 2 * i - 1 );
    b[i] = t * t;
  }

  p = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  q = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );

  r8cf_evaluate ( n, a, b, p, q );

  printf ( "\n" );
  printf ( "  CF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    printf ( "  %2d  %24.16g  %24.16g  %24.16g\n", i, p[i], q[i], p[i] / q[i] );
  }

  free ( a );
  free ( b );
  free ( p );
  free ( q );

  return;
}
/******************************************************************************/

void r8scf_evaluate ( int n, double a[], double p[], double q[] )

/******************************************************************************/
/*
  Purpose:

    R8SCF_EVALUATE evaluates a simple continued fraction with R8 entries.

  Discussion:

    The simple continued fraction with real coefficients is:

      SCF = A(0) + 1 / ( A(1) + 1 / ( A(2) ... + 1 / A(N) ) )

    This routine returns the N successive approximants P[i]/Q[i]
    to the value of the rational number represented by the continued
    fraction, with the value exactly equal to the final ratio C(N)/D(N).

  Licensing:

    I don't care what you do with this code.

  Modified:

    03 August 2017

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of continued fraction
    coefficients.

    Input, double A[N+1], the continued fraction coefficients.

    Output, double P[N+1], Q[N+1], the numerators and
    denominators of the successive approximations.
*/
{
  int i;

  for ( i = 0; i <= n; i++ )
  {
    if ( i == 0 )
    {
      p[i] = a[i] * 1.0 + 0.0;
      q[i] = a[i] * 0.0 + 1.0;
    }
    else if ( i == 1 )
    {
      p[i] = a[i] * p[i-1] + 1.0;
      q[i] = a[i] * q[i-1] + 0.0;
    }
    else
    {
      p[i] = a[i] * p[i-1] + p[i-2];
      q[i] = a[i] * q[i-1] + q[i-2];
    }
  }

  return;
}
/******************************************************************************/

void r8scf_evaluate_test ( )

/******************************************************************************/
/*
  Purpose:

    R8SCF_EVALUATE_TEST tests R8SCF_EVALUATE.

  Licensing:

    I don't care what you do with this code.

  Modified:

    03 August 2017

  Author:

    John Burkardt
*/
{
  double a[20] = {
    3.0, 7.0, 15.0, 1.0, 292.0, 
    1.0, 1.0,  1.0, 2.0,   1.0, 
    3.0, 1.0, 14.0, 2.0,   1.0, 
    1.0, 2.0,  2.0, 2.0,   2.0 };
  int i;
  int n = 19;
  double *p;
  double *q;

  printf ( "\n" );
  printf ( "R8SCF_EVALUATE_TEST:\n" );

  p = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  q = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );

  r8scf_evaluate ( n, a, p, q );

  printf ( "\n" );
  printf ( "  SCF numerators, denominators, ratios:\n" );
  printf ( "\n" );

  for ( i = 0; i <= n; i++ )
  {
    printf ( "  %2d  %24.16g  %24.16g  %24.16g\n", i, p[i], q[i], p[i] / q[i] );
  }

  free ( p );
  free ( q );

  return;
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
