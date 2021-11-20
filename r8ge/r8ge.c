# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "r8ge.h"

/******************************************************************************/

int i4_log_10 ( int i )

/******************************************************************************/
/*
  Purpose:

    I4_LOG_10 returns the integer part of the logarithm base 10 of an I4.

  Example:

        I  I4_LOG_10
    -----  --------
        0    0
        1    0
        2    0
        9    0
       10    1
       11    1
       99    1
      100    2
      101    2
      999    2
     1000    3
     1001    3
     9999    3
    10000    4

  Discussion:

    I4_LOG_10 ( I ) + 1 is the number of decimal digits in I.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, the number whose logarithm base 10 is desired.

    Output, int I4_LOG_10, the integer part of the logarithm base 10 of
    the absolute value of X.
*/
{
  int i_abs;
  int ten_pow;
  int value;

  if ( i == 0 )
  {
    value = 0;
  }
  else
  {
    value = 0;
    ten_pow = 10;

    i_abs = abs ( i );

    while ( ten_pow <= i_abs )
    {
      value = value + 1;
      ten_pow = ten_pow * 10;
    }
  }
  return value;
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

int i4_power ( int i, int j )

/******************************************************************************/
/*
  Purpose:

    I4_POWER returns the value of I^J.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2007

  Author:

    John Burkardt

  Parameters:

    Input, int I, J, the base and the power.  J should be nonnegative.

    Output, int I4_POWER, the value of I^J.
*/
{
  int k;
  int value;

  if ( j < 0 )
  {
    if ( i == 1 )
    {
      value = 1;
    }
    else if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I4_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J negative.\n" );
      exit ( 1 );
    }
    else
    {
      value = 0;
    }
  }
  else if ( j == 0 )
  {
    if ( i == 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "I4_POWER - Fatal error!\n" );
      fprintf ( stderr, "  I^J requested, with I = 0 and J = 0.\n" );
      exit ( 1 );
    }
    else
    {
      value = 1;
    }
  }
  else if ( j == 1 )
  {
    value = i;
  }
  else
  {
    value = 1;
    for ( k = 1; k <= j; k++ )
    {
      value = value * i;
    }
  }
  return value;
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

double r8_sign ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_SIGN returns the sign of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 May 2006

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

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a unit pseudorandom R8.

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
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + 2147483647;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
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

void r8ge_cg ( int n, double a[], double b[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_CG uses the conjugate gradient method on an R8GE system.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    The matrix A must be a positive definite symmetric band matrix.

    The method is designed to reach the solution after N computational
    steps.  However, roundoff may introduce unacceptably large errors for
    some problems.  In such a case, calling the routine again, using
    the computed solution as the new starting estimate, should improve
    the results.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2014

  Author:

    John Burkardt

  Reference:

    Frank Beckman,
    The Solution of Linear Equations by the Conjugate Gradient Method,
    in Mathematical Methods for Digital Computers,
    edited by John Ralston, Herbert Wilf,
    Wiley, 1967,
    ISBN: 0471706892,
    LC: QA76.5.R3.

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[N*N], the matrix.

    Input, double B[N], the right hand side vector.

    Input/output, double X[N].
    On input, an estimate for the solution, which may be 0.
    On output, the approximate solution vector.
*/
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
/*
  Initialize
    AP = A * x,
    R  = b - A * x,
    P  = b - A * x.
*/
  ap = r8ge_mv ( n, n, a, x );

  r = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
/*
  Do the N steps of the conjugate gradient method.
*/
  for ( it = 1; it <= n; it++ )
  {
/*
  Compute the matrix*vector product AP=A*P.
*/
    free ( ap );
    ap = r8ge_mv ( n, n, a, p );
/*
  Compute the dot products
    PAP = P*AP,
    PR  = P*R
  Set
    ALPHA = PR / PAP.
*/
    pap = r8vec_dot_product ( n, p, ap );
    pr = r8vec_dot_product ( n, p, r );

    if ( pap == 0.0 )
    {
      free ( ap );
      break;
    }

    alpha = pr / pap;
/*
  Set
    X = X + ALPHA * P
    R = R - ALPHA * AP.
*/
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
/*
  Compute the vector dot product
    RAP = R*AP
  Set
    BETA = - RAP / PAP.
*/
    rap = r8vec_dot_product ( n, r, ap );

    beta = - rap / pap;
/*
  Update the perturbation vector
    P = R + BETA * P.
*/
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }
  }

  free ( p );
  free ( r );

  return;
}
/******************************************************************************/

double r8ge_co ( int n, double a[], int pivot[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_CO factors an R8GE matrix and estimates its condition number.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    For the system A * X = B, relative perturbations in A and B
    of size EPSILON may cause relative perturbations in X of size
    EPSILON/RCOND.

    If RCOND is so small that the logical expression
      1.0 + rcond == 1.0
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate
    underflows.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 February 2012

  Author:

    Original FORTRAN77 version by Dongarra, Bunch, Moler, Stewart.
    C version by John Burkardt.

  Reference:

    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979,
    ISBN13: 978-0-898711-72-1,
    LC: QA214.L56.

  Parameters:

    Input, int N, the order of the matrix A.

    Input/output, double A[N*N].  On input, a matrix to be factored.
    On output, the LU factorization of the matrix.

    Output, int PIVOT[N], the pivot indices.

    Output, double R8GE_CO, an estimate of the reciprocal condition number of A.
*/
{
  double anorm;
  double ek;
  int i;
  int info;
  int j;
  int k;
  int l;
  double rcond;
  double s;
  double sm;
  double t;
  double wk;
  double wkm;
  double ynorm;
  double *z;
/*
  Compute the L1 norm of A.
*/
  anorm = 0.0;
  for ( j = 0; j < n; j++ )
  {
    s = 0.0;
    for ( i = 0; i < n; i++ )
    {
      s = s + fabs ( a[i+j*n] );
    }
    anorm = r8_max ( anorm, s );
  }
/*
  Compute the LU factorization.
*/
  info = r8ge_fa ( n, a, pivot );

  if ( info != 0 ) 
  {
    rcond = 0.0;
    return rcond;
  }
/*
  RCOND = 1 / ( norm(A) * (estimate of norm(inverse(A))) )

  estimate of norm(inverse(A)) = norm(Z) / norm(Y)

  where
    A * Z = Y
  and
    A' * Y = E

  The components of E are chosen to cause maximum local growth in the
  elements of W, where U'*W = E.  The vectors are frequently rescaled
  to avoid overflow.

  Solve U' * W = E.
*/
  ek = 1.0;
  z = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    z[i] = 0.0;
  }

  for ( k = 0; k < n; k++ )
  {
    if ( z[k] != 0.0 ) 
    {
      ek = - r8_sign ( z[k] ) * fabs ( ek );
    }

    if ( fabs ( a[k+k*n] ) < fabs ( ek - z[k] ) )
    {
      s = fabs ( a[k+k*n] ) / fabs ( ek - z[k] );
      for ( i = 0; i < n; i++ )
      {
        z[i] = s * z[i];
      }
      ek = s * ek;
    }

    wk = ek - z[k];
    wkm = - ek - z[k];
    s = fabs ( wk );
    sm = fabs ( wkm );

    if ( a[k+k*n] != 0.0 )
    {
      wk = wk / a[k+k*n];
      wkm = wkm / a[k+k*n];
    }
    else
    {
      wk = 1.0;
      wkm = 1.0;
    }

    if ( k + 2 <= n )
    {
      for ( j = k+1; j < n; j++ )
      {
        sm = sm + fabs ( z[j] + wkm * a[k+j*n] );
        z[j] = z[j] + wk * a[k+j*n];
        s = s + fabs ( z[j] );
      }

      if ( s < sm )
      {
        t = wkm - wk;
        wk = wkm;
        for ( j = k+1; j < n; j++ )
        {
          z[j] = z[j] + t * a[k+j*n];
        }
      }
    }
    z[k] = wk;
  }

  s = 0.0;
  for ( i = 0; i < n; i++ )
  {
    s = s + fabs ( z[i] );
  }

  for ( i = 0; i < n; i++ )
  {
    z[i] = z[i] / s;
  }
/*
  Solve L' * Y = W
*/
  for ( k = n - 1; 0 <= k; k-- )
  {
    for ( i = k+1; i < n; i++ )
    {
      z[k] = z[k] + z[i] * a[i+k*n];
    }
    t = fabs ( z[k] );
    if ( 1.0 < t )
    {
      for ( i = 0; i < n; i++ )
      {
        z[i] = z[i] / t;
      }
    }

    l = pivot[k] - 1;

    t    = z[l];
    z[l] = z[k];
    z[k] = t;
  }

  t = 0.0;
  for ( i = 0; i < n; i++ )
  {
    t = t + fabs ( z[i] );
  }
  for ( i = 0; i < n; i++ )
  {
    z[i] = z[i] / t;
  }

  ynorm = 1.0;
/*
  Solve L * V = Y.
*/
  for ( k = 0; k < n; k++ )
  {
    l = pivot[k] - 1;

    t    = z[l];
    z[l] = z[k];
    z[k] = t;

    for ( i = k + 1; i < n; i++ )
    {
      z[i] = z[i] + t * a[i+k*n];
    }

    t = fabs ( z[k] );

    if ( 1.0 < t )
    {
      ynorm = ynorm / t;
      for ( i = 0; i < n; i++ )
      {
        z[i] = z[i] / t;
      }
    }
  }
  s = 0.0;
  for ( i = 0; i < n; i++ )
  {
    s = s + fabs ( z[i] );
  }

  for ( i = 0; i < n; i++ )
  {
    z[i] = z[i] / s;
  }
  ynorm = ynorm / s;
/*
  Solve U * Z = V.
*/
  for ( k = n - 1; 0 <= k; k-- )
  {
    if ( fabs ( a[k+k*n] ) < fabs ( z[k] ) )
    {
      s = fabs ( a[k+k*n] ) / fabs ( z[k] );
      for ( i = 0; i < n; i++ )
      {
        z[i] = s * z[i];
      }
      ynorm = s * ynorm;
    }

    if ( a[k+k*n] != 0.0 )
    {
      z[k] = z[k] / a[k+k*n];
    }
    else
    {
      z[k] = 1.0;
    }

    for ( i = 0; i < k; i++ )
    {
      z[i] = z[i] - a[i+k*n] * z[k];
    }
  }
/*
  Normalize Z in the L1 norm.
*/
  s = 0.0;
  for ( i = 0; i < n; i++ )
  {
    s = s + fabs ( z[i] );
  }
  s = 1.0 / s;

  for ( i = 0; i < n; i++ )
  {
    z[i] = s * z[i];
  }
  ynorm = s * ynorm;

  if ( anorm != 0.0 )
  {
    rcond = ynorm / anorm;
  }
  else
  {
    rcond = 0.0;
  }

  free ( z );

  return rcond;
}
/******************************************************************************/

double *r8ge_copy ( int m, int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_COPY copies an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2016

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of A.

    Input, double A[M*N], the matrix to be copied.

    Output, double R8GE_COPY[M*N], the copy of A.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[i+j*m] = a[i+j*m];
    }
  }

  return b;
}
/******************************************************************************/

double r8ge_det ( int n, double a_lu[], int pivot[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_DET computes the determinant of a matrix factored by R8GE_FA or R8GE_TRF.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Reference:

    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979,
    ISBN13: 978-0-898711-72-1,
    LC: QA214.L56.

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A_LU[N*N], the LU factors from R8GE_FA or R8GE_TRF.

    Input, int PIVOT[N], as computed by R8GE_FA or R8GE_TRF.

    Output, double R8GE_DET, the determinant of the matrix.
*/
{
  double det;
  int i;

  det = 1.0;

  for ( i = 1; i <= n; i++ )
  {
    det = det * a_lu[i-1+(i-1)*n];
    if ( pivot[i-1] != i )
    {
      det = - det;
    }
  }

  return det;
}
/******************************************************************************/

double *r8ge_dif2 ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8GE_DIF2 returns the DIF2 matrix in R8GE format.

  Example:

    N = 5

    2 -1  .  .  .
   -1  2 -1  .  .
    . -1  2 -1  .
    .  . -1  2 -1
    .  .  . -1  2

  Properties:

    A is banded, with bandwidth 3.

    A is tridiagonal.

    Because A is tridiagonal, it has property A (bipartite).

    A is a special case of the TRIS or tridiagonal scalar matrix.

    A is integral, therefore det ( A ) is integral, and 
    det ( A ) * inverse ( A ) is integral.

    A is Toeplitz: constant along diagonals.

    A is symmetric: A' = A.

    Because A is symmetric, it is normal.

    Because A is normal, it is diagonalizable.

    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).

    A is positive definite.

    A is an M matrix.

    A is weakly diagonally dominant, but not strictly diagonally dominant.

    A has an LU factorization A = L * U, without pivoting.

      The matrix L is lower bidiagonal with subdiagonal elements:

        L(I+1,I) = -I/(I+1)

      The matrix U is upper bidiagonal, with diagonal elements

        U(I,I) = (I+1)/I

      and superdiagonal elements which are all -1.

    A has a Cholesky factorization A = L * L', with L lower bidiagonal.

      L(I,I) =    sqrt ( (I+1) / I )
      L(I,I-1) = -sqrt ( (I-1) / I )

    The eigenvalues are

      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
                = 4 SIN^2(I*PI/(2*N+2))

    The corresponding eigenvector X(I) has entries

       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).

    Simple linear systems:

      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)

      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)

    det ( A ) = N + 1.

    The value of the determinant can be seen by induction,
    and expanding the determinant across the first row:

      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
                = 2 * N - (N-1)
                = N + 1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 June 2016

  Author:

    John Burkardt

  Reference:

    Robert Gregory, David Karney,
    A Collection of Matrices for Testing Computational Algorithms,
    Wiley, 1969,
    ISBN: 0882756494,
    LC: QA263.68

    Morris Newman, John Todd,
    Example A8,
    The evaluation of matrix inversion programs,
    Journal of the Society for Industrial and Applied Mathematics,
    Volume 6, Number 4, pages 466-476, 1958.

    John Todd,
    Basic Numerical Mathematics,
    Volume 2: Numerical Algebra,
    Birkhauser, 1980,
    ISBN: 0817608117,
    LC: QA297.T58.

    Joan Westlake,
    A Handbook of Numerical Matrix Inversion and Solution of 
    Linear Equations,
    John Wiley, 1968,
    ISBN13: 978-0471936756,
    LC: QA263.W47.

  Parameters:

    Input, int M, N, the order of the matrix.

    Output, double R8GE_DIF2[M*N], the matrix.
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
      if ( j == i - 1 )
      {
        a[i+j*m] = -1.0;
      }
      else if ( j == i )
      {
        a[i+j*m] = 2.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*m] = -1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }

  return a;
}
/******************************************************************************/

double *r8ge_dilu ( int m, int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_DILU produces the diagonal incomplete LU factor of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, double A[M*N], the R8GE matrix.

    Output, double R8GE_DILU[M], the D-ILU factor.
*/
{
  double *d;
  int i;
  int j;

  d = ( double * ) malloc ( m * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    if ( i < n ) 
    {
      d[i] = a[i+i*m];
    }
    else
    {
      d[i] = 0.0;
    }
  }

  for ( i = 0; i < m && i < n; i++ )
  {
    d[i] = 1.0 / d[i];
    for ( j = i+1; j < m && j < n; j++ )
    {
      d[j] = d[j] - a[j+i*m] * d[i] * a[i+j*m];
    }
  }

  return d;
}
/******************************************************************************/

int r8ge_fa ( int n, double a[], int pivot[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_FA performs a LINPACK-style PLU factorization of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_FA is a simplified version of the LINPACK routine SGEFA.

    The two dimensional array is stored by columns in a one dimensional
    array.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Reference:

    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979,
    ISBN13: 978-0-898711-72-1,
    LC: QA214.L56.

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input/output, double A[N*N], the matrix to be factored.
    On output, A contains an upper triangular matrix and the multipliers
    which were used to obtain it.  The factorization can be written
    A = L * U, where L is a product of permutation and unit lower
    triangular matrices and U is upper triangular.

    Output, int PIVOT[N], a vector of pivot indices.

    Output, int R8GE_FA, singularity flag.
    0, no singularity detected.
    nonzero, the factorization failed on the INFO-th step.
*/
{
  int i;
  int j;
  int k;
  int l;
  double t;

  for ( k = 1; k <= n-1; k++ )
  {
/*
  Find L, the index of the pivot row.
*/
    l = k;

    for ( i = k + 1; i <= n; i++ )
    {
      if ( fabs ( a[l-1+(k-1)*n] ) < fabs ( a[i-1+(k-1)*n] ) )
      {
        l = i;
      }
    }

    pivot[k-1] = l;
/*
  If the pivot index is zero, the algorithm has failed.
*/
    if ( a[l-1+(k-1)*n] == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8GE_FA - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", k );
      exit ( 1 );
    }
/*
  Interchange rows L and K if necessary.
*/
    if ( l != k )
    {
      t              = a[l-1+(k-1)*n];
      a[l-1+(k-1)*n] = a[k-1+(k-1)*n];
      a[k-1+(k-1)*n] = t;
    }
/*
  Normalize the values that lie below the pivot entry A(K,K).
*/
    for ( i = k+1; i <= n; i++ )
    {
      a[i-1+(k-1)*n] = -a[i-1+(k-1)*n] / a[k-1+(k-1)*n];
    }
/*
  Row elimination with column indexing.
*/
    for ( j = k+1; j <= n; j++ )
    {
      if ( l != k )
      {
        t              = a[l-1+(j-1)*n];
        a[l-1+(j-1)*n] = a[k-1+(j-1)*n];
        a[k-1+(j-1)*n] = t;
      }

      for ( i = k+1; i <= n; i++ )
      {
        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + a[i-1+(k-1)*n] * a[k-1+(j-1)*n];
      }

    }

  }

  pivot[n-1] = n;

  if ( a[n-1+(n-1)*n] == 0.0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8GE_FA - Fatal error!\n" );
    fprintf ( stderr, "  Zero pivot on step %d\n", n );
    exit ( 1 );
  }

  return 0;
}
/******************************************************************************/

void r8ge_fs ( int n, double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_FS factors and solves an R8GE system.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The function does not save the LU factors of the matrix, and hence cannot
    be used to efficiently solve multiple linear systems, or even to
    factor A at one time, and solve a single linear system at a later time.

    The function uses partial pivoting, but no pivot vector is required.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input/output, double A[N*N].
    On input, A is the coefficient matrix of the linear system.
    On output, A is in unit upper triangular form, and
    represents the U factor of an LU factorization of the
    original coefficient matrix.

    Input/output, double X[N], on input, the right hand side of the linear system.
    On output, the solution of the linear system.
*/
{
  int i;
  int ipiv;
  int j;
  int jcol;
  double piv;
  double t;

  for ( jcol = 1; jcol <= n; jcol++ )
  {
/*
  Find the maximum element in column I.
*/
    piv = fabs ( a[jcol-1+(jcol-1)*n] );
    ipiv = jcol;
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( piv < fabs ( a[i-1+(jcol-1)*n] ) )
      {
        piv = fabs ( a[i-1+(jcol-1)*n] );
        ipiv = i;
      }
    }

    if ( piv == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8GE_FS - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", jcol );
      exit ( 1 );
    }
/*
  Switch rows JCOL and IPIV, and X.
*/
    if ( jcol != ipiv )
    {
      for ( j = 1; j <= n; j++ )
      {
        t                 = a[jcol-1+(j-1)*n];
        a[jcol-1+(j-1)*n] = a[ipiv-1+(j-1)*n];
        a[ipiv-1+(j-1)*n] = t;
      }
      t         = x[jcol-1];
      x[jcol-1] = x[ipiv-1];
      x[ipiv-1] = t;
    }
/*
  Scale the pivot row.
*/
    t = a[jcol-1+(jcol-1)*n];
    a[jcol-1+(jcol-1)*n] = 1.0;
    for ( j = jcol+1; j <= n; j++ )
    {
      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;
    }
    x[jcol-1] = x[jcol-1] / t;
/*
  Use the pivot row to eliminate lower entries in that column.
*/
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( a[i-1+(jcol-1)*n] != 0.0 )
      {
        t = - a[i-1+(jcol-1)*n];
        a[i-1+(jcol-1)*n] = 0.0;
        for ( j = jcol+1; j <= n; j++ )
        {
          a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + t * a[jcol-1+(j-1)*n];
        }
        x[i-1] = x[i-1] + t * x[jcol-1];
      }
    }
  }
/*
  Back solve.
*/
  for ( jcol = n; 2 <= jcol; jcol-- )
  {
    for ( i = 1; i < jcol; i++ )
    {
      x[i-1] = x[i-1] - a[i-1+(jcol-1)*n] * x[jcol-1];
    }
  }

  return;
}
/******************************************************************************/

double *r8ge_fs_new ( int n, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_FS_NEW factors and solves an R8GE system.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The function does not save the LU factors of the matrix, and hence cannot
    be used to efficiently solve multiple linear systems, or even to
    factor A at one time, and solve a single linear system at a later time.

    The function uses partial pivoting, but no pivot vector is required.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input/output, double A[N*N].
    On input, A is the coefficient matrix of the linear system.
    On output, A is in unit upper triangular form, and
    represents the U factor of an LU factorization of the
    original coefficient matrix.

    Input, double B[N], the right hand side of the linear system.

    Output, double R8GE_FS_NEW[N], the solution of the linear system.
*/
{
  int i;
  int ipiv;
  int j;
  int jcol;
  double piv;
  double t;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    x[i] = b[i];
  }

  for ( jcol = 1; jcol <= n; jcol++ )
  {
/*
  Find the maximum element in column I.
*/
    piv = fabs ( a[jcol-1+(jcol-1)*n] );
    ipiv = jcol;
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( piv < fabs ( a[i-1+(jcol-1)*n] ) )
      {
        piv = fabs ( a[i-1+(jcol-1)*n] );
        ipiv = i;
      }
    }

    if ( piv == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8GE_FS_NEW - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", jcol );
      exit ( 1 );
    }
/*
  Switch rows JCOL and IPIV, and X.
*/
    if ( jcol != ipiv )
    {
      for ( j = 1; j <= n; j++ )
      {
        t                 = a[jcol-1+(j-1)*n];
        a[jcol-1+(j-1)*n] = a[ipiv-1+(j-1)*n];
        a[ipiv-1+(j-1)*n] = t;
      }
      t         = x[jcol-1];
      x[jcol-1] = x[ipiv-1];
      x[ipiv-1] = t;
    }
/*
  Scale the pivot row.
*/
    t = a[jcol-1+(jcol-1)*n];
    a[jcol-1+(jcol-1)*n] = 1.0;
    for ( j = jcol+1; j <= n; j++ )
    {
      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;
    }
    x[jcol-1] = x[jcol-1] / t;
/*
  Use the pivot row to eliminate lower entries in that column.
*/
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( a[i-1+(jcol-1)*n] != 0.0 )
      {
        t = - a[i-1+(jcol-1)*n];
        a[i-1+(jcol-1)*n] = 0.0;
        for ( j = jcol+1; j <= n; j++ )
        {
          a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + t * a[jcol-1+(j-1)*n];
        }
        x[i-1] = x[i-1] + t * x[jcol-1];
      }
    }
  }
/*
  Back solve.
*/
  for ( jcol = n; 2 <= jcol; jcol-- )
  {
    for ( i = 1; i < jcol; i++ )
    {
      x[i-1] = x[i-1] - a[i-1+(jcol-1)*n] * x[jcol-1];
    }
  }

  return x;
}
/******************************************************************************/

void r8ge_fss ( int n, double a[], int nb, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_FSS factors and solves a system with multiple right hand sides.

  Discussion:

    This routine uses partial pivoting, but no pivot vector is required.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input/output, double A[N*N].
    On input, A is the coefficient matrix of the linear system.
    On output, A is in unit upper triangular form, and
    represents the U factor of an LU factorization of the
    original coefficient matrix.
    Input, int NB, the number of right hand sides.

    Input/output, double X[N*NB], on input, the right hand sides of the
    linear systems.  On output, the solutions of the linear systems.
*/
{
  int i;
  int ipiv;
  int j;
  int jcol;
  double piv;
  double t;

  for ( jcol = 1; jcol <= n; jcol++ )
  {
/*
  Find the maximum element in column I.
*/
    piv = fabs ( a[jcol-1+(jcol-1)*n] );
    ipiv = jcol;
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( piv < fabs ( a[i-1+(jcol-1)*n] ) )
      {
        piv = fabs ( a[i-1+(jcol-1)*n] );
        ipiv = i;
      }
    }

    if ( piv == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8GE_FSS - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", jcol );
      exit ( 1 );
    }
/*
  Switch rows JCOL and IPIV, and X.
*/
    if ( jcol != ipiv )
    {
      for ( j = 1; j <= n; j++ )
      {
        t                 = a[jcol-1+(j-1)*n];
        a[jcol-1+(j-1)*n] = a[ipiv-1+(j-1)*n];
        a[ipiv-1+(j-1)*n] = t;
      }
      for ( j = 0; j < nb; j++ )
      {
        t            = x[jcol-1+j*n];
        x[jcol-1+j*n] = x[ipiv-1+j*n];
        x[ipiv-1+j*n] = t;
      }
    }
/*
  Scale the pivot row.
*/
    t = a[jcol-1+(jcol-1)*n];
    a[jcol-1+(jcol-1)*n] = 1.0;
    for ( j = jcol+1; j <= n; j++ )
    {
      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;
    }
    for ( j = 0; j < nb; j++ )
    {
      x[jcol-1+j*n] = x[jcol-1+j*n] / t;
    }
/*
  Use the pivot row to eliminate lower entries in that column.
*/
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( a[i-1+(jcol-1)*n] != 0.0 )
      {
        t = - a[i-1+(jcol-1)*n];
        a[i-1+(jcol-1)*n] = 0.0;
        for ( j = jcol+1; j <= n; j++ )
        {
          a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + t * a[jcol-1+(j-1)*n];
        }
        for ( j = 0; j < nb; j++ )
        {
          x[i-1+j*n] = x[i-1+j*n] + t * x[jcol-1+j*n];
        }
      }
    }
  }
/*
  Back solve.
*/
  for ( jcol = n; 2 <= jcol; jcol-- )
  {
    for ( i = 1; i < jcol; i++ )
    {
      for ( j = 0; j < nb; j++ )
      {
        x[i-1+j*n] = x[i-1+j*n] - a[i-1+(jcol-1)*n] * x[jcol-1+j*n];
      }
    }
  }

  return;
}
/******************************************************************************/

double *r8ge_fss_new ( int n, double a[], int nb, double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_FSS_NEW factors and solves a system with multiple right hand sides.

  Discussion:

    This routine uses partial pivoting, but no pivot vector is required.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input/output, double A[N*N].
    On input, A is the coefficient matrix of the linear system.
    On output, A is in unit upper triangular form, and
    represents the U factor of an LU factorization of the
    original coefficient matrix.

    Input, int NB, the number of right hand sides.

    Input, double B[N*NB], the right hand sides of the linear systems.

    Output, double R8GE_FSS_NEW[N*NB], the solutions of the linear systems.
*/
{
  int i;
  int ipiv;
  int j;
  int jcol;
  double piv;
  double t;
  double *x;

  x = ( double * ) malloc ( n * nb * sizeof ( double ) );

  for ( j = 0; j < nb; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i+j*n] = b[i+j*n];
    }
  }
  for ( jcol = 1; jcol <= n; jcol++ )
  {
/*
  Find the maximum element in column I.
*/
    piv = fabs ( a[jcol-1+(jcol-1)*n] );
    ipiv = jcol;
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( piv < fabs ( a[i-1+(jcol-1)*n] ) )
      {
        piv = fabs ( a[i-1+(jcol-1)*n] );
        ipiv = i;
      }
    }

    if ( piv == 0.0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "R8GE_FSS_NEW - Fatal error!\n" );
      fprintf ( stderr, "  Zero pivot on step %d\n", jcol );
      exit ( 1 );
    }
/*
  Switch rows JCOL and IPIV, and X.
*/
    if ( jcol != ipiv )
    {
      for ( j = 1; j <= n; j++ )
      {
        t                 = a[jcol-1+(j-1)*n];
        a[jcol-1+(j-1)*n] = a[ipiv-1+(j-1)*n];
        a[ipiv-1+(j-1)*n] = t;
      }
      for ( j = 0; j < nb; j++ )
      {
        t            = x[jcol-1+j*n];
        x[jcol-1+j*n] = x[ipiv-1+j*n];
        x[ipiv-1+j*n] = t;
      }
    }
/*
  Scale the pivot row.
*/
    t = a[jcol-1+(jcol-1)*n];
    a[jcol-1+(jcol-1)*n] = 1.0;
    for ( j = jcol+1; j <= n; j++ )
    {
      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;
    }
    for ( j = 0; j < nb; j++ )
    {
      x[jcol-1+j*n] = x[jcol-1+j*n] / t;
    }
/*
  Use the pivot row to eliminate lower entries in that column.
*/
    for ( i = jcol+1; i <= n; i++ )
    {
      if ( a[i-1+(jcol-1)*n] != 0.0 )
      {
        t = - a[i-1+(jcol-1)*n];
        a[i-1+(jcol-1)*n] = 0.0;
        for ( j = jcol+1; j <= n; j++ )
        {
          a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + t * a[jcol-1+(j-1)*n];
        }
        for ( j = 0; j < nb; j++ )
        {
          x[i-1+j*n] = x[i-1+j*n] + t * x[jcol-1+j*n];
        }
      }
    }
  }
/*
  Back solve.
*/
  for ( jcol = n; 2 <= jcol; jcol-- )
  {
    for ( i = 1; i < jcol; i++ )
    {
      for ( j = 0; j < nb; j++ )
      {
        x[i-1+j*n] = x[i-1+j*n] - a[i-1+(jcol-1)*n] * x[jcol-1+j*n];
      }
    }
  }

  return x;
}
/******************************************************************************/

double *r8ge_hilbert ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8GE_HILBERT returns the Hilbert matrix.

  Formula:

    A(I,J) = 1 / ( I + J - 1 )

  Example:

    N = 5

    1/1 1/2 1/3 1/4 1/5
    1/2 1/3 1/4 1/5 1/6
    1/3 1/4 1/5 1/6 1/7
    1/4 1/5 1/6 1/7 1/8
    1/5 1/6 1/7 1/8 1/9

  Properties:

    A is a Hankel matrix: constant along anti-diagonals.

    A is positive definite.

    A is symmetric: A' = A.

    Because A is symmetric, it is normal.

    Because A is normal, it is diagonalizable.

    A is totally positive.

    A is a Cauchy matrix.

    A is nonsingular.

    A is very ill-conditioned.

    The entries of the inverse of A are all integers.

    The sum of the entries of the inverse of A is N*N.

    The ratio of the absolute values of the maximum and minimum
    eigenvalues is roughly EXP(3.5*N).

    The determinant of the Hilbert matrix of order 10 is
    2.16417... * 10^(-53).

    If the (1,1) entry of the 5 by 5 Hilbert matrix is changed
    from 1 to 24/25, the matrix is exactly singular.  And there
    is a similar rule for larger Hilbert matrices.

    The family of matrices is nested as a function of N.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 October 2010

  Author:

    John Burkardt

  Reference:

    MD Choi,
    Tricks or treats with the Hilbert matrix,
    American Mathematical Monthly,
    Volume 90, 1983, pages 301-312.

    Robert Gregory, David Karney,
    A Collection of Matrices for Testing Computational Algorithms,
    Wiley, 1969,
    ISBN: 0882756494,
    LC: QA263.68

    Nicholas Higham,
    Accuracy and Stability of Numerical Algorithms,
    Society for Industrial and Applied Mathematics, Philadelphia, PA,
    USA, 1996; section 26.1.

    Donald Knuth,
    The Art of Computer Programming,
    Volume 1, Fundamental Algorithms, Second Edition
    Addison-Wesley, Reading, Massachusetts, 1973, page 37.

    Morris Newman, John Todd,
    Example A13,
    The evaluation of matrix inversion programs,
    Journal of the Society for Industrial and Applied Mathematics,
    Volume 6, 1958, pages 466-476.

    Joan Westlake,
    A Handbook of Numerical Matrix Inversion and Solution of 
    Linear Equations,
    John Wiley, 1968,
    ISBN13: 978-0471936756,
    LC: QA263.W47.

  Parameters:

    Input, int M, N, the order of the matrix.

    Output, double R8GE_HILBERT[M*N], the matrix.
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
      a[i+j*m] = 1.0 / ( double ) ( i + j + 1 );
    }
  }
  return a;
}
/******************************************************************************/

double *r8ge_hilbert_inverse ( int n )

/******************************************************************************/
/*
  Purpose:

    R8GE_HILBERT_INVERSE returns the inverse of the Hilbert matrix.

  Formula:

    A(I,J) =  (-1)**(I+J) * (N+I-1)! * (N+J-1)! /
           [ (I+J-1) * ((I-1)!*(J-1)!)**2 * (N-I)! * (N-J)! ]

  Example:

    N = 5

       25    -300     1050    -1400     630
     -300    4800   -18900    26880  -12600
     1050  -18900    79380  -117600   56700
    -1400   26880  -117600   179200  -88200
      630  -12600    56700   -88200   44100

  Properties:

    A is symmetric.

    Because A is symmetric, it is normal, so diagonalizable.

    A is almost impossible to compute accurately by general routines
    that compute the inverse.

    A is integral.

    The sum of the entries of A is N**2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of A.

    Output, double R8GE_HILBERT_INVERSE[N*N], the inverse Hilbert matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( n * n * sizeof ( double ) );
/*
  Set the (1,1) entry.
*/
  a[0+0*n] = ( double ) ( n * n );
/*
  Define Row 1, Column J by recursion on Row 1 Column J-1
*/
  i = 1;

  for ( j = 2; j <= n; j++ )
  {
    a[i-1+(j-1)*n] = -a[i-1+(j-2)*n] 
      * ( double ) ( ( n + j - 1 ) * ( i + j - 2 ) * ( n + 1 - j ) ) 
      / ( double ) ( ( i + j - 1 ) * ( j - 1 ) * ( j - 1 ) );
  }
/*
  Define Row I by recursion on row I-1
*/
  for ( i = 2; i <= n; i++ )
  {
    for (  j = 1; j <= n; j++ )
    {
      a[i-1+(j-1)*n] = -a[i-2+(j-1)*n] 
        * ( double ) ( ( n + i - 1 ) * ( i + j - 2 ) * ( n + 1 - i ) ) 
        / ( double ) ( ( i + j - 1 ) * ( i - 1 ) * ( i - 1 ) );
    }
  }

  return a;
}
/******************************************************************************/

double *r8ge_identity ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8GE_IDENTITY sets an R8GE matrix to the identity.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of A.

    Output, double R8GE_IDENTITY[M*N], the identity matrix.
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
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }

  return a;
}
/******************************************************************************/

void r8ge_ilu ( int m, int n, double a[], double l[], double u[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_ILU produces the incomplete LU factors of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The incomplete LU factors of the M by N matrix A are:

      L, an M by M unit lower triangular matrix,
      U, an M by N upper triangular matrix

    with the property that L and U are computed in the same way as
    the usual LU factors, except that, whenever an off diagonal element
    of the original matrix is zero, then the corresponding value of
    U is forced to be zero.

    This condition means that it is no longer the case that A = L*U.

    On the other hand, L and U will have a simple sparsity structure
    related to that of A.  The incomplete LU factorization is generally
    used as a preconditioner in iterative schemes applied to sparse
    matrices.  It is presented here merely for illustration.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, double A[M*N], the R8GE matrix.

    Output, double L[M*M], the M by M unit lower triangular factor.

    Output, double U[M*N], the M by N upper triangular factor.
*/
{
  int i;
  int j;
  int jhi;
  int k;
/*
  Initialize:

    L := M by M Identity
    U := A
*/
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( i == j )
      {
        l[i+j*m] = 1.0;
      }
      else
      {
        l[i+j*m] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      u[i+j*m] = a[i+j*m];
    }
  }

  jhi = i4_min ( m - 1, n );

  for ( j = 0; j < jhi; j++ )
  {
/*
  Zero out the entries in column J, from row J+1 to M.
*/
    for ( i = j+1; i < m; i++ )
    {
      if ( u[i+j*m] != 0.0 )
      {
        l[i+j*m] = u[i+j*m] / u[j+j*m];
        u[i+j*m] = 0.0;

        for ( k = j + 1; k < n; k++ )
        {
          if ( u[i+k*m] != 0.0 )
          {
            u[i+k*m] = u[i+k*m] - l[i+j*m] * u[j+k*m];
          }
        }
      }
    }
  }

  return;
}
/******************************************************************************/

double *r8ge_indicator ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8GE_INDICATOR sets up an R8GE indicator matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Output, double R8GE_INDICATOR[M*N], the R8GE matrix.
*/
{
  double *a;
  int fac;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= m; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      a[i-1+(j-1)*m] = ( double ) ( fac * i + j );
    }
  }

  return a;
}
/******************************************************************************/

double *r8ge_inverse ( int n, double a[], int pivot[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_INVERSE computes the inverse of an R8GE matrix factored by R8GE_FA.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_INVERSE is a simplified standalone version of the LINPACK routine
    SGEDI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix A.

    Input, double A[N*N], the factor information computed by R8GE_FA.

    Input, int PIVOT[N], the pivot vector from R8GE_FA.

    Output, double R8GE_INVERSE[N*N], the inverse matrix.
*/
{
  double *b;
  int i;
  int j;
  int k;
  double temp;

  b = ( double * ) malloc ( n * n * sizeof ( double ) );
/*
  Compute Inverse(U).
*/
  for ( k = 1; k <= n; k++ )
  {
    for ( i = 1; i <= k-1; i++ )
    {
      b[i-1+(k-1)*n] = -b[i-1+(k-1)*n] / a[k-1+(k-1)*n];
    }
    b[k-1+(k-1)*n] = 1.0 / a[k-1+(k-1)*n];

    for ( j = k+1; j <= n; j++ )
    {
      b[k-1+(j-1)*n] = 0.0;
      for ( i = 1; i <= k; i++ )
      {
        b[i-1+(j-1)*n] = b[i-1+(j-1)*n] + b[i-1+(k-1)*n] * a[k-1+(j-1)*n];
      }
    }
  }
/*
  Multiply Inverse(U) by Inverse(L).
*/
  for ( k = n-1; 1 <= k; k-- )
  {
    for ( i = k+1; i <= n; i++ )
    {
      b[i-1+(k-1)*n] = 0.0;
    }

    for ( j = k+1; j <= n; j++ )
    {
      for ( i = 1; i <= n; i++ )
      {
        b[i-1+(k-1)*n] = b[i-1+(k-1)*n] + b[i-1+(j-1)*n] * a[j-1+(k-1)*n];
      }
    }

    if ( pivot[k-1] != k )
    {
      for ( i = 1; i <= n; i++ )
      {
        temp = b[i-1+(k-1)*n];
        b[i-1+(k-1)*n] = b[i-1+(pivot[k-1]-1)*n];
        b[i-1+(pivot[k-1]-1)*n] = temp;
      }

    }

  }

  return b;
}
/******************************************************************************/

double *r8ge_ml ( int n, double a_lu[], int pivot[], double x[], int job )

/******************************************************************************/
/*
  Purpose:

    R8GE_ML computes A * x or A' * x, using R8GE_FA factors.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    It is assumed that R8GE_FA has overwritten the original matrix
    information by LU factors.  R8GE_ML is able to reconstruct the
    original matrix from the LU factor data.

    R8GE_ML allows the user to check that the solution of a linear
    system is correct, without having to save an unfactored copy
    of the matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A_LU[N*N], the LU factors from R8GE_FA.

    Input, int PIVOT[N], the pivot vector computed by R8GE_FA.

    Input, double X[N], the vector to be multiplied.

    Input, int JOB, specifies the operation to be done:
    JOB = 0, compute A * x.
    JOB nonzero, compute A' * X.

    Output, double R8GE_ML[N], the result of the multiplication.
*/
{
  double *b;
  int i;
  int j;
  int k;
  double temp;

  b = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    b[i] = x[i];
  }

  if ( job == 0 )
  {
/*
  Y = U * X.
*/
    for ( j = 1; j <= n; j++ )
    {
      for ( i = 1; i <= j-1; i++ )
      {
        b[i-1] = b[i-1] + a_lu[i-1+(j-1)*n] * b[j-1];
      }
      b[j-1] = a_lu[j-1+(j-1)*n] * b[j-1];
    }
/*
  B = PL * Y = PL * U * X = A * x.
*/
    for ( j = n-1; 1 <= j; j-- )
    {
      for ( i = j+1; i <= n; i++ )
      {
        b[i-1] = b[i-1] - a_lu[i-1+(j-1)*n] * b[j-1];
      }

      k = pivot[j-1];

      if ( k != j )
      {
        temp   = b[k-1];
        b[k-1] = b[j-1];
        b[j-1] = temp;
      }
    }
  }
  else
  {
/*
  Y = (PL)' * X:
*/
    for ( j = 1; j <= n-1; j++ )
    {
      k = pivot[j-1];

      if ( k != j )
      {
        temp   = b[k-1];
        b[k-1] = b[j-1];
        b[j-1] = temp;
      }

      temp = 0.0;
      for ( i = j+1; i <= n; i++ )
      {
        temp = temp + b[i-1] * a_lu[i-1+(j-1)*n];
      }
      b[j-1] = b[j-1] - temp;

    }
/*
  B = U' * Y = ( PL * U )' * X = A' * X.
*/
    for ( i = n; 1 <= i; i-- )
    {
      for ( j = i+1; j <= n; j++ )
      {
        b[j-1] = b[j-1] + b[i-1] * a_lu[i-1+(j-1)*n];
      }
      b[i-1] = b[i-1] * a_lu[i-1+(i-1)*n];
    }

  }

  return b;
}
/******************************************************************************/

double *r8ge_mu ( int m, int n, double a_lu[], char trans, int pivot[], 
  double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_MU computes A * x or A' * x, using R8GE_TRF factors.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    It is assumed that R8GE_TRF has overwritten the original matrix
    information by PLU factors.  R8GE_MU is able to reconstruct the
    original matrix from the PLU factor data.

    R8GE_MU allows the user to check that the solution of a linear
    system is correct, without having to save an unfactored copy
    of the matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Reference:

    Edward Anderson, Zhaojun Bai, Christian Bischof, Susan Blackford, 
    James Demmel, Jack Dongarra, Jeremy Du Croz, Anne Greenbaum, 
    Sven Hammarling, Alan McKenney, Danny Sorensen,
    LAPACK User's Guide,
    Second Edition,
    SIAM, 1995.

  Parameters:

    Input, int M, the number of rows in the matrix.

    Input, int N, the number of columns in the matrix.

    Input, double A_LU[M*N], the LU factors from R8GE_TRF.

    Input, char TRANS, specifies the form of the system of equations:
    'N':  A * x = b  (No transpose)
    'T':  A'* X = B  (Transpose)
    'C':  A'* X = B  (Conjugate transpose = Transpose)

    Input, int PIVOT[*], the pivot vector computed by R8GE_TRF.

    Input, double X[*], the vector to be multiplied.
    For the untransposed case, X should have N entries.
    For the transposed case, X should have M entries.

    Output, double R8GE_MU[*], the result of the multiplication.
    For the untransposed case, the result should have M entries.
    For the transposed case, the result should have N entries.
*/
{
  double *b;
  int i;
  int j;
  int k;
  int mn_max;
  int npiv;
  double temp;
  double *y;

  npiv = i4_min ( m - 1, n );
  mn_max = i4_max ( m, n );
  y = ( double * ) malloc ( mn_max * sizeof ( double ) );

  if ( trans == 'n' || trans == 'N' )
  {
    b = ( double * ) malloc ( m * sizeof ( double ) );
/*
  Y[MN] = U[MNxN] * X[N].
*/
    for ( i = 0; i < n; i++ )
    {
      y[i] = 0.0;
    }

    for ( j = 1; j <= n; j++ )
    {
      for ( i = 1; i <= i4_min ( j, m ); i++ )
      {
        y[i-1] = y[i-1] + a_lu[i-1+(j-1)*m] * x[j-1];
      }
    }
/*
  Z[M] = L[MxMN] * Y[MN] = L[MxMN] * U[MNxN] * X[N].
*/
    for ( i = 0; i < m; i++ )
    {
      if ( i < n ) 
      {
        b[i] = y[i];
      }
      else
      {
        b[i] = 0.0;
      }
    }

    for ( j = i4_min ( m-1, n ); 1 <= j; j-- )
    {
      for ( i = j+1; i <= m; i++ )
      {
        b[i-1] = b[i-1] + a_lu[i-1+(j-1)*m] * y[j-1];
      }
    }
/*
  B = P * Z = P * L * Y = P * L * U * X = A * x.
*/
    for ( j = npiv; 1 <= j; j-- )
    {
      k = pivot[j-1];

      if ( k != j )
      {
        temp = b[k-1];
        b[k-1] = b[j-1];
        b[j-1] = temp;
      }
    }
  }
  else if ( trans == 't' || trans == 'T' ||
            trans == 'c' || trans == 'C' )
  {
    b = ( double * ) malloc ( n * sizeof ( double ) );
/*
  Y = P' * X:
*/
    for ( i = 1; i <= npiv; i++ )
    {
      k = pivot[i-1];

      if ( k != i )
      {
        temp = x[k-1];
        x[k-1] = x[i-1];
        x[i-1] = temp;
      }
    }

    for ( i = 0; i < n; i++ )
    {
      if ( i < m ) 
      {
        b[i] = x[i];
      }
      else
      {
        b[i] = 0.0;
      }
    }
/*
  Z = L' * Y:
*/
    for ( j = 1; j <= i4_min ( m - 1, n ); j++ )
    {
      for ( i = j+1; i <= m; i++ )
      {
        b[j-1] = b[j-1] + x[i-1] * a_lu[i-1+(j-1)*m];
      }
    }
/*
  B = U' * Z.
*/
    for ( i = m; 1 <= i; i-- )
    {
      for ( j = i+1; j <= n; j++ )
      {
        b[j-1] = b[j-1] + b[i-1] * a_lu[i-1+(j-1)*m];
      }
      if ( i <= n )
      {
        b[i-1] = b[i-1] * a_lu[i-1+(i-1)*m];
      }
    }
/*
  Now restore X.
*/
    for ( i = npiv; 1 <= i; i-- )
    {
      k = pivot[i-1];

      if ( k != i )
      {
        temp = x[k-1];
        x[k-1] = x[i-1];
        x[i-1] = temp;
      }
    }
  }
/*
  Illegal value of TRANS.
*/
  else
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8GE_MU - Fatal error!\n" );
    fprintf ( stderr, "  Illegal value of TRANS = \"%c\"\n", trans );
    exit ( 1 );
  }

  free ( y );

  return b;
}
/******************************************************************************/

double *r8ge_mm ( int n1, int n2, int n3, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_MM multiplies two R8GE matrices.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2016

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, the order of the matrices.

    Input, double A[N1*N2], B[N2*N3], the factors.

    Output, double C[N1*N3], the product.
*/
{
  double *c;
  int i;
  int j;
  int k;

  c = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[k+j*n2];
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8ge_mtm ( int n1, int n2, int n3, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_MTM computes C=A'*B for R8GE matrices.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2016

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, the order of the matrices.

    Input, double A[N2*N1], B[N2*N3], the factors.

    Output, double C[N1*N3], the product.
*/
{
  double *c;
  int i;
  int j;
  int k;

  c = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[k+i*n2] * b[k+j*n2];
      }
    }
  }

  return c;
}
/******************************************************************************/

double *r8ge_mtv ( int m, int n, double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_MTV multiplies a vector times an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8GE matrix.

    Input, double X[M], the vector to be multiplied by A.

    Output, double R8GE_MTV[N], the product A' * x.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    b[i] = 0.0;
    for ( j = 0; j < m; j++ )
    {
      b[i] = b[i] + a[j+i*m] * x[j];
    }
  }

  return b;
}
/******************************************************************************/

double *r8ge_mv ( int m, int n, double a[], double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_MV multiplies an R8GE matrix times a vector.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8GE matrix.

    Input, double X[N], the vector to be multiplied by A.

    Output, double R8GE_MV[M], the product A * x.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( m * sizeof ( double ) );

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
    for ( j = 0; j < n; j++ )
    {
      b[i] = b[i] + a[i+j*m] * x[j];
    }
  }

  return b;
}
/******************************************************************************/

double r8ge_np_det ( int n, double a_lu[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_DET computes the determinant of a matrix factored by R8GE_NP_FA.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A_LU[N*N], the LU factors from R8GE_NP_FA.

    Output, double R8GE_NP_DET, the determinant of the matrix.
*/
{
  double det;
  int i;

  det = 1.0;
  for ( i = 0; i < n; i++ )
  {
    det = det * a_lu[i+i*n];
  }

  return det;
}
/******************************************************************************/

int r8ge_np_fa ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_FA factors an R8GE matrix by nonpivoting Gaussian elimination.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_NP_FA is a version of the LINPACK routine SGEFA, but uses no
    pivoting.  It will fail if the matrix is singular, or if any zero
    pivot is encountered.

    If R8GE_NP_FA successfully factors the matrix, R8GE_NP_SL may be called
    to solve linear systems involving the matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input/output, double A[N*N].
    On input, A contains the matrix to be factored.
    On output, A contains information about the factorization,
    which must be passed unchanged to R8GE_NP_SL for solutions.

    Output, int R8GE_NP_FA, singularity flag.
    0, no singularity detected.
    nonzero, the factorization failed on the INFO-th step.
*/
{
  int i;
  int j;
  int k;

  for ( k = 1; k <= n-1; k++ )
  {
    if ( a[k-1+(k-1)*n] == 0.0 )
    {
      return k;
    }

    for ( i = k+1; i <= n; i++ )
    {
      a[i-1+(k-1)*n] = -a[i-1+(k-1)*n] / a[k-1+(k-1)*n];
    }

    for ( j = k+1; j <= n; j++ )
    {
      for ( i = k+1; i <= n; i++ )
      {
        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + a[i-1+(k-1)*n] * a[k-1+(j-1)*n];
      }
    }
  }

  if ( a[n-1+(n-1)*n] == 0.0 )
  {
    return n;
  }

  return 0;
}
/******************************************************************************/

double *r8ge_np_inverse ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_INVERSE computes the inverse of a matrix factored by R8GE_NP_FA.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix A.

    Input, double A[N*N], the factor information computed by R8GE_NP_FA.

    Output, double R8GE_NP_INVERSE[N*N], the inverse matrix.
*/
{
  double *b;
  int i;
  int j;
  int k;
  double temp;
  double *work;

  b = ( double * ) malloc ( n * n * sizeof ( double ) );
  work = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      b[i+j*n] = a[i+j*n];
    }
  }
/*
  Compute Inverse(U).
*/
  for ( k = 1; k <= n; k++ )
  {
    b[k-1+(k-1)*n] = 1.0 / b[k-1+(k-1)*n];
    for ( i = 1; i <= k-1; i++ )
    {
      b[i-1+(k-1)*n] = -b[i-1+(k-1)*n] * b[k-1+(k-1)*n];
    }
    for ( j = k+1; j <= n; j++ )
    {
      temp = b[k-1+(j-1)*n];
      b[k-1+(j-1)*n] = 0.0;
      for ( i = 1; i <= k; i++ )
      {
        b[i-1+(j-1)*n] = b[i-1+(j-1)*n] + temp * b[i-1+(k-1)*n];
      }
    }
  }
/*
  Form Inverse(U) * Inverse(L).
*/
  for ( k = n-1; 1 <= k; k-- )
  {
    for ( i = k+1; i <= n; i++ )
    {
      work[i-1] = b[i-1+(k-1)*n];
      b[i-1+(k-1)*n] = 0.0;
    }

    for ( j = k+1; j <= n; j++ )
    {
      for ( i = 1; i <= n; i++ )
      {
        b[i-1+(k-1)*n] = b[i-1+(k-1)*n] + b[i-1+(j-1)*n] * work[j-1];
      }
    }
  }

  free ( work );

  return b;
}
/******************************************************************************/

double *r8ge_np_ml ( int n, double a_lu[], double x[], int job )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_ML computes A * x or x * A, for a matrix factored by R8GE_NP_FA.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The matrix A is assumed to have been factored by R8GE_NP_FA.

    R8GE_NP_ML allows the user to check that the solution of a linear
    system is correct, without having to save an unfactored copy
    of the matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A_LU[N*N], the LU factors from R8GE_NP_FA.

    Input, double X[N], the vector to be multiplied.

    Input, int JOB, determines the multiplication to
    be carried out:
    JOB = 0, compute A * x.
    JOB nonzero, compute A' * X.

    Output, double R8GE_NP_ML[N], the result of the multiplication.
*/
{
  double *b;
  int i;
  int j;
  double t;

  b = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    b[i] = x[i];
  }

  if ( job == 0 )
  {
/*
  Compute U * X = Y:
*/
    for ( i = 0; i < n; i++ )
    {
      t = 0.0;
      for ( j = i; j < n; j++ )
      {
        t = t + a_lu[i+j*n] * b[j];
      }
      b[i] = t;
    }
/*
  Compute L * Y = B:
*/
    for ( j = n-2; 0 <= j; j-- )
    {
      for ( i = j+1; i < n; i++ )
      {
        b[i] = b[i] - a_lu[i+j*n] * b[j];
      }
    }
  }
  else
  {
/*
  Compute L' * X = Y:
*/
    for ( j = 0; j < n-1; j++ )
    {
      for ( i = j+1; i < n; i++ )
      {
        b[j] = b[j] - b[i] * a_lu[i+j*n];
      }
    }
/*
  Compute U' * Y = B:
*/
    for ( j = n-1; 0 <= j; j-- )
    {
      b[j] = b[j] * a_lu[j+j*n];
      for ( i = 0; i < j; i++ )
      {
        b[j] = b[j] + b[i] * a_lu[i+j*n];
      }
    }
  }

  return b;
}
/******************************************************************************/

double *r8ge_np_sl ( int n, double a_lu[], double b[], int job )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_SL solves a system factored by R8GE_NP_FA.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A_LU[N*N], the LU factors from R8GE_NP_FA.

    Input, double B[N], the right hand side.

    Input, int JOB.
    If JOB is zero, the routine will solve A * x = b.
    If JOB is nonzero, the routine will solve A' * x = b.

    Output, double R8GE_NP_SL[N], the solution.
*/
{
  int i;
  int k;
  double *x;
/*
  Solve A * x = b.
*/
  x = ( double * ) malloc ( n * sizeof ( double ) );
  for ( i = 0; i < n; i++ )
  {
    x[i] = b[i];
  }

  if ( job == 0 )
  {
    for ( k = 0; k < n-1; k++ )
    {
      for ( i = k+1; i < n; i++ )
      {
        x[i] = x[i] + a_lu[i+k*n] * x[k];
      }
    }

    for ( k = n-1; 0 <= k; k-- )
    {
      x[k] = x[k] / a_lu[k+k*n];
      for ( i = 0; i <= k-1; i++ )
      {
        x[i] = x[i] - a_lu[i+k*n] * x[k];
      }
    }
  }
/*
  Solve A' * X = B.
*/
  else
  {
    for ( k = 0; k < n; k++ )
    {
      for ( i = 0; i <= k-1; i++ )
      {
        x[k] = x[k] - x[i] * a_lu[i+k*n];
      }
      x[k] = x[k] / a_lu[k+k*n];
    }

    for ( k = n-2; 0 <= k; k-- )
    {
      for ( i = k+1; i < n; i++ )
      {
        x[k] = x[k] + x[i] * a_lu[i+k*n];
      }
    }

  }

  return x;
}
/******************************************************************************/

int r8ge_np_trf ( int m, int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_TRF computes the LU factorization of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_NP_TRF is a nonpivoting version of R8GE_TRF, and will fail if
    a zero element is encountered along the diagonal.

    The factorization has the form
      A = L * U
    where L is lower triangular with unit diagonal elements (lower
    trapezoidal if N < M), and U is upper triangular (upper trapezoidal
    if M < N).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix A.  0 <= M.

    Input, int N, the number of columns of the matrix A.  0 <= N.

    Input/output, double A[M*N].
    On entry, the M by N matrix to be factored.
    On exit, the factors L and U from the factorization
    A = L*U; the unit diagonal elements of L are not stored.

    Output, int R8GE_NP_TRF.
    = 0: successful exit
    = -K, the K-th argument had an illegal value
    = K, U(K,K) is exactly zero. The factorization
         has been completed, but the factor U is exactly
         singular, and division by zero will occur if it is used
         to solve a system of equations.
*/
{
  int i;
  int ii;
  int info;
  int j;
/*
  Test the input parameters.
*/
  info = 0;

  if ( m < 0 )
  {
    return (-1);
  }
  else if ( n < 0 )
  {
    return (-2);
  }

  if ( m == 0 || n == 0 )
  {
    return 0;
  }

  for ( j = 1; j <= i4_min ( m, n ); j++ )
  {
/*
  Compute elements J+1:M of the J-th column.
*/
    if ( a[j-1+(j-1)*m] != 0.0 )
    {
      for ( i = j+1; i <= m; i++ )
      {
        a[i-1+(j-1)*m] = a[i-1+(j-1)*m] / a[j-1+(j-1)*m];
      }
    }
    else if ( info == 0 )
    {
      info = j;
    }
/*
  Update the trailing submatrix.
*/
    if ( j < i4_min ( m, n ) )
    {
      for ( ii = j+1; ii <= m; ii++ )
      {
        for ( i = j+1; i <= n; i++ )
        {
          a[ii-1+(i-1)*m] = a[ii-1+(i-1)*m] - a[ii-1+(j-1)*m] * a[j-1+(i-1)*m];
        }
      }
    }
  }

  return info;
}
/******************************************************************************/

double *r8ge_np_trm ( int m, int n, double a[], double x[], int job )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_TRM computes A * x or A' * x, for a matrix factored by R8GE_NP_TRF.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The matrix A is assumed to have been factored by R8GE_NP_TRF.

    R8GE_NP_TRM allows the user to check that the solution of a linear
    system is correct, without having to save an unfactored copy
    of the matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Reference:

    Edward Anderson, Zhaojun Bai, Christian Bischof, Susan Blackford, 
    James Demmel, Jack Dongarra, Jeremy Du Croz, Anne Greenbaum, 
    Sven Hammarling, Alan McKenney, Danny Sorensen,
    LAPACK User's Guide,
    Second Edition,
    SIAM, 1995.

  Parameters:

    Input, int M, N, the number of rows and columns in the matrix.
    M and N must be positive.

    Input, double A[M*N], the M by N matrix factors computed by R8GE_NP_TRF.

    Input, double X[*], the vector to be multiplied.
    If JOB is 0, X must have dimension N.
    If JOB is nonzero, X must have dimension M.

    Input, int JOB, determines the multiplication to
    be carried out:
    JOB = 0, compute A * x.
    JOB nonzero, compute A' * X.

    Output, double R8GE_NP_TRM[*], the result of the multiplication.
    If JOB is 0, the output has dimension M.
    If JOB is nonzero, the output has dimension N.
*/
{
  double *b;
  int i;
  int j;
  double temp;

  if ( job == 0 )
  {
    b = ( double * ) malloc ( m * sizeof ( double ) );
    for ( i = 0; i < m; i++ )
    {
      b[i] = 0.0;
    }
/*
  Compute U * X = Y:
*/
    for ( i = 0; i < i4_min ( m, n ); i++ )
    {
      for ( j = i; j < n; j++ )
      {
        b[i] = b[i] + a[i+j*m] * x[j];
      }
    }
/*
  Compute L * Y = B:
*/
    for ( i = i4_min ( m-1, n ); 1 <= i; i-- )
    {
      for ( j = 0; j < i; j++ )
      {
        b[i] = b[i] + a[i+j*m] * b[j];
      }
    }
  }
  else
  {
    b = ( double * ) malloc ( n * sizeof ( double ) );
    for ( i = 0; i < n; i++ )
    {
      b[i] = 0.0;
    }
/*
  Compute L' * X = Y:
*/
    for ( i = 0; i < i4_min ( m, n ); i++ )
    {
      b[i] = x[i];
      for ( j = i+1; j < m; j++ )
      {
        b[i] = b[i] + a[j+i*m] * x[j];
      }
    }
/*
  Compute U' * Y = B:
*/
    for ( i = i4_min ( m, n ) - 1; 0 <= i; i-- )
    {
      temp = 0.0;
      for ( j = 0; j <= i; j++ )
      {
        temp = temp + a[j+i*m] * b[j];
      }
      b[i] = temp;
    }

  }

  return b;
}
/******************************************************************************/

double *r8ge_np_trs ( int n, int nrhs, char trans, double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_NP_TRS solves a system of linear equations factored by R8GE_NP_TRF.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_NP_TRS is a nonpivoting version of R8GE_TRS.

    R8GE_TRS solves a system of linear equations
      A * x = b  or  A' * X = B
    with a general N by N matrix A using the LU factorization computed
    by R8GE_NP_TRF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Reference:

    Edward Anderson, Zhaojun Bai, Christian Bischof, Susan Blackford, 
    James Demmel, Jack Dongarra, Jeremy Du Croz, Anne Greenbaum, 
    Sven Hammarling, Alan McKenney, Danny Sorensen,
    LAPACK User's Guide,
    Second Edition,
    SIAM, 1995.

  Parameters:

    Input, int N, the order of the matrix A.  0 <= N.

    Input, int NRHS, the number of right hand sides.  0 <= NRHS.

    Input, char TRANS, pecifies the form of the system of equations:
    'N':  A * x = b  (No transpose)
    'T':  A'* X = B  (Transpose)
    'C':  A'* X = B  (Conjugate transpose = Transpose)

    Input, double A[N*N], the factors L and U from the factorization
    A = L*U as computed by R8GE_NP_TRF.

    Input, double B[N*NRHS], the right hand side matrix B.

    Output, double R8GE_NP_TRS[N*NRHS], the solution matrix X.
*/
{
  int i;
  int j;
  int k;
  double *x;

  if ( trans != 'n' && trans != 'N' && 
       trans != 't' && trans != 'T' && 
       trans != 'c' && trans != 'C' )
  {
    return NULL;
  }
  if ( n < 0 )
  {
    return NULL;
  }
  if ( nrhs < 0 )
  {
    return NULL;
  }

  if ( n == 0 || nrhs == 0 )
  {
    return NULL;
  }

  x = ( double * ) malloc ( n * nrhs * sizeof ( double ) );

  for ( j = 0; j < nrhs; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i+j*n] = b[i+j*n];
    }
  }

  if ( trans == 'n' || trans == 'N' )
  {
/*
  Solve L * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = 1; j <= n-1; j++ )
      {
        for ( i = j+1; i <= n; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];
        }
      }
    }
/*
  Solve U * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = n; 1 <= j; j-- )
      {
        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];
        for ( i = 1; i <= j-1; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];
        }
      }
    }
  }
  else
/*
  Solve U' * x = b, overwriting b with x.
*/
  {
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = 1; j <= n; j++ )
      {
        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];
        for ( i = j+1; i <= n; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];
        }
      }
    }
/*
  Solve L' * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = n; 2 <= j; j-- )
      {
        for ( i = 1; i <= j-1; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];
        }
      }
    }
  }

  return x;
}
/******************************************************************************/

void r8ge_plu ( int m, int n, double a[], double p[], double l[], double u[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_PLU produces the PLU factors of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The PLU factors of the M by N matrix A are:

      P, an M by M permutation matrix P,
      L, an M by M unit lower triangular matrix,
      U, an M by N upper triangular matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, double A[M,N], the M by N matrix to be factored.

    Output, double P[M*M], the M by M permutation factor.

    Output, double L[M*M], the M by M unit lower triangular factor.

    Output, double U[M*N], the M by N upper triangular factor.
*/
{
  int i;
  int j;
  int k;
  int pivot_row;
  double pivot_value;
  double t;
/*
  Initialize:

    P: = M by M Identity
    L: = M by M Identity
    U: = A
*/

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      if ( i == j ) 
      {
        l[i+j*m] = 1.0;
        p[i+j*m] = 1.0;
      }
      else
      {
        l[i+j*m] = 0.0;
        p[i+j*m] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      u[i+j*m] = a[i+j*m];
    }
  }
/*
  On step J, find the pivot row and the pivot value.
*/
  for ( j = 0; j < i4_min ( m-2, n-1 ); j++ )
  {
    pivot_value = 0.0;
    pivot_row = -1;

    for ( i = j; i < m; i++ )
    {
      if ( pivot_value < fabs ( u[i+j*m] ) )
      {
        pivot_value = fabs ( u[i+j*m] );
        pivot_row = i;
      }
    }
/*
  If the pivot row is nonzero swap:
  * rows J and PIVOT_ROW of U;
  * rows J and PIVOT_ROW of L and cols J and PIVOT_ROW of L;
  * cols J and PIVOT_ROW of P.
*/
    if ( pivot_row != -1 )
    {
      for ( k = 0; k < n; k++ )
      {
        t                = u[j+k*m];
        u[j+k*m]         = u[pivot_row+k*m];
        u[pivot_row+k*m] = t;
      }

      for ( k = 0; k < m; k++ )
      {
        t                = l[j+k*m];
        l[j+k*m]         = l[pivot_row+k*m];
        l[pivot_row+k*m] = t;
      }
      for ( k = 0; k < m; k++ )
      {
        t                = l[k+j*m];
        l[k+j*m]         = l[k+pivot_row*m];
        l[k+pivot_row*m] = t;
      }

      for ( k = 0; k < m; k++ )
      {
        t                = p[k+j*m];
        p[k+j*m]         = p[k+pivot_row*m];
        p[k+pivot_row*m] = t;
      }
/*
  Zero out the entries in column J, from row J+1 to M.
*/
      for ( i = j+1; i < m; i++ )
      {
        if ( u[i+j*m] != 0.0 )
        {
          l[i+j*m] = u[i+j*m] / u[j+j*m];
          u[i+j*m] = 0.0;
          for ( k = j+1; k < n; k++ )
          {
            u[i+k*m] = u[i+k*m] - l[i+j*m] * u[j+k*m];
          }
        }
      }
    }
  }

  return;
}
/******************************************************************************/

double *r8ge_poly ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_POLY computes the characteristic polynomial of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[N*N], the R8GE matrix.

    Output, double R8GE_POLY[N+1], the coefficients of the characteristic
    polynomial of A.  P(I) contains the coefficient of X**I.
*/
{
  int i;
  int j;
  int k;
  int order;
  double *p;
  double trace;
  double *work1;
  double *work2;

  p = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  work2 = ( double * ) malloc ( n * n * sizeof ( double ) );
/*
  Initialize WORK1 to the identity matrix.
*/
  work1 = r8ge_identity ( n, n );

  p[n] = 1.0;

  for ( order = n-1; 0 <= order; order-- )
  {
/*
  Work2 = A * WORK1.
*/
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        work2[i+j*n] = 0.0;
        for ( k = 0; k < n; k++ )
        {
          work2[i+j*n] = work2[i+j*n] + a[i+k*n] * work1[k+j*n];
        }
      }
    }
/*
  Take the trace.
*/
    trace = 0.0;
    for ( i = 0; i < n; i++ )
    {
      trace = trace + work2[i+i*n];
    }
/*
  P(ORDER) = - Trace ( WORK2 ) / ( N - ORDER )
*/
    p[order] = -trace / ( double ) ( n - order );
/*
  WORK1 := WORK2 + P(ORDER) * Identity.
*/
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        work1[i+j*n] = work2[i+j*n];
      }
    }
    for ( j = 0; j < n; j++ )
    {
      work1[j+j*n] = work1[j+j*n] + p[order];
    }
  }

  free ( work1 );
  free ( work2 ) ;

  return p;
}
/******************************************************************************/

void r8ge_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8GE_PRINT prints an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8GE matrix.

    Input, char *TITLE, a title.
*/
{
  r8ge_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8ge_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8GE_PRINT_SOME prints some of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the R8GE matrix.

    Input, int ILO, JLO, IHI, JHI, designate the first row and
    column, and the last row and column to be printed.

    Input, char *TITLE, a title.
*/
{
# define INCX 5

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  printf ( "\n" );
  printf ( "%s\n", title );
/*
  Print the columns of the matrix, in strips of 5.
*/
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    printf ( "\n" );
/*
  For each column J in the current range...

  Write the header.
*/
    printf ( "  Col:    " );
    for ( j = j2lo; j <= j2hi; j++ )
    {
      printf ( "%7d       ", j );
    }
    printf ( "\n" );
    printf ( "  Row\n" );
    printf ( "  ---\n" );
/*
  Determine the range of the rows in this strip.
*/
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )
    {
/*
  Print out (up to) 5 entries in row I, that lie in the current strip.
*/
      printf ( "%5d  ", i );
      for ( j = j2lo; j <= j2hi; j++ )
      {
        printf ( "%12g  ", a[i-1+(j-1)*m] );
      }
      printf ( "\n" );
    }
  }
  return;
# undef INCX
}
/******************************************************************************/

double *r8ge_random ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8GE_RANDOM randomizes an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 November 2011

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8GE_RANDOM[M*N], the randomized M by N matrix, 
    with entries between 0 and 1.
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
      a[i+j*m] = r8_uniform_01 ( seed );
    }
  }
  return a;
}
/******************************************************************************/

double *r8ge_res ( int m, int n, double a[], double x[], double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_RES computes the residual for an R8GE system.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2016

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[M*N], the original, UNFACTORED matrix.

    Input, double X[N], an estimate of the solution the linear system.

    Input, double B[M], the right hand side vector.

    Output, double R8GE_RES[M], the residual vector: b - A * x.
*/
{
  double *r;
  int i;

  r = r8ge_mv ( m, n, a, x );

  for ( i = 0; i < m; i++ )
  {
    r[i] = r[i] - b[i];
  }

  return r;
}
/******************************************************************************/

double *r8ge_sl_it ( int n, double a[], double a_lu[], int pivot[], double b[], 
  int job, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_SL_IT applies one step of iterative refinement following R8GE_SL_NEW.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    It is assumed that:

    * the original matrix A has been factored by R8GE_FA;
    * the linear system A * x = b has been solved once by R8GE_SL_NEW.

    (Actually, it is not necessary to solve the system once using R8GE_SL_NEW.
    You may simply supply the initial estimated solution X = 0.)

    Each time this routine is called, it will compute the residual in
    the linear system, apply one step of iterative refinement, and
    add the computed correction to the current solution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A[N*N], the original, UNFACTORED R8GE matrix.

    Input, double A_LU[N*N], the LU factors from R8GE_FA.

    Input, int PIVOT[N], the pivot vector from R8GE_FA.

    Input, double B[N], the right hand side vector.

    Input, int JOB, specifies the operation.
    0, solve A*X=B.
    nonzero, solve A'*X=B.

    Input, double X[N], an estimate of the solution of A * x = b.

    Output, double R8GE_SL_IT[N], the solution after one step of 
    iterative refinement.
*/
{
  double *dx;
  int i;
  double *r;
  double *x_new;
/*
  Compute the residual vector.
*/
  r = r8ge_res ( n, n, a, x, b );
/*
  Solve A * dx = r
*/
  dx = r8ge_sl_new ( n, a_lu, pivot, r, job );
/*
  Add dx to x.
*/
  x_new = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    x_new[i] = x[i] + dx[i];
  }

  free ( r );
  free ( dx );

  return x_new;
}
/******************************************************************************/

double *r8ge_sl_new ( int n, double a_lu[], int pivot[], double b[], int job )

/******************************************************************************/
/*
  Purpose:

    R8GE_SL_NEW solves an R8GE system factored by R8GE_FA.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_SL_NEW is a simplified version of the LINPACK routine SGESL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.
    N must be positive.

    Input, double A_LU[N*N], the LU factors from R8GE_FA.

    Input, int PIVOT[N], the pivot vector from R8GE_FA.

    Input, double B[N], the right hand side vector.

    Input, int JOB, specifies the operation.
    0, solve A * x = b.
    nonzero, solve A' * x = b.

    Output, double R8GE_SL_NEW[N], the solution vector.
*/
{
  int i;
  int k;
  int l;
  double t;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    x[i] = b[i];
  }
/*
  Solve A * x = b.
*/
  if ( job == 0 )
  {
/*
  Solve PL * Y = B.
*/
    for ( k = 1; k <= n-1; k++ )
    {
      l = pivot[k-1];

      if ( l != k )
      {
        t      = x[l-1];
        x[l-1] = x[k-1];
        x[k-1] = t;
      }
      for ( i = k+1; i <= n; i++ )
      {
        x[i-1] = x[i-1] + a_lu[i-1+(k-1)*n] * x[k-1];
      }
    }
/*
  Solve U * X = Y.
*/
    for ( k = n; 1 <= k; k-- )
    {
      x[k-1] = x[k-1] / a_lu[k-1+(k-1)*n];
      for ( i = 1; i <= k-1; i++ )
      {
        x[i-1] = x[i-1] - a_lu[i-1+(k-1)*n] * x[k-1];
      }
    }
  }
/*
  Solve A' * X = B.
*/
  else
  {
/*
  Solve U' * Y = B.
*/
    for ( k = 1; k <= n; k++ )
    {
      t = 0.0;
      for ( i = 1; i <= k-1; i++ )
      {
        t = t + x[i-1] * a_lu[i-1+(k-1)*n];
      }
      x[k-1] = ( x[k-1] - t ) / a_lu[k-1+(k-1)*n];
    }
/*
  Solve ( PL )' * X = Y.
*/
    for ( k = n-1; 1 <= k; k-- )
    {
      t = 0.0;
      for ( i = k+1; i <= n; i++ )
      {
        t = t + x[i-1] * a_lu[i-1+(k-1)*n];
      }
      x[k-1] = x[k-1] + t;

      l = pivot[k-1];

      if ( l != k )
      {
        t      = x[l-1];
        x[l-1] = x[k-1];
        x[k-1] = t;
      }

    }

  }

  return x;
}
/******************************************************************************/

double *r8ge_to_r8gb ( int m, int n, int ml, int mu, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8GB copies an R8GE matrix to an R8GB matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    The R8GB storage format is for an M by N banded matrix, with lower
    bandwidth ML and upper bandwidth MU.  Storage includes room for ML
    extra superdiagonals, which may be required to store nonzero entries
    generated during Gaussian elimination.

    It usually doesn't make sense to try to store a general matrix
    in a band matrix format.  You can always do it, but it will take
    more space, unless the general matrix is actually banded.

    The purpose of this routine is to allow a user to set up a
    banded matrix in the easy-to-use general format, and have this
    routine take care of the compression of the data into general
    format.  All the user has to do is specify the bandwidths.

    Note that this routine "believes" what the user says about the
    bandwidth.  It will assume that all entries in the general matrix
    outside of the bandwidth are zero.

    The original M by N matrix is "collapsed" downward, so that diagonals
    become rows of the storage array, while columns are preserved.  The
    collapsed array is logically 2*ML+MU+1 by N.

    LINPACK and LAPACK band storage requires that an extra ML
    superdiagonals be supplied to allow for fillin during Gauss
    elimination.  Even though a band matrix is described as
    having an upper bandwidth of MU, it effectively has an
    upper bandwidth of MU+ML.  This routine will copy nonzero
    values it finds in these extra bands, so that both unfactored
    and factored matrices can be handled.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    John Burkardt

  Reference:

    Edward Anderson, Zhaojun Bai, Christian Bischof, Susan Blackford, 
    James Demmel, Jack Dongarra, Jeremy Du Croz, Anne Greenbaum, 
    Sven Hammarling, Alan McKenney, Danny Sorensen,
    LAPACK User's Guide,
    Second Edition,
    SIAM, 1995.

    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979,
    ISBN13: 978-0-898711-72-1,
    LC: QA214.L56.

  Parameters:

    Input, int M, the number of rows of the matrices.
    M must be positive.

    Input, int N, the number of columns of the matrices.
    N must be positive.

    Input, int ML, MU, the lower and upper bandwidths of A1.
    ML and MU must be nonnegative, and no greater than min(M,N)-1.

    Output, double A[M*N], the R8GE matrix.

    Input, double R8GE_TO_R8GB[(2*ML+MU+1)*N], the R8GB matrix.
*/
{
  double *b;
  int i;
  int j;
  int jhi;
  int jlo;
  int k;

  b = ( double * ) malloc ( (2*ml+mu+1) * n * sizeof ( double ) );
  for ( k = 0; k < (2*ml+mu+1)*n; k++ )
  {
    b[k] = 0.0;
  }

  for ( i = 1; i <= m; i++ )
  {
    jlo = i4_max ( i - ml, 1 );
    jhi = i4_min ( i + mu, n );

    for ( j = jlo; j <= jhi; j++ )
    {
      b[ml+mu+i-j+(j-1)*(2*ml+mu+1)] = a[i-1+(j-1)*m];
    }
  }

  return b;
}
/******************************************************************************/

double *r8ge_to_r8lt ( int m, int n, double a_ge[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8LT copies an R8GE matrix to an R8LT matrix.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    The R8LT storage format is used for an M by N lower triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, double A_GE[M,N], the R8GE matrix.

    Output, double R8GE_TO_R8LT[M,N], the R8LT matrix.
*/
{
  double *a_lt;
  int i;
  int j;

  a_lt = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( j <= i ) 
      {
        a_lt[i+j*m] = a_ge[i+j*m];
      }
      else
      {
        a_lt[i+j*m] = 0.0;
      }
    }
  }

  return a_lt;
}
/******************************************************************************/

double *r8ge_to_r8po ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8PO copies an R8GE matrix to an R8PO matrix.

  Discussion:

    The R8PO format assumes the matrix is square and symmetric; it is also 
    typically assumed that the matrix is positive definite.  These are not
    required here.  The copied R8PO matrix simply zeros out the lower triangle
    of the R8GE matrix.

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    The R8PO storage format is used for a symmetric positive definite 
    matrix and its inverse.  (The Cholesky factor of an R8PO matrix is an
    upper triangular matrix, so it will be in R8GE storage format.)

    Only the diagonal and upper triangle of the square array are used.
    This same storage scheme is used when the matrix is factored by
    R8PO_FA, or inverted by R8PO_INVERSE.  For clarity, the lower triangle
    is set to zero.

    R8PO storage is used by LINPACK and LAPACK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N,N], the R8GE matrix.

    Output, double R8GE_TO_R8PO[N,N], the R8PO matrix.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( n * n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i <= j ) 
      {
        b[i+j*n] = a[i+j*n];
      }
      else
      {
        b[i+j*n] = 0.0;
      }
    }
  }

  return b;
}
/******************************************************************************/

void r8ge_to_r8ri ( int n, double a[], int nz, int ija[], double sa[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8RI converts an R8GE matrix to R8RI form.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    An R8RI matrix is in row indexed sparse storage form.

    The size of the arrays IJA and SA can be determined by calling
    R8GE_TO_R8RI_SIZE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 January 2013

  Author:

    John Burkardt

  Reference:

    William Press, Brian Flannery, Saul Teukolsky, William Vetterling,
    Numerical Recipes in FORTRAN: The Art of Scientific Computing,
    Third Edition,
    Cambridge University Press, 2007,
    ISBN13: 978-0-521-88068-8,
    LC: QA297.N866.

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N*N], the matrix stored in GE 
    or "general" format.

    Input, int NZ, the size required for the RI
    or "row indexed" sparse storage.

    Output, int IJA[NZ], the index vector.

    Output, double SA[NZ], the value vector.
*/
{
  int i;
  int im;
  int j;
  int k;
  int l;

  for ( k = 0; k < n; k++ )
  {
    i = k;
    j = k;
    sa[k] = a[i+j*n];
  }

  k = n;
  sa[k] = 0.0;

  for ( i = 0; i <= n; i++ )
  {
    ija[i] = 0;
  }

  im = 0;

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i != j )
      {
        if ( a[i+j*n] != 0.0 )
        {
          k = k + 1;
          if ( ija[i] == 0 )
          {
            for ( l = im; l <= i; l++ )
            {
              ija[l] = k;
            }
            im = i + 1;
          }
          ija[k] = j;
          sa[k] = a[i+j*n];
        }
      }
    }
  }

  ija[n] = k + 1;

  return;
}
/******************************************************************************/

int r8ge_to_r8ri_size ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8RI_SIZE determines the size of an R8RI matrix.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    N spaces are always used for the diagonal entries, plus a dummy.
    The remaining spaces store off-diagonal nonzeros.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2013

  Author:

    John Burkardt

  Reference:

    William Press, Brian Flannery, Saul Teukolsky, William Vetterling,
    Numerical Recipes in FORTRAN: The Art of Scientific Computing,
    Third Edition,
    Cambridge University Press, 2007,
    ISBN13: 978-0-521-88068-8,
    LC: QA297.N866.

  Parameters:

    Input, int N, the order of the matrix.

    Input, double A[N*N], the matrix stored in GE or "general" format.

    Output, int R8GE_TO_R8RI_SIZE, the size required for the RI
    or "row indexed" sparse storage.
*/
{
  int i;
  int j;
  int nz;

  nz = n + 1;

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i != j )
      {
        if ( a[i+j*n] != 0.0 )
        {
          nz = nz + 1;
        }
      }
    }
  }

  return nz;
}
/******************************************************************************/

double *r8ge_to_r8ut ( int m, int n, double a_ge[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8UT copies an R8GE matrix to an R8UT matrix.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    The R8UT storage format is used for an M by N upper triangular matrix,
    and allocates space even for the zero entries.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of the matrix.

    Input, double A_GE[M,N], the R8GE matrix.

    Output, double R8GE_TO_R8UT[M,N], the R8UT matrix.
*/
{
  double *a_ut;
  int i;
  int j;

  a_ut = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( i <= j ) 
      {
        a_ut[i+j*m] = a_ge[i+j*m];
      }
      else
      {
        a_ut[i+j*m] = 0.0;
      }
    }
  }

  return a_ut;
}
/******************************************************************************/

double *r8ge_to_r8vec ( int m, int n, double *a )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8VEC copies an R8GE matrix to a real vector.

  Discussion:

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    In C++ and FORTRAN, this routine is not really needed.  In MATLAB,
    a data item carries its dimensionality implicitly, and so cannot be
    regarded sometimes as a vector and sometimes as an array.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns in the array.

    Input, double R8VEC_TO_R8GE[M*N], the array to be copied.

    Output, double X[M*N], the vector.
*/
{
  int i;
  int j;
  int k;
  double *x;

  x = ( double * ) malloc ( m * n * sizeof ( double ) );

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      x[k] = a[i+j*m];
      k = k + 1;
    }
  }

  return x;
}
/******************************************************************************/

double *r8ge_to_r8vm ( int m, int n, double a_ge[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TO_R8VM copies an R8GE matrix to an R8VM matrix.

  Discussion:

     The assumption is made that am MxN Vandermonde matrix has been stored in
     general format (R8GE), and that a copy is to be created in Vandermonde 
     (R8VM) format.  This means that only the second row of the GE matrix is 
     examined.

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

    The R8VM storage format is used for an M by N Vandermonde matrix.
    An M by N Vandermonde matrix is defined by the values in its second
    row, which will be written here as X(1:N).  The matrix has a first 
    row of 1's, a second row equal to X(1:N), a third row whose entries
    are the squares of the X values, up to the M-th row whose entries
    are the (M-1)th powers of the X values.  The matrix can be stored
    compactly by listing just the values X(1:N).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 August 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns of the matrix.

    Input, double A_GE[M*N], the R8GE matrix.

    Output, double R8GE_TO_R8VM[N], the R8VM matrix.
*/
{
  double *a_vm;
  int i;
  int j;

  a_vm = ( double * ) malloc ( n * sizeof ( double ) );

  i = 1;

  for ( j = 0; j < n; j++ )
  {
    a_vm[j] = a_ge[i+j*m];
  }

  return a_vm;
}
/******************************************************************************/

double *r8ge_transpose ( int m, int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TRANSPOSE creates a transposed copy of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2016

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the order of A.

    Input, double A[M*N], the matrix to be copied.

    Output, double R8GE_TRANSPOSE[N*M], the transpose of A.
*/
{
  double *b;
  int i;
  int j;

  b = ( double * ) malloc ( n * m * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[j+i*n] = a[i+j*m];
    }
  }

  return b;
}
/******************************************************************************/

void r8ge_transpose_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8GE_TRANSPOSE_PRINT prints an R8GE matrix, transposed.

  Discussion:

    An R8GE matrix is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

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
  r8ge_transpose_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8ge_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8GE_TRANSPOSE_PRINT_SOME prints some of an R8GE matrix, transposed.

  Discussion:

    An R8GE matrix is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 September 2013

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
  int i2lo_hi;
  int i2lo_lo;
  int inc;
  int j;
  int j2hi;
  int j2lo;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );

  if ( m <= 0 || n <= 0 )
  {
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  (None)\n" );
    return;
  }

  if ( ilo < 1 )
  {
    i2lo_lo = 1;
  }
  else
  {
    i2lo_lo = ilo;
  }

  if ( ihi < m )
  {
    i2lo_hi = m;
  }
  else
  {
    i2lo_hi = ihi;
  }

  for ( i2lo = i2lo_lo; i2lo <= i2lo_hi; i2lo = i2lo + INCX )
  {
    i2hi = i2lo + INCX - 1;

    if ( m < i2hi )
    {
      i2hi = m;
    }
    if ( ihi < i2hi )
    {
      i2hi = ihi;
    }

    inc = i2hi + 1 - i2lo;

    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Row:" );
    for ( i = i2lo; i <= i2hi; i++ )
    {
      fprintf ( stdout, "  %7d     ", i - 1 );
    }
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Col\n" );
    fprintf ( stdout, "\n" );

    if ( jlo < 1 )
    {
      j2lo = 1;
    }
    else
    {
      j2lo = jlo;
    }
    if ( n < jhi )
    {
      j2hi = n;
    }
    else
    {
      j2hi = jhi;
    }
    for ( j = j2lo; j <= j2hi; j++ )
    {
      fprintf ( stdout, "%5d:", j - 1 );
      for ( i2 = 1; i2 <= inc; i2++ )
      {
        i = i2lo - 1 + i2;
        fprintf ( stdout, "  %14g", a[(i-1)+(j-1)*m] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef INCX
}
/******************************************************************************/

int r8ge_trf ( int m, int n, double a[], int pivot[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TRF performs a LAPACK-style PLU factorization of an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_TRF is a standalone version of the LAPACK routine SGETRF.

    The factorization uses partial pivoting with row interchanges,
    and has the form
      A = P * L * U
    where P is a permutation matrix, L is lower triangular with unit
    diagonal elements (lower trapezoidal if N < M), and U is upper
    triangular (upper trapezoidal if M < N).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    Original FORTRAN77 version by Anderson, Bai, Bischof, Blackford,
    Demmel, Dongarra, DuCroz, Greenbaum, Hammarling, McKenney, Sorensen.
    C version by John Burkardt

  Reference:

    Edward Anderson, Zhaojun Bai, Christian Bischof, Susan Blackford, 
    James Demmel, Jack Dongarra, Jeremy Du Croz, Anne Greenbaum, 
    Sven Hammarling, Alan McKenney, Danny Sorensen,
    LAPACK User's Guide,
    Second Edition,
    SIAM, 1995.

  Parameters:

    Input, int M, the number of rows of the matrix A.  0 <= M.

    Input, int N, the number of columns of the matrix A.  0 <= N.

    Input/output, double A[M*N].
    On entry, the M by N matrix to be factored.
    On exit, the factors L and U from the factorization
    A = P*L*U; the unit diagonal elements of L are not stored.

    Output, int PIVOT[min(M,N)], the pivot indices.

    Output, int R8GE_TRF.
    = 0: successful exit
    = -K, the K-th argument had an illegal value
    = K: U(K,K) is exactly zero. The factorization
         has been completed, but the factor U is exactly
         singular, and division by zero will occur if it is used
         to solve a system of equations.
*/
{
  int i;
  int ii;
  int info;
  int j;
  int jj;
  int jp;
  double temp;
/*
  Test the input parameters.
*/
  info = 0;

  if ( m < 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8GE_TRF - Fatal error!\n" );
    fprintf ( stderr, "  M < 0.\n" );
    exit ( -1 );
  }

  if ( n < 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8GE_TRF - Fatal error!\n" );
    fprintf ( stderr, "  N < 0.\n" );
    exit ( -1 );
  }

  if ( m == 0 || n == 0 )
  {
    return 0;
  }

  for ( j = 1; j <= i4_min ( m, n ); j++ )
  {
/*
  Find the pivot.
*/
    temp = fabs ( a[j-1+(j-1)*m] );
    jp = j;
    for ( i = j + 1; i <= m; i++ )
    {
      if ( temp < fabs ( a[i-1+(j-1)*m] ) )
      {
        temp = fabs ( a[i-1+(j-1)*m] );
        jp = i;
      }
    }

    pivot[j-1] = jp;
/*
  Apply the interchange to columns 1:N.
  Compute elements J+1:M of the J-th column.
*/
    if ( a[jp-1+(j-1)*m] != 0.0 )
    {
      if ( jp != j )
      {
        for ( jj = 1; jj <= n; jj++ )
        {
          temp             = a[j-1+(jj-1)*m];
          a[j-1+(jj-1)*m]  = a[jp-1+(jj-1)*m];
          a[jp-1+(jj-1)*m] = temp;
        }
      }

      if ( j < m )
      {
        for ( i = j+1; i <= m; i++ )
        {
          a[i-1+(j-1)*m] = a[i-1+(j-1)*m] / a[j-1+(j-1)*m];
        }
      }
    }
    else if ( info == 0 )
    {
      info = j;
    }
/*
  Update the trailing submatrix.
*/
    if ( j < i4_min ( m, n ) )
    {
      for ( ii = j+1; ii <= m; ii++ )
      {
        for ( i = j+1; i <= n; i++ )
        {
          a[ii-1+(i-1)*m] = a[ii-1+(i-1)*m] - a[ii-1+(j-1)*m] * a[j-1+(i-1)*m];
        }
      }
    }
  }

  return info;
}
/******************************************************************************/

double *r8ge_trs ( int n, int nrhs, char trans, double a[], int pivot[], 
  double b[] )

/******************************************************************************/
/*
  Purpose:

    R8GE_TRS solves a system of linear equations factored by R8GE_TRF.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

    R8GE_TRS is a standalone version of the LAPACK routine SGETRS.

    R8GE_TRS solves a system of linear equations
      A * x = b  or  A' * X = B
    with a general N by N matrix A using the PLU factorization computed
    by R8GE_TRF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    Original FORTRAN77 version by Anderson, Bai, Bischof, Blackford,
    Demmel, Dongarra, DuCroz, Greenbaum, Hammarling, McKenney, Sorensen.
    C version by John Burkardt

  Reference:

    Edward Anderson, Zhaojun Bai, Christian Bischof, Susan Blackford, 
    James Demmel, Jack Dongarra, Jeremy Du Croz, Anne Greenbaum, 
    Sven Hammarling, Alan McKenney, Danny Sorensen,
    LAPACK User's Guide,
    Second Edition,
    SIAM, 1995.

  Parameters:

    Input, int N, the order of the matrix A.  0 <= N.

    Input, int NRHS, the number of right hand sides.  0 <= NRHS.

    Input, char TRANS, specifies the form of the system of equations:
    'N':  A * x = b  (No transpose)
    'T':  A'* X = B  (Transpose)
    'C':  A'* X = B  (Conjugate transpose = Transpose)

    Input, double A[N*N], the factors L and U from the factorization
    A = P*L*U as computed by R8GE_TRF.

    Input, int PIVOT[N], the pivot indices from R8GE_TRF.

    Input, double B[N*NRHS], the right hand side matrix.

    Output, double R8GE_TRS[N*NRHS], the solution matrix X.
*/
{
  int i;
  int j;
  int k;
  double temp;
  double *x;

  if ( trans != 'n' && trans != 'N' && 
       trans != 't' && trans != 'T' && 
       trans != 'c' && trans != 'C' )
  {
    return NULL;
  }

  if ( n < 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8GE_TRS - Fatal error!\n" );
    fprintf ( stderr, "  N < 0.\n" );
    exit ( -1 );
  }

  if ( nrhs < 0 )
  {
    return NULL;
  }

  if ( n == 0 )
  {
    return NULL;
  }
  if ( nrhs == 0 )
  {
    return NULL;
  }

  x = ( double * ) malloc ( n * nrhs * sizeof ( double ) );
  for ( k = 0; k < nrhs; k++ )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i+k*n] = b[i+k*n];
    }
  }

  if ( trans == 'n' || trans == 'N' )
  {
/*
  Apply row interchanges to the right hand sides.
*/
    for ( i = 1; i <= n; i++ )
    {
      if ( pivot[i-1] != i )
      {
        for ( k = 0; k < nrhs; k++ )
        {
          temp                = x[i-1+k*n];
          x[i-1+k*n]          = x[pivot[i-1]-1+k*n];
          x[pivot[i-1]-1+k*n] = temp;
        }
      }
    }
/*
  Solve L * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = 1; j <= n-1; j++ )
      {
        for ( i = j+1; i <= n; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];
        }
      }
    }
/*
  Solve U * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = n; 1 <= j; j-- )
      {
        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];
        for ( i = 1; i < j; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];
        }
      }
    }
  }
  else
  {
/*
  Solve U' * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = 1; j <= n; j++ )
      {
        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];
        for ( i = j+1; i <= n; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];
        }
      }
    }
/*
  Solve L' * x = b, overwriting b with x.
*/
    for ( k = 0; k < nrhs; k++ )
    {
      for ( j = n; 2 <= j; j-- )
      {
        for ( i = 1; i < j; i++ )
        {
          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];
        }
      }
    }
/*
  Apply row interchanges to the solution vectors.
*/
    for ( i = n; 1 <= i; i-- )
    {
      if ( pivot[i-1] != i )
      {
        for ( k = 0; k < nrhs; k++ )
        {
          temp                = x[i-1+k*n];
          x[i-1+k*n]          = x[pivot[i-1]-1+k*n];
          x[pivot[i-1]-1+k*n] = temp;
        }
      }
    }
  }

  return x;
}
/******************************************************************************/

double *r8ge_zeros_new ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8GE_ZEROS_NEW zeros an R8GE matrix.

  Discussion:

    The R8GE storage format is used for a "general" M by N matrix.  
    A physical storage space is made for each logical entry.  The two 
    dimensional logical array is mapped to a vector, in which storage is 
    by columns.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Output, double R8GE_ZEROS_NEW[M*N], the M by N matrix.
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

double *r8vec_indicator1_new ( int n )

/******************************************************************************/
/*
  Purpose:

    R8VEC_INDICATOR1_NEW sets an R8VEC to the indicator1 vector {1,2,3...}.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of elements of A.

    Output, double R8VEC_INDICATOR1_NEW[N], the array.
*/
{
  double *a;
  int i;

  a = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i <= n-1; i++ ) 
  {
    a[i] = ( double ) ( i + 1 );
  }

  return a;
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

double r8vec_mean ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MEAN returns the mean of a R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double X[N], the vector whose mean is desired.

    Output, double R8VEC_MEAN, the mean, or average, of the vector entries.
*/
{
  int i;
  double mean;

  mean = 0.0;
  for ( i = 0; i < n; i++ )
  {
    mean = mean + x[i];
  }

  mean = mean / ( double ) n;

  return mean;
}
/******************************************************************************/

double r8vec_min ( int n, double r8vec[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MIN returns the value of the minimum element in a R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the array.

    Input, double R8VEC[N], the array to be checked.

    Output, double R8VEC_MIN, the value of the minimum element.
*/
{
  int i;
  double value;

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( r8vec[i] < value )
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

double r8vec_norm_affine ( int n, double v0[], double v1[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORM_AFFINE returns the affine L2 norm of an R8VEC.

  Discussion:

    The affine vector L2 norm is defined as:

      R8VEC_NORM_AFFINE(V0,V1)
        = sqrt ( sum ( 1 <= I <= N ) ( V1(I) - V0(I) )^2 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the dimension of the vectors.

    Input, double V0[N], the base vector.

    Input, double V1[N], the vector whose affine L2 norm is desired.

    Output, double R8VEC_NORM_AFFINE, the affine L2 norm of V1.
*/
{
  int i;
  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )
  {
    value = value + ( v1[i] - v0[i] ) * ( v1[i] - v0[i] );
  }
  value = sqrt ( value );

  return value;
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

  printf ( "\n" );
  printf ( "%s\n", title );
  printf ( "\n" );

  for ( i = 0; i < n; i++ ) 
  {
    printf ( "  %8d  %14f\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

void r8vec_print_some ( int n, double a[], int max_print, char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT_SOME prints "some" of an R8VEC.

  Discussion:

    The user specifies MAX_PRINT, the maximum number of lines to print.

    If N, the size of the vector, is no more than MAX_PRINT, then
    the entire vector is printed, one entry per line.

    Otherwise, if possible, the first MAX_PRINT-2 entries are printed,
    followed by a line of periods suggesting an omission,
    and the last entry.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 February 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries of the vector.

    Input, double A[N], the vector to be printed.

    Input, int MAX_PRINT, the maximum number of lines
    to print.

    Input, char *TITLE, a title.
*/
{
  int i;

  if ( max_print <= 0 )
  {
    return;
  }

  if ( n <= 0 )
  {
    return;
  }

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  if ( n <= max_print )
  {
    for ( i = 0; i < n; i++ )
    {
      fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
    }
  }
  else if ( 3 <= max_print )
  {
    for ( i = 0; i < max_print - 2; i++ )
    {
      fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
    }
    fprintf ( stdout, "  ........  ..............\n" );
    i = n - 1;
    fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
  }
  else
  {
    for ( i = 0; i < max_print - 1; i++ )
    {
      fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
    }
    i = max_print - 1;
    fprintf ( stdout, "  %8d: %14g  ...more entries...\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

double *r8vec_to_r8ge ( int m, int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_TO_R8GE copies an R8VEC into an R8GE matrix.

  Discussion:

    In C++ and FORTRAN, this routine is not really needed.  In MATLAB,
    a data item carries its dimensionality implicitly, and so cannot be
    regarded sometimes as a vector and sometimes as an array.

    The R8GE storage format is used for a general M by N matrix.  A storage 
    space is made for each entry.  The two dimensional logical
    array can be thought of as a vector of M*N entries, starting with
    the M entries in the column 1, then the M entries in column 2
    and so on.  Considered as a vector, the entry A(I,J) is then stored
    in vector location I+(J-1)*M.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 February 2016

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns 
    in the array.

    Input, double X[M*N], the vector to be copied into the array.

    Output, double A[M*N], the array.
*/
{
  double *a;
  int i;
  int j;
  int k;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*n] = x[k];
      k = k + 1;
    }
  }

  return a;
}
/******************************************************************************/

double *r8vec_uniform_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

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

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
}
/******************************************************************************/

double r8vec_variance ( int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_VARIANCE returns the variance of an R8VEC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double X[N], the vector whose variance is desired.

    Output, double R8VEC_VARIANCE, the variance of the vector entries.
*/
{
  int i;
  double mean;
  double variance;

  mean = r8vec_mean ( n, x );

  variance = 0.0;
  for ( i = 0; i < n; i++ )
  {
    variance = variance + ( x[i] - mean ) * ( x[i] - mean );
  }

  if ( 1 < n )
  {
    variance = variance / ( double ) ( n - 1 );
  }
  else
  {
    variance = 0.0;
  }

  return variance;
}
/******************************************************************************/

void r8vec2_print ( int n, double a1[], double a2[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC2_PRINT prints an R8VEC2.

  Discussion:

    An R8VEC2 is a dataset consisting of N pairs of real values, stored
    as two separate vectors A1 and A2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A1[N], double A2[N], the vectors to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %4d: %14g  %14g\n", i, a1[i], a2[i] );
  }

  return;
}
/******************************************************************************/

void r8vec2_print_some ( int n, double x1[], double x2[], int max_print,
  char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC2_PRINT_SOME prints "some" of an R8VEC2.

  Discussion:

    An R8VEC2 is a dataset consisting of N pairs of real values, stored
    as two separate vectors A1 and A2.

    The user specifies MAX_PRINT, the maximum number of lines to print.

    If N, the size of the vectors, is no more than MAX_PRINT, then
    the entire vectors are printed, one entry of each per line.

    Otherwise, if possible, the first MAX_PRINT-2 entries are printed,
    followed by a line of periods suggesting an omission,
    and the last entry.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries of the vectors.

    Input, double X1[N], X2[N], the vector to be printed.

    Input, int MAX_PRINT, the maximum number of lines to print.

    Input, char *TITLE, a title.
*/
{
  int i;

  if ( max_print <= 0 )
  {
    return;
  }

  if ( n <= 0 )
  {
    return;
  }

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );

  if ( n <= max_print )
  {
    for ( i = 0; i < n; i++ )
    {
      fprintf ( stdout, "  %4d: %14f  %14f\n", i, x1[i], x2[i] );
    }
  }
  else if ( 3 <= max_print )
  {
    for ( i = 0; i < max_print-2; i++ )
    {
      fprintf ( stdout, "  %4d: %14f  %14f\n", i, x1[i], x2[i] );
    }
    fprintf ( stdout, "......  ..............  ..............\n" );
    i = n - 1;
    fprintf ( stdout, "  %4d: %14f  %14f\n", i, x1[i], x2[i] );
  }
  else
  {
    for ( i = 0; i < max_print - 1; i++ )
    {
      fprintf ( stdout, "  %4d: %14f  %14f\n", i, x1[i], x2[i] );
    }
    i = max_print - 1;
    fprintf ( stdout, "  %4d: %14f  %14f  ...more entries...\n", i, x1[i], x2[i] );
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
