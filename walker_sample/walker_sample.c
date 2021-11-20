# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "walker_sample.h"

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

void normalize ( unsigned int n, double x[] )

/******************************************************************************/
/*
  Purpose:

    NORMALIZE scales a vector X so its entries sum to 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.

  Parameters:

    Input, unsigned int N, indicates the size of X.

    Input/output, double X[N+2], the vector to be normalized.
    Entries X[1] through X[N] will sum to 1 on output.
*/
{
  unsigned int i;
  double sum;
/*
  Sum X.
*/
  sum = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    sum = sum + fabs ( x[i] );
  }
/*
  Normalize so that the new sum of X will be 1.
*/
  sum = 1.0 / sum;
  for ( i = 1; i <= n; i++ )
  {
    x[i] = x[i] * sum; 
  }

  return;
}
/******************************************************************************/

void random_permutation ( unsigned int n, double x[], int *seed )

/******************************************************************************/
/*
  Purpose:

    RANDOM_PERMUTATION applies a random permutation to an array.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.

  Parameters:

    Input, unsigned int N, indicates the size of X.

    Input/output, double X[N+2].  On output, entries X[1] through
    X[N] have been randomly permuted.

    Input/output, int SEED, a seed for the random number generator.
*/
{
  unsigned int i;
  unsigned int j;
  double t;

  for ( i = 1; i < n; i++ )
  {
    j = i4_uniform_ab ( i, n, seed );

    t = x[i];
    x[i] = x[j];
    x[j] = t;      
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
/******************************************************************************/

void walker_build ( unsigned int n, double x[], double y[], unsigned int a[] )

/******************************************************************************/
/*
  Purpose:

    WALKER_BUILD sets up the data for a Walker sampler.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.

  Reference:

    Warren Smith,
    How to sample from a probability distribution,
    April 18, 2002.

  Parameters:

    Input, unsigned int N, indicates the size of X.

    Input, double X[N+2], contains in X[1] through X[N] the
    probabilities of outcomes 1 through N.  

    Output, double Y[N+2], the Walker threshold vector.

    Output, unsigned int A[N+2], the Walker index vector.
*/
{
  unsigned int *b;
  unsigned int i;
  unsigned int j;
  unsigned int k;
/*
  Initialize A.
*/
  a[0] = 0;
  for ( i = 1; i <= n; i++ )
  { 
    a[i] = i;
  }
  a[n+1] = n + 1;
/*
  Initialize B to the "stay here" value, and set sentinel values at the ends.
*/
  b = ( unsigned int * ) malloc ( ( n + 2 ) * sizeof ( unsigned int ) );

  b[0] = 0;
  for ( i = 1; i <= n; i++ )
  {
    b[i] = i;
  }
  b[n+1] = n + 1;
/*
  Copy Y from X.
  Scale the probability vector and set sentinel values at the ends.
*/
  y[0] = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    y[i] = x[i] * ( double ) ( n );
  }
  y[n+1] = 2.0;

  i = 0;
  j = n + 1;
  for ( ; ; )
  {
/*
  Find i so Y[B[i]] needs more.
*/
    do 
    { 
      i++; 
    } while ( y[b[i]] < 1.0 );
/*
  Find j so Y[B[j]] wants less.
*/
    do
    { 
      j--; 
    } while ( 1.0 <= y[b[j]] );

    if ( j <= i )
    { 
      break;
    }
/*
  Swap B[i] and B[j].
*/
    k = b[i];
    b[i] = b[j];
    b[j] = k;
  }

  i = j;
  j++;

  while ( 0 < i )
  {
/*
  Find J such that Y[B[j]] needs more.
*/
    while ( y[b[j]] <= 1.0 )
    {
      j++; 
    }
/*
  Meanwhile, Y[B[i]] wants less.
*/
    if ( n < j )
    {
      break;
    }
/*
  B[i] will donate to B[j] to fix up.
*/
    y[b[j]] = y[b[j]] - ( 1.0 - y[b[i]] );     
    a[b[i]] = b[j];             
/* 
  Y[B[j]] now wants less so readjust ordering.
*/
    if ( y[b[j]] < 1.0 )
    {
      k = b[i];
      b[i] = b[j];
      b[j] = k;
      j++;
    }
    else
    {
      i--;
    }
  }
/*
  Free memory.
*/
  free ( b );

  return;
}
/******************************************************************************/

unsigned int walker_sampler ( unsigned int n, double y[], unsigned int a[] )

/******************************************************************************/
/*
  Purpose:

    WALKER_SAMPLER returns a random sample i=1..N with prob X[i].

  Discussion:

    Implementation of algorithm for sampling from a discrete
    probability N-vector X[1], X[2], ..., X[N].  (N>=1.)
    Runs on O(1) worst case time per sample,
    and uses one integer and one double N-element array for storage.
    Preprocessing consumes O(N) time and temporarily uses one 
    additional integer array (B[0..N+1]) for bookkeeping. 
    X[0] and X[N+1] are also used as sentinels in the Build() algorithm.
 
  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.

  Reference:

    Warren Smith,
    How to sample from a probability distribution,
    April 18, 2002.

  Parameters:

    Input, unsigned int N, indicates the size of the probability vector X.

    Input, double Y[N+2], the Walker threshold vector.

    Input, unsigned int A[N+2], the Walker index vector.

    Output, unsigned int WALKER_SAMPLER, a sample value between 1 and N,
    selected according to the probability vector X.
*/
{
  unsigned int i; 
  double r;
/* 
  Let i = random uniform integer from {1,2,...N};  
*/
  i = 1 + ( unsigned int ) ( n * drand48 ( ) ); 

  r = drand48 ( );

  if ( y[i] < r ) 
  { 
    i = a[i];
  }

  return i;
}
/******************************************************************************/
    
void walker_sampler_test ( )

/******************************************************************************/
/*
  Purpose:

    WALKER_SAMPLER_TEST tests WALKER_SAMPLER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.
*/
{
  unsigned int *a;
  unsigned int *count;
  double expval;
  unsigned int i;
  unsigned int j;
  unsigned int n;
  double p;
  unsigned int seed;
  int seed2;
  double sum;
  double t;
  double v;
  double *x;
  double *y;

  seed = 123456789;
  n = 10;
  p = 2.0;
  
  printf ( "\n" );
  printf ( "WALKER_SAMPLER_TEST:\n" );
  printf ( "  WALKER_SAMPLER creates Walker sample vectors Y and A\n" );
  printf ( "  for efficient sampling of a discrete probability vector.\n" );
  printf ( "  Test the Walker sampler with a Zipf-type probability\n" );
/*
  Initialize the random number generator.
*/
  printf ( "  Use seed = %u to initialize srand48():\n", seed );

  srand48 ( seed );
/*
  "Warm up" the random number generator.
*/
  for ( i = 0; i < 100; i++ )
  {
    drand48 ( );
  }
  printf ( "\n" );
  printf ( "  After 100 warmup calls, next 3 values of drand48():\n" );

  for ( i = 100; i < 103; i++ )
  {
    printf ( "  %g\n", drand48 ( ) );
  }
/*
  Generate a standard Zipf probability vector for cases 1 - N,
  with parameter P.
*/
  x = zipf_probability ( n, p );

  printf ( "\n" );
  printf ( "  Zipf probabilities\n" );
  printf ( "  for N = %d\n", n );
  printf ( "  and parameter P = %g\n", p );
  printf ( "\n" );
  printf ( "     I     X[I]\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    printf ( "  %4u %g\n", i, x[i] );
  }
/*
  For better testing, randomly scramble the probabilities.
*/
  seed2 = 123456789;
  random_permutation ( n, x, &seed2 );

  printf ( "\n" );
  printf ( "  Randomly permuted X:\n");
  printf ( "\n" );
  printf ( "     I     X[I]\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    printf ( "  %4u %g\n", i, x[i] );
  }
/*
  Build the Walker sampler.
*/
  y = ( double * ) malloc ( ( n + 2 ) * sizeof ( double ) );
  a = ( unsigned int * ) malloc ( ( n + 2 ) * sizeof ( unsigned int ) );

  walker_build ( n, x, y, a );

  printf ( "\n" );
  printf ( "  Built the sampler\n" );
  printf ( "  i Y[i] A[i]:\n" );
  printf ( "\n" );

  for ( i = 1; i <= n; i++ )
  { 
    printf ( "  %3u %f %u\n", i, y[i], a[i] ); 
  }
/*
  Prepare to count the frequency of each outcome.
*/
  count = ( unsigned int * ) malloc ( ( n + 2 ) * sizeof ( unsigned int ) );
  for ( i = 1; i <= n; i++ )
  {
    count[i] = 0;
  }
/*
  Call the sampler many times.
*/
  for ( i = 0; i < 100000; i++ )
  {
    j = walker_sampler ( n, y, a );
    count[j] = count[j] + 1;
  }
/*
  Compare normalized sample frequencies to the original probabilities in X.
*/
  sum = 0.0;
  printf ( "\n" );
  printf ( "  100000 samples:\n" );
  printf ( "  prob   #samples:\n" );
  printf ( "\n" );

  for ( i = 1; i <= n; i++ )
  { 
    printf ( "  %f %6u\n", x[i], count[i] ); 
    expval = x[i] * 100000;
    t = expval - count[i];
    sum = sum + t * t / expval;
  }
  sum = sum / ( double ) ( n );

  printf ( "\n" );
  printf ( "  sumvar = %g (should be about 1)\n", sum );
/*
  Verify the data structure.
*/
  v = walker_verify ( n, x, y, a );
  printf ( "\n" );
  printf ( "  Verification sum = %g\n", v );
  printf ( "  (Should be close to 0)\n" );
/*
  Free memory.
*/
  free ( a );
  free ( count );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

double walker_verify ( unsigned int n, double x[], double y[], unsigned int a[] )

/******************************************************************************/
/*
  Purpose:

    WALKER_VERIFY verifies a Walker Sampler structure.

  Discussion:

    This test applies the sampling algorithms to a Zipfian distribution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.

  Parameters:

    Input, unsigned int N, indicates the size of X.

    Input, double X[N+2], contains in X[1] through X[N] the
    probabilities of outcomes 1 through N.

    Input, double Y[N+2], the Walker threshold vector.

    Input, unsigned int A[N+2], the Walker index vector.
*/
{
  unsigned int i;
  double v;
  double *z;

  z = ( double * ) malloc ( ( n + 2 ) * sizeof ( double ) );
/*
  Reverse the scaling.
*/
  for ( i = 1; i <= n; i++ )
  {
    z[i] = y[i] / ( double ) ( n );
  }
/*
  Add back the adjustments.
*/
  for ( i = 1; i <= n; i++ )
  {
    z[a[i]] = z[a[i]] + ( 1.0 - y[i] ) / ( double ) ( n );
  }
/*
  Check for discrepancies between Z and X.
*/
  v = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    v = v + fabs ( z[i] - x[i] );
  }
/*
  Free memory.
*/
  free ( z );

  return v;
}
/******************************************************************************/

double *zipf_probability ( unsigned int n, double p )

/******************************************************************************/
/*
  Purpose:

    ZIPF_PROBABILITY sets up a Zipf probability vector.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 February 2016

  Author:

    Original C version by Warren Smith.
    This C version by John Burkardt.

  Reference:

    George Zipf,
    The Psychobiology of Language,
    1935.

  Parameters:

    Input, unsigned int N, indicates the size of X.

    Input, double P, the Zipf parameter.
    1.0 < P.

    Output, double ZIPF_PROBABILITY[N+2], contains in X[1] through X[N] the
    probabilities of outcomes 1 through N.

*/
{
  unsigned int i;
  double *x;

  x = ( double * ) malloc ( ( n + 2 ) * sizeof ( double ) );

  x[0] = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    x[i] = pow ( i, - p );
  }
  x[n+1] = 0.0;

  normalize ( n, x );

  return x;
}
