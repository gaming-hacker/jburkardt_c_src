# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "blas0.h"
# include "blas1_s.h"
# include "linpack_s.h"

/******************************************************************************/

int schdc ( float a[], int lda, int p, float work[], int ipvt[], int job )

/******************************************************************************/
/*
  Purpose:

    SCHDC computes the Cholesky decomposition of a positive definite matrix.

  Discussion:

    A pivoting option allows the user to estimate the condition of a
    positive definite matrix or determine the rank of a positive
    semidefinite matrix.

    For positive definite matrices, INFO = P is the normal return.

    For pivoting with positive semidefinite matrices, INFO will
    in general be less than P.  However, INFO may be greater than
    the rank of A, since rounding error can cause an otherwise zero
    element to be positive.  Indefinite systems will always cause
    INFO to be less than P.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*P].
    On input, A contains the matrix whose decomposition is to
    be computed.  Only the upper half of A need be stored.
    The lower part of the array a is not referenced.
    On output, A contains in its upper half the Cholesky factor
    of the input matrix, as it has been permuted by pivoting.

    Input, int LDA, the leading dimension of the array A.

    Input, int P, the order of the matrix.

    Input, float WORK[P] is a work array.

    Input/output, int IPVT[P].
    On input, IPVT contains integers that control the selection
    of the pivot elements, if pivoting has been requested.
    Each diagonal element A(K,K) is placed in one of three classes
    according to the value of IPVT(K).

      > 0, then X(K) is an initial element.
      = 0, then X(K) is a free element.
      < 0, then X(K) is a final element.

    Before the decomposition is computed, initial elements are moved by
    symmetric row and column interchanges to the beginning of the array A
    and final elements to the end.  Both initial and final elements are
    frozen in place during the computation and only free elements are moved.
    At the K-th stage of the reduction, if A(K,K) is occupied by a free
    element, it is interchanged with the largest free element A(L,L) with
    K <= L.  IPVT is not referenced if JOB is 0.

    On output, IPVT(J) contains the index of the diagonal element
    of A that was moved into the J-th position, if pivoting was requested.

    Input, int JOB, initiates column pivoting.
    0, no pivoting is done.
    nonzero, pivoting is done.

    Output, int SCHDC, contains the index of the last positive diagonal
    element of the Cholesky factor.
*/
{
  int info;
  int j;
  int jp;
  int jt;
  int k;
  int l;
  float maxdia;
  int maxl;
  int pl;
  int pu;
  int swapk;
  float temp;

  pl = 1;
  pu = 0;
  info = p;
/*
  Pivoting has been requested.
  Rearrange the the elements according to IPVT.
*/
  if ( job != 0 )
  {
    for ( k = 1; k <= p; k++ )
    {
      swapk = ( 0 < ipvt[k-1] );

      if ( ipvt[k-1] < 0 )
      {
        ipvt[k-1] = -k;
      }
      else
      {
        ipvt[k-1] = k;
      }

      if ( swapk )
      {
        if ( k != pl )
        {
          sswap ( pl-1, a+0+(k-1)*lda, 1, a+0+(pl-1)*lda, 1 );

          temp = a[k-1+(k-1)*lda];
          a[k-1+(k-1)*lda] = a[pl-1+(pl-1)*lda];
          a[pl-1+(pl-1)*lda] = temp;

          for ( j = pl+1; j <= p; j++ )
          {
            if ( j < k )
            {
              temp = a[pl-1+(j-1)*lda];
              a[pl-1+(j-1)*lda] = a[j-1+(k-1)*lda];
              a[j-1+(k-1)*lda] = temp;
            }
            else if ( k < j )
            {
              temp = a[k-1+(j-1)*lda];
              a[k-1+(j-1)*lda] = a[pl-1+(j-1)*lda];
              a[pl-1+(j-1)*lda] = temp;
            }
          }
          ipvt[k-1] = ipvt[pl-1];
          ipvt[pl-1] = k;
        }
        pl = pl + 1;
      }
    }
    pu = p;

    for ( k = p; pl <= k; k-- )
    {
      if ( ipvt[k-1] < 0 )
      {
        ipvt[k-1] = -ipvt[k-1];

        if ( pu != k )
        {
          sswap ( k-1, a+0+(k-1)*lda, 1, a+0+(pu-1)*lda, 1 );

          temp = a[k-1+(k-1)*lda];
          a[k-1+(k-1)*lda] = a[pu-1+(pu-1)*lda];
          a[pu-1+(pu-1)*lda] = temp;

          for ( j = k+1; j <= p; j++ )
          {
            if ( j < pu )
            {
              temp = a[k-1+(j-1)*lda];
              a[k-1+(j-1)*lda] = a[j-1+(pu-1)*lda];
              a[j-1+(pu-1)*lda] = temp;
            }
            else if ( pu < j )
            {
              temp = a[k-1+(j-1)*lda];
              a[k-1+(j-1)*lda] = a[pu-1+(j-1)*lda];
              a[pu-1+(j-1)*lda] = temp;
            }
          }
          jt = ipvt[k-1];
          ipvt[k-1] = ipvt[pu-1];
          ipvt[pu-1] = jt;
        }
        pu = pu - 1;
      }
    }
  }

  for ( k = 1; k <= p; k++ )
  {
/*
  Reduction loop.
*/
    maxdia = a[k-1+(k-1)*lda];
    maxl = k;
/*
  Determine the pivot element.
*/
    if ( pl <= k && k < pu )
    {
      for ( l = k+1; l <= pu; l++ )
      {
        if ( maxdia < a[l-1+(l-1)*lda] )
        {
          maxdia = a[l-1+(l-1)*lda];
          maxl = l;
        }
      }
    }
/*
  Quit if the pivot element is not positive.
*/
    if ( maxdia <= 0.0 )
    {
      info = k - 1;
      return info;
    }
/*
  Start the pivoting and update IPVT.
*/
    if ( k != maxl )
    {
      sswap ( k-1, a+0+(k-1)*lda, 1, a+0+(maxl-1)*lda, 1 );
      a[maxl-1+(maxl-1)*lda] = a[k-1+(k-1)*lda];
      a[k-1+(k-1)*lda] = maxdia;
      jp = ipvt[maxl-1];
      ipvt[maxl-1] = ipvt[k-1];
      ipvt[k-1] = jp;
    }
/*
  Reduction step.
  Pivoting is contained across the rows.
*/
    work[k-1] = sqrt ( a[k-1+(k-1)*lda] );
    a[k-1+(k-1)*lda] = work[k-1];

    for ( j = k+1; j <= p; j++ )
    {
      if ( k != maxl )
      {
        if ( j < maxl )
        {
          temp = a[k-1+(j-1)*lda];
          a[k-1+(j-1)*lda] = a[j-1+(maxl-1)*lda];
          a[j-1+(maxl-1)*lda] = temp;
        }
        else if ( maxl < j )
        {
          temp = a[k-1+(j-1)*lda];
          a[k-1+(j-1)*lda] = a[maxl-1+(j-1)*lda];
          a[maxl-1+(j-1)*lda] = temp;
        }
      }
      a[k-1+(j-1)*lda] = a[k-1+(j-1)*lda] / work[k-1];
      work[j-1] = a[k-1+(j-1)*lda];
      temp = -a[k-1+(j-1)*lda];
      saxpy ( j-k, temp, work+k, 1, a+k+(j-1)*lda, 1 );
    }
  }

  return info;
}
/******************************************************************************/

int schdd ( float r[], int ldr, int p, float x[], float z[], int ldz, 
  int nz, float y[], float rho[], float c[], float s[] )

/******************************************************************************/
/*
  Purpose:

    SCHDD downdates an augmented Cholesky decomposition.

  Discussion:

    SCHDD can also downdate the triangular factor of an augmented QR
    decomposition.

    Specifically, given an upper triangular matrix R of order P, a
    row vector X, a column vector Z, and a scalar Y, SCHDD
    determines an orthogonal matrix U and a scalar ZETA such that

          (R   Z )     (RR  ZZ)
      U * (      )  =  (      ),
          (0 ZETA)     ( X   Y)

    where RR is upper triangular.

    If R and Z have been obtained from the factorization of a least squares
    problem, then RR and ZZ are the factors corresponding to the problem
    with the observation (X,Y) removed.  In this case, if RHO
    is the norm of the residual vector, then the norm of
    the residual vector of the downdated problem is
    sqrt ( RHO * RHO - ZETA * ZETA ). SCHDD will simultaneously downdate
    several triplets (Z, Y, RHO) along with R.

    For a less terse description of what SCHDD does and how
    it may be applied, see the LINPACK guide.

    The matrix U is determined as the product U(1)*...*U(P)
    where U(I) is a rotation in the (P+1,I)-plane of the form

      ( C(I)      -S(I)    )
      (                    ).
      ( S(I)       C(I)    )

    The rotations are chosen so that C(I) is real.

    The user is warned that a given downdating problem may be impossible
    to accomplish or may produce inaccurate results.  For example, this
    can happen if X is near a vector whose removal will reduce the
    rank of R.  Beware.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float R[LDR*P], the upper triangular matrix that
    is to be  downdated.  The part of R below the diagonal is not referenced.

    Input, int LDR, the leading dimension of the array R.
    LDR must be at least P.

    Input, int P, the order of the matrix R.

    Input, float X[P], the row vector that is to be removed from R.

    Input/output, float Z[LDZ*NZ], an array of NZ P-vectors
    which are to be downdated along with R.

    Input, int LDZ, the leading dimension of the array Z.
    LDZ must be at least P.

    Input, int NZ, the number of vectors to be downdated.
    NZ may be zero, in which case Z, Y, and RHO are not referenced.

    Input, float Y[NZ], the scalars for the downdating of
    the vectors Z.

    Input/output, float RHO[NZ], the norms of the residual vectors.
    On output these have been changed along with R and Z.

    Output, float C[P], S[P], the cosines and sines of the
    transforming rotations.

    Output, int SCHDD, return flag.
     0, the entire downdating was successful.
    -1, if R could not be downdated.  In this case, all quantities
        are left unaltered.
     1, if some RHO could not be downdated.  The offending RHO's are
        set to -1.
*/
{
  float a;
  float alpha;
  float azeta;
  float b;
  int i;
  int ii;
  int info;
  int j;
  float norm;
  float scale;
  float t;
  float xx;
  float zeta;
/*
  Solve R' * A = X, placing the result in the array S.
*/
  info = 0;
  s[0] = x[0] / r[0+0*ldr];

  for ( j = 2; j <= p; j++ )
  {
    s[j-1] = x[j-1] - sdot ( j-1, r+0+(j-1)*ldr, 1, s, 1 );
    s[j-1] = s[j-1] / r[j-1+(j-1)*ldr];
  }

  norm = snrm2 ( p, s, 1 );

  if ( 1.0 <= norm )
  {
    info = -1;
    return info;
  }

  alpha = sqrt ( 1.0 - norm * norm );
/*
  Determine the transformations.
*/
  for ( ii = 1; ii <= p; ii++ )
  {
    i = p - ii + 1;
    scale = alpha + fabs ( s[i-1] );
    a = alpha / scale;
    b = s[i-1] / scale;
    norm = sqrt ( a * a + b * b );
    c[i-1] = a / norm;
    s[i-1] = b / norm;
    alpha = scale * norm;
  }
/*
  Apply the transformations to R.
*/
  for ( j = 1; j <= p; j++ )
  {
    xx = 0.0;
    for ( ii = 1; ii <= j; ii++ )
    {
      i = j - ii + 1;
      t = c[i-1] * xx + s[i-1] * r[i-1+(j-1)*ldr];
      r[i-1+(j-1)*ldr] = c[i-1] * r[i-1+(j-1)*ldr] - s[i-1] * xx;
      xx = t;
    }
  }
/*
  If required, downdate Z and RHO.
*/
  for ( j = 1; j <= nz; j++ )
  {
    zeta = y[j-1];
    for ( i = 1; i <= p; i++ )
    {
      z[i-1+(j-1)*ldz] = ( z[i-1+(j-1)*ldz] - s[i-1] * zeta ) / c[i-1];
      zeta = c[i-1] * zeta - s[i-1] * z[i-1+(j-1)*ldz];
    }

    azeta = fabs ( zeta );

    if ( rho[j-1] < azeta )
    {
      info = 1;
      rho[j-1] = -1.0;
    }
    else
    {
      rho[j-1] = rho[j-1] * sqrt ( 1.0 - pow ( azeta / rho[j-1], 2 ) );
    }
  }

  return info;
}
/******************************************************************************/

void schex ( float r[], int ldr, int p, int k, int l, float z[], int ldz, 
  int nz, float c[], float s[], int job )

/******************************************************************************/
/*
  Purpose:

    SCHEX updates the Cholesky factorization of a positive definite matrix.

  Discussion:

    The factorization has the form

      A = R' * R

    where A is a positive definite matrix of order P.

    The updating involves diagonal permutations of the form

      E' * A * E

    where E is a permutation matrix.  Specifically, given
    an upper triangular matrix R and a permutation matrix
    E (which is specified by K, L, and JOB), SCHEX determines
    an orthogonal matrix U such that

      U * R * E = RR,

    where RR is upper triangular.  At the user's option, the
    transformation U will be multiplied into the array Z.
    If A = X'*X, so that R is the triangular part of the
    QR factorization of X, then RR is the triangular part of the
    QR factorization of X*E, that is, X with its columns permuted.

    For a less terse description of what SCHEX does and how
    it may be applied, see the LINPACK guide.

    The matrix Q is determined as the product U(L-K)*...*U(1)
    of plane rotations of the form

      (    C(I)       S(I) )
      (                    ),
      (   -S(I)       C(I) )

    where C(I) is real, the rows these rotations operate on
    are described below.

    There are two types of permutations, which are determined
    by the value of JOB.

    1, right circular shift.  The columns are rearranged in the order:

         1,...,K-1,L,K,K+1,...,L-1,L+1,...,P.

       U is the product of L-K rotations U(I), where U(I)
       acts in the (L-I,L-I+1)-plane.

    2, left circular shift: the columns are rearranged in the order

         1,...,K-1,K+1,K+2,...,L,K,L+1,...,P.

       U is the product of L-K rotations U(I), where U(I)
       acts in the (K+I-1,K+I)-plane.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float R[LDR*P].  On input, the upper
    triangular factor that is to be updated.  Elements of R below the
    diagonal are not referenced.  On output, R has been updated.

    Input, int LDR, the leading dimension of the array R.
    LDR must be at least P.

    Input, int P, the order of the matrix R.

    Input, int K, the first column to be permuted.

    Input, int L, the last column to be permuted.
    L must be strictly greater than K.

    Input/output float Z[LDZ*NZ], an array of NZ P-vectors into
    which the transformation U is multiplied.  Z is not referenced if NZ = 0.
    On output, Z has been updated.

    Input, int LDZ, the leading dimension of the array Z.
    LDZ must be at least P.

    Input, int NZ, the number of columns of the matrix Z.

    Output, float C[P], S[P], the cosines and sines of the
    transforming rotations.

    Input, int JOB, determines the type of permutation.
    1, right circular shift.
    2, left circular shift.
*/
{
  int i;
  int ii;
  int il;
  int iu;
  int j;
  int jj;
  int lm1;
  int lmk;
  float t;
/*
  Initialize
*/
  lmk = l - k;
  lm1 = l - 1;
/*
  Right circular shift.
*/
  if ( job == 1 )
  {
/*
  Reorder the columns.
*/
    for ( i = 1; i <= l; i++ )
    {
      ii = l - i + 1;
      s[i-1] = r[ii-1+(l-1)*ldr];
    }

    for ( jj = k; jj <= lm1; jj++ )
    {
      j = lm1 - jj + k;
      for ( i = 1; i <= j; i++ )
      {
        r[i-1+(j)*ldr] = r[i-1+(j-1)*ldr];
      }
      r[j+(j)*ldr] = 0.0;
    }

    for ( i = 1; i <= k-1; i++ )
    {
      ii = l - i + 1;
      r[i-1+(k-1)*ldr] = s[ii-1];
    }
/*
  Calculate the rotations.
*/
    t = s[0];
    for ( i = 1; i <= lmk; i++ )
    {
      srotg ( s+i, &t, c+i-1, s+i-1 );
      t = s[i];
    }

    r[k-1+(k-1)*ldr] = t;

    for ( j = k+1; j <= p; j++ )
    {
      il = i4_max ( 1, l-j+1 );
      for ( ii = il; ii <= lmk; ii++ )
      {
        i = l - ii;
        t = c[ii-1] * r[i-1+(j-1)*ldr] + s[ii-1] * r[i+(j-1)*ldr];
        r[i+(j-1)*ldr] = c[ii-1] * r[i+(j-1)*ldr] - s[ii-1] * r[i-1+(j-1)*ldr];
        r[i-1+(j-1)*ldr] = t;
      }
    }
/*
  If required, apply the transformations to Z.
*/
    for ( j = 1; j <= nz; j++ )
    {
      for ( ii = 1; ii <= lmk; ii++ )
      {
        i = l - ii;
        t = c[ii-1] * z[i-1+(j-1)*ldr] + s[ii-1] * z[i+(j-1)*ldr];
        z[i+(j-1)*ldr] = c[ii-1] * z[i+(j-1)*ldr] - s[ii-1] * z[i-1+(j-1)*ldr];
        z[i-1+(j-1)*ldr] = t;
      }
    }
  }
/*
  Left circular shift.
*/
  else
  {
/*
  Reorder the columns.
*/
    for ( i = 1; i <= k; i++ )
    {
      ii = lmk + i;
      s[ii-1] = r[i-1+(k-1)*ldr];
    }

    for ( j = k; j <= lm1; j++ )
    {
      for ( i = 1; i <= j; i++ )
      {
        r[i-1+(j-1)*ldr] = r[i-1+(j)*ldr];
      }
      jj = j - k + 1;
      s[jj-1] = r[j+(j)*ldr];
    }

    for ( i = 1; i <= k; i++ )
    {
      ii = lmk + i;
      r[i-1+(l-1)*ldr] = s[ii-1];
    }

    for ( i = k+1; i <= l; i++ )
    {
      r[i-1+(l-1)*ldr] = 0.0;
    }
/*
  Reduction loop.
*/
    for ( j = k; j <= p; j++ )
    {
/*
  Apply the rotations.
*/
      if ( j != k )
      {
        iu = i4_min ( j-1, l-1 );

        for ( i = k; i <= iu; i++ )
        {
          ii = i - k + 1;
          t = c[ii-1] * r[i-1+(j-1)*ldr] + s[ii-1] * r[i+(j-1)*ldr];
          r[i+(j-1)*ldr] = c[ii-1] * r[i+(j-1)*ldr] 
            - s[ii-1] * r[i-1+(j-1)*ldr];
          r[i-1+(j-1)*ldr] = t;
        }
      }

      if ( j < l )
      {
        jj = j - k + 1;
        t = s[jj-1];
        srotg ( r+j-1+(j-1)*ldr, &t, c+jj-1, s+jj-1 );
      }
    }
/*
  Apply the rotations to Z.
*/
    for ( j = 1; j <= nz; j++ )
    {
      for ( i = k; i <= lm1; i++ )
      {
        ii = i - k + 1;
        t = c[ii-1] * z[i-1+(j-1)*ldr] + s[ii-1] * z[i+(j-1)*ldr];
        z[i+(j-1)*ldr] = c[ii-1] * z[i+(j-1)*ldr] - s[ii-1] * z[i-1+(j-1)*ldr];
        z[i-1+(j-1)*ldr] = t;
      }
    }
  }

  return;
}
/******************************************************************************/

void schud ( float r[], int ldr, int p, float x[], float z[], int ldz, int nz, 
  float y[], float rho[], float c[], float s[] )

/******************************************************************************/
/*
  Purpose:

    SCHUD updates an augmented Cholesky decomposition.

  Discussion:

    SCHUD can also update the triangular part of an augmented QR
    decomposition.

    Specifically, given an upper triangular matrix R of order P, a row vector
    X, a column vector Z, and a scalar Y, SCHUD determines a unitary matrix
    U and a scalar ZETA such that

           (R  Z)     (RR   ZZ )
      U  * (    )  =  (        ),
           (X  Y)     ( 0  ZETA)

    where RR is upper triangular.

    If R and Z have been obtained from the factorization of a least squares
    problem, then RR and ZZ are the factors corresponding to the problem
    with the observation (X,Y) appended.  In this case, if RHO is the
    norm of the residual vector, then the norm of the residual vector of
    the updated problem is sqrt ( RHO * RHO + ZETA * ZETA ).  SCHUD will
    simultaneously update several triplets (Z, Y, RHO).

    For a less terse description of what SCHUD does and how
    it may be applied, see the LINPACK guide.

    The matrix U is determined as the product U(P)*...*U(1),
    where U(I) is a rotation in the (I,P+1) plane of the form

      (     C(I)      S(I) )
      (                    ).
      (    -S(I)      C(I) )

    The rotations are chosen so that C(I) is real.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float R[LDR*P], the upper triangular matrix to be
    updated.  The part of R below the diagonal is not referenced.
    On output, the matrix has been updated.

    Input, int LDR, the leading dimension of the array R.
    LDR must be at least equal to P.

    Input, int P, the order of the matrix R.

    Input, float X[P], the row to be added to R.

    Input/output, float Z[LDZ*NZ], contains NZ P-vectors
    to be updated with R.

    Input, int LDZ, the leading dimension of the array Z.
    LDZ must be at least P.

    Input, int NZ, the number of vectors to be updated.  NZ may be
    zero, in which case Z, Y, and RHO are not referenced.

    Input, float Y[NZ], the scalars for updating the vectors Z.

    Input/output, float RHO[NZ].  On input, the norms of the
    residual vectors to be updated.  If RHO(J) is negative, it is left
    unaltered.

    Output, float C[P], S[P], the cosines and sines of the
    transforming rotations.
*/
{
  float azeta;
  int i;
  int j;
  float scale;
  float t;
  float xj;
  float zeta;
/*
  Update R.
*/
  for ( j = 1; j <= p; j++ )
  {
    xj = x[j-1];
/*
  Apply the previous rotations.
*/
    for ( i = 1; i <= j-1; i++ )
    {
      t = c[i-1] * r[i-1+(j-1)*ldz] + s[i-1] * xj;
      xj = c[i-1] * xj - s[i-1] * r[i-1+(j-1)*ldz];
      r[i-1+(j-1)*ldz] = t;
    }
/*
  Compute the next rotation.
*/
    srotg ( r+j-1+(j-1)*ldr, &xj, c+j-1, s+j-1 );
  }
/*
  If required, update Z and RHO.
*/
  for ( j = 1; j <= nz; j++ )
  {
    zeta = y[j-1];
    for ( i = 1; i <= p; i++ )
    {
      t =    c[i-1] * z[i-1+(j-1)*ldz] + s[i-1] * zeta;
      zeta = c[i-1] * zeta   - s[i-1] * z[i-1+(j-1)*ldz];
      z[i-1+(j-1)*ldz] = t;
    }

    azeta = fabs ( zeta );

    if ( azeta != 0.0 && 0.0 <= rho[j-1] )
    {
      scale = azeta + rho[j-1];
      rho[j-1] = scale * sqrt ( 
        pow ( azeta / scale, 2 ) + pow ( rho[j-1] / scale, 2 ) );
    }

  }

  return;
}
/******************************************************************************/

float sgbco ( float abd[], int lda, int n, int ml, int mu, int ipvt[], 
  float z[] )

/******************************************************************************/
/*
  Purpose:

    SGBCO factors a real band matrix and estimates its condition.

  Discussion:

    If RCOND is not needed, SGBFA is slightly faster.

    To solve A*X = B, follow SGBCO by SGBSL.

    To compute inverse(A)*C, follow SGBCO by SGBSL.

    To compute determinant(A), follow SGBCO by SGBDI.

  Example:

    If the original matrix is

      11 12 13  0  0  0
      21 22 23 24  0  0
       0 32 33 34 35  0
       0  0 43 44 45 46
       0  0  0 54 55 56
       0  0  0  0 65 66

    then for proper band storage,

      N = 6, ML = 1, MU = 2, 5 <= LDA and ABD should contain

       *  *  *  +  +  +      * = not used
       *  * 13 24 35 46      + = used for pivoting
       * 12 23 34 45 56
      11 22 33 44 55 66
      21 32 43 54 65  *

  Band storage:

    If A is a band matrix, the following program segment
    will set up the input.

      ml = (band width below the diagonal)
      mu = (band width above the diagonal)
      m = ml + mu + 1

      do j = 1, n
        i1 = max ( 1, j-mu )
        i2 = min ( n, j+ml )
        do i = i1, i2
          k = i - j + m
          abd(k,j) = a(i,j)
        }
      }

    This uses rows ML+1 through 2*ML+MU+1 of ABD.  In addition, the first
    ML rows in ABD are used for elements generated during the
    triangularization.  The total number of rows needed in ABD is
    2*ML+MU+1.  The ML+MU by ML+MU upper left triangle and the ML by ML
    lower right triangle are not referenced.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float ABD[LDA*N].  On input, the matrix in band
    storage.  The columns of the matrix are stored in the columns of ABD and
    the diagonals of the matrix are stored in rows ML+1 through 2*ML+MU+1
    of ABD.  On output, an upper triangular matrix in band storage and
    the multipliers which were used to obtain it.  The factorization can
    be written A = L*U where L is a product of permutation and unit lower
    triangular matrices and U is upper triangular.

    Input, int LDA, the leading dimension of the array ABD.
    2*ML + MU + 1 <= LDA is required.

    Input, int N, the order of the matrix.

    Input, int ML, MU, the number of diagonals below and above the
    main diagonal.  0 <= ML < N, 0 <= MU < N.

    Output, int IPVT[N], the pivot indices.

    Workspace, float Z[N], a work vector whose contents are
    usually unimportant.  If A is close to a singular matrix, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).

    Output, float SGBCO, an estimate of the reciprocal condition number RCOND
    of A.  For the system A*X = B, relative perturbations in A and B of size
    EPSILON may cause relative perturbations in X of size EPSILON/RCOND.
    If RCOND is so small that the logical expression
      1.0 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float anorm;
  float ek;
  int i;
  int is;
  int j;
  int ju;
  int k;
  int l;
  int la;
  int lm;
  int lz;
  int m;
  int mm;
  float rcond;
  float s;
  float sm;
  float t;
  float wk;
  float wkm;
  float ynorm;
/*
  Compute the 1-norm of A.
*/
  anorm = 0.0;
  l = ml + 1;
  is = l + mu;

  for ( j = 1; j <= n; j++ )
  {
    anorm = r4_max ( anorm, sasum ( l, abd+is-1+(j-1)*lda, 1 ) );
    if ( ml + 1 < is )
    {
      is = is - 1;
    }
    if ( j <= mu )
    {
      l = l + 1;
    }
    if ( n - ml <= j )
    {
      l = l - 1;
    }
  }
/*
  Factor.
*/
  sgbfa ( abd, lda, n, ml, mu, ipvt );
/*
  RCOND = 1/(norm(A)*(estimate of norm(inverse(A)))).

  Estimate = norm(Z)/norm(Y) where  a*z = y  and A'*Y = E.

  A' is the transpose of A.  The components of E are
  chosen to cause maximum local growth in the elements of W where
  U'*W = E.  The vectors are frequently rescaled to avoid
  overflow.

  Solve U' * W = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }
  m = ml + mu + 1;
  ju = 0;

  for ( k = 1; k <= n; k++ )
  {
    if ( 0.0 < z[k-1] )
    {
      ek = - ek;
    }

    if ( fabs ( abd[m-1+(k-1)*lda] ) < fabs ( ek - z[k-1] ) )
    {
      s = fabs ( abd[m-1+(k-1)*lda] ) / fabs ( ek - z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ek = s * ek;
    }

    wk = ek - z[k-1];
    wkm = -ek - z[k-1];
    s = fabs ( wk );
    sm = fabs ( wkm );

    if ( abd[m-1+(k-1)*lda] != 0.0 )
    {
      wk = wk / abd[m-1+(k-1)*lda];
      wkm = wkm / abd[m-1+(k-1)*lda];
    }
    else
    {
      wk = 1.0;
      wkm = 1.0;
    }

    ju = i4_min ( i4_max ( ju, mu+ipvt[k-1] ), n );
    mm = m;

    if ( k+1 <= ju )
    {
      for ( j = k+1; j <= ju; j++ )
      {
        mm = mm - 1;
        sm = sm + fabs ( z[j-1] + wkm * abd[mm-1+(j-1)*lda] );
        z[j-1] = z[j-1] + wk * abd[mm-1+(j-1)*lda];
        s = s + fabs ( z[j-1] );
      }

      if ( s < sm )
      {
        t = wkm - wk;
        wk = wkm;
        mm = m;
        for ( j = k+1; j <= ju; ju++ )
        {
          mm = mm - 1;
          z[j-1] = z[j-1] + t * abd[mm-1+(j-1)*lda];
        }
      }
    }
    z[k-1] = wk;
  }

  s = sasum ( n, z, 1 );

  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
/*
  Solve L' * Y = W.
*/
  for ( k = n; 1 <= k; k-- )
  {
    lm = i4_min ( ml, n-k );

    if ( k < m )
    {
      z[k-1] = z[k-1] + sdot ( lm, abd+m+(k-1)*lda, 1, z+k, 1 );
    }

    if ( 1.0 < fabs ( z[k-1] ) )
    {
      s = 1.0 / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
    }
    l = ipvt[k-1];
    t = z[l-1];
    z[l-1] = z[k-1];
    z[k-1] = t;
  }

  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
  ynorm = 1.0;
/*
  Solve L * V = Y.
*/
  for ( k = 1; k <= n; k++ )
  {
    l = ipvt[k-1];
    t = z[l-1];
    z[l-1] = z[k-1];
    z[k-1] = t;
    lm = i4_min ( ml, n-k );

    if ( k < n )
    {
      saxpy ( lm, t, abd+m+(k-1)*lda, 1, z+k, 1 );
    }

    if ( 1.0 < fabs ( z[k-1] ) )
    {
      s = 1.0 / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }
  }
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;
/*
  Solve U * Z = W.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( fabs ( abd[m-1+(k-1)*lda] ) < fabs ( z[k-1] ) )
    {
      s = fabs ( abd[m-1+(k-1)*lda] ) / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }

    if ( abd[m-1+(k-1)*lda] != 0.0 )
    {
      z[k-1] = z[k-1] / abd[m-1+(k-1)*lda];
    }
    else
    {
      z[k-1] = 1.0;
    }

    lm = i4_min ( k, m ) - 1;
    la = m - lm;
    lz = k - lm;
    t = -z[k-1];
    saxpy ( lm, t, abd+la-1+(k-1)*lda, 1, z+lz-1, 1 );
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void sgbdi ( float abd[], int lda, int n, int ml, int mu, int ipvt[], 
  float det[2] )

/******************************************************************************/
/*
  Purpose:

    SGBDI computes the determinant of a band matrix factored by SGBCO or SGBFA.

  Discussion:

    If the inverse is needed, use SGBSL N times.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float ABD[LDA*N], the LU factor information from SGBCO 
    or SGBFA.

    Input, int LDA, the leading dimension of the array ABD.

    Input, int N, the order of the matrix.

    Input, int ML, MU, the number of diagonals below and above the
    main diagonal.  0 <= ML < N, 0 <= MU < N.

    Input, int IPVT[N], the pivot vector from SGBCO or SGBFA.

    Output, float DET[2], the determinant of the original matrix,
    if requested.
      determinant = DET[0] * 10.0**DET[1]
    with  1.0D+00 <= abs ( DET[0] ) < 10.0D+00 or DET[0] = 0.0D+00.
*/
{
  int i;
  int m;

  m = ml + mu + 1;
  det[0] = 1.0;
  det[1] = 0.0;

  for ( i = 1; i <= n; i++ )
  {
    if ( ipvt[i-1] != i )
    {
      det[0] = -det[0];
    }

    det[0] = det[0] * abd[m-1+(i-1)*lda];

    if ( det[0] == 0.0 )
    {
      return;
    }

    while ( fabs ( det[0] ) < 1.0 )
    {
      det[0] = det[0] * 10.0;
      det[1] = det[1] - 1.0;
    }

    while ( 10.0 <= fabs ( det[0] ) )
    {
      det[0] = det[0] / 10.0;
      det[1] = det[1] + 1.0;
    }
  }
  return;
}
/******************************************************************************/

int sgbfa ( float abd[], int lda, int n, int ml, int mu, int ipvt[] )

/******************************************************************************/
/*
  Purpose:

    SGBFA factors a real band matrix by elimination.

  Discussion:

    SGBFA is usually called by SGBCO, but it can be called
    directly with a saving in time if RCOND is not needed.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float ABD[LDA*N].  On input, the matrix in band
    storage.  The columns of the matrix are stored in the columns of ABD
    and the diagonals of the matrix are stored in rows ML+1 through
    2*ML+MU+1 of ABD.  On output, an upper triangular matrix in band storage
    and the multipliers which were used to obtain it.  The factorization
    can be written A = L*U where L is a product of permutation and unit lower
    triangular matrices and U is upper triangular.

    Input, int LDA, the leading dimension of the array ABD.
    2*ML + MU + 1 <= LDA is required.

    Input, int N, the order of the matrix.

    Input, int ML, MU, the number of diagonals below and above the
    main diagonal.  0 <= ML < N, 0 <= MU < N.

    Output, int IPVT[N], the pivot indices.

    Output, integer SGBFA, error flag.
    0, normal value.
    K, if U(K,K) == 0.0D+00.  This is not an error condition for this
      subroutine, but it does indicate that SGBSL will divide by zero if
      called.  Use RCOND in SGBCO for a reliable indication of singularity.
*/
{
  int i;
  int i0;
  int info;
  int j;
  int j0;
  int j1;
  int ju;
  int jz;
  int k;
  int l;
  int lm;
  int m;
  int mm;
  float t;

  m = ml + mu + 1;
  info = 0;
/*
  Zero initial fill-in columns.
*/
  j0 = mu + 2;
  j1 = i4_min ( n, m ) - 1;

  for ( jz = j0; jz <= j1; jz++ )
  {
    i0 = m + 1 - jz;
    for ( i = i0; i <= ml; i++ )
    {
      abd[i-1+(jz-1)*lda] = 0.0;
    }
  }

  jz = j1;
  ju = 0;
/*
  Gaussian elimination with partial pivoting.
*/
  for ( k = 1; k <= n-1; k++ )
  {
/*
  Zero out the next fill-in column.
*/
    jz = jz + 1;
    if ( jz <= n )
    {
      for ( i = 1; i <= ml; i++ )
      {
        abd[i-1+(jz-1)*lda] = 0.0;
      }
    }
/*
  Find L = pivot index.
*/
    lm = i4_min ( ml, n-k );
    l = isamax ( lm+1, abd+m-1+(k-1)*lda, 1 ) + m - 1;
    ipvt[k-1] = l + k - m;
/*
  Zero pivot implies this column already triangularized.
*/
    if ( abd[l-1+(k-1)*lda] == 0.0 )
    {
      info = k;
    }
/*
  Interchange if necessary.
*/
    else
    {
      if ( l != m )
      {
        t = abd[l-1+(k-1)*lda];
        abd[l-1+(k-1)*lda] = abd[m-1+(k-1)*lda];
        abd[m-1+(k-1)*lda] = t;
      }
/*
  Compute multipliers.
*/
      t = -1.0 / abd[m-1+(k-1)*lda];
      sscal ( lm, t, abd+m+(k-1)*lda, 1 );
/*
  Row elimination with column indexing.
*/
      ju = i4_min ( i4_max ( ju, mu+ipvt[k-1] ), n );
      mm = m;

      for ( j = k+1; j <= ju; j++ )
      {
        l = l - 1;
        mm = mm - 1;
        t = abd[l-1+(j-1)*lda];
        if ( l != mm )
        {
          abd[l-1+(j-1)*lda] = abd[mm-1+(j-1)*lda];
          abd[mm-1+(j-1)*lda] = t;
        }
        saxpy ( lm, t, abd+m+(k-1)*lda, 1, abd+mm+(j-1)*lda, 1 );
      }

    }

  }

  ipvt[n-1] = n;

  if ( abd[m-1+(n-1)*lda] == 0.0 )
  {
    info = n;
  }

  return info;
}
/******************************************************************************/

void sgbsl ( float abd[], int lda, int n, int ml, int mu, int ipvt[], 
  float b[], int job )

/******************************************************************************/
/*
  Purpose:

    SGBSL solves a real banded system factored by SGBCO or DGBFA.

  Discussion:

    SGBSL can solve either A * X = B  or  A' * X = B.

    A division by zero will occur if the input factor contains a
    zero on the diagonal.  Technically this indicates singularity
    but it is often caused by improper arguments or improper
    setting of LDA.  It will not occur if the subroutines are
    called correctly and if SGBCO has set 0.0 < RCOND
    or SGBFA has set INFO == 0.

    To compute inverse(A) * C  where C is a matrix with P columns:

      call sgbco ( abd, lda, n, ml, mu, ipvt, rcond, z )

      if ( rcond is too small ) then
        exit
      end if

      do j = 1, p
        call sgbsl ( abd, lda, n, ml, mu, ipvt, c(1,j), 0 )
      end do

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float ABD[LDA*N], the output from SGBCO or SGBFA.

    Input, integer LDA, the leading dimension of the array ABD.

    Input, int N, the order of the matrix.

    Input, int ML, MU, the number of diagonals below and above the
    main diagonal.  0 <= ML < N, 0 <= MU < N.

    Input, int IPVT[N], the pivot vector from SGBCO or SGBFA.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.

    Input, int JOB, job choice.
    0, solve A*X=B.
    nonzero, solve A'*X=B.
*/
{
  int k;
  int l;
  int la;
  int lb;
  int lm;
  int m;
  float t;

  m = mu + ml + 1;
/*
  JOB = 0, Solve A * x = b.

  First solve L * y = b.
*/
  if ( job == 0 )
  {
    if ( 0 < ml )
    {
      for ( k = 1; k <= n-1; k++ )
      {
        lm = i4_min ( ml, n-k );
        l = ipvt[k-1];
        t = b[l-1];
        if ( l != k )
        {
          b[l-1] = b[k-1];
          b[k-1] = t;
        }
        saxpy ( lm, t, abd+m+(k-1)*lda, 1, b+k, 1 );
      }
    }
/*
  Now solve U * x = y.
*/
    for ( k = n; 1 <= k; k-- )
    {
      b[k-1] = b[k-1] / abd[m-1+(k-1)*lda];
      lm = i4_min ( k, m ) - 1;
      la = m - lm;
      lb = k - lm;
      t = -b[k-1];
      saxpy ( lm, t, abd+la-1+(k-1)*lda, 1, b+lb-1, 1 );
    }
  }
/*
  JOB nonzero, solve A' * x = b.

  First solve U' * y = b.
*/
  else
  {
    for ( k = 1; k <= n; k++ )
    {
      lm = i4_min ( k, m ) - 1;
      la = m - lm;
      lb = k - lm;
      t = sdot ( lm, abd+la-1+(k-1)*lda, 1, b+lb-1, 1 );
      b[k-1] = ( b[k-1] - t ) / abd[m-1+(k-1)*lda];
    }
/*
  Now solve L' * x = y.
*/
    if ( 0 < ml )
    {
      for ( k = n-1; 1 <= k; k-- )
      {
        lm = i4_min ( ml, n-k );
        b[k-1] = b[k-1] + sdot ( lm, abd+m+(k-1)*lda, 1, b+k, 1 );
        l = ipvt[k-1];
        if ( l != k )
        {
          t = b[l-1];
          b[l-1] = b[k-1];
          b[k-1] = t;
        }
      }
    }
  }

  return;
}
/******************************************************************************/

float sgeco ( float a[], int lda, int n, int ipvt[], float z[] )

/******************************************************************************/
/*
  Purpose:

    SGECO factors a real matrix and estimates its condition number.

  Discussion:

    If RCOND is not needed, SGEFA is slightly faster.

    To solve A * X = B, follow SGECO by SGESL.

    To compute inverse ( A ) * C, follow SGECO by SGESL.

    To compute determinant ( A ), follow SGECO by SGEDI.

    To compute inverse ( A ), follow SGECO by SGEDI.

    For the system A * X = B, relative perturbations in A and B
    of size EPSILON may cause relative perturbations in X of size
    EPSILON/RCOND.

    If RCOND is so small that the logical expression
      1.0D+00 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate
    underflows.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, a matrix to be
    factored.  On output, the LU factorization of the matrix.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix A.

    Output, int IPVT[N], the pivot indices.

    Output, float Z[N], a work vector whose contents are usually
    unimportant.  If A is close to a singular matrix, then Z is an
    approximate null vector in the sense that
      norm ( A * Z ) = RCOND * norm ( A ) * norm ( Z ).

    Output, float SGECO, the value of RCOND, an estimate 
    of the reciprocal condition number of A.
*/
{
  float anorm;
  float ek;
  int i;
  int j;
  int k;
  int l;
  float rcond;
  float s;
  float sm;
  float t;
  float wk;
  float wkm;
  float ynorm;
/*
  Compute the L1 norm of A.
*/
  anorm = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    anorm = r4_max ( anorm, sasum ( n, a+0+(j-1)*lda, 1 ) );
  }
/*
  Compute the LU factorization.
*/
  sgefa ( a, lda, n, ipvt );
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
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }

  for ( k = 1; k <= n; k++ )
  {
    if ( 0.0 < z[k-1] )
    {
      ek = - ek;
    }

    if ( fabs ( a[k-1+(k-1)*lda] ) < fabs ( ek - z[k-1] ) )
    {
      s = fabs ( a[k-1+(k-1)*lda] ) / fabs ( ek - z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ek = s * ek;
    }

    wk = ek - z[k-1];
    wkm = -ek - z[k-1];
    s = fabs ( wk );
    sm = fabs ( wkm );

    if ( a[k-1+(k-1)*lda] != 0.0 )
    {
      wk = wk / a[k-1+(k-1)*lda];
      wkm = wkm / a[k-1+(k-1)*lda];
    }
    else
    {
      wk = 1.0;
      wkm = 1.0;
    }

    if ( k+1 <= n )
    {
      for ( j = k+1; j <= n; j++ )
      {
        sm = sm + fabs ( z[j-1] + wkm * a[k-1+(j-1)*lda] );
        z[j-1] = z[j-1] + wk * a[k-1+(j-1)*lda];
        s = s + fabs ( z[j-1] );
      }

      if ( s < sm )
      {
        t = wkm - wk;
        wk = wkm;
        for ( i = k+1; i <= n; i++ )
        {
          z[i-1] = z[i-1] + t * a[k-1+(i-1)*lda];
        }
      }
    }
    z[k-1] = wk;
  }

  t = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / t;
  }
/*
  Solve L' * Y = W
*/
  for ( k = n; 1 <= k; k-- )
  {
    z[k-1] = z[k-1] + sdot ( n - k, a+k+(k-1)*lda, 1, z+k, 1 );

    if ( 1.0 < fabs ( z[k-1] ) )
    {
      t = fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = z[i-1] / t;
      }
    }

    l = ipvt[k-1];

    t = z[l-1];
    z[l-1] = z[k-1];
    z[k-1] = t;
  }
  t = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / t;
  }

  ynorm = 1.0;
/*
  Solve L * V = Y.
*/
  for ( k = 1; k <= n; k++ )
  {
    l = ipvt[k-1];

    t = z[l-1];
    z[l-1] = z[k-1];
    z[k-1] = t;

    for ( i = k+1; i <= n; i++ )
    {
      z[i-1] = z[i-1] + t * a[i-1+(k-1)*lda];
    }

    if ( 1.0 < fabs ( z[k-1] ) )
    {
      ynorm = ynorm / fabs ( z[k-1] );
      t = fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = z[i-1] / t;
      }
    }
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
  ynorm = ynorm / s;
/*
  Solve U * Z = V.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( fabs ( a[k-1+(k-1)*lda] ) < fabs ( z[k-1] ) )
    {
      s = fabs ( a[k-1+(k-1)*lda] ) / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }

    if ( a[k-1+(k-1)*lda] != 0.0 )
    {
      z[k-1] = z[k-1] / a[k-1+(k-1)*lda];
    }
    else
    {
      z[k-1] = 1.0;
    }
    for ( i = 1; i <= k-1; i++ )
    {
      z[i-1] = z[i-1] - z[k-1] * a[i-1+(k-1)*lda];
    }
  }
/*
  Normalize Z in the L1 norm.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void sgedi ( float a[], int lda, int n, int ipvt[], float det[], 
  float work[], int job )

/******************************************************************************/
/*
  Purpose:

    SGEDI: determinant and inverse of a matrix factored by SGECO or SGEFA.

  Discussion:

    A division by zero will occur if the input factor contains
    a zero on the diagonal and the inverse is requested.
    It will not occur if the subroutines are called correctly
    and if SGECO has set 0.0 < RCOND or SGEFA has set INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N], on input, the LU factor information,
    as output by SGECO or SGEFA.  On output, the inverse
    matrix if requested.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix A.

    Input, int IPVT[N], the pivot vector from SGECO or SGEFA.

    Workspace, float WORK[N].

    Output, float DET[2], the determinant of original matrix if
    requested.  The determinant = DET[0] * pow ( 10.0, DET[1] )
    with  1.0 <= abs ( DET[0] ) < 10.0 or DET[0] == 0.0.

    Input, int JOB, specifies what is to be computed.
    11, both determinant and inverse.
    01, inverse only.
    10, determinant only.
*/
{
  int i;
  int j;
  int k;
  int l;
  float t;
/*
  Compute the determinant.
*/
  if ( job / 10 != 0 )
  {
    det[0] = 1.0;
    det[1] = 0.0;

    for ( i = 1; i <= n; i++ )
    {
      if ( ipvt[i-1] != i )
      {
        det[0] = -det[0];
      }
      det[0] = det[0] * a[i-1+(i-1)*lda];

      if ( det[0] == 0.0 )
      {
        break;
      }

      while ( fabs ( det[0] ) < 1.0 )
      {
        det[0] = det[0] * 10.0;
        det[1] = det[1] - 1.0;
      }
      while ( 10.0 <= fabs ( det[0] ) )
      {
        det[0] = det[0] / 10.0;
        det[1] = det[1] + 1.0;
      }
    }
  }
/*
  Compute inverse(U).
*/
  if ( ( job % 10 ) != 0 )
  {
    for ( k = 1; k <= n; k++ )
    {
      a[k-1+(k-1)*lda] = 1.0 / a[k-1+(k-1)*lda];
      t = -a[k-1+(k-1)*lda];
      sscal ( k-1, t, a+0+(k-1)*lda, 1 );

      for ( j = k+1; j <= n; j++ )
      {
        t = a[k-1+(j-1)*lda];
        a[k-1+(j-1)*lda] = 0.0;
        saxpy ( k, t, a+0+(k-1)*lda, 1, a+0+(j-1)*lda, 1 );
      }
    }
/*
  Form inverse(U) * inverse(L).
*/
    for ( k = n-1; 1 <= k; k-- )
    {
      for ( i = k+1; i <= n; i++ )
      {
        work[i-1] = a[i-1+(k-1)*lda];
        a[i-1+(k-1)*lda] = 0.0;
      }

      for ( j = k+1; j <= n; j++ )
      {
        t = work[j-1];
        saxpy ( n, t, a+0+(j-1)*lda, 1, a+0+(k-1)*lda, 1 );
      }

      l = ipvt[k-1];
      if ( l != k )
      {
        sswap ( n, a+0+(k-1)*lda, 1, a+0+(l-1)*lda, 1 );
      }
    }
  }

  return;
}
/******************************************************************************/

int sgefa ( float a[], int lda, int n, int ipvt[] )

/******************************************************************************/
/*
  Purpose:

    SGEFA factors a real general matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].
    On intput, the matrix to be factored.
    On output, an upper triangular matrix and the multipliers used to obtain
    it.  The factorization can be written A=L*U, where L is a product of
    permutation and unit lower triangular matrices, and U is upper triangular.

    Input, int LDA, the leading dimension of A.

    Input, int N, the order of the matrix A.

    Output, int IPVT[N], the pivot indices.

    Output, int SGEFA, singularity indicator.
    0, normal value.
    K, if U(K,K) == 0.  This is not an error condition for this subroutine,
    but it does indicate that SGESL or SGEDI will divide by zero if called.
    Use RCOND in SGECO for a reliable indication of singularity.
*/
{
  int info;
  int j;
  int k;
  int l;
  float t;
/*
  Gaussian elimination with partial pivoting.
*/
  info = 0;

  for ( k = 1; k <= n-1; k++ )
  {
/*
  Find L = pivot index.
*/
    l = isamax ( n-k+1, a+(k-1)+(k-1)*lda, 1 ) + k - 1;
    ipvt[k-1] = l;
/*
  Zero pivot implies this column already triangularized.
*/
    if ( a[l-1+(k-1)*lda] == 0.0 )
    {
      info = k;
      continue;
    }
/*
  Interchange if necessary.
*/
    if ( l != k )
    {
      t = a[l-1+(k-1)*lda];
      a[l-1+(k-1)*lda] = a[k-1+(k-1)*lda];
      a[k-1+(k-1)*lda] = t;
    }
/*
  Compute multipliers.
*/
    t = -1.0 / a[k-1+(k-1)*lda];

    sscal ( n-k, t, a+k+(k-1)*lda, 1 );
/*
  Row elimination with column indexing.
*/
    for ( j = k+1; j <= n; j++ )
    {
      t = a[l-1+(j-1)*lda];
      if ( l != k )
      {
        a[l-1+(j-1)*lda] = a[k-1+(j-1)*lda];
        a[k-1+(j-1)*lda] = t;
      }
      saxpy ( n-k, t, a+k+(k-1)*lda, 1, a+k+(j-1)*lda, 1 );
    }

  }

  ipvt[n-1] = n;

  if ( a[n-1+(n-1)*lda] == 0.0 )
  {
    info = n;
  }

  return info;
}
/******************************************************************************/

void sgesl ( float a[], int lda, int n, int ipvt[], float b[], int job )

/******************************************************************************/
/*
  Purpose:

    SGESL solves a real general linear system A * X = B.

  Discussion:

    SGESL can solve either of the systems A * X = B or A' * X = B.

    The system matrix must have been factored by SGECO or SGEFA.

    A division by zero will occur if the input factor contains a
    zero on the diagonal.  Technically this indicates singularity
    but it is often caused by improper arguments or improper
    setting of LDA.  It will not occur if the subroutines are
    called correctly and if SGECO has set 0.0 < RCOND
    or SGEFA has set INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float A[LDA*N], the output from SGECO or SGEFA.

    Input, int LDA, the leading dimension of A.

    Input, int N, the order of the matrix A.

    Input, int IPVT[N], the pivot vector from SGECO or SGEFA.

    Input/output, float B[N].
    On input, the right hand side vector.
    On output, the solution vector.

    Input, int JOB.
    0, solve A * X = B;
    nonzero, solve A' * X = B.
*/
{
  int k;
  int l;
  float t;
/*
  Solve A * X = B.
*/
  if ( job == 0 )
  {
    for ( k = 1; k <= n-1; k++ )
    {
      l = ipvt[k-1];
      t = b[l-1];

      if ( l != k )
      {
        b[l-1] = b[k-1];
        b[k-1] = t;
      }

      saxpy ( n-k, t, a+k+(k-1)*lda, 1, b+k, 1 );

    }

    for ( k = n; 1 <= k; k-- )
    {
      b[k-1] = b[k-1] / a[k-1+(k-1)*lda];
      t = -b[k-1];
      saxpy ( k-1, t, a+0+(k-1)*lda, 1, b, 1 );
    }
  }
/*
  Solve A' * X = B.
*/
  else
  {
    for ( k = 1; k <= n; k++ )
    {
      t = sdot ( k-1, a+0+(k-1)*lda, 1, b, 1 );
      b[k-1] = ( b[k-1] - t ) / a[k-1+(k-1)*lda];
    }

    for ( k = n-1; 1 <= k; k-- )
    {
      b[k-1] = b[k-1] + sdot ( n-k, a+k+(k-1)*lda, 1, b+k, 1 );
      l = ipvt[k-1];

      if ( l != k )
      {
        t = b[l-1];
        b[l-1] = b[k-1];
        b[k-1] = t;
      }
    }
  }
  return;
}
/******************************************************************************/

int sgtsl ( int n, float c[], float d[], float e[], float b[] )

/******************************************************************************/
/*
  Purpose:

    SGTSL solves a general tridiagonal linear system.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, int N, the order of the tridiagonal matrix.

    Input/output, float C[N], contains the subdiagonal of the
    tridiagonal matrix in entries C(2:N).  On output, C is destroyed.

    Input/output, float D[N].  On input, the diagonal of the
    matrix.  On output, D is destroyed.

    Input/output, float E[N], contains the superdiagonal of the
    tridiagonal matrix in entries E(1:N-1).  On output E is destroyed.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.

    Output, int SGTSL, error flag.
    0, normal value.
    K, the K-th element of the diagonal becomes exactly zero.  The
       subroutine returns if this error condition is detected.
*/
{
  int info;
  int k;
  float t;

  info = 0;
  c[0] = d[0];

  if ( 2 <= n )
  {
    d[0] = e[0];
    e[0] = 0.0;
    e[n-1] = 0.0;

    for ( k = 1; k <= n - 1; k++ )
    {
/*
  Find the larger of the two rows.
*/
      if ( fabs ( c[k-1] ) <= fabs ( c[k] ) )
      {
/*
  Interchange rows.
*/
        t = c[k];
        c[k] = c[k-1];
        c[k-1] = t;

        t = d[k];
        d[k] = d[k-1];
        d[k-1] = t;

        t = e[k];
        e[k] = e[k-1];
        e[k-1] = t;

        t = b[k];
        b[k] = b[k-1];
        b[k-1] = t;
      }
/*
  Zero elements.
*/
      if ( c[k-1] == 0.0 )
      {
        info = k;
        return info;
      }

      t = -c[k] / c[k-1];
      c[k] = d[k] + t * d[k-1];
      d[k] = e[k] + t * e[k-1];
      e[k] = 0.0;
      b[k] = b[k] + t * b[k-1];
    }
  }

  if ( c[n-1] == 0.0 )
  {
    info = n;
    return info;
  }
/*
  Back solve.
*/
  b[n-1] = b[n-1] / c[n-1];

  if ( 1 < n )
  {
    b[n-2] = ( b[n-2] - d[n-2] * b[n-1] ) / c[n-2];

    for ( k = n - 2; 1 <= k; k-- )
    {
      b[k-1] = ( b[k-1] - d[k-1] * b[k] - e[k-1] * b[k+1] ) / c[k-1];
    }

  }

  return info;
}
/******************************************************************************/

float spbco ( float abd[], int lda, int n, int m, float z[] )

/******************************************************************************/
/*
  Purpose:

    SPBCO factors a real symmetric positive definite banded matrix.

  Discussion:

    SPBCO also estimates the condition of the matrix.

    If RCOND is not needed, SPBFA is slightly faster.

    To solve A*X = B, follow SPBCO by SPBSL.

    To compute inverse(A)*C, follow SPBCO by SPBSL.

    To compute determinant(A), follow SPBCO by SPBDI.

  Band storage:

    If A is a symmetric positive definite band matrix, the following
    program segment will set up the input.

      m = (band width above diagonal)
      do j = 1, n
        i1 = max (1, j-m)
        do i = i1, j
          k = i-j+m+1
          abd(k,j) = a(i,j)
        }
      }

    This uses M + 1 rows of A, except for the M by M upper left triangle,
    which is ignored.

    For example, if the original matrix is

      11 12 13  0  0  0
      12 22 23 24  0  0
      13 23 33 34 35  0
       0 24 34 44 45 46
       0  0 35 45 55 56
       0  0  0 46 56 66

    then N = 6, M = 2  and ABD should contain

       *  * 13 24 35 46
       * 12 23 34 45 56
      11 22 33 44 55 66

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float ABD[LDA*N].  On input, the matrix to be
    factored.  The columns of the upper triangle are stored in the columns
    of ABD and the diagonals of the upper triangle are stored in the rows
    of ABD.  On output, an upper triangular matrix R, stored in band form,
    so that A = R'*R.  If INFO /= 0, the factorization is not complete.

    Input, int LDA, the leading dimension of the array ABD.
    M+1 <= LDA is required.

    Input, int N, the order of the matrix.

    Input, int M, the number of diagonals above the main diagonal.

    Output, float Z[N], a work vector whose contents are usually
    unimportant.  If A is singular to working precision, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).
    If INFO /= 0, Z is unchanged.

    Output, float SPBCO, an estimate of the reciprocal condition number
    RCOND.  For the system A*X = B, relative perturbations in A and B of size
    EPSILON may cause relative perturbations in X of size EPSILON/RCOND.
    If RCOND is so small that the logical expression
      1.0 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float anorm;
  float ek;
  int i;
  int info;
  int j;
  int j2;
  int k;
  int l;
  int la;
  int lb;
  int lm;
  int mu;
  float rcond;
  float s;
  float sm;
  float t;
  float wk;
  float wkm;
  float ynorm;
/*
  Find the norm of A.
*/
  for ( j = 1; j <= n; j++ )
  {
    l = i4_min ( j, m+1 );
    mu = i4_max ( m+2-j, 1 );
    z[j-1] = sasum ( l, abd+mu-1+(j-1)*lda, 1 );
    k = j - l;
    for ( i = mu; i <= m; i++ )
    {
      k = k + 1;
      z[k-1] = z[k-1] + fabs ( abd[i-1+(j-1)*lda] );
    }
  }
  anorm = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    anorm = r4_max ( anorm, z[i-1] );
  }
/*
  Factor.
*/
  info = spbfa ( abd, lda, n, m );

  if ( info != 0 )
  {
    rcond = 0.0;
    return rcond;
  }
/*
  RCOND = 1/(norm(A)*(estimate of norm(inverse(A)))).

  Estimate = norm(Z)/norm(Y) where A*Z = Y and A*Y = E.

  The components of E are chosen to cause maximum local
  growth in the elements of W where R'*W = E.

  The vectors are frequently rescaled to avoid overflow.

  Solve R' * W = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }

  for ( k = 1; k <= n; k++ )
  {
    if ( 0.0 < z[k-1] )
    {
      ek = - ek;
    }

    if ( abd[m+(k-1)*lda] < fabs ( ek - z[k-1] ) )
    {
      s = abd[m+(k-1)*lda] / fabs ( ek - z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ek = s * ek;
    }
    wk = ek - z[k-1];
    wkm = -ek - z[k-1];
    s = fabs ( wk );
    sm = fabs ( wkm );
    wk = wk / abd[m+(k-1)*lda];
    wkm = wkm / abd[m+(k-1)*lda];
    j2 = i4_min ( k+m, n );
    i = m + 1;

    if ( k+1 <= j2 )
    {
      for ( j = k+1; j <= j2; j++ )
      {
        i = i - 1;
        sm = sm + fabs ( z[j-1] + wkm * abd[i-1+(j-1)*lda] );
        z[j-1] = z[j-1] + wk * abd[i-1+(j-1)*lda];
        s = s + fabs ( z[j-1] );
      }

      if ( s < sm )
      {
        t = wkm - wk;
        wk = wkm;
        i = m + 1;

        for ( j = k+1; j <= j2; j++ )
        {
          i = i - 1;
          z[j-1] = z[j-1] + t * abd[i-1+(j-1)*lda];
        }
      }
    }
    z[k-1] = wk;
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
/*
  Solve R * Y = W.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( abd[m+(k-1)*lda] < fabs ( z[k-1] ) )
    {
      s = abd[m+(k-1)*lda] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
    }
    z[k-1] = z[k-1] / abd[m+(k-1)*lda];
    lm = i4_min ( k-1, m );
    la = m + 1 - lm;
    lb = k - lm;
    t = -z[k-1];
    saxpy ( lm, t, abd+la-1+(k-1)*lda, 1, z+lb-1, 1 );
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
  ynorm = 1.0;
/*
  Solve R' * V = Y.
*/
  for ( k = 1; k <= n; k++ )
  {
    lm = i4_min ( k-1, m );
    la = m + 1 - lm;
    lb = k - lm;

    z[k-1] = z[k-1] - sdot ( lm, abd+la-1+(k-1)*lda, 1, z+lb-1, 1 );

    if ( abd[m+(k-1)*lda] < fabs ( z[k-1] ) )
    {
      s = abd[m+(k-1)*lda] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }
    z[k-1] = z[k-1] / abd[m+(k-1)*lda];
  }
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;
/*
  Solve R * Z = W.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( abd[m+(k-1)*lda] < fabs ( z[k-1] ) )
    {
      s = abd[m+(k-1)*lda] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }
    z[k-1] = z[k-1] / abd[m+(k-1)*lda];
    lm = i4_min ( k-1, m );
    la = m + 1 - lm;
    lb = k - lm;
    t = -z[k-1];
    saxpy ( lm, t, abd+la-1+(k-1)*lda, 1, z+lb-1, 1 );
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void spbdi ( float abd[], int lda, int n, int m, float det[] )

/******************************************************************************/
/*
  Purpose:

    SPBDI computes the determinant of a matrix factored by SPBCO or SPBFA.

  Discussion:

    If the inverse is needed, use SPBSL N times.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float ABD[LDA*N], the output from SPBCO or SPBFA.

    Input, int LDA, the leading dimension of the array ABD.

    Input, int N, the order of the matrix.

    Input, int M, the number of diagonals above the main diagonal.

    Output, float DET[2], the determinant of the original
    matrix in the form
      determinant = DET[0] * 10.0**DET[1]
    with 1.0D+00 <= DET[0] < 10.0D+00 or DET[0] == 0.0D+00.
*/
{
  int i;
  float s;
/*
  Compute the determinant.
*/
  det[0] = 1.0;
  det[1] = 0.0;
  s = 10.0;

  for ( i = 1; i <= n; i++ )
  {
    det[0] = det[0] * abd[m+(i-1)*lda] * abd[m+(i-1)*lda];

    if ( det[0] == 0.0 )
    {
      return;
    }

    while ( det[0] < 1.0 )
    {
      det[0] = det[0] * s;
      det[1] = det[1] - 1.0;
    }

    while ( s <= det[0] )
    {
      det[0] = det[0] / s;
      det[1] = det[1] + 1.0;
    }

  }

  return;
}
/******************************************************************************/

int spbfa ( float abd[], int lda, int n, int m )

/******************************************************************************/
/*
  Purpose:

    SPBFA factors a symmetric positive definite matrix stored in band form.

  Discussion:

    SPBFA is usually called by SPBCO, but it can be called
    directly with a saving in time if RCOND is not needed.

    If A is a symmetric positive definite band matrix,
    the following program segment will set up the input.

      m = (band width above diagonal)
      do j = 1, n
        i1 = max ( 1, j-m )
        do i = i1, j
          k = i-j+m+1
          abd(k,j) = a(i,j)
        end do
      end do

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 May 2005

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float ABD[LDA*N].  On input, the matrix to be
    factored.  The columns of the upper triangle are stored in the columns
    of ABD and the diagonals of the upper triangle are stored in the
    rows of ABD.  On output, an upper triangular matrix R, stored in band
    form, so that A = R' * R.

    Input, int LDA, the leading dimension of the array ABD.
    M+1 <= LDA is required.

    Input, int N, the order of the matrix.

    Input, int M, the number of diagonals above the main diagonal.

    Output, int SPBFA, error indicator.
    0, for normal return.
    K, if the leading minor of order K is not positive definite.
*/
{
  int ik;
  int info;
  int j;
  int jk;
  int k;
  int mu;
  float s;
  float t;

  for ( j = 1; j <= n; j++ )
  {
    s = 0.0;
    ik = m + 1;
    jk = i4_max ( j - m, 1 );
    mu = i4_max ( m + 2 - j, 1 );

    for ( k = mu; k <= m; k++ )
    {
      t = abd[k-1+(j-1)*lda] 
        - sdot ( k-mu, abd+ik-1+(jk-1)*lda, 1, abd+mu-1+(j-1)*lda, 1 );
      t = t / abd[m+(jk-1)*lda];
      abd[k-1+(j-1)*lda] = t;
      s = s + t * t;
      ik = ik - 1;
      jk = jk + 1;
    }
    s = abd[m+(j-1)*lda] - s;

    if ( s <= 0.0 )
    {
      info = j;
      return info;
    }
    abd[m+(j-1)*lda] = sqrt ( s );
  }
  info = 0;

  return info;
}
/******************************************************************************/

void spbsl ( float abd[], int lda, int n, int m, float b[] )

/******************************************************************************/
/*
  Purpose:

    SPBSL solves a real SPD band system factored by SPBCO or SPBFA.

  Discussion:

    The matrix is assumed to be a symmetric positive definite (SPD)
    band matrix.

    To compute inverse(A) * C  where C is a matrix with P columns:

      call spbco ( abd, lda, n, rcond, z, info )

      if ( rcond is too small .or. info /= 0) go to ...

      do j = 1, p
        call spbsl ( abd, lda, n, c(1,j) )
      end do

    A division by zero will occur if the input factor contains
    a zero on the diagonal.  Technically this indicates
    singularity but it is usually caused by improper subroutine
    arguments.  It will not occur if the subroutines are called
    correctly and INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float ABD[LDA*N], the output from SPBCO or SPBFA.

    Input, int LDA, the leading dimension of the array ABD.

    Input, int N, the order of the matrix.

    Input, int M, the number of diagonals above the main diagonal.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.
*/
{
  int k;
  int la;
  int lb;
  int lm;
  float t;
/*
  Solve R'*Y = B.
*/
  for ( k = 1; k <= n; k++ )
  {
    lm = i4_min ( k-1, m );
    la = m + 1 - lm;
    lb = k - lm;
    t = sdot ( lm, abd+la-1+(k-1)*lda, 1, b+lb-1, 1 );
    b[k-1] = ( b[k-1] - t ) / abd[m+(k-1)*lda];
  }
/*
  Solve R*X = Y.
*/
  for ( k = n; 1 <= k; k-- )
  {
    lm = i4_min ( k-1, m );
    la = m + 1 - lm;
    lb = k - lm;
    b[k-1] = b[k-1] / abd[m+(k-1)*lda];
    t = -b[k-1];
    saxpy ( lm, t, abd+la-1+(k-1)*lda, 1, b+lb-1, 1 );
  }

  return;
}
/******************************************************************************/

float spoco ( float a[], int lda, int n, float z[] )

/******************************************************************************/
/*
  Purpose:

    SPOCO factors a real symmetric positive definite matrix and estimates its condition.

  Discussion:

    If RCOND is not needed, SPOFA is slightly faster.

    To solve A*X = B, follow SPOCO by SPOSL.

    To compute inverse(A)*C, follow SPOCO by SPOSL.

    To compute determinant(A), follow SPOCO by SPODI.

    To compute inverse(A), follow SPOCO by SPODI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, the symmetric
    matrix to be factored.  Only the diagonal and upper triangle are used.
    On output, an upper triangular matrix R so that A = R'*R where R'
    is the transpose.  The strict lower triangle is unaltered.
    If INFO /= 0, the factorization is not complete.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Output, float Z[N], a work vector whose contents are usually
    unimportant.  If A is close to a singular matrix, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).
    If INFO /= 0, Z is unchanged.

    Output, float SPOCO, an estimate of the reciprocal
    condition of A.  For the system A*X = B, relative perturbations in
    A and B of size EPSILON may cause relative perturbations in X of
    size EPSILON/RCOND.  If RCOND is so small that the logical expression
      1.0D+00 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float anorm;
  float ek;
  int i;
  int info;
  int j;
  int k;
  float rcond;
  float s;
  float sm;
  float t;
  float wk;
  float wkm;
  float ynorm;
/*
  Find norm of A using only upper half.
*/
  for ( j = 1; j <= n; j++ )
  {
    z[j-1] = sasum ( j, a+0+(j-1)*lda, 1 );
    for ( i = 1; i <= j-1; i++ )
    {
      z[i-1] = z[i-1] + fabs ( a[i-1+(j-1)*lda] );
    }
  }

  anorm = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    anorm = r4_max ( anorm, z[i-1] );
  }
/*
  Factor.
*/
  info = spofa ( a, lda, n );

  if ( info != 0 )
  {
    rcond = 0.0;
    return rcond;
  }
/*
  RCOND = 1/(norm(A)*(estimate of norm(inverse(A)))).

  Estimate = norm(Z)/norm(Y) where A*Z = Y and A*Y = E.

  The components of E are chosen to cause maximum local
  growth in the elements of W where R'*W = E.

  The vectors are frequently rescaled to avoid overflow.

  Solve R' * W = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }

  for ( k = 1; k <= n; k++ )
  {
    if ( 0.0 < z[k-1] )
    {
      ek = - ek;
    }

    if ( a[k-1+(k-1)*lda] < fabs ( ek - z[k-1] ) )
    {
      s = a[k-1+(k-1)*lda] / fabs ( ek - z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ek = s * ek;
    }

    wk = ek - z[k-1];
    wkm = -ek - z[k-1];
    s = fabs ( wk );
    sm = fabs ( wkm );
    wk = wk / a[k-1+(k-1)*lda];
    wkm = wkm / a[k-1+(k-1)*lda];

    if ( k + 1 <= n )
    {
      for ( j = k+1; j <= n; j++ )
      {
        sm = sm + fabs ( z[j-1] + wkm * a[k-1+(j-1)*lda] );
        z[j-1] = z[j-1] + wk * a[k-1+(j-1)*lda];
        s = s + fabs ( z[j-1] );
      }

      if ( s < sm )
      {
        t = wkm - wk;
        wk = wkm;
        for ( j = k+1; j <= n; j++ )
        {
          z[j-1] = z[j-1] + t * a[k-1+(j-1)*lda];
        }
      }
    }
    z[k-1] = wk;
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
/*
  Solve R * Y = W.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( a[k-1+(k-1)*lda] < fabs ( z[k-1] ) )
    {
      s = a[k-1+(k-1)*lda] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
    }
    z[k-1] = z[k-1] / a[k-1+(k-1)*lda];
    t = -z[k-1];
    saxpy ( k-1, t, a+0+(k-1)*lda, 1, z, 1 );
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
  ynorm = 1.0;
/*
  Solve R' * V = Y.
*/
  for ( k = 1; k <= n; k++ )
  {
    z[k-1] = z[k-1] - sdot ( k-1, a+0+(k-1)*lda, 1, z, 1 );

    if ( a[k-1+(k-1)*lda] < fabs ( z[k-1] ) )
    {
      s = a[k-1+(k-1)*lda] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }
    z[k-1] = z[k-1] / a[k-1+(k-1)*lda];
  }
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;
/*
  Solve R * Z = V.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( a[k-1+(k-1)*lda] < fabs ( z[k-1] ) )
    {
      s = a[k-1+(k-1)*lda] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }
    z[k-1] = z[k-1] / a[k-1+(k-1)*lda];
    t = -z[k-1];
    saxpy ( k-1, t, a+0+(k-1)*lda, 1, z, 1 );
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void spodi ( float a[], int lda, int n, float det[], int job )

/******************************************************************************/
/*
  Purpose:

    SPODI computes the determinant and inverse of a certain matrix.

  Discussion:

    The matrix is real symmetric positive definite.
    SPODI uses the factors computed by SPOCO, SPOFA or SQRDC.

    A division by zero will occur if the input factor contains
    a zero on the diagonal and the inverse is requested.
    It will not occur if the subroutines are called correctly
    and if SPOCO or SPOFA has set INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, the output A from
    SPOCO or SPOFA, or the output X from SQRDC.  On output, if SPOCO or
    SPOFA was used to factor A then SPODI produces the upper half of
    inverse(A).  If SQRDC was used to decompose X then SPODI produces
    the upper half of inverse(X'*X) where X' is the transpose.
    Elements of A below the diagonal are unchanged.  If the units digit
    of JOB is zero, A is unchanged.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix A.

    Input, int JOB, specifies the task.
    11, both determinant and inverse.
    01, inverse only.
    10, determinant only.

    Output, float DET[2], the determinant of A or of X'*X
    if requested.
      determinant = DET[0] * 10.0**DET[1]
    with 1.0D+00 <= DET[0] < 10.0D+00 or DET[0] == 0.0D+00.
*/
{
  int i;
  int j;
  int k;
  float s;
  float t;
/*
  Compute the determinant.
*/
  if ( job / 10 != 0 )
  {
    det[0] = 1.0;
    det[1] = 0.0;
    s = 10.0;

    for ( i = 1; i <= n; i++ )
    {
      det[0] = det[0] * a[i-1+(i-1)*lda] * a[i-1+(i-1)*lda];

      if ( det[0] == 0.0 )
      {
        break;
      }

      while ( det[0] < 1.0 )
      {
        det[0] = det[0] * s;
        det[1] = det[1] - 1.0;
      }

      while ( s <= det[0] )
      {
        det[0] = det[0] / s;
        det[1] = det[1] + 1.0;
      }
    }
  }
/*
  Compute inverse(R).
*/
  if ( ( job % 10 ) != 0 )
  {
    for ( k = 1; k <= n; k++ )
    {
      a[k-1+(k-1)*lda] = 1.0 / a[k-1+(k-1)*lda];
      t = -a[k-1+(k-1)*lda];
      sscal ( k-1, t, a+0+(k-1)*lda, 1 );

      for ( j = k+1; j <= n; j++ )
      {
        t = a[k-1+(j-1)*lda];
        a[k-1+(j-1)*lda] = 0.0;
        saxpy ( k, t, a+0+(k-1)*lda, 1, a+0+(j-1)*lda, 1 );
      }
    }
/*
  Form inverse(R) * (inverse(R))'.
*/
    for ( j = 1; j <= n; j++ )
    {
      for ( k = 1; k <= j-1; k++ )
      {
        t = a[k-1+(j-1)*lda];
        saxpy ( k, t, a+0+(j-1)*lda, 1, a+0+(k-1)*lda, 1 );
      }
      t = a[j-1+(j-1)*lda];
      sscal ( j, t, a+0+(j-1)*lda, 1 );
    }
  }

  return;
}
/******************************************************************************/

int spofa ( float a[], int lda, int n )

/******************************************************************************/
/*
  Purpose:

    SPOFA factors a real symmetric positive definite matrix.

  Discussion:

    SPOFA is usually called by SPOCO, but it can be called
    directly with a saving in time if RCOND is not needed.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, the symmetric matrix
    to be  factored.  Only the diagonal and upper triangle are used.
    On output, an upper triangular matrix R so that A = R'*R
    where R' is the transpose.  The strict lower triangle is unaltered.
    If INFO /= 0, the factorization is not complete.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Output, int SPOFA, error flag.
    0, for normal return.
    K, signals an error condition.  The leading minor of order K is not
    positive definite.
*/
{
  int info;
  int j;
  int k;
  float s;
  float t;

  for ( j = 1; j <= n; j++ )
  {
    s = 0.0;

    for ( k = 1; k <= j-1; k++ )
    {
      t = a[k-1+(j-1)*lda] - sdot ( k-1, a+0+(k-1)*lda, 1, a+0+(j-1)*lda, 1 );
      t = t / a[k-1+(k-1)*lda];
      a[k-1+(j-1)*lda] = t;
      s = s + t * t;
    }

    s = a[j-1+(j-1)*lda] - s;

    if ( s <= 0.0 )
    {
      info = j;
      return info;
    }

    a[j-1+(j-1)*lda] = sqrt ( s );
  }

  info = 0;

  return info;
}
/******************************************************************************/

void sposl ( float a[], int lda, int n, float b[] )

/******************************************************************************/
/*
  Purpose:

    SPOSL solves a linear system factored by SPOCO or SPOFA.

  Discussion:

    To compute inverse(A) * C where C is a matrix with P columns:

      call spoco ( a, lda, n, rcond, z, info )

      if ( rcond is not too small .and. info == 0 ) then
        do j = 1, p
          call sposl ( a, lda, n, c(1,j) )
        end do
      end if

    A division by zero will occur if the input factor contains
    a zero on the diagonal.  Technically this indicates
    singularity but it is usually caused by improper subroutine
    arguments.  It will not occur if the subroutines are called
    correctly and INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float A[LDA*N], the output from SPOCO or SPOFA.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.
*/
{
  int k;
  float t;
/*
  Solve R' * Y = B.
*/
  for ( k = 1; k <= n; k++ )
  {
    t = sdot ( k-1, a+0+(k-1)*lda, 1, b, 1 );
    b[k-1] = ( b[k-1] - t ) / a[k-1+(k-1)*lda];
  }
/*
  Solve R * X = Y.
*/
  for ( k = n; 1 <= k; k-- )
  {
    b[k-1] = b[k-1] / a[k-1+(k-1)*lda];
    t = -b[k-1];
    saxpy ( k-1, t, a+0+(k-1)*lda, 1, b, 1 );
  }

  return;
}
/******************************************************************************/

float sppco ( float ap[], int n, float z[] )

/******************************************************************************/
/*
  Purpose:

    SPPCO factors a real symmetric positive definite matrix in packed form.

  Discussion:

    SPPCO also estimates the condition of the matrix.

    If RCOND is not needed, SPPFA is slightly faster.

    To solve A*X = B, follow SPPCO by SPPSL.

    To compute inverse(A)*C, follow SPPCO by SPPSL.

    To compute determinant(A), follow SPPCO by SPPDI.

    To compute inverse(A), follow SPPCO by SPPDI.

  Packed storage:

    The following program segment will pack the upper triangle of
    a symmetric matrix.

      k = 0
      do j = 1, n
        do i = 1, j
          k = k + 1
          ap[k-1] = a(i,j)
        }
      }

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float AP[N*(N+1)/2].  On input, the packed
    form of a symmetric matrix A.  The columns of the upper triangle are
    stored sequentially in a one-dimensional array.  On output, an upper
    triangular matrix R, stored in packed form, so that A = R'*R.
    If INFO /= 0, the factorization is not complete.

    Input, int N, the order of the matrix.

    Output, float Z[N], a work vector whose contents are usually
    unimportant.  If A is singular to working precision, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).
    If INFO /= 0, Z is unchanged.

    Output, float SPPCO, an estimate of the reciprocal condition number RCOND
    of A.  For the system A*X = B, relative perturbations in A and B of size
    EPSILON may cause relative perturbations in X of size EPSILON/RCOND.
    If RCOND is so small that the logical expression
      1.0 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float anorm;
  float ek;
  int i;
  int ij;
  int info;
  int j;
  int j1;
  int k;
  int kj;
  int kk;
  float rcond;
  float s;
  float sm;
  float t;
  float wk;
  float wkm;
  float ynorm;
/*
  Find the norm of A.
*/
  j1 = 1;
  for ( j = 1; j <= n; j++ )
  {
    z[j-1] = sasum ( j, ap+j1-1, 1 );
    ij = j1;
    j1 = j1 + j;
    for ( i = 1; i <= j-1; i++ )
    {
      z[i-1] = z[i-1] + fabs ( ap[ij-1] );
      ij = ij + 1;
    }
  }
  anorm = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    anorm = r4_max ( anorm, z[i-1] );
  }
/*
  Factor.
*/
  info = sppfa ( ap, n );

  if ( info != 0 )
  {
    rcond = 0.0;
    return rcond;
  }
/*
  RCOND = 1/(norm(A)*(estimate of norm(inverse(A)))).

  Estimate = norm(Z)/norm(Y) where A * Z = Y and A * Y = E.

  The components of E are chosen to cause maximum local
  growth in the elements of W where R'*W = E.

  The vectors are frequently rescaled to avoid overflow.

  Solve R' * W = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }

  kk = 0;

  for ( k = 1; k <= n; k++ )
  {
    kk = kk + k;

    if ( 0.0 < z[k-1] )
    {
      ek = - ek;
    }

    if ( ap[kk-1] < fabs ( ek - z[k-1] ) )
    {
      s = ap[kk-1] / fabs ( ek - z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ek = s * ek;
    }
    wk = ek - z[k-1];
    wkm = -ek - z[k-1];
    s = fabs ( wk );
    sm = fabs ( wkm );
    wk = wk / ap[kk-1];
    wkm = wkm / ap[kk-1];
    kj = kk + k;

    if ( k + 1 <= n )
    {
      for ( j = k + 1; j <= n; j++ )
      {
        sm = sm + fabs ( z[j-1] + wkm * ap[kj-1] );
        z[j-1] = z[j-1] + wk * ap[kj-1];
        s = s + fabs ( z[j-1] );
        kj = kj + j;
      }

      if ( s < sm )
      {
        t = wkm - wk;
        wk = wkm;
        kj = kk + k;

        for ( j = k+1; j <= n; j++ )
        {
          z[j-1] = z[j-1] + t * ap[kj-1];
          kj = kj + j;
        }
      }
    }
    z[k-1] = wk;
  }

  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
/*
  Solve R * Y = W.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( ap[kk-1] < fabs ( z[k-1] ) )
    {
      s = ap[kk-1] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
    }
    z[k-1] = z[k-1] / ap[kk-1];
    kk = kk - k;
    t = -z[k-1];
    saxpy ( k-1, t, ap+kk, 1, z, 1 );
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
  ynorm = 1.0;
/*
  Solve R' * V = Y.
*/
  for ( k = 1; k <= n; k++ )
  {
    z[k-1] = z[k-1] - sdot ( k-1, ap+kk, 1, z, 1 );
    kk = kk + k;

    if ( ap[kk-1] < fabs ( z[k-1] ) )
    {
      s = ap[kk-1] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }

    z[k-1] = z[k-1] / ap[kk-1];
  }
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;
/*
  Solve R * Z = V.
*/
  for ( k = n; 1 <= k; k-- )
  {
    if ( ap[kk-1] < fabs ( z[k-1] ) )
    {
      s = ap[kk-1] / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }
    z[k-1] = z[k-1] / ap[kk-1];
    kk = kk - k;
    t = -z[k-1];
    saxpy ( k-1, t, ap+kk, 1, z, 1 );
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void sppdi ( float ap[], int n, float det[2], int job )

/******************************************************************************/
/*
  Purpose:

    SPPDI: determinant and inverse of a matrix factored by SPPCO or SPPFA.

  Discussion:

    A division by zero will occur if the input factor contains
    a zero on the diagonal and the inverse is requested.
    It will not occur if the subroutines are called correctly
    and if SPOCO or SPOFA has set INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float AP[N*(N+1)/2].  On input, the output from
    SPPCO or SPPFA.  On output, the upper triangular half of the
    inverse, if requested.

    Input, int N, the order of the matrix.

    Output, float DET[2], the determinant of the original matrix
    if requested.
      determinant = DET[0] * 10.0**DET[1]
    with  1.0D+00 <= DET[0] < 10.0D+00 or DET[0] == 0.0D+00.

    Input, int JOB, job request.
    11, both determinant and inverse.
    01, inverse only.
    10, determinant only.
*/
{
  int i;
  int ii;
  int j;
  int j1;
  int jj;
  int k;
  int k1;
  int kj;
  int kk;
  float s;
  float t;
/*
  Compute the determinant.
*/
  if ( job / 10 != 0 )
  {
    det[0] = 1.0;
    det[1] = 0.0;
    s = 10.0;
    ii = 0;

    for ( i = 1; i <= n; i++ )
    {
      ii = ii + i;

      det[0] = det[0] * ap[ii-1] * ap[ii-1];

      if ( det[0] == 0.0 )
      {
        break;
      }

      while ( det[0] < 1.0 )
      {
        det[0] = det[0] * s;
        det[1] = det[1] - 1.0;
      }

      while ( s <= det[0] )
      {
        det[0] = det[0] / s;
        det[1] = det[1] + 1.0;
      }
    }
  }
/*
  Compute inverse(R).
*/
  if ( ( job % 10 ) != 0 )
  {
    kk = 0;

    for ( k = 1; k <= n; k++ )
    {
      k1 = kk + 1;
      kk = kk + k;
      ap[kk-1] = 1.0 / ap[kk-1];
      t = -ap[kk-1];
      sscal ( k-1, t, ap+k1-1, 1 );
      j1 = kk + 1;
      kj = kk + k;

      for ( j = k + 1; j <= n; j++ )
      {
        t = ap[kj-1];
        ap[kj-1] = 0.0;
        saxpy ( k, t, ap+k1-1, 1, ap+j1-1, 1 );
        j1 = j1 + j;
        kj = kj + j;
      }
    }
/*
  Form inverse(R) * (inverse(R))'.
*/
    jj = 0;

    for ( j = 1; j <= n; j++ )
    {
      j1 = jj + 1;
      jj = jj + j;
      k1 = 1;
      kj = j1;

      for ( k = 1; k <= j-1; k++ )
      {
        t = ap[kj-1];
        saxpy ( k, t, ap+j1-1, 1, ap+k1-1, 1 );
        k1 = k1 + k;
        kj = kj + 1;
      }
      t = ap[jj-1];
      sscal ( j, t, ap+j1-1, 1 );
    }
  }
  return;
}
/******************************************************************************/

int sppfa ( float ap[], int n )

/******************************************************************************/
/*
  Purpose:

    SPPFA factors a real symmetric positive definite matrix in packed form.

  Discussion:

    SPPFA is usually called by SPPCO, but it can be called
    directly with a saving in time if RCOND is not needed.

  Packed storage:

    The following program segment will pack the upper
    triangle of a symmetric matrix.

      k = 0
      do j = 1, n
        do i = 1, j
          k = k + 1
          ap(k) = a(i,j)
        end do
      end do

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float AP[N*(N+1)/2].  On input, the packed
    form of a symmetric matrix A.  The columns of the upper triangle are
    stored sequentially in a one-dimensional array.  On output, an upper
    triangular matrix R, stored in packed form, so that A = R'*R.

    Input, int N, the order of the matrix.

    Output, int SPPFA, error flag.
    0, for normal return.
    K, if the leading minor of order K is not positive definite.
*/
{
  int info;
  int j;
  int jj;
  int k;
  int kj;
  int kk;
  float s;
  float t;

  info = 0;
  jj = 0;

  for ( j = 1; j <= n; j++ )
  {
    s = 0.0;
    kj = jj;
    kk = 0;

    for ( k = 1; k <= j-1; k++ )
    {
      kj = kj + 1;
      t = ap[kj-1] - sdot ( k-1, ap+kk, 1, ap+jj, 1 );
      kk = kk + k;
      t = t / ap[kk-1];
      ap[kj-1] = t;
      s = s + t * t;
    }

    jj = jj + j;
    s = ap[jj-1] - s;

    if ( s <= 0.0 )
    {
      info = j;
      return info;
    }

    ap[jj-1] = sqrt ( s );

  }
  return info;
}
/******************************************************************************/

void sppsl ( float ap[], int n, float b[] )

/******************************************************************************/
/*
  Purpose:

    SPPSL solves a real symmetric positive definite system factored by SPPCO or SPPFA.

  Discussion:

    To compute inverse(A) * C where C is a matrix with P columns

      call sppco ( ap, n, rcond, z, info )

      if ( rcond is too small .or. info /= 0 ) then
        exit
      end if

      do j = 1, p
        call sppsl ( ap, n, c(1,j) )
      end do

    A division by zero will occur if the input factor contains
    a zero on the diagonal.  Technically this indicates
    singularity but it is usually caused by improper subroutine
    arguments.  It will not occur if the subroutines are called
    correctly and INFO == 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float AP[N*(N+1)/2], the output from SPPCO or SPPFA.

    Input, int N, the order of the matrix.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.
*/
{
  int k;
  int kk;
  float t;

  kk = 0;

  for ( k = 1; k <= n; k++ )
  {
    t = sdot ( k-1, ap+kk, 1, b, 1 );
    kk = kk + k;
    b[k-1] = ( b[k-1] - t ) / ap[kk-1];
  }

  for ( k = n; 1 <= k; k-- )
  {
    b[k-1] = b[k-1] / ap[kk-1];
    kk = kk - k;
    t = -b[k-1];
    saxpy ( k-1, t, ap+kk, 1, b, 1 );
  }

  return;
}
/******************************************************************************/

void sptsl ( int n, float d[], float e[], float b[] )

/******************************************************************************/
/*
  Purpose:

    SPTSL solves a positive definite tridiagonal linear system.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, int N, the order of the matrix.

    Input/output, float D[N], on input the diagonal of the
    tridiagonal matrix.  On output, D is destroyed.

    Input, float E[N], the offdiagonal of the tridiagonal matrix in
    entries E(1:N-1).

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.
*/
{
  int k;
  int kbm1;
  int ke;
  int kf;
  int kp1;
  int nm1d2;
  float t1;
  float t2;
/*
  Check for 1 x 1 case.
*/
  if ( n == 1 )
  {
    b[0] = b[0] / d[0];
    return;
  }

  nm1d2 = ( n - 1 ) / 2;

  if ( 2 < n )
  {
    kbm1 = n - 1;
/*
  Zero top half of subdiagonal and bottom half of superdiagonal.
*/
    for ( k = 1; k <= nm1d2; k++ )
    {
      t1 = e[k-1] / d[k-1];
      d[k] = d[k] - t1 * e[k-1];
      b[k] = b[k] - t1 * b[k-1];
      t2 = e[kbm1-1] / d[kbm1];
      d[kbm1-1] = d[kbm1-1] - t2 * e[kbm1-1];
      b[kbm1-1] = b[kbm1-1] - t2 * b[kbm1];
      kbm1 = kbm1 - 1;
    }
  }

  kp1 = nm1d2 + 1;
/*
  Clean up for possible 2 x 2 block at center.
*/
  if ( ( n % 2 ) == 0 )
  {
    t1 = e[kp1-1] / d[kp1-1];
    d[kp1] = d[kp1] - t1 * e[kp1-1];
    b[kp1] = b[kp1] - t1 * b[kp1-1];
    kp1 = kp1 + 1;
  }
/*
  Back solve starting at the center, going towards the top and bottom.
*/
  b[kp1-1] = b[kp1-1] / d[kp1-1];

  if ( 2 < n )
  {
    k = kp1 - 1;
    ke = kp1 + nm1d2 - 1;

    for ( kf = kp1; kf <= ke; kf++ )
    {
      b[k-1] = ( b[k-1] - e[k-1] * b[k] ) / d[k-1];
      b[kf] = ( b[kf] - e[kf-1] * b[kf-1] ) / d[kf];
      k = k - 1;
    }
  }

  if ( ( n % 2 ) == 0 )
  {
    b[0] = ( b[0] - e[0] * b[1] ) / d[0];
  }

  return;
}
/******************************************************************************/

void sqrdc ( float a[], int lda, int n, int p, float qraux[], int jpvt[], 
  float work[], int job )

/******************************************************************************/
/*
  Purpose:

    SQRDC computes the QR factorization of a real rectangular matrix.

  Discussion:

    SQRDC uses Householder transformations.

    Column pivoting based on the 2-norms of the reduced columns may be
    performed at the user's option.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A(LDA,P).  On input, the N by P matrix
    whose decomposition is to be computed.  On output, A contains in
    its upper triangle the upper triangular matrix R of the QR
    factorization.  Below its diagonal A contains information from
    which the orthogonal part of the decomposition can be recovered.
    Note that if pivoting has been requested, the decomposition is not that
    of the original matrix A but that of A with its columns permuted
    as described by JPVT.

    Input, int LDA, the leading dimension of the array A.  LDA must
    be at least N.

    Input, int N, the number of rows of the matrix A.

    Input, int P, the number of columns of the matrix A.

    Output, float QRAUX[P], contains further information required
    to recover the orthogonal part of the decomposition.

    Input/output, integer JPVT[P].  On input, JPVT contains integers that
    control the selection of the pivot columns.  The K-th column A(*,K) of A
    is placed in one of three classes according to the value of JPVT(K).
      > 0, then A(K) is an initial column.
      = 0, then A(K) is a free column.
      < 0, then A(K) is a final column.
    Before the decomposition is computed, initial columns are moved to
    the beginning of the array A and final columns to the end.  Both
    initial and final columns are frozen in place during the computation
    and only free columns are moved.  At the K-th stage of the
    reduction, if A(*,K) is occupied by a free column it is interchanged
    with the free column of largest reduced norm.  JPVT is not referenced
    if JOB == 0.  On output, JPVT(K) contains the index of the column of the
    original matrix that has been interchanged into the K-th column, if
    pivoting was requested.

    Workspace, float WORK[P].  WORK is not referenced if JOB == 0.

    Input, int JOB, initiates column pivoting.
    0, no pivoting is done.
    nonzero, pivoting is done.
*/
{
  int j;
  int jp;
  int l;
  int lup;
  int maxj;
  float maxnrm;
  float nrmxl;
  int pl;
  int pu;
  int swapj;
  float t;
  float tt;

  pl = 1;
  pu = 0;
/*
  If pivoting is requested, rearrange the columns.
*/
  if ( job != 0 )
  {
    for ( j = 1; j <= p; j++ )
    {
      swapj = ( 0 < jpvt[j-1] );

      if ( jpvt[j-1] < 0 )
      {
        jpvt[j-1] = -j;
      }
      else
      {
        jpvt[j-1] = j;
      }

      if ( swapj )
      {
        if ( j != pl )
        {
          sswap ( n, a+0+(pl-1)*lda, 1, a+0+(j-1), 1 );
        }
        jpvt[j-1] = jpvt[pl-1];
        jpvt[pl-1] = j;
        pl = pl + 1;
      }
    }
    pu = p;

    for ( j = p; 1 <= j; j-- )
    {
      if ( jpvt[j-1] < 0 )
      {
        jpvt[j-1] = -jpvt[j-1];

        if ( j != pu )
        {
          sswap ( n, a+0+(pu-1)*lda, 1, a+0+(j-1)*lda, 1 );
          jp = jpvt[pu-1];
          jpvt[pu-1] = jpvt[j-1];
          jpvt[j-1] = jp;
        }
        pu = pu - 1;
      }
    }
  }
/*
  Compute the norms of the free columns.
*/
  for ( j = pl; j <= pu; j++ )
  {
    qraux[j-1] = snrm2 ( n, a+0+(j-1)*lda, 1 );
  }

  for ( j = pl; j <= pu; j++ )
  {
    work[j-1] = qraux[j-1];
  }
/*
  Perform the Householder reduction of A.
*/
  lup = i4_min ( n, p );

  for ( l = 1; l <= lup; l++ )
  {
/*
  Bring the column of largest norm into the pivot position.
*/
    if ( pl <= l && l < pu )
    {
      maxnrm = 0.0;
      maxj = l;
      for ( j = l; j <= pu; j++ )
      {
        if ( maxnrm < qraux[j-1] )
        {
          maxnrm = qraux[j-1];
          maxj = j;
        }
      }

      if ( maxj != l )
      {
        sswap ( n, a+0+(l-1)*lda, 1, a+0+(maxj-1)*lda, 1 );
        qraux[maxj-1] = qraux[l-1];
        work[maxj-1] = work[l-1];
        jp = jpvt[maxj-1];
        jpvt[maxj-1] = jpvt[l-1];
        jpvt[l-1] = jp;
      }
    }
/*
  Compute the Householder transformation for column L.
*/
    qraux[l-1] = 0.0;

    if ( l != n )
    {
      nrmxl = snrm2 ( n-l+1, a+l-1+(l-1)*lda, 1 );

      if ( nrmxl != 0.0 )
      {
        if ( a[l-1+(l-1)*lda] < 0.0 )
        {
          nrmxl = - nrmxl;
        }

        sscal ( n-l+1, 1.0 / nrmxl, a+l-1+(l-1)*lda, 1 );
        a[l-1+(l-1)*lda] = 1.0 + a[l-1+(l-1)*lda];
/*
  Apply the transformation to the remaining columns, updating the norms.
*/
        for ( j = l + 1; j <= p; j++ )
        {
          t = -sdot ( n-l+1, a+l-1+(l-1)*lda, 1, a+l-1+(j-1)*lda, 1 ) 
            / a[l-1+(l-1)*lda];
          saxpy ( n-l+1, t, a+l-1+(l-1)*lda, 1, a+l-1+(j-1)*lda, 1 );

          if ( pl <= j && j <= pu )
          {
            if ( qraux[j-1] != 0.0 )
            {
              tt = 1.0 - pow ( fabs ( a[l-1+(j-1)*lda] ) / qraux[j-1], 2 );
              tt = r4_max ( tt, 0.0 );
              t = tt;
              tt = 1.0 + 0.05 * tt * pow ( qraux[j-1] / work[j-1], 2 );

              if ( tt != 1.0 )
              {
                qraux[j-1] = qraux[j-1] * sqrt ( t );
              }
              else
              {
                qraux[j-1] = snrm2 ( n-l, a+l+(j-1)*lda, 1 );
                work[j-1] = qraux[j-1];
              }
            }
          }
        }
/*
  Save the transformation.
*/
        qraux[l-1] = a[l-1+(l-1)*lda];
        a[l-1+(l-1)*lda] = -nrmxl;
      }
    }
  }
  return;
}
/******************************************************************************/

int sqrsl ( float a[], int lda, int n, int k, float qraux[], float y[], 
  float qy[], float qty[], float b[], float rsd[], float ab[], int job )

/******************************************************************************/
/*
  Purpose:

    SQRSL computes transformations, projections, and least squares solutions.

  Discussion:

    SQRSL requires the output of SQRDC.

    For K <= min(N,P), let AK be the matrix

      AK = ( A(JPVT[0]), A(JPVT(2)), ..., A(JPVT(K)) )

    formed from columns JPVT[0], ..., JPVT(K) of the original
    N by P matrix A that was input to SQRDC.  If no pivoting was
    done, AK consists of the first K columns of A in their
    original order.  SQRDC produces a factored orthogonal matrix Q
    and an upper triangular matrix R such that

      AK = Q * (R)
               (0)

    This information is contained in coded form in the arrays
    A and QRAUX.

    The parameters QY, QTY, B, RSD, and AB are not referenced
    if their computation is not requested and in this case
    can be replaced by dummy variables in the calling program.
    To save storage, the user may in some cases use the same
    array for different parameters in the calling sequence.  A
    frequently occuring example is when one wishes to compute
    any of B, RSD, or AB and does not need Y or QTY.  In this
    case one may identify Y, QTY, and one of B, RSD, or AB, while
    providing separate arrays for anything else that is to be
    computed.

    Thus the calling sequence

      sqrsl ( a, lda, n, k, qraux, y, dum, y, b, y, dum, 110, info )

    will result in the computation of B and RSD, with RSD
    overwriting Y.  More generally, each item in the following
    list contains groups of permissible identifications for
    a single calling sequence.

      1. (Y,QTY,B) (RSD) (AB) (QY)

      2. (Y,QTY,RSD) (B) (AB) (QY)

      3. (Y,QTY,AB) (B) (RSD) (QY)

      4. (Y,QY) (QTY,B) (RSD) (AB)

      5. (Y,QY) (QTY,RSD) (B) (AB)

      6. (Y,QY) (QTY,AB) (B) (RSD)

    In any group the value returned in the array allocated to
    the group corresponds to the last member of the group.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float A[LDA*P], contains the output of SQRDC.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the number of rows of the matrix AK.  It must
    have the same value as N in SQRDC.

    Input, int K, the number of columns of the matrix AK.  K
    must not be greater than min(N,P), where P is the same as in the
    calling sequence to SQRDC.

    Input, float QRAUX[P], the auxiliary output from SQRDC.

    Input, float Y[N], a vector to be manipulated by SQRSL.

    Output, float QY[N], contains Q * Y, if requested.

    Output, float QTY[N], contains Q' * Y, if requested.

    Output, float B[K], the solution of the least squares problem
      minimize norm2 ( Y - AK * B),
    if its computation has been requested.  Note that if pivoting was
    requested in SQRDC, the J-th component of B will be associated with
    column JPVT(J) of the original matrix A that was input into SQRDC.

    Output, float RSD[N], the least squares residual Y - AK * B,
    if its computation has been requested.  RSD is also the orthogonal
    projection of Y onto the orthogonal complement of the column space
    of AK.

    Output, float AB[N], the least squares approximation Ak * B,
    if its computation has been requested.  AB is also the orthogonal
    projection of Y onto the column space of A.

    Input, integer JOB, specifies what is to be computed.  JOB has
    the decimal expansion ABCDE, with the following meaning:

      if A != 0, compute QY.
      if B != 0, compute QTY.
      if C != 0, compute QTY and B.
      if D != 0, compute QTY and RSD.
      if E != 0, compute QTY and AB.

    Note that a request to compute B, RSD, or AB automatically triggers
    the computation of QTY, for which an array must be provided in the
    calling sequence.

    Output, int SQRSL, is zero unless the computation of B has
    been requested and R is exactly singular.  In this case, INFO is the
    index of the first zero diagonal element of R, and B is left unaltered.
*/
{
  int cab;
  int cb;
  int cqty;
  int cqy;
  int cr;
  int i;
  int info;
  int j;
  int jj;
  int ju;
  float t;
  float temp;
/*
  set info flag.
*/
  info = 0;
/*
  Determine what is to be computed.
*/
  cqy =  (   job / 10000          != 0 );
  cqty = ( ( job %  10000 )       != 0 );
  cb =   ( ( job %   1000 ) / 100 != 0 );
  cr =   ( ( job %    100 ) /  10 != 0 );
  cab =  ( ( job %     10 )       != 0 );

  ju = i4_min ( k, n-1 );
/*
  Special action when N = 1.
*/
  if ( ju == 0 )
  {
    if ( cqy )
    {
      qy[0] = y[0];
    }

    if ( cqty )
    {
      qty[0] = y[0];
    }

    if ( cab )
    {
      ab[0] = y[0];
    }

    if ( cb )
    {
      if ( a[0+0*lda] == 0.0 )
      {
        info = 1;
      }
      else
      {
        b[0] = y[0] / a[0+0*lda];
      }
    }

    if ( cr )
    {
      rsd[0] = 0.0;
    }
    return info;
  }
/*
  Set up to compute QY or QTY.
*/
  if ( cqy )
  {
    for ( i = 1; i <= n; i++ )
    {
      qy[i-1] = y[i-1];
    }
  }

  if ( cqty )
  {
    for ( i = 1; i <= n; i++ )
    {
      qty[i-1] = y[i-1];
    }
  }
/*
  Compute QY.
*/
  if ( cqy )
  {
    for ( jj = 1; jj <= ju; jj++ )
    {
      j = ju - jj + 1;

      if ( qraux[j-1] != 0.0 )
      {
        temp = a[j-1+(j-1)*lda];
        a[j-1+(j-1)*lda] = qraux[j-1];
        t = -sdot ( n-j+1, a+j-1+(j-1)*lda, 1, qy+j-1, 1 ) / a[j-1+(j-1)*lda];
        saxpy ( n-j+1, t, a+j-1+(j-1)*lda, 1, qy+j-1, 1 );
        a[j-1+(j-1)*lda] = temp;
      }
    }
  }
/*
  Compute Q'*Y.
*/
  if ( cqty )
  {
    for ( j = 1; j <= ju; j++ )
    {
      if ( qraux[j-1] != 0.0 )
      {
        temp = a[j-1+(j-1)*lda];
        a[j-1+(j-1)*lda] = qraux[j-1];
        t = -sdot ( n-j+1, a+j-1+(j-1)*lda, 1, qty+j-1, 1 ) / a[j-1+(j-1)*lda];
        saxpy ( n-j+1, t, a+j-1+(j-1)*lda, 1, qty+j-1, 1 );
        a[j-1+(j-1)*lda] = temp;
      }
    }
  }
/*
  Set up to compute B, RSD, or AB.
*/
  if ( cb )
  {
    for ( i = 1; i <= k; i++ )
    {
      b[i-1] = qty[i-1];
    }
  }

  if ( cab )
  {
    for ( i = 1; i <= k; i++ )
    {
      ab[i-1] = qty[i-1];
    }
  }

  if ( cr && k < n )
  {
    for ( i = k+1; i <= n; i++ )
    {
      rsd[i-1] = qty[i-1];
    }
  }

  if ( cab && k+1 <= n )
  {
    for ( i = k+1; i <= n; i++ )
    {
      ab[i-1] = 0.0;
    }
  }

  if ( cr )
  {
    for ( i = 1; i <= k; i++ )
    {
      rsd[i-1] = 0.0;
    }
  }
/*
  Compute B.
*/
  if ( cb )
  {
    for ( jj = 1; jj <= k; jj++ )
    {
      j = k - jj + 1;

      if ( a[j-1+(j-1)*lda] == 0.0 )
      {
        info = j;
        break;
      }

      b[j-1] = b[j-1] / a[j-1+(j-1)*lda];

      if ( j != 1 )
      {
        t = -b[j-1];
        saxpy ( j-1, t, a+0+(j-1)*lda, 1, b, 1 );
      }
    }
  }
/*
  Compute RSD or AB as required.
*/
  if ( cr || cab )
  {
    for ( jj = 1; jj <= ju; jj++ )
    {
      j = ju - jj + 1;

      if ( qraux[j-1] != 0.0 )
      {
        temp = a[j-1+(j-1)*lda];
        a[j-1+(j-1)*lda] = qraux[j-1];

        if ( cr )
        {
          t = -sdot ( n-j+1, a+j-1+(j-1)*lda, 1, rsd+j-1, 1 ) 
            / a[j-1+(j-1)*lda];
          saxpy ( n-j+1, t, a+j-1+(j-1)*lda, 1, rsd+j-1, 1 );
        }

        if ( cab )
        {
          t = -sdot ( n-j+1, a+j-1+(j-1)*lda, 1, ab+j-1, 1 ) 
            / a[j-1+(j-1)*lda];
          saxpy ( n-j+1, t, a+j-1+(j-1)*lda, 1, ab+j-1, 1 );
        }
        a[j-1+(j-1)*lda] = temp;
      }
    }
  }

  return info;
}
/******************************************************************************/

float ssico ( float a[], int lda, int n, int kpvt[], float z[] )

/******************************************************************************/
/*
  Purpose:

    SSICO factors a real symmetric matrix and estimates its condition.

  Discussion:

    If RCOND is not needed, SSIFA is slightly faster.

    To solve A * X = B, follow SSICO by SSISL.

    To compute inverse(A)*C, follow SSICO by SSISL.

    To compute inverse(A), follow SSICO by SSIDI.

    To compute determinant(A), follow SSICO by SSIDI.

    To compute inertia(A), follow SSICO by SSIDI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, the symmetric
    matrix to be factored.  Only the diagonal and upper triangle are used.
    On output, a block diagonal matrix and the multipliers which
    were used to obtain it.  The factorization can be written A = U*D*U'
    where U is a product of permutation and unit upper triangular
    matrices, U' is the transpose of U, and D is block diagonal
    with 1 by 1 and 2 by 2 blocks.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Output, int KPVT[N], pivot indices.

    Output, float Z[N], a work vector whose contents are usually
    unimportant.  If A is close to a singular matrix, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).

    Output, float SSICO, an estimate of the reciprocal condition number RCOND
    of A.  For the system A*X = B, relative perturbations in A and B of size
    EPSILON may cause relative perturbations in X of size EPSILON/RCOND.
    If RCOND is so small that the logical expression
      1.0 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float ak;
  float akm1;
  float anorm;
  float bk;
  float bkm1;
  float denom;
  float ek;
  int i;
  int j;
  int k;
  int kp;
  int kps;
  int ks;
  float rcond;
  float s;
  float t;
  float ynorm;
/*
  Find the norm of A, using only entries in the upper half of the matrix.
*/
  for ( j = 1; j <= n; j++ )
  {
    z[j-1] = sasum ( j, a+0+(j-1)*lda, 1 );
    for ( i = 1; i <= j-1; i++ )
    {
      z[i-1] = z[i-1] + fabs ( a[i-1+(j-1)*lda] );
    }
  }

  anorm = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    anorm = r4_max ( anorm, z[i-1] );
  }
/*
  Factor.
*/
  ssifa ( a, lda, n, kpvt );
/*
  RCOND = 1/(norm(A)*(estimate of norm(inverse(A)))).

  Estimate = norm(Z)/norm(Y) where A*Z = Y and A*Y = E.

  The components of E are chosen to cause maximum local
  growth in the elements of W where U*D*W = E.

  The vectors are frequently rescaled to avoid overflow.

  Solve U * D * W = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }
  k = n;

  while ( k != 0 )
  {
    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }
    kp = abs ( kpvt[k-1] );
    kps = k + 1 - ks;

    if ( kp != kps )
    {
      t = z[kps-1];
      z[kps-1] = z[kp-1];
      z[kp-1] = t;
    }

    if ( z[k-1] < 0.0 )
    {
      ek = - ek;
    }

    z[k-1] = z[k-1] + ek;
    saxpy ( k-ks, z[k-2], a+0+(k-1)*lda, 1, z, 1 );

    if ( ks != 1 )
    {
      if ( z[k-2] < 0.0 )
      {
        ek = - ek;
      }
      z[k-2] = z[k-2] + ek;
      saxpy ( k-ks, z[k-2], a+0+(k-2)*lda, 1, z, 1 );
    }

    if ( ks != 2 )
    {
      if ( fabs ( a[k-1+(k-1)*lda] ) < fabs ( z[k-1] ) )
      {
        s = fabs ( a[k-1+(k-1)*lda] ) / fabs ( z[k-1] );
        for ( i = 1; i <= n; i++ )
        {
          z[i-1] = s * z[i-1];
        }
        ek = s * ek;
      }

      if ( a[k-1+(k-1)*lda] != 0.0 )
      {
        z[k-1] = z[k-1] / a[k-1+(k-1)*lda];
      }
      else
      {
        z[k-1] = 1.0;
      }
    }
    else
    {
      ak = a[k-1+(k-1)*lda] / a[k-2+(k-1)*lda];
      akm1 = a[k-2+(k-2)*lda] / a[k-2+(k-1)*lda];
      bk = z[k-1] / a[k-2+(k-1)*lda];
      bkm1 = z[k-2] / a[k-2+(k-1)*lda];
      denom = ak * akm1 - 1.0;
      z[k-1] = ( akm1 * bk - bkm1 ) / denom;
      z[k-2] = ( ak * bkm1 - bk ) / denom;
    }
    k = k - ks;
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
/*
  Solve U' * Y = W.
*/
  k = 1;

  while ( k <= n )
  {
    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    if ( k != 1 )
    {
      z[k-1] = z[k-1] + sdot ( k-1, a+0+(k-1)*lda, 1, z, 1 );

      if ( ks == 2 )
      {
        z[k] = z[k] + sdot ( k-1, a+0+k*lda, 1, z, 1 );
      }

      kp = abs ( kpvt[k-1] );

      if ( kp != k )
      {
        t = z[k-1];
        z[k-1] = z[kp-1];
        z[kp-1] = t;
      }
    }
    k = k + ks;
  }
  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
  ynorm = 1.0;
/*
  Solve U * D * V = Y.
*/
  k = n;

  while ( k != 0 )
  {
    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    if ( k != ks )
    {
      kp = abs ( kpvt[k-1] );
      kps = k + 1 - ks;

      if ( kp != kps )
      {
        t = z[kps-1];
        z[kps-1] = z[kp-1];
        z[kp-1] = t;
      }

      saxpy ( k-ks, z[k-1], a+0+(k-1)*lda, 1, z, 1 );

      if ( ks == 2 )
      {
        saxpy ( k-ks, z[k-2], a+0+(k-2)*lda, 1, z, 1 );
      }
    }

    if ( ks != 2 )
    {
      if ( fabs ( a[k-1+(k-1)*lda] ) < fabs ( z[k-1] ) )
      {
        s = fabs ( a[k-1+(k-1)*lda] ) / fabs ( z[k-1] );
        for ( i = 1; i <= n; i++ )
        {
          z[i-1] = s * z[i-1];
        }
        ynorm = s * ynorm;
      }

      if ( a[k-1+(k-1)*lda] != 0.0 )
      {
        z[k-1] = z[k-1] / a[k-1+(k-1)*lda];
      }
      else
      {
        z[k-1] = 1.0;
      }
    }
    else
    {
      ak = a[k-1+(k-1)*lda] / a[k-2+(k-1)*lda];
      akm1 = a[k-2+(k-2)*lda] / a[k-2+(k-1)*lda];
      bk = z[k-1] / a[k-2+(k-1)*lda];
      bkm1 = z[k-2] / a[k-2+(k-1)*lda];
      denom = ak * akm1 - 1.0;
      z[k-1] = ( akm1 * bk - bkm1 ) / denom;
      z[k-2] = ( ak * bkm1 - bk ) / denom;
    }
    k = k - ks;
  }

  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;
/*
  Solve U' * Z = V.
*/
  k = 1;

  while ( k <= n )
  {
    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    if ( k != 1 )
    {
      z[k-1] = z[k-1] + sdot ( k-1, a+0+(k-1)*lda, 1, z, 1 );
      if ( ks == 2 )
      {
        z[k] = z[k] + sdot ( k-1, a+0+k*lda, 1, z, 1 );
      }
      kp = abs ( kpvt[k-1] );

      if ( kp != k )
      {
        t = z[k-1];
        z[k-1] = z[kp-1];
        z[kp-1] = t;
      }
    }
    k = k + ks;
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void ssidi ( float a[], int lda, int n, int kpvt[], float det[2], 
  int inert[3], float work[], int job )

/******************************************************************************/
/*
  Purpose:

    SSIDI computes the determinant, inertia and inverse of a real symmetric matrix.

  Discussion:

    SSIDI uses the factors from SSIFA.

    A division by zero may occur if the inverse is requested
    and SSICO has set RCOND == 0.0D+00 or SSIFA has set INFO /= 0.

    Variables not requested by JOB are not used.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A(LDA,N).  On input, the output from SSIFA.
    On output, the upper triangle of the inverse of the original matrix,
    if requested.  The strict lower triangle is never referenced.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Input, int KPVT[N], the pivot vector from SSIFA.

    Output, float DET[2], the determinant of the original matrix,
    if requested.
      determinant = DET[0] * 10.0**DET[1]
    with 1.0D+00 <= abs ( DET[0] ) < 10.0D+00 or DET[0] = 0.0.

    Output, int INERT(3), the inertia of the original matrix,
    if requested.
    INERT(1) = number of positive eigenvalues.
    INERT(2) = number of negative eigenvalues.
    INERT(3) = number of zero eigenvalues.

    Workspace, float WORK[N].

    Input, int JOB, specifies the tasks.
    JOB has the decimal expansion ABC where
    If C /= 0, the inverse is computed,
    If B /= 0, the determinant is computed,
    If A /= 0, the inertia is computed.
    For example, JOB = 111 gives all three.
*/
{
  float ak;
  float akkp1;
  float akp1;
  float d;
  int dodet;
  int doert;
  int doinv;
  int j;
  int jb;
  int k;
  int ks;
  int kstep;
  float t;
  float temp;

  doinv = ( job %   10 )       != 0;
  dodet = ( job %  100 ) /  10 != 0;
  doert = ( job % 1000 ) / 100 != 0;

  if ( dodet || doert )
  {
    if ( doert )
    {
      inert[0] = 0;
      inert[1] = 0;
      inert[2] = 0;
    }

    if ( dodet )
    {
      det[0] = 1.0;
      det[1] = 0.0;
    }

    t = 0.0;

    for ( k = 1; k <= n; k++ )
    {
      d = a[k-1+(k-1)*lda];
/*
  2 by 2 block.

  use det (d  s)  =  (d/t * c - t) * t,  t = abs ( s )
          (s  c)
  to avoid underflow/overflow troubles.

  Take two passes through scaling.  Use T for flag.
*/
      if ( kpvt[k-1] <= 0 )
      {
        if ( t == 0.0 )
        {
          t = fabs ( a[k-1+k*lda] );
          d = ( d / t ) * a[k+k*lda] - t;
        }
        else
        {
          d = t;
          t = 0.0;
        }
      }

      if ( doert )
      {
        if ( 0.0 < d )
        {
          inert[0] = inert[0] + 1;
        }
        else if ( d < 0.0 )
        {
          inert[1] = inert[1] + 1;
        }
        else if ( d == 0.0 )
        {
          inert[2] = inert[2] + 1;
        }
      }

      if ( dodet )
      {
        det[0] = det[0] * d;

        if ( det[0] != 0.0 )
        {
          while ( fabs ( det[0] ) < 1.0 )
          {
            det[0] = det[0] * 10.0;
            det[1] = det[1] - 1.0;
          }

          while ( 10.0 <= fabs ( det[0] ) )
          {
            det[0] = det[0] / 10.0;
            det[1] = det[1] + 1.0;
          }
        }
      }
    }
  }
/*
  Compute inverse(A).
*/
  if ( doinv )
  {
    k = 1;

    while ( k <= n )
    {
      if ( 0 <= kpvt[k-1] )
      {
/*
  1 by 1.
*/
        a[k-1+(k-1)*lda] = 1.0 / a[k-1+(k-1)*lda];

        if ( 2 <= k )
        {
          scopy ( k-1, a+0+(k-1)*lda, 1, work, 1 );

          for ( j = 1; j <= k-1; j++ )
          {
            a[j-1+(k-1)*lda] = sdot ( j, a+0+(j-1)*lda, 1, work, 1 );
            saxpy ( j-1, work[j-1], a+0+(j-1)*lda, 1, a+0+(k-1)*lda, 1 );
          }
          a[k-1+(k-1)*lda] = a[k-1+(k-1)*lda] 
            + sdot ( k-1, work, 1, a+0+(k-1)*lda, 1 );
        }
        kstep = 1;
      }
/*
  2 by 2.
*/
      else
      {
        t = fabs ( a[k-1+k*lda] );
        ak = a[k-1+(k-1)*lda] / t;
        akp1 = a[k+k*lda] / t;
        akkp1 = a[k-1+k*lda] / t;
        d = t * ( ak * akp1 - 1.0 );
        a[k-1+(k-1)*lda] = akp1 / d;
        a[k+k*lda] = ak / d;
        a[k-1+k*lda] = -akkp1 / d;

        if ( 2 <= k )
        {
          scopy ( k-1, a+0+k*lda, 1, work, 1 );

          for ( j = 1; j <= k-1; j++ )
          {
            a[j-1+k*lda] = sdot ( j, a+0+(j-1)*lda, 1, work, 1 );
            saxpy ( j-1, work[j-1], a+0+(j-1)*lda, 1, a+0+k*lda, 1 );
          }
          a[k+k*lda] = a[k+k*lda] + sdot ( k-1, work, 1, a+0+k*lda, 1 );
          a[k-1+k*lda] = a[k-1+k*lda] 
            + sdot ( k-1, a+0+(k-1)*lda, 1, a+0+k*lda, 1 );
          scopy ( k-1, a+0+(k-1)*lda, 1, work, 1 );

          for ( j = 1; j <= k-1; j++ )
          {
            a[j-1+(k-1)*lda] = sdot ( j, a+0+(j-1)*lda, 1, work, 1 );
            saxpy ( j-1, work[j-1], a+0+(j-1)*lda, 1, a+0+(k-1)*lda, 1 );
          }
          a[k-1+(k-1)*lda] = a[k-1+(k-1)*lda] 
            + sdot ( k-1, work, 1, a+0+(k-1)*lda, 1 );
        }
        kstep = 2;
      }
/*
  Swap.
*/
      ks = abs ( kpvt[k-1] );

      if ( ks != k )
      {
        sswap ( ks, a+0+(ks-1)*lda, 1, a+0+(k-1)*lda, 1 );

        for ( jb = ks; jb <= k; jb++ )
        {
          j = k + ks - jb;
          temp = a[j-1+(k-1)*lda];
          a[j-1+(k-1)*lda] = a[ks-1+(j-1)*lda];
          a[ks-1+(j-1)*lda] = temp;
        }

        if ( kstep != 1 )
        {
          temp = a[ks-1+k*lda];
          a[ks-1+k*lda] = a[k-1+k*lda];
          a[k-1+k*lda] = temp;
        }
      }
      k = k + kstep;
    }
  }
  return;
}
/******************************************************************************/

int ssifa ( float a[], int lda, int n, int kpvt[] )

/******************************************************************************/
/*
  Purpose:

    SSIFA factors a real symmetric matrix.

  Discussion:

    To solve A*X = B, follow SSIFA by SSISL.

    To compute inverse(A)*C, follow SSIFA by SSISL.

    To compute determinant(A), follow SSIFA by SSIDI.

    To compute inertia(A), follow SSIFA by SSIDI.

    To compute inverse(A), follow SSIFA by SSIDI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, the symmetric matrix
    to be factored.  Only the diagonal and upper triangle are used.
    On output, a block diagonal matrix and the multipliers which
    were used to obtain it.  The factorization can be written A = U*D*U'
    where U is a product of permutation and unit upper triangular
    matrices, U' is the transpose of U, and D is block diagonal
    with 1 by 1 and 2 by 2 blocks.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Output, int KPVT[N], the pivot indices.

    Output, integer SSIFA, error flag.
    0, normal value.
    K, if the K-th pivot block is singular.  This is not an error
    condition for this subroutine, but it does indicate that SSISL
    or SSIDI may divide by zero if called.
*/
{
  float absakk;
  float ak;
  float akm1;
  float alpha;
  float bk;
  float bkm1;
  float colmax;
  float denom;
  int imax;
  int imaxp1;
  int info;
  int j;
  int jj;
  int jmax;
  int k;
  int kstep;
  float mulk;
  float mulkm1;
  float rowmax;
  int swap;
  float t;
/*
  ALPHA is used in choosing pivot block size.
*/
  alpha = ( 1.0 + sqrt ( 17.0 ) ) / 8.0;

  info = 0;
/*
  Main loop on K, which goes from N to 1.
*/
  k = n;

  while ( 0 < k )
  {
    if ( k == 1 )
    {
      kpvt[0] = 1;
      if ( a[0+0*lda] == 0.0 )
      {
        info = 1;
      }
      return info;
    }
/*
  This section of code determines the kind of
  elimination to be performed.  When it is completed,
  KSTEP will be set to the size of the pivot block, and
  SWAP will be set to .true. if an interchange is required.
*/
    absakk = fabs ( a[k-1+(k-1)*lda] );
/*
  Determine the largest off-diagonal element in column K.
*/
    imax = isamax ( k-1, a+0+(k-1)*lda, 1 );
    colmax = fabs ( a[imax-1+(k-1)*lda] );

    if ( alpha * colmax <= absakk )
    {
      kstep = 1;
      swap = 0;
    }
/*
  Determine the largest off-diagonal element in row IMAX.
*/
    else
    {
      rowmax = 0.0;
      imaxp1 = imax + 1;
      for ( j = imaxp1; j <= k; j++ )
      {
        rowmax = r4_max ( rowmax, fabs ( a[imax-1+(j-1)*lda] ) );
      }

      if ( imax != 1 )
      {
        jmax = isamax ( imax-1, a+0+(imax-1)*lda, 1 );
        rowmax = r4_max ( rowmax, fabs ( a[jmax-1+(imax-1)*lda] ) );
      }

      if ( alpha * rowmax <= fabs ( a[imax-1+(imax-1)*lda] ) )
      {
        kstep = 1;
        swap = 1;
      }
      else if ( alpha * colmax * ( colmax / rowmax ) <= absakk ) 
      {
        kstep = 1;
        swap = 0;
      }
      else
      {
        kstep = 2;
        swap = ( imax != k-1 );
      }
    }
/*
  Column K is zero.
  Set INFO and iterate the loop.
*/
    if ( r4_max ( absakk, colmax ) == 0.0 )
    {
      kpvt[k-1] = k;
      info = k;
    }
/*
  1 x 1 pivot block.

  Perform an interchange.
*/
    else if ( kstep != 2 )
    {
      if ( swap )
      {
        sswap ( imax, a+0+(imax-1)*lda, 1, a+0+(k-1)*lda, 1 );

        for ( jj = imax; jj <= k; jj++ )
        {
          j = k + imax - jj;
          t = a[j-1+(k-1)*lda];
          a[j-1+(k-1)*lda] = a[imax-1+(j-1)*lda];
          a[imax-1+(j-1)*lda] = t;
        }
      }
/*
  Perform the elimination.
*/
      for ( jj = 1; jj <= k-1; jj++ )
      {
        j = k - jj;
        mulk = -a[j-1+(k-1)*lda] / a[k-1+(k-1)*lda];
        t = mulk;
        saxpy ( j, t, a+0+(k-1)*lda, 1, a+0+(j-1)*lda, 1 );
        a[j-1+(k-1)*lda] = mulk;
      }
/*
  Set the pivot array.
*/
      if ( swap )
      {
        kpvt[k-1] = imax;
      }
      else
      {
        kpvt[k-1] = k;
      }
    }
/*
  2 x 2 pivot block.

  Perform an interchange.
*/
    else
    {
      if ( swap )
      {
        sswap ( imax, a+0+(imax-1)*lda, 1, a+0+(k-2)*lda, 1 );

        for ( jj = imax; jj <= k-1; jj++ )
        {
          j = k-1 + imax - jj;
          t = a[j-1+(k-1)*lda];
          a[j-1+(k-1)*lda] = a[imax-1+(j-1)*lda];
          a[imax-1+(j-1)*lda] = t;
        }

        t = a[k-2+(k-1)*lda];
        a[k-2+(k-1)*lda] = a[imax-1+(k-1)*lda];
        a[imax-1+(k-1)*lda] = t;
      }
/*
  Perform the elimination.
*/
      if ( k-2 != 0 )
      {
        ak = a[k-1+(k-1)*lda] / a[k-2+(k-1)*lda];
        akm1 = a[k-2+(k-2)*lda] / a[k-2+(k-1)*lda];
        denom = 1.0 - ak * akm1;

        for ( jj = 1; jj <= k-2; jj++ )
        {
          j = k-1 - jj;
          bk = a[j-1+(k-1)*lda] / a[k-2+(k-1)*lda];
          bkm1 = a[j-1+(k-2)*lda] / a[k-2+(k-1)*lda];
          mulk = ( akm1 * bk - bkm1 ) / denom;
          mulkm1 = ( ak * bkm1 - bk ) / denom;
          t = mulk;
          saxpy ( j, t, a+0+(k-1)*lda, 1, a+0+(j-1)*lda, 1 );
          t = mulkm1;
          saxpy ( j, t, a+0+(k-2)*lda, 1, a+0+(j-1)*lda, 1 );
          a[j-1+(k-1)*lda] = mulk;
          a[j-1+(k-2)*lda] = mulkm1;
        }
      }
/*
  Set the pivot array.
*/
      if ( swap )
      {
        kpvt[k-1] = -imax;
      }
      else
      {
        kpvt[k-1] = 1 - k;
      }
      kpvt[k-2] = kpvt[k-1];
    }
    k = k - kstep;
  }
  return info;
}
/******************************************************************************/

void ssisl ( float a[], int lda, int n, int kpvt[], float b[] )

/******************************************************************************/
/*
  Purpose:

    SSISL solves a real symmetric system factored by SSIFA.

  Discussion:

    To compute inverse(A) * C where C is a matrix with P columns

      call ssifa ( a, lda, n, kpvt, info )

      if ( info == 0 ) then
        do j = 1, p
          call ssisl ( a, lda, n, kpvt, c(1,j) )
        end do
      end if

    A division by zero may occur if the inverse is requested
    and SSICO has set RCOND == 0.0D+00 or SSIFA has set INFO /= 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float A[LDA*N], the output from SSIFA.

    Input, int LDA, the leading dimension of the array A.

    Input, int N, the order of the matrix.

    Input, int KPVT[N], the pivot vector from SSIFA.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.
*/
{
  float ak;
  float akm1;
  float bk;
  float bkm1;
  float denom;
  int k;
  int kp;
  float temp;
/*
  Loop backward applying the transformations and D inverse to B.
*/
  k = n;

  while ( 0 < k )
  {
    if ( 0 <= kpvt[k-1] )
    {
/*
  1 x 1 pivot block.
*/
      if ( k != 1 )
      {
        kp = kpvt[k-1];
/*
  Interchange.
*/
        if ( kp != k )
        {
          temp = b[k-1];
          b[k-1] = b[kp-1];
          b[kp-1] = temp;
        }
/*
  Apply the transformation.
*/
        saxpy ( k-1, b[k-1], a+0+(k-1)*lda, 1, b, 1 );
      }
/*
  Apply D inverse.
*/
      b[k-1] = b[k-1] / a[k-1+(k-1)*lda];
      k = k - 1;
    }
    else
    {
/*
  2 x 2 pivot block.
*/
      if ( k != 2 )
      {
        kp = abs ( kpvt[k-1] );
/*
  Interchange.
*/
        if ( kp != k-1 )
        {
          temp = b[k-2];
          b[k-2] = b[kp-1];
          b[kp-1] = temp;
        }
/*
  Apply the transformation.
*/
        saxpy ( k-2, b[k-1], a+0+(k-1)*lda, 1, b, 1 );
        saxpy ( k-2, b[k-2], a+0+(k-2)*lda, 1, b, 1 );
      }
/*
  Apply D inverse.
*/
      ak = a[k-1+(k-1)*lda] / a[k-2+(k-1)*lda];
      akm1 = a[k-2+(k-2)*lda] / a[k-2+(k-1)*lda];
      bk = b[k-1] / a[k-2+(k-1)*lda];
      bkm1 = b[k-2] / a[k-2+(k-1)*lda];
      denom = ak * akm1 - 1.0;
      b[k-1] = ( akm1 * bk - bkm1 ) / denom;
      b[k-2] = ( ak * bkm1 - bk ) / denom;
      k = k - 2;
    }
  }
/*
  Loop forward applying the transformations.
*/
  k = 1;

  while ( k <= n )
  {
    if ( 0 <= kpvt[k-1] )
    {
/*
  1 x 1 pivot block.
*/
      if ( k != 1 )
      {
/*
  Apply the transformation.
*/
        b[k-1] = b[k-1] + sdot ( k-1, a+0+(k-1)*lda, 1, b, 1 );
        kp = kpvt[k-1];
/*
  Interchange.
*/
        if ( kp != k )
        {
          temp = b[k-1];
          b[k-1] = b[kp-1];
          b[kp-1] = temp;
        }
      }
      k = k + 1;
    }
    else
    {
/*
  2 x 2 pivot block.
*/
      if ( k != 1 )
      {
/*
  Apply the transformation.
*/
        b[k-1] = b[k-1] + sdot ( k-1, a+0+(k-1)*lda, 1, b, 1 );
        b[k] = b[k] + sdot ( k-1, a+0+k*lda, 1, b, 1 );
        kp = abs ( kpvt[k-1] );
/*
  Interchange.
*/
        if ( kp != k )
        {
          temp = b[k-1];
          b[k-1] = b[kp-1];
          b[kp-1] = temp;
        }
      }
      k = k + 2;
    }
  }
  return;
}
/******************************************************************************/

float sspco ( float ap[], int n, int kpvt[], float z[] )

/******************************************************************************/
/*
  Purpose:

    SSPCO factors a real symmetric matrix stored in packed form.

  Discussion:

    SSPCO uses elimination with symmetric pivoting and estimates
    the condition of the matrix.

    If RCOND is not needed, SSPFA is slightly faster.

    To solve A*X = B, follow SSPCO by SSPSL.

    To compute inverse(A)*C, follow SSPCO by SSPSL.

    To compute inverse(A), follow SSPCO by SSPDI.

    To compute determinant(A), follow SSPCO by SSPDI.

    To compute inertia(A), follow SSPCO by SSPDI.

  Packed storage:

    The following program segment will pack the upper triangle of a
    symmetric matrix.

      k = 0
      do j = 1, n
        do i = 1, j
          k = k + 1
          ap[k-1] = a(i,j)
        }
      }

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float AP[N*(N+1)/2].  On input, the packed form
    of a symmetric matrix A.  The columns of the upper triangle are stored
    sequentially in a one-dimensional array.  On output, a block diagonal
    matrix and the multipliers which were used to obtain it, stored in
    packed form.  The factorization can be written A = U*D*U'
    where U is a product of permutation and unit upper triangular
    matrices, U' is the transpose of U, and D is block diagonal
    with 1 by 1 and 2 by 2 blocks.

    Input, int N, the order of the matrix.

    Output, int KPVT[N], the pivot indices.

    Output, float Z[N] a work vector whose contents are usually
    unimportant.  If A is close to a singular matrix, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).

    Output, float SSPCO, an estimate of the reciprocal condition number RCOND
    of A.  For the system A*X = B, relative perturbations in A and B of size
    EPSILON may cause relative perturbations in X of size EPSILON/RCOND.
    If RCOND is so small that the logical expression
      1.0 + RCOND == 1.0D+00
    is true, then A may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float ak;
  float akm1;
  float anorm;
  float bk;
  float bkm1;
  float denom;
  float ek;
  int i;
  int ij;
  int ik;
  int ikm1;
  int ikp1;
  int j;
  int j1;
  int k;
  int kk;
  int km1k;
  int km1km1;
  int kp;
  int kps;
  int ks;
  float rcond;
  float s;
  float t;
  float ynorm;
/*
  Find norm of A using only upper half.
*/
  j1 = 1;
  for ( j = 1; j <= n; j++ )
  {
    z[j-1] = sasum ( j, ap+j1-1, 1 );
    ij = j1;
    j1 = j1 + j;
    for ( i = 1; i <= j-1; i++ )
    {
      z[i-1] = z[i-1] + fabs ( ap[ij-1] );
      ij = ij + 1;
    }
  }
  anorm = 0.0;
  for ( i = 1; i <= n; i++ )
  {
    anorm = r4_max ( anorm, z[i-1] );
  }
/*
  Factor.
*/
  sspfa ( ap, n, kpvt );
/*
  RCOND = 1/(norm(A)*(estimate of norm(inverse(A)))).

  Estimate = norm(Z)/norm(Y) where A*Z = Y and A*Y = E.

  The components of E are chosen to cause maximum local
  growth in the elements of W where U*D*W = E.

  The vectors are frequently rescaled to avoid overflow.

  Solve U * D * W = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }

  k = n;
  ik = ( n * ( n - 1 ) ) / 2;

  while ( k != 0 )
  {
    kk = ik + k;
    ikm1 = ik - ( k - 1 );

    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    kp = abs ( kpvt[k-1] );
    kps = k + 1 - ks;

    if ( kp != kps )
    {
      t = z[kps-1];
      z[kps-1] = z[kp-1];
      z[kp-1] = t;
    }

    if ( z[k-1] < 0.0 )
    {
      ek = - ek;
    }

    z[k-1] = z[k-1] + ek;
    saxpy ( k-ks, z[k-1], ap+ik, 1, z, 1 );

    if ( ks != 1 )
    {
      if ( z[k-2] < 0.0 )
      {
        ek = - ek;
      }
      z[k-2] = z[k-2] + ek;
      saxpy ( k-ks, z[k-2], ap+ikm1, 1, z, 1 );
    }

    if ( ks != 2 )
    {
      if ( fabs ( ap[kk-1] ) < fabs ( z[k-1] ) )
      {
        s = fabs ( ap[kk-1] ) / fabs ( z[k-1] );
        for ( i = 1; i <= n; i++ )
        {
          z[i-1] = s * z[i-1];
        }
        ek = s * ek;
      }

      if ( ap[kk-1] != 0.0 )
      {
        z[k-1] = z[k-1] / ap[kk-1];
      }
      else
      {
        z[k-1] = 1.0;
      }
    }
    else
    {
      km1k = ik + k - 1;
      km1km1 = ikm1 + k - 1;
      ak = ap[kk-1] / ap[km1k-1];
      akm1 = ap[km1km1-1] / ap[km1k-1];
      bk = z[k-1] / ap[km1k-1];
      bkm1 = z[k-2] / ap[km1k-1];
      denom = ak * akm1 - 1.0;
      z[k-1] = ( akm1 * bk - bkm1 ) / denom;
      z[k-2] = ( ak * bkm1 - bk ) / denom;
    }
    k = k - ks;
    ik = ik - k;
    if ( ks == 2 )
    {
      ik = ik - ( k + 1 );
    }
  }

  s = sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / s;
  }
/*
  Solve U' * Y = W.
*/
  k = 1;
  ik = 0;

  while ( k <= n )
  {
    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    if ( k != 1 )
    {
      z[k-1] = z[k-1] + sdot ( k-1, ap+ik, 1, z, 1 );
      ikp1 = ik + k;

      if ( ks == 2 )
      {
        z[k] = z[k] + sdot ( k-1, ap+ikp1, 1, z, 1 );
      }

      kp = abs ( kpvt[k-1] );

      if ( kp != k )
      {
        t = z[k-1];
        z[k-1] = z[kp-1];
        z[kp-1] = t;
      }
    }

    ik = ik + k;
    if ( ks == 2 )
    {
      ik = ik + ( k + 1 );
    }
    k = k + ks;
  }
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = 1.0;
/*
  Solve U * D * V = Y.
*/
  k = n;

  ik = ( n * ( n - 1 ) ) / 2;

  while ( 0 < k )
  {
    kk = ik + k;
    ikm1 = ik - ( k - 1 );

    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    if ( k != ks )
    {
      kp = abs ( kpvt[k-1] );
      kps = k + 1 - ks;

      if ( kp != kps )
      {
        t = z[kps-1];
        z[kps-1] = z[kp-1];
        z[kp-1] = t;
      }

      saxpy ( k-ks, z[k-1], ap+ik, 1, z, 1 );

      if ( ks == 2 )
      {
        saxpy ( k-ks, z[k-2], ap+ikm1, 1, z, 1 );
      }
    }

    if ( ks != 2 )
    {
      if ( fabs ( ap[kk-1] ) < fabs ( z[k-1] ) )
      {
        s = fabs ( ap[kk-1] ) / fabs ( z[k-1] );
        for ( i = 1; i <= n; i++ )
        {
          z[i-1] = s * z[i-1];
        }
        ynorm = s * ynorm;
      }

      if ( ap[kk-1] != 0.0 )
      {
        z[k-1] = z[k-1] / ap[kk-1];
      }
      else
      {
        z[k-1] = 1.0;
      }
    }
    else
    {
      km1k = ik + k - 1;
      km1km1 = ikm1 + k - 1;
      ak = ap[kk-1] / ap[km1k-1];
      akm1 = ap[km1km1-1] / ap[km1k-1];
      bk = z[k-1] / ap[km1k-1];
      bkm1 = z[k-2] / ap[km1k-1];
      denom = ak * akm1 - 1.0;
      z[k-1] = ( akm1 * bk - bkm1 ) / denom;
      z[k-2] = ( ak * bkm1 - bk ) / denom;
    }
    k = k - ks;
    ik = ik - k;
    if ( ks == 2 )
    {
      ik = ik - ( k + 1 );
    }
  }
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;
/*
  Solve U' * Z = V.
*/
  k = 1;
  ik = 0;

  while ( k <= n )
  {
    if ( kpvt[k-1] < 0 )
    {
      ks = 2;
    }
    else
    {
      ks = 1;
    }

    if ( k != 1 )
    {
      z[k-1] = z[k-1] + sdot ( k-1, ap+ik, 1, z, 1 );
      ikp1 = ik + k;

      if ( ks == 2 )
      {
        z[k] = z[k] + sdot ( k-1, ap+ikp1, 1, z, 1 );
      }

      kp = abs ( kpvt[k-1] );

      if ( kp != k )
      {
        t = z[k-1];
        z[k-1] = z[kp-1];
        z[kp-1] = t;
      }
    }

    ik = ik + k;
    if ( ks == 2 )
    {
      ik = ik + ( k + 1 );
    }
    k = k + ks;
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
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

  return rcond;
}
/******************************************************************************/

void sspdi ( float ap[], int n, int kpvt[], float det[2], int inert[3], 
  float work[], int job )

/******************************************************************************/
/*
  Purpose:

    SSPDI computes the determinant, inertia and inverse of a real symmetric matrix.

  Discussion:

    SSPDI uses the factors from SSPFA, where the matrix is stored in
    packed form.

    A division by zero will occur if the inverse is requested
    and SSPCO has set RCOND == 0.0D+00 or SSPFA has set INFO /= 0.

    Variables not requested by JOB are not used.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float AP[(N*(N+1))/2].  On input, the output from
    SSPFA.  On output, the upper triangle of the inverse of the original
    matrix, stored in packed form, if requested.  The columns of the upper 
    triangle are stored sequentially in a one-dimensional array.

    Input, int N, the order of the matrix.

    Input, int KPVT[N], the pivot vector from SSPFA.

    Output, float DET[2], the determinant of the original matrix,
    if requested.
      determinant = DET[0] * 10.0**DET[1]
    with 1.0D+00 <= abs ( DET[0] ) < 10.0D+00 or DET[0] = 0.0.

    Output, int INERT[3], the inertia of the original matrix, if requested.
    INERT(1) = number of positive eigenvalues.
    INERT(2) = number of negative eigenvalues.
    INERT(3) = number of zero eigenvalues.

    Workspace, float WORK[N].

    Input, int JOB, has the decimal expansion ABC where:
      if A /= 0, the inertia is computed,
      if B /= 0, the determinant is computed,
      if C /= 0, the inverse is computed.
    For example, JOB = 111  gives all three.
*/
{
  float ak;
  float akkp1;
  float akp1;
  float d;
  int dodet;
  int doert;
  int doinv;
  int ij;
  int ik;
  int ikp1;
  int iks;
  int j;
  int jb;
  int jk;
  int jkp1;
  int k;
  int kk;
  int kkp1;
  int km1;
  int ks;
  int ksj;
  int kskp1;
  int kstep;
  float t;
  float temp;

  doinv = ( job %   10 )       != 0;
  dodet = ( job %  100 ) /  10 != 0;
  doert = ( job % 1000 ) / 100 != 0;

  if ( dodet || doert )
  {
    if ( doert )
    {
      inert[0] = 0;
      inert[1] = 0;
      inert[2] = 0;
    }

    if ( dodet )
    {
      det[0] = 1.0;
      det[1] = 0.0;
    }

    t = 0.0;
    ik = 0;

    for ( k = 1; k <= n; k++ )
    {
      kk = ik + k;
      d = ap[kk-1];
/*
  2 by 2 block
  use det (d  s)  =  (d/t * c - t) * t,  t = abs ( s )
          (s  c)
  to avoid underflow/overflow troubles.

  Take two passes through scaling.  Use T for flag.
*/
      if ( kpvt[k-1] <= 0 )
      {
        if ( t == 0.0 )
        {
          ikp1 = ik + k;
          kkp1 = ikp1 + k;
          t = fabs ( ap[kkp1-1] );
          d = ( d / t ) * ap[kkp1] - t;
        }
        else
        {
          d = t;
          t = 0.0;
        }
      }

      if ( doert )
      {
        if ( 0.0 < d )
        {
          inert[0] = inert[0] + 1;
        }
        else if ( d < 0.0 )
        {
          inert[1] = inert[1] + 1;
        }
        else if ( d == 0.0 )
        {
          inert[2] = inert[2] + 1;
        }
      }

      if ( dodet )
      {
        det[0] = det[0] * d;

        if ( det[0] != 0.0 )
        {
          while ( fabs ( det[0] ) < 1.0 )
          {
            det[0] = det[0] * 10.0;
            det[1] = det[1] - 1.0;
          }

          while ( 10.0 <= fabs ( det[0] ) )
          {
            det[0] = det[0] / 10.0;
            det[1] = det[1] + 1.0;
          }
        }
      }
      ik = ik + k;
    }
  }
/*
  Compute inverse(A).
*/
  if ( doinv )
  {
    k = 1;
    ik = 0;

    while ( k <= n )
    {
      km1 = k - 1;
      kk = ik + k;
      ikp1 = ik + k;
      kkp1 = ikp1 + k;

      if ( 0 <= kpvt[k-1] )
      {
/*
  1 by 1.
*/
        ap[kk-1] = 1.0 / ap[kk-1];

        if ( 2 <= k )
        {
          scopy ( k-1, ap+ik, 1, work, 1 );
          ij = 0;

          for ( j = 1; j <= k-1; j++ )
          {
            jk = ik + j;
            ap[jk-1] = sdot ( j, ap+ij, 1, work, 1 );
            saxpy ( j-1, work[j-1], ap+ij, 1, ap+ik, 1 );
            ij = ij + j;
          }
          ap[kk-1] = ap[kk-1] + sdot ( k-1, work, 1, ap+ik, 1 );
        }
        kstep = 1;
      }
      else
      {
/*
  2 by 2.
*/
        t = fabs ( ap[kkp1-1] );
        ak = ap[kk-1] / t;
        akp1 = ap[kkp1] / t;
        akkp1 = ap[kkp1-1] / t;
        d = t * ( ak * akp1 - 1.0 );
        ap[kk-1] = akp1 / d;
        ap[kkp1] = ak / d;
        ap[kkp1-1] = -akkp1 / d;

        if ( 1 <= km1 )
        {
          scopy ( km1, ap+ikp1, 1, work, 1 );
          ij = 0;

          for ( j = 1; j <= km1; j++ )
          {
            jkp1 = ikp1 + j;
            ap[jkp1-1] = sdot ( j, ap+ij, 1, work, 1 );
            saxpy ( j-1, work[j-1], ap+ij, 1, ap+ikp1, 1 );
            ij = ij + j;
          }

          ap[kkp1] = ap[kkp1] + sdot ( km1, work, 1, ap+ikp1, 1 );
          ap[kkp1-1] = ap[kkp1-1] + sdot ( km1, ap+ik, 1, ap+ikp1, 1 );
          scopy ( km1, ap+ik, 1, work, 1 );
          ij = 0;

          for ( j = 1; j <= km1; j++ )
          {
            jk = ik + j;
            ap[jk-1] = sdot ( j, ap+ij, 1, work, 1 );
            saxpy ( j-1, work[j-1], ap+ij, 1, ap+ik, 1 );
            ij = ij + j;
          }
          ap[kk-1] = ap[kk-1] + sdot ( km1, work, 1, ap+ik, 1 );
        }
        kstep = 2;
      }
/*
  Swap.
*/
      ks = abs ( kpvt[k-1] );

      if ( ks != k )
      {
        iks = ( ks * ( ks - 1 ) ) / 2;
        sswap ( ks, ap+iks, 1, ap+ik, 1 );
        ksj = ik + ks;

        for ( jb = ks; jb <= k; jb++ )
        {
          j = k + ks - jb;
          jk = ik + j;
          temp = ap[jk-1];
          ap[jk-1] = ap[ksj-1];
          ap[ksj-1] = temp;
          ksj = ksj - ( j - 1 );
        }

        if ( kstep != 1 )
        {
          kskp1 = ikp1 + ks;
          temp = ap[kskp1-1];
          ap[kskp1-1] = ap[kkp1-1];
          ap[kkp1-1] = temp;
        }
      }
      ik = ik + k;
      if ( kstep == 2 )
      {
        ik = ik + k + 1;
      }
      k = k + kstep;
    }
  }

  return;
}
/******************************************************************************/

int sspfa ( float ap[], int n, int kpvt[] )

/******************************************************************************/
/*
  Purpose:

    SSPFA factors a real symmetric matrix stored in packed form.

  Discussion:

    To solve A*X = B, follow SSPFA by SSPSL.

    To compute inverse(A)*C, follow SSPFA by SSPSL.

    To compute determinant(A), follow SSPFA by SSPDI.

    To compute inertia(A), follow SSPFA by SSPDI.

    To compute inverse(A), follow SSPFA by SSPDI.

  Packed storage:

    The following program segment will pack the upper triangle of a
    symmetric matrix.

      k = 0
      do j = 1, n
        do i = 1, j
          k = k + 1
          ap(k) = a(i,j)
        end do
      end do

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float AP[(N*(N+1))/2].  On input, the packed form of a
    symmetric matrix A.  The columns of the upper triangle are stored
    sequentially in a one-dimensional array.  On output, a block diagonal
    matrix and the multipliers which were used to obtain it stored in
    packed form.  The factorization can be written A = U*D*U' where U
    is a product of permutation and unit upper triangular matrices, U'
    is the transpose of U, and D is block diagonal with 1 by 1 and 2
    by 2 blocks.

    Input, int N, the order of the matrix.

    Output, int KPVT[N], the pivot indices.

    Output, int SSPFA, error flag.
    0, normal value.
    K, if the K-th pivot block is singular.  This is not an error
    condition for this subroutine, but it does indicate that SSPSL or
    SSPDI may divide by zero if called.
*/
{
  float absakk;
  float ak;
  float akm1;
  float alpha;
  float bk;
  float bkm1;
  float colmax;
  float denom;
  int ij;
  int ik;
  int ikm1;
  int im;
  int imax;
  int imaxp1;
  int imim;
  int imj;
  int imk;
  int info;
  int j;
  int jj;
  int jk;
  int jkm1;
  int jmax;
  int jmim;
  int k;
  int kk;
  int km1;
  int km1k;
  int km1km1;
  int kstep;
  float mulk;
  float mulkm1;
  float rowmax;
  int swap;
  float t;
/*
  ALPHA is used in choosing pivot block size.
*/
  alpha = ( 1.0 + sqrt ( 17.0 ) ) / 8.0;

  info = 0;
/*
  Main loop on K, which goes from N to 1.
*/
  k = n;
  ik = ( n * ( n - 1 ) ) / 2;

  for ( ; ; )
  {
/*
  Leave the loop if K = 0 or K = 1.
*/
    if ( k == 0 )
    {
      break;
    }

    if ( k == 1 )
    {
      kpvt[0] = 1;
      if ( ap[0] == 0.0 )
      {
        info = 1;
      }
      break;
    }
/*
  This section of code determines the kind of elimination to be performed.
  When it is completed, KSTEP will be set to the size of the pivot block,
  and SWAP will be set to .true. if an interchange is required.
*/
    km1 = k - 1;
    kk = ik + k;
    absakk = fabs ( ap[kk-1] );
/*
  Determine the largest off-diagonal element in column K.
*/
    imax = isamax ( k-1, ap+ik, 1 );
    imk = ik + imax;
    colmax = fabs ( ap[imk-1] );

    if ( alpha * colmax <= absakk )
    {
      kstep = 1;
      swap = 0;
    }
/*
  Determine the largest off-diagonal element in row IMAX.
*/
    else
    {
      rowmax = 0.0;
      imaxp1 = imax + 1;
      im = ( imax * ( imax - 1 ) ) / 2;
      imj = im + 2 * imax;

      for ( j = imaxp1; j <= k; j++ )
      {
        rowmax = r4_max ( rowmax, fabs ( ap[imj-1] ) );
        imj = imj + j;
      }

      if ( imax != 1 )
      {
        jmax = isamax ( imax-1, ap+im, 1 );
        jmim = jmax + im;
        rowmax = r4_max ( rowmax, fabs ( ap[jmim-1] ) );
      }

      imim = imax + im;

      if ( alpha * rowmax <= fabs ( ap[imim-1] ) )
      {
        kstep = 1;
        swap = 1;
      }
      else if ( alpha * colmax * ( colmax / rowmax ) <= absakk )
      {
        kstep = 1;
        swap = 0;
      }
      else
      {
        kstep = 2;
        swap = imax != km1;
      }
    }
/*
  Column K is zero.  Set INFO and iterate the loop.
*/
    if ( r4_max ( absakk, colmax ) == 0.0 )
    {
      kpvt[k-1] = k;
      info = k;
    }
    else
    {
      if ( kstep != 2 )
      {
/*
  1 x 1 pivot block.
*/
        if ( swap )
        {
/*
  Perform an interchange.
*/
          sswap ( imax, ap+im, 1, ap+ik, 1 );
          imj = ik + imax;

          for ( jj = imax; jj <= k; jj++ )
          {
            j = k + imax - jj;
            jk = ik + j;
            t = ap[jk-1];
            ap[jk-1] = ap[imj-1];
            ap[imj-1] = t;
            imj = imj - ( j - 1 );
          }
        }
/*
  Perform the elimination.
*/
        ij = ik - ( k - 1 );

        for ( jj = 1; jj <= km1; jj++ )
        {
          j = k - jj;
          jk = ik + j;
          mulk = -ap[jk-1] / ap[kk-1];
          t = mulk;
          saxpy ( j, t, ap+ik, 1, ap+ij, 1 );
          ap[jk-1] = mulk;
          ij = ij - ( j - 1 );
        }
/*
  Set the pivot array.
*/
        if ( swap )
        {
          kpvt[k-1] = imax;
        }
        else
        {
          kpvt[k-1] = k;
        }
      }
      else
      {
/*
  2 x 2 pivot block.
*/
        km1k = ik + k - 1;
        ikm1 = ik - ( k - 1 );
/*
  Perform an interchange.
*/
        if ( swap )
        {
          sswap ( imax, ap+im, 1, ap+ikm1, 1 );
          imj = ikm1 + imax;

          for ( jj = imax; jj <= km1; jj++ )
          {
            j = km1 + imax - jj;
            jkm1 = ikm1 + j;
            t = ap[jkm1-1];
            ap[jkm1-1] = ap[imj-1];
            ap[imj-1] = t;
            imj = imj - ( j - 1 );
          }
          t = ap[km1k-1];
          ap[km1k-1] = ap[imk-1];
          ap[imk-1] = t;
        }
/*
  Perform the elimination.
*/
        if ( k-2 != 0 )
        {
          ak = ap[kk-1] / ap[km1k-1];
          km1km1 = ikm1 + k - 1;
          akm1 = ap[km1km1-1] / ap[km1k-1];
          denom = 1.0 - ak * akm1;
          ij = ik - ( k - 1 ) - ( k - 2 );

          for ( jj = 1; jj <= k-2; jj++ )
          {
            j = km1 - jj;
            jk = ik + j;
            bk = ap[jk-1] / ap[km1k-1];
            jkm1 = ikm1 + j;
            bkm1 = ap[jkm1-1] / ap[km1k-1];
            mulk = ( akm1 * bk - bkm1 ) / denom;
            mulkm1 = ( ak * bkm1 - bk ) / denom;
            t = mulk;
            saxpy ( j, t, ap+ik, 1, ap+ij, 1 );
            t = mulkm1;
            saxpy ( j, t, ap+ikm1, 1, ap+ij, 1 );
            ap[jk-1] = mulk;
            ap[jkm1-1] = mulkm1;
            ij = ij - ( j - 1 );
          }
        }
/*
  Set the pivot array.
*/
        if ( swap )
        {
          kpvt[k-1] = -imax;
        }
        else
        {
          kpvt[k-1] = 1 - k;
        }
        kpvt[k-2] = kpvt[k-1];
      }
    }

    ik = ik - ( k - 1 );
    if ( kstep == 2 )
    {
      ik = ik - ( k - 2 );
    }

    k = k - kstep;

  }

  return info;
}
/******************************************************************************/

void sspsl ( float ap[], int n, int kpvt[], float b[] )

/******************************************************************************/
/*
  Purpose:

    SSPSL solves the real symmetric system factored by SSPFA.

  Discussion:

    To compute inverse(A) * C where C is a matrix with P columns:

      call sspfa ( ap, n, kpvt, info )

      if ( info /= 0 ) go to ...

      do j = 1, p
        call sspsl ( ap, n, kpvt, c(1,j) )
      end do

    A division by zero may occur if SSPCO has set RCOND == 0.0D+00
    or SSPFA has set INFO /= 0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float AP[(N*(N+1))/2], the output from SSPFA.

    Input, int N, the order of the matrix.

    Input, int KPVT[N], the pivot vector from SSPFA.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.
*/
{
  float ak;
  float akm1;
  float bk;
  float bkm1;
  float denom;
  int ik;
  int ikm1;
  int ikp1;
  int k;
  int kk;
  int km1k;
  int km1km1;
  int kp;
  float temp;
/*
  Loop backward applying the transformations and D inverse to B.
*/
  k = n;
  ik = ( n * ( n - 1 ) ) / 2;

  while ( 0 < k )
  {
    kk = ik + k;

    if ( 0 <= kpvt[k-1] )
    {
/*
  1 x 1 pivot block.
*/
      if ( k != 1 )
      {
        kp = kpvt[k-1];
/*
  Interchange.
*/
        if ( kp != k )
        {
          temp = b[k-1];
          b[k-1] = b[kp-1];
          b[kp-1] = temp;
        }
/*
  Apply the transformation.
*/
        saxpy ( k-1, b[k-1], ap+ik, 1, b, 1 );
      }
/*
  Apply D inverse.
*/
      b[k-1] = b[k-1] / ap[kk-1];
      k = k - 1;
      ik = ik - k;
    }
    else
    {
/*
  2 x 2 pivot block.
*/
      ikm1 = ik - ( k - 1 );

      if ( k != 2 )
      {
        kp = abs ( kpvt[k-1] );
/*
  Interchange.
*/
        if ( kp != k-1 )
        {
          temp = b[k-2];
          b[k-2] = b[kp-1];
          b[kp-1] = temp;
        }
/*
  Apply the transformation.
*/
        saxpy ( k-2, b[k-1], ap+ik, 1, b, 1 );
        saxpy ( k-2, b[k-2], ap+ikm1, 1, b, 1 );
      }
/*
  Apply D inverse.
*/
      km1k = ik + k - 1;
      kk = ik + k;
      ak = ap[kk-1] / ap[km1k-1];
      km1km1 = ikm1 + k - 1;
      akm1 = ap[km1km1-1] / ap[km1k-1];
      bk = b[k-1] / ap[km1k-1];
      bkm1 = b[k-2] / ap[km1k-1];
      denom = ak * akm1 - 1.0;
      b[k-1] = ( akm1 * bk - bkm1 ) / denom;
      b[k-2] = ( ak * bkm1 - bk ) / denom;
      k = k - 2;
      ik = ik - ( k + 1 ) - k;
    }
  }
/*
  Loop forward applying the transformations.
*/
  k = 1;
  ik = 0;

  while ( k <= n )
  {
    if ( 0 <= kpvt[k-1] )
    {
/*
  1 x 1 pivot block.
*/
      if ( k != 1 )
      {
/*
  Apply the transformation.
*/
        b[k-1] = b[k-1] + sdot ( k-1, ap+ik, 1, b, 1 );
        kp = kpvt[k-1];
/*
  Interchange.
*/
        if ( kp != k )
        {
          temp = b[k-1];
          b[k-1] = b[kp-1];
          b[kp-1] = temp;
        }
      }
      ik = ik + k;
      k = k + 1;
    }
    else
    {
/*
  2 x 2 pivot block.
*/
      if ( k != 1 )
      {
/*
  Apply the transformation.
*/
        b[k-1] = b[k-1] + sdot ( k-1, ap+ik, 1, b, 1 );
        ikp1 = ik + k;
        b[k] = b[k] + sdot ( k-1, ap+ikp1, 1, b, 1 );
        kp = abs ( kpvt[k-1] );
/*
  Interchange.
*/
        if ( kp != k )
        {
          temp = b[k-1];
          b[k-1] = b[kp-1];
          b[kp-1] = temp;
        }
      }
      ik = ik + k + k + 1;
      k = k + 2;
    }
  }

  return;
}
/******************************************************************************/

int ssvdc ( float a[], int lda, int m, int n, float s[], float e[], 
  float u[], int ldu, float v[], int ldv, float work[], int job )

/******************************************************************************/
/*
  Purpose:

    SSVDC computes the singular value decomposition of a real rectangular matrix.

  Discussion:

    This routine reduces an M by N matrix A to diagonal form by orthogonal
    transformations U and V.  The diagonal elements S(I) are the singular
    values of A.  The columns of U are the corresponding left singular
    vectors, and the columns of V the right singular vectors.

    The form of the singular value decomposition is then

      A(MxN) = U(MxM) * S(MxN) * V(NxN)'

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 May 2007

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float A[LDA*N].  On input, the M by N matrix whose
    singular value decomposition is to be computed.  On output, the matrix
    has been destroyed.  Depending on the user's requests, the matrix may 
    contain other useful information.

    Input, int LDA, the leading dimension of the array A.
    LDA must be at least M.

    Input, int M, the number of rows of the matrix.

    Input, int N, the number of columns of the matrix A.

    Output, float S[MM], where MM = min(M+1,N).  The first
    min(M,N) entries of S contain the singular values of A arranged in
    descending order of magnitude.

    Output, float E[N], where MM = min(M+1,N), ordinarily contains zeros.
    However see the discussion of INFO for exceptions.

    Output, float U[LDU*K].  If JOBA = 1 then K = M;
    if 2 <= JOBA, then K = min(M,N).  U contains the M by M matrix of left singular
    vectors.  U is not referenced if JOBA = 0.  If M <= N or if JOBA = 2, then
    U may be identified with A in the subroutine call.

    Input, int LDU, the leading dimension of the array U.
    LDU must be at least M.

    Output, float V[LDV*N], the N by N matrix of right singular vectors.
    V is not referenced if JOB is 0.  If N <= M, then V may be identified
    with A in the subroutine call.

    Input, int LDV, the leading dimension of the array V.
    LDV must be at least N.

    Workspace, float WORK[M].

    Input, int JOB, controls the computation of the singular
    vectors.  It has the decimal expansion AB with the following meaning:
      A =  0, do not compute the left singular vectors.
      A =  1, return the M left singular vectors in U.
      A >= 2, return the first min(M,N) singular vectors in U.
      B =  0, do not compute the right singular vectors.
      B =  1, return the right singular vectors in V.

    Output, int SSVDC, status indicator INFO.
    The singular values (and their corresponding singular vectors)
    S(*INFO+1), S(*INFO+2),...,S(MN) are correct.  Here MN = min ( M, N ).
    Thus if *INFO is 0, all the singular values and their vectors are
    correct.  In any event, the matrix B = U' * A * V is the bidiagonal
    matrix with the elements of S on its diagonal and the elements of E on
    its superdiagonal.  Thus the singular values of A and B are the same.
*/
{
  float b;
  float c;
  float cs;
  float el;
  float emm1;
  float f;
  float g;
  int i;
  int info;
  int iter;
  int j;
  int jobu;
  int k;
  int kase;
  int kk;
  int l;
  int ll;
  int lls;
  int ls;
  int lu;
  int maxit = 30;
  int mm;
  int mm1;
  int mn;
  int nct;
  int nctp1;
  int ncu;
  int nrt;
  int nrtp1;
  float scale;
  float shift;
  float sl;
  float sm;
  float smm1;
  float sn;
  float t;
  float t1;
  float test;
  int wantu;
  int wantv;
  float ztest;
/*
  Determine what is to be computed.
*/
  info = 0;
  wantu = 0;
  wantv = 0;
  jobu = ( job % 100 ) / 10;

  if ( 1 < jobu )
  {
    ncu = i4_min ( m, n );
  }
  else
  {
    ncu = m;
  }

  if ( jobu != 0 )
  {
    wantu = 1;
  }

  if ( ( job % 10 ) != 0 )
  {
    wantv = 1;
  }
/*
  Reduce A to bidiagonal form, storing the diagonal elements
  in S and the super-diagonal elements in E.
*/
  nct = i4_min ( m-1, n );
  nrt = i4_max ( 0, i4_min ( m, n-2 ) );
  lu = i4_max ( nct, nrt );

  for ( l = 1; l <= lu; l++ )
  {
/*
  Compute the transformation for the L-th column and
  place the L-th diagonal in S(L).
*/
    if ( l <= nct )
    {
      s[l-1] = snrm2 ( m-l+1, a+l-1+(l-1)*lda, 1 );

      if ( s[l-1] != 0.0 )
      {
        if ( a[l-1+(l-1)*lda] < 0.0 )
        {
          s[l-1] = - s[l-1];
        }
        sscal ( m-l+1, 1.0 / s[l-1], a+l-1+(l-1)*lda, 1 );
        a[l-1+(l-1)*lda] = 1.0 + a[l-1+(l-1)*lda];
      }

      s[l-1] = -s[l-1];

    }

    for ( j = l+1; j <= n; j++ )
    {
/*
  Apply the transformation.
*/
      if ( l <= nct && s[l-1] != 0.0 )
      {
        t = - sdot ( m-l+1, a+l-1+(l-1)*lda, 1, a+l-1+(j-1)*lda, 1 ) 
          / a[l-1+(l-1)*lda];
        saxpy ( m-l+1, t, a+l-1+(l-1)*lda, 1, a+l-1+(j-1)*lda, 1 );
      }
/*
  Place the L-th row of A into E for the
  subsequent calculation of the row transformation.
*/
      e[j-1] = a[l-1+(j-1)*lda];
    }
/*
  Place the transformation in U for subsequent back multiplication.
*/
    if ( wantu && l <= nct )
    {
      for ( i = l; i <= m; i++ )
      {
        u[i-1+(l-1)*ldu] = a[i-1+(l-1)*lda];
      }
    }

    if ( l <= nrt )
    {
/*
  Compute the L-th row transformation and place the
  L-th superdiagonal in E(L).
*/
      e[l-1] = snrm2 ( n-l, e+l, 1 );

      if ( e[l-1] != 0.0 )
      {
        if ( e[l] < 0.0 )
        {
          e[l-1] = - e[l-1];
        }
        sscal ( n-l, 1.0 / e[l-1], e+l, 1 );
        e[l] = 1.0 + e[l];
      }

      e[l-1] = -e[l-1];
/*
  Apply the transformation.
*/
      if ( l+1 <= m && e[l-1] != 0.0 )
      {
        for ( j = l+1; j <= m; j++ )
        {
          work[j-1] = 0.0;
        }

        for ( j = l+1; j <= n; j++ )
        {
          saxpy ( m-l, e[j-1], a+l+(j-1)*lda, 1, work+l, 1 );
        }

        for ( j = l+1; j <= n; j++ )
        {
          saxpy ( m-l, -e[j-1]/e[l], work+l, 1, a+l+(j-1)*lda, 1 );
        }
      }
/*
  Place the transformation in V for subsequent back multiplication.
*/
      if ( wantv )
      {
        for ( j = l+1; j <= n; j++ )
        {
          v[j-1+(l-1)*ldv] = e[j-1];
        }
      }
    }
  }
/*
  Set up the final bidiagonal matrix of order MN.
*/
  mn = i4_min ( m + 1, n );
  nctp1 = nct + 1;
  nrtp1 = nrt + 1;

  if ( nct < n )
  {
    s[nctp1-1] = a[nctp1-1+(nctp1-1)*lda];
  }

  if ( m < mn )
  {
    s[mn-1] = 0.0;
  }

  if ( nrtp1 < mn )
  {
    e[nrtp1-1] = a[nrtp1-1+(mn-1)*lda];
  }

  e[mn-1] = 0.0;
/*
  If required, generate U.
*/
  if ( wantu )
  {
    for ( i = 1; i <= m; i++ )
    {
      for ( j = nctp1; j <= ncu; j++ )
      {
        u[(i-1)+(j-1)*ldu] = 0.0;
      }
    }

    for ( j = nctp1; j <= ncu; j++ )
    {
      u[j-1+(j-1)*ldu] = 1.0;
    }

    for ( ll = 1; ll <= nct; ll++ )
    {
      l = nct - ll + 1;

      if ( s[l-1] != 0.0 )
      {
        for ( j = l+1; j <= ncu; j++ )
        {
          t = - sdot ( m-l+1, u+(l-1)+(l-1)*ldu, 1, u+(l-1)+(j-1)*ldu, 1 ) 
            / u[l-1+(l-1)*ldu];
          saxpy ( m-l+1, t, u+(l-1)+(l-1)*ldu, 1, u+(l-1)+(j-1)*ldu, 1 );
        }

        sscal ( m-l+1, -1.0, u+(l-1)+(l-1)*ldu, 1 );
        u[l-1+(l-1)*ldu] = 1.0 + u[l-1+(l-1)*ldu];
        for ( i = 1; i <= l-1; i++ )
        {
          u[i-1+(l-1)*ldu] = 0.0;
        }
      }
      else
      {
        for ( i = 1; i <= m; i++ )
        {
          u[i-1+(l-1)*ldu] = 0.0;
        }
        u[l-1+(l-1)*ldu] = 1.0;
      }
    }
  }
/*
  If it is required, generate V.
*/
  if ( wantv )
  {
    for ( ll = 1; ll <= n; ll++ )
    {
      l = n - ll + 1;

      if ( l <= nrt && e[l-1] != 0.0 )
      {
        for ( j = l+1; j <= n; j++ )
        {
          t = - sdot ( n-l, v+l+(l-1)*ldv, 1, v+l+(j-1)*ldv, 1 ) 
            / v[l+(l-1)*ldv];
          saxpy ( n-l, t, v+l+(l-1)*ldv, 1, v+l+(j-1)*ldv, 1 );
        }

      }
      for ( i = 1; i <= n; i++ )
      {
        v[i-1+(l-1)*ldv] = 0.0;
      }
      v[l-1+(l-1)*ldv] = 1.0;
    }
  }
/*
  Main iteration loop for the singular values.
*/
  mm = mn;
  iter = 0;

  while ( 0 < mn )
  {
/*
  If too many iterations have been performed, set flag and return.
*/
    if ( maxit <= iter )
    {
      info = mn;
      return info;
    }
/*
  This section of the program inspects for
  negligible elements in the S and E arrays.

  On completion the variables KASE and L are set as follows:

  KASE = 1     if S(MN) and E(L-1) are negligible and L < MN
  KASE = 2     if S(L) is negligible and L < MN
  KASE = 3     if E(L-1) is negligible, L < MN, and
               S(L), ..., S(MN) are not negligible (QR step).
  KASE = 4     if E(MN-1) is negligible (convergence).
*/
    for ( ll = 1; ll <= mn; ll++ )
    {
      l = mn - ll;

      if ( l == 0 )
      {
        break;
      }

      test = fabs ( s[l-1] ) + fabs ( s[l] );
      ztest = test + fabs ( e[l-1] );

      if ( ztest == test )
      {
        e[l-1] = 0.0;
        break;
      }
    }

    if ( l == mn - 1 )
    {
      kase = 4;
    }
    else
    {
      for ( lls = l + 1; lls <= mn + 1; lls++ )
      {
        ls = mn - lls + l + 1;

        if ( ls == l )
        {
          break;
        }

        test = 0.0;
        if ( ls != mn )
        {
          test = test + fabs ( e[ls-1] );
        }

        if ( ls != l + 1 )
        {
          test = test + fabs ( e[ls-2] );
        }

        ztest = test + fabs ( s[ls-1] );

        if ( ztest == test )
        {
          s[ls-1] = 0.0;
          break;
        }

      }

      if ( ls == l )
      {
        kase = 3;
      }
      else if ( ls == mn )
      {
        kase = 1;
      }
      else
      {
        kase = 2;
        l = ls;
      }
    }

    l = l + 1;
/*
  Deflate negligible S(MN).
*/
    if ( kase == 1 )
    {
      mm1 = mn - 1;
      f = e[mn-2];
      e[mn-2] = 0.0;

      for ( kk = 1; kk <= mm1; kk++ )
      {
        k = mm1 - kk + l;
        t1 = s[k-1];
        srotg ( &t1, &f, &cs, &sn );
        s[k-1] = t1;

        if ( k != l )
        {
          f = -sn * e[k-2];
          e[k-2] = cs * e[k-2];
        }

        if ( wantv )
        {
          srot ( n, v+0+(k-1)*ldv, 1, v+0+(mn-1)*ldv, 1, cs, sn );
        }
      }
    }
/*
  Split at negligible S(L).
*/
    else if ( kase == 2 )
    {
      f = e[l-2];
      e[l-2] = 0.0;

      for ( k = l; k <= mn; k++ )
      {
        t1 = s[k-1];
        srotg ( &t1, &f, &cs, &sn );
        s[k-1] = t1;
        f = - sn * e[k-1];
        e[k-1] = cs * e[k-1];
        if ( wantu )
        {
          srot ( m, u+0+(k-1)*ldu, 1, u+0+(l-2)*ldu, 1, cs, sn );
        }
      }
    }
/*
  Perform one QR step.
*/
    else if ( kase == 3 )
    {
/*
  Calculate the shift.
*/
      scale = r4_max ( fabs ( s[mn-1] ), 
              r4_max ( fabs ( s[mn-2] ), 
              r4_max ( fabs ( e[mn-2] ), 
              r4_max ( fabs ( s[l-1] ), fabs ( e[l-1] ) ) ) ) );

      sm = s[mn-1] / scale;
      smm1 = s[mn-2] / scale;
      emm1 = e[mn-2] / scale;
      sl = s[l-1] / scale;
      el = e[l-1] / scale;
      b = ( ( smm1 + sm ) * ( smm1 - sm ) + emm1 * emm1 ) / 2.0;
      c = ( sm * emm1 ) * ( sm * emm1 );
      shift = 0.0;

      if ( b != 0.0 || c != 0.0 )
      {
        shift = sqrt ( b * b + c );
        if ( b < 0.0 )
        {
          shift = -shift;
        }
        shift = c / ( b + shift );
      }

      f = ( sl + sm ) * ( sl - sm ) - shift;
      g = sl * el;
/*
  Chase zeros.
*/
      mm1 = mn - 1;

      for ( k = l; k <= mm1; k++ )
      {
        srotg ( &f, &g, &cs, &sn );

        if ( k != l )
        {
          e[k-2] = f;
        }

        f = cs * s[k-1] + sn * e[k-1];
        e[k-1] = cs * e[k-1] - sn * s[k-1];
        g = sn * s[k];
        s[k] = cs * s[k];

        if ( wantv )
        {
          srot ( n, v+0+(k-1)*ldv, 1, v+0+k*ldv, 1, cs, sn );
        }

        srotg ( &f, &g, &cs, &sn );
        s[k-1] = f;
        f = cs * e[k-1] + sn * s[k];
        s[k] = -sn * e[k-1] + cs * s[k];
        g = sn * e[k];
        e[k] = cs * e[k];

        if ( wantu && k < m )
        {
          srot ( m, u+0+(k-1)*ldu, 1, u+0+k*ldu, 1, cs, sn );
        }
      }
      e[mn-2] = f;
      iter = iter + 1;
    }
/*
  Convergence.
*/
    else if ( kase == 4 )
    {
/*
  Make the singular value nonnegative.
*/
      if ( s[l-1] < 0.0 )
      {
        s[l-1] = -s[l-1];
        if ( wantv )
        {
          sscal ( n, -1.0, v+0+(l-1)*ldv, 1 );
        }
      }
/*
  Order the singular value.
*/
      for ( ; ; )
      {
        if ( l == mm )
        {
          break;
        }

        if ( s[l] <= s[l-1] )
        {
          break;
        }

        t = s[l-1];
        s[l-1] = s[l];
        s[l] = t;

        if ( wantv && l < n )
        {
          sswap ( n, v+0+(l-1)*ldv, 1, v+0+l*ldv, 1 );
        }

        if ( wantu && l < m )
        {
          sswap ( m, u+0+(l-1)*ldu, 1, u+0+l*ldu, 1 );
        }

        l = l + 1;
      }
      iter = 0;
      mn = mn - 1;
    }
  }

  return info;
}
/******************************************************************************/

float strco ( float t[], int ldt, int n, float z[], int job )

/******************************************************************************/
/*
  Purpose:

    STRCO estimates the condition of a real triangular matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float T[LDT*N], the triangular matrix.  The zero
    elements of the matrix are not referenced, and the corresponding
    elements of the array can be used to store other information.

    Input, int LDT, the leading dimension of the array T.

    Input, int N, the order of the matrix.

    Output, float Z[N] a work vector whose contents are usually
    unimportant.  If T is close to a singular matrix, then Z is an
    approximate null vector in the sense that
      norm(A*Z) = RCOND * norm(A) * norm(Z).

    Input, int JOB, indicates the shape of T:
    0, T is lower triangular.
    nonzero, T is upper triangular.

    Output, float STRCO, an estimate of the reciprocal condition RCOND
    of T.  For the system T*X = B, relative perturbations in T and B of size
    EPSILON may cause relative perturbations in X of size EPSILON/RCOND.
    If RCOND is so small that the logical expression
      1.0D+00 + RCOND == 1.0D+00
    is true, then T may be singular to working precision.  In particular,
    RCOND is zero if exact singularity is detected or the estimate underflows.
*/
{
  float ek;
  int i;
  int i1;
  int j;
  int j1;
  int j2;
  int k;
  int kk;
  int l;
  int lower;
  float rcond;
  float s;
  float sm;
  float temp;
  float tnorm;
  float w;
  float wk;
  float wkm;
  float ynorm;

  lower = ( job == 0 );
/*
  Compute the 1-norm of T.
*/
  tnorm = 0.0;

  for ( j = 1; j <= n; j++ )
  {
    if ( lower )
    {
      l = n + 1 - j;
      i1 = j;
    }
    else
    {
      l = j;
      i1 = 1;
    }
    tnorm = r4_max ( tnorm, sasum ( l, t+i1-1+(j-1)*ldt, 1 ) );
  }
/*
  RCOND = 1/(norm(T)*(estimate of norm(inverse(T)))).

  Estimate = norm(Z)/norm(Y) where T * Z = Y and T' * Y = E.

  T' is the transpose of T.

  The components of E are chosen to cause maximum local
  growth in the elements of Y.

  The vectors are frequently rescaled to avoid overflow.

  Solve T' * Y = E.
*/
  ek = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = 0.0;
  }

  for ( kk = 1; kk <= n; kk++ )
  {
    if ( lower )
    {
      k = n + 1 - kk;
    }
    else
    {
      k = kk;
    }

    if ( 0.0 < z[k-1] )
    {
      ek = - ek;
    }

    if ( fabs ( t[k-1+(k-1)*ldt] ) < fabs ( ek - z[k-1] ) )
    {
      s = fabs ( t[k-1+(k-1)*ldt] ) / fabs ( ek - z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ek = s * ek;
    }

    wk = ek - z[k-1];
    wkm = -ek - z[k-1];
    s = fabs ( wk );
    sm = fabs ( wkm );

    if ( t[k-1+(k-1)*ldt] != 0.0 )
    {
      wk = wk / t[k-1+(k-1)*ldt];
      wkm = wkm / t[k-1+(k-1)*ldt];
    }
    else
    {
      wk = 1.0;
      wkm = 1.0;
    }

    if ( kk != n )
    {
      if ( lower )
      {
        j1 = 1;
        j2 = k - 1;
      }
      else
      {
        j1 = k + 1;
        j2 = n;
      }

      for ( j = j1; j <= j2; j++ )
      {
        sm = sm + fabs ( z[j-1] + wkm * t[k-1+(j-1)*ldt] );
        z[j-1] = z[j-1] + wk * t[k-1+(j-1)*ldt];
        s = s + fabs ( z[j-1] );
      }

      if ( s < sm )
      {
        w = wkm - wk;
        wk = wkm;
        for ( j = j1; j <= j2; j++ )
        {
          z[j-1] = z[j-1] + w * t[k-1+(j-1)*ldt];
        }
      }
    }
    z[k-1] = wk;
  }

  temp = sasum ( n, z, 1 );

  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = z[i-1] / temp;
  }

  ynorm = 1.0;
/*
  Solve T * Z = Y.
*/
  for ( kk = 1; kk <= n; kk++ )
  {
    if ( lower )
    {
      k = kk;
    }
    else
    {
      k = n + 1 - kk;
    }

    if ( fabs ( t[k-1+(k-1)*ldt] ) < fabs ( z[k-1] ) )
    {
      s = fabs ( t[k-1+(k-1)*ldt] ) / fabs ( z[k-1] );
      for ( i = 1; i <= n; i++ )
      {
        z[i-1] = s * z[i-1];
      }
      ynorm = s * ynorm;
    }

    if ( t[k-1+(k-1)*ldt] != 0.0 )
    {
      z[k-1] = z[k-1] / t[k-1+(k-1)*ldt];
    }
    else
    {
      z[k-1] = 1.0;
    }

    if ( lower )
    {
      i1 = k + 1;
    }
    else
    {
      i1 = 1;
    }

    if ( kk < n )
    {
      w = -z[k-1];
      saxpy ( n-kk, w, t+i1-1+(k-1)*ldt, 1, z+i1-1, 1 );
    }
  }
/*
  Make ZNORM = 1.0.
*/
  s = 1.0 / sasum ( n, z, 1 );
  for ( i = 1; i <= n; i++ )
  {
    z[i-1] = s * z[i-1];
  }
  ynorm = s * ynorm;

  if ( tnorm != 0.0 )
  {
    rcond = ynorm / tnorm;
  }
  else
  {
    rcond = 0.0;
  }

  return rcond;
}
/******************************************************************************/

int strdi ( float t[], int ldt, int n, float det[], int job )

/******************************************************************************/
/*
  Purpose:

    STRDI computes the determinant and inverse of a real triangular matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input/output, float T[LDT*N].
    On input, T contains the triangular matrix.  The zero elements of the
    matrix are not referenced, and the corresponding elements of the array
    can be used to store other information.
    On output, T contains the inverse matrix, if it was requested.

    Input, int LDT, the leading dimension of T.

    Input, int N, the order of the matrix.

    Output, float DET[2], the determinant of the matrix, if
    requested.  The determinant = DET[0] * 10.0**DET[1], with
    1.0 <= abs ( DET[0] ) < 10.0, or DET[0] == 0.

    Input, int JOB, specifies the shape of T, and the task.
    010, inverse of lower triangular matrix.
    011, inverse of upper triangular matrix.
    100, determinant only.
    110, determinant and inverse of lower triangular.
    111, determinant and inverse of upper triangular.

    Output, int STRDI.
    If the inverse was requested, then
    0, if the system was nonsingular;
    nonzero, if the system was singular.
*/
{
  int i;
  int info;
  int j;
  int k;
  float temp;
/*
  Determinant.
*/
  info = 0;

  if ( job / 100 != 0 )
  {
    det[0] = 1.0;
    det[1] = 0.0;

    for ( i = 1; i <= n; i++ )
    {
      det[0] = det[0] * t[i-1+(i-1)*ldt];

      if ( det[0] == 0.0 )
      {
        break;
      }

      while ( fabs ( det[0] ) < 1.0 )
      {
        det[0] = det[0] * 10.0;
        det[1] = det[1] - 1.0;
      }

      while ( 10.0 <= fabs ( det[0] ) )
      {
        det[0] = det[0] / 10.0;
        det[1] = det[1] + 1.0;
      }
    }
  }

  if ( ( ( job / 10 ) % 10 ) == 0 )
  {
    return info;
  }
/*
  Inverse of an upper triangular matrix.
*/
  if ( ( job % 10 ) != 0 )
  {
    info = 0;

    for ( k = 1; k <= n; k++ )
    {
      if ( t[k-1+(k-1)*ldt] == 0.0 )
      {
        info = k;
        break;
      }

      t[k-1+(k-1)*ldt] = 1.0 / t[k-1+(k-1)*ldt];
      temp = -t[k-1+(k-1)*ldt];
      sscal ( k-1, temp, t+0+(k-1)*ldt, 1 );

      for ( j = k + 1; j <= n; j++ )
      {
        temp = t[k-1+(j-1)*ldt];
        t[k-1+(j-1)*ldt] = 0.0;
        saxpy ( k, temp, t+0+(k-1)*ldt, 1, t+0+(j-1)*ldt, 1 );
      }
    }
  }
/*
  Inverse of a lower triangular matrix.
*/
  else
  {
    info = 0;

    for ( k = n; 1 <= k; k-- )
    {
      if ( t[k-1+(k-1)*ldt] == 0.0 )
      {
        info = k;
        break;
      }

      t[k-1+(k-1)*ldt] = 1.0 / t[k-1+(k-1)*ldt];
      temp = -t[k-1+(k-1)*ldt];

      if ( k != n )
      {
        sscal ( n-k, temp, t+k+(k-1)*ldt, 1 );
      }

      for ( j = 1; j <= k-1; j++ )
      {
        temp = t[k-1+(j-1)*ldt];
        t[k-1+(j-1)*ldt] = 0.0;
        saxpy ( n-k+1, temp, t+k-1+(k-1)*ldt, 1, t+k-1+(j-1)*ldt, 1 );
      }
    }
  }

  return info;
}
/******************************************************************************/

int strsl ( float t[], int ldt, int n, float b[], int job )

/******************************************************************************/
/*
  Purpose:

    STRSL solves triangular linear systems.

  Discussion:

    STRSL can solve T * X = B or T' * X = B where T is a triangular
    matrix of order N.

    Here T' denotes the transpose of the matrix T.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 April 2006

  Author:

    C version by John Burkardt.

  Reference:

    Jack Dongarra, Cleve Moler, Jim Bunch and Pete Stewart,
    LINPACK User's Guide,
    SIAM, (Society for Industrial and Applied Mathematics),
    3600 University City Science Center,
    Philadelphia, PA, 19104-2688.
    ISBN 0-89871-172-X

  Parameters:

    Input, float T[LDT*N], the matrix of the system.  The zero
    elements of the matrix are not referenced, and the corresponding
    elements of the array can be used to store other information.

    Input, int LDT, the leading dimension of the array T.

    Input, int N, the order of the matrix.

    Input/output, float B[N].  On input, the right hand side.
    On output, the solution.

    Input, int JOB, specifies what kind of system is to be solved:
    00, solve T * X = B, T lower triangular,
    01, solve T * X = B, T upper triangular,
    10, solve T'* X = B, T lower triangular,
    11, solve T'* X = B, T upper triangular.

    Output, int STRSL, singularity indicator.
    0, the system is nonsingular.
    nonzero, the index of the first zero diagonal element of T.
*/
{
  int info;
  int j;
  int jj;
  int kase;
  float temp;
/*
  Check for zero diagonal elements.
*/
  for ( j = 1; j <= n; j++ )
  {
    if ( t[j-1+(j-1)*ldt] == 0.0 )
    {
      info = j;
      return info;
    }
  }

  info = 0;
/*
  Determine the task and go to it.
*/
  if ( ( job % 10 ) == 0 )
  {
    kase = 1;
  }
  else
  {
    kase = 2;
  }

  if ( ( job % 100 ) / 10 != 0 )
  {
    kase = kase + 2;
  }
/*
  Solve T * X = B for T lower triangular.
*/
  if ( kase == 1 )
  {
    b[0] = b[0] / t[0+0*ldt];
    for ( j = 2; j <= n; j++ )
    {
      temp = -b[j-2];
      saxpy ( n-j+1, temp, t+(j-1)+(j-2)*ldt, 1, b+j-1, 1 );
      b[j-1] = b[j-1] / t[j-1+(j-1)*ldt];
    }
  }
/*
  Solve T * X = B for T upper triangular.
*/
  else if ( kase == 2 )
  {
    b[n-1] = b[n-1] / t[n-1+(n-1)*ldt];
    for ( jj = 2; jj <= n; jj++ )
    {
      j = n - jj + 1;
      temp = -b[j];
      saxpy ( j, temp, t+0+j*ldt, 1, b, 1 );
      b[j-1] = b[j-1] / t[j-1+(j-1)*ldt];
    }
  }
/*
  Solve T' * X = B for T lower triangular.
*/
  else if ( kase == 3 )
  {
    b[n-1] = b[n-1] / t[n-1+(n-1)*ldt];
    for ( jj = 2; jj <= n; jj++ )
    {
      j = n - jj + 1;
      b[j-1] = b[j-1] - sdot ( jj-1, t+j+(j-1)*ldt, 1, b+j, 1 );
      b[j-1] = b[j-1] / t[j-1+(j-1)*ldt];
    }
  }
/*
  Solve T' * X = B for T upper triangular.
*/
  else if ( kase == 4 )
  {
    b[0] = b[0] / t[0+0*ldt];
    for ( j = 2; j <= n; j++ )
    {
      b[j-1] = b[j-1] - sdot ( j-1, t+0+(j-1)*ldt, 1, b, 1 );
      b[j-1] = b[j-1] / t[j-1+(j-1)*ldt];
    }
  }

  return info;
}
