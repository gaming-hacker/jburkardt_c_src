# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <complex.h>

# include "blas0.h"
# include "blas1_z.h"

/******************************************************************************/

double dzasum ( int n, double complex x[], int incx )

/******************************************************************************/
/*
  Purpose:

    DZASUM takes the sum of the absolute values of a vector.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for FORTRAN usage,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, pages 308-323, 1979.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double complex X[], the vector.

    Input, int INCX, the increment between successive entries of X.

    Output, double DZASUM, the sum of the absolute values.
*/
{
  int i;
  int ix;
  double value;

  value = 0.0;

  if ( n <= 0 || incx <= 0 )
  {
    return value;
  }

  if ( incx == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      value = value + fabs ( creal ( x[i] ) ) 
                    + fabs ( cimag ( x[i] ) );
    }
  }
  else
  {
    ix = 0;
    for ( i = 0; i < n; i++ )
    {
      value = value + fabs ( creal ( x[ix] ) ) 
                    + fabs ( cimag ( x[ix] ) );
      ix = ix + incx;
    }
  }
  return value;
}
/******************************************************************************/

double dznrm2 ( int n, double complex x[], int incx )

/******************************************************************************/
/*
  Purpose:

    DZNRM2 returns the euclidean norm of a vector.

  Discussion:

    This routine uses double precision complex arithmetic.

    DZNRM2 := sqrt ( sum ( conjg ( x(1:n) ) * x(1:n) ) )
            = sqrt ( dot_product ( x(1:n), x(1:n) ) )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for FORTRAN usage,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, pages 308-323, 1979.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double complex X[], the vector.

    Input, int INCX, the increment between successive entries of X.

    Output, double DZNRM2, the norm of the vector.
*/
{
  int i;
  int ix;
  double scale;
  double ssq;
  double temp;
  double value;

  if ( n < 1 || incx < 1 )
  {
    value  = 0.0;
  }
  else
  {
    scale = 0.0;
    ssq = 1.0;
    ix = 0;

    for ( i = 0; i < n; i++ )
    {
      if ( creal ( x[ix] ) != 0.0 )
      {
        temp = fabs ( creal ( x[ix] ) );
        if ( scale < temp )
        {
          ssq = 1.0 + ssq * pow ( scale / temp, 2 );
          scale = temp;
        }
        else
        {
          ssq = ssq + pow ( temp / scale, 2 );
        }
      }

      if ( cimag ( x[ix] ) != 0.0 )
      {
        temp = fabs ( cimag ( x[ix] ) );
        if ( scale < temp )
        {
          ssq = 1.0 + ssq * pow ( scale / temp, 2 );
          scale = temp;
        }
        else
        {
          ssq = ssq + pow ( temp / scale, 2 );
        }
      }
      ix = ix + incx;
    }
    value  = scale * sqrt ( ssq );
  }
  return value;
}
/******************************************************************************/

int izamax ( int n, double complex x[], int incx )

/******************************************************************************/
/*
  Purpose:

    IZAMAX indexes the vector element of maximum absolute value.

  Discussion:

    This routine uses double precision complex arithmetic.

    WARNING: This index is a 1-based index, not a 0-based index!

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for FORTRAN usage,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, pages 308-323, 1979.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double complex X[], the vector.

    Input, int INCX, the increment between successive entries of X.

    Output, int IZAMAX, the index of the element of maximum
    absolute value.
*/
{
  int i;
  int ix;
  double smax;
  int value;

  value = 0;

  if ( n < 1 || incx  <=  0 )
  {
    return value;
  }

  value = 1;

  if ( n == 1 )
  {
    return value;
  }

  if ( incx != 1 )
  {
    ix = 0;
    smax = zabs1 ( x[0] );
    ix = ix + incx;

    for ( i = 1; i < n; i++ )
    {
      if ( smax < zabs1 ( x[ix] ) )
      {
        value = i + 1;
        smax = zabs1 ( x[ix] );
      }
      ix = ix + incx;
    }
  }
  else
  {
    smax = zabs1 ( x[0] );
    for ( i = 1; i < n; i++ )
    {
      if ( smax < zabs1 ( x[i] ) )
      {
        value = i + 1;
        smax = zabs1 ( x[i] );
      }
    }
  }

  return value;
}
/******************************************************************************/

void zaxpy ( int n, double complex ca, double complex cx[], 
  int incx, double complex cy[], int incy )

/******************************************************************************/
/*
  Purpose:

    ZAXPY computes a constant times a vector plus a vector.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of elements in CX and CY.

    Input, double complex CA, the multiplier of CX.

    Input, double complex CX[], the first vector.

    Input, int INCX, the increment between successive entries of CX.

    Input/output, double complex CY[], the second vector.
    On output, CY(*) has been replaced by CY(*) + CA * CX(*).

    Input, int INCY, the increment between successive entries of CY.
*/
{
  int i;
  int ix;
  int iy;

  if ( n <= 0 )
  {
    return;
  }

  if ( zabs1 ( ca ) == 0.0 ) 
  {
    return;
  }

  if ( incx != 1 || incy != 1 )
  {
    if ( 0 <= incx )
    {
      ix = 0;
    }
    else
    {
      ix = ( -n + 1 ) * incx;
    }

    if ( 0 <= incy )
    {
      iy = 0;
    }
    else
    {
      iy = ( -n + 1 ) * incy;
    }

    for ( i = 0; i < n; i++ )
    {
      cy[iy] = cy[iy] + ca * cx[ix];
      ix = ix + incx;
      iy = iy + incy;
    }
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      cy[i] = cy[i] + ca * cx[i];
    }

  }

  return;
}
/******************************************************************************/

void zcopy ( int n, double complex cx[], int incx, double complex cy[], 
  int incy )

/******************************************************************************/
/*
  Purpose:

    ZCOPY copies a vector X to a vector Y.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of elements in CX and CY.

    Input, double complex CX[], the first vector.

    Input, int INCX, the increment between successive entries of CX.

    Output, double complex CY[], the second vector.

    Input, int INCY, the increment between successive entries of CY.
*/
{
  int i;
  int ix;
  int iy;

  if ( n <= 0 )
  {
    return;
  }

  if ( incx != 1 || incy != 1 )
  {
    if ( 0 <= incx )
    {
      ix = 0;
    }
    else
    {
      ix = ( -n + 1 ) * incx;
    }

    if ( 0 <= incy )
    {
      iy = 0;
    }
    else
    {
      iy = ( -n + 1 ) * incy;
    }

    for ( i = 0; i < n; i++ )
    {
      cy[iy] = cx[ix];
      ix = ix + incx;
      iy = iy + incy;
    }
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      cy[i] = cx[i];
    }
  }
  return;
}
/******************************************************************************/

double complex zdotc ( int n, double complex cx[], int incx, 
  double complex cy[], int incy )

/******************************************************************************/
/*
  Purpose:

    ZDOTC forms the conjugated dot product of two vectors.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double complex CX[], the first vector.

    Input, int INCX, the increment between successive entries in CX.

    Input, double complex CY[], the second vector.

    Input, int INCY, the increment between successive entries in CY.

    Output, double complex ZDOTC, the conjugated dot product of
    the corresponding entries of CX and CY.
*/
{
  int i;
  int ix;
  int iy;
  double complex value;

  value = 0.0;

  if ( n <= 0 )
  {
    return value;
  }

  if ( incx == 1 && incy == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      value = value + ( ~cx[i] ) * cy[i];
    }
  }
  else
  {
    if ( 0 <= incx )
    {
      ix = 0;
    }
    else
    {
      ix = ( -n + 1 ) * incx;
    }

    if ( 0 <= incy )
    {
      iy = 0;
    }
    else
    {
      iy = ( -n + 1 ) * incy;
    }

    for ( i = 0; i < n; i++ )
    {
      value = value + ( ~cx[ix] ) * cy[iy];
      ix = ix + incx;
      iy = iy + incy;
    }
  }
  return value;
}
/******************************************************************************/

double complex zdotu ( int n, double complex cx[], int incx, 
  double complex cy[], int incy )

/******************************************************************************/
/*
  Purpose:

    ZDOTU forms the unconjugated dot product of two vectors.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double complex CX[], the first vector.

    Input, int INCX, the increment between successive entries in CX.

    Input, double complex CY[], the second vector.

    Input, int INCY, the increment between successive entries in CY.

    Output, double complex ZDOTU, the unconjugated dot product of
    the corresponding entries of CX and CY.
*/
{
  int i;
  int ix;
  int iy;
  double complex value;

  value = 0.0;

  if ( n <= 0 )
  {
    return value;
  }

  if ( incx == 1 && incy == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      value = value + cx[i] * cy[i];
    }
  }
  else
  {
    if ( 0 <= incx )
    {
      ix = 0;
    }
    else
    {
      ix = ( -n + 1 ) * incx;
    }

    if ( 0 <= incy )
    {
      iy = 0;
    }
    else
    {
      iy = ( -n + 1 ) * incy;
    }

    for ( i = 0; i < n; i++ )
    {
      value = value + cx[ix] * cy[iy];
      ix = ix + incx;
      iy = iy + incy;
    }
  }
  return value;
}
/******************************************************************************/

void zdrot ( int n, double complex cx[], int incx, double complex cy[], 
  int incy, double c, double s )

/******************************************************************************/
/*
  Purpose:

    ZDROT applies a plane rotation.

  Discussion:

    This routine uses double precision complex arithmetic.

    The cosine C and sine S are real and the vectors CX and CY are complex.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input/output, double complex CX[], one of the vectors to be rotated.

    Input, int INCX, the increment between successive entries of CX.

    Input/output, double complex CY[], one of the vectors to be rotated.

    Input, int INCY, the increment between successive elements of CY.

    Input, double C, S, parameters (presumably the cosine and sine of
    some angle) that define a plane rotation.
*/
{
  double complex ctemp;
  int i;
  int ix;
  int iy;

  if ( n <= 0 )
  {
    return;
  }

  if ( incx == 1 && incy == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      ctemp = c * cx[i] + s * cy[i];
      cy[i] = c * cy[i] - s * cx[i];
      cx[i] = ctemp;
    }
  }
  else
  {
    if ( 0 <= incx )
    {
      ix = 0;
    }
    else
    {
      ix = ( -n + 1 ) * incx;
    }

    if ( 0 <= incy )
    {
      iy = 0;
    }
    else
    {
      iy = ( -n + 1 ) * incy;
    }

    for ( i = 0; i < n; i++ )
    {
      ctemp  = c * cx[ix] + s * cy[iy];
      cy[iy] = c * cy[iy] - s * cx[ix];
      cx[ix] = ctemp;
      ix = ix + incx;
      iy = iy + incy;
    }
  }
  return;
}
/******************************************************************************/

void zdscal ( int n, double sa, double complex cx[], int incx )

/******************************************************************************/
/*
  Purpose:

    ZDSCAL scales a vector by a constant.

  Discussion:

    This routine uses double precision complex arithmetic.

    The scaling constant is double precision real.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double SA, the multiplier.

    Input/output, double complex CX[], the vector to be scaled.

    Input, int INCX, the increment between successive entries of
    the vector CX.
*/
{
  int i;

  if ( n <= 0 || incx <= 0 )
  {
    return;
  }

  if ( incx == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      cx[i] = sa * cx[i];
    }
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      cx[i*incx] = sa * cx[i*incx];
    }
  }
  return;
}
/******************************************************************************/

void zrotg ( double complex *ca, double complex cb, double *c, 
  double complex *s )

/******************************************************************************/
/*
  Purpose:

    ZROTG determines a Givens rotation.

  Discussion:

    This routine uses double precision complex arithmetic.

    Given values A and B, this routine computes:

    If A = 0:

      R = B
      C = 0
      S = (1,0).

    If A /= 0:

      ALPHA = A / abs ( A )
      NORM  = sqrt ( ( abs ( A ) )**2 + ( abs ( B ) )**2 )
      R     = ALPHA * NORM
      C     = abs ( A ) / NORM
      S     = ALPHA * conj ( B ) / NORM

    In either case, the computed numbers satisfy the equation:

    (         C    S ) * ( A ) = ( R )
    ( -conj ( S )  C )   ( B ) = ( 0 )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for FORTRAN usage,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, pages 308-323, 1979.

  Parameters:

    Input/output, double complex *CA, on input, the value A.  On output,
    the value R.

    Input, double complex CB, the value B.

    Output, double *C, the cosine of the Givens rotation.

    Output, double complex *S, the sine of the Givens rotation.
*/
{
  double complex alpha;
  double norm;
  double scale;

  if ( zabs2 ( *ca ) == 0.0 )
  {
    *c = 0.0;
    *s = 1.0;
    *ca = cb;
  }
  else
  {
    scale = zabs2 ( *ca ) + zabs2 ( cb );
    norm = scale * sqrt ( pow ( zabs2 ( *ca / scale ), 2 )
                        + pow ( zabs2 (  cb / scale ), 2 ) );
    alpha = *ca / zabs2 ( *ca );
    *c = zabs2 ( *ca ) / norm;
    *s = alpha * ( ~cb ) / norm;
    *ca = alpha * norm;
  }

  return;
}
/******************************************************************************/

void zscal ( int n, double complex ca, double complex cx[], int incx )

/******************************************************************************/
/*
  Purpose:

    ZSCAL scales a vector by a constant.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double complex CA, the multiplier.

    Input/output, double complex CX[], the vector to be scaled.

    Input, int INCX, the increment between successive entries of CX.
*/
{
  int i;

  if ( n <= 0 || incx <= 0 )
  {
    return;
  }

  if ( incx == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      cx[i] = ca * cx[i];
    }
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      cx[i*incx] = ca * cx[i*incx];
    }
  }
  return;
}
/******************************************************************************/

void zswap ( int n, double complex cx[], int incx, double complex cy[], 
  int incy )

/******************************************************************************/
/*
  Purpose:

    ZSWAP interchanges two vectors.

  Discussion:

    This routine uses double precision complex arithmetic.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 March 2007

  Author:

    C version by John Burkardt

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
    LINPACK User's Guide,
    SIAM, 1979.

    Charles Lawson, Richard Hanson, David Kincaid, Fred Krogh,
    Basic Linear Algebra Subprograms for Fortran Usage,
    Algorithm 539,
    ACM Transactions on Mathematical Software,
    Volume 5, Number 3, September 1979, pages 308-323.

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input/output, double complex CX[], one of the vectors to swap.

    Input, int INCX, the increment between successive entries of CX.

    Input/output, double complex CY[], one of the vectors to swap.

    Input, int INCY, the increment between successive elements of CY.
*/
{
  double complex ctemp;
  int i;
  int ix;
  int iy;

  if ( n <= 0 )
  {
    return;
  }

  if ( incx == 1 && incy == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      ctemp = cx[i];
      cx[i] = cy[i];
      cy[i] = ctemp;
    }
  }
  else
  {
    if ( 0 <= incx )
    {
      ix = 0;
    }
    else
    {
      ix = ( -n + 1 ) * incx;
    }

    if ( 0 <= incy )
    {
      iy = 0;
    }
    else
    {
      iy = ( -n + 1 ) * incy;
    }

    for ( i = 0; i < n; i++ )
    {
      ctemp = cx[ix];
      cx[ix] = cy[iy];
      cy[iy] = ctemp;
      ix = ix + incx;
      iy = iy + incy;
    }
  }

  return;
}
