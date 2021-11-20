# include <complex.h>
# include <fenv.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
/*
  DBL_EPSILON, provided by <float.h>, is twice the machine epsilon for
  double precision arithmetic.
*/
# define TWOITERTOL DBL_EPSILON

# include "toms917.h"

/******************************************************************************/

double complex wrightomega ( double complex z )

/******************************************************************************/
/*
  Purpose:

    WRIGHTOMEGA is the simple routine for evaluating the Wright Omega function. 

  Discussion:

    This function is called by:

      w = wrightomega ( z )

    This function makes a call to the more powerful wrightomega_ext() function.

  Modified:

    13 May 2016

  Author:

    Piers Lawrence, Robert Corless, David Jeffrey

  Reference:

    Piers Lawrence, Robert Corless, David Jeffrey,
    Algorithm 917: Complex Double-Precision Evaluation of the Wright Omega 
    Function,
    ACM Transactions on Mathematical Software,
    Volume 38, Number 3, Article 20, April 2012, 17 pages.

  Parameters:

    Input, double complex Z, the argument.

    Output, double complex WRIGHTOMEGA, the value of the Wright Omega
    function of Z.
*/
{
  double complex e;
  double complex r;
  double complex w;

  wrightomega_ext ( z, &w, &e, &r, NULL );

  return w;
}
/******************************************************************************/

int wrightomega_ext ( double complex z, double complex *w, double complex *e,
  double complex *r, double complex *cond )

/******************************************************************************/
/*
  Purpose:

    WRIGHTOMEGA_EXT computes the Wright Omega function, with extra information.

  Discussion:

    WRIGHTOMEGA_EXT is the extended routine for evaluating the Wright
    Omega function with the option of extracting the last update step,
    the penultimate residual and the condition number estimate.

  Modified:

    13 May 2016

  Author:

    Piers Lawrence, Robert Corless, David Jeffrey

  Reference:

    Piers Lawrence, Robert Corless, David Jeffrey,
    Algorithm 917: Complex Double-Precision Evaluation of the Wright Omega 
    Function,
    ACM Transactions on Mathematical Software,
    Volume 38, Number 3, Article 20, April 2012, 17 pages.

  Parameters:

    Input, double complex Z, value at which to evaluate Wrightomega().

    Output, double complex *W, the value of Wrightomega(z).

    Output, double complex *E, the last update step in the iterative scheme.

    Output, double complex *R, the penultimate residual,
    r_k = z - w_k - log(w_k)

    Output, double complex *COND, the condition number estimate. 
    If NULL on input, the condition number is not calculated.

    Output, int WRIGHTOMEGA_EXT, error flag;
    0, successful computation.
    nonzero, the computation failed.        
*/
{
  double near;
  double pi = M_PI;
  double complex pz;
  double s = 1.0;
  double complex t;
  double complex wp1;
  double x;
  double y;
  double ympi;
  double yppi;
/* 
  Extract real and imaginary parts of Z. 
*/
  x = creal ( z );
  y = cimag ( z );
/* 
  Compute if we are near the branch cuts.
*/
  ympi = y - pi;
  yppi = y + pi;
  near = 0.01;
/* 
  Test for floating point exceptions:
*/

/*
  NaN output for NaN input.
*/
  if ( isnan ( x ) || isnan ( y ) )
  {
    *w = ( 0.0 / 0.0 ) + ( 0.0 / 0.0 ) * I;
    *e = 0.0 + 0.0 * I;
    *r = 0.0 + 0.0 * I;
    return 0;
  }
/*
  Signed zeros between branches.
*/
  else if ( isinf ( x ) && ( x < 0.0 ) && ( - pi < y ) && ( y <= pi ) )
  {
    if ( fabs ( y ) <= pi / 2.0 )
    {
      *w = + 0.0;
    }
    else
    {
      *w = - 0.0;
    }
      
    if ( 0.0 <= y )
    {
      *w = *w + 0.0 * I;
    }
    else
    {
      *w = *w - 1.0 * 0.0 * I;
    }

    *e = 0.0 + 0.0 * I;
    *r = 0.0 + 0.0 * I;
    return 0;
  }
/*
  Asymptotic for large z.
*/
  else if ( isinf ( x ) || isinf ( y ) )
  {
    *w = x + I * y;
    *e = 0.0 + 0.0 * I;
    *r = 0.0 + 0.0 * I;
    return 0;
  }
/*
  Test If exactly on the singular points.
*/
  if ( ( x == - 1.0 ) && ( fabs ( y ) == pi ) )
  {
    *w = - 1.0 + 0.0 * I;
    *e = 0.0 + 0.0 * I;
    *r = 0.0 + 0.0 * I;
    return 0;
  }

/* 
  Choose approximation based on region.
*/

/*
  Region 1: upper branch point.
  Series about z=-1+Pi*I.
*/
  if ( ( - 2.0 < x && x <= 1.0 && 1.0 < y && y < 2.0 * pi ) )
  {
    pz = conj ( csqrt ( conj ( 2.0 * ( z + 1.0 - I * pi ) ) ) );
    *w = - 1.0 
      + ( I 
      + ( 1.0 / 3.0 
      + ( - 1.0 / 36.0 * I 
      + ( 1.0 / 270.0 + 1.0 / 4320.0 * I * pz ) * pz ) * pz ) * pz ) * pz;
  }
/*
  Region 2: lower branch point.
  Series about z=-1-Pi*I.
*/
  else if ( ( - 2.0 < x && x <= 1.0 && - 2.0 * pi < y && y <- 1.0 ) )
  {
    pz = conj ( csqrt ( conj ( 2.0 * ( z + 1.0 + I * pi ) ) ) );
    *w = - 1.0 
      + ( - I + ( 1.0 / 3.0 
      + ( 1.0 / 36.0 * I 
      + ( 1.0 / 270.0 - 1.0 / 4320.0 * I * pz ) * pz ) * pz ) * pz ) * pz;
  }
/*
  Region 3: between branch cuts.
  Series: About -infinity.
*/
  else if ( x <= - 2.0 && - pi < y && y <= pi )
  {
    pz = cexp ( z );
    *w = ( 1.0 
      + ( - 1.0 
      + ( 3.0 / 2.0 
      + ( - 8.0 / 3.0 
      + 125.0 / 24.0 * pz ) * pz ) * pz ) * pz ) * pz;
  }
/*
  Region 4: Mushroom.
  Series about z=1.
*/
  else if ( ( ( - 2.0 < x ) && ( x <= 1.0 ) && ( - 1.0 <= y ) && ( y <= 1.0 ) )
    || ( ( - 2.0 < x ) && ( x - 1.0 ) * ( x - 1.0 ) + y * y <= pi * pi ) )
  {
    pz = z - 1.0;
    *w = 1.0 / 2.0 + 1.0 / 2.0 * z 
      + ( 1.0 / 16.0 
      + ( - 1.0 / 192.0 
      + ( - 1.0 / 3072.0 + 13.0 / 61440.0 * pz ) * pz ) * pz ) * pz * pz;
  }
/*
  Region 5: Top wing.
  Negative log series.
*/
  else if ( x <= - 1.05 && pi < y && y - pi <= - 0.75 * ( x + 1.0 ) )
  {
    t = z - I * pi;
    pz = clog ( - t );
    *w = ( ( 1.0 + ( - 3.0 / 2.0 + 1.0 / 3.0 * pz ) * pz ) * pz 
      + ( ( -1.0 + 1.0 / 2.0 * pz ) * pz + ( pz + ( - pz + t ) * t ) * t ) * t ) 
      / ( t * t * t );
  }
/*
  Region 6: Bottom wing.
  Negative log series.
*/
  else if ( x <= - 1.05 && 0.75 * ( x + 1.0 ) < y + pi && y + pi <= 0.0 )
  {
    t = z + I * pi;
    pz = clog ( - t );
    *w = ( ( 1.0 + ( - 3.0 / 2.0 + 1.0 / 3.0 * pz ) * pz ) * pz
      + ( ( - 1.0 + 1.0 / 2.0 * pz ) * pz + ( pz + ( - pz + t ) * t ) * t ) * t ) 
      / ( t * t * t );
  }
/*
  Region 7: Everywhere else.
  Series solution about infinity.
*/
  else
  {
    pz = clog ( z );
    *w = ( ( 1.0 + ( - 3.0 / 2.0 + 1.0 / 3.0 * pz ) * pz ) * pz 
      + ( ( - 1.0 + 1.0 / 2.0 * pz ) * pz + ( pz + ( - pz + z ) * z ) * z ) * z ) 
      / ( z * z * z );
  }
/*
  Regularize if near branch cuts.
*/
  if ( x <= - 1.0 + near && ( fabs ( ympi ) <= near || fabs ( yppi ) <= near ) ) 
  { 
    s = - 1.0;
    if ( fabs ( ympi ) <= near )
    {
/* 
  Recompute ympi with directed rounding.
*/
      fesetround ( FE_UPWARD );
      ympi = y - pi;
          
      if ( ympi <= 0.0 )
      {
        fesetround ( FE_DOWNWARD );
        ympi = y - pi;
      }
          
      z = x + I * ympi;

/* 
  Return rounding to default.
*/
      fesetround ( FE_TONEAREST );
    }
    else
    {
/* 
  Recompute yppi with directed rounding.
*/
      fesetround ( FE_UPWARD );
      yppi = y + pi;
          
      if ( yppi <= 0.0 )
      {
        fesetround ( FE_DOWNWARD );
        yppi = y + pi;
      }
          
      z = x + I * yppi;
/* 
  Return rounding to default.
*/
      fesetround ( FE_TONEAREST );
    }
  }
/*
  Iteration one.
*/
  *w = s * *w;
  *r = z - s * *w - clog ( *w );
  wp1 = s * *w + 1.0;
  *e = *r / wp1 * ( 2.0 * wp1 * ( wp1 + 2.0 / 3.0 * *r ) - *r )
    / ( 2.0 * wp1 * ( wp1 + 2.0 / 3.0 * *r ) - 2.0 * *r );
  *w = *w * ( 1.0 + *e );
/*
  Iteration two.
*/
  if ( cabs ( ( 2.0 * *w * *w - 8.0 * *w - 1.0 ) * pow ( cabs ( *r ), 4.0 ) ) 
    >= TWOITERTOL * 72.0 * pow ( cabs ( wp1 ), 6.0 ) )
  {
    *r = z - s * *w - clog ( *w );
    wp1 = s * *w + 1.0;
    *e = *r / wp1 * ( 2.0 * wp1 * ( wp1 + 2.0 / 3.0 * *r ) - *r ) 
      / ( 2.0 * wp1 * ( wp1 + 2.0 / 3.0 * *r ) - 2.0 * *r );
    *w = *w * ( 1.0 + *e );
  }
/*
  Undo regularization.
*/
  *w = s * *w;
/*
  Provide condition number estimate if requested.
*/
  if ( cond != NULL )
  {
    *cond = z / ( 1.0 + *w );
  }
      
  return 0;
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

