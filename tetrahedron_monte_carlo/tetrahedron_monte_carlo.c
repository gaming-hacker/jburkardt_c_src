# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>

# include "tetrahedron_monte_carlo.h"

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

double r8mat_det_4d ( double a[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DET_4D computes the determinant of a 4 by 4 R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2010

  Author:

    John Burkardt

  Parameters:

    Input, double A[4*4], the matrix whose determinant is desired.

    Output, double R8MAT_DET_4D, the determinant of the matrix.
*/
{
  double det;

  det =
      a[0+0*4] * (
          a[1+1*4] * ( a[2+2*4] * a[3+3*4] - a[2+3*4] * a[3+2*4] )
        - a[1+2*4] * ( a[2+1*4] * a[3+3*4] - a[2+3*4] * a[3+1*4] )
        + a[1+3*4] * ( a[2+1*4] * a[3+2*4] - a[2+2*4] * a[3+1*4] ) )
    - a[0+1*4] * (
          a[1+0*4] * ( a[2+2*4] * a[3+3*4] - a[2+3*4] * a[3+2*4] )
        - a[1+2*4] * ( a[2+0*4] * a[3+3*4] - a[2+3*4] * a[3+0*4] )
        + a[1+3*4] * ( a[2+0*4] * a[3+2*4] - a[2+2*4] * a[3+0*4] ) )
    + a[0+2*4] * (
          a[1+0*4] * ( a[2+1*4] * a[3+3*4] - a[2+3*4] * a[3+1*4] )
        - a[1+1*4] * ( a[2+0*4] * a[3+3*4] - a[2+3*4] * a[3+0*4] )
        + a[1+3*4] * ( a[2+0*4] * a[3+1*4] - a[2+1*4] * a[3+0*4] ) )
    - a[0+3*4] * (
          a[1+0*4] * ( a[2+1*4] * a[3+2*4] - a[2+2*4] * a[3+1*4] )
        - a[1+1*4] * ( a[2+0*4] * a[3+2*4] - a[2+2*4] * a[3+0*4] )
        + a[1+2*4] * ( a[2+0*4] * a[3+1*4] - a[2+1*4] * a[3+0*4] ) );

  return det;
}
/******************************************************************************/

void r8mat_transpose_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_TRANSPOSE_PRINT prints an R8MAT, transposed.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
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
  r8mat_transpose_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_TRANSPOSE_PRINT_SOME prints some of an R8MAT, transposed.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
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

double r8vec_sum ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SUM returns the sum of an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A[N], the vector.

    Output, double R8VEC_SUM, the sum of the vector.
*/
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i];
  }

  return value;
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

double *reference_to_physical_tet4 ( double t[], int n, double ref[] )

/******************************************************************************/
/*
  Purpose:

    REFERENCE_TO_PHYSICAL_TET4 maps TET4 reference points to physical points.

  Discussion:

    Given the vertices of an order 4 physical tetrahedron and a point
    (R,S,T) in the reference tetrahedron, the routine computes the value
    of the corresponding image point (X,Y,Z) in physical space.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, double T[3*4], the coordinates of the vertices.
    The vertices are assumed to be the images of (1,0,0), (0,1,0),
    (0,0,1) and (0,0,0) respectively.

    Input, int N, the number of points to transform.

    Input, double REF[3*N], points in the reference element.

    Output, double REFERENCE_TO_PHYSICAL_TET4[3*N], corresponding points in the
    physical element.
*/
{
  int i;
  int j;
  double *phy;

  phy = ( double * ) malloc ( 3 * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      phy[i+j*3] =
          t[i+0*3] *         ref[0+j*3]
        + t[i+1*3] *                      ref[1+j*3]
        + t[i+2*3] *                                   ref[2+j*3]
        + t[i+3*3] * ( 1.0 - ref[0+j*3] - ref[1+j*3] - ref[2+j*3] );
    }
  }

  return phy;
}
/******************************************************************************/

double *tetrahedron_integrand_01 ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INTEGRAND_01 evaluates 1 integrand function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P[3*P_NUM], the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double FP[F_NUM*P_NUM], the integrand values.
*/
{
  double *fp;
  int j;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[0+j*f_num] = 1.0;
  }
  return fp;
}
/******************************************************************************/

double *tetrahedron_integrand_02 ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INTEGRAND_02 evaluates 3 integrand functions.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P[3*P_NUM], the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double FP[F_NUM*P_NUM], the integrand values.
*/
{
  double *fp;
  int j;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[0+j*f_num] = p[0+j*3];
    fp[1+j*f_num] = p[1+j*3];
    fp[2+j*f_num] = p[2+j*3];
  }

  return fp;
}
/******************************************************************************/

double *tetrahedron_integrand_03 ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INTEGRAND_03 evaluates 6 integrand functions.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P[3*P_NUM], the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double FP[F_NUM*P_NUM], the integrand values.
*/
{
  double *fp;
  int j;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[0+j*f_num] = p[0+j*3] * p[0+j*3];
    fp[1+j*f_num] = p[0+j*3] * p[1+j*3];
    fp[2+j*f_num] = p[0+j*3] * p[2+j*3];
    fp[3+j*f_num] = p[1+j*3] * p[1+j*3];
    fp[4+j*f_num] = p[1+j*3] * p[2+j*3];
    fp[5+j*f_num] = p[2+j*3] * p[2+j*3];
  }

  return fp;
}
/******************************************************************************/

double *tetrahedron_integrand_04 ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INTEGRAND_04 evaluates 10 integrand functions.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P[3*P_NUM], the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double FP[F_NUM*P_NUM], the integrand values.
*/
{
  double *fp;
  int j;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[0+j*f_num] = p[0+j*3] * p[0+j*3] * p[0+j*3];
    fp[1+j*f_num] = p[0+j*3] * p[0+j*3] * p[1+j*3];
    fp[2+j*f_num] = p[0+j*3] * p[0+j*3] * p[2+j*3];
    fp[3+j*f_num] = p[0+j*3] * p[1+j*3] * p[1+j*3];
    fp[4+j*f_num] = p[0+j*3] * p[1+j*3] * p[2+j*3];
    fp[5+j*f_num] = p[0+j*3] * p[2+j*3] * p[2+j*3];
    fp[6+j*f_num] = p[1+j*3] * p[1+j*3] * p[1+j*3];
    fp[7+j*f_num] = p[1+j*3] * p[1+j*3] * p[2+j*3];
    fp[8+j*f_num] = p[1+j*3] * p[2+j*3] * p[2+j*3];
    fp[9+j*f_num] = p[2+j*3] * p[2+j*3] * p[2+j*3];
  }

  return fp;
}
/******************************************************************************/

double *tetrahedron_integrand_05 ( int p_num, double p[], int f_num )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_INTEGRAND_05 evaluates 15 integrand functions.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input, double P[3*P_NUM], the evaluation points.

    Input, int F_NUM, the number of integrands.

    Output, double FP[F_NUM*P_NUM], the integrand values.
*/
{
  double *fp;
  int j;

  fp = ( double * ) malloc ( f_num * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    fp[ 0+j*f_num] = p[0+j*3] * p[0+j*3] * p[0+j*3] * p[0+j*3];
    fp[ 1+j*f_num] = p[0+j*3] * p[0+j*3] * p[0+j*3] * p[1+j*3];
    fp[ 2+j*f_num] = p[0+j*3] * p[0+j*3] * p[0+j*3] * p[2+j*3];
    fp[ 3+j*f_num] = p[0+j*3] * p[0+j*3] * p[1+j*3] * p[1+j*3];
    fp[ 4+j*f_num] = p[0+j*3] * p[0+j*3] * p[1+j*3] * p[2+j*3];
    fp[ 5+j*f_num] = p[0+j*3] * p[0+j*3] * p[2+j*3] * p[2+j*3];
    fp[ 6+j*f_num] = p[0+j*3] * p[1+j*3] * p[1+j*3] * p[1+j*3];
    fp[ 7+j*f_num] = p[0+j*3] * p[1+j*3] * p[1+j*3] * p[2+j*3];
    fp[ 8+j*f_num] = p[0+j*3] * p[1+j*3] * p[2+j*3] * p[2+j*3];
    fp[ 9+j*f_num] = p[0+j*3] * p[2+j*3] * p[2+j*3] * p[2+j*3];
    fp[10+j*f_num] = p[1+j*3] * p[1+j*3] * p[1+j*3] * p[1+j*3];
    fp[11+j*f_num] = p[1+j*3] * p[1+j*3] * p[1+j*3] * p[2+j*3];
    fp[12+j*f_num] = p[1+j*3] * p[1+j*3] * p[2+j*3] * p[2+j*3];
    fp[13+j*f_num] = p[1+j*3] * p[2+j*3] * p[2+j*3] * p[2+j*3];
    fp[14+j*f_num] = p[2+j*3] * p[2+j*3] * p[2+j*3] * p[2+j*3];
  }
  return fp;
}
/******************************************************************************/

double *tetrahedron_monte_carlo ( double t[], int p_num, int f_num,
  double *tetrahedron_unit_sample ( int p_num, int *seed ),
  double *tetrahedron_integrand ( int p_num, double p[], int f_num ), int *seed )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_MONTE_CARLO applies the Monte Carlo rule to integrate a function.

  Discussion:

    The function f(x,y,z) is to be integrated over a tetrahedron T.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, double T[3*4], the tetrahedron vertices.

    Input, int P_NUM, the number of sample points.

    Input, int F_NUM, the number of functions to integrate.

    Input, external TETRAHEDRON_UNIT_SAMPLE, the sampling routine.

    Input, external TETRAHEDRON_INTEGRAND, the integrand routine.

    Input/output, int *SEED, a seed for the random
    number generator.

    Output, dobule TETRAHEDRON_MONTE_CARLO[F_NUM], the approximate integrals.
*/
{
  double *fp;
  double fp_sum;
  int i;
  int j;
  double *p;
  double *p2;
  double *result;
  double volume;

  volume = tetrahedron_volume ( t );

  p = tetrahedron_unit_sample ( p_num, seed );

  p2 = reference_to_physical_tet4 ( t, p_num, p );

  fp = tetrahedron_integrand ( p_num, p2, f_num );

  result = ( double * ) malloc ( f_num * sizeof ( double ) );

  for ( i = 0; i < f_num; i++ )
  {
    fp_sum = 0.0;
    for ( j = 0; j < p_num; j++ )
    {
      fp_sum = fp_sum + fp[i+j*f_num];
    }
    result[i] = volume * fp_sum / ( double ) ( p_num );
  }

  free ( fp );
  free ( p );
  free ( p2 );

  return result;
}
/******************************************************************************/

double *tetrahedron_unit_sample_01 ( int p_num, int *seed )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_UNIT_SAMPLE_01 selects points from the unit tetrahedron.

  Discussion:

    The unit tetrahedron has vertices (1,0,0), (0,1,0), (0,0,1), (0,0,0).

    Any point in the unit tetrahedron CAN be chosen by this algorithm.

    However, the points that are chosen tend to be clustered near
    the centroid.

    This routine is supplied as an example of "bad" sampling.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Parameters:

    Input, int P_NUM, the number of points.

    Input/output, int *SEED, a seed for the random
    number generator.

    Output, double TETRAHEDRON_UNIT_SAMPLE_01[3*P_NUM], the points.
*/
{
  double *e;
  double e_sum;
  int i;
  int j;
  double *p;

  p = ( double * ) malloc ( 3 * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    e = r8vec_uniform_01_new ( 4, seed );

    e_sum = r8vec_sum ( 4, e );

    for ( i = 0; i < 3; i++ )
    {
      p[i+j*3] = e[i] / e_sum;
    }
    free ( e );
  }

  return p;
}
/******************************************************************************/

double *tetrahedron_unit_sample_02 ( int p_num, int *seed )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_UNIT_SAMPLE_02 selects points from the unit tetrahedron.

  Discussion:

    The unit tetrahedron has vertices (1,0,0), (0,1,0), (0,0,1), (0,0,0).

    The sampling is uniform.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Reference:

    Claudio Rocchini, Paolo Cignoni,
    Generating Random Points in a Tetrahedron,
    Journal of Graphics Tools,
    Volume 5, Number 5, 2000, pages 9-12.

  Parameters:

    Input, int P_NUM, the number of points.

    Input/output, int *SEED, a seed for the random
    number generator.

    Output, double TETRAHEDRON_UNIT_SAMPLE_02[3*P_NUM], the points.
*/
{
  double *c;
  int j;
  double *p;
  double t;

  p = ( double * ) malloc ( 3 * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    c = r8vec_uniform_01_new ( 3, seed );

    if ( 1.0 < c[0] + c[1] )
    {
      c[0] = 1.0 - c[0];
      c[1] = 1.0 - c[1];
    }

    if ( 1.0 < c[1] + c[2] )
    {
      t = c[2];
      c[2] = 1.0 - c[0] - c[1];
      c[1] = 1.0 - t;
    }
    else if ( 1.0 < c[0] + c[1] + c[2] )
    {
       t = c[2];
       c[2] = c[0] + c[1] + c[2] - 1.0;
       c[0] = 1.0 - c[1] - t;
    }
    p[0+j*3] = c[0];
    p[1+j*3] = c[1];
    p[2+j*3] = c[2];

    free ( c );
  }

  return p;
}
/******************************************************************************/

double *tetrahedron_unit_sample_03 ( int p_num, int *seed )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_UNIT_SAMPLE_03 selects points from the unit tetrahedron.

  Discussion:

    The unit tetrahedron has vertices (1,0,0), (0,1,0), (0,0,1), (0,0,0).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Reference:

    Greg Turk,
    Generating Random Points in a Triangle,
    in Graphics Gems,
    edited by Andrew Glassner,
    AP Professional, 1990, pages 24-28.

  Parameters:

    Input, int P_NUM, the number of points.

    Input/output, int *SEED, a seed for the random
    number generator.

    Output, double TETRAHEDRON_UNIT_SAMPLE_03[3*P_NUM], the points.
*/
{
  double a;
  double b;
  double c;
  double e;
  double f;
  double g;
  int j;
  double *p;
  double *r;

  p = ( double * ) malloc ( 3 * p_num * sizeof ( double ) );

  for ( j = 0; j < p_num; j++ )
  {
    r = r8vec_uniform_01_new ( 3, seed );

    e = pow ( r[0], 1.0 / 3.0 );
    f = sqrt ( r[1] );
    g = r[2];

    a =   1.0 - e;
    b = ( 1.0 - f )       * e;
    c = ( 1.0 - g ) * f   * e;

    p[0+j*3] = a;
    p[1+j*3] = b;
    p[2+j*3] = c;

    free ( r );
  }

  return p;
}
/******************************************************************************/

double *tetrahedron_unit_sample_04 ( int p_num, int *seed )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_UNIT_SAMPLE_04 selects points from the unit tetrahedron.

  Discussion:

    The unit tetrahedron has vertices (1,0,0), (0,1,0), (0,0,1), (0,0,0).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 August 2009

  Author:

    John Burkardt

  Reference:

    Reuven Rubinstein,
    Monte Carlo Optimization, Simulation, and Sensitivity
    of Queueing Networks,
    Krieger, 1992,
    ISBN: 0894647644,
    LC: QA298.R79.

  Parameters:

    Input, int P_NUM, the number of points.

    Input/output, int *SEED, a seed for the random
    number generator.

    Output, double TETRAHEDRON_UNIT_SAMPLE_04[3*P_NUM], the points.
*/
{
  double *e;
  double e_sum;
  int i;
  int j;
  double *p;

  p = ( double * ) malloc ( 3 * p_num * sizeof ( double ) );
/*
  The construction begins by sampling DIM_NUM+1 points from the
  exponential distribution with parameter 1.
*/
  for ( j = 0; j < p_num; j++ )
  {
    e = r8vec_uniform_01_new ( 4, seed );

    for ( i = 0; i < 4; i++ )
    {
      e[i] = - log ( e[i] );
    }
    e_sum = r8vec_sum ( 4, e );

    for ( i = 0; i < 3; i++ )
    {
      p[i+j*3] = e[i] / e_sum;
    }
    free ( e );
  }

  return p;
}
/******************************************************************************/

double tetrahedron_volume ( double tetra[3*4] )

/******************************************************************************/
/*
  Purpose:

    TETRAHEDRON_VOLUME computes the volume of a tetrahedron.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2005

  Author:

    John Burkardt

  Parameters:

    Input, double TETRA[3*4], the coordinates of the vertices.

    Output, double TETRAHEDRON_VOLUME, the volume of the tetrahedron.
*/
{
  double a[4*4];
  int i;
  int j;
  double volume;

  for ( i = 0; i < 3; i++ )
  {
    for ( j = 0; j < 4; j++ )
    {
      a[i+j*4] = tetra[i+j*3];
    }
  }

  i = 3;
  for ( j = 0; j < 4; j++ )
  {
    a[i+j*4] = 1.0;
  }

  volume = fabs ( r8mat_det_4d ( a ) ) / 6.0;

  return volume;
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

