# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "square_minimal_rule.h"

/******************************************************************************/

double *r8mat_copy_new ( int m, int n, double a1[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_COPY_NEW copies one R8MAT to a "new" R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input, double A1[M*N], the matrix to be copied.

    Output, double R8MAT_COPY_NEW[M*N], the copy of A1.
*/
{
  double *a2;
  int i;
  int j;

  a2 = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }

  return a2;
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

double *smr00 ( )

/******************************************************************************/
/*
  Purpose:

    SMR00 returns the SMR rule of degree 0.

  Discussion:

    DEGREE: 0
    SYMM.: (X,Y), (-X,-Y)
    POINTS CARDINALITY: 1
    NORM INF MOMS. RESIDUAL: 0.00000e+00,
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR00[3*1], the requested rule.
*/
{
  const int degree = 0;
  int order;
  double xw[3*1] = {
     0.000000000000000e+00, 0.000000000000000e+00, 4.000000000000000e+00 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr01 ( )

/******************************************************************************/
/*
  Purpose:

    SMR01 returns the SMR rule of degree 1.

  Discussion:

    DEGREE: 1
    SYMM.: (X,Y), (-X,-Y)
    POINTS CARDINALITY: 1
    NORM INF MOMS. RESIDUAL: 0.00000e+00,
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR01[3*1], the requested rule.
*/
{
  const int degree = 1;
  int order;
  double xw[3*1] = {
     0.000000000000000e+00, 0.000000000000000e+00, 4.000000000000000e+00 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr02 ( )

/******************************************************************************/
/*
  Purpose:

    SMR02 returns the SMR rule of degree 2.

  Discussion:

    DEGREE: 2
    POINTS CARDINALITY: 3
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR02[3*3], the requested rule.
*/
{
  const int degree = 2;
  int order;
  double xw[3*3] = {
     6.519542382482019e-01,  3.623444315022428e-01, 1.498681096511322e+00,
    -8.070876861583226e-01,  5.322309038833022e-01, 1.051530016968792e+00,
    -8.856086946552445e-02, -7.605904084126465e-01, 1.449788886519887e+00 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr03 ( )

/******************************************************************************/
/*
  Purpose:

    SMR03 returns the SMR rule of degree 3.

  Discussion:

    DEGREE: 3
    SYMMETRY: (X,Y), (-Y,X), (-X,-Y), (Y,-X)
    POINTS CARDINALITY: 4
    NORM INF MOMS. RESIDUAL: 2.22045e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR03[3*4], the requested rule.
*/
{
  const int degree = 3;
  int order;
  double xw[3*4] = {
    -5.773502691896257e-01, -5.773502691896257e-01, 1.000000000000000e+00,
    -5.773502691896257e-01,  5.773502691896257e-01, 1.000000000000000e+00,
     5.773502691896257e-01,  5.773502691896257e-01, 1.000000000000000e+00,
     5.773502691896257e-01, -5.773502691896257e-01, 1.000000000000000e+00 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr04 ( )

/******************************************************************************/
/*
  Purpose:

    SMR04 returns the SMR rule of degree 4.

  Discussion:

    DEGREE: 4
    POINTS CARDINALITY: 6
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR04[3*6], the requested rule.
*/
{
  const int degree = 4;
  int order;
  double xw[3*6] = {
     9.298664473826397e-01,  6.361197473108544e-02,  4.979283660841867e-01,
    -7.329012618874027e-01,  5.903145258425608e-01,  6.883081069413867e-01,
     3.895446419719248e-01,  8.325323327063485e-01,  6.340849824642651e-01,
     5.169294362169509e-01, -8.804002381721473e-01,  4.856847322376568e-01,
    -5.223159975544114e-02, -1.540167862605936e-01,  1.180646405191258e+00,
    -7.693563599017555e-01, -6.943687766134327e-01,  5.133474070812475e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr05 ( )

/******************************************************************************/
/*
  Purpose:

    SMR05 returns the SMR rule of degree 5.

  Discussion:

    DEGREE: 5
    SYMMETRY: (X,Y), (-X,-Y)
    POINTS CARDINALITY: 7
    NORM INF MOMS. RESIDUAL: 1.66533e-16
    SUM NEGATIVE WEIGHTS: 0
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR05[3*7], the requested rule.
*/
{
  const int degree = 5;
  int order;
  double xw[3*7] = {
   -9.660917830792960e-01,  0.000000000000000e+00, 3.174603174603175e-01,
   -5.773502691896258e-01, -7.745966692414834e-01, 5.555555555555556e-01,
   -5.773502691896258e-01,  7.745966692414834e-01, 5.555555555555556e-01,
    0.000000000000000e+00,  0.000000000000000e+00, 1.142857142857143e+00,
    5.773502691896258e-01,  7.745966692414834e-01, 5.555555555555556e-01,
    5.773502691896258e-01, -7.745966692414834e-01, 5.555555555555556e-01,
    9.660917830792960e-01,  0.000000000000000e+00, 3.174603174603175e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr06 ( )

/******************************************************************************/
/*
  Purpose:

    SMR06 returns the SMR rule of degree 6.

  Discussion:

    DEGREE: 6
    POINTS CARDINALITY: 10
    NORM INF MOMS. RESIDUAL: 9.02056e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR06[3*10], the requested rule.
*/
{
  const int degree = 6;
  int order;
  double xw[3*10] = {
    9.785155476851563e-01,  2.032663758845348e-01, 2.115144101443901e-01,
    8.002071174796732e-01, -8.068212789789568e-01, 2.633128596562718e-01,
    6.478447271179293e-01,  8.174437151345265e-01, 3.765392584231271e-01,
    4.527740405918522e-01, -2.317108088207500e-01, 7.128261121734308e-01,
   -4.775668731692919e-01,  9.766597077168154e-01, 1.915080888326935e-01,
   -7.569420164799104e-02,  4.409055401533251e-01, 7.647398979197457e-01,
   -1.241563248035317e-01, -8.409222499092199e-01, 4.422079284502612e-01,
   -9.014158913156406e-01,  5.483121720080090e-01, 2.801510395399764e-01,
   -6.560277628978444e-01, -2.866497529648795e-01, 6.536308666716537e-01,
   -9.537871517453275e-01, -8.861523430050633e-01, 1.035695381884487e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr07 ( )

/******************************************************************************/
/*
  Purpose:

    SMR07 returns the SMR rule of degree 7.

  Discussion:

    DEGREE: 7
    ROTATIONALLY INVARIANT: (X,Y),(-Y,X),(-X,-Y),(Y,-X).
    POINTS CARDINALITY: 12
    NORM INF MOMS. RESIDUAL: 2.77556e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR07[3*12], the requested rule.
*/
{
  const int degree = 7;
  int order;
  double xw[3*12] = {
    3.938313610187890e-01, -3.669979343404274e-01, 5.209286223023044e-01,
    8.019684762065925e-01,  8.099259297580919e-01, 2.374024056137991e-01,
   -1.832732766424723e-02,  9.259609259310837e-01, 2.416689720838965e-01,
    3.669979343404274e-01,  3.938313610187890e-01, 5.209286223023044e-01,
   -8.099259297580919e-01,  8.019684762065925e-01, 2.374024056137991e-01,
   -9.259609259310837e-01, -1.832732766424723e-02, 2.416689720838965e-01,
   -3.938313610187890e-01,  3.669979343404274e-01, 5.209286223023044e-01,
   -8.019684762065925e-01, -8.099259297580919e-01, 2.374024056137991e-01,
    1.832732766424723e-02, -9.259609259310837e-01, 2.416689720838965e-01,
   -3.669979343404274e-01, -3.938313610187890e-01, 5.209286223023044e-01,
    8.099259297580919e-01, -8.019684762065925e-01, 2.374024056137991e-01,
    9.259609259310837e-01,  1.832732766424723e-02, 2.416689720838965e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr08 ( )

/******************************************************************************/
/*
  Purpose:

    SMR08 returns the SMR rule of degree 8.

  Discussion:

    R.COOLS SAYS THERE IS A RULE WITH 15 PTS.

    DEGREE: 8
    POINTS CARDINALITY: 16
    NORM INF MOMS. RESIDUAL: 5.27356e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR08[3*16], the requested rule.
*/
{
  const int degree = 8;
  int order;
  double xw[3*16] = {
    9.200233979246099e-01, -1.061811254185043e-01, 2.066851970823297e-01,
    8.930854460206108e-01,  7.538456868810103e-01, 1.637084884729354e-01,
    6.675369061590991e-01, -6.602769863240182e-01, 3.448725288612837e-01,
    9.736841855611369e-01, -9.418906397956112e-01, 4.154990098574050e-02,
    4.634059670545806e-01,  9.713146222867728e-01, 1.207701070516287e-01,
    5.257251055722159e-01,  3.284384783969826e-01, 4.761612149298055e-01,
   -3.171906088585705e-01,  8.431651719683217e-01, 8.714564872094989e-02,
   -6.189113622341841e-02,  6.853227004655966e-01, 3.755078795520529e-01,
    6.720825424065331e-02, -2.654137657769545e-01, 5.939493422195995e-01,
    1.957478656950412e-01, -9.531380985058940e-01, 1.576823081145121e-01,
   -7.280591295595631e-01,  9.245623167165428e-01, 1.261748042046440e-01,
   -5.538775451118830e-01,  1.849451143123379e-01, 4.968422862065046e-01,
   -4.448446986979669e-01, -7.417922043114903e-01, 3.611024723493892e-01,
   -9.421081322947572e-01,  5.652760298758271e-01, 1.413572491732567e-01,
   -8.900106969566213e-01, -3.626326971963237e-01, 2.363188753269229e-01,
   -8.841558907294489e-01, -9.418511077281306e-01, 7.017169674844463e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr09 ( )

/******************************************************************************/
/*
  Purpose:

    SMR09 returns the SMR rule of degree 9.

  Discussion:

    DEGREE: 9
    ROTATIONALLY INVARIANT: (X,Y),(-Y,X),(-X,-Y),(Y,-X).-
    POINTS CARDINALITY: 17
    NORM INF MOMS. RESIDUAL: 2.77556e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR09[3*17], the requested rule.
*/
{
  const int degree = 9;
  int order;
  double xw[3*17] = {
    -6.306801197316687e-01,  9.688499663619777e-01,  8.887937817019871e-02,
     4.533398211356471e-01, -5.237358202144294e-01,  3.982824392620701e-01,
     8.526157293336624e-01, -7.620832819261733e-02,  2.690513376397807e-01,
    -7.502770999789007e-01, -9.279616459595696e-01,  1.120996021295965e-01,
    -9.688499663619777e-01, -6.306801197316687e-01,  8.887937817019871e-02,
     5.237358202144294e-01,  4.533398211356471e-01,  3.982824392620701e-01,
     7.620832819261733e-02,  8.526157293336624e-01,  2.690513376397807e-01,
     9.279616459595696e-01, -7.502770999789007e-01,  1.120996021295965e-01,
     6.306801197316687e-01, -9.688499663619777e-01,  8.887937817019871e-02,
    -4.533398211356471e-01,  5.237358202144294e-01,  3.982824392620701e-01,
    -8.526157293336624e-01,  7.620832819261733e-02,  2.690513376397807e-01,
     7.502770999789007e-01,  9.279616459595696e-01,  1.120996021295965e-01,
     9.688499663619777e-01,  6.306801197316687e-01,  8.887937817019871e-02,
    -5.237358202144294e-01, -4.533398211356471e-01,  3.982824392620701e-01,
    -7.620832819261733e-02, -8.526157293336624e-01,  2.690513376397807e-01,
    -9.279616459595696e-01,  7.502770999789007e-01,  1.120996021295965e-01,
     0.000000000000000e+00,  0.000000000000000e+00,  5.267489711934157e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr10 ( )

/******************************************************************************/
/*
  Purpose:

    SMR10 returns the SMR rule of degree 10.

  Discussion:

    DEGREE: 10
    POINTS CARDINALITY: 22
    NORM INF MOMS. RESIDUAL: 3.88578e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR10[3*22], the requested rule.
*/
{
  const int degree = 10;
  int order;
  double xw[3*22] = {
    9.406185571992117e-01, -3.188453596839293e-01,  1.198415853239125e-01,
    9.817119264047970e-01,  6.258661935323968e-01,  6.326927276111106e-02,
    8.117151060164873e-01,  9.246684242905354e-01,  8.868620221697536e-02,
    7.788254159831852e-01,  2.105273891482154e-01,  2.658711347712608e-01,
    6.476354842626755e-01, -6.474946981752544e-01,  2.305700455337005e-01,
    9.225481682574119e-01, -8.792348043990323e-01,  6.253794118755233e-02,
    1.142951736422380e-01,  9.492191314088700e-01,  1.186176720746597e-01,
    4.711392149070169e-01,  6.666473305982111e-01,  2.839584221827897e-01,
    3.507267260891899e-01, -1.844717206212197e-01,  3.881144740244089e-01,
    6.240243795898468e-01, -9.853833119314599e-01,  3.338712924707296e-02,
   -3.924748753960961e-01,  7.631114939243835e-01,  2.582793941034283e-01,
   -3.211002312038658e-02,  3.187935759364070e-01,  4.082419772615457e-01,
   -1.073322786510871e-01, -6.188661913929927e-01,  3.149887822123112e-01,
    2.065013461988724e-01, -9.119588710357345e-01,  1.346097738619806e-01,
   -7.529656324799602e-01,  9.707183739677747e-01,  5.911019515035110e-02,
   -7.605065507139738e-01,  3.663139167806791e-01,  2.604239768191683e-01,
   -4.732489884927658e-01, -1.655785251003833e-01,  3.717176493089616e-01,
   -5.089131904296067e-01, -9.215290755789827e-01,  1.333773119224012e-01,
   -9.538019223425510e-01,  7.551269206143554e-01,  7.180589876051692e-02,
   -9.663420836873585e-01, -1.043123255663638e-01,  9.794042948413186e-02,
   -8.103749226019182e-01, -6.115967830349249e-01,  2.001832062027751e-01,
   -9.577495916000752e-01, -9.262105001258389e-01,  3.446752558898364e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr11 ( )

/******************************************************************************/
/*
  Purpose:

    SMR11 returns the SMR rule of degree 11.

  Discussion:

    DEGREE: 11
    ROTATIONALLY INVARIANT: (X,Y),(-Y,X),(-X,-Y),(Y,-X).
    POINTS CARDINALITY: 24
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR11[3*24], the requested rule.
*/
{
  const int degree = 11;
  int order;
  double xw[3*24] = {
   -4.165807191202228e-02,  4.248472488486693e-01,  3.511587183982455e-01,
    3.156234329152542e-01,  8.125205483048132e-01,  2.117363499989486e-01,
    7.120019130753363e-01,  5.253202503645478e-01,  2.256260617288634e-01,
    6.980761045495677e-01,  9.826392235408555e-01,  4.802076335072379e-02,
    9.535395282015321e-01,  1.885861387186419e-01,  9.738677735866817e-02,
    9.394863828167369e-01,  8.257758359029640e-01,  6.607132916455061e-02,
   -4.248472488486693e-01, -4.165807191202228e-02,  3.511587183982455e-01,
   -8.125205483048132e-01,  3.156234329152542e-01,  2.117363499989486e-01,
   -5.253202503645478e-01,  7.120019130753363e-01,  2.256260617288634e-01,
   -9.826392235408555e-01,  6.980761045495677e-01,  4.802076335072379e-02,
   -1.885861387186419e-01,  9.535395282015321e-01,  9.738677735866817e-02,
   -8.257758359029640e-01,  9.394863828167369e-01,  6.607132916455061e-02,
    4.165807191202228e-02, -4.248472488486693e-01,  3.511587183982455e-01,
   -3.156234329152542e-01, -8.125205483048132e-01,  2.117363499989486e-01,
   -7.120019130753363e-01, -5.253202503645478e-01,  2.256260617288634e-01,
   -6.980761045495677e-01, -9.826392235408555e-01,  4.802076335072379e-02,
   -9.535395282015321e-01, -1.885861387186419e-01,  9.738677735866817e-02,
   -9.394863828167369e-01, -8.257758359029640e-01,  6.607132916455061e-02,
    4.248472488486693e-01,  4.165807191202228e-02,  3.511587183982455e-01,
    8.125205483048132e-01, -3.156234329152542e-01,  2.117363499989486e-01,
    5.253202503645478e-01, -7.120019130753363e-01,  2.256260617288634e-01,
    9.826392235408555e-01, -6.980761045495677e-01,  4.802076335072379e-02,
    1.885861387186419e-01, -9.535395282015321e-01,  9.738677735866817e-02,
    8.257758359029640e-01, -9.394863828167369e-01,  6.607132916455061e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr12 ( )

/******************************************************************************/
/*
  Purpose:

    SMR12 returns the SMR rule of degree 12.

  Discussion:

    DEGREE: 12
    POINTS CARDINALITY: 31
    NORM INF MOMS. RESIDUAL: 5.55112e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR12[3*31], the requested rule.
*/
{
  const int degree = 12;
  int order;
  double xw[3*31] = {
    7.887961133518859e-01,  9.788423074444343e-01,  3.643740653079505e-02,
    9.636803326457559e-01, -8.325162377112404e-01,  4.156946367307449e-02,
    5.727054392308150e-01,  7.717261293782711e-01,  1.680361793533787e-01,
    9.634302613611325e-01,  8.254780463742046e-01,  4.273104217362153e-02,
    9.850208941660858e-01,  2.929038490713011e-03,  5.527116827932585e-02,
    8.590486289231106e-01, -4.568247023502062e-01,  1.528634492877730e-01,
    7.730732984501992e-01, -9.683129045193353e-01,  4.413124147353821e-02,
   -1.779670698164110e-01,  7.009187390097460e-01,  2.328494912954924e-01,
    8.543638116305748e-01,  4.518538584893645e-01,  1.556045127005831e-01,
    6.291273683568680e-01, -7.545283511153206e-03,  2.625512570459704e-01,
    5.528579662023739e-01, -7.445078276040368e-01,  1.822720395257231e-01,
    2.838402579450193e-01,  4.114855681818982e-01,  2.766169541326807e-01,
   -8.461631704059508e-02,  8.864609533086124e-02,  2.383849367209651e-01,
    2.425324152553718e-01, -3.742080386362673e-01,  2.920973373876344e-01,
    1.732349372327210e-01, -9.397208645575091e-01,  1.020918275656317e-01,
    1.711409536609614e-01,  9.405188030525048e-01,  1.014134103497821e-01,
   -4.125379277895744e-01,  5.932317296236497e-02,  1.455335918991387e-01,
   -2.114002132094871e-01, -2.840983635497378e-01,  7.946218537051837e-02,
   -4.914206209696642e-01,  9.453457692968009e-01,  8.467100517264473e-02,
   -6.078146688229159e-01,  4.486792064962008e-01,  2.211679207393056e-01,
   -5.774993705610445e-01, -3.758525621312278e-01,  2.131288659567110e-01,
   -4.943548938878011e-01, -9.487282033931176e-01,  8.106167025374129e-02,
   -8.307832892042354e-01,  8.056995002918920e-01,  1.095231158786915e-01,
   -8.780106307148161e-01,  1.661245295800410e-01,  9.555205419558256e-02,
   -9.855207994154948e-01, -5.172324935881427e-01,  4.485874655537044e-02,
   -1.843157675090382e-01, -7.106474367504330e-01,  2.242636308727417e-01,
   -9.639808262111604e-01,  9.935149440412500e-01,  1.153343223604792e-02,
   -9.905890478558095e-01,  5.280652625496880e-01,  4.024626264818196e-02,
   -8.720537162767097e-01, -1.329065631973914e-01,  1.058449657495581e-01,
   -9.263657835203469e-01, -9.372594643356640e-01,  3.401287490362680e-02,
   -7.769128911427001e-01, -7.339368334159078e-01,  1.242179600721695e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr13 ( )

/******************************************************************************/
/*
  Purpose:

    SMR13 returns the SMR rule of degree 13.

  Discussion:

    DEGREE: 13
    ROTATIONALLY INVARIANT: (X,Y),(-Y,X),(-X,-Y),(Y,-X).
    POINTS CARDINALITY: 33
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR13[3*33], the requested rule.
*/
{
  const int degree = 13;
  int order;
  double xw[3*33] = {
    4.758086252182755e-01,  8.500766736997488e-01,  1.188446673005955e-01,
    3.427165560404069e-01,  4.093045616940387e-01,  2.568707494819678e-01,
    7.558053565720811e-01,  6.478216371870110e-01,  1.297635503700028e-01,
    9.413272258729251e-01,  3.907362161294611e-01,  7.749273853310545e-02,
    9.572976997863074e-01,  8.595560056416388e-01,  3.817442131708364e-02,
    7.788097115544195e-01,  9.834866824398723e-01,  2.999183886449914e-02,
   -7.074150899644469e-02,  6.962500784917494e-01,  2.133415814571894e-01,
    1.381834598624650e-01,  9.589251702875350e-01,  6.042492381774981e-02,
   -8.500766736997488e-01,  4.758086252182755e-01,  1.188446673005955e-01,
   -4.093045616940387e-01,  3.427165560404069e-01,  2.568707494819678e-01,
   -6.478216371870110e-01,  7.558053565720811e-01,  1.297635503700028e-01,
   -3.907362161294611e-01,  9.413272258729251e-01,  7.749273853310545e-02,
   -8.595560056416388e-01,  9.572976997863074e-01,  3.817442131708364e-02,
   -9.834866824398723e-01,  7.788097115544195e-01,  2.999183886449914e-02,
   -6.962500784917494e-01, -7.074150899644469e-02,  2.133415814571894e-01,
   -9.589251702875350e-01,  1.381834598624650e-01,  6.042492381774981e-02,
   -4.758086252182755e-01, -8.500766736997488e-01,  1.188446673005955e-01,
   -3.427165560404069e-01, -4.093045616940387e-01,  2.568707494819678e-01,
   -7.558053565720811e-01, -6.478216371870110e-01,  1.297635503700028e-01,
   -9.413272258729251e-01, -3.907362161294611e-01,  7.749273853310545e-02,
   -9.572976997863074e-01, -8.595560056416388e-01,  3.817442131708364e-02,
   -7.788097115544195e-01, -9.834866824398723e-01,  2.999183886449914e-02,
    7.074150899644469e-02, -6.962500784917494e-01,  2.133415814571894e-01,
   -1.381834598624650e-01, -9.589251702875350e-01,  6.042492381774981e-02,
    8.500766736997488e-01, -4.758086252182755e-01,  1.188446673005955e-01,
    4.093045616940387e-01, -3.427165560404069e-01,  2.568707494819678e-01,
    6.478216371870110e-01, -7.558053565720811e-01,  1.297635503700028e-01,
    3.907362161294611e-01, -9.413272258729251e-01,  7.749273853310545e-02,
    8.595560056416388e-01, -9.572976997863074e-01,  3.817442131708364e-02,
    9.834866824398723e-01, -7.788097115544195e-01,  2.999183886449914e-02,
    6.962500784917494e-01,  7.074150899644469e-02,  2.133415814571894e-01,
    9.589251702875350e-01, -1.381834598624650e-01,  6.042492381774981e-02,
    0.000000000000000e+00,  0.000000000000000e+00,  3.003821154312253e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}

/******************************************************************************/

double *smr14 ( )

/******************************************************************************/
/*
  Purpose:

    SMR14 returns the SMR rule of degree 14.

  Discussion:
 
    DEGREE: 14
    POINTS CARDINALITY: 40
    NORM INF MOMS. RESIDUAL: 9.57567e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR14[3*40], the requested rule.
*/
{
  const int degree = 14;
  int order;
  double xw[3*40] = {
    9.784247248091626e-01,  9.849379037345679e-01,  7.042609290974809e-03,
    9.696033367128390e-01, -3.331633352358324e-01,  5.127000401619231e-02,
    9.635907900433699e-01, -8.235135827696192e-01,  2.835904116834926e-02,
    9.609680853689336e-01, -9.665848054209388e-01,  5.802552341290735e-03,
    8.759175244824323e-01,  8.440519016975554e-01,  6.406839799781101e-02,
    9.850622977861553e-01,  5.927006882272775e-01,  3.059827453183588e-02,
    9.132378164262995e-01,  1.686644107446046e-01,  1.015293304177829e-01,
    8.210255575251280e-01, -6.312138484114799e-01,  1.070566792196576e-01,
    7.253802697646771e-01,  5.271299424251080e-01,  1.491850201682654e-01,
    7.129972234617307e-01, -1.746725364206650e-01,  1.672674729613243e-01,
    5.551781984544302e-01, -8.617677569495097e-01,  1.035166248728787e-01,
    8.047627946516351e-01, -9.674432786379303e-01,  2.787008138269169e-02,
    6.424373183439024e-01,  9.660008737161317e-01,  4.265704272492368e-02,
    4.202620588036903e-01,  7.809596116887254e-01,  1.425075466703280e-01,
    4.547166615470812e-01,  1.927401717576898e-01,  2.105516162791665e-01,
    4.259990143599163e-01, -4.962208715768625e-01,  1.867185172918136e-01,
    9.710021027954509e-02,  9.536977082453567e-01,  6.972182442589203e-02,
    1.114008919498024e-01,  4.923616289896904e-01,  2.043948618313033e-01,
    1.209667130758268e-01, -1.503469100876254e-01,  2.335930539280487e-01,
    7.524097400070873e-02, -7.452253206810735e-01,  1.601269026668343e-01,
   -4.518656196438389e-01,  9.427795716582286e-01,  6.465270834286081e-02,
   -2.040271575380492e-01,  7.591224031418166e-01,  1.466929221365241e-01,
   -2.427862218874625e-01,  1.736708825032474e-01,  2.280281871073875e-01,
   -2.459782585741061e-01, -4.449955936922590e-01,  2.055272577034085e-01,
    2.124852450722984e-01, -9.810732833242932e-01,  4.316769231929027e-02,
   -7.568108239381779e-01,  7.901122315570046e-01,  9.576721669303179e-02,
   -5.448202693114659e-01,  5.034324548840123e-01,  1.739315171493671e-01,
   -5.908385723762482e-01, -1.268935867110808e-01,  1.941490024297708e-01,
   -2.895046302710989e-01, -9.116133911949098e-01,  9.663345199603172e-02,
   -6.417036777526361e-01, -9.886715561256082e-01,  2.266331268661072e-02,
   -7.921595150813847e-01,  9.955322518565568e-01,  1.393382316893550e-02,
   -9.527313016559716e-01,  5.688243284550245e-01,  5.657603379663307e-02,
   -8.300912488610223e-01,  2.262029630794567e-01,  1.327223448878936e-01,
   -5.758839055540124e-01, -6.756366015563920e-01,  1.369481741372994e-01,
   -7.954880187581953e-01, -8.506684869408652e-01,  6.033321912862107e-02,
   -9.562007514872694e-01,  9.139906777934969e-01,  2.419546581425405e-02,
   -9.839876523259704e-01, -5.381597268716472e-02,  4.116110545021220e-02,
   -8.552518042944189e-01, -4.002028380944249e-01,  1.164178174263354e-01,
   -9.694591723778574e-01, -6.823556992833991e-01,  3.472756253802061e-02,
   -9.468282975367817e-01, -9.506255113908446e-01,  1.793373090014833e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr15 ( )

/******************************************************************************/
/*
  Purpose:

    SMR15 returns the SMR rule of degree 15.

  Discussion:
 
    DEGREE: 15
    SYMMETRY: (X,Y), (-X,-Y).
    POINTS CARDINALITY: 43
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR15[3*43], the requested rule.
*/
{
  const int degree = 15;
  int order;
  double xw[3*43] = {
   -9.897035809317545e-01,  5.425907314742811e-01,  2.692004637463620e-02,
   -9.844256804341962e-01, -8.630433434831161e-01,  1.749593663841038e-02,
   -9.720740612950027e-01, -3.529770957215327e-01,  4.407397330060381e-02,
   -9.717518222429252e-01,  9.683214017531246e-01,  9.597984117068133e-03,
   -9.192734438999380e-01,  1.159789159156424e-01,  9.186688636374692e-02,
   -8.920718007989080e-01,  8.096447739678093e-01,  6.009039847791869e-02,
   -8.694522415973330e-01, -9.761961093345928e-01,  2.099677952515304e-02,
   -8.685236892209494e-01, -6.756459657106383e-01,  7.822899155683208e-02,
   -7.630389610522654e-01, -4.519651830370793e-01,  4.323794116684067e-02,
   -7.606746138826611e-01,  4.797962173343035e-01,  1.341465202538838e-01,
   -7.151716310198851e-01, -1.863833474025069e-01,  1.456054555637575e-01,
   -6.987339962580051e-01,  9.595571077523438e-01,  4.226674647754744e-02,
   -6.348443155921265e-01, -8.760006464754001e-01,  8.606581576391330e-02,
   -5.034250302130044e-01,  7.544476347964910e-01,  1.336407358940195e-01,
   -4.795655397342558e-01,  1.795809740683987e-01,  2.029010677239986e-01,
   -4.639944974152491e-01, -5.789694673013793e-01,  1.560859171904400e-01,
   -3.244129251598891e-01, -9.815797807964038e-01,  3.669707979316125e-02,
   -2.413326601845606e-01, -2.562094364546668e-01,  1.805943476814126e-01,
   -2.289847857525782e-01,  9.462454193863400e-01,  7.000525056015877e-02,
   -1.648117901013778e-01,  5.076930665870906e-01,  2.008843851797360e-01,
   -1.220776156497820e-01, -8.000225811280368e-01,  1.383276061021405e-01,
    0.000000000000000e+00,  0.000000000000000e+00,  1.605402685892418e-01,
    1.220776156497820e-01,  8.000225811280368e-01,  1.383276061021405e-01,
    1.648117901013778e-01, -5.076930665870906e-01,  2.008843851797360e-01,
    2.289847857525782e-01, -9.462454193863400e-01,  7.000525056015877e-02,
    2.413326601845606e-01,  2.562094364546668e-01,  1.805943476814126e-01,
    3.244129251598891e-01,  9.815797807964038e-01,  3.669707979316125e-02,
    4.639944974152491e-01,  5.789694673013793e-01,  1.560859171904400e-01,
    4.795655397342558e-01, -1.795809740683987e-01,  2.029010677239986e-01,
    5.034250302130044e-01, -7.544476347964910e-01,  1.336407358940195e-01,
    6.348443155921265e-01,  8.760006464754001e-01,  8.606581576391330e-02,
    6.987339962580051e-01, -9.595571077523438e-01,  4.226674647754744e-02,
    7.151716310198851e-01,  1.863833474025069e-01,  1.456054555637575e-01,
    7.606746138826611e-01, -4.797962173343035e-01,  1.341465202538838e-01,
    7.630389610522654e-01,  4.519651830370793e-01,  4.323794116684067e-02,
    8.685236892209494e-01,  6.756459657106383e-01,  7.822899155683208e-02,
    8.694522415973330e-01,  9.761961093345928e-01,  2.099677952515304e-02,
    8.920718007989080e-01, -8.096447739678093e-01,  6.009039847791869e-02,
    9.192734438999380e-01, -1.159789159156424e-01,  9.186688636374692e-02,
    9.717518222429252e-01, -9.683214017531246e-01,  9.597984117068133e-03,
    9.720740612950027e-01,  3.529770957215327e-01,  4.407397330060381e-02,
    9.844256804341962e-01,  8.630433434831161e-01,  1.749593663841038e-02,
    9.897035809317545e-01, -5.425907314742811e-01,  2.692004637463620e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr16 ( )

/******************************************************************************/
/*
  Purpose:

    SMR16 returns the SMR rule of degree 16.

  Discussion:

    DEGREE: 16
    POINTS CARDINALITY: 52
    NORM INF MOMS. RESIDUAL: 9.15934e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR16[3*52], the requested rule.
*/
{
  const int degree = 16;
  int order;
  double xw[3*52] = {
    9.849840927490825e-01, -8.331548011067518e-01,  1.148497840181236e-02,
    9.872657987157976e-01,  8.588448788294810e-01,  1.473194969200236e-02,
    9.793426944857834e-01,  3.488215241207180e-01,  3.098444037686296e-02,
    9.710730712462519e-01, -1.976275486943358e-01,  3.939075140298535e-02,
    9.543665314722640e-01, -6.214859681775430e-01,  3.181988181461071e-02,
    8.967156835567945e-01,  6.357233965740013e-01,  6.754726963166503e-02,
    8.560787402043915e-01,  9.300163636799799e-02,  9.806208102265382e-02,
    8.352602163787974e-01, -4.546303275105074e-01,  8.007156600306299e-02,
    9.242704749020406e-01, -9.624752146350085e-01,  1.773036206031470e-02,
    8.914637296434523e-01,  9.704982463181010e-01,  1.966130427988303e-02,
    7.225506553250621e-01,  8.352620376414029e-01,  7.379440929879094e-02,
    6.725198105909391e-01,  3.980674436765583e-01,  1.347645483339404e-01,
    6.371105617029685e-01, -1.999912055384129e-01,  1.423112416621634e-01,
    7.808910471981420e-01, -8.134492991124070e-01,  7.085421872868532e-02,
    6.337062775345687e-01, -9.719980099330250e-01,  2.925279318090791e-02,
    5.291062928070972e-01,  9.679384351925090e-01,  3.562931685878622e-02,
    4.244965002466626e-01,  6.479593280988540e-01,  1.310143500409354e-01,
    3.773110188906150e-01,  1.020856639775450e-01,  1.867695133142744e-01,
    5.192633407488266e-01, -6.187964471903282e-01,  1.329295627808754e-01,
    3.642312437714700e-01, -8.863235986829771e-01,  7.576971496593095e-02,
    5.561745660244605e-02,  9.824987512094673e-01,  2.458923517607215e-02,
    2.315339247267523e-01,  8.666994462444320e-01,  7.856108542290755e-02,
    7.921301678093465e-02,  3.983722019927857e-01,  1.821994092983056e-01,
    2.060553068006480e-01, -3.586293462932311e-01,  1.877843167547426e-01,
    5.968748053306436e-02, -7.377671587273356e-01,  1.194943798093123e-01,
    9.345890458174631e-02, -9.856937685796492e-01,  2.683866060217570e-02,
   -2.309174536279237e-01,  9.038233934314195e-01,  5.704293324973451e-02,
   -8.490129042248308e-02,  7.103616948287095e-01,  1.008414737624086e-01,
   -1.156391657288008e-01, -5.831278342511520e-02,  2.065290952798645e-01,
   -2.469994669672659e-01, -5.451953129096770e-01,  1.486152719982061e-01,
   -2.407569095414160e-01, -9.110001765460239e-01,  7.369448825579748e-02,
   -5.483869894552442e-01, -9.876593748951622e-01,  2.052629805335149e-02,
   -4.504247208566849e-01,  9.823752262299734e-01,  2.182431901411460e-02,
   -3.866081747635596e-01,  6.227238096470654e-01,  9.969926465444570e-02,
   -3.830201431115215e-01,  2.758592684399684e-01,  1.620659760964653e-01,
   -5.052430403406701e-01, -2.965505634060009e-01,  1.515331269600610e-01,
   -5.534470349649314e-01, -7.802045621704854e-01,  9.917678556230886e-02,
   -8.118615876869535e-01, -9.295671133984095e-01,  4.092795912351316e-02,
   -6.110904286470239e-01,  8.416598154470650e-01,  7.681751936941439e-02,
   -7.180850315887866e-01,  5.275124303877409e-01,  1.078772215341901e-01,
   -6.717184597177530e-01,  5.190959173969474e-02,  1.274953461648875e-01,
   -7.688067943153316e-01, -5.765647129796945e-01,  9.670064900592909e-02,
   -8.122178392749709e-01,  9.667410754993326e-01,  2.507418689814922e-02,
   -9.001198519620254e-01,  7.660124377216176e-01,  5.337920648061494e-02,
   -8.927917900428630e-01,  2.801343969829519e-01,  7.365567660310912e-02,
   -8.625316023871907e-01, -2.304828850740908e-01,  7.976422028192462e-02,
   -9.444379963884221e-01, -7.886904781685101e-01,  3.680993075145274e-02,
   -9.814383394418308e-01,  9.386107932617476e-01,  1.041932477487203e-02,
   -9.868302403965578e-01,  5.376625218147606e-01,  2.163454704946022e-02,
   -9.782564506674100e-01, -7.629524842176458e-03,  2.926520573014411e-02,
   -9.734724345230769e-01, -4.774981225500561e-01,  2.926793258824966e-02,
   -9.832450869161593e-01, -9.836383787047436e-01,  5.320699842671481e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr17 ( )

/******************************************************************************/
/*
  Purpose:

    SMR17 returns the SMR rule of degree 17.

  Discussion:

    DEGREE: 17
    SYMMETRY (X,Y), (-X,-Y)
    POINTS CARDINALITY: 54
    NORM INF MOMS. RESIDUAL: 4.44089e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR17[3*54], the requested rule.
*/
{
  const int degree = 17;
  int order;
  double xw[3*54] = {
   -9.863407162001064e-01, -5.350413962053188e-01,  2.305601467067279e-02,
   -9.797917920771685e-01,  9.250929106098536e-02,  3.240673241115238e-02,
   -9.759748695590249e-01, -9.216725954273451e-01,  1.270290274356204e-02,
   -9.751604610540874e-01,  8.226615823534071e-01,  6.967658416756498e-03,
   -9.655463590660567e-01,  5.873038194012039e-01,  3.379494459982002e-02,
   -9.580417051272648e-01,  9.392146008421756e-01,  1.490471492599059e-02,
   -8.990410418369936e-01, -2.442899840300571e-01,  8.052033202871829e-02,
   -8.929777462525665e-01, -7.628113086068719e-01,  5.184525239733102e-02,
   -8.684155248367631e-01, -9.940332573157988e-01,  8.888523934900541e-03,
   -8.543834155553983e-01,  3.348609125819369e-01,  8.942431131283363e-02,
   -8.198994002699886e-01,  7.861039744617548e-01,  6.602369125585303e-02,
   -7.927874398654909e-01,  9.867131971602722e-01,  1.519282623398942e-02,
   -7.313489231885142e-01, -5.375736491397500e-01,  1.043702032541429e-01,
   -7.090784726108733e-01, -9.201347632293920e-01,  4.542324896856204e-02,
   -6.903443278598889e-01,  8.463704695540367e-03,  1.345081852973794e-01,
   -6.159136297254387e-01,  5.598744500532884e-01,  1.235292068763380e-01,
   -5.503655196818333e-01,  9.111946838818689e-01,  6.486019261315923e-02,
   -5.088888961572688e-01, -7.826367523208496e-01,  8.485070415264370e-02,
   -4.701395263110675e-01, -3.185012886935781e-01,  1.454492206755823e-01,
   -3.956137656607415e-01,  2.488545706442738e-01,  1.612339647041861e-01,
   -3.787399827823459e-01, -9.766193765657439e-01,  3.251051105156653e-02,
   -2.831429683388207e-01,  7.382031830574145e-01,  1.224068303196167e-01,
   -2.468625326731463e-01, -6.309764352559230e-01,  1.169672902517008e-01,
   -2.225539938942038e-01,  9.838126768040562e-01,  2.855916848841619e-02,
   -1.626641413140420e-01, -1.008646063203129e-01,  1.626132038726945e-01,
   -6.874965210282233e-02, -8.853346747431012e-01,  8.682936644584309e-02,
   -5.847903009448556e-02,  4.510735833781594e-01,  1.501607980965882e-01,
    5.847903009448556e-02, -4.510735833781594e-01,  1.501607980965882e-01,
    6.874965210282233e-02,  8.853346747431012e-01,  8.682936644584309e-02,
    1.626641413140420e-01,  1.008646063203129e-01,  1.626132038726945e-01,
    2.225539938942038e-01, -9.838126768040562e-01,  2.855916848841619e-02,
    2.468625326731463e-01,  6.309764352559230e-01,  1.169672902517008e-01,
    2.831429683388207e-01, -7.382031830574145e-01,  1.224068303196167e-01,
    3.787399827823459e-01,  9.766193765657439e-01,  3.251051105156653e-02,
    3.956137656607415e-01, -2.488545706442738e-01,  1.612339647041861e-01,
    4.701395263110675e-01,  3.185012886935781e-01,  1.454492206755823e-01,
    5.088888961572688e-01,  7.826367523208496e-01,  8.485070415264370e-02,
    5.503655196818333e-01, -9.111946838818689e-01,  6.486019261315923e-02,
    6.159136297254387e-01, -5.598744500532884e-01,  1.235292068763380e-01,
    6.903443278598889e-01, -8.463704695540367e-03,  1.345081852973794e-01,
    7.090784726108733e-01,  9.201347632293920e-01,  4.542324896856204e-02,
    7.313489231885142e-01,  5.375736491397500e-01,  1.043702032541429e-01,
    7.927874398654909e-01, -9.867131971602722e-01,  1.519282623398942e-02,
    8.198994002699886e-01, -7.861039744617548e-01,  6.602369125585303e-02,
    8.543834155553983e-01, -3.348609125819369e-01,  8.942431131283363e-02,
    8.684155248367631e-01,  9.940332573157988e-01,  8.888523934900541e-03,
    8.929777462525665e-01,  7.628113086068719e-01,  5.184525239733102e-02,
    8.990410418369936e-01,  2.442899840300571e-01,  8.052033202871829e-02,
    9.580417051272648e-01, -9.392146008421756e-01,  1.490471492599059e-02,
    9.655463590660567e-01, -5.873038194012039e-01,  3.379494459982002e-02,
    9.751604610540874e-01, -8.226615823534071e-01,  6.967658416756498e-03,
    9.759748695590249e-01,  9.216725954273451e-01,  1.270290274356204e-02,
    9.797917920771685e-01, -9.250929106098536e-02,  3.240673241115238e-02,
    9.863407162001064e-01,  5.350413962053188e-01,  2.305601467067279e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr18 ( )

/******************************************************************************/
/*
  Purpose:

    SMR18 returns the SMR rule of degree 18.

  Discussion:

    DEGREE: 18
    POINTS CARDINALITY: 64
    NORM INF MOMS. RESIDUAL: 1.80411e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR18[3*64], the requested rule.
*/
{
  const int degree = 18;
  int order;
  double xw[3*64] = {
   -9.901134796801783e-01, -3.636920739279686e-01,  1.924401162821098e-02,
   -9.813479194657442e-01,  2.269728889226950e-01,  2.377081803411145e-02,
   -9.751246202174101e-01, -8.087895536063188e-01,  1.824571677716675e-02,
   -9.741192020631542e-01,  8.966914512186399e-01,  1.040325999881736e-02,
   -9.699879010686473e-01, -9.814171856874379e-01,  5.169228082043371e-03,
   -9.695988425630034e-01,  6.372691271564769e-01,  2.701864190192290e-02,
   -9.502627815202467e-01,  9.663374399441544e-01,  6.832430188474440e-03,
   -9.197723058789439e-01, -5.864804338113919e-02,  5.855723621166473e-02,
   -9.059247381128510e-01, -5.898828597989898e-01,  5.297590163131558e-02,
   -8.627599153540467e-01,  4.164987829940056e-01,  7.111515467482395e-02,
   -8.569855990839045e-01, -9.267827643653366e-01,  2.894383892650155e-02,
   -8.389143776305836e-01,  8.004661957859885e-01,  5.373522067458378e-02,
   -8.065675356071547e-01,  9.834437446052690e-01,  1.315188692146605e-02,
   -7.872448206722253e-01, -2.985727024319632e-01,  8.409595266673971e-02,
   -7.325897102338846e-01, -7.627707340005139e-01,  6.493193699070636e-02,
   -7.108608115543918e-01,  1.482798927069730e-01,  1.059543276308938e-01,
   -6.620192350608188e-01, -9.914865774170796e-01,  1.356692677046532e-02,
   -6.334849400427111e-01,  6.037434357654228e-01,  1.051942339342666e-01,
   -6.014705998319453e-01,  9.143204709310846e-01,  5.210486977766542e-02,
   -5.892324845704049e-01, -5.045342974742788e-01,  9.788981223530169e-02,
   -5.131040457735190e-01, -9.095715109599031e-02,  1.108235515488634e-01,
   -5.033556139567553e-01, -8.956709590819707e-01,  5.541443510056418e-02,
   -3.947567656009430e-01,  3.383853875972697e-01,  1.469566677471172e-01,
   -3.365255254825216e-01, -6.932064968553141e-01,  9.848736935036356e-02,
   -3.344750516678310e-01,  9.866136919798809e-01,  2.170786884754973e-02,
   -3.310287403968845e-01,  7.731192382826196e-01,  1.015778188232984e-01,
   -2.999505641193486e-01, -2.928443015341402e-01,  1.107816184233573e-01,
   -2.331455368936777e-01, -9.731854050766667e-01,  2.884073562303302e-02,
   -1.116980244718904e-01,  4.992438237750351e-02,  1.612001429698854e-01,
   -6.575627688742440e-02,  5.455174655246902e-01,  1.390613750634900e-01,
   -6.089043840299364e-02, -8.562318836763884e-01,  6.853830062046717e-02,
   -4.781118177875937e-02, -4.996330916388668e-01,  1.194580692354339e-01,
   -2.644564050493325e-02,  9.165721602454180e-01,  6.685724630082367e-02,
    1.924944168163869e-01, -2.367466035142029e-01,  1.491161554688392e-01,
    1.951330272152753e-01, -7.328036825494620e-01,  8.630902364197904e-02,
    2.028158693449157e-01, -9.703380537473529e-01,  3.364243858164141e-02,
    2.092663468167508e-01,  2.662322825395520e-01,  1.486647112920279e-01,
    2.283553896503115e-01,  7.496185156938090e-01,  1.027379035896721e-01,
    2.876554348315164e-01,  9.873845509936813e-01,  2.192507210698709e-02,
    4.237159887642933e-01, -5.535582535086475e-01,  1.058102193186085e-01,
    4.581157947253051e-01,  5.130944233380290e-01,  1.090905648997083e-01,
    4.752280776399702e-01, -8.857999997554080e-01,  6.346475038588688e-02,
    4.831508023294471e-01, -2.549857293827913e-02,  1.337777655566684e-01,
    5.057868104561423e-01,  8.896750734704260e-01,  6.079360942822091e-02,
    6.099162517568020e-01, -3.853032051834505e-01,  6.436419858280257e-02,
    6.559598836045895e-01,  2.795821152702244e-01,  8.177939511493874e-02,
    6.565622107706015e-01, -9.883582556647157e-01,  1.640381218907065e-02,
    6.956126158721206e-01,  6.950821057395169e-01,  7.746885102883669e-02,
    7.094177605066919e-01, -7.370072009566638e-01,  7.788188331156506e-02,
    7.290386435476074e-01,  9.703386432783726e-01,  2.313579562579107e-02,
    7.557526341619506e-01, -2.941608525026456e-01,  7.412112987017343e-02,
    7.912367791054172e-01,  8.744914899411797e-02,  6.420122545616397e-02,
    8.543844628271234e-01, -9.182475827792237e-01,  3.336594260262386e-02,
    8.645615995455240e-01,  4.552151496141779e-01,  6.553880387109420e-02,
    8.705823452020542e-01,  8.420186142289366e-01,  3.949607694089933e-02,
    8.978579920125014e-01, -5.603807009892569e-01,  5.906741413770155e-02,
    9.236747719664095e-01, -1.092483343302797e-01,  5.348329279696051e-02,
    9.440144649649265e-01,  9.743199890031753e-01,  8.946275110809443e-03,
    9.689413373175574e-01,  6.453835143088201e-01,  2.577199176900479e-02,
    9.716342103019509e-01, -9.824772013181601e-01,  5.332369479915357e-03,
    9.729481716901303e-01, -7.936277261963781e-01,  2.070804573643469e-02,
    9.758025156447697e-01,  2.267876624457436e-01,  2.981298882062168e-02,
    9.939173935792275e-01,  8.841354641450845e-01,  5.745299494229030e-03,
    9.953701290021145e-01, -3.661129988733890e-01,  1.543638847873499e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr19 ( )

/******************************************************************************/
/*
  Purpose:

    SMR19 returns the SMR rule of degree 19.

  Discussion:

    DEGREE: 19
    SYMMETRY: (X,Y), (-X,-Y)
    POINTS CARDINALITY: 67
    NORM INF MOMS. RESIDUAL: 4.44089e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR19[3*67], the requested rule.
*/
{
  const int degree = 19;
  int order;
  double xw[3*67] = {
   -9.882811207043626e-01,  5.499680659586386e-02,  2.092785503234627e-02,
   -9.849643667633750e-01,  6.212597907298936e-01,  1.808240699704512e-02,
   -9.813999666122014e-01, -4.952365265213790e-01,  2.248743945205191e-02,
   -9.782104202505005e-01,  9.275801424350509e-01,  1.011830773881234e-02,
   -9.691016249998836e-01, -9.857365066859964e-01,  4.619328461670566e-03,
   -9.683241755943918e-01, -8.352830082748723e-01,  1.956137669036511e-02,
   -9.202706700587867e-01,  3.511851149995373e-01,  5.773555533944277e-02,
   -9.094971072531579e-01, -2.172757421209814e-01,  6.345799736852624e-02,
   -8.955283373897494e-01,  7.976174402318889e-01,  3.990477349231469e-02,
   -8.910382534296201e-01,  9.945369448321910e-01,  6.887461729231832e-03,
   -8.645217306506207e-01, -6.631996105098346e-01,  5.773686209899585e-02,
   -8.361991822628865e-01, -9.403589726574770e-01,  2.822764839262689e-02,
   -7.730414957980034e-01,  8.238831136924889e-02,  1.001138265151715e-01,
   -7.650572339362595e-01,  5.862972313979000e-01,  7.938451847571938e-02,
   -7.339165122981658e-01,  9.301444324799357e-01,  3.698855138726674e-02,
   -7.142591688630336e-01, -4.144687459254282e-01,  9.862108370826694e-02,
   -6.567593878397442e-01, -8.187456800244232e-01,  6.430400825705974e-02,
   -5.911965681070577e-01, -9.890895416891479e-01,  1.619432554055879e-02,
   -5.650612797733545e-01,  3.562777186069158e-01,  1.145600986645687e-01,
   -5.522558344482561e-01,  7.877180001548971e-01,  7.542302799441891e-02,
   -5.204497226646213e-01, -1.319110721429938e-01,  1.271745083852966e-01,
   -4.843104169217222e-01, -6.372481900547796e-01,  7.509621769261574e-02,
   -4.576710954771651e-01,  9.804344277407575e-01,  2.360353464684936e-02,
   -3.501819505299977e-01, -9.155258592028724e-01,  5.647374387294429e-02,
   -3.449909757079617e-01, -5.171112886647338e-01,  6.683630505556533e-02,
   -3.245616103968320e-01,  6.112729098917052e-01,  1.024013654183961e-01,
   -2.899888936344285e-01,  1.640917354232377e-01,  1.271636872050067e-01,
   -2.124604121926062e-01,  8.907682205113933e-01,  6.854209870863227e-02,
   -2.101863370194021e-01, -2.888406804953518e-01,  1.103357066015591e-01,
   -2.061044019817992e-01, -7.806540187071476e-01,  3.167739924216664e-02,
   -6.183281639699825e-02,  4.515274811396188e-01,  1.060858442601201e-01,
   -5.624698000526564e-02, -7.388749473949220e-01,  8.327955875718944e-02,
   -4.730013829225772e-02, -9.811237074398366e-01,  2.608831452074966e-02,
    0.000000000000000e+00,  0.000000000000000e+00,  1.198105245928960e-01,
    4.730013829225772e-02,  9.811237074398366e-01,  2.608831452074966e-02,
    5.624698000526564e-02,  7.388749473949220e-01,  8.327955875718944e-02,
    6.183281639699825e-02, -4.515274811396188e-01,  1.060858442601201e-01,
    2.061044019817992e-01,  7.806540187071476e-01,  3.167739924216664e-02,
    2.101863370194021e-01,  2.888406804953518e-01,  1.103357066015591e-01,
    2.124604121926062e-01, -8.907682205113933e-01,  6.854209870863227e-02,
    2.899888936344285e-01, -1.640917354232377e-01,  1.271636872050067e-01,
    3.245616103968320e-01, -6.112729098917052e-01,  1.024013654183961e-01,
    3.449909757079617e-01,  5.171112886647338e-01,  6.683630505556533e-02,
    3.501819505299977e-01,  9.155258592028724e-01,  5.647374387294429e-02,
    4.576710954771651e-01, -9.804344277407575e-01,  2.360353464684936e-02,
    4.843104169217222e-01,  6.372481900547796e-01,  7.509621769261574e-02,
    5.204497226646213e-01,  1.319110721429938e-01,  1.271745083852966e-01,
    5.522558344482561e-01, -7.877180001548971e-01,  7.542302799441891e-02,
    5.650612797733545e-01, -3.562777186069158e-01,  1.145600986645687e-01,
    5.911965681070577e-01,  9.890895416891479e-01,  1.619432554055879e-02,
    6.567593878397442e-01,  8.187456800244232e-01,  6.430400825705974e-02,
    7.142591688630336e-01,  4.144687459254282e-01,  9.862108370826694e-02,
    7.339165122981658e-01, -9.301444324799357e-01,  3.698855138726674e-02,
    7.650572339362595e-01, -5.862972313979000e-01,  7.938451847571938e-02,
    7.730414957980034e-01, -8.238831136924889e-02,  1.001138265151715e-01,
    8.361991822628865e-01,  9.403589726574770e-01,  2.822764839262689e-02,
    8.645217306506207e-01,  6.631996105098346e-01,  5.773686209899585e-02,
    8.910382534296201e-01, -9.945369448321910e-01,  6.887461729231832e-03,
    8.955283373897494e-01, -7.976174402318889e-01,  3.990477349231469e-02,
    9.094971072531579e-01,  2.172757421209814e-01,  6.345799736852624e-02,
    9.202706700587867e-01, -3.511851149995373e-01,  5.773555533944277e-02,
    9.683241755943918e-01,  8.352830082748723e-01,  1.956137669036511e-02,
    9.691016249998836e-01,  9.857365066859964e-01,  4.619328461670566e-03,
    9.782104202505005e-01, -9.275801424350509e-01,  1.011830773881234e-02,
    9.813999666122014e-01,  4.952365265213790e-01,  2.248743945205191e-02,
    9.849643667633750e-01, -6.212597907298936e-01,  1.808240699704512e-02,
    9.882811207043626e-01, -5.499680659586386e-02,  2.092785503234627e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr19s ( )

/******************************************************************************/
/*
  Purpose:

    SMR19S returns the rotationally invariant SMR rule of degree 19.

  Discussion:

    DEGREE: 19
    ROTATIONALLY INVARIANT: (X,Y),(-Y,X),(-X,-Y),(Y,-X).
    POINTS CARDINALITY: 68
    NORM INF MOMS. RESIDUAL: 2.63678e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR19S[3*68], the requested rule.
*/
{
  const int degree = 19;
  int order;
  double xw[3*68] = {
    6.772712303303220e-02,  1.091623307294788e-01,  5.494509440087280e-02,
    1.911320239476111e-01,  7.684428790753622e-01,  9.924039371581232e-02,
    1.293584417049455e-01,  9.843401047067886e-01,  2.298164089064930e-02,
    2.653188588974263e-01,  3.187377804093571e-01,  1.356277329376223e-01,
    4.805884103058745e-01,  5.883672104526556e-01,  1.092830463202312e-01,
    4.353820421144143e-01,  9.253041863610407e-01,  5.332719030254342e-02,
    5.327122733511525e-01,  5.307888414194004e-02,  1.342811802398570e-01,
    6.817257899596626e-01,  8.006754071171294e-01,  6.668259225153295e-02,
    6.897274550636672e-01,  9.904094449990978e-01,  1.399432148751916e-02,
    8.960307328244307e-01,  1.256777467976840e-01,  6.752580403681208e-02,
    7.189012994269330e-01,  3.612251785232622e-01,  1.014916530440626e-01,
    8.636764064784566e-01,  6.273567750914366e-01,  5.639122590523545e-02,
    8.689071260438135e-01,  9.214958682077944e-01,  2.840189695206082e-02,
    9.851138463638244e-01,  3.506711929883037e-01,  1.440758011223270e-02,
    9.604323781459383e-01,  4.868528161195464e-01,  1.812287875530189e-02,
    9.757200071559576e-01,  7.955215584636620e-01,  1.826958037918748e-02,
    9.734329880957604e-01,  9.798840213938864e-01,  5.026188268466660e-03,
   -1.091623307294788e-01,  6.772712303303220e-02,  5.494509440087280e-02,
   -7.684428790753622e-01,  1.911320239476111e-01,  9.924039371581232e-02,
   -9.843401047067886e-01,  1.293584417049455e-01,  2.298164089064930e-02,
   -3.187377804093571e-01,  2.653188588974263e-01,  1.356277329376223e-01,
   -5.883672104526556e-01,  4.805884103058745e-01,  1.092830463202312e-01,
   -9.253041863610407e-01,  4.353820421144143e-01,  5.332719030254342e-02,
   -5.307888414194004e-02,  5.327122733511525e-01,  1.342811802398570e-01,
   -8.006754071171294e-01,  6.817257899596626e-01,  6.668259225153295e-02,
   -9.904094449990978e-01,  6.897274550636672e-01,  1.399432148751916e-02,
   -1.256777467976840e-01,  8.960307328244307e-01,  6.752580403681208e-02,
   -3.612251785232622e-01,  7.189012994269330e-01,  1.014916530440626e-01,
   -6.273567750914366e-01,  8.636764064784566e-01,  5.639122590523545e-02,
   -9.214958682077944e-01,  8.689071260438135e-01,  2.840189695206082e-02,
   -3.506711929883037e-01,  9.851138463638244e-01,  1.440758011223270e-02,
   -4.868528161195464e-01,  9.604323781459383e-01,  1.812287875530189e-02,
   -7.955215584636620e-01,  9.757200071559576e-01,  1.826958037918748e-02,
   -9.798840213938864e-01,  9.734329880957604e-01,  5.026188268466660e-03,
   -6.772712303303220e-02, -1.091623307294788e-01,  5.494509440087280e-02,
   -1.911320239476111e-01, -7.684428790753622e-01,  9.924039371581232e-02,
   -1.293584417049455e-01, -9.843401047067886e-01,  2.298164089064930e-02,
   -2.653188588974263e-01, -3.187377804093571e-01,  1.356277329376223e-01,
   -4.805884103058745e-01, -5.883672104526556e-01,  1.092830463202312e-01,
   -4.353820421144143e-01, -9.253041863610407e-01,  5.332719030254342e-02,
   -5.327122733511525e-01, -5.307888414194004e-02,  1.342811802398570e-01,
   -6.817257899596626e-01, -8.006754071171294e-01,  6.668259225153295e-02,
   -6.897274550636672e-01, -9.904094449990978e-01,  1.399432148751916e-02,
   -8.960307328244307e-01, -1.256777467976840e-01,  6.752580403681208e-02,
   -7.189012994269330e-01, -3.612251785232622e-01,  1.014916530440626e-01,
   -8.636764064784566e-01, -6.273567750914366e-01,  5.639122590523545e-02,
   -8.689071260438135e-01, -9.214958682077944e-01,  2.840189695206082e-02,
   -9.851138463638244e-01, -3.506711929883037e-01,  1.440758011223270e-02,
   -9.604323781459383e-01, -4.868528161195464e-01,  1.812287875530189e-02,
   -9.757200071559576e-01, -7.955215584636620e-01,  1.826958037918748e-02,
   -9.734329880957604e-01, -9.798840213938864e-01,  5.026188268466660e-03,
    1.091623307294788e-01, -6.772712303303220e-02,  5.494509440087280e-02,
    7.684428790753622e-01, -1.911320239476111e-01,  9.924039371581232e-02,
    9.843401047067886e-01, -1.293584417049455e-01,  2.298164089064930e-02,
    3.187377804093571e-01, -2.653188588974263e-01,  1.356277329376223e-01,
    5.883672104526556e-01, -4.805884103058745e-01,  1.092830463202312e-01,
    9.253041863610407e-01, -4.353820421144143e-01,  5.332719030254342e-02,
    5.307888414194004e-02, -5.327122733511525e-01,  1.342811802398570e-01,
    8.006754071171294e-01, -6.817257899596626e-01,  6.668259225153295e-02,
    9.904094449990978e-01, -6.897274550636672e-01,  1.399432148751916e-02,
    1.256777467976840e-01, -8.960307328244307e-01,  6.752580403681208e-02,
    3.612251785232622e-01, -7.189012994269330e-01,  1.014916530440626e-01,
    6.273567750914366e-01, -8.636764064784566e-01,  5.639122590523545e-02,
    9.214958682077944e-01, -8.689071260438135e-01,  2.840189695206082e-02,
    3.506711929883037e-01, -9.851138463638244e-01,  1.440758011223270e-02,
    4.868528161195464e-01, -9.604323781459383e-01,  1.812287875530189e-02,
    7.955215584636620e-01, -9.757200071559576e-01,  1.826958037918748e-02,
    9.798840213938864e-01, -9.734329880957604e-01,  5.026188268466660e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr20 ( )

/******************************************************************************/
/*
  Purpose:

    SMR20 returns the SMR rule of degree 20.

  Discussion:
 
    DEGREE: 20
    POINTS CARDINALITY: 78
    NORM INF MOMS. RESIDUAL: 2.28983e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR20[3*78], the requested rule.
*/
{
  const int degree = 20;
  int order;
  double xw[3*78] = {
   -9.915878317634396e-01, -3.766765890053987e-01,  1.499554515729458e-02,  
   -9.848784210298892e-01,  2.360994416770047e-01,  2.023115319845336e-02,  
   -9.825526677091110e-01, -8.035427779709161e-01,  1.282555877962797e-02,  
   -9.823044706287086e-01,  9.079824601518448e-01,  8.347241351837816e-03,  
   -9.779664722705005e-01,  6.550056336206199e-01,  1.862995031692569e-02,  
   -9.749883694415311e-01, -9.764755256224437e-01,  4.686323174122413e-03,  
   -9.385487288532800e-01,  9.860342433350299e-01,  5.797911563640461e-03,  
   -9.382963126427573e-01, -8.801426949855569e-02,  4.706757194633274e-02,  
   -9.249968857981914e-01, -6.085959286922041e-01,  4.012822177863082e-02,  
   -8.999893404040346e-01,  4.529514070355635e-01,  5.107860141818281e-02,  
   -8.920744993132258e-01, -9.198780734342489e-01,  2.159208371061492e-02,  
   -8.839154125809222e-01,  8.143818242625289e-01,  3.594236238111754e-02,  
   -8.255579083847894e-01, -3.654427417348043e-01,  6.695838633949613e-02,  
   -8.150245024284021e-01,  1.358607026009545e-01,  6.745427113661845e-02,  
   -7.845038084549548e-01,  9.550568485953186e-01,  2.204090981614230e-02,  
   -7.824159434580745e-01, -7.878743325718499e-01,  4.748312482965101e-02,  
   -7.695472095330197e-01, -9.958600578952408e-01,  8.095042436189770e-03,  
   -7.297305046678980e-01,  6.478626088426425e-01,  7.099765909663569e-02,  
   -6.917823169027344e-01,  3.281317067480576e-01,  5.185357866003446e-02,  
   -6.707656574849767e-01, -1.664730150689492e-01,  7.925719271981636e-02,  
   -6.531604608468555e-01, -6.061553872260436e-01,  6.838834261564096e-02,  
   -6.077773437763014e-01,  8.732147826609341e-01,  4.367407053165663e-02,  
   -6.066275299755738e-01, -9.326014647185664e-01,  3.595011352210572e-02,  
   -5.368890549246464e-01,  9.928457944663468e-01,  1.126554474822698e-02,  
   -5.316204099083646e-01,  6.576158887431759e-02,  8.069676572542248e-02,  
   -4.990046627082800e-01,  4.435890153276254e-01,  9.122827397472959e-02,  
   -4.796158821615813e-01, -4.431584361510255e-01,  8.384497173647569e-02,  
   -4.453245842342572e-01, -8.121904960479558e-01,  5.866651296620028e-02,  
   -4.339460304187116e-01,  7.546357919895570e-01,  6.052390807315380e-02,  
   -3.360460286836234e-01, -1.779527551281239e-01,  9.606753662405314e-02,  
   -3.163304450629529e-01, -9.789738490980646e-01,  2.421886578475265e-02,  
   -2.973007276058863e-01,  9.384528339104452e-01,  3.945003410423680e-02,  
   -2.583665449486478e-01, -6.746223007740130e-01,  7.803382675359716e-02,  
   -2.518910778242828e-01,  2.047144992617838e-01,  1.190753521874101e-01,  
   -2.350658939126170e-01,  6.176223949714494e-01,  8.152900900964591e-02,  
   -1.249372040555246e-01, -4.012798196143892e-01,  9.737789681157598e-02,  
   -1.071681420632334e-01,  9.911853557002673e-01,  7.840583991172302e-03,  
   -7.990032115620818e-02, -8.881537557485726e-01,  6.417774009554068e-02,  
   -4.818581787472142e-02,  8.368871897464495e-01,  6.958137992100039e-02,  
   -6.302932436761816e-03,  4.427387497778728e-01,  1.046411531707668e-01,  
    6.282561382377720e-03, -4.735863969094835e-02,  1.283072770780011e-01,  
    7.678421140871043e-02, -6.515968986198225e-01,  7.386235866198392e-02,  
    1.223163344818137e-01, -5.049264867963420e-01,  3.280543393245010e-02,  
    1.476259613184704e-01,  9.693655840355563e-01,  2.767850463294367e-02,  
    1.518625838305689e-01, -9.802704961935971e-01,  2.416012781979250e-02,  
    2.026981528589298e-01,  6.904257555809832e-01,  8.975917019163195e-02,  
    2.329194026833933e-01,  2.327373099667877e-01,  1.156666854710510e-01,  
    2.594187814838830e-01, -2.856358493697289e-01,  1.124110482665555e-01,  
    2.798470302423499e-01, -8.056133086386197e-01,  7.131679353184883e-02,  
    3.814217712474836e-01,  8.883375933116525e-01,  5.600628102613372e-02,  
    4.444592404902306e-01,  5.043261157258173e-01,  1.006394209690602e-01,  
    4.558914387037205e-01, -5.329822923030598e-01,  9.411407048103884e-02,  
    4.614020071813320e-01,  4.486972130091344e-03,  1.101092346172853e-01,  
    4.685495664357138e-01, -9.368544770988728e-01,  4.082934734266681e-02,  
    5.560918457946907e-01,  9.862938876987586e-01,  1.658263314370683e-02,  
    6.138352275991088e-01,  7.500124042821561e-01,  7.207159699616439e-02,  
    6.168426991815920e-01, -7.309006089346149e-01,  6.388336371014162e-02,  
    6.496172646332740e-01, -2.465046206462174e-01,  9.502316165822158e-02,  
    6.597659995735623e-01,  2.810856634851854e-01,  9.635446672099211e-02,  
    6.758048936769788e-01, -9.975229702582141e-01,  8.901892537462009e-03,  
    7.526986651007189e-01, -8.790172927450672e-01,  3.744847919043556e-02,  
    7.612710727469121e-01,  9.187271298549152e-01,  3.541134799086990e-02,  
    7.917231830960033e-01, -4.936809625913063e-01,  6.733975809456394e-02,  
    8.045897042890074e-01,  5.573763685706831e-01,  6.859164893126736e-02,  
    8.267194449217807e-01,  2.268030189899398e-02,  7.832191919270795e-02,  
    8.905802715963324e-01, -9.579826342974288e-01,  1.558785638304684e-02,  
    8.926961921705238e-01, -7.092071287453895e-01,  3.889483241199626e-02,  
    9.008369589898633e-01,  9.865275306057119e-01,  7.998523354461931e-03,  
    9.055629673123163e-01,  7.845529526667002e-01,  3.438925925800883e-02,  
    9.323802074714704e-01, -2.645795079832657e-01,  4.838142723685821e-02,  
    9.345858376931122e-01,  3.200026555755083e-01,  4.824416289256322e-02,  
    9.738506914356970e-01, -8.469006629251953e-01,  1.394893863211126e-02,  
    9.755796434358871e-01,  8.802225242154167e-01,  6.292208457909152e-03,  
    9.843147800221137e-01, -5.383749684018156e-01,  1.737917079753502e-02,  
    9.849316953313286e-01,  9.464841822891732e-01,  4.298012753035497e-03,  
    9.851840541929131e-01,  6.021648971571338e-01,  1.660764544264520e-02,  
    9.870587239914860e-01, -9.834157626132080e-01,  2.426383339927545e-03,  
    9.921802352398980e-01,  2.608826889643944e-02,  1.626098469219482e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr21 ( )

/******************************************************************************/
/*
  Purpose:

    SMR21 returns the SMR rule of degree 21.

  Discussion:

    DEGREE: 21
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 81
    NORM INF MOMS. RESIDUAL: 4.44089e-15
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR21[3*81], the requested rule.
*/
{
  const int degree = 21;
  int order;
  double xw[3*81] = {
    2.659786054558319e-01,  2.472943466792205e-01,  1.257081274315271e-01,  
    2.966299561078732e-01,  6.837659120145181e-01,  9.195620074644660e-02,  
    3.476456848560975e-01,  9.391305012893792e-01,  3.823913002575823e-02,  
    5.204899365134467e-01,  4.701056221362075e-01,  9.955659700462254e-02,  
    5.565331479249288e-01,  8.299687476559192e-01,  5.711233679557120e-02,  
    5.608625825041144e-01,  9.938235381537796e-01,  8.125409684532186e-03,  
    7.107545267842089e-01,  2.218786231241980e-01,  8.989795633682901e-02,  
    7.323028382034139e-01,  6.675759613958541e-01,  6.285712965516167e-02,  
    7.248337121391071e-01,  9.556008374660931e-01,  2.068885521020362e-02,  
    8.678958423780866e-01,  4.595394054487673e-01,  5.463376630254965e-02,  
    8.501142309217191e-01,  8.692220828069680e-01,  2.950403142043507e-02,  
    9.142859758630335e-01,  9.852274923275850e-01,  6.850217129206400e-03,  
    9.537223544012101e-01,  2.050108803358328e-01,  3.630414793101230e-02,  
    9.934425198626209e-01,  5.102048128337472e-01,  1.110556726680624e-02,  
    9.448573049959050e-01,  7.218738735054576e-01,  2.723130314700101e-02,  
    9.865716562931908e-01,  8.882998675210052e-01,  6.165546352541271e-03,  
    9.790570750021207e-01,  9.587134606894607e-01,  2.900715554613127e-03,  
    1.944817128807972e-02,  4.950400647800665e-01,  1.165426493105556e-01,  
    5.600805589569329e-02,  8.501230581964183e-01,  6.754741413634147e-02,  
    1.000588448960449e-01,  9.908677016040155e-01,  1.332984242008183e-02,  
   -2.472943466792205e-01,  2.659786054558319e-01,  1.257081274315271e-01,  
   -6.837659120145181e-01,  2.966299561078732e-01,  9.195620074644660e-02,  
   -9.391305012893792e-01,  3.476456848560975e-01,  3.823913002575823e-02,  
   -4.701056221362075e-01,  5.204899365134467e-01,  9.955659700462254e-02,  
   -8.299687476559192e-01,  5.565331479249288e-01,  5.711233679557120e-02,  
   -9.938235381537796e-01,  5.608625825041144e-01,  8.125409684532186e-03,  
   -2.218786231241980e-01,  7.107545267842089e-01,  8.989795633682901e-02,  
   -6.675759613958541e-01,  7.323028382034139e-01,  6.285712965516167e-02,  
   -9.556008374660931e-01,  7.248337121391071e-01,  2.068885521020362e-02,  
   -4.595394054487673e-01,  8.678958423780866e-01,  5.463376630254965e-02,  
   -8.692220828069680e-01,  8.501142309217191e-01,  2.950403142043507e-02,  
   -9.852274923275850e-01,  9.142859758630335e-01,  6.850217129206400e-03,  
   -2.050108803358328e-01,  9.537223544012101e-01,  3.630414793101230e-02,  
   -5.102048128337472e-01,  9.934425198626209e-01,  1.110556726680624e-02,  
   -7.218738735054576e-01,  9.448573049959050e-01,  2.723130314700101e-02,  
   -8.882998675210052e-01,  9.865716562931908e-01,  6.165546352541271e-03,  
   -9.587134606894607e-01,  9.790570750021207e-01,  2.900715554613127e-03,  
   -4.950400647800665e-01,  1.944817128807972e-02,  1.165426493105556e-01,  
   -8.501230581964183e-01,  5.600805589569329e-02,  6.754741413634147e-02,  
   -9.908677016040155e-01,  1.000588448960449e-01,  1.332984242008183e-02,  
   -2.659786054558319e-01, -2.472943466792205e-01,  1.257081274315271e-01,  
   -2.966299561078732e-01, -6.837659120145181e-01,  9.195620074644660e-02,  
   -3.476456848560975e-01, -9.391305012893792e-01,  3.823913002575823e-02,  
   -5.204899365134467e-01, -4.701056221362075e-01,  9.955659700462254e-02,  
   -5.565331479249288e-01, -8.299687476559192e-01,  5.711233679557120e-02,  
   -5.608625825041144e-01, -9.938235381537796e-01,  8.125409684532186e-03,  
   -7.107545267842089e-01, -2.218786231241980e-01,  8.989795633682901e-02,  
   -7.323028382034139e-01, -6.675759613958541e-01,  6.285712965516167e-02,  
   -7.248337121391071e-01, -9.556008374660931e-01,  2.068885521020362e-02,  
   -8.678958423780866e-01, -4.595394054487673e-01,  5.463376630254965e-02,  
   -8.501142309217191e-01, -8.692220828069680e-01,  2.950403142043507e-02,  
   -9.142859758630335e-01, -9.852274923275850e-01,  6.850217129206400e-03,  
   -9.537223544012101e-01, -2.050108803358328e-01,  3.630414793101230e-02,  
   -9.934425198626209e-01, -5.102048128337472e-01,  1.110556726680624e-02,  
   -9.448573049959050e-01, -7.218738735054576e-01,  2.723130314700101e-02,  
   -9.865716562931908e-01, -8.882998675210052e-01,  6.165546352541271e-03,  
   -9.790570750021207e-01, -9.587134606894607e-01,  2.900715554613127e-03,  
   -1.944817128807972e-02, -4.950400647800665e-01,  1.165426493105556e-01,  
   -5.600805589569329e-02, -8.501230581964183e-01,  6.754741413634147e-02,  
   -1.000588448960449e-01, -9.908677016040155e-01,  1.332984242008183e-02,  
    2.472943466792205e-01, -2.659786054558319e-01,  1.257081274315271e-01,  
    6.837659120145181e-01, -2.966299561078732e-01,  9.195620074644660e-02,  
    9.391305012893792e-01, -3.476456848560975e-01,  3.823913002575823e-02,  
    4.701056221362075e-01, -5.204899365134467e-01,  9.955659700462254e-02,  
    8.299687476559192e-01, -5.565331479249288e-01,  5.711233679557120e-02,  
    9.938235381537796e-01, -5.608625825041144e-01,  8.125409684532186e-03,  
    2.218786231241980e-01, -7.107545267842089e-01,  8.989795633682901e-02,  
    6.675759613958541e-01, -7.323028382034139e-01,  6.285712965516167e-02,  
    9.556008374660931e-01, -7.248337121391071e-01,  2.068885521020362e-02,  
    4.595394054487673e-01, -8.678958423780866e-01,  5.463376630254965e-02,  
    8.692220828069680e-01, -8.501142309217191e-01,  2.950403142043507e-02,  
    9.852274923275850e-01, -9.142859758630335e-01,  6.850217129206400e-03,  
    2.050108803358328e-01, -9.537223544012101e-01,  3.630414793101230e-02,  
    5.102048128337472e-01, -9.934425198626209e-01,  1.110556726680624e-02,  
    7.218738735054576e-01, -9.448573049959050e-01,  2.723130314700101e-02,  
    8.882998675210052e-01, -9.865716562931908e-01,  6.165546352541271e-03,  
    9.587134606894607e-01, -9.790570750021207e-01,  2.900715554613127e-03,  
    4.950400647800665e-01, -1.944817128807972e-02,  1.165426493105556e-01,  
    8.501230581964183e-01, -5.600805589569329e-02,  6.754741413634147e-02,  
    9.908677016040155e-01, -1.000588448960449e-01,  1.332984242008183e-02,  
    0.000000000000000e+00,  0.000000000000000e+00,  1.349722245528155e-01 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr22 ( )

/******************************************************************************/
/*
  Purpose:

    SMR22 returns the SMR rule of degree 22.

  Discussion:
 
    DEGREE: 22
    POINTS CARDINALITY: 93
    NORM INF MOMS. RESIDUAL: 9.10296e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR22[3*93], the requested rule.
*/
{
  const int degree = 22;
  int order;
  double xw[3*93] = {
    9.886329057797582e-01, -1.145674729933659e-01,  1.325842639382102e-02,  
    9.888026938509622e-01, -5.213303149527411e-01,  1.068979190883013e-02,  
    9.661816000824490e-01, -7.555070898927371e-01,  1.743977208490352e-02,  
    9.889031095854282e-01, -9.320977012046493e-01,  5.174381878169184e-03,  
    9.873701927717461e-01,  9.897035459144938e-01,  1.707304801541134e-03,  
    9.905941115128364e-01,  8.327302191279294e-01,  6.754790334156039e-03,  
    9.706393731700478e-01,  5.982438926502055e-01,  2.062095495154808e-02,  
    9.803136579961507e-01,  2.717042647614646e-01,  1.891617092472248e-02,  
    9.341083383086605e-01, -3.353056638554749e-01,  3.390112966783673e-02,  
    8.734893606329978e-01, -6.054983585922311e-01,  3.753341638181854e-02,  
    8.810582900635474e-01, -8.777017334048872e-01,  2.414667023001881e-02,  
    9.308712251904757e-01, -9.880767541958921e-01,  5.413462408552709e-03,  
    9.377374302689546e-01,  9.330744362659844e-01,  1.265810122238417e-02,  
    8.843781920205257e-01,  7.681591801566370e-01,  3.367838185981432e-02,  
    8.775411599331090e-01,  4.195677919703100e-01,  4.701250942104521e-02,  
    9.082100522297584e-01,  4.460741468226298e-02,  4.492517531449552e-02,  
    7.763303548789647e-01, -4.810624802969050e-01,  3.017348276324992e-02,  
    7.230162511431557e-01, -7.596607824735281e-01,  4.911947899024260e-02,  
    7.562342329425361e-01, -9.545271924860271e-01,  1.392058621129393e-02,  
    8.327763332833239e-01,  9.863527280259253e-01,  8.265982196594024e-03,  
    7.412680367128046e-01,  8.954212932861624e-01,  3.350811254077402e-02,  
    7.400126973983402e-01,  6.111125638321177e-01,  5.811729500469508e-02,  
    7.414564617437679e-01,  1.965720776730482e-01,  7.150247641033709e-02,  
    7.867408087541262e-01, -1.930389785977610e-01,  6.417378369478929e-02,  
    5.369437186749637e-01, -6.314307127870589e-01,  4.820720884716240e-02,  
    5.461961159674565e-01, -8.910958585786000e-01,  4.010297901331633e-02,  
    7.505636824335776e-01, -9.781952487239193e-01,  5.423665310144266e-03,  
    5.668739124520142e-01,  9.769610350593898e-01,  1.855890684449772e-02,  
    5.608631907999050e-01,  7.717573834145061e-01,  5.676854811058375e-02,  
    5.612115855209996e-01,  4.088149453043886e-01,  8.333374346661079e-02,  
    5.661336430919435e-01, -4.176475015217607e-02,  9.157138052866115e-02,  
    6.134724653625782e-01, -4.169917924461408e-01,  6.572843506020827e-02,  
    3.374627534596129e-01, -7.953338524031655e-01,  4.698932393055661e-02,  
    5.506194243847290e-01, -9.906600094074560e-01,  6.956589831798293e-03,  
    3.682032600755504e-01,  8.998189655297543e-01,  4.291338908110833e-02,  
    3.503173557999109e-01,  6.043160593908300e-01,  8.199842424347994e-02,  
    3.484934492594987e-01,  1.842187014808652e-01,  1.042545147901201e-01,  
    3.599239753698877e-01, -2.793900622896136e-01,  1.003220388009486e-01,  
    3.352794040120309e-01, -6.090983723997480e-01,  5.250936392916155e-02,  
    1.648479846846835e-01, -9.222811023803827e-01,  3.600095811243217e-02,  
    3.409639556515009e-01, -9.775579820216516e-01,  1.513630382707296e-02,  
    2.013308254889806e-01,  9.817828174442371e-01,  1.803413215387369e-02,  
    1.340901732488610e-01,  7.766562660948982e-01,  6.844087294220280e-02,  
    1.144967045243097e-01,  4.069075707084039e-01,  1.019382263127832e-01,  
    1.189485784665626e-01, -5.433922354403713e-02,  1.136907024324531e-01,  
    1.058758908864689e-01, -4.793787778363424e-01,  9.348793573923811e-02,  
    2.839855852222449e-02, -7.559768193014593e-01,  6.803236606704954e-02,  
   -4.712493250696739e-02, -9.874476808665996e-01,  1.515020459751181e-02,  
   -1.410549552011679e-01,  9.945136764387909e-01,  7.185771234424889e-03,  
   -5.100979131120797e-02,  9.148649196209385e-01,  4.369402100644239e-02,  
   -1.137013612566373e-01,  6.139356044623114e-01,  8.777317450897354e-02,  
   -1.244170197023402e-01,  1.823653793283892e-01,  1.117684867762398e-01,  
   -1.370122651236654e-01, -2.712575708608372e-01,  1.085208525145446e-01,  
   -2.232031959837765e-01, -6.067425313332153e-01,  8.558870495241622e-02,  
   -1.940829548165339e-01, -8.901639697157221e-01,  4.867603590079570e-02,  
   -4.081653916012992e-01, -9.709368148205605e-01,  2.331260017933040e-02,  
   -3.533981306028999e-01,  9.616410187563108e-01,  2.242566292797548e-02,  
   -3.045652224491460e-01,  7.985802428860417e-01,  6.420737202085385e-02,  
   -3.526743970139553e-01,  4.146812551454919e-01,  9.787271335988859e-02,  
   -3.720004998868196e-01, -3.666778868685774e-02,  1.068882608071387e-01,  
   -4.514888617224385e-01, -4.096349836635951e-01,  9.192684575976928e-02,  
   -4.429908638318878e-01, -7.743729186166529e-01,  6.295500628522636e-02,  
   -6.815740834481019e-01, -9.928214216661736e-01,  7.026776085145282e-03,  
   -5.632109089288005e-01,  9.935896447624268e-01,  6.283490740799424e-03,  
   -5.621512958714884e-01,  8.896399470067906e-01,  3.761225364844008e-02,  
   -5.382057775784931e-01,  6.382212857626252e-01,  7.506638282008458e-02,  
   -5.813167555829912e-01,  2.056862702815186e-01,  9.243697007930982e-02,  
   -6.516405814152544e-01, -1.846901900997915e-01,  8.505041739260445e-02,  
   -6.506998051630787e-01, -6.087053290037806e-01,  6.818365853952568e-02,  
   -6.334805048429584e-01, -8.975976820838455e-01,  3.682517885499488e-02,  
   -7.472275238683430e-01,  9.641740358177714e-01,  1.669151214269935e-02,  
   -7.482067350979565e-01,  7.780755148965470e-01,  4.495260598024266e-02,  
   -7.400821884669309e-01,  4.532491832762973e-01,  6.928645874800578e-02,  
   -8.105044748991020e-01,  5.416962245544283e-02,  6.619505274805781e-02,  
   -8.156792303551951e-01, -4.060746003340047e-01,  6.042829810764130e-02,  
   -8.090136873528386e-01, -7.748312229117293e-01,  4.151899530758620e-02,  
   -8.335513136071991e-01, -9.535072625443444e-01,  1.514946999120562e-02,  
   -8.872174992437346e-01,  8.965769271361460e-01,  2.104433235476698e-02,  
   -8.931086765195151e-01,  6.328025905174818e-01,  3.860028858677801e-02,  
   -8.916333811989803e-01,  3.038140953910366e-01,  2.786266023247349e-02,  
   -9.292789589232818e-01, -1.761834888463487e-01,  4.117008802426377e-02,  
   -9.292197203932411e-01, -6.069529981720342e-01,  3.315912528944302e-02,  
   -9.385590119112288e-01, -8.777667192165588e-01,  1.580481441801968e-02,  
   -9.284304209620261e-01, -9.951824052865140e-01,  2.664793505134054e-03,  
   -9.053874905610783e-01,  9.962748823261235e-01,  3.593987239589643e-03,  
   -9.747952911035821e-01,  7.907984327057133e-01,  1.405694455607466e-02,  
   -9.866861855312228e-01,  5.118586070736004e-01,  1.306184877568784e-02,  
   -9.863703578500000e-01,  6.111749406829102e-02,  1.559138821480461e-02,  
   -9.889270365025400e-01, -3.994782279754348e-01,  1.342812184963877e-02,  
   -9.908021213083021e-01, -7.596541692019284e-01,  7.741415848728735e-03,  
   -9.815692523507022e-01,  9.572922384144454e-01,  5.171764118207254e-03,  
   -9.471376718841760e-01,  2.927695425907414e-01,  2.000641714794302e-02,  
   -9.874787306662429e-01, -9.621211118728035e-01,  3.377128849473962e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr23 ( )

/******************************************************************************/
/*
  Purpose:

    SMR23 returns the SMR rule of degree 23.

  Discussion:

    DEGREE: 23
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 96
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR23[3*96], the requested rule.
*/
{
  const int degree = 23;
  int order;
  double xw[3*96] = {
    1.853314713323298e-01, -1.194182324265387e-02,  6.529202325372914e-02,  
    1.659642315868930e-01,  3.367719887764350e-01,  6.231767492170222e-02,  
    9.876738163488666e-02,  8.306969615801286e-01,  6.201416548818468e-02,  
    8.869002322225777e-02,  9.854102218186098e-01,  1.324109920098785e-02,  
    3.982734759789451e-01,  1.335875115514376e-01,  6.923888037215149e-02,  
    2.307675985221515e-01,  5.659053189940804e-01,  7.857529731333650e-02,  
    4.154938603680680e-01,  7.488761930933899e-01,  6.583136220575310e-02,  
    3.258331163946451e-01,  9.405377066569092e-01,  3.516290651110937e-02,  
    4.718068156165912e-01,  3.742733716935872e-01,  7.391201672123172e-02,  
    6.214843667854110e-01,  5.757611415753823e-01,  6.633209783965152e-02,  
    6.111965358277813e-01,  8.835074910197936e-01,  4.096440841363334e-02,  
    5.425835924085424e-01,  9.934011708856250e-01,  9.791218112671066e-03,  
    6.454787887214178e-01,  7.290903205395782e-02,  7.527535021842932e-02,  
    7.663883133711373e-01,  3.281528217933192e-01,  6.564383307544155e-02,  
    7.763362157153701e-01,  7.457829318163177e-01,  4.507790595281267e-02,  
    7.869974305642068e-01,  9.638578123979478e-01,  1.814838304609862e-02,  
    9.212736070974256e-01,  1.716486762023320e-01,  4.117445213281692e-02,  
    8.886542125222323e-01,  5.442346685704154e-01,  4.215575969073930e-02,  
    9.057049801164405e-01,  8.685411402721253e-01,  2.274825956928111e-02,  
    9.457512810375365e-01,  9.860275528096041e-01,  5.078778817313888e-03,  
    9.878935301664215e-01,  7.759170798217239e-02,  4.765144456210194e-03,  
    9.836661500284433e-01,  4.041056452269987e-01,  1.596460029217852e-02,  
    9.734962304125074e-01,  7.140118690494257e-01,  1.705297096357996e-02,  
    9.936548069316368e-01,  9.210767826681668e-01,  4.241411430955866e-03,  
    1.194182324265387e-02,  1.853314713323298e-01,  6.529202325372914e-02,  
   -3.367719887764350e-01,  1.659642315868930e-01,  6.231767492170222e-02,  
   -8.306969615801286e-01,  9.876738163488666e-02,  6.201416548818468e-02,  
   -9.854102218186098e-01,  8.869002322225777e-02,  1.324109920098785e-02,  
   -1.335875115514376e-01,  3.982734759789451e-01,  6.923888037215149e-02,  
   -5.659053189940804e-01,  2.307675985221515e-01,  7.857529731333650e-02,  
   -7.488761930933899e-01,  4.154938603680680e-01,  6.583136220575310e-02,  
   -9.405377066569092e-01,  3.258331163946451e-01,  3.516290651110937e-02,  
   -3.742733716935872e-01,  4.718068156165912e-01,  7.391201672123172e-02,  
   -5.757611415753823e-01,  6.214843667854110e-01,  6.633209783965152e-02,  
   -8.835074910197936e-01,  6.111965358277813e-01,  4.096440841363334e-02,  
   -9.934011708856250e-01,  5.425835924085424e-01,  9.791218112671066e-03,  
   -7.290903205395782e-02,  6.454787887214178e-01,  7.527535021842932e-02,  
   -3.281528217933192e-01,  7.663883133711373e-01,  6.564383307544155e-02,  
   -7.457829318163177e-01,  7.763362157153701e-01,  4.507790595281267e-02,  
   -9.638578123979478e-01,  7.869974305642068e-01,  1.814838304609862e-02,  
   -1.716486762023320e-01,  9.212736070974256e-01,  4.117445213281692e-02,  
   -5.442346685704154e-01,  8.886542125222323e-01,  4.215575969073930e-02,  
   -8.685411402721253e-01,  9.057049801164405e-01,  2.274825956928111e-02,  
   -9.860275528096041e-01,  9.457512810375365e-01,  5.078778817313888e-03,  
   -7.759170798217239e-02,  9.878935301664215e-01,  4.765144456210194e-03,  
   -4.041056452269987e-01,  9.836661500284433e-01,  1.596460029217852e-02,  
   -7.140118690494257e-01,  9.734962304125074e-01,  1.705297096357996e-02,  
   -9.210767826681668e-01,  9.936548069316368e-01,  4.241411430955866e-03,  
   -1.853314713323298e-01,  1.194182324265387e-02,  6.529202325372914e-02,  
   -1.659642315868930e-01, -3.367719887764350e-01,  6.231767492170222e-02,  
   -9.876738163488666e-02, -8.306969615801286e-01,  6.201416548818468e-02,  
   -8.869002322225777e-02, -9.854102218186098e-01,  1.324109920098785e-02,  
   -3.982734759789451e-01, -1.335875115514376e-01,  6.923888037215149e-02,  
   -2.307675985221515e-01, -5.659053189940804e-01,  7.857529731333650e-02,  
   -4.154938603680680e-01, -7.488761930933899e-01,  6.583136220575310e-02,  
   -3.258331163946451e-01, -9.405377066569092e-01,  3.516290651110937e-02,  
   -4.718068156165912e-01, -3.742733716935872e-01,  7.391201672123172e-02,  
   -6.214843667854110e-01, -5.757611415753823e-01,  6.633209783965152e-02,  
   -6.111965358277813e-01, -8.835074910197936e-01,  4.096440841363334e-02,  
   -5.425835924085424e-01, -9.934011708856250e-01,  9.791218112671066e-03,  
   -6.454787887214178e-01, -7.290903205395782e-02,  7.527535021842932e-02,  
   -7.663883133711373e-01, -3.281528217933192e-01,  6.564383307544155e-02,  
   -7.763362157153701e-01, -7.457829318163177e-01,  4.507790595281267e-02,  
   -7.869974305642068e-01, -9.638578123979478e-01,  1.814838304609862e-02,  
   -9.212736070974256e-01, -1.716486762023320e-01,  4.117445213281692e-02,  
   -8.886542125222323e-01, -5.442346685704154e-01,  4.215575969073930e-02,  
   -9.057049801164405e-01, -8.685411402721253e-01,  2.274825956928111e-02,  
   -9.457512810375365e-01, -9.860275528096041e-01,  5.078778817313888e-03,  
   -9.878935301664215e-01, -7.759170798217239e-02,  4.765144456210194e-03,  
   -9.836661500284433e-01, -4.041056452269987e-01,  1.596460029217852e-02,  
   -9.734962304125074e-01, -7.140118690494257e-01,  1.705297096357996e-02,  
   -9.936548069316368e-01, -9.210767826681668e-01,  4.241411430955866e-03,  
   -1.194182324265387e-02, -1.853314713323298e-01,  6.529202325372914e-02,  
    3.367719887764350e-01, -1.659642315868930e-01,  6.231767492170222e-02,  
    8.306969615801286e-01, -9.876738163488666e-02,  6.201416548818468e-02,  
    9.854102218186098e-01, -8.869002322225777e-02,  1.324109920098785e-02,  
    1.335875115514376e-01, -3.982734759789451e-01,  6.923888037215149e-02,  
    5.659053189940804e-01, -2.307675985221515e-01,  7.857529731333650e-02,  
    7.488761930933899e-01, -4.154938603680680e-01,  6.583136220575310e-02,  
    9.405377066569092e-01, -3.258331163946451e-01,  3.516290651110937e-02,  
    3.742733716935872e-01, -4.718068156165912e-01,  7.391201672123172e-02,  
    5.757611415753823e-01, -6.214843667854110e-01,  6.633209783965152e-02,  
    8.835074910197936e-01, -6.111965358277813e-01,  4.096440841363334e-02,  
    9.934011708856250e-01, -5.425835924085424e-01,  9.791218112671066e-03,  
    7.290903205395782e-02, -6.454787887214178e-01,  7.527535021842932e-02,  
    3.281528217933192e-01, -7.663883133711373e-01,  6.564383307544155e-02,  
    7.457829318163177e-01, -7.763362157153701e-01,  4.507790595281267e-02,  
    9.638578123979478e-01, -7.869974305642068e-01,  1.814838304609862e-02,  
    1.716486762023320e-01, -9.212736070974256e-01,  4.117445213281692e-02,  
    5.442346685704154e-01, -8.886542125222323e-01,  4.215575969073930e-02,  
    8.685411402721253e-01, -9.057049801164405e-01,  2.274825956928111e-02,  
    9.860275528096041e-01, -9.457512810375365e-01,  5.078778817313888e-03,  
    7.759170798217239e-02, -9.878935301664215e-01,  4.765144456210194e-03,  
    4.041056452269987e-01, -9.836661500284433e-01,  1.596460029217852e-02,  
    7.140118690494257e-01, -9.734962304125074e-01,  1.705297096357996e-02,  
    9.210767826681668e-01, -9.936548069316368e-01,  4.241411430955866e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr24 ( )

/******************************************************************************/
/*
  Purpose:

    SMR24 returns the SMR rule of degree 24.

  Discussion:

    DEGREE: 24
    POINTS CARDINALITY: 109
    NORM INF MOMS. RESIDUAL: 1.33227e-15
    SUM NEGATIVE WEIGHTS: 0.00000e+00, 

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR24[3*109], the requested rule.
*/
{
  const int degree = 24;
  int order;
  double xw[3*109] = {
   -9.947552488434938e-01, -4.385704490896414e-01,  2.698557791124145e-03,  
   -9.931097629772323e-01,  6.703739358435329e-01,  7.377682774083533e-03,  
   -9.926803856666530e-01,  2.074620875386726e-01,  6.953676686934647e-03,  
   -9.906389564778285e-01,  9.389787594673664e-01,  4.005676169355294e-03,  
   -9.853982980908041e-01, -1.546975310338203e-01,  1.391680440670080e-02,  
   -9.837508975466611e-01, -8.419003469340943e-01,  8.844680842740435e-03,  
   -9.834972384053117e-01, -5.844467591604228e-01,  1.101492580337329e-02,  
   -9.818922098458703e-01, -9.808906804560406e-01,  2.833762301624789e-03,  
   -9.737197710731226e-01,  3.846778957131831e-01,  1.346113092355880e-02,  
   -9.500074961120746e-01,  8.209864656561424e-01,  1.735987104490214e-02,  
   -9.403701834437002e-01,  9.898046509843106e-01,  4.134638994139726e-03,  
   -9.322891009559756e-01,  6.891056205665078e-02,  3.385109951711678e-02,  
   -9.291432442434125e-01, -3.649292941055270e-01,  3.313278955371516e-02,  
   -9.278770514198088e-01,  5.372507215773373e-01,  2.595775803019849e-02,  
   -9.160984294365914e-01, -7.088454133225529e-01,  2.740072723324332e-02,  
   -9.158788280467461e-01, -9.354605631847065e-01,  1.341647825529986e-02,  
   -8.614049341981235e-01,  9.223186488292008e-01,  1.828556090710842e-02,  
   -8.411326781777169e-01,  2.986796133696130e-01,  5.109735452042367e-02,  
   -8.399585109946057e-01,  6.941827653602577e-01,  3.578648643426428e-02,  
   -8.284250818876616e-01, -1.413597089673544e-01,  5.450666609336831e-02,  
   -8.258893393997301e-01, -9.946839974593770e-01,  5.524951523211650e-03,  
   -8.061244501112171e-01, -5.249750016790736e-01,  5.069979449576008e-02,  
   -8.039912747312149e-01, -8.393703760802331e-01,  3.118857585337858e-02,  
   -7.503800600330690e-01,  9.808995135027622e-01,  1.020614373666720e-02,  
   -7.159580396066608e-01,  8.204005009530653e-01,  3.345975676433573e-02,  
   -7.066954614920985e-01,  5.015305614605768e-01,  6.001952691278750e-02,  
   -6.885485793465114e-01,  9.202328849593100e-02,  7.346166114914886e-02,  
   -6.800088501791149e-01, -9.443640836874199e-01,  2.298808927262541e-02,  
   -6.560939841533527e-01, -3.083819563661853e-01,  7.136431171052350e-02,  
   -6.549319709970016e-01, -6.928080924969605e-01,  5.352097766179938e-02,  
   -5.986758659840633e-01,  9.036887631193311e-01,  2.206238875433044e-02,  
   -5.440986421726908e-01,  6.690288689480005e-01,  5.524621622310746e-02,  
   -5.421013331274553e-01,  9.805973671548335e-01,  1.050046021811538e-02,  
   -5.117472121011815e-01,  3.140452735180922e-01,  8.289952810298720e-02,  
   -5.059194733599800e-01, -9.837457937119135e-01,  1.096035229919467e-02,  
   -4.980272781651189e-01, -8.405454275729934e-01,  4.487909208174960e-02,  
   -4.827305043646576e-01, -4.980524078016305e-01,  7.003741329201849e-02,  
   -4.657032616378755e-01, -8.311620500718582e-02,  9.203159768871901e-02,  
   -3.984335431880944e-01,  7.823560336425450e-01,  3.533735180399633e-02,  
   -3.812251842054403e-01,  9.211692018557595e-01,  2.479377740140328e-02,  
   -3.254324649968378e-01, -6.106485217368141e-01,  1.987123465724002e-02,  
   -3.081376572739211e-01,  5.152565145304252e-01,  8.148061878192561e-02,  
   -3.061609471247951e-01, -9.953099499439115e-01,  4.421627578115842e-03,  
   -3.040806099754977e-01, -6.945205873058414e-01,  4.874084869821138e-02,  
   -3.040627168926376e-01, -9.238254614973810e-01,  2.731221830374910e-02,  
   -2.730267547433428e-01,  9.914365779967292e-01,  9.183887978612177e-03,  
   -2.548424890251378e-01, -3.019158326395579e-01,  9.514384875199645e-02,  
   -2.519554856003144e-01,  1.492385558662303e-01,  1.000641506538448e-01,  
   -1.931995209634114e-01,  8.232643617111496e-01,  3.769059900817138e-02,  
   -1.885349353760669e-01, -8.893470388562837e-01,  8.285027518755494e-03,  
   -1.018544959716391e-01, -7.832201508773523e-01,  4.767805838303123e-02,  
   -9.655685106805004e-02,  6.703558020663598e-01,  5.541671674358566e-02,  
   -7.901309787694769e-02, -9.687392227645953e-01,  1.819078482187320e-02,  
   -7.169337674372403e-02,  9.452615682987324e-01,  2.860240343608491e-02,  
   -4.349902330261272e-02, -5.144306594431935e-01,  8.777502677071561e-02,  
   -2.884848343031785e-02, -7.515483993225638e-02,  1.033082821984657e-01,  
   -1.950518268267537e-02,  3.687032706515938e-01,  9.771287132446460e-02,  
    1.000713405257931e-01, -8.778592595775899e-01,  4.025365288851937e-02,  
    1.288386576225213e-01,  8.499166400570952e-01,  4.727125786790465e-02,  
    1.307155265497598e-01, -9.938241813833318e-01,  7.039833852159185e-03,  
    1.308425147211156e-01,  6.526807421421726e-01,  4.979273601404909e-02,  
    1.451164406166477e-01,  9.905591807186089e-01,  1.078258330904423e-02,  
    1.853995153478054e-01, -3.035646033025806e-01,  9.690391758696711e-02,  
    1.943247761163270e-01, -6.769527305130935e-01,  7.109638809439672e-02,  
    2.052879132552834e-01,  1.494567879060908e-01,  1.010903998636895e-01,  
    2.768585369952569e-01,  5.067311062472540e-01,  6.479712852470575e-02,  
    3.149836876173980e-01, -9.498509878332206e-01,  2.600605597250065e-02,  
    3.466439434503832e-01,  9.410184803711036e-01,  2.912818672968244e-02,  
    3.903088921667896e-01,  4.250693093572162e-01,  2.571049499832495e-02,  
    3.993865541451484e-01,  7.683264787575288e-01,  5.493699586057709e-02,  
    4.086593369430472e-01, -4.969944946335217e-01,  7.910634640474691e-02,  
    4.120045473805335e-01, -8.379854233451292e-02,  9.482614431233395e-02,  
    4.170298041496714e-01, -8.110827678737819e-01,  5.059001095427527e-02,  
    4.991948804043371e-01,  2.844383580006540e-01,  7.600131857765238e-02,  
    5.215718300412919e-01, -9.911476542754794e-01,  8.938791600642888e-03,  
    5.358795456370800e-01,  9.892706596240752e-01,  9.652257973711614e-03,  
    5.675663650098263e-01,  6.269930547839709e-01,  5.565333636824790e-02,  
    6.083113501735691e-01, -6.671573460757463e-01,  5.724631842495273e-02,  
    6.091213803480886e-01, -3.002786277521432e-01,  7.620974249495195e-02,  
    6.098130539524327e-01,  8.880641734983817e-01,  3.607781947134865e-02,  
    6.133229089892412e-01, -9.115716813284614e-01,  2.976045072649638e-02,  
    6.644692975845461e-01,  7.278284636752541e-02,  7.402473800633137e-02,  
    7.058360022640749e-01,  4.736368348307747e-01,  5.128474162165504e-02,  
    7.603978094655672e-01,  7.687530787837937e-01,  3.987086504850027e-02,  
    7.680081930648918e-01,  9.719796486153569e-01,  1.425802911781755e-02,  
    7.730566152310493e-01, -8.076103665001979e-01,  3.513944563783513e-02,  
    7.740524973445363e-01, -5.000787609526253e-01,  5.331933422231531e-02,  
    7.765031539359070e-01, -9.744702466310179e-01,  1.298770336406751e-02,  
    8.105891537849745e-01, -1.496106096240346e-01,  5.659879783131575e-02,  
    8.136030860267544e-01,  2.997934729123835e-01,  4.597071032159282e-02,  
    8.738296548638522e-01,  6.252207344858673e-01,  3.235229209061567e-02,  
    8.820767009721266e-01,  8.997350185706089e-01,  1.969080467560540e-02,  
    8.968725800328660e-01, -6.749357059674395e-01,  3.049246549718226e-02,  
    9.008567820439595e-01, -9.076509501580650e-01,  1.724041843190777e-02,  
    9.036351991894711e-01,  1.066673951092828e-01,  3.553262749083069e-02,  
    9.194113498715898e-01, -3.652426921938732e-01,  3.438229944741761e-02,  
    9.235901436599459e-01,  4.967015317618840e-01,  1.373744804296171e-02,  
    9.328830195971040e-01, -9.941380940892665e-01,  2.989382978667606e-03,  
    9.404372628037821e-01,  9.889603686778536e-01,  4.443564861581591e-03,  
    9.607926125333919e-01,  7.879019305115507e-01,  1.649904214759328e-02,  
    9.627435059550357e-01,  3.759293384523862e-01,  1.893234461167443e-02,  
    9.661246051400586e-01, -9.321465960805159e-02,  2.021199306716822e-02,  
    9.772105063681134e-01, -8.054188902050837e-01,  1.143950510739337e-02,  
    9.818083790572272e-01, -5.613562549296841e-01,  1.303588980687769e-02,  
    9.873606864519788e-01, -9.558632391723191e-01,  3.650162385277064e-03,  
    9.909481727417117e-01,  9.350098107984304e-01,  4.199764168210779e-03,  
    9.933228865506706e-01,  1.717028973685849e-01,  7.977198513429708e-03,  
    9.934734927244968e-01,  6.113673375988821e-01,  7.151800672626832e-03,  
    9.958206097496789e-01, -2.883979781434184e-01,  5.617961121686336e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr25 ( )

/******************************************************************************/
/*
  Purpose:

    SMR25 returns the SMR rule of degree 25.

  Discussion:

    DEGREE: 25
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 113
    NORM INF MOMS. RESIDUAL: 2.04121e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR25[3*113], the requested rule.
*/
{
  const int degree = 25;
  int order;
  double xw[3*113] = {
    2.408979561244244e-01,  4.202921149345177e-01,  8.649643596540968e-02,  
    2.718022358106373e-01,  7.547569098063632e-01,  5.930450471454697e-02,  
    2.949651173549945e-01,  9.557139743958390e-01,  2.492523876506716e-02,  
    4.390520493777193e-01,  2.026918805813806e-01,  8.650651080976479e-02,  
    4.662064901266157e-01,  5.942245210433184e-01,  6.800866187330593e-02,  
    4.830786617878046e-01,  8.732633185547312e-01,  3.820005521117373e-02,  
    5.045376712354956e-01,  9.940169417092007e-01,  7.120126112016729e-03,  
    7.757488163218268e-01,  1.779409708250335e-01,  5.827884791218824e-02,  
    6.369947479572929e-01,  4.005073391747475e-01,  6.761649569671979e-02,  
    6.535675504807226e-01,  7.533634302760710e-01,  4.601021918794469e-02,  
    6.595342990537197e-01,  9.508745400630684e-01,  1.723971223901597e-02,  
    7.906371918772621e-01,  5.934656821653986e-01,  4.568246307970081e-02,  
    8.055336482199160e-01,  8.773080252379840e-01,  2.484701585804588e-02,  
    7.535373835857363e-01,  9.795331551151395e-01,  4.313716122504384e-03,  
    9.564646592216111e-01,  1.571205964662031e-01,  2.535428637556193e-02,  
    8.902743405153437e-01,  3.914673487680078e-01,  3.753743912008318e-02,  
    9.033639329394400e-01,  7.595177874407598e-01,  2.457091299936516e-02,  
    9.372983112686489e-01,  9.385069580562527e-01,  1.007243031836228e-02,  
    8.636461603424476e-01,  9.896801193034730e-01,  4.961458044877222e-03,  
    9.938360564492993e-01,  3.750300609078687e-01,  7.598805738926257e-03,  
    9.619543373713801e-01,  5.836819379362060e-01,  1.776328589308987e-02,  
    9.918091540820021e-01,  7.176122922535305e-01,  3.747585881528770e-03,  
    9.847916123916505e-01,  8.571417379883992e-01,  6.289982457940641e-03,  
    9.885652833157735e-01,  9.860593798999778e-01,  1.697350354991505e-03,  
    9.233777086225921e-03,  2.208671709154587e-01,  9.688701249182402e-02,  
    3.041113022131709e-02,  6.137415273447637e-01,  7.643513771616485e-02,  
    6.708941821053316e-02,  8.786573477860689e-01,  4.373962481400533e-02,  
    7.276240742442623e-02,  9.928846185998859e-01,  8.791036677341798e-03,  
   -4.202921149345177e-01,  2.408979561244244e-01,  8.649643596540968e-02,  
   -7.547569098063632e-01,  2.718022358106373e-01,  5.930450471454697e-02,  
   -9.557139743958390e-01,  2.949651173549945e-01,  2.492523876506716e-02,  
   -2.026918805813806e-01,  4.390520493777193e-01,  8.650651080976479e-02,  
   -5.942245210433184e-01,  4.662064901266157e-01,  6.800866187330593e-02,  
   -8.732633185547312e-01,  4.830786617878046e-01,  3.820005521117373e-02,  
   -9.940169417092007e-01,  5.045376712354956e-01,  7.120126112016729e-03,  
   -1.779409708250335e-01,  7.757488163218268e-01,  5.827884791218824e-02,  
   -4.005073391747475e-01,  6.369947479572929e-01,  6.761649569671979e-02,  
   -7.533634302760710e-01,  6.535675504807226e-01,  4.601021918794469e-02,  
   -9.508745400630684e-01,  6.595342990537197e-01,  1.723971223901597e-02,  
   -5.934656821653986e-01,  7.906371918772621e-01,  4.568246307970081e-02,  
   -8.773080252379840e-01,  8.055336482199160e-01,  2.484701585804588e-02,  
   -9.795331551151395e-01,  7.535373835857363e-01,  4.313716122504384e-03,  
   -1.571205964662031e-01,  9.564646592216111e-01,  2.535428637556193e-02,  
   -3.914673487680078e-01,  8.902743405153437e-01,  3.753743912008318e-02,  
   -7.595177874407598e-01,  9.033639329394400e-01,  2.457091299936516e-02,  
   -9.385069580562527e-01,  9.372983112686489e-01,  1.007243031836228e-02,  
   -9.896801193034730e-01,  8.636461603424476e-01,  4.961458044877222e-03,  
   -3.750300609078687e-01,  9.938360564492993e-01,  7.598805738926257e-03,  
   -5.836819379362060e-01,  9.619543373713801e-01,  1.776328589308987e-02,  
   -7.176122922535305e-01,  9.918091540820021e-01,  3.747585881528770e-03,  
   -8.571417379883992e-01,  9.847916123916505e-01,  6.289982457940641e-03,  
   -9.860593798999778e-01,  9.885652833157735e-01,  1.697350354991505e-03,  
   -2.208671709154587e-01,  9.233777086225921e-03,  9.688701249182402e-02,  
   -6.137415273447637e-01,  3.041113022131709e-02,  7.643513771616485e-02,  
   -8.786573477860689e-01,  6.708941821053316e-02,  4.373962481400533e-02,  
   -9.928846185998859e-01,  7.276240742442623e-02,  8.791036677341798e-03,  
   -2.408979561244244e-01, -4.202921149345177e-01,  8.649643596540968e-02,  
   -2.718022358106373e-01, -7.547569098063632e-01,  5.930450471454697e-02,  
   -2.949651173549945e-01, -9.557139743958390e-01,  2.492523876506716e-02,  
   -4.390520493777193e-01, -2.026918805813806e-01,  8.650651080976479e-02,  
   -4.662064901266157e-01, -5.942245210433184e-01,  6.800866187330593e-02,  
   -4.830786617878046e-01, -8.732633185547312e-01,  3.820005521117373e-02,  
   -5.045376712354956e-01, -9.940169417092007e-01,  7.120126112016729e-03,  
   -7.757488163218268e-01, -1.779409708250335e-01,  5.827884791218824e-02,  
   -6.369947479572929e-01, -4.005073391747475e-01,  6.761649569671979e-02,  
   -6.535675504807226e-01, -7.533634302760710e-01,  4.601021918794469e-02,  
   -6.595342990537197e-01, -9.508745400630684e-01,  1.723971223901597e-02,  
   -7.906371918772621e-01, -5.934656821653986e-01,  4.568246307970081e-02,  
   -8.055336482199160e-01, -8.773080252379840e-01,  2.484701585804588e-02,  
   -7.535373835857363e-01, -9.795331551151395e-01,  4.313716122504384e-03,  
   -9.564646592216111e-01, -1.571205964662031e-01,  2.535428637556193e-02,  
   -8.902743405153437e-01, -3.914673487680078e-01,  3.753743912008318e-02,  
   -9.033639329394400e-01, -7.595177874407598e-01,  2.457091299936516e-02,  
   -9.372983112686489e-01, -9.385069580562527e-01,  1.007243031836228e-02,  
   -8.636461603424476e-01, -9.896801193034730e-01,  4.961458044877222e-03,  
   -9.938360564492993e-01, -3.750300609078687e-01,  7.598805738926257e-03,  
   -9.619543373713801e-01, -5.836819379362060e-01,  1.776328589308987e-02,  
   -9.918091540820021e-01, -7.176122922535305e-01,  3.747585881528770e-03,  
   -9.847916123916505e-01, -8.571417379883992e-01,  6.289982457940641e-03,  
   -9.885652833157735e-01, -9.860593798999778e-01,  1.697350354991505e-03,  
   -9.233777086225921e-03, -2.208671709154587e-01,  9.688701249182402e-02,  
   -3.041113022131709e-02, -6.137415273447637e-01,  7.643513771616485e-02,  
   -6.708941821053316e-02, -8.786573477860689e-01,  4.373962481400533e-02,  
   -7.276240742442623e-02, -9.928846185998859e-01,  8.791036677341798e-03,  
    4.202921149345177e-01, -2.408979561244244e-01,  8.649643596540968e-02,  
    7.547569098063632e-01, -2.718022358106373e-01,  5.930450471454697e-02,  
    9.557139743958390e-01, -2.949651173549945e-01,  2.492523876506716e-02,  
    2.026918805813806e-01, -4.390520493777193e-01,  8.650651080976479e-02,  
    5.942245210433184e-01, -4.662064901266157e-01,  6.800866187330593e-02,  
    8.732633185547312e-01, -4.830786617878046e-01,  3.820005521117373e-02,  
    9.940169417092007e-01, -5.045376712354956e-01,  7.120126112016729e-03,  
    1.779409708250335e-01, -7.757488163218268e-01,  5.827884791218824e-02,  
    4.005073391747475e-01, -6.369947479572929e-01,  6.761649569671979e-02,  
    7.533634302760710e-01, -6.535675504807226e-01,  4.601021918794469e-02,  
    9.508745400630684e-01, -6.595342990537197e-01,  1.723971223901597e-02,  
    5.934656821653986e-01, -7.906371918772621e-01,  4.568246307970081e-02,  
    8.773080252379840e-01, -8.055336482199160e-01,  2.484701585804588e-02,  
    9.795331551151395e-01, -7.535373835857363e-01,  4.313716122504384e-03,  
    1.571205964662031e-01, -9.564646592216111e-01,  2.535428637556193e-02,  
    3.914673487680078e-01, -8.902743405153437e-01,  3.753743912008318e-02,  
    7.595177874407598e-01, -9.033639329394400e-01,  2.457091299936516e-02,  
    9.385069580562527e-01, -9.372983112686489e-01,  1.007243031836228e-02,  
    9.896801193034730e-01, -8.636461603424476e-01,  4.961458044877222e-03,  
    3.750300609078687e-01, -9.938360564492993e-01,  7.598805738926257e-03,  
    5.836819379362060e-01, -9.619543373713801e-01,  1.776328589308987e-02,  
    7.176122922535305e-01, -9.918091540820021e-01,  3.747585881528770e-03,  
    8.571417379883992e-01, -9.847916123916505e-01,  6.289982457940641e-03,  
    9.860593798999778e-01, -9.885652833157735e-01,  1.697350354991505e-03,  
    2.208671709154587e-01, -9.233777086225921e-03,  9.688701249182402e-02,  
    6.137415273447637e-01, -3.041113022131709e-02,  7.643513771616485e-02,  
    8.786573477860689e-01, -6.708941821053316e-02,  4.373962481400533e-02,  
    9.928846185998859e-01, -7.276240742442623e-02,  8.791036677341798e-03,  
    0.000000000000000e+00,  0.000000000000000e+00,  1.459027412974250e-05 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr26 ( )

/******************************************************************************/
/*
  Purpose:

    SMR26 returns the SMR rule of degree 26.

  Discussion:

    DEGREE: 26
    POINTS CARDINALITY: 127
    NORM INF MOMS. RESIDUAL: 2.72785e-16
    SUM NEGATIVE WEIGHTS: 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR26[3*127], the requested rule.
*/
{
  const int degree = 26;
  int order;
  double xw[3*127] = {
   -9.954149432053586e-01, -8.467950645561364e-01,  3.684914976298696e-03,  
   -9.951846316463983e-01,  4.962239287417011e-01,  5.769468055434405e-03,  
   -9.946910061010343e-01, -2.554039039018801e-01,  5.732088976456913e-03,  
   -9.919373759022915e-01,  1.036499274958413e-01,  7.852213957780449e-03,  
   -9.906494815143384e-01,  8.649856906058798e-01,  5.121508648969548e-03,  
   -9.896255204784331e-01, -5.367353086290219e-01,  7.653897829024368e-03,  
   -9.883067004873612e-01,  9.892991458592666e-01,  1.353489163893612e-03,  
   -9.871269120799574e-01, -9.856243972746432e-01,  1.601609521006031e-03,  
   -9.688175505639893e-01,  6.876579842845731e-01,  1.481263227905701e-02,  
   -9.623107235333284e-01, -7.113315046485157e-01,  1.467102553035195e-02,  
   -9.594699050132816e-01,  3.158494085062999e-01,  2.066592783625548e-02,  
   -9.556340329654068e-01, -8.022603946161568e-02,  2.057995991913653e-02,  
   -9.551530447389018e-01, -9.306484497591768e-01,  8.053489843056318e-03,  
   -9.424969861668707e-01,  9.469477514122181e-01,  8.919732609121192e-03,  
   -9.420253084162512e-01, -3.677325230608104e-01,  2.273184282144351e-02,  
   -8.987320916561362e-01,  8.122593786261580e-01,  2.096666902511633e-02,  
   -8.958607050863848e-01,  5.192884077130218e-01,  3.251925598993868e-02,  
   -8.896472695790547e-01, -8.337317899908271e-01,  1.954814636274032e-02,  
   -8.855870754573025e-01, -5.696730697875062e-01,  2.769715991416717e-02,  
   -8.851975534775430e-01, -9.861706664088894e-01,  5.503686420382153e-03,  
   -8.824869023397663e-01,  1.313680696309325e-01,  3.733200212029421e-02,  
   -8.536298178066737e-01,  9.912818948096804e-01,  5.124303871062341e-03,  
   -8.470126989959706e-01, -1.751543370107349e-01,  3.903031857246672e-02,  
   -7.935791896852771e-01,  9.085946391105678e-01,  2.070806621666239e-02,  
   -7.916311495402206e-01, -4.081621366651574e-01,  3.398634661189039e-02,  
   -7.861405619098327e-01, -9.316104713801209e-01,  1.770750778349851e-02,  
   -7.844763488387392e-01,  6.770066879653323e-01,  3.909373917813275e-02,  
   -7.812595515556915e-01, -7.208792112743798e-01,  3.206208479847047e-02,  
   -7.750802181046658e-01,  3.380282238952111e-01,  5.215291009390418e-02,  
   -7.135764412117650e-01,  1.416925255648272e-02,  5.853608843151761e-02,  
   -6.828943144695906e-01, -9.907384181599451e-01,  6.548608319199373e-03,  
   -6.658796622951563e-01, -5.739095648918578e-01,  4.128887088242855e-02,  
   -6.601473080396085e-01,  9.720448999511093e-01,  1.432353654588031e-02,  
   -6.579506062388087e-01, -2.844859212870189e-01,  4.720582197472361e-02,  
   -6.479646319399198e-01, -8.498157318331752e-01,  3.083452896969299e-02,  
   -6.397790086368259e-01,  8.094061184323337e-01,  3.847861173239278e-02,  
   -6.249362696077773e-01,  5.216217958951045e-01,  5.859572334726999e-02,  
   -5.576842250639873e-01,  2.121572188446747e-01,  6.977200243841351e-02,  
   -5.231225720726088e-01, -9.559709376266402e-01,  1.921032430496192e-02,  
   -5.108013542724835e-01, -7.271185268803120e-01,  4.267920181533953e-02,  
   -4.958822443640539e-01, -1.352950226786132e-01,  6.727743365041994e-02,  
   -4.903913278322852e-01, -4.632593578701779e-01,  5.398148692009514e-02,  
   -4.716786109784886e-01,  9.096410577420503e-01,  3.072280881059000e-02,  
   -4.571089728524948e-01,  9.962395125952335e-01,  5.314155662552198e-03,  
   -4.458359027750944e-01,  6.845878478236567e-01,  5.741502788464329e-02,  
   -3.761204219053791e-01,  4.027492188232445e-01,  7.244352535381400e-02,  
   -3.757270438769368e-01, -8.813300989750833e-01,  2.864804532479737e-02,  
   -3.233151458448575e-01, -9.924702614510548e-01,  8.376460295913149e-03,  
   -3.214177198641322e-01,  5.465196421581072e-02,  7.825743561587792e-02,  
   -3.079596913747666e-01, -6.299193766661012e-01,  5.253252015129221e-02,  
   -2.908499987046121e-01, -3.299468222568143e-01,  7.147473944911664e-02,  
   -2.711488527112555e-01, -8.141343465894294e-01,  2.066316039292166e-02,  
   -2.621892153300335e-01,  9.646535606685744e-01,  1.798911598012612e-02,  
   -2.481167506627375e-01,  8.186440564336724e-01,  4.859943151527142e-02,  
   -1.791342365314126e-01,  5.748981248381774e-01,  6.765610404074739e-02,  
   -1.437544578360581e-01, -9.443574522438600e-01,  2.652222430073281e-02,  
   -1.269743475931557e-01,  2.485350964764208e-01,  8.025561424009733e-02,  
   -1.038608843226707e-01, -1.432437001920102e-01,  8.120590842585292e-02,  
   -8.599298880188963e-02, -7.716801473651607e-01,  4.636752344758587e-02,  
   -8.395006281782805e-02,  9.871263594306682e-01,  6.816019493764937e-03,  
   -8.371947125930103e-02, -5.208589889223917e-01,  6.747918873878211e-02,  
   -1.697646807858736e-02,  9.086536018884021e-01,  3.387459722470887e-02,  
    1.833871143655595e-02,  7.209167099679072e-01,  5.538931339457189e-02,  
    5.565106332452326e-02, -9.889754197418217e-01,  1.032926366015326e-02,  
    7.395330091505788e-02,  4.297944936585988e-01,  7.320349165354346e-02,  
    9.468086843565157e-02,  5.388968586906774e-02,  8.305615985562806e-02,  
    1.024839179112914e-01, -8.834041600598230e-01,  3.604665584816725e-02,  
    1.074857184095777e-01, -3.452094910890526e-01,  7.761121952888624e-02,  
    1.267100636690128e-01,  9.932822811543160e-01,  6.369719109332116e-03,  
    1.534607276530462e-01, -6.678010821258034e-01,  6.156496555816345e-02,  
    2.264963086729804e-01,  8.230177907394701e-01,  3.968243470712332e-02,  
    2.459857454037700e-01,  9.492195041164657e-01,  2.026587105731689e-02,  
    2.573243932667488e-01,  5.876784265758089e-01,  5.691232110819883e-02,  
    2.787299946892420e-01, -8.902304358275253e-01,  6.562216924914964e-03,  
    2.938069266369140e-01,  2.464559758407173e-01,  7.639234774613035e-02,  
    3.031751644439591e-01, -1.498955147329062e-01,  7.988963989267751e-02,  
    3.057176124210453e-01, -9.663294098875163e-01,  1.951951397301675e-02,  
    3.429948224409587e-01, -5.036657844935868e-01,  6.771694379519085e-02,  
    3.468395902763219e-01, -8.106928028976478e-01,  3.534883558238713e-02,  
    4.294715053745923e-01,  6.972444059344115e-01,  4.114854443928950e-02,  
    4.504438324791868e-01,  9.813465089178893e-01,  1.218029689385577e-02,  
    4.587114216458100e-01,  8.757161022302909e-01,  2.985614815263661e-02,  
    4.705023240099300e-01,  4.248914232485290e-01,  6.029605985982594e-02,  
    4.730542337014057e-01, -7.226405060364207e-01,  3.424156109429213e-02,  
    4.939440770258761e-01,  5.066200964988320e-02,  7.407077493593092e-02,  
    5.203715415927748e-01, -3.207475729229982e-01,  6.635966202614821e-02,  
    5.257639785007799e-01, -9.977170958540899e-01,  5.409613333068085e-03,  
    5.313378826806301e-01, -9.170479942929537e-01,  2.720520257275587e-02,  
    6.022923045507941e-01, -5.994501280239045e-01,  4.830919014106976e-02,  
    6.204433975928566e-01,  7.641974295227819e-01,  3.404033553026726e-02,  
    6.209466711991216e-01,  5.494777927720476e-01,  3.791496686575289e-02,  
    6.466689879582136e-01,  9.360734505765457e-01,  1.996022042410962e-02,  
    6.621033564067602e-01,  2.496966370849072e-01,  6.144981322024960e-02,  
    6.789809770063248e-01, -8.212602557120876e-01,  3.236488593000712e-02,  
    6.796918717501631e-01, -1.331309975388194e-01,  5.802989349830448e-02,  
    6.812502176754324e-01,  9.989521401044065e-01,  3.579807875673121e-03,  
    7.266475436540760e-01, -9.675683591285036e-01,  1.484875678494199e-02,  
    7.440642616936161e-01, -4.322014403053586e-01,  4.959179569785551e-02,  
    7.592474840505909e-01,  6.228158958890423e-01,  3.061073682759719e-02,  
    7.651597556914833e-01,  8.643901077992759e-01,  1.594483883723016e-02,  
    7.967436284918096e-01, -6.999653717120403e-01,  3.119771973203415e-02,  
    8.082541716984714e-01,  5.125601506516623e-02,  4.548581114128645e-02,  
    8.109696076652307e-01,  4.100804853037188e-01,  4.010668645708275e-02,  
    8.230542108068375e-01,  7.992506945688510e-01,  1.707575997005541e-02,  
    8.345479402209883e-01,  9.699921801950655e-01,  1.084337625005019e-02,  
    8.501041529924387e-01, -8.905397308072454e-01,  2.036774520670110e-02,  
    8.672176401962716e-01, -2.462270148388496e-01,  4.072777874876069e-02,  
    8.815659674305341e-01, -9.912929489021226e-01,  4.286277790305716e-03,  
    8.884328863679039e-01, -5.630909797598750e-01,  2.665108708356420e-02,  
    9.036096198949736e-01,  6.861746191520888e-01,  2.199046962304617e-02,  
    9.087614696522919e-01,  2.107906691217087e-01,  2.933513900564612e-02,  
    9.227489940536037e-01,  5.030781079388300e-01,  1.792733716201453e-02,  
    9.244232598969854e-01,  8.987785855053358e-01,  1.334853657169367e-02,  
    9.371340023166588e-01, -7.719078499479927e-01,  1.828418899551716e-02,  
    9.533101385624838e-01, -5.893948233744529e-02,  2.493427565247522e-02,  
    9.546218786151554e-01,  9.901100266242597e-01,  2.997669288160739e-03,  
    9.549184254866305e-01, -9.479041510850161e-01,  7.333351181224950e-03,  
    9.584840095307160e-01, -4.174125864174710e-01,  1.906983600300858e-02,  
    9.754885144991214e-01,  3.570890018408184e-01,  1.283253988624834e-02,  
    9.784766134144718e-01,  7.916730646314184e-01,  9.664155967361797e-03,  
    9.878112520788415e-01,  5.881933255153872e-01,  8.019243932869360e-03,  
    9.878730421247439e-01, -6.289972589684678e-01,  8.869256817284361e-03,  
    9.914552412725798e-01, -8.617824090170690e-01,  4.432377107176309e-03,  
    9.929343270174540e-01, -9.907397806148996e-01,  9.278177812673883e-04,  
    9.937639919249919e-01,  9.433436502803851e-01,  2.685285882370453e-03,  
    9.939007341106521e-01,  1.320895377365522e-01,  6.886649912238812e-03,  
    9.952509862842531e-01, -2.550697642134186e-01,  6.463763906756026e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr27 ( )

/******************************************************************************/
/*
  Purpose:

    SMR27 returns the SMR rule of degree 27.

  Discussion:

    DEGREE: 27
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 132
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR27[3*132], the requested rule.
*/
{
  const int degree = 27;
  int order;
  double xw[3*132] = {
    1.886005021782720e-03,  5.828566738691298e-01,  6.979680609052895e-02,  
   -4.610090446080339e-03,  8.577929872633651e-01,  4.314966506560954e-02,  
   -4.155284083838179e-02,  9.888852930552997e-01,  1.072399831167234e-02,  
    2.067872320344404e-01, -6.296477862134920e-04,  8.488483237702206e-02,  
    2.082269167023509e-01,  4.038616639190317e-01,  7.727830308506041e-02,  
    2.052137161358173e-01,  7.394171390837959e-01,  5.621586102413551e-02,  
    1.807393256852824e-01,  9.496265565549702e-01,  2.535911050249288e-02,  
    3.322057475944939e-01,  9.960227386085063e-01,  5.272055511683970e-03,  
    4.045305824612024e-01,  2.059859741136477e-01,  7.726743635049893e-02,  
    4.025837874193514e-01,  5.870128510662224e-01,  6.365147357369046e-02,  
    3.850900136224434e-01,  8.707822203710608e-01,  3.854775533996937e-02,  
    4.961565809611688e-01,  9.726108752621352e-01,  1.194490281825224e-02,  
    7.337041416795138e-01,  2.082446806606209e-01,  5.658941671510189e-02,  
    5.809960989937741e-01,  4.073474789041275e-01,  6.376865298046723e-02,  
    5.677230574148288e-01,  7.531679569108030e-01,  4.625453544861270e-02,  
    6.209259660886249e-01,  9.313450399117541e-01,  1.820437285093996e-02,  
    7.222712946524428e-01,  9.926688332077881e-01,  5.756269356678867e-03,  
    8.472675519335334e-01,  4.202098689198475e-01,  4.046935707697283e-02,  
    7.235313755189597e-01,  6.009001598253331e-01,  4.695366916509310e-02,  
    7.436209196607865e-01,  8.532631127882830e-01,  2.452811191323398e-02,  
    8.078125449235396e-01,  8.865860238557206e-01,  3.599599560868793e-03,  
    8.496011789870433e-01,  9.584740402687207e-01,  1.136717702495919e-02,  
    9.873993632652779e-01,  3.857565023254501e-01,  9.087958640367919e-03,  
    9.407918538992979e-01,  5.806290275537873e-01,  2.155259200865792e-02,  
    8.583622893662932e-01,  7.355260155277167e-01,  2.723142317719206e-02,  
    9.417112190155333e-01,  8.140933233486173e-01,  6.586312510744677e-03,  
    9.293007271718974e-01,  8.976314904285845e-01,  9.170625679716800e-03,  
    9.365522911144204e-01,  2.247649048332172e-01,  2.753902574626484e-02,  
    9.913001320610028e-01,  5.146910772747944e-01,  2.062938898431044e-03,  
    9.892062993684332e-01,  7.177306340863354e-01,  6.213455600316710e-03,  
    9.825794696006162e-01,  8.526916976863245e-01,  3.542165144107640e-03,  
    9.899623983816039e-01,  9.559123039771233e-01,  2.789025209960568e-03,  
    9.454816892922301e-01,  9.931508332329141e-01,  2.641115240694518e-03,  
   -5.828566738691298e-01,  1.886005021782720e-03,  6.979680609052895e-02,  
   -8.577929872633651e-01, -4.610090446080339e-03,  4.314966506560954e-02,  
   -9.888852930552997e-01, -4.155284083838179e-02,  1.072399831167234e-02,  
    6.296477862134920e-04,  2.067872320344404e-01,  8.488483237702206e-02,  
   -4.038616639190317e-01,  2.082269167023509e-01,  7.727830308506041e-02,  
   -7.394171390837959e-01,  2.052137161358173e-01,  5.621586102413551e-02,  
   -9.496265565549702e-01,  1.807393256852824e-01,  2.535911050249288e-02,  
   -9.960227386085063e-01,  3.322057475944939e-01,  5.272055511683970e-03,    
   -2.059859741136477e-01,  4.045305824612024e-01,  7.726743635049893e-02,  
   -5.870128510662224e-01,  4.025837874193514e-01,  6.365147357369046e-02,  
   -8.707822203710608e-01,  3.850900136224434e-01,  3.854775533996937e-02,  
   -9.726108752621352e-01,  4.961565809611688e-01,  1.194490281825224e-02,  
   -2.082446806606209e-01,  7.337041416795138e-01,  5.658941671510189e-02,  
   -4.073474789041275e-01,  5.809960989937741e-01,  6.376865298046723e-02,  
   -7.531679569108030e-01,  5.677230574148288e-01,  4.625453544861270e-02,  
   -9.313450399117541e-01,  6.209259660886249e-01,  1.820437285093996e-02,  
   -9.926688332077881e-01,  7.222712946524428e-01,  5.756269356678867e-03,  
   -4.202098689198475e-01,  8.472675519335334e-01,  4.046935707697283e-02,  
   -6.009001598253331e-01,  7.235313755189597e-01,  4.695366916509310e-02,  
   -8.532631127882830e-01,  7.436209196607865e-01,  2.452811191323398e-02,  
   -8.865860238557206e-01,  8.078125449235396e-01,  3.599599560868793e-03,  
   -9.584740402687207e-01,  8.496011789870433e-01,  1.136717702495919e-02,  
   -3.857565023254501e-01,  9.873993632652779e-01,  9.087958640367919e-03,  
   -5.806290275537873e-01,  9.407918538992979e-01,  2.155259200865792e-02,  
   -7.355260155277167e-01,  8.583622893662932e-01,  2.723142317719206e-02,  
   -8.140933233486173e-01,  9.417112190155333e-01,  6.586312510744677e-03,  
   -8.976314904285845e-01,  9.293007271718974e-01,  9.170625679716800e-03,  
   -2.247649048332172e-01,  9.365522911144204e-01,  2.753902574626484e-02,  
   -5.146910772747944e-01,  9.913001320610028e-01,  2.062938898431044e-03,  
   -7.177306340863354e-01,  9.892062993684332e-01,  6.213455600316710e-03,  
   -8.526916976863245e-01,  9.825794696006162e-01,  3.542165144107640e-03,  
   -9.559123039771233e-01,  9.899623983816039e-01,  2.789025209960568e-03,  
   -9.931508332329141e-01,  9.454816892922301e-01,  2.641115240694518e-03,  
   -1.886005021782720e-03, -5.828566738691298e-01,  6.979680609052895e-02,  
    4.610090446080339e-03, -8.577929872633651e-01,  4.314966506560954e-02,  
    4.155284083838179e-02, -9.888852930552997e-01,  1.072399831167234e-02,  
   -2.067872320344404e-01,  6.296477862134920e-04,  8.488483237702206e-02,  
   -2.082269167023509e-01, -4.038616639190317e-01,  7.727830308506041e-02,  
   -2.052137161358173e-01, -7.394171390837959e-01,  5.621586102413551e-02,  
   -1.807393256852824e-01, -9.496265565549702e-01,  2.535911050249288e-02,  
   -3.322057475944939e-01, -9.960227386085063e-01,  5.272055511683970e-03,  
   -4.045305824612024e-01, -2.059859741136477e-01,  7.726743635049893e-02,  
   -4.025837874193514e-01, -5.870128510662224e-01,  6.365147357369046e-02,  
   -3.850900136224434e-01, -8.707822203710608e-01,  3.854775533996937e-02,  
   -4.961565809611688e-01, -9.726108752621352e-01,  1.194490281825224e-02,  
   -7.337041416795138e-01, -2.082446806606209e-01,  5.658941671510189e-02,  
   -5.809960989937741e-01, -4.073474789041275e-01,  6.376865298046723e-02,  
   -5.677230574148288e-01, -7.531679569108030e-01,  4.625453544861270e-02,  
   -6.209259660886249e-01, -9.313450399117541e-01,  1.820437285093996e-02,  
   -7.222712946524428e-01, -9.926688332077881e-01,  5.756269356678867e-03,  
   -8.472675519335334e-01, -4.202098689198475e-01,  4.046935707697283e-02,  
   -7.235313755189597e-01, -6.009001598253331e-01,  4.695366916509310e-02,  
   -7.436209196607865e-01, -8.532631127882830e-01,  2.452811191323398e-02,  
   -8.078125449235396e-01, -8.865860238557206e-01,  3.599599560868793e-03,  
   -8.496011789870433e-01, -9.584740402687207e-01,  1.136717702495919e-02,  
   -9.873993632652779e-01, -3.857565023254501e-01,  9.087958640367919e-03,  
   -9.407918538992979e-01, -5.806290275537873e-01,  2.155259200865792e-02,  
   -8.583622893662932e-01, -7.355260155277167e-01,  2.723142317719206e-02,  
   -9.417112190155333e-01, -8.140933233486173e-01,  6.586312510744677e-03,  
   -9.293007271718974e-01, -8.976314904285845e-01,  9.170625679716800e-03,  
   -9.365522911144204e-01, -2.247649048332172e-01,  2.753902574626484e-02,  
   -9.913001320610028e-01, -5.146910772747944e-01,  2.062938898431044e-03,  
   -9.892062993684332e-01, -7.177306340863354e-01,  6.213455600316710e-03,  
   -9.825794696006162e-01, -8.526916976863245e-01,  3.542165144107640e-03,  
   -9.899623983816039e-01, -9.559123039771233e-01,  2.789025209960568e-03,  
   -9.454816892922301e-01, -9.931508332329141e-01,  2.641115240694518e-03,  
    5.828566738691298e-01, -1.886005021782720e-03,  6.979680609052895e-02,  
    8.577929872633651e-01,  4.610090446080339e-03,  4.314966506560954e-02,  
    9.888852930552997e-01,  4.155284083838179e-02,  1.072399831167234e-02,  
   -6.296477862134920e-04, -2.067872320344404e-01,  8.488483237702206e-02,  
    4.038616639190317e-01, -2.082269167023509e-01,  7.727830308506041e-02,  
    7.394171390837959e-01, -2.052137161358173e-01,  5.621586102413551e-02,  
    9.496265565549702e-01, -1.807393256852824e-01,  2.535911050249288e-02,  
    9.960227386085063e-01, -3.322057475944939e-01,  5.272055511683970e-03,  
    2.059859741136477e-01, -4.045305824612024e-01,  7.726743635049893e-02,  
    5.870128510662224e-01, -4.025837874193514e-01,  6.365147357369046e-02,  
    8.707822203710608e-01, -3.850900136224434e-01,  3.854775533996937e-02,  
    9.726108752621352e-01, -4.961565809611688e-01,  1.194490281825224e-02,  
    2.082446806606209e-01, -7.337041416795138e-01,  5.658941671510189e-02,  
    4.073474789041275e-01, -5.809960989937741e-01,  6.376865298046723e-02,  
    7.531679569108030e-01, -5.677230574148288e-01,  4.625453544861270e-02,  
    9.313450399117541e-01, -6.209259660886249e-01,  1.820437285093996e-02,  
    9.926688332077881e-01, -7.222712946524428e-01,  5.756269356678867e-03,  
    4.202098689198475e-01, -8.472675519335334e-01,  4.046935707697283e-02,  
    6.009001598253331e-01, -7.235313755189597e-01,  4.695366916509310e-02,  
    8.532631127882830e-01, -7.436209196607865e-01,  2.452811191323398e-02,  
    8.865860238557206e-01, -8.078125449235396e-01,  3.599599560868793e-03,  
    9.584740402687207e-01, -8.496011789870433e-01,  1.136717702495919e-02,  
    3.857565023254501e-01, -9.873993632652779e-01,  9.087958640367919e-03,  
    5.806290275537873e-01, -9.407918538992979e-01,  2.155259200865792e-02,  
    7.355260155277167e-01, -8.583622893662932e-01,  2.723142317719206e-02,  
    8.140933233486173e-01, -9.417112190155333e-01,  6.586312510744677e-03,  
    8.976314904285845e-01, -9.293007271718974e-01,  9.170625679716800e-03,  
    2.247649048332172e-01, -9.365522911144204e-01,  2.753902574626484e-02,  
    5.146910772747944e-01, -9.913001320610028e-01,  2.062938898431044e-03,  
    7.177306340863354e-01, -9.892062993684332e-01,  6.213455600316710e-03,  
    8.526916976863245e-01, -9.825794696006162e-01,  3.542165144107640e-03,  
    9.559123039771233e-01, -9.899623983816039e-01,  2.789025209960568e-03,  
    9.931508332329141e-01, -9.454816892922301e-01,  2.641115240694518e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr28 ( )

/******************************************************************************/
/*
  Purpose:

    SMR28 returns the SMR rule of degree 28.

  Discussion:

    DEGREE: 28
    POINTS CARDINALITY: 146
    NORM INF MOMS. RESIDUAL: 9.93129e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR28[3*146], the requested rule.
*/
{
  const int degree = 28;
  int order;
  double xw[3*146] = {
    9.948578576510482e-01,  9.951313777393089e-01,  5.350567115949095e-04,  
    9.942909707974587e-01,  8.766570248036105e-01,  2.791138783606160e-03,  
    9.936073905803642e-01,  6.435920031349868e-01,  4.975936005062567e-03,  
    9.955492434128311e-01,  3.009600560431372e-01,  5.028092846274678e-03,  
    9.953117341967249e-01, -1.155952308989407e-01,  5.404591653487998e-03,  
    9.945568546430053e-01, -4.954371212342698e-01,  4.995854780477920e-03,  
    9.941123224157187e-01, -7.686450662183013e-01,  3.412261550099155e-03,  
    9.973970470314231e-01, -9.477148556565722e-01,  1.256390479179999e-03,  
    9.688973112117140e-01,  9.519148224233880e-01,  4.713673624203035e-03,  
    9.613309496208055e-01,  7.757025845655895e-01,  1.166028423822774e-02,  
    9.659860418437211e-01,  4.681861912724297e-01,  1.519045343561554e-02,  
    9.698532836823804e-01,  9.733476040026384e-02,  1.657048063461714e-02,  
    9.676987141452779e-01, -3.026291805415285e-01,  1.602715348074777e-02,  
    9.652351090613974e-01, -6.421223495984553e-01,  1.210066207543355e-02,  
    9.705483737595868e-01, -8.773547971281066e-01,  6.923308160213495e-03,  
    9.748783800172183e-01, -9.912505022009086e-01,  1.588717379761370e-03,  
    9.166016146066042e-01,  9.861313164544186e-01,  3.329484690768878e-03,  
    8.994804531261812e-01,  8.827649742916205e-01,  1.434726026694510e-02,  
    9.053106430680723e-01,  6.228188101332273e-01,  2.276716021991524e-02,  
    9.071948418179018e-01,  2.805718262681513e-01,  2.888726414871897e-02,  
    9.109240111661969e-01, -9.646023425605603e-02,  2.952643485962895e-02,  
    9.103965861122791e-01, -4.750063547383416e-01,  2.428497272680478e-02,  
    9.135589107435960e-01, -7.731270000889884e-01,  1.598024520842712e-02,  
    9.235219832875176e-01, -9.536909415826325e-01,  7.313384482073473e-03,  
    8.422727743872929e-01,  9.983748940501636e-01,  1.177144882525381e-03,  
    8.021369409522103e-01,  9.526336218686154e-01,  1.233677299331454e-02,  
    8.162908906345308e-01,  7.599008885973428e-01,  2.655091644582969e-02,  
    8.127751861060339e-01,  4.597366883296284e-01,  3.763596042165646e-02,  
    8.129630861903968e-01,  9.176425527693403e-02,  4.284745602911020e-02,  
    8.233720523878740e-01, -2.917598066537037e-01,  3.906509971261103e-02,  
    8.273253984611962e-01, -6.351315017888974e-01,  2.985137841867004e-02,  
    8.410861657858746e-01, -8.770078144051303e-01,  1.678011176333675e-02,  
    8.462927808942150e-01, -9.911001774446370e-01,  4.109086265895744e-03,  
    6.692649802375389e-01,  9.897101791893593e-01,  6.302703194199112e-03,  
    6.959480214373159e-01,  8.669178979407627e-01,  2.525587670248390e-02,  
    6.896592055450543e-01,  6.236755137912841e-01,  4.183562464805562e-02,  
    6.865013864931789e-01,  2.840539118035566e-01,  5.208001068769284e-02,  
    6.962750629039214e-01, -1.115191087063258e-01,  5.256283376203195e-02,  
    7.074126907672926e-01, -4.752442590431704e-01,  4.556426477896882e-02,  
    7.191258343646272e-01, -7.720946761786819e-01,  3.133433453762152e-02,  
    7.381207241833775e-01, -9.459798668063141e-01,  1.409639241355121e-02,  
    6.771073750372986e-01, -9.922518457423063e-01,  2.777359845401900e-03,  
    5.475677331233061e-01,  9.422181957297456e-01,  1.897982231084832e-02,  
    5.400263477570776e-01,  7.619170134687657e-01,  3.998120414157146e-02,  
    5.343007222250298e-01,  4.660852613438181e-01,  5.641016682972110e-02,  
    5.464626157458451e-01,  8.180074857237349e-02,  6.215654744912379e-02,  
    5.520150032550133e-01, -3.052541200774422e-01,  5.923432236764290e-02,  
    5.668728132802315e-01, -6.388668498497777e-01,  4.710391803124826e-02,  
    5.810992753051508e-01, -8.752071635592164e-01,  2.787797798973161e-02,  
    5.671475579878305e-01, -9.796604593842159e-01,  7.793314748885580e-03,  
    3.968756859090636e-01,  9.879827506647261e-01,  8.923994125095943e-03,  
    3.707910234961497e-01,  8.695515088341891e-01,  3.239278927868577e-02,  
    3.620431155247392e-01,  6.294210332481971e-01,  5.436999365883735e-02,  
    3.756691454599630e-01,  2.722208281305576e-01,  6.689872061273545e-02,  
    3.801363136282314e-01, -1.153023476012179e-01,  6.916197504314157e-02,  
    3.870789258805237e-01, -4.852712266367580e-01,  6.069376521414673e-02,  
    4.013748435296351e-01, -7.721926519007076e-01,  4.296137864461146e-02,  
    4.029880643773450e-01, -9.405596605751765e-01,  1.992102855514764e-02,  
    4.035133457630937e-01, -9.984853538421118e-01,  2.668528192375319e-03,  
    1.160216426928697e-01,  9.922413519284493e-01,  5.350102953202783e-03,  
    2.055793223051185e-01,  9.459133372942112e-01,  2.072186274583783e-02,  
    1.776855819898789e-01,  7.668715275107250e-01,  4.612076109466228e-02,  
    1.919764609816849e-01,  4.526549306348999e-01,  6.552641398222167e-02,  
    1.926293216704643e-01,  7.875626396945502e-02,  7.415699880326786e-02,  
    1.985057734993036e-01, -3.060328376638529e-01,  7.072349740661799e-02,  
    2.038466930455823e-01, -6.417616215413990e-01,  5.626372459884906e-02,  
    2.088349228463496e-01, -8.693904617391873e-01,  3.383513644639114e-02,  
    2.112825401519657e-01, -9.795723716889928e-01,  1.129835512516279e-02,  
   -5.348117081594564e-02,  9.601197110277508e-01,  1.102425532666331e-02,  
   -1.440209295656826e-03,  8.728107413837934e-01,  3.293357956668601e-02,  
    3.475808263467210e-03,  6.154311844205719e-01,  5.809864825359298e-02,  
   -1.120628220586241e-03,  2.708231330142061e-01,  7.325167415256556e-02,  
    1.044970007167108e-03, -1.158225951592231e-01,  7.568882188561220e-02,  
    6.384994250920603e-03, -4.809476808243928e-01,  6.617874013219743e-02,  
    4.295452536640910e-03, -7.676008066148449e-01,  4.657600571756004e-02,  
    4.651117956286204e-03, -9.365900032572481e-01,  2.283252555981913e-02,  
    8.237620269373420e-03, -9.962744074089572e-01,  3.786352125662351e-03,  
   -1.274891040086490e-01,  9.929001195823554e-01,  4.958467693467626e-03,  
   -2.413142327752992e-01,  9.029321598234583e-01,  1.853018716489174e-02,  
   -1.832813730805473e-01,  7.525928605307329e-01,  4.713333096331936e-02,  
   -1.920382892873746e-01,  4.539454858901587e-01,  6.603945261049947e-02,  
   -1.956436793406595e-01,  7.941255257340975e-02,  7.508025050715028e-02,  
   -1.923970603608269e-01, -3.024155270841158e-01,  7.084970982103253e-02,  
   -1.911944603737556e-01, -6.318610134350573e-01,  5.601846880048385e-02,  
   -1.997986481004511e-01, -8.643880734116528e-01,  3.434757868627490e-02,  
   -2.040634037532908e-01, -9.778548144980190e-01,  1.259279635934074e-02,  
   -2.997076844021980e-01,  9.628107191472532e-01,  1.314095498758601e-02,  
   -4.148554476460968e-01,  8.338942142941969e-01,  3.293242786053679e-02,  
   -3.779198201034129e-01,  6.158737694305179e-01,  5.508527968607409e-02,  
   -3.805490179487411e-01,  2.750443753116855e-01,  6.796131506618697e-02,  
   -3.841282487515310e-01, -1.132877025420610e-01,  7.045152003060294e-02,  
   -3.804454671026422e-01, -4.720772509930954e-01,  6.002911781360866e-02,  
   -3.841911412860247e-01, -7.558248311258943e-01,  4.283433317172849e-02,  
   -4.014494726845325e-01, -9.319408172971044e-01,  2.234448515507551e-02,  
   -4.134249428005414e-01, -9.971881189618174e-01,  3.879387979882435e-03,  
   -4.482484235975709e-01,  9.933540226000461e-01,  5.885518307205129e-03,  
   -5.401264617535639e-01,  9.300111343789312e-01,  2.045252873739783e-02,  
   -5.846028440856790e-01,  7.267512221362666e-01,  4.025157999677987e-02,  
   -5.551715224920534e-01,  4.543430257556506e-01,  5.681533956880705e-02,  
   -5.546040128597290e-01,  8.607588431664005e-02,  6.345041073160007e-02,  
   -5.590463446310300e-01, -2.987570130168568e-01,  5.984062693812596e-02,  
   -5.535005324411616e-01, -6.169692132455251e-01,  4.534179475738604e-02,  
   -5.666697445547572e-01, -8.481255174324074e-01,  2.955237828322555e-02,  
   -5.928240900022717e-01, -9.728321444146757e-01,  1.207258865550634e-02,  
   -6.756466780817323e-01,  9.797748409271184e-01,  9.430834821192467e-03,  
   -7.057090125640939e-01,  8.569411643178257e-01,  2.578172152269087e-02,  
   -7.324178297883669e-01,  5.881115844344131e-01,  4.112604151501918e-02,  
   -7.089833134544923e-01,  2.743227288305772e-01,  5.206048407106920e-02,  
   -7.070216898176970e-01, -1.052133696540627e-01,  5.313592538270182e-02,  
   -7.140246356433033e-01, -4.665219411497065e-01,  4.523777395980864e-02,  
   -7.018378364178222e-01, -7.239136739360896e-01,  2.865845173440685e-02,  
   -7.265012674973680e-01, -9.106140002539487e-01,  1.785266500303629e-02,  
   -7.502326422653172e-01, -9.941725573151815e-01,  3.753285495396784e-03,  
   -8.274846897101481e-01,  9.978010553534403e-01,  2.202140457066555e-03,  
   -8.192923347877169e-01,  9.390289816897084e-01,  1.292326356223006e-02,  
   -8.313147253414798e-01,  7.529833038926661e-01,  2.592641401983919e-02,  
   -8.508397854338550e-01,  4.234950052660812e-01,  3.562268594306770e-02,  
   -8.335604271423080e-01,  8.263716754706234e-02,  4.169722943892294e-02,  
   -8.333299598244532e-01, -2.871192325820531e-01,  3.873060921878728e-02,  
   -8.458562646869368e-01, -5.969821698805272e-01,  2.877988053080015e-02,  
   -8.078655554136182e-01, -7.904438964071007e-01,  1.755929774595502e-02,  
   -8.447527353299386e-01, -9.573586572433928e-01,  9.057958019613784e-03,  
   -9.281623277448025e-01,  9.778973529249545e-01,  4.706571839130655e-03,  
   -9.134629368007466e-01,  8.725226493533312e-01,  1.272093703683140e-02,  
   -9.189059119013587e-01,  6.228132355945927e-01,  2.081162885166939e-02,  
   -9.352972042034906e-01,  2.394035979501314e-01,  2.507345449526446e-02,  
   -9.260008242840237e-01, -1.093506648825247e-01,  2.730772032753251e-02,  
   -9.322554404281427e-01, -4.325018867770137e-01,  2.166809223221262e-02,  
   -9.265407983180678e-01, -6.804488306011519e-01,  1.129035475105887e-02,  
   -8.963660879434896e-01, -8.578428981954751e-01,  1.427796928443569e-02,  
   -9.228669313126245e-01, -9.903049524081384e-01,  2.936908429948614e-03,  
   -9.795076814902403e-01,  9.391999047436536e-01,  3.611764745309799e-03,  
   -9.682018722477242e-01,  7.789774445276537e-01,  9.386909970380832e-03,  
   -9.723852471142062e-01,  4.752904607817341e-01,  1.284048267253543e-02,  
   -9.845164156039091e-01,  4.496231910970377e-02,  1.155742732057478e-02,  
   -9.919138468383984e-01, -5.892431915668860e-01,  5.712369221551983e-03,  
   -9.653607048671382e-01, -7.514078044040550e-01,  9.247990075208610e-03,  
   -9.634968122279486e-01, -9.300634913926976e-01,  6.455717208889276e-03,  
   -9.899993900205354e-01,  9.944294353233614e-01,  6.923818612511791e-04,  
   -9.957478348818433e-01,  8.751512353190156e-01,  1.727894454945418e-03,  
   -9.950143212717456e-01,  6.584454755209226e-01,  3.945702259118487e-03,  
   -9.960292127295011e-01,  3.102415165889851e-01,  4.235815708736188e-03,  
   -9.868438218892031e-01, -2.632466666320823e-01,  1.048005824445523e-02,  
   -9.759292701915939e-01, -4.866196210874411e-01,  4.122542369510386e-03,  
   -9.956803593698287e-01, -8.464174810055828e-01,  2.909040478947865e-03,  
   -9.918608822862665e-01, -9.833582162145671e-01,  1.201280370154266e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr29 ( )

/******************************************************************************/
/*
  Purpose:

    SMR29 returns the SMR rule of degree 29.

  Discussion:

    DEGREE: 29
    SYMMETRY: (X,  Y),  (-X, -Y)
    POINTS CARDINALITY: 153
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR29[3*153], the requested rule.
*/
{
  const int degree = 29;
  int order;
  double xw[3*153] = {
   -9.949933127427926e-01,  9.846653902287268e-01,  9.395690393964076e-04,  
   -9.947553807807867e-01, -6.565416135023074e-01,  4.902572703976801e-03,  
   -9.945746533289254e-01,  8.095347588811120e-01,  3.444322300954131e-03,  
   -9.936165836110393e-01,  5.449460871204653e-01,  5.048778280493792e-03,  
   -9.916021206491545e-01, -3.020588266272870e-01,  7.856326443021280e-03,  
   -9.885493346511697e-01,  3.754426235872674e-02,  9.243463352453171e-03,  
   -9.853949921317231e-01, -9.716885948870212e-01,  2.611624046143479e-03,  
   -9.850307952194871e-01, -8.619821821525152e-01,  5.756950705760731e-03,  
   -9.832827588628299e-01,  3.064831307139635e-01,  1.011037458386165e-02,  
   -9.721136174490276e-01,  9.199575449706859e-01,  6.336945711231334e-03,  
   -9.629324251458530e-01,  6.898499209334040e-01,  1.253275279199627e-02,  
   -9.611009120701418e-01, -5.003853392931935e-01,  1.712154659313199e-02,  
   -9.462498240094916e-01, -1.332608625807670e-01,  2.240075719199047e-02,  
   -9.411359576419225e-01, -7.505472392355358e-01,  1.603065396164867e-02,  
   -9.382448848401312e-01,  4.599118226520993e-01,  1.718439080989034e-02,  
   -9.314612798308124e-01, -9.967694998936406e-01,  1.745679805743830e-03,  
   -9.295735875484051e-01,  9.848152682310835e-01,  4.103888501222671e-03,  
   -9.232310041137312e-01,  1.804372056187648e-01,  2.477443727803194e-02,  
   -9.183317763520688e-01, -9.261208167798600e-01,  1.096195080681892e-02,  
   -9.116574969716016e-01,  8.271123341203230e-01,  1.601077862848477e-02,  
   -8.888912692909274e-01, -3.479987971871291e-01,  2.796225817458692e-02,  
   -8.779301509485118e-01,  5.948583749922939e-01,  2.015897400394908e-02,  
   -8.637451657209914e-01, -6.139023089531026e-01,  2.808904163947544e-02,  
   -8.501310025536610e-01,  9.347168973702518e-01,  1.258009305624949e-02,  
   -8.432406244370808e-01,  2.340798283350513e-02,  3.394457013361375e-02,  
   -8.333294144744180e-01, -1.839129116833924e-01,  9.917901422164995e-03,  
   -8.296887505977431e-01, -8.345532619659806e-01,  2.285324032183532e-02,  
   -8.290744150263981e-01,  3.658292544818590e-01,  3.507289015514854e-02,  
   -8.187205704950732e-01, -9.788557134648613e-01,  7.722403962482972e-03,  
   -8.088673371817973e-01,  7.219103637161282e-01,  2.472789041607375e-02,  
   -7.802699772004215e-01,  9.914861448776406e-01,  4.713473975833743e-03,  
   -7.752301559048632e-01, -2.171128429124935e-01,  2.378259924133609e-02,  
   -7.470829498608977e-01, -4.586599493926842e-01,  4.002928037597185e-02,  
   -7.361511371834013e-01,  8.583154508083678e-01,  2.261583569713491e-02,  
   -7.287146431973126e-01, -6.873006158071762e-01,  2.251882920671917e-02,  
   -7.180886055039243e-01,  2.076767520253592e-01,  4.499352749218116e-02,  
   -7.146537939190210e-01, -9.289340401690634e-01,  1.645329992585584e-02,  
   -7.067199537433859e-01,  5.424756607903567e-01,  4.335690137047433e-02,  
   -6.903679490586278e-01, -7.147862946890238e-02,  3.408763052303377e-02,  
   -6.764025157771765e-01, -7.573659452363536e-01,  1.935531604707887e-02,  
   -6.506894539762457e-01,  9.564690231494537e-01,  1.464896209687315e-02,  
   -6.208513475663459e-01, -9.916051471397467e-01,  6.432187025682493e-03,  
   -6.116292887899047e-01,  7.357056852576344e-01,  3.377020044412275e-02,  
   -5.979003962373047e-01, -2.796891406409555e-01,  4.888297756206456e-02,  
   -5.778077209855854e-01, -8.675249675625395e-01,  2.457244823370517e-02,  
   -5.728456567073842e-01, -5.296576709425311e-01,  3.639826598763665e-02,  
   -5.602688054023620e-01,  3.829382266085970e-01,  5.473125938490646e-02,  
   -5.600226162335806e-01,  7.201761109528224e-02,  4.732804187723799e-02,  
   -5.315715479129545e-01, -6.485017442148879e-01,  2.380537349256804e-02,  
   -5.213722221542452e-01,  8.717053530032300e-01,  2.354037231951190e-02,  
   -5.205683240806913e-01,  9.943357320308036e-01,  5.022863813128614e-03,  
   -4.747713831994940e-01,  6.303175260200578e-01,  3.769491458931831e-02,  
   -4.518891563243193e-01, -9.565726413410444e-01,  1.899592320434612e-02,  
   -4.253276863946355e-01, -1.030467857496181e-01,  5.661499125196553e-02,  
   -4.243714642725596e-01, -7.749351121311114e-01,  3.571480883454545e-02,  
   -4.208552091936032e-01,  9.360365856546493e-01,  1.371343151498627e-02,  
   -3.971426434725366e-01, -3.784299583698726e-01,  5.358828824792165e-02,  
   -3.840824803302514e-01,  2.278813318596969e-01,  5.817728003299089e-02,  
   -3.537037178838521e-01,  5.212016641539493e-01,  4.215943343810559e-02,  
   -3.344249565042606e-01,  7.938301760272564e-01,  3.983164515649597e-02,  
   -3.183689681012091e-01, -5.911289985164023e-01,  4.507083618856889e-02,  
   -3.099978370992671e-01,  9.775914827530479e-01,  1.070368922033845e-02,  
   -2.742873135694627e-01, -9.934217560165197e-01,  7.024959810244680e-03,  
   -2.684789526442052e-01, -8.841305328486172e-01,  3.234575636115414e-02,  
   -2.236413499576709e-01,  6.847889170584819e-02,  5.715210426473966e-02,  
   -2.076813935038102e-01, -1.933246405625380e-01,  5.711938069880197e-02,  
   -1.985992354046592e-01,  4.002875818222759e-01,  5.390325679350508e-02,  
   -1.731862586703496e-01,  9.086517858862069e-01,  2.785469982257396e-02,  
   -1.650094536595912e-01,  6.768962485151462e-01,  4.809572953564538e-02,  
   -1.634028445678156e-01, -7.199249170570964e-01,  4.287990357079033e-02,  
   -1.548556328765567e-01, -4.247385329928982e-01,  4.815909770521859e-02,  
   -8.887107041790254e-02,  9.911658972290777e-01,  7.431729974979581e-03,  
   -8.682050121233974e-02, -9.548310793397383e-01,  2.094359269434157e-02,  
   -3.424326390343065e-02,  2.534546862921038e-01,  5.738432661390758e-02,  
   -3.764571754171391e-03, -5.533592189095456e-01,  4.897606541273797e-02,  
   -1.890047137705217e-03,  8.246644534267950e-01,  3.721909074703320e-02,  
    0.000000000000000e+00,  0.000000000000000e+00,  5.611678279970572e-02,  
    1.890047137705217e-03, -8.246644534267950e-01,  3.721909074703320e-02,  
    3.764571754171391e-03,  5.533592189095456e-01,  4.897606541273797e-02,  
    3.424326390343065e-02, -2.534546862921038e-01,  5.738432661390758e-02,  
    8.682050121233974e-02,  9.548310793397383e-01,  2.094359269434157e-02,  
    8.887107041790254e-02, -9.911658972290777e-01,  7.431729974979581e-03,  
    1.548556328765567e-01,  4.247385329928982e-01,  4.815909770521859e-02,  
    1.634028445678156e-01,  7.199249170570964e-01,  4.287990357079033e-02,  
    1.650094536595912e-01, -6.768962485151462e-01,  4.809572953564538e-02,  
    1.731862586703496e-01, -9.086517858862069e-01,  2.785469982257396e-02,  
    1.985992354046592e-01, -4.002875818222759e-01,  5.390325679350508e-02,  
    2.076813935038102e-01,  1.933246405625380e-01,  5.711938069880197e-02,  
    2.236413499576709e-01, -6.847889170584819e-02,  5.715210426473966e-02,  
    2.684789526442052e-01,  8.841305328486172e-01,  3.234575636115414e-02,  
    2.742873135694627e-01,  9.934217560165197e-01,  7.024959810244680e-03,  
    3.099978370992671e-01, -9.775914827530479e-01,  1.070368922033845e-02,  
    3.183689681012091e-01,  5.911289985164023e-01,  4.507083618856889e-02,  
    3.344249565042606e-01, -7.938301760272564e-01,  3.983164515649597e-02,  
    3.537037178838521e-01, -5.212016641539493e-01,  4.215943343810559e-02,  
    3.840824803302514e-01, -2.278813318596969e-01,  5.817728003299089e-02,  
    3.971426434725366e-01,  3.784299583698726e-01,  5.358828824792165e-02,  
    4.208552091936032e-01, -9.360365856546493e-01,  1.371343151498627e-02,  
    4.243714642725596e-01,  7.749351121311114e-01,  3.571480883454545e-02,  
    4.253276863946355e-01,  1.030467857496181e-01,  5.661499125196553e-02,  
    4.518891563243193e-01,  9.565726413410444e-01,  1.899592320434612e-02,  
    4.747713831994940e-01, -6.303175260200578e-01,  3.769491458931831e-02,  
    5.205683240806913e-01, -9.943357320308036e-01,  5.022863813128614e-03,  
    5.213722221542452e-01, -8.717053530032300e-01,  2.354037231951190e-02,  
    5.315715479129545e-01,  6.485017442148879e-01,  2.380537349256804e-02,  
    5.600226162335806e-01, -7.201761109528224e-02,  4.732804187723799e-02,  
    5.602688054023620e-01, -3.829382266085970e-01,  5.473125938490646e-02,  
    5.728456567073842e-01,  5.296576709425311e-01,  3.639826598763665e-02,  
    5.778077209855854e-01,  8.675249675625395e-01,  2.457244823370517e-02,  
    5.979003962373047e-01,  2.796891406409555e-01,  4.888297756206456e-02,  
    6.116292887899047e-01, -7.357056852576344e-01,  3.377020044412275e-02,  
    6.208513475663459e-01,  9.916051471397467e-01,  6.432187025682493e-03,  
    6.506894539762457e-01, -9.564690231494537e-01,  1.464896209687315e-02,  
    6.764025157771765e-01,  7.573659452363536e-01,  1.935531604707887e-02,  
    6.903679490586278e-01,  7.147862946890238e-02,  3.408763052303377e-02,  
    7.067199537433859e-01, -5.424756607903567e-01,  4.335690137047433e-02,  
    7.146537939190210e-01,  9.289340401690634e-01,  1.645329992585584e-02,  
    7.180886055039243e-01, -2.076767520253592e-01,  4.499352749218116e-02,  
    7.287146431973126e-01,  6.873006158071762e-01,  2.251882920671917e-02,  
    7.361511371834013e-01, -8.583154508083678e-01,  2.261583569713491e-02,  
    7.470829498608977e-01,  4.586599493926842e-01,  4.002928037597185e-02,  
    7.752301559048632e-01,  2.171128429124935e-01,  2.378259924133609e-02,  
    7.802699772004215e-01, -9.914861448776406e-01,  4.713473975833743e-03,  
    8.088673371817973e-01, -7.219103637161282e-01,  2.472789041607375e-02,  
    8.187205704950732e-01,  9.788557134648613e-01,  7.722403962482972e-03,  
    8.290744150263981e-01, -3.658292544818590e-01,  3.507289015514854e-02,  
    8.296887505977431e-01,  8.345532619659806e-01,  2.285324032183532e-02,  
    8.333294144744180e-01,  1.839129116833924e-01,  9.917901422164995e-03,  
    8.432406244370808e-01, -2.340798283350513e-02,  3.394457013361375e-02,  
    8.501310025536610e-01, -9.347168973702518e-01,  1.258009305624949e-02,  
    8.637451657209914e-01,  6.139023089531026e-01,  2.808904163947544e-02,  
    8.779301509485118e-01, -5.948583749922939e-01,  2.015897400394908e-02,  
    8.888912692909274e-01,  3.479987971871291e-01,  2.796225817458692e-02,  
    9.116574969716016e-01, -8.271123341203230e-01,  1.601077862848477e-02,  
    9.183317763520688e-01,  9.261208167798600e-01,  1.096195080681892e-02,  
    9.232310041137312e-01, -1.804372056187648e-01,  2.477443727803194e-02,  
    9.295735875484051e-01, -9.848152682310835e-01,  4.103888501222671e-03,  
    9.314612798308124e-01,  9.967694998936406e-01,  1.745679805743830e-03,  
    9.382448848401312e-01, -4.599118226520993e-01,  1.718439080989034e-02,  
    9.411359576419225e-01,  7.505472392355358e-01,  1.603065396164867e-02,  
    9.462498240094916e-01,  1.332608625807670e-01,  2.240075719199047e-02,  
    9.611009120701418e-01,  5.003853392931935e-01,  1.712154659313199e-02,  
    9.629324251458530e-01, -6.898499209334040e-01,  1.253275279199627e-02,  
    9.721136174490276e-01, -9.199575449706859e-01,  6.336945711231334e-03,  
    9.832827588628299e-01, -3.064831307139635e-01,  1.011037458386165e-02,  
    9.850307952194871e-01,  8.619821821525152e-01,  5.756950705760731e-03,  
    9.853949921317231e-01,  9.716885948870212e-01,  2.611624046143479e-03,  
    9.885493346511697e-01, -3.754426235872674e-02,  9.243463352453171e-03,  
    9.916021206491545e-01,  3.020588266272870e-01,  7.856326443021280e-03,  
    9.936165836110393e-01, -5.449460871204653e-01,  5.048778280493792e-03,  
    9.945746533289254e-01, -8.095347588811120e-01,  3.444322300954131e-03,  
    9.947553807807867e-01,  6.565416135023074e-01,  4.902572703976801e-03,  
    9.949933127427926e-01, -9.846653902287268e-01,  9.395690393964076e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr29s ( )

/******************************************************************************/
/*
  Purpose:

    SMR29S returns the rotatonally invariant SMR rule of degree 29.

  Discussion:
 
    DEGREE: 29
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 153
    NORM INF MOMS. RESIDUAL: 2.70617e-16
    SUM NEGATIVE WEIGHTS: 1.46517e-02,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR29S[3*153], the requested rule.
*/
{
  const int degree = 29;
  int order;
  double xw[3*153] = {
    1.995554510347695e-01,  1.887353707822548e-01,  7.344881047788419e-02,  
    2.130905764129401e-01,  5.455267403580432e-01,  6.209984035978915e-02,  
    2.388895084628246e-01,  8.131809651972651e-01,  4.184384427163037e-02,  
    2.038938767743064e-01,  9.863343822191492e-01,  5.131075694716339e-04,  
    2.698246240215212e-01,  9.643706705539593e-01,  1.712164807226155e-02,  
    3.928345180603147e-01,  3.686184349052021e-01,  6.489527207591311e-02,  
    4.144000559327279e-01,  6.845975817877503e-01,  4.944840913356350e-02,  
    4.402759350876731e-01,  9.010432195863607e-01,  2.757405514679618e-02,  
    4.527181508614157e-01,  9.952152161758490e-01,  4.925532618002394e-03,  
    5.579522261495289e-01,  1.761582819832321e-01,  6.188238970001386e-02,  
    5.753347655779147e-01,  5.292288412881652e-01,  5.168460836650747e-02,  
    5.934515082334419e-01,  8.046750403390426e-01,  3.415204165486681e-02,  
    6.055261390114883e-01,  9.669899640916929e-01,  1.323441713883155e-02,  
    7.154909664472028e-01,  3.523839334728593e-01,  4.846803145137081e-02,  
    7.268010683419225e-01,  6.783203685825908e-01,  3.602990566434557e-02,  
    7.296280734021068e-01,  9.091222948855520e-01,  1.863026896557024e-02,  
    7.685318705419301e-01,  9.932162015282956e-01,  4.367730318652883e-03,  
    8.289969889442530e-01,  1.584524092289804e-01,  4.058748981808668e-02,  
    8.365897953958084e-01,  5.258522155386184e-01,  3.319785897530852e-02,  
    8.316719666113968e-01,  8.204370730256448e-01,  2.075970864095848e-02,  
    8.871860429369979e-01,  9.163805447338561e-01,  3.893022115627323e-03,  
    8.690236026560919e-01,  9.647484296790166e-01,  7.335685071586549e-03,  
    9.187533470826308e-01,  3.499840453590620e-01,  2.626466692941504e-02,  
    9.134702524025524e-01,  7.013486396820177e-01,  1.955810454123038e-02,  
    9.541746623132917e-01,  8.410023019359270e-01,  6.965850473298985e-03,  
    9.475721149242626e-01,  9.269025845479085e-01,  5.802838252293684e-03,  
    9.568636719971328e-01,  9.889975414443256e-01,  3.098510717291335e-03,  
    9.700539003410525e-01,  1.462690094803091e-01,  1.684436628110278e-02,  
    9.961052572257075e-01,  3.632658507871842e-01,  5.146979760206008e-03,  
    9.696607933775031e-01,  5.511605113182357e-01,  1.411592369017692e-02,  
    9.930889935835162e-01,  7.238541535398172e-01,  4.366281743177327e-03,  
    9.861368659264031e-01,  8.483603521407402e-01,  2.558788266617852e-03,  
    9.703225207695876e-01,  9.617299191521864e-01, -3.662923776765502e-03,  
    9.877929897983208e-01,  9.572988789445298e-01,  3.811762688023674e-03,  
    1.110886537223573e-02,  3.805232776392568e-01,  7.048655460716827e-02,  
    2.656770164537742e-02,  7.008980905724834e-01,  5.369718262729808e-02,  
    5.439701833656795e-02,  9.100556589521321e-01,  2.989488274476401e-02,  
    7.142859722990462e-02,  9.946044556670760e-01,  5.849868982269740e-03,  
   -1.887353707822548e-01,  1.995554510347695e-01,  7.344881047788419e-02,  
   -5.455267403580432e-01,  2.130905764129401e-01,  6.209984035978915e-02,  
   -8.131809651972651e-01,  2.388895084628246e-01,  4.184384427163037e-02,  
   -9.863343822191492e-01,  2.038938767743064e-01,  5.131075694716339e-04,  
   -9.643706705539593e-01,  2.698246240215212e-01,  1.712164807226155e-02,  
   -3.686184349052021e-01,  3.928345180603147e-01,  6.489527207591311e-02,  
   -6.845975817877503e-01,  4.144000559327279e-01,  4.944840913356350e-02,  
   -9.010432195863607e-01,  4.402759350876731e-01,  2.757405514679618e-02,  
   -9.952152161758490e-01,  4.527181508614157e-01,  4.925532618002394e-03,  
   -1.761582819832321e-01,  5.579522261495289e-01,  6.188238970001386e-02,  
   -5.292288412881652e-01,  5.753347655779147e-01,  5.168460836650747e-02,  
   -8.046750403390426e-01,  5.934515082334419e-01,  3.415204165486681e-02,  
   -9.669899640916929e-01,  6.055261390114883e-01,  1.323441713883155e-02,  
   -3.523839334728593e-01,  7.154909664472028e-01,  4.846803145137081e-02,  
   -6.783203685825908e-01,  7.268010683419225e-01,  3.602990566434557e-02,  
   -9.091222948855520e-01,  7.296280734021068e-01,  1.863026896557024e-02,  
   -9.932162015282956e-01,  7.685318705419301e-01,  4.367730318652883e-03,  
   -1.584524092289804e-01,  8.289969889442530e-01,  4.058748981808668e-02,  
   -5.258522155386184e-01,  8.365897953958084e-01,  3.319785897530852e-02,  
   -8.204370730256448e-01,  8.316719666113968e-01,  2.075970864095848e-02,  
   -9.163805447338561e-01,  8.871860429369979e-01,  3.893022115627323e-03,  
   -9.647484296790166e-01,  8.690236026560919e-01,  7.335685071586549e-03,  
   -3.499840453590620e-01,  9.187533470826308e-01,  2.626466692941504e-02,  
   -7.013486396820177e-01,  9.134702524025524e-01,  1.955810454123038e-02,  
   -8.410023019359270e-01,  9.541746623132917e-01,  6.965850473298985e-03,  
   -9.269025845479085e-01,  9.475721149242626e-01,  5.802838252293684e-03,  
   -9.889975414443256e-01,  9.568636719971328e-01,  3.098510717291335e-03,  
   -1.462690094803091e-01,  9.700539003410525e-01,  1.684436628110278e-02,  
   -3.632658507871842e-01,  9.961052572257075e-01,  5.146979760206008e-03,  
   -5.511605113182357e-01,  9.696607933775031e-01,  1.411592369017692e-02,  
   -7.238541535398172e-01,  9.930889935835162e-01,  4.366281743177327e-03,  
   -8.483603521407402e-01,  9.861368659264031e-01,  2.558788266617852e-03,  
   -9.617299191521864e-01,  9.703225207695876e-01, -3.662923776765502e-03,  
   -9.572988789445298e-01,  9.877929897983208e-01,  3.811762688023674e-03,  
   -3.805232776392568e-01,  1.110886537223573e-02,  7.048655460716827e-02,  
   -7.008980905724834e-01,  2.656770164537742e-02,  5.369718262729808e-02,  
   -9.100556589521321e-01,  5.439701833656795e-02,  2.989488274476401e-02,  
   -9.946044556670760e-01,  7.142859722990462e-02,  5.849868982269740e-03,  
   -1.995554510347695e-01, -1.887353707822548e-01,  7.344881047788419e-02,  
   -2.130905764129401e-01, -5.455267403580432e-01,  6.209984035978915e-02,  
   -2.388895084628246e-01, -8.131809651972651e-01,  4.184384427163037e-02,  
   -2.038938767743064e-01, -9.863343822191492e-01,  5.131075694716339e-04,  
   -2.698246240215212e-01, -9.643706705539593e-01,  1.712164807226155e-02,  
   -3.928345180603147e-01, -3.686184349052021e-01,  6.489527207591311e-02,  
   -4.144000559327279e-01, -6.845975817877503e-01,  4.944840913356350e-02,  
   -4.402759350876731e-01, -9.010432195863607e-01,  2.757405514679618e-02,  
   -4.527181508614157e-01, -9.952152161758490e-01,  4.925532618002394e-03,  
   -5.579522261495289e-01, -1.761582819832321e-01,  6.188238970001386e-02,  
   -5.753347655779147e-01, -5.292288412881652e-01,  5.168460836650747e-02,  
   -5.934515082334419e-01, -8.046750403390426e-01,  3.415204165486681e-02,  
   -6.055261390114883e-01, -9.669899640916929e-01,  1.323441713883155e-02,  
   -7.154909664472028e-01, -3.523839334728593e-01,  4.846803145137081e-02,  
   -7.268010683419225e-01, -6.783203685825908e-01,  3.602990566434557e-02,  
   -7.296280734021068e-01, -9.091222948855520e-01,  1.863026896557024e-02,  
   -7.685318705419301e-01, -9.932162015282956e-01,  4.367730318652883e-03,  
   -8.289969889442530e-01, -1.584524092289804e-01,  4.058748981808668e-02,  
   -8.365897953958084e-01, -5.258522155386184e-01,  3.319785897530852e-02,  
   -8.316719666113968e-01, -8.204370730256448e-01,  2.075970864095848e-02,  
   -8.871860429369979e-01, -9.163805447338561e-01,  3.893022115627323e-03,  
   -8.690236026560919e-01, -9.647484296790166e-01,  7.335685071586549e-03,  
   -9.187533470826308e-01, -3.499840453590620e-01,  2.626466692941504e-02,  
   -9.134702524025524e-01, -7.013486396820177e-01,  1.955810454123038e-02,  
   -9.541746623132917e-01, -8.410023019359270e-01,  6.965850473298985e-03,  
   -9.475721149242626e-01, -9.269025845479085e-01,  5.802838252293684e-03,  
   -9.568636719971328e-01, -9.889975414443256e-01,  3.098510717291335e-03,  
   -9.700539003410525e-01, -1.462690094803091e-01,  1.684436628110278e-02,  
   -9.961052572257075e-01, -3.632658507871842e-01,  5.146979760206008e-03,  
   -9.696607933775031e-01, -5.511605113182357e-01,  1.411592369017692e-02,  
   -9.930889935835162e-01, -7.238541535398172e-01,  4.366281743177327e-03,  
   -9.861368659264031e-01, -8.483603521407402e-01,  2.558788266617852e-03,  
   -9.703225207695876e-01, -9.617299191521864e-01, -3.662923776765502e-03,  
   -9.877929897983208e-01, -9.572988789445298e-01,  3.811762688023674e-03,  
   -1.110886537223573e-02, -3.805232776392568e-01,  7.048655460716827e-02,  
   -2.656770164537742e-02, -7.008980905724834e-01,  5.369718262729808e-02,  
   -5.439701833656795e-02, -9.100556589521321e-01,  2.989488274476401e-02,  
   -7.142859722990462e-02, -9.946044556670760e-01,  5.849868982269740e-03,  
    1.887353707822548e-01, -1.995554510347695e-01,  7.344881047788419e-02,  
    5.455267403580432e-01, -2.130905764129401e-01,  6.209984035978915e-02,  
    8.131809651972651e-01, -2.388895084628246e-01,  4.184384427163037e-02,  
    9.863343822191492e-01, -2.038938767743064e-01,  5.131075694716339e-04,  
    9.643706705539593e-01, -2.698246240215212e-01,  1.712164807226155e-02,  
    3.686184349052021e-01, -3.928345180603147e-01,  6.489527207591311e-02,  
    6.845975817877503e-01, -4.144000559327279e-01,  4.944840913356350e-02,  
    9.010432195863607e-01, -4.402759350876731e-01,  2.757405514679618e-02,  
    9.952152161758490e-01, -4.527181508614157e-01,  4.925532618002394e-03,  
    1.761582819832321e-01, -5.579522261495289e-01,  6.188238970001386e-02,  
    5.292288412881652e-01, -5.753347655779147e-01,  5.168460836650747e-02,  
    8.046750403390426e-01, -5.934515082334419e-01,  3.415204165486681e-02,  
    9.669899640916929e-01, -6.055261390114883e-01,  1.323441713883155e-02,  
    3.523839334728593e-01, -7.154909664472028e-01,  4.846803145137081e-02,  
    6.783203685825908e-01, -7.268010683419225e-01,  3.602990566434557e-02,  
    9.091222948855520e-01, -7.296280734021068e-01,  1.863026896557024e-02,  
    9.932162015282956e-01, -7.685318705419301e-01,  4.367730318652883e-03,  
    1.584524092289804e-01, -8.289969889442530e-01,  4.058748981808668e-02,  
    5.258522155386184e-01, -8.365897953958084e-01,  3.319785897530852e-02,  
    8.204370730256448e-01, -8.316719666113968e-01,  2.075970864095848e-02,  
    9.163805447338561e-01, -8.871860429369979e-01,  3.893022115627323e-03,  
    9.647484296790166e-01, -8.690236026560919e-01,  7.335685071586549e-03,  
    3.499840453590620e-01, -9.187533470826308e-01,  2.626466692941504e-02,  
    7.013486396820177e-01, -9.134702524025524e-01,  1.955810454123038e-02,  
    8.410023019359270e-01, -9.541746623132917e-01,  6.965850473298985e-03,  
    9.269025845479085e-01, -9.475721149242626e-01,  5.802838252293684e-03,  
    9.889975414443256e-01, -9.568636719971328e-01,  3.098510717291335e-03,  
    1.462690094803091e-01, -9.700539003410525e-01,  1.684436628110278e-02,  
    3.632658507871842e-01, -9.961052572257075e-01,  5.146979760206008e-03,  
    5.511605113182357e-01, -9.696607933775031e-01,  1.411592369017692e-02,  
    7.238541535398172e-01, -9.930889935835162e-01,  4.366281743177327e-03,  
    8.483603521407402e-01, -9.861368659264031e-01,  2.558788266617852e-03,  
    9.617299191521864e-01, -9.703225207695876e-01, -3.662923776765502e-03,  
    9.572988789445298e-01, -9.877929897983208e-01,  3.811762688023674e-03,  
    3.805232776392568e-01, -1.110886537223573e-02,  7.048655460716827e-02,  
    7.008980905724834e-01, -2.656770164537742e-02,  5.369718262729808e-02,  
    9.100556589521321e-01, -5.439701833656795e-02,  2.989488274476401e-02,  
    9.946044556670760e-01, -7.142859722990462e-02,  5.849868982269740e-03,  
    0.000000000000000e+00,  0.000000000000000e+00,  7.642673546157117e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr30 ( )

/******************************************************************************/
/*
  Purpose:

    SMR30 returns the SMR rule of degree 30.

  Discussion:
 
    DEGREE: 30
    XIAO-GIMBUTAS ESTIMATE: 166 MOELLER-RASPUTIN LOWER BOUND: 128
    POINTS CARDINALITY: 167
    NORM INF MOMS. RESIDUAL: 4.44089e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR30[3*167], the requested rule.
*/
{
  const int degree = 30;
  int order;
  double xw[3*167] = {
     -9.962695953022117e-01, -4.432378837780777e-01,  3.892630177515625e-03,  
     -9.954114173626548e-01,  2.643526556843364e-01,  4.534201620636273e-03,  
     -9.949269819594637e-01,  5.811458193160586e-01,  3.690610442210943e-03,  
     -9.947791036081476e-01, -8.855392187642179e-02,  4.945989612847814e-03,  
     -9.940513238712086e-01, -9.629012381127487e-01,  1.529980279640927e-03,  
     -9.937009284888235e-01, -7.963627749974038e-01,  3.806704824353705e-03,  
     -9.914129974533056e-01,  9.014542533695618e-01,  3.250642010093910e-03,  
     -9.912570981356938e-01,  9.920951313914597e-01,  7.737085001637529e-04,  
     -9.823632199537923e-01,  7.480690374805677e-01,  7.178107249226476e-03,  
     -9.774418651328238e-01, -6.195633189134538e-01,  1.012484081798108e-02,  
     -9.706544108267556e-01, -2.729784055929617e-01,  1.355763804090731e-02,  
     -9.703903424063889e-01, -9.055390715558742e-01,  3.812394374457089e-03,  
     -9.694574072185448e-01,  4.341328372213230e-01,  1.266804574330651e-02,  
     -9.690407115962437e-01,  9.341819736700314e-02,  1.394979228044907e-02,  
     -9.628802671374306e-01, -9.944496567185225e-01,  1.467879560257003e-03,  
     -9.527399448624597e-01,  9.624994157286473e-01,  5.260700927456429e-03,  
     -9.514132521336506e-01, -8.829098392211954e-01,  4.907118941168890e-03,  
     -9.345046955574380e-01,  8.387639945783492e-01,  1.172001054121250e-02,  
     -9.297146520577916e-01,  6.183698468095432e-01,  1.825632348450637e-02,  
     -9.293314444347445e-01, -7.435030197515320e-01,  1.482615873422928e-02,  
     -9.260149110397602e-01, -4.576849499932223e-01,  2.118348083720268e-02,  
     -9.191878620227047e-01, -8.576798396420104e-02,  2.272620841149477e-02,  
     -9.158350185631037e-01,  2.692275128511369e-01,  2.304963366190331e-02,  
     -9.100695669977138e-01, -9.705559713759557e-01,  3.389088115670371e-03,  
     -8.849735191782050e-01, -9.517932989228655e-01,  5.364563594773305e-03,  
     -8.808666812238437e-01,  9.943730059848226e-01,  2.875519471334203e-03,  
     -8.595716686462112e-01,  9.162278791175735e-01,  1.277710664857529e-02,  
     -8.534233518158184e-01, -8.449957910924649e-01,  1.658096280776431e-02,  
     -8.532333609215695e-01, -2.640000860004303e-01,  2.911278919189067e-02,  
     -8.500329899131518e-01,  4.606540637675913e-01,  2.965001937514069e-02,  
     -8.500143920229317e-01, -6.082069619792305e-01,  2.645748804192720e-02,  
     -8.454025250745086e-01,  7.354238754987793e-01,  2.316800651593019e-02,  
     -8.367229347951246e-01,  8.990264524394226e-02,  3.373621057431971e-02,  
     -8.001347673092866e-01, -9.933648582561806e-01,  3.850587028399502e-03,  
     -7.695116274930011e-01, -4.118889027088976e-01,  3.034893498538439e-02,  
     -7.555576680657612e-01,  9.700425147325877e-01,  1.014999644279535e-02,  
     -7.538647716837412e-01, -9.239685866946878e-01,  1.517356711708827e-02,  
     -7.462990724884444e-01, -7.378827886824465e-01,  2.842931310687195e-02,  
     -7.435929466472898e-01,  2.881630895110476e-01,  4.096030346800239e-02,  
     -7.367231344637399e-01,  8.391743049717729e-01,  2.371595352428025e-02,  
     -7.360783333119556e-01,  5.954890113834164e-01,  3.505479981673820e-02,  
     -7.358357631903044e-01, -9.719765309238697e-02,  4.351226764743989e-02,  
     -6.784458770150876e-01, -5.334164281651258e-01,  2.989403195373217e-02,  
     -6.323142754086236e-01, -9.756719768853687e-01,  1.050599811708168e-02,  
     -6.187413218331049e-01,  9.957562917639060e-01,  3.877141507331312e-03,  
     -6.185869146576074e-01, -8.450016714647949e-01,  2.679921705344681e-02,  
     -6.169842175479411e-01,  1.078804071378743e-01,  5.004167045667424e-02,  
     -6.111438437236484e-01, -2.769425577256663e-01,  4.921646796209538e-02,  
     -6.028539652311193e-01,  7.224797085796002e-01,  3.569438969843478e-02,  
     -6.024568031179428e-01,  9.184105677646670e-01,  2.045602682082065e-02,  
     -6.005929876780286e-01,  4.366655576377152e-01,  4.708714185331756e-02,  
     -5.721476752159514e-01, -6.455779128450227e-01,  3.324435055130232e-02,  
     -4.821587643276321e-01, -6.552912695280060e-02,  5.000579378842215e-02,  
     -4.693508512146036e-01, -9.251514364207605e-01,  2.156482363680663e-02,  
     -4.664112078735353e-01, -4.442366390500550e-01,  5.080565593127764e-02,  
     -4.618665119648193e-01, -9.967579491010828e-01,  3.816748009617544e-03,  
     -4.494143273856875e-01,  8.276470129494764e-01,  3.214308262649934e-02,  
     -4.479160038776199e-01,  9.719485124728899e-01,  1.285989649810473e-02,  
     -4.448715957603111e-01,  5.834707035806619e-01,  4.762439584447587e-02,  
     -4.443814635842437e-01,  2.635713157455042e-01,  5.794249352621746e-02,  
     -4.396198113354752e-01, -7.548969208964118e-01,  3.428224841661166e-02,  
     -3.657940226461420e-01, -2.006533706330268e-01,  3.755546975167398e-02,  
     -3.068381707303870e-01, -5.934274157892239e-01,  4.806217780828576e-02,  
     -2.967415958337351e-01,  9.138477267737024e-01,  2.179374136407983e-02,  
     -2.843623923239886e-01, -9.723235086081026e-01,  1.370404412777051e-02,  
     -2.841773158810993e-01, -8.502214939557524e-01,  3.069486488068529e-02,  
     -2.774502955157072e-01,  7.783800443548269e-02,  6.485367831170855e-02,  
     -2.754822583044234e-01,  7.120414326285063e-01,  4.331711859331076e-02,  
     -2.687871739273696e-01,  4.269851621611526e-01,  5.836353670839110e-02,  
     -2.567436168928061e-01,  9.945360458235195e-01,  5.240836616582418e-03,  
     -2.513499007569119e-01, -3.210828524214602e-01,  4.844638715484986e-02,  
     -1.598590614299937e-01,  8.482252908489760e-01,  1.682030776305622e-02,  
     -1.427799257579916e-01, -7.170460184955041e-01,  3.915904236744100e-02,  
     -1.091853236351570e-01,  9.580261183543186e-01,  1.474658041347025e-02,  
     -1.022992873259765e-01, -1.104785543258961e-01,  6.661932528640521e-02,  
     -1.015416677161510e-01, -9.200676756186152e-01,  2.329668513832093e-02,  
     -9.412889158601399e-02, -4.688846642550997e-01,  5.469210938337690e-02,  
     -8.907000954456333e-02,  2.513213963693643e-01,  6.571594126284511e-02,  
     -8.744029029762249e-02,  5.785381919572421e-01,  5.300724353175888e-02,  
     -7.712410713884485e-02, -9.943194119246959e-01,  5.499112875651152e-03,  
     -6.523473573640569e-02,  7.983102424409952e-01,  2.517854943448727e-02,  
     -1.095721736720509e-02, -7.962228644585386e-01,  2.085587531389086e-02,  
     2.518303411594268e-02,  9.860853647300887e-01,  6.488533578084030e-03,  
     6.649367018609328e-02,  8.934359950937619e-01,  2.271313073139822e-02,  
     7.864093675987820e-02, -2.918181793455348e-01,  6.374671736339137e-02,  
     8.230594852824862e-02, -6.128716323876445e-01,  5.036688164272618e-02,  
     8.994595584407042e-02,  6.378488548700582e-02,  6.747055946750249e-02,  
     9.331414467274024e-02,  4.264112897435890e-01,  5.762076485371190e-02,  
     1.036274934285688e-01, -9.654170079830869e-01,  1.528097665571535e-02,  
     1.062379679357248e-01,  7.045294352966426e-01,  4.336208027576573e-02,  
     1.070563588959354e-01, -8.518818738785342e-01,  2.527278435887043e-02,  
     1.702241024982263e-01,  9.972150656853269e-01,  2.645999354440326e-03,  
     1.941498146775931e-01,  9.416958566669819e-01,  1.299271762491835e-02,  
     2.382851494989787e-01,  2.794121411070278e-01,  3.900619436018987e-02,  
     2.597216208260207e-01, -4.600772470944473e-01,  5.666664739064187e-02,  
     2.633608715116675e-01, -7.382703813686664e-01,  4.094242606634930e-02,  
     2.680422728449567e-01, -1.237008749685800e-01,  6.430917939062639e-02,  
     2.709535102430495e-01, -9.946277851787007e-01,  4.995330134500549e-03,  
     2.717768185055764e-01,  8.206386870412736e-01,  3.322490081159339e-02,  
     2.860865029604455e-01,  5.750046796390000e-01,  5.163715243954464e-02,  
     2.919629207724195e-01, -9.126523283762582e-01,  2.290547444002006e-02,  
     3.221994725736586e-01,  9.739873036170995e-01,  9.709787500403095e-03,  
     3.238916864531801e-01,  1.871152636079638e-01,  3.786953410800285e-02,  
     4.326883824490022e-01,  9.054252916722543e-01,  2.179426150033381e-02,  
     4.334112862933560e-01, -6.113886295669552e-01,  4.619739021387417e-02,  
     4.393894435610020e-01, -3.042985645127746e-01,  5.679993404477694e-02,  
     4.457707596424073e-01,  4.135856200591693e-01,  5.369039030443149e-02,  
     4.480222422807119e-01, -9.699096000438506e-01,  1.284524266997323e-02,  
     4.481245405662154e-01,  7.226095819651619e-01,  3.875267371369672e-02,  
     4.548106144879556e-01, -8.323081975450645e-01,  3.014220006377240e-02,  
     4.581780858586828e-01,  3.469977407352812e-02,  5.500861406890217e-02,  
     4.703860920439117e-01,  9.947418373536940e-01,  3.780014001903630e-03,  
     5.804007745393400e-01,  9.618079992566787e-01,  1.161053553740031e-02,  
     5.833354854251170e-01,  5.930231848340044e-01,  3.799033003205411e-02,  
     5.930856097062387e-01,  2.373877943575770e-01,  5.084589261923814e-02,  
     5.965641353176369e-01, -4.730726160978409e-01,  4.627028009154758e-02,  
     6.019409638213139e-01,  8.388951235924025e-01,  2.676118014960469e-02,  
     6.025337137784932e-01, -1.408542441091471e-01,  4.904466589737274e-02,  
     6.035685372806677e-01, -9.184860893047954e-01,  1.930940686592521e-02,  
     6.054544565337695e-01, -9.957236600655665e-01,  3.768877425809975e-03,  
     6.057207734020840e-01, -7.322512010108688e-01,  3.339567747677206e-02,  
     6.875670307888612e-01,  4.627278058070344e-01,  2.947065495054275e-02,  
     7.023177466590736e-01,  9.928205536558483e-01,  3.885728390925337e-03,  
     7.195170980700635e-01,  7.305873329417671e-01,  2.847807814619499e-02,  
     7.238446910374424e-01,  5.561690048457465e-02,  4.419832996135477e-02,  
     7.240210652949475e-01, -3.007014261972007e-01,  3.439575422315153e-02,  
     7.371020667711963e-01,  9.252595362582127e-01,  1.536785201342859e-02,  
     7.384195707426535e-01, -8.438380733571678e-01,  2.235510768691872e-02,  
     7.405499034588905e-01, -6.188990137603514e-01,  3.246295613758222e-02,  
     7.440604692168796e-01, -9.713408547253161e-01,  9.607479120263517e-03,  
     7.685900922442980e-01,  3.465057508910690e-01,  2.776338673026480e-02,  
     7.954329735534109e-01, -4.109341533557886e-01,  1.857369110661608e-02,  
     8.140461518894649e-01,  5.964637576338830e-01,  2.604275460103966e-02,  
     8.298209513184971e-01,  8.417188363600208e-01,  1.770911353888088e-02,  
     8.337255108415906e-01, -1.237521420338796e-01,  3.477363818844623e-02,  
     8.450338467672839e-01,  9.803989034344278e-01,  6.318914249788773e-03,  
     8.499053424569023e-01, -7.513598048680518e-01,  2.131459811435620e-02,  
     8.505494208495452e-01,  2.034903566768354e-01,  2.898559224509574e-02,  
     8.534375448038033e-01, -9.226288272371441e-01,  1.212457346099878e-02,  
     8.655964520277111e-01, -9.954157466834472e-01,  2.574302443652325e-03,  
     8.685850946711341e-01, -5.228140183251604e-01,  2.217355893689261e-02,  
     8.943292225583946e-01,  4.595261118728072e-01,  2.187541877465294e-02,  
     9.006171857996548e-01,  7.180830553785196e-01,  1.636671200905273e-02,  
     9.075612511758971e-01,  9.205481097893897e-01,  7.889096906380533e-03,  
     9.108243128554621e-01, -3.093255095271237e-01,  2.247790975299426e-02,  
     9.242976221883992e-01,  4.079387457619278e-02,  2.269368117980306e-02,  
     9.336780332840566e-01, -8.547607055279791e-01,  1.092484696375260e-02,  
     9.387265328139205e-01, -6.592057435752858e-01,  1.490210373726517e-02,  
     9.446037800832677e-01, -9.693489449953010e-01,  4.898536170872587e-03,  
     9.479408185885666e-01,  9.575588886071763e-01,  2.997578905083853e-03,  
     9.495353577945340e-01,  3.186288923971684e-01,  1.513823435852647e-02,  
     9.520042531581182e-01,  9.980612732198122e-01,  1.202725556369299e-03,  
     9.525533437955715e-01,  8.141508738554407e-01,  8.188829215294804e-03,  
     9.641212854564828e-01,  5.940993549166920e-01,  1.301642639806175e-02,  
     9.664957432070073e-01, -1.581005636616589e-01,  1.326365917546207e-02,  
     9.683352852913805e-01, -4.679098763469015e-01,  1.225127303731581e-02,  
     9.842518603414726e-01,  1.836896830126595e-01,  8.499315253887113e-03,  
     9.846619943535420e-01, -7.799717728866817e-01,  5.965044619806711e-03,  
     9.852422761112879e-01,  8.861974810453618e-01,  3.934308818294981e-03,  
     9.891880847194036e-01, -9.191530362600531e-01,  3.253203726665571e-03,  
     9.897009343507575e-01, -9.931297876049714e-01,  7.600893882678305e-04,  
     9.922603853169076e-01,  9.719335327349238e-01,  1.435167883917694e-03,  
     9.936305551862550e-01, -1.510608205895069e-02,  4.418790732679170e-03,  
     9.941000705774204e-01,  4.425041797515226e-01,  5.144918479154803e-03,  
     9.941101780466588e-01,  7.280757215015392e-01,  3.867855257271212e-03,  
     9.950172763856067e-01, -6.114888124308911e-01,  3.581501248642710e-03,  
     9.951171305214461e-01, -3.168085664517462e-01,  4.336888090484613e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr31 ( )

/******************************************************************************/
/*
  Purpose:

    SMR31 returns the SMR rule of degree 31.

  Discussion:
 
   DEGREE: 31
    POINTS CARDINALITY: 172
    NORM INF MOMS. RESIDUAL: 2.07733e-16
    SUM NEGATIVE WEIGHTS: 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR31[3*172], the requested rule.
*/
{
  const int degree = 31;
  int order;
  double xw[3*172] = {
-9.955496296346447e-01, -2.757893737712724e-02,  3.952828126515200e-03,  
 -9.952093636515903e-01,  3.078672596656606e-01,  4.465674926565594e-03,  
 -9.949219293696708e-01, -4.293313749761587e-01,  4.734653786951149e-03,  
 -9.947777289433332e-01,  6.082007753656643e-01,  3.687083706716762e-03,  
 -9.947711657807963e-01, -7.291135575065112e-01,  3.567753282746309e-03,  
 -9.898665478412323e-01,  9.927280498683013e-01,  7.900353557535870e-04,  
 -9.896201133119824e-01,  9.148303804608103e-01,  3.248339703605548e-03,  
 -9.894221797194233e-01, -8.963309110540300e-01,  2.680927365865937e-03,  
 -9.891613515312806e-01, -9.745514901909140e-01,  1.655992514072826e-03,  
 -9.847115459075805e-01,  7.760597415217361e-01,  5.791133619187665e-03,  
 -9.822216835749852e-01, -1.858981354343795e-01,  6.958199118327337e-03,  
 -9.688290280461213e-01,  1.346435658626332e-01,  1.394269523344841e-02,  
 -9.681141160941403e-01,  4.618217642366224e-01,  1.249777398451523e-02,  
 -9.680653032337156e-01, -5.892528308394193e-01,  1.229021380297149e-02,  
 -9.621105113004819e-01, -8.293868331873653e-01,  7.471001060877273e-03,  
 -9.565888110363844e-01, -2.955138587991344e-01,  1.254260666301101e-02,  
 -9.469790068617381e-01, -9.968106327216375e-01,  1.362946951896202e-03,  
 -9.464971595212447e-01,  9.668261260754121e-01,  5.057521838548747e-03,  
 -9.404074979033311e-01,  6.594952112812067e-01,  1.377422226180171e-02,  
 -9.386071275818250e-01, -9.447266737672761e-01,  4.408092682116897e-03,  
 -9.340283957363398e-01,  8.488905145274273e-01,  1.096662540259541e-02,  
 -9.198052061978775e-01, -5.136717870605163e-02,  2.325563069027812e-02,  
 -9.125069846160752e-01,  2.965175005985400e-01,  2.317349030282014e-02,  
 -9.123983052278903e-01, -7.247489113905282e-01,  1.632786836774140e-02,  
 -9.068677187647651e-01, -4.445873104662686e-01,  2.188675357029590e-02,  
 -9.055659136341394e-01, -9.175374320754922e-01,  5.491385731273308e-03,  
 -8.774069425333418e-01,  5.321738640857572e-01,  1.982544206254361e-02,  
 -8.706320657782287e-01,  9.948789461128177e-01,  2.722659841902658e-03,  
 -8.559872594373867e-01,  9.178926105523973e-01,  1.239374987476905e-02,  
 -8.487413771127457e-01,  7.442213847925441e-01,  2.151797328509033e-02,  
 -8.475645530398180e-01, -2.209115672323100e-01,  2.832498125828596e-02,  
 -8.449119525088070e-01, -9.790174363372415e-01,  6.490465735794747e-03,  
 -8.388493423999792e-01, -8.442105015209006e-01,  1.741719558530361e-02,  
 -8.320878189683433e-01,  1.145771146767555e-01,  3.439308836971967e-02,  
 -8.290267482829156e-01, -5.972601809233826e-01,  2.702368742037717e-02,  
 -8.034575695173080e-01,  4.094748377144478e-01,  2.509623581221141e-02,  
 -7.760357257316899e-01, -3.548922765484357e-01,  2.268460217050950e-02,  
 -7.509248997072229e-01,  9.692871949519603e-01,  9.979338077119586e-03,  
 -7.387062791288017e-01,  8.375261790603876e-01,  2.279562252991799e-02,  
 -7.382550697652832e-01,  6.100825289389331e-01,  3.294515892662506e-02,  
 -7.363260972595160e-01, -9.253776418251520e-01,  1.584321780127163e-02,  
 -7.298334096260589e-01, -7.360653624762051e-01,  2.903866461556321e-02,  
 -7.251547137883499e-01, -6.996863675606819e-02,  4.370775795972342e-02,  
 -7.113581145093257e-01,  2.702313355967329e-01,  3.714680586412551e-02,  
 -7.071807441641457e-01, -9.944876613499617e-01,  3.480514785349274e-03,  
 -7.039820156247814e-01, -4.654525806221809e-01,  3.069975493264972e-02,  
 -6.184086297782805e-01,  9.955258965189302e-01,  3.881568620917195e-03,  
 -6.077218310997582e-01,  9.148419450019303e-01,  1.991703166278273e-02,  
 -6.034954341682667e-01,  7.237932367497814e-01,  3.389141507458358e-02,  
 -6.013041765209197e-01, -8.425771299300596e-01,  2.713141610820029e-02,  
 -5.995171839175090e-01,  4.575307437971686e-01,  4.553732637405976e-02,  
 -5.987747492273197e-01, -2.555243484270794e-01,  5.002646306167845e-02,  
 -5.927778548664734e-01, -6.036103424582507e-01,  3.911054484449386e-02,  
 -5.901440107668018e-01,  1.060198712260184e-01,  4.821287790488322e-02,  
 -5.784913015945842e-01, -9.666586674693635e-01,  1.173664788888666e-02,  
 -4.588198301439419e-01,  9.693486333009571e-01,  1.313666284266309e-02,  
 -4.567271123348693e-01,  8.253817273249296e-01,  3.056135412459628e-02,  
 -4.537069399424983e-01, -4.303216184624180e-01,  5.246566824474671e-02,  
 -4.528331550744691e-01, -6.765968580901423e-02,  5.225928157201407e-02,  
 -4.472686223717481e-01, -7.308744706376724e-01,  3.864973973872291e-02,  
 -4.434291687664805e-01,  2.865506865407869e-01,  5.621007974099101e-02,  
 -4.406325252658753e-01, -9.951861574277165e-01,  3.942690951645789e-03,  
 -4.393137941615871e-01,  5.923410411408412e-01,  4.592935024129758e-02,  
 -4.286656345744738e-01, -9.110553186427821e-01,  2.189185972353471e-02,  
 -3.378031689425344e-01, -2.004187762207998e-01,  2.823318588167162e-02,  
 -3.044251614615452e-01,  9.086361595553306e-01,  2.309284749670321e-02,  
 -2.928456536563019e-01, -9.712927609897977e-01,  1.017404407973292e-02,  
 -2.912502627343641e-01, -5.842088648173278e-01,  4.974674817513107e-02,  
 -2.811322114845757e-01,  9.943304190452436e-01,  5.253366355617619e-03,  
 -2.766540265223294e-01,  7.185096774489679e-01,  4.096115975792532e-02,  
 -2.748922538693097e-01,  1.033654937792176e-01,  6.398840590311936e-02,  
 -2.658691893989600e-01, -8.278100124889359e-01,  3.306728584127568e-02,  
 -2.638448388909397e-01,  4.383380334499116e-01,  5.665306321736824e-02,  
 -2.509255177911933e-01, -2.932348684939356e-01,  4.608256320492199e-02,  
 -1.873924507634162e-01, -9.941405263712252e-01,  2.154767334708834e-03,  
 -1.623725117112911e-01, -9.393770105705175e-01,  1.234737326017698e-02,  
 -1.321095433217891e-01,  8.321796504932829e-01,  2.707477268062864e-02,  
 -1.248486574319150e-01,  9.596829430320998e-01,  1.572343508516491e-02,  
 -1.160794606213587e-01, -7.051458563086379e-01,  3.871928288060491e-02,  
 -9.862627315703923e-02, -8.426927609780714e-02,  6.684928152189812e-02,  
 -9.324738040737274e-02, -4.443546718135858e-01,  5.655998204740964e-02,  
 -9.000433791884935e-02,  5.901154946888999e-01,  5.092306051816564e-02,  
 -8.193230202578333e-02,  2.677472052197009e-01,  6.437330348690143e-02,  
 -4.921447280582370e-02, -8.948195724899560e-01,  2.115122029930462e-02,  
 -2.766233245972495e-02, -9.904468342292223e-01,  6.140727614369517e-03,  
 -1.010525418227002e-02,  7.724429823094344e-01,  1.672977767715024e-02,  
 1.010525418227002e-02, -7.724429823094344e-01,  1.672977767715024e-02,  
 2.766233245972495e-02,  9.904468342292223e-01,  6.140727614369517e-03,  
 4.921447280582370e-02,  8.948195724899560e-01,  2.115122029930462e-02,  
 8.193230202578333e-02, -2.677472052197009e-01,  6.437330348690143e-02,  
 9.000433791884935e-02, -5.901154946888999e-01,  5.092306051816564e-02,  
 9.324738040737274e-02,  4.443546718135858e-01,  5.655998204740964e-02,  
 9.862627315703923e-02,  8.426927609780714e-02,  6.684928152189812e-02,  
 1.160794606213587e-01,  7.051458563086379e-01,  3.871928288060491e-02,  
 1.248486574319150e-01, -9.596829430320998e-01,  1.572343508516491e-02,  
 1.321095433217891e-01, -8.321796504932829e-01,  2.707477268062864e-02,  
 1.623725117112911e-01,  9.393770105705175e-01,  1.234737326017698e-02,  
 1.873924507634162e-01,  9.941405263712252e-01,  2.154767334708834e-03,  
 2.509255177911933e-01,  2.932348684939356e-01,  4.608256320492199e-02,  
 2.638448388909397e-01, -4.383380334499116e-01,  5.665306321736824e-02,  
 2.658691893989600e-01,  8.278100124889359e-01,  3.306728584127568e-02,  
 2.748922538693097e-01, -1.033654937792176e-01,  6.398840590311936e-02,  
 2.766540265223294e-01, -7.185096774489679e-01,  4.096115975792532e-02,  
 2.811322114845757e-01, -9.943304190452436e-01,  5.253366355617619e-03,  
 2.912502627343641e-01,  5.842088648173278e-01,  4.974674817513107e-02,  
 2.928456536563019e-01,  9.712927609897977e-01,  1.017404407973292e-02,  
 3.044251614615452e-01, -9.086361595553306e-01,  2.309284749670321e-02,  
 3.378031689425344e-01,  2.004187762207998e-01,  2.823318588167162e-02,  
 4.286656345744738e-01,  9.110553186427821e-01,  2.189185972353471e-02,  
 4.393137941615871e-01, -5.923410411408412e-01,  4.592935024129758e-02,  
 4.406325252658753e-01,  9.951861574277165e-01,  3.942690951645789e-03,  
 4.434291687664805e-01, -2.865506865407869e-01,  5.621007974099101e-02,  
 4.472686223717481e-01,  7.308744706376724e-01,  3.864973973872291e-02,  
 4.528331550744691e-01,  6.765968580901423e-02,  5.225928157201407e-02,  
 4.537069399424983e-01,  4.303216184624180e-01,  5.246566824474671e-02,  
 4.567271123348693e-01, -8.253817273249296e-01,  3.056135412459628e-02,  
 4.588198301439419e-01, -9.693486333009571e-01,  1.313666284266309e-02,  
 5.784913015945842e-01,  9.666586674693635e-01,  1.173664788888666e-02,  
 5.901440107668018e-01, -1.060198712260184e-01,  4.821287790488322e-02,  
 5.927778548664734e-01,  6.036103424582507e-01,  3.911054484449386e-02,  
 5.987747492273197e-01,  2.555243484270794e-01,  5.002646306167845e-02,  
 5.995171839175090e-01, -4.575307437971686e-01,  4.553732637405976e-02,  
 6.013041765209197e-01,  8.425771299300596e-01,  2.713141610820029e-02,  
 6.034954341682667e-01, -7.237932367497814e-01,  3.389141507458358e-02,  
 6.077218310997582e-01, -9.148419450019303e-01,  1.991703166278273e-02,  
 6.184086297782805e-01, -9.955258965189302e-01,  3.881568620917195e-03,  
 7.039820156247814e-01,  4.654525806221809e-01,  3.069975493264972e-02,  
 7.071807441641457e-01,  9.944876613499617e-01,  3.480514785349274e-03,  
 7.113581145093257e-01, -2.702313355967329e-01,  3.714680586412551e-02,  
 7.251547137883499e-01,  6.996863675606819e-02,  4.370775795972342e-02,  
 7.298334096260589e-01,  7.360653624762051e-01,  2.903866461556321e-02,  
 7.363260972595160e-01,  9.253776418251520e-01,  1.584321780127163e-02,  
 7.382550697652832e-01, -6.100825289389331e-01,  3.294515892662506e-02,  
 7.387062791288017e-01, -8.375261790603876e-01,  2.279562252991799e-02,  
 7.509248997072229e-01, -9.692871949519603e-01,  9.979338077119586e-03,  
 7.760357257316899e-01,  3.548922765484357e-01,  2.268460217050950e-02,  
 8.034575695173080e-01, -4.094748377144478e-01,  2.509623581221141e-02,  
 8.290267482829156e-01,  5.972601809233826e-01,  2.702368742037717e-02,  
 8.320878189683433e-01, -1.145771146767555e-01,  3.439308836971967e-02,  
 8.388493423999792e-01,  8.442105015209006e-01,  1.741719558530361e-02,  
 8.449119525088070e-01,  9.790174363372415e-01,  6.490465735794747e-03,  
 8.475645530398180e-01,  2.209115672323100e-01,  2.832498125828596e-02,  
 8.487413771127457e-01, -7.442213847925441e-01,  2.151797328509033e-02,  
 8.559872594373867e-01, -9.178926105523973e-01,  1.239374987476905e-02,  
 8.706320657782287e-01, -9.948789461128177e-01,  2.722659841902658e-03,  
 8.774069425333418e-01, -5.321738640857572e-01,  1.982544206254361e-02,  
 9.055659136341394e-01,  9.175374320754922e-01,  5.491385731273308e-03,  
 9.068677187647651e-01,  4.445873104662686e-01,  2.188675357029590e-02,  
 9.123983052278903e-01,  7.247489113905282e-01,  1.632786836774140e-02,  
 9.125069846160752e-01, -2.965175005985400e-01,  2.317349030282014e-02,  
 9.198052061978775e-01,  5.136717870605163e-02,  2.325563069027812e-02,  
 9.340283957363398e-01, -8.488905145274273e-01,  1.096662540259541e-02,  
 9.386071275818250e-01,  9.447266737672761e-01,  4.408092682116897e-03,  
 9.404074979033311e-01, -6.594952112812067e-01,  1.377422226180171e-02,  
 9.464971595212447e-01, -9.668261260754121e-01,  5.057521838548747e-03,  
 9.469790068617381e-01,  9.968106327216375e-01,  1.362946951896202e-03,  
 9.565888110363844e-01,  2.955138587991344e-01,  1.254260666301101e-02,  
 9.621105113004819e-01,  8.293868331873653e-01,  7.471001060877273e-03,  
 9.680653032337156e-01,  5.892528308394193e-01,  1.229021380297149e-02,  
 9.681141160941403e-01, -4.618217642366224e-01,  1.249777398451523e-02,  
 9.688290280461213e-01, -1.346435658626332e-01,  1.394269523344841e-02,  
 9.822216835749852e-01,  1.858981354343795e-01,  6.958199118327337e-03,  
 9.847115459075805e-01, -7.760597415217361e-01,  5.791133619187665e-03,  
 9.891613515312806e-01,  9.745514901909140e-01,  1.655992514072826e-03,  
 9.894221797194233e-01,  8.963309110540300e-01,  2.680927365865937e-03,  
 9.896201133119824e-01, -9.148303804608103e-01,  3.248339703605548e-03,  
 9.898665478412323e-01, -9.927280498683013e-01,  7.900353557535870e-04,  
 9.947711657807963e-01,  7.291135575065112e-01,  3.567753282746309e-03,  
 9.947777289433332e-01, -6.082007753656643e-01,  3.687083706716762e-03,  
 9.949219293696708e-01,  4.293313749761587e-01,  4.734653786951149e-03,  
 9.952093636515903e-01, -3.078672596656606e-01,  4.465674926565594e-03,  
 9.955496296346447e-01,  2.757893737712724e-02,  3.952828126515200e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr31s ( )

/******************************************************************************/
/*
  Purpose:

    SMR31S returns the rotationally invariant SMR rule of degree 31.

  Discussion:
 
    DEGREE: 31
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 172
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 2.84496e-03,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR31S[3*172], the requested rule.
*/
{
  const int degree = 31;
  int order;
  double xw[3*172] = {
 -3.904806549599655e-02, -4.335393037614890e-02,  1.983961989686983e-02,  
 1.361882296394248e-01,  5.339885716159022e-01,  5.606290851087755e-02,  
 -6.237898572307624e-02,  6.650680443410015e-01,  4.954926631685492e-02,  
 1.043081290265589e-01,  7.978188386199707e-01,  3.954352049027991e-02,  
 8.175663994339752e-02,  9.536337842041479e-01,  1.819407316290299e-02,  
 1.326909285794375e-01,  9.985967754075993e-01,  2.198741271493517e-03,  
 3.573200269387108e-01,  3.083812309752531e-02,  6.275382718191864e-02,  
 1.711251846005631e-01,  2.023226798991783e-01,  6.312752392564865e-02,  
 3.301558760691319e-01,  3.890928730006515e-01,  5.784814622385932e-02,  
 2.990255438330413e-01,  6.899278622152941e-01,  4.599430975257399e-02,  
 2.743945607890017e-01,  8.969874117510032e-01,  2.722794626350406e-02,  
 2.930343597574347e-01,  9.866371893249537e-01,  7.297804329258834e-03,  
 4.811149130969350e-01,  5.627097593501477e-01,  4.813376158498228e-02,  
 4.577756563378687e-01,  8.164852603726748e-01,  3.369675352996792e-02,  
 4.576603028130140e-01,  9.581255271049165e-01,  1.483779460064700e-02,  
 5.011717697509331e-01,  9.967514621307949e-01,  1.375821755782986e-03,  
 5.066615476347207e-01,  2.279797220835331e-01,  5.617345067788202e-02,  
 6.414891770627443e-01,  4.165197368067110e-01,  4.637789988502160e-02,  
 6.218437939846863e-01,  7.124331860455828e-01,  3.611694132069662e-02,  
 6.189705671147399e-01,  9.055771549707593e-01,  2.142589064473523e-02,  
 6.257695254024579e-01,  9.920525612037021e-01,  4.604781337595676e-03,  
 7.773558757000041e-01,  2.587982643359955e-01,  3.995025536141079e-02,  
 7.602620921526432e-01,  5.866806545003377e-01,  3.454986715153591e-02,  
 8.080239490235996e-01,  7.466133969130114e-01, -7.112408612016088e-04,  
 7.578022960040215e-01,  8.250210799807152e-01,  2.415241529771807e-02,  
 7.572699136795021e-01,  9.658518182607879e-01,  1.066322723829567e-02,  
 8.838106230790593e-01,  9.517499798893064e-02,  3.021344380673574e-02,  
 8.690870146928319e-01,  4.428796688721532e-01,  2.841376547681653e-02,  
 8.664188675223524e-01,  7.215367573910633e-01,  2.259238404505909e-02,  
 8.662357931878873e-01,  9.115792712550360e-01,  1.298465964143997e-02,  
 8.668639312200342e-01,  9.955281129139882e-01,  2.678582771124035e-03,  
 9.464084279482877e-01,  2.901035303505874e-01,  1.924589937161483e-02,  
 9.432116671128417e-01,  5.914789709627410e-01,  1.601261396001407e-02,  
 9.621603453340629e-01,  7.421113162391834e-01,  2.850658278802631e-03,  
 9.424551010209468e-01,  8.371341836669535e-01,  1.039571899572164e-02,  
 9.455364284543073e-01,  9.674856486387888e-01,  5.118117255528941e-03,  
 9.860981807821748e-01,  1.062982665761813e-01,  8.507743310820945e-03,  
 9.968354200302058e-01,  2.730105297008364e-01,  1.865603977042027e-03,  
 9.874604632806666e-01,  4.594240145656220e-01,  7.587442385373269e-03,  
 9.914773043212965e-01,  6.790808250554563e-01,  3.856894243772012e-03,  
 9.892581143506071e-01,  7.901123155310413e-01,  2.579633577944600e-03,  
 9.893015185233809e-01,  9.146983422640488e-01,  3.312018439594244e-03,  
 9.898894503566366e-01,  9.925022404589151e-01,  7.995136114829527e-04,  
 4.335393037614890e-02, -3.904806549599655e-02,  1.983961989686983e-02,  
 -5.339885716159022e-01,  1.361882296394248e-01,  5.606290851087755e-02,  
 -6.650680443410015e-01, -6.237898572307624e-02,  4.954926631685492e-02,  
 -7.978188386199707e-01,  1.043081290265589e-01,  3.954352049027991e-02,  
 -9.536337842041479e-01,  8.175663994339752e-02,  1.819407316290299e-02,  
 -9.985967754075993e-01,  1.326909285794375e-01,  2.198741271493517e-03,  
 -3.083812309752531e-02,  3.573200269387108e-01,  6.275382718191864e-02,  
 -2.023226798991783e-01,  1.711251846005631e-01,  6.312752392564865e-02,  
 -3.890928730006515e-01,  3.301558760691319e-01,  5.784814622385932e-02,  
 -6.899278622152941e-01,  2.990255438330413e-01,  4.599430975257399e-02,  
 -8.969874117510032e-01,  2.743945607890017e-01,  2.722794626350406e-02,  
 -9.866371893249537e-01,  2.930343597574347e-01,  7.297804329258834e-03,  
 -5.627097593501477e-01,  4.811149130969350e-01,  4.813376158498228e-02,  
 -8.164852603726748e-01,  4.577756563378687e-01,  3.369675352996792e-02,  
 -9.581255271049165e-01,  4.576603028130140e-01,  1.483779460064700e-02,  
 -9.967514621307949e-01,  5.011717697509331e-01,  1.375821755782986e-03,  
 -2.279797220835331e-01,  5.066615476347207e-01,  5.617345067788202e-02,  
 -4.165197368067110e-01,  6.414891770627443e-01,  4.637789988502160e-02,  
 -7.124331860455828e-01,  6.218437939846863e-01,  3.611694132069662e-02,  
 -9.055771549707593e-01,  6.189705671147399e-01,  2.142589064473523e-02,  
 -9.920525612037021e-01,  6.257695254024579e-01,  4.604781337595676e-03,  
 -2.587982643359955e-01,  7.773558757000041e-01,  3.995025536141079e-02,  
 -5.866806545003377e-01,  7.602620921526432e-01,  3.454986715153591e-02,  
 -7.466133969130114e-01,  8.080239490235996e-01, -7.112408612016088e-04,  
 -8.250210799807152e-01,  7.578022960040215e-01,  2.415241529771807e-02,  
 -9.658518182607879e-01,  7.572699136795021e-01,  1.066322723829567e-02,  
 -9.517499798893064e-02,  8.838106230790593e-01,  3.021344380673574e-02,  
 -4.428796688721532e-01,  8.690870146928319e-01,  2.841376547681653e-02,  
 -7.215367573910633e-01,  8.664188675223524e-01,  2.259238404505909e-02,  
 -9.115792712550360e-01,  8.662357931878873e-01,  1.298465964143997e-02,  
 -9.955281129139882e-01,  8.668639312200342e-01,  2.678582771124035e-03,  
 -2.901035303505874e-01,  9.464084279482877e-01,  1.924589937161483e-02,  
 -5.914789709627410e-01,  9.432116671128417e-01,  1.601261396001407e-02,  
 -7.421113162391834e-01,  9.621603453340629e-01,  2.850658278802631e-03,  
 -8.371341836669535e-01,  9.424551010209468e-01,  1.039571899572164e-02,  
 -9.674856486387888e-01,  9.455364284543073e-01,  5.118117255528941e-03,  
 -1.062982665761813e-01,  9.860981807821748e-01,  8.507743310820945e-03,  
 -2.730105297008364e-01,  9.968354200302058e-01,  1.865603977042027e-03,  
 -4.594240145656220e-01,  9.874604632806666e-01,  7.587442385373269e-03,  
 -6.790808250554563e-01,  9.914773043212965e-01,  3.856894243772012e-03,  
 -7.901123155310413e-01,  9.892581143506071e-01,  2.579633577944600e-03,  
 -9.146983422640488e-01,  9.893015185233809e-01,  3.312018439594244e-03,  
 -9.925022404589151e-01,  9.898894503566366e-01,  7.995136114829527e-04,  
 3.904806549599655e-02,  4.335393037614890e-02,  1.983961989686983e-02,  
 -1.361882296394248e-01, -5.339885716159022e-01,  5.606290851087755e-02,  
 6.237898572307624e-02, -6.650680443410015e-01,  4.954926631685492e-02,  
 -1.043081290265589e-01, -7.978188386199707e-01,  3.954352049027991e-02,  
 -8.175663994339752e-02, -9.536337842041479e-01,  1.819407316290299e-02,  
 -1.326909285794375e-01, -9.985967754075993e-01,  2.198741271493517e-03,  
 -3.573200269387108e-01, -3.083812309752531e-02,  6.275382718191864e-02,  
 -1.711251846005631e-01, -2.023226798991783e-01,  6.312752392564865e-02,  
 -3.301558760691319e-01, -3.890928730006515e-01,  5.784814622385932e-02,  
 -2.990255438330413e-01, -6.899278622152941e-01,  4.599430975257399e-02,  
 -2.743945607890017e-01, -8.969874117510032e-01,  2.722794626350406e-02,  
 -2.930343597574347e-01, -9.866371893249537e-01,  7.297804329258834e-03,  
 -4.811149130969350e-01, -5.627097593501477e-01,  4.813376158498228e-02,  
 -4.577756563378687e-01, -8.164852603726748e-01,  3.369675352996792e-02,  
 -4.576603028130140e-01, -9.581255271049165e-01,  1.483779460064700e-02,  
 -5.011717697509331e-01, -9.967514621307949e-01,  1.375821755782986e-03,  
 -5.066615476347207e-01, -2.279797220835331e-01,  5.617345067788202e-02,  
 -6.414891770627443e-01, -4.165197368067110e-01,  4.637789988502160e-02,  
 -6.218437939846863e-01, -7.124331860455828e-01,  3.611694132069662e-02,  
 -6.189705671147399e-01, -9.055771549707593e-01,  2.142589064473523e-02,  
 -6.257695254024579e-01, -9.920525612037021e-01,  4.604781337595676e-03,  
 -7.773558757000041e-01, -2.587982643359955e-01,  3.995025536141079e-02,  
 -7.602620921526432e-01, -5.866806545003377e-01,  3.454986715153591e-02,  
 -8.080239490235996e-01, -7.466133969130114e-01, -7.112408612016088e-04,  
 -7.578022960040215e-01, -8.250210799807152e-01,  2.415241529771807e-02,  
 -7.572699136795021e-01, -9.658518182607879e-01,  1.066322723829567e-02,  
 -8.838106230790593e-01, -9.517499798893064e-02,  3.021344380673574e-02,  
 -8.690870146928319e-01, -4.428796688721532e-01,  2.841376547681653e-02,  
 -8.664188675223524e-01, -7.215367573910633e-01,  2.259238404505909e-02,  
 -8.662357931878873e-01, -9.115792712550360e-01,  1.298465964143997e-02,  
 -8.668639312200342e-01, -9.955281129139882e-01,  2.678582771124035e-03,  
 -9.464084279482877e-01, -2.901035303505874e-01,  1.924589937161483e-02,  
 -9.432116671128417e-01, -5.914789709627410e-01,  1.601261396001407e-02,  
 -9.621603453340629e-01, -7.421113162391834e-01,  2.850658278802631e-03,  
 -9.424551010209468e-01, -8.371341836669535e-01,  1.039571899572164e-02,  
 -9.455364284543073e-01, -9.674856486387888e-01,  5.118117255528941e-03,  
 -9.860981807821748e-01, -1.062982665761813e-01,  8.507743310820945e-03,  
 -9.968354200302058e-01, -2.730105297008364e-01,  1.865603977042027e-03,  
 -9.874604632806666e-01, -4.594240145656220e-01,  7.587442385373269e-03,  
 -9.914773043212965e-01, -6.790808250554563e-01,  3.856894243772012e-03,  
 -9.892581143506071e-01, -7.901123155310413e-01,  2.579633577944600e-03,  
 -9.893015185233809e-01, -9.146983422640488e-01,  3.312018439594244e-03,  
 -9.898894503566366e-01, -9.925022404589151e-01,  7.995136114829527e-04,  
 -4.335393037614890e-02,  3.904806549599655e-02,  1.983961989686983e-02,  
 5.339885716159022e-01, -1.361882296394248e-01,  5.606290851087755e-02,  
 6.650680443410015e-01,  6.237898572307624e-02,  4.954926631685492e-02,  
 7.978188386199707e-01, -1.043081290265589e-01,  3.954352049027991e-02,  
 9.536337842041479e-01, -8.175663994339752e-02,  1.819407316290299e-02,  
 9.985967754075993e-01, -1.326909285794375e-01,  2.198741271493517e-03,  
 3.083812309752531e-02, -3.573200269387108e-01,  6.275382718191864e-02,  
 2.023226798991783e-01, -1.711251846005631e-01,  6.312752392564865e-02,  
 3.890928730006515e-01, -3.301558760691319e-01,  5.784814622385932e-02,  
 6.899278622152941e-01, -2.990255438330413e-01,  4.599430975257399e-02,  
 8.969874117510032e-01, -2.743945607890017e-01,  2.722794626350406e-02,  
 9.866371893249537e-01, -2.930343597574347e-01,  7.297804329258834e-03,  
 5.627097593501477e-01, -4.811149130969350e-01,  4.813376158498228e-02,  
 8.164852603726748e-01, -4.577756563378687e-01,  3.369675352996792e-02,  
 9.581255271049165e-01, -4.576603028130140e-01,  1.483779460064700e-02,  
 9.967514621307949e-01, -5.011717697509331e-01,  1.375821755782986e-03,  
 2.279797220835331e-01, -5.066615476347207e-01,  5.617345067788202e-02,  
 4.165197368067110e-01, -6.414891770627443e-01,  4.637789988502160e-02,  
 7.124331860455828e-01, -6.218437939846863e-01,  3.611694132069662e-02,  
 9.055771549707593e-01, -6.189705671147399e-01,  2.142589064473523e-02,  
 9.920525612037021e-01, -6.257695254024579e-01,  4.604781337595676e-03,  
 2.587982643359955e-01, -7.773558757000041e-01,  3.995025536141079e-02,  
 5.866806545003377e-01, -7.602620921526432e-01,  3.454986715153591e-02,  
 7.466133969130114e-01, -8.080239490235996e-01, -7.112408612016088e-04,  
 8.250210799807152e-01, -7.578022960040215e-01,  2.415241529771807e-02,  
 9.658518182607879e-01, -7.572699136795021e-01,  1.066322723829567e-02,  
 9.517499798893064e-02, -8.838106230790593e-01,  3.021344380673574e-02,  
 4.428796688721532e-01, -8.690870146928319e-01,  2.841376547681653e-02,  
 7.215367573910633e-01, -8.664188675223524e-01,  2.259238404505909e-02,  
 9.115792712550360e-01, -8.662357931878873e-01,  1.298465964143997e-02,  
 9.955281129139882e-01, -8.668639312200342e-01,  2.678582771124035e-03,  
 2.901035303505874e-01, -9.464084279482877e-01,  1.924589937161483e-02,  
 5.914789709627410e-01, -9.432116671128417e-01,  1.601261396001407e-02,  
 7.421113162391834e-01, -9.621603453340629e-01,  2.850658278802631e-03,  
 8.371341836669535e-01, -9.424551010209468e-01,  1.039571899572164e-02,  
 9.674856486387888e-01, -9.455364284543073e-01,  5.118117255528941e-03,  
 1.062982665761813e-01, -9.860981807821748e-01,  8.507743310820945e-03,  
 2.730105297008364e-01, -9.968354200302058e-01,  1.865603977042027e-03,  
 4.594240145656220e-01, -9.874604632806666e-01,  7.587442385373269e-03,  
 6.790808250554563e-01, -9.914773043212965e-01,  3.856894243772012e-03,  
 7.901123155310413e-01, -9.892581143506071e-01,  2.579633577944600e-03,  
 9.146983422640488e-01, -9.893015185233809e-01,  3.312018439594244e-03,  
 9.925022404589151e-01, -9.898894503566366e-01,  7.995136114829527e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr32 ( )

/******************************************************************************/
/*
  Purpose:

    SMR32 returns the SMR rule of degree 32.

  Discussion:
 
    DEGREE: 32
    POINTS CARDINALITY: 189
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR32[3*189], the requested rule.
*/
{
  const int degree = 32;
  int order;
  double xw[3*189] = {
 -9.961443158376487e-01, -6.887572767977012e-01,  3.176265881806332e-03,  
 -9.955150539895966e-01,  6.626971407249244e-01,  3.280265060152129e-03,  
 -9.953673174806560e-01, -3.490320479685254e-02,  4.675890937959332e-03,  
 -9.953301148958117e-01,  8.868398804037936e-01,  2.284058312905218e-03,  
 -9.949536289138113e-01, -3.776956946778952e-01,  4.510771123627496e-03,  
 -9.947581001027488e-01,  3.329076528027972e-01,  4.813891020740236e-03,  
 -9.941343268456251e-01,  9.936112061216035e-01,  5.375112498857630e-04,  
 -9.932824877107631e-01, -9.089949394457987e-01,  2.496612709475389e-03,  
 -9.901718606538452e-01, -9.916407321742867e-01,  7.701138529293439e-04,  
 -9.751008630866578e-01,  5.195777161215037e-01,  9.359036791703322e-03,  
 -9.723977826522521e-01,  1.379087148825411e-01,  1.181986792189326e-02,  
 -9.716123205144245e-01, -8.031016796856173e-01,  7.898808335562373e-03,  
 -9.711842977478065e-01, -5.430726346303393e-01,  1.151176330250413e-02,  
 -9.704055489123288e-01,  7.804584258849506e-01,  8.644818596664990e-03,  
 -9.694199058988444e-01,  9.557067749284750e-01,  4.223280833025587e-03,  
 -9.683411874625077e-01, -2.103323587190609e-01,  1.388419379439329e-02,  
 -9.567808007888505e-01, -9.626987460709516e-01,  4.415431329419894e-03,  
 -9.437425354265615e-01,  4.414088771841401e-01,  6.832573539725157e-03,  
 -9.402218788200302e-01,  2.637892865469118e-01,  1.016860955591373e-02,  
 -9.217551019965182e-01,  8.766772417195136e-01,  1.065665181655526e-02,  
 -9.201345036606068e-01, -6.784459223365346e-01,  1.669398948968993e-02,  
 -9.187137927257295e-01, -8.800989100992515e-01,  9.591064623401077e-03,  
 -9.181947091905479e-01, -3.841738613909663e-01,  2.059591744256289e-02,  
 -9.181637384564565e-01,  6.508430144443661e-01,  1.797283563699723e-02,  
 -9.180866951945609e-01, -3.534323022121689e-02,  2.220774903033375e-02,  
 -9.162233942094903e-01,  9.905273384808887e-01,  2.842827696268136e-03,  
 -8.942375422053964e-01, -9.940021310654177e-01,  2.526325882162393e-03,  
 -8.925004548103099e-01,  3.675577608041817e-01,  1.740206879654378e-02,  
 -8.567376342667298e-01,  1.327464071241374e-01,  2.320747945421362e-02,  
 -8.527049285163805e-01, -5.173331471639295e-01,  1.823135215166509e-02,  
 -8.500346292659974e-01,  9.424744256560323e-01,  9.628825949603207e-03,  
 -8.495936622225249e-01, -9.366589616617220e-01,  8.808214017805906e-03,  
 -8.420958026145372e-01,  7.746496697546652e-01,  2.038980506805041e-02,  
 -8.405229008591695e-01, -2.146465103993396e-01,  3.115686395982564e-02,  
 -8.400130747502382e-01, -7.833828505922565e-01,  1.867972088056950e-02,  
 -8.251520015911556e-01,  5.249712695416556e-01,  2.828908020393419e-02,  
 -7.960746843247288e-01, -5.942990648607921e-01,  1.818720327698928e-02,  
 -7.884200501943553e-01,  2.431068089032147e-01,  2.161873511289656e-02,  
 -7.832198580393690e-01,  9.882893671904269e-01,  4.201313239030647e-03,  
 -7.691956377515223e-01, -9.767479568418154e-01,  6.899965676153335e-03,  
 -7.509072411287868e-01, -2.719575746898528e-02,  3.742043760045523e-02,  
 -7.427461156257692e-01,  8.707027609907575e-01,  1.919642121969817e-02,  
 -7.393846173049607e-01, -8.675695987661742e-01,  1.783672443816834e-02,  
 -7.351194183949288e-01, -3.774494681673472e-01,  3.738148314393595e-02,  
 -7.213398259926092e-01,  6.655990116514867e-01,  3.145176228542881e-02,  
 -7.120543004828920e-01,  3.695232160325304e-01,  3.307881993920563e-02,  
 -7.013785314229773e-01, -6.985386189309318e-01,  2.798941131398564e-02,  
 -6.889047528617022e-01,  9.602183527522339e-01,  7.162747081491355e-03,  
 -6.522280372437145e-01, -9.963873207253509e-01,  2.915037219722206e-03,  
 -6.294141334037263e-01, -9.321941144432188e-01,  1.469357873203910e-02,  
 -6.289236482231599e-01,  1.335531135944628e-01,  4.333999853931410e-02,  
 -6.250143551668971e-01, -1.909837821647839e-01,  4.450992385162815e-02,  
 -6.162479185474388e-01,  9.957592249563421e-01,  2.859071377057288e-03,  
 -6.099556060400831e-01, -5.265301674660628e-01,  3.737333144755796e-02,  
 -6.035692437775674e-01,  5.068951570189404e-01,  3.542431096817152e-02,  
 -5.957398931434491e-01,  7.867544741614058e-01,  2.991054273162196e-02,  
 -5.880720673778793e-01,  9.278338224868491e-01,  1.311047438579956e-02,  
 -5.642943955874409e-01, -8.045488845290898e-01,  2.887379909514902e-02,  
 -5.341453289511777e-01, -6.580308812592266e-01,  8.231881868308998e-03,  
 -5.037785265285627e-01,  2.911261252936324e-01,  4.463898222861209e-02,  
 -5.035520020780221e-01,  6.164678558380017e-01,  2.375628980516375e-02,  
 -4.988776272469410e-01, -9.742698071302808e-01,  9.972534732384969e-03,  
 -4.880950860424961e-01, -3.570330104924047e-01,  4.487865776129120e-02,  
 -4.782873763449944e-01, -3.311071102284526e-02,  4.988651815705654e-02,  
 -4.611263669660518e-01,  9.776538472171752e-01,  9.547170864365405e-03,  
 -4.460940172737087e-01, -5.617163266009875e-01,  1.057733340125433e-02,  
 -4.344215560289689e-01,  8.756198694104429e-01,  2.433238295221333e-02,  
 -4.303464547840762e-01, -6.717475726140401e-01,  3.186301410699670e-02,  
 -4.140771909387703e-01, -8.929909921505204e-01,  2.416865558364916e-02,  
 -4.106621334605041e-01,  6.984143047391834e-01,  2.962064813188227e-02,  
 -3.860009662973919e-01,  4.525655697932027e-01,  3.233946990986691e-02,  
 -3.484793436284917e-01, -9.955996498738462e-01,  3.793172976457341e-03,  
 -3.391951567840935e-01,  1.226820429084983e-01,  4.753908343744886e-02,  
 -3.357809356696743e-01, -2.224706747610833e-01,  4.615497828125666e-02,  
 -3.250278129966869e-01,  3.756115481576739e-01,  1.811254509132181e-02,  
 -3.056089159859502e-01, -4.920724555612009e-01,  4.554710841070758e-02,  
 -2.961214860982124e-01,  9.974527284699805e-01,  3.060823576685151e-03,  
 -2.847932366229927e-01, -7.838348732823106e-01,  3.404104052520678e-02,  
 -2.713478176538165e-01,  9.439481248438524e-01,  1.788329467008652e-02,  
 -2.623891895744691e-01,  7.934963660422401e-01,  3.215348099890328e-02,  
 -2.474541407740861e-01, -9.552431364916144e-01,  1.619837106218808e-02,  
 -2.350008942691768e-01,  5.720771765501166e-01,  4.318782866021313e-02,  
 -2.029577973797018e-01, -8.943368639764357e-02,  4.553097782784060e-02,  
 -1.990670168540228e-01,  2.443876445322615e-01,  4.110363868615158e-02,  
 -1.549456091317803e-01, -6.415558836799513e-01,  4.267610300710221e-02,  
 -1.347331997024815e-01, -3.592068358004468e-01,  5.074071162472863e-02,  
 -1.193212615110174e-01, -8.772608465003254e-01,  2.680897358145306e-02,  
 -9.608366181884005e-02,  8.811478309456120e-01,  2.657134265114752e-02,  
 -8.724674317423464e-02,  9.829741829813902e-01,  9.730625947232925e-03,  
 -8.357262181047176e-02,  4.013140117181199e-01,  4.841144500118764e-02,  
 -7.663657189401872e-02, -9.904382181654797e-01,  6.943274642780526e-03,  
 -7.506542665125431e-02,  6.928415737526518e-01,  4.014342124479778e-02,  
 -6.814560175398696e-02,  4.856261470453426e-02,  4.844065720660989e-02,  
 1.062473558727759e-02, -7.650288124962303e-01,  3.558799833293477e-02,  
 1.660017546118934e-02, -2.180239260173989e-01,  4.831607231731554e-02,  
 2.272453179480726e-02, -5.268496064565723e-01,  4.537055458358597e-02,  
 4.931212356041427e-02, -9.458603059209817e-01,  1.758790356906201e-02,  
 7.613140727060182e-02,  5.418798866250614e-01,  4.818153253307554e-02,  
 7.853294280823510e-02,  2.224042128166391e-01,  5.465464269071678e-02,  
 8.372125557287705e-02,  9.435131549853616e-01,  1.786409990626899e-02,  
 9.337887407842871e-02,  8.001140509910943e-01,  3.410288806782028e-02,  
 1.089074910813305e-01, -3.010076469468967e-02,  2.723309734230703e-02,  
 1.411908890075358e-01,  9.960717448990448e-01,  3.569321191002430e-03,  
 1.751413474655890e-01, -3.997261685283053e-01,  4.541750739879684e-02,  
 1.756054472282782e-01, -8.658339890881421e-01,  2.662577185951133e-02,  
 1.864598899283486e-01, -6.697382946526751e-01,  3.827435555232931e-02,  
 2.015902009534723e-01, -9.883931352101503e-01,  7.887679303175682e-03,  
 2.044045426953899e-01, -1.421919981535460e-01,  3.558139723631710e-02,  
 2.378932317489774e-01,  3.802228852670115e-01,  5.139141457782884e-02,  
 2.453419557836962e-01,  6.743539422739147e-01,  4.230440026330508e-02,  
 2.673924056388006e-01,  8.857386065554180e-01,  2.512168130932855e-02,  
 2.794321878522678e-01,  8.071672703911634e-02,  5.195889525876823e-02,  
 2.852750321228393e-01,  9.766942081801527e-01,  8.542384805675192e-03,  
 3.366919097882969e-01, -5.582614071904248e-01,  3.957781174651530e-02,  
 3.382140442187983e-01, -9.401781089769999e-01,  1.829722847974778e-02,  
 3.432642241169637e-01, -7.908855951561965e-01,  2.972251194098460e-02,  
 3.455152732870559e-01, -2.966429396872311e-01,  4.443118022793111e-02,  
 3.916837958172765e-01,  5.230067770696570e-01,  4.184441753133104e-02,  
 4.120040722413747e-01,  7.890179305884122e-01,  3.275969268754896e-02,  
 4.238156081215504e-01,  9.950429590804639e-01,  2.471843473128421e-03,  
 4.287156692418698e-01,  2.431531997648373e-01,  5.098740815593964e-02,  
 4.406392416503330e-01, -9.421351055228980e-02,  4.952434585624959e-02,  
 4.435754669288457e-01,  9.470031795306957e-01,  1.407985409716778e-02,  
 4.558595671892888e-01, -9.896709958176498e-01,  6.495456224860164e-03,  
 4.873417746475680e-01, -6.968841503239952e-01,  3.193924196689053e-02,  
 4.970448498999819e-01, -4.587836752559167e-01,  4.009098722323794e-02,  
 5.026246934476013e-01, -8.799728934510729e-01,  2.251236322931963e-02,  
 5.142480616051717e-01,  6.332295493966821e-01,  2.628145641746948e-02,  
 5.635007809294439e-01,  8.830661523985979e-01,  2.138158866985076e-02,  
 5.760177960925376e-01,  4.034390879812669e-01,  4.461725888680534e-02,  
 5.786951907000567e-01,  7.200913403128530e-02,  4.714224835011449e-02,  
 5.850240866763193e-01,  9.892820474952123e-01,  5.400839750748531e-03,  
 5.851379143554923e-01, -2.686399203625244e-01,  4.255109067146633e-02,  
 6.039149631797995e-01, -9.595657522395640e-01,  1.243029383620673e-02,  
 6.085940759319246e-01,  7.188102110043890e-01,  2.414801307071736e-02,  
 6.367455861073830e-01, -6.091087379827170e-01,  3.181043163725066e-02,  
 6.389771216716220e-01, -8.001263004879462e-01,  2.306016831136437e-02,  
 6.923848443111713e-01,  9.536668248480320e-01,  1.203359878310568e-02,  
 7.027796911591175e-01, -9.965270954213804e-01,  3.064467191573918e-03,  
 7.057525331398022e-01, -1.091230879464752e-01,  3.965634211274827e-02,  
 7.065644544049037e-01,  5.577016427729737e-01,  3.480317597803997e-02,  
 7.069599688705653e-01,  2.377081331437708e-01,  4.015277537380656e-02,  
 7.089592747680905e-01, -4.373982847931744e-01,  3.119546438021227e-02,  
 7.146942471573201e-01,  8.178315170110126e-01,  2.161251683469453e-02,  
 7.307538954522923e-01, -9.007096403390665e-01,  1.565402681403319e-02,  
 7.704504545341444e-01, -7.396567334921220e-01,  2.067477223680419e-02,  
 7.897818448390646e-01, -3.232780509941606e-01,  1.880267861755378e-02,  
 7.934484404832058e-01,  9.926504167490636e-01,  3.776050573673320e-03,  
 8.026728771155266e-01, -9.655537841075670e-01,  7.156659310810854e-03,  
 8.087651311032129e-01, -5.934295716161285e-01,  2.201032582341064e-02,  
 8.095585492822206e-01,  5.131014033000776e-02,  3.161252035941158e-02,  
 8.113041827662109e-01,  4.018532940895451e-01,  2.993617375756685e-02,  
 8.140746090133947e-01,  6.999506065348030e-01,  2.452891312211182e-02,  
 8.175220739845873e-01,  9.045678533269281e-01,  1.408878624403073e-02,  
 8.442244744987026e-01, -2.330660680257271e-01,  2.137248847571907e-02,  
 8.577022609864510e-01, -8.347496637512480e-01,  1.302733239156259e-02,  
 8.740997306450817e-01, -9.016947723266606e-01,  5.700088397798577e-03,  
 8.760720409171439e-01,  1.798424501465092e-01,  1.242534941969138e-02,  
 8.776595540145247e-01, -9.871736549700062e-01,  3.023298480841919e-03,  
 8.876770756008736e-01, -4.737591614279884e-01,  2.114261952758863e-02,  
 8.893257290546359e-01,  5.497239097424972e-01,  1.883916296392102e-02,  
 8.966119498774410e-01,  9.684306041089270e-01,  6.514509999621678e-03,  
 9.005134923798872e-01,  8.160726922491325e-01,  1.492277961359557e-02,  
 9.028454350969399e-01,  2.628603055474125e-01,  1.525753840078711e-02,  
 9.099332057150961e-01, -9.463222058681031e-02,  2.114989721521207e-02,  
 9.116851421787586e-01, -6.958768581382581e-01,  1.656213645188111e-02,  
 9.380791852794695e-01, -9.390761885813872e-01,  6.505278755513709e-03,  
 9.395276649285043e-01,  6.496946928511224e-01,  9.668304772455727e-03,  
 9.473470605468867e-01, -3.346050342634356e-01,  1.585630013135186e-02,  
 9.491070785582369e-01, -9.969373733490615e-01,  9.281179028714037e-04,  
 9.509854262005244e-01,  3.980404983361944e-01,  1.284569365696251e-02,  
 9.538750327616107e-01,  4.953599709321822e-02,  1.055872402608265e-02,  
 9.578780270631901e-01,  9.103067048312464e-01,  6.968260865746103e-03,  
 9.592991308680465e-01,  9.968731654931796e-01,  1.210463692085719e-03,  
 9.601302552519683e-01, -8.180789200488630e-01,  8.683841565713000e-03,  
 9.694392229219877e-01, -5.715033820344755e-01,  1.159851379681130e-02,  
 9.703910299123225e-01,  1.632899951759109e-01,  7.363467408097404e-03,  
 9.719159673797005e-01,  7.411274370572497e-01,  7.318477013269155e-03,  
 9.829103770479058e-01,  5.055355492737967e-01,  6.282928001932651e-03,  
 9.833554207795926e-01, -1.837381133019218e-01,  8.880000815180237e-03,  
 9.874031706544697e-01, -9.781008326752658e-01,  1.660786069380725e-03,  
 9.915132744979969e-01, -8.960126036794243e-01,  2.711324914646742e-03,  
 9.917024709452258e-01,  9.678533470873883e-01,  1.688735729327407e-03,  
 9.937579585467250e-01, -7.180615094407097e-01,  3.871787826906220e-03,  
 9.940901871599539e-01,  8.430528621092570e-01,  2.741339818214634e-03,  
 9.941340765584503e-01,  2.870098965170506e-01,  4.589322892855804e-03,  
 9.949661609261387e-01,  6.084106757497423e-03,  3.583734039365401e-03,  
 9.960704002907521e-01, -4.220415957631232e-01,  4.045718926806529e-03,  
 9.968040423856127e-01,  6.246991365652024e-01,  2.405030444120247e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr33 ( )

/******************************************************************************/
/*
  Purpose:

    SMR33 returns the SMR rule of degree 33.

  Discussion:
 
    DEGREE: 33
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 197
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR33[3*197], the requested rule.
*/
{
  const int degree = 33;
  int order;
  double xw[3*197] = {
 1.485098538731679e-01,  1.694663949097438e-01,  4.808148867803772e-02,  
 1.172505996395537e-01,  5.208793654128182e-01,  4.731056174816773e-02,  
 1.066031447166868e-01,  7.778079973351806e-01,  3.516295123254670e-02,  
 1.132061108674796e-01,  9.316643176349618e-01,  1.951472105421867e-02,  
 1.073615219898776e-01,  9.959676005278353e-01,  3.976501444162358e-03,  
 3.462608583072413e-01,  2.127438914067375e-01,  2.293908286621284e-02,  
 2.637306543835957e-01,  3.722947344432351e-01,  4.432068637015522e-02,  
 2.693795841838618e-01,  6.682002420169654e-01,  3.897921421448901e-02,  
 2.875348204916399e-01,  8.670452225998134e-01,  2.660382508243975e-02,  
 2.893753551193369e-01,  9.757288452382227e-01,  1.105346348813268e-02,  
 5.338546425019925e-01,  2.183801117113716e-01,  3.966360973156654e-02,  
 4.549680885072975e-01,  3.744677210475233e-01,  2.597222014353591e-02,  
 4.090144024608169e-01,  5.458954883248048e-01,  3.713648914135518e-02,  
 5.663026752204063e-01,  6.734659888883729e-01,  2.933590367319608e-02,  
 4.400187284568344e-01,  7.788448587064940e-01,  3.047735039849236e-02,  
 4.582598509566294e-01,  9.355376236278888e-01,  1.725142829363587e-02,  
 4.582752827247127e-01,  9.968603726644156e-01,  3.162797947778954e-03,  
 6.759309027563951e-01,  3.646480880237580e-01,  3.217426321537782e-02,  
 5.907301259704386e-01,  4.949340946812834e-01,  2.734110543912327e-02,  
 7.146893160300763e-01,  6.329648433025803e-01,  1.940442339199639e-02,  
 5.953318104316343e-01,  8.701483739421072e-01,  2.120649987549222e-02,  
 6.160860838046369e-01,  9.794286822210785e-01,  8.362497816308373e-03,  
 7.767420410261425e-01,  2.222325062449502e-01,  3.296613956707922e-02,  
 7.831882183207082e-01,  5.287992062720019e-01,  2.386573699307072e-02,  
 7.041851604707902e-01,  7.847889458751023e-01,  2.058221303838324e-02,  
 7.290534382081308e-01,  9.388309009733727e-01,  1.190900733146451e-02,  
 7.820133071823339e-01,  9.948308715565458e-01,  3.147989159421966e-03,  
 8.652684158240387e-01,  4.011976196638404e-01,  2.438236797329849e-02,  
 8.642300806994567e-01,  6.861574436903071e-01,  1.727637663346140e-02,  
 8.162582507393171e-01,  7.697617350233709e-01,  9.484139746590401e-03,  
 8.182773560074186e-01,  8.794302700865166e-01,  1.280268009696023e-02,  
 8.763977475275423e-01,  9.668867982051652e-01,  6.900853588227474e-03,  
 9.328617706321541e-01,  2.521078906774078e-01,  1.887531974376769e-02,  
 9.761739411206226e-01,  4.312566462575608e-01,  1.066375643199943e-02,  
 9.303430517898699e-01,  5.710543042726919e-01,  1.625052256486291e-02,  
 9.235378662628289e-01,  8.205750108473285e-01,  1.032788782555771e-02,  
 9.162909962693953e-01,  9.020219304490703e-01,  4.456178267147566e-03,  
 9.687563884966668e-01,  9.315860338184979e-01,  4.698545579229029e-03,  
 9.479068758778074e-01,  9.935126494654830e-01,  1.772982851226346e-03,  
 9.962467362996064e-01,  2.548705123657606e-01,  3.847516809883929e-03,  
 9.961740044729398e-01,  6.047358347062713e-01,  3.352228907155900e-03,  
 9.715483507430605e-01,  7.273867424892582e-01,  8.746651111990895e-03,  
 9.934251724726507e-01,  8.497187134082044e-01,  2.995115265626365e-03,  
 9.944169188618658e-01,  9.785612572781918e-01,  1.006759244687949e-03,  
 7.126217736993628e-03,  2.946754002433002e-01,  3.527142153616744e-02,  
 -6.246434173781462e-02,  4.078563905320223e-01,  3.051711732786730e-02,  
 -5.410706476354973e-02,  6.561935311635315e-01,  4.279129134457323e-02,  
 -6.740481034767548e-02,  8.680969463101411e-01,  2.696044145284995e-02,  
 -7.268739448152371e-02,  9.746198602047339e-01,  1.183714051929051e-02,  
 -1.694663949097438e-01,  1.485098538731679e-01,  4.808148867803772e-02,  
 -5.208793654128182e-01,  1.172505996395537e-01,  4.731056174816773e-02,  
 -7.778079973351806e-01,  1.066031447166868e-01,  3.516295123254670e-02,  
 -9.316643176349618e-01,  1.132061108674796e-01,  1.951472105421867e-02,  
 -9.959676005278353e-01,  1.073615219898776e-01,  3.976501444162358e-03,  
 -2.127438914067375e-01,  3.462608583072413e-01,  2.293908286621284e-02,  
 -3.722947344432351e-01,  2.637306543835957e-01,  4.432068637015522e-02,  
 -6.682002420169654e-01,  2.693795841838618e-01,  3.897921421448901e-02,  
 -8.670452225998134e-01,  2.875348204916399e-01,  2.660382508243975e-02,  
 -9.757288452382227e-01,  2.893753551193369e-01,  1.105346348813268e-02,  
 -2.183801117113716e-01,  5.338546425019925e-01,  3.966360973156654e-02,  
 -3.744677210475233e-01,  4.549680885072975e-01,  2.597222014353591e-02,  
 -5.458954883248048e-01,  4.090144024608169e-01,  3.713648914135518e-02,  
 -6.734659888883729e-01,  5.663026752204063e-01,  2.933590367319608e-02,  
 -7.788448587064940e-01,  4.400187284568344e-01,  3.047735039849236e-02,  
 -9.355376236278888e-01,  4.582598509566294e-01,  1.725142829363587e-02,  
 -9.968603726644156e-01,  4.582752827247127e-01,  3.162797947778954e-03,  
 -3.646480880237580e-01,  6.759309027563951e-01,  3.217426321537782e-02,  
 -4.949340946812834e-01,  5.907301259704386e-01,  2.734110543912327e-02,  
 -6.329648433025803e-01,  7.146893160300763e-01,  1.940442339199639e-02,  
 -8.701483739421072e-01,  5.953318104316343e-01,  2.120649987549222e-02,  
 -9.794286822210785e-01,  6.160860838046369e-01,  8.362497816308373e-03,  
 -2.222325062449502e-01,  7.767420410261425e-01,  3.296613956707922e-02,  
 -5.287992062720019e-01,  7.831882183207082e-01,  2.386573699307072e-02,  
 -7.847889458751023e-01,  7.041851604707902e-01,  2.058221303838324e-02,  
 -9.388309009733727e-01,  7.290534382081308e-01,  1.190900733146451e-02,  
 -9.948308715565458e-01,  7.820133071823339e-01,  3.147989159421966e-03,  
 -4.011976196638404e-01,  8.652684158240387e-01,  2.438236797329849e-02,  
 -6.861574436903071e-01,  8.642300806994567e-01,  1.727637663346140e-02,  
 -7.697617350233709e-01,  8.162582507393171e-01,  9.484139746590401e-03,  
 -8.794302700865166e-01,  8.182773560074186e-01,  1.280268009696023e-02,  
 -9.668867982051652e-01,  8.763977475275423e-01,  6.900853588227474e-03,  
 -2.521078906774078e-01,  9.328617706321541e-01,  1.887531974376769e-02,  
 -4.312566462575608e-01,  9.761739411206226e-01,  1.066375643199943e-02,  
 -5.710543042726919e-01,  9.303430517898699e-01,  1.625052256486291e-02,  
 -8.205750108473285e-01,  9.235378662628289e-01,  1.032788782555771e-02,  
 -9.020219304490703e-01,  9.162909962693953e-01,  4.456178267147566e-03,  
 -9.315860338184979e-01,  9.687563884966668e-01,  4.698545579229029e-03,  
 -9.935126494654830e-01,  9.479068758778074e-01,  1.772982851226346e-03,  
 -2.548705123657606e-01,  9.962467362996064e-01,  3.847516809883929e-03,  
 -6.047358347062713e-01,  9.961740044729398e-01,  3.352228907155900e-03,  
 -7.273867424892582e-01,  9.715483507430605e-01,  8.746651111990895e-03,  
 -8.497187134082044e-01,  9.934251724726507e-01,  2.995115265626365e-03,  
 -9.785612572781918e-01,  9.944169188618658e-01,  1.006759244687949e-03,  
 -2.946754002433002e-01,  7.126217736993628e-03,  3.527142153616744e-02,  
 -4.078563905320223e-01, -6.246434173781462e-02,  3.051711732786730e-02,  
 -6.561935311635315e-01, -5.410706476354973e-02,  4.279129134457323e-02,  
 -8.680969463101411e-01, -6.740481034767548e-02,  2.696044145284995e-02,  
 -9.746198602047339e-01, -7.268739448152371e-02,  1.183714051929051e-02,  
 -1.485098538731679e-01, -1.694663949097438e-01,  4.808148867803772e-02,  
 -1.172505996395537e-01, -5.208793654128182e-01,  4.731056174816773e-02,  
 -1.066031447166868e-01, -7.778079973351806e-01,  3.516295123254670e-02,  
 -1.132061108674796e-01, -9.316643176349618e-01,  1.951472105421867e-02,  
 -1.073615219898776e-01, -9.959676005278353e-01,  3.976501444162358e-03,  
 -3.462608583072413e-01, -2.127438914067375e-01,  2.293908286621284e-02,  
 -2.637306543835957e-01, -3.722947344432351e-01,  4.432068637015522e-02,  
 -2.693795841838618e-01, -6.682002420169654e-01,  3.897921421448901e-02,  
 -2.875348204916399e-01, -8.670452225998134e-01,  2.660382508243975e-02,  
 -2.893753551193369e-01, -9.757288452382227e-01,  1.105346348813268e-02,  
 -5.338546425019925e-01, -2.183801117113716e-01,  3.966360973156654e-02,  
 -4.549680885072975e-01, -3.744677210475233e-01,  2.597222014353591e-02,  
 -4.090144024608169e-01, -5.458954883248048e-01,  3.713648914135518e-02,  
 -5.663026752204063e-01, -6.734659888883729e-01,  2.933590367319608e-02,  
 -4.400187284568344e-01, -7.788448587064940e-01,  3.047735039849236e-02,  
 -4.582598509566294e-01, -9.355376236278888e-01,  1.725142829363587e-02,  
 -4.582752827247127e-01, -9.968603726644156e-01,  3.162797947778954e-03,  
 -6.759309027563951e-01, -3.646480880237580e-01,  3.217426321537782e-02,  
 -5.907301259704386e-01, -4.949340946812834e-01,  2.734110543912327e-02,  
 -7.146893160300763e-01, -6.329648433025803e-01,  1.940442339199639e-02,  
 -5.953318104316343e-01, -8.701483739421072e-01,  2.120649987549222e-02,  
 -6.160860838046369e-01, -9.794286822210785e-01,  8.362497816308373e-03,  
 -7.767420410261425e-01, -2.222325062449502e-01,  3.296613956707922e-02,  
 -7.831882183207082e-01, -5.287992062720019e-01,  2.386573699307072e-02,  
 -7.041851604707902e-01, -7.847889458751023e-01,  2.058221303838324e-02,  
 -7.290534382081308e-01, -9.388309009733727e-01,  1.190900733146451e-02,  
 -7.820133071823339e-01, -9.948308715565458e-01,  3.147989159421966e-03,  
 -8.652684158240387e-01, -4.011976196638404e-01,  2.438236797329849e-02,  
 -8.642300806994567e-01, -6.861574436903071e-01,  1.727637663346140e-02,  
 -8.162582507393171e-01, -7.697617350233709e-01,  9.484139746590401e-03,  
 -8.182773560074186e-01, -8.794302700865166e-01,  1.280268009696023e-02,  
 -8.763977475275423e-01, -9.668867982051652e-01,  6.900853588227474e-03,  
 -9.328617706321541e-01, -2.521078906774078e-01,  1.887531974376769e-02,  
 -9.761739411206226e-01, -4.312566462575608e-01,  1.066375643199943e-02,  
 -9.303430517898699e-01, -5.710543042726919e-01,  1.625052256486291e-02,  
 -9.235378662628289e-01, -8.205750108473285e-01,  1.032788782555771e-02,  
 -9.162909962693953e-01, -9.020219304490703e-01,  4.456178267147566e-03,  
 -9.687563884966668e-01, -9.315860338184979e-01,  4.698545579229029e-03,  
 -9.479068758778074e-01, -9.935126494654830e-01,  1.772982851226346e-03,  
 -9.962467362996064e-01, -2.548705123657606e-01,  3.847516809883929e-03,  
 -9.961740044729398e-01, -6.047358347062713e-01,  3.352228907155900e-03,  
 -9.715483507430605e-01, -7.273867424892582e-01,  8.746651111990895e-03,  
 -9.934251724726507e-01, -8.497187134082044e-01,  2.995115265626365e-03,  
 -9.944169188618658e-01, -9.785612572781918e-01,  1.006759244687949e-03,  
 -7.126217736993628e-03, -2.946754002433002e-01,  3.527142153616744e-02,  
 6.246434173781462e-02, -4.078563905320223e-01,  3.051711732786730e-02,  
 5.410706476354973e-02, -6.561935311635315e-01,  4.279129134457323e-02,  
 6.740481034767548e-02, -8.680969463101411e-01,  2.696044145284995e-02,  
 7.268739448152371e-02, -9.746198602047339e-01,  1.183714051929051e-02,  
 1.694663949097438e-01, -1.485098538731679e-01,  4.808148867803772e-02,  
 5.208793654128182e-01, -1.172505996395537e-01,  4.731056174816773e-02,  
 7.778079973351806e-01, -1.066031447166868e-01,  3.516295123254670e-02,  
 9.316643176349618e-01, -1.132061108674796e-01,  1.951472105421867e-02,  
 9.959676005278353e-01, -1.073615219898776e-01,  3.976501444162358e-03,  
 2.127438914067375e-01, -3.462608583072413e-01,  2.293908286621284e-02,  
 3.722947344432351e-01, -2.637306543835957e-01,  4.432068637015522e-02,  
 6.682002420169654e-01, -2.693795841838618e-01,  3.897921421448901e-02,  
 8.670452225998134e-01, -2.875348204916399e-01,  2.660382508243975e-02,  
 9.757288452382227e-01, -2.893753551193369e-01,  1.105346348813268e-02,  
 2.183801117113716e-01, -5.338546425019925e-01,  3.966360973156654e-02,  
 3.744677210475233e-01, -4.549680885072975e-01,  2.597222014353591e-02,  
 5.458954883248048e-01, -4.090144024608169e-01,  3.713648914135518e-02,  
 6.734659888883729e-01, -5.663026752204063e-01,  2.933590367319608e-02,  
 7.788448587064940e-01, -4.400187284568344e-01,  3.047735039849236e-02,  
 9.355376236278888e-01, -4.582598509566294e-01,  1.725142829363587e-02,  
 9.968603726644156e-01, -4.582752827247127e-01,  3.162797947778954e-03,  
 3.646480880237580e-01, -6.759309027563951e-01,  3.217426321537782e-02,  
 4.949340946812834e-01, -5.907301259704386e-01,  2.734110543912327e-02,  
 6.329648433025803e-01, -7.146893160300763e-01,  1.940442339199639e-02,  
 8.701483739421072e-01, -5.953318104316343e-01,  2.120649987549222e-02,  
 9.794286822210785e-01, -6.160860838046369e-01,  8.362497816308373e-03,  
 2.222325062449502e-01, -7.767420410261425e-01,  3.296613956707922e-02,  
 5.287992062720019e-01, -7.831882183207082e-01,  2.386573699307072e-02,  
 7.847889458751023e-01, -7.041851604707902e-01,  2.058221303838324e-02,  
 9.388309009733727e-01, -7.290534382081308e-01,  1.190900733146451e-02,  
 9.948308715565458e-01, -7.820133071823339e-01,  3.147989159421966e-03,  
 4.011976196638404e-01, -8.652684158240387e-01,  2.438236797329849e-02,  
 6.861574436903071e-01, -8.642300806994567e-01,  1.727637663346140e-02,  
 7.697617350233709e-01, -8.162582507393171e-01,  9.484139746590401e-03,  
 8.794302700865166e-01, -8.182773560074186e-01,  1.280268009696023e-02,  
 9.668867982051652e-01, -8.763977475275423e-01,  6.900853588227474e-03,  
 2.521078906774078e-01, -9.328617706321541e-01,  1.887531974376769e-02,  
 4.312566462575608e-01, -9.761739411206226e-01,  1.066375643199943e-02,  
 5.710543042726919e-01, -9.303430517898699e-01,  1.625052256486291e-02,  
 8.205750108473285e-01, -9.235378662628289e-01,  1.032788782555771e-02,  
 9.020219304490703e-01, -9.162909962693953e-01,  4.456178267147566e-03,  
 9.315860338184979e-01, -9.687563884966668e-01,  4.698545579229029e-03,  
 9.935126494654830e-01, -9.479068758778074e-01,  1.772982851226346e-03,  
 2.548705123657606e-01, -9.962467362996064e-01,  3.847516809883929e-03,  
 6.047358347062713e-01, -9.961740044729398e-01,  3.352228907155900e-03,  
 7.273867424892582e-01, -9.715483507430605e-01,  8.746651111990895e-03,  
 8.497187134082044e-01, -9.934251724726507e-01,  2.995115265626365e-03,  
 9.785612572781918e-01, -9.944169188618658e-01,  1.006759244687949e-03,  
 2.946754002433002e-01, -7.126217736993628e-03,  3.527142153616744e-02,  
 4.078563905320223e-01,  6.246434173781462e-02,  3.051711732786730e-02,  
 6.561935311635315e-01,  5.410706476354973e-02,  4.279129134457323e-02,  
 8.680969463101411e-01,  6.740481034767548e-02,  2.696044145284995e-02,  
 9.746198602047339e-01,  7.268739448152371e-02,  1.183714051929051e-02,  
 0.000000000000000e+00,  0.000000000000000e+00,  5.152213536694609e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr34 ( )

/******************************************************************************/
/*
  Purpose:

    SMR34 returns the SMR rule of degree 34.

  Discussion:
 
    DEGREE: 34
    POINTS CARDINALITY: 211
    NORM INF MOMS. RESIDUAL: 1.28603e-15
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR34[3*211], the requested rule.
*/
{
  const int degree = 34;
  int order;
  double xw[3*211] = {
 9.957894049234940e-01,  9.315910675787362e-01,  1.269921938742754e-03,  
 9.966819226158441e-01,  1.990628617847345e-01,  2.824785894655117e-03,  
 9.964232568659287e-01, -8.647711926777550e-02,  2.645466616758639e-03,  
 9.956972863904161e-01, -3.319481955508262e-01,  2.579394947779080e-03,  
 9.970019011095760e-01, -9.813822644968530e-01,  5.121822735027154e-04,  
 9.927566324556228e-01,  9.934870866426487e-01,  4.095595153407374e-04,  
 9.703323011961618e-01,  9.728958623239660e-01,  2.212600752526410e-03,  
 9.900242513895626e-01,  8.165046961752659e-01,  3.489632874382814e-03,  
 9.902525852068462e-01,  6.514930247782849e-01,  4.815598056643366e-03,  
 9.917712097306959e-01,  4.326945836209130e-01,  4.941854039948059e-03,  
 9.773024985383031e-01,  5.683940605635036e-02,  8.460270092591574e-03,  
 9.765396060948102e-01, -2.098648339912204e-01,  7.323452637054356e-03,  
 9.880323477406699e-01, -5.045486513331958e-01,  5.591335677415872e-03,  
 9.944122733775166e-01, -7.025141307156174e-01,  3.181105696378461e-03,  
 9.958204649863345e-01, -8.811936722293690e-01,  1.679399407542441e-03,  
 9.739851411479190e-01, -9.961982985684296e-01,  6.089390050721569e-04,  
 9.254838810436582e-01,  9.958919316136239e-01,  1.271037344372932e-03,  
 9.587557132884421e-01,  8.944112789567285e-01,  5.640872717691950e-03,  
 9.478849514864001e-01,  7.463373175773630e-01,  1.008027250286055e-02,  
 9.549410582182760e-01,  5.355951225176204e-01,  1.161336024599024e-02,  
 9.613314688856274e-01,  2.819596780094841e-01,  1.253554272417035e-02,  
 9.371448388483095e-01, -8.017182518756116e-02,  1.355567725840021e-02,  
 9.492637368076354e-01, -3.697133117565873e-01,  1.281170011512887e-02,  
 9.566739186062905e-01, -6.179209188638126e-01,  1.016499900104730e-02,  
 9.690740057689825e-01, -8.076324709283432e-01,  7.066159092569420e-03,  
 9.749406372948716e-01, -9.432315538275444e-01,  3.241771014445550e-03,  
 9.028278454473605e-01,  9.506719573551936e-01,  5.718690511681701e-03,  
 8.866581548182707e-01,  8.445040467901622e-01,  1.175179682399269e-02,  
 8.903706483869364e-01,  6.377461105727130e-01,  1.554746970297020e-02,  
 8.969144590540912e-01,  3.956118985338431e-01,  1.953552168957224e-02,  
 9.053329661179432e-01,  1.228611554470282e-01,  2.024486874693669e-02,  
 8.842030747448643e-01, -2.282562902715039e-01,  2.040134384913240e-02,  
 8.946404670250787e-01, -4.984799138722827e-01,  1.782084645269496e-02,  
 9.062802014741841e-01, -7.288543903373946e-01,  1.354418113376059e-02,  
 9.198811888280545e-01, -8.922009039806831e-01,  8.721191397819752e-03,  
 9.293075634720418e-01, -9.788256460307448e-01,  3.013136362612083e-03,  
 8.307416649103097e-01,  9.847272069450065e-01,  3.863549341320347e-03,  
 7.989018093580924e-01,  9.174533264327734e-01,  1.128961407311655e-02,  
 8.153857983509745e-01,  7.467362479932101e-01,  1.716850446840271e-02,  
 8.106585959801085e-01,  5.188318587780150e-01,  2.320252631505465e-02,  
 8.162893718776413e-01,  2.444840500980434e-01,  2.728966404029472e-02,  
 8.215905935547697e-01, -3.780686241256082e-02,  2.873816438714253e-02,  
 8.072057239710502e-01, -3.681756246884155e-01,  2.561572339256985e-02,  
 8.197749309285268e-01, -6.248305963346963e-01,  2.157459899366617e-02,  
 8.339165476219796e-01, -8.250462105756355e-01,  1.506332709846787e-02,  
 8.437899588814044e-01, -9.504266038421356e-01,  7.899470455295205e-03,  
 8.682228958168398e-01, -9.969291267643441e-01,  1.326374275614798e-03,  
 7.414965930896726e-01,  9.976180923017504e-01,  1.275494804255145e-03,  
 6.896123397952399e-01,  9.672239781292444e-01,  8.487518731202960e-03,  
 7.211153759242311e-01,  8.337039311560572e-01,  1.641194543039353e-02,  
 7.110494018863930e-01,  6.441550914790497e-01,  2.560376586419488e-02,  
 7.120710037407173e-01,  3.843983266067464e-01,  3.118328085454265e-02,  
 7.082337843919169e-01,  9.533642358177043e-02,  3.479648766166858e-02,  
 7.187206312556610e-01, -1.999543274853690e-01,  3.480535416060045e-02,  
 7.099505499909835e-01, -5.055377353405510e-01,  2.961142270210251e-02,  
 7.231776378051314e-01, -7.385609605003077e-01,  2.311015021964838e-02,  
 7.369495741211172e-01, -9.005396614377654e-01,  1.415501795415763e-02,  
 7.505952660477123e-01, -9.861825097580426e-01,  4.832952601963804e-03,  
 5.629653024363824e-01,  9.941135664776372e-01,  3.633655134392321e-03,  
 6.141214240396574e-01,  8.998790302041257e-01,  1.392167112523221e-02,  
 5.931921073513758e-01,  7.527920640845824e-01,  2.481829833350465e-02,  
 5.899871025319341e-01,  5.223942064090121e-01,  3.423115609409048e-02,  
 5.883574941173312e-01,  2.456253195175061e-01,  3.801938621563456e-02,  
 5.866522692423990e-01, -6.354514810462418e-02,  4.033761673976392e-02,  
 5.956977300877557e-01, -3.566931332257176e-01,  3.883131233055023e-02,  
 5.927782889432014e-01, -6.336224604245022e-01,  3.122552426886264e-02,  
 6.039926786166937e-01, -8.337208546028212e-01,  2.203539439992588e-02,  
 6.254100151918139e-01, -9.560918196311188e-01,  1.059755194349184e-02,  
 6.138060651734009e-01, -9.979430080887202e-01,  1.564596443077996e-03,  
 5.022165322679116e-01,  9.482480846379436e-01,  1.084348902106024e-02,  
 4.589509327363929e-01,  8.404994158661170e-01,  2.205645658430699e-02,  
 4.535417272429489e-01,  6.512962979642629e-01,  3.348745611830561e-02,  
 4.510904524624095e-01,  3.881579570291138e-01,  4.047512990695875e-02,  
 4.531813432716658e-01,  9.229245238599951e-02,  4.393288153714553e-02,  
 4.488470929336799e-01, -2.197179800757668e-01,  4.388737292644242e-02,  
 4.563145412677839e-01, -5.038653497135700e-01,  4.012853694760013e-02,  
 4.562655526794984e-01, -7.462651889579118e-01,  3.008472851353892e-02,  
 4.727430836168379e-01, -9.110093097588490e-01,  1.799703635920556e-02,  
 4.843396113021201e-01, -9.856160975683469e-01,  5.547598452760956e-03,  
 3.782074525681371e-01,  9.816291834100873e-01,  7.597211525403482e-03,  
 3.210021971883614e-01,  9.073748618669065e-01,  1.712946714791248e-02,  
 2.971150388089600e-01,  7.594439443864908e-01,  3.119492749262633e-02,  
 3.085827486636639e-01,  5.288161042011519e-01,  3.927023314753940e-02,  
 3.026283090386810e-01,  2.403811853574280e-01,  4.600362243085380e-02,  
 3.035481141969048e-01, -6.382973969918371e-02,  4.775119284718515e-02,  
 2.994451040546098e-01, -3.704131087942491e-01,  4.493238986528309e-02,  
 3.026913839582241e-01, -6.362750245744471e-01,  3.848554817804676e-02,  
 3.121563314492936e-01, -8.444884638792907e-01,  2.592723046024846e-02,  
 3.177377527975286e-01, -9.623829050564436e-01,  1.196800170196079e-02,  
 3.522562949226852e-01, -9.977574902186489e-01,  1.465730151083379e-03,  
 2.252906962715443e-01,  9.978350295394129e-01,  2.641867829058960e-03,  
 1.870003268404008e-01,  9.519167862352040e-01,  1.192465747101495e-02,  
 1.307262219235918e-01,  8.489253631104906e-01,  2.661740954067537e-02,  
 1.460202234422147e-01,  6.479061469473005e-01,  3.731070624469975e-02,  
 1.551732848359904e-01,  3.937810190186502e-01,  4.428770255029615e-02,  
 1.446818601451690e-01,  8.694181210571608e-02,  4.921582512367255e-02,  
 1.447233210916806e-01, -2.195027813449513e-01,  4.906351937807495e-02,  
 1.412640048285802e-01, -5.107425247720647e-01,  4.323240844139490e-02,  
 1.466417969010396e-01, -7.557347294477489e-01,  3.399928104285673e-02,  
 1.513983361920271e-01, -9.178835711763990e-01,  1.968326070317311e-02,  
 1.600169709826858e-01, -9.920169758816885e-01,  5.106715024206334e-03,  
 4.623093501161722e-02,  9.801351468257945e-01,  8.170216576549613e-03,  
 -4.319669651670000e-02,  9.166149692153970e-01,  2.022961085099902e-02,  
 -2.230730777996857e-02,  7.523423884761198e-01,  3.290525410921873e-02,  
 -1.392477655643914e-02,  5.228385485756610e-01,  4.239225481578053e-02,  
 -2.183676694863989e-03,  2.501384326494425e-01,  4.695791528007733e-02,  
 -1.771073397997970e-02, -6.845314069841779e-02,  4.998518364759874e-02,  
 -1.918022708935162e-02, -3.696927200439754e-01,  4.749247254760981e-02,  
 -1.474661089836961e-02, -6.423393807595678e-01,  3.916228450022604e-02,  
 -1.910959910763293e-02, -8.510668952524700e-01,  2.737517696135046e-02,  
 -1.100089784272918e-02, -9.691167342202294e-01,  1.213622924790588e-02,  
 -3.847492042854418e-02, -9.987599455147976e-01,  5.258835064828757e-04,  
 -1.160040389320081e-01,  9.958817619644164e-01,  3.406278974443858e-03,  
 -2.185121444211190e-01,  9.631241177105265e-01,  1.268502876701255e-02,  
 -1.937132212208339e-01,  8.383996125115697e-01,  2.675583510478743e-02,  
 -1.826019579662390e-01,  6.413756225205492e-01,  3.761719838478075e-02,  
 -1.735927428003249e-01,  3.847679978445431e-01,  4.506880832422441e-02,  
 -1.594820599810335e-01,  1.021893850082368e-01,  4.732469156429694e-02,  
 -1.797927762716425e-01, -2.215868153351966e-01,  4.805977741575223e-02,  
 -1.784086402180959e-01, -5.142300281088545e-01,  4.362591086259024e-02,  
 -1.745465205857428e-01, -7.537366611960344e-01,  3.293031384181930e-02,  
 -1.828492149475154e-01, -9.245139444740262e-01,  1.949340077252138e-02,  
 -1.789613218613975e-01, -9.949810109450419e-01,  4.016610904884734e-03,  
 -3.800099111129797e-01,  9.908974338803321e-01,  5.688273109814698e-03,  
 -3.586039156258787e-01,  9.068849508020077e-01,  1.913010526360378e-02,  
 -3.496397464654761e-01,  7.438459923959813e-01,  3.124476168334308e-02,  
 -3.364944138026182e-01,  5.149360180314989e-01,  3.983236757275106e-02,  
 -3.294605072590807e-01,  2.384445970652024e-01,  4.513790568866929e-02,  
 -3.122746998671402e-01, -4.678649257141996e-02,  4.548014560760486e-02,  
 -3.341423047428589e-01, -3.709042921640023e-01,  4.429219382577024e-02,  
 -3.354222464209633e-01, -6.423389313071104e-01,  3.714968452645009e-02,  
 -3.286029525442455e-01, -8.464666976755009e-01,  2.548880688148467e-02,  
 -3.423506685296714e-01, -9.732216431261292e-01,  1.101466595660109e-02,  
 -5.138042906159611e-01,  9.558781663655185e-01,  1.229885705467326e-02,  
 -5.033240255512550e-01,  8.325996634815285e-01,  2.342997859462644e-02,  
 -4.934184358754027e-01,  6.313367991374997e-01,  3.314341950516837e-02,  
 -4.810231379698435e-01,  3.779456066296256e-01,  3.930146102742181e-02,  
 -4.764387898456861e-01,  8.757235735790503e-02,  4.263018853028100e-02,  
 -4.572408337995446e-01, -1.943807931912226e-01,  4.242015879601867e-02,  
 -4.802078301948393e-01, -5.087552615537000e-01,  3.799154907843184e-02,  
 -4.816737135589465e-01, -7.533088525220843e-01,  2.921009462864135e-02,  
 -4.733119659070418e-01, -9.179909803583359e-01,  1.746139256900922e-02,  
 -4.990207194253169e-01, -9.955235014987277e-01,  3.570668877927755e-03,  
 -6.062998022698073e-01,  9.932404164712231e-01,  3.708370634578858e-03,  
 -6.491078687880649e-01,  8.991595936933783e-01,  1.661359748562513e-02,  
 -6.321366293284888e-01,  7.379522674184295e-01,  2.543791270192361e-02,  
 -6.224588096649009e-01,  5.058658625167738e-01,  3.217812029858986e-02,  
 -6.117601892971127e-01,  2.344646477708566e-01,  3.626413991737416e-02,  
 -6.122438295935009e-01, -6.118231673822243e-02,  3.846524273667296e-02,  
 -5.905469375569611e-01, -3.379271094668896e-01,  3.725605813241765e-02,  
 -6.122926561666857e-01, -6.332620144806621e-01,  3.045025547248366e-02,  
 -6.117420843079315e-01, -8.439605906500176e-01,  2.063725984389774e-02,  
 -6.116108912175794e-01, -9.645394242789779e-01,  1.003007390672613e-02,  
 -7.202064450714707e-01,  9.687351621558032e-01,  7.343535416630068e-03,  
 -7.640489552162673e-01,  8.186646209837353e-01,  1.863562117417300e-02,  
 -7.436443095834101e-01,  6.262385938114700e-01,  2.495426940021197e-02,  
 -7.331951159558409e-01,  3.722915352073840e-01,  2.875505251303774e-02,  
 -7.291744483592270e-01,  9.368940286691475e-02,  3.156945503308321e-02,  
 -7.288163979760982e-01, -2.086415233438004e-01,  3.215315002188151e-02,  
 -7.098973709325594e-01, -4.751240313065653e-01,  3.076312488254992e-02,  
 -7.268316303036324e-01, -7.421205012809852e-01,  2.255876744610365e-02,  
 -7.264152089003056e-01, -9.083680633160397e-01,  1.267855278207347e-02,  
 -7.233502526295543e-01, -9.921398900464297e-01,  3.600327870316919e-03,  
 -7.944789979709225e-01,  9.959607742122426e-01,  1.854529264151413e-03,  
 -8.147179926759360e-01,  9.259971742330974e-01,  9.286071545967561e-03,  
 -8.358777763260274e-01,  5.001749403101742e-01,  2.223492620715524e-02,  
 -8.280513515003269e-01,  2.411582059883278e-01,  2.368666725498836e-02,  
 -8.243355863622386e-01, -4.998572152583577e-02,  2.569483374962900e-02,  
 -8.253626145601571e-01, -3.493120592376261e-01,  2.490342922131878e-02,  
 -8.121903650291438e-01, -6.033292859790981e-01,  2.346341699504689e-02,  
 -8.243577863456620e-01, -8.312302356419400e-01,  1.465176915755172e-02,  
 -8.082617618985660e-01, -9.574178572790982e-01,  6.560728336041037e-03,  
 -8.769708382829380e-01,  9.770175617614344e-01,  3.974309788574307e-03,  
 -8.880540245245994e-01,  8.666033220470682e-01,  9.800468993344479e-03,  
 -8.568819581968040e-01,  7.165122557426438e-01,  1.790497672791658e-02,  
 -9.108965422368728e-01,  3.666364065180091e-01,  1.733578039890229e-02,  
 -8.999292387149525e-01,  1.038339307709946e-01,  1.840663934478885e-02,  
 -8.998152788908981e-01, -1.919839007449358e-01,  1.937803424050972e-02,  
 -9.011685721899708e-01, -4.791884508086222e-01,  1.781696597031558e-02,  
 -8.923912156383284e-01, -7.214601312758249e-01,  1.500532951025639e-02,  
 -8.907008410401606e-01, -9.129470624567904e-01,  7.655314254685561e-03,  
 -8.676939171104242e-01, -9.904314861849869e-01,  2.705031002848760e-03,  
 -9.188556339019280e-01,  9.977441709649485e-01,  6.651528764616177e-04,  
 -9.393146671802626e-01,  9.406875019616726e-01,  4.907287875623333e-03,  
 -9.427004725205717e-01,  7.884492668449667e-01,  8.999020685128650e-03,  
 -9.254983409374398e-01,  5.949923406312909e-01,  1.449266443485655e-02,  
 -9.623402050786286e-01,  2.203675962432235e-01,  1.154948473266472e-02,  
 -9.534726655584184e-01, -3.595939510894143e-02,  1.281508516722223e-02,  
 -9.562602062411448e-01, -3.265233934409525e-01,  1.289425537223051e-02,  
 -9.499571065866433e-01, -6.131217314929267e-01,  1.037125192483871e-02,  
 -9.414372674717216e-01, -8.421925517112083e-01,  7.635598833311997e-03,  
 -9.395229108692154e-01, -9.677418086529198e-01,  3.716167310778579e-03,  
 -9.663743388828732e-01,  9.850068209277927e-01,  1.420844648930481e-03,  
 -9.793571344458664e-01,  8.835824849533620e-01,  4.236370836658044e-03,  
 -9.784131895253078e-01,  6.860465632928617e-01,  6.466485198832629e-03,  
 -9.720790479760727e-01,  4.609381343239562e-01,  9.123045248824293e-03,  
 -9.922349973191166e-01,  7.408980516640630e-02,  5.036903551023158e-03,  
 -9.884518154282259e-01, -1.661796274498394e-01,  6.407263174244769e-03,  
 -9.837613800395109e-01, -4.904211187466530e-01,  6.284479940669028e-03,  
 -9.762934256514504e-01, -7.589006865381343e-01,  5.806817236490501e-03,  
 -9.802746096908096e-01, -9.188419450488240e-01,  3.548038742379143e-03,  
 -9.621555816212115e-01, -9.997532394165864e-01,  5.926783687992160e-04,  
 -9.896332869499853e-01,  9.951276758066656e-01,  3.200747405907301e-04,  
 -9.951132917806931e-01,  9.549806547758480e-01,  1.112585947085899e-03,  
 -9.971587223315985e-01,  7.967223653947199e-01,  1.766856809395384e-03,  
 -9.966946507532868e-01,  5.656259514453754e-01,  2.374570144278089e-03,  
 -9.948421084318764e-01,  3.184211137190651e-01,  3.508527197107025e-03,  
 -9.985195040394224e-01, -3.568719965932207e-01,  1.842016463896301e-03,  
 -9.952776313728143e-01, -6.518074202281385e-01,  2.603732985806352e-03,  
 -9.985034101792289e-01, -8.450489535939099e-01,  1.326109663812068e-03,  
 -9.930680364844743e-01, -9.794233688312636e-01,  9.749008815310916e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr35 ( )

/******************************************************************************/
/*
  Purpose:

    SMR35 returns the SMR rule of degree 35.

  Discussion:
 
    DEGREE: 35
    SYMMETRY: (X,  Y),  (-X, -Y)
    POINTS CARDINALITY: 220
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR35[3*220], the requested rule.
*/
{
  const int degree = 35;
  int order;
  double xw[3*220] = {
 -9.963054076831271e-01,  5.895227652492729e-01,  3.040448117975760e-03,  
 -9.959258876623405e-01,  8.226232166208993e-01,  1.978505799274471e-03,  
 -9.954067560360648e-01, -9.074145716693054e-01,  1.810898452206362e-03,  
 -9.952722138287154e-01,  2.785041956973013e-01,  4.045664611880734e-03,  
 -9.949775104476455e-01, -7.198973208744759e-01,  2.841977406946536e-03,  
 -9.943750550352027e-01, -3.487179202856331e-02,  4.548201806973092e-03,  
 -9.943677037885296e-01,  9.710410041880194e-01,  1.118097006661641e-03,  
 -9.937038655576630e-01, -9.931050540649843e-01,  4.830386117047890e-04,  
 -9.930202681222473e-01, -3.214092657950156e-01,  4.905950396961080e-03,  
 -9.861727841676639e-01, -5.400704381496431e-01,  6.797444141494801e-03,  
 -9.810071147719678e-01,  8.985653300431585e-01,  3.181435032108599e-03,  
 -9.740062631571137e-01,  7.162386303873299e-01,  7.887232214456035e-03,  
 -9.739587062789258e-01,  4.439901118287898e-01,  1.034505230549930e-02,  
 -9.726572697503230e-01, -8.181619946621148e-01,  6.464658905526641e-03,  
 -9.698067055262342e-01, -9.633285091443817e-01,  3.282158060938487e-03,  
 -9.694166462805192e-01,  1.256612526452283e-01,  1.203688131505905e-02,  
 -9.658674622089268e-01,  9.953452266059633e-01,  1.102717947131251e-03,  
 -9.638166221951805e-01, -1.751088896720577e-01,  1.281494987287384e-02,  
 -9.504683215166834e-01,  9.376314986069719e-01,  4.086139127613287e-03,  
 -9.449990557642718e-01, -6.629472122415720e-01,  1.284843891927071e-02,  
 -9.446169086076862e-01, -4.135452324650374e-01,  1.479906753649862e-02,  
 -9.317772095678226e-01,  8.201150672577782e-01,  9.940838732765474e-03,  
 -9.290486544464471e-01, -8.950190921642169e-01,  7.779964394420137e-03,  
 -9.283184737295814e-01,  5.879017021514434e-01,  1.561783824168382e-02,  
 -9.245462285990703e-01,  2.974342857591706e-01,  1.847140993304593e-02,  
 -9.211763298375819e-01, -9.934526556341349e-01,  2.003191789183488e-03,  
 -9.119151052554647e-01, -4.274927442267495e-02,  1.424779189715308e-02,  
 -9.057117846078058e-01,  4.659054057320846e-02,  9.353615677783169e-03,  
 -8.999935234232900e-01,  9.752903231391948e-01,  4.574852292020883e-03,  
 -8.829230087690153e-01, -7.770114466508429e-01,  1.555785382570586e-02,  
 -8.824467573040489e-01, -2.752146559569857e-01,  2.057326622412542e-02,  
 -8.735663725309100e-01, -5.411359973847757e-01,  2.141510206682392e-02,  
 -8.722180260064613e-01,  8.841005984426642e-01,  8.223856754800985e-03,  
 -8.688253850828861e-01, -9.504355153693655e-01,  7.016335896084859e-03,  
 -8.610711834248425e-01,  7.150978677167033e-01,  1.850564562244901e-02,  
 -8.562600324120904e-01,  4.495124318073283e-01,  2.357983853078307e-02,  
 -8.358095013326707e-01,  1.733093930153186e-01,  2.670539971994917e-02,  
 -8.228302442461702e-01, -1.697016693626475e-01,  1.342647121783435e-02,  
 -8.174385098192266e-01,  9.961711079884141e-01,  2.165794610184791e-03,  
 -8.166426016882831e-01,  9.271485107406205e-01,  7.934960713327414e-03,  
 -7.985152091160521e-01, -8.693626506598062e-01,  1.561754453690349e-02,  
 -7.981120997224805e-01, -9.863110488956950e-01,  4.428350131300970e-03,  
 -7.904587180395604e-01, -3.698232163504092e-02,  2.186616762504613e-02,  
 -7.887652330718642e-01, -6.709289186517926e-01,  2.371430123275542e-02,  
 -7.796834866912661e-01, -3.994715783200819e-01,  2.994104825767884e-02,  
 -7.704963456494349e-01,  5.900999992322654e-01,  2.533980569560729e-02,  
 -7.640326515570037e-01,  8.125887805195392e-01,  1.949174894848284e-02,  
 -7.450492234413376e-01,  3.427381908986717e-01,  2.313801537268639e-02,  
 -7.328136392431331e-01,  2.875348312510743e-01,  1.087089248290535e-02,  
 -7.295286264509984e-01,  9.665226078227548e-01,  8.147629083103793e-03,  
 -7.084311098316746e-01, -1.768747230410797e-01,  2.397513960514677e-02,  
 -7.005552670374735e-01, -9.406601330339404e-01,  1.246369990823231e-02,  
 -6.897531031934704e-01,  6.782883935108303e-01,  6.655878361359627e-03,  
 -6.848525475182752e-01, -7.813397580356689e-01,  2.347027715648843e-02,  
 -6.787362302215644e-01,  8.353105038445782e-02,  3.660462342407370e-02,  
 -6.758525517932752e-01, -5.427274842488018e-01,  3.178580319617729e-02,  
 -6.598249437273979e-01, -9.948642685624477e-01,  2.808772731098325e-03,  
 -6.499799074317244e-01,  8.924083156022753e-01,  1.749067931565174e-02,  
 -6.406772691253437e-01,  7.139228812806040e-01,  2.272673241453971e-02,  
 -6.404909510129633e-01,  4.864679391303438e-01,  2.960589457868493e-02,  
 -6.308221736554908e-01, -2.945267523482654e-01,  3.146868659787020e-02,  
 -6.143455982549889e-01,  9.920826636566066e-01,  4.351963504883606e-03,  
 -5.844710675512947e-01,  2.592109992058108e-01,  2.283706283744573e-02,  
 -5.748230680261558e-01, -8.760965122066653e-01,  1.943926421467558e-02,  
 -5.572474716940677e-01, -6.686420737982589e-01,  3.083669208006901e-02,  
 -5.482102814487624e-01,  4.226896138717067e-01,  1.428889064276768e-02,  
 -5.435737968160658e-01, -7.127399923480068e-02,  4.496806151459203e-02,  
 -5.391683921956473e-01, -9.726355827179098e-01,  9.266285418087179e-03,  
 -5.207225999437588e-01,  2.085864473946192e-01,  2.344644441982280e-02,  
 -5.185875206855339e-01,  8.093271136372929e-01,  2.465400557427630e-02,  
 -5.177821997159030e-01, -4.860941365404695e-01,  4.035705383914671e-03,  
 -5.159801356223465e-01,  9.489058642290333e-01,  1.356103767266921e-02,  
 -5.158924660295786e-01, -4.251904122231722e-01,  3.560324497451925e-02,  
 -4.994044935070279e-01,  6.099462217677528e-01,  3.154922279377764e-02,  
 -4.542210356062989e-01, -7.958468688022844e-01,  1.794582284359643e-02,  
 -4.056267255080869e-01,  5.341375520421459e-01,  1.152087899889739e-02,  
 -4.055948117557182e-01, -9.243438360258911e-01,  1.650133309775475e-02,  
 -4.040537647708318e-01, -9.964418579498329e-01,  3.051316164369587e-03,  
 -4.039882331666476e-01, -2.369652785329704e-01,  4.786645009346951e-02,  
 -4.035957925466688e-01, -7.396121234399951e-01,  1.283147906403060e-02,  
 -3.998139656878879e-01,  3.785894153380550e-01,  3.993632109430833e-02,  
 -3.963413695053817e-01,  9.888743963929636e-01,  6.292415031278153e-03,  
 -3.916192571372809e-01,  8.570203854231701e-02,  4.709957356606227e-02,  
 -3.781489380730715e-01, -5.664445529989698e-01,  3.920699629566945e-02,  
 -3.716587536775290e-01,  8.852446618690641e-01,  2.141062768778597e-02,  
 -3.634328788865228e-01,  7.287742400150319e-01,  2.448742112847983e-02,  
 -2.987755245919356e-01,  6.636636932174717e-01,  1.342406173089754e-02,  
 -2.968276435525883e-01, -8.304928792595524e-01,  1.658848141268110e-02,  
 -2.730446394137964e-01, -9.731854164765670e-01,  9.487914154560882e-03,  
 -2.527215209939402e-01, -3.953707636595537e-01,  4.787894718529206e-02,  
 -2.484030447599341e-01,  9.526421508958445e-01,  1.422151685597499e-02,  
 -2.449636454507225e-01, -7.846110838738764e-02,  5.146237215684395e-02,  
 -2.425768385346887e-01,  5.209707813340320e-01,  3.945757174858697e-02,  
 -2.350501139206987e-01,  2.470184275136251e-01,  4.984023350983210e-02,  
 -2.242013177906116e-01, -6.901076261298711e-01,  3.533647809963283e-02,  
 -2.185301091710398e-01, -8.814048828689003e-01,  1.288022793213647e-02,  
 -2.041253198436666e-01,  7.913052621344840e-01,  2.097344678642826e-02,  
 -1.711186961614260e-01,  8.484142146354349e-01,  1.191006595550569e-02,  
 -1.706560382250964e-01,  9.949901599692252e-01,  3.586815258663693e-03,  
 -1.215442732714673e-01, -9.952093452521580e-01,  3.571400312739183e-03,  
 -1.212739677278976e-01, -9.375172954719908e-01,  1.267403468943651e-02,  
 -9.463646218871977e-02, -5.420702319082150e-01,  4.444769202139284e-02,  
 -8.912243328958734e-02,  6.529263044412255e-01,  3.773327086808358e-02,  
 -8.859975837369544e-02, -2.416302562834947e-01,  5.169192291225042e-02,  
 -8.213238766551616e-02, -8.377296354933957e-01,  1.300368186580167e-02,  
 -7.960209828358143e-02,  8.301571435730447e-02,  5.326449572668888e-02,  
 -6.910083831974916e-02,  3.985144846429817e-01,  4.829901192754266e-02,  
 -6.703676747477079e-02,  9.036691320042987e-01,  1.766559618844168e-02,  
 -3.859244773141641e-02, -7.670969426559235e-01,  2.567105291338053e-02,  
 -2.835677761623644e-02,  9.748999327824780e-01,  8.816515305029195e-03,  
 2.835677761623644e-02, -9.748999327824780e-01,  8.816515305029195e-03,  
 3.859244773141641e-02,  7.670969426559235e-01,  2.567105291338053e-02,  
 6.703676747477079e-02, -9.036691320042987e-01,  1.766559618844168e-02,  
 6.910083831974916e-02, -3.985144846429817e-01,  4.829901192754266e-02,  
 7.960209828358143e-02, -8.301571435730447e-02,  5.326449572668888e-02,  
 8.213238766551616e-02,  8.377296354933957e-01,  1.300368186580167e-02,  
 8.859975837369544e-02,  2.416302562834947e-01,  5.169192291225042e-02,  
 8.912243328958734e-02, -6.529263044412255e-01,  3.773327086808358e-02,  
 9.463646218871977e-02,  5.420702319082150e-01,  4.444769202139284e-02,  
 1.212739677278976e-01,  9.375172954719908e-01,  1.267403468943651e-02,  
 1.215442732714673e-01,  9.952093452521580e-01,  3.571400312739183e-03,  
 1.706560382250964e-01, -9.949901599692252e-01,  3.586815258663693e-03,  
 1.711186961614260e-01, -8.484142146354349e-01,  1.191006595550569e-02,  
 2.041253198436666e-01, -7.913052621344840e-01,  2.097344678642826e-02,  
 2.185301091710398e-01,  8.814048828689003e-01,  1.288022793213647e-02,  
 2.242013177906116e-01,  6.901076261298711e-01,  3.533647809963283e-02,  
 2.350501139206987e-01, -2.470184275136251e-01,  4.984023350983210e-02,  
 2.425768385346887e-01, -5.209707813340320e-01,  3.945757174858697e-02,  
 2.449636454507225e-01,  7.846110838738764e-02,  5.146237215684395e-02,  
 2.484030447599341e-01, -9.526421508958445e-01,  1.422151685597499e-02,  
 2.527215209939402e-01,  3.953707636595537e-01,  4.787894718529206e-02,  
 2.730446394137964e-01,  9.731854164765670e-01,  9.487914154560882e-03,  
 2.968276435525883e-01,  8.304928792595524e-01,  1.658848141268110e-02,  
 2.987755245919356e-01, -6.636636932174717e-01,  1.342406173089754e-02,  
 3.634328788865228e-01, -7.287742400150319e-01,  2.448742112847983e-02,  
 3.716587536775290e-01, -8.852446618690641e-01,  2.141062768778597e-02,  
 3.781489380730715e-01,  5.664445529989698e-01,  3.920699629566945e-02,  
 3.916192571372809e-01, -8.570203854231701e-02,  4.709957356606227e-02,  
 3.963413695053817e-01, -9.888743963929636e-01,  6.292415031278153e-03,  
 3.998139656878879e-01, -3.785894153380550e-01,  3.993632109430833e-02,  
 4.035957925466688e-01,  7.396121234399951e-01,  1.283147906403060e-02,  
 4.039882331666476e-01,  2.369652785329704e-01,  4.786645009346951e-02,  
 4.040537647708318e-01,  9.964418579498329e-01,  3.051316164369587e-03,  
 4.055948117557182e-01,  9.243438360258911e-01,  1.650133309775475e-02,  
 4.056267255080869e-01, -5.341375520421459e-01,  1.152087899889739e-02,  
 4.542210356062989e-01,  7.958468688022844e-01,  1.794582284359643e-02,  
 4.994044935070279e-01, -6.099462217677528e-01,  3.154922279377764e-02,  
 5.158924660295786e-01,  4.251904122231722e-01,  3.560324497451925e-02,  
 5.159801356223465e-01, -9.489058642290333e-01,  1.356103767266921e-02,  
 5.177821997159030e-01,  4.860941365404695e-01,  4.035705383914671e-03,  
 5.185875206855339e-01, -8.093271136372929e-01,  2.465400557427630e-02,  
 5.207225999437588e-01, -2.085864473946192e-01,  2.344644441982280e-02,  
 5.391683921956473e-01,  9.726355827179098e-01,  9.266285418087179e-03,  
 5.435737968160658e-01,  7.127399923480068e-02,  4.496806151459203e-02,  
 5.482102814487624e-01, -4.226896138717067e-01,  1.428889064276768e-02,  
 5.572474716940677e-01,  6.686420737982589e-01,  3.083669208006901e-02,  
 5.748230680261558e-01,  8.760965122066653e-01,  1.943926421467558e-02,  
 5.844710675512947e-01, -2.592109992058108e-01,  2.283706283744573e-02,  
 6.143455982549889e-01, -9.920826636566066e-01,  4.351963504883606e-03,  
 6.308221736554908e-01,  2.945267523482654e-01,  3.146868659787020e-02,  
 6.404909510129633e-01, -4.864679391303438e-01,  2.960589457868493e-02,  
 6.406772691253437e-01, -7.139228812806040e-01,  2.272673241453971e-02,  
 6.499799074317244e-01, -8.924083156022753e-01,  1.749067931565174e-02,  
 6.598249437273979e-01,  9.948642685624477e-01,  2.808772731098325e-03,  
 6.758525517932752e-01,  5.427274842488018e-01,  3.178580319617729e-02,  
 6.787362302215644e-01, -8.353105038445782e-02,  3.660462342407370e-02,  
 6.848525475182752e-01,  7.813397580356689e-01,  2.347027715648843e-02,  
 6.897531031934704e-01, -6.782883935108303e-01,  6.655878361359627e-03,  
 7.005552670374735e-01,  9.406601330339404e-01,  1.246369990823231e-02,  
 7.084311098316746e-01,  1.768747230410797e-01,  2.397513960514677e-02,  
 7.295286264509984e-01, -9.665226078227548e-01,  8.147629083103793e-03,  
 7.328136392431331e-01, -2.875348312510743e-01,  1.087089248290535e-02,  
 7.450492234413376e-01, -3.427381908986717e-01,  2.313801537268639e-02,  
 7.640326515570037e-01, -8.125887805195392e-01,  1.949174894848284e-02,  
 7.704963456494349e-01, -5.900999992322654e-01,  2.533980569560729e-02,  
 7.796834866912661e-01,  3.994715783200819e-01,  2.994104825767884e-02,  
 7.887652330718642e-01,  6.709289186517926e-01,  2.371430123275542e-02,  
 7.904587180395604e-01,  3.698232163504092e-02,  2.186616762504613e-02,  
 7.981120997224805e-01,  9.863110488956950e-01,  4.428350131300970e-03,  
 7.985152091160521e-01,  8.693626506598062e-01,  1.561754453690349e-02,  
 8.166426016882831e-01, -9.271485107406205e-01,  7.934960713327414e-03,  
 8.174385098192266e-01, -9.961711079884141e-01,  2.165794610184791e-03,  
 8.228302442461702e-01,  1.697016693626475e-01,  1.342647121783435e-02,  
 8.358095013326707e-01, -1.733093930153186e-01,  2.670539971994917e-02,  
 8.562600324120904e-01, -4.495124318073283e-01,  2.357983853078307e-02,  
 8.610711834248425e-01, -7.150978677167033e-01,  1.850564562244901e-02,  
 8.688253850828861e-01,  9.504355153693655e-01,  7.016335896084859e-03,  
 8.722180260064613e-01, -8.841005984426642e-01,  8.223856754800985e-03,  
 8.735663725309100e-01,  5.411359973847757e-01,  2.141510206682392e-02,  
 8.824467573040489e-01,  2.752146559569857e-01,  2.057326622412542e-02,  
 8.829230087690153e-01,  7.770114466508429e-01,  1.555785382570586e-02,  
 8.999935234232900e-01, -9.752903231391948e-01,  4.574852292020883e-03,  
 9.057117846078058e-01, -4.659054057320846e-02,  9.353615677783169e-03,  
 9.119151052554647e-01,  4.274927442267495e-02,  1.424779189715308e-02,  
 9.211763298375819e-01,  9.934526556341349e-01,  2.003191789183488e-03,  
 9.245462285990703e-01, -2.974342857591706e-01,  1.847140993304593e-02,  
 9.283184737295814e-01, -5.879017021514434e-01,  1.561783824168382e-02,  
 9.290486544464471e-01,  8.950190921642169e-01,  7.779964394420137e-03,  
 9.317772095678226e-01, -8.201150672577782e-01,  9.940838732765474e-03,  
 9.446169086076862e-01,  4.135452324650374e-01,  1.479906753649862e-02,  
 9.449990557642718e-01,  6.629472122415720e-01,  1.284843891927071e-02,  
 9.504683215166834e-01, -9.376314986069719e-01,  4.086139127613287e-03,  
 9.638166221951805e-01,  1.751088896720577e-01,  1.281494987287384e-02,  
 9.658674622089268e-01, -9.953452266059633e-01,  1.102717947131251e-03,  
 9.694166462805192e-01, -1.256612526452283e-01,  1.203688131505905e-02,  
 9.698067055262342e-01,  9.633285091443817e-01,  3.282158060938487e-03,  
 9.726572697503230e-01,  8.181619946621148e-01,  6.464658905526641e-03,  
 9.739587062789258e-01, -4.439901118287898e-01,  1.034505230549930e-02,  
 9.740062631571137e-01, -7.162386303873299e-01,  7.887232214456035e-03,  
 9.810071147719678e-01, -8.985653300431585e-01,  3.181435032108599e-03,  
 9.861727841676639e-01,  5.400704381496431e-01,  6.797444141494801e-03,  
 9.930202681222473e-01,  3.214092657950156e-01,  4.905950396961080e-03,  
 9.937038655576630e-01,  9.931050540649843e-01,  4.830386117047890e-04,  
 9.943677037885296e-01, -9.710410041880194e-01,  1.118097006661641e-03,  
 9.943750550352027e-01,  3.487179202856331e-02,  4.548201806973092e-03,  
 9.949775104476455e-01,  7.198973208744759e-01,  2.841977406946536e-03,  
 9.952722138287154e-01, -2.785041956973013e-01,  4.045664611880734e-03,  
 9.954067560360648e-01,  9.074145716693054e-01,  1.810898452206362e-03,  
 9.959258876623405e-01, -8.226232166208993e-01,  1.978505799274471e-03,  
 9.963054076831271e-01, -5.895227652492729e-01,  3.040448117975760e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr35s ( )

/******************************************************************************/
/*
  Purpose:

    SMR35S returns the rotationally invariant SMR rule of degree 35.

  Discussion:
 
    DEGREE: 35
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 220
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 6.54962e-03,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR35S[3*220], the requested rule.
*/
{
  const int degree = 35;
  int order;
  double xw[3*220] = {
 4.889904361809121e-03,  1.619503174532069e-01,  5.226179892467336e-02,  
 1.430680275835659e-02,  4.693240762340044e-01,  4.679625079080703e-02,  
 1.814469250768224e-01,  6.009339848917693e-01,  4.158929555209646e-02,  
 3.513535787046233e-02,  9.092730028762068e-01,  2.186232237110550e-02,  
 7.640565697368758e-02,  9.941574902382558e-01,  4.878857836280798e-03,  
 1.713276929018882e-01,  3.150081208611397e-01,  4.954187274939539e-02,  
 1.878090789211163e-01,  8.240874417949644e-01,  2.885775015170009e-02,  
 3.641585032828187e-01,  8.926397561302795e-01,  1.380108158872173e-02,  
 3.369795025432279e-01,  8.976793330525874e-01,  7.578776426504399e-03,  
 2.085987555621641e-01,  9.589188503432696e-01,  1.412626006558690e-02,  
 3.243221451814440e-01,  1.522018736597065e-01,  4.954596092265034e-02,  
 3.340889484224165e-01,  4.585908563274512e-01,  4.430990763422363e-02,  
 3.416707320282502e-01,  7.180689168234468e-01,  3.441280383837739e-02,  
 5.024923591323561e-01,  8.083923344052878e-01,  2.637941189985826e-02,  
 4.874255868918486e-01,  9.513870810486795e-01,  1.250237621770788e-02,  
 3.540377809173803e-01,  9.907757451385623e-01,  5.795738840614077e-03,  
 6.111391703621065e-01,  1.419989823593704e-01,  4.138723814719325e-02,  
 4.786194165434669e-01,  3.040699140137090e-01,  4.424656646443821e-02,  
 4.861267145306208e-01,  5.913669578961687e-01,  3.721264812187189e-02,  
 6.345277961643816e-01,  6.987872435915059e-01,  2.910424842344178e-02,  
 6.280256760699003e-01,  8.900123914565822e-01,  1.728479546144200e-02,  
 5.638455934275640e-01,  9.906924665049914e-01,  3.999894615639466e-03,  
 7.357593544096634e-01,  2.940516185138239e-01,  3.430970133414903e-02,  
 6.187418092262584e-01,  4.486490710363784e-01,  3.718438978370203e-02,  
 7.505794530276153e-01,  5.696684149936826e-01,  2.884692065902148e-02,  
 7.475454182228141e-01,  8.033938822693132e-01,  2.018681888060652e-02,  
 6.695740390881190e-01,  9.620089635211753e-01,  5.992235715031513e-03,  
 7.137131446338533e-01,  9.946730046954464e-01,  2.252933356555567e-03,  
 7.266647735941557e-01, -2.452226684020481e-02,  3.613466911375480e-02,  
 8.470677884177439e-01,  4.244997249111068e-01,  2.562278510791793e-02,  
 8.461060260934473e-01,  6.944065541165793e-01,  2.014809941680893e-02,  
 7.673369976264737e-01,  9.139571921846420e-01,  5.720892850954219e-03,  
 7.837945110129694e-01,  9.598803080155067e-01,  5.594606457330472e-03,  
 8.527052966458518e-01,  9.899482390180141e-01,  3.064017911530195e-03,  
 8.330453451104365e-01,  1.306648127961336e-01,  2.910519731720890e-02,  
 9.208363926514060e-01,  5.648082314710416e-01,  1.681694481057345e-02,  
 8.555714597948697e-01,  8.421130303734168e-01,  3.389803494740707e-03,  
 8.569746510423235e-01,  8.904703192599482e-01,  8.892049582448583e-03,  
 9.163957789950904e-01,  9.512153808029943e-01,  5.736088538001383e-03,  
 9.468183474113080e-01,  9.935269656304787e-01,  1.198934044159158e-03,  
 9.709743906771017e-01,  1.015883859290755e-01,  1.259776829311839e-02,  
 9.211304080943010e-01,  2.672344770872243e-01,  2.012412691259350e-02,  
 9.720064559847991e-01,  4.216836904760396e-01,  1.141976686833465e-02,  
 9.932227888701425e-01,  6.482010598302427e-01, -1.475608411232590e-03,  
 9.826552234357039e-01,  6.932083351123020e-01,  4.286571189420782e-03,  
 9.238348699268808e-01,  7.973265219048701e-01,  1.108551064645477e-02,  
 9.785171113227352e-01,  9.731930158842385e-01,  1.481797407435137e-03,  
 9.963425748043122e-01,  2.646515091977871e-01,  3.893391747905868e-03,  
 9.988925112672711e-01,  4.106568212342961e-01, -1.617960722779276e-04,  
 9.959215572099368e-01,  5.751170429423320e-01,  3.902216245624410e-03,  
 9.640572980293431e-01,  6.867546611123180e-01,  5.691309854696837e-03,  
 9.945462995891214e-01,  8.085573402233180e-01,  2.563895647702530e-03,  
 9.670114428073955e-01,  8.888800101355042e-01,  5.609754500116319e-03,  
 9.958210056699377e-01,  9.383693663697456e-01,  1.047624717542818e-03,  
 9.943379392579890e-01,  9.949415630191232e-01,  2.607250337397194e-04,  
 -1.619503174532069e-01,  4.889904361809121e-03,  5.226179892467336e-02,  
 -4.693240762340044e-01,  1.430680275835659e-02,  4.679625079080703e-02,  
 -6.009339848917693e-01,  1.814469250768224e-01,  4.158929555209646e-02,  
 -9.092730028762068e-01,  3.513535787046233e-02,  2.186232237110550e-02,  
 -9.941574902382558e-01,  7.640565697368758e-02,  4.878857836280798e-03,  
 -3.150081208611397e-01,  1.713276929018882e-01,  4.954187274939539e-02,  
 -8.240874417949644e-01,  1.878090789211163e-01,  2.885775015170009e-02,  
 -8.926397561302795e-01,  3.641585032828187e-01,  1.380108158872173e-02,  
 -8.976793330525874e-01,  3.369795025432279e-01,  7.578776426504399e-03,  
 -9.589188503432696e-01,  2.085987555621641e-01,  1.412626006558690e-02,  
 -1.522018736597065e-01,  3.243221451814440e-01,  4.954596092265034e-02,  
 -4.585908563274512e-01,  3.340889484224165e-01,  4.430990763422363e-02,  
 -7.180689168234468e-01,  3.416707320282502e-01,  3.441280383837739e-02,  
 -8.083923344052878e-01,  5.024923591323561e-01,  2.637941189985826e-02,  
 -9.513870810486795e-01,  4.874255868918486e-01,  1.250237621770788e-02,  
 -9.907757451385623e-01,  3.540377809173803e-01,  5.795738840614077e-03,  
 -1.419989823593704e-01,  6.111391703621065e-01,  4.138723814719325e-02,  
 -3.040699140137090e-01,  4.786194165434669e-01,  4.424656646443821e-02,  
 -5.913669578961687e-01,  4.861267145306208e-01,  3.721264812187189e-02,  
 -6.987872435915059e-01,  6.345277961643816e-01,  2.910424842344178e-02,  
 -8.900123914565822e-01,  6.280256760699003e-01,  1.728479546144200e-02,  
 -9.906924665049914e-01,  5.638455934275640e-01,  3.999894615639466e-03,  
 -2.940516185138239e-01,  7.357593544096634e-01,  3.430970133414903e-02,  
 -4.486490710363784e-01,  6.187418092262584e-01,  3.718438978370203e-02,  
 -5.696684149936826e-01,  7.505794530276153e-01,  2.884692065902148e-02,  
 -8.033938822693132e-01,  7.475454182228141e-01,  2.018681888060652e-02,  
 -9.620089635211753e-01,  6.695740390881190e-01,  5.992235715031513e-03,  
 -9.946730046954464e-01,  7.137131446338533e-01,  2.252933356555567e-03,  
 2.452226684020481e-02,  7.266647735941557e-01,  3.613466911375480e-02,  
 -4.244997249111068e-01,  8.470677884177439e-01,  2.562278510791793e-02,  
 -6.944065541165793e-01,  8.461060260934473e-01,  2.014809941680893e-02,  
 -9.139571921846420e-01,  7.673369976264737e-01,  5.720892850954219e-03,  
 -9.598803080155067e-01,  7.837945110129694e-01,  5.594606457330472e-03,  
 -9.899482390180141e-01,  8.527052966458518e-01,  3.064017911530195e-03,  
 -1.306648127961336e-01,  8.330453451104365e-01,  2.910519731720890e-02,  
 -5.648082314710416e-01,  9.208363926514060e-01,  1.681694481057345e-02,  
 -8.421130303734168e-01,  8.555714597948697e-01,  3.389803494740707e-03,  
 -8.904703192599482e-01,  8.569746510423235e-01,  8.892049582448583e-03,  
 -9.512153808029943e-01,  9.163957789950904e-01,  5.736088538001383e-03,  
 -9.935269656304787e-01,  9.468183474113080e-01,  1.198934044159158e-03,  
 -1.015883859290755e-01,  9.709743906771017e-01,  1.259776829311839e-02,  
 -2.672344770872243e-01,  9.211304080943010e-01,  2.012412691259350e-02,  
 -4.216836904760396e-01,  9.720064559847991e-01,  1.141976686833465e-02,  
 -6.482010598302427e-01,  9.932227888701425e-01, -1.475608411232590e-03,  
 -6.932083351123020e-01,  9.826552234357039e-01,  4.286571189420782e-03,  
 -7.973265219048701e-01,  9.238348699268808e-01,  1.108551064645477e-02,  
 -9.731930158842385e-01,  9.785171113227352e-01,  1.481797407435137e-03,  
 -2.646515091977871e-01,  9.963425748043122e-01,  3.893391747905868e-03,  
 -4.106568212342961e-01,  9.988925112672711e-01, -1.617960722779276e-04,  
 -5.751170429423320e-01,  9.959215572099368e-01,  3.902216245624410e-03,  
 -6.867546611123180e-01,  9.640572980293431e-01,  5.691309854696837e-03,  
 -8.085573402233180e-01,  9.945462995891214e-01,  2.563895647702530e-03,  
 -8.888800101355042e-01,  9.670114428073955e-01,  5.609754500116319e-03,  
 -9.383693663697456e-01,  9.958210056699377e-01,  1.047624717542818e-03,  
 -9.949415630191232e-01,  9.943379392579890e-01,  2.607250337397194e-04,  
 -4.889904361809121e-03, -1.619503174532069e-01,  5.226179892467336e-02,  
 -1.430680275835659e-02, -4.693240762340044e-01,  4.679625079080703e-02,  
 -1.814469250768224e-01, -6.009339848917693e-01,  4.158929555209646e-02,  
 -3.513535787046233e-02, -9.092730028762068e-01,  2.186232237110550e-02,  
 -7.640565697368758e-02, -9.941574902382558e-01,  4.878857836280798e-03,  
 -1.713276929018882e-01, -3.150081208611397e-01,  4.954187274939539e-02,  
 -1.878090789211163e-01, -8.240874417949644e-01,  2.885775015170009e-02,  
 -3.641585032828187e-01, -8.926397561302795e-01,  1.380108158872173e-02,  
 -3.369795025432279e-01, -8.976793330525874e-01,  7.578776426504399e-03,  
 -2.085987555621641e-01, -9.589188503432696e-01,  1.412626006558690e-02,  
 -3.243221451814440e-01, -1.522018736597065e-01,  4.954596092265034e-02,  
 -3.340889484224165e-01, -4.585908563274512e-01,  4.430990763422363e-02,  
 -3.416707320282502e-01, -7.180689168234468e-01,  3.441280383837739e-02,  
 -5.024923591323561e-01, -8.083923344052878e-01,  2.637941189985826e-02,  
 -4.874255868918486e-01, -9.513870810486795e-01,  1.250237621770788e-02,  
 -3.540377809173803e-01, -9.907757451385623e-01,  5.795738840614077e-03,  
 -6.111391703621065e-01, -1.419989823593704e-01,  4.138723814719325e-02,  
 -4.786194165434669e-01, -3.040699140137090e-01,  4.424656646443821e-02,  
 -4.861267145306208e-01, -5.913669578961687e-01,  3.721264812187189e-02,  
 -6.345277961643816e-01, -6.987872435915059e-01,  2.910424842344178e-02,  
 -6.280256760699003e-01, -8.900123914565822e-01,  1.728479546144200e-02,  
 -5.638455934275640e-01, -9.906924665049914e-01,  3.999894615639466e-03,  
 -7.357593544096634e-01, -2.940516185138239e-01,  3.430970133414903e-02,  
 -6.187418092262584e-01, -4.486490710363784e-01,  3.718438978370203e-02,  
 -7.505794530276153e-01, -5.696684149936826e-01,  2.884692065902148e-02,  
 -7.475454182228141e-01, -8.033938822693132e-01,  2.018681888060652e-02,  
 -6.695740390881190e-01, -9.620089635211753e-01,  5.992235715031513e-03,  
 -7.137131446338533e-01, -9.946730046954464e-01,  2.252933356555567e-03,  
 -7.266647735941557e-01,  2.452226684020481e-02,  3.613466911375480e-02,  
 -8.470677884177439e-01, -4.244997249111068e-01,  2.562278510791793e-02,  
 -8.461060260934473e-01, -6.944065541165793e-01,  2.014809941680893e-02,  
 -7.673369976264737e-01, -9.139571921846420e-01,  5.720892850954219e-03,  
 -7.837945110129694e-01, -9.598803080155067e-01,  5.594606457330472e-03,  
 -8.527052966458518e-01, -9.899482390180141e-01,  3.064017911530195e-03,  
 -8.330453451104365e-01, -1.306648127961336e-01,  2.910519731720890e-02,  
 -9.208363926514060e-01, -5.648082314710416e-01,  1.681694481057345e-02,  
 -8.555714597948697e-01, -8.421130303734168e-01,  3.389803494740707e-03,  
 -8.569746510423235e-01, -8.904703192599482e-01,  8.892049582448583e-03,  
 -9.163957789950904e-01, -9.512153808029943e-01,  5.736088538001383e-03,  
 -9.468183474113080e-01, -9.935269656304787e-01,  1.198934044159158e-03,  
 -9.709743906771017e-01, -1.015883859290755e-01,  1.259776829311839e-02,  
 -9.211304080943010e-01, -2.672344770872243e-01,  2.012412691259350e-02,  
 -9.720064559847991e-01, -4.216836904760396e-01,  1.141976686833465e-02,  
 -9.932227888701425e-01, -6.482010598302427e-01, -1.475608411232590e-03,  
 -9.826552234357039e-01, -6.932083351123020e-01,  4.286571189420782e-03,  
 -9.238348699268808e-01, -7.973265219048701e-01,  1.108551064645477e-02,  
 -9.785171113227352e-01, -9.731930158842385e-01,  1.481797407435137e-03,  
 -9.963425748043122e-01, -2.646515091977871e-01,  3.893391747905868e-03,  
 -9.988925112672711e-01, -4.106568212342961e-01, -1.617960722779276e-04,  
 -9.959215572099368e-01, -5.751170429423320e-01,  3.902216245624410e-03,  
 -9.640572980293431e-01, -6.867546611123180e-01,  5.691309854696837e-03,  
 -9.945462995891214e-01, -8.085573402233180e-01,  2.563895647702530e-03,  
 -9.670114428073955e-01, -8.888800101355042e-01,  5.609754500116319e-03,  
 -9.958210056699377e-01, -9.383693663697456e-01,  1.047624717542818e-03,  
 -9.943379392579890e-01, -9.949415630191232e-01,  2.607250337397194e-04,  
 1.619503174532069e-01, -4.889904361809121e-03,  5.226179892467336e-02,  
 4.693240762340044e-01, -1.430680275835659e-02,  4.679625079080703e-02,  
 6.009339848917693e-01, -1.814469250768224e-01,  4.158929555209646e-02,  
 9.092730028762068e-01, -3.513535787046233e-02,  2.186232237110550e-02,  
 9.941574902382558e-01, -7.640565697368758e-02,  4.878857836280798e-03,  
 3.150081208611397e-01, -1.713276929018882e-01,  4.954187274939539e-02,  
 8.240874417949644e-01, -1.878090789211163e-01,  2.885775015170009e-02,  
 8.926397561302795e-01, -3.641585032828187e-01,  1.380108158872173e-02,  
 8.976793330525874e-01, -3.369795025432279e-01,  7.578776426504399e-03,  
 9.589188503432696e-01, -2.085987555621641e-01,  1.412626006558690e-02,  
 1.522018736597065e-01, -3.243221451814440e-01,  4.954596092265034e-02,  
 4.585908563274512e-01, -3.340889484224165e-01,  4.430990763422363e-02,  
 7.180689168234468e-01, -3.416707320282502e-01,  3.441280383837739e-02,  
 8.083923344052878e-01, -5.024923591323561e-01,  2.637941189985826e-02,  
 9.513870810486795e-01, -4.874255868918486e-01,  1.250237621770788e-02,  
 9.907757451385623e-01, -3.540377809173803e-01,  5.795738840614077e-03,  
 1.419989823593704e-01, -6.111391703621065e-01,  4.138723814719325e-02,  
 3.040699140137090e-01, -4.786194165434669e-01,  4.424656646443821e-02,  
 5.913669578961687e-01, -4.861267145306208e-01,  3.721264812187189e-02,  
 6.987872435915059e-01, -6.345277961643816e-01,  2.910424842344178e-02,  
 8.900123914565822e-01, -6.280256760699003e-01,  1.728479546144200e-02,  
 9.906924665049914e-01, -5.638455934275640e-01,  3.999894615639466e-03,  
 2.940516185138239e-01, -7.357593544096634e-01,  3.430970133414903e-02,  
 4.486490710363784e-01, -6.187418092262584e-01,  3.718438978370203e-02,  
 5.696684149936826e-01, -7.505794530276153e-01,  2.884692065902148e-02,  
 8.033938822693132e-01, -7.475454182228141e-01,  2.018681888060652e-02,  
 9.620089635211753e-01, -6.695740390881190e-01,  5.992235715031513e-03,  
 9.946730046954464e-01, -7.137131446338533e-01,  2.252933356555567e-03,  
 -2.452226684020481e-02, -7.266647735941557e-01,  3.613466911375480e-02,  
 4.244997249111068e-01, -8.470677884177439e-01,  2.562278510791793e-02,  
 6.944065541165793e-01, -8.461060260934473e-01,  2.014809941680893e-02,  
 9.139571921846420e-01, -7.673369976264737e-01,  5.720892850954219e-03,  
 9.598803080155067e-01, -7.837945110129694e-01,  5.594606457330472e-03,  
 9.899482390180141e-01, -8.527052966458518e-01,  3.064017911530195e-03,  
 1.306648127961336e-01, -8.330453451104365e-01,  2.910519731720890e-02,  
 5.648082314710416e-01, -9.208363926514060e-01,  1.681694481057345e-02,  
 8.421130303734168e-01, -8.555714597948697e-01,  3.389803494740707e-03,  
 8.904703192599482e-01, -8.569746510423235e-01,  8.892049582448583e-03,  
 9.512153808029943e-01, -9.163957789950904e-01,  5.736088538001383e-03,  
 9.935269656304787e-01, -9.468183474113080e-01,  1.198934044159158e-03,  
 1.015883859290755e-01, -9.709743906771017e-01,  1.259776829311839e-02,  
 2.672344770872243e-01, -9.211304080943010e-01,  2.012412691259350e-02,  
 4.216836904760396e-01, -9.720064559847991e-01,  1.141976686833465e-02,  
 6.482010598302427e-01, -9.932227888701425e-01, -1.475608411232590e-03,  
 6.932083351123020e-01, -9.826552234357039e-01,  4.286571189420782e-03,  
 7.973265219048701e-01, -9.238348699268808e-01,  1.108551064645477e-02,  
 9.731930158842385e-01, -9.785171113227352e-01,  1.481797407435137e-03,  
 2.646515091977871e-01, -9.963425748043122e-01,  3.893391747905868e-03,  
 4.106568212342961e-01, -9.988925112672711e-01, -1.617960722779276e-04,  
 5.751170429423320e-01, -9.959215572099368e-01,  3.902216245624410e-03,  
 6.867546611123180e-01, -9.640572980293431e-01,  5.691309854696837e-03,  
 8.085573402233180e-01, -9.945462995891214e-01,  2.563895647702530e-03,  
 8.888800101355042e-01, -9.670114428073955e-01,  5.609754500116319e-03,  
 9.383693663697456e-01, -9.958210056699377e-01,  1.047624717542818e-03,  
 9.949415630191232e-01, -9.943379392579890e-01,  2.607250337397194e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr36 ( )

/******************************************************************************/
/*
  Purpose:

    SMR36 returns the SMR rule of degree 36.

  Discussion:
 
    DEGREE: 36
    POINTS CARDINALITY: 238
    NORM INF MOMS. RESIDUAL: 4.27609e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR36[3*238], the requested rule.
*/
{
  const int degree = 36;
  int order;
  double xw[3*238] = {
 -9.978817227614055e-01, -8.890076517204608e-04,  2.330741632674278e-03,  
 -9.973711646404451e-01, -9.532092615783677e-01,  9.627969193226537e-04,  
 -9.961692635944124e-01,  9.688495936611794e-01,  8.898973486835064e-04,  
 -9.959497922009879e-01, -3.098803144458146e-01,  2.832831652522147e-03,  
 -9.959465092993447e-01, -5.592627350774092e-01,  2.519247595249725e-03,  
 -9.954980310007229e-01,  6.046856101951658e-01,  2.958064214592169e-03,  
 -9.946662450102303e-01,  3.416260049342602e-01,  3.892327512506448e-03,  
 -9.934973736752050e-01, -7.316617433785163e-01,  2.288706827417947e-03,  
 -9.917053480435074e-01,  8.702611598150070e-01,  1.958941400105963e-03,  
 -9.916694420714898e-01,  7.809558409845563e-01,  2.395428553360631e-03,  
 -9.895910809889403e-01, -8.396046316830745e-01,  2.802701148321813e-03,  
 -9.831331889300642e-01,  1.393223594054985e-01,  6.694472389602429e-03,  
 -9.807631633241672e-01, -1.600365161997248e-01,  7.382399101251368e-03,  
 -9.798886059262791e-01, -9.915282494038506e-01,  1.128746425663043e-03,  
 -9.750680034434991e-01, -4.311357357378125e-01,  7.832140397353063e-03,  
 -9.728412562557132e-01,  9.944489940720668e-01,  1.002140135620488e-03,  
 -9.710537275206133e-01,  4.830250325748792e-01,  9.568264880729656e-03,  
 -9.689535066576080e-01, -9.071389361410935e-01,  4.309260818499709e-03,  
 -9.687604103109784e-01, -6.302344727365032e-01,  6.664551467651576e-03,  
 -9.687211535263930e-01,  9.237100995654350e-01,  4.080017523260788e-03,  
 -9.668485420668568e-01,  7.049532664378062e-01,  7.415218794906055e-03,  
 -9.535784368796688e-01,  2.490218550690452e-01,  1.037891180826214e-02,  
 -9.512663640224540e-01, -7.491171041425378e-01,  7.422605405628350e-03,  
 -9.493818109732231e-01, -2.852036250206639e-02,  1.195246886959401e-02,  
 -9.367870389253897e-01,  8.258762212688808e-01,  8.844488878029041e-03,  
 -9.363513457140649e-01, -2.859985380532227e-01,  1.380555928314730e-02,  
 -9.360696971408200e-01, -9.644084451245751e-01,  4.146894859108681e-03,  
 -9.239202364264265e-01,  9.695178305424945e-01,  4.259509443297511e-03,  
 -9.225706959239526e-01, -5.058509463174830e-01,  1.253905649616530e-02,  
 -9.179832388286352e-01,  6.014333969026019e-01,  1.426678903924167e-02,  
 -9.149034273351938e-01, -8.372226403884956e-01,  9.334389760441908e-03,  
 -9.138551873238143e-01,  3.754959341345724e-01,  1.452036035160031e-02,  
 -8.996791165793870e-01,  9.328644693068573e-02,  1.734677366105503e-02,  
 -8.885447268542435e-01, -6.386179822823047e-01,  1.367023050135804e-02,  
 -8.871714117838472e-01, -9.948601599114012e-01,  1.899222828399880e-03,  
 -8.816880330919030e-01, -1.586021131310660e-01,  1.669820902512087e-02,  
 -8.812403173103464e-01,  8.951164258907871e-01,  8.364155027998615e-03,  
 -8.656692388301289e-01,  7.350500859830660e-01,  1.548010198333609e-02,  
 -8.643529629348047e-01, -9.173100142874313e-01,  9.120730562086893e-03,  
 -8.641286582087778e-01,  9.950657916116978e-01,  1.918170304192286e-03,  
 -8.522612942302550e-01, -3.788264332914240e-01,  2.087884271099431e-02,  
 -8.422113258119911e-01,  2.446382041130486e-01,  2.002609499764870e-02,  
 -8.416694599504575e-01,  4.814984345703843e-01,  1.925007441204762e-02,  
 -8.360902062521303e-01, -7.477119396150796e-01,  1.554744797988430e-02,  
 -8.203145632717700e-01, -5.613317466249494e-02,  1.901567227303284e-02,  
 -8.199490742198897e-01,  9.428287492604916e-01,  7.056116422992586e-03,  
 -7.984923809331644e-01, -9.722593485667060e-01,  6.504144377884679e-03,  
 -7.937886622074718e-01, -5.311719776256463e-01,  2.203842796899376e-02,  
 -7.898800883541095e-01,  8.213759805863565e-01,  1.360908524722615e-02,  
 -7.857456450301465e-01,  6.109453946109499e-01,  1.776520678097427e-02,  
 -7.707528347691809e-01,  1.109546864852665e-01,  2.039092251468907e-02,  
 -7.702900422534331e-01, -8.487764338033230e-01,  1.532480873697326e-02,  
 -7.576331295741205e-01, -2.435713966271017e-01,  2.854257229107140e-02,  
 -7.569151133259240e-01,  9.814581630123478e-01,  4.921916895711927e-03,  
 -7.438369227242233e-01,  3.482222843377805e-01,  2.451979727480189e-02,  
 -7.241630175636773e-01, -6.592065655597069e-01,  2.199849707676197e-02,  
 -7.176692539981274e-01,  8.801116546686418e-01,  1.112305619521462e-02,  
 -7.124686946589255e-01,  6.945133493012733e-01,  1.771156252011625e-02,  
 -7.069737778502420e-01, -9.962628623410572e-01,  2.374966048245442e-03,  
 -6.963043004286823e-01, -8.135105429081526e-03,  2.318695224198078e-02,  
 -6.921249477814184e-01,  4.700703121100537e-01,  1.655699575608719e-02,  
 -6.892915677631921e-01, -9.267197507187467e-01,  1.257447358342760e-02,  
 -6.785922159896439e-01, -4.067666128583923e-01,  2.999698423607718e-02,  
 -6.552506919956539e-01,  9.423928975555224e-01,  9.667568404627368e-03,  
 -6.449800715385902e-01, -7.742900371415136e-01,  2.163194611984287e-02,  
 -6.384020750298662e-01,  2.053842735458858e-01,  3.298168414587938e-02,  
 -6.376845625430727e-01,  9.961884415103500e-01,  2.510551666922923e-03,  
 -6.198393609997173e-01,  7.788946966190957e-01,  2.119226728365691e-02,  
 -6.187213657289741e-01, -1.433838420063922e-01,  3.147480251378770e-02,  
 -6.160766221019519e-01,  5.525549239562721e-01,  2.501384151648360e-02,  
 -5.942484471471827e-01, -5.523398131727161e-01,  2.880932433502099e-02,  
 -5.886645820614776e-01, -9.742244390227165e-01,  7.791673063038694e-03,  
 -5.491885966414285e-01, -8.701566014002242e-01,  1.925267375227190e-02,  
 -5.454451806767899e-01,  8.873611141110606e-01,  1.421144648662051e-02,  
 -5.363668460871786e-01,  3.689903490268424e-01,  3.551950638985276e-02,  
 -5.288973102226180e-01, -3.000753546210893e-01,  3.577864794644277e-02,  
 -5.228971037176965e-01,  5.511893622125074e-02,  3.559238125168576e-02,  
 -5.149484349272324e-01,  9.736990573228385e-01,  8.663852126555528e-03,  
 -5.034028322638731e-01, -6.810046891007370e-01,  2.770229125683340e-02,  
 -5.018240598484098e-01,  6.610827773551222e-01,  2.955164458688282e-02,  
 -4.836723369928086e-01, -9.951317872137048e-01,  2.432216069339591e-03,  
 -4.472178273697551e-01,  8.261234039804835e-01,  1.723994440057944e-02,  
 -4.351671626526074e-01, -9.405635523740720e-01,  1.391944650569191e-02,  
 -4.325000537322283e-01, -4.571254404046099e-01,  3.550196939096451e-02,  
 -4.221899486344116e-01,  2.072870640590052e-01,  2.856147506087960e-02,  
 -4.184381906407810e-01, -9.486272782368495e-02,  3.647913743103923e-02,  
 -4.051084329362841e-01,  4.968069795284735e-01,  3.427981654195449e-02,  
 -3.996415711088327e-01, -7.922180602255362e-01,  2.534465150429595e-02,  
 -3.802275025133069e-01,  9.957850696595502e-01,  3.171371339804449e-03,  
 -3.746724165491376e-01,  9.322066554008961e-01,  1.474166848943957e-02,  
 -3.507030139156035e-01,  7.411784897062579e-01,  2.164321207016425e-02,  
 -3.396094592441956e-01,  2.851648864371023e-01,  2.378767233475549e-02,  
 -3.373067518851020e-01, -9.891744514862336e-01,  4.703010171973971e-03,  
 -3.310224303024400e-01, -2.403265390297470e-01,  3.423310351714857e-02,  
 -3.277966873918430e-01, -5.977752159941997e-01,  3.339651184485331e-02,  
 -2.908043265646401e-01,  5.910702778731858e-01,  2.096575868118241e-02,  
 -2.890360016090808e-01, -8.852915279552505e-01,  1.911208855887150e-02,  
 -2.761160035464659e-01,  7.095757720766041e-02,  4.278824944215505e-02,  
 -2.702812218851570e-01,  8.808141244965264e-01,  1.053036550496354e-02,  
 -2.649298324354653e-01,  7.864553422973282e-01,  8.647185905965778e-03,  
 -2.401609050863505e-01,  9.806596979744967e-01,  5.868860421996299e-03,  
 -2.377667595528341e-01, -3.801643379704139e-01,  3.628804159235034e-02,  
 -2.206216268941887e-01, -7.204121124667704e-01,  2.854623272707025e-02,  
 -2.201538989416436e-01,  3.913115801581338e-01,  3.894518817033470e-02,  
 -2.193792333441053e-01, -9.646669064229157e-01,  1.014429441651051e-02,  
 -1.934707182262981e-01,  6.432496392898787e-01,  2.233474208920316e-02,  
 -1.772628853095497e-01,  9.609427885428339e-01,  7.154337173291553e-03,  
 -1.729141076933932e-01,  8.539977338065532e-01,  1.673175151833196e-02,  
 -1.718150507993583e-01, -9.405721790034696e-02,  4.086787977428533e-02,  
 -1.328625066941062e-01, -8.318318453990768e-01,  1.982971921305763e-02,  
 -1.307387810744456e-01, -5.185641556580906e-01,  3.616547559993144e-02,  
 -1.100824617462925e-01,  2.107790367554701e-01,  4.576013746563733e-02,  
 -9.984259485045630e-02, -9.955064961031446e-01,  3.717433056480130e-03,  
 -9.328608102993199e-02,  7.332290790832092e-01,  2.071715580387419e-02,  
 -6.793914116753401e-02, -2.506459841110294e-01,  4.089224120208960e-02,  
 -6.741335673585816e-02, -9.267152274199159e-01,  1.602534157276938e-02,  
 -6.637788288034263e-02,  5.124518645869145e-01,  3.844362321627411e-02,  
 -5.192619879677355e-02,  9.952626224499167e-01,  3.973984013870450e-03,  
 -4.256393926237442e-02, -6.587648588333753e-01,  2.554184333603511e-02,  
 -3.928908743269727e-02,  9.249275328206857e-01,  1.717155965123946e-02,  
 -8.616254706753439e-03,  7.863971003772713e-01,  1.617333783082740e-02,  
 3.445686005032637e-03,  3.438556195988679e-02,  4.484896925422164e-02,  
 2.162783184909196e-02, -7.869560221084054e-01,  2.154792738605269e-02,  
 4.685825299635766e-02, -4.020978227292492e-01,  4.049427770416184e-02,  
 5.479814290878701e-02,  3.514969350769057e-01,  4.422512667927580e-02,  
 6.774629290604679e-02, -9.760182750123766e-01,  9.963602473671930e-03,  
 7.328667269147976e-02, -5.930557986747867e-01,  1.877217900127421e-02,  
 8.018258564306395e-02,  6.365101735574987e-01,  3.483121330550053e-02,  
 1.073043308069154e-01,  8.535066059079015e-01,  2.227117133691220e-02,  
 1.113229411695483e-01, -8.835075472889613e-01,  1.949085547150652e-02,  
 1.114570513525386e-01,  9.729484455626918e-01,  1.101932189177536e-02,  
 1.153437593007439e-01, -1.317768141870329e-01,  4.247315097231750e-02,  
 1.690835216382367e-01,  1.764988836591127e-01,  4.458603343706025e-02,  
 1.753955610939935e-01, -7.156031949485488e-01,  2.527623764375623e-02,  
 1.976972674748326e-01, -5.279953242568892e-01,  3.026255490382024e-02,  
 2.116967467449395e-01,  4.926985242614755e-01,  4.098066738615446e-02,  
 2.235223377254471e-01,  7.379223803362939e-01,  2.795309201248948e-02,  
 2.258353983807109e-01, -2.868829397355061e-01,  3.947306768337931e-02,  
 2.264823571880064e-01, -9.969471381094707e-01,  3.073985454466239e-03,  
 2.490851417470266e-01, -9.447796629842063e-01,  1.396431826192642e-02,  
 2.508519660769009e-01,  9.195561800757367e-01,  1.768832443081297e-02,  
 2.680482539332619e-01, -8.226935415045739e-01,  1.981797389395326e-02,  
 2.680721351751811e-01,  9.958511445825230e-01,  3.640429024869928e-03,  
 2.821534236058784e-01,  7.446925967702267e-03,  4.211100109823734e-02,  
 3.247146118763189e-01,  3.224964883167490e-01,  4.234100652772199e-02,  
 3.343254479054538e-01, -6.422924772737209e-01,  2.425454643455124e-02,  
 3.453396235355017e-01, -4.291253398815807e-01,  3.317163396355886e-02,  
 3.462605320455555e-01,  8.161845863833764e-01,  1.987362322109004e-02,  
 3.651493677371224e-01,  6.182965874272552e-01,  3.559824694190696e-02,  
 3.854996236485986e-01, -1.532257150482036e-01,  3.742508791404799e-02,  
 3.870016759773888e-01, -7.585686209099854e-01,  1.501299544256757e-02,  
 3.938946116638710e-01,  9.662848771953462e-01,  1.068691773232336e-02,  
 3.982573856142398e-01, -8.950554117718855e-01,  1.602448842253433e-02,  
 4.016801936992866e-01, -9.813691194805932e-01,  7.892152840793696e-03,  
 4.371070566774968e-01,  1.511026982040890e-01,  4.102768020962930e-02,  
 4.544035146465257e-01,  8.763928228014183e-01,  1.634600741893583e-02,  
 4.558293123288908e-01, -5.713496230258187e-01,  2.252028952268153e-02,  
 4.732557000280899e-01,  4.583389381205352e-01,  3.776384470597906e-02,  
 4.810692207812149e-01, -3.081467734409822e-01,  3.206248778671018e-02,  
 5.077103930139962e-01, -8.274029452105797e-01,  1.494395639519947e-02,  
 5.078271770180696e-01,  7.302517937446340e-01,  2.869995132952615e-02,  
 5.184597430790860e-01,  9.915516893623654e-01,  4.063313365916709e-03,  
 5.243768590626090e-01, -7.095143454551895e-01,  1.946548740642335e-02,  
 5.347672174839160e-01, -2.303639928245786e-02,  3.592243824739078e-02,  
 5.378718338501072e-01, -9.453203497305898e-01,  1.131041403550440e-02,  
 5.604528611741826e-01, -4.738251057279866e-01,  2.716710521567537e-02,  
 5.649480860981207e-01, -9.961787956204670e-01,  2.686662642257578e-03,  
 5.694785456537736e-01,  9.306241376040423e-01,  1.310983188725784e-02,  
 5.797726075345430e-01,  2.904464196731755e-01,  3.707917140022222e-02,  
 6.073441340190595e-01,  5.863537474015226e-01,  3.123083612446972e-02,  
 6.146619349973880e-01, -1.954577444891345e-01,  3.004097012228125e-02,  
 6.310711580799437e-01, -8.865377678376085e-01,  1.239250785539078e-02,  
 6.369188707330101e-01,  8.251358672704174e-01,  2.109369809774988e-02,  
 6.397822146063097e-01,  9.933516960588022e-01,  1.566823050510530e-03,  
 6.447025783419807e-01, -7.748327398433732e-01,  1.353919524034135e-02,  
 6.490923224989641e-01, -6.210654215758872e-01,  2.453036222700825e-02,  
 6.652852081461884e-01,  1.056429932263364e-01,  3.235059149781160e-02,  
 6.769243424161306e-01, -9.791782695964194e-01,  4.843329361124712e-03,  
 6.812487855144383e-01, -3.677376001017615e-01,  2.767580050018398e-02,  
 6.881611881783396e-01,  9.690785564088401e-01,  7.180152922776447e-03,  
 7.029917084563276e-01,  4.285118331295772e-01,  3.086990327791525e-02,  
 7.164764656784520e-01, -9.518583821949328e-01,  5.355105147941908e-03,  
 7.246902454799630e-01,  7.020207625777104e-01,  2.375449102290038e-02,  
 7.325693440295951e-01, -8.399374390925475e-01,  1.036024466955918e-02,  
 7.351112383538153e-01, -7.951756972515223e-02,  2.785001849780098e-02,  
 7.509928361696643e-01,  8.988638838541747e-01,  1.368741903606304e-02,  
 7.607007202364793e-01, -5.206337661298087e-01,  2.328103635760096e-02,  
 7.690593533802963e-01, -7.201514627550166e-01,  1.811779028755979e-02,  
 7.720233247908281e-01,  2.383646904389616e-01,  2.697895164503969e-02,  
 7.861129856968502e-01,  9.953733636825969e-01,  2.204660432176242e-03,  
 7.932635688940682e-01, -2.545931233040153e-01,  2.360509584832022e-02,  
 7.934795953540076e-01, -9.940911141191972e-01,  2.578022439771223e-03,  
 7.986501480724928e-01, -9.141670055638340e-01,  9.844477819414077e-03,  
 8.061029566945606e-01,  5.593366976508258e-01,  2.355691263970365e-02,  
 8.243070351881039e-01,  8.000279479141921e-01,  1.625476526376125e-02,  
 8.349061461503988e-01,  5.242989783303436e-02,  2.396763947561963e-02,  
 8.387086026393442e-01,  9.590800307491609e-01,  6.799333697297724e-03,  
 8.514060544957516e-01, -4.143618409619704e-01,  1.824968840166299e-02,  
 8.564000533604161e-01,  3.680409247826315e-01,  2.048685538595784e-02,  
 8.586490931530540e-01, -8.172679381074797e-01,  1.319146184667337e-02,  
 8.603733614050693e-01, -6.314782677843042e-01,  1.724870287833661e-02,  
 8.708025881828373e-01, -9.671023391671761e-01,  5.636725309105074e-03,  
 8.801258067547251e-01, -1.305377170691088e-01,  1.777128791266185e-02,  
 8.888526668725696e-01,  6.765021487498224e-01,  1.606206650402240e-02,  
 8.933099031235968e-01,  8.952281659692933e-01,  8.296408662073707e-03,  
 9.113602853210563e-01,  9.899169943701300e-01,  2.463722493435422e-03,  
 9.118722066757234e-01,  1.929776411231569e-01,  1.825776248523375e-02,  
 9.163929674501358e-01, -2.990041843102318e-01,  1.314634212775509e-02,  
 9.189017721547910e-01,  4.858317388925585e-01,  1.362028136343246e-02,  
 9.207066423332223e-01, -8.980672622897176e-01,  7.718082091266390e-03,  
 9.272785007117844e-01, -5.207581337916093e-01,  1.312690216075551e-02,  
 9.311020805101690e-01,  8.243210513505537e-01,  6.095543309002014e-03,  
 9.312327541844606e-01, -9.944089524999217e-01,  1.544072841043584e-03,  
 9.326765355471089e-01, -7.345782056816920e-01,  1.147121027748882e-02,  
 9.403087384697171e-01, -8.071436851387262e-03,  1.176918657324237e-02,  
 9.533497236250201e-01,  9.491647170059687e-01,  4.270793656586557e-03,  
 9.581432174025166e-01,  7.516220759263724e-01,  6.745942316173472e-03,  
 9.604046590298700e-01,  5.830153275767322e-01,  7.784720252720092e-03,  
 9.631077811144789e-01, -1.757985976531334e-01,  8.688657559223576e-03,  
 9.646721058936349e-01,  3.325578173839724e-01,  1.132962868101588e-02,  
 9.647811822781394e-01, -9.547975852433266e-01,  3.342959180531801e-03,  
 9.692409843048421e-01, -3.948453480534794e-01,  8.200365271055058e-03,  
 9.748844113653906e-01, -8.353669805015749e-01,  5.733917618965338e-03,  
 9.765605657096736e-01, -6.223778160859140e-01,  7.479750101379069e-03,  
 9.777781151583427e-01,  1.008331484661780e-01,  7.466802821144819e-03,  
 9.823248797734118e-01,  9.908257848386118e-01,  1.055477347697845e-03,  
 9.824013057546825e-01,  8.793077972340478e-01,  3.946153214787464e-03,  
 9.896592863949374e-01,  6.524183287421559e-01,  3.684068604731808e-03,  
 9.901852458780420e-01, -9.879591744269937e-01,  8.501750539953944e-04,  
 9.924040123666048e-01, -2.695088450767503e-01,  3.730991030920448e-03,  
 9.927679196128025e-01,  4.643954909265275e-01,  4.248272970481418e-03,  
 9.938098745051424e-01, -6.272470872855707e-02,  3.793703053258545e-03,  
 9.960268905980724e-01, -9.143875891227382e-01,  1.458149770534853e-03,  
 9.960772480893844e-01,  7.831338729008818e-01,  1.769564456969298e-03,  
 9.962805481813658e-01, -7.386272660484093e-01,  2.258142891171576e-03,  
 9.962980942352860e-01, -4.897161915618530e-01,  2.721379560273475e-03,  
 9.963851076303689e-01,  2.242470825907724e-01,  2.871929785587053e-03,  
 9.983360376701429e-01,  9.526320578956575e-01,  7.769150734629690e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr37 ( )

/******************************************************************************/
/*
  Purpose:

    SMR37 returns the SMR rule of degree 37.

  Discussion:
 
    DEGREE: 37
    ROTATIONALLY INVARIANT: (X,  Y),  (-Y,  X),  (-X, -Y),  (Y, -X).
    POINTS CARDINALITY: 245
    NORM INF MOMS. RESIDUAL: 1.97628e-15
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR37[3*245], the requested rule.
*/
{
  const int degree = 37;
  int order;
  double xw[3*245] = {
 1.688689515698905e-01,  1.899855310442196e-01,  1.879076889689011e-02,  
 1.664922672701527e-01,  3.429140133623845e-01,  3.449917667815708e-02,  
 1.789345703476781e-01,  5.923725055750423e-01,  3.712580251685875e-02,  
 1.912828097143278e-01,  8.047865391631479e-01,  2.804589806906416e-02,  
 1.909000554810340e-01,  9.526563151843329e-01,  1.317147780067464e-02,  
 1.197461382570857e-01,  9.934656721499447e-01,  3.246786042836229e-03,  
 3.142942982925143e-01,  1.085212763112808e-01,  4.073944662145704e-02,  
 3.136430658350363e-01,  3.168853969514266e-01,  1.888769495196758e-02,  
 3.257592735310023e-01,  4.744364447040339e-01,  3.338316795412049e-02,  
 3.370767611845376e-01,  7.018261748212855e-01,  3.160597567460757e-02,  
 3.228638369287264e-01,  8.961218476259737e-01,  1.882298564453669e-02,  
 3.240794429041066e-01,  9.907076643667728e-01,  5.242591968441962e-03,  
 4.573043899331568e-01,  2.595246348757670e-01,  3.729781542768577e-02,  
 4.752591359356870e-01,  4.488205755197494e-01,  1.479677650128667e-02,  
 4.758333073820230e-01,  5.902241348085835e-01,  2.899670157191689e-02,  
 5.652930131354381e-01,  7.267134552411152e-01,  2.191839430308059e-02,  
 4.508159401323132e-01,  8.204509229358563e-01,  2.228800060943608e-02,  
 4.475176031554735e-01,  9.598714005292409e-01,  1.115771006747028e-02,  
 5.961940658067776e-01,  1.285519929807882e-01,  3.745963783702447e-02,  
 5.958894993059283e-01,  4.008434952939153e-01,  3.161819475642853e-02,  
 6.758517622961954e-01,  5.420453939309517e-01,  1.197569541821857e-02,  
 6.440973695595638e-01,  6.074025740384232e-01,  1.687104351509356e-02,  
 6.599539606557937e-01,  8.196857529727558e-01,  1.433025041492978e-02,  
 5.662112657592980e-01,  9.051653639016278e-01,  1.517136608765207e-02,  
 6.604704311527990e-01,  9.545232264955925e-01,  5.954681784138311e-03,  
 5.550021925411663e-01,  9.938020253544084e-01,  3.779613188841330e-03,  
 7.175598471168050e-01,  2.730403569607258e-01,  3.181466382684873e-02,  
 7.689529149485085e-01,  4.849501945095196e-01,  2.205707035359098e-02,  
 7.225244519379806e-01,  7.346670194240615e-01,  8.555695820639366e-03,  
 7.402191126180568e-01,  8.767789551273115e-01,  1.086516778783751e-02,  
 6.901879840655373e-01,  9.774065816278240e-01,  4.413949586651726e-03,  
 8.145402907615753e-01,  1.194770600468978e-01,  2.773238005998524e-02,  
 8.468674880069054e-01,  3.677292203050513e-01,  2.040170735025986e-02,  
 7.709894430969280e-01,  6.883167579089596e-01,  1.537385690938401e-02,  
 8.412324448391584e-01,  8.049116063955287e-01,  1.469009646857076e-02,  
 8.046126375110838e-01,  9.350177341085882e-01,  8.737871041426535e-03,  
 7.820614187450875e-01,  9.953174665105079e-01,  2.315496884250784e-03,  
 9.508079160816079e-01,  1.063127388777120e-01,  1.140349599008745e-02,  
 9.083772470189286e-01,  2.392578185017081e-01,  1.649605664974265e-02,  
 8.623376059969516e-01,  6.074887398627125e-01,  1.799944191342780e-02,  
 9.049650989085555e-01,  8.906584714348453e-01,  8.885404075061408e-03,  
 9.414987804698027e-01,  9.972662607622250e-01,  1.012999506114864e-03,  
 8.784002089990299e-01,  9.767224278002355e-01,  4.609542770434277e-03,  
 9.277718380370786e-01,  4.868377946168942e-01,  1.482235294209374e-02,  
 9.740284280473888e-01,  6.153952571724473e-01,  8.444452079041077e-03,  
 9.261384032176685e-01,  7.279402581589705e-01,  1.230535711494119e-02,  
 9.679546133670914e-01,  8.320886256235162e-01,  6.228411019066719e-03,  
 9.563820929391198e-01,  9.496839487816863e-01,  4.116804695327055e-03,  
 9.926061411961665e-01,  2.123910718029504e-01,  4.298821847813497e-03,  
 9.709143978580982e-01,  3.514215085134095e-01,  9.842825211091850e-03,  
 9.964469722990946e-01,  4.826995164323201e-01,  3.063734063870583e-03,  
 9.948590950034147e-01,  7.363116181982159e-01,  2.686189437945335e-03,  
 9.924033492665334e-01,  8.341694790656329e-01,  4.583425786943879e-04,  
 9.936078762597962e-01,  9.109429166275763e-01,  1.832840176946247e-03,  
 9.897652124914369e-01,  9.843626854080677e-01,  1.073091219432144e-03,  
 3.032916166693916e-02,  1.723425646848686e-01,  3.655713458299797e-02,  
 2.217294601980654e-02,  4.663686154054668e-01,  4.027271183981319e-02,  
 2.814942665710626e-02,  7.102048981913600e-01,  3.373438958414005e-02,  
 4.438627067827642e-02,  8.900063168860698e-01,  2.195827523559744e-02,  
 6.744822333126831e-03,  9.762502292316360e-01,  5.490273279461521e-03,  
 -4.982446329191517e-02,  9.956312481563887e-01,  1.436535699659639e-03,  
 -1.899855310442196e-01,  1.688689515698905e-01,  1.879076889689011e-02,  
 -3.429140133623845e-01,  1.664922672701527e-01,  3.449917667815708e-02,  
 -5.923725055750423e-01,  1.789345703476781e-01,  3.712580251685875e-02,  
 -8.047865391631479e-01,  1.912828097143278e-01,  2.804589806906416e-02,  
 -9.526563151843329e-01,  1.909000554810340e-01,  1.317147780067464e-02,  
 -9.934656721499447e-01,  1.197461382570857e-01,  3.246786042836229e-03,  
 -1.085212763112808e-01,  3.142942982925143e-01,  4.073944662145704e-02,  
 -3.168853969514266e-01,  3.136430658350363e-01,  1.888769495196758e-02,  
 -4.744364447040339e-01,  3.257592735310023e-01,  3.338316795412049e-02,  
 -7.018261748212855e-01,  3.370767611845376e-01,  3.160597567460757e-02,  
 -8.961218476259737e-01,  3.228638369287264e-01,  1.882298564453669e-02,  
 -9.907076643667728e-01,  3.240794429041066e-01,  5.242591968441962e-03,  
 -2.595246348757670e-01,  4.573043899331568e-01,  3.729781542768577e-02,  
 -4.488205755197494e-01,  4.752591359356870e-01,  1.479677650128667e-02,  
 -5.902241348085835e-01,  4.758333073820230e-01,  2.899670157191689e-02,  
 -7.267134552411152e-01,  5.652930131354381e-01,  2.191839430308059e-02,  
 -8.204509229358563e-01,  4.508159401323132e-01,  2.228800060943608e-02,  
 -9.598714005292409e-01,  4.475176031554735e-01,  1.115771006747028e-02,  
 -1.285519929807882e-01,  5.961940658067776e-01,  3.745963783702447e-02,  
 -4.008434952939153e-01,  5.958894993059283e-01,  3.161819475642853e-02,  
 -5.420453939309517e-01,  6.758517622961954e-01,  1.197569541821857e-02,  
 -6.074025740384232e-01,  6.440973695595638e-01,  1.687104351509356e-02,  
 -8.196857529727558e-01,  6.599539606557937e-01,  1.433025041492978e-02,  
 -9.051653639016278e-01,  5.662112657592980e-01,  1.517136608765207e-02,  
 -9.545232264955925e-01,  6.604704311527990e-01,  5.954681784138311e-03,  
 -9.938020253544084e-01,  5.550021925411663e-01,  3.779613188841330e-03,  
 -2.730403569607258e-01,  7.175598471168050e-01,  3.181466382684873e-02,  
 -4.849501945095196e-01,  7.689529149485085e-01,  2.205707035359098e-02,  
 -7.346670194240615e-01,  7.225244519379806e-01,  8.555695820639366e-03,  
 -8.767789551273115e-01,  7.402191126180568e-01,  1.086516778783751e-02,  
 -9.774065816278240e-01,  6.901879840655373e-01,  4.413949586651726e-03,  
 -1.194770600468978e-01,  8.145402907615753e-01,  2.773238005998524e-02,  
 -3.677292203050513e-01,  8.468674880069054e-01,  2.040170735025986e-02,  
 -6.883167579089596e-01,  7.709894430969280e-01,  1.537385690938401e-02,  
 -8.049116063955287e-01,  8.412324448391584e-01,  1.469009646857076e-02,  
 -9.350177341085882e-01,  8.046126375110838e-01,  8.737871041426535e-03,  
 -9.953174665105079e-01,  7.820614187450875e-01,  2.315496884250784e-03,  
 -1.063127388777120e-01,  9.508079160816079e-01,  1.140349599008745e-02,  
 -2.392578185017081e-01,  9.083772470189286e-01,  1.649605664974265e-02,  
 -6.074887398627125e-01,  8.623376059969516e-01,  1.799944191342780e-02,  
 -8.906584714348453e-01,  9.049650989085555e-01,  8.885404075061408e-03,  
 -9.972662607622250e-01,  9.414987804698027e-01,  1.012999506114864e-03,  
 -9.767224278002355e-01,  8.784002089990299e-01,  4.609542770434277e-03,  
 -4.868377946168942e-01,  9.277718380370786e-01,  1.482235294209374e-02,  
 -6.153952571724473e-01,  9.740284280473888e-01,  8.444452079041077e-03,  
 -7.279402581589705e-01,  9.261384032176685e-01,  1.230535711494119e-02,  
 -8.320886256235162e-01,  9.679546133670914e-01,  6.228411019066719e-03,  
 -9.496839487816863e-01,  9.563820929391198e-01,  4.116804695327055e-03,  
 -2.123910718029504e-01,  9.926061411961665e-01,  4.298821847813497e-03,  
 -3.514215085134095e-01,  9.709143978580982e-01,  9.842825211091850e-03,  
 -4.826995164323201e-01,  9.964469722990946e-01,  3.063734063870583e-03,  
 -7.363116181982159e-01,  9.948590950034147e-01,  2.686189437945335e-03,  
 -8.341694790656329e-01,  9.924033492665334e-01,  4.583425786943879e-04,  
 -9.109429166275763e-01,  9.936078762597962e-01,  1.832840176946247e-03,  
 -9.843626854080677e-01,  9.897652124914369e-01,  1.073091219432144e-03,  
 -1.723425646848686e-01,  3.032916166693916e-02,  3.655713458299797e-02,  
 -4.663686154054668e-01,  2.217294601980654e-02,  4.027271183981319e-02,  
 -7.102048981913600e-01,  2.814942665710626e-02,  3.373438958414005e-02,  
 -8.900063168860698e-01,  4.438627067827642e-02,  2.195827523559744e-02,  
 -9.762502292316360e-01,  6.744822333126831e-03,  5.490273279461521e-03,  
 -9.956312481563887e-01, -4.982446329191517e-02,  1.436535699659639e-03,  
 -1.688689515698905e-01, -1.899855310442196e-01,  1.879076889689011e-02,  
 -1.664922672701527e-01, -3.429140133623845e-01,  3.449917667815708e-02,  
 -1.789345703476781e-01, -5.923725055750423e-01,  3.712580251685875e-02,  
 -1.912828097143278e-01, -8.047865391631479e-01,  2.804589806906416e-02,  
 -1.909000554810340e-01, -9.526563151843329e-01,  1.317147780067464e-02,  
 -1.197461382570857e-01, -9.934656721499447e-01,  3.246786042836229e-03,  
 -3.142942982925143e-01, -1.085212763112808e-01,  4.073944662145704e-02,  
 -3.136430658350363e-01, -3.168853969514266e-01,  1.888769495196758e-02,  
 -3.257592735310023e-01, -4.744364447040339e-01,  3.338316795412049e-02,  
 -3.370767611845376e-01, -7.018261748212855e-01,  3.160597567460757e-02,  
 -3.228638369287264e-01, -8.961218476259737e-01,  1.882298564453669e-02,  
 -3.240794429041066e-01, -9.907076643667728e-01,  5.242591968441962e-03,  
 -4.573043899331568e-01, -2.595246348757670e-01,  3.729781542768577e-02,  
 -4.752591359356870e-01, -4.488205755197494e-01,  1.479677650128667e-02,  
 -4.758333073820230e-01, -5.902241348085835e-01,  2.899670157191689e-02,  
 -5.652930131354381e-01, -7.267134552411152e-01,  2.191839430308059e-02,  
 -4.508159401323132e-01, -8.204509229358563e-01,  2.228800060943608e-02,  
 -4.475176031554735e-01, -9.598714005292409e-01,  1.115771006747028e-02,  
 -5.961940658067776e-01, -1.285519929807882e-01,  3.745963783702447e-02,  
 -5.958894993059283e-01, -4.008434952939153e-01,  3.161819475642853e-02,  
 -6.758517622961954e-01, -5.420453939309517e-01,  1.197569541821857e-02,  
 -6.440973695595638e-01, -6.074025740384232e-01,  1.687104351509356e-02,  
 -6.599539606557937e-01, -8.196857529727558e-01,  1.433025041492978e-02,  
 -5.662112657592980e-01, -9.051653639016278e-01,  1.517136608765207e-02,  
 -6.604704311527990e-01, -9.545232264955925e-01,  5.954681784138311e-03,  
 -5.550021925411663e-01, -9.938020253544084e-01,  3.779613188841330e-03,  
 -7.175598471168050e-01, -2.730403569607258e-01,  3.181466382684873e-02,  
 -7.689529149485085e-01, -4.849501945095196e-01,  2.205707035359098e-02,  
 -7.225244519379806e-01, -7.346670194240615e-01,  8.555695820639366e-03,  
 -7.402191126180568e-01, -8.767789551273115e-01,  1.086516778783751e-02,  
 -6.901879840655373e-01, -9.774065816278240e-01,  4.413949586651726e-03,  
 -8.145402907615753e-01, -1.194770600468978e-01,  2.773238005998524e-02,  
 -8.468674880069054e-01, -3.677292203050513e-01,  2.040170735025986e-02,  
 -7.709894430969280e-01, -6.883167579089596e-01,  1.537385690938401e-02,  
 -8.412324448391584e-01, -8.049116063955287e-01,  1.469009646857076e-02,  
 -8.046126375110838e-01, -9.350177341085882e-01,  8.737871041426535e-03,  
 -7.820614187450875e-01, -9.953174665105079e-01,  2.315496884250784e-03,  
 -9.508079160816079e-01, -1.063127388777120e-01,  1.140349599008745e-02,  
 -9.083772470189286e-01, -2.392578185017081e-01,  1.649605664974265e-02,  
 -8.623376059969516e-01, -6.074887398627125e-01,  1.799944191342780e-02,  
 -9.049650989085555e-01, -8.906584714348453e-01,  8.885404075061408e-03,  
 -9.414987804698027e-01, -9.972662607622250e-01,  1.012999506114864e-03,  
 -8.784002089990299e-01, -9.767224278002355e-01,  4.609542770434277e-03,  
 -9.277718380370786e-01, -4.868377946168942e-01,  1.482235294209374e-02,  
 -9.740284280473888e-01, -6.153952571724473e-01,  8.444452079041077e-03,  
 -9.261384032176685e-01, -7.279402581589705e-01,  1.230535711494119e-02,  
 -9.679546133670914e-01, -8.320886256235162e-01,  6.228411019066719e-03,  
 -9.563820929391198e-01, -9.496839487816863e-01,  4.116804695327055e-03,  
 -9.926061411961665e-01, -2.123910718029504e-01,  4.298821847813497e-03,  
 -9.709143978580982e-01, -3.514215085134095e-01,  9.842825211091850e-03,  
 -9.964469722990946e-01, -4.826995164323201e-01,  3.063734063870583e-03,  
 -9.948590950034147e-01, -7.363116181982159e-01,  2.686189437945335e-03,  
 -9.924033492665334e-01, -8.341694790656329e-01,  4.583425786943879e-04,  
 -9.936078762597962e-01, -9.109429166275763e-01,  1.832840176946247e-03,  
 -9.897652124914369e-01, -9.843626854080677e-01,  1.073091219432144e-03,  
 -3.032916166693916e-02, -1.723425646848686e-01,  3.655713458299797e-02,  
 -2.217294601980654e-02, -4.663686154054668e-01,  4.027271183981319e-02,  
 -2.814942665710626e-02, -7.102048981913600e-01,  3.373438958414005e-02,  
 -4.438627067827642e-02, -8.900063168860698e-01,  2.195827523559744e-02,  
 -6.744822333126831e-03, -9.762502292316360e-01,  5.490273279461521e-03,  
 4.982446329191517e-02, -9.956312481563887e-01,  1.436535699659639e-03,  
 1.899855310442196e-01, -1.688689515698905e-01,  1.879076889689011e-02,  
 3.429140133623845e-01, -1.664922672701527e-01,  3.449917667815708e-02,  
 5.923725055750423e-01, -1.789345703476781e-01,  3.712580251685875e-02,  
 8.047865391631479e-01, -1.912828097143278e-01,  2.804589806906416e-02,  
 9.526563151843329e-01, -1.909000554810340e-01,  1.317147780067464e-02,  
 9.934656721499447e-01, -1.197461382570857e-01,  3.246786042836229e-03,  
 1.085212763112808e-01, -3.142942982925143e-01,  4.073944662145704e-02,  
 3.168853969514266e-01, -3.136430658350363e-01,  1.888769495196758e-02,  
 4.744364447040339e-01, -3.257592735310023e-01,  3.338316795412049e-02,  
 7.018261748212855e-01, -3.370767611845376e-01,  3.160597567460757e-02,  
 8.961218476259737e-01, -3.228638369287264e-01,  1.882298564453669e-02,  
 9.907076643667728e-01, -3.240794429041066e-01,  5.242591968441962e-03,  
 2.595246348757670e-01, -4.573043899331568e-01,  3.729781542768577e-02,  
 4.488205755197494e-01, -4.752591359356870e-01,  1.479677650128667e-02,  
 5.902241348085835e-01, -4.758333073820230e-01,  2.899670157191689e-02,  
 7.267134552411152e-01, -5.652930131354381e-01,  2.191839430308059e-02,  
 8.204509229358563e-01, -4.508159401323132e-01,  2.228800060943608e-02,  
 9.598714005292409e-01, -4.475176031554735e-01,  1.115771006747028e-02,  
 1.285519929807882e-01, -5.961940658067776e-01,  3.745963783702447e-02,  
 4.008434952939153e-01, -5.958894993059283e-01,  3.161819475642853e-02,  
 5.420453939309517e-01, -6.758517622961954e-01,  1.197569541821857e-02,  
 6.074025740384232e-01, -6.440973695595638e-01,  1.687104351509356e-02,  
 8.196857529727558e-01, -6.599539606557937e-01,  1.433025041492978e-02,  
 9.051653639016278e-01, -5.662112657592980e-01,  1.517136608765207e-02,  
 9.545232264955925e-01, -6.604704311527990e-01,  5.954681784138311e-03,  
 9.938020253544084e-01, -5.550021925411663e-01,  3.779613188841330e-03,  
 2.730403569607258e-01, -7.175598471168050e-01,  3.181466382684873e-02,  
 4.849501945095196e-01, -7.689529149485085e-01,  2.205707035359098e-02,  
 7.346670194240615e-01, -7.225244519379806e-01,  8.555695820639366e-03,  
 8.767789551273115e-01, -7.402191126180568e-01,  1.086516778783751e-02,  
 9.774065816278240e-01, -6.901879840655373e-01,  4.413949586651726e-03,  
 1.194770600468978e-01, -8.145402907615753e-01,  2.773238005998524e-02,  
 3.677292203050513e-01, -8.468674880069054e-01,  2.040170735025986e-02,  
 6.883167579089596e-01, -7.709894430969280e-01,  1.537385690938401e-02,  
 8.049116063955287e-01, -8.412324448391584e-01,  1.469009646857076e-02,  
 9.350177341085882e-01, -8.046126375110838e-01,  8.737871041426535e-03,  
 9.953174665105079e-01, -7.820614187450875e-01,  2.315496884250784e-03,  
 1.063127388777120e-01, -9.508079160816079e-01,  1.140349599008745e-02,  
 2.392578185017081e-01, -9.083772470189286e-01,  1.649605664974265e-02,  
 6.074887398627125e-01, -8.623376059969516e-01,  1.799944191342780e-02,  
 8.906584714348453e-01, -9.049650989085555e-01,  8.885404075061408e-03,  
 9.972662607622250e-01, -9.414987804698027e-01,  1.012999506114864e-03,  
 9.767224278002355e-01, -8.784002089990299e-01,  4.609542770434277e-03,  
 4.868377946168942e-01, -9.277718380370786e-01,  1.482235294209374e-02,  
 6.153952571724473e-01, -9.740284280473888e-01,  8.444452079041077e-03,  
 7.279402581589705e-01, -9.261384032176685e-01,  1.230535711494119e-02,  
 8.320886256235162e-01, -9.679546133670914e-01,  6.228411019066719e-03,  
 9.496839487816863e-01, -9.563820929391198e-01,  4.116804695327055e-03,  
 2.123910718029504e-01, -9.926061411961665e-01,  4.298821847813497e-03,  
 3.514215085134095e-01, -9.709143978580982e-01,  9.842825211091850e-03,  
 4.826995164323201e-01, -9.964469722990946e-01,  3.063734063870583e-03,  
 7.363116181982159e-01, -9.948590950034147e-01,  2.686189437945335e-03,  
 8.341694790656329e-01, -9.924033492665334e-01,  4.583425786943879e-04,  
 9.109429166275763e-01, -9.936078762597962e-01,  1.832840176946247e-03,  
 9.843626854080677e-01, -9.897652124914369e-01,  1.073091219432144e-03,  
 1.723425646848686e-01, -3.032916166693916e-02,  3.655713458299797e-02,  
 4.663686154054668e-01, -2.217294601980654e-02,  4.027271183981319e-02,  
 7.102048981913600e-01, -2.814942665710626e-02,  3.373438958414005e-02,  
 8.900063168860698e-01, -4.438627067827642e-02,  2.195827523559744e-02,  
 9.762502292316360e-01, -6.744822333126831e-03,  5.490273279461521e-03,  
 9.956312481563887e-01,  4.982446329191517e-02,  1.436535699659639e-03,  
 0.000000000000000e+00,  0.000000000000000e+00,  2.733962437974891e-02 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr38 ( )

/******************************************************************************/
/*
  Purpose:

    SMR38 returns the SMR rule of degree 38.

  Discussion:
 
    DEGREE: 38
    POINTS CARDINALITY: 265
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR38[3*265], the requested rule.
*/
{
  const int degree = 38;
  int order;
  double xw[3*265] = {
 -9.986728061698944e-01,  7.022053437776367e-01,  1.480107210669759e-03,  
 -9.982717636746820e-01, -9.054654092610701e-01,  1.075250999194606e-03,  
 -9.967818426696908e-01,  2.010254208991262e-01,  2.641794509284354e-03,  
 -9.961752169855568e-01, -4.510641362412657e-01,  2.262884166375447e-03,  
 -9.956850333584866e-01, -2.104763459288764e-01,  2.878520269955461e-03,  
 -9.954228554916262e-01, -6.464904618069326e-01,  2.018600540825626e-03,  
 -9.952874532053829e-01,  4.651922890152825e-01,  2.686536492992849e-03,  
 -9.948147421400011e-01,  8.983435291372217e-01,  1.575355209064770e-03,  
 -9.944162554551003e-01,  9.804886839517453e-01,  7.123537841476463e-04,  
 -9.941508164951945e-01, -9.924193701187594e-01,  4.124555173483122e-04,  
 -9.895909168262721e-01, -7.760059158658976e-01,  3.335123807315742e-03,  
 -9.884130043110948e-01, -6.828120541211876e-03,  5.966363865455931e-03,  
 -9.825019022108045e-01,  8.025512121835557e-01,  4.473439125255699e-03,  
 -9.808025717173898e-01,  5.928703642747596e-01,  5.654233758485060e-03,  
 -9.789202260574441e-01, -9.600751096501493e-01,  2.400023758037121e-03,  
 -9.780946430895284e-01,  3.312033086392446e-01,  7.232443622428314e-03,  
 -9.768400253233941e-01, -3.363809641049628e-01,  6.810652491435815e-03,  
 -9.766127586199059e-01, -5.507973729936958e-01,  5.502878410512012e-03,  
 -9.709970420576878e-01,  9.982493459462520e-01,  5.220890807668551e-04,  
 -9.699274049351875e-01,  9.472087194394833e-01,  3.027446723606712e-03,  
 -9.687234644693394e-01, -8.597252944572178e-01,  4.921184172578546e-03,  
 -9.579599016628263e-01,  1.346951753939543e-01,  1.158893898492868e-02,  
 -9.565118929757315e-01, -1.489920158469925e-01,  1.130253568365422e-02,  
 -9.553009304164504e-01, -6.804355607895213e-01,  8.027637882625688e-03,  
 -9.511658622347594e-01,  6.971063358211608e-01,  8.324574726565883e-03,  
 -9.437446561733596e-01,  4.732467184275191e-01,  1.096804727700399e-02,  
 -9.430645590398508e-01,  8.721609246940591e-01,  6.497332370837135e-03,  
 -9.424278783556489e-01, -9.922571454686503e-01,  1.636770445566413e-03,  
 -9.398691006571868e-01, -4.560244625614296e-01,  8.895278250957981e-03,  
 -9.292771715176156e-01, -9.225625756492970e-01,  5.669237451343602e-03,  
 -9.249858311739745e-01,  9.811603990754799e-01,  2.809384277239985e-03,  
 -9.180677638423977e-01, -7.800607674872433e-01,  9.623850741009066e-03,  
 -9.177060680740887e-01, -3.177972997817269e-01,  1.019917034278841e-02,  
 -9.174754746776520e-01,  3.041897807994299e-01,  1.201129866345285e-02,  
 -9.079474620384712e-01, -1.522732468440084e-02,  1.645827217241348e-02,  
 -8.989880442284409e-01, -5.721449662059714e-01,  1.288528291339345e-02,  
 -8.981089387121135e-01,  7.784183494868725e-01,  1.067299862517563e-02,  
 -8.932346929455569e-01,  5.887798321389541e-01,  1.418723684484729e-02,  
 -8.844628907549286e-01,  9.298461890098859e-01,  6.826913613669788e-03,  
 -8.785753240387332e-01,  1.874264068388238e-01,  1.280230079204341e-02,  
 -8.769155610558782e-01, -9.702794097426992e-01,  4.732604136822726e-03,  
 -8.745143973474696e-01, -2.287312677692649e-01,  1.419838785220286e-02,  
 -8.616355979293774e-01, -8.599524645119671e-01,  1.033767954867920e-02,  
 -8.543820371352494e-01,  9.950509885730230e-01,  1.586566768400716e-03,  
 -8.524166456930568e-01,  4.012946300633538e-01,  1.310477717253685e-02,  
 -8.456839492120051e-01, -6.831067002350120e-01,  1.516421735877612e-02,  
 -8.383382188368550e-01, -4.319298337860406e-01,  1.921462523307014e-02,  
 -8.264198166719673e-01,  8.543820715032787e-01,  1.170776794008535e-02,  
 -8.238644456887115e-01,  4.631329546631612e-01,  1.038537538791454e-02,  
 -8.223392361684277e-01,  6.288554440206344e-02,  1.667203720394711e-02,  
 -8.211280022738077e-01,  6.855811948721302e-01,  1.601478444956828e-02,  
 -8.199277985385334e-01, -9.968372670905445e-01,  1.661577894515087e-03,  
 -8.129329692738561e-01, -1.273992868913358e-01,  1.875947652746525e-02,  
 -8.011794106051470e-01,  9.669501083215283e-01,  5.767768497940699e-03,  
 -7.929367673515950e-01, -9.266258905147980e-01,  9.411444971101739e-03,  
 -7.900564493377547e-01,  2.381148763558590e-01,  1.647531191140429e-02,  
 -7.731467279987423e-01, -7.797397671681381e-01,  1.601496823099040e-02,  
 -7.623964593130932e-01, -5.501193940493972e-01,  1.159218418929015e-02,  
 -7.584255224981719e-01, -3.184791336183493e-01,  2.091892442653742e-02,  
 -7.519475217388361e-01, -5.791824818686737e-01,  1.205989910558337e-02,  
 -7.479661500312423e-01,  5.530676731141679e-01,  2.158851143401081e-02,  
 -7.352203999162555e-01,  7.734652586603286e-01,  1.630985619573579e-02,  
 -7.301302673120450e-01,  9.132724657488548e-01,  1.112141678436374e-02,  
 -7.256956958727250e-01,  3.329739597626992e-01,  2.022428576496201e-02,  
 -7.239178205154017e-01, -9.768043840489384e-01,  5.995264547827235e-03,  
 -7.144660932162712e-01,  9.939502544860596e-01,  2.623316720141714e-03,  
 -7.134918721775755e-01, -8.299044913428447e-02,  1.940442510934155e-02,  
 -7.119027324460611e-01,  8.578636631641405e-02,  2.131075003508226e-02,  
 -6.885657387083151e-01, -8.646581939789911e-01,  1.508744259539114e-02,  
 -6.815796916450431e-01, -2.520940863406625e-01,  1.530753004805380e-02,  
 -6.642578820959111e-01, -6.852634338827157e-01,  2.278049969875701e-02,  
 -6.473518575748209e-01,  6.592583222880233e-01,  2.271475467380947e-02,  
 -6.437258851335323e-01, -4.477173879758088e-01,  2.975639615479566e-02,  
 -6.355112635497605e-01,  4.378956512417215e-01,  2.521762558761123e-02,  
 -6.325124605614381e-01,  8.407501306388737e-01,  1.460590022059716e-02,  
 -6.315677583266991e-01,  9.662034393812413e-01,  7.808742737505493e-03,  
 -6.196042474875053e-01, -9.963363069708174e-01,  2.238568005909896e-03,  
 -6.140032205110788e-01,  2.010897045841556e-01,  2.855123742414878e-02,  
 -6.129576438043784e-01, -9.390322728980965e-01,  1.034926062595989e-02,  
 -5.875439691207275e-01, -2.193439986467143e-02,  2.499512527874338e-02,  
 -5.799105261064157e-01, -2.023065726805473e-01,  2.524717784018200e-02,  
 -5.639961982962394e-01, -7.885570098234548e-01,  2.129350870359041e-02,  
 -5.596787042093025e-01,  9.043275540829417e-01,  9.506472361159410e-03,  
 -5.352404064125716e-01, -5.820386013748505e-01,  2.975207132885310e-02,  
 -5.296093245457807e-01,  7.468713682804629e-01,  2.126630472576444e-02,  
 -5.287674931826091e-01,  5.463207389216995e-01,  2.634684268285789e-02,  
 -5.219567374887893e-01,  9.934029903982332e-01,  3.621614418679607e-03,  
 -5.149216590929167e-01, -9.004320190387479e-01,  7.688847109621289e-03,  
 -5.011828192721633e-01,  3.227765374618168e-01,  3.053941514246194e-02,  
 -4.984369209637762e-01, -9.785989702329311e-01,  6.782679629517108e-03,  
 -4.936061758540524e-01, -3.486445503736601e-01,  3.330194686505883e-02,  
 -4.708043838891184e-01,  9.397512604542692e-01,  9.223376930093745e-03,  
 -4.700530607377321e-01,  9.067704013502087e-02,  3.194924782643185e-02,  
 -4.421006521894345e-01, -8.668776943903029e-01,  1.365222130557064e-02,  
 -4.322459166260278e-01,  8.364964883317925e-01,  1.748429055313385e-02,  
 -4.274779754835013e-01, -1.078954532368429e-01,  3.224879248144154e-02,  
 -4.198312559908789e-01, -7.021715466719177e-01,  2.768892576177184e-02,  
 -4.084458907612225e-01,  6.401570118208092e-01,  2.499005578311043e-02,  
 -3.854852212643881e-01,  4.349492407425390e-01,  2.817381856722252e-02,  
 -3.774830229936222e-01, -4.844006263231227e-01,  3.385700109477467e-02,  
 -3.733125787412826e-01, -9.970755357985500e-01,  2.170942883821916e-03,  
 -3.727797012921453e-01,  9.754151248075028e-01,  7.281188512200446e-03,  
 -3.688270887346273e-01, -9.468451854156112e-01,  1.073492503946515e-02,  
 -3.400601966223295e-01,  2.175481788735125e-01,  3.596233825588648e-02,  
 -3.309577504370512e-01, -2.409725722453500e-01,  3.299006641898251e-02,  
 -3.139120548586594e-01,  8.944387687131167e-01,  1.499808244204078e-02,  
 -3.077283461062756e-01,  7.430289388062856e-01,  2.298506594699816e-02,  
 -3.068704930295912e-01, -8.068905304677897e-01,  2.173679496778064e-02,  
 -2.858215339736228e-01,  9.963809140996434e-01,  2.123402062955704e-03,  
 -2.752650785602830e-01,  5.229667081821272e-01,  2.373528701602919e-02,  
 -2.741878663975621e-01,  1.806172412531546e-02,  3.809014012672781e-02,  
 -2.567719567007165e-01, -6.119240851225661e-01,  3.194011296016801e-02,  
 -2.486412305697790e-01, -9.068815421904441e-01,  1.217810020482826e-02,  
 -2.449174300564486e-01, -9.850991839405564e-01,  4.904448003786544e-03,  
 -2.187168991298080e-01, -3.684600845707849e-01,  3.494313486419826e-02,  
 -2.033117249838243e-01,  9.468738387846685e-01,  1.197619385623436e-02,  
 -2.010080284425486e-01,  3.460129359512604e-01,  3.625695619354579e-02,  
 -1.826355317918911e-01,  6.262632974300691e-01,  2.662590215392095e-02,  
 -1.790215484342411e-01,  8.175236068900705e-01,  2.125277683247088e-02,  
 -1.620973947089955e-01, -1.254151736109939e-01,  3.616346313257308e-02,  
 -1.539052421137992e-01, -7.363057881237680e-01,  2.507618881866903e-02,  
 -1.509748710751692e-01, -9.644785457571827e-01,  7.018739561734089e-03,  
 -1.493613992998394e-01,  9.916687319806494e-01,  3.018026062389521e-03,  
 -1.222783616692547e-01,  1.555419729513029e-01,  3.996865738603259e-02,  
 -1.217834179658884e-01, -8.665867966847536e-01,  1.614918555107364e-02,  
 -9.954568034561521e-02, -4.983049956809532e-01,  3.480237785300572e-02,  
 -6.355783962147189e-02,  4.834454631547017e-01,  3.435231211682938e-02,  
 -5.980328238804704e-02, -9.959405331674103e-01,  3.043977853817699e-03,  
 -5.539568797194713e-02,  8.900885330680616e-01,  1.816753046217396e-02,  
 -5.044959347909641e-02,  7.147609138031071e-01,  2.708098053621957e-02,  
 -4.957845184210880e-02, -2.517606346179521e-01,  3.400381338647362e-02,  
 -3.882145970770993e-02,  9.753666286618804e-01,  7.353902601259136e-03,  
 -1.876732002789969e-02, -9.356601897044989e-01,  1.223556469983839e-02,  
 -1.249886771851880e-02, -6.467617699294321e-01,  2.729244897787926e-02,  
 -2.013003655499770e-03,  6.804392691959212e-03,  3.855008975037510e-02,  
 1.402682997558021e-02,  3.138839948744481e-01,  3.388937184270214e-02,  
 1.858848688086966e-02, -8.036198891624267e-01,  2.153717804647764e-02,  
 6.003092973120553e-02, -3.753272041106706e-01,  3.397898340796751e-02,  
 7.672497416901625e-02,  5.912600487498983e-01,  3.121782785742061e-02,  
 8.150239020231834e-02,  8.067824202268138e-01,  2.407531651957368e-02,  
 8.668589264981116e-02,  9.969497157386084e-01,  2.701504620609339e-03,  
 9.231571720996709e-02, -9.780482238991313e-01,  7.785551665765360e-03,  
 9.737323505829255e-02,  9.384929736173514e-01,  1.338210888613317e-02,  
 1.128012445661176e-01,  1.896414997815953e-01,  3.128705789253182e-02,  
 1.143511803097085e-01, -1.243491400435504e-01,  3.392864370862653e-02,  
 1.176787443821946e-01, -5.474612454684378e-01,  2.746213627764317e-02,  
 1.268891351439016e-01, -8.839456725175053e-01,  1.672616556795388e-02,  
 1.631426909205751e-01, -7.177106221484078e-01,  2.625147736220446e-02,  
 1.758741383852967e-01,  4.265421432395542e-01,  3.797964446958128e-02,  
 2.006154550504023e-01,  6.951418864446643e-01,  2.545733408956723e-02,  
 2.152860030071384e-01, -2.422132475961240e-01,  3.100597045992737e-02,  
 2.185770634825280e-01,  6.907417504035727e-02,  3.492638326125608e-02,  
 2.236246288520670e-01, -9.963809891717132e-01,  2.645997507264436e-03,  
 2.288887051657028e-01,  8.754003178432914e-01,  1.912737808424751e-02,  
 2.333826052338914e-01,  9.779009358962610e-01,  8.217956207171995e-03,  
 2.396650307918395e-01, -9.403475642021211e-01,  1.212182944813937e-02,  
 2.400346653041813e-01, -4.372367795710141e-01,  2.750818762763818e-02,  
 2.748295966460754e-01, -8.146962266181857e-01,  2.119754629186746e-02,  
 2.987201821315680e-01, -6.058548502859488e-01,  2.839877337228632e-02,  
 3.045773430811280e-01,  2.755917979498074e-01,  3.925796207971420e-02,  
 3.076075819952085e-01,  5.616633852300046e-01,  3.047990578805131e-02,  
 3.287712171984706e-01,  7.700477537553330e-01,  2.209664204066767e-02,  
 3.353060396411924e-01, -6.713224338700050e-02,  3.731512968063742e-02,  
 3.590192167691809e-01, -3.124154796685937e-01,  2.690461091828352e-02,  
 3.599858348938447e-01, -9.772275522212224e-01,  7.322166085339412e-03,  
 3.633366721464262e-01,  9.346084117544282e-01,  1.354702461771435e-02,  
 3.764020834512444e-01,  9.961755944581749e-01,  2.780135787415783e-03,  
 3.890228459314153e-01, -8.890435602042946e-01,  1.607523732193323e-02,  
 4.027914291932886e-01, -7.160255035244310e-01,  2.387070910106874e-02,  
 4.097421894946350e-01,  4.452381475461492e-01,  2.464804897575283e-02,  
 4.229178797439392e-01, -4.701825939351019e-01,  2.729336096379032e-02,  
 4.340848616284464e-01,  1.248473223854657e-01,  3.829435373976316e-02,  
 4.470213771246104e-01,  8.458186314958444e-01,  1.848706583481758e-02,  
 4.529246621415263e-01,  6.588844784476522e-01,  2.807897061918352e-02,  
 4.691823411918916e-01, -1.894802637910654e-01,  3.053879012802178e-02,  
 4.783450123946249e-01, -9.966085192019259e-01,  2.372775192102795e-03,  
 4.895259810138424e-01,  3.534144616221834e-01,  2.351128491079622e-02,  
 4.959734262824529e-01,  9.740444635499416e-01,  7.710763334339463e-03,  
 5.035757619767235e-01, -9.439613658930373e-01,  1.096738800807791e-02,  
 5.065601845768776e-01, -5.790286708924139e-01,  2.135179779707459e-02,  
 5.085183945179361e-01, -8.074877657027639e-01,  1.929376564778246e-02,  
 5.522864200597388e-01, -2.345289122385255e-02,  3.173415604312580e-02,  
 5.570494428224395e-01,  9.133422840649569e-01,  1.040230474694315e-02,  
 5.592614360711528e-01, -3.522697411422632e-01,  3.062865653271522e-02,  
 5.701115871183835e-01,  5.306977130285789e-01,  2.961992797000797e-02,  
 5.715387605890363e-01,  7.590559568198023e-01,  2.163444564883412e-02,  
 5.835624398896593e-01, -6.686734742923499e-01,  1.834802018964697e-02,  
 5.852476417677183e-01,  2.370919609747132e-01,  3.031865232259109e-02,  
 6.022583849974138e-01,  8.935147959329210e-01,  4.687076326332230e-03,  
 6.126343242580223e-01,  9.948806624831008e-01,  2.738111925376468e-03,  
 6.130380835098971e-01, -9.809871456541636e-01,  6.008330808378468e-03,  
 6.137772669975574e-01, -8.823362281279877e-01,  1.455389914650117e-02,  
 6.503113146309555e-01, -4.923990275537434e-01,  2.548798440031706e-02,  
 6.557363354466152e-01, -1.827492834052264e-01,  2.943913000621533e-02,  
 6.632308515099845e-01, -7.513836134228538e-01,  1.603729849717827e-02,  
 6.733087762907948e-01,  7.458312789499499e-02,  2.620926808459537e-02,  
 6.777745043586945e-01,  6.498008245436880e-01,  2.305772728455377e-02,  
 6.801215770962631e-01,  9.582506362246405e-01,  8.570728995577852e-03,  
 6.812691836007740e-01,  3.950396235783185e-01,  2.866215400698846e-02,  
 6.845867333636126e-01,  8.369868628766669e-01,  1.511423850063031e-02,  
 7.142144737185003e-01, -9.401517749959084e-01,  9.679186610760252e-03,  
 7.273928279094639e-01, -9.968690745004373e-01,  1.839049038220150e-03,  
 7.351794320872288e-01, -3.295931784311009e-01,  2.303520052753472e-02,  
 7.366016686661473e-01, -6.141664794256717e-01,  2.025486074750510e-02,  
 7.410876578755918e-01, -8.243736678762867e-01,  1.265159478674391e-02,  
 7.551110132205514e-01,  2.093562914164269e-01,  2.349869126796357e-02,  
 7.702496257050028e-01, -6.565803371865064e-02,  2.585856694796258e-02,  
 7.725680221187270e-01,  9.904023414650684e-01,  3.400468248188160e-03,  
 7.738393121081201e-01,  5.296366886950493e-01,  2.210916654329989e-02,  
 7.749611837963317e-01,  9.058131786659659e-01,  1.041506168806316e-02,  
 7.760702944135377e-01,  7.489596799092613e-01,  1.652307042159280e-02,  
 8.027353439778935e-01, -4.573336361960537e-01,  1.831340868862391e-02,  
 8.124305771363060e-01, -9.759706592062355e-01,  5.062161724834427e-03,  
 8.147149488148366e-01, -8.861421984181819e-01,  9.631215601485367e-03,  
 8.163753750967859e-01, -7.177004379126865e-01,  1.541261476754118e-02,  
 8.258640864298581e-01,  3.417271576604571e-01,  1.986204459592654e-02,  
 8.385288085877484e-01, -2.304198329903687e-01,  2.068650913588178e-02,  
 8.480262557901783e-01,  9.584500401922721e-01,  5.818073292341461e-03,  
 8.499406855634883e-01,  8.311541485724494e-02,  2.138582032495064e-02,  
 8.542395824011385e-01,  6.470836810764854e-01,  1.548189977556605e-02,  
 8.551735349936741e-01,  8.361408239071259e-01,  1.113210052356122e-02,  
 8.682126765591526e-01, -5.724226374325766e-01,  1.512163401783132e-02,  
 8.862702936910032e-01, -8.045997586076709e-01,  1.081270580739009e-02,  
 8.864333814317719e-01, -9.343418320939790e-01,  6.185112577237470e-03,  
 8.887165787912253e-01,  4.737933027545716e-01,  1.532406329926187e-02,  
 8.909110194387325e-01, -9.952080704120854e-01,  1.557095545851028e-03,  
 8.969514630808822e-01,  9.930243801730180e-01,  1.899826340411995e-03,  
 8.975959754390993e-01, -3.806019598663427e-01,  1.487375295518117e-02,  
 9.030468245555767e-01, -9.390288889102749e-02,  1.549257621043731e-02,  
 9.085939371709327e-01,  2.350241676754213e-01,  1.558218899145559e-02,  
 9.140361598405574e-01,  9.095155793512008e-01,  6.544935838415903e-03,  
 9.171230192628999e-01,  7.511379775519837e-01,  1.001948867534600e-02,  
 9.268871231165261e-01, -6.775251262894855e-01,  1.088618566292480e-02,  
 9.416935102978777e-01,  6.013078832211158e-01,  1.017124306808582e-02,  
 9.433556271573456e-01, -8.749994999185291e-01,  6.277143297506312e-03,  
 9.434325703715991e-01,  3.225727122372022e-02,  9.237465593827822e-03,  
 9.437308091058394e-01, -9.711971052517493e-01,  3.026949149785576e-03,  
 9.439963213838909e-01, -2.608317409688558e-01,  9.360240633006462e-03,  
 9.484876843189004e-01, -5.004997732310644e-01,  1.009870421315387e-02,  
 9.499243743977762e-01,  3.801906587509148e-01,  9.818422202948377e-03,  
 9.514871432590463e-01,  9.671631794962331e-01,  3.146221524837508e-03,  
 9.609489550655589e-01,  8.428332536315430e-01,  5.730637488550284e-03,  
 9.662829103996791e-01,  1.468518597297787e-01,  7.207542405549267e-03,  
 9.696872558843541e-01, -1.605437913785572e-01,  5.981560914072205e-03,  
 9.702856060632504e-01, -7.717575893450904e-01,  5.993654542760810e-03,  
 9.760573100533793e-01,  9.966116994495912e-01,  5.808298238542816e-04,  
 9.778854166720647e-01, -9.945815670139703e-01,  7.405440773791397e-04,  
 9.789726619300820e-01,  7.196402966212632e-01,  5.322542886910651e-03,  
 9.792756889708635e-01,  5.073451727037140e-01,  5.506244507295100e-03,  
 9.811303210024424e-01, -6.060022042631865e-01,  5.278083219704399e-03,  
 9.821031078208879e-01, -3.681824090938130e-01,  6.200855551112159e-03,  
 9.823346110259005e-01, -9.302538972721487e-01,  2.710453922448771e-03,  
 9.862095221362329e-01,  2.895216427234739e-01,  5.194439945195447e-03,  
 9.864268580437249e-01,  9.195586194143690e-01,  2.646059688376799e-03,  
 9.880369774377964e-01, -3.549566919434279e-02,  5.082042661181035e-03,  
 9.945896034737212e-01, -8.501279475990717e-01,  1.873959291274505e-03,  
 9.954239677428349e-01,  6.245266829365560e-01,  2.088928242308500e-03,  
 9.961170766979618e-01,  9.777701767940108e-01,  6.025320119282685e-04,  
 9.966190752080943e-01, -7.030873365364748e-01,  1.672495855073975e-03,  
 9.973338514057413e-01, -4.871402038403967e-01,  1.840226666996993e-03,  
 9.975779076043548e-01, -2.229904598382893e-01,  2.112563470049513e-03,  
 9.976658933368316e-01,  1.309914613948673e-01,  1.954166630091224e-03,  
 9.977174090396262e-01,  8.188675476038971e-01,  1.472509815415101e-03,  
 9.983759366126691e-01, -9.751850545004921e-01,  4.748950672235257e-04,  
 9.984440204501318e-01,  4.288187400230707e-01,  1.459369339895693e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr39 ( )

/******************************************************************************/
/*
  Purpose:

    SMR39 returns the SMR rule of degree 39.

  Discussion:
 
    DEGREE: 39
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 274
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR39[3*274], the requested rule.
*/
{
  const int degree = 39;
  int order;
  double xw[3*274] = {
 -9.983507138390728e-01,  2.846923651716276e-02,  1.946248040917511e-03,  
 -9.974803510397799e-01,  5.723617700464594e-01,  1.730177315995435e-03,  
 -9.970436400762405e-01,  8.380584517844631e-01,  1.474635255954523e-03,  
 -9.966780331371223e-01,  9.694002319896394e-01,  7.243867200693780e-04,  
 -9.966744182696170e-01, -5.085108565093430e-01,  1.980803681920541e-03,  
 -9.958948247928820e-01,  3.162381906315679e-01,  2.750378228739487e-03,  
 -9.957989442071229e-01, -2.946071658312556e-01,  2.310642786475657e-03,  
 -9.951431493831727e-01, -9.317895250779106e-01,  1.311747532188187e-03,  
 -9.947425612275775e-01, -6.937725695763057e-01,  2.327244406193416e-03,  
 -9.946606993258253e-01, -9.946657556011911e-01,  3.187304244494703e-04,  
 -9.891970457464104e-01, -8.249338141061554e-01,  3.217331206511223e-03,  
 -9.882776096714541e-01,  6.996008607192892e-01,  3.762641387033618e-03,  
 -9.863969994171303e-01, -1.393885680294662e-01,  5.467653298722175e-03,  
 -9.815404512250665e-01,  1.578509309909750e-01,  6.740930954579635e-03,  
 -9.808343955917264e-01,  9.119881406240292e-01,  3.204352632730979e-03,  
 -9.801636812194632e-01,  4.593560896100384e-01,  6.656001065255846e-03,  
 -9.781563938994409e-01,  9.946089769037700e-01,  7.827411078516896e-04,  
 -9.778060661329431e-01, -3.970269563950553e-01,  6.040841876140015e-03,  
 -9.732806127131356e-01, -5.909702866713498e-01,  6.577441961101425e-03,  
 -9.719927242736324e-01, -9.738032840708760e-01,  2.184317380157956e-03,  
 -9.672092676086640e-01,  7.825063090118517e-01,  5.021658745346757e-03,  
 -9.603776991602971e-01, -2.153921649724314e-02,  8.448862253501903e-03,  
 -9.590320135912280e-01, -8.917513123920264e-01,  5.150986564054207e-03,  
 -9.545890590274086e-01, -7.377847025903865e-01,  8.094745379189257e-03,  
 -9.518800297972723e-01,  6.005875476668143e-01,  1.012666553714644e-02,  
 -9.515429157747712e-01,  2.941640121000471e-01,  1.034277329324190e-02,  
 -9.490472836637540e-01,  9.596558694888836e-01,  3.220645239038979e-03,  
 -9.474949611934800e-01, -2.528714063790848e-01,  1.171512879678826e-02,  
 -9.373768292011957e-01,  8.493689030467824e-01,  5.846679077116532e-03,  
 -9.316184094587854e-01, -4.719381834645925e-01,  1.149946336342146e-02,  
 -9.286585069364643e-01, -9.958860857406989e-01,  1.228760288290566e-03,  
 -9.267775091062305e-01,  8.114744510060384e-02,  1.023519688964817e-02,  
 -9.163559242547217e-01,  4.235110040036954e-01,  1.200757888591889e-02,  
 -9.121815833695173e-01,  9.882371567284969e-01,  2.019136532361037e-03,  
 -9.109849110758503e-01, -9.453953022277268e-01,  5.441926862298386e-03,  
 -9.037513800248385e-01,  7.152403666234081e-01,  1.254893510280643e-02,  
 -9.029200480204936e-01, -8.212018233771367e-01,  1.010629097307952e-02,  
 -9.017715031500836e-01, -6.268263259886000e-01,  1.344763853761130e-02,  
 -8.966208411354669e-01,  9.032456722718886e-01,  6.128920772776423e-03,  
 -8.949592560928252e-01, -1.162935700588350e-01,  1.704399639079853e-02,  
 -8.840140563237966e-01,  1.969976541674721e-01,  1.596015406249639e-02,  
 -8.746116719331715e-01, -3.448361698711476e-01,  1.765094462924452e-02,  
 -8.710753346416532e-01,  5.340745871340347e-01,  1.443864424160225e-02,  
 -8.484438717285120e-01,  9.509156312117837e-01,  5.738054352556750e-03,  
 -8.458535483524889e-01, -9.815128577523679e-01,  4.137548861495137e-03,  
 -8.398481586927637e-01,  9.961877079907046e-01,  1.304263243999687e-03,  
 -8.380687425956748e-01,  8.117290446268374e-01,  1.347035082702432e-02,  
 -8.338881116659986e-01, -8.932750703415656e-01,  1.036216371830049e-02,  
 -8.323418772294408e-01, -7.249676279524006e-01,  1.575346317085866e-02,  
 -8.249812915580336e-01,  3.366002739808117e-01,  2.128624669032709e-02,  
 -8.240658406348467e-01,  2.473915430588143e-02,  2.254370190641922e-02,  
 -8.235861595693262e-01, -5.100296033516193e-01,  2.030894605456216e-02,  
 -8.077195745093785e-01,  6.402169882573437e-01,  1.719971170125941e-02,  
 -7.994401076934280e-01, -2.090758091368732e-01,  2.285093214933729e-02,  
 -7.630151789434809e-01,  8.944374728168084e-01,  1.178494783231054e-02,  
 -7.595914562260390e-01,  9.774953228487998e-01,  5.007040345181551e-03,  
 -7.582407204546612e-01, -9.977747817904907e-01,  1.471436198785488e-03,  
 -7.479025577044630e-01,  4.742891505995823e-01,  2.322814942159416e-02,  
 -7.476388136248332e-01, -9.482109321336361e-01,  8.869792121065277e-03,  
 -7.467703985197518e-01, -8.150373305425095e-01,  1.612171337958705e-02,  
 -7.437239011702286e-01,  1.745124876671426e-01,  2.695721316522005e-02,  
 -7.347330924126372e-01, -6.233626922279565e-01,  2.200766479881018e-02,  
 -7.315599487238387e-01, -3.750364118349838e-01,  2.628156017590748e-02,  
 -7.287657206722611e-01,  7.405217467057846e-01,  1.766147427786541e-02,  
 -7.068497539323653e-01, -5.980644840754300e-02,  2.389888208127354e-02,  
 -6.810402042857588e-01, -1.522180405710772e-01,  9.694473603796364e-03,  
 -6.732322428485551e-01,  3.420204047422755e-01,  1.378566447967479e-02,  
 -6.671777044407723e-01,  9.965429698430747e-01,  2.043998547474421e-03,  
 -6.661024488936084e-01,  8.365632468531969e-01,  1.043213484692862e-02,  
 -6.574739030221062e-01,  6.056292870332995e-01,  1.928874088451468e-02,  
 -6.471433178579986e-01,  9.435400364191848e-01,  1.053431875912228e-02,  
 -6.450928247980198e-01, -8.897594199253124e-01,  1.467091129012532e-02,  
 -6.450169863776212e-01, -9.837401664708233e-01,  5.320225765195333e-03,  
 -6.356111898627910e-01,  2.888888071755747e-01,  1.689616308681305e-02,  
 -6.353365310873343e-01, -7.289411912040862e-01,  2.112609662944668e-02,  
 -6.298334119568398e-01, -4.991303444532345e-01,  2.693509156798771e-02,  
 -6.291453725213981e-01,  5.401236508742461e-01,  8.067204019727233e-03,  
 -6.052836931615376e-01, -2.550054118031913e-01,  3.145439290857988e-02,  
 -6.020155389610803e-01,  7.193745911974410e-02,  3.280026289766638e-02,  
 -5.864000058451709e-01,  8.398830909360200e-01,  9.794020060223996e-03,  
 -5.844053681740743e-01,  7.439581399260577e-01,  9.673537687961857e-03,  
 -5.595952952122188e-01,  4.183137864951066e-01,  2.109228735521581e-02,  
 -5.426224610168304e-01,  6.721678667912533e-01,  1.507682570233586e-02,  
 -5.392718444436758e-01, -6.640373564025523e-01,  6.853039280534112e-03,  
 -5.392273233424993e-01, -9.497301018552529e-01,  1.000131088526367e-02,  
 -5.352356532684714e-01, -5.949900365542921e-01,  1.257623121836303e-02,  
 -5.323778014446715e-01,  9.820204941474223e-01,  6.618755503045249e-03,  
 -5.217356658216146e-01, -8.191869945411094e-01,  1.965283477527441e-02,  
 -5.005240240607661e-01,  9.025303947810552e-01,  1.461332246120154e-02,  
 -4.938892072238822e-01, -9.399631019971544e-02,  3.808292738661537e-02,  
 -4.937487614230233e-01, -9.959198263215358e-01,  2.729762079728744e-03,  
 -4.900963037914226e-01, -3.938750807407649e-01,  3.202384141512818e-02,  
 -4.882533660406217e-01,  2.148638214494721e-01,  3.418958389588500e-02,  
 -4.867250611982683e-01,  5.069290645382520e-01,  2.181757841571514e-02,  
 -4.652861756571924e-01, -6.195234647797874e-01,  1.584655621464966e-02,  
 -4.606315835191566e-01,  7.592681033169186e-01,  1.498569479673017e-02,  
 -4.247086062086841e-01, -9.049304493933019e-01,  1.318933688912641e-02,  
 -4.065029720082786e-01,  6.264617368348774e-01,  1.614341656613300e-02,  
 -3.964381931274395e-01, -7.402485185211833e-01,  2.066230577186247e-02,  
 -3.917275322790500e-01, -2.763915160061775e-01,  2.066535103271340e-02,  
 -3.832536927501162e-01,  9.979855334480493e-01,  2.234175560395208e-03,  
 -3.794623453333835e-01,  9.538177413235013e-01,  1.114591704523323e-02,  
 -3.772235876850343e-01,  3.495735710597775e-01,  3.119665329913849e-02,  
 -3.717776952778286e-01,  8.276226068123943e-01,  1.892035069295494e-02,  
 -3.653673059860704e-01, -9.753012851813677e-01,  8.368304519228926e-03,  
 -3.645712799913758e-01,  5.949773008037845e-02,  4.066487888089951e-02,  
 -3.538124036025474e-01,  5.741754846631917e-01,  1.454074748757973e-02,  
 -3.469245014798072e-01, -5.093114780151489e-01,  3.377755276109650e-02,  
 -3.282417053015600e-01, -2.037015005394916e-01,  2.733887753306074e-02,  
 -3.131220942783493e-01, -8.518113941722779e-01,  1.597548862353881e-02,  
 -2.898525204314484e-01,  4.261338334628221e-01,  1.508608675885359e-02,  
 -2.882387623730816e-01, -6.853570019217500e-01,  1.688354844281806e-02,  
 -2.702465413583358e-01,  7.030983141548524e-01,  2.434400019199495e-02,  
 -2.508609565354079e-01,  8.968720007287277e-01,  1.702860129891579e-02,  
 -2.295191348329352e-01,  2.120242218321433e-01,  4.168382939934718e-02,  
 -2.272941564596992e-01, -9.960184881945845e-01,  3.049828038296397e-03,  
 -2.264708864968271e-01, -9.349035701784980e-01,  1.391154926700919e-02,  
 -2.246333439376893e-01,  9.827415964495356e-01,  7.017267263314176e-03,  
 -2.114669394714854e-01, -3.735617108580254e-01,  3.956793096822071e-02,  
 -2.089912056577438e-01, -7.231174948680190e-02,  4.093460500440146e-02,  
 -2.088716807934302e-01,  5.073561793189525e-01,  2.832407460904032e-02,  
 -1.854458909022641e-01, -7.951187042517341e-01,  2.077334257293032e-02,  
 -1.842272015612801e-01, -6.069003654432927e-01,  2.779454600167818e-02,  
 -1.777934970536059e-01,  7.780240581694521e-01,  1.585670340057501e-02,  
 -1.355056850182737e-01,  9.495952359773809e-01,  4.847063927629738e-03,  
 -9.279375419038796e-02,  6.222406899096711e-01,  3.101829992759421e-02,  
 -8.902511936497644e-02,  8.391229312717673e-01,  1.695975469484219e-02,  
 -8.734458962076150e-02,  3.558214042720322e-01,  3.984235442334169e-02,  
 -8.571835501122597e-02, -9.754128963485780e-01,  8.697179874291300e-03,  
 -7.422536842735775e-02, -8.831710824906397e-01,  1.813390976222609e-02,  
 -7.156922510987426e-02, -2.275959622954337e-01,  4.227714481951355e-02,  
 -7.101258554499701e-02,  7.775804214199432e-02,  4.334052544550671e-02,  
 -6.035205037448012e-02, -7.014869129344957e-01,  1.646744774690809e-02,  
 -6.004312209068092e-02,  9.389290315999793e-01,  1.055063932869926e-02,  
 -5.380430609957936e-02,  9.956336871057816e-01,  3.141838490889661e-03,  
 -5.001273890650990e-02, -4.928052077494132e-01,  3.665549033605845e-02,  
 -9.807961584190060e-03, -7.518448026748643e-01,  1.483105676671131e-02,  
 9.807961584190060e-03,  7.518448026748643e-01,  1.483105676671131e-02,  
 5.001273890650990e-02,  4.928052077494132e-01,  3.665549033605845e-02,  
 5.380430609957936e-02, -9.956336871057816e-01,  3.141838490889661e-03,  
 6.004312209068092e-02, -9.389290315999793e-01,  1.055063932869926e-02,  
 6.035205037448012e-02,  7.014869129344957e-01,  1.646744774690809e-02,  
 7.101258554499701e-02, -7.775804214199432e-02,  4.334052544550671e-02,  
 7.156922510987426e-02,  2.275959622954337e-01,  4.227714481951355e-02,  
 7.422536842735775e-02,  8.831710824906397e-01,  1.813390976222609e-02,  
 8.571835501122597e-02,  9.754128963485780e-01,  8.697179874291300e-03,  
 8.734458962076150e-02, -3.558214042720322e-01,  3.984235442334169e-02,  
 8.902511936497644e-02, -8.391229312717673e-01,  1.695975469484219e-02,  
 9.279375419038796e-02, -6.222406899096711e-01,  3.101829992759421e-02,  
 1.355056850182737e-01, -9.495952359773809e-01,  4.847063927629738e-03,  
 1.777934970536059e-01, -7.780240581694521e-01,  1.585670340057501e-02,  
 1.842272015612801e-01,  6.069003654432927e-01,  2.779454600167818e-02,  
 1.854458909022641e-01,  7.951187042517341e-01,  2.077334257293032e-02,  
 2.088716807934302e-01, -5.073561793189525e-01,  2.832407460904032e-02,  
 2.089912056577438e-01,  7.231174948680190e-02,  4.093460500440146e-02,  
 2.114669394714854e-01,  3.735617108580254e-01,  3.956793096822071e-02,  
 2.246333439376893e-01, -9.827415964495356e-01,  7.017267263314176e-03,  
 2.264708864968271e-01,  9.349035701784980e-01,  1.391154926700919e-02,  
 2.272941564596992e-01,  9.960184881945845e-01,  3.049828038296397e-03,  
 2.295191348329352e-01, -2.120242218321433e-01,  4.168382939934718e-02,  
 2.508609565354079e-01, -8.968720007287277e-01,  1.702860129891579e-02,  
 2.702465413583358e-01, -7.030983141548524e-01,  2.434400019199495e-02,  
 2.882387623730816e-01,  6.853570019217500e-01,  1.688354844281806e-02,  
 2.898525204314484e-01, -4.261338334628221e-01,  1.508608675885359e-02,  
 3.131220942783493e-01,  8.518113941722779e-01,  1.597548862353881e-02,  
 3.282417053015600e-01,  2.037015005394916e-01,  2.733887753306074e-02,  
 3.469245014798072e-01,  5.093114780151489e-01,  3.377755276109650e-02,  
 3.538124036025474e-01, -5.741754846631917e-01,  1.454074748757973e-02,  
 3.645712799913758e-01, -5.949773008037845e-02,  4.066487888089951e-02,  
 3.653673059860704e-01,  9.753012851813677e-01,  8.368304519228926e-03,  
 3.717776952778286e-01, -8.276226068123943e-01,  1.892035069295494e-02,  
 3.772235876850343e-01, -3.495735710597775e-01,  3.119665329913849e-02,  
 3.794623453333835e-01, -9.538177413235013e-01,  1.114591704523323e-02,  
 3.832536927501162e-01, -9.979855334480493e-01,  2.234175560395208e-03,  
 3.917275322790500e-01,  2.763915160061775e-01,  2.066535103271340e-02,  
 3.964381931274395e-01,  7.402485185211833e-01,  2.066230577186247e-02,  
 4.065029720082786e-01, -6.264617368348774e-01,  1.614341656613300e-02,  
 4.247086062086841e-01,  9.049304493933019e-01,  1.318933688912641e-02,  
 4.606315835191566e-01, -7.592681033169186e-01,  1.498569479673017e-02,  
 4.652861756571924e-01,  6.195234647797874e-01,  1.584655621464966e-02,  
 4.867250611982683e-01, -5.069290645382520e-01,  2.181757841571514e-02,  
 4.882533660406217e-01, -2.148638214494721e-01,  3.418958389588500e-02,  
 4.900963037914226e-01,  3.938750807407649e-01,  3.202384141512818e-02,  
 4.937487614230233e-01,  9.959198263215358e-01,  2.729762079728744e-03,  
 4.938892072238822e-01,  9.399631019971544e-02,  3.808292738661537e-02,  
 5.005240240607661e-01, -9.025303947810552e-01,  1.461332246120154e-02,  
 5.217356658216146e-01,  8.191869945411094e-01,  1.965283477527441e-02,  
 5.323778014446715e-01, -9.820204941474223e-01,  6.618755503045249e-03,  
 5.352356532684714e-01,  5.949900365542921e-01,  1.257623121836303e-02,  
 5.392273233424993e-01,  9.497301018552529e-01,  1.000131088526367e-02,  
 5.392718444436758e-01,  6.640373564025523e-01,  6.853039280534112e-03,  
 5.426224610168304e-01, -6.721678667912533e-01,  1.507682570233586e-02,  
 5.595952952122188e-01, -4.183137864951066e-01,  2.109228735521581e-02,  
 5.844053681740743e-01, -7.439581399260577e-01,  9.673537687961857e-03,  
 5.864000058451709e-01, -8.398830909360200e-01,  9.794020060223996e-03,  
 6.020155389610803e-01, -7.193745911974410e-02,  3.280026289766638e-02,  
 6.052836931615376e-01,  2.550054118031913e-01,  3.145439290857988e-02,  
 6.291453725213981e-01, -5.401236508742461e-01,  8.067204019727233e-03,  
 6.298334119568398e-01,  4.991303444532345e-01,  2.693509156798771e-02,  
 6.353365310873343e-01,  7.289411912040862e-01,  2.112609662944668e-02,  
 6.356111898627910e-01, -2.888888071755747e-01,  1.689616308681305e-02,  
 6.450169863776212e-01,  9.837401664708233e-01,  5.320225765195333e-03,  
 6.450928247980198e-01,  8.897594199253124e-01,  1.467091129012532e-02,  
 6.471433178579986e-01, -9.435400364191848e-01,  1.053431875912228e-02,  
 6.574739030221062e-01, -6.056292870332995e-01,  1.928874088451468e-02,  
 6.661024488936084e-01, -8.365632468531969e-01,  1.043213484692862e-02,  
 6.671777044407723e-01, -9.965429698430747e-01,  2.043998547474421e-03,  
 6.732322428485551e-01, -3.420204047422755e-01,  1.378566447967479e-02,  
 6.810402042857588e-01,  1.522180405710772e-01,  9.694473603796364e-03,  
 7.068497539323653e-01,  5.980644840754300e-02,  2.389888208127354e-02,  
 7.287657206722611e-01, -7.405217467057846e-01,  1.766147427786541e-02,  
 7.315599487238387e-01,  3.750364118349838e-01,  2.628156017590748e-02,  
 7.347330924126372e-01,  6.233626922279565e-01,  2.200766479881018e-02,  
 7.437239011702286e-01, -1.745124876671426e-01,  2.695721316522005e-02,  
 7.467703985197518e-01,  8.150373305425095e-01,  1.612171337958705e-02,  
 7.476388136248332e-01,  9.482109321336361e-01,  8.869792121065277e-03,  
 7.479025577044630e-01, -4.742891505995823e-01,  2.322814942159416e-02,  
 7.582407204546612e-01,  9.977747817904907e-01,  1.471436198785488e-03,  
 7.595914562260390e-01, -9.774953228487998e-01,  5.007040345181551e-03,  
 7.630151789434809e-01, -8.944374728168084e-01,  1.178494783231054e-02,  
 7.994401076934280e-01,  2.090758091368732e-01,  2.285093214933729e-02,  
 8.077195745093785e-01, -6.402169882573437e-01,  1.719971170125941e-02,  
 8.235861595693262e-01,  5.100296033516193e-01,  2.030894605456216e-02,  
 8.240658406348467e-01, -2.473915430588143e-02,  2.254370190641922e-02,  
 8.249812915580336e-01, -3.366002739808117e-01,  2.128624669032709e-02,  
 8.323418772294408e-01,  7.249676279524006e-01,  1.575346317085866e-02,  
 8.338881116659986e-01,  8.932750703415656e-01,  1.036216371830049e-02,  
 8.380687425956748e-01, -8.117290446268374e-01,  1.347035082702432e-02,  
 8.398481586927637e-01, -9.961877079907046e-01,  1.304263243999687e-03,  
 8.458535483524889e-01,  9.815128577523679e-01,  4.137548861495137e-03,  
 8.484438717285120e-01, -9.509156312117837e-01,  5.738054352556750e-03,  
 8.710753346416532e-01, -5.340745871340347e-01,  1.443864424160225e-02,  
 8.746116719331715e-01,  3.448361698711476e-01,  1.765094462924452e-02,  
 8.840140563237966e-01, -1.969976541674721e-01,  1.596015406249639e-02,  
 8.949592560928252e-01,  1.162935700588350e-01,  1.704399639079853e-02,  
 8.966208411354669e-01, -9.032456722718886e-01,  6.128920772776423e-03,  
 9.017715031500836e-01,  6.268263259886000e-01,  1.344763853761130e-02,  
 9.029200480204936e-01,  8.212018233771367e-01,  1.010629097307952e-02,  
 9.037513800248385e-01, -7.152403666234081e-01,  1.254893510280643e-02,  
 9.109849110758503e-01,  9.453953022277268e-01,  5.441926862298386e-03,  
 9.121815833695173e-01, -9.882371567284969e-01,  2.019136532361037e-03,  
 9.163559242547217e-01, -4.235110040036954e-01,  1.200757888591889e-02,  
 9.267775091062305e-01, -8.114744510060384e-02,  1.023519688964817e-02,  
 9.286585069364643e-01,  9.958860857406989e-01,  1.228760288290566e-03,  
 9.316184094587854e-01,  4.719381834645925e-01,  1.149946336342146e-02,  
 9.373768292011957e-01, -8.493689030467824e-01,  5.846679077116532e-03,  
 9.474949611934800e-01,  2.528714063790848e-01,  1.171512879678826e-02,  
 9.490472836637540e-01, -9.596558694888836e-01,  3.220645239038979e-03,  
 9.515429157747712e-01, -2.941640121000471e-01,  1.034277329324190e-02,  
 9.518800297972723e-01, -6.005875476668143e-01,  1.012666553714644e-02,  
 9.545890590274086e-01,  7.377847025903865e-01,  8.094745379189257e-03,  
 9.590320135912280e-01,  8.917513123920264e-01,  5.150986564054207e-03,  
 9.603776991602971e-01,  2.153921649724314e-02,  8.448862253501903e-03,  
 9.672092676086640e-01, -7.825063090118517e-01,  5.021658745346757e-03,  
 9.719927242736324e-01,  9.738032840708760e-01,  2.184317380157956e-03,  
 9.732806127131356e-01,  5.909702866713498e-01,  6.577441961101425e-03,  
 9.778060661329431e-01,  3.970269563950553e-01,  6.040841876140015e-03,  
 9.781563938994409e-01, -9.946089769037700e-01,  7.827411078516896e-04,  
 9.801636812194632e-01, -4.593560896100384e-01,  6.656001065255846e-03,  
 9.808343955917264e-01, -9.119881406240292e-01,  3.204352632730979e-03,  
 9.815404512250665e-01, -1.578509309909750e-01,  6.740930954579635e-03,  
 9.863969994171303e-01,  1.393885680294662e-01,  5.467653298722175e-03,  
 9.882776096714541e-01, -6.996008607192892e-01,  3.762641387033618e-03,  
 9.891970457464104e-01,  8.249338141061554e-01,  3.217331206511223e-03,  
 9.946606993258253e-01,  9.946657556011911e-01,  3.187304244494703e-04,  
 9.947425612275775e-01,  6.937725695763057e-01,  2.327244406193416e-03,  
 9.951431493831727e-01,  9.317895250779106e-01,  1.311747532188187e-03,  
 9.957989442071229e-01,  2.946071658312556e-01,  2.310642786475657e-03,  
 9.958948247928820e-01, -3.162381906315679e-01,  2.750378228739487e-03,  
 9.966744182696170e-01,  5.085108565093430e-01,  1.980803681920541e-03,  
 9.966780331371223e-01, -9.694002319896394e-01,  7.243867200693780e-04,  
 9.970436400762405e-01, -8.380584517844631e-01,  1.474635255954523e-03,  
 9.974803510397799e-01, -5.723617700464594e-01,  1.730177315995435e-03,  
 9.983507138390728e-01, -2.846923651716276e-02,  1.946248040917511e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr40 ( )

/******************************************************************************/
/*
  Purpose:

    SMR40 returns the SMR rule of degree 40.

  Discussion:
 
    DEGREE: 40
    POINTS CARDINALITY: 296
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR40[3*296], the requested rule.
*/
{
  const int degree = 40;
  int order;
  double xw[3*296] = {
 -9.980037227196614e-01,  1.255939443038006e-01,  2.053102393463664e-03,  
 -9.975374042816840e-01,  5.936108405943805e-01,  1.276187489810420e-03,  
 -9.972861466402049e-01, -6.627439420820114e-01,  1.580298156253981e-03,  
 -9.968592673741854e-01,  8.736423351683437e-01,  1.202945592410809e-03,  
 -9.966589451189311e-01, -4.369849380251707e-01,  2.115586380569520e-03,  
 -9.965219690837533e-01, -1.944638806631471e-01,  2.429919318140257e-03,  
 -9.964358393204891e-01,  4.092031891829934e-01,  2.182777026867640e-03,  
 -9.963941450446951e-01,  9.775574537230374e-01,  5.781357112514488e-04,  
 -9.955864247426816e-01, -9.784933334191470e-01,  6.423485659734820e-04,  
 -9.955242411687316e-01, -8.201261852647251e-01,  1.452148584658119e-03,  
 -9.913130830294992e-01,  7.451950336474148e-01,  3.099740554076827e-03,  
 -9.900337734476057e-01, -9.112486663047842e-01,  2.026525375041507e-03,  
 -9.844939696556546e-01, -3.396948505159310e-02,  6.297322525864257e-03,  
 -9.828708241253864e-01,  2.672014458471039e-01,  6.110796337925116e-03,  
 -9.813352997502048e-01,  9.317282602187734e-01,  2.388338374639091e-03,  
 -9.812506993249306e-01, -5.599844336596295e-01,  5.433547359777527e-03,  
 -9.811994633761572e-01,  5.954700474743184e-01,  3.855922634832198e-03,  
 -9.787064347309005e-01, -3.245284003636001e-01,  6.507740619311661e-03,  
 -9.780647700362322e-01, -7.464363616852314e-01,  4.386694918546395e-03,  
 -9.768709333873531e-01,  9.964868257322258e-01,  5.743979761358160e-04,  
 -9.743127159036291e-01, -9.969203399240063e-01,  5.885958513598154e-04,  
 -9.719890138043383e-01,  4.635529385440017e-01,  5.543426475209034e-03,  
 -9.663961744212400e-01,  8.297161334267321e-01,  5.377245930028534e-03,  
 -9.624486391679733e-01, -9.552403379650487e-01,  2.935271926976710e-03,  
 -9.571101155486035e-01, -8.504016909299451e-01,  5.548045896834978e-03,  
 -9.569508072526900e-01,  1.145259922791730e-01,  1.019364727373913e-02,  
 -9.539620291105575e-01,  9.656118875216714e-01,  2.000317967473577e-03,  
 -9.531361804534030e-01, -1.756012259335100e-01,  1.012788272053494e-02,  
 -9.503256987566595e-01,  6.828228592655408e-01,  8.213806957862843e-03,  
 -9.455690174869477e-01, -4.553679978362609e-01,  1.002546929027743e-02,  
 -9.444080894387320e-01, -6.600309149596145e-01,  8.342165274488325e-03,  
 -9.363352068572794e-01,  3.305989409491193e-01,  1.063637549554008e-02,  
 -9.344111368509483e-01,  5.018191785468655e-01,  7.093229113292136e-03,  
 -9.250445674046065e-01,  8.992422617422033e-01,  6.279305248680532e-03,  
 -9.225703808148057e-01,  9.858292479280879e-01,  1.834573979737579e-03,  
 -9.165441617582062e-01, -9.853128908447532e-01,  2.565324347525059e-03,  
 -9.150614770382599e-01, -3.139530918232870e-02,  1.359896871759167e-02,  
 -9.103915600727824e-01, -9.092647756707973e-01,  6.216724896190497e-03,  
 -9.074945980525453e-01, -3.110157725349993e-01,  1.298683840693059e-02,  
 -9.043535181463653e-01, -7.713160602214696e-01,  1.024303332784389e-02,  
 -9.025325558225301e-01,  7.743255817267981e-01,  1.011918005042377e-02,  
 -8.936138114540279e-01,  1.960899239677014e-01,  1.411969841594799e-02,  
 -8.921757562307675e-01,  5.847775228961032e-01,  1.223494929054215e-02,  
 -8.914413155620955e-01, -5.644405075920796e-01,  1.287350206631372e-02,  
 -8.651606789959365e-01,  9.507227302652309e-01,  5.817570712124294e-03,  
 -8.624964059071404e-01,  4.007509803672114e-01,  1.631963389227952e-02,  
 -8.624016491888394e-01,  9.973607974975222e-01,  1.085292256544525e-03,  
 -8.571481676731489e-01, -1.732871980674100e-01,  1.643819257648864e-02,  
 -8.511908836822574e-01, -4.127628928140689e-01,  1.185185065054727e-02,  
 -8.471275338153255e-01, -9.533530423203328e-01,  5.827596397572629e-03,  
 -8.433676706517138e-01,  5.983417524756374e-02,  1.569370700632547e-02,  
 -8.424649352939378e-01,  8.531606755621376e-01,  1.000254175836821e-02,  
 -8.382814166059266e-01, -9.973371948408554e-01,  1.236406010086881e-03,  
 -8.380565845515963e-01, -8.466246757209853e-01,  1.074234765384687e-02,  
 -8.321936110008199e-01, -6.779831075876902e-01,  1.522781703701599e-02,  
 -8.286278033800711e-01,  6.833732733978219e-01,  1.509304227664999e-02,  
 -8.055255758765038e-01, -4.763880300923605e-01,  1.085366933632746e-02,  
 -7.971673647784905e-01,  2.532323209821991e-01,  2.052836615250460e-02,  
 -7.910441928184301e-01,  5.077971678500216e-01,  1.780077542770354e-02,  
 -7.859172990177037e-01, -7.833283965104983e-02,  1.472595970793188e-02,  
 -7.798224683613482e-01,  9.817158588687893e-01,  4.411372664168903e-03,  
 -7.733447858053083e-01, -2.912095449947633e-01,  2.109987317572403e-02,  
 -7.707288564403509e-01,  9.135259150232076e-01,  8.345329225642115e-03,  
 -7.578198426154767e-01, -9.796098169168449e-01,  4.456574433684158e-03,  
 -7.562414896721606e-01, -9.049214717524879e-01,  1.001882084525143e-02,  
 -7.548211869038036e-01,  7.785365721991255e-01,  1.478039679943451e-02,  
 -7.494378413286128e-01, -7.662608330090768e-01,  1.581956505815484e-02,  
 -7.445473618861123e-01, -5.699700714382581e-01,  1.889632922544271e-02,  
 -7.423038822674627e-01,  7.897961507665216e-02,  1.715604114405427e-02,  
 -7.170452369551987e-01,  6.041689391836269e-01,  1.721434133773814e-02,  
 -7.096177258303671e-01,  3.669023638814550e-01,  2.303538633973196e-02,  
 -6.947187172157958e-01, -9.098243292500578e-02,  1.600840192685054e-02,  
 -6.827474344539016e-01,  8.632122010101693e-01,  9.488912002746175e-03,  
 -6.766766916048634e-01, -4.118520712505950e-01,  2.365726668658341e-02,  
 -6.757537207484740e-01,  9.965428761249577e-01,  1.913682375287724e-03,  
 -6.716977448629430e-01,  9.507129459344548e-01,  7.775380155384150e-03,  
 -6.705672963967729e-01, -2.084540920008020e-01,  1.628326394109379e-02,  
 -6.634191394897307e-01, -9.956567399175887e-01,  2.049561637770933e-03,  
 -6.628050205606234e-01,  1.672916166402376e-01,  2.265410339187529e-02,  
 -6.572284494011310e-01, -9.451593820143880e-01,  8.033722247688203e-03,  
 -6.502802198668451e-01, -6.663478504843525e-01,  2.086896333372951e-02,  
 -6.500944652911421e-01, -8.388046887319990e-01,  1.533892815116460e-02,  
 -6.494395416059597e-01,  6.978896106401927e-01,  1.632586135380591e-02,  
 -6.182525423851862e-01,  4.772666066191493e-01,  2.314379901273175e-02,  
 -6.097521926338272e-01,  8.178387432803899e-01,  1.027570595259021e-02,  
 -5.857038932505656e-01, -1.750697876397254e-03,  2.826026275637352e-02,  
 -5.765612790071245e-01, -5.184987079049800e-01,  2.276145801578116e-02,  
 -5.737142051029732e-01, -3.132765352046541e-01,  1.443899895963975e-02,  
 -5.644865970292597e-01,  9.783893306945404e-01,  5.710986844724012e-03,  
 -5.644553463342945e-01,  2.782921931969836e-01,  2.781479815231922e-02,  
 -5.580769546100564e-01, -9.759275455445522e-01,  5.684058667060024e-03,  
 -5.542741288051631e-01,  9.016977074485676e-01,  1.168589067769203e-02,  
 -5.542073588689838e-01, -2.043031348070334e-01,  1.827083660577868e-02,  
 -5.433087051306172e-01,  5.922649560095551e-01,  1.990937282981727e-02,  
 -5.386567969465166e-01, -8.983031172510674e-01,  1.272427456995568e-02,  
 -5.373382383966947e-01, -7.520144164271236e-01,  2.091503656277224e-02,  
 -5.224304686125945e-01,  7.455130741439847e-01,  1.698684695502466e-02,  
 -4.893827154330137e-01, -5.941538126001544e-01,  1.598966080652984e-02,  
 -4.722069619254669e-01, -3.587550371799506e-01,  2.132063146049633e-02,  
 -4.718832732594200e-01, -9.958106507002302e-01,  2.226108918584357e-03,  
 -4.706670553696944e-01,  1.154506383897263e-01,  2.935766164731613e-02,  
 -4.626454569472719e-01,  9.963250210519803e-01,  2.223046715737653e-03,  
 -4.600264076712823e-01,  3.966582665227552e-01,  2.629091387627286e-02,  
 -4.481481045273694e-01,  9.395445338170469e-01,  8.839978177696708e-03,  
 -4.415878841168007e-01, -1.062065683181053e-01,  3.058245417110486e-02,  
 -4.412583635452328e-01,  5.087399017780769e-01,  1.125492379082715e-02,  
 -4.304912794659402e-01, -4.469668566457143e-01,  1.012062172404055e-02,  
 -4.287211566152106e-01,  8.321571485937996e-01,  1.786605784125267e-02,  
 -4.223793646176035e-01, -8.333753189124466e-01,  1.730213472188374e-02,  
 -4.222588890220841e-01, -9.452641667145504e-01,  1.007216794776104e-02,  
 -4.083597732182007e-01,  6.509919047599022e-01,  2.181242775531822e-02,  
 -3.998205203687450e-01, -6.594190487482490e-01,  2.190933309032257e-02,  
 -3.695693944824219e-01,  2.193101954125042e-01,  2.327576101611239e-02,  
 -3.676144523897173e-01,  9.682350478689863e-01,  4.815232646045845e-03,  
 -3.591049460581930e-01, -4.614598488900264e-01,  1.852799716750301e-02,  
 -3.447647402371574e-01, -2.381537435610105e-01,  2.808527790039856e-02,  
 -3.341217099662899e-01, -9.826197273812773e-01,  5.494849259173287e-03,  
 -3.093195936880301e-01,  3.287238905146597e-01,  2.185303504037471e-02,  
 -3.072048398998126e-01,  9.859602190406442e-01,  3.831362623751753e-03,  
 -3.058002206640513e-01,  2.103076331772531e-02,  3.459647562394031e-02,  
 -3.044867199555938e-01,  5.186120611581733e-01,  2.833979791519306e-02,  
 -3.028681432998989e-01, -7.600469172213820e-01,  1.964686881716537e-02,  
 -3.024605574449728e-01,  8.931659138204667e-01,  1.538434812191329e-02,  
 -3.011532601990519e-01,  7.437794313731125e-01,  2.273787326209627e-02,  
 -2.887440306182171e-01, -8.957912044678301e-01,  1.555524233275056e-02,  
 -2.644411240015258e-01, -5.502788852260921e-01,  2.671171545840637e-02,  
 -2.400609781144449e-01, -3.260570838043731e-01,  2.569267849167105e-02,  
 -2.246489878361267e-01, -9.978033236073471e-01,  1.770873804828288e-03,  
 -2.066616281756470e-01, -1.045383048279050e-01,  2.497609050660571e-02,  
 -2.009374136079489e-01,  2.040282941161825e-01,  2.267428085593906e-02,  
 -1.909926939589495e-01,  9.968668571166585e-01,  2.126801518422638e-03,  
 -1.887172076094760e-01, -9.549438196754605e-01,  1.035110388694925e-02,  
 -1.885639548532559e-01, -6.847997847346543e-01,  2.014138051533820e-02,  
 -1.856269263888624e-01,  9.475270956402012e-01,  1.146925671119005e-02,  
 -1.790760401308231e-01,  6.312120892250483e-01,  2.910873684757638e-02,  
 -1.707661353723164e-01,  8.213933035442971e-01,  2.057181928201535e-02,  
 -1.702074855482027e-01,  4.002072179476484e-01,  2.982548255683739e-02,  
 -1.505878349304818e-01, -8.293254383680554e-01,  2.076026265668495e-02,  
 -1.380074232134180e-01,  1.170336739663703e-01,  2.527234775085595e-02,  
 -1.268389913099443e-01, -4.236318257465341e-01,  3.117645114412499e-02,  
 -1.153288220374788e-01, -1.747226323716413e-01,  2.609156073209279e-02,  
 -8.202442049825323e-02, -6.034256289197292e-01,  2.293044125103543e-02,  
 -6.778022692220509e-02, -9.864359427377531e-01,  5.537492701577899e-03,  
 -5.134750275993507e-02,  9.806699464341012e-01,  7.025195533489713e-03,  
 -4.796731115368809e-02,  5.109816289271156e-01,  2.949281042166952e-02,  
 -4.605994163927313e-02,  8.940716194171991e-01,  1.696854743218261e-02,  
 -4.447210172626447e-02, -9.096553765331403e-01,  1.548395021034487e-02,  
 -4.115113842285135e-02,  7.297743920654538e-01,  2.604976478474774e-02,  
 -2.744836558183677e-02,  4.417586914136311e-03,  3.387227419183413e-02,  
 -1.995488830453244e-02,  2.898374142768337e-01,  3.548548223572283e-02,  
 -9.393841375026718e-03, -7.464248084281863e-01,  2.510074937831712e-02,  
 5.604522124288533e-03, -2.838153304903738e-01,  3.557931287068862e-02,  
 3.379282258563019e-02, -5.108284849354834e-01,  2.741093593275501e-02,  
 7.396931495071729e-02,  6.103364495915078e-01,  2.553255759952799e-02,  
 7.811073060419052e-02, -9.596104105748841e-01,  9.711338256956472e-03,  
 8.053272615641659e-02,  1.616603676436590e-01,  2.424025867338976e-02,  
 8.332876758512328e-02, -9.980434804933414e-01,  1.698291109393467e-03,  
 8.611110621478242e-02,  9.972454574738652e-01,  2.305464957382294e-03,  
 9.098018561909829e-02,  9.458495772991818e-01,  1.224095474595298e-02,  
 9.177090470118981e-02,  8.205555321043025e-01,  2.227240136214740e-02,  
 9.706026488340756e-02, -8.463187115614078e-01,  2.019012230112588e-02,  
 9.815256847947500e-02, -9.239456937873544e-02,  2.644315338527209e-02,  
 1.222602596423681e-01,  4.213511759613903e-01,  3.341374966024566e-02,  
 1.323057369500668e-01, -6.509117254364495e-01,  2.871043880147142e-02,  
 1.476438086930435e-01, -4.017405050343198e-01,  2.837624979369559e-02,  
 1.700850694113563e-01, -1.780332539520100e-01,  2.291185695253523e-02,  
 1.736805569574461e-01,  1.096612012416960e-01,  2.405540809236990e-02,  
 1.843432890535553e-01,  6.990228911926680e-01,  2.163148537165614e-02,  
 1.995648926700597e-01, -9.818731842028169e-01,  3.370075215701449e-03,  
 2.081596610552691e-01,  2.925076496248445e-01,  1.903382067011115e-02,  
 2.211797307297267e-01, -9.164694403878136e-01,  1.468906732639756e-02,  
 2.277074094032160e-01,  9.805932530165899e-01,  7.084751090497078e-03,  
 2.292021628595871e-01,  8.912694976681395e-01,  1.721353195733831e-02,  
 2.353608895201955e-01, -3.491298395101170e-01,  9.892666536128697e-03,  
 2.385004221656652e-01, -7.689128083096237e-01,  2.393352337395165e-02,  
 2.613881314139023e-01,  5.471551577512984e-01,  3.040265099653250e-02,  
 2.662205097670882e-01, -9.919548226778696e-01,  2.707867154217599e-03,  
 2.680565017395204e-01, -5.400402346502616e-01,  3.088207638947784e-02,  
 2.833408004935626e-01, -6.718319274714699e-03,  3.511070135380980e-02,  
 2.921989695479881e-01,  7.730713136429667e-01,  1.950015697008031e-02,  
 2.932051140793899e-01, -2.568476496223008e-01,  2.600581679576460e-02,  
 3.010766919534110e-01,  3.879280619333716e-01,  1.093142774025551e-02,  
 3.103865035997045e-01,  2.499428455332039e-01,  2.499586360508493e-02,  
 3.585933886911649e-01, -8.576820377675525e-01,  1.842882832290949e-02,  
 3.596570955415763e-01, -9.615962408411522e-01,  9.068153972939736e-03,  
 3.618929539106814e-01,  9.449875484526220e-01,  1.169739415667232e-02,  
 3.672563754612045e-01,  9.968578675032447e-01,  2.310464434967522e-03,  
 3.689758663333720e-01, -6.723055595123385e-01,  2.553001008106885e-02,  
 3.871364360677614e-01, -3.963308613870815e-01,  2.492421215216349e-02,  
 3.982469712949650e-01,  4.487336172829021e-01,  2.309608167942591e-02,  
 3.983155249621386e-01,  6.561427847972009e-01,  2.730674172786235e-02,  
 4.034252589810011e-01,  8.423386731412055e-01,  1.707487237256047e-02,  
 4.102541856930609e-01, -1.410736134292944e-01,  3.151312043028231e-02,  
 4.168183088396271e-01,  1.263343252035515e-01,  3.270130716222084e-02,  
 4.356104174313109e-01, -9.957058788304909e-01,  2.363557214215902e-03,  
 4.405318740860549e-01, -4.926398721055529e-01,  1.608280706132078e-02,  
 4.649771622601932e-01,  3.483599503333080e-01,  1.925449126504078e-02,  
 4.709325171484977e-01, -7.695942184085469e-01,  1.705050367502311e-02,  
 4.850638966079184e-01, -9.216775010693871e-01,  1.252775237505845e-02,  
 4.932957374397012e-01,  9.795648836635775e-01,  6.463044419371160e-03,  
 5.128665631816022e-01,  9.033981066102003e-01,  1.292621422635387e-02,  
 5.150863190443300e-01, -5.934248074499449e-01,  2.363213862387783e-02,  
 5.156373648667533e-01,  5.651053767086885e-01,  1.423781492860490e-02,  
 5.181912316625248e-01, -2.922194304405071e-01,  2.989079134667543e-02,  
 5.251717070662635e-01,  7.552962710143433e-01,  2.242429087194216e-02,  
 5.269679036105911e-01, -2.177852596986115e-02,  2.944698631679846e-02,  
 5.359327347133740e-01, -8.200294790454760e-01,  8.860113200433273e-03,  
 5.388079818555839e-01, -9.812499958704087e-01,  4.680745828233062e-03,  
 5.434833238763666e-01,  2.380283686509251e-01,  2.395538344613452e-02,  
 5.496379512343986e-01,  5.253805284097529e-01,  1.632157824790180e-02,  
 6.051493656005358e-01, -4.503578461535495e-01,  2.612344895845866e-02,  
 6.124277898034318e-01,  9.967024781187570e-01,  2.002070456520778e-03,  
 6.140603542011213e-01,  3.676905093247132e-01,  1.890620847606754e-02,  
 6.149248157512081e-01, -8.737165849180063e-01,  1.296667270713843e-02,  
 6.154648019220623e-01, -7.039292064085437e-01,  2.124810385786090e-02,  
 6.216520374448096e-01,  9.489344195184967e-01,  8.530620092099012e-03,  
 6.262996333546856e-01, -9.603966937474196e-01,  6.014411655091729e-03,  
 6.266507568536149e-01, -1.753112127213321e-01,  2.574430846684179e-02,  
 6.320748250590934e-01,  9.236778723276985e-02,  2.509516970454762e-02,  
 6.371103207708532e-01,  8.421673270141240e-01,  1.637617879409531e-02,  
 6.445697045015427e-01,  6.589930041457702e-01,  2.309339250212301e-02,  
 6.611641817999792e-01, -9.971250985273443e-01,  1.780949246753485e-03,  
 6.827225489763870e-01,  4.582089303489358e-01,  1.967115820258447e-02,  
 7.007607922685678e-01, -5.793001008608837e-01,  2.187824067436787e-02,  
 7.074131809621955e-01, -3.372902789247548e-01,  2.360006012075187e-02,  
 7.117739087420435e-01,  2.241359340497962e-01,  2.258162720143967e-02,  
 7.151943805770620e-01, -7.271602060694378e-02,  2.063320130758209e-02,  
 7.155680922709143e-01, -7.994435082716885e-01,  1.620969075703751e-02,  
 7.187947908611272e-01, -9.289105584767267e-01,  8.674348771692817e-03,  
 7.188580147804288e-01,  9.801870566125678e-01,  4.556848768699447e-03,  
 7.407850806335647e-01,  9.092174747735176e-01,  1.069960175297740e-02,  
 7.414535252324259e-01,  7.627992252808989e-01,  1.713716583993931e-02,  
 7.620781689289542e-01,  5.682929391541718e-01,  1.992594154989019e-02,  
 7.635939132299792e-01, -9.831481015790724e-01,  4.153559323873574e-03,  
 7.797638735837149e-01,  4.665676142002305e-02,  1.954090589438721e-02,  
 7.867620038671331e-01,  3.403489048139350e-01,  1.972374555702004e-02,  
 7.883553505223821e-01, -6.893416107380125e-01,  1.663667575800614e-02,  
 7.942764870013759e-01, -4.707153685105653e-01,  1.983755770035392e-02,  
 7.952669529963022e-01, -2.273770055235256e-01,  2.028000921211288e-02,  
 7.990872541216331e-01,  9.962955158284175e-01,  1.408927698874655e-03,  
 8.066178878802995e-01, -8.762511423208362e-01,  1.090696275036013e-02,  
 8.274679999131711e-01,  8.480202028380042e-01,  1.137803861452648e-02,  
 8.297408153069072e-01,  9.581886918512165e-01,  5.948632265683609e-03,  
 8.377680145222012e-01,  6.811297101045124e-01,  1.536534914781161e-02,  
 8.427716005452982e-01, -9.571708221478029e-01,  4.952439619855199e-03,  
 8.488271945024087e-01,  1.666337693793623e-01,  1.887388216602816e-02,  
 8.525662030669592e-01,  4.592708043695782e-01,  1.653498201879920e-02,  
 8.561315417874497e-01, -9.598113535151943e-02,  1.680778035994472e-02,  
 8.606876078808835e-01, -9.969922689109865e-01,  1.288211684632280e-03,  
 8.613581542207239e-01, -7.784610468370953e-01,  1.096644364207657e-02,  
 8.690885595988450e-01, -5.894733063271762e-01,  1.503337345041933e-02,  
 8.723930444088900e-01, -3.621107058578862e-01,  1.641608892157977e-02,  
 8.962187117350728e-01,  9.900514429185334e-01,  2.177703335659953e-03,  
 8.978901908775218e-01,  9.150513717072788e-01,  6.528697758436882e-03,  
 8.995842578268963e-01, -9.234484518613306e-01,  5.137110006320958e-03,  
 9.026936084906036e-01,  7.808928092755504e-01,  1.012526399216284e-02,  
 9.070441620900885e-01,  3.009963311241410e-01,  1.501588480324425e-02,  
 9.077878820329093e-01,  5.794983066365614e-01,  1.246940196306337e-02,  
 9.111551364648940e-01, -8.412973077435701e-01,  5.641113054429737e-03,  
 9.142518109635371e-01,  2.169517484726380e-02,  1.439386845586924e-02,  
 9.173217644911268e-01, -2.254212884222193e-01,  1.167670360384378e-02,  
 9.282555961436508e-01, -6.912520433990101e-01,  9.933776930685268e-03,  
 9.284877628036031e-01, -9.817037571629690e-01,  2.694281259701618e-03,  
 9.334452240614641e-01, -4.859399349804389e-01,  1.184281101417954e-02,  
 9.468439730471343e-01,  9.657765158699502e-01,  3.003223815105551e-03,  
 9.506625037743694e-01,  4.376710347741515e-01,  1.025469033794625e-02,  
 9.520896121093332e-01,  8.643710868609885e-01,  5.555972363422187e-03,  
 9.523271992044501e-01,  6.913007415265950e-01,  7.990950689265556e-03,  
 9.545272982243453e-01, -8.811333722531620e-01,  3.828862340862868e-03,  
 9.554958506512122e-01,  1.588668533845889e-01,  1.058860881322785e-02,  
 9.598844841990601e-01, -3.304786335896162e-01,  6.696028105510322e-03,  
 9.612092716134895e-01, -1.252637834195337e-01,  8.918983273981967e-03,  
 9.664864057745631e-01, -7.771023857020345e-01,  5.108888381040824e-03,  
 9.696658884223082e-01, -9.486617819335378e-01,  2.629252771609383e-03,  
 9.714461152005505e-01,  9.966817132006599e-01,  6.382221125358519e-04,  
 9.756072026722676e-01, -9.972566545264508e-01,  5.380433266276414e-04,  
 9.756270675128569e-01, -5.974850205967676e-01,  6.836267790083512e-03,  
 9.794527164689676e-01,  5.643324681844055e-01,  5.410131191715718e-03,  
 9.826866520761600e-01,  7.911127382228441e-01,  3.928246838882010e-03,  
 9.831392239644022e-01,  9.303396888012979e-01,  2.423589086603377e-03,  
 9.832274416154096e-01,  3.033661616270960e-01,  6.310915040526618e-03,  
 9.843450993838505e-01, -4.150221010386896e-01,  4.095407382162835e-03,  
 9.849932890167565e-01,  7.572227591204869e-03,  5.802629795760786e-03,  
 9.909963827975042e-01, -2.639507972140410e-01,  3.395140293721511e-03,  
 9.912765561948801e-01, -8.332891526969999e-01,  1.953926311905468e-03,  
 9.934327301490941e-01,  6.231882587178860e-01,  9.287993595683975e-04,  
 9.937448936136122e-01, -9.092710501130503e-01,  1.256142182103206e-03,  
 9.948882230658729e-01, -7.050697257712721e-01,  2.287960809703529e-03,  
 9.951704470679726e-01,  9.801745622873680e-01,  6.475410324288955e-04,  
 9.952340236934687e-01, -9.783971899965007e-01,  6.447054298301821e-04,  
 9.963792308208721e-01,  6.981957876294371e-01,  1.512427084884079e-03,  
 9.970264968246741e-01,  4.457495638028096e-01,  2.107128717380615e-03,  
 9.977348846785328e-01, -1.427747693558082e-01,  1.552913600795280e-03,  
 9.977388598284106e-01,  1.545000376629158e-01,  2.038498731858248e-03,  
 9.982891584585788e-01,  8.710523206892243e-01,  9.529077858582162e-04,  
 9.991656973291163e-01, -5.021799411346501e-01,  1.444993876112607e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr41 ( )

/******************************************************************************/
/*
  Purpose:

    SMR41 returns the SMR rule of degree 41.

  Discussion:
 
    DEGREE: 41
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 303
    NORM INF MOMS. RESIDUAL: 1.77636e-15
    SUM NEGATIVE WEIGHTS: 0.00000e+00, 

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR41[3*303], the requested rule.
*/
{
  const int degree = 41;
  int order;
  double xw[3*303] = {
 -9.979788599279722e-01, -8.620321171404657e-01,  9.843080418879427e-04,  
 -9.972233023651127e-01, -1.689643304774283e-01,  2.334603070096216e-03,  
 -9.968865665492763e-01,  1.264946845449128e-01,  2.336585497171821e-03,  
 -9.967543799903597e-01,  3.758322880625192e-01,  1.965952058779777e-03,  
 -9.966030911672050e-01, -4.414700559329136e-01,  2.103309187930437e-03,  
 -9.965848495106024e-01, -6.842725498070605e-01,  1.783337849517576e-03,  
 -9.961989059670616e-01,  9.525971037206539e-01,  6.660472520224310e-04,  
 -9.955131940127476e-01,  8.558413309721239e-01,  1.466862509992409e-03,  
 -9.955121819465780e-01, -9.789979211029449e-01,  6.407210056305082e-04,  
 -9.954861320163209e-01,  5.681416527913361e-01,  2.181094091195068e-03,  
 -9.929582393871068e-01, -5.370347553708347e-01,  6.365700160628349e-04,  
 -9.918341858607898e-01,  7.250215468408083e-01,  2.925047225366992e-03,  
 -9.897982334464747e-01,  9.889847320679855e-01,  6.578382364688170e-04,  
 -9.850276191493494e-01, -9.248683981506678e-01,  2.259102932718402e-03,  
 -9.820959231331791e-01, -7.821855489421354e-01,  4.084862972791807e-03,  
 -9.818366925634343e-01, -2.156090420260150e-02,  6.852107137072102e-03,  
 -9.808975723862894e-01, -3.112518230537506e-01,  6.733976982472782e-03,  
 -9.803016487147558e-01,  2.539985793768113e-01,  6.144467944923415e-03,  
 -9.791585763360798e-01, -5.756466500202441e-01,  5.476389537369480e-03,  
 -9.767561034338471e-01,  9.143771666367756e-01,  2.776979717116026e-03,  
 -9.758317798625764e-01,  4.558745215283740e-01,  5.758484945330961e-03,  
 -9.733634369985799e-01, -9.966978125597651e-01,  6.175342802324851e-04,  
 -9.675664657866050e-01,  6.206279941904160e-01,  6.157178279661575e-03,  
 -9.667526686680565e-01,  8.023493190515092e-01,  5.052013954468514e-03,  
 -9.574847616595294e-01,  9.991852307452070e-01,  4.156752677850517e-04,  
 -9.551655794629224e-01,  9.662000026762417e-01,  2.519263815744828e-03,  
 -9.541283709855817e-01, -9.615200131743211e-01,  2.770123594982525e-03,  
 -9.529627107888853e-01, -8.594308951734482e-01,  5.521466103754615e-03,  
 -9.511137028620014e-01,  1.537123214377626e-01,  1.548656739539656e-03,  
 -9.501218449448332e-01, -1.679843056344594e-01,  1.129203236633850e-02,  
 -9.486279733146294e-01, -6.865588686606500e-01,  8.287308334158514e-03,  
 -9.483377728448769e-01,  1.079182983808205e-01,  9.649772007405522e-03,  
 -9.481698863829746e-01, -4.482511579023943e-01,  1.058846772781884e-02,  
 -9.376659862954376e-01,  3.320927786395850e-01,  9.853104948952236e-03,  
 -9.306103944301639e-01,  8.662316655121048e-01,  5.280103565555265e-03,  
 -9.300699834315862e-01,  7.014618847802435e-01,  8.344725482478233e-03,  
 -9.280108673251274e-01,  4.983380051452493e-01,  9.333950017742142e-03,  
 -9.095843629981852e-01, -9.870451124979706e-01,  2.291616065068371e-03,  
 -9.045872993270916e-01,  9.244231244080491e-01,  4.633234288837451e-03,  
 -9.035282359913408e-01, -9.127575798900944e-01,  6.195061068875661e-03,  
 -9.023427661156972e-01, -3.102537604841927e-01,  1.518789863772203e-02,  
 -9.023191697919575e-01,  9.860953439377561e-01,  2.287777730391639e-03,  
 -9.018609313605185e-01, -3.168234272327462e-02,  1.540631304873537e-02,  
 -9.009350039678510e-01, -7.782630377583909e-01,  1.005814342536296e-02,  
 -8.995512373198538e-01, -5.752687860358924e-01,  1.333914316671023e-02,  
 -8.862410073156858e-01,  2.023135190038032e-01,  1.419438960724134e-02,  
 -8.799510611339678e-01,  7.804272229598096e-01,  9.800822621659112e-03,  
 -8.779133156049225e-01,  5.858583967917332e-01,  1.273340964065398e-02,  
 -8.655996427765849e-01,  3.758701133077118e-01,  1.356217699235571e-02,  
 -8.409266136580046e-01, -4.471234082886604e-01,  1.725729695008926e-02,  
 -8.400990403804555e-01, -9.553728108586558e-01,  5.756357460449216e-03,  
 -8.396784302276527e-01, -1.756139328191055e-01,  1.921157782857880e-02,  
 -8.378454530446884e-01,  9.530099558379057e-01,  5.399408829933249e-03,  
 -8.351166757877715e-01, -9.976562452857387e-01,  1.078286714786108e-03,  
 -8.318210977517786e-01, -8.478689190545843e-01,  1.077737568013724e-02,  
 -8.316813659365053e-01, -6.810571166632299e-01,  1.554511865335202e-02,  
 -8.305330238628740e-01,  8.626294758901784e-01,  9.402009758617824e-03,  
 -8.294785607894918e-01,  9.967444014424583e-01,  1.208238555914957e-03,  
 -8.257889703732273e-01,  7.178314536082597e-02,  1.768899055141865e-02,  
 -8.110197774934704e-01,  6.807113046668994e-01,  1.523540797814434e-02,  
 -8.029840820822153e-01,  4.688347153306865e-01,  1.679016485272365e-02,  
 -7.832130052321671e-01,  2.499268458076058e-01,  1.971664557932711e-02,  
 -7.801221870591962e-01, -5.296331251016586e-01,  3.661339198539565e-03,  
 -7.680489268476366e-01, -3.239665253282490e-01,  2.029577519777635e-02,  
 -7.568982042081489e-01, -6.469903320156577e-02,  1.929849800043277e-02,  
 -7.519799147310821e-01, -9.820165683081348e-01,  4.279421611368336e-03,  
 -7.503688437977389e-01, -9.065793653546036e-01,  1.014558607042340e-02,  
 -7.503013634605583e-01,  9.802360242338881e-01,  4.439623982463855e-03,  
 -7.497536820115352e-01, -5.698053761201402e-01,  1.779839962659180e-02,  
 -7.446422046307247e-01,  9.102156841025124e-01,  9.086171802680322e-03,  
 -7.445500034233367e-01,  7.848047539654122e-01,  1.480460601233261e-02,  
 -7.420314577338432e-01, -7.669296945893275e-01,  1.649262306205733e-02,  
 -7.232254143511531e-01,  5.713056680823388e-01,  2.016548810406117e-02,  
 -7.062208864591450e-01,  9.503977235942600e-02,  1.928783830209237e-02,  
 -7.031430448656599e-01,  3.539369545569842e-01,  2.086333365650514e-02,  
 -6.910760386360507e-01, -2.202589299389135e-01,  1.824693519009817e-02,  
 -6.711541165821081e-01, -4.470179997221566e-01,  1.982448992952755e-02,  
 -6.531718048226814e-01,  9.967997404348319e-01,  1.851797920829879e-03,  
 -6.510982873867898e-01, -9.494836825061095e-01,  8.282094698086110e-03,  
 -6.495359763175098e-01, -9.967203887198085e-01,  1.840591604616235e-03,  
 -6.473927602298331e-01,  6.932779937556659e-01,  1.958957103753717e-02,  
 -6.464452229923815e-01,  8.552721751249167e-01,  1.167683626501659e-02,  
 -6.459328707826928e-01, -6.630485503781940e-01,  2.204591732276851e-02,  
 -6.422957416183844e-01,  9.498995336148190e-01,  8.184904472780722e-03,  
 -6.411208000593052e-01, -8.428969978933917e-01,  1.568169438177813e-02,  
 -6.376753802962584e-01, -7.106433457042012e-02,  1.835262838211505e-02,  
 -6.277916196017650e-01,  1.869178545078614e-01,  2.243995725960829e-02,  
 -6.151521573306764e-01,  4.575647790357444e-01,  2.332139121086357e-02,  
 -6.110490337662942e-01, -3.716909293029730e-01,  1.353424810977647e-02,  
 -5.789585639318591e-01,  8.116111501687501e-01,  8.239538289259576e-03,  
 -5.719445376985364e-01, -2.076230901972163e-01,  1.980619800036562e-02,  
 -5.503010082245448e-01, -5.351187300277593e-01,  2.203583241136872e-02,  
 -5.448020739951114e-01,  5.943977618827134e-01,  2.119679939093152e-02,  
 -5.405717934730448e-01,  2.398766500666945e-02,  2.753053261097250e-02,  
 -5.379183131495114e-01, -9.794968398169707e-01,  5.852700601431832e-03,  
 -5.351808255772759e-01,  9.807921885374170e-01,  5.695018653828906e-03,  
 -5.307318203931908e-01, -7.548959411509537e-01,  2.161368448540176e-02,  
 -5.295874335958505e-01,  2.972675778301046e-01,  2.831405936915660e-02,  
 -5.286141781682451e-01, -9.043560824552355e-01,  1.301083261420718e-02,  
 -5.174239052084288e-01,  9.052729023030037e-01,  1.310577146977484e-02,  
 -5.002001743362517e-01,  7.536126162564385e-01,  1.877702249835676e-02,  
 -4.949149883106970e-01, -3.239151523715213e-01,  2.413732904338590e-02,  
 -4.926819371575777e-01, -5.863264530268616e-01,  9.252700572850187e-03,  
 -4.572955824770646e-01,  5.174797928661199e-01,  1.280901341961230e-02,  
 -4.330661622416971e-01, -1.162896573168444e-01,  3.094672746065751e-02,  
 -4.265146037440953e-01,  1.431197872276920e-01,  3.097439241585212e-02,  
 -4.261542183676564e-01,  4.217014688490645e-01,  2.299426219446216e-02,  
 -4.260965440692615e-01, -9.965783521197458e-01,  2.184951478119829e-03,  
 -4.195965641842235e-01,  9.968712678138757e-01,  2.102981801155398e-03,  
 -4.122399178795176e-01, -4.475194975775657e-01,  1.989673839306039e-02,  
 -4.105366827946999e-01, -8.373589753274594e-01,  1.841138617779475e-02,  
 -4.018650475100398e-01, -6.569857706362335e-01,  2.531099347585827e-02,  
 -4.011312302189050e-01, -9.485309748736876e-01,  1.036126977964170e-02,  
 -3.965687446957954e-01,  9.512021797025086e-01,  1.007429601084097e-02,  
 -3.886867567687322e-01,  8.415221322242826e-01,  1.867865037165336e-02,  
 -3.863072449479136e-01,  6.585305620664139e-01,  2.494229959731991e-02,  
 -3.558089768700468e-01, -4.173145393898551e-01,  1.256145253990760e-02,  
 -3.361006797113043e-01, -2.320489871510133e-01,  2.411745034362549e-02,  
 -3.273064092637250e-01,  2.552981701918742e-01,  1.731337482356964e-02,  
 -3.143235654002606e-01,  3.434855626045295e-01,  1.768325686985408e-02,  
 -2.969988871235867e-01,  1.512212631139971e-02,  3.451049222856652e-02,  
 -2.851682496889180e-01, -9.823368483892302e-01,  6.076427259472100e-03,  
 -2.842287026196041e-01, -7.573701654746426e-01,  2.254851231334031e-02,  
 -2.763872051458339e-01,  9.848430016399402e-01,  4.391195859850334e-03,  
 -2.757570191887748e-01,  5.328644045211444e-01,  3.039500110542442e-02,  
 -2.689789570111630e-01, -8.976396396474979e-01,  1.589379778474137e-02,  
 -2.666695494019358e-01, -5.458482771574984e-01,  3.009909572762831e-02,  
 -2.655053034213333e-01,  9.771787699513292e-01,  1.894385891729340e-03,  
 -2.627557017089030e-01,  7.555588777373272e-01,  2.363679764618126e-02,  
 -2.562363324756580e-01,  9.047634768272976e-01,  1.523993759370399e-02,  
 -2.401694466154886e-01, -3.082397101256352e-01,  2.545591145933639e-02,  
 -1.999384860986652e-01,  1.995960452917006e-01,  2.644981232826374e-02,  
 -1.934165548136490e-01, -1.001228826623429e-01,  2.353802509227792e-02,  
 -1.605338025079172e-01, -9.977634540883650e-01,  1.896784969760382e-03,  
 -1.596836572730810e-01,  3.941151625223360e-01,  3.004459538308863e-02,  
 -1.582769934825167e-01, -6.689987456876101e-01,  2.405213561825666e-02,  
 -1.454325940338082e-01, -9.514097712610464e-01,  1.102950511878142e-02,  
 -1.436551253873852e-01,  6.453308106984021e-01,  2.877227939270967e-02,  
 -1.364207441182524e-01,  9.973928878261128e-01,  2.062325710829592e-03,  
 -1.323616733693008e-01, -8.292521434719048e-01,  2.101390827968778e-02,  
 -1.284662135957239e-01, -4.199690393178734e-01,  3.292903599927027e-02,  
 -1.272488031447826e-01,  8.354138942117858e-01,  2.022653122178670e-02,  
 -1.242239684265682e-01,  9.539196646941631e-01,  1.076287752752471e-02,  
 -1.099650016306503e-01,  1.001181481554234e-01,  2.776239604781384e-02,  
 -1.058473836439364e-01, -1.676489858375358e-01,  2.632360797858480e-02,  
 -4.887769924515067e-02,  4.984873757664716e-01,  2.452379021441048e-02,  
 -4.878511560715085e-02, -5.810857563657668e-01,  2.200867989097806e-02,  
 -1.487759494787105e-02, -9.841897690617597e-01,  6.148525047866293e-03,  
 -9.715667325046100e-03,  2.841665712486741e-01,  3.560311127234845e-02,  
 -7.133604297269260e-03, -9.026737353005819e-01,  1.596380767648381e-02,  
 -5.357202966277515e-03,  7.436791749793509e-01,  2.516341018429965e-02,  
 0.000000000000000e+00,  0.000000000000000e+00,  3.080626042474933e-02,  
 5.357202966277515e-03, -7.436791749793509e-01,  2.516341018429965e-02,  
 7.133604297269260e-03,  9.026737353005819e-01,  1.596380767648381e-02,  
 9.715667325046100e-03, -2.841665712486741e-01,  3.560311127234845e-02,  
 1.487759494787105e-02,  9.841897690617597e-01,  6.148525047866293e-03,  
 4.878511560715085e-02,  5.810857563657668e-01,  2.200867989097806e-02,  
 4.887769924515067e-02, -4.984873757664716e-01,  2.452379021441048e-02,  
 1.058473836439364e-01,  1.676489858375358e-01,  2.632360797858480e-02,  
 1.099650016306503e-01, -1.001181481554234e-01,  2.776239604781384e-02,  
 1.242239684265682e-01, -9.539196646941631e-01,  1.076287752752471e-02,  
 1.272488031447826e-01, -8.354138942117858e-01,  2.022653122178670e-02,  
 1.284662135957239e-01,  4.199690393178734e-01,  3.292903599927027e-02,  
 1.323616733693008e-01,  8.292521434719048e-01,  2.101390827968778e-02,  
 1.364207441182524e-01, -9.973928878261128e-01,  2.062325710829592e-03,  
 1.436551253873852e-01, -6.453308106984021e-01,  2.877227939270967e-02,  
 1.454325940338082e-01,  9.514097712610464e-01,  1.102950511878142e-02,  
 1.582769934825167e-01,  6.689987456876101e-01,  2.405213561825666e-02,  
 1.596836572730810e-01, -3.941151625223360e-01,  3.004459538308863e-02,  
 1.605338025079172e-01,  9.977634540883650e-01,  1.896784969760382e-03,  
 1.934165548136490e-01,  1.001228826623429e-01,  2.353802509227792e-02,  
 1.999384860986652e-01, -1.995960452917006e-01,  2.644981232826374e-02,  
 2.401694466154886e-01,  3.082397101256352e-01,  2.545591145933639e-02,  
 2.562363324756580e-01, -9.047634768272976e-01,  1.523993759370399e-02,  
 2.627557017089030e-01, -7.555588777373272e-01,  2.363679764618126e-02,  
 2.655053034213333e-01, -9.771787699513292e-01,  1.894385891729340e-03,  
 2.666695494019358e-01,  5.458482771574984e-01,  3.009909572762831e-02,  
 2.689789570111630e-01,  8.976396396474979e-01,  1.589379778474137e-02,  
 2.757570191887748e-01, -5.328644045211444e-01,  3.039500110542442e-02,  
 2.763872051458339e-01, -9.848430016399402e-01,  4.391195859850334e-03,  
 2.842287026196041e-01,  7.573701654746426e-01,  2.254851231334031e-02,  
 2.851682496889180e-01,  9.823368483892302e-01,  6.076427259472100e-03,  
 2.969988871235867e-01, -1.512212631139971e-02,  3.451049222856652e-02,  
 3.143235654002606e-01, -3.434855626045295e-01,  1.768325686985408e-02,  
 3.273064092637250e-01, -2.552981701918742e-01,  1.731337482356964e-02,  
 3.361006797113043e-01,  2.320489871510133e-01,  2.411745034362549e-02,  
 3.558089768700468e-01,  4.173145393898551e-01,  1.256145253990760e-02,  
 3.863072449479136e-01, -6.585305620664139e-01,  2.494229959731991e-02,  
 3.886867567687322e-01, -8.415221322242826e-01,  1.867865037165336e-02,  
 3.965687446957954e-01, -9.512021797025086e-01,  1.007429601084097e-02,  
 4.011312302189050e-01,  9.485309748736876e-01,  1.036126977964170e-02,  
 4.018650475100398e-01,  6.569857706362335e-01,  2.531099347585827e-02,  
 4.105366827946999e-01,  8.373589753274594e-01,  1.841138617779475e-02,  
 4.122399178795176e-01,  4.475194975775657e-01,  1.989673839306039e-02,  
 4.195965641842235e-01, -9.968712678138757e-01,  2.102981801155398e-03,  
 4.260965440692615e-01,  9.965783521197458e-01,  2.184951478119829e-03,  
 4.261542183676564e-01, -4.217014688490645e-01,  2.299426219446216e-02,  
 4.265146037440953e-01, -1.431197872276920e-01,  3.097439241585212e-02,  
 4.330661622416971e-01,  1.162896573168444e-01,  3.094672746065751e-02,  
 4.572955824770646e-01, -5.174797928661199e-01,  1.280901341961230e-02,  
 4.926819371575777e-01,  5.863264530268616e-01,  9.252700572850187e-03,  
 4.949149883106970e-01,  3.239151523715213e-01,  2.413732904338590e-02,  
 5.002001743362517e-01, -7.536126162564385e-01,  1.877702249835676e-02,  
 5.174239052084288e-01, -9.052729023030037e-01,  1.310577146977484e-02,  
 5.286141781682451e-01,  9.043560824552355e-01,  1.301083261420718e-02,  
 5.295874335958505e-01, -2.972675778301046e-01,  2.831405936915660e-02,  
 5.307318203931908e-01,  7.548959411509537e-01,  2.161368448540176e-02,  
 5.351808255772759e-01, -9.807921885374170e-01,  5.695018653828906e-03,  
 5.379183131495114e-01,  9.794968398169707e-01,  5.852700601431832e-03,  
 5.405717934730448e-01, -2.398766500666945e-02,  2.753053261097250e-02,  
 5.448020739951114e-01, -5.943977618827134e-01,  2.119679939093152e-02,  
 5.503010082245448e-01,  5.351187300277593e-01,  2.203583241136872e-02,  
 5.719445376985364e-01,  2.076230901972163e-01,  1.980619800036562e-02,  
 5.789585639318591e-01, -8.116111501687501e-01,  8.239538289259576e-03,  
 6.110490337662942e-01,  3.716909293029730e-01,  1.353424810977647e-02,  
 6.151521573306764e-01, -4.575647790357444e-01,  2.332139121086357e-02,  
 6.277916196017650e-01, -1.869178545078614e-01,  2.243995725960829e-02,  
 6.376753802962584e-01,  7.106433457042012e-02,  1.835262838211505e-02,  
 6.411208000593052e-01,  8.428969978933917e-01,  1.568169438177813e-02,  
 6.422957416183844e-01, -9.498995336148190e-01,  8.184904472780722e-03,  
 6.459328707826928e-01,  6.630485503781940e-01,  2.204591732276851e-02,  
 6.464452229923815e-01, -8.552721751249167e-01,  1.167683626501659e-02,  
 6.473927602298331e-01, -6.932779937556659e-01,  1.958957103753717e-02,  
 6.495359763175098e-01,  9.967203887198085e-01,  1.840591604616235e-03,  
 6.510982873867898e-01,  9.494836825061095e-01,  8.282094698086110e-03,  
 6.531718048226814e-01, -9.967997404348319e-01,  1.851797920829879e-03,  
 6.711541165821081e-01,  4.470179997221566e-01,  1.982448992952755e-02,  
 6.910760386360507e-01,  2.202589299389135e-01,  1.824693519009817e-02,  
 7.031430448656599e-01, -3.539369545569842e-01,  2.086333365650514e-02,  
 7.062208864591450e-01, -9.503977235942600e-02,  1.928783830209237e-02,  
 7.232254143511531e-01, -5.713056680823388e-01,  2.016548810406117e-02,  
 7.420314577338432e-01,  7.669296945893275e-01,  1.649262306205733e-02,  
 7.445500034233367e-01, -7.848047539654122e-01,  1.480460601233261e-02,  
 7.446422046307247e-01, -9.102156841025124e-01,  9.086171802680322e-03,  
 7.497536820115352e-01,  5.698053761201402e-01,  1.779839962659180e-02,  
 7.503013634605583e-01, -9.802360242338881e-01,  4.439623982463855e-03,  
 7.503688437977389e-01,  9.065793653546036e-01,  1.014558607042340e-02,  
 7.519799147310821e-01,  9.820165683081348e-01,  4.279421611368336e-03,  
 7.568982042081489e-01,  6.469903320156577e-02,  1.929849800043277e-02,  
 7.680489268476366e-01,  3.239665253282490e-01,  2.029577519777635e-02,  
 7.801221870591962e-01,  5.296331251016586e-01,  3.661339198539565e-03,  
 7.832130052321671e-01, -2.499268458076058e-01,  1.971664557932711e-02,  
 8.029840820822153e-01, -4.688347153306865e-01,  1.679016485272365e-02,  
 8.110197774934704e-01, -6.807113046668994e-01,  1.523540797814434e-02,  
 8.257889703732273e-01, -7.178314536082597e-02,  1.768899055141865e-02,  
 8.294785607894918e-01, -9.967444014424583e-01,  1.208238555914957e-03,  
 8.305330238628740e-01, -8.626294758901784e-01,  9.402009758617824e-03,  
 8.316813659365053e-01,  6.810571166632299e-01,  1.554511865335202e-02,  
 8.318210977517786e-01,  8.478689190545843e-01,  1.077737568013724e-02,  
 8.351166757877715e-01,  9.976562452857387e-01,  1.078286714786108e-03,  
 8.378454530446884e-01, -9.530099558379057e-01,  5.399408829933249e-03,  
 8.396784302276527e-01,  1.756139328191055e-01,  1.921157782857880e-02,  
 8.400990403804555e-01,  9.553728108586558e-01,  5.756357460449216e-03,  
 8.409266136580046e-01,  4.471234082886604e-01,  1.725729695008926e-02,  
 8.655996427765849e-01, -3.758701133077118e-01,  1.356217699235571e-02,  
 8.779133156049225e-01, -5.858583967917332e-01,  1.273340964065398e-02,  
 8.799510611339678e-01, -7.804272229598096e-01,  9.800822621659112e-03,  
 8.862410073156858e-01, -2.023135190038032e-01,  1.419438960724134e-02,  
 8.995512373198538e-01,  5.752687860358924e-01,  1.333914316671023e-02,  
 9.009350039678510e-01,  7.782630377583909e-01,  1.005814342536296e-02,  
 9.018609313605185e-01,  3.168234272327462e-02,  1.540631304873537e-02,  
 9.023191697919575e-01, -9.860953439377561e-01,  2.287777730391639e-03,  
 9.023427661156972e-01,  3.102537604841927e-01,  1.518789863772203e-02,  
 9.035282359913408e-01,  9.127575798900944e-01,  6.195061068875661e-03,  
 9.045872993270916e-01, -9.244231244080491e-01,  4.633234288837451e-03,  
 9.095843629981852e-01,  9.870451124979706e-01,  2.291616065068371e-03,  
 9.280108673251274e-01, -4.983380051452493e-01,  9.333950017742142e-03,  
 9.300699834315862e-01, -7.014618847802435e-01,  8.344725482478233e-03,  
 9.306103944301639e-01, -8.662316655121048e-01,  5.280103565555265e-03,  
 9.376659862954376e-01, -3.320927786395850e-01,  9.853104948952236e-03,  
 9.481698863829746e-01,  4.482511579023943e-01,  1.058846772781884e-02,  
 9.483377728448769e-01, -1.079182983808205e-01,  9.649772007405522e-03,  
 9.486279733146294e-01,  6.865588686606500e-01,  8.287308334158514e-03,  
 9.501218449448332e-01,  1.679843056344594e-01,  1.129203236633850e-02,  
 9.511137028620014e-01, -1.537123214377626e-01,  1.548656739539656e-03,  
 9.529627107888853e-01,  8.594308951734482e-01,  5.521466103754615e-03,  
 9.541283709855817e-01,  9.615200131743211e-01,  2.770123594982525e-03,  
 9.551655794629224e-01, -9.662000026762417e-01,  2.519263815744828e-03,  
 9.574847616595294e-01, -9.991852307452070e-01,  4.156752677850517e-04,  
 9.667526686680565e-01, -8.023493190515092e-01,  5.052013954468514e-03,  
 9.675664657866050e-01, -6.206279941904160e-01,  6.157178279661575e-03,  
 9.733634369985799e-01,  9.966978125597651e-01,  6.175342802324851e-04,  
 9.758317798625764e-01, -4.558745215283740e-01,  5.758484945330961e-03,  
 9.767561034338471e-01, -9.143771666367756e-01,  2.776979717116026e-03,  
 9.791585763360798e-01,  5.756466500202441e-01,  5.476389537369480e-03,  
 9.803016487147558e-01, -2.539985793768113e-01,  6.144467944923415e-03,  
 9.808975723862894e-01,  3.112518230537506e-01,  6.733976982472782e-03,  
 9.818366925634343e-01,  2.156090420260150e-02,  6.852107137072102e-03,  
 9.820959231331791e-01,  7.821855489421354e-01,  4.084862972791807e-03,  
 9.850276191493494e-01,  9.248683981506678e-01,  2.259102932718402e-03,  
 9.897982334464747e-01, -9.889847320679855e-01,  6.578382364688170e-04,  
 9.918341858607898e-01, -7.250215468408083e-01,  2.925047225366992e-03,  
 9.929582393871068e-01,  5.370347553708347e-01,  6.365700160628349e-04,  
 9.954861320163209e-01, -5.681416527913361e-01,  2.181094091195068e-03,  
 9.955121819465780e-01,  9.789979211029449e-01,  6.407210056305082e-04,  
 9.955131940127476e-01, -8.558413309721239e-01,  1.466862509992409e-03,  
 9.961989059670616e-01, -9.525971037206539e-01,  6.660472520224310e-04,  
 9.965848495106024e-01,  6.842725498070605e-01,  1.783337849517576e-03,  
 9.966030911672050e-01,  4.414700559329136e-01,  2.103309187930437e-03,  
 9.967543799903597e-01, -3.758322880625192e-01,  1.965952058779777e-03,  
 9.968865665492763e-01, -1.264946845449128e-01,  2.336585497171821e-03,  
 9.972233023651127e-01,  1.689643304774283e-01,  2.334603070096216e-03,  
 9.979788599279722e-01,  8.620321171404657e-01,  9.843080418879427e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr42 ( )

/******************************************************************************/
/*
  Purpose:

    SMR42 returns the SMR rule of degree 42.

  Discussion:
 
    DEGREE: 42
    POINTS CARDINALITY: 326
    NORM INF MOMS. RESIDUAL: 8.67145e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR42[3*326], the requested rule.
*/
{
  const int degree = 42;
  int order;
  double xw[3*326] = {
 -9.983895853811665e-01,  2.969737627802563e-01,  1.238150356046483e-03,  
 -9.977615781174913e-01, -7.709519815994472e-01,  1.081616267165998e-03,  
 -9.975604363093720e-01,  5.337316075161648e-01,  1.249737376093271e-03,  
 -9.975457919908404e-01,  9.770830229535153e-01,  4.470299430512570e-04,  
 -9.969809246965443e-01, -2.451005993701799e-01,  2.074243379361551e-03,  
 -9.968120260128331e-01,  8.514136675024221e-01,  1.167341137105932e-03,  
 -9.966778899972677e-01, -9.176221669397234e-01,  8.041981836080290e-04,  
 -9.964245708711565e-01, -4.889240550109979e-01,  2.074108808482804e-03,  
 -9.960265424615615e-01, -3.206262163873343e-03,  2.541774019152315e-03,  
 -9.957193536867802e-01,  6.973486149261381e-01,  1.833470374408153e-03,  
 -9.954906184608173e-01, -9.834651303414434e-01,  4.837448015994170e-04,  
 -9.923170394980639e-01, -6.488504511621852e-01,  2.300838549325460e-03,  
 -9.894941295318366e-01,  1.816206171244922e-01,  3.686717692046918e-03,  
 -9.874887743325775e-01, -8.588958391844354e-01,  1.934675349668603e-03,  
 -9.873676197128440e-01,  4.258048442933274e-01,  3.995262993123166e-03,  
 -9.872315968340971e-01,  9.256499485066579e-01,  2.010548420182620e-03,  
 -9.817076131502388e-01, -3.607331662659895e-01,  5.403841252241704e-03,  
 -9.810397049156565e-01,  9.959675054022549e-01,  5.131550081223118e-04,  
 -9.788010746558530e-01,  7.823002392178441e-01,  4.112245929337191e-03,  
 -9.779826267946542e-01, -1.280907393842539e-01,  6.825619620264833e-03,  
 -9.778857566817490e-01, -7.070297596348967e-01,  2.333933933327752e-03,  
 -9.770873279965435e-01,  5.991400956941817e-01,  5.320539361361202e-03,  
 -9.765278890669798e-01, -9.531509988501621e-01,  2.086667535123516e-03,  
 -9.761966529808779e-01, -9.980243997428009e-01,  3.926872153298788e-04,  
 -9.726562997502463e-01, -5.585474334620195e-01,  4.784629701022005e-03,  
 -9.726043123727997e-01, -8.113170875896518e-01,  2.635483305155019e-03,  
 -9.682147583093088e-01,  8.904719493506889e-02,  6.698723958291691e-03,  
 -9.634445582523827e-01,  3.139599897908095e-01,  7.954619210267289e-03,  
 -9.610169069361439e-01,  9.666011711506927e-01,  2.268817275848690e-03,  
 -9.551948115536512e-01,  8.710650846109909e-01,  4.964920743527174e-03,  
 -9.505460777198159e-01, -4.343062948294107e-01,  6.106499989272643e-03,  
 -9.482223349262576e-01, -7.448087682906291e-01,  5.255811938574469e-03,  
 -9.479658383534716e-01, -8.987701284133403e-01,  4.635769935190221e-03,  
 -9.436143895358713e-01,  6.959041714345351e-01,  7.863254576614227e-03,  
 -9.436039683315387e-01, -6.104452737087587e-01,  4.434535145882001e-03,  
 -9.433758303285367e-01,  4.906689218494150e-01,  9.429821854040199e-03,  
 -9.423237187354413e-01, -2.467823489744650e-01,  1.076584727710253e-02,  
 -9.391182625762966e-01, -9.826638214851392e-01,  2.109364556787303e-03,  
 -9.350615084246884e-01, -1.659457024937119e-02,  1.048767996389870e-02,  
 -9.217645802840572e-01,  9.907869871400011e-01,  1.616360403829918e-03,  
 -9.215474836204731e-01,  2.043715053498819e-01,  1.216781578897710e-02,  
 -9.126031690605523e-01,  9.291576693756454e-01,  5.032494622473610e-03,  
 -9.108376159034378e-01, -4.897424808873326e-01,  8.527008883353277e-03,  
 -9.064530353685755e-01,  7.992951966595492e-01,  8.733726687076370e-03,  
 -9.056607152087032e-01, -8.272477088723909e-01,  7.878562829643663e-03,  
 -9.044219288728528e-01, -6.636706870428218e-01,  8.309150810743564e-03,  
 -8.947784500749467e-01, -9.451248056062111e-01,  4.977957482614220e-03,  
 -8.942957719772126e-01,  3.854833600681813e-01,  1.263526180235866e-02,  
 -8.914509500717330e-01,  5.988572449686976e-01,  1.236911144033898e-02,  
 -8.852322112438892e-01, -1.236708436669904e-01,  1.426043676836211e-02,  
 -8.841579338925228e-01, -3.412926369849601e-01,  1.325394767927102e-02,  
 -8.801771943577119e-01, -9.966091035909469e-01,  1.109347862822931e-03,  
 -8.662960901298091e-01,  8.948961991555911e-02,  1.538814023759737e-02,  
 -8.547901173562468e-01,  9.685970327546581e-01,  4.221229608246627e-03,  
 -8.513281464403821e-01,  9.987701957017139e-01,  6.276947609934688e-04,  
 -8.493965412767819e-01,  8.750994636081615e-01,  8.702080207924946e-03,  
 -8.486190442117658e-01, -5.636240679874738e-01,  1.285521591384748e-02,  
 -8.463705738558919e-01, -7.448243067394232e-01,  1.130500524300540e-02,  
 -8.405308044871470e-01,  3.043148488295061e-01,  1.046140819688675e-02,  
 -8.398358181977051e-01,  7.161435779598875e-01,  1.314151256378980e-02,  
 -8.383653549203041e-01, -8.878539286502376e-01,  8.430171578574307e-03,  
 -8.210741123697933e-01, -9.766488081068017e-01,  4.098354002811169e-03,  
 -8.208707647886223e-01,  4.974203597708007e-01,  1.710985289131320e-02,  
 -8.146158417958415e-01, -2.198432016525242e-01,  1.701739186308798e-02,  
 -8.118659561962476e-01,  2.211043698771638e-01,  8.434215380175943e-03,  
 -8.109301081611654e-01, -4.211295967806792e-01,  1.412782056675765e-02,  
 -8.011290535296839e-01, -1.248581495063462e-02,  1.560092136756764e-02,  
 -7.735252515593568e-01,  9.309650034206048e-01,  7.961026263346178e-03,  
 -7.716408539520909e-01,  9.890328536125180e-01,  2.627819279756719e-03,  
 -7.713122237357826e-01, -6.510284878473606e-01,  1.538601522963826e-02,  
 -7.707190051131479e-01,  2.324471573934027e-01,  9.036405673615943e-03,  
 -7.702424235973540e-01,  8.084384767368644e-01,  1.275881172676499e-02,  
 -7.669148226628323e-01, -8.144012723914440e-01,  1.203610936905808e-02,  
 -7.563615651755403e-01, -9.344574350143551e-01,  7.162428695194032e-03,  
 -7.549356580691885e-01,  6.261159426797993e-01,  1.790785421685001e-02,  
 -7.388091269205519e-01, -9.953991842940237e-01,  1.935302554193668e-03,  
 -7.378692050124985e-01, -8.521050209128646e-02,  1.377372412683884e-02,  
 -7.377023207292610e-01, -4.941261650174635e-01,  1.380544592194696e-02,  
 -7.331931178475477e-01,  3.913893482110728e-01,  2.143967325273679e-02,  
 -7.270864834829239e-01,  1.139187591845308e-01,  1.516896982460334e-02,  
 -7.267695434410246e-01, -3.082489183913576e-01,  1.881115737108218e-02,  
 -6.899885699483223e-01, -8.821573559917478e-01,  4.925947047330577e-03,  
 -6.813723030880324e-01,  9.984161114829040e-01,  7.885438697656719e-04,  
 -6.794320916451463e-01,  8.785358277598266e-01,  1.205922032830251e-02,  
 -6.784703765570435e-01, -7.297133387630516e-01,  1.598916748258378e-02,  
 -6.776012969063153e-01,  1.391839047743928e-01,  9.832835902747970e-03,  
 -6.764723618609201e-01,  9.685324267578785e-01,  5.859512706387141e-03,  
 -6.738460375138086e-01, -9.651002679024745e-01,  4.767009187250398e-03,  
 -6.737243836937874e-01,  7.342773798093677e-01,  1.709899970138294e-02,  
 -6.644539826425694e-01, -5.635537416067942e-01,  1.564317167183973e-02,  
 -6.634751213533232e-01, -1.604215873631951e-01,  1.935734255198524e-02,  
 -6.619502670840386e-01, -8.649428894817014e-01,  7.118057258260406e-03,  
 -6.549827012606614e-01,  5.282752967927656e-01,  2.240760255327129e-02,  
 -6.306600511355206e-01, -3.919448791059551e-01,  1.900513660573725e-02,  
 -6.297817200305971e-01,  2.823803712729075e-01,  2.502986526281338e-02,  
 -6.216953173007335e-01,  5.643843021717805e-03,  1.796402412073861e-02,  
 -6.140165745664186e-01, -9.859418938622825e-01,  3.212423164931555e-03,  
 -5.771270411761599e-01, -9.215133237530594e-01,  9.668925716545904e-03,  
 -5.748435613862279e-01,  9.327577622499963e-01,  9.757429923397945e-03,  
 -5.737485473796465e-01, -7.972486291015727e-01,  1.508656680428934e-02,  
 -5.718887760630267e-01, -6.370333746969838e-01,  1.848456636165576e-02,  
 -5.707074067500586e-01,  9.922102608817531e-01,  2.881990914702140e-03,  
 -5.688961239076191e-01,  3.298702902382509e-02,  1.047465657364413e-02,  
 -5.675251115967979e-01,  8.169896013111752e-01,  1.640586553806266e-02,  
 -5.655659214306783e-01,  6.509750976080372e-01,  2.125680475231248e-02,  
 -5.571510587648792e-01, -2.467810374030457e-01,  2.398602658758524e-02,  
 -5.507102005306738e-01, -4.616455796605000e-01,  1.436780242522091e-02,  
 -5.419415518233097e-01,  4.248295257169304e-01,  2.626823745716256e-02,  
 -5.218547423997800e-01, -9.976415918771692e-01,  1.583196126084757e-03,  
 -5.149992864069691e-01, -9.423558398261378e-02,  1.076036322418040e-02,  
 -5.132180036238988e-01,  1.711550456896960e-01,  2.785354108817730e-02,  
 -4.829210648831740e-01, -9.616162988487118e-01,  7.469943358099489e-03,  
 -4.688160566868244e-01, -8.611456662935529e-01,  1.398190185303191e-02,  
 -4.677745958608924e-01, -5.249766577809418e-01,  2.002854227312364e-02,  
 -4.669496773079832e-01,  9.726887728674144e-01,  6.450395357727730e-03,  
 -4.658245441037069e-01, -8.858372256137174e-02,  1.784446157965224e-02,  
 -4.628895760753138e-01, -7.133269525288682e-01,  1.912050315315815e-02,  
 -4.535449668032904e-01,  8.866031212139555e-01,  1.401926812957357e-02,  
 -4.478788754500803e-01,  5.600753093630753e-01,  2.492544822075299e-02,  
 -4.457854778948153e-01,  7.446400102911364e-01,  2.064381447286162e-02,  
 -4.369470824412445e-01, -3.431724701283002e-01,  2.658713998880457e-02,  
 -4.185328241266283e-01,  3.170545750718476e-01,  2.922560369899428e-02,  
 -3.890877209652377e-01,  9.971081288565442e-01,  1.796661084966019e-03,  
 -3.864446656766595e-01,  5.863091742160163e-02,  3.003146041596166e-02,  
 -3.831955458377362e-01, -1.740817521363409e-01,  1.214811438718327e-02,  
 -3.735932973145009e-01, -9.868758698413692e-01,  4.788684591089814e-03,  
 -3.613111294101750e-01, -9.165044324691506e-01,  1.212237717515227e-02,  
 -3.538765488045220e-01, -6.105807051018285e-01,  2.342111343448623e-02,  
 -3.470851761320838e-01, -7.893958214407354e-01,  1.847852212603510e-02,  
 -3.391198332478134e-01,  9.420920789488475e-01,  1.053753340465246e-02,  
 -3.259626426410726e-01, -2.132438198328835e-01,  2.050933783996452e-02,  
 -3.225863338681545e-01,  4.621171913143386e-01,  2.803762474902662e-02,  
 -3.223116544172475e-01,  8.281765786009968e-01,  1.845884999832045e-02,  
 -3.181331758231921e-01,  6.624003884340418e-01,  2.410899398588486e-02,  
 -3.097545730889024e-01, -4.424649187010514e-01,  2.680988640221558e-02,  
 -2.884650031184056e-01,  9.884147622938702e-01,  2.472347723619564e-03,  
 -2.873088695274083e-01,  2.062472424818550e-01,  3.118760247446968e-02,  
 -2.512791493091187e-01, -5.135873454190604e-02,  3.099744003973420e-02,  
 -2.423641370999858e-01, -9.577710745485877e-01,  9.265732928547869e-03,  
 -2.328824316631447e-01, -9.978364337209883e-01,  1.779978256713267e-03,  
 -2.263780767365199e-01, -7.000400004124890e-01,  2.322442438266213e-02,  
 -2.263399639641023e-01, -8.582209349267874e-01,  1.680208369151338e-02,  
 -2.087812004974775e-01,  9.770858608961845e-01,  5.302771699443291e-03,  
 -2.083614303693334e-01, -3.073111903430377e-01,  2.784736930013426e-02,  
 -1.999283175075603e-01,  8.989837030255559e-01,  1.499199948128067e-02,  
 -1.909845816734380e-01,  3.575369873843971e-01,  3.046703330507673e-02,  
 -1.884716472361604e-01,  5.724569389790787e-01,  2.632448749251792e-02,  
 -1.869410921110642e-01,  7.565028038405339e-01,  2.233491028950177e-02,  
 -1.843841115545689e-01, -5.395615455530922e-01,  2.494019997742770e-02,  
 -1.498332978393480e-01,  9.424107635111555e-02,  3.190590627327158e-02,  
 -1.195770040560849e-01,  9.976785699720651e-01,  1.708610445747687e-03,  
 -1.128810472678152e-01, -1.621115180942063e-01,  3.095358985546368e-02,  
 -1.020657000747672e-01, -9.827964093930615e-01,  5.862490005379920e-03,  
 -9.932663283884499e-02, -9.143596686063581e-01,  1.369553699475923e-02,  
 -9.274767285187367e-02, -7.822730372488192e-01,  2.164311512564077e-02,  
 -8.103825378906829e-02, -4.096519478108676e-01,  2.759310160331856e-02,  
 -7.489973868725409e-02,  9.518169186995218e-01,  1.035496878834830e-02,  
 -6.335698901293590e-02, -6.250608749966023e-01,  2.255920523045297e-02,  
 -6.166904446316302e-02,  4.784389475960453e-01,  2.676383008544048e-02,  
 -5.970836208331559e-02,  8.405649967632023e-01,  1.908548342904795e-02,  
 -5.501382393331618e-02,  2.467531511014508e-01,  3.173197137193996e-02,  
 -5.061788078599418e-02,  6.732401322495646e-01,  2.516076352162443e-02,  
 -1.015615433395733e-02, -2.055972514442930e-02,  3.182295725284823e-02,  
 9.042710639563842e-03,  9.901284880011576e-01,  3.036532554395697e-03,  
 2.455819938982937e-02, -2.746511791380577e-01,  3.058344887912262e-02,  
 3.009510952559026e-02, -9.957979450703934e-01,  2.230092699402469e-03,  
 4.161126623700789e-02, -8.541692940023290e-01,  1.832620914421112e-02,  
 4.315071485893791e-02, -9.531546367603930e-01,  1.004404501682993e-02,  
 4.980781610591364e-02, -5.055026057272577e-01,  2.695393126406910e-02,  
 5.614259373801662e-02,  3.839891266510965e-01,  2.555881058966561e-02,  
 5.653066870778246e-02, -7.009049065775056e-01,  2.162651797501659e-02,  
 6.431492052043117e-02,  9.094943484367410e-01,  1.442924487724422e-02,  
 7.954502210454595e-02,  7.677175431668712e-01,  2.242255949995469e-02,  
 8.170982374355797e-02,  5.812890091744177e-01,  2.612319135336336e-02,  
 8.304206805112350e-02,  1.303122834290349e-01,  3.197796594776971e-02,  
 9.579669178358458e-02,  9.786128840932780e-01,  4.858466607668643e-03,  
 1.298140716395927e-01, -1.364129934454575e-01,  3.153849046439230e-02,  
 1.448602053653137e-01, -9.993997310860954e-01,  5.187655461501736e-04,  
 1.637794332334225e-01,  2.917847592352579e-01,  2.372133318277343e-02,  
 1.656376032948203e-01, -3.792766926420451e-01,  3.002828141125498e-02,  
 1.762292877481467e-01, -7.767882983828635e-01,  2.024589761678427e-02,  
 1.814953063827089e-01, -9.796863149731511e-01,  6.038716138269680e-03,  
 1.834852661942361e-01, -5.949216461693253e-01,  2.588018863116454e-02,  
 1.867990480390358e-01, -9.082909202013399e-01,  1.438268457601201e-02,  
 1.997745797864829e-01,  8.521395692935436e-01,  1.769908491854464e-02,  
 2.012879315451541e-01,  4.865204987031345e-01,  2.424802585375267e-02,  
 2.073540200015715e-01,  9.979690495625936e-01,  1.871839129499010e-03,  
 2.092466713865647e-01,  9.536237467670772e-01,  9.197918109386862e-03,  
 2.142508728125625e-01,  6.811733554860471e-01,  2.453455227667186e-02,  
 2.222235734801500e-01,  1.329690651656386e-02,  3.153867440259803e-02,  
 2.552587195458114e-01,  2.135868866634151e-01,  1.710171709003340e-02,  
 2.738405728748159e-01, -2.432353447249460e-01,  3.084667141478646e-02,  
 3.037543314031991e-01,  3.985764917009157e-01,  2.212002672383645e-02,  
 3.062582671628846e-01, -4.779029541794464e-01,  2.841632130217824e-02,  
 3.073771915996136e-01, -9.932860050681348e-01,  2.560967478145304e-03,  
 3.085884559918400e-01, -6.853150635640251e-01,  2.335501600448783e-02,  
 3.097655269975939e-01, -8.409329107501455e-01,  1.745461988433493e-02,  
 3.264090470748552e-01,  7.799958670008352e-01,  1.976931010135947e-02,  
 3.269506077033738e-01,  1.528597292687391e-01,  1.880416143417532e-02,  
 3.287397793338149e-01, -9.499963119187408e-01,  1.015995287897780e-02,  
 3.299686062924967e-01,  9.136754073945763e-01,  1.223211496544324e-02,  
 3.399940734865946e-01,  9.843406124989522e-01,  5.358533964816193e-03,  
 3.414386037016686e-01,  5.837599078463863e-01,  2.531201093274045e-02,  
 3.626455120418416e-01, -9.420914031009561e-02,  2.954195879994616e-02,  
 4.071626746871289e-01,  3.109774847555636e-01,  2.432492670918727e-02,  
 4.140936135772086e-01, -3.459697602487943e-01,  2.904643863705676e-02,  
 4.145550075939219e-01, -9.984668858105441e-01,  8.704393591207662e-04,  
 4.248119738620462e-01,  7.344623137957502e-02,  2.290584551728990e-02,  
 4.327427543879804e-01, -5.800952441542988e-01,  2.542846350942939e-02,  
 4.378605680904344e-01, -7.622695385405753e-01,  1.990561596716723e-02,  
 4.398019895929731e-01,  8.590468375941196e-01,  1.424593076230482e-02,  
 4.409957188846723e-01, -8.964515554446453e-01,  1.360912679478925e-02,  
 4.446633915248027e-01,  6.971747211943454e-01,  2.079224858597253e-02,  
 4.561120813077312e-01,  9.583286368134947e-01,  7.651874640364773e-03,  
 4.578378135836055e-01,  4.858442710495443e-01,  2.286780694222276e-02,  
 4.673508637290545e-01, -9.782167962078963e-01,  6.029168541655493e-03,  
 4.743480302386265e-01,  9.967031114708308e-01,  1.646439778827267e-03,  
 4.982830846776936e-01, -1.973451409716288e-01,  2.712296241805855e-02,  
 5.053791029402219e-01, -4.887386159139488e-02,  8.213397938570224e-03,  
 5.182457807020877e-01,  2.160333823951996e-01,  2.436046657122245e-02,  
 5.382900510803214e-01, -4.567938591720622e-01,  2.598020239337663e-02,  
 5.431714974163138e-01,  2.867426624023640e-02,  1.502442733748493e-02,  
 5.450456322230584e-01,  7.938839184396489e-01,  1.592965984721472e-02,  
 5.460671166844733e-01,  4.143453777845346e-01,  1.419118265364266e-02,  
 5.483280208744600e-01,  9.203785964981086e-01,  9.152425543104364e-03,  
 5.538810843207090e-01,  6.108588585460906e-01,  2.034833182220751e-02,  
 5.568932657964470e-01, -6.692481046679927e-01,  2.157498392901168e-02,  
 5.596381875735323e-01,  9.921593115140971e-01,  1.608865885491389e-03,  
 5.597407146364283e-01, -8.307068015467881e-01,  1.582771127386430e-02,  
 5.662708737165433e-01, -9.399876147283586e-01,  9.394744050751306e-03,  
 5.918239732225662e-01, -9.949593941852612e-01,  2.396290467084638e-03,  
 6.132912672442516e-01, -3.146039051646457e-01,  2.212711650881879e-02,  
 6.138426634662881e-01, -6.118802903793545e-02,  1.806733793235598e-02,  
 6.142784830337650e-01,  3.453724863115886e-01,  1.864729091061658e-02,  
 6.182773578473880e-01,  9.740513097221366e-01,  5.410977905903992e-03,  
 6.396787787836092e-01,  8.728694805818825e-01,  1.137048039230828e-02,  
 6.406468508438566e-01,  1.468000595369991e-01,  2.043212465588637e-02,  
 6.467851189666363e-01,  7.205388161010090e-01,  1.703077749193565e-02,  
 6.488127284463796e-01, -2.007299075262801e-01,  1.095427143818548e-02,  
 6.517007603679420e-01,  5.283348578512921e-01,  1.809208934701153e-02,  
 6.559512407902149e-01, -5.555135149722775e-01,  2.234826148158751e-02,  
 6.690244056582569e-01, -7.508923368689349e-01,  1.710484161723342e-02,  
 6.718714751553437e-01, -8.884291476865778e-01,  1.150781632550147e-02,  
 6.771644395694760e-01, -9.722288077426058e-01,  5.528569852248240e-03,  
 7.083681501678855e-01,  6.248980851431146e-02,  1.314715640510330e-02,  
 7.097149683060735e-01,  9.954900449580694e-01,  1.976100218099145e-03,  
 7.138402644040628e-01,  9.387924343684284e-01,  8.164980595434149e-03,  
 7.198490951545802e-01,  2.812564715356937e-01,  1.789583577642915e-02,  
 7.215588783892570e-01, -1.159998849132680e-01,  1.652956139432900e-02,  
 7.226187070333294e-01, -4.079425951229357e-01,  2.112863498184051e-02,  
 7.265292300868345e-01,  4.469086468315797e-01,  1.420616050890493e-02,  
 7.331775979965447e-01,  8.135825128068572e-01,  1.307598884661690e-02,  
 7.416232943868383e-01,  6.401664396369919e-01,  1.652038500895329e-02,  
 7.474274447805114e-01, -2.490193226057417e-01,  9.746025489521986e-03,  
 7.577219445007012e-01, -6.503099455495434e-01,  1.766386441308518e-02,  
 7.585692250178416e-01, -9.940238473548991e-01,  2.133367947374089e-03,  
 7.673603283405851e-01, -8.229326660746660e-01,  1.248597476302831e-02,  
 7.692530439279005e-01, -9.355395173554912e-01,  7.514322260630891e-03,  
 7.854444511977640e-01,  2.685123392480584e-02,  1.533947945855647e-02,  
 7.951738457011064e-01,  9.766083680702315e-01,  4.356175996997274e-03,  
 7.985748483813998e-01,  2.025555068725613e-01,  1.564386357005296e-02,  
 8.040234894621253e-01, -2.042597387565252e-01,  7.710958187140682e-03,  
 8.057295032357437e-01,  8.915828031028744e-01,  9.355613099192112e-03,  
 8.088604175612499e-01,  4.023062626041685e-01,  1.273706153435572e-02,  
 8.120135674815725e-01, -5.076674583210536e-01,  1.736448568443276e-02,  
 8.133759777422149e-01,  5.487782375682692e-01,  1.217998404158868e-02,  
 8.184347733263844e-01,  7.425426026236549e-01,  1.279679392158505e-02,  
 8.235558633092787e-01, -3.024959465991686e-01,  1.287819098925984e-02,  
 8.421681940961352e-01, -9.736872041616552e-01,  4.112192665900335e-03,  
 8.426583009273289e-01, -7.378407924120958e-01,  1.274069526022431e-02,  
 8.491855987208501e-01, -8.846256408253794e-01,  8.283446027511682e-03,  
 8.516898507135523e-01, -7.990981970042101e-02,  1.580891087490480e-02,  
 8.583531941070754e-01,  9.966311518784791e-01,  1.191591564881406e-03,  
 8.707932748733679e-01, -9.983455554915148e-01,  6.345865698137260e-04,  
 8.719292766173237e-01,  3.244559296210806e-01,  1.339462628650847e-02,  
 8.741706562832676e-01,  1.282050668916198e-01,  1.359136343527793e-02,  
 8.746739329394990e-01,  9.458932113235630e-01,  5.483866186101370e-03,  
 8.754686572917406e-01,  6.486907444035410e-01,  9.118856886512235e-03,  
 8.810154998962139e-01,  8.328762658091308e-01,  8.944431517124202e-03,  
 8.838623245418704e-01,  5.232758761535393e-01,  8.099355551928950e-03,  
 8.840131826785472e-01, -6.067031031846036e-01,  1.277176198724360e-02,  
 8.857877394173622e-01, -3.901273813669436e-01,  1.389624600553866e-02,  
 9.091784209404282e-01, -9.377849360846731e-01,  4.939598298332105e-03,  
 9.095211566710759e-01, -1.967240155892789e-01,  1.315977866277586e-02,  
 9.097092205890601e-01, -8.157851178868343e-01,  8.243125043271836e-03,  
 9.196079033409038e-01,  7.363362622288353e-01,  5.921333683728877e-03,  
 9.227347373981668e-01,  2.518050384938889e-02,  1.062691558572691e-02,  
 9.248521839866148e-01,  9.836500044365560e-01,  2.345619531278534e-03,  
 9.251563778586870e-01,  4.438563917317115e-01,  9.900476467889377e-03,  
 9.257255001153735e-01, -9.889449924089616e-01,  1.597653710972395e-03,  
 9.343954029970296e-01,  9.015214103086258e-01,  5.328104999186108e-03,  
 9.369174879213626e-01,  2.389817273899876e-01,  1.111346808242325e-02,  
 9.383511550992609e-01,  6.373581080663476e-01,  5.774002588554636e-03,  
 9.387517764149524e-01, -4.968798107682113e-01,  1.020259840078752e-02,  
 9.387607494306587e-01, -7.000259293912848e-01,  8.261643223094358e-03,  
 9.539697271844676e-01,  7.975969707432101e-01,  4.649762577280237e-03,  
 9.552276863128365e-01, -3.035710530293175e-01,  9.006117332227408e-03,  
 9.569172017920470e-01, -8.842472974692178e-01,  4.741019829465620e-03,  
 9.595675104913648e-01, -7.355852323028661e-02,  7.652758779266264e-03,  
 9.644864346894841e-01, -9.667641619200008e-01,  2.030067204957960e-03,  
 9.656087615773162e-01,  5.543437727025696e-01,  6.351762240325599e-03,  
 9.688546673876272e-01,  9.558880345442317e-01,  2.480910477329663e-03,  
 9.704101090001410e-01,  9.981808611338953e-01,  4.561152547158576e-04,  
 9.727514081123080e-01,  1.110004091109647e-01,  6.093769602114571e-03,  
 9.729878975391641e-01,  3.616245012182894e-01,  6.843942401499502e-03,  
 9.756932294462006e-01, -6.036471845921362e-01,  5.800134625750472e-03,  
 9.760900548932613e-01, -7.838246719005716e-01,  4.407536360315319e-03,  
 9.782973640835879e-01, -9.971684762652360e-01,  4.311602698318422e-04,  
 9.807900912370063e-01,  7.129244508544674e-01,  4.127102044979779e-03,  
 9.808939118005312e-01,  8.613001240894053e-01,  2.999414636157759e-03,  
 9.835779953552617e-01, -4.135902303116288e-01,  5.032085033161774e-03,  
 9.854244802470254e-01, -1.682373835033575e-01,  4.864699918722623e-03,  
 9.871873668187979e-01,  1.693824175740657e-01,  2.336035230228115e-03,  
 9.897390691072502e-01, -9.305936554854670e-01,  1.645629389008965e-03,  
 9.934973942415222e-01,  4.709702784519761e-01,  2.855403033244952e-03,  
 9.941323665942218e-01,  9.840689837610336e-01,  5.975302834838432e-04,  
 9.948473950532203e-01,  9.223043056827241e-01,  1.118642207825798e-03,  
 9.948570811646354e-01,  6.241948125538140e-01,  1.966746818044319e-03,  
 9.955141358332547e-01, -7.009139270684177e-01,  1.973528831634365e-03,  
 9.955332555186237e-01, -8.505509962676160e-01,  1.399475221966474e-03,  
 9.959646721127126e-01, -4.250651416434814e-04,  2.683953315797548e-03,  
 9.966503083795464e-01,  2.697627971477953e-01,  2.110801603897598e-03,  
 9.966625578128554e-01, -9.821401814469173e-01,  4.298915672048476e-04,  
 9.972191681750349e-01, -5.232937991459530e-01,  1.621857507529301e-03,  
 9.977589931512456e-01, -2.851699647482527e-01,  1.679574685965640e-03,  
 9.982095733525613e-01,  7.942486273250328e-01,  1.122778646693857e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr43 ( )

/******************************************************************************/
/*
  Purpose:

    SMR43 returns the SMR rule of degree 43.

  Discussion:
 
    DEGREE: 43
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 331
    NORM INF MOMS. RESIDUAL: 6.57894e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR43[3*331], the requested rule.
*/
{
  const int degree = 43;
  int order;
  double xw[3*331] = {
 -9.991322806157538e-01, -7.967757949667039e-01,  8.678616486509684e-04,  
 -9.982000639809739e-01,  3.046004953209935e-01,  1.439841751685133e-03,  
 -9.980850962629690e-01,  9.781664509229353e-01,  3.796649877334044e-04,  
 -9.980230789357751e-01, -2.518043976244231e-01,  1.843703555135520e-03,  
 -9.977169911523626e-01,  5.459548078849698e-01,  1.239809456010988e-03,  
 -9.960955981451255e-01,  1.323322402607845e-02,  2.563511060458582e-03,  
 -9.949822864151898e-01, -9.238195120237386e-01,  9.266737007306744e-04,  
 -9.949201671743397e-01,  7.003454609915903e-01,  2.006603012946033e-03,  
 -9.948772524482939e-01,  8.407859395090261e-01,  1.605442474502514e-03,  
 -9.948541523937408e-01, -9.833293028860037e-01,  5.491048194068317e-04,  
 -9.947061632621746e-01, -6.355790382588226e-01,  1.778286578522554e-03,  
 -9.945229623313124e-01, -4.853023018396496e-01,  2.560515852421350e-03,  
 -9.892614872423598e-01,  9.260146296311070e-01,  1.799734507689385e-03,  
 -9.871939619842668e-01, -8.755067171008981e-01,  1.519837361369944e-03,  
 -9.870688041516782e-01,  1.860477389466161e-01,  4.518470382030127e-03,  
 -9.867444463087381e-01,  4.389464150281105e-01,  4.224292354075523e-03,  
 -9.834968499928717e-01, -7.202131341080557e-01,  3.339955375858229e-03,  
 -9.821598385319343e-01,  9.959978097052690e-01,  4.727038168393605e-04,  
 -9.821204851739278e-01, -1.368717477114345e-01,  4.757586602695279e-03,  
 -9.797140053995109e-01, -3.605450203749538e-01,  5.952555069740412e-03,  
 -9.748774429719304e-01,  6.046447974749469e-01,  5.546938866694710e-03,  
 -9.734413327253255e-01, -9.978546421321081e-01,  4.474703090515473e-04,  
 -9.734116599154365e-01, -8.128285861906330e-02,  2.741115844813457e-03,  
 -9.726507374329582e-01,  7.726414313517832e-01,  4.741572721729229e-03,  
 -9.714591142922610e-01, -8.274759240878854e-01,  3.381861982854643e-03,  
 -9.707758044034546e-01, -9.550455839865367e-01,  2.339780436266730e-03,  
 -9.675614571152631e-01, -5.690626658543524e-01,  6.088138066683147e-03,  
 -9.643580663040768e-01,  9.675657234336767e-01,  2.156284749425144e-03,  
 -9.620411392118244e-01,  8.827193644891181e-02,  7.524938344770951e-03,  
 -9.613825223406508e-01,  3.274157880119070e-01,  8.329588693656027e-03,  
 -9.572105649891679e-01,  8.779211539499637e-01,  4.677019870857324e-03,  
 -9.482779256977600e-01, -6.571793975487423e-01,  3.415065808643305e-03,  
 -9.442203741741305e-01, -2.396912099299458e-01,  1.053267886519870e-02,  
 -9.414082069989970e-01, -4.455867154949159e-01,  7.955507648643412e-03,  
 -9.399484869570831e-01,  5.017481363429027e-01,  9.346304112770374e-03,  
 -9.387730081468121e-01, -8.994764149206039e-01,  5.120889482069984e-03,  
 -9.381605799832013e-01, -7.581359176425346e-01,  6.330117595761937e-03,  
 -9.324895156315322e-01,  6.876092944131506e-01,  8.757387580269081e-03,  
 -9.303980205538308e-01, -2.287492239980876e-02,  9.878323399096202e-03,  
 -9.300897829687235e-01, -9.834052375669528e-01,  2.235790741981890e-03,  
 -9.235245729050272e-01,  9.918027925163878e-01,  1.542906053318116e-03,  
 -9.175260810911099e-01,  2.167671303064032e-01,  1.277769691913465e-02,  
 -9.152022665122554e-01,  9.349908468306158e-01,  4.721132707483059e-03,  
 -9.085212108480799e-01,  8.115960772910453e-01,  8.234979199618303e-03,  
 -9.005451856752491e-01, -6.470132016778298e-01,  9.072910191199055e-03,  
 -8.993217981371787e-01, -5.116431205683809e-01,  8.049099608777895e-03,  
 -8.927214238682213e-01,  4.039129384019244e-01,  1.176810878122849e-02,  
 -8.881186605619299e-01, -8.304324891473370e-01,  8.581965557258065e-03,  
 -8.876535679652159e-01, -3.361428192098763e-01,  1.273089714018281e-02,  
 -8.857085475134302e-01, -1.254112109470145e-01,  1.296699198587140e-02,  
 -8.821398112805722e-01, -9.453230958968664e-01,  5.328273493767261e-03,  
 -8.750237163459592e-01,  5.925043126358809e-01,  1.336532935350772e-02,  
 -8.681630157484973e-01, -9.968478564406162e-01,  1.108072915590710e-03,  
 -8.654982773274537e-01,  8.883753842636366e-02,  1.557578581133525e-02,  
 -8.563237880711940e-01,  9.727943477844379e-01,  3.899549565205258e-03,  
 -8.529385601042461e-01,  8.850063664849166e-01,  8.114118976527893e-03,  
 -8.416510529475818e-01,  7.343186487220238e-01,  1.255955264577050e-02,  
 -8.384749004002887e-01,  3.197575534100762e-01,  1.323030988966136e-02,  
 -8.382565684334965e-01, -7.304981145627908e-01,  1.224239155066108e-02,  
 -8.367263219641764e-01,  9.989783711881817e-01,  6.905843510793296e-04,  
 -8.317712773416662e-01, -5.574060797969008e-01,  1.237820673005956e-02,  
 -8.211388015093348e-01, -4.085976590181732e-01,  1.240477807928645e-02,  
 -8.200424695478955e-01, -2.132333832998874e-01,  1.547445721646811e-02,  
 -8.166284772848996e-01, -8.902469000574972e-01,  9.021259420998788e-03,  
 -8.064166934103733e-01, -9.770750896183711e-01,  4.237570484423649e-03,  
 -8.007534551335261e-01,  2.023658932297688e-01,  1.164039038671748e-02,  
 -8.007277480191897e-01, -2.104803054778272e-02,  1.569505703943440e-02,  
 -8.004502220252274e-01,  4.920509614468455e-01,  1.783350078263945e-02,  
 -7.777206426895686e-01,  9.379771024961836e-01,  7.326924906570778e-03,  
 -7.728688446320272e-01,  8.237137982084558e-01,  1.213629881907029e-02,  
 -7.580631733732273e-01, -8.027077015709957e-01,  1.251455028114069e-02,  
 -7.577866929033681e-01,  6.473964743724965e-01,  1.731376923259042e-02,  
 -7.553675037695931e-01,  9.890969808970442e-01,  2.691505001410149e-03,  
 -7.542249834026444e-01, -6.390864016792512e-01,  1.601212151097312e-02,  
 -7.477885480587728e-01,  2.427391554099002e-01,  1.018027057488272e-02,  
 -7.429209417585371e-01, -4.572389551800778e-01,  1.367871025169973e-02,  
 -7.371197753463775e-01, -2.906469452332063e-01,  1.778595422410749e-02,  
 -7.324580428326298e-01, -8.991331137587374e-02,  1.376411964043993e-02,  
 -7.298747767373949e-01, -9.377223151384039e-01,  7.856423898031506e-03,  
 -7.216457298390802e-01, -9.955998257315364e-01,  1.925204978765617e-03,  
 -7.198181678973603e-01,  9.304616811847628e-02,  1.635290663392455e-02,  
 -7.130017786063146e-01,  3.849140372358901e-01,  2.099925831266623e-02,  
 -6.825679163672110e-01,  8.905466207929580e-01,  1.126602938845450e-02,  
 -6.763401791869282e-01,  7.520777122204155e-01,  1.664378870053760e-02,  
 -6.745643364827608e-01, -8.606759404486958e-01,  9.423794484989551e-03,  
 -6.692634952197962e-01,  5.097498990430799e-01,  3.490301165694596e-03,  
 -6.678673365644893e-01,  9.692798398364254e-01,  5.426070381428601e-03,  
 -6.643115741452658e-01, -5.309653253850217e-01,  1.761400113990701e-02,  
 -6.606757146764088e-01, -7.200291927434657e-01,  1.686289443033400e-02,  
 -6.567913888935971e-01,  5.564860922255590e-01,  1.944041905076146e-02,  
 -6.534475768044156e-01, -1.614337947470229e-01,  1.995971702129454e-02,  
 -6.524650541104557e-01,  9.984813564068824e-01,  8.021305622560764e-04,  
 -6.485591953402302e-01,  1.462165876218090e-01,  1.245039847543152e-02,  
 -6.399859555346357e-01, -9.716158671859889e-01,  5.166264959182605e-03,  
 -6.305799776467085e-01, -3.579775654349885e-01,  1.953568169826047e-02,  
 -6.267627879174098e-01, -8.871690949497815e-01,  4.520535674923600e-03,  
 -6.120426992404430e-01,  2.869750962968468e-03,  1.860789887443906e-02,  
 -6.088744531800644e-01,  2.804875419270162e-01,  2.332988515386343e-02,  
 -5.749843157741534e-01, -9.904789673241521e-01,  2.362095702578418e-03,  
 -5.718072946653548e-01,  8.322456115066252e-01,  1.553421465906625e-02,  
 -5.675480158302344e-01,  9.377249812058859e-01,  9.005466515286650e-03,  
 -5.664486963280643e-01, -6.135983682693644e-01,  2.017210091127541e-02,  
 -5.657771979464153e-01,  6.704839134317745e-01,  2.109811178256368e-02,  
 -5.585579279296714e-01, -7.943301890435838e-01,  1.609461230917944e-02,  
 -5.579555277532646e-01, -9.225093413353801e-01,  9.166625675892499e-03,  
 -5.577648940591486e-01,  9.919460143463890e-01,  2.677714001127571e-03,  
 -5.482310238931972e-01,  4.436263081953605e-01,  2.595341256088991e-02,  
 -5.447318792923874e-01, -4.312874087466062e-01,  1.584488792236623e-02,  
 -5.329070463527521e-01, -2.338802504012752e-01,  2.422380287073101e-02,  
 -5.252362328960822e-01,  3.532940066961791e-02,  9.744250397514996e-03,  
 -5.130671510975665e-01, -6.775266904189804e-02,  1.459619277289368e-02,  
 -4.960740015643434e-01,  1.706460416978806e-01,  2.591008998522666e-02,  
 -4.808128433935768e-01, -9.974703436931273e-01,  1.443156609799716e-03,  
 -4.623102743179813e-01, -9.610162776458973e-01,  7.615494645822680e-03,  
 -4.600618171289382e-01, -4.996628273183154e-01,  2.060900455474742e-02,  
 -4.564322622275068e-01, -6.991541335990263e-01,  2.068903174625100e-02,  
 -4.548079347101475e-01,  9.746241299392923e-01,  6.067456845050942e-03,  
 -4.515547213045702e-01, -8.598202981137183e-01,  1.439130083445319e-02,  
 -4.503129032330394e-01,  7.633185764987656e-01,  1.967366980699904e-02,  
 -4.502426979449590e-01,  5.735143166228439e-01,  2.537869809042589e-02,  
 -4.496670834961325e-01,  8.946719781100732e-01,  1.311990862370523e-02,  
 -4.251260023953483e-01,  3.328741198230487e-01,  2.923686270121404e-02,  
 -4.102747237675974e-01, -3.287465817704832e-01,  2.653855839458294e-02,  
 -4.097742235858718e-01, -1.135690075591068e-01,  2.264588400082614e-02,  
 -3.821379964609022e-01,  9.977278116070721e-01,  1.492947570302465e-03,  
 -3.710645184035626e-01,  6.451693464263640e-02,  2.822176831273999e-02,  
 -3.481673778720014e-01, -5.903202117641789e-01,  2.447652324050865e-02,  
 -3.448938453586106e-01, -9.856166934989374e-01,  5.018022434939532e-03,  
 -3.422130750204260e-01, -9.147110358303762e-01,  1.211341740570449e-02,  
 -3.378211193742023e-01, -7.806996115904031e-01,  1.966729409903938e-02,  
 -3.293359567236023e-01,  6.802105984639650e-01,  2.316447832146869e-02,  
 -3.271120843566677e-01,  9.451621148227166e-01,  1.023548496461210e-02,  
 -3.229115509093045e-01,  4.710955737486453e-01,  2.874889270545898e-02,  
 -3.211530646437794e-01,  8.398359715224299e-01,  1.720122054179252e-02,  
 -3.191122714012474e-01, -1.905915965306147e-01,  1.407630952884238e-02,  
 -2.905224871790252e-01,  2.219174453896190e-01,  3.135886233490107e-02,  
 -2.868275827924473e-01, -4.287232032846321e-01,  2.644181346508640e-02,  
 -2.813268043035183e-01,  9.900617341002494e-01,  2.531900366243961e-03,  
 -2.489834837398367e-01, -2.386259984115299e-01,  2.038703880401185e-02,  
 -2.348227489146337e-01, -3.642259826195845e-02,  2.974478219547869e-02,  
 -2.229672705935626e-01, -9.536956599040048e-01,  8.925090234945601e-03,  
 -2.217237803712502e-01, -6.844325665508253e-01,  2.424626466446409e-02,  
 -2.128621594472864e-01, -8.526186852917771e-01,  1.756834142926637e-02,  
 -2.125561177477307e-01, -9.980480071481969e-01,  1.726623494738264e-03,  
 -2.054220511368849e-01,  5.927379621951687e-01,  2.476004812382263e-02,  
 -1.954822662555086e-01,  7.701425309943154e-01,  2.069081296177256e-02,  
 -1.899491393527934e-01,  9.774606174758702e-01,  5.458708894084326e-03,  
 -1.869931902994500e-01,  3.648439403146066e-01,  3.090130558081868e-02,  
 -1.869854048603779e-01,  9.026780626332723e-01,  1.464880341973280e-02,  
 -1.679896766248765e-01, -5.248629640600491e-01,  2.470645077115440e-02,  
 -1.465102454558500e-01,  1.123409399107938e-01,  3.177165363173588e-02,  
 -1.385073680894356e-01, -3.298408069038985e-01,  2.620563217542392e-02,  
 -1.134715731110063e-01, -9.780057138044185e-01,  4.706880211425860e-03,  
 -1.021222696160731e-01,  9.977141232529759e-01,  1.651355185248162e-03,  
 -9.405687967364605e-02, -1.438416812367627e-01,  3.079509771216723e-02,  
 -8.817076361552034e-02, -7.703079005902046e-01,  2.232155693784380e-02,  
 -8.704255665377880e-02,  5.068242195166577e-01,  2.401020117466116e-02,  
 -7.913623635980109e-02, -9.095514118294697e-01,  1.423838918529654e-02,  
 -6.929449557918647e-02,  6.932074779450002e-01,  2.267377008668297e-02,  
 -5.631165265722810e-02,  9.521617930920341e-01,  1.005557273422889e-02,  
 -5.146821758475675e-02, -6.119016003137178e-01,  2.335034055431550e-02,  
 -4.992117521864334e-02,  8.431401729697686e-01,  1.893911020782059e-02,  
 -4.672957151157093e-02,  2.554909810874523e-01,  3.137166376170161e-02,  
 -2.525132080623741e-02, -9.900183656322150e-01,  3.101973828036974e-03,  
 -2.362106216876548e-02, -4.221330758506368e-01,  2.444427008848211e-02,  
 0.000000000000000e+00,  0.000000000000000e+00,  3.168017196709776e-02,  
 2.362106216876548e-02,  4.221330758506368e-01,  2.444427008848211e-02,  
 2.525132080623741e-02,  9.900183656322150e-01,  3.101973828036974e-03,  
 4.672957151157093e-02, -2.554909810874523e-01,  3.137166376170161e-02,  
 4.992117521864334e-02, -8.431401729697686e-01,  1.893911020782059e-02,  
 5.146821758475675e-02,  6.119016003137178e-01,  2.335034055431550e-02,  
 5.631165265722810e-02, -9.521617930920341e-01,  1.005557273422889e-02,  
 6.929449557918647e-02, -6.932074779450002e-01,  2.267377008668297e-02,  
 7.913623635980109e-02,  9.095514118294697e-01,  1.423838918529654e-02,  
 8.704255665377880e-02, -5.068242195166577e-01,  2.401020117466116e-02,  
 8.817076361552034e-02,  7.703079005902046e-01,  2.232155693784380e-02,  
 9.405687967364605e-02,  1.438416812367627e-01,  3.079509771216723e-02,  
 1.021222696160731e-01, -9.977141232529759e-01,  1.651355185248162e-03,  
 1.134715731110063e-01,  9.780057138044185e-01,  4.706880211425860e-03,  
 1.385073680894356e-01,  3.298408069038985e-01,  2.620563217542392e-02,  
 1.465102454558500e-01, -1.123409399107938e-01,  3.177165363173588e-02,  
 1.679896766248765e-01,  5.248629640600491e-01,  2.470645077115440e-02,  
 1.869854048603779e-01, -9.026780626332723e-01,  1.464880341973280e-02,  
 1.869931902994500e-01, -3.648439403146066e-01,  3.090130558081868e-02,  
 1.899491393527934e-01, -9.774606174758702e-01,  5.458708894084326e-03,  
 1.954822662555086e-01, -7.701425309943154e-01,  2.069081296177256e-02,  
 2.054220511368849e-01, -5.927379621951687e-01,  2.476004812382263e-02,  
 2.125561177477307e-01,  9.980480071481969e-01,  1.726623494738264e-03,  
 2.128621594472864e-01,  8.526186852917771e-01,  1.756834142926637e-02,  
 2.217237803712502e-01,  6.844325665508253e-01,  2.424626466446409e-02,  
 2.229672705935626e-01,  9.536956599040048e-01,  8.925090234945601e-03,  
 2.348227489146337e-01,  3.642259826195845e-02,  2.974478219547869e-02,  
 2.489834837398367e-01,  2.386259984115299e-01,  2.038703880401185e-02,  
 2.813268043035183e-01, -9.900617341002494e-01,  2.531900366243961e-03,  
 2.868275827924473e-01,  4.287232032846321e-01,  2.644181346508640e-02,  
 2.905224871790252e-01, -2.219174453896190e-01,  3.135886233490107e-02,  
 3.191122714012474e-01,  1.905915965306147e-01,  1.407630952884238e-02,  
 3.211530646437794e-01, -8.398359715224299e-01,  1.720122054179252e-02,  
 3.229115509093045e-01, -4.710955737486453e-01,  2.874889270545898e-02,  
 3.271120843566677e-01, -9.451621148227166e-01,  1.023548496461210e-02,  
 3.293359567236023e-01, -6.802105984639650e-01,  2.316447832146869e-02,  
 3.378211193742023e-01,  7.806996115904031e-01,  1.966729409903938e-02,  
 3.422130750204260e-01,  9.147110358303762e-01,  1.211341740570449e-02,  
 3.448938453586106e-01,  9.856166934989374e-01,  5.018022434939532e-03,  
 3.481673778720014e-01,  5.903202117641789e-01,  2.447652324050865e-02,  
 3.710645184035626e-01, -6.451693464263640e-02,  2.822176831273999e-02,  
 3.821379964609022e-01, -9.977278116070721e-01,  1.492947570302465e-03,  
 4.097742235858718e-01,  1.135690075591068e-01,  2.264588400082614e-02,  
 4.102747237675974e-01,  3.287465817704832e-01,  2.653855839458294e-02,  
 4.251260023953483e-01, -3.328741198230487e-01,  2.923686270121404e-02,  
 4.496670834961325e-01, -8.946719781100732e-01,  1.311990862370523e-02,  
 4.502426979449590e-01, -5.735143166228439e-01,  2.537869809042589e-02,  
 4.503129032330394e-01, -7.633185764987656e-01,  1.967366980699904e-02,  
 4.515547213045702e-01,  8.598202981137183e-01,  1.439130083445319e-02,  
 4.548079347101475e-01, -9.746241299392923e-01,  6.067456845050942e-03,  
 4.564322622275068e-01,  6.991541335990263e-01,  2.068903174625100e-02,  
 4.600618171289382e-01,  4.996628273183154e-01,  2.060900455474742e-02,  
 4.623102743179813e-01,  9.610162776458973e-01,  7.615494645822680e-03,  
 4.808128433935768e-01,  9.974703436931273e-01,  1.443156609799716e-03,  
 4.960740015643434e-01, -1.706460416978806e-01,  2.591008998522666e-02,  
 5.130671510975665e-01,  6.775266904189804e-02,  1.459619277289368e-02,  
 5.252362328960822e-01, -3.532940066961791e-02,  9.744250397514996e-03,  
 5.329070463527521e-01,  2.338802504012752e-01,  2.422380287073101e-02,  
 5.447318792923874e-01,  4.312874087466062e-01,  1.584488792236623e-02,  
 5.482310238931972e-01, -4.436263081953605e-01,  2.595341256088991e-02,  
 5.577648940591486e-01, -9.919460143463890e-01,  2.677714001127571e-03,  
 5.579555277532646e-01,  9.225093413353801e-01,  9.166625675892499e-03,  
 5.585579279296714e-01,  7.943301890435838e-01,  1.609461230917944e-02,  
 5.657771979464153e-01, -6.704839134317745e-01,  2.109811178256368e-02,  
 5.664486963280643e-01,  6.135983682693644e-01,  2.017210091127541e-02,  
 5.675480158302344e-01, -9.377249812058859e-01,  9.005466515286650e-03,  
 5.718072946653548e-01, -8.322456115066252e-01,  1.553421465906625e-02,  
 5.749843157741534e-01,  9.904789673241521e-01,  2.362095702578418e-03,  
 6.088744531800644e-01, -2.804875419270162e-01,  2.332988515386343e-02,  
 6.120426992404430e-01, -2.869750962968468e-03,  1.860789887443906e-02,  
 6.267627879174098e-01,  8.871690949497815e-01,  4.520535674923600e-03,  
 6.305799776467085e-01,  3.579775654349885e-01,  1.953568169826047e-02,  
 6.399859555346357e-01,  9.716158671859889e-01,  5.166264959182605e-03,  
 6.485591953402302e-01, -1.462165876218090e-01,  1.245039847543152e-02,  
 6.524650541104557e-01, -9.984813564068824e-01,  8.021305622560764e-04,  
 6.534475768044156e-01,  1.614337947470229e-01,  1.995971702129454e-02,  
 6.567913888935971e-01, -5.564860922255590e-01,  1.944041905076146e-02,  
 6.606757146764088e-01,  7.200291927434657e-01,  1.686289443033400e-02,  
 6.643115741452658e-01,  5.309653253850217e-01,  1.761400113990701e-02,  
 6.678673365644893e-01, -9.692798398364254e-01,  5.426070381428601e-03,  
 6.692634952197962e-01, -5.097498990430799e-01,  3.490301165694596e-03,  
 6.745643364827608e-01,  8.606759404486958e-01,  9.423794484989551e-03,  
 6.763401791869282e-01, -7.520777122204155e-01,  1.664378870053760e-02,  
 6.825679163672110e-01, -8.905466207929580e-01,  1.126602938845450e-02,  
 7.130017786063146e-01, -3.849140372358901e-01,  2.099925831266623e-02,  
 7.198181678973603e-01, -9.304616811847628e-02,  1.635290663392455e-02,  
 7.216457298390802e-01,  9.955998257315364e-01,  1.925204978765617e-03,  
 7.298747767373949e-01,  9.377223151384039e-01,  7.856423898031506e-03,  
 7.324580428326298e-01,  8.991331137587374e-02,  1.376411964043993e-02,  
 7.371197753463775e-01,  2.906469452332063e-01,  1.778595422410749e-02,  
 7.429209417585371e-01,  4.572389551800778e-01,  1.367871025169973e-02,  
 7.477885480587728e-01, -2.427391554099002e-01,  1.018027057488272e-02,  
 7.542249834026444e-01,  6.390864016792512e-01,  1.601212151097312e-02,  
 7.553675037695931e-01, -9.890969808970442e-01,  2.691505001410149e-03,  
 7.577866929033681e-01, -6.473964743724965e-01,  1.731376923259042e-02,  
 7.580631733732273e-01,  8.027077015709957e-01,  1.251455028114069e-02,  
 7.728688446320272e-01, -8.237137982084558e-01,  1.213629881907029e-02,  
 7.777206426895686e-01, -9.379771024961836e-01,  7.326924906570778e-03,  
 8.004502220252274e-01, -4.920509614468455e-01,  1.783350078263945e-02,  
 8.007277480191897e-01,  2.104803054778272e-02,  1.569505703943440e-02,  
 8.007534551335261e-01, -2.023658932297688e-01,  1.164039038671748e-02,  
 8.064166934103733e-01,  9.770750896183711e-01,  4.237570484423649e-03,  
 8.166284772848996e-01,  8.902469000574972e-01,  9.021259420998788e-03,  
 8.200424695478955e-01,  2.132333832998874e-01,  1.547445721646811e-02,  
 8.211388015093348e-01,  4.085976590181732e-01,  1.240477807928645e-02,  
 8.317712773416662e-01,  5.574060797969008e-01,  1.237820673005956e-02,  
 8.367263219641764e-01, -9.989783711881817e-01,  6.905843510793296e-04,  
 8.382565684334965e-01,  7.304981145627908e-01,  1.224239155066108e-02,  
 8.384749004002887e-01, -3.197575534100762e-01,  1.323030988966136e-02,  
 8.416510529475818e-01, -7.343186487220238e-01,  1.255955264577050e-02,  
 8.529385601042461e-01, -8.850063664849166e-01,  8.114118976527893e-03,  
 8.563237880711940e-01, -9.727943477844379e-01,  3.899549565205258e-03,  
 8.654982773274537e-01, -8.883753842636366e-02,  1.557578581133525e-02,  
 8.681630157484973e-01,  9.968478564406162e-01,  1.108072915590710e-03,  
 8.750237163459592e-01, -5.925043126358809e-01,  1.336532935350772e-02,  
 8.821398112805722e-01,  9.453230958968664e-01,  5.328273493767261e-03,  
 8.857085475134302e-01,  1.254112109470145e-01,  1.296699198587140e-02,  
 8.876535679652159e-01,  3.361428192098763e-01,  1.273089714018281e-02,  
 8.881186605619299e-01,  8.304324891473370e-01,  8.581965557258065e-03,  
 8.927214238682213e-01, -4.039129384019244e-01,  1.176810878122849e-02,  
 8.993217981371787e-01,  5.116431205683809e-01,  8.049099608777895e-03,  
 9.005451856752491e-01,  6.470132016778298e-01,  9.072910191199055e-03,  
 9.085212108480799e-01, -8.115960772910453e-01,  8.234979199618303e-03,  
 9.152022665122554e-01, -9.349908468306158e-01,  4.721132707483059e-03,  
 9.175260810911099e-01, -2.167671303064032e-01,  1.277769691913465e-02,  
 9.235245729050272e-01, -9.918027925163878e-01,  1.542906053318116e-03,  
 9.300897829687235e-01,  9.834052375669528e-01,  2.235790741981890e-03,  
 9.303980205538308e-01,  2.287492239980876e-02,  9.878323399096202e-03,  
 9.324895156315322e-01, -6.876092944131506e-01,  8.757387580269081e-03,  
 9.381605799832013e-01,  7.581359176425346e-01,  6.330117595761937e-03,  
 9.387730081468121e-01,  8.994764149206039e-01,  5.120889482069984e-03,  
 9.399484869570831e-01, -5.017481363429027e-01,  9.346304112770374e-03,  
 9.414082069989970e-01,  4.455867154949159e-01,  7.955507648643412e-03,  
 9.442203741741305e-01,  2.396912099299458e-01,  1.053267886519870e-02,  
 9.482779256977600e-01,  6.571793975487423e-01,  3.415065808643305e-03,  
 9.572105649891679e-01, -8.779211539499637e-01,  4.677019870857324e-03,  
 9.613825223406508e-01, -3.274157880119070e-01,  8.329588693656027e-03,  
 9.620411392118244e-01, -8.827193644891181e-02,  7.524938344770951e-03,  
 9.643580663040768e-01, -9.675657234336767e-01,  2.156284749425144e-03,  
 9.675614571152631e-01,  5.690626658543524e-01,  6.088138066683147e-03,  
 9.707758044034546e-01,  9.550455839865367e-01,  2.339780436266730e-03,  
 9.714591142922610e-01,  8.274759240878854e-01,  3.381861982854643e-03,  
 9.726507374329582e-01, -7.726414313517832e-01,  4.741572721729229e-03,  
 9.734116599154365e-01,  8.128285861906330e-02,  2.741115844813457e-03,  
 9.734413327253255e-01,  9.978546421321081e-01,  4.474703090515473e-04,  
 9.748774429719304e-01, -6.046447974749469e-01,  5.546938866694710e-03,  
 9.797140053995109e-01,  3.605450203749538e-01,  5.952555069740412e-03,  
 9.821204851739278e-01,  1.368717477114345e-01,  4.757586602695279e-03,  
 9.821598385319343e-01, -9.959978097052690e-01,  4.727038168393605e-04,  
 9.834968499928717e-01,  7.202131341080557e-01,  3.339955375858229e-03,  
 9.867444463087381e-01, -4.389464150281105e-01,  4.224292354075523e-03,  
 9.870688041516782e-01, -1.860477389466161e-01,  4.518470382030127e-03,  
 9.871939619842668e-01,  8.755067171008981e-01,  1.519837361369944e-03,  
 9.892614872423598e-01, -9.260146296311070e-01,  1.799734507689385e-03,  
 9.945229623313124e-01,  4.853023018396496e-01,  2.560515852421350e-03,  
 9.947061632621746e-01,  6.355790382588226e-01,  1.778286578522554e-03,  
 9.948541523937408e-01,  9.833293028860037e-01,  5.491048194068317e-04,  
 9.948772524482939e-01, -8.407859395090261e-01,  1.605442474502514e-03,  
 9.949201671743397e-01, -7.003454609915903e-01,  2.006603012946033e-03,  
 9.949822864151898e-01,  9.238195120237386e-01,  9.266737007306744e-04,  
 9.960955981451255e-01, -1.323322402607845e-02,  2.563511060458582e-03,  
 9.977169911523626e-01, -5.459548078849698e-01,  1.239809456010988e-03,  
 9.980230789357751e-01,  2.518043976244231e-01,  1.843703555135520e-03,  
 9.980850962629690e-01, -9.781664509229353e-01,  3.796649877334044e-04,  
 9.982000639809739e-01, -3.046004953209935e-01,  1.439841751685133e-03,  
 9.991322806157538e-01,  7.967757949667039e-01,  8.678616486509684e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr44 ( )

/******************************************************************************/
/*
  Purpose:

    SMR44 returns the SMR rule of degree 44.

  Discussion:
 
    DEGREE: 44
    POINTS CARDINALITY: 353
    NORM INF MOMS. RESIDUAL: 1.39699e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR44[3*353], the requested rule.
*/
{
  const int degree = 44;
  int order;
  double xw[3*353] = {
 -9.984320392366739e-01, -8.069907738631789e-01,  9.129188297919674e-04,  
 -9.983184531837725e-01,  9.305063618730227e-01,  5.320673982755963e-04,  
 -9.978244272094350e-01,  2.010518994335128e-01,  1.598745058561678e-03,  
 -9.974547076089806e-01,  4.442097888110615e-01,  1.587226283438206e-03,  
 -9.971550888623897e-01, -5.768131021729579e-02,  1.901977649434094e-03,  
 -9.967647638775373e-01,  8.058203134817903e-01,  1.263686704072662e-03,  
 -9.963702759402693e-01,  9.957226369845009e-01,  1.818612016165590e-04,  
 -9.963181710633270e-01, -6.304189998071564e-01,  1.671127161151113e-03,  
 -9.961268807224163e-01,  6.456711899254686e-01,  1.750825399677425e-03,  
 -9.957522090105495e-01, -9.275216968816482e-01,  8.507815083388259e-04,  
 -9.951693924758787e-01, -2.761138658566978e-01,  2.436900445069140e-03,  
 -9.950054666513565e-01, -9.849707705106929e-01,  4.757246968341718e-04,  
 -9.946541882949513e-01, -4.583314062976532e-01,  2.366650251412720e-03,  
 -9.887114315163458e-01,  9.660230724784559e-01,  8.879418773849759e-04,  
 -9.846991374239497e-01,  7.976665855520176e-02,  5.012110624120673e-03,  
 -9.844761515180129e-01,  3.207459712592796e-01,  4.876181551671285e-03,  
 -9.842610329585771e-01, -8.709872191992893e-01,  2.295666225344954e-03,  
 -9.839028036500266e-01, -7.269350704556350e-01,  3.598356544188341e-03,  
 -9.834521968435078e-01,  8.788181549694504e-01,  2.662295402621843e-03,  
 -9.825404996126923e-01,  5.377600798078346e-01,  4.243392110291322e-03,  
 -9.791830807570596e-01,  7.300801609052650e-01,  4.174881751974668e-03,  
 -9.789536888169472e-01, -1.541839686056489e-01,  5.635575613152338e-03,  
 -9.754623934517895e-01, -9.985001905507400e-01,  3.451126367359588e-04,  
 -9.754074605989603e-01, -5.489105297220782e-01,  5.119253227374393e-03,  
 -9.743732738644221e-01, -9.576680228121058e-01,  1.885947698906212e-03,  
 -9.727071455292210e-01,  9.854153480279049e-01,  9.090447956991166e-04,  
 -9.724216540568620e-01, -3.604921321100248e-01,  5.763676619977396e-03,  
 -9.613138962914113e-01, -8.110561453053367e-01,  3.754018364329767e-03,  
 -9.569550751753445e-01,  9.321525496230852e-01,  3.154552805737187e-03,  
 -9.556428656633877e-01,  2.033112164565538e-01,  8.655618940100654e-03,  
 -9.549267697092383e-01,  4.267664542473830e-01,  7.666973204798044e-03,  
 -9.533681225680328e-01, -1.542928806337710e-02,  8.164452383475256e-03,  
 -9.527049674156014e-01,  6.174677639259242e-01,  6.608979468596846e-03,  
 -9.515654916231491e-01,  8.125776987261066e-01,  5.354225267337657e-03,  
 -9.490456638939141e-01, -6.481440018182706e-01,  6.672612545168258e-03,  
 -9.458175364481419e-01, -9.060068746246541e-01,  4.013235135085827e-03,  
 -9.440126918917942e-01,  9.976234060121431e-01,  5.680139121819110e-04,  
 -9.437045246883812e-01, -4.180391499005318e-01,  4.052305718583254e-03,  
 -9.416958977488444e-01, -9.832610660242087e-01,  1.644473802134468e-03,  
 -9.406877057002140e-01, -2.319813480159833e-01,  8.705386624332852e-03,  
 -9.296781480094017e-01, -7.566364668417300e-01,  4.783429752162442e-03,  
 -9.248302265385766e-01, -4.861577371922396e-01,  7.748939834534853e-03,  
 -9.202441950236100e-01,  9.674488696318712e-01,  2.660205689239971e-03,  
 -9.178390013250890e-01,  7.064362568998120e-01,  7.919583195340947e-03,  
 -9.135758448462131e-01,  8.754421512868488e-01,  5.404549032231900e-03,  
 -9.119456444341953e-01,  3.233647958995216e-01,  1.083291124444676e-02,  
 -9.079717560919897e-01, -8.773647290343602e-02,  9.522960144764343e-03,  
 -9.067025869022671e-01,  1.076010187739800e-01,  1.170317912042211e-02,  
 -9.051126411361261e-01,  5.170998371398160e-01,  1.099643030005613e-02,  
 -9.001351500517843e-01, -9.461649530258005e-01,  4.028247494909381e-03,  
 -9.000620333263829e-01, -8.422658056671526e-01,  6.586062353219417e-03,  
 -8.994849690542454e-01, -9.938608373644522e-01,  9.520566362941994e-04,  
 -8.941680642100808e-01, -3.104307200910414e-01,  9.898803205596610e-03,  
 -8.932311675008094e-01, -5.876846915824177e-01,  7.570892945063220e-03,  
 -8.795126005531750e-01, -7.053987104996297e-01,  8.491984407075194e-03,  
 -8.784492099639224e-01,  9.883243937096547e-01,  1.809730927741861e-03,  
 -8.693740466112758e-01,  9.210068898056959e-01,  4.897281085790932e-03,  
 -8.693401894440411e-01,  7.856297245279599e-01,  9.261454593228968e-03,  
 -8.562011220892315e-01, -3.962460994060516e-01,  9.981754074698595e-03,  
 -8.548549835925230e-01,  2.399548122908549e-01,  1.209333227731901e-02,  
 -8.532888443992166e-01,  6.222509726831481e-01,  1.233013730701336e-02,  
 -8.528074077558421e-01, -1.579638544671366e-01,  1.324588980901926e-02,  
 -8.444113766994861e-01, -9.992229866877739e-01,  4.723975132108903e-04,  
 -8.432057487089938e-01,  3.235108142044065e-02,  1.319558395099830e-02,  
 -8.430373389996317e-01, -8.928430380538469e-01,  6.787529444568871e-03,  
 -8.425055028423227e-01, -5.289098324323593e-01,  8.580086025567452e-03,  
 -8.396012261206522e-01, -9.728858072059390e-01,  3.439212998921980e-03,  
 -8.382826128298011e-01,  4.169643647390908e-01,  1.529603938770566e-02,  
 -8.216846795004334e-01, -7.826199200643963e-01,  1.066116384062461e-02,  
 -8.180509590829773e-01,  9.976706498590422e-01,  8.622182721712620e-04,  
 -8.168446401782580e-01,  9.569871415452944e-01,  4.642547532189030e-03,  
 -8.059705646063106e-01,  8.562279695272285e-01,  9.713220584480500e-03,  
 -7.985378237516410e-01, -6.361943884365141e-01,  1.288799983989059e-02,  
 -7.874963351816394e-01,  7.136737011098295e-01,  1.328855758833727e-02,  
 -7.873181180776506e-01,  1.717693790572155e-01,  1.456745869621430e-02,  
 -7.867043322440256e-01, -2.603635734391026e-01,  1.766717913659451e-02,  
 -7.837010537620064e-01, -4.338871119370292e-01,  1.153873491612521e-02,  
 -7.718371515252632e-01, -9.328817815076849e-01,  6.466448787081487e-03,  
 -7.714891987669056e-01, -4.239834940027459e-02,  1.628468473942501e-02,  
 -7.713192309659846e-01,  5.319196451075733e-01,  1.658253232258541e-02,  
 -7.617253581469365e-01, -9.897388221915862e-01,  2.488625548037977e-03,  
 -7.506982895864639e-01,  3.204233011897250e-01,  1.685029450873451e-02,  
 -7.448534415599564e-01,  9.829922539741698e-01,  3.520796639776173e-03,  
 -7.421873132631707e-01, -8.453867233878035e-01,  1.088288447448831e-02,  
 -7.293425876035039e-01,  9.154064068042572e-01,  8.936809305882937e-03,  
 -7.223446846603496e-01, -7.141244471949223e-01,  1.414814648905025e-02,  
 -7.219135429448188e-01, -5.263185876605118e-01,  1.575035952702964e-02,  
 -7.098617300046203e-01,  7.947984896859370e-01,  1.339686789384787e-02,  
 -6.988495988698514e-01,  4.052943040220409e-01,  9.837663715320634e-03,  
 -6.984909504155071e-01, -1.429846401852013e-01,  1.896573077123497e-02,  
 -6.975652345893874e-01,  9.525558491386997e-02,  2.060322580221702e-02,  
 -6.900736961878055e-01,  6.326479337076335e-01,  1.728656050260011e-02,  
 -6.869058806489352e-01, -3.499362651285792e-01,  2.042431472019608e-02,  
 -6.838451466610610e-01, -9.632238434827868e-01,  5.536575368407264e-03,  
 -6.601354229220036e-01, -9.978926285407612e-01,  1.118308079993473e-03,  
 -6.591611069246858e-01,  9.972971332925751e-01,  1.393373155547319e-03,  
 -6.496630709138930e-01, -8.968850821145237e-01,  9.867235398314472e-03,  
 -6.435615255682987e-01,  4.745725306260367e-01,  1.695728879109135e-02,  
 -6.382152417385206e-01,  9.593302235740115e-01,  6.948544515653850e-03,  
 -6.368057767453273e-01, -6.105621900036199e-01,  1.773677383165920e-02,  
 -6.352930402436240e-01,  2.440334398061165e-01,  2.247199576089053e-02,  
 -6.302597734646941e-01, -7.836990702094097e-01,  1.442675294839290e-02,  
 -6.222316612499560e-01,  8.650945015472389e-01,  1.244266398906457e-02,  
 -6.142105393288021e-01, -3.115349747226613e-02,  1.267213816470802e-02,  
 -5.999445700339456e-01,  7.231403345609435e-01,  1.705107902581306e-02,  
 -5.985364302471942e-01, -2.220826177325775e-01,  2.068460393331641e-02,  
 -5.874715162971924e-01, -4.537860718695650e-01,  2.256935531509155e-02,  
 -5.805876391669599e-01,  1.164148986297675e-02,  1.455966199822115e-02,  
 -5.761875109801690e-01, -9.834901963379014e-01,  4.021379301366000e-03,  
 -5.536892203872140e-01,  5.713476331182120e-01,  2.021949241318215e-02,  
 -5.482191724466468e-01, -9.351120650991530e-01,  7.900752509637180e-03,  
 -5.443795454192639e-01,  3.668375708005358e-01,  2.231767290088453e-02,  
 -5.356710284369979e-01, -6.904452102919497e-01,  1.837686099829941e-02,  
 -5.352962150371631e-01,  9.876776882519422e-01,  4.155389888548638e-03,  
 -5.257781590187137e-01, -8.445781803925743e-01,  1.356203757752880e-02,  
 -5.248342428534777e-01,  9.219407641844128e-01,  1.026387297173803e-02,  
 -5.174066557246780e-01,  1.518777346465177e-01,  2.518880761805230e-02,  
 -5.036594510447880e-01,  8.035723784673375e-01,  1.586067262933542e-02,  
 -5.034025143249927e-01, -3.126938402863565e-01,  2.210632272995924e-02,  
 -4.806633025223544e-01, -1.069134743166169e-01,  2.522706612518943e-02,  
 -4.768202265102032e-01, -5.503872364548488e-01,  2.284324106026750e-02,  
 -4.646325900518826e-01, -9.961732199116691e-01,  1.946334569341992e-03,  
 -4.547884920410544e-01,  6.649539370735507e-01,  1.931316094733287e-02,  
 -4.421806574347436e-01, -9.613324393854693e-01,  6.002473078471003e-03,  
 -4.394327628517760e-01,  4.730023882906435e-01,  2.198395890845260e-02,  
 -4.232998688209890e-01,  2.883435479068856e-01,  2.182550754053004e-02,  
 -4.226231099797195e-01, -7.634216829847481e-01,  1.777618548814907e-02,  
 -4.220890965407914e-01,  9.630811547877729e-01,  6.855160079679186e-03,  
 -4.112420604475592e-01, -8.937882050869647e-01,  1.158849916478484e-02,  
 -4.024593442610409e-01,  8.726238717970590e-01,  1.358874265349387e-02,  
 -4.002269679736949e-01, -4.051442349677620e-01,  2.393039425904835e-02,  
 -3.993267478943860e-01,  5.176385479657997e-02,  2.702588719348437e-02,  
 -3.923849152916527e-01,  9.981789733855365e-01,  1.591517314127669e-03,  
 -3.906313798231402e-01, -1.840437971511796e-01,  1.351522769629539e-02,  
 -3.582740394972692e-01,  7.469437554790193e-01,  1.688419511612995e-02,  
 -3.576445111330830e-01, -6.381016019538316e-01,  2.217271254303683e-02,  
 -3.471390596376763e-01,  9.751558114236266e-01,  1.414687365431868e-03,  
 -3.410270978511928e-01,  5.659016258527511e-01,  1.929118341000195e-02,  
 -3.395129208825403e-01, -9.824778005139284e-01,  4.415576863417267e-03,  
 -3.331346997723381e-01,  2.223766929597974e-01,  1.646772259494828e-02,  
 -3.252463389952233e-01, -2.451189274367319e-01,  2.240870404470034e-02,  
 -3.009376392714923e-01, -8.266673670128765e-01,  1.591461362539792e-02,  
 -2.981870657864640e-01,  3.966510337158281e-01,  2.346801013649629e-02,  
 -2.952430335911029e-01,  9.272338125092218e-01,  1.052839956257688e-02,  
 -2.925795365681464e-01, -9.317251622707681e-01,  9.101328501500838e-03,  
 -2.837411558415489e-01, -4.979776736270173e-01,  2.506976148361703e-02,  
 -2.806344135463510e-01, -4.809162882996374e-02,  2.782770459634624e-02,  
 -2.656701164804061e-01,  8.179772293299151e-01,  1.481544909528898e-02,  
 -2.542370551980483e-01,  9.856209199785680e-01,  4.824829120437116e-03,  
 -2.521259754556285e-01, -9.973002828723974e-01,  1.620836943142523e-03,  
 -2.497736261853112e-01,  6.474134806850792e-01,  1.852942792640709e-02,  
 -2.494952225569154e-01,  1.582011504522273e-01,  2.190214882403085e-02,  
 -2.324705240257510e-01, -7.170067419800342e-01,  2.080073547457119e-02,  
 -2.104466559805069e-01, -3.406566669476734e-01,  2.720075219951604e-02,  
 -2.099261409117430e-01,  4.786906023524469e-01,  1.185954144951369e-02,  
 -1.861486176729608e-01, -9.634767979371285e-01,  6.737017697973697e-03,  
 -1.756023068664000e-01, -8.797164554325823e-01,  1.312819960371862e-02,  
 -1.662816084102881e-01,  8.799028024337228e-01,  1.284862663386604e-02,  
 -1.657193846143792e-01,  3.172098063693634e-01,  2.614101117655917e-02,  
 -1.615402128474088e-01, -1.512617629404641e-01,  2.870683831769700e-02,  
 -1.562119970212992e-01, -5.878544646273842e-01,  2.490102418715279e-02,  
 -1.534073739178984e-01,  7.313740308801530e-01,  1.907865171993343e-02,  
 -1.468820128344276e-01,  7.454986763836169e-02,  2.515116960979389e-02,  
 -1.456132526020360e-01,  9.547929947534334e-01,  8.009904149647161e-03,  
 -1.411022235577947e-01,  5.402822094147779e-01,  1.985276171591949e-02,  
 -1.145203437993708e-01,  9.971336236185711e-01,  1.976988745961730e-03,  
 -1.083747697202039e-01, -9.898130243123879e-01,  3.355317427073141e-03,  
 -1.034956048479747e-01, -7.889452083356127e-01,  1.855933599799289e-02,  
 -9.518052933052586e-02, -4.313306509695957e-01,  2.120680416955437e-02,  
 -5.764780880949349e-02, -9.255412926001291e-01,  1.041178057147584e-02,  
 -4.945963945071411e-02,  8.139429446246940e-01,  1.695154845553709e-02,  
 -4.694483372115068e-02,  2.260246749730705e-01,  2.750563040286702e-02,  
 -3.710556308317932e-02, -2.550849012394165e-01,  2.916267630869709e-02,  
 -3.589386545922083e-02, -2.053720558161740e-02,  2.801912438135100e-02,  
 -3.529301810325418e-02,  4.374449384609287e-01,  2.490206851452144e-02,  
 -3.174169125194722e-02,  6.397258205734582e-01,  2.335214947901313e-02,  
 -2.807946922203877e-02,  9.747008686677923e-01,  4.510619199652917e-03,  
 -2.585228714382427e-02, -6.752836809385544e-01,  2.280749223644548e-02,  
 -1.289238997994259e-02, -4.843864246438258e-01,  1.556053198827482e-02,  
 -1.223860458201907e-02,  9.149372658820439e-01,  1.142835906607102e-02,  
 -1.086355028359328e-02, -9.753777328721651e-01,  3.249297484258564e-03,  
 2.708179220842590e-02, -8.547719772455804e-01,  1.569718188959173e-02,  
 4.149479523966346e-02, -9.979599963961665e-01,  1.565335881756029e-03,  
 5.689776414251970e-02,  9.891551358091155e-01,  3.282255117781437e-03,  
 6.075582703243104e-02, -5.668334256989663e-01,  1.153844244336376e-02,  
 7.101224496756312e-02, -9.575012140957714e-01,  6.335543760258588e-03,  
 7.535912927721751e-02,  1.235303669187323e-01,  2.997948351699728e-02,  
 7.592224478984431e-02,  7.415381032881689e-01,  2.029679101450883e-02,  
 7.750653209648602e-02,  3.539562134043134e-01,  2.426431231808029e-02,  
 8.652690668833830e-02, -1.247447983933045e-01,  2.991558956158543e-02,  
 9.446479482059529e-02, -3.553535264925528e-01,  2.880322792020771e-02,  
 9.779012576626916e-02,  5.494194161163839e-01,  2.608420815396981e-02,  
 1.012772299308512e-01, -7.581900569606719e-01,  1.947312434746350e-02,  
 1.030203458432020e-01,  8.661062919924195e-01,  1.346630675248675e-02,  
 1.062220246130106e-01, -5.577336014290080e-01,  1.363056491610594e-02,  
 1.327284751168050e-01,  9.519418660538810e-01,  9.110450516946341e-03,  
 1.563331097859266e-01, -9.095402453421066e-01,  1.228782579110563e-02,  
 1.701527767472629e-01,  9.984157843452909e-01,  1.295448963991591e-03,  
 1.741393635207433e-01, -9.854144027813655e-01,  4.755824748909084e-03,  
 1.879938370487562e-01,  2.630174862645962e-01,  2.621178775149382e-02,  
 2.002223207104934e-01, -6.587656605309330e-01,  2.189481233525649e-02,  
 2.033135424032844e-01,  1.226680906571880e-02,  3.091880266293206e-02,  
 2.073867973374402e-01,  6.656736012079840e-01,  2.289758057394497e-02,  
 2.165364146034749e-01,  8.131469595412018e-01,  1.546367066744115e-02,  
 2.186815288972714e-01, -2.296610279178752e-01,  2.995732867358852e-02,  
 2.218162837289157e-01, -4.581289072758777e-01,  2.642830689906846e-02,  
 2.263761239474323e-01,  4.557960959181672e-01,  2.667293537062659e-02,  
 2.289231298283811e-01, -8.289790576270621e-01,  1.613294129345465e-02,  
 2.527251024651854e-01,  9.135017973841686e-01,  1.092935602260977e-02,  
 2.621462888782247e-01,  9.816181546275472e-01,  5.528965474505003e-03,  
 2.823739032553990e-01, -9.532140949241149e-01,  8.906935903531529e-03,  
 2.955081211245678e-01,  1.689963046033540e-01,  2.153510784480399e-02,  
 2.985636391106877e-01, -9.974664868313298e-01,  1.671486096091834e-03,  
 3.232078531359192e-01, -7.439006988246658e-01,  1.855709405036384e-02,  
 3.279464627695976e-01, -5.713898766443788e-01,  2.281029102796516e-02,  
 3.338179507930596e-01,  5.793637325547847e-01,  2.428395685755850e-02,  
 3.362148410933743e-01, -9.818025366828656e-02,  3.019903785775920e-02,  
 3.385127772310140e-01,  7.540230240429753e-01,  1.856265624620952e-02,  
 3.419562637644176e-01, -3.435538342382597e-01,  2.733858964505634e-02,  
 3.471461374896801e-01,  3.553265509457362e-01,  2.648696947548793e-02,  
 3.502303936426706e-01, -8.883940691302195e-01,  1.279371820180086e-02,  
 3.556091773799562e-01,  8.707051502073961e-01,  1.047555741127083e-02,  
 3.556899139550058e-01,  1.128080696436079e-01,  1.321188723958388e-02,  
 3.841288497521308e-01,  9.553718729947618e-01,  8.119912907486298e-03,  
 3.946422029579690e-01,  9.964039498775228e-01,  2.112349660084158e-03,  
 4.050330117544253e-01, -9.814927725279841e-01,  5.157104944908028e-03,  
 4.362849601968560e-01,  9.019016117216835e-01,  2.940968659036344e-03,  
 4.379541949910271e-01, -6.683641513610455e-01,  1.846439396156306e-02,  
 4.420456441645449e-01, -4.713347319581990e-01,  2.365595165327062e-02,  
 4.472336730065484e-01, -8.167105914183533e-01,  1.590868587912039e-02,  
 4.492188628877602e-01,  3.464784069711753e-02,  2.599642724440654e-02,  
 4.516598503772268e-01, -2.248848786742561e-01,  2.605750990330061e-02,  
 4.534848886303145e-01,  4.821787086314744e-01,  2.470370157097336e-02,  
 4.558094575502872e-01,  6.776999314380787e-01,  2.063485603141766e-02,  
 4.597299209841112e-01,  2.512300079082298e-01,  2.520816228387497e-02,  
 4.664792245356821e-01, -9.343321639127969e-01,  9.316460572589282e-03,  
 4.676049536388429e-01,  8.280983665613982e-01,  1.378155136701219e-02,  
 5.125021470312456e-01, -9.961912026741276e-01,  1.787642568838215e-03,  
 5.134945143382650e-01,  9.255730990320611e-01,  8.514600636975230e-03,  
 5.166884966564118e-01,  9.825109005210685e-01,  5.038395003621559e-03,  
 5.363347257603982e-01, -1.095695413413886e-01,  1.941023977299713e-02,  
 5.399965994699566e-01, -5.859352676802068e-01,  1.854304744927082e-02,  
 5.464942478849923e-01, -3.640970433686203e-01,  2.338117168332904e-02,  
 5.581611838771341e-01, -7.440467570644548e-01,  1.656347514164712e-02,  
 5.627502014020098e-01, -8.788042385170552e-01,  1.221723450900345e-02,  
 5.642272201418791e-01,  3.770370382758487e-01,  2.374317220254762e-02,  
 5.673319233898169e-01,  5.874729567335129e-01,  2.128053054223834e-02,  
 5.674460469518047e-01,  1.540150684251285e-01,  2.257605869396812e-02,  
 5.707186911322696e-01,  7.641772183668017e-01,  1.625295655282468e-02,  
 5.742168074270232e-01, -9.682555557935811e-01,  5.994073320670981e-03,  
 5.959490795665168e-01, -1.948187074408299e-02,  1.530634182479124e-02,  
 6.062396124913686e-01,  8.797986377073432e-01,  1.088748308713618e-02,  
 6.229319420659956e-01,  9.975455983379399e-01,  1.521861509028911e-03,  
 6.295610198351687e-01, -4.991220308747384e-01,  1.739885853059415e-02,  
 6.324276873199660e-01, -2.471665977726898e-01,  2.093917940469638e-02,  
 6.355497887094055e-01, -9.952129871832354e-01,  1.099875629037961e-03,  
 6.410901541595502e-01,  9.583614862393586e-01,  7.156911768526562e-03,  
 6.605190644019022e-01, -6.630669125378098e-01,  1.682341496394070e-02,  
 6.618975494369205e-01, -8.156394553988217e-01,  1.300052108247076e-02,  
 6.673842000772493e-01,  2.749077536864489e-01,  2.067282662025163e-02,  
 6.680484006462090e-01, -9.288814872355221e-01,  8.563893166362068e-03,  
 6.686812125950333e-01,  4.866788467643654e-01,  2.039892342110449e-02,  
 6.700985984918092e-01,  6.842265838658567e-01,  1.713021812997701e-02,  
 6.769960821664744e-01,  8.318062288950726e-02,  1.684726166034979e-02,  
 6.859697885605170e-01, -1.260093282101731e-01,  1.484254174402420e-02,  
 6.926497230416636e-01, -9.859783123599433e-01,  2.705348861376380e-03,  
 6.959863573791213e-01,  8.238747062055407e-01,  1.204055197449034e-02,  
 6.977679871466710e-01, -4.161601763333563e-01,  1.335373628024542e-02,  
 7.368622503416473e-01,  9.864017859775360e-01,  3.620239739614126e-03,  
 7.375774852972609e-01,  9.169799988402917e-01,  8.825252453784535e-03,  
 7.438254372505340e-01, -3.279021941386523e-01,  1.463105332863874e-02,  
 7.440253522657176e-01, -1.400891582182774e-02,  1.425466175849190e-02,  
 7.495595182168627e-01, -5.717554727395397e-01,  1.640815363214294e-02,  
 7.530771473618030e-01, -7.446510104634911e-01,  1.295670791695812e-02,  
 7.544901018164238e-01, -8.766498669907319e-01,  9.526725213141853e-03,  
 7.587437942011223e-01,  5.908863410878806e-01,  1.647006558144315e-02,  
 7.593851565749156e-01,  3.839941762215441e-01,  1.723107403577913e-02,  
 7.639885454115690e-01,  1.980228289731446e-01,  1.519597994741737e-02,  
 7.685687728456019e-01, -9.630400573145438e-01,  5.001848985499082e-03,  
 7.770428027301898e-01, -9.982843164373418e-01,  8.745652562061165e-04,  
 7.772871884934368e-01,  7.542035650256003e-01,  1.251996742574017e-02,  
 7.825025147503595e-01, -1.834533183514675e-01,  1.579709193200259e-02,  
 8.150533231289440e-01,  1.014695483551139e-01,  1.256924687457834e-02,  
 8.181863818318679e-01, -4.606542231051104e-01,  1.549715675497659e-02,  
 8.193847399280907e-01,  8.611191119341332e-01,  9.398125531125533e-03,  
 8.207989728131910e-01,  9.591480451070792e-01,  5.279791002982384e-03,  
 8.297368239121403e-01, -6.631813144059097e-01,  1.224002342014436e-02,  
 8.320106005459350e-01, -8.152569987720697e-01,  9.323523497601202e-03,  
 8.320408056110908e-01,  9.977249436063439e-01,  1.033282992509946e-03,  
 8.329105693070811e-01,  4.871128705837552e-01,  1.348907133473504e-02,  
 8.365337282424045e-01, -9.243522188950283e-01,  6.014070108326465e-03,  
 8.434092146075628e-01, -5.376676824572151e-02,  1.449901864773636e-02,  
 8.449004755072183e-01,  3.093947633052660e-01,  1.245158207072536e-02,  
 8.465147750656848e-01,  6.700666235615695e-01,  1.175161455116867e-02,  
 8.478350019505928e-01, -2.985362344057802e-01,  1.366010228359022e-02,  
 8.496498343126059e-01, -9.871021978521631e-01,  2.415904636287212e-03,  
 8.796260274253024e-01,  2.138443454392648e-01,  9.339618669988453e-03,  
 8.845751363465439e-01,  7.907698638866625e-01,  8.893129746809459e-03,  
 8.866321017241603e-01, -5.623269734279417e-01,  1.150129922332423e-02,  
 8.882047697517171e-01,  9.164586294991613e-01,  5.951354500731454e-03,  
 8.938627976408585e-01, -7.430539467366774e-01,  8.289403676208404e-03,  
 8.949156789984212e-01,  5.661161599991380e-01,  8.566550012330865e-03,  
 8.954010799494210e-01, -8.753539964754327e-01,  5.837845483486322e-03,  
 8.973716972615503e-01,  9.833889194543620e-01,  2.511910121955958e-03,  
 9.001148478941252e-01, -1.724880329303405e-01,  1.268999061952536e-02,  
 9.023269610303840e-01,  6.533036389509404e-02,  1.173221023616003e-02,  
 9.023726303973623e-01, -9.609883325303766e-01,  3.360315770311110e-03,  
 9.081093855357991e-01, -3.974545530931652e-01,  1.116292038350684e-02,  
 9.082458364338479e-01,  4.160787215946197e-01,  9.411679613649818e-03,  
 9.201288583031026e-01, -9.973298211676691e-01,  7.257268851225051e-04,  
 9.288000531532276e-01,  7.013943012440006e-01,  7.037823616626887e-03,  
 9.329884007773763e-01,  3.304494336614532e-01,  5.904281068176790e-03,  
 9.384251860650527e-01,  8.571626242598636e-01,  5.623306077628070e-03,  
 9.387709463419280e-01, -6.569247138091421e-01,  7.505461254587439e-03,  
 9.390362481895664e-01, -8.140965237093258e-01,  4.977781534664430e-03,  
 9.431435157432486e-01,  5.870360626983142e-01,  5.191324447454316e-03,  
 9.450773084819802e-01, -9.221219392424895e-01,  3.393763295106028e-03,  
 9.453915273808479e-01,  1.895221840939932e-01,  8.348594654611519e-03,  
 9.456536724677754e-01,  9.539239527027603e-01,  3.022785644899445e-03,  
 9.473577935390517e-01, -5.193485262434305e-02,  9.670046203567387e-03,  
 9.489719119922718e-01,  9.971737186812124e-01,  6.141238201223769e-04,  
 9.513861085801828e-01, -2.782244198545041e-01,  9.083776210637055e-03,  
 9.524619245554554e-01, -5.009630638627496e-01,  7.585592261208418e-03,  
 9.570396759412962e-01, -9.818217124953741e-01,  1.504963278061301e-03,  
 9.651084193076095e-01,  4.764381514817677e-01,  6.804854306822511e-03,  
 9.673991604949321e-01,  7.692810312148867e-01,  4.520963014240378e-03,  
 9.730917870009820e-01, -7.458190017187750e-01,  4.241383153444730e-03,  
 9.734392697290727e-01, -8.673592113403571e-01,  2.810476896561892e-03,  
 9.763607543792061e-01,  3.048040261918404e-01,  5.276457875981873e-03,  
 9.768475228065115e-01,  9.082588824000043e-01,  2.643888308901319e-03,  
 9.782469107965639e-01,  7.857190536343943e-02,  6.186986811631052e-03,  
 9.798711093359943e-01,  6.455315254229357e-01,  4.130331043787127e-03,  
 9.801558211147705e-01,  9.831284518138658e-01,  1.028657890512397e-03,  
 9.817934561418729e-01, -6.004957048608559e-01,  4.153182683219009e-03,  
 9.822023634787357e-01, -9.520064075525696e-01,  1.488447743427078e-03,  
 9.824823278531268e-01, -1.588192490530472e-01,  5.597811173658705e-03,  
 9.824823551297321e-01, -3.937517188889684e-01,  5.138454426652030e-03,  
 9.866504547608295e-01, -9.955835634824257e-01,  3.961208092085676e-04,  
 9.905327362354205e-01,  8.309506492911954e-01,  2.069825511375866e-03,  
 9.942355332758673e-01,  3.974103619286143e-01,  2.413263541158905e-03,  
 9.945084471405289e-01,  5.494932527943799e-01,  2.193364858292885e-03,  
 9.945305554986960e-01, -8.135327323625892e-01,  1.514406390792948e-03,  
 9.947615068172242e-01,  9.545658333888697e-01,  7.423836783813612e-04,  
 9.949517157579387e-01, -9.067668333653325e-01,  9.864959809811758e-04,  
 9.957818259075973e-01,  1.993953840265955e-01,  2.396827736651728e-03,  
 9.962141216868449e-01, -6.903174371098946e-01,  1.476800783658664e-03,  
 9.968687603178163e-01, -2.875773812112470e-02,  2.072108287711335e-03,  
 9.971393163063961e-01,  7.214186037213960e-01,  1.344741266208887e-03,  
 9.972431159527100e-01, -5.064881469083564e-01,  1.610896725802623e-03,  
 9.974246740827564e-01,  9.967061334165134e-01,  1.310709895846009e-04,  
 9.974788575004648e-01, -2.791676769769759e-01,  1.765107353951216e-03,  
 9.989309477716464e-01, -9.759800757253289e-01,  2.868352447506991e-04,  
 9.999408488515129e-01,  8.953088235569292e-01,  3.456123608241670e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr45 ( )

/******************************************************************************/
/*
  Purpose:

    SMR45 returns the SMR rule of degree 45.

  Discussion:
 
    DEGREE: 45
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 359
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR45[3*359], the requested rule.
*/
{
  const int degree = 45;
  int order;
  double xw[3*359] = {
 -9.987809239831112e-01,  9.748368623655366e-01,  2.993356033786765e-04,  
 -9.985808631696838e-01, -8.990756328646153e-01,  5.055415778287732e-04,  
 -9.985157152594889e-01, -9.971971012987678e-01,  9.821637011466654e-05,
 -9.976075303722897e-01,  2.495954379536609e-01,  1.726273349986223e-03,  
 -9.975896723770977e-01, -7.481282641542352e-01,  1.186765908765057e-03,  
 -9.970359077153589e-01, -4.973042782590862e-03,  1.976200444087838e-03,  
 -9.970034303329453e-01,  4.805125358625656e-01,  1.717119689979895e-03,  
 -9.961579504388610e-01, -2.339319461038794e-01,  2.197631276825098e-03,  
 -9.959759411587524e-01,  8.966138075526434e-01,  9.460145783264427e-04,  
 -9.955607724070924e-01,  6.629654417179892e-01,  1.734396121578630e-03,  
 -9.944882643568679e-01, -5.822713014974841e-01,  2.130704201950450e-03,  
 -9.944839549832385e-01, -4.305503528241359e-01,  2.332655357182134e-03,  
 -9.943103084508153e-01, -9.589447862560037e-01,  7.154329251248137e-04,  
 -9.942971011761540e-01,  7.923589246102194e-01,  1.676928772166950e-03,  
 -9.879109700683048e-01, -8.401442342078335e-01,  2.254477068544381e-03,  
 -9.871570448287768e-01,  9.953040717606414e-01,  4.014919822858868e-04,  
 -9.834657898675960e-01,  9.464917816489062e-01,  1.606043238725865e-03,  
 -9.833305319309631e-01,  1.263457021753157e-01,  5.419689142545006e-03,  
 -9.826246063168834e-01,  3.638393037687699e-01,  5.148686860161606e-03,  
 -9.810868050137430e-01, -9.856276869865556e-01,  8.700281868935982e-04,  
 -9.802648322311707e-01, -6.750032224988851e-01,  3.955250863364047e-03,  
 -9.799852473516794e-01,  5.711769167233038e-01,  4.435133168562443e-03,  
 -9.796202659342652e-01, -1.139693876952825e-01,  5.831373899382246e-03,  
 -9.771712814502167e-01, -3.337491350874086e-01,  5.138702967736385e-03,  
 -9.753612107572261e-01,  8.542575822594997e-01,  2.939880020404475e-03,  
 -9.750871880034563e-01, -9.181022714139108e-01,  2.418384903446744e-03,  
 -9.712009645368384e-01,  7.236074445113848e-01,  4.632318546295927e-03,  
 -9.664706318878840e-01, -5.062808601831001e-01,  6.514641073677681e-03,  
 -9.635773411406924e-01, -7.811935286068071e-01,  4.341305455620128e-03,  
 -9.592551721099858e-01,  9.800077457957908e-01,  1.583793112109460e-03,  
 -9.527470555424390e-01,  2.452206198184587e-01,  8.934499397490152e-03,  
 -9.512217505973695e-01, -9.975809114133117e-01,  5.139248565810932e-04,  
 -9.509238027788980e-01,  4.671808125048466e-01,  7.778845637088972e-03,  
 -9.502795953661248e-01,  1.665956085226044e-02,  9.244882696179383e-03,  
 -9.483846862528557e-01,  9.121585564057219e-01,  3.515812117215462e-03,  
 -9.464214946937899e-01, -2.174055880473181e-01,  8.183789662861353e-03,  
 -9.462416352500443e-01, -9.599078291538412e-01,  2.602348449588172e-03,  
 -9.419837071661598e-01, -6.127904283944557e-01,  5.775655266427641e-03,  
 -9.391238991374505e-01,  7.989714235337833e-01,  5.179018142204592e-03,  
 -9.378086513718291e-01, -8.695603466712696e-01,  5.169665843353311e-03,  
 -9.370137281757169e-01,  6.282649414142087e-01,  7.623356356150477e-03,  
 -9.356961338262859e-01, -3.645584063625137e-01,  6.010631113438040e-03,  
 -9.253974646921507e-01, -7.190198240417008e-01,  6.336440252338264e-03,  
 -9.248470794804491e-01,  9.972632014604238e-01,  7.216535092722727e-04,  
 -9.102216394091136e-01,  9.552115242137005e-01,  3.429119254261080e-03,  
 -9.090014113055961e-01, -4.456272486278706e-01,  9.085459391365453e-03,  
 -9.077061721157841e-01,  3.609878414025458e-01,  1.119544980789453e-02,  
 -9.044718083850251e-01, -9.248380504679798e-02,  1.138730334189965e-02,  
 -9.041052183788196e-01,  1.370275081676114e-01,  1.231280001099448e-02,  
 -9.003272138921747e-01, -9.855131239038005e-01,  2.142261107197177e-03,  
 -8.998267130073949e-01,  8.611867551994773e-01,  5.652454680674074e-03,  
 -8.964517879623641e-01,  7.184571948644249e-01,  8.121078281162448e-03,  
 -8.906894622641233e-01, -5.845154566197192e-01,  8.308665412941993e-03,  
 -8.897286914429898e-01, -9.254565139699565e-01,  5.359918872844426e-03,  
 -8.856328610403172e-01,  5.303622802964915e-01,  1.168547747268816e-02,  
 -8.854742809240306e-01, -8.063045923419880e-01,  8.148233321624298e-03,  
 -8.834346561856141e-01, -2.466770217389220e-01,  9.493619529933141e-03,  
 -8.629850430376032e-01,  9.846794003258130e-01,  2.528739364876000e-03,  
 -8.506693908403453e-01,  9.125903996034499e-01,  5.849578632842550e-03,  
 -8.492900289400127e-01,  2.609008872385714e-01,  1.361563690700432e-02,  
 -8.474472786288211e-01, -6.901503323404313e-01,  1.100649739704037e-02,  
 -8.464217718205864e-01,  2.909630308393418e-02,  1.381846696789304e-02,  
 -8.459950759889058e-01, -3.370889407226870e-01,  1.214993895881173e-02,  
 -8.408627217827968e-01,  7.927942230163550e-01,  9.201701596927991e-03,  
 -8.370863536953854e-01, -9.980212613540562e-01,  8.867352167594041e-04,  
 -8.323965789758532e-01,  6.377990761410410e-01,  1.217271062025909e-02,  
 -8.314738798895785e-01, -5.062045685366845e-01,  1.274593131055984e-02,  
 -8.240227041551308e-01, -9.642226450420159e-01,  4.656297575580126e-03,  
 -8.233464165343024e-01, -8.728783340437961e-01,  8.558990866905701e-03,  
 -8.220591736941830e-01, -1.243862989299787e-01,  1.244606872559087e-02,  
 -8.188844823185363e-01,  4.261617662513782e-01,  1.558630923706844e-02,  
 -7.969896207737629e-01,  9.976480667995195e-01,  9.937781058818520e-04,  
 -7.918069891410763e-01,  9.552496571182889e-01,  5.247432489034864e-03,  
 -7.839313303459738e-01,  1.577452094536468e-01,  1.531782499550762e-02,  
 -7.808186099816705e-01, -7.721253866618816e-01,  1.174558344919606e-02,  
 -7.735975996435843e-01,  8.594993334079274e-01,  9.569255855638928e-03,  
 -7.673513409414942e-01, -2.186521333866828e-01,  1.604398689184609e-02,  
 -7.634767876646369e-01, -6.119083101507623e-01,  1.551125361015980e-02,  
 -7.604924395747599e-01, -4.040521641808663e-01,  1.640483106687547e-02,  
 -7.598303762668254e-01,  7.223972889507986e-01,  1.294995516437059e-02,  
 -7.546147648023375e-01,  5.450635784714123e-01,  1.627134395977775e-02,  
 -7.477268693062509e-01, -1.178617906350497e-03,  1.534766967987536e-02,  
 -7.441981398623979e-01, -9.248122192057350e-01,  7.952214175998626e-03,  
 -7.411794309655517e-01, -9.883378955524539e-01,  3.149005459627492e-03,  
 -7.396577473534641e-01,  3.065734892201429e-01,  1.696772838146242e-02,  
 -7.173231621338175e-01,  9.835540032598186e-01,  3.576914417052623e-03,  
 -7.013275658365165e-01, -8.389991135422733e-01,  1.116556601175833e-02,  
 -6.972792709156885e-01,  9.171883050550365e-01,  8.783301477841914e-03,  
 -6.889056647928331e-01,  4.105476960488628e-01,  1.322143695866550e-02,  
 -6.791491171576957e-01, -9.973182946735697e-02,  1.835334682967442e-02,  
 -6.785344806438597e-01, -7.028760007459759e-01,  1.603405486470507e-02,  
 -6.778885853526038e-01,  7.985598896411525e-01,  1.305296371184325e-02,  
 -6.767414083720775e-01,  1.216983833611472e-01,  1.702881131982138e-02,  
 -6.767037258823436e-01, -5.089593879681761e-01,  1.929956845223450e-02,  
 -6.693168433164310e-01, -2.985847484238517e-01,  2.053896928599153e-02,  
 -6.681575030734345e-01,  6.391753535023200e-01,  1.675821395824656e-02,  
 -6.490686401640144e-01, -9.624589736537986e-01,  6.433329913117225e-03,  
 -6.299677977917032e-01,  9.975283667931077e-01,  1.307683705358367e-03,  
 -6.269567681651597e-01,  4.853810354287711e-01,  1.557881532766953e-02,  
 -6.251430706398415e-01, -9.977234181855117e-01,  1.373432556349576e-03,  
 -6.246231931149462e-01,  2.373991342623364e-01,  1.859631127917601e-02,  
 -6.135737153470906e-01, -8.913530795649121e-01,  9.807279239964804e-03,  
 -6.099509227115107e-01,  9.609069768683841e-01,  6.626684869311525e-03,  
 -5.906682339894699e-01,  8.667890507859654e-01,  1.214231245428204e-02,  
 -5.902315633378371e-01,  7.656704700409119e-03,  1.553617180174587e-02,  
 -5.827340699533451e-01, -7.799185004279106e-01,  1.506550662060840e-02,  
 -5.800597214330994e-01, -6.076368281751579e-01,  1.994641910743171e-02,  
 -5.731297492992956e-01,  7.245305917039069e-01,  1.666027168900788e-02,  
 -5.720751096895411e-01, -1.782643294102043e-01,  2.248088421841022e-02,  
 -5.704963535556302e-01, -4.059198759788438e-01,  2.319074978994265e-02,  
 -5.499812366523558e-01,  3.491130804137083e-01,  2.143412266902755e-02,  
 -5.413499891114516e-01,  5.699276014351697e-01,  1.818656471958422e-02,  
 -5.404313099098355e-01,  7.035913506382468e-02,  1.450685080017977e-02,  
 -5.241201775879956e-01, -9.836142249086132e-01,  4.533301530515161e-03,  
 -5.211800788850269e-01, -9.318333678975942e-01,  7.829122810295861e-03,  
 -5.091471437000489e-01,  9.883443269909445e-01,  3.852866247300155e-03,  
 -4.999904832068175e-01,  9.243318111693436e-01,  9.722335283461081e-03,  
 -4.827891808826871e-01, -8.404726014611830e-01,  1.259532628864143e-02,  
 -4.758599005186578e-01,  8.031297625877543e-01,  1.563421315582868e-02,  
 -4.739367439717606e-01, -6.948299595246461e-01,  1.902025287597122e-02,  
 -4.725182717643259e-01,  1.906085429772531e-01,  2.556026449129186e-02,  
 -4.685979592711882e-01, -2.811429587683000e-01,  2.475198280486229e-02,  
 -4.617764304558508e-01, -5.116467385712951e-01,  2.392689042225338e-02,  
 -4.543098644742484e-01, -6.357162836142750e-02,  2.429812363005727e-02,  
 -4.514514457659036e-01,  4.524814600085829e-01,  2.178659688025009e-02,  
 -4.454674266029482e-01, -9.088658429301943e-01,  1.921862701385430e-03,  
 -4.442220408374918e-01,  6.539255470454639e-01,  1.815962112706960e-02,  
 -4.037641494006043e-01, -9.963492843723524e-01,  2.019937935352191e-03,  
 -3.994965424916097e-01,  9.652033889320616e-01,  6.696722911338705e-03,  
 -3.949679284272561e-01, -9.580785434262290e-01,  7.330895788726833e-03,  
 -3.839587310522242e-01,  8.749726658353748e-01,  1.286006475529313e-02,  
 -3.774779250407504e-01, -8.809520347205344e-01,  9.629793742675348e-03,  
 -3.724254271641495e-01,  3.180527134728118e-01,  2.421744890018692e-02,  
 -3.706962390305071e-01, -1.391738691222885e-01,  1.415158967598348e-02,  
 -3.635222351976187e-01,  9.976906542407633e-01,  1.690203137096647e-03,  
 -3.634271195533723e-01, -7.666438656111270e-01,  1.659518137533172e-02,  
 -3.588134811520187e-01, -3.863706837941547e-01,  2.562066896160286e-02,  
 -3.511410895989978e-01,  7.598657097017213e-02,  2.910832017440310e-02,  
 -3.466859823064926e-01,  7.342599349174546e-01,  1.755602838304911e-02,  
 -3.437157470820955e-01, -6.085084561101284e-01,  2.330640521520084e-02,  
 -3.427496011843691e-01,  5.493351398103018e-01,  2.167791054401352e-02,  
 -2.977464025093953e-01, -2.106175113605862e-01,  2.369155711000212e-02,  
 -2.841131225980947e-01,  2.454441303908954e-01,  1.128244322556367e-02,  
 -2.838181184983802e-01,  9.294716603915232e-01,  9.657842880004704e-03,  
 -2.734308898435502e-01, -9.821535582823072e-01,  5.186520389550382e-03,  
 -2.686875707529910e-01, -9.183318465397052e-01,  1.013872822805395e-02,  
 -2.659505623760141e-01,  9.790699184449342e-01,  2.972586627418943e-03,  
 -2.597785379692306e-01,  8.165639824525108e-01,  1.545056567597512e-02,  
 -2.524367426587176e-01,  4.306497620594896e-01,  2.413813532250804e-02,  
 -2.521254582882448e-01, -8.208877915065049e-01,  1.380175215808280e-02,  
 -2.416100067508830e-01, -4.864539918350533e-01,  2.540579845521675e-02,  
 -2.295904421272411e-01,  6.423345387430144e-01,  2.156902469663802e-02,  
 -2.257486484336952e-01, -3.648215238588141e-02,  2.987778176615610e-02,  
 -2.220343030041925e-01,  1.957161674328358e-01,  2.195717424950444e-02,  
 -2.179684508686903e-01, -6.927362944979131e-01,  2.155320590936663e-02,  
 -2.125785431554086e-01,  9.877070401926165e-01,  3.018182936437289e-03,  
 -1.882237242340730e-01, -9.986463574985669e-01,  1.183175228276184e-03,  
 -1.861290129251524e-01, -3.113784253755371e-01,  2.679220781431789e-02,  
 -1.612964698946688e-01,  8.840734468407453e-01,  1.245957990550999e-02,  
 -1.460578395314807e-01, -9.538340166911464e-01,  8.610066632546907e-03,  
 -1.453751285806197e-01,  5.230712405315956e-01,  1.269762461159384e-02,  
 -1.367296766455244e-01,  7.427957482907744e-01,  1.891959592837709e-02,  
 -1.361199669288722e-01, -8.678102051101638e-01,  1.300544655252503e-02,  
 -1.297519722477037e-01,  3.446333134156687e-01,  2.525956832091458e-02,  
 -1.260626917855079e-01,  9.523539560424874e-01,  7.832872314688318e-03,  
 -1.171007843208515e-01, -5.778453790284559e-01,  2.438894687265387e-02,  
 -1.122739223228800e-01,  1.017082445961973e-01,  2.710215456491743e-02,  
 -1.036241515184341e-01, -1.486588557732932e-01,  2.899957751330600e-02,  
 -9.450221416605288e-02,  5.591570240316848e-01,  1.413344321715599e-02,  
 -9.300307584944975e-02,  9.974712889340351e-01,  1.727683826252121e-03,  
 -8.814000629237449e-02, -7.646007397219974e-01,  1.862769502398370e-02,  
 -7.747007763111526e-02, -4.031347072028282e-01,  2.085048513843114e-02,  
 -7.227524974688553e-02, -9.894515397095711e-01,  3.355911821480428e-03,  
 -4.023801246392568e-02,  8.277576362873151e-01,  1.555793756126800e-02,  
 -2.080615617949091e-02,  9.742774768032481e-01,  4.593636973363114e-03,  
 -1.411339171791895e-02,  2.524618422545646e-01,  2.675098480014549e-02,  
 -1.258443439627821e-02, -9.143387117035456e-01,  1.160220639371127e-02,  
 -9.858909067684239e-03,  6.635856125497768e-01,  2.179583092424484e-02,  
 -9.552055799839686e-03,  4.656768245300902e-01,  1.833743720043940e-02,  
 0.000000000000000e+00,  0.000000000000000e+00,  2.726382862976956e-02,  
 9.552055799839686e-03, -4.656768245300902e-01,  1.833743720043940e-02,  
 9.858909067684239e-03, -6.635856125497768e-01,  2.179583092424484e-02,  
 1.258443439627821e-02,  9.143387117035456e-01,  1.160220639371127e-02,  
 1.411339171791895e-02, -2.524618422545646e-01,  2.675098480014549e-02,  
 2.080615617949091e-02, -9.742774768032481e-01,  4.593636973363114e-03,  
 4.023801246392568e-02, -8.277576362873151e-01,  1.555793756126800e-02,  
 7.227524974688553e-02,  9.894515397095711e-01,  3.355911821480428e-03,  
 7.747007763111526e-02,  4.031347072028282e-01,  2.085048513843114e-02,  
 8.814000629237449e-02,  7.646007397219974e-01,  1.862769502398370e-02,  
 9.300307584944975e-02, -9.974712889340351e-01,  1.727683826252121e-03,  
 9.450221416605288e-02, -5.591570240316848e-01,  1.413344321715599e-02,  
 1.036241515184341e-01,  1.486588557732932e-01,  2.899957751330600e-02,  
 1.122739223228800e-01, -1.017082445961973e-01,  2.710215456491743e-02,  
 1.171007843208515e-01,  5.778453790284559e-01,  2.438894687265387e-02,  
 1.260626917855079e-01, -9.523539560424874e-01,  7.832872314688318e-03,  
 1.297519722477037e-01, -3.446333134156687e-01,  2.525956832091458e-02,  
 1.361199669288722e-01,  8.678102051101638e-01,  1.300544655252503e-02,  
 1.367296766455244e-01, -7.427957482907744e-01,  1.891959592837709e-02,  
 1.453751285806197e-01, -5.230712405315956e-01,  1.269762461159384e-02,  
 1.460578395314807e-01,  9.538340166911464e-01,  8.610066632546907e-03,  
 1.612964698946688e-01, -8.840734468407453e-01,  1.245957990550999e-02,  
 1.861290129251524e-01,  3.113784253755371e-01,  2.679220781431789e-02,  
 1.882237242340730e-01,  9.986463574985669e-01,  1.183175228276184e-03,  
 2.125785431554086e-01, -9.877070401926165e-01,  3.018182936437289e-03,  
 2.179684508686903e-01,  6.927362944979131e-01,  2.155320590936663e-02,  
 2.220343030041925e-01, -1.957161674328358e-01,  2.195717424950444e-02,  
 2.257486484336952e-01,  3.648215238588141e-02,  2.987778176615610e-02,  
 2.295904421272411e-01, -6.423345387430144e-01,  2.156902469663802e-02,  
 2.416100067508830e-01,  4.864539918350533e-01,  2.540579845521675e-02,  
 2.521254582882448e-01,  8.208877915065049e-01,  1.380175215808280e-02,  
 2.524367426587176e-01, -4.306497620594896e-01,  2.413813532250804e-02,  
 2.597785379692306e-01, -8.165639824525108e-01,  1.545056567597512e-02,  
 2.659505623760141e-01, -9.790699184449342e-01,  2.972586627418943e-03,  
 2.686875707529910e-01,  9.183318465397052e-01,  1.013872822805395e-02,  
 2.734308898435502e-01,  9.821535582823072e-01,  5.186520389550382e-03,  
 2.838181184983802e-01, -9.294716603915232e-01,  9.657842880004704e-03,  
 2.841131225980947e-01, -2.454441303908954e-01,  1.128244322556367e-02,  
 2.977464025093953e-01,  2.106175113605862e-01,  2.369155711000212e-02,  
 3.427496011843691e-01, -5.493351398103018e-01,  2.167791054401352e-02,  
 3.437157470820955e-01,  6.085084561101284e-01,  2.330640521520084e-02,  
 3.466859823064926e-01, -7.342599349174546e-01,  1.755602838304911e-02,  
 3.511410895989978e-01, -7.598657097017213e-02,  2.910832017440310e-02,  
 3.588134811520187e-01,  3.863706837941547e-01,  2.562066896160286e-02,  
 3.634271195533723e-01,  7.666438656111270e-01,  1.659518137533172e-02,  
 3.635222351976187e-01, -9.976906542407633e-01,  1.690203137096647e-03,  
 3.706962390305071e-01,  1.391738691222885e-01,  1.415158967598348e-02,  
 3.724254271641495e-01, -3.180527134728118e-01,  2.421744890018692e-02,  
 3.774779250407504e-01,  8.809520347205344e-01,  9.629793742675348e-03,  
 3.839587310522242e-01, -8.749726658353748e-01,  1.286006475529313e-02,  
 3.949679284272561e-01,  9.580785434262290e-01,  7.330895788726833e-03,  
 3.994965424916097e-01, -9.652033889320616e-01,  6.696722911338705e-03,  
 4.037641494006043e-01,  9.963492843723524e-01,  2.019937935352191e-03,  
 4.442220408374918e-01, -6.539255470454639e-01,  1.815962112706960e-02,  
 4.454674266029482e-01,  9.088658429301943e-01,  1.921862701385430e-03,  
 4.514514457659036e-01, -4.524814600085829e-01,  2.178659688025009e-02,  
 4.543098644742484e-01,  6.357162836142750e-02,  2.429812363005727e-02,  
 4.617764304558508e-01,  5.116467385712951e-01,  2.392689042225338e-02,  
 4.685979592711882e-01,  2.811429587683000e-01,  2.475198280486229e-02,  
 4.725182717643259e-01, -1.906085429772531e-01,  2.556026449129186e-02,  
 4.739367439717606e-01,  6.948299595246461e-01,  1.902025287597122e-02,  
 4.758599005186578e-01, -8.031297625877543e-01,  1.563421315582868e-02,  
 4.827891808826871e-01,  8.404726014611830e-01,  1.259532628864143e-02,  
 4.999904832068175e-01, -9.243318111693436e-01,  9.722335283461081e-03,  
 5.091471437000489e-01, -9.883443269909445e-01,  3.852866247300155e-03,  
 5.211800788850269e-01,  9.318333678975942e-01,  7.829122810295861e-03,  
 5.241201775879956e-01,  9.836142249086132e-01,  4.533301530515161e-03,  
 5.404313099098355e-01, -7.035913506382468e-02,  1.450685080017977e-02,  
 5.413499891114516e-01, -5.699276014351697e-01,  1.818656471958422e-02,  
 5.499812366523558e-01, -3.491130804137083e-01,  2.143412266902755e-02,  
 5.704963535556302e-01,  4.059198759788438e-01,  2.319074978994265e-02,  
 5.720751096895411e-01,  1.782643294102043e-01,  2.248088421841022e-02,  
 5.731297492992956e-01, -7.245305917039069e-01,  1.666027168900788e-02,  
 5.800597214330994e-01,  6.076368281751579e-01,  1.994641910743171e-02,  
 5.827340699533451e-01,  7.799185004279106e-01,  1.506550662060840e-02,  
 5.902315633378371e-01, -7.656704700409119e-03,  1.553617180174587e-02,  
 5.906682339894699e-01, -8.667890507859654e-01,  1.214231245428204e-02,  
 6.099509227115107e-01, -9.609069768683841e-01,  6.626684869311525e-03,  
 6.135737153470906e-01,  8.913530795649121e-01,  9.807279239964804e-03,  
 6.246231931149462e-01, -2.373991342623364e-01,  1.859631127917601e-02,  
 6.251430706398415e-01,  9.977234181855117e-01,  1.373432556349576e-03,  
 6.269567681651597e-01, -4.853810354287711e-01,  1.557881532766953e-02,  
 6.299677977917032e-01, -9.975283667931077e-01,  1.307683705358367e-03,  
 6.490686401640144e-01,  9.624589736537986e-01,  6.433329913117225e-03,  
 6.681575030734345e-01, -6.391753535023200e-01,  1.675821395824656e-02,  
 6.693168433164310e-01,  2.985847484238517e-01,  2.053896928599153e-02,  
 6.767037258823436e-01,  5.089593879681761e-01,  1.929956845223450e-02,  
 6.767414083720775e-01, -1.216983833611472e-01,  1.702881131982138e-02,  
 6.778885853526038e-01, -7.985598896411525e-01,  1.305296371184325e-02,  
 6.785344806438597e-01,  7.028760007459759e-01,  1.603405486470507e-02,  
 6.791491171576957e-01,  9.973182946735697e-02,  1.835334682967442e-02,  
 6.889056647928331e-01, -4.105476960488628e-01,  1.322143695866550e-02,  
 6.972792709156885e-01, -9.171883050550365e-01,  8.783301477841914e-03,  
 7.013275658365165e-01,  8.389991135422733e-01,  1.116556601175833e-02,  
 7.173231621338175e-01, -9.835540032598186e-01,  3.576914417052623e-03,  
 7.396577473534641e-01, -3.065734892201429e-01,  1.696772838146242e-02,  
 7.411794309655517e-01,  9.883378955524539e-01,  3.149005459627492e-03,  
 7.441981398623979e-01,  9.248122192057350e-01,  7.952214175998626e-03,  
 7.477268693062509e-01,  1.178617906350497e-03,  1.534766967987536e-02,  
 7.546147648023375e-01, -5.450635784714123e-01,  1.627134395977775e-02,  
 7.598303762668254e-01, -7.223972889507986e-01,  1.294995516437059e-02,  
 7.604924395747599e-01,  4.040521641808663e-01,  1.640483106687547e-02,  
 7.634767876646369e-01,  6.119083101507623e-01,  1.551125361015980e-02,  
 7.673513409414942e-01,  2.186521333866828e-01,  1.604398689184609e-02,  
 7.735975996435843e-01, -8.594993334079274e-01,  9.569255855638928e-03,  
 7.808186099816705e-01,  7.721253866618816e-01,  1.174558344919606e-02,  
 7.839313303459738e-01, -1.577452094536468e-01,  1.531782499550762e-02,  
 7.918069891410763e-01, -9.552496571182889e-01,  5.247432489034864e-03,  
 7.969896207737629e-01, -9.976480667995195e-01,  9.937781058818520e-04,  
 8.188844823185363e-01, -4.261617662513782e-01,  1.558630923706844e-02,  
 8.220591736941830e-01,  1.243862989299787e-01,  1.244606872559087e-02,  
 8.233464165343024e-01,  8.728783340437961e-01,  8.558990866905701e-03,  
 8.240227041551308e-01,  9.642226450420159e-01,  4.656297575580126e-03,  
 8.314738798895785e-01,  5.062045685366845e-01,  1.274593131055984e-02,  
 8.323965789758532e-01, -6.377990761410410e-01,  1.217271062025909e-02,  
 8.370863536953854e-01,  9.980212613540562e-01,  8.867352167594041e-04,  
 8.408627217827968e-01, -7.927942230163550e-01,  9.201701596927991e-03,  
 8.459950759889058e-01,  3.370889407226870e-01,  1.214993895881173e-02,  
 8.464217718205864e-01, -2.909630308393418e-02,  1.381846696789304e-02,  
 8.474472786288211e-01,  6.901503323404313e-01,  1.100649739704037e-02,  
 8.492900289400127e-01, -2.609008872385714e-01,  1.361563690700432e-02,  
 8.506693908403453e-01, -9.125903996034499e-01,  5.849578632842550e-03,  
 8.629850430376032e-01, -9.846794003258130e-01,  2.528739364876000e-03,  
 8.834346561856141e-01,  2.466770217389220e-01,  9.493619529933141e-03,  
 8.854742809240306e-01,  8.063045923419880e-01,  8.148233321624298e-03,  
 8.856328610403172e-01, -5.303622802964915e-01,  1.168547747268816e-02,  
 8.897286914429898e-01,  9.254565139699565e-01,  5.359918872844426e-03,  
 8.906894622641233e-01,  5.845154566197192e-01,  8.308665412941993e-03,  
 8.964517879623641e-01, -7.184571948644249e-01,  8.121078281162448e-03,  
 8.998267130073949e-01, -8.611867551994773e-01,  5.652454680674074e-03,  
 9.003272138921747e-01,  9.855131239038005e-01,  2.142261107197177e-03,  
 9.041052183788196e-01, -1.370275081676114e-01,  1.231280001099448e-02,  
 9.044718083850251e-01,  9.248380504679798e-02,  1.138730334189965e-02,  
 9.077061721157841e-01, -3.609878414025458e-01,  1.119544980789453e-02,  
 9.090014113055961e-01,  4.456272486278706e-01,  9.085459391365453e-03,  
 9.102216394091136e-01, -9.552115242137005e-01,  3.429119254261080e-03,  
 9.248470794804491e-01, -9.972632014604238e-01,  7.216535092722727e-04,  
 9.253974646921507e-01,  7.190198240417008e-01,  6.336440252338264e-03,  
 9.356961338262859e-01,  3.645584063625137e-01,  6.010631113438040e-03,  
 9.370137281757169e-01, -6.282649414142087e-01,  7.623356356150477e-03,  
 9.378086513718291e-01,  8.695603466712696e-01,  5.169665843353311e-03,  
 9.391238991374505e-01, -7.989714235337833e-01,  5.179018142204592e-03,  
 9.419837071661598e-01,  6.127904283944557e-01,  5.775655266427641e-03,  
 9.462416352500443e-01,  9.599078291538412e-01,  2.602348449588172e-03,  
 9.464214946937899e-01,  2.174055880473181e-01,  8.183789662861353e-03,  
 9.483846862528557e-01, -9.121585564057219e-01,  3.515812117215462e-03,  
 9.502795953661248e-01, -1.665956085226044e-02,  9.244882696179383e-03,  
 9.509238027788980e-01, -4.671808125048466e-01,  7.778845637088972e-03,  
 9.512217505973695e-01,  9.975809114133117e-01,  5.139248565810932e-04,  
 9.527470555424390e-01, -2.452206198184587e-01,  8.934499397490152e-03,  
 9.592551721099858e-01, -9.800077457957908e-01,  1.583793112109460e-03,  
 9.635773411406924e-01,  7.811935286068071e-01,  4.341305455620128e-03,  
 9.664706318878840e-01,  5.062808601831001e-01,  6.514641073677681e-03,  
 9.712009645368384e-01, -7.236074445113848e-01,  4.632318546295927e-03,  
 9.750871880034563e-01,  9.181022714139108e-01,  2.418384903446744e-03,  
 9.753612107572261e-01, -8.542575822594997e-01,  2.939880020404475e-03,  
 9.771712814502167e-01,  3.337491350874086e-01,  5.138702967736385e-03,  
 9.796202659342652e-01,  1.139693876952825e-01,  5.831373899382246e-03,  
 9.799852473516794e-01, -5.711769167233038e-01,  4.435133168562443e-03,  
 9.802648322311707e-01,  6.750032224988851e-01,  3.955250863364047e-03,  
 9.810868050137430e-01,  9.856276869865556e-01,  8.700281868935982e-04,  
 9.826246063168834e-01, -3.638393037687699e-01,  5.148686860161606e-03,  
 9.833305319309631e-01, -1.263457021753157e-01,  5.419689142545006e-03,  
 9.834657898675960e-01, -9.464917816489062e-01,  1.606043238725865e-03,  
 9.871570448287768e-01, -9.953040717606414e-01,  4.014919822858868e-04,  
 9.879109700683048e-01,  8.401442342078335e-01,  2.254477068544381e-03,  
 9.942971011761540e-01, -7.923589246102194e-01,  1.676928772166950e-03,  
 9.943103084508153e-01,  9.589447862560037e-01,  7.154329251248137e-04,  
 9.944839549832385e-01,  4.305503528241359e-01,  2.332655357182134e-03,  
 9.944882643568679e-01,  5.822713014974841e-01,  2.130704201950450e-03,  
 9.955607724070924e-01, -6.629654417179892e-01,  1.734396121578630e-03,  
 9.959759411587524e-01, -8.966138075526434e-01,  9.460145783264427e-04,  
 9.961579504388610e-01,  2.339319461038794e-01,  2.197631276825098e-03,  
 9.970034303329453e-01, -4.805125358625656e-01,  1.717119689979895e-03,  
 9.970359077153589e-01,  4.973042782590862e-03,  1.976200444087838e-03,  
 9.975896723770977e-01,  7.481282641542352e-01,  1.186765908765057e-03,  
 9.976075303722897e-01, -2.495954379536609e-01,  1.726273349986223e-03,  
 9.985157152594889e-01,  9.971971012987678e-01,  9.821637011466654e-05,
 9.985808631696838e-01,  8.990756328646153e-01,  5.055415778287732e-04,  
 9.987809239831112e-01, -9.748368623655366e-01,  2.993356033786765e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr46 ( )

/******************************************************************************/
/*
  Purpose:

    SMR46 returns the SMR rule of degree 46.

  Discussion:
 
    DEGREE: 46
    POINTS CARDINALITY: 387
    NORM INF MOMS. RESIDUAL: 2.03396e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR46[3*387], the requested rule.
*/
{
  const int degree = 46;
  int order;
  double xw[3*387] = {
 -9.983111423300403e-01,  5.288463379177194e-01,  1.077877162071936e-03,  
 -9.980165536240384e-01,  9.771577113964515e-01,  3.358785950069629e-04,  
 -9.980057366593107e-01,  8.627358726346877e-01,  6.003479857328445e-04,  
 -9.979683379344829e-01, -6.942209080688336e-01,  1.101994373218053e-03,  
 -9.978846063972665e-01,  7.248634355141237e-01,  9.622706165518573e-04,  
 -9.976343783636701e-01, -4.901932224780105e-01,  1.459301786243793e-03,  
 -9.975456640840761e-01,  3.145719096243388e-01,  1.435508298339834e-03,  
 -9.974305941584383e-01, -8.537788458635189e-01,  8.063821753970214e-04,  
 -9.963467450618418e-01, -9.821437303584432e-01,  4.013000811661125e-04,  
 -9.963009121112316e-01, -2.704146437985034e-01,  2.094359395819190e-03,  
 -9.962806106099757e-01,  1.123075934443736e-01,  1.888774287809683e-03,  
 -9.940902248165704e-01, -9.316901409499205e-01,  8.495707747103506e-04,  
 -9.938933215260991e-01, -7.079039559931181e-02,  2.912153811018539e-03,  
 -9.917585881160206e-01,  9.225449661005339e-01,  1.208278868867505e-03,  
 -9.877765791917548e-01,  6.288297749314813e-01,  3.125282998079219e-03,  
 -9.868078584857646e-01,  8.017653629554962e-01,  2.384264480882027e-03,  
 -9.864405958010823e-01, -7.802922340742308e-01,  2.766257703102030e-03,  
 -9.861374381057205e-01,  4.302599938856595e-01,  3.896596604742260e-03,  
 -9.860561184001005e-01,  9.959625949335185e-01,  3.768462609684377e-04,  
 -9.851999106336341e-01, -5.993676873167308e-01,  3.897179923118708e-03,  
 -9.823744385328851e-01,  2.224305198952116e-01,  4.389361116586368e-03,  
 -9.823717033752213e-01, -3.922448187993621e-01,  4.866053077993799e-03,  
 -9.816324879121784e-01, -9.972824585879037e-01,  3.539318490028104e-04,  
 -9.808402316764249e-01, -8.969081857937120e-01,  1.430112081567521e-03,  
 -9.755886861073786e-01,  9.593223831278707e-01,  1.537597902797862e-03,  
 -9.743498206750085e-01, -1.814564543728963e-01,  6.160694758533645e-03,  
 -9.723572538186456e-01, -9.608004605969592e-01,  1.775385419876353e-03,  
 -9.722382292526556e-01,  4.575052264951963e-02,  6.359444615009903e-03,  
 -9.674256064855085e-01,  8.719589137075090e-01,  3.343864470517355e-03,  
 -9.655171991563514e-01,  7.180035091780340e-01,  4.785905400994727e-03,  
 -9.624420464882796e-01, -8.488914199258957e-01,  3.342352186086261e-03,  
 -9.624375637065791e-01,  5.378256410738799e-01,  6.214733942070574e-03,  
 -9.609564853325729e-01, -6.987107790974231e-01,  5.634701956686364e-03,  
 -9.582534487467066e-01,  3.329644217027720e-01,  6.778705946888507e-03,  
 -9.553330912989174e-01, -5.085340714542828e-01,  7.366493334985202e-03,  
 -9.513324008400423e-01,  9.856312840827730e-01,  1.330643418748665e-03,  
 -9.462216299986661e-01, -3.074523531561095e-01,  8.518829293626153e-03,  
 -9.423577772939717e-01, -9.868227254586934e-01,  1.516125769939738e-03,  
 -9.393806145622896e-01, -6.393001117132881e-02,  9.254712550028325e-03,  
 -9.380581290975274e-01, -9.143951836207059e-01,  3.592402661502303e-03,  
 -9.370997481849076e-01,  9.247112445714407e-01,  3.596998195741029e-03,  
 -9.370408950027029e-01,  1.701035315993199e-01,  9.761731824542692e-03,  
 -9.331125695054737e-01,  7.991178696492102e-01,  6.010555876145078e-03,  
 -9.264553050234512e-01,  6.367471939422996e-01,  8.013247394678898e-03,  
 -9.257833020863018e-01, -7.851138118520632e-01,  6.465654027360096e-03,  
 -9.232295614388404e-01,  4.373930707289740e-01,  8.924951728810733e-03,  
 -9.169304968245420e-01, -6.173156236169133e-01,  9.176842979353183e-03,  
 -9.158461010077630e-01,  9.983551814323244e-01,  5.272476313713648e-04,  
 -9.051276758776533e-01, -4.239566904643302e-01,  1.072046479438868e-02,  
 -9.032419077912952e-01, -9.530184538306384e-01,  3.182051544793368e-03,  
 -9.021102524547485e-01, -1.916184311444890e-01,  1.130998717609783e-02,  
 -8.980961459025067e-01,  9.646542499645536e-01,  3.178751154593399e-03,  
 -8.930078393151207e-01, -9.981508615033944e-01,  6.570920554362360e-04,  
 -8.906744958940082e-01,  5.331652102117236e-02,  1.270902532675199e-02,  
 -8.905389004793887e-01,  8.675870875563284e-01,  6.336364651974894e-03,  
 -8.886387309148650e-01,  2.919115286844978e-01,  1.269563275681320e-02,  
 -8.854149145655548e-01, -8.605083285679000e-01,  6.622620311336960e-03,  
 -8.793037622856232e-01,  7.261357982998039e-01,  9.242333645649367e-03,  
 -8.771808942835173e-01,  5.369791516940807e-01,  1.078396362232102e-02,  
 -8.678439739737586e-01, -7.154028908195939e-01,  1.017271142495267e-02,  
 -8.547339766301599e-01, -9.781932956431606e-01,  2.678930288181945e-03,  
 -8.537315103377962e-01, -5.343331860669793e-01,  1.242332352924924e-02,  
 -8.520164840234268e-01, -3.094551247900096e-01,  1.305829147586281e-02,  
 -8.488681825198992e-01,  9.896255593087030e-01,  2.002616403722711e-03,  
 -8.416507788252385e-01, -8.265115783740917e-02,  1.490207091803921e-02,  
 -8.392425787263469e-01,  9.232660535378425e-01,  5.881955508762292e-03,  
 -8.354077924594627e-01, -9.142725948542541e-01,  5.674810428887848e-03,  
 -8.308359345629498e-01,  1.725487547473738e-01,  1.533431714809703e-02,  
 -8.274841967106447e-01,  4.088159141245927e-01,  1.501736541467763e-02,  
 -8.238115079964703e-01,  8.060487501731384e-01,  9.429758324133860e-03,  
 -8.197373702496686e-01,  6.306005588539771e-01,  1.221854856004642e-02,  
 -8.119207537103786e-01, -8.024258568330985e-01,  1.017584060240601e-02,  
 -7.934808337088018e-01, -6.360553805785052e-01,  1.319241564428063e-02,  
 -7.914436664499496e-01, -4.207932036862586e-01,  1.447292693321381e-02,  
 -7.887191070259210e-01, -9.936283345929116e-01,  1.752216334037365e-03,  
 -7.817594477527704e-01,  9.649444494603818e-01,  4.403270919820491e-03,  
 -7.806968676724935e-01, -2.127005818706033e-01,  1.590915338247300e-02,  
 -7.787206463899139e-01, -9.502131272522223e-01,  4.429611018981373e-03,  
 -7.729716977649312e-01,  3.504231727683854e-02,  1.730216063737120e-02,  
 -7.615475168534998e-01,  9.970713335225059e-01,  1.105751104522964e-03,  
 -7.613774270772271e-01,  8.732384669131723e-01,  8.765009909401999e-03,  
 -7.605658209205032e-01,  2.873715524000673e-01,  1.724853309888603e-02,  
 -7.545102898776130e-01,  5.185064654385597e-01,  1.653260406179394e-02,  
 -7.543179046928901e-01,  7.203533180047458e-01,  1.279648077347124e-02,  
 -7.462096105686143e-01, -8.716832704900178e-01,  8.965204163025747e-03,  
 -7.297551839636630e-01, -7.294705145359583e-01,  1.257733002011545e-02,  
 -7.242201288685997e-01, -5.260417553686566e-01,  1.491064590305035e-02,  
 -7.111976203431433e-01, -3.418767681380177e-01,  1.372933284312857e-02,  
 -7.108504678954995e-01, -1.039300655680135e-01,  1.688080640592963e-02,  
 -7.080091377554032e-01, -9.738542524510675e-01,  3.832949073991781e-03,  
 -6.993005032215379e-01,  9.292838315386169e-01,  6.854783787218264e-03,  
 -6.945010624970885e-01,  1.490753875762792e-01,  1.908181406615000e-02,  
 -6.829539157895229e-01,  3.943661912129811e-01,  1.775227360298309e-02,  
 -6.824522164896524e-01,  9.828020464230726e-01,  3.461480537140765e-03,  
 -6.811161448382028e-01,  8.009485101920445e-01,  1.247548617968576e-02,  
 -6.740874841537527e-01, -9.203828537769473e-01,  6.499214840639783e-03,  
 -6.740590762912708e-01,  6.234582056824679e-01,  1.710880207528098e-02,  
 -6.667283792866656e-01, -9.966870351134982e-01,  1.345631389649490e-03,  
 -6.627500062251878e-01, -2.629897031536784e-01,  1.253500094538003e-02,  
 -6.622225214428993e-01, -8.059108267523946e-01,  1.065281011757487e-02,  
 -6.557914154525895e-01, -6.273988439708652e-01,  1.444872151803694e-02,  
 -6.348709267896325e-01, -4.673203468046226e-01,  1.172736214570953e-02,  
 -6.328413233255047e-01, -6.452211008886946e-04,  1.869025751288091e-02,  
 -6.118719359252214e-01,  8.762829386426818e-01,  1.033274390128391e-02,  
 -6.110556896889493e-01,  2.560001034291458e-01,  1.917352404679710e-02,  
 -6.092675868512063e-01,  9.974932063614328e-01,  1.111770360271985e-03,  
 -6.089001735150132e-01,  4.894606407282653e-01,  1.493304221615996e-02,  
 -5.957728962033498e-01, -9.442775669731837e-01,  5.152774389043164e-03,  
 -5.934378260544972e-01, -8.618789798012082e-01,  8.671109578031069e-03,  
 -5.919685431225901e-01,  9.532093633373470e-01,  6.000008339596521e-03,  
 -5.919111534153291e-01, -3.881929105751961e-01,  1.404997546066828e-02,  
 -5.877361965725245e-01, -1.659039454745879e-01,  1.965458127599791e-02,  
 -5.877226304090875e-01,  7.189942447153720e-01,  1.660443704063239e-02,  
 -5.853917259329147e-01, -7.157079059870500e-01,  1.335893581504478e-02,  
 -5.787373200325358e-01, -9.819349338509461e-01,  3.724690335082629e-03,  
 -5.515089331602092e-01, -5.600319273292009e-01,  1.459416036801704e-02,  
 -5.469704321502723e-01,  5.581230180424370e-01,  1.320231485769863e-02,  
 -5.448756607377084e-01,  1.052883744135819e-01,  2.111827618977989e-02,  
 -5.340427010083240e-01,  3.528051735252741e-01,  1.689752990450137e-02,  
 -5.315744106126522e-01,  9.832382229796701e-01,  2.995609026491748e-03,  
 -5.148064070837848e-01,  8.147217984009684e-01,  1.345617174772626e-02,  
 -5.087680119024051e-01, -2.788763652823787e-01,  1.994337766154448e-02,  
 -5.061581233455268e-01, -7.892496183565814e-01,  1.286508149092348e-02,  
 -5.012203894259853e-01, -8.990231192240392e-01,  8.956058330470088e-03,  
 -4.936349963135775e-01, -9.968369463719365e-01,  1.575947703548631e-03,  
 -4.911326875959225e-01,  9.149214659234989e-01,  9.293367007494500e-03,  
 -4.879661301700524e-01, -4.800056817263576e-02,  2.227718283981051e-02,  
 -4.847914361880020e-01, -4.546071876863588e-01,  1.526526777579720e-02,  
 -4.846822250085249e-01, -6.418342427755345e-01,  1.219156161879653e-02,  
 -4.760256114114479e-01,  6.375375872806944e-01,  1.720769987743707e-02,  
 -4.621007151616755e-01, -9.579502546478819e-01,  6.554088731066456e-03,  
 -4.612967110110002e-01,  9.966660407011948e-01,  1.217481758961742e-03,  
 -4.569206283268340e-01,  4.345123071178997e-01,  1.839698391377606e-02,  
 -4.496803127775477e-01,  2.202902900476915e-01,  2.241266821911760e-02,  
 -4.278915134934840e-01,  9.671114926361384e-01,  5.191064069034339e-03,  
 -4.146363040355858e-01,  7.473511052485697e-01,  1.508362820205234e-02,  
 -4.076400871388755e-01, -7.062801223113114e-01,  1.443945184922928e-02,  
 -4.070553182360229e-01, -1.526895844070415e-01,  2.047617240956142e-02,  
 -4.022172104649683e-01, -3.511189153921571e-01,  1.888641854799721e-02,  
 -4.005903401571346e-01, -8.436497390055564e-01,  1.164332051477943e-02,  
 -3.942704527579263e-01, -5.429006006269239e-01,  1.763233210715006e-02,  
 -3.920322092784385e-01,  8.675390012920151e-01,  1.041096047388326e-02,  
 -3.846660086832624e-01,  8.917470150450708e-02,  1.892693797908766e-02,  
 -3.729863115263242e-01, -9.859184869614498e-01,  4.095961239144511e-03,  
 -3.716740791814342e-01,  5.310297213894640e-01,  2.083126621383546e-02,  
 -3.486558657245032e-01, -9.194138838445431e-01,  9.698505131349492e-03,  
 -3.433349546665356e-01,  3.230449465905588e-01,  2.374293118970489e-02,  
 -3.344389712170940e-01,  9.921091261971137e-01,  2.869305970347512e-03,  
 -3.339313518662538e-01,  9.384366607395505e-01,  7.681016742585266e-03,  
 -3.325417016336327e-01,  1.286602408259136e-02,  1.557157921087293e-02,  
 -3.282638864870970e-01, -7.785798295099498e-01,  9.483406458745599e-03,  
 -3.219994475413112e-01,  6.704477854046392e-01,  1.550078134528658e-02,  
 -3.159420291185248e-01,  8.270797065832005e-01,  8.524811430984630e-03,  
 -3.092399396317421e-01, -2.277117057375501e-01,  2.112662086798820e-02,  
 -2.968279429238752e-01, -4.396378070292698e-01,  2.129314196872056e-02,  
 -2.905204845049371e-01, -6.277035890195538e-01,  1.949076619182426e-02,  
 -2.660737641019463e-01,  4.255724500180151e-01,  1.406940792473095e-02,  
 -2.657259347700068e-01, -9.983145161338485e-01,  1.297107633585316e-03,  
 -2.557040513029764e-01, -9.607724968354249e-01,  7.076847711496876e-03,  
 -2.507469864960903e-01,  1.885266112795361e-01,  2.719835405580567e-02,  
 -2.465621618464433e-01, -6.302324636139266e-02,  2.220715080388317e-02,  
 -2.422173156650345e-01,  7.716949471630073e-01,  1.461225419981911e-02,  
 -2.397259575954650e-01, -7.537162650009356e-01,  1.272707785511618e-02,  
 -2.382433304389768e-01, -8.636962693408693e-01,  1.314939728605020e-02,  
 -2.348523931292380e-01,  5.954466740476743e-01,  1.696950549956305e-02,  
 -2.302678163192251e-01,  8.980662833826019e-01,  1.075143067263782e-02,  
 -2.280326790666749e-01,  9.731664665061597e-01,  5.788926660667668e-03,  
 -2.067449089627632e-01, -3.142157476434185e-01,  2.065950705760577e-02,  
 -1.998822841751484e-01,  4.556559275603105e-01,  1.452445159282058e-02,  
 -1.780348710790272e-01, -5.294356781067937e-01,  2.293930129672077e-02,  
 -1.729154221323040e-01,  8.947634588886424e-02,  9.633358448521607e-03,  
 -1.679785686773150e-01,  9.977004810664578e-01,  1.580660537042458e-03,  
 -1.513615578790225e-01, -1.408023440657114e-01,  1.999321020575889e-02,  
 -1.510049533511834e-01, -9.857568554875824e-01,  4.171489211283228e-03,  
 -1.397908366129535e-01, -6.831910361461173e-01,  1.843457361864874e-02,  
 -1.388453696223859e-01, -9.202453076597740e-01,  1.063712403558069e-02,  
 -1.364042879497747e-01,  3.148557325219815e-01,  2.642864804518861e-02,  
 -1.357676378587967e-01, -3.700839091893132e-01,  1.007003471287555e-02,  
 -1.341336818342906e-01,  6.962786900689967e-01,  1.930661907444524e-02,  
 -1.268063328385695e-01,  8.405755822951979e-01,  1.421554079635553e-02,  
 -1.159584802313210e-01,  6.193763651449499e-02,  2.189180449837289e-02,  
 -1.136601056222965e-01,  9.411644534061605e-01,  8.852548392145691e-03,  
 -1.021809090852591e-01, -8.116890139416293e-01,  1.638446296121459e-02,  
 -9.957974534510225e-02,  5.465537117483713e-01,  1.936985897602384e-02,  
 -6.013303858641021e-02, -2.228487583791975e-01,  2.265701874040998e-02,  
 -5.169586652442786e-02,  9.835122859254263e-01,  4.824215443618791e-03,  
 -5.139510564692561e-02, -4.291434980038135e-01,  2.272752478914381e-02,  
 -3.882804828978392e-02, -9.973934768928572e-01,  1.457851894270487e-03,  
 -3.342710705704959e-02,  2.161596108865151e-01,  2.137936125066629e-02,  
 -3.218752249323631e-02, -9.607936917182006e-01,  7.314373566869228e-03,  
 -3.017152289296703e-02, -5.994190919388979e-01,  2.040979936959506e-02,  
 -1.867008238226461e-02,  4.362811533647392e-01,  2.208258553134326e-02,  
 -1.343806034595350e-02,  7.734825117081163e-01,  1.719967834300143e-02,  
 -1.185114610879654e-02, -3.481367504384966e-02,  2.423341772064624e-02,  
 -7.919342463364545e-04,  8.945837010426477e-01,  1.232847827313112e-02,  
 4.919452919873997e-03, -8.809812407295396e-01,  1.354090072320326e-02,  
 1.305827593618624e-02,  6.297679760756248e-01,  2.008240810469282e-02,  
 1.779271432032194e-02, -7.377081209970429e-01,  1.876486052772664e-02,  
 4.884160865441580e-02,  1.507066653383158e-01,  1.871250815547388e-02,  
 5.990126302514630e-02,  9.969795355703539e-01,  1.692710307507148e-03,  
 6.006717209602051e-02, -3.083136689294216e-01,  2.565724966279625e-02,  
 6.393909219067830e-02,  3.594993165616777e-01,  1.509548787122363e-02,  
 7.175408292024850e-02,  9.554637730216967e-01,  8.306658405607603e-03,  
 7.525461672292501e-02, -5.160683941502094e-01,  1.874790249909374e-02,  
 8.110183649610606e-02, -9.867585187826022e-01,  4.076210204008766e-03,  
 8.141967150319139e-02, -1.189705745248058e-01,  2.032608743176999e-02,  
 1.124880105553899e-01, -9.359171673996224e-01,  9.571932927888115e-03,  
 1.165489339636398e-01,  8.367961024670041e-01,  1.506162267493892e-02,  
 1.210277013276357e-01,  7.092707728848469e-01,  1.701632734469468e-02,  
 1.226974308970525e-01,  5.269692986000968e-01,  2.428603200993640e-02,  
 1.229083911931521e-01, -8.182540440119128e-01,  1.570235696766660e-02,  
 1.350112470613993e-01, -6.538504393209962e-01,  2.030628583177083e-02,  
 1.399181256835766e-01,  3.015348908887893e-01,  2.019291503816718e-02,  
 1.404257985465581e-01,  6.092746217029241e-02,  2.461307617903064e-02,  
 1.537383644071319e-01, -4.285399646581668e-01,  1.729562302093782e-02,  
 1.793831484355051e-01,  9.848486617613754e-01,  4.373304719358010e-03,  
 1.885276528802143e-01, -1.946570197424425e-01,  2.437822908681812e-02,  
 1.913490446236383e-01,  9.136669626572853e-01,  1.136057870401207e-02,  
 1.950733760684369e-01, -9.988883757089664e-01,  1.115917379491008e-03,  
 2.202349038604578e-01, -8.872502852695510e-01,  1.183870475738118e-02,  
 2.266103135304583e-01, -9.724019023500025e-01,  6.089563321336039e-03,  
 2.334514056216084e-01,  2.100250708586558e-01,  2.242983008197881e-02,  
 2.346890297758962e-01, -7.430696053291979e-01,  1.611144382586636e-02,  
 2.371854897054120e-01,  6.277158377811654e-01,  1.998985840392359e-02,  
 2.381551058710785e-01, -2.728024275968237e-02,  1.867617065182177e-02,  
 2.403845626744464e-01, -5.494371080987960e-01,  1.919163292548581e-02,  
 2.406566753219083e-01,  7.709850451400717e-01,  1.548587357826445e-02,  
 2.437892485634663e-01,  4.312692590040306e-01,  2.500208999773301e-02,  
 2.457113471217321e-01, -3.504488987179999e-01,  2.076259214573411e-02,  
 2.787975217317672e-01,  9.987709148054594e-01,  1.074439970173681e-03,  
 2.874526689515157e-01,  9.610687558161728e-01,  6.639643775994492e-03,  
 3.050701074537157e-01,  8.576858834243071e-01,  1.330354503175670e-02,  
 3.079020816595327e-01, -6.341747220801298e-01,  1.232930413128336e-02,  
 3.129207107515677e-01, -8.153811415487545e-01,  1.088352641587536e-02,  
 3.235238534770942e-01, -9.348385551501034e-01,  8.405733683243891e-03,  
 3.249461420324165e-01,  1.195055866712430e-01,  2.059445277234703e-02,  
 3.259332646765282e-01, -8.115322717293480e-02,  1.921450979679603e-02,  
 3.418019449964280e-01, -9.921627760081128e-01,  2.876179862337243e-03,  
 3.441463742468578e-01, -2.507586930846943e-01,  2.246920139880491e-02,  
 3.454157311797964e-01,  3.196442608280841e-01,  1.949168155726703e-02,  
 3.522858087462989e-01,  5.473292954828115e-01,  2.052211824025522e-02,  
 3.550612724894830e-01, -4.622644021251900e-01,  2.237322821452582e-02,  
 3.628206389441777e-01,  6.996588792810672e-01,  1.611470867455308e-02,  
 3.803124073211717e-01,  9.267629522530908e-01,  7.864925821108384e-03,  
 3.837527955162833e-01, -7.107409299987680e-01,  1.416444264486913e-02,  
 3.851917500153872e-01,  9.887591655242265e-01,  3.339189896709617e-03,  
 3.854269547410605e-01, -8.618469546717433e-01,  9.610742279852392e-03,  
 4.019225793782901e-01,  4.016798585964549e-01,  1.012917154681300e-02,  
 4.127391066428609e-01,  7.903342236233291e-01,  1.269130304446248e-02,  
 4.206237377241268e-01, -9.659761107125491e-01,  5.178093920336236e-03,  
 4.299310943181327e-01, -5.994572508065145e-01,  1.557080469778748e-02,  
 4.307413834300436e-01,  4.658662181207777e-02,  2.219196980426284e-02,  
 4.405340685608884e-01,  2.335295068344127e-01,  1.865946407826078e-02,  
 4.489137849532947e-01, -1.476957002369098e-01,  2.137580876989588e-02,  
 4.553257248925679e-01, -3.592620025020420e-01,  2.194266456909868e-02,  
 4.596003509315073e-01,  8.854184724628273e-01,  8.841941691903296e-03,  
 4.709725837444826e-01,  4.828558460588853e-01,  1.704907169399865e-02,  
 4.739134209792026e-01, -9.952544731037134e-01,  1.384022073294283e-03,  
 4.744311818429655e-01, -9.091663251538931e-01,  9.407209766944927e-03,  
 4.754339111432121e-01,  9.677012363182328e-01,  5.151968481850169e-03,  
 4.756400085409440e-01, -7.846592391745022e-01,  1.479999552925989e-02,  
 4.797722514467903e-01,  6.266312294749810e-01,  1.517363837511235e-02,  
 5.100902189441707e-01, -5.204709881652611e-01,  1.794265819609321e-02,  
 5.114213495330481e-01,  7.063838369295402e-01,  9.385769008220548e-03,  
 5.154702873160621e-01,  9.970261558990023e-01,  1.418938295959134e-03,  
 5.206787479692746e-01, -9.804693890194831e-01,  2.602127396219503e-03,  
 5.248386664133297e-01,  8.240594713994390e-01,  1.015762604252224e-02,  
 5.292261493359739e-01,  3.532128983853009e-01,  1.761372213704019e-02,  
 5.412455238586017e-01,  1.663089169562654e-01,  1.981488239826455e-02,  
 5.422636874412113e-01, -3.888952643040450e-02,  2.029645493692368e-02,  
 5.490686000308411e-01, -6.800871557244708e-01,  1.778082318788007e-02,  
 5.506497016063064e-01, -2.569823972423157e-01,  2.040618638507255e-02,  
 5.558484982602493e-01,  9.370085805481705e-01,  6.860313942207178e-03,  
 5.730289132425076e-01, -8.539043933599846e-01,  1.199840964520873e-02,  
 5.743172499325917e-01, -9.493748534639627e-01,  6.446458905888820e-03,  
 5.933561550270604e-01, -9.973165046518369e-01,  1.106220941881708e-03,  
 5.958409370787153e-01,  5.800079660836041e-01,  1.671078508710501e-02,  
 5.988069851863091e-01,  7.502260051414449e-01,  1.282898642169325e-02,  
 5.990481942679082e-01, -4.246825001870817e-01,  1.984169743778542e-02,  
 6.005986331257841e-01,  4.554769692975677e-01,  1.334287115720346e-02,  
 6.040160922907698e-01,  9.854671530856786e-01,  2.994287695803976e-03,  
 6.148479609092942e-01,  8.841220860695742e-01,  9.043118053822746e-03,  
 6.290329677665637e-01,  6.473056660736756e-02,  1.770611661233833e-02,  
 6.357508149775565e-01,  2.792335526293019e-01,  1.792883669549749e-02,  
 6.359115381229695e-01, -1.533221513721983e-01,  1.866471728653944e-02,  
 6.428347625670869e-01, -5.860865379095112e-01,  1.800068148760219e-02,  
 6.431770915314418e-01, -7.673033465075149e-01,  1.415629485620442e-02,  
 6.629470916951145e-01, -9.814101628847763e-01,  3.828055463736441e-03,  
 6.635620751159940e-01,  9.669552929922944e-01,  3.573941812000668e-03,  
 6.662663601364237e-01, -9.116551120171078e-01,  8.464264999754742e-03,  
 6.826809651786937e-01,  6.740553403014049e-01,  1.482537895685379e-02,  
 6.841894614722424e-01,  9.991626816274169e-01,  6.403585593440745e-04,  
 6.879813211979059e-01, -3.164327346746020e-01,  1.950390211841089e-02,  
 6.895381114908021e-01,  8.244385950006391e-01,  1.107283514053267e-02,  
 6.951293081922316e-01,  3.848652923305114e-01,  1.205406495559543e-02,  
 7.071941862038644e-01,  1.557551547343111e-01,  1.487157194009795e-02,  
 7.088392130891149e-01,  9.311081105556229e-01,  6.403186257497955e-03,  
 7.103489145184514e-01,  5.128671353459157e-01,  1.447349152743848e-02,  
 7.112523777541994e-01, -5.343627919039270e-02,  1.622337417018616e-02,  
 7.269363794433283e-01, -6.840991876519299e-01,  1.435100659999861e-02,  
 7.279049704858229e-01, -8.426704238412119e-01,  1.045402040085113e-02,  
 7.285342993988090e-01, -4.839061792889138e-01,  1.728103414529436e-02,  
 7.452814605775970e-01, -9.968228546357361e-01,  1.246345264724730e-03,  
 7.453280291188794e-01,  9.911483462347401e-01,  1.772175614234971e-03,  
 7.500124480157498e-01, -9.547637231472251e-01,  5.631122806171691e-03,  
 7.660136246691086e-01,  2.540733190060072e-01,  1.368648950065803e-02,  
 7.691308291829931e-01,  7.612449038860015e-01,  1.157990272462695e-02,  
 7.695653758500861e-01, -2.017051775800784e-01,  1.788941594689514e-02,  
 7.757855546099112e-01,  6.120139510322031e-01,  1.234795524473133e-02,  
 7.783422194325996e-01,  8.857643892793224e-01,  8.021465975032427e-03,  
 7.794925507276567e-01,  3.834881273142750e-02,  1.394353531135586e-02,  
 7.881718171116056e-01,  3.986996175544144e-01,  1.286848339449679e-02,  
 7.897308006236938e-01,  9.695228604931504e-01,  3.758196130226270e-03,  
 8.005617072950878e-01, -7.714759314806717e-01,  1.082717845154526e-02,  
 8.014647958275422e-01, -5.914754924105888e-01,  1.372540088894792e-02,  
 8.048586654976113e-01, -3.760191806026097e-01,  1.578196274558745e-02,  
 8.074198214828329e-01, -9.002944432867208e-01,  7.509326689239254e-03,  
 8.229471194855432e-01, -9.844354012048210e-01,  2.780744450891915e-03,  
 8.350468397869657e-01,  5.190039957049550e-01,  1.164754105169609e-02,  
 8.365299137297749e-01,  1.412585586299757e-01,  1.308242784832346e-02,  
 8.413421178380436e-01, -8.484860532171155e-02,  1.504535328855272e-02,  
 8.458961337160322e-01,  6.994870213051259e-01,  1.009460273201535e-02,  
 8.469985537754668e-01,  8.338344678958003e-01,  8.168632261528704e-03,  
 8.488085430055092e-01,  9.947858132674051e-01,  1.443650552126127e-03,  
 8.500645149945468e-01,  9.373507720718434e-01,  5.137934922700379e-03,  
 8.546242903977276e-01,  3.051629507870270e-01,  1.089091512734386e-02,  
 8.641763900405030e-01, -6.889448486764105e-01,  1.039249251041895e-02,  
 8.659703474188424e-01, -4.920675442015341e-01,  1.232231682369118e-02,  
 8.693776571618932e-01, -9.487224468680494e-01,  4.354062518153025e-03,  
 8.694914780269520e-01, -2.629599405001600e-01,  1.349510193140824e-02,  
 8.700002668817390e-01, -8.383123670557577e-01,  7.781670768080279e-03,  
 8.855489975037527e-01, -9.979953692358957e-01,  7.195696835960152e-04,  
 8.915724133557099e-01,  4.333952149598865e-01,  9.718531146073172e-03,  
 8.968125829421709e-01,  6.154154698482395e-01,  9.130732879751960e-03,  
 8.995352955639010e-01,  3.727433236704860e-02,  1.210455078959554e-02,  
 9.044176738266044e-01,  9.759589325906001e-01,  2.784595965114452e-03,  
 9.047127613663705e-01,  2.206198562862635e-01,  8.552543877154380e-03,  
 9.068881151497454e-01,  7.787953338368784e-01,  7.037593396418797e-03,  
 9.083011281987010e-01,  8.960176782874899e-01,  5.423153331182166e-03,  
 9.173132897326095e-01, -5.972448898522749e-01,  9.084632723408663e-03,  
 9.175159859708392e-01, -9.030480944892180e-01,  4.616231117242107e-03,  
 9.181461241031550e-01, -3.851974576496667e-01,  1.023307955068548e-02,  
 9.208135196421833e-01, -1.434373337472792e-01,  1.050231657558337e-02,  
 9.217303926670013e-01, -7.644491631725594e-01,  7.188933837018584e-03,  
 9.227515342181415e-01, -9.791268272110957e-01,  2.161611001412200e-03,  
 9.390812942639490e-01,  3.458046057721214e-01,  8.001729417607994e-03,  
 9.391736486952373e-01,  5.304895199343252e-01,  7.122316398716251e-03,  
 9.430600573892549e-01,  9.966709231907848e-01,  7.129053481620616e-04,  
 9.454576615044328e-01,  7.052920398449620e-01,  6.071748103577099e-03,  
 9.496345360898582e-01,  1.521627208076305e-01,  7.676594864205592e-03,  
 9.524245393681409e-01,  9.458296922698042e-01,  3.034421018413787e-03,  
 9.549490689468429e-01,  8.452832051303726e-01,  4.625534494986953e-03,  
 9.549952747196216e-01, -8.482826904953155e-01,  3.945366388858040e-03,  
 9.561903566881326e-01, -2.674325744283451e-01,  7.592688481937286e-03,  
 9.574313570023540e-01, -4.955636512788343e-01,  7.063311775228204e-03,  
 9.589118653680453e-01, -9.459098456977220e-01,  2.498821388791289e-03,  
 9.592027558752809e-01, -2.347640435515468e-02,  7.496102409709891e-03,  
 9.609958781667891e-01, -6.801431473140105e-01,  5.715602788126438e-03,  
 9.627398206459263e-01, -9.951247808234173e-01,  6.592649205000905e-04,  
 9.728989108861091e-01,  4.499381661270909e-01,  5.032786439355391e-03,  
 9.740714589903327e-01,  6.233281153298854e-01,  4.526374604487227e-03,  
 9.768548600134053e-01, -7.949632055922030e-01,  2.082313300604911e-03,  
 9.782650771098491e-01,  2.726194163361467e-01,  5.185181641231907e-03,  
 9.786925055378212e-01,  9.827582996544191e-01,  1.141047824238659e-03,  
 9.822091362390636e-01,  7.746068528251591e-01,  3.392981026324791e-03,  
 9.828825653139780e-01, -3.788927753616619e-01,  4.587476394453676e-03,  
 9.831832567744532e-01, -1.495359315198227e-01,  4.796541548146330e-03,  
 9.845823512703257e-01,  9.041799806417141e-01,  2.254648011248501e-03,  
 9.848729561355289e-01, -9.008616462537060e-01,  2.041681903834455e-03,  
 9.858543382964763e-01, -9.755482569442001e-01,  9.339547720854347e-04,  
 9.862811960229013e-01, -5.856501611199811e-01,  3.641915309288278e-03,  
 9.864821493614616e-01,  8.874301057952583e-02,  4.193190248767370e-03,  
 9.891882478301796e-01, -7.505304865321339e-01,  1.890478947988027e-03,  
 9.940951241861832e-01,  5.432137582110499e-01,  2.245016939288178e-03,  
 9.953374929604664e-01,  3.836092124240039e-01,  2.043871336953785e-03,  
 9.960416279394205e-01,  9.972986154465028e-01,  1.461982700921600e-04,  
 9.961174988510967e-01, -9.950835645943196e-01,  1.717741433409342e-04,  
 9.961527671803110e-01,  6.918580060078352e-01,  1.525847569674391e-03,  
 9.966559754610508e-01,  9.557295127448442e-01,  6.302051569265952e-04,  
 9.970214929502554e-01, -2.644098315766063e-01,  1.749852740750748e-03,  
 9.973200872809646e-01, -3.826590124697109e-02,  1.645309636276182e-03,  
 9.973259273035801e-01, -8.408771000383591e-01,  8.974177017096658e-04,  
 9.974702963631498e-01, -4.748457085080076e-01,  1.419898311116791e-03,  
 9.979804912008889e-01,  2.058903880121162e-01,  1.332855555539681e-03,  
 9.980187128543290e-01,  8.423741210647242e-01,  8.934394663320126e-04,  
 9.983634077785508e-01, -9.445962296620326e-01,  4.424225813983324e-04,  
 9.983713812941385e-01, -6.766009567160710e-01,  9.089763434524134e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr47 ( )

/******************************************************************************/
/*
  Purpose:

    SMR47 returns the SMR rule of degree 47.

  Discussion:
 
    DEGREE: 47
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 396
    NORM INF MOMS. RESIDUAL: 1.56234e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR47[3*396], the requested rule.
*/
{
  const int degree = 47;
  int order;
  double xw[3*396] = {
 -9.988860641396040e-01, -2.373189065242698e-01,  1.059226498023405e-03,  
 -9.984308298705356e-01,  6.810115040142974e-01,  8.742573242503645e-04,  
 -9.982849649115821e-01,  9.436218579698744e-01,  4.239310404841323e-04,  
 -9.975891711682796e-01, -9.308337785182597e-01,  5.005025838481359e-04,  
 -9.975758902464168e-01, -8.292104265892648e-01,  8.758182348185454e-04,  
 -9.975527094081703e-01, -6.722468138431469e-01,  1.228393951475139e-03,  
 -9.975229416008712e-01,  8.411146681674510e-01,  8.259054712338016e-04,  
 -9.974354703237893e-01, -9.972347569712511e-01,  1.178428627156954e-04,  
 -9.973323543291763e-01,  4.909591129622543e-01,  1.363609590112511e-03,  
 -9.971337685886393e-01,  7.632359805747738e-02,  1.695014196901724e-03,  
 -9.969508496154019e-01,  9.951320518801803e-01,  1.406624476607038e-04,  
 -9.967221454497780e-01,  2.967880150220837e-01,  1.788242723078713e-03,  
 -9.958488160214992e-01, -4.963853591618409e-01,  1.871218692254807e-03,  
 -9.922776511892646e-01, -3.473204119330540e-01,  2.073619684302503e-03,  
 -9.908388235274806e-01, -8.317660908501920e-02,  3.661061584693876e-03,  
 -9.904720670548077e-01, -9.710213211789278e-01,  8.475646284885832e-04,  
 -9.888702332586248e-01,  7.575946249394171e-01,  2.014228686820058e-03,  
 -9.874342455637046e-01,  9.765233090751630e-01,  8.334380630773419e-04,  
 -9.862543531528728e-01,  5.965690502576685e-01,  3.417223744136484e-03,  
 -9.858704720189189e-01,  9.012846007723281e-01,  1.872665686706367e-03,  
 -9.844078028285480e-01, -7.576106510429415e-01,  3.160151211848773e-03,  
 -9.842497345754406e-01, -8.869330623714193e-01,  2.084899867143594e-03,  
 -9.830502038887345e-01,  1.855914572695679e-01,  4.596336081266426e-03,  
 -9.817085463008139e-01,  4.080671844783566e-01,  4.517002995396259e-03,  
 -9.808958789729733e-01, -5.936214063681421e-01,  4.206620288925534e-03,  
 -9.763487274404036e-01,  8.040608258571258e-01,  1.735576449905203e-03,  
 -9.758618568064553e-01, -4.021500807907098e-01,  4.191420631437088e-03,  
 -9.739747222412156e-01, -2.170070835355472e-01,  5.848357083847142e-03,  
 -9.698875102419363e-01, -9.910520236356811e-01,  8.725558215646179e-04,  
 -9.668937072725421e-01,  9.958238219074350e-01,  5.454007647675571e-04,  
 -9.667753163257026e-01,  3.477910291429498e-02,  6.924394568068183e-03,  
 -9.629858793094620e-01, -9.381408744361764e-01,  2.554368802597983e-03,  
 -9.625096668136147e-01,  9.481536769647175e-01,  2.281103018635964e-03,  
 -9.621099147673235e-01,  6.897553564879744e-01,  5.294641784299885e-03,  
 -9.575259606392211e-01,  8.526222258903702e-01,  3.522351032086693e-03,  
 -9.565093211986069e-01, -8.285414929426780e-01,  4.524164566301950e-03,  
 -9.560668264177599e-01,  2.992407743127743e-01,  7.187486995447770e-03,  
 -9.551892905468934e-01,  5.215279150021472e-01,  6.895698107002057e-03,  
 -9.529413061166492e-01, -6.848663302380273e-01,  6.115869631822169e-03,  
 -9.499379163273817e-01, -4.990544089847970e-01,  7.157918511939649e-03,  
 -9.417225429447996e-01, -1.010399506491120e-01,  8.545115482104066e-03,  
 -9.376385227666459e-01, -3.149592118756698e-01,  8.640152266819899e-03,  
 -9.296009678982454e-01,  1.579161826917062e-01,  1.000831611323566e-02,  
 -9.294596181015237e-01,  9.813684731390790e-01,  1.920664927315008e-03,  
 -9.278797101416244e-01, -9.706959780392181e-01,  2.420070122891078e-03,  
 -9.250982605210959e-01,  7.735956141038276e-01,  6.643173932293495e-03,  
 -9.231065278766845e-01,  9.076886759912991e-01,  4.277169811976498e-03,  
 -9.217831985976003e-01, -9.985289666041468e-01,  5.078696283821862e-04,  
 -9.195935562112217e-01, -8.913327000110681e-01,  5.052649337869474e-03,  
 -9.181270575285391e-01,  4.122328505086459e-01,  9.601387120539102e-03,  
 -9.148831482219597e-01,  6.224206774261293e-01,  8.741538710357355e-03,  
 -9.106078414366331e-01, -7.633798877459725e-01,  7.390023577666990e-03,  
 -9.082567296294581e-01, -5.961320469495873e-01,  9.396878139328617e-03,  
 -8.956547894973423e-01, -1.969077394197896e-01,  1.052048363646446e-02,  
 -8.947837985257842e-01,  1.554349304099888e-02,  1.207505504176275e-02,  
 -8.934682220664112e-01, -4.216540388538755e-01,  1.073747532386832e-02,  
 -8.887805555572472e-01,  9.980469645264131e-01,  6.927987848988626e-04,  
 -8.788480167168854e-01,  2.792330855544344e-01,  1.282453595081661e-02,  
 -8.781614570655271e-01,  9.532957838212304e-01,  3.986319116448455e-03,  
 -8.763285336755390e-01,  8.465920091250118e-01,  7.228076122988736e-03,  
 -8.707970024861261e-01, -9.370668393694276e-01,  4.607127648721668e-03,  
 -8.676827987392443e-01,  5.159125990270553e-01,  1.149515499866792e-02,  
 -8.651527837557776e-01, -9.866988624485060e-01,  2.118506810134428e-03,  
 -8.624098290914860e-01,  7.126189995166746e-01,  9.861047155006141e-03,  
 -8.592237506008711e-01, -8.341324721077372e-01,  7.928559898856604e-03,  
 -8.522596697975072e-01, -6.840670787785538e-01,  1.062952046635244e-02,  
 -8.422263654558482e-01, -3.015292326049363e-01,  1.287800406757572e-02,  
 -8.373962094750010e-01, -5.186387354716220e-01,  1.230119470881243e-02,  
 -8.369983523769275e-01,  1.347222940319437e-01,  1.460708731761451e-02,  
 -8.357310902097985e-01, -9.723800805043467e-02,  1.374148019748794e-02,  
 -8.269374328956414e-01,  9.850869495918245e-01,  2.648428928686930e-03,  
 -8.179672372442700e-01,  9.076223036675563e-01,  6.892206214578204e-03,  
 -8.148639002101447e-01,  3.932890823416910e-01,  1.520502153610768e-02,  
 -8.058634520423256e-01,  6.117159879145377e-01,  1.279254088338618e-02,  
 -8.004833550779242e-01,  7.919528617574970e-01,  1.006437035257496e-02,  
 -7.983956784496398e-01, -8.914942533713631e-01,  7.267362334258530e-03,  
 -7.966190004094728e-01, -9.968334127996725e-01,  1.036781499468538e-03,  
 -7.957314634069883e-01, -9.607527680221649e-01,  4.059074074883998e-03,  
 -7.862399052534020e-01, -7.635989572508247e-01,  1.120659033007899e-02,  
 -7.766600189797701e-01, -4.041663776132322e-01,  1.451699415444131e-02,  
 -7.752582668662442e-01,  1.137400097769025e-02,  1.483822376274713e-02,  
 -7.718688019814154e-01, -6.087164044214350e-01,  1.281755532683666e-02,  
 -7.664905651113335e-01, -2.123608448367788e-01,  1.521536630069221e-02,  
 -7.658473206792390e-01,  2.470075232375816e-01,  1.699291241018386e-02,  
 -7.570188231121615e-01,  9.562983797766917e-01,  5.269367781364454e-03,  
 -7.480114600555077e-01,  9.967592933390678e-01,  1.243409201000067e-03,  
 -7.391128608011459e-01,  5.011842297262301e-01,  1.677675545049549e-02,  
 -7.344946046482385e-01,  7.002770707813594e-01,  1.339498521201928e-02,  
 -7.331498071508773e-01,  8.596337901924931e-01,  9.291892667177389e-03,  
 -7.258177950289607e-01, -9.805030048690940e-01,  2.984765845250313e-03,  
 -7.157802360889779e-01, -8.336762449322652e-01,  1.012482548177606e-02,  
 -7.072078419693140e-01, -9.234919823555481e-01,  6.841723221210096e-03,  
 -7.053541655207917e-01,  1.073889554567113e-01,  1.602910466636588e-02,  
 -7.052090371098516e-01, -1.119584635184487e-01,  1.420955705467702e-02,  
 -7.011205173485494e-01, -5.092216197809605e-01,  1.524066877662247e-02,  
 -6.978846262070233e-01, -3.414874362228780e-01,  1.076367185856306e-02,  
 -6.960765595225886e-01, -6.880190026120154e-01,  1.357698223373921e-02,  
 -6.857267249496155e-01,  3.551782556666386e-01,  1.835639998551701e-02,  
 -6.718996078310749e-01,  9.187863739753772e-01,  7.227260623084868e-03,  
 -6.688694553842166e-01, -9.962634726340323e-01,  1.299102531809083e-03,  
 -6.680438282278643e-01,  9.807419818799499e-01,  3.734416537582896e-03,  
 -6.562162894928593e-01,  7.813381408111647e-01,  1.314356882014099e-02,  
 -6.539068033827653e-01,  6.025223400436617e-01,  1.747705500021484e-02,  
 -6.508182477278392e-01, -2.656608209143835e-01,  1.482527461108588e-02,  
 -6.371638788293418e-01, -2.566889805750509e-02,  1.632793168239773e-02,  
 -6.291434547685805e-01,  2.023189788534562e-01,  1.795321661628254e-02,  
 -6.285276641730166e-01, -9.557558207146426e-01,  5.222692046521106e-03,  
 -6.243785655726330e-01, -7.677131072866508e-01,  1.213021892933221e-02,  
 -6.153035647870176e-01, -4.406604449329651e-01,  1.315774503238905e-02,  
 -6.101810791749840e-01, -8.730802950223981e-01,  9.810988876956505e-03,  
 -6.058276827683423e-01,  9.969104641392599e-01,  1.067957112281833e-03,  
 -6.050277497663656e-01, -5.991789076131454e-01,  1.720383270245636e-02,  
 -6.010977897838671e-01,  4.554853809841653e-01,  1.796395971673612e-02,  
 -5.862984837774434e-01,  8.612555834742029e-01,  1.061579515310207e-02,  
 -5.768270943940413e-01,  9.454129989500087e-01,  5.910967881352096e-03,  
 -5.750197447578449e-01, -9.850659057962179e-01,  3.114356971775973e-03,  
 -5.702248508469594e-01, -1.587490643869126e-01,  2.016275464017900e-02,  
 -5.631550904449273e-01,  6.970949553808866e-01,  1.710763838261802e-02,  
 -5.506357337723290e-01,  7.306393615078814e-02,  2.031057229536963e-02,  
 -5.479124054422221e-01,  9.758854402340520e-01,  2.479427756255549e-03,  
 -5.470345570052684e-01, -3.529314403402576e-01,  1.664817380826956e-02,  
 -5.440713379383119e-01,  3.006296094832735e-01,  1.989408266036578e-02,  
 -5.285706246264491e-01, -9.197245554796940e-01,  7.615187153561376e-03,  
 -5.252972416610120e-01, -7.002954752760404e-01,  1.432680033700977e-02,  
 -5.217907594059557e-01,  5.400272741858242e-01,  1.528186481468926e-02,  
 -5.089619423128140e-01, -5.059056477462620e-01,  1.501904216932111e-02,  
 -5.078115420044046e-01, -8.111235694116724e-01,  1.195709426495920e-02,  
 -4.969587258871904e-01,  8.017211919716127e-01,  1.201247603705383e-02,  
 -4.968199837157944e-01, -9.980749914312900e-01,  1.166586821104947e-03,  
 -4.959353636879837e-01,  9.946393860645547e-01,  1.686433249616119e-03,  
 -4.730248940935154e-01,  9.059843124829209e-01,  9.865671699789467e-03,  
 -4.695306511179968e-01, -4.012372094823102e-02,  2.020512288389702e-02,  
 -4.684490949568364e-01, -9.635515324500772e-01,  5.666260551094232e-03,  
 -4.662090360870560e-01, -2.413919218504774e-01,  1.957608008114237e-02,  
 -4.507847851393222e-01,  1.821342046391818e-01,  2.224205809945713e-02,  
 -4.504408392645829e-01,  6.157745693132981e-01,  1.569673318119340e-02,  
 -4.495408838986024e-01,  3.997386347652018e-01,  2.144177767812802e-02,  
 -4.494943818222650e-01, -6.112785695796794e-01,  1.388627516731650e-02,  
 -4.395708346821193e-01,  9.678474058357293e-01,  5.077033132428894e-03,  
 -4.321562916730266e-01, -4.268668982636962e-01,  1.400797089606991e-02,  
 -4.307037407356070e-01, -8.725201945024389e-01,  9.278527778245265e-03,  
 -4.168964278432936e-01,  7.450104874315282e-01,  1.219395278659381e-02,  
 -3.874730976670355e-01, -7.119235377808760e-01,  1.294126106740710e-02,  
 -3.805985421896226e-01, -1.079747078834100e-01,  1.723299400705402e-02,  
 -3.785199405738555e-01, -9.876371778523105e-01,  3.684675193016349e-03,  
 -3.775068034484436e-01, -7.905403853269520e-01,  1.033847725718908e-02,  
 -3.734584665565494e-01,  8.558256846730252e-01,  1.067328374347898e-02,  
 -3.655903961329190e-01, -3.266752580040530e-01,  1.908074633576273e-02,  
 -3.612230477553254e-01, -9.267019889154319e-01,  8.280449836489664e-03,  
 -3.611495490628304e-01,  8.388928253840910e-02,  1.815199832909277e-02,  
 -3.544575658069047e-01,  9.925869383206430e-01,  2.882266155274377e-03,  
 -3.523952800132275e-01,  5.022785378730914e-01,  2.168828448212548e-02,  
 -3.522817929012660e-01, -5.348680504702295e-01,  1.723090656172525e-02,  
 -3.413724045500098e-01,  2.868713230288657e-01,  2.351641706301941e-02,  
 -3.376590699608993e-01,  6.730406677101659e-01,  1.510911918727652e-02,  
 -3.363380915928801e-01,  9.381057218930409e-01,  8.380841067557760e-03,  
 -3.054308661239457e-01,  8.161565054705295e-01,  7.871489934535132e-03,  
 -2.911339093732676e-01, -1.871048424026023e-01,  2.156968793388712e-02,  
 -2.909958284611122e-01, -6.500113551280087e-01,  1.132941951059163e-02,  
 -2.866402453607698e-01,  2.784499095490639e-02,  1.703845446866903e-02,  
 -2.781698350684899e-01, -8.610025448278995e-01,  1.244171703315526e-02,  
 -2.687238931740498e-01, -9.617339692504230e-01,  6.543696094444514e-03,  
 -2.646563355865805e-01, -9.979985340168123e-01,  1.301749448971297e-03,  
 -2.616214122538829e-01, -4.278716843777844e-01,  2.187272120725739e-02,  
 -2.497917994325549e-01,  3.866154000884120e-01,  1.753377798849834e-02,  
 -2.407157278594363e-01, -7.680657426891803e-01,  1.428720407246563e-02,  
 -2.382131093495637e-01, -6.122566385532253e-01,  1.138418395778662e-02,  
 -2.374961081733647e-01,  5.896199791481574e-01,  1.985721981262199e-02,  
 -2.368860581759901e-01,  9.742068851942397e-01,  5.931341045087387e-03,  
 -2.366505826732369e-01,  7.562399666814275e-01,  1.546898361371274e-02,  
 -2.265278487364104e-01,  8.931328439685737e-01,  1.159210102063848e-02,  
 -2.209747362024745e-01,  1.884122436616868e-01,  2.568250169412151e-02,  
 -1.950442902755774e-01, -2.811626958807719e-01,  2.058667944338659e-02,  
 -1.887947955157539e-01, -5.488181437676766e-02,  2.412519217314849e-02,  
 -1.874042727370219e-01,  9.985870256064080e-01,  1.332128559441302e-03,  
 -1.811513910117983e-01,  4.469187039158583e-01,  1.435518386826230e-02,  
 -1.692436690540040e-01, -9.152720547405664e-01,  1.114841347262132e-02,  
 -1.607696194805920e-01, -9.844697592632383e-01,  4.214417557364065e-03,  
 -1.460884104029156e-01, -5.230400107152748e-01,  2.273359239371198e-02,  
 -1.354171446842564e-01, -6.995287211759852e-01,  1.740459683896718e-02,  
 -1.250146267020614e-01,  6.790330316810501e-01,  1.950903133230569e-02,  
 -1.229292048107615e-01,  8.290159292480069e-01,  1.515992221010223e-02,  
 -1.200344097155717e-01,  9.404504623511184e-01,  9.138948896183798e-03,  
 -1.126043088126702e-01,  1.039969994189184e-01,  1.948734738016160e-02,  
 -1.098342248198241e-01, -8.290702847459517e-01,  1.543693536615040e-02,  
 -1.062616019354709e-01, -3.544622956747235e-01,  1.741587972206798e-02,  
 -1.054516940373236e-01,  3.111820934533777e-01,  2.489503857532097e-02,  
 -9.124174526481066e-02, -1.510286762878782e-01,  2.131519019223245e-02,  
 -8.948050655152551e-02,  5.281952357331835e-01,  2.017160434945273e-02,  
 -6.799375882563330e-02,  9.851240571486062e-01,  4.627482783799522e-03,  
 -5.194154553379345e-02, -9.566399970108974e-01,  8.026920571106742e-03,  
 -5.040318666219792e-02, -9.971099379170584e-01,  1.609275224242142e-03,  
 -3.734302745905130e-02,  3.768691967771551e-02,  1.732149882179709e-02,  
 -2.601415514808519e-02, -6.149995401127395e-01,  2.079979843878833e-02,  
 -1.166789681045224e-02, -4.291998918000027e-01,  2.197612010503848e-02,  
 -8.044650945002080e-03,  7.582402904728758e-01,  1.762484494418019e-02,  
 -7.099519309103105e-03,  8.900638838242294e-01,  1.286870713319578e-02,  
 -1.955928951485019e-03, -2.282207401564467e-01,  2.008962148147744e-02,  
 1.955928951485019e-03,  2.282207401564467e-01,  2.008962148147744e-02,  
 7.099519309103105e-03, -8.900638838242294e-01,  1.286870713319578e-02,  
 8.044650945002080e-03, -7.582402904728758e-01,  1.762484494418019e-02,  
 1.166789681045224e-02,  4.291998918000027e-01,  2.197612010503848e-02,  
 2.601415514808519e-02,  6.149995401127395e-01,  2.079979843878833e-02,  
 3.734302745905130e-02, -3.768691967771551e-02,  1.732149882179709e-02,  
 5.040318666219792e-02,  9.971099379170584e-01,  1.609275224242142e-03,  
 5.194154553379345e-02,  9.566399970108974e-01,  8.026920571106742e-03,  
 6.799375882563330e-02, -9.851240571486062e-01,  4.627482783799522e-03,  
 8.948050655152551e-02, -5.281952357331835e-01,  2.017160434945273e-02,  
 9.124174526481066e-02,  1.510286762878782e-01,  2.131519019223245e-02,  
 1.054516940373236e-01, -3.111820934533777e-01,  2.489503857532097e-02,  
 1.062616019354709e-01,  3.544622956747235e-01,  1.741587972206798e-02,  
 1.098342248198241e-01,  8.290702847459517e-01,  1.543693536615040e-02,  
 1.126043088126702e-01, -1.039969994189184e-01,  1.948734738016160e-02,  
 1.200344097155717e-01, -9.404504623511184e-01,  9.138948896183798e-03,  
 1.229292048107615e-01, -8.290159292480069e-01,  1.515992221010223e-02,  
 1.250146267020614e-01, -6.790330316810501e-01,  1.950903133230569e-02,  
 1.354171446842564e-01,  6.995287211759852e-01,  1.740459683896718e-02,  
 1.460884104029156e-01,  5.230400107152748e-01,  2.273359239371198e-02,  
 1.607696194805920e-01,  9.844697592632383e-01,  4.214417557364065e-03,  
 1.692436690540040e-01,  9.152720547405664e-01,  1.114841347262132e-02,  
 1.811513910117983e-01, -4.469187039158583e-01,  1.435518386826230e-02,  
 1.874042727370219e-01, -9.985870256064080e-01,  1.332128559441302e-03,  
 1.887947955157539e-01,  5.488181437676766e-02,  2.412519217314849e-02,  
 1.950442902755774e-01,  2.811626958807719e-01,  2.058667944338659e-02,  
 2.209747362024745e-01, -1.884122436616868e-01,  2.568250169412151e-02,  
 2.265278487364104e-01, -8.931328439685737e-01,  1.159210102063848e-02,  
 2.366505826732369e-01, -7.562399666814275e-01,  1.546898361371274e-02,  
 2.368860581759901e-01, -9.742068851942397e-01,  5.931341045087387e-03,  
 2.374961081733647e-01, -5.896199791481574e-01,  1.985721981262199e-02,  
 2.382131093495637e-01,  6.122566385532253e-01,  1.138418395778662e-02,  
 2.407157278594363e-01,  7.680657426891803e-01,  1.428720407246563e-02,  
 2.497917994325549e-01, -3.866154000884120e-01,  1.753377798849834e-02,  
 2.616214122538829e-01,  4.278716843777844e-01,  2.187272120725739e-02,  
 2.646563355865805e-01,  9.979985340168123e-01,  1.301749448971297e-03,  
 2.687238931740498e-01,  9.617339692504230e-01,  6.543696094444514e-03,  
 2.781698350684899e-01,  8.610025448278995e-01,  1.244171703315526e-02,  
 2.866402453607698e-01, -2.784499095490639e-02,  1.703845446866903e-02,  
 2.909958284611122e-01,  6.500113551280087e-01,  1.132941951059163e-02,  
 2.911339093732676e-01,  1.871048424026023e-01,  2.156968793388712e-02,  
 3.054308661239457e-01, -8.161565054705295e-01,  7.871489934535132e-03,  
 3.363380915928801e-01, -9.381057218930409e-01,  8.380841067557760e-03,  
 3.376590699608993e-01, -6.730406677101659e-01,  1.510911918727652e-02,  
 3.413724045500098e-01, -2.868713230288657e-01,  2.351641706301941e-02,  
 3.522817929012660e-01,  5.348680504702295e-01,  1.723090656172525e-02,  
 3.523952800132275e-01, -5.022785378730914e-01,  2.168828448212548e-02,  
 3.544575658069047e-01, -9.925869383206430e-01,  2.882266155274377e-03,  
 3.611495490628304e-01, -8.388928253840910e-02,  1.815199832909277e-02,  
 3.612230477553254e-01,  9.267019889154319e-01,  8.280449836489664e-03,  
 3.655903961329190e-01,  3.266752580040530e-01,  1.908074633576273e-02,  
 3.734584665565494e-01, -8.558256846730252e-01,  1.067328374347898e-02,  
 3.775068034484436e-01,  7.905403853269520e-01,  1.033847725718908e-02,  
 3.785199405738555e-01,  9.876371778523105e-01,  3.684675193016349e-03,  
 3.805985421896226e-01,  1.079747078834100e-01,  1.723299400705402e-02,  
 3.874730976670355e-01,  7.119235377808760e-01,  1.294126106740710e-02,  
 4.168964278432936e-01, -7.450104874315282e-01,  1.219395278659381e-02,  
 4.307037407356070e-01,  8.725201945024389e-01,  9.278527778245265e-03,  
 4.321562916730266e-01,  4.268668982636962e-01,  1.400797089606991e-02,  
 4.395708346821193e-01, -9.678474058357293e-01,  5.077033132428894e-03,  
 4.494943818222650e-01,  6.112785695796794e-01,  1.388627516731650e-02,  
 4.495408838986024e-01, -3.997386347652018e-01,  2.144177767812802e-02,  
 4.504408392645829e-01, -6.157745693132981e-01,  1.569673318119340e-02,  
 4.507847851393222e-01, -1.821342046391818e-01,  2.224205809945713e-02,  
 4.662090360870560e-01,  2.413919218504774e-01,  1.957608008114237e-02,  
 4.684490949568364e-01,  9.635515324500772e-01,  5.666260551094232e-03,  
 4.695306511179968e-01,  4.012372094823102e-02,  2.020512288389702e-02,  
 4.730248940935154e-01, -9.059843124829209e-01,  9.865671699789467e-03,  
 4.959353636879837e-01, -9.946393860645547e-01,  1.686433249616119e-03,  
 4.968199837157944e-01,  9.980749914312900e-01,  1.166586821104947e-03,  
 4.969587258871904e-01, -8.017211919716127e-01,  1.201247603705383e-02,  
 5.078115420044046e-01,  8.111235694116724e-01,  1.195709426495920e-02,  
 5.089619423128140e-01,  5.059056477462620e-01,  1.501904216932111e-02,  
 5.217907594059557e-01, -5.400272741858242e-01,  1.528186481468926e-02,  
 5.252972416610120e-01,  7.002954752760404e-01,  1.432680033700977e-02,  
 5.285706246264491e-01,  9.197245554796940e-01,  7.615187153561376e-03,  
 5.440713379383119e-01, -3.006296094832735e-01,  1.989408266036578e-02,  
 5.470345570052684e-01,  3.529314403402576e-01,  1.664817380826956e-02,  
 5.479124054422221e-01, -9.758854402340520e-01,  2.479427756255549e-03,  
 5.506357337723290e-01, -7.306393615078814e-02,  2.031057229536963e-02,  
 5.631550904449273e-01, -6.970949553808866e-01,  1.710763838261802e-02,  
 5.702248508469594e-01,  1.587490643869126e-01,  2.016275464017900e-02,  
 5.750197447578449e-01,  9.850659057962179e-01,  3.114356971775973e-03,  
 5.768270943940413e-01, -9.454129989500087e-01,  5.910967881352096e-03,  
 5.862984837774434e-01, -8.612555834742029e-01,  1.061579515310207e-02,  
 6.010977897838671e-01, -4.554853809841653e-01,  1.796395971673612e-02,  
 6.050277497663656e-01,  5.991789076131454e-01,  1.720383270245636e-02,  
 6.058276827683423e-01, -9.969104641392599e-01,  1.067957112281833e-03,  
 6.101810791749840e-01,  8.730802950223981e-01,  9.810988876956505e-03,  
 6.153035647870176e-01,  4.406604449329651e-01,  1.315774503238905e-02,  
 6.243785655726330e-01,  7.677131072866508e-01,  1.213021892933221e-02,  
 6.285276641730166e-01,  9.557558207146426e-01,  5.222692046521106e-03,  
 6.291434547685805e-01, -2.023189788534562e-01,  1.795321661628254e-02,  
 6.371638788293418e-01,  2.566889805750509e-02,  1.632793168239773e-02,  
 6.508182477278392e-01,  2.656608209143835e-01,  1.482527461108588e-02,  
 6.539068033827653e-01, -6.025223400436617e-01,  1.747705500021484e-02,  
 6.562162894928593e-01, -7.813381408111647e-01,  1.314356882014099e-02,  
 6.680438282278643e-01, -9.807419818799499e-01,  3.734416537582896e-03,  
 6.688694553842166e-01,  9.962634726340323e-01,  1.299102531809083e-03,  
 6.718996078310749e-01, -9.187863739753772e-01,  7.227260623084868e-03,  
 6.857267249496155e-01, -3.551782556666386e-01,  1.835639998551701e-02,  
 6.960765595225886e-01,  6.880190026120154e-01,  1.357698223373921e-02,  
 6.978846262070233e-01,  3.414874362228780e-01,  1.076367185856306e-02,  
 7.011205173485494e-01,  5.092216197809605e-01,  1.524066877662247e-02,  
 7.052090371098516e-01,  1.119584635184487e-01,  1.420955705467702e-02,  
 7.053541655207917e-01, -1.073889554567113e-01,  1.602910466636588e-02,  
 7.072078419693140e-01,  9.234919823555481e-01,  6.841723221210096e-03,  
 7.157802360889779e-01,  8.336762449322652e-01,  1.012482548177606e-02,  
 7.258177950289607e-01,  9.805030048690940e-01,  2.984765845250313e-03,  
 7.331498071508773e-01, -8.596337901924931e-01,  9.291892667177389e-03,  
 7.344946046482385e-01, -7.002770707813594e-01,  1.339498521201928e-02,  
 7.391128608011459e-01, -5.011842297262301e-01,  1.677675545049549e-02,  
 7.480114600555077e-01, -9.967592933390678e-01,  1.243409201000067e-03,  
 7.570188231121615e-01, -9.562983797766917e-01,  5.269367781364454e-03,  
 7.658473206792390e-01, -2.470075232375816e-01,  1.699291241018386e-02,  
 7.664905651113335e-01,  2.123608448367788e-01,  1.521536630069221e-02,  
 7.718688019814154e-01,  6.087164044214350e-01,  1.281755532683666e-02,  
 7.752582668662442e-01, -1.137400097769025e-02,  1.483822376274713e-02,  
 7.766600189797701e-01,  4.041663776132322e-01,  1.451699415444131e-02,  
 7.862399052534020e-01,  7.635989572508247e-01,  1.120659033007899e-02,  
 7.957314634069883e-01,  9.607527680221649e-01,  4.059074074883998e-03,  
 7.966190004094728e-01,  9.968334127996725e-01,  1.036781499468538e-03,  
 7.983956784496398e-01,  8.914942533713631e-01,  7.267362334258530e-03,  
 8.004833550779242e-01, -7.919528617574970e-01,  1.006437035257496e-02,  
 8.058634520423256e-01, -6.117159879145377e-01,  1.279254088338618e-02,  
 8.148639002101447e-01, -3.932890823416910e-01,  1.520502153610768e-02,  
 8.179672372442700e-01, -9.076223036675563e-01,  6.892206214578204e-03,  
 8.269374328956414e-01, -9.850869495918245e-01,  2.648428928686930e-03,  
 8.357310902097985e-01,  9.723800805043467e-02,  1.374148019748794e-02,  
 8.369983523769275e-01, -1.347222940319437e-01,  1.460708731761451e-02,  
 8.373962094750010e-01,  5.186387354716220e-01,  1.230119470881243e-02,  
 8.422263654558482e-01,  3.015292326049363e-01,  1.287800406757572e-02,  
 8.522596697975072e-01,  6.840670787785538e-01,  1.062952046635244e-02,  
 8.592237506008711e-01,  8.341324721077372e-01,  7.928559898856604e-03,  
 8.624098290914860e-01, -7.126189995166746e-01,  9.861047155006141e-03,  
 8.651527837557776e-01,  9.866988624485060e-01,  2.118506810134428e-03,  
 8.676827987392443e-01, -5.159125990270553e-01,  1.149515499866792e-02,  
 8.707970024861261e-01,  9.370668393694276e-01,  4.607127648721668e-03,  
 8.763285336755390e-01, -8.465920091250118e-01,  7.228076122988736e-03,  
 8.781614570655271e-01, -9.532957838212304e-01,  3.986319116448455e-03,  
 8.788480167168854e-01, -2.792330855544344e-01,  1.282453595081661e-02,  
 8.887805555572472e-01, -9.980469645264131e-01,  6.927987848988626e-04,  
 8.934682220664112e-01,  4.216540388538755e-01,  1.073747532386832e-02,  
 8.947837985257842e-01, -1.554349304099888e-02,  1.207505504176275e-02,  
 8.956547894973423e-01,  1.969077394197896e-01,  1.052048363646446e-02,  
 9.082567296294581e-01,  5.961320469495873e-01,  9.396878139328617e-03,  
 9.106078414366331e-01,  7.633798877459725e-01,  7.390023577666990e-03,  
 9.148831482219597e-01, -6.224206774261293e-01,  8.741538710357355e-03,  
 9.181270575285391e-01, -4.122328505086459e-01,  9.601387120539102e-03,  
 9.195935562112217e-01,  8.913327000110681e-01,  5.052649337869474e-03,  
 9.217831985976003e-01,  9.985289666041468e-01,  5.078696283821862e-04,  
 9.231065278766845e-01, -9.076886759912991e-01,  4.277169811976498e-03,  
 9.250982605210959e-01, -7.735956141038276e-01,  6.643173932293495e-03,  
 9.278797101416244e-01,  9.706959780392181e-01,  2.420070122891078e-03,  
 9.294596181015237e-01, -9.813684731390790e-01,  1.920664927315008e-03,  
 9.296009678982454e-01, -1.579161826917062e-01,  1.000831611323566e-02,  
 9.376385227666459e-01,  3.149592118756698e-01,  8.640152266819899e-03,  
 9.417225429447996e-01,  1.010399506491120e-01,  8.545115482104066e-03,  
 9.499379163273817e-01,  4.990544089847970e-01,  7.157918511939649e-03,  
 9.529413061166492e-01,  6.848663302380273e-01,  6.115869631822169e-03,  
 9.551892905468934e-01, -5.215279150021472e-01,  6.895698107002057e-03,  
 9.560668264177599e-01, -2.992407743127743e-01,  7.187486995447770e-03,  
 9.565093211986069e-01,  8.285414929426780e-01,  4.524164566301950e-03,  
 9.575259606392211e-01, -8.526222258903702e-01,  3.522351032086693e-03,  
 9.621099147673235e-01, -6.897553564879744e-01,  5.294641784299885e-03,  
 9.625096668136147e-01, -9.481536769647175e-01,  2.281103018635964e-03,  
 9.629858793094620e-01,  9.381408744361764e-01,  2.554368802597983e-03,  
 9.667753163257026e-01, -3.477910291429498e-02,  6.924394568068183e-03,  
 9.668937072725421e-01, -9.958238219074350e-01,  5.454007647675571e-04,  
 9.698875102419363e-01,  9.910520236356811e-01,  8.725558215646179e-04,  
 9.739747222412156e-01,  2.170070835355472e-01,  5.848357083847142e-03,  
 9.758618568064553e-01,  4.021500807907098e-01,  4.191420631437088e-03,  
 9.763487274404036e-01, -8.040608258571258e-01,  1.735576449905203e-03,  
 9.808958789729733e-01,  5.936214063681421e-01,  4.206620288925534e-03,  
 9.817085463008139e-01, -4.080671844783566e-01,  4.517002995396259e-03,  
 9.830502038887345e-01, -1.855914572695679e-01,  4.596336081266426e-03,  
 9.842497345754406e-01,  8.869330623714193e-01,  2.084899867143594e-03,  
 9.844078028285480e-01,  7.576106510429415e-01,  3.160151211848773e-03,  
 9.858704720189189e-01, -9.012846007723281e-01,  1.872665686706367e-03,  
 9.862543531528728e-01, -5.965690502576685e-01,  3.417223744136484e-03,  
 9.874342455637046e-01, -9.765233090751630e-01,  8.334380630773419e-04,  
 9.888702332586248e-01, -7.575946249394171e-01,  2.014228686820058e-03,  
 9.904720670548077e-01,  9.710213211789278e-01,  8.475646284885832e-04,  
 9.908388235274806e-01,  8.317660908501920e-02,  3.661061584693876e-03,  
 9.922776511892646e-01,  3.473204119330540e-01,  2.073619684302503e-03,  
 9.958488160214992e-01,  4.963853591618409e-01,  1.871218692254807e-03,  
 9.967221454497780e-01, -2.967880150220837e-01,  1.788242723078713e-03,  
 9.969508496154019e-01, -9.951320518801803e-01,  1.406624476607038e-04,  
 9.971337685886393e-01, -7.632359805747738e-02,  1.695014196901724e-03,  
 9.973323543291763e-01, -4.909591129622543e-01,  1.363609590112511e-03,  
 9.974354703237893e-01,  9.972347569712511e-01,  1.178428627156954e-04,  
 9.975229416008712e-01, -8.411146681674510e-01,  8.259054712338016e-04,  
 9.975527094081703e-01,  6.722468138431469e-01,  1.228393951475139e-03,  
 9.975758902464168e-01,  8.292104265892648e-01,  8.758182348185454e-04,  
 9.975891711682796e-01,  9.308337785182597e-01,  5.005025838481359e-04,  
 9.982849649115821e-01, -9.436218579698744e-01,  4.239310404841323e-04,  
 9.984308298705356e-01, -6.810115040142974e-01,  8.742573242503645e-04,  
 9.988860641396040e-01,  2.373189065242698e-01,  1.059226498023405e-03 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr48 ( )

/******************************************************************************/
/*
  Purpose:

    SMR48 returns the SMR rule of degree 48.

  Discussion:
 
    DEGREE: 48
    POINTS CARDINALITY: 417
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR48[3*417], the requested rule.
*/
{
  const int degree = 48;
  int order;
  double xw[3*417] = {
 -9.990552580516567e-01, -7.479254608809505e-01,  4.845844320013029e-04,  
 -9.988760883998153e-01,  2.568938088751835e-01,  8.877453242046397e-04,  
 -9.986091048294213e-01,  1.475403353286808e-02,  8.040816649406732e-04,  
 -9.985122425173576e-01, -5.059783159128129e-01,  1.125983578847775e-03,  
 -9.984530690329705e-01, -9.196817917920462e-01,  3.211292464713594e-04,  
 -9.982842816947866e-01,  4.893019742012896e-01,  8.282364851453019e-04,  
 -9.982520488850405e-01,  9.821235324863609e-01,  2.422927481790814e-04,  
 -9.973280389800840e-01,  6.756520485620866e-01,  8.237504025536671e-04,  
 -9.967449468871785e-01,  7.716874829711365e-01,  7.452334436535652e-04,  
 -9.964365335122727e-01,  8.681515615582738e-01,  8.902528711682726e-04,  
 -9.962098577937705e-01, -2.857266397360828e-01,  1.937344458762579e-03,  
 -9.957795050622651e-01, -9.876433080318017e-01,  3.429533984696887e-04,  
 -9.946778211699915e-01, -8.474215921378356e-01,  1.194026452801634e-03,  
 -9.945109495244129e-01, -6.711427250073166e-01,  1.419745783388957e-03,  
 -9.940837925205557e-01, -1.077708304941221e-01,  2.223464254615778e-03,  
 -9.925155388861520e-01,  9.388248000765870e-01,  1.047480811500816e-03,  
 -9.919901944290620e-01,  5.686557912949334e-01,  1.838793597622181e-03,  
 -9.917306363878621e-01, -9.478395921965526e-01,  7.802173870853395e-04,  
 -9.910822911638744e-01,  1.331031266923891e-01,  2.938508672222513e-03,  
 -9.908515335539425e-01,  3.685202933287459e-01,  2.830526597142672e-03,  
 -9.866307668467350e-01,  9.966272831969996e-01,  2.933195451028031e-04,  
 -9.858792923413487e-01, -4.118290444180076e-01,  3.755509131978820e-03,  
 -9.855194095112306e-01,  7.159397591374761e-01,  1.535917055011706e-03,  
 -9.837772596137903e-01, -5.934253159283669e-01,  3.377108351701475e-03,  
 -9.819497692855043e-01, -7.782643779166490e-01,  2.756877484994091e-03,  
 -9.812266425695817e-01,  8.130580129104829e-01,  2.309363670601080e-03,  
 -9.771749693182564e-01, -9.984960207754501e-01,  2.822482441259009e-04,  
 -9.763974116368401e-01, -1.934951329958478e-01,  5.027497830243744e-03,  
 -9.759936629550091e-01, -8.954485094924929e-01,  2.449068285191341e-03,  
 -9.754641485200377e-01,  8.434179079015775e-03,  5.273299242251507e-03,  
 -9.741421449181825e-01,  6.292753411868561e-01,  3.568019735683563e-03,  
 -9.730819722375790e-01,  9.724521292180650e-01,  1.382948896073604e-03,  
 -9.730789870204469e-01,  2.472883400161374e-01,  5.460293273811428e-03,  
 -9.726640066871888e-01,  4.651672305117452e-01,  4.813551654491207e-03,  
 -9.717010087770350e-01, -9.703771901004872e-01,  1.394234729269292e-03,  
 -9.714960642729723e-01,  8.970281595932642e-01,  2.562951198781977e-03,  
 -9.617362473444955e-01, -7.027703241908005e-01,  4.605971076568484e-03,  
 -9.607210672269872e-01, -3.322709269921182e-01,  5.431302361324639e-03,  
 -9.602445514242340e-01,  7.612260341568599e-01,  2.456698577190253e-03,  
 -9.579948900288462e-01, -5.112746901351274e-01,  6.253400316621933e-03,  
 -9.484290775926218e-01, -8.341736274933066e-01,  4.531225726400182e-03,  
 -9.451917183607923e-01,  1.238808781931126e-01,  8.201814840229081e-03,  
 -9.432653194808177e-01, -8.861458353897265e-02,  8.008713660300900e-03,  
 -9.428586367673794e-01,  9.934004622465014e-01,  9.547156202731789e-04,  
 -9.428418829683745e-01,  7.043511955026499e-01,  4.669981461123601e-03,  
 -9.427846854068982e-01,  3.530751008963562e-01,  7.832254190109047e-03,  
 -9.414741499351150e-01,  5.507528104239781e-01,  6.583790177049798e-03,  
 -9.405199230043805e-01, -9.336896767870310e-01,  3.192075832607225e-03,  
 -9.398430171859361e-01,  9.410585382180106e-01,  2.918746684002447e-03,  
 -9.380601617332789e-01,  8.443007256893251e-01,  4.531934577547019e-03,  
 -9.357722262152627e-01, -9.892798298875611e-01,  1.357757734504045e-03,  
 -9.297135605148458e-01, -6.291547793730226e-01,  6.754868314277823e-03,  
 -9.287300178800064e-01, -2.543930308185366e-01,  7.243849160815757e-03,  
 -9.161728844949248e-01, -4.239962588280450e-01,  9.299369071546468e-03,  
 -9.122999452276054e-01, -7.650962839278904e-01,  6.505328730774483e-03,  
 -9.027195651058045e-01,  2.343213824631600e-01,  1.070153334345670e-02,  
 -9.002481970024863e-01,  1.787948642362641e-02,  1.028208803766175e-02,  
 -8.994716034464636e-01,  4.509467480279049e-01,  9.722518509241976e-03,  
 -8.993299181171596e-01,  6.366994301022654e-01,  8.088190471646505e-03,  
 -8.989185508841521e-01,  9.746279357779196e-01,  2.489656257649104e-03,  
 -8.973598832577063e-01, -8.839606479669895e-01,  5.558455108410310e-03,  
 -8.960324839944227e-01,  7.780412959093933e-01,  6.945480690212927e-03,  
 -8.937261594542628e-01,  8.990377097685573e-01,  4.960137962212837e-03,  
 -8.894524278225060e-01, -9.645087195310335e-01,  3.234691525597815e-03,  
 -8.852845185346627e-01, -1.644249224842236e-01,  1.054311506523360e-02,  
 -8.832749949602599e-01, -5.540463681956116e-01,  9.519966984097020e-03,  
 -8.763116175834303e-01, -9.976476645275696e-01,  7.363515432897181e-04,  
 -8.681923940787308e-01,  9.972359969871393e-01,  8.113364667770608e-04,  
 -8.668394917625060e-01, -6.993705565874477e-01,  7.872179533786066e-03,  
 -8.613634360731458e-01, -3.261475318345773e-01,  1.232507953462154e-02,  
 -8.509299252626037e-01,  1.169899980428923e-01,  1.136757785818936e-02,  
 -8.482538929392435e-01,  3.393726360408879e-01,  1.267378157246283e-02,  
 -8.451523222407388e-01,  5.453005687235306e-01,  1.130491811792810e-02,  
 -8.449087456035432e-01, -8.224590938386219e-01,  8.042605075076493e-03,  
 -8.412671406367855e-01,  9.446888202667849e-01,  4.514535531844399e-03,  
 -8.389136147784579e-01,  8.439972605417678e-01,  7.433693180569364e-03,  
 -8.388809490720153e-01,  7.089485738913401e-01,  9.353324994663370e-03,  
 -8.309124445900310e-01, -9.265465930991434e-01,  5.703635540067962e-03,  
 -8.274670608886809e-01, -6.041854831216104e-02,  1.386142916565396e-02,  
 -8.236973795101074e-01, -4.667582208856409e-01,  1.279580075793840e-02,  
 -8.174330288251811e-01, -9.840873060176719e-01,  2.642923071487787e-03,  
 -8.120012776170108e-01, -6.342612806052523e-01,  1.021716402717029e-02,  
 -8.050460479697321e-01,  9.843510759586377e-01,  2.619831715043517e-03,  
 -7.963298579913790e-01,  2.091194063771606e-01,  1.291867519635318e-02,  
 -7.946735264586758e-01, -2.195828771062506e-01,  1.512054362089480e-02,  
 -7.827811955363804e-01,  4.402675008295936e-01,  1.430859367414026e-02,  
 -7.808856870805703e-01, -7.574581885514182e-01,  9.891673069466232e-03,  
 -7.745104986488009e-01,  6.271495747138331e-01,  1.211509248039978e-02,  
 -7.742852249721359e-01,  9.016812565623727e-01,  7.058444102029891e-03,  
 -7.712501309180960e-01,  7.818205620509094e-01,  9.871384023520356e-03,  
 -7.644957465687958e-01, -8.749115601199623e-01,  8.398169418965080e-03,  
 -7.569201207717521e-01,  5.030282021695773e-02,  1.660514828868849e-02,  
 -7.523794410765668e-01, -3.660105878543244e-01,  1.584334374567671e-02,  
 -7.455561476506094e-01, -9.573278361059363e-01,  5.090662283402881e-03,  
 -7.449421292184407e-01, -9.968633522754683e-01,  1.161090043869617e-03,  
 -7.446132349955634e-01, -5.547266254690082e-01,  1.386801984803096e-02,  
 -7.369394855016965e-01,  9.975277318664320e-01,  1.006571180791874e-03,  
 -7.314430658691584e-01,  9.585376926340167e-01,  4.835999288723090e-03,  
 -7.300796275468885e-01,  3.048033260490218e-01,  1.561003081144107e-02,  
 -7.168671655213190e-01, -1.074176336475728e-01,  1.755811473136017e-02,  
 -7.109858048794567e-01, -6.930842326296686e-01,  1.103274111420899e-02,  
 -7.042131099438929e-01,  5.325994952276727e-01,  1.503724999824317e-02,  
 -6.966126002275308e-01,  7.081800737356690e-01,  1.259320917995288e-02,  
 -6.964513605087373e-01,  8.482976774714664e-01,  9.697594807909158e-03,  
 -6.865327730089299e-01, -8.144546391445805e-01,  1.072836825388296e-02,  
 -6.753051999581515e-01,  1.623967218674537e-01,  1.866107345822792e-02,  
 -6.704437071455894e-01, -2.555701283341775e-01,  1.828130593919578e-02,  
 -6.688090823093042e-01, -9.158922580375838e-01,  7.745824340518855e-03,  
 -6.654346461416878e-01, -4.581318541855599e-01,  1.715362559535030e-02,  
 -6.622715641926926e-01, -9.815849224623253e-01,  3.264022763125851e-03,  
 -6.569729367129702e-01,  9.843252854264678e-01,  3.107653612709843e-03,  
 -6.490814825652859e-01,  9.219379527553472e-01,  7.273589045997255e-03,  
 -6.490772877820512e-01,  4.032488941882870e-01,  1.750178260989192e-02,  
 -6.403967267747678e-01, -6.234176969692687e-01,  1.335506042885241e-02,  
 -6.321887611571272e-01, -9.956439648928699e-01,  7.346686354790276e-04,  
 -6.290834033601033e-01,  7.216244083470421e-03,  1.947776642467306e-02,  
 -6.171162584505504e-01,  6.223647914691047e-01,  1.549230086365143e-02,  
 -6.112516621704388e-01,  7.831776557256033e-01,  1.255020376848972e-02,  
 -5.985853482566683e-01, -7.497385410641988e-01,  1.263727710129047e-02,  
 -5.869424988010886e-01,  9.973980234326894e-01,  1.017364927160106e-03,  
 -5.839168637130311e-01, -8.616887542657947e-01,  9.710010662354636e-03,  
 -5.838249969862671e-01,  2.718839290695758e-01,  1.987995004105253e-02,  
 -5.785506719608396e-01, -1.394134201304520e-01,  2.006270434602024e-02,  
 -5.776106646583016e-01, -3.488508238645545e-01,  1.954400064690151e-02,  
 -5.759454975927832e-01, -9.501573801694301e-01,  5.909368816766506e-03,  
 -5.641159090423106e-01,  9.599854139458381e-01,  5.586746910682514e-03,  
 -5.633216281680778e-01,  8.755125598060366e-01,  9.255164778582764e-03,  
 -5.607747764243531e-01, -5.381763644015136e-01,  1.699095923630616e-02,  
 -5.600305973998688e-01, -9.806167661958205e-01,  1.262483548230043e-03,  
 -5.567454205492522e-01,  5.026048129003556e-01,  1.827080325916463e-02,  
 -5.341810753346672e-01, -9.969266028026199e-01,  1.301907496370608e-03,  
 -5.329787205184003e-01,  1.215536852040537e-01,  2.056858991083391e-02,  
 -5.216420701735659e-01,  7.059660023740130e-01,  1.551296508436025e-02,  
 -5.172659165257237e-01, -6.815002930550295e-01,  1.311160294691172e-02,  
 -5.149399834555580e-01, -8.911544014546450e-01,  3.106710974499213e-03,  
 -4.954671722032739e-01,  9.877262447568889e-01,  2.704444947872211e-03,  
 -4.865772270036066e-01,  3.790795935677761e-01,  2.015371460883953e-02,  
 -4.820537324578744e-01, -2.316193655903357e-01,  2.104746654078359e-02,  
 -4.809419330248884e-01,  8.244191675015446e-01,  1.014591526088192e-02,  
 -4.787129350153638e-01, -1.934329117484134e-02,  2.070508811124076e-02,  
 -4.782751005587915e-01, -8.029894135918636e-01,  1.336764814038257e-02,  
 -4.770175275669148e-01, -9.699883462880337e-01,  3.399274611185233e-03,  
 -4.724003494477093e-01, -4.356324025404807e-01,  1.986953131882142e-02,  
 -4.689391598576622e-01,  9.240111512762571e-01,  7.965383957108562e-03,  
 -4.658911980881860e-01, -9.126526757581364e-01,  7.367814824582447e-03,  
 -4.549738262686863e-01,  5.964200891972189e-01,  1.827733026219556e-02,  
 -4.416949290061132e-01, -6.094657082125391e-01,  1.513501533289796e-02,  
 -4.308781935067766e-01,  2.346747589224954e-01,  2.059752932220561e-02,  
 -4.237214429183968e-01,  9.988429740989183e-01,  7.468909138370148e-04,  
 -4.162231798125762e-01, -9.881086636947707e-01,  2.889752971892923e-03,  
 -4.039955476728034e-01,  7.698207973252635e-01,  1.213731648511270e-02,  
 -4.022743536629942e-01,  9.678771998474882e-01,  4.855326691856050e-03,  
 -3.856816592054024e-01, -1.046220184544868e-01,  1.985451526323344e-02,  
 -3.842028783258495e-01,  4.782357222377692e-01,  1.944910685094546e-02,  
 -3.786287262961593e-01, -7.317696143997668e-01,  1.545284771037087e-02,  
 -3.774042657220710e-01,  1.071473163945458e-01,  1.828035198356040e-02,  
 -3.767581689748362e-01, -3.215686449173350e-01,  2.187073763613115e-02,  
 -3.751374240015725e-01,  8.801101468531496e-01,  9.395413302507984e-03,  
 -3.683490409041832e-01, -9.428181074008333e-01,  6.588189243834728e-03,  
 -3.629438583461049e-01, -8.569398241270274e-01,  1.243551011498686e-02,  
 -3.588340459663644e-01, -5.198877431352260e-01,  1.898803694431077e-02,  
 -3.464473861083704e-01,  6.804932722717799e-01,  1.665356435051682e-02,  
 -3.299311445310920e-01,  3.361312544479299e-01,  1.885441897381050e-02,  
 -3.219997348518502e-01,  9.895504501564032e-01,  2.761328697047235e-03,  
 -3.198808254382448e-01, -9.980928088447467e-01,  1.234974434831144e-03,  
 -3.037501615875154e-01,  9.368481435389949e-01,  7.207594725661396e-03,  
 -3.001889723102260e-01,  3.829984631352593e-02,  1.749110699980297e-02,  
 -2.952842276415655e-01, -1.831220068752724e-01,  1.884429765898816e-02,  
 -2.933788342322968e-01, -6.564781732148162e-01,  1.409372395800510e-02,  
 -2.896454119116090e-01,  8.350902239498463e-01,  1.042215860220357e-02,  
 -2.813733871881473e-01, -9.706700162800450e-01,  5.210254763353661e-03,  
 -2.803796107520479e-01,  5.666580371271599e-01,  1.769551985203818e-02,  
 -2.646649728993916e-01, -4.140438773807713e-01,  2.201548097535621e-02,  
 -2.558406082629252e-01,  2.189136718964751e-01,  2.131050014957573e-02,  
 -2.512104300954118e-01, -7.918292212992303e-01,  1.562248186161317e-02,  
 -2.488917545593868e-01, -9.038959168898448e-01,  1.025510969508195e-02,  
 -2.438092787887342e-01,  4.188288491033791e-01,  1.475732864033983e-02,  
 -2.346445346959175e-01,  7.613261048327971e-01,  1.455391668451701e-02,  
 -2.271156542693553e-01, -5.887245648490607e-01,  1.434999190758240e-02,  
 -2.247073731789063e-01,  9.979933451517716e-01,  1.039791944866300e-03,  
 -2.163763876756374e-01,  9.677392729427614e-01,  4.990957116044046e-03,  
 -2.103558829810385e-01, -2.574697338318033e-01,  1.764960446990464e-02,  
 -2.095250370525197e-01, -4.031736543450098e-02,  2.178465331938922e-02,  
 -1.927828958465816e-01,  8.982684824267485e-01,  1.042589527917258e-02,  
 -1.871159934019396e-01,  6.474212617254689e-01,  1.535750116524344e-02,  
 -1.806658576765277e-01, -9.896867624509934e-01,  3.408734541691759e-03,  
 -1.633259573375413e-01,  1.400955882739857e-01,  1.959106088770077e-02,  
 -1.562364680645740e-01,  4.925045888845677e-01,  1.737804918299484e-02,  
 -1.491971854353493e-01, -7.098622267114059e-01,  1.806240202498965e-02,  
 -1.452318661461631e-01, -9.437776536061130e-01,  7.890722263129550e-03,  
 -1.439290914451357e-01, -5.038374394299656e-01,  2.033901736325344e-02,  
 -1.357808182391570e-01,  3.334065136263061e-01,  2.200934208245402e-02,  
 -1.313016026395862e-01, -8.511650652628034e-01,  1.347969997761506e-02,  
 -1.245113984567057e-01,  9.861958682207052e-01,  3.308916883269708e-03,  
 -1.229885666993439e-01, -3.334500618371383e-01,  1.933435335874882e-02,  
 -1.144529387813882e-01,  8.314993434856852e-01,  1.360965950150718e-02,  
 -1.095687849917511e-01, -1.301117874964884e-01,  2.211874730643872e-02,  
 -9.411332760666641e-02,  7.176378070213986e-01,  1.463449452671732e-02,  
 -8.388626313485989e-02,  9.413401035627339e-01,  8.138348671609086e-03,  
 -7.111096756881072e-02,  5.901854458702823e-02,  2.159648899983570e-02,  
 -5.596535842806818e-02, -9.985986389503078e-01,  1.152035315802443e-03,  
 -5.519377855670472e-02,  5.804621131957924e-01,  1.951093459498052e-02,  
 -5.083880286421506e-02, -6.184685667120825e-01,  1.949335828949948e-02,  
 -4.232428288883773e-02, -9.721213788531580e-01,  5.459634326563773e-03,  
 -3.362895942304555e-02,  2.473398037721315e-01,  2.225550633881426e-02,  
 -2.878763707909897e-02,  9.974212143963649e-01,  1.392150791806729e-03,  
 -2.701947130628778e-02, -7.792634752677781e-01,  1.635358938483053e-02,  
 -2.099733154867333e-02, -4.174896614559798e-01,  2.064580833064765e-02,  
 -1.942942890989090e-02, -9.030039921748615e-01,  1.075920755862384e-02,  
 -1.025241776704336e-02, -2.209004411746912e-01,  2.189514896760084e-02,  
 -5.603709661495010e-03,  4.376284944061901e-01,  2.305488563112960e-02,  
 5.160807557708119e-03,  8.883127314312923e-01,  1.173589844777346e-02,  
 1.478755859639245e-02,  7.805710255221150e-01,  1.419483273432981e-02,  
 2.203211920457429e-02,  9.710286258778940e-01,  5.352311200607812e-03,  
 2.667969840358058e-02, -3.169899165421439e-02,  2.212058357439342e-02,  
 4.419649539576614e-02, -5.358738509280914e-01,  1.537849072244061e-02,  
 5.645986923166345e-02,  6.654224239023853e-01,  1.852457014689922e-02,  
 7.014561544903802e-02,  1.539138394301714e-01,  2.361180582820691e-02,  
 7.382490787646279e-02, -9.888797183102520e-01,  3.401063622770633e-03,  
 7.677748557728954e-02, -6.950549395483447e-01,  1.891944949236252e-02,  
 8.334400516372700e-02, -9.420248129445080e-01,  7.428425442889059e-03,  
 8.811404198697755e-02, -8.425744879388839e-01,  1.354320033736116e-02,  
 9.428202794142194e-02, -3.130508677914989e-01,  2.260130066690366e-02,  
 1.010204727329467e-01,  3.441432117443262e-01,  2.223504878996065e-02,  
 1.118057634342426e-01,  9.901984397677133e-01,  2.866107790272031e-03,  
 1.196298840971513e-01,  5.382727379580559e-01,  2.270074787659283e-02,  
 1.209411181337108e-01, -4.799090158464530e-01,  1.152147426491700e-02,  
 1.219850999637117e-01, -1.218612532860722e-01,  2.101568083502077e-02,  
 1.232292464562112e-01,  9.343108083094505e-01,  9.206323005860302e-03,  
 1.295669785368222e-01,  8.406880568875401e-01,  1.287955106877277e-02,  
 1.735905842899504e-01,  7.429177350779718e-01,  1.571431921804362e-02,  
 1.755724480028529e-01,  5.338528258468570e-02,  2.372489552516464e-02,  
 1.757472783291680e-01, -5.979131889853080e-01,  1.794402481478493e-02,  
 1.842105709085970e-01, -8.912854841712154e-01,  7.954070193779422e-03,  
 1.849994792854633e-01, -9.651899282978637e-01,  5.064149534933845e-03,  
 1.883621786044712e-01, -9.977844639120534e-01,  1.248646247932006e-03,  
 1.936423269701602e-01, -7.695301946784334e-01,  1.610490406496761e-02,  
 2.014762149232713e-01, -4.110301142644528e-01,  1.885365723952532e-02,  
 2.036789289831738e-01,  2.505729164783445e-01,  2.177691306082853e-02,  
 2.124821840633064e-01,  9.983678654418292e-01,  1.013308752600118e-03,  
 2.186440916146861e-01, -2.099360144286631e-01,  2.166303561905097e-02,  
 2.266009299450756e-01,  4.361972923038600e-01,  2.158994434128180e-02,  
 2.315646394710894e-01,  9.701295500103406e-01,  6.079344492651117e-03,  
 2.356865468776172e-01,  6.370910939235934e-01,  1.931745618038865e-02,  
 2.454088634004036e-01,  8.937656157434565e-01,  1.097036321751639e-02,  
 2.483612800101855e-01, -9.144118112672673e-01,  5.880986220439612e-03,  
 2.738636464954728e-01, -4.180479898913641e-02,  1.973225599622812e-02,  
 2.741334945816214e-01, -6.688097177458799e-01,  1.552583691672160e-02,  
 2.806967904899877e-01, -9.837566472737467e-01,  3.668812731548744e-03,  
 2.878146592243341e-01,  8.096216755413393e-01,  1.248593716069912e-02,  
 2.928095492516591e-01, -8.296492444850465e-01,  1.002982078393012e-02,  
 3.003707713405964e-01,  1.574001974071592e-01,  2.081647115457695e-02,  
 3.032112900280739e-01, -3.213476683127075e-01,  1.986943316524076e-02,  
 3.038778633328361e-01, -5.155279822940786e-01,  2.132140323091509e-02,  
 3.189416740657732e-01,  5.301239563235857e-01,  1.599311728650303e-02,  
 3.379458538210279e-01,  3.380078043017812e-01,  2.231047709478462e-02,  
 3.414315269801313e-01, -9.447221797790122e-01,  7.193479552256923e-03,  
 3.451501869255189e-01,  9.911045296989844e-01,  3.150815381449179e-03,  
 3.459501416944350e-01,  9.412460482178074e-01,  7.581328265611393e-03,  
 3.498025442310060e-01,  7.259867843713310e-01,  1.534088761786192e-02,  
 3.506298151283278e-01, -1.110943927993918e-01,  1.551666339044610e-02,  
 3.508944053443432e-01, -8.597690806797168e-01,  6.780738534373333e-03,  
 3.676203412527344e-01, -7.355441788616041e-01,  1.449363179369764e-02,  
 3.775941728027782e-01, -9.966110448377157e-01,  1.588376651423708e-03,  
 3.860519270960796e-01,  7.302449463643648e-02,  1.674967274353688e-02,  
 3.908175824545033e-01,  6.040163725706776e-01,  1.278149700085847e-02,  
 3.932995953514418e-01,  8.586784918787448e-01,  9.330747431728702e-03,  
 4.009583889628902e-01, -2.237036393799572e-01,  1.892604307935697e-02,  
 4.132872901647590e-01, -4.161374351557686e-01,  2.138066163226836e-02,  
 4.156626605778777e-01, -6.064541375879013e-01,  1.924814510794154e-02,  
 4.275837181210796e-01,  9.094238876105997e-01,  4.770828940366273e-03,  
 4.328418582000582e-01,  4.496319777430270e-01,  1.936747828289653e-02,  
 4.385174796956023e-01, -8.999264574814262e-01,  9.370005851764580e-03,  
 4.416854437364063e-01, -9.738073510248620e-01,  4.796346619556446e-03,  
 4.421330688920201e-01,  2.374107327854063e-01,  2.181532535184939e-02,  
 4.550615803392936e-01,  9.726655099206181e-01,  5.179676710206462e-03,  
 4.569654688277525e-01,  6.884355926489272e-03,  1.583552991175338e-02,  
 4.632819243713829e-01, -8.003126851100022e-01,  1.316681225047508e-02,  
 4.689306146948844e-01,  6.814262213200711e-01,  1.334579482569558e-02,  
 4.696207639607174e-01,  7.988154952920899e-01,  1.184787022608413e-02,  
 4.857658052760571e-01,  9.984893866977577e-01,  1.096119304476565e-03,  
 4.993823494452720e-01, -1.215115809417293e-01,  1.866094748126752e-02,  
 5.147227675195748e-01, -3.085631716120487e-01,  2.105349795001905e-02,  
 5.165019514631053e-01,  5.527052226731102e-01,  1.594523958184094e-02,  
 5.184998491048611e-01, -5.122582772507516e-01,  1.944936029664543e-02,  
 5.212882108068023e-01,  8.912280598565898e-01,  6.430590724186390e-03,  
 5.216196172575923e-01, -6.918653721187973e-01,  1.673261806644407e-02,  
 5.267404688211808e-01, -9.928234349336557e-01,  2.264249969231592e-03,  
 5.337628878538487e-01,  3.562767541456822e-01,  1.973968319676171e-02,  
 5.362462702301273e-01, -9.419621269592201e-01,  7.018123899882877e-03,  
 5.376377966884078e-01,  9.405432980109936e-01,  5.735139534376493e-03,  
 5.414492290361640e-01,  1.392734385435706e-01,  2.077403754645742e-02,  
 5.609107809910865e-01, -8.610602440350434e-01,  1.065010493507847e-02,  
 5.657856622042965e-01,  7.599631423795741e-01,  1.071300749042643e-02,  
 5.853656077435417e-01,  9.875390366974179e-01,  3.152366608701943e-03,  
 5.901716003152813e-01,  6.434525496875014e-01,  1.295115318701735e-02,  
 5.926475181039332e-01, -1.394312891636593e-02,  1.831016768731409e-02,  
 6.004152984409479e-01,  8.529159644062866e-01,  9.481026402361680e-03,  
 6.117360608723036e-01, -1.986847607827743e-01,  1.980214313193597e-02,  
 6.130824033534686e-01, -4.095714300275702e-01,  1.917012065007447e-02,  
 6.151072377903102e-01,  4.701060842696129e-01,  1.706729076110463e-02,  
 6.159307791132325e-01, -7.726284834690805e-01,  1.314127931857205e-02,  
 6.178862021937575e-01, -6.037568023506926e-01,  1.700517763869981e-02,  
 6.233140115752496e-01, -9.990478475611962e-01,  5.756607762407137e-04,  
 6.233882556383349e-01, -9.736906648802569e-01,  4.400416908080170e-03,  
 6.293004246408224e-01,  2.602964866719539e-01,  1.911043777425127e-02,  
 6.354013023790106e-01,  9.594829356193809e-01,  3.875984169380209e-03,  
 6.531860907351404e-01, -9.129935732773705e-01,  7.993871581045829e-03,  
 6.669095378699366e-01,  7.212125041562338e-01,  1.115937328874872e-02,  
 6.682888522038171e-01,  9.170080181860093e-01,  6.711591614310012e-03,  
 6.733698677832002e-01,  9.531068015393949e-02,  1.704322733008138e-02,  
 6.867975790725386e-01,  5.732210324621596e-01,  1.405118611426179e-02,  
 6.877498285966892e-01,  9.972377597170190e-01,  1.171144176394094e-03,  
 6.919530077164939e-01,  8.183966376302371e-01,  8.546002645004975e-03,  
 7.006699775901079e-01, -3.018130078739841e-01,  1.797963536109381e-02,  
 7.007378604415206e-01, -6.967393023705793e-01,  1.347242645942421e-02,  
 7.011706428762506e-01, -8.645955499455821e-02,  1.805455337163264e-02,  
 7.046359024076116e-01, -8.408642058193949e-01,  1.001402071103762e-02,  
 7.050184040815621e-01, -5.062475643165765e-01,  1.662718203829281e-02,  
 7.059713500450162e-01,  3.789436426580511e-01,  1.673848305527229e-02,  
 7.069046616445557e-01, -9.908001304861944e-01,  1.978600063893940e-03,  
 7.266691397063710e-01,  9.764485842045145e-01,  3.196135869015411e-03,  
 7.363406109597423e-01, -9.531023692016642e-01,  5.413055258221468e-03,  
 7.430250973663187e-01,  2.035056651546192e-01,  1.504638709941723e-02,  
 7.535644399389860e-01,  8.879258118131659e-01,  7.006171198702037e-03,  
 7.563574258683842e-01,  6.568574070169740e-01,  1.127645966819047e-02,  
 7.667442271787138e-01,  7.756805658723509e-01,  8.207817118717271e-03,  
 7.701722119351029e-01,  9.513283511378082e-01,  3.288073973455126e-03,  
 7.726397716060590e-01,  4.891287757524024e-01,  1.380985802819005e-02,  
 7.763819833434896e-01, -6.108424957683033e-01,  1.316465009375289e-02,  
 7.765876970003720e-01, -9.983175720029679e-01,  5.530803312446341e-04,  
 7.783135272478848e-01,  3.067088271297034e-02,  1.617867766579491e-02,  
 7.789758903483420e-01, -7.755784522131605e-01,  1.024240381182082e-02,  
 7.794951515725598e-01, -1.900547136170159e-01,  1.605547922328266e-02,  
 7.827786520173903e-01, -4.013994693137274e-01,  1.542333829511010e-02,  
 7.859968639285212e-01, -8.957991066819440e-01,  7.388246252798941e-03,  
 8.019277506261744e-01,  3.096569162287749e-01,  1.321462723675400e-02,  
 8.046989562620047e-01,  9.934698121858433e-01,  1.620975163901152e-03,  
 8.116271678470535e-01, -9.812368844557581e-01,  2.805354005606401e-03,  
 8.271120113357940e-01,  8.445310805164534e-01,  7.391494649958003e-03,  
 8.315475863435614e-01,  9.349719428861505e-01,  4.319512065933182e-03,  
 8.321584209664755e-01,  7.156459468065629e-01,  8.211658184356523e-03,  
 8.346880955680183e-01,  5.790843779334668e-01,  1.053843380670116e-02,  
 8.421200025145761e-01, -5.163218277007364e-01,  1.214654046014649e-02,  
 8.428358142326123e-01, -7.004905652156834e-01,  9.807944160460698e-03,  
 8.429068230233057e-01,  1.506850609766789e-01,  1.392052411787133e-02,  
 8.469443668153608e-01, -7.373217636068097e-02,  1.387616447908254e-02,  
 8.499231814765066e-01, -2.903842316704804e-01,  1.345748857648198e-02,  
 8.509676963874204e-01, -9.421501714518346e-01,  4.512282801925937e-03,  
 8.513842034584429e-01, -8.385682243825499e-01,  7.589918785203049e-03,  
 8.529297252064996e-01,  9.788650415840999e-01,  1.767999675129546e-03,  
 8.548119318481671e-01,  4.129920008983965e-01,  1.142134843011626e-02,  
 8.743399003663345e-01, -9.965501332313196e-01,  8.866545706261915e-04,  
 8.868589131988083e-01,  7.813550256000477e-01,  7.028611053580085e-03,  
 8.882097576725707e-01,  8.967871781921426e-01,  5.131933562814728e-03,  
 8.940437357261795e-01,  6.448353054197643e-01,  7.532981116414975e-03,  
 8.951043245737870e-01,  2.701305401459678e-01,  1.119698691900426e-02,  
 8.957988629549595e-01, -6.172417311892393e-01,  8.745996105562806e-03,  
 8.966637138539476e-01, -4.139876550907898e-01,  1.042345398687548e-02,  
 8.972477740164735e-01,  9.688428320077953e-01,  2.185864494768297e-03,  
 9.009266678826738e-01,  9.978009702135497e-01,  6.895418046666433e-04,  
 9.018821552007310e-01,  4.650154498011889e-02,  1.144764316389570e-02,  
 9.031198283499343e-01, -8.990561632189207e-01,  4.723822492423395e-03,  
 9.045602400259568e-01, -7.701264771658067e-01,  7.053104592289312e-03,  
 9.053380379607494e-01, -1.746480109218232e-01,  1.103438645893049e-02,  
 9.054411149232872e-01, -9.744873584378785e-01,  2.378102961922232e-03,  
 9.055326931403324e-01,  5.042853365036326e-01,  8.843909529693304e-03,  
 9.343926720143196e-01,  8.408281722676378e-01,  4.939252078872689e-03,  
 9.369672998076496e-01,  9.392509664822630e-01,  3.036071275593237e-03,  
 9.370649990477178e-01, -5.263980680715866e-01,  7.197501644580989e-03,  
 9.375084976458372e-01,  3.772288160090471e-01,  7.723756326362103e-03,  
 9.381535834200617e-01,  7.106235070910863e-01,  5.902848304746877e-03,  
 9.397089401153526e-01, -3.064559939391279e-01,  8.183193061824199e-03,  
 9.430513485839862e-01, -8.453991555068732e-01,  4.259151291048153e-03,  
 9.439138207794857e-01,  1.694346027653371e-01,  8.711608432261320e-03,  
 9.453640500952915e-01, -6.918818219382270e-01,  5.811160329023696e-03,  
 9.458401661756128e-01, -9.433047135677757e-01,  2.666991866215932e-03,  
 9.474931749108476e-01, -9.934540488719975e-01,  9.077513966991803e-04,  
 9.480260033412141e-01, -5.528363383644061e-02,  8.344368695609054e-03,  
 9.515094736278008e-01,  9.869714675506723e-01,  1.367495384365193e-03,  
 9.522042365240376e-01,  5.775886113807980e-01,  6.278213478960007e-03,  
 9.666835796199322e-01,  4.481624968499795e-01,  3.204558585936675e-03,  
 9.674418063223464e-01, -4.304000963196550e-01,  5.347598797243928e-03,  
 9.701359035367135e-01, -7.802525506646220e-01,  3.115557673116472e-03,  
 9.701857271817536e-01,  8.938055399198392e-01,  2.864900302668842e-03,  
 9.708930152297497e-01, -1.958004635679564e-01,  5.654816581606078e-03,  
 9.714573561311842e-01,  7.782560227882267e-01,  3.821062888660015e-03,  
 9.738224913796117e-01, -6.066878673454835e-01,  4.238239901525744e-03,  
 9.743870386597691e-01, -9.005600796222234e-01,  2.292879276270914e-03,  
 9.748694751568308e-01,  2.872115060189273e-01,  5.488782914198373e-03,  
 9.770534257331674e-01, -9.733442069702187e-01,  1.220396530498849e-03,  
 9.773487838243448e-01,  6.742991425576679e-02,  5.516141834251902e-03,  
 9.807262602523558e-01,  9.605757763822972e-01,  1.453483834542216e-03,  
 9.821557641147268e-01,  6.556398036205757e-01,  3.678998334252915e-03,  
 9.839106243620387e-01,  9.977561756217526e-01,  2.768302865456187e-04,  
 9.847751712912336e-01,  4.874332090983019e-01,  3.074449052250624e-03,  
 9.872347823081763e-01, -8.347683105720206e-01,  1.269040121422027e-03,  
 9.873631625273047e-01, -3.284258517966067e-01,  3.314654538180889e-03,  
 9.878645619258249e-01, -9.970787084309179e-01,  2.392045469575733e-04,  
 9.891124753817594e-01, -7.120059529034396e-01,  2.190875058685215e-03,  
 9.904843680686551e-01, -8.399228923374426e-02,  3.184383491092044e-03,  
 9.911486992958609e-01, -5.172577211992232e-01,  2.483935260660239e-03,  
 9.926946438637168e-01,  8.406144684615959e-01,  1.680655250200566e-03,  
 9.940864938813981e-01, -9.401988730146373e-01,  8.590139939992197e-04,  
 9.941987746944642e-01,  1.912235208694665e-01,  2.518562325519789e-03,  
 9.960483559226059e-01,  3.732328466642290e-01,  1.950601561707686e-03,  
 9.962534123813316e-01,  9.225251976350251e-01,  7.835582462513657e-04,  
 9.966184286027521e-01, -8.738768172094957e-01,  6.340506805099443e-04,  
 9.968580870618724e-01,  7.336608062965726e-01,  1.218635259088649e-03,  
 9.972221719684324e-01,  9.836266811867312e-01,  3.070667564929675e-04,  
 9.973502464780108e-01,  5.703835859132225e-01,  1.316377370815025e-03,  
 9.977903571993221e-01, -2.217334569601657e-01,  1.243787387237352e-03,  
 9.981467866635252e-01, -7.852760517081546e-01,  5.930241241924707e-04,  
 9.983950085519884e-01, -6.322084663179760e-01,  8.416135676187133e-04,  
 9.984871758203762e-01, -9.838507269098428e-01,  1.976555370458795e-04,  
 9.985986690813101e-01, -4.178930731294047e-01,  8.254856487030795e-04,  
 9.989532297601191e-01,  3.236183825764132e-02,  9.014418551948622e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr49 ( )

/******************************************************************************/
/*
  Purpose:

    SMR49 returns the SMR rule of degree 49.

  Discussion:

    DEGREE: 49
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 427
    NORM INF MOMS. RESIDUAL: 4.24357e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR49[3*427], the requested rule.
*/
{
  const int degree = 49;
  int order;
  double xw[3*427] = {
 -9.987179482199477e-01, -6.341055456784180e-02,  9.427263494251746e-04,  
 -9.985820051950299e-01,  4.311577677096960e-01,  8.506787489756313e-04,  
 -9.985812215892117e-01,  2.098862069679553e-01,  9.932558396288942e-04,  
 -9.984853824993025e-01, -7.518363345257131e-01,  6.752050933944545e-04,  
 -9.984416520882323e-01, -8.814083896367437e-01,  4.548127997472904e-04,  
 -9.983293539476047e-01,  9.835120159252404e-01,  2.181997023647311e-04,  
 -9.982115219214424e-01,  6.305047404346029e-01,  8.136830618787968e-04,  
 -9.978435386703776e-01,  7.692080150297662e-01,  6.598609318533428e-04,  
 -9.977221586114358e-01, -6.019952067889782e-01,  5.964708123101566e-04,  
 -9.966209533584591e-01, -3.237318892379179e-01,  1.736701233968157e-03,  
 -9.963148656482692e-01, -9.861307505276973e-01,  3.364793817721787e-04,  
 -9.959458468526172e-01,  8.639404647925895e-01,  9.127209022448868e-04,  
 -9.955419051779023e-01, -5.028006893760714e-01,  1.625315064214383e-03,  
 -9.939777572418940e-01,  9.377670381442861e-01,  9.071335269558794e-04,  
 -9.931100571448706e-01, -9.398758417699402e-01,  9.653046269879767e-04,  
 -9.914404533622192e-01,  7.370377576026632e-02,  3.114508431996894e-03,  
 -9.910529016163073e-01, -1.720232075920507e-01,  2.834840262020965e-03,  
 -9.904412956303582e-01,  5.265151744794012e-01,  2.514644595413010e-03,  
 -9.897745584940826e-01,  3.209639101085088e-01,  3.026155349324961e-03,  
 -9.896878613799838e-01, -6.734414823238595e-01,  2.206204039428005e-03,  
 -9.896446181606325e-01, -8.258526268641876e-01,  1.761173631057456e-03,  
 -9.882983824911455e-01,  7.029568166797684e-01,  2.101767111893595e-03,  
 -9.870995148246587e-01,  9.971266172517755e-01,  2.522985579422540e-04,  
 -9.828402728207225e-01,  8.130859429654207e-01,  1.813569870463969e-03,  
 -9.805838302292789e-01, -4.186960243528708e-01,  4.224419641522761e-03,  
 -9.799683347097561e-01, -9.982787940792663e-01,  2.802539460088801e-04,  
 -9.768576153531923e-01,  9.720516240923431e-01,  1.260176677733168e-03,  
 -9.737646096663447e-01,  8.979365374145354e-01,  2.417846375635086e-03,  
 -9.736351786214140e-01, -5.825032309876242e-01,  4.276722297762739e-03,  
 -9.734565439099904e-01, -8.924228057613435e-01,  2.621925808197151e-03,  
 -9.729306672713298e-01,  1.937971855968040e-01,  5.661441805111854e-03,  
 -9.728709777782690e-01, -9.691292467666289e-01,  1.466141068305907e-03,  
 -9.726983304977663e-01, -4.425763588680746e-02,  5.881914856745899e-03,  
 -9.715318079839266e-01,  6.114344673195419e-01,  4.212935529909797e-03,  
 -9.711831524640260e-01, -7.579747866842650e-01,  3.663853318492690e-03,  
 -9.709279126257970e-01, -2.562383260371136e-01,  5.255024629747484e-03,  
 -9.708137869429159e-01,  4.239389021325329e-01,  5.141869518483292e-03,  
 -9.664977673747553e-01,  7.669983680205528e-01,  2.614941215020715e-03,  
 -9.469548060003440e-01,  9.927873239383316e-01,  9.693950321163949e-04,  
 -9.450858475738110e-01, -5.025373008969878e-01,  6.252666523418040e-03,  
 -9.448077504847031e-01,  9.425192762886759e-01,  2.715142333531406e-03,  
 -9.432745759141794e-01, -3.578284894473978e-01,  6.177743639544537e-03,  
 -9.432551757252079e-01, -6.778512313399264e-01,  5.997726172859794e-03,  
 -9.425924799508709e-01,  7.723036765423268e-02,  8.594457541849910e-03,  
 -9.424045442737207e-01,  6.965818136607429e-01,  5.492047852799914e-03,  
 -9.422279295242960e-01,  8.430010110128885e-01,  4.356685968058319e-03,  
 -9.421296116189286e-01,  3.072458818807862e-01,  8.166950645809414e-03,  
 -9.414068461363603e-01, -8.319946383779213e-01,  4.899221558401311e-03,  
 -9.401222897124206e-01,  5.208371173674092e-01,  7.080933689521712e-03,  
 -9.396692618824576e-01, -9.333268377293767e-01,  3.176964275867470e-03,  
 -9.387594609269243e-01, -9.896419412770018e-01,  1.315181972642427e-03,  
 -9.376865583713452e-01, -1.472997681505319e-01,  8.802757771504873e-03,  
 -9.058866443920447e-01, -2.915118591864504e-01,  7.312514214991043e-03,  
 -9.033753194459962e-01,  9.739301226929417e-01,  2.430898666967969e-03,  
 -9.026928782557422e-01, -5.971154860482422e-01,  8.134575081016936e-03,  
 -9.021900638531539e-01,  8.986885201991707e-01,  4.735976500809632e-03,  
 -9.006876027333818e-01,  7.738025214543742e-01,  6.953572521005407e-03,  
 -9.000160662012473e-01,  1.936545205467035e-01,  1.105560603537899e-02,  
 -8.994183334513204e-01, -7.589002650753883e-01,  7.412012270186419e-03,  
 -8.991432933902236e-01,  6.161569102595980e-01,  8.649321074038529e-03,  
 -8.990136642719798e-01,  4.154161042204226e-01,  1.027033600307130e-02,  
 -8.955650716170729e-01, -2.889828380654945e-02,  1.141690753127995e-02,  
 -8.934822042254417e-01, -8.849206485200981e-01,  5.481269950434707e-03,  
 -8.925866230961302e-01, -9.651738737461483e-01,  3.087139101703460e-03,  
 -8.916399066676414e-01, -4.478690090838509e-01,  8.958243051785242e-03,  
 -8.787467882854940e-01, -9.974975541031985e-01,  7.520196736734306e-04,  
 -8.768368119879948e-01,  9.972195337276928e-01,  7.824958500505416e-04,  
 -8.688111752985119e-01, -2.062730881400507e-01,  1.032123607597266e-02,  
 -8.488444646215817e-01,  9.417487190138607e-01,  4.527482466935922e-03,  
 -8.483308513877643e-01,  8.420081277059801e-01,  7.356656581421614e-03,  
 -8.465974052776020e-01, -6.804500384380086e-01,  9.439844848201484e-03,  
 -8.457711905447103e-01,  3.060565758105315e-01,  1.313083077355583e-02,  
 -8.454498037908205e-01,  5.197883189451455e-01,  1.190856918137506e-02,  
 -8.440484090367564e-01,  6.995813955156258e-01,  9.801510245897441e-03,  
 -8.420990261538619e-01,  8.700843845073450e-02,  1.361576981188029e-02,  
 -8.387107616534492e-01, -8.225135460279916e-01,  8.023995882685042e-03,  
 -8.342806635072800e-01, -3.686663614256265e-01,  1.185649053487261e-02,  
 -8.341324042868387e-01, -5.413042996556211e-01,  1.028726411584244e-02,  
 -8.328917808999070e-01, -9.275746498999357e-01,  5.345327410698648e-03,  
 -8.222752044712189e-01, -9.828983653726329e-01,  2.569844448228937e-03,  
 -8.181510041117529e-01, -1.013221207184385e-01,  1.380702843362417e-02,  
 -8.152169502901689e-01,  9.831801913034185e-01,  2.619950174549044e-03,  
 -7.828790059504277e-01,  8.970932838288118e-01,  7.123319843648826e-03,  
 -7.814359340875883e-01,  4.148826331713472e-01,  1.479944058585885e-02,  
 -7.801982799083059e-01,  7.770472357073510e-01,  1.015003094959520e-02,  
 -7.785783303955014e-01,  6.125037703604832e-01,  1.287366180571384e-02,  
 -7.781640573729546e-01,  1.995944750196611e-01,  1.546595460903855e-02,  
 -7.780033996472984e-01, -2.651062610509234e-01,  1.437115393673534e-02,  
 -7.761306169624727e-01, -7.501004998319117e-01,  9.930943224422817e-03,  
 -7.715857235482023e-01,  9.983428621580931e-01,  5.452222266440912e-04,  
 -7.655483726416725e-01, -8.750797093910616e-01,  7.985877894766822e-03,  
 -7.650517717498729e-01, -4.715771704307840e-01,  1.255037589648692e-02,  
 -7.638158346191554e-01, -6.256899643054369e-01,  1.089753036742033e-02,  
 -7.586912864075982e-01, -9.961911332837330e-01,  1.179272785443735e-03,  
 -7.531768231132037e-01,  1.201386227993326e-02,  1.642203608617212e-02,  
 -7.525943724917873e-01, -9.538377812626558e-01,  4.657805305389900e-03,  
 -7.425465126897265e-01,  9.565892784834152e-01,  4.976897852233662e-03,  
 -7.120337647362697e-01, -1.543105022946922e-01,  1.667558344244733e-02,  
 -7.058491208433765e-01,  9.915756755872566e-01,  1.790261844614419e-03,  
 -7.050966153827319e-01,  3.088933084722713e-01,  1.701475236717927e-02,  
 -7.050386520037029e-01,  5.147871049065931e-01,  1.577829434551910e-02,  
 -7.044541730236628e-01,  8.417075739142680e-01,  9.820401163435438e-03,  
 -7.038938546524356e-01,  6.992970712529386e-01,  1.317427859481092e-02,  
 -7.030786952640691e-01, -3.737683313436290e-01,  1.533113926314000e-02,  
 -6.952697432642575e-01, -8.074711595576919e-01,  9.903249938089028e-03,  
 -6.874559480675843e-01, -9.781638816357989e-01,  3.101643133626598e-03,  
 -6.843864494264393e-01, -5.640703334807048e-01,  1.247073498122494e-02,  
 -6.791674419638026e-01, -6.963055362251113e-01,  1.115720692184079e-02,  
 -6.763078266684166e-01,  1.264181240942355e-01,  1.836539066857489e-02,  
 -6.743529219450092e-01, -9.106698394539678e-01,  7.349919293946242e-03,  
 -6.621044246635598e-01,  9.176320041970745e-01,  7.378997680603661e-03,  
 -6.431249402968114e-01, -9.960239767584596e-01,  1.189113707782781e-03,  
 -6.349167527421143e-01, -4.120238337350225e-02,  1.855565407496183e-02,  
 -6.332996010231378e-01,  9.748499154546882e-01,  3.858727420800304e-03,  
 -6.308194378333426e-01, -2.632109226108148e-01,  1.804417109814068e-02,  
 -6.216612560681409e-01,  4.121887181945136e-01,  1.799934456348149e-02,  
 -6.209382034591413e-01,  6.097444447472842e-01,  1.619622888897558e-02,  
 -6.184436204963421e-01,  7.739873263881869e-01,  1.280285540627544e-02,  
 -6.181782824659667e-01, -4.720385956358120e-01,  1.570128558680570e-02,  
 -6.088138333002981e-01,  9.988834235712669e-01,  6.368095509394178e-04,  
 -6.065399576093181e-01, -8.463858971291857e-01,  8.079219530748298e-03,  
 -5.996620894961030e-01, -9.482291632711998e-01,  5.540693800633477e-03,  
 -5.902607741689768e-01,  2.385643885392057e-01,  1.956867882471149e-02,  
 -5.879157685226737e-01, -6.347809747856457e-01,  1.176279561786886e-02,  
 -5.837357122734029e-01, -7.476017166168016e-01,  1.139197942656491e-02,  
 -5.736831191631178e-01,  8.680031315190274e-01,  9.765401515377791e-03,  
 -5.642269847367442e-01, -9.833709030918961e-01,  2.797162890164879e-03,  
 -5.513432891392764e-01,  9.450770682538761e-01,  6.170899375503570e-03,  
 -5.500959245098467e-01, -8.702213264603355e-01,  4.396899487663076e-03,  
 -5.483041549056678e-01,  7.179049125370220e-02,  1.968682836966377e-02,  
 -5.464176822976653e-01, -1.467074339338491e-01,  2.005834944791575e-02,  
 -5.403151496840451e-01, -3.630610758750227e-01,  1.886598318155659e-02,  
 -5.340189262268797e-01,  9.912655376872981e-01,  2.067175993092469e-03,  
 -5.310500417455106e-01,  5.118198224616344e-01,  1.858069243154359e-02,  
 -5.266542221288756e-01,  6.945596957359338e-01,  1.591896408992095e-02,  
 -5.205326762839934e-01, -5.526298443835523e-01,  1.463536127791667e-02,  
 -5.077007528436556e-01, -9.110215108206120e-01,  6.879755450888522e-03,  
 -4.983192797981136e-01, -9.976115668643906e-01,  1.171541751761967e-03,  
 -4.951332232653569e-01,  3.460504369406958e-01,  2.023874109373681e-02,  
 -4.835426583725593e-01,  8.111430213132370e-01,  1.157971471365758e-02,  
 -4.813959504258653e-01, -7.906922160702855e-01,  1.227086240600740e-02,  
 -4.710786595525681e-01, -6.776468702229034e-01,  1.309017893729792e-02,  
 -4.684016915514839e-01, -9.631060061929865e-01,  5.069810155479069e-03,  
 -4.601634273592006e-01,  9.736184752433025e-01,  3.981032410636509e-03,  
 -4.586406152579688e-01,  9.067429858222903e-01,  8.151450352060937e-03,  
 -4.581246913316372e-01,  1.846374671629571e-01,  1.859836421630574e-02,  
 -4.542591579155089e-01, -2.533998951051241e-02,  2.019107274450048e-02,  
 -4.507016433960112e-01, -2.452585642576526e-01,  2.097607879874488e-02,  
 -4.405266836969018e-01, -4.527844645321407e-01,  1.865598696449664e-02,  
 -4.313857093444732e-01,  6.040918064374622e-01,  1.842506376270006e-02,  
 -4.267485951806373e-01, -8.688547899404195e-01,  6.723705742819690e-03,  
 -4.131499625978771e-01,  9.970815492711668e-01,  1.271249087845813e-03,  
 -3.986015122530552e-01,  7.510577780393508e-01,  1.269074691033858e-02,  
 -3.967149116103497e-01, -6.041689107858602e-01,  1.192636288654412e-02,  
 -3.961555040155331e-01,  4.470760721116281e-01,  2.010362718935436e-02,  
 -3.870311898550397e-01, -9.875044282645365e-01,  3.406124439417308e-03,  
 -3.759111439580939e-01,  8.681044983359713e-01,  7.567587310258595e-03,  
 -3.733018295823582e-01,  1.124745920090000e-01,  1.444272159271557e-02,  
 -3.698211803848768e-01,  9.497944995362068e-01,  5.588072557089718e-03,  
 -3.677520025284451e-01, -9.304735975401455e-01,  7.985180614906596e-03,  
 -3.647799432566780e-01, -1.113354938202836e-01,  1.869502288898936e-02,  
 -3.564395741412303e-01, -7.281106510086501e-01,  1.411781032844452e-02,  
 -3.557949371891208e-01, -8.330285597968599e-01,  9.641510028740691e-03,  
 -3.555243523154669e-01,  2.839179571854041e-01,  1.993717563297461e-02,  
 -3.484889009386569e-01, -3.392883270625222e-01,  2.140162840707676e-02,  
 -3.283812713294078e-01, -5.303954087605249e-01,  1.601217072102609e-02,  
 -3.195420634648112e-01,  9.856964924833570e-01,  3.355668049705953e-03,  
 -3.183691341673544e-01,  6.823032199063920e-01,  1.502246554463540e-02,  
 -3.044813423163074e-01,  8.293787725761752e-01,  1.046325726611303e-02,  
 -2.987630526075223e-01,  4.684092365905865e-02,  1.926775266958230e-02,  
 -2.936532335470334e-01,  5.403974535032333e-01,  1.910165254855807e-02,  
 -2.839114443643144e-01, -9.982115043292803e-01,  1.188632971361439e-03,  
 -2.838714383237747e-01,  9.229409872704248e-01,  6.670754525457344e-03,  
 -2.810131840539091e-01, -1.888679679442530e-01,  1.832810176225835e-02,  
 -2.687507311235811e-01, -9.661991515046374e-01,  6.311482289862918e-03,  
 -2.656987431438242e-01, -6.579434003777319e-01,  1.182247248408541e-02,  
 -2.614828276593449e-01,  3.765883630233104e-01,  1.796650685355945e-02,  
 -2.531943910872507e-01, -8.899457540567935e-01,  1.092169990171894e-02,  
 -2.406846427640522e-01, -7.855631193658050e-01,  1.359117656318325e-02,  
 -2.391816880092877e-01, -4.306619043003660e-01,  2.108838808511827e-02,  
 -2.355724334549767e-01,  2.049280038734326e-01,  2.190235001744360e-02,  
 -2.230244166633031e-01,  9.979412002068919e-01,  1.240219580715109e-03,  
 -2.143016309053875e-01,  7.672825366517191e-01,  1.532929818887211e-02,  
 -2.084210826685112e-01, -6.026618831861471e-01,  1.266723448088261e-02,  
 -2.074608754565781e-01,  9.668302372454330e-01,  5.784281081186120e-03,  
 -1.994470236746966e-01, -4.262641530424785e-02,  2.336758693844741e-02,  
 -1.953909451600504e-01,  8.884510132587173e-01,  9.639725933265000e-03,  
 -1.947973443282949e-01,  6.327934412393972e-01,  1.604045001285653e-02,  
 -1.934348429848317e-01, -2.676344080255245e-01,  1.945754749492376e-02,  
 -1.731674619232558e-01,  4.594347331929800e-01,  1.701418105871642e-02,  
 -1.581108634025118e-01, -9.886241341680647e-01,  3.738115075160524e-03,  
 -1.422635614677805e-01, -9.353836759115295e-01,  9.131973629103902e-03,  
 -1.361305424868328e-01,  1.223782786800707e-01,  2.022098154521878e-02,  
 -1.332706201055330e-01, -7.135796064753009e-01,  1.658816867334942e-02,  
 -1.279679844994012e-01, -8.428571211216312e-01,  1.270368784787859e-02,  
 -1.215680553809675e-01, -5.177010109986793e-01,  2.044565322938263e-02,  
 -1.191841609577679e-01,  3.166199536093801e-01,  2.232566149349017e-02,  
 -1.030306575568989e-01,  5.564353141202014e-01,  1.319022417392010e-02,  
 -1.010032725708720e-01,  8.358781872733483e-01,  1.317927677377359e-02,  
 -9.793911367017349e-02, -3.496629047055283e-01,  2.036641167270025e-02,  
 -9.632162801653921e-02,  9.888966773648641e-01,  3.635491187724198e-03,  
 -9.413622131664506e-02, -1.384648595071072e-01,  2.325132772759284e-02,  
 -9.173762319021858e-02,  9.377720732845000e-01,  8.484100706145753e-03,  
 -8.621270959290740e-02,  7.067235284679263e-01,  1.663872363860805e-02,  
 -4.600495484763667e-02,  4.189736454726613e-02,  2.011405200689851e-02,  
 -3.846886242278941e-02,  5.343444763759839e-01,  7.629129920225949e-03,  
 -3.114682416899431e-02, -9.984328758619065e-01,  1.215239197082301e-03,  
 -3.079267631383417e-02, -6.283320709748856e-01,  1.866968865866494e-02,  
 -2.943594515930726e-02, -9.691705324016726e-01,  6.300149444345140e-03,  
 -1.716717474844928e-02, -7.802924106209882e-01,  1.460622280342255e-02,  
 -1.471848835947739e-02, -8.938525086535020e-01,  1.128301163750197e-02,  
 -9.971581147176094e-03,  2.306776723300077e-01,  2.246786582285274e-02,  
 -9.401058469724652e-03,  4.283083438750301e-01,  2.037055156805384e-02,  
 0.000000000000000e+00,  0.000000000000000e+00,  5.253249918853668e-04,  
 9.401058469724652e-03, -4.283083438750301e-01,  2.037055156805384e-02,  
 9.971581147176094e-03, -2.306776723300077e-01,  2.246786582285274e-02,  
 1.471848835947739e-02,  8.938525086535020e-01,  1.128301163750197e-02,  
 1.716717474844928e-02,  7.802924106209882e-01,  1.460622280342255e-02,  
 2.943594515930726e-02,  9.691705324016726e-01,  6.300149444345140e-03,  
 3.079267631383417e-02,  6.283320709748856e-01,  1.866968865866494e-02,  
 3.114682416899431e-02,  9.984328758619065e-01,  1.215239197082301e-03,  
 3.846886242278941e-02, -5.343444763759839e-01,  7.629129920225949e-03,  
 4.600495484763667e-02, -4.189736454726613e-02,  2.011405200689851e-02,  
 8.621270959290740e-02, -7.067235284679263e-01,  1.663872363860805e-02,  
 9.173762319021858e-02, -9.377720732845000e-01,  8.484100706145753e-03,  
 9.413622131664506e-02,  1.384648595071072e-01,  2.325132772759284e-02,  
 9.632162801653921e-02, -9.888966773648641e-01,  3.635491187724198e-03,  
 9.793911367017349e-02,  3.496629047055283e-01,  2.036641167270025e-02,  
 1.010032725708720e-01, -8.358781872733483e-01,  1.317927677377359e-02,  
 1.030306575568989e-01, -5.564353141202014e-01,  1.319022417392010e-02,  
 1.191841609577679e-01, -3.166199536093801e-01,  2.232566149349017e-02,  
 1.215680553809675e-01,  5.177010109986793e-01,  2.044565322938263e-02,  
 1.279679844994012e-01,  8.428571211216312e-01,  1.270368784787859e-02,  
 1.332706201055330e-01,  7.135796064753009e-01,  1.658816867334942e-02,  
 1.361305424868328e-01, -1.223782786800707e-01,  2.022098154521878e-02,  
 1.422635614677805e-01,  9.353836759115295e-01,  9.131973629103902e-03,  
 1.581108634025118e-01,  9.886241341680647e-01,  3.738115075160524e-03,  
 1.731674619232558e-01, -4.594347331929800e-01,  1.701418105871642e-02,  
 1.934348429848317e-01,  2.676344080255245e-01,  1.945754749492376e-02,  
 1.947973443282949e-01, -6.327934412393972e-01,  1.604045001285653e-02,  
 1.953909451600504e-01, -8.884510132587173e-01,  9.639725933265000e-03,  
 1.994470236746966e-01,  4.262641530424785e-02,  2.336758693844741e-02,  
 2.074608754565781e-01, -9.668302372454330e-01,  5.784281081186120e-03,  
 2.084210826685112e-01,  6.026618831861471e-01,  1.266723448088261e-02,  
 2.143016309053875e-01, -7.672825366517191e-01,  1.532929818887211e-02,  
 2.230244166633031e-01, -9.979412002068919e-01,  1.240219580715109e-03,  
 2.355724334549767e-01, -2.049280038734326e-01,  2.190235001744360e-02,  
 2.391816880092877e-01,  4.306619043003660e-01,  2.108838808511827e-02,  
 2.406846427640522e-01,  7.855631193658050e-01,  1.359117656318325e-02,  
 2.531943910872507e-01,  8.899457540567935e-01,  1.092169990171894e-02,  
 2.614828276593449e-01, -3.765883630233104e-01,  1.796650685355945e-02,  
 2.656987431438242e-01,  6.579434003777319e-01,  1.182247248408541e-02,  
 2.687507311235811e-01,  9.661991515046374e-01,  6.311482289862918e-03,  
 2.810131840539091e-01,  1.888679679442530e-01,  1.832810176225835e-02,  
 2.838714383237747e-01, -9.229409872704248e-01,  6.670754525457344e-03,  
 2.839114443643144e-01,  9.982115043292803e-01,  1.188632971361439e-03,  
 2.936532335470334e-01, -5.403974535032333e-01,  1.910165254855807e-02,  
 2.987630526075223e-01, -4.684092365905865e-02,  1.926775266958230e-02,  
 3.044813423163074e-01, -8.293787725761752e-01,  1.046325726611303e-02,  
 3.183691341673544e-01, -6.823032199063920e-01,  1.502246554463540e-02,  
 3.195420634648112e-01, -9.856964924833570e-01,  3.355668049705953e-03,  
 3.283812713294078e-01,  5.303954087605249e-01,  1.601217072102609e-02,  
 3.484889009386569e-01,  3.392883270625222e-01,  2.140162840707676e-02,  
 3.555243523154669e-01, -2.839179571854041e-01,  1.993717563297461e-02,  
 3.557949371891208e-01,  8.330285597968599e-01,  9.641510028740691e-03,  
 3.564395741412303e-01,  7.281106510086501e-01,  1.411781032844452e-02,  
 3.647799432566780e-01,  1.113354938202836e-01,  1.869502288898936e-02,  
 3.677520025284451e-01,  9.304735975401455e-01,  7.985180614906596e-03,  
 3.698211803848768e-01, -9.497944995362068e-01,  5.588072557089718e-03,  
 3.733018295823582e-01, -1.124745920090000e-01,  1.444272159271557e-02,  
 3.759111439580939e-01, -8.681044983359713e-01,  7.567587310258595e-03,  
 3.870311898550397e-01,  9.875044282645365e-01,  3.406124439417308e-03,  
 3.961555040155331e-01, -4.470760721116281e-01,  2.010362718935436e-02,  
 3.967149116103497e-01,  6.041689107858602e-01,  1.192636288654412e-02,  
 3.986015122530552e-01, -7.510577780393508e-01,  1.269074691033858e-02,  
 4.131499625978771e-01, -9.970815492711668e-01,  1.271249087845813e-03,  
 4.267485951806373e-01,  8.688547899404195e-01,  6.723705742819690e-03,  
 4.313857093444732e-01, -6.040918064374622e-01,  1.842506376270006e-02,  
 4.405266836969018e-01,  4.527844645321407e-01,  1.865598696449664e-02,  
 4.507016433960112e-01,  2.452585642576526e-01,  2.097607879874488e-02,  
 4.542591579155089e-01,  2.533998951051241e-02,  2.019107274450048e-02,  
 4.581246913316372e-01, -1.846374671629571e-01,  1.859836421630574e-02,  
 4.586406152579688e-01, -9.067429858222903e-01,  8.151450352060937e-03,  
 4.601634273592006e-01, -9.736184752433025e-01,  3.981032410636509e-03,  
 4.684016915514839e-01,  9.631060061929865e-01,  5.069810155479069e-03,  
 4.710786595525681e-01,  6.776468702229034e-01,  1.309017893729792e-02,  
 4.813959504258653e-01,  7.906922160702855e-01,  1.227086240600740e-02,  
 4.835426583725593e-01, -8.111430213132370e-01,  1.157971471365758e-02,  
 4.951332232653569e-01, -3.460504369406958e-01,  2.023874109373681e-02,  
 4.983192797981136e-01,  9.976115668643906e-01,  1.171541751761967e-03,  
 5.077007528436556e-01,  9.110215108206120e-01,  6.879755450888522e-03,  
 5.205326762839934e-01,  5.526298443835523e-01,  1.463536127791667e-02,  
 5.266542221288756e-01, -6.945596957359338e-01,  1.591896408992095e-02,  
 5.310500417455106e-01, -5.118198224616344e-01,  1.858069243154359e-02,  
 5.340189262268797e-01, -9.912655376872981e-01,  2.067175993092469e-03,  
 5.403151496840451e-01,  3.630610758750227e-01,  1.886598318155659e-02,  
 5.464176822976653e-01,  1.467074339338491e-01,  2.005834944791575e-02,  
 5.483041549056678e-01, -7.179049125370220e-02,  1.968682836966377e-02,  
 5.500959245098467e-01,  8.702213264603355e-01,  4.396899487663076e-03,  
 5.513432891392764e-01, -9.450770682538761e-01,  6.170899375503570e-03,  
 5.642269847367442e-01,  9.833709030918961e-01,  2.797162890164879e-03,  
 5.736831191631178e-01, -8.680031315190274e-01,  9.765401515377791e-03,  
 5.837357122734029e-01,  7.476017166168016e-01,  1.139197942656491e-02,  
 5.879157685226737e-01,  6.347809747856457e-01,  1.176279561786886e-02,  
 5.902607741689768e-01, -2.385643885392057e-01,  1.956867882471149e-02,  
 5.996620894961030e-01,  9.482291632711998e-01,  5.540693800633477e-03,  
 6.065399576093181e-01,  8.463858971291857e-01,  8.079219530748298e-03,  
 6.088138333002981e-01, -9.988834235712669e-01,  6.368095509394178e-04,  
 6.181782824659667e-01,  4.720385956358120e-01,  1.570128558680570e-02,  
 6.184436204963421e-01, -7.739873263881869e-01,  1.280285540627544e-02,  
 6.209382034591413e-01, -6.097444447472842e-01,  1.619622888897558e-02,  
 6.216612560681409e-01, -4.121887181945136e-01,  1.799934456348149e-02,  
 6.308194378333426e-01,  2.632109226108148e-01,  1.804417109814068e-02,  
 6.332996010231378e-01, -9.748499154546882e-01,  3.858727420800304e-03,  
 6.349167527421143e-01,  4.120238337350225e-02,  1.855565407496183e-02,  
 6.431249402968114e-01,  9.960239767584596e-01,  1.189113707782781e-03,  
 6.621044246635598e-01, -9.176320041970745e-01,  7.378997680603661e-03,  
 6.743529219450092e-01,  9.106698394539678e-01,  7.349919293946242e-03,  
 6.763078266684166e-01, -1.264181240942355e-01,  1.836539066857489e-02,  
 6.791674419638026e-01,  6.963055362251113e-01,  1.115720692184079e-02,  
 6.843864494264393e-01,  5.640703334807048e-01,  1.247073498122494e-02,  
 6.874559480675843e-01,  9.781638816357989e-01,  3.101643133626598e-03,  
 6.952697432642575e-01,  8.074711595576919e-01,  9.903249938089028e-03,  
 7.030786952640691e-01,  3.737683313436290e-01,  1.533113926314000e-02,  
 7.038938546524356e-01, -6.992970712529386e-01,  1.317427859481092e-02,  
 7.044541730236628e-01, -8.417075739142680e-01,  9.820401163435438e-03,  
 7.050386520037029e-01, -5.147871049065931e-01,  1.577829434551910e-02,  
 7.050966153827319e-01, -3.088933084722713e-01,  1.701475236717927e-02,  
 7.058491208433765e-01, -9.915756755872566e-01,  1.790261844614419e-03,  
 7.120337647362697e-01,  1.543105022946922e-01,  1.667558344244733e-02,  
 7.425465126897265e-01, -9.565892784834152e-01,  4.976897852233662e-03,  
 7.525943724917873e-01,  9.538377812626558e-01,  4.657805305389900e-03,  
 7.531768231132037e-01, -1.201386227993326e-02,  1.642203608617212e-02,  
 7.586912864075982e-01,  9.961911332837330e-01,  1.179272785443735e-03,  
 7.638158346191554e-01,  6.256899643054369e-01,  1.089753036742033e-02,  
 7.650517717498729e-01,  4.715771704307840e-01,  1.255037589648692e-02,  
 7.655483726416725e-01,  8.750797093910616e-01,  7.985877894766822e-03,  
 7.715857235482023e-01, -9.983428621580931e-01,  5.452222266440912e-04,  
 7.761306169624727e-01,  7.501004998319117e-01,  9.930943224422817e-03,  
 7.780033996472984e-01,  2.651062610509234e-01,  1.437115393673534e-02,  
 7.781640573729546e-01, -1.995944750196611e-01,  1.546595460903855e-02,  
 7.785783303955014e-01, -6.125037703604832e-01,  1.287366180571384e-02,  
 7.801982799083059e-01, -7.770472357073510e-01,  1.015003094959520e-02,  
 7.814359340875883e-01, -4.148826331713472e-01,  1.479944058585885e-02,  
 7.828790059504277e-01, -8.970932838288118e-01,  7.123319843648826e-03,  
 8.152169502901689e-01, -9.831801913034185e-01,  2.619950174549044e-03,  
 8.181510041117529e-01,  1.013221207184385e-01,  1.380702843362417e-02,  
 8.222752044712189e-01,  9.828983653726329e-01,  2.569844448228937e-03,  
 8.328917808999070e-01,  9.275746498999357e-01,  5.345327410698648e-03,  
 8.341324042868387e-01,  5.413042996556211e-01,  1.028726411584244e-02,  
 8.342806635072800e-01,  3.686663614256265e-01,  1.185649053487261e-02,  
 8.387107616534492e-01,  8.225135460279916e-01,  8.023995882685042e-03,  
 8.420990261538619e-01, -8.700843845073450e-02,  1.361576981188029e-02,  
 8.440484090367564e-01, -6.995813955156258e-01,  9.801510245897441e-03,  
 8.454498037908205e-01, -5.197883189451455e-01,  1.190856918137506e-02,  
 8.457711905447103e-01, -3.060565758105315e-01,  1.313083077355583e-02,  
 8.465974052776020e-01,  6.804500384380086e-01,  9.439844848201484e-03,  
 8.483308513877643e-01, -8.420081277059801e-01,  7.356656581421614e-03,  
 8.488444646215817e-01, -9.417487190138607e-01,  4.527482466935922e-03,  
 8.688111752985119e-01,  2.062730881400507e-01,  1.032123607597266e-02,  
 8.768368119879948e-01, -9.972195337276928e-01,  7.824958500505416e-04,  
 8.787467882854940e-01,  9.974975541031985e-01,  7.520196736734306e-04,  
 8.916399066676414e-01,  4.478690090838509e-01,  8.958243051785242e-03,  
 8.925866230961302e-01,  9.651738737461483e-01,  3.087139101703460e-03,  
 8.934822042254417e-01,  8.849206485200981e-01,  5.481269950434707e-03,  
 8.955650716170729e-01,  2.889828380654945e-02,  1.141690753127995e-02,  
 8.990136642719798e-01, -4.154161042204226e-01,  1.027033600307130e-02,  
 8.991432933902236e-01, -6.161569102595980e-01,  8.649321074038529e-03,  
 8.994183334513204e-01,  7.589002650753883e-01,  7.412012270186419e-03,  
 9.000160662012473e-01, -1.936545205467035e-01,  1.105560603537899e-02,  
 9.006876027333818e-01, -7.738025214543742e-01,  6.953572521005407e-03,  
 9.021900638531539e-01, -8.986885201991707e-01,  4.735976500809632e-03,  
 9.026928782557422e-01,  5.971154860482422e-01,  8.134575081016936e-03,  
 9.033753194459962e-01, -9.739301226929417e-01,  2.430898666967969e-03,  
 9.058866443920447e-01,  2.915118591864504e-01,  7.312514214991043e-03,  
 9.376865583713452e-01,  1.472997681505319e-01,  8.802757771504873e-03,  
 9.387594609269243e-01,  9.896419412770018e-01,  1.315181972642427e-03,  
 9.396692618824576e-01,  9.333268377293767e-01,  3.176964275867470e-03,  
 9.401222897124206e-01, -5.208371173674092e-01,  7.080933689521712e-03,  
 9.414068461363603e-01,  8.319946383779213e-01,  4.899221558401311e-03,  
 9.421296116189286e-01, -3.072458818807862e-01,  8.166950645809414e-03,  
 9.422279295242960e-01, -8.430010110128885e-01,  4.356685968058319e-03,  
 9.424045442737207e-01, -6.965818136607429e-01,  5.492047852799914e-03,  
 9.425924799508709e-01, -7.723036765423268e-02,  8.594457541849910e-03,  
 9.432551757252079e-01,  6.778512313399264e-01,  5.997726172859794e-03,  
 9.432745759141794e-01,  3.578284894473978e-01,  6.177743639544537e-03,  
 9.448077504847031e-01, -9.425192762886759e-01,  2.715142333531406e-03,  
 9.450858475738110e-01,  5.025373008969878e-01,  6.252666523418040e-03,  
 9.469548060003440e-01, -9.927873239383316e-01,  9.693950321163949e-04,  
 9.664977673747553e-01, -7.669983680205528e-01,  2.614941215020715e-03,  
 9.708137869429159e-01, -4.239389021325329e-01,  5.141869518483292e-03,  
 9.709279126257970e-01,  2.562383260371136e-01,  5.255024629747484e-03,  
 9.711831524640260e-01,  7.579747866842650e-01,  3.663853318492690e-03,  
 9.715318079839266e-01, -6.114344673195419e-01,  4.212935529909797e-03,  
 9.726983304977663e-01,  4.425763588680746e-02,  5.881914856745899e-03,  
 9.728709777782690e-01,  9.691292467666289e-01,  1.466141068305907e-03,  
 9.729306672713298e-01, -1.937971855968040e-01,  5.661441805111854e-03,  
 9.734565439099904e-01,  8.924228057613435e-01,  2.621925808197151e-03,  
 9.736351786214140e-01,  5.825032309876242e-01,  4.276722297762739e-03,  
 9.737646096663447e-01, -8.979365374145354e-01,  2.417846375635086e-03,  
 9.768576153531923e-01, -9.720516240923431e-01,  1.260176677733168e-03,  
 9.799683347097561e-01,  9.982787940792663e-01,  2.802539460088801e-04,  
 9.805838302292789e-01,  4.186960243528708e-01,  4.224419641522761e-03,  
 9.828402728207225e-01, -8.130859429654207e-01,  1.813569870463969e-03,  
 9.870995148246587e-01, -9.971266172517755e-01,  2.522985579422540e-04,  
 9.882983824911455e-01, -7.029568166797684e-01,  2.101767111893595e-03,  
 9.896446181606325e-01,  8.258526268641876e-01,  1.761173631057456e-03,  
 9.896878613799838e-01,  6.734414823238595e-01,  2.206204039428005e-03,  
 9.897745584940826e-01, -3.209639101085088e-01,  3.026155349324961e-03,  
 9.904412956303582e-01, -5.265151744794012e-01,  2.514644595413010e-03,  
 9.910529016163073e-01,  1.720232075920507e-01,  2.834840262020965e-03,  
 9.914404533622192e-01, -7.370377576026632e-02,  3.114508431996894e-03,  
 9.931100571448706e-01,  9.398758417699402e-01,  9.653046269879767e-04,  
 9.939777572418940e-01, -9.377670381442861e-01,  9.071335269558794e-04,  
 9.955419051779023e-01,  5.028006893760714e-01,  1.625315064214383e-03,  
 9.959458468526172e-01, -8.639404647925895e-01,  9.127209022448868e-04,  
 9.963148656482692e-01,  9.861307505276973e-01,  3.364793817721787e-04,  
 9.966209533584591e-01,  3.237318892379179e-01,  1.736701233968157e-03,  
 9.977221586114358e-01,  6.019952067889782e-01,  5.964708123101566e-04,  
 9.978435386703776e-01, -7.692080150297662e-01,  6.598609318533428e-04,  
 9.982115219214424e-01, -6.305047404346029e-01,  8.136830618787968e-04,  
 9.983293539476047e-01, -9.835120159252404e-01,  2.181997023647311e-04,  
 9.984416520882323e-01,  8.814083896367437e-01,  4.548127997472904e-04,  
 9.984853824993025e-01,  7.518363345257131e-01,  6.752050933944545e-04,  
 9.985812215892117e-01, -2.098862069679553e-01,  9.932558396288942e-04,  
 9.985820051950299e-01, -4.311577677096960e-01,  8.506787489756313e-04,  
 9.987179482199477e-01,  6.341055456784180e-02,  9.427263494251746e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr50 ( )

/******************************************************************************/
/*
  Purpose:

    SMR50 returns the SMR rule of degree 50.

  Discussion:
 
    DEGREE: 50
    POINTS CARDINALITY: 454
    NORM INF MOMS. RESIDUAL: 1.97162e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR50[3*454], the requested rule.
*/
{
  const int degree = 50;
  int order;
  double xw[3*454] = {
 -9.985305923732772e-01,  9.480346609653949e-01,  3.637016044890175e-04,  
 -9.983266574377337e-01, -7.135200571279965e-01,  8.681375001274842e-04,  
 -9.982410599710965e-01, -5.061487385182745e-02,  1.210422814431021e-03,  
 -9.981979630190073e-01,  1.943963798210550e-01,  1.209667416017868e-03,  
 -9.981164101550407e-01,  4.217828123427281e-01,  1.100221981712261e-03,  
 -9.980251256813344e-01,  8.409407151717826e-01,  6.790256958329296e-04,  
 -9.978977416561483e-01, -5.175396836215825e-01,  1.209910288842294e-03,  
 -9.977749235731450e-01, -8.787383894116004e-01,  6.804808145574241e-04,  
 -9.974790513531082e-01, -2.987478462479398e-01,  1.485043396561256e-03,  
 -9.973044005791738e-01,  9.966139708183203e-01,  1.024593234561320e-04,  
 -9.965354581345114e-01, -9.625283354808352e-01,  5.086867261717252e-04,  
 -9.959776528397177e-01,  5.865612330340912e-01,  1.475073552829635e-03,  
 -9.958674494848857e-01,  7.184881012827657e-01,  1.314678451882094e-03,  
 -9.958634171963171e-01, -9.964330603430479e-01,  1.378555297245596e-04,  
 -9.899892964541681e-01, -8.034025241583582e-01,  2.063321727799165e-03,  
 -9.890089603003986e-01, -1.607654105825233e-01,  3.171831815687111e-03,  
 -9.889269890822903e-01,  9.792253114023887e-01,  6.925166147590135e-04,  
 -9.888556249081619e-01,  9.011374451124298e-01,  1.524076231835903e-03,  
 -9.883405484188146e-01,  3.140956912031643e-01,  3.326070006645496e-03,  
 -9.882926852196964e-01,  7.591140506738633e-02,  3.713229391963024e-03,  
 -9.879532633546659e-01, -6.253049497236600e-01,  2.968377985270547e-03,  
 -9.862738466801083e-01, -4.136828994040758e-01,  3.792003832590160e-03,  
 -9.840867690629249e-01, -9.225459592561057e-01,  1.716688686998262e-03,  
 -9.834561801290923e-01,  7.913470127721602e-01,  2.467251464100417e-03,  
 -9.829084684207806e-01,  4.958738236441704e-01,  3.605246991559088e-03,  
 -9.799751230610935e-01, -9.858070723372447e-01,  8.062256820069726e-04,  
 -9.773121022170035e-01,  6.531868802837602e-01,  3.655328649772478e-03,  
 -9.727540699799997e-01, -2.463858035039539e-01,  3.968311046518957e-03,  
 -9.722508392684289e-01,  2.227204587069684e-01,  2.881691797859937e-03,  
 -9.706187607468760e-01, -7.290537686894693e-01,  3.938655209703868e-03,  
 -9.704346881779157e-01,  9.463998760417839e-01,  1.815054306514290e-03,  
 -9.690510704309230e-01,  9.956152727894065e-01,  4.874122727335260e-04,  
 -9.675183125664917e-01, -3.873668624805015e-02,  6.258912209048882e-03,  
 -9.670967144416286e-01, -5.346820717217893e-01,  5.020688484630141e-03,  
 -9.655166141119431e-01, -8.589490689754655e-01,  3.424882118788690e-03,  
 -9.627685982819859e-01,  8.574258075931914e-01,  3.211357083932979e-03,  
 -9.611985315766414e-01,  1.735034523650290e-01,  4.470806430187272e-03,  
 -9.597845726633061e-01,  3.970047952525823e-01,  6.128594443133615e-03,  
 -9.569446290012320e-01, -3.378216199983041e-01,  5.083719898994831e-03,  
 -9.565067320986410e-01, -9.583763747944724e-01,  2.042573269760935e-03,  
 -9.529509863706143e-01,  7.367253684069424e-01,  4.607147767328114e-03,  
 -9.509009916467068e-01, -9.982452717308193e-01,  4.171743785231584e-04,  
 -9.498639131139113e-01,  5.672749857805497e-01,  5.975731307616273e-03,  
 -9.428689649793603e-01, -6.526060553577299e-01,  5.505889774975882e-03,  
 -9.422311181031663e-01,  9.769229657788217e-01,  1.605353293384605e-03,  
 -9.375241836457983e-01, -4.577530187027701e-01,  5.705829120945821e-03,  
 -9.362131629000300e-01, -1.507446207119618e-01,  8.504765626649076e-03,  
 -9.339474938107682e-01,  9.120768210172238e-01,  3.338622941804765e-03,  
 -9.316644572520522e-01, -7.908094170683131e-01,  5.751538344933908e-03,  
 -9.314325437683882e-01,  7.308639756184374e-02,  8.950456494516651e-03,  
 -9.304457837028240e-01, -9.108477682553909e-01,  3.622093803410868e-03,  
 -9.262042777363618e-01,  2.926429789075467e-01,  8.847143966496282e-03,  
 -9.205873982096271e-01,  8.098896505724084e-01,  5.174844527226764e-03,  
 -9.162051560377870e-01, -9.832510479457329e-01,  1.819552993042389e-03,  
 -9.145628768323527e-01, -2.911965871109570e-01,  6.354190461823213e-03,  
 -9.144568861286890e-01,  6.634543776500917e-01,  6.992029249399327e-03,  
 -9.134662288030968e-01,  4.776130498503005e-01,  8.193380404605263e-03,  
 -9.126046852400858e-01,  9.959169009245570e-01,  7.303402358793004e-04,  
 -9.084013096944704e-01, -5.810944597640583e-01,  6.912234750082650e-03,  
 -8.968296850710641e-01, -4.128318260767174e-01,  6.809730423186475e-03,  
 -8.963106431292505e-01,  9.531579778618777e-01,  2.914835462196634e-03,  
 -8.901833704330284e-01, -8.608019888123171e-01,  5.050561896084555e-03,  
 -8.884475404720591e-01, -4.181808934399530e-02,  1.158653342037486e-02,  
 -8.859496918290896e-01, -7.137986488176715e-01,  8.297704906842986e-03,  
 -8.826270793702349e-01,  8.736037565380022e-01,  4.992525221172924e-03,  
 -8.823557325667086e-01,  1.833542443150059e-01,  1.150671440741034e-02,  
 -8.803378140572387e-01, -9.483904752475437e-01,  3.713568296274433e-03,  
 -8.730496783252757e-01, -2.233431485071996e-01,  9.317119532426758e-03,  
 -8.699283953657505e-01,  3.852358620688430e-01,  1.027156006726837e-02,  
 -8.698133028410201e-01,  7.486827472812273e-01,  7.596749165870595e-03,  
 -8.674834848675760e-01,  5.836354021401285e-01,  9.310768477516692e-03,  
 -8.628243813571611e-01, -9.960431212097594e-01,  9.977579306457195e-04,  
 -8.624814683206987e-01,  9.841369657891215e-01,  1.842174250748435e-03,  
 -8.581906826960382e-01, -5.182071016007672e-01,  9.222800088580358e-03,  
 -8.484873092060258e-01, -8.116205306074403e-01,  5.448026047767842e-03,  
 -8.375416835189680e-01,  9.244249381249888e-01,  4.359562847763335e-03,  
 -8.343496291886240e-01, -3.560928009556643e-01,  1.173308803213457e-02,  
 -8.291306871234821e-01,  6.960605157818649e-02,  1.390910739512651e-02,  
 -8.281553984054720e-01, -6.382569464166583e-01,  9.693436224505143e-03,  
 -8.256425444491163e-01, -9.054076217011587e-01,  5.816411318368521e-03,  
 -8.223579984614887e-01,  8.269951489970134e-01,  7.127087970713289e-03,  
 -8.215593436322257e-01,  9.981381538674631e-01,  6.329945045794524e-04,  
 -8.198483858368308e-01, -1.319278740037157e-01,  1.298320952391481e-02,  
 -8.192027189051302e-01,  2.877778785137557e-01,  1.265773788043916e-02,  
 -8.172502785117453e-01, -9.750039267897708e-01,  3.134812108850403e-03,  
 -8.138299706643672e-01,  4.972544598166810e-01,  1.161528697363953e-02,  
 -8.115048842276773e-01,  6.785974006783519e-01,  1.000389489115020e-02,  
 -8.033489337701412e-01, -7.623411898836773e-01,  7.618682602864780e-03,  
 -7.981451309405014e-01,  9.655610226211084e-01,  3.238149495801071e-03,  
 -7.788793515049757e-01, -4.659125664753414e-01,  1.294788836398086e-02,  
 -7.676616475483181e-01,  8.903050218772064e-01,  6.412981842164176e-03,  
 -7.654405876460623e-01, -2.609719605681909e-01,  1.510691545326006e-02,  
 -7.651705117791751e-01, -5.933719404029307e-01,  7.689899801767004e-03,  
 -7.610553487070951e-01, -8.537787359055480e-01,  8.005675846962551e-03,  
 -7.598494916125437e-01,  1.822273140486022e-01,  1.528388680362909e-02,  
 -7.579923742217070e-01, -9.945462254206379e-01,  1.550380002631925e-03,  
 -7.554414721363940e-01,  7.704489057786914e-01,  9.613889207061148e-03,  
 -7.546303325899156e-01, -2.587451873434423e-02,  1.541716632386868e-02,  
 -7.533501105520592e-01,  4.028033457447762e-01,  1.416780003145239e-02,  
 -7.512634680369265e-01, -9.427500341739973e-01,  5.278060834005935e-03,  
 -7.492677967965817e-01,  9.893278319960217e-01,  1.942720461021166e-03,  
 -7.476477835194629e-01,  5.993754192648574e-01,  1.240433786628891e-02,  
 -7.384396341741885e-01, -7.049337544138190e-01,  1.019806600177946e-02,  
 -7.178686225860993e-01,  9.426175650021613e-01,  5.076879608670298e-03,  
 -6.981541470167513e-01, -3.738996976336288e-01,  1.623617174158692e-02,  
 -6.930270182761278e-01, -5.503057726865391e-01,  1.252261832635268e-02,  
 -6.914007366726129e-01, -1.492403377321120e-01,  1.687175767189600e-02,  
 -6.898255514942709e-01,  8.450597437929396e-01,  9.044588739380572e-03,  
 -6.878471762364344e-01, -7.980792470880590e-01,  9.683099148036134e-03,  
 -6.874914713445559e-01,  9.985765065838036e-01,  5.429828741714135e-04,  
 -6.851758646966849e-01,  2.991299533883399e-01,  1.680000628152785e-02,  
 -6.841372891501616e-01, -9.759846205669235e-01,  3.792981482377291e-03,  
 -6.824533415259976e-01,  7.012478423815675e-01,  1.242282959150627e-02,  
 -6.806130791896147e-01,  8.613441527468559e-02,  1.715469593857349e-02,  
 -6.782455218903122e-01,  5.106365783701324e-01,  1.495469178663973e-02,  
 -6.767016667485439e-01, -9.023128892125745e-01,  7.148516270448834e-03,  
 -6.589112285487670e-01,  9.766144758417425e-01,  3.310403467016667e-03,  
 -6.511681540558421e-01, -6.631624128792538e-01,  1.080993463231836e-02,  
 -6.380516344996316e-01, -9.971292836795032e-01,  1.091941596727160e-03,  
 -6.321934701591331e-01,  9.112877114102699e-01,  6.899365963636340e-03,  
 -6.189763674514923e-01, -2.549410517879415e-01,  1.680578646075412e-02,  
 -6.156902457901138e-01, -4.609743414379315e-01,  1.446782156032898e-02,  
 -6.095366081540551e-01, -3.536699015280872e-02,  1.850017035472999e-02,  
 -6.064980319841019e-01,  7.855933379724550e-01,  1.191421549804811e-02,  
 -6.037838321468384e-01, -8.588880336516307e-01,  7.493653196531501e-03,  
 -6.032572636799473e-01,  6.191506051681956e-01,  1.533794488328530e-02,  
 -6.029215218823031e-01,  4.121372818661574e-01,  1.746667230493666e-02,  
 -6.004670419231046e-01,  2.003417792141365e-01,  1.853576294985650e-02,  
 -5.978165937113178e-01, -9.464336654728625e-01,  6.209112452624394e-03,  
 -5.973624658830221e-01, -7.522142533728916e-01,  1.070955771848203e-02,  
 -5.972383581448467e-01,  9.955134418355728e-01,  1.205515802358963e-03,  
 -5.775575710831099e-01, -5.936186239487227e-01,  1.108117334138420e-02,  
 -5.716545691484377e-01,  9.586937694828399e-01,  4.477003194366252e-03,  
 -5.544501743841143e-01, -9.859194586440739e-01,  2.990668121908608e-03,  
 -5.533389067322111e-01,  8.727090179141404e-01,  7.641422231771522e-03,  
 -5.508248111710804e-01, -3.360687262652585e-01,  1.326315896795831e-02,  
 -5.269836692039951e-01, -1.373273675486175e-01,  1.846993932273529e-02,  
 -5.252683048124628e-01,  7.769369828819343e-02,  1.828457505601571e-02,  
 -5.232549472077624e-01, -8.262684949558237e-01,  8.105817403692208e-03,  
 -5.216149653619029e-01, -4.944286105148744e-01,  1.099366935751496e-02,  
 -5.189971990652680e-01,  5.251343160031084e-01,  1.801382551804368e-02,  
 -5.187072221708287e-01,  7.127559592388867e-01,  1.475721541133735e-02,  
 -5.157523922022348e-01, -6.649848553773774e-01,  1.035112521727110e-02,  
 -5.154577487348173e-01,  3.146569819892138e-01,  1.881013777037231e-02,  
 -5.121209365416318e-01,  9.881269957126972e-01,  2.581279958818058e-03,  
 -5.085478436271724e-01, -9.062214676374273e-01,  7.876549270964693e-03,  
 -4.890864408748029e-01,  9.331958642967023e-01,  6.252083630599476e-03,  
 -4.830798048819471e-01,  8.307910647681210e-01,  9.069844919775074e-03,  
 -4.769568695143335e-01, -7.406437471378572e-01,  9.792607423330369e-03,  
 -4.711384868324521e-01, -9.982442886371089e-01,  9.977513750498068e-04,  
 -4.670429883275934e-01, -3.837258048261876e-01,  1.481809931562225e-02,  
 -4.666978361533338e-01, -9.638780668495475e-01,  5.093634425116185e-03,  
 -4.583860333911172e-01, -2.194459707654301e-01,  1.399842259428002e-02,  
 -4.488372720482744e-01,  1.852523019019599e-01,  1.562937178489875e-02,  
 -4.466182114907417e-01,  1.045052032899272e-02,  9.145117658682660e-03,  
 -4.398969646289078e-01, -5.643439180041001e-01,  1.536885553161082e-02,  
 -4.286607785443331e-01,  6.284182834880983e-01,  1.704743034990286e-02,  
 -4.281803723972377e-01,  4.257307629052356e-01,  1.891821754399137e-02,  
 -4.251215127406949e-01,  9.990156228445619e-01,  8.538043330161814e-04,  
 -4.118280892991981e-01,  9.714759276031080e-01,  4.880101949369545e-03,  
 -4.079009162767762e-01, -8.127761432326117e-01,  9.682944715935253e-03,  
 -4.061050423178847e-01, -4.674050637680804e-02,  1.763350006605001e-02,  
 -4.056845643788482e-01, -8.739980868114045e-01,  5.900069010534015e-03,  
 -4.030307435938099e-01,  7.756488822994984e-01,  1.281187876680621e-02,  
 -4.006967431242406e-01,  8.961755809836305e-01,  8.973613291265101e-03,  
 -3.916049226821231e-01, -9.273410115124909e-01,  5.297964504333964e-03,  
 -3.767714330669960e-01, -6.548167260904730e-01,  9.467239374026879e-03,  
 -3.759401992622222e-01,  2.756208903780863e-01,  1.532016187158172e-02,  
 -3.755012873186720e-01, -9.871862321784112e-01,  3.250146148554228e-03,  
 -3.730541368999579e-01, -7.112556629483213e-01,  7.329934266008029e-03,  
 -3.725289366278142e-01, -2.774273474801098e-01,  1.754335020704925e-02,  
 -3.672221731554482e-01, -4.498269623849093e-01,  1.635160912830995e-02,  
 -3.517016115907431e-01,  5.427475370188103e-01,  1.038435257761881e-02,  
 -3.472072906873430e-01,  1.297375715246647e-01,  1.511255362750808e-02,  
 -3.288603177035728e-01,  4.816597830509821e-01,  6.559008197617309e-03,  
 -3.221265382254779e-01, -1.433656648153948e-01,  1.620111125789070e-02,  
 -3.131321362159788e-01,  7.032975112241375e-01,  1.594512703102189e-02,  
 -3.082989492612527e-01, -9.578410503896179e-01,  3.982391593695098e-03,  
 -3.082247018694904e-01,  9.906739284535425e-01,  2.962374733019264e-03,  
 -3.072260057987407e-01,  9.424355086678589e-01,  7.485667285562808e-03,  
 -3.062114826214366e-01, -9.347879939525434e-01,  2.589717354994651e-03,  
 -3.046631601690127e-01,  8.455016733897478e-01,  1.202814315872106e-02,  
 -2.960605213864115e-01, -5.110628541558808e-01,  1.002716095596817e-02,  
 -2.917625758358438e-01,  3.593747168154432e-01,  1.837042545246992e-02,  
 -2.895557314330913e-01, -6.159501875196743e-01,  1.206000739213904e-02,  
 -2.871906599030266e-01, -7.705048149609509e-01,  1.383267273104722e-02,  
 -2.859792213471688e-01, -8.714115510524062e-01,  1.038591281351532e-02,  
 -2.856503520749610e-01,  5.747007863914991e-02,  1.748058432381039e-02,  
 -2.824592805060356e-01,  5.612750161066066e-01,  9.353603746527843e-03,  
 -2.728487335032520e-01, -9.975408583725541e-01,  1.264352449742901e-03,  
 -2.601809045605671e-01, -3.522853948258879e-01,  2.092850963826799e-02,  
 -2.597903214660320e-01, -9.994084053639378e-02,  8.825557728414398e-03,  
 -2.256215566562435e-01,  2.283770326898505e-01,  2.160089195520415e-02,  
 -2.188098462531380e-01, -2.067500347682650e-01,  1.252332154956301e-02,  
 -2.185684926171157e-01, -9.755155987010639e-01,  4.112709587283565e-03,  
 -2.053682577466782e-01,  7.806266036689269e-01,  1.501612574781621e-02,  
 -2.049162099957439e-01,  6.343543635897640e-01,  1.580531156711188e-02,  
 -2.041124215059686e-01, -5.429590922002024e-01,  1.362853247269861e-02,  
 -2.002875030215060e-01,  9.009976779341253e-01,  1.031145511059078e-02,  
 -1.976029493822827e-01,  9.714461314931776e-01,  5.332016356692966e-03,  
 -1.954132400791727e-01,  4.624136298055638e-01,  1.945983666591439e-02,  
 -1.879132665032426e-01, -6.925128794555552e-01,  1.703923942906849e-02,  
 -1.821951153235339e-01, -1.426582763733243e-02,  1.987409951184996e-02,  
 -1.810578998197690e-01, -9.204035043869775e-01,  9.272464757303015e-03,  
 -1.774507741267828e-01,  9.978134769969224e-01,  1.228301960791354e-03,  
 -1.621404219665848e-01, -8.249452802330807e-01,  1.365662754138641e-02,  
 -1.464771076898347e-01, -4.340215233356940e-01,  1.945862436948514e-02,  
 -1.460344552467488e-01, -2.429282629387507e-01,  1.565971349603635e-02,  
 -1.357303124694478e-01, -9.913278393826657e-01,  2.344766960985844e-03,  
 -1.348850451544348e-01,  1.418182577007316e-01,  1.855959179083704e-02,  
 -1.178453467617478e-01,  3.462124048386542e-01,  2.128688457301467e-02,  
 -1.070963545859648e-01,  5.697167424399421e-01,  1.270219547686097e-02,  
 -9.418089864452631e-02,  8.464061176824520e-01,  1.318512157781563e-02,  
 -9.284665135473712e-02,  7.115189151497324e-01,  1.693264777896065e-02,  
 -8.649884288942110e-02,  9.412721885997597e-01,  7.947036543700148e-03,  
 -8.381550837050580e-02, -1.034404718739174e-01,  2.042114347858592e-02,  
 -8.132901275144148e-02, -6.047646884556696e-01,  1.901873006719877e-02,  
 -7.314393059200233e-02, -9.584726090471121e-01,  6.990580671801756e-03,  
 -6.585476015650292e-02,  9.869964307266527e-01,  3.475568911966144e-03,  
 -5.940953281811259e-02, -7.531405908206484e-01,  1.610516174433207e-02,  
 -5.723571915110250e-02, -3.156995009383814e-01,  1.757545073276317e-02,  
 -4.881350872683240e-02, -8.821229556281880e-01,  1.190858000679253e-02,  
 -4.623125113800330e-02, -9.984756475663564e-01,  8.661846411096376e-04,  
 -4.537127170091439e-02,  5.454245190895872e-01,  7.887365308447648e-03,  
 -4.427946025894871e-02,  7.620061393862830e-02,  1.715262718303868e-02,  
 -3.652498887773526e-02, -4.854048438229047e-01,  1.164475499560268e-02,  
 -2.693515118939117e-02,  4.662758740691014e-01,  1.418575874574526e-02,  
 -2.196660636199712e-02,  2.563688847935753e-01,  2.048504486701552e-02,  
 1.684869503861126e-02,  9.985028110516669e-01,  8.343196408295555e-04,  
 1.937078508280643e-02,  7.845643755910120e-01,  1.528657010406891e-02,  
 2.203824694705822e-02,  8.989738024148887e-01,  1.069256626530232e-02,  
 2.241772195214512e-02, -1.754589056829656e-01,  1.981467867657729e-02,  
 2.975250703736150e-02,  1.862596862025734e-03,  1.586261473431975e-02,  
 3.055821004449258e-02, -3.713097808061478e-01,  1.472665339094052e-02,  
 3.289324396609741e-02,  6.432956961893939e-01,  1.864369020889923e-02,  
 3.723492660056246e-02, -9.844719413983402e-01,  4.259554223135243e-03,  
 4.770102526934471e-02,  9.660516213959782e-01,  5.910690727520699e-03,  
 4.835037248406306e-02, -6.721798158089920e-01,  1.837739301039192e-02,  
 5.239032096709587e-02, -5.201345460249732e-01,  1.609773629036364e-02,  
 5.502518798282641e-02, -8.182265682703534e-01,  1.429356112573313e-02,  
 5.830896522283972e-02,  4.016909728418846e-01,  1.831359832124226e-02,  
 6.198731221349852e-02, -9.303653863405975e-01,  9.255582126803446e-03,  
 7.857891643486636e-02,  1.766467214761190e-01,  1.939355213634587e-02,  
 1.208356536244954e-01,  3.216785108904378e-01,  9.071620470626165e-03,  
 1.208368243862543e-01, -2.541561566739803e-01,  2.021580169628961e-02,  
 1.216863587634878e-01,  9.916346904595559e-01,  2.444055246895457e-03,  
 1.232655916759636e-01,  5.414949782908248e-01,  1.986491824292366e-02,  
 1.241778913712552e-01, -4.978636357670361e-02,  1.834144377738077e-02,  
 1.337347631223449e-01,  8.472659711961135e-01,  1.284004194508113e-02,  
 1.466010849626561e-01,  7.236699453278207e-01,  1.678250950273756e-02,  
 1.496400580028691e-01, -9.975365491819376e-01,  1.471039139180874e-03,  
 1.529671602153546e-01, -4.138359329741561e-01,  1.970291306047588e-02,  
 1.553076799904455e-01,  9.825333958721993e-02,  1.331862934874382e-02,  
 1.564393944563869e-01,  9.341317137357775e-01,  8.329285394320438e-03,  
 1.607100339920880e-01, -8.768225824887561e-01,  1.145010706137546e-02,  
 1.633664795918194e-01, -5.876766334680318e-01,  1.831745704958468e-02,  
 1.649345927645013e-01, -7.456333961574857e-01,  1.658594926267819e-02,  
 1.724639115261522e-01, -9.662243526431580e-01,  6.397001220461619e-03,  
 1.856135967174529e-01,  3.019753251009087e-01,  1.604124847134084e-02,  
 2.207568082418493e-01, -1.341768231114187e-01,  2.201353706987977e-02,  
 2.216590623136845e-01,  6.237862843359905e-01,  1.130843281124745e-02,  
 2.222728182351477e-01,  9.767149748533738e-01,  4.270350031153890e-03,  
 2.251913391882167e-01,  4.515133683755246e-01,  1.961372976506132e-02,  
 2.393332091219671e-01,  6.746796047622838e-02,  1.563788629592373e-02,  
 2.454323613661074e-01,  9.987765164968539e-01,  8.734893357177072e-04,  
 2.489948172638105e-01,  2.049235281953148e-01,  1.270930859704317e-02,  
 2.551647790899600e-01, -4.986851928535581e-01,  1.121625142075451e-02,  
 2.569501661619921e-01,  7.948735761125491e-01,  1.372820954751759e-02,  
 2.586452498793473e-01, -9.219424663897881e-01,  8.044149671331794e-03,  
 2.601094175807203e-01, -3.053795751586294e-01,  2.158658189071271e-02,  
 2.633547449910876e-01,  8.921977837870594e-01,  1.019013452355202e-02,  
 2.654090569206588e-01,  6.495375037274833e-01,  8.750452222218987e-03,  
 2.690640635337399e-01, -8.151729320209684e-01,  1.356683615382717e-02,  
 2.728833763425947e-01, -6.617494728362482e-01,  1.691235069293519e-02,  
 2.832389697359580e-01, -4.580344348270283e-01,  7.865208224812631e-03,  
 2.840896766783086e-01, -9.890120421665016e-01,  3.588966784785691e-03,  
 3.151693234434736e-01,  9.534401100755432e-01,  5.557418660257084e-03,  
 3.260081563690662e-01, -1.795252417843553e-02,  2.146401172038991e-02,  
 3.274401122842648e-01,  3.681991260958348e-01,  1.852510306194186e-02,  
 3.284833444644465e-01,  2.189215721397187e-01,  1.439774012533690e-02,  
 3.337782993016923e-01,  5.444183052791469e-01,  1.768422453882693e-02,  
 3.384090593283935e-01, -9.515287291879881e-01,  4.960138634028438e-03,  
 3.438984906707113e-01, -5.371780889807538e-01,  1.068695089769454e-02,  
 3.446230444324452e-01,  7.190351391805496e-01,  1.249860147037258e-02,  
 3.543528388111687e-01,  9.902368488113547e-01,  2.826004111195709e-03,  
 3.602282612815438e-01, -1.947302593649046e-01,  2.173836797361481e-02,  
 3.612552194216351e-01, -7.319208685947469e-01,  1.249441852526187e-02,  
 3.632929794407099e-01, -8.704852750274591e-01,  9.768989552535455e-03,  
 3.744793900580320e-01,  8.286415194062603e-01,  6.671271590709352e-03,  
 3.860890582535335e-01, -3.839824460224215e-01,  2.092918906725470e-02,  
 3.928710017718934e-01,  8.672865777465832e-01,  6.936260220669673e-03,  
 3.931996788966815e-01,  9.279235914180360e-01,  5.272293822412451e-03,  
 4.007261695646738e-01,  1.223557508548206e-01,  1.739277111294605e-02,  
 4.062478163754075e-01, -9.984412635687164e-01,  1.118910221718476e-03,  
 4.106255773005774e-01, -5.988996724168920e-01,  1.562901284122264e-02,  
 4.123501152038699e-01,  7.367091972519042e-01,  4.909337398435131e-03,  
 4.172900522264887e-01, -9.721977396522211e-01,  4.399018232299250e-03,  
 4.314957914891770e-01,  4.647378299513769e-01,  1.657826429386184e-02,  
 4.317959505632551e-01, -7.839966309166440e-01,  1.002961987603591e-02,  
 4.331331185623659e-01,  6.317320218888924e-01,  1.491157542954482e-02,  
 4.400703045168821e-01, -9.090920579494268e-01,  6.758378154370627e-03,  
 4.413453712232151e-01,  3.026452329003297e-01,  1.816222308777934e-02,  
 4.563399517359142e-01,  9.712472856776212e-01,  4.837136504147411e-03,  
 4.566101742568825e-01, -8.299751644192108e-02,  2.070092724204458e-02,  
 4.600940256413679e-01,  7.358720101030228e-02,  9.566565631101559e-03,  
 4.604812529078548e-01,  9.984195308056378e-01,  8.414203442745121e-04,  
 4.808602748352557e-01,  7.905645541015534e-01,  1.052995268205664e-02,  
 4.827694496186490e-01, -2.738930106938465e-01,  2.090057903801916e-02,  
 4.902896825779680e-01, -4.796343698686354e-01,  1.970211671607839e-02,  
 4.980721753534725e-01,  9.157146659597657e-01,  7.088539756844323e-03,  
 4.998104630815455e-01, -6.796065261644658e-01,  1.577525512582634e-02,  
 5.094252232151556e-01, -8.368693540841839e-01,  1.074700155814415e-02,  
 5.192774433643107e-01, -9.883852225797410e-01,  3.036728485600766e-03,  
 5.195781232521763e-01, -9.398491136525347e-01,  6.356409539852770e-03,  
 5.199091809396583e-01,  8.569634476765962e-01,  5.258870099579074e-03,  
 5.229669281084162e-01,  5.594933800929066e-01,  1.395310653595126e-02,  
 5.277471964272620e-01,  2.088203156823199e-01,  1.879162946198670e-02,  
 5.309038668016169e-01,  7.063079812356768e-01,  1.112337221025911e-02,  
 5.382154499373017e-01,  4.065037042579824e-01,  1.597509886966357e-02,  
 5.516901995859222e-01,  2.395725953104485e-02,  1.772537813373606e-02,  
 5.527797967108647e-01,  9.898809035115810e-01,  2.406110601287913e-03,  
 5.750934868747971e-01, -1.608553196274835e-01,  1.999458400282759e-02,  
 5.826416379535926e-01, -5.769647685634977e-01,  1.716174776614503e-02,  
 5.828982582142574e-01, -3.706431888713908e-01,  1.927115149218318e-02,  
 5.850904508510351e-01,  9.536524310311831e-01,  5.849579241942577e-03,  
 5.903129886530973e-01, -7.571779340576262e-01,  1.342299877672259e-02,  
 5.958483435151166e-01,  8.681226767219122e-01,  7.303322832277533e-03,  
 5.993502036615301e-01, -8.879811146186565e-01,  9.100212257108971e-03,  
 6.050183737665353e-01,  6.475724613929950e-01,  1.074862599712923e-02,  
 6.143297462629967e-01,  7.837772856375271e-01,  1.032139260028579e-02,  
 6.153165941746209e-01, -9.665059604638701e-01,  4.843117865525232e-03,  
 6.161439379518383e-01, -9.981214531139727e-01,  9.753216220325940e-04,  
 6.175168884004676e-01,  3.159407352975249e-01,  1.637383804148541e-02,  
 6.217394522871077e-01,  5.078428721394385e-01,  1.362126210274025e-02,  
 6.299826667484392e-01,  1.276627125784212e-01,  1.607743572209873e-02,  
 6.380312602008873e-01,  9.984592465433296e-01,  6.879014666059284e-04,  
 6.619401281471743e-01, -4.910221084647453e-02,  1.800834418028045e-02,  
 6.674023930795736e-01, -4.731419452655840e-01,  1.673528342997327e-02,  
 6.681506875256884e-01, -6.664316392680106e-01,  1.423631431136118e-02,  
 6.699586457560213e-01, -2.582142639784658e-01,  1.831293821635849e-02,  
 6.700629393564212e-01,  9.153625801049049e-01,  7.211301710323832e-03,  
 6.737233221090680e-01,  7.173277865865444e-01,  6.610660635246017e-03,  
 6.745073548792663e-01,  9.808177327151206e-01,  3.335305616421728e-03,  
 6.778146451052540e-01, -8.234922260494466e-01,  1.057682497759063e-02,  
 6.908467734992273e-01, -9.289111905832840e-01,  6.533919963273618e-03,  
 6.953563494538313e-01,  4.185159914801704e-01,  1.411689605267293e-02,  
 6.956622893885850e-01,  5.981008752604229e-01,  1.164860612595941e-02,  
 7.000653188381879e-01,  2.214609724485731e-01,  1.377466770804801e-02,  
 7.037630540132982e-01, -9.876775194786391e-01,  2.680336723639033e-03,  
 7.104138022608364e-01,  8.335936077499366e-01,  9.361402014358680e-03,  
 7.312620222424863e-01,  7.241821704859189e-01,  7.324085688124115e-03,  
 7.377947101997951e-01,  6.019282202794075e-02,  1.545266033002662e-02,  
 7.432626735055564e-01, -5.692902294936619e-01,  1.380983624211225e-02,  
 7.463716527825006e-01, -3.650065781089341e-01,  1.572334278442964e-02,  
 7.473714210847725e-01, -7.438987523094117e-01,  1.119428524509579e-02,  
 7.479060990243412e-01,  9.546404095610349e-01,  4.774712942139564e-03,  
 7.497338213800094e-01, -1.437602092341267e-01,  1.665640989044135e-02,  
 7.551017439728431e-01,  9.959903451333804e-01,  1.228086933220431e-03,  
 7.591482573195993e-01, -8.774194742914248e-01,  7.586269856563272e-03,  
 7.633324906212867e-01,  3.136203740000685e-01,  1.293765982026287e-02,  
 7.650644572872880e-01,  5.091844736715609e-01,  1.189055699839011e-02,  
 7.700358230014746e-01, -9.622554291254800e-01,  4.130632579632251e-03,  
 7.803618979679303e-01,  8.901458109807174e-01,  6.979020029847049e-03,  
 7.864173038832742e-01, -9.978780396924563e-01,  8.523818960483254e-04,  
 7.865539415769538e-01,  6.444528101970656e-01,  9.779082708584302e-03,  
 7.980764438789796e-01,  7.802200932109996e-01,  8.751239749911849e-03,  
 7.998064049263058e-01,  1.573746239393782e-01,  1.153314940800488e-02,  
 8.115339339837927e-01, -6.541157752948943e-01,  1.081501204510849e-02,  
 8.122968512881367e-01, -4.669611624262626e-01,  1.275121734348267e-02,  
 8.172332485051989e-01, -2.537325117758131e-01,  1.424812222167168e-02,  
 8.173520738904602e-01, -8.098997527380203e-01,  8.129789190108278e-03,  
 8.178221088482659e-01,  9.819369149456145e-01,  2.554058729705376e-03,  
 8.203518851901087e-01, -2.848141797141588e-02,  1.462387517662095e-02,  
 8.252880251126054e-01,  4.061913511894648e-01,  1.166744929568591e-02,  
 8.273414827850937e-01, -9.223585802664281e-01,  4.998620758584853e-03,  
 8.407955028132980e-01, -9.831208231993736e-01,  2.226504941332199e-03,  
 8.434816562041050e-01,  9.360798445804146e-01,  4.637841436379602e-03,  
 8.459602643116834e-01,  2.369112261168515e-01,  9.231435360575175e-03,  
 8.471265891317460e-01,  5.607143752033232e-01,  9.370910316615211e-03,  
 8.544039302272810e-01,  8.437316388011586e-01,  6.684546573241642e-03,  
 8.584519706838185e-01,  7.001783215001461e-01,  8.637290041473251e-03,  
 8.691797730219265e-01, -7.293852681306572e-01,  7.916587819483284e-03,  
 8.694955383875622e-01, -5.578683468627721e-01,  9.777395917753213e-03,  
 8.715225068140382e-01,  9.968629229036633e-01,  8.317205346907935e-04,  
 8.737322022500262e-01, -3.624845067925466e-01,  1.142884436428019e-02,  
 8.748455473474397e-01, -8.666688668665444e-01,  5.501879290681462e-03,  
 8.783568279821649e-01, -1.408106351805172e-01,  1.222770107988572e-02,  
 8.807000621010282e-01,  8.577202208035965e-02,  1.208916044443412e-02,  
 8.861191555247315e-01, -9.524587365695271e-01,  2.996809350965912e-03,  
 8.908714545623476e-01,  3.200728941018283e-01,  9.132233939830871e-03,  
 8.918849262329097e-01, -9.953299489673937e-01,  8.349160581858519e-04,  
 8.923957457559257e-01,  4.727862002708382e-01,  7.649082746924224e-03,  
 8.992219867205118e-01,  9.696383870346604e-01,  2.712861853539782e-03,  
 9.037366973903258e-01,  8.982722285187050e-01,  4.553188238165971e-03,  
 9.058049717812220e-01,  7.750612684220821e-01,  6.573933171769569e-03,  
 9.131013487425569e-01,  6.183060481541276e-01,  7.822429485807891e-03,  
 9.152680757385779e-01, -7.967925142545168e-01,  5.472782958925398e-03,  
 9.153194784422245e-01, -6.409066271644237e-01,  7.068811844211731e-03,  
 9.212375062298164e-01, -4.626882296966913e-01,  8.505557437086888e-03,  
 9.241806475212835e-01, -9.073693661022466e-01,  3.491966652690000e-03,  
 9.242655253133358e-01, -2.553881984456130e-01,  9.435712214118857e-03,  
 9.278685381584146e-01, -2.653703926395334e-02,  9.626254172659349e-03,  
 9.292177091225340e-01,  1.981150041249339e-01,  9.120861207209665e-03,  
 9.293709816985555e-01, -9.743419848916115e-01,  1.695761394360294e-03,  
 9.361004878709992e-01,  4.885572309032284e-01,  3.587508119392231e-03,  
 9.386011261575939e-01,  9.923607023625215e-01,  1.027746374416859e-03,  
 9.416316207823281e-01,  3.848246163685812e-01,  5.939044760002660e-03,  
 9.429469392782762e-01, -9.969137251707089e-01,  3.661853125669515e-04,  
 9.451218403684011e-01,  8.425754983796822e-01,  4.380238586156267e-03,  
 9.463230530060351e-01,  9.398320877335458e-01,  2.748352326578851e-03,  
 9.496567334542220e-01,  7.028051861622154e-01,  5.415662354453875e-03,  
 9.504527598249251e-01, -7.179397056605220e-01,  4.858056515732989e-03,  
 9.545502432300008e-01, -8.483672446398389e-01,  3.493614776736699e-03,  
 9.567226666698644e-01, -5.574361090807435e-01,  5.711544750304637e-03,  
 9.604743008370903e-01, -3.634999075225396e-01,  6.518215206604805e-03,  
 9.614350881231609e-01, -9.400793516785635e-01,  2.075637167332280e-03,  
 9.617205731156480e-01, -1.437778684046163e-01,  6.766721124990966e-03,  
 9.627292013618208e-01,  5.526147023410976e-01,  5.203862026907654e-03,  
 9.645339614003799e-01,  8.912679972814096e-02,  6.720220154114170e-03,  
 9.681982898776231e-01, -9.858482988016933e-01,  7.854806252207273e-04,  
 9.684495587062435e-01,  2.941036296126024e-01,  5.195376918064249e-03,  
 9.718043670689287e-01,  9.757438210857030e-01,  1.191159865328584e-03,  
 9.761533852459922e-01,  7.788946250155976e-01,  3.220271808790217e-03,  
 9.766012140635367e-01,  8.955372887998586e-01,  2.409386138666988e-03,  
 9.789182968946982e-01, -7.802922134664675e-01,  2.851798066970247e-03,  
 9.803687856312776e-01, -6.441628855863613e-01,  3.244928766737902e-03,  
 9.822912045411591e-01,  9.984383651196385e-01,  2.341272827142674e-04,  
 9.827025129630593e-01,  4.311771782500267e-01,  3.707882781947956e-03,  
 9.827228609176302e-01, -8.919420074129613e-01,  1.854127115183594e-03,  
 9.832282949134381e-01, -2.444850615823892e-01,  2.565975919898579e-03,  
 9.842695902809974e-01,  6.440248345169696e-01,  3.235673284757067e-03,  
 9.843960342896765e-01, -4.685449063372227e-01,  3.758206611082762e-03,  
 9.863495085969685e-01, -9.979572836369498e-01,  1.885243013566843e-04,  
 9.863894006621330e-01, -3.054206067550260e-02,  4.070957199968271e-03,  
 9.884373933820602e-01, -9.631986863799080e-01,  8.909268125570525e-04,  
 9.889831635646070e-01,  2.001521680789260e-01,  3.415256267259531e-03,  
 9.895486008443393e-01, -2.802400020803678e-01,  1.784951229309678e-03,  
 9.913011952915273e-01,  9.490722861303337e-01,  9.334114310415029e-04,  
 9.939722207265341e-01,  8.378634329981455e-01,  1.348862490324860e-03,  
 9.941405572471773e-01,  5.032506127587780e-01,  1.321839206521580e-03,  
 9.943806852246193e-01, -6.860004265918137e-01,  7.140588378827780e-04,  
 9.957633794231534e-01, -8.360114490592742e-01,  1.041707929268540e-03,  
 9.966883143052717e-01,  7.278496613238243e-01,  1.191792248759857e-03,  
 9.968035955361948e-01, -5.651523666439144e-01,  1.374867996046609e-03,  
 9.968605145969733e-01, -7.336757652882711e-01,  7.990342391998070e-04,  
 9.969384946190634e-01,  9.868433854178995e-01,  2.740236217096047e-04,  
 9.975593611800366e-01,  3.360863758987011e-01,  1.454585250009066e-03,  
 9.978110877289340e-01, -1.465750773024727e-01,  1.377030312298262e-03,  
 9.979325714446113e-01, -9.249224066288942e-01,  4.777113521207585e-04,  
 9.979765814666188e-01, -3.775646733998311e-01,  1.202710471482889e-03,  
 9.980898127659592e-01, -9.874218489978037e-01,  1.849225119026519e-04,  
 9.981040178114964e-01,  8.280125816480956e-02,  1.248796781507533e-03,  
 9.982820382418868e-01,  5.769543802463517e-01,  7.519588496094478e-04,  
 9.990895206748026e-01,  9.085198717249964e-01,  3.348164725496207e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr51 ( )

/******************************************************************************/
/*
  Purpose:

    SMR51 returns the SMR rule of degree 51.

  Discussion:
 
    DEGREE: 51
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 462
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR51[3*462], the requested rule.
*/
{
  const int degree = 51;
  int order;
  double xw[3*462] = {
 -9.984626432301655e-01,  7.731810731373280e-01,  2.930667077040843e-04,  
 -9.982950612817629e-01, -8.809790422529455e-01,  5.868976563494200e-04,  
 -9.982657143502113e-01, -5.472808378415216e-01,  8.825961580004602e-04,  
 -9.982465196344393e-01, -5.720585061776626e-02,  1.187360397727577e-03,  
 -9.980752383111224e-01,  9.895590629954322e-01,  1.605142582803498e-04,  
 -9.980563050335864e-01,  4.026468127795991e-01,  1.133746118823456e-03,  
 -9.980560915023025e-01,  9.316458011937399e-01,  4.410107005989047e-04,  
 -9.979331148437312e-01, -7.218491788727829e-01,  9.165568347185002e-04,  
 -9.978969853829365e-01,  1.744352247684945e-01,  1.316676065658554e-03,  
 -9.976266468967849e-01, -3.120694338997498e-01,  1.417265243059842e-03,  
 -9.967076640629561e-01,  5.825966069019469e-01,  1.351054193096153e-03,  
 -9.966756982844908e-01, -9.646209210318417e-01,  4.673464325522125e-04,  
 -9.958487588813290e-01,  8.454813315395656e-01,  9.269269947395651e-04,  
 -9.958386434423615e-01, -9.967140264655182e-01,  1.294234585034121e-04,  
 -9.947687668481154e-01,  7.122817636688038e-01,  1.297939923938297e-03,  
 -9.931482649594923e-01, -4.688097799928717e-01,  1.263445560038073e-03,  
 -9.899762961164086e-01, -8.107546466202721e-01,  1.978506208627187e-03,  
 -9.894541209227824e-01, -1.743999916176229e-01,  3.272756891802527e-03,  
 -9.894046340107479e-01,  3.041157495057775e-01,  2.220343118583675e-03,  
 -9.885082901085881e-01,  9.678446822025472e-01,  8.290334262139013e-04,  
 -9.872610044005977e-01, -6.363286357326429e-01,  2.912531649448298e-03,  
 -9.871440151549654e-01,  5.740263552332389e-02,  3.880572488162640e-03,  
 -9.855704338257310e-01,  9.982037827098472e-01,  1.679707148208503e-04,  
 -9.855018569701638e-01, -9.249596493833102e-01,  1.577833631361155e-03,  
 -9.843630383600804e-01,  4.886238428735122e-01,  3.617312818445750e-03,  
 -9.839061975006608e-01,  8.975109105786676e-01,  1.696426511535707e-03,  
 -9.834620733084443e-01, -4.095317899088909e-01,  3.294182229441701e-03,  
 -9.819763154480772e-01,  2.606278193971512e-01,  2.140965174384009e-03,  
 -9.801554723479408e-01, -9.863754508076430e-01,  7.682431569634297e-04,  
 -9.796226493234478e-01,  7.887535957547051e-01,  2.729782607675046e-03,  
 -9.788073039622869e-01,  6.519818446915956e-01,  3.314343051454497e-03,  
 -9.706604253083109e-01, -2.692976728099303e-01,  4.748645217638728e-03,  
 -9.705718320763341e-01, -7.396086944705653e-01,  3.749135556172170e-03,  
 -9.674102004473606e-01, -5.434109773347497e-01,  4.913196335695364e-03,  
 -9.668019398584777e-01, -8.667816625365619e-01,  3.131430980170647e-03,  
 -9.665514792427918e-01,  9.883256946409834e-01,  7.290779022650052e-04,  
 -9.662771630324206e-01, -6.217984707467629e-02,  6.426823016887218e-03,  
 -9.635050607978470e-01,  9.431294630830762e-01,  1.956380667434553e-03,  
 -9.627844810540420e-01,  1.672694103301844e-01,  6.389370066661570e-03,  
 -9.610263909737414e-01,  3.856673360143000e-01,  6.245421895915378e-03,  
 -9.580781208653250e-01, -9.589071798906652e-01,  1.967241617526768e-03,  
 -9.561574884827165e-01,  8.545038074891833e-01,  3.350951463581097e-03,  
 -9.549317791767546e-01,  5.686259325313919e-01,  5.498722518704855e-03,  
 -9.508617818904216e-01, -9.981801380774861e-01,  4.122462038678519e-04,  
 -9.503534180334950e-01,  7.288766888422127e-01,  4.767863642349979e-03,  
 -9.498352776387182e-01, -3.600313059077714e-01,  4.618417760022735e-03,  
 -9.438088288340477e-01, -6.623911600100255e-01,  5.441477466246755e-03,  
 -9.383440437473887e-01, -4.677837297857259e-01,  5.286783724635598e-03,  
 -9.378343978313476e-01,  9.979840227602486e-01,  2.886874404933051e-04,  
 -9.347835826828178e-01, -8.032727461306876e-01,  5.101386107167580e-03,  
 -9.335259963058073e-01, -1.741913013268586e-01,  8.674585526845215e-03,  
 -9.316426596133324e-01,  9.753406841125737e-01,  1.609586813812562e-03,  
 -9.309296248560257e-01, -9.140613176099411e-01,  3.495989691744833e-03,  
 -9.305488551107037e-01,  5.136546721748054e-02,  9.197493230088536e-03,  
 -9.263857355252882e-01,  2.779326048975370e-01,  9.028086779958895e-03,  
 -9.263239701445769e-01,  9.107049422584537e-01,  3.371000191307030e-03,  
 -9.205673142765751e-01,  4.776877088663017e-01,  8.065709176393822e-03,  
 -9.174707990058046e-01, -9.831219824223332e-01,  1.793027637558652e-03,  
 -9.157242077150120e-01,  8.048621575323117e-01,  5.331392481303393e-03,  
 -9.146615254968106e-01,  6.525583504423961e-01,  6.930392199976675e-03,  
 -9.089721587302551e-01, -5.857463675029180e-01,  7.267970782315043e-03,  
 -9.080065935974906e-01, -3.164859240152895e-01,  6.837639413127251e-03,  
 -8.947437970286245e-01, -7.322325765211256e-01,  6.893118586976826e-03,  
 -8.919221754192620e-01,  9.949598324120587e-01,  8.127871134893036e-04,  
 -8.895890260377957e-01, -8.637277108491151e-01,  5.232804117494899e-03,  
 -8.886655773400590e-01,  9.537789903620841e-01,  2.876082206616951e-03,  
 -8.885392464038627e-01, -4.435272092291309e-01,  7.568949220120856e-03,  
 -8.866202065469098e-01, -6.348808497993091e-02,  1.154404882651323e-02,  
 -8.824241243616843e-01,  1.639785341465538e-01,  1.169349797338188e-02,  
 -8.809708780612643e-01, -9.497050899975726e-01,  3.553886416146671e-03,  
 -8.760350227104163e-01,  8.717500400436297e-01,  5.259870620154938e-03,  
 -8.754979784047946e-01,  3.798655264692855e-01,  1.081669329181522e-02,  
 -8.692675323873814e-01,  5.704948013117649e-01,  9.415315641120716e-03,  
 -8.690861109568938e-01,  7.385216965817932e-01,  7.679645948063224e-03,  
 -8.682723849317826e-01, -2.413725440218638e-01,  9.253909164096906e-03,  
 -8.642150696852295e-01, -9.960092787039047e-01,  1.003841753738079e-03,  
 -8.498643855720464e-01, -6.649755550632316e-01,  7.597610473619992e-03,  
 -8.467214017035217e-01, -5.362390367615976e-01,  8.895976060123083e-03,  
 -8.436301872985277e-01,  9.832315944888775e-01,  2.074514135087015e-03,  
 -8.422060631929207e-01, -8.074677442695858e-01,  6.683571843601402e-03,  
 -8.299696186499533e-01,  9.252056406107587e-01,  4.686829064201373e-03,  
 -8.282749185054267e-01,  4.933486591871209e-02,  1.397066501428090e-02,  
 -8.269765469411963e-01, -9.080859052720072e-01,  5.544241952351055e-03,  
 -8.257297950277435e-01, -3.708722000140850e-01,  1.212267988934058e-02,  
 -8.219455142773742e-01,  2.731244055602917e-01,  1.349903286379663e-02,  
 -8.186687694116527e-01,  8.169654336809941e-01,  7.724614247165545e-03,  
 -8.177674865173270e-01, -9.751105570722036e-01,  3.104258903016394e-03,  
 -8.168195553880896e-01, -1.491433592951066e-01,  1.263065366829014e-02,  
 -8.143075811610117e-01,  4.808919934779660e-01,  1.211587707934682e-02,  
 -8.122235222464764e-01,  6.645693263356235e-01,  1.034590169853937e-02,  
 -7.924551682337602e-01,  9.979434118184467e-01,  7.996645031474067e-04,  
 -7.911850724888906e-01, -7.506825569200485e-01,  7.941591929716212e-03,  
 -7.837299301003484e-01, -6.221133816449059e-01,  9.355464426914692e-03,  
 -7.749274054206045e-01,  9.636900992554140e-01,  3.821815982327952e-03,  
 -7.691224233934532e-01, -4.797259824277350e-01,  1.254447144435524e-02,  
 -7.648340229962162e-01, -8.581827935318574e-01,  7.491144670441934e-03,  
 -7.627844940764947e-01,  8.826229759338237e-01,  7.074367688839350e-03,  
 -7.592567621031157e-01,  1.621753494096360e-01,  1.582235203050707e-02,  
 -7.592537632153245e-01, -9.944779325803701e-01,  1.562546451718628e-03,  
 -7.590915957882161e-01, -2.690284231981802e-01,  1.472349868949412e-02,  
 -7.522143486281416e-01, -4.420957762341238e-02,  1.533410434098432e-02,  
 -7.517728783471738e-01,  3.808909146571708e-01,  1.484618411110594e-02,  
 -7.502398495650368e-01,  7.529941361384164e-01,  1.058551634212385e-02,  
 -7.501867381740732e-01, -9.428041484167984e-01,  5.372797181130857e-03,  
 -7.465512348230974e-01,  5.812636029728919e-01,  1.308836850969356e-02,  
 -7.215017997406428e-01, -7.029762664554089e-01,  8.951206614074616e-03,  
 -7.117204454198214e-01,  9.882619725048780e-01,  2.485303732104740e-03,  
 -6.985970094666423e-01, -8.050208586687611e-01,  8.605257870218163e-03,  
 -6.974082194827886e-01,  9.323769900190633e-01,  6.036713475981832e-03,  
 -6.968216588357791e-01, -5.685630259242790e-01,  1.270493967976205e-02,  
 -6.965278443683667e-01, -3.813019527700768e-01,  1.500927174360908e-02,  
 -6.843613518240634e-01, -1.595802737672721e-01,  1.661539044799480e-02,  
 -6.837395418610350e-01,  8.311442230210669e-01,  9.863681583277186e-03,  
 -6.834535427418744e-01, -9.760799862104438e-01,  3.846584874829861e-03,  
 -6.810744539515917e-01,  2.740932444646828e-01,  1.725213516752411e-02,  
 -6.768663568972961e-01,  6.600586241345030e-02,  1.734826728379393e-02,  
 -6.745224370419017e-01,  4.870189903811539e-01,  1.578358047019544e-02,  
 -6.739684725259000e-01,  6.773736800515929e-01,  1.345027777804938e-02,  
 -6.727321115145797e-01, -9.007641976237168e-01,  7.583356682716259e-03,  
 -6.450460332339586e-01, -6.757412229808869e-01,  7.508776080828879e-03,  
 -6.389939293530692e-01, -9.973854338568079e-01,  1.063420084490733e-03,  
 -6.262273709687267e-01,  9.982013719921785e-01,  9.099112612198464e-04,  
 -6.247537179451397e-01,  9.683796791313465e-01,  4.469874771751688e-03,  
 -6.220861512524035e-01, -4.697281748057330e-01,  1.438590125499024e-02,  
 -6.156820155086310e-01, -2.709084325931711e-01,  1.688158496630053e-02,  
 -6.129302881959240e-01, -7.641285676915613e-01,  9.495321490596256e-03,  
 -6.084927218969570e-01,  8.936876664228429e-01,  8.406065647319754e-03,  
 -6.039369653473292e-01, -8.553105132198990e-01,  5.992514339035710e-03,  
 -6.024059992622410e-01, -4.938164236519791e-02,  1.789883159375976e-02,  
 -5.996089026350557e-01,  7.672038662942753e-01,  1.255110376162054e-02,  
 -5.962301970690166e-01, -6.095934069736669e-01,  9.465990926377369e-03,  
 -5.961040200801679e-01,  3.848010075739488e-01,  1.817040820422673e-02,  
 -5.952839737903306e-01, -9.461274496340163e-01,  6.416292856646743e-03,  
 -5.926997294875127e-01,  1.776082891969388e-01,  1.866120408927115e-02,  
 -5.923843694597760e-01,  5.896493007707313e-01,  1.621562787972456e-02,  
 -5.527846142946271e-01, -9.861830959616884e-01,  3.099780098793835e-03,  
 -5.459986569191559e-01, -8.375938371742565e-01,  6.050055084086778e-03,  
 -5.388169516109163e-01, -3.607537832967127e-01,  1.609524415648660e-02,  
 -5.312450979752437e-01,  9.432008243433877e-01,  5.898171201208263e-03,  
 -5.310856361451403e-01, -6.813014817383491e-01,  1.027869913918279e-02,  
 -5.304327612566657e-01,  9.890527261919566e-01,  2.827063130099349e-03,  
 -5.268264010539805e-01, -5.252722734230787e-01,  1.359552165919798e-02,  
 -5.244630726975610e-01, -1.577626633034953e-01,  1.882044362224186e-02,  
 -5.224669683154261e-01,  6.130399485027747e-02,  1.507572575361228e-02,  
 -5.217650146651664e-01,  8.449124099305068e-01,  1.001711474683906e-02,  
 -5.132250082992501e-01,  6.918190741864376e-01,  1.482210020758091e-02,  
 -5.059023911245950e-01,  4.925206672723313e-01,  1.868221045034610e-02,  
 -5.046922823409280e-01, -9.035785351511306e-01,  8.414747616632558e-03,  
 -5.026640169457263e-01,  2.885178419959957e-01,  1.960777274062006e-02,  
 -4.917682812876415e-01, -7.568554964536706e-01,  9.839983273859529e-03,  
 -4.637181860680785e-01, -9.054278376743077e-04,  9.310011516460947e-03,  
 -4.628745793832066e-01, -9.980775898655661e-01,  1.085007318378005e-03,  
 -4.612328243535970e-01, -9.636523905629031e-01,  5.391019613357756e-03,  
 -4.521990532828559e-01,  9.132454907960982e-01,  6.548142672947493e-03,  
 -4.452822066090281e-01,  7.925031022467097e-01,  1.000481753825504e-02,  
 -4.434508659987488e-01, -4.254148994030716e-01,  1.620216257327421e-02,  
 -4.426248172627640e-01, -2.509072334899481e-01,  1.793705768294306e-02,  
 -4.404692204242281e-01, -6.030105930154493e-01,  1.529211567826421e-02,  
 -4.402029273535364e-01,  1.500200794764788e-01,  1.542342490182974e-02,  
 -4.347931405390690e-01, -8.230011687029393e-01,  8.429370045209109e-03,  
 -4.297409120893627e-01,  9.734301034170465e-01,  4.194517995438787e-03,  
 -4.280793712750670e-01,  6.111370786685761e-01,  1.539138011397148e-02,  
 -4.190565853462007e-01,  9.985365756542770e-01,  1.043658595167089e-03,  
 -4.087838261055447e-01,  3.960341312468386e-01,  1.965538234308296e-02,  
 -4.013358778023735e-01, -6.857748024247086e-02,  1.914789477071623e-02,  
 -3.908325740224702e-01, -9.235350202575059e-01,  5.809955546559159e-03,  
 -3.832064070624976e-01, -6.989145768785087e-01,  1.037562767669162e-02,  
 -3.758321036768930e-01,  8.749564346095232e-01,  9.283988967311280e-03,  
 -3.742272834656374e-01,  7.386438108932267e-01,  1.206959551802083e-02,  
 -3.734439819891471e-01, -7.600731641857339e-01,  4.571534994749117e-03,  
 -3.686176671629213e-01, -8.637636801184702e-01,  7.881047457319663e-03,  
 -3.649610153286265e-01,  2.347382351652932e-01,  1.685485671337773e-02,  
 -3.634966464384106e-01, -9.868648166528062e-01,  3.442228582990279e-03,  
 -3.600054767607526e-01,  5.420299693619358e-01,  1.119360645451427e-02,  
 -3.505957261026271e-01, -5.039294885140760e-01,  1.713918706362200e-02,  
 -3.501126585283145e-01,  9.528774489514406e-01,  4.781907234841134e-03,  
 -3.431840305246549e-01, -3.234632166086708e-01,  1.841998237556686e-02,  
 -3.249814204509735e-01,  7.805883807339332e-02,  2.000458123624601e-02,  
 -3.238200997259933e-01, -1.646986314843889e-01,  1.453038910021411e-02,  
 -3.071870647501693e-01,  4.525937353623032e-01,  7.042710134632947e-03,  
 -3.062952672101842e-01, -6.627772715600880e-01,  9.909474136448071e-03,  
 -3.050091209118546e-01, -9.543052172408368e-01,  4.342402989401129e-03,  
 -2.996824040276308e-01,  9.893886367263438e-01,  3.372729439255868e-03,  
 -2.921284081754466e-01, -9.294730734165612e-01,  2.665965363398914e-03,  
 -2.914965364345655e-01,  6.692685855887550e-01,  1.582542223968635e-02,  
 -2.849688540703927e-01,  8.208871837516990e-01,  1.282912704147129e-02,  
 -2.775942437207699e-01, -7.860689613395975e-01,  1.360434664922907e-02,  
 -2.774362772023182e-01,  5.115990505348308e-01,  1.098897677957239e-02,  
 -2.755992085208109e-01,  3.254136406036551e-01,  1.925748460208263e-02,  
 -2.730189749816505e-01, -5.730141929391641e-01,  8.984924690945310e-03,  
 -2.726652774174905e-01,  9.242598423864574e-01,  7.499462320384355e-03,  
 -2.634405915779047e-01, -1.587836571409323e-01,  9.151050686680885e-03,  
 -2.581490524350047e-01, -9.976246277074098e-01,  1.288369519072761e-03,  
 -2.490613945225850e-01, -4.306131655168830e-03,  1.532382255249465e-02,  
 -2.481031816687010e-01, -8.793359713116025e-01,  9.514481983528278e-03,  
 -2.422113837712834e-01, -4.067758048281825e-01,  2.014440359087718e-02,  
 -2.142982700599490e-01, -5.985373158690191e-01,  1.073521366680798e-02,  
 -2.135636186828752e-01, -9.733501320280229e-01,  4.395976260430139e-03,  
 -2.120981534047442e-01, -2.428876390935836e-01,  1.362392033623074e-02,  
 -2.113005630523961e-01,  1.863808573678246e-01,  2.256933019148822e-02,  
 -1.895873328892071e-01,  9.674135332629907e-01,  6.051240317593347e-03,  
 -1.887919907489533e-01,  5.980986332057304e-01,  1.682881188451604e-02,  
 -1.857949999128354e-01,  7.522305689580321e-01,  1.584160022074351e-02,  
 -1.785159586757167e-01,  8.807216617533518e-01,  1.082011427084735e-02,  
 -1.761916572679682e-01,  4.332093347373318e-01,  1.838648906261771e-02,  
 -1.742977443345394e-01, -7.112509510911679e-01,  1.631426543009215e-02,  
 -1.702885707912656e-01,  9.976789076998883e-01,  1.351463488000147e-03,  
 -1.691543181894413e-01, -6.151605950205655e-02,  1.668922632214760e-02,  
 -1.512139533768488e-01, -9.260205563520960e-01,  8.640465753043138e-03,  
 -1.429635335922110e-01, -2.866349030383558e-01,  1.453893632844844e-02,  
 -1.375607617049847e-01, -4.955879381687505e-01,  2.007831161324815e-02,  
 -1.363419810781558e-01, -8.281488459378050e-01,  1.334923028506015e-02,  
 -1.250921268079241e-01, -9.903984650569976e-01,  2.682247880612530e-03,  
 -1.125935592224152e-01,  3.114936705323088e-01,  2.026270260609158e-02,  
 -1.120779617378507e-01,  9.019594046827543e-02,  2.123405804160869e-02,  
 -8.562789192900672e-02,  5.348790809658290e-01,  1.342143700870946e-02,  
 -8.108140369770123e-02,  9.326400187377183e-01,  8.842669360811586e-03,  
 -8.047112887577813e-02, -1.412185710601948e-01,  1.994097452113148e-02,  
 -7.703715921083283e-02,  8.232440020795283e-01,  1.369548566612555e-02,  
 -7.440127659045481e-02,  6.789581696580780e-01,  1.764482626920084e-02,  
 -6.880848892096898e-02, -6.277692461838515e-01,  1.711869621320623e-02,  
 -6.244277913125515e-02, -3.629270311886996e-01,  1.813298184989576e-02,  
 -6.005252974695677e-02,  9.855825278690261e-01,  3.918915934867240e-03,  
 -4.739084718649585e-02, -9.614605234215312e-01,  6.465138335746558e-03,  
 -3.228486396950021e-02, -7.582958812442467e-01,  1.552477272766300e-02,  
 -2.853961004873518e-02, -9.985342967589811e-01,  9.129413317439405e-04,  
 -2.709739827138708e-02, -8.853879813981095e-01,  1.151661207322516e-02,  
 -2.187534604509761e-02,  4.331482264797441e-01,  1.526409630067874e-02,  
 -1.949843130353365e-02,  2.223381624896826e-01,  2.052030171197288e-02,  
 -1.664223141068962e-02,  2.434035865751951e-02,  1.253941316760429e-02,  
 -5.632469283442591e-03, -5.482248741666836e-01,  1.007056710865806e-02,  
 5.632469283442591e-03,  5.482248741666836e-01,  1.007056710865806e-02,  
 1.664223141068962e-02, -2.434035865751951e-02,  1.253941316760429e-02,  
 1.949843130353365e-02, -2.223381624896826e-01,  2.052030171197288e-02,  
 2.187534604509761e-02, -4.331482264797441e-01,  1.526409630067874e-02,  
 2.709739827138708e-02,  8.853879813981095e-01,  1.151661207322516e-02,  
 2.853961004873518e-02,  9.985342967589811e-01,  9.129413317439405e-04,  
 3.228486396950021e-02,  7.582958812442467e-01,  1.552477272766300e-02,  
 4.739084718649585e-02,  9.614605234215312e-01,  6.465138335746558e-03,  
 6.005252974695677e-02, -9.855825278690261e-01,  3.918915934867240e-03,  
 6.244277913125515e-02,  3.629270311886996e-01,  1.813298184989576e-02,  
 6.880848892096898e-02,  6.277692461838515e-01,  1.711869621320623e-02,  
 7.440127659045481e-02, -6.789581696580780e-01,  1.764482626920084e-02,  
 7.703715921083283e-02, -8.232440020795283e-01,  1.369548566612555e-02,  
 8.047112887577813e-02,  1.412185710601948e-01,  1.994097452113148e-02,  
 8.108140369770123e-02, -9.326400187377183e-01,  8.842669360811586e-03,  
 8.562789192900672e-02, -5.348790809658290e-01,  1.342143700870946e-02,  
 1.120779617378507e-01, -9.019594046827543e-02,  2.123405804160869e-02,  
 1.125935592224152e-01, -3.114936705323088e-01,  2.026270260609158e-02,  
 1.250921268079241e-01,  9.903984650569976e-01,  2.682247880612530e-03,  
 1.363419810781558e-01,  8.281488459378050e-01,  1.334923028506015e-02,  
 1.375607617049847e-01,  4.955879381687505e-01,  2.007831161324815e-02,  
 1.429635335922110e-01,  2.866349030383558e-01,  1.453893632844844e-02,  
 1.512139533768488e-01,  9.260205563520960e-01,  8.640465753043138e-03,  
 1.691543181894413e-01,  6.151605950205655e-02,  1.668922632214760e-02,  
 1.702885707912656e-01, -9.976789076998883e-01,  1.351463488000147e-03,  
 1.742977443345394e-01,  7.112509510911679e-01,  1.631426543009215e-02,  
 1.761916572679682e-01, -4.332093347373318e-01,  1.838648906261771e-02,  
 1.785159586757167e-01, -8.807216617533518e-01,  1.082011427084735e-02,  
 1.857949999128354e-01, -7.522305689580321e-01,  1.584160022074351e-02,  
 1.887919907489533e-01, -5.980986332057304e-01,  1.682881188451604e-02,  
 1.895873328892071e-01, -9.674135332629907e-01,  6.051240317593347e-03,  
 2.113005630523961e-01, -1.863808573678246e-01,  2.256933019148822e-02,  
 2.120981534047442e-01,  2.428876390935836e-01,  1.362392033623074e-02,  
 2.135636186828752e-01,  9.733501320280229e-01,  4.395976260430139e-03,  
 2.142982700599490e-01,  5.985373158690191e-01,  1.073521366680798e-02,  
 2.422113837712834e-01,  4.067758048281825e-01,  2.014440359087718e-02,  
 2.481031816687010e-01,  8.793359713116025e-01,  9.514481983528278e-03,  
 2.490613945225850e-01,  4.306131655168830e-03,  1.532382255249465e-02,  
 2.581490524350047e-01,  9.976246277074098e-01,  1.288369519072761e-03,  
 2.634405915779047e-01,  1.587836571409323e-01,  9.151050686680885e-03,  
 2.726652774174905e-01, -9.242598423864574e-01,  7.499462320384355e-03,  
 2.730189749816505e-01,  5.730141929391641e-01,  8.984924690945310e-03,  
 2.755992085208109e-01, -3.254136406036551e-01,  1.925748460208263e-02,  
 2.774362772023182e-01, -5.115990505348308e-01,  1.098897677957239e-02,  
 2.775942437207699e-01,  7.860689613395975e-01,  1.360434664922907e-02,  
 2.849688540703927e-01, -8.208871837516990e-01,  1.282912704147129e-02,  
 2.914965364345655e-01, -6.692685855887550e-01,  1.582542223968635e-02,  
 2.921284081754466e-01,  9.294730734165612e-01,  2.665965363398914e-03,  
 2.996824040276308e-01, -9.893886367263438e-01,  3.372729439255868e-03,  
 3.050091209118546e-01,  9.543052172408368e-01,  4.342402989401129e-03,  
 3.062952672101842e-01,  6.627772715600880e-01,  9.909474136448071e-03,  
 3.071870647501693e-01, -4.525937353623032e-01,  7.042710134632947e-03,  
 3.238200997259933e-01,  1.646986314843889e-01,  1.453038910021411e-02,  
 3.249814204509735e-01, -7.805883807339332e-02,  2.000458123624601e-02,  
 3.431840305246549e-01,  3.234632166086708e-01,  1.841998237556686e-02,  
 3.501126585283145e-01, -9.528774489514406e-01,  4.781907234841134e-03,  
 3.505957261026271e-01,  5.039294885140760e-01,  1.713918706362200e-02,  
 3.600054767607526e-01, -5.420299693619358e-01,  1.119360645451427e-02,  
 3.634966464384106e-01,  9.868648166528062e-01,  3.442228582990279e-03,  
 3.649610153286265e-01, -2.347382351652932e-01,  1.685485671337773e-02,  
 3.686176671629213e-01,  8.637636801184702e-01,  7.881047457319663e-03,  
 3.734439819891471e-01,  7.600731641857339e-01,  4.571534994749117e-03,  
 3.742272834656374e-01, -7.386438108932267e-01,  1.206959551802083e-02,  
 3.758321036768930e-01, -8.749564346095232e-01,  9.283988967311280e-03,  
 3.832064070624976e-01,  6.989145768785087e-01,  1.037562767669162e-02,  
 3.908325740224702e-01,  9.235350202575059e-01,  5.809955546559159e-03,  
 4.013358778023735e-01,  6.857748024247086e-02,  1.914789477071623e-02,  
 4.087838261055447e-01, -3.960341312468386e-01,  1.965538234308296e-02,  
 4.190565853462007e-01, -9.985365756542770e-01,  1.043658595167089e-03,  
 4.280793712750670e-01, -6.111370786685761e-01,  1.539138011397148e-02,  
 4.297409120893627e-01, -9.734301034170465e-01,  4.194517995438787e-03,  
 4.347931405390690e-01,  8.230011687029393e-01,  8.429370045209109e-03,  
 4.402029273535364e-01, -1.500200794764788e-01,  1.542342490182974e-02,  
 4.404692204242281e-01,  6.030105930154493e-01,  1.529211567826421e-02,  
 4.426248172627640e-01,  2.509072334899481e-01,  1.793705768294306e-02,  
 4.434508659987488e-01,  4.254148994030716e-01,  1.620216257327421e-02,  
 4.452822066090281e-01, -7.925031022467097e-01,  1.000481753825504e-02,  
 4.521990532828559e-01, -9.132454907960982e-01,  6.548142672947493e-03,  
 4.612328243535970e-01,  9.636523905629031e-01,  5.391019613357756e-03,  
 4.628745793832066e-01,  9.980775898655661e-01,  1.085007318378005e-03,  
 4.637181860680785e-01,  9.054278376743077e-04,  9.310011516460947e-03,  
 4.917682812876415e-01,  7.568554964536706e-01,  9.839983273859529e-03,  
 5.026640169457263e-01, -2.885178419959957e-01,  1.960777274062006e-02,  
 5.046922823409280e-01,  9.035785351511306e-01,  8.414747616632558e-03,  
 5.059023911245950e-01, -4.925206672723313e-01,  1.868221045034610e-02,  
 5.132250082992501e-01, -6.918190741864376e-01,  1.482210020758091e-02,  
 5.217650146651664e-01, -8.449124099305068e-01,  1.001711474683906e-02,  
 5.224669683154261e-01, -6.130399485027747e-02,  1.507572575361228e-02,  
 5.244630726975610e-01,  1.577626633034953e-01,  1.882044362224186e-02,  
 5.268264010539805e-01,  5.252722734230787e-01,  1.359552165919798e-02,  
 5.304327612566657e-01, -9.890527261919566e-01,  2.827063130099349e-03,  
 5.310856361451403e-01,  6.813014817383491e-01,  1.027869913918279e-02,  
 5.312450979752437e-01, -9.432008243433877e-01,  5.898171201208263e-03,  
 5.388169516109163e-01,  3.607537832967127e-01,  1.609524415648660e-02,  
 5.459986569191559e-01,  8.375938371742565e-01,  6.050055084086778e-03,  
 5.527846142946271e-01,  9.861830959616884e-01,  3.099780098793835e-03,  
 5.923843694597760e-01, -5.896493007707313e-01,  1.621562787972456e-02,  
 5.926997294875127e-01, -1.776082891969388e-01,  1.866120408927115e-02,  
 5.952839737903306e-01,  9.461274496340163e-01,  6.416292856646743e-03,  
 5.961040200801679e-01, -3.848010075739488e-01,  1.817040820422673e-02,  
 5.962301970690166e-01,  6.095934069736669e-01,  9.465990926377369e-03,  
 5.996089026350557e-01, -7.672038662942753e-01,  1.255110376162054e-02,  
 6.024059992622410e-01,  4.938164236519791e-02,  1.789883159375976e-02,  
 6.039369653473292e-01,  8.553105132198990e-01,  5.992514339035710e-03,  
 6.084927218969570e-01, -8.936876664228429e-01,  8.406065647319754e-03,  
 6.129302881959240e-01,  7.641285676915613e-01,  9.495321490596256e-03,  
 6.156820155086310e-01,  2.709084325931711e-01,  1.688158496630053e-02,  
 6.220861512524035e-01,  4.697281748057330e-01,  1.438590125499024e-02,  
 6.247537179451397e-01, -9.683796791313465e-01,  4.469874771751688e-03,  
 6.262273709687267e-01, -9.982013719921785e-01,  9.099112612198464e-04,  
 6.389939293530692e-01,  9.973854338568079e-01,  1.063420084490733e-03,  
 6.450460332339586e-01,  6.757412229808869e-01,  7.508776080828879e-03,  
 6.727321115145797e-01,  9.007641976237168e-01,  7.583356682716259e-03,  
 6.739684725259000e-01, -6.773736800515929e-01,  1.345027777804938e-02,  
 6.745224370419017e-01, -4.870189903811539e-01,  1.578358047019544e-02,  
 6.768663568972961e-01, -6.600586241345030e-02,  1.734826728379393e-02,  
 6.810744539515917e-01, -2.740932444646828e-01,  1.725213516752411e-02,  
 6.834535427418744e-01,  9.760799862104438e-01,  3.846584874829861e-03,  
 6.837395418610350e-01, -8.311442230210669e-01,  9.863681583277186e-03,  
 6.843613518240634e-01,  1.595802737672721e-01,  1.661539044799480e-02,  
 6.965278443683667e-01,  3.813019527700768e-01,  1.500927174360908e-02,  
 6.968216588357791e-01,  5.685630259242790e-01,  1.270493967976205e-02,  
 6.974082194827886e-01, -9.323769900190633e-01,  6.036713475981832e-03,  
 6.985970094666423e-01,  8.050208586687611e-01,  8.605257870218163e-03,  
 7.117204454198214e-01, -9.882619725048780e-01,  2.485303732104740e-03,  
 7.215017997406428e-01,  7.029762664554089e-01,  8.951206614074616e-03,  
 7.465512348230974e-01, -5.812636029728919e-01,  1.308836850969356e-02,  
 7.501867381740732e-01,  9.428041484167984e-01,  5.372797181130857e-03,  
 7.502398495650368e-01, -7.529941361384164e-01,  1.058551634212385e-02,  
 7.517728783471738e-01, -3.808909146571708e-01,  1.484618411110594e-02,  
 7.522143486281416e-01,  4.420957762341238e-02,  1.533410434098432e-02,  
 7.590915957882161e-01,  2.690284231981802e-01,  1.472349868949412e-02,  
 7.592537632153245e-01,  9.944779325803701e-01,  1.562546451718628e-03,  
 7.592567621031157e-01, -1.621753494096360e-01,  1.582235203050707e-02,  
 7.627844940764947e-01, -8.826229759338237e-01,  7.074367688839350e-03,  
 7.648340229962162e-01,  8.581827935318574e-01,  7.491144670441934e-03,  
 7.691224233934532e-01,  4.797259824277350e-01,  1.254447144435524e-02,  
 7.749274054206045e-01, -9.636900992554140e-01,  3.821815982327952e-03,  
 7.837299301003484e-01,  6.221133816449059e-01,  9.355464426914692e-03,  
 7.911850724888906e-01,  7.506825569200485e-01,  7.941591929716212e-03,  
 7.924551682337602e-01, -9.979434118184467e-01,  7.996645031474067e-04,  
 8.122235222464764e-01, -6.645693263356235e-01,  1.034590169853937e-02,  
 8.143075811610117e-01, -4.808919934779660e-01,  1.211587707934682e-02,  
 8.168195553880896e-01,  1.491433592951066e-01,  1.263065366829014e-02,  
 8.177674865173270e-01,  9.751105570722036e-01,  3.104258903016394e-03,  
 8.186687694116527e-01, -8.169654336809941e-01,  7.724614247165545e-03,  
 8.219455142773742e-01, -2.731244055602917e-01,  1.349903286379663e-02,  
 8.257297950277435e-01,  3.708722000140850e-01,  1.212267988934058e-02,  
 8.269765469411963e-01,  9.080859052720072e-01,  5.544241952351055e-03,  
 8.282749185054267e-01, -4.933486591871209e-02,  1.397066501428090e-02,  
 8.299696186499533e-01, -9.252056406107587e-01,  4.686829064201373e-03,  
 8.422060631929207e-01,  8.074677442695858e-01,  6.683571843601402e-03,  
 8.436301872985277e-01, -9.832315944888775e-01,  2.074514135087015e-03,  
 8.467214017035217e-01,  5.362390367615976e-01,  8.895976060123083e-03,  
 8.498643855720464e-01,  6.649755550632316e-01,  7.597610473619992e-03,  
 8.642150696852295e-01,  9.960092787039047e-01,  1.003841753738079e-03,  
 8.682723849317826e-01,  2.413725440218638e-01,  9.253909164096906e-03,  
 8.690861109568938e-01, -7.385216965817932e-01,  7.679645948063224e-03,  
 8.692675323873814e-01, -5.704948013117649e-01,  9.415315641120716e-03,  
 8.754979784047946e-01, -3.798655264692855e-01,  1.081669329181522e-02,  
 8.760350227104163e-01, -8.717500400436297e-01,  5.259870620154938e-03,  
 8.809708780612643e-01,  9.497050899975726e-01,  3.553886416146671e-03,  
 8.824241243616843e-01, -1.639785341465538e-01,  1.169349797338188e-02,  
 8.866202065469098e-01,  6.348808497993091e-02,  1.154404882651323e-02,  
 8.885392464038627e-01,  4.435272092291309e-01,  7.568949220120856e-03,  
 8.886655773400590e-01, -9.537789903620841e-01,  2.876082206616951e-03,  
 8.895890260377957e-01,  8.637277108491151e-01,  5.232804117494899e-03,  
 8.919221754192620e-01, -9.949598324120587e-01,  8.127871134893036e-04,  
 8.947437970286245e-01,  7.322325765211256e-01,  6.893118586976826e-03,  
 9.080065935974906e-01,  3.164859240152895e-01,  6.837639413127251e-03,  
 9.089721587302551e-01,  5.857463675029180e-01,  7.267970782315043e-03,  
 9.146615254968106e-01, -6.525583504423961e-01,  6.930392199976675e-03,  
 9.157242077150120e-01, -8.048621575323117e-01,  5.331392481303393e-03,  
 9.174707990058046e-01,  9.831219824223332e-01,  1.793027637558652e-03,  
 9.205673142765751e-01, -4.776877088663017e-01,  8.065709176393822e-03,  
 9.263239701445769e-01, -9.107049422584537e-01,  3.371000191307030e-03,  
 9.263857355252882e-01, -2.779326048975370e-01,  9.028086779958895e-03,  
 9.305488551107037e-01, -5.136546721748054e-02,  9.197493230088536e-03,  
 9.309296248560257e-01,  9.140613176099411e-01,  3.495989691744833e-03,  
 9.316426596133324e-01, -9.753406841125737e-01,  1.609586813812562e-03,  
 9.335259963058073e-01,  1.741913013268586e-01,  8.674585526845215e-03,  
 9.347835826828178e-01,  8.032727461306876e-01,  5.101386107167580e-03,  
 9.378343978313476e-01, -9.979840227602486e-01,  2.886874404933051e-04,  
 9.383440437473887e-01,  4.677837297857259e-01,  5.286783724635598e-03,  
 9.438088288340477e-01,  6.623911600100255e-01,  5.441477466246755e-03,  
 9.498352776387182e-01,  3.600313059077714e-01,  4.618417760022735e-03,  
 9.503534180334950e-01, -7.288766888422127e-01,  4.767863642349979e-03,  
 9.508617818904216e-01,  9.981801380774861e-01,  4.122462038678519e-04,  
 9.549317791767546e-01, -5.686259325313919e-01,  5.498722518704855e-03,  
 9.561574884827165e-01, -8.545038074891833e-01,  3.350951463581097e-03,  
 9.580781208653250e-01,  9.589071798906652e-01,  1.967241617526768e-03,  
 9.610263909737414e-01, -3.856673360143000e-01,  6.245421895915378e-03,  
 9.627844810540420e-01, -1.672694103301844e-01,  6.389370066661570e-03,  
 9.635050607978470e-01, -9.431294630830762e-01,  1.956380667434553e-03,  
 9.662771630324206e-01,  6.217984707467629e-02,  6.426823016887218e-03,  
 9.665514792427918e-01, -9.883256946409834e-01,  7.290779022650052e-04,  
 9.668019398584777e-01,  8.667816625365619e-01,  3.131430980170647e-03,  
 9.674102004473606e-01,  5.434109773347497e-01,  4.913196335695364e-03,  
 9.705718320763341e-01,  7.396086944705653e-01,  3.749135556172170e-03,  
 9.706604253083109e-01,  2.692976728099303e-01,  4.748645217638728e-03,  
 9.788073039622869e-01, -6.519818446915956e-01,  3.314343051454497e-03,  
 9.796226493234478e-01, -7.887535957547051e-01,  2.729782607675046e-03,  
 9.801554723479408e-01,  9.863754508076430e-01,  7.682431569634297e-04,  
 9.819763154480772e-01, -2.606278193971512e-01,  2.140965174384009e-03,  
 9.834620733084443e-01,  4.095317899088909e-01,  3.294182229441701e-03,  
 9.839061975006608e-01, -8.975109105786676e-01,  1.696426511535707e-03,  
 9.843630383600804e-01, -4.886238428735122e-01,  3.617312818445750e-03,  
 9.855018569701638e-01,  9.249596493833102e-01,  1.577833631361155e-03,  
 9.855704338257310e-01, -9.982037827098472e-01,  1.679707148208503e-04,  
 9.871440151549654e-01, -5.740263552332389e-02,  3.880572488162640e-03,  
 9.872610044005977e-01,  6.363286357326429e-01,  2.912531649448298e-03,  
 9.885082901085881e-01, -9.678446822025472e-01,  8.290334262139013e-04,  
 9.894046340107479e-01, -3.041157495057775e-01,  2.220343118583675e-03,  
 9.894541209227824e-01,  1.743999916176229e-01,  3.272756891802527e-03,  
 9.899762961164086e-01,  8.107546466202721e-01,  1.978506208627187e-03,  
 9.931482649594923e-01,  4.688097799928717e-01,  1.263445560038073e-03,  
 9.947687668481154e-01, -7.122817636688038e-01,  1.297939923938297e-03,  
 9.958386434423615e-01,  9.967140264655182e-01,  1.294234585034121e-04,  
 9.958487588813290e-01, -8.454813315395656e-01,  9.269269947395651e-04,  
 9.966756982844908e-01,  9.646209210318417e-01,  4.673464325522125e-04,  
 9.967076640629561e-01, -5.825966069019469e-01,  1.351054193096153e-03,  
 9.976266468967849e-01,  3.120694338997498e-01,  1.417265243059842e-03,  
 9.978969853829365e-01, -1.744352247684945e-01,  1.316676065658554e-03,  
 9.979331148437312e-01,  7.218491788727829e-01,  9.165568347185002e-04,  
 9.980560915023025e-01, -9.316458011937399e-01,  4.410107005989047e-04,  
 9.980563050335864e-01, -4.026468127795991e-01,  1.133746118823456e-03,  
 9.980752383111224e-01, -9.895590629954322e-01,  1.605142582803498e-04,  
 9.982465196344393e-01,  5.720585061776626e-02,  1.187360397727577e-03,  
 9.982657143502113e-01,  5.472808378415216e-01,  8.825961580004602e-04,  
 9.982950612817629e-01,  8.809790422529455e-01,  5.868976563494200e-04,  
 9.984626432301655e-01, -7.731810731373280e-01,  2.930667077040843e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr52 ( )

/******************************************************************************/
/*
  Purpose:

    SMR52 returns the SMR rule of degree 52.

  Discussion:
 
    DEGREE: 52
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 493
    NORM INF MOMS. RESIDUAL: 1.77636e-15
    SUM NEGATIVE WEIGHTS: 0.00000e+00, 

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR52[3*493], the requested rule.
*/
{
  const int degree = 52;
  int order;
  double xw[3*493] = {
 -9.988127014409341e-01, -9.436524211624828e-01,  2.625526521558170e-04,  
 -9.987672107909694e-01,  6.030206237885709e-01,  5.695969962358445e-04,  
 -9.985482219550218e-01, -5.039975022757507e-02,  7.711038314291110e-04,  
 -9.984716084730251e-01,  1.648465544907188e-01,  9.876559621004946e-04,  
 -9.983247427277899e-01,  9.851489095644117e-01,  1.847474866940015e-04,  
 -9.981050848344004e-01, -9.897892710317165e-01,  1.455770846634000e-04,  
 -9.980702320219238e-01, -8.710220064295600e-01,  3.606265853945270e-04,  
 -9.980157290478607e-01,  3.823621895788871e-01,  1.084084984803506e-03,  
 -9.979067456855214e-01, -3.075229364789735e-01,  1.191752453605670e-03,  
 -9.976530827260541e-01, -4.990560694030991e-01,  1.016394895068514e-03,  
 -9.976275687951667e-01,  7.452570753224620e-01,  7.962338632193404e-04,  
 -9.975360338995326e-01,  9.261655839467660e-01,  4.882884021026501e-04,  
 -9.975285341692078e-01, -6.928059429685538e-01,  9.702964010210698e-04,  
 -9.953470417114124e-01,  8.469149414179490e-01,  1.047597310781277e-03,  
 -9.949171976648574e-01, -8.070683057038244e-01,  1.108166020112025e-03,  
 -9.944164425670770e-01, -5.787407343604202e-01,  7.129063333926422e-04,  
 -9.941125375307870e-01, -1.470529960706050e-01,  1.642945733107137e-03,  
 -9.940811335498559e-01,  5.262691220462341e-01,  1.362380806792382e-03,  
 -9.897485255752738e-01,  5.394829132785462e-02,  2.963671420601588e-03,  
 -9.892180378042456e-01, -9.087168466804317e-01,  1.131388755188889e-03,  
 -9.889422632399338e-01,  2.713380420380118e-01,  3.125665368172544e-03,  
 -9.885261339590784e-01,  6.719762287559811e-01,  2.097374310513504e-03,  
 -9.884080307277354e-01,  9.975758923464908e-01,  1.953339748936135e-04,  
 -9.882332182747464e-01, -9.695741031299449e-01,  7.675549180338620e-04,  
 -9.877426889646129e-01,  9.620340499987866e-01,  8.981773684854589e-04,  
 -9.866490694768677e-01, -4.072569387119710e-01,  3.309040261667309e-03,  
 -9.862080286100734e-01, -9.979989708388572e-01,  1.771493432242450e-04,  
 -9.850029364942529e-01, -6.122812872550168e-01,  2.518297727094817e-03,  
 -9.837180977617805e-01,  4.565187303545456e-01,  2.849889245739051e-03,  
 -9.828587452609784e-01, -2.237836811810542e-01,  3.333021131510325e-03,  
 -9.812038715498557e-01, -7.470892816031330e-01,  2.670944794198278e-03,  
 -9.804090236453241e-01,  7.865707923823555e-01,  2.595590100008589e-03,  
 -9.803632387653639e-01,  8.971515025804927e-01,  1.885488419687061e-03,  
 -9.744321506843910e-01, -8.554737714830845e-01,  2.459646855887305e-03,  
 -9.742163651294308e-01,  6.008292093097657e-01,  2.870907182669987e-03,  
 -9.729683924479909e-01, -5.587440042487817e-02,  4.917833265113004e-03,  
 -9.697112617400576e-01,  1.602542576828755e-01,  5.452176079736804e-03,  
 -9.680411604163617e-01,  9.857573537516288e-01,  8.708152215923545e-04,  
 -9.671487130651160e-01, -5.124328504244583e-01,  4.833032752395291e-03,  
 -9.660915478928949e-01, -9.410399722417206e-01,  1.871973610506917e-03,  
 -9.654667822672215e-01,  3.609268066648831e-01,  5.184591828903681e-03,  
 -9.639431956447733e-01, -9.879198529552836e-01,  8.794879382184762e-04,  
 -9.614660794937132e-01, -3.152384510082097e-01,  5.556266122517595e-03,  
 -9.578505518072694e-01, -6.724291809200033e-01,  4.600539485987667e-03,  
 -9.577920524303927e-01,  9.419676523596269e-01,  2.067193179306530e-03,  
 -9.565901478096345e-01,  7.131943261709114e-01,  4.501746579124314e-03,  
 -9.563856659236216e-01,  5.366994723963830e-01,  4.091039972256468e-03,  
 -9.547002111419167e-01,  8.456829919243595e-01,  3.449895771139099e-03,  
 -9.480347148392301e-01, -7.980108126871678e-01,  4.091232197362770e-03,  
 -9.466546601107151e-01, -1.535515771237759e-01,  6.528301611585182e-03,  
 -9.407727344940110e-01,  9.974474996682516e-01,  4.106004179329372e-04,  
 -9.406336688240443e-01,  4.809416959792988e-02,  7.867342756512173e-03,  
 -9.385942706076326e-01, -8.971257377253743e-01,  3.361963450252926e-03,  
 -9.374484562304576e-01, -4.280910958367013e-01,  5.268531158388501e-03,  
 -9.355541598304502e-01,  2.580629240689983e-01,  7.741872807667612e-03,  
 -9.298520361643660e-01,  4.530291593891102e-01,  6.861969988622674e-03,  
 -9.288002329410462e-01, -9.982636344108895e-01,  4.247627014166712e-04,  
 -9.286076316092796e-01, -9.683702815657360e-01,  2.067880829241110e-03,  
 -9.273140499128685e-01, -5.830164942292532e-01,  6.818967325836010e-03,  
 -9.241333130400774e-01,  9.730541529028506e-01,  1.883965192232535e-03,  
 -9.237428919656653e-01,  9.027306131882519e-01,  3.504902468774958e-03,  
 -9.235277754610037e-01,  6.312812357563800e-01,  6.653238342342486e-03,  
 -9.201554641362426e-01,  7.828842024684245e-01,  5.399263941930352e-03,  
 -9.146048961351547e-01, -3.818203957693841e-01,  3.883204055435776e-03,  
 -9.134571331269357e-01, -7.302858649211827e-01,  5.936946390067688e-03,  
 -9.127061051003793e-01, -2.440926271600780e-01,  7.778151311059332e-03,  
 -9.000460112835083e-01, -5.999759307515896e-02,  1.006988417423119e-02,  
 -8.993673287617778e-01, -8.451235123042792e-01,  5.132639563405409e-03,  
 -8.951339292576600e-01,  1.501613851250017e-01,  1.029518732475798e-02,  
 -8.900418335246519e-01, -9.336515985913562e-01,  3.643970310522402e-03,  
 -8.898728450490625e-01,  3.576291382984933e-01,  9.637275856624482e-03,  
 -8.857738818343428e-01,  9.936543288762641e-01,  1.022984433880787e-03,  
 -8.818416083906041e-01,  9.450853611425074e-01,  3.145523188534807e-03,  
 -8.817749203273469e-01, -4.932298853007941e-01,  9.084000283221681e-03,  
 -8.814761392195805e-01,  5.416562961189009e-01,  9.072290159833062e-03,  
 -8.809406948295482e-01,  8.535407316796645e-01,  5.347074653297229e-03,  
 -8.798020856626885e-01, -9.884352690470977e-01,  1.656645365945089e-03,  
 -8.768241727520295e-01,  7.105750002763417e-01,  7.595594780779568e-03,  
 -8.743313495697173e-01, -6.501013827893755e-01,  7.766100758953991e-03,  
 -8.675207720318823e-01, -3.252706153983532e-01,  8.588815830823287e-03,  
 -8.531346041372393e-01, -7.827795724666364e-01,  6.991254752878786e-03,  
 -8.485014584070562e-01, -1.648574733809313e-01,  1.202856513087624e-02,  
 -8.434761432300958e-01,  4.179466117573257e-02,  1.258022009476385e-02,  
 -8.393214861404557e-01, -8.894108000250006e-01,  5.524277448717241e-03,  
 -8.391818467944713e-01,  2.545179546089011e-01,  1.225926031029606e-02,  
 -8.389010580797999e-01,  9.785599021539588e-01,  2.201494437849886e-03,  
 -8.333919059785300e-01,  9.103106242715236e-01,  4.477470554220304e-03,  
 -8.311563781350246e-01, -9.635256164514960e-01,  3.376010197250481e-03,  
 -8.298217920912521e-01,  7.941332222788777e-01,  7.533564430897306e-03,  
 -8.290685095371755e-01,  4.482650209711272e-01,  1.149566481976958e-02,  
 -8.246295014835788e-01,  6.305997501362324e-01,  1.002133619364441e-02,  
 -8.207113611081525e-01, -5.682370182998021e-01,  9.882671274606030e-03,  
 -8.184340779238838e-01, -4.076114937064008e-01,  1.051088940238909e-02,  
 -8.157166374300039e-01, -9.978562540287571e-01,  7.535666678414864e-04,  
 -8.078488627527156e-01, -7.069269989950133e-01,  8.137719625036887e-03,  
 -8.030595241917000e-01,  9.978144889761291e-01,  7.398767813052343e-04,  
 -7.837853688110477e-01, -2.620814341544582e-01,  1.356775659591216e-02,  
 -7.828099445346539e-01,  9.554066491475680e-01,  3.742102504728495e-03,  
 -7.821811758153498e-01, -8.335204770344818e-01,  7.560387964952924e-03,  
 -7.806111270198954e-01,  8.684234719628749e-01,  6.102001596168975e-03,  
 -7.803524467869071e-01, -6.465757120579249e-02,  1.471759892403581e-02,  
 -7.781302732885756e-01,  1.478929640026117e-01,  1.455413037861192e-02,  
 -7.699048258009954e-01, -9.276274655447458e-01,  5.304525007717353e-03,  
 -7.695306270777027e-01,  7.257931943974629e-01,  1.003569188582270e-02,  
 -7.682303760797261e-01,  3.499626949711698e-01,  1.375880064922265e-02,  
 -7.631751201806299e-01,  5.447749679670292e-01,  1.242753039931487e-02,  
 -7.596138287899911e-01, -9.835396090923282e-01,  2.607052889697995e-03,  
 -7.538052521221817e-01, -4.841495100795145e-01,  1.150926269265990e-02,  
 -7.454457200592598e-01, -6.328463240917150e-01,  1.022935020395876e-02,  
 -7.377478072703448e-01, -7.556338792328159e-01,  7.532798021311965e-03,  
 -7.352232084975729e-01,  9.868858130897517e-01,  2.411113681116213e-03,  
 -7.198141234443793e-01,  8.186185822277544e-01,  8.298549121304033e-03,  
 -7.182219035413855e-01,  9.224204584112459e-01,  5.742283577427958e-03,  
 -7.128567090368071e-01, -3.559798783186696e-01,  1.405749666059914e-02,  
 -7.053617504255151e-01,  4.264400312830402e-02,  1.671342637637877e-02,  
 -7.048221835776498e-01, -1.660772434082720e-01,  1.620416954102582e-02,  
 -7.028328208733023e-01, -8.796259271763389e-01,  7.428666069379373e-03,  
 -7.005292342230423e-01,  2.490631256735430e-01,  1.528459322279345e-02,  
 -7.004349479969345e-01,  6.487283853703079e-01,  1.261520225658359e-02,  
 -6.939940634234720e-01,  4.522675627245327e-01,  1.477231723739015e-02,  
 -6.903338552941003e-01, -9.562199287411650e-01,  4.558348175052095e-03,  
 -6.871780610546661e-01, -9.960902675679658e-01,  1.281042369432823e-03,  
 -6.751199651659419e-01, -7.954841412473590e-01,  6.801383287420498e-03,  
 -6.746711192530436e-01, -5.537611273503755e-01,  1.197946633058212e-02,  
 -6.594485902401920e-01, -6.893928585162992e-01,  1.054328271246189e-02,  
 -6.589580171205064e-01,  9.979540800990127e-01,  9.138061267054189e-04,  
 -6.581546857660769e-01,  9.651549901275206e-01,  4.438106561226704e-03,  
 -6.508115469743178e-01,  7.593018044169728e-01,  1.059590935519099e-02,  
 -6.442960669971189e-01,  8.800883973543062e-01,  8.056539860531373e-03,  
 -6.342911650570392e-01, -4.362965821626758e-01,  1.297306553921443e-02,  
 -6.311270608623304e-01,  1.623081864679719e-01,  1.169419850392987e-02,  
 -6.236113280952295e-01,  5.626303448491500e-01,  1.512993252997899e-02,  
 -6.230699212989589e-01, -2.676031853187564e-01,  1.701679082042949e-02,  
 -6.228316359543020e-01, -6.139199670125942e-02,  1.791234833004659e-02,  
 -6.180167254452483e-01,  3.536311947236717e-01,  1.688041459255943e-02,  
 -6.139917320508425e-01, -9.166124328923988e-01,  6.752267430799639e-03,  
 -6.135997420321182e-01, -9.785871069978234e-01,  3.265291929749685e-03,  
 -6.049437626707715e-01, -8.348685175419790e-01,  7.920079758120289e-03,  
 -5.924156072192565e-01,  1.122151337459072e-01,  9.854536189651026e-03,  
 -5.808954536963412e-01, -6.144989257211043e-01,  1.238347439918297e-02,  
 -5.771402248064471e-01,  6.916411158262615e-01,  1.234940827737965e-02,  
 -5.727489353537671e-01, -7.435597296984338e-01,  1.009808411716704e-02,  
 -5.727126755704744e-01,  9.873108745063405e-01,  2.892689438784615e-03,  
 -5.726969487730084e-01,  9.340439611874428e-01,  6.716170602729774e-03,  
 -5.641880535367902e-01,  8.278878381092918e-01,  1.034186096378337e-02,  
 -5.619751160626054e-01, -9.957490800477657e-01,  1.306397050035806e-03,  
 -5.595114849904512e-01, -4.950932951701612e-01,  1.012055396521365e-02,  
 -5.404408181688395e-01,  4.682798275107506e-01,  1.740850053308458e-02,  
 -5.346178912468168e-01, -1.658145193211824e-01,  1.879896919108429e-02,  
 -5.316901221553333e-01,  2.545384708233044e-01,  1.840778394220723e-02,  
 -5.304417973198247e-01, -3.592809785284879e-01,  1.695143266847294e-02,  
 -5.280451477489559e-01, -9.481339086199096e-01,  5.577814969827481e-03,  
 -5.221322143523578e-01,  2.800952111551927e-02,  1.767290541941230e-02,  
 -5.151186905025813e-01, -8.730519403291820e-01,  8.112883844601817e-03,  
 -5.020061912373424e-01,  6.192421120294556e-01,  1.353861723690707e-02,  
 -4.903530401754813e-01, -7.931258003876139e-01,  8.399071608732376e-03,  
 -4.865831129729520e-01,  9.982345574079382e-01,  8.888257339789671e-04,  
 -4.846013662166668e-01, -6.763247187729596e-01,  1.217250051276967e-02,  
 -4.839999766820920e-01,  8.928758009749419e-01,  8.937216600833743e-03,  
 -4.825855280212472e-01, -5.431509513734653e-01,  1.183707346969829e-02,  
 -4.823249529225693e-01,  7.660844388757198e-01,  1.216788713755992e-02,  
 -4.796646373118009e-01, -9.806365591887873e-01,  2.997919914508063e-03,  
 -4.767777412147164e-01,  9.670704183485596e-01,  5.199287981007803e-03,  
 -4.578606953009008e-01,  3.653266008375833e-01,  1.471515179826852e-02,  
 -4.457848210286569e-01,  1.456094511265953e-01,  1.865104111169145e-02,  
 -4.379382988456925e-01, -2.629650176911282e-01,  1.846921409696814e-02,  
 -4.348650881002861e-01, -9.972784483849305e-01,  1.074202056193302e-03,  
 -4.322726489605065e-01, -7.297583238110245e-02,  1.906793743471395e-02,  
 -4.275919441110620e-01, -4.360820986786115e-01,  1.573633000734291e-02,  
 -4.270673912729934e-01, -9.090686566218157e-01,  7.431022374141501e-03,  
 -4.254326005730727e-01,  5.424147018907464e-01,  1.524591494142875e-02,  
 -4.034134004690716e-01,  4.015985647828361e-01,  8.132984537933393e-03,  
 -4.019562701112450e-01, -7.422749928931541e-01,  8.984384832841273e-03,  
 -4.007956316021173e-01,  6.977544690649647e-01,  1.324825764743806e-02,  
 -3.970394499889119e-01,  8.417028483702832e-01,  1.064019181372773e-02,  
 -3.962311519387068e-01, -8.266178179921937e-01,  8.217747940915577e-03,  
 -3.925693641275523e-01, -6.062484728313788e-01,  1.307080472085916e-02,  
 -3.914186598228789e-01,  9.913544137855500e-01,  2.245607042588322e-03,  
 -3.907636956098022e-01, -9.581583494234572e-01,  4.727344394460009e-03,  
 -3.802684631916854e-01,  9.356425085799084e-01,  7.546845180916252e-03,  
 -3.667235432096608e-01,  2.538377799106385e-01,  1.802700518759309e-02,  
 -3.542077324305666e-01,  3.400725316094907e-02,  1.656276879967741e-02,  
 -3.382472441767229e-01, -1.769861959933089e-01,  1.695133386076922e-02,  
 -3.360507944158749e-01, -9.870600771841807e-01,  2.993500538686252e-03,  
 -3.321333158476729e-01, -3.472770242047587e-01,  1.692208839910539e-02,  
 -3.283161387055968e-01, -5.022338788020836e-01,  1.384987928124117e-02,  
 -3.234470453782608e-01,  4.749702348708390e-01,  1.664727618065397e-02,  
 -3.202148987380042e-01,  7.835525766177759e-01,  1.004319161998912e-02,  
 -3.190832382601436e-01,  6.269941745416843e-01,  1.454224638443978e-02,  
 -3.189860391580026e-01, -8.607035592419185e-01,  8.155361325578816e-03,  
 -3.171223960288885e-01,  9.776396030267889e-01,  3.392812344765450e-03,  
 -3.152599194498346e-01, -6.813908984973552e-01,  1.112163469352541e-02,  
 -3.048189974393888e-01, -7.518549520866326e-01,  5.276819552431108e-03,  
 -3.010266238384297e-01,  1.148836153616587e-01,  1.208064328383956e-02,  
 -2.975203773505370e-01, -9.264620147915089e-01,  6.591008941421552e-03,  
 -2.866843597937876e-01,  8.916357142521784e-01,  9.722680920609808e-03,  
 -2.778520292008587e-01,  3.379398856834260e-01,  1.660452875526483e-02,  
 -2.744543978372941e-01, -9.801898430305439e-02,  1.247830609628909e-02,  
 -2.587845000315547e-01, -9.987548667843699e-01,  8.603127328776212e-04,  
 -2.544608894429891e-01,  9.979361786556559e-01,  1.252512834658488e-03,  
 -2.535888618284378e-01, -5.699260916663523e-01,  1.192322325012015e-02,  
 -2.516174268783917e-01,  7.330785425737227e-01,  8.853857957147779e-03,  
 -2.417076375974273e-01, -7.891442960379055e-01,  1.102295327385847e-02,  
 -2.413622675326031e-01, -2.767284930209392e-01,  1.077421913186015e-02,  
 -2.328396638924550e-01, -9.660240239613915e-01,  5.265050387190376e-03,  
 -2.312798916515771e-01,  8.188743812299971e-01,  4.930961548632319e-03,  
 -2.306624795927337e-01,  9.461369824834985e-01,  3.182424510285970e-03,  
 -2.303709121443397e-01,  9.629630229642722e-01,  3.441645956712537e-03,  
 -2.267984183900834e-01, -4.153651530633773e-01,  1.478553509404215e-02,  
 -2.256135494476024e-01,  1.919211927874176e-01,  1.887063394340442e-02,  
 -2.179557409452807e-01,  5.651427172988402e-01,  1.620039755630136e-02,  
 -2.168766477790742e-01, -1.012612126707933e-02,  1.760999731931498e-02,  
 -2.016684978642726e-01, -8.842464367674409e-01,  8.512644523701873e-03,  
 -1.993535882469331e-01, -6.338481461271839e-01,  9.730410168975228e-03,  
 -1.913491324242725e-01, -2.232354009324879e-01,  1.422718417945826e-02,  
 -1.890072860808679e-01,  4.247570907504695e-01,  1.695426438700273e-02,  
 -1.862712620524861e-01,  6.913654513337745e-01,  1.082745299386850e-02,  
 -1.746191018373572e-01,  8.480550307741350e-01,  8.886868262309344e-03,  
 -1.675200684369691e-01, -7.047430234854786e-01,  1.094270966276307e-02,  
 -1.555836887665503e-01, -4.800663622673465e-01,  1.256149504580157e-02,  
 -1.539778628553684e-01, -9.901542147304263e-01,  2.778842341022969e-03,  
 -1.428714573350953e-01,  9.873473637042918e-01,  3.649388897241209e-03,  
 -1.384698657127528e-01,  9.205163602534699e-01,  7.904116666380833e-03,  
 -1.280453089534869e-01, -8.261529284212121e-01,  1.003683355115124e-02,  
 -1.269663966462650e-01, -9.340066191936205e-01,  7.536775230064883e-03,  
 -1.262851022233290e-01,  9.368263634475028e-02,  1.974459832420309e-02,  
 -1.259733133156085e-01,  2.934330084484927e-01,  2.074833465157029e-02,  
 -1.215370941220813e-01, -1.129536910574994e-01,  1.891311893739475e-02,  
 -1.063702041365650e-01,  7.792027274018843e-01,  1.191220588531841e-02,  
 -1.040885518460405e-01, -3.345081265086896e-01,  1.973449969826947e-02,  
 -9.605998455844682e-02,  6.444074525536151e-01,  1.345070861908871e-02,  
 -9.279166418896197e-02,  5.146935916151650e-01,  1.655226263892481e-02,  
 -9.125555597164577e-02, -5.450318588034616e-01,  1.217992697790634e-02,  
 -8.532044687750825e-02, -7.537009739836885e-01,  6.788672864407014e-03,  
 -6.799112688359676e-02, -6.229899588936270e-01,  1.080161967200763e-02,  
 -6.241140417558962e-02, -9.744491489990948e-01,  3.566539673859765e-03,  
 -5.161370829018064e-02,  9.610809656564491e-01,  6.005594200474568e-03,  
 -4.538160583172780e-02,  1.675029579312542e-02,  1.139804373859566e-02,  
 -4.097385567264155e-02,  8.800609612527350e-01,  8.815909757700713e-03,  
 -3.655935033800797e-02, -1.968615631298038e-01,  1.402267657973052e-02,  
 -3.473806771275045e-02, -8.898414026442482e-01,  8.163797867856551e-03,  
 -3.115326906841854e-02, -7.299617142501118e-01,  8.753969855827624e-03,  
 -2.664715561157583e-02, -9.979756016894712e-01,  1.223714150081927e-03,  
 -2.609621149728821e-02,  9.978312276054969e-01,  1.321094043330279e-03,  
 -2.462169196136119e-02,  4.000170187213391e-01,  1.964525457913152e-02,  
 -1.904435752714274e-02,  7.360687696712604e-01,  8.550678949429199e-03,  
 -1.889566824340530e-02,  1.984890570456425e-01,  2.186008310624084e-02,  
 -9.785690785648083e-03, -8.389279715572893e-01,  6.367637566748681e-03,  
 -9.157810803927260e-03, -4.247277120525336e-01,  1.808897606828866e-02,  
 3.179810404505250e-03,  8.314617064208917e-01,  7.240482363634763e-03,  
 8.164449639995641e-03, -3.602121469951976e-02,  1.507784539606016e-02,  
 8.914821501355173e-03, -9.569660527272593e-01,  4.452800904218950e-03,  
 1.397375150217838e-02,  6.074602279060227e-01,  1.339941447663378e-02,  
 2.177165943291160e-02, -2.514057561092151e-01,  1.257069649597742e-02,  
 4.345656816980569e-02, -6.515535698280098e-01,  1.376520145235682e-02,  
 4.780837263094481e-02, -5.293455201419695e-01,  1.433806151954274e-02,  
 5.126722291181950e-02,  7.136184270678109e-01,  9.059040654245952e-03,  
 5.384128121275275e-02,  5.215281819965334e-01,  1.026521104059108e-02,  
 5.402250856984708e-02,  9.276694371633791e-01,  7.888401157883149e-03,  
 5.581143910668790e-02,  9.821386878503260e-01,  3.771203907120499e-03,  
 6.627333635862039e-02, -7.885663982200815e-01,  1.217604845925398e-02,  
 7.206636203593361e-02, -9.211241316961639e-01,  6.736415177465982e-03,  
 7.992668048420556e-02,  3.134386785203354e-01,  2.055572742606252e-02,  
 8.448805256391662e-02,  9.712957741353333e-02,  2.128227886088045e-02,  
 8.463750249088479e-02, -9.874388870838863e-01,  3.523234483327328e-03,  
 9.799267198568701e-02, -1.212891339515704e-01,  1.949535188292260e-02,  
 9.827877674637196e-02, -3.251986289297008e-01,  1.749435408326382e-02,  
 9.985235399264410e-02,  8.076435842941359e-01,  1.073632596606910e-02,  
 1.057705156820273e-01,  4.793866965123078e-01,  1.166074198719580e-02,  
 1.278018204573015e-01, -8.673024017686580e-01,  8.130060280452144e-03,  
 1.364747655580873e-01,  8.824534837148562e-01,  8.631223960740082e-03,  
 1.418802082443522e-01,  6.877615804223791e-01,  1.036232616585965e-02,  
 1.441395429362260e-01, -7.037951529711909e-01,  1.188979856915669e-02,  
 1.469434540715263e-01, -4.441704987291489e-01,  1.490787435959768e-02,  
 1.506185900581580e-01,  9.946720380541423e-01,  1.885774991512346e-03,  
 1.560960715550660e-01, -9.625915789870874e-01,  3.201097878674840e-03,  
 1.604800952783144e-01,  6.059469388605253e-01,  1.251646880334661e-02,  
 1.635825517653865e-01, -5.753866291936182e-01,  1.530295086183503e-02,  
 1.655478645083420e-01,  9.589555963365791e-01,  5.804218295769638e-03,  
 1.726856195129373e-01,  2.122274920034202e-01,  1.881284565328789e-02,  
 1.789604491789879e-01, -9.402742786279485e-01,  3.866866604734349e-03,  
 1.830770810490266e-01, -7.917068664553941e-03,  1.896081259105628e-02,  
 1.917045789075228e-01, -8.352790590418837e-01,  6.668422594982694e-03,  
 1.919614057410328e-01,  4.159468317764071e-01,  1.803709701284910e-02,  
 1.934907380358813e-01, -2.169747177608121e-01,  1.856246659829771e-02,  
 1.969572179795044e-01, -9.977527139562596e-01,  1.300798686497381e-03,  
 2.107123929928807e-01, -7.484424229574373e-01,  8.397883820247469e-03,  
 2.151288514233329e-01,  7.680354518275807e-01,  1.267367187142015e-02,  
 2.377269840756392e-01, -3.593587047461513e-01,  1.531855347072487e-02,  
 2.449798765113445e-01,  8.561714185289828e-01,  8.384247794169401e-03,  
 2.461530653627976e-01,  9.236449528059149e-01,  6.701681191198367e-03,  
 2.486966580905335e-01,  3.008228521374701e-01,  1.106325734333346e-02,  
 2.499701593513872e-01, -9.752017232492153e-01,  3.850329050405175e-03,  
 2.501058258824206e-01,  5.509389569101368e-01,  1.475977026196545e-02,  
 2.528611993268930e-01,  9.351675397537039e-02,  1.449585921909408e-02,  
 2.568949734863621e-01, -9.022348356156346e-01,  8.940909487499378e-03,  
 2.683426686375737e-01,  9.991154086591990e-01,  5.889345360874240e-04,  
 2.685503151871029e-01, -6.356230295277764e-01,  1.517335754148565e-02,  
 2.697644015612075e-01,  9.815789636486361e-01,  3.726914126330296e-03,  
 2.709381851134464e-01, -1.244795386325534e-01,  1.382732736695818e-02,  
 2.737056179114525e-01, -4.896517471925337e-01,  1.596973556497186e-02,  
 2.841153891916503e-01, -7.963610419905591e-01,  1.018240390326565e-02,  
 2.887360776877746e-01,  6.760513756029857e-01,  1.358604251351786e-02,  
 3.149795837868063e-01,  1.767826719425314e-01,  1.445177151533629e-02,  
 3.165712280980518e-01,  3.479571606636541e-01,  1.397116071739750e-02,  
 3.233387951857696e-01, -3.964021294199390e-02,  1.467594281112195e-02,  
 3.268920397235026e-01, -2.731725775852362e-01,  1.771570545449453e-02,  
 3.326248311408019e-01,  4.836740826389543e-01,  1.486343284668958e-02,  
 3.335126221786843e-01, -9.908899215613953e-01,  2.568858034338105e-03,  
 3.408563759162994e-01,  7.550164756697521e-01,  6.822413031377531e-03,  
 3.443109876462521e-01,  8.290574313399783e-01,  9.197826117265570e-03,  
 3.486450229035982e-01, -9.439378779811103e-01,  6.983226832200802e-03,  
 3.518759527448840e-01,  9.560724389841232e-01,  4.965627623349140e-03,  
 3.524828322454360e-01, -7.050052060893320e-01,  1.197554054145159e-02,  
 3.590126501200323e-01,  9.063249825645421e-01,  6.542367126762410e-03,  
 3.633899545054107e-01, -4.158806284730630e-01,  1.021934848164813e-02,  
 3.656349853648961e-01, -8.551125998661749e-01,  1.062020373233702e-02,  
 3.807891001192470e-01,  6.253125077526936e-01,  1.119123494000414e-02,  
 3.808423427288536e-01,  9.944730583867565e-01,  1.632382643499531e-03,  
 3.809375504826950e-01, -5.546294515204083e-01,  1.615046394684124e-02,  
 3.945468502595033e-01,  6.752821319401937e-02,  1.729957749916545e-02,  
 4.037326882224722e-01, -7.443269137253894e-01,  5.244741835639755e-03,  
 4.039759465731999e-01, -1.584043966963531e-01,  1.831424532905047e-02,  
 4.104920535739149e-01,  2.529785766209403e-01,  1.814309214474618e-02,  
 4.222816582184452e-01,  7.408148672071336e-01,  7.766759229688390e-03,  
 4.224134639390744e-01, -3.745372912517947e-01,  1.317478594938575e-02,  
 4.277143244118732e-01,  4.170215562701938e-01,  1.538057245965674e-02,  
 4.333717867425739e-01,  5.690603581255754e-01,  1.115237702189693e-02,  
 4.349755932480709e-01, -9.985636264967975e-01,  8.821277372105579e-04,  
 4.398941633478518e-01,  9.803729409712968e-01,  2.765623301727146e-03,  
 4.441324812379997e-01, -9.722660935224676e-01,  4.719463795528141e-03,  
 4.543070171443870e-01,  8.838298014870239e-01,  7.433086897010635e-03,  
 4.552061144607135e-01,  8.130123814788113e-01,  6.665811090423725e-03,  
 4.563764124987013e-01, -9.047285344881011e-01,  8.712285205058833e-03,  
 4.605130146464505e-01, -7.890667787179867e-01,  1.104769785347448e-02,  
 4.650767440674204e-01, -6.345308909000896e-01,  1.471818226211541e-02,  
 4.674115659846697e-01, -2.156835684881248e-02,  1.289379103218861e-02,  
 4.773494044297329e-01,  9.456346888484196e-01,  5.554333960414898e-03,  
 4.810795638831788e-01,  7.045677590620393e-01,  8.378675676746713e-03,  
 4.883109086023527e-01, -2.624666533620124e-01,  1.805604188701234e-02,  
 4.989586416584096e-01, -4.789926304087422e-01,  1.768874128800384e-02,  
 5.035782169093800e-01,  1.523921509996070e-01,  1.912436354376622e-02,  
 5.136924925920076e-01,  9.970688163327739e-01,  1.172939498317349e-03,  
 5.169947058579401e-01,  3.370225548177525e-01,  1.637088692250307e-02,  
 5.191129921767861e-01, -8.134646960530036e-02,  1.194181152772743e-02,  
 5.204183249331878e-01,  5.085175426873372e-01,  1.466908354875696e-02,  
 5.393484610466828e-01,  6.440810813198078e-01,  1.182257049730026e-02,  
 5.409261529913778e-01, -9.899204841179033e-01,  2.610777565683107e-03,  
 5.436431320060356e-01, -8.462212203410651e-01,  1.007390508879517e-02,  
 5.451712421766679e-01,  8.553559399904247e-01,  5.821377493347785e-03,  
 5.478116255118839e-01, -9.433804473799871e-01,  6.399987549895861e-03,  
 5.478642383937216e-01, -7.090052412035255e-01,  1.297516415531765e-02,  
 5.564069189295534e-01,  7.864423641670446e-01,  9.321003881444800e-03,  
 5.624905637364527e-01,  9.770501107487227e-01,  3.623905342788340e-03,  
 5.756133273548432e-01,  9.199072591365679e-01,  6.781383669452935e-03,  
 5.767931202505592e-01, -3.594698820499517e-01,  1.753399004685696e-02,  
 5.847884341379717e-01, -5.712950409715517e-01,  1.571578525431043e-02,  
 5.874943626825653e-01, -1.671372439879485e-01,  1.698143276407778e-02,  
 5.907655121511671e-01,  4.660979703031718e-02,  1.844804672503901e-02,  
 6.025450669838789e-01,  2.467984537567849e-01,  1.677462288624064e-02,  
 6.090800603255943e-01,  4.286875996929576e-01,  1.513541325944424e-02,  
 6.258710710954998e-01,  7.165277069854407e-01,  1.099701682736415e-02,  
 6.266701063249871e-01,  5.769310800380454e-01,  1.308931762513766e-02,  
 6.270265093488953e-01, -8.955278457672096e-01,  7.880275838227896e-03,  
 6.270791988555975e-01, -7.761774347112587e-01,  1.090179865169966e-02,  
 6.345595645944537e-01, -9.984595226960734e-01,  7.958742560860689e-04,  
 6.370082702111213e-01, -9.713020953178747e-01,  4.152547195517621e-03,  
 6.401569547703443e-01,  9.938746764274359e-01,  1.693532564574805e-03,  
 6.497075309477621e-01,  8.190875365131459e-01,  4.464599165971847e-03,  
 6.531764939123219e-01,  8.722128479560702e-01,  7.098779024952168e-03,  
 6.562818147683037e-01, -4.576915030242588e-01,  1.578169238311144e-02,  
 6.591132614876472e-01,  9.562877989480233e-01,  4.990862456559823e-03,  
 6.665524280175228e-01, -6.564174347015698e-01,  1.340898468809120e-02,  
 6.700483215827622e-01, -2.620296401455633e-01,  1.661493024207803e-02,  
 6.739087687271405e-01, -5.912298687650318e-02,  1.738774404391026e-02,  
 6.804263668179958e-01,  1.460527560676405e-01,  1.628317266757141e-02,  
 6.912597270988795e-01,  3.404614930979913e-01,  1.475743069354967e-02,  
 7.014060026242689e-01, -8.344065963965686e-01,  8.628757323236287e-03,  
 7.058713078417868e-01, -9.347792116756997e-01,  5.591815013522645e-03,  
 7.079262640927377e-01,  7.724165756101982e-01,  8.029293398342626e-03,  
 7.088857312664080e-01,  4.967023279703596e-01,  1.280511610828170e-02,  
 7.101371621418650e-01,  6.457186195302522e-01,  1.105714695286113e-02,  
 7.202725263717996e-01,  9.994335364106648e-01,  3.332183106806338e-04,  
 7.207000082772794e-01, -9.895454215133570e-01,  2.196061699346258e-03,  
 7.292419930403204e-01,  9.157811426160827e-01,  6.384383783991632e-03,  
 7.313037161184995e-01, -5.505073556267344e-01,  1.356179225976500e-02,  
 7.360379569189480e-01,  9.821653512788314e-01,  2.896207033581717e-03,  
 7.420779913438207e-01, -7.334083762452253e-01,  1.091197483582354e-02,  
 7.426392282312145e-01, -3.645617372015513e-01,  1.485653149831074e-02,  
 7.528875171829301e-01, -1.601913784019904e-01,  1.550841643509901e-02,  
 7.554705394085318e-01,  4.459678870394624e-02,  1.525675110217471e-02,  
 7.615088314802664e-01,  8.361789767059251e-01,  7.437033911513647e-03,  
 7.616191329271083e-01,  2.428806469892401e-01,  1.393414245795238e-02,  
 7.690623514791849e-01, -8.832140323355561e-01,  6.416243610572680e-03,  
 7.769110395657105e-01, -9.640621745534697e-01,  3.536472011287542e-03,  
 7.791327107486173e-01,  7.076456730403544e-01,  8.608254113024549e-03,  
 7.829433189081187e-01,  4.115102550571496e-01,  1.200809373544269e-02,  
 7.868440926994443e-01,  5.651491336107541e-01,  1.060866196158618e-02,  
 7.972018338130737e-01, -9.982656120587307e-01,  6.617532655225795e-04,  
 7.992533072865277e-01,  9.540895776450939e-01,  4.268074259130473e-03,  
 7.997458930401107e-01, -6.367603626594224e-01,  1.111474927165712e-02,  
 8.081744777455525e-01,  9.960702140107771e-01,  1.017600517226123e-03,  
 8.089591973706927e-01, -4.632652606248073e-01,  1.251849428515888e-02,  
 8.099291035161289e-01, -8.014389840867161e-01,  8.342550278485161e-03,  
 8.178497193943023e-01, -2.666599682868107e-01,  1.332265855465428e-02,  
 8.217550355721945e-01,  8.852380807000872e-01,  5.823149693854945e-03,  
 8.248245538809940e-01, -5.566567666688539e-02,  1.345955258709000e-02,  
 8.273765716391087e-01,  1.453558810621134e-01,  1.259780460396138e-02,  
 8.290016229908019e-01, -9.229141926989057e-01,  4.488946673444931e-03,  
 8.312137267728380e-01,  7.737766398959207e-01,  7.517252141547089e-03,  
 8.388984040766698e-01, -9.832445987611033e-01,  1.929266776470329e-03,  
 8.403266531241620e-01,  3.204495146952222e-01,  1.029684622414818e-02,  
 8.460597215913815e-01,  6.338027356985795e-01,  8.416485697270661e-03,  
 8.568044167409157e-01,  4.819269934220108e-01,  1.007395289111620e-02,  
 8.594761322839366e-01, -7.158610827355618e-01,  8.544219655885121e-03,  
 8.596747778040242e-01,  9.812814052217911e-01,  2.240512756664986e-03,  
 8.673861033254269e-01, -5.560970888453474e-01,  9.984840676923732e-03,  
 8.687781521055384e-01, -8.598267927850410e-01,  5.909994487514023e-03,  
 8.736670048192481e-01, -3.696430123878972e-01,  1.076394694975309e-02,  
 8.755805123744724e-01,  9.286193847818732e-01,  4.104689783978988e-03,  
 8.802236992100727e-01, -1.636568935863089e-01,  1.134645488289895e-02,  
 8.818997102528549e-01, -9.534487417523689e-01,  2.910586840863237e-03,  
 8.822967422821377e-01,  8.327421092911165e-01,  5.857534910892974e-03,  
 8.855982125406932e-01,  4.859209760326954e-02,  1.081167505168916e-02,  
 8.890374543692038e-01, -9.948464939801149e-01,  8.623364516957774e-04,  
 8.910752241508448e-01,  2.326161934300192e-01,  8.657918564170076e-03,  
 8.924589745638828e-01,  7.060431740562146e-01,  7.042076085079714e-03,  
 9.038398251450660e-01,  3.788269004577886e-01,  7.187646339123819e-03,  
 9.047525315555535e-01,  9.968725405524917e-01,  6.949154523896342e-04,  
 9.073202051898728e-01,  5.601382603883635e-01,  7.436779820469599e-03,  
 9.094763644040651e-01, -7.866497708112262e-01,  6.068502473389529e-03,  
 9.156228827733042e-01, -6.431201317749281e-01,  7.377455744161945e-03,  
 9.180472655171079e-01, -9.072540984216338e-01,  3.786751966998675e-03,  
 9.201626776981597e-01, -4.661265100590501e-01,  8.127631621548038e-03,  
 9.203986204520849e-01,  9.637153195221804e-01,  2.417737344163030e-03,  
 9.253660941390490e-01, -2.716337337205402e-01,  8.801548207513724e-03,  
 9.261353319076545e-01,  8.862669995455879e-01,  4.060802203561684e-03,  
 9.267589978677341e-01, -9.763906164865308e-01,  1.670956060135679e-03,  
 9.296045895443023e-01, -5.692925807559270e-02,  8.746043891267270e-03,  
 9.333076832759312e-01,  7.750586963210155e-01,  5.218813242315273e-03,  
 9.349472019768319e-01,  1.484963626935633e-01,  7.389237501576750e-03,  
 9.374075610340270e-01,  4.399432525590961e-01,  5.306731082295346e-03,  
 9.400580998441358e-01,  2.800423571899046e-01,  2.918608608301983e-03,  
 9.427005957607336e-01, -9.981293404387946e-01,  3.121604460197559e-04,  
 9.429072476811193e-01,  6.363767343005619e-01,  5.407112479875284e-03,  
 9.493669863964902e-01, -8.473200668433625e-01,  3.846633887541680e-03,  
 9.531421892703198e-01,  9.886504733043840e-01,  1.059870260157853e-03,  
 9.531523577846154e-01, -7.227080846477228e-01,  4.913934090239149e-03,  
 9.551294253765648e-01, -5.565381013465578e-01,  5.502249381020629e-03,  
 9.565005297414140e-01, -9.442027533788165e-01,  2.096401005441424e-03,  
 9.593664858716742e-01,  3.053899240329821e-01,  4.414651034089092e-03,  
 9.596171541726947e-01,  9.321549520212439e-01,  2.376782646049461e-03,  
 9.608407654147756e-01, -3.746593104351715e-01,  6.173923907524476e-03,  
 9.621733022265412e-01, -1.656432296827873e-01,  6.194664026342116e-03,  
 9.653886055298680e-01,  5.150967645436137e-01,  4.919715066546461e-03,  
 9.657457263464734e-01,  8.382246690529398e-01,  3.337986835409403e-03,  
 9.659619334304088e-01,  5.177847935345642e-02,  5.910264564840144e-03,  
 9.680706602854513e-01, -9.879517363794693e-01,  7.458697645747395e-04,  
 9.699041735219510e-01,  7.091732174417210e-01,  3.716606593077174e-03,  
 9.780789408497448e-01, -8.978740559477660e-01,  2.027198167864543e-03,  
 9.785773409931260e-01,  3.759248114479532e-01,  2.296845005889542e-03,  
 9.787987362927277e-01, -6.363450519845599e-01,  3.147711109744902e-03,  
 9.798364272746407e-01, -7.938445879710778e-01,  2.695483313991862e-03,  
 9.808577769253177e-01,  9.991060454256292e-01,  1.898396166637044e-04,  
 9.809404950148999e-01,  2.027338094714153e-01,  3.990737313161254e-03,  
 9.816961339717497e-01,  9.686754967649751e-01,  1.091492569688088e-03,  
 9.840712745111234e-01, -2.626430872984131e-01,  3.097193509559313e-03,  
 9.843743224238546e-01, -4.750390603479636e-01,  3.584637477381167e-03,  
 9.862128026721591e-01, -9.654567087398049e-01,  8.890511587785677e-04,  
 9.863734263187778e-01, -5.930270513959802e-02,  3.688256991164665e-03,  
 9.865546785141253e-01,  6.035001549964859e-01,  3.023283764277423e-03,  
 9.869243250476414e-01,  8.947234846399443e-01,  1.668881526792388e-03,  
 9.893166095732513e-01,  7.775602858535637e-01,  2.064175704304855e-03,  
 9.894504025423468e-01,  4.193743047955185e-01,  2.246763513509927e-03,  
 9.896385884303135e-01, -9.973923443405563e-01,  1.851291041947312e-04,  
 9.901336007320924e-01, -7.114773894581000e-01,  1.034175772851253e-03,  
 9.919851856512742e-01, -3.114226899156755e-01,  1.170994569732132e-03,  
 9.940232288498372e-01,  1.283386128570500e-01,  1.603565228346927e-03,  
 9.953349820305321e-01, -8.536885202268084e-01,  1.025029596972725e-03,  
 9.959554742671337e-01, -6.783893531292533e-01,  6.259052194003695e-04,  
 9.962560319135685e-01,  9.890105787700981e-01,  2.669967855812931e-04,  
 9.964245305056454e-01, -9.302976837204511e-01,  6.033448523675142e-04,  
 9.967719421795390e-01, -5.665750992594114e-01,  1.303580233612213e-03,  
 9.972052149065609e-01,  9.417145950405990e-01,  5.101220212030444e-04,  
 9.973430748397051e-01,  2.936231135628724e-01,  1.457376036828792e-03,  
 9.977062733384420e-01,  3.661565190365799e-02,  9.783420284466598e-04,  
 9.978229005821968e-01,  6.875780893713088e-01,  9.676594371466553e-04,  
 9.978827039187840e-01, -1.661072510068121e-01,  1.283088734138761e-03,  
 9.979604058269933e-01,  5.108799809982550e-01,  1.066411053654888e-03,  
 9.980979734268004e-01, -3.916679884444568e-01,  1.034466005643900e-03,  
 9.983096397698943e-01, -7.631969332836371e-01,  5.325513292549041e-04,  
 9.985301658336433e-01,  8.440237285924725e-01,  5.771277489702493e-04,  
 9.987276765293339e-01, -9.843837655020101e-01,  1.687416201363766e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr53 ( )

/******************************************************************************/
/*
  Purpose:

    SMR53 returns the SMR rule of degree 53.

  Discussion:
 
    DEGREE: 53
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 498
    NORM INF MOMS. RESIDUAL: 8.88178e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR53[3*498], the requested rule.
*/
{
  const int degree = 53;
  int order;
  double xw[3*498] = {
 -9.985928023604709e-01,  9.844383621232889e-01,  1.770821645368481e-04,  
 -9.985845745857554e-01, -8.445726670375774e-01,  5.544684199320334e-04,  
 -9.983624118051736e-01,  7.608024429037672e-01,  5.224452130672093e-04,  
 -9.981572755902530e-01,  3.878455559966326e-01,  9.745188221536845e-04,  
 -9.979563603675163e-01,  1.627643560997576e-01,  1.227147024948174e-03,  
 -9.979346610008943e-01, -5.127640690222413e-01,  1.033714442116006e-03,  
 -9.979107729485314e-01,  6.529159127971879e-01,  3.633867657362896e-04,  
 -9.978751297025205e-01, -6.879180639452499e-01,  9.450952193083518e-04,  
 -9.974464559033922e-01, -2.966888554053162e-01,  1.397441303354461e-03,  
 -9.973454309733404e-01, -9.423377622335455e-01,  4.836806630189215e-04,  
 -9.972986691166712e-01, -2.707798066058207e-02,  8.893716616277809e-04,  
 -9.965532592866511e-01,  9.290044070830288e-01,  6.034648824689160e-04,  
 -9.964624830190837e-01,  5.570787045642487e-01,  1.303165763686854e-03,  
 -9.964167588339662e-01, -9.892036664406441e-01,  2.516135591721077e-04,  
 -9.954005028570233e-01, -1.203116337354302e-01,  1.443569885953676e-03,  
 -9.953468235808713e-01,  8.508120228627952e-01,  1.028310207063733e-03,  
 -9.933660348449341e-01,  3.161717536031352e-01,  8.387713122106447e-04,  
 -9.914304305563754e-01, -4.291601514462605e-01,  1.270285302858647e-03,  
 -9.914052559973405e-01,  7.023250519059472e-01,  1.361348704496822e-03,  
 -9.896982696240531e-01, -7.781770875290389e-01,  1.992196225105480e-03,  
 -9.891720527404116e-01,  9.974135252406250e-01,  1.922590066403422e-04,  
 -9.875040522290420e-01, -8.954189297031747e-01,  1.599426753793162e-03,  
 -9.867187183083578e-01, -6.036002868761330e-01,  2.989922308625185e-03,  
 -9.865979212862428e-01,  5.871716068212986e-02,  3.448498853249387e-03,  
 -9.861629614331282e-01,  9.648994574590848e-01,  9.190271035579097e-04,  
 -9.853079288654077e-01,  2.623064638103086e-01,  3.238657892966299e-03,  
 -9.844227148004673e-01,  4.680325982952541e-01,  3.466798907655683e-03,  
 -9.831116643490232e-01, -3.932597865155385e-01,  2.757351758467422e-03,  
 -9.826130188082844e-01, -2.018533291539324e-01,  3.940386018971356e-03,  
 -9.825204731628883e-01, -9.691072435867270e-01,  1.033098155222703e-03,  
 -9.815923254661588e-01, -9.991082969355470e-01,  1.800328977889874e-04,  
 -9.799368890832454e-01,  7.898861275347491e-01,  2.697855299373055e-03,  
 -9.789828886434943e-01,  6.301653850940090e-01,  3.120578758401599e-03,  
 -9.785540980020077e-01,  8.955915042635302e-01,  2.022068123378164e-03,  
 -9.708143762319804e-01, -7.098339240446494e-01,  3.611310052438938e-03,  
 -9.679069092640856e-01, -5.291894734981822e-02,  5.483965867735776e-03,  
 -9.669765353727785e-01, -8.388123877959717e-01,  3.240365622776667e-03,  
 -9.666680119711900e-01,  9.879489037902746e-01,  8.035625344075275e-04,  
 -9.651954595073776e-01, -5.128458551084091e-01,  5.121256639651095e-03,  
 -9.634120661314701e-01,  1.626856446045910e-01,  5.991502859241982e-03,  
 -9.617304012154808e-01,  3.684756255396696e-01,  5.961021756038116e-03,  
 -9.614256374444105e-01, -9.328771743819428e-01,  2.264842731050030e-03,  
 -9.606958049220916e-01, -3.081366550020263e-01,  5.455334451053538e-03,  
 -9.572708860210799e-01,  9.424725960383203e-01,  2.087979607175203e-03,  
 -9.558923457352529e-01,  5.499187290928166e-01,  5.368921482058166e-03,  
 -9.549989203380340e-01, -9.887724667769165e-01,  1.007773895019914e-03,  
 -9.539639220051850e-01,  7.173033838147738e-01,  4.862799620669253e-03,  
 -9.502192536056790e-01,  8.439252795287028e-01,  3.825522511161339e-03,  
 -9.443304774038754e-01, -6.368742088572625e-01,  5.273401811778445e-03,  
 -9.395231994348571e-01, -1.457862489409124e-01,  6.657538796439106e-03,  
 -9.389178998337855e-01,  9.983688364336674e-01,  3.205800161394826e-04,  
 -9.350865783178156e-01, -7.749842255798853e-01,  5.158635670181725e-03,  
 -9.343242796602114e-01, -4.294254268855136e-01,  6.109989073144874e-03,  
 -9.338088134935508e-01, -2.598456851976017e-01,  2.595536800191603e-03,  
 -9.320728477635706e-01,  5.264490338972241e-02,  8.452404593360153e-03,  
 -9.290856294325159e-01, -8.871608380321619e-01,  3.918401242147426e-03,  
 -9.273226373183119e-01,  2.659618987488091e-01,  8.495674903422557e-03,  
 -9.261329198739888e-01,  9.746027153962696e-01,  1.776302974763280e-03,  
 -9.235763538947596e-01, -9.640444233499114e-01,  2.312159206833450e-03,  
 -9.220086198065640e-01,  4.592930118785874e-01,  7.896825458118423e-03,  
 -9.202380773523146e-01,  9.050386110265841e-01,  3.683312035807689e-03,  
 -9.172703778429636e-01,  6.365672819732232e-01,  7.262815260314241e-03,  
 -9.111951012665040e-01,  7.814905098540573e-01,  6.041492892648836e-03,  
 -9.096781399489776e-01, -5.604773052603598e-01,  7.205603970066971e-03,  
 -9.087015117883152e-01, -9.969915072869269e-01,  6.470318411854381e-04,  
 -9.013251796383466e-01, -3.666844788249730e-01,  6.151586476003017e-03,  
 -8.969710028279102e-01, -2.256802214985589e-01,  7.410425347310207e-03,  
 -8.940375402275955e-01, -7.041313708313275e-01,  7.142826419236804e-03,  
 -8.895672957850502e-01, -5.293510599726065e-02,  1.040987558289029e-02,  
 -8.866199302094060e-01,  9.938258930614400e-01,  9.839665860219130e-04,  
 -8.860972589276557e-01, -8.331612020727454e-01,  5.781048219808546e-03,  
 -8.837148490953154e-01,  1.576361975891787e-01,  1.099997902023932e-02,  
 -8.811873265749205e-01,  9.497474912342982e-01,  3.085534283412631e-03,  
 -8.801258841317081e-01, -9.290747990279913e-01,  3.975614899427044e-03,  
 -8.768491423274493e-01,  3.627381824235000e-01,  1.044386961685712e-02,  
 -8.732550362347075e-01,  8.574796771270368e-01,  5.681748093343370e-03,  
 -8.702282345000577e-01,  5.484829121208596e-01,  9.793908671588478e-03,  
 -8.659273047100809e-01, -9.818377837992252e-01,  2.087386821145729e-03,  
 -8.621111168073954e-01,  7.090421883632249e-01,  8.492263963507059e-03,  
 -8.619939023548052e-01, -4.806373416483297e-01,  9.672951472047629e-03,  
 -8.480068796648080e-01, -3.119740973719929e-01,  9.321790315925496e-03,  
 -8.467158604246162e-01, -6.289407999349215e-01,  8.567266871139807e-03,  
 -8.371745526664012e-01,  9.808931214242823e-01,  2.050522723814058e-03,  
 -8.345679943920669e-01, -7.722499650445845e-01,  7.694139784998021e-03,  
 -8.333486955686686e-01, -1.495187297327515e-01,  1.195411188321836e-02,  
 -8.298817228165417e-01,  4.932544049099609e-02,  1.308861281523968e-02,  
 -8.279841059514953e-01,  9.168099196511450e-01,  4.729333631541270e-03,  
 -8.271269848617255e-01, -8.851367103086550e-01,  5.783392447697547e-03,  
 -8.226990779980473e-01,  2.594419621957182e-01,  1.295208242924248e-02,  
 -8.174915256392483e-01,  7.995012686440126e-01,  7.949359593998170e-03,  
 -8.152897321117292e-01, -9.960859909883866e-01,  9.730665170684366e-04,  
 -8.132142904625197e-01,  4.548944220943146e-01,  1.223637699266143e-02,  
 -8.087394328827582e-01, -9.556037745856076e-01,  3.933758242891774e-03,  
 -8.034618006847678e-01,  6.281857009049345e-01,  1.103532286602404e-02,  
 -8.009671113820225e-01,  9.981533390719061e-01,  6.852854862182664e-04,  
 -7.947551849888224e-01, -4.052480669355576e-01,  1.157650073560808e-02,  
 -7.898299665920954e-01, -5.577510224714766e-01,  1.013316669078794e-02,  
 -7.803754591141053e-01, -7.029689837797256e-01,  8.961843744448235e-03,  
 -7.774912262938560e-01,  9.604818908070105e-01,  3.634588036562608e-03,  
 -7.686352988370738e-01, -2.446641549937693e-01,  1.323529815530171e-02,  
 -7.677740322724570e-01,  8.743907671109992e-01,  6.716521459650556e-03,  
 -7.660500336383849e-01, -8.342336877874392e-01,  7.639362847929806e-03,  
 -7.626828581715114e-01, -5.217879939928463e-02,  1.481683281953144e-02,  
 -7.594734183304540e-01,  1.526746736533888e-01,  1.510577254629861e-02,  
 -7.533200770053481e-01,  7.322571707312160e-01,  1.036649979314898e-02,  
 -7.486275502230029e-01,  3.557473677134377e-01,  1.447118457086799e-02,  
 -7.453991512679197e-01, -9.822746950042834e-01,  2.777507829800740e-03,  
 -7.437035450232024e-01, -9.192149785074237e-01,  5.716340360168384e-03,  
 -7.360777363538358e-01,  5.402149274576373e-01,  1.345453771968750e-02,  
 -7.329540430986968e-01, -9.994520361414482e-01,  3.041538127530700e-04,  
 -7.269321822743222e-01,  9.887675638640850e-01,  2.273665309343846e-03,  
 -7.196190732492783e-01, -4.882248666799530e-01,  1.197379647349226e-02,  
 -7.140404207255062e-01, -6.371246573044332e-01,  1.070392459478854e-02,  
 -7.086337444142102e-01, -7.695704670416541e-01,  8.641963674824546e-03,  
 -7.084219401683487e-01,  9.298201384783297e-01,  5.716321197953060e-03,  
 -7.024233424547481e-01, -3.412634918186152e-01,  1.381334136967731e-02,  
 -7.000574548967922e-01,  8.225599957784430e-01,  8.956533081134005e-03,  
 -6.875688691464135e-01, -1.523532795702211e-01,  1.589039314041529e-02,  
 -6.831396553262982e-01,  5.025358955518219e-02,  1.692483716041910e-02,  
 -6.816715380174886e-01,  6.562333074021302e-01,  1.277287173246379e-02,  
 -6.782866455285573e-01,  2.534754008840426e-01,  1.602307855437726e-02,  
 -6.743483706032866e-01, -8.786507719647361e-01,  6.600160557324268e-03,  
 -6.712488971549284e-01, -9.564498500229109e-01,  4.776110132553591e-03,  
 -6.620238508003119e-01,  4.457520355368754e-01,  1.565706421137813e-02,  
 -6.547035795617938e-01, -9.940970172871774e-01,  1.595895622818180e-03,  
 -6.450215203909843e-01,  9.694287012984952e-01,  4.254123969191675e-03,  
 -6.435026336621807e-01,  9.983082528329512e-01,  8.406070876814557e-04,  
 -6.410984836103271e-01, -8.238821673751913e-01,  5.824601846420805e-03,  
 -6.379215112130751e-01, -5.670614401267176e-01,  1.233100287824145e-02,  
 -6.326491461674595e-01, -7.087147856504342e-01,  1.065338418396687e-02,  
 -6.312112678821253e-01,  8.887426834499652e-01,  8.035436464026399e-03,  
 -6.261412120185321e-01,  7.612964882114873e-01,  1.115166684172651e-02,  
 -6.218404535164949e-01, -4.260251807764488e-01,  1.409803518042624e-02,  
 -6.122357177770217e-01, -2.548990689966739e-01,  1.629549089611943e-02,  
 -6.033379016027892e-01,  5.719396137245076e-01,  1.508372611713938e-02,  
 -6.007203269774244e-01,  1.597960513238969e-01,  1.570057785252238e-02,  
 -6.002219783980102e-01, -5.403874585262955e-02,  1.797054198971408e-02,  
 -5.890404501501693e-01, -9.206940307202106e-01,  6.572394666527264e-03,  
 -5.835973374377773e-01,  3.461086614433988e-01,  1.732203682677555e-02,  
 -5.799634263647828e-01, -9.772590728941044e-01,  3.449436790328003e-03,  
 -5.625099260935547e-01, -7.778619069194846e-01,  8.878902849634178e-03,  
 -5.587300450136236e-01, -8.583430849979702e-01,  5.927281418798553e-03,  
 -5.576025578329094e-01,  9.401328137991951e-01,  6.500514236109148e-03,  
 -5.528541698467803e-01, -6.361229352805877e-01,  1.171212237998683e-02,  
 -5.519019991796891e-01,  9.890368385507939e-01,  2.732564982558912e-03,  
 -5.492720320374657e-01,  8.373014762031777e-01,  1.023676166331683e-02,  
 -5.487723900103840e-01,  6.920470750806444e-01,  1.280023752030945e-02,  
 -5.371325089697084e-01,  8.011203379709990e-02,  1.181135941584131e-02,  
 -5.343185807415033e-01, -5.029270269025070e-01,  1.396353037202522e-02,  
 -5.331665865462701e-01, -9.970597494728978e-01,  1.110041538717393e-03,  
 -5.262824452533256e-01, -3.433052927748735e-01,  1.581695407925873e-02,  
 -5.196722725049188e-01,  4.801432725924391e-01,  1.725926992286396e-02,  
 -5.157073778702320e-01, -1.609863620383591e-01,  1.879587748844137e-02,  
 -4.969937503660588e-01,  2.466042915149466e-01,  1.784450657561326e-02,  
 -4.936443037514611e-01, -9.465513055935159e-01,  5.403406971553440e-03,  
 -4.845997407738473e-01, -7.035482990021875e-01,  1.037135994169719e-02,  
 -4.758233967224794e-01,  9.499700014764531e-03,  1.501969591730733e-02,  
 -4.731977818372050e-01, -8.122514030227285e-01,  6.930386109087627e-03,  
 -4.709097305697209e-01,  6.192328037671802e-01,  1.353895520891179e-02,  
 -4.688360336456553e-01, -8.843163742148189e-01,  7.157111782324953e-03,  
 -4.681987676963164e-01,  9.000816415421663e-01,  8.752217670591854e-03,  
 -4.671044062418229e-01,  7.773382366003790e-01,  1.148882380125715e-02,  
 -4.632227635675115e-01, -9.814205193370379e-01,  2.613335253646615e-03,  
 -4.561007226835129e-01,  9.700945862732528e-01,  4.912897122852274e-03,  
 -4.519080731349339e-01,  9.984396765695470e-01,  9.104456319465278e-04,  
 -4.472892660613361e-01, -5.690445212955879e-01,  1.221020583633636e-02,  
 -4.441617460367955e-01,  3.742961592477722e-01,  1.369039678808185e-02,  
 -4.362577546949490e-01, -4.202960350604942e-01,  1.486935839319106e-02,  
 -4.218638446966653e-01, -2.592840266301589e-01,  1.805298724340071e-02,  
 -4.145077201239032e-01,  1.434465664707271e-01,  1.725622426589416e-02,  
 -4.108551792292466e-01,  7.261324870817387e-01,  4.306155002341567e-03,  
 -4.077259796016033e-01, -7.492102429229035e-01,  8.694161987156229e-03,  
 -3.994375393561766e-01, -8.413566670896548e-02,  1.767270854523918e-02,  
 -3.989722688095441e-01, -9.952608430268175e-01,  1.546205690889865e-03,  
 -3.955046992121652e-01,  5.474259893157579e-01,  1.426771157675970e-02,  
 -3.864577517310250e-01, -6.299902317618596e-01,  1.049642638160978e-02,  
 -3.849225170655068e-01,  4.169734666972951e-01,  9.724255552168744e-03,  
 -3.802442553217521e-01,  8.493133552804323e-01,  1.051968675909273e-02,  
 -3.796487515464433e-01, -9.092228699079343e-01,  6.356176322652544e-03,  
 -3.737267040247370e-01, -9.590954871481244e-01,  4.640668672343144e-03,  
 -3.680086351266054e-01,  6.979889582949302e-01,  1.081487021761422e-02,  
 -3.617280769528435e-01,  9.401480659088486e-01,  7.154768091047104e-03,  
 -3.610877408616728e-01, -8.297008620205625e-01,  9.406051770632176e-03,  
 -3.522240818473209e-01,  9.904239151356983e-01,  2.630094662997393e-03,  
 -3.486739568508627e-01,  2.706799453032748e-01,  1.790534599137358e-02,  
 -3.459056603672409e-01, -4.880157144461191e-01,  1.427913060937561e-02,  
 -3.274412213828406e-01,  2.260401457313204e-02,  1.328209466144314e-02,  
 -3.211239215007341e-01, -3.481155947386593e-01,  1.639976888297377e-02,  
 -3.164232593211551e-01, -7.429261686367324e-01,  5.976361940569912e-03,  
 -3.145433255025609e-01, -1.887048598242300e-01,  1.548218828411259e-02,  
 -3.098139879229698e-01,  1.066163988920963e-01,  1.095431624202562e-02,  
 -3.093324993446162e-01,  7.866827669318777e-01,  8.507371224954144e-03,  
 -3.012423936798629e-01, -6.693885031733898e-01,  1.126757188865965e-02,  
 -2.957526162080209e-01,  4.876169383565411e-01,  1.534619575085735e-02,  
 -2.954492755010769e-01, -9.834117127161082e-01,  3.379925266369860e-03,  
 -2.898542188079066e-01,  6.330069652325342e-01,  1.412145798182586e-02,  
 -2.722006540631997e-01, -9.272099993727561e-01,  6.281659290118641e-03,  
 -2.721846392481617e-01,  8.970549509207049e-01,  9.025150443164945e-03,  
 -2.702194513535268e-01, -8.611546877103153e-01,  7.548029223327319e-03,  
 -2.701666789762488e-01,  9.741038333559231e-01,  3.879006409933471e-03,  
 -2.633486798231064e-01, -5.531499703542735e-01,  1.398453718361448e-02,  
 -2.602577385956935e-01,  3.559789948391511e-01,  1.590809902210510e-02,  
 -2.539085167701460e-01, -9.992367354749008e-01,  7.362226870467214e-04,  
 -2.528734987524705e-01, -1.000864569130400e-01,  1.372369295593181e-02,  
 -2.418266355083030e-01,  8.155977304752622e-01,  5.639586061670630e-03,  
 -2.299925708319869e-01, -7.766849935728968e-01,  1.162319829976198e-02,  
 -2.281975753978523e-01, -2.933251049638128e-01,  1.039571151862245e-02,  
 -2.264962677001022e-01,  7.406196628504332e-01,  9.018221989261329e-03,  
 -2.254137995022369e-01,  1.945262619590385e-01,  2.032600241526465e-02,  
 -2.202097667160187e-01,  9.977429662985270e-01,  1.303069934955326e-03,  
 -2.115604600690373e-01, -4.206501628650725e-01,  1.622528102872075e-02,  
 -2.042331092646998e-01,  1.225948074751524e-02,  1.663069524482181e-02,  
 -1.950313398093114e-01,  9.390444256419040e-01,  4.129734438091659e-03,  
 -1.946536814154290e-01, -9.612563295817905e-01,  5.490013367391810e-03,  
 -1.910999388491465e-01,  5.748539496478213e-01,  1.509977429582099e-02,  
 -1.816716354061224e-01,  9.615618491387735e-01,  2.978742099030132e-03,  
 -1.726116714065732e-01, -2.174974452316975e-01,  1.590035665116296e-02,  
 -1.725147740607741e-01, -5.976020811915204e-01,  1.140314608712299e-02,  
 -1.722055467782442e-01, -6.873345735469495e-01,  1.133583684301726e-02,  
 -1.706449838302763e-01, -8.836551802782431e-01,  8.038658519121712e-03,  
 -1.679988089754341e-01,  4.388106052157863e-01,  1.571275386456942e-02,  
 -1.602837781659527e-01,  8.546895483149928e-01,  9.885073478511747e-03,  
 -1.570373933725618e-01,  6.978163142964436e-01,  1.148876151378708e-02,  
 -1.442219587876548e-01, -9.917004260484690e-01,  2.527011807500108e-03,  
 -1.276588070261918e-01,  3.027418975026165e-01,  1.880072826559714e-02,  
 -1.231008517680125e-01, -4.753879650258501e-01,  1.324596293468438e-02,  
 -1.151860373260542e-01, -8.151600041578237e-01,  1.116067302973472e-02,  
 -1.128965150592470e-01, -8.839516814078634e-02,  1.821643608834104e-02,  
 -1.123053787507008e-01,  1.095876693506785e-01,  1.978565819024786e-02,  
 -1.100537548339115e-01,  9.869592350981791e-01,  3.620908902716640e-03,  
 -9.648898098941808e-02,  9.150132212119572e-01,  7.261424197102146e-03,  
 -9.000801156431583e-02, -9.281582931717732e-01,  7.762421934834004e-03,  
 -8.755571046923658e-02, -3.265338207762313e-01,  1.966893754969280e-02,  
 -8.676802116466929e-02,  7.890938948277969e-01,  1.182634147172253e-02,  
 -7.982169502523445e-02, -7.229964637208218e-01,  8.885119945778230e-03,  
 -7.533277250983217e-02,  5.253341801281358e-01,  1.477352957389778e-02,  
 -6.228882188644439e-02,  6.470376895730875e-01,  1.366136970817887e-02,  
 -5.300829581300114e-02, -9.768027160770031e-01,  3.724202248380016e-03,  
 -5.089861416336603e-02, -5.276784631402766e-01,  1.097680016715092e-02,  
 -4.834001433988518e-02, -6.180420749231472e-01,  1.165892332494916e-02,  
 -3.421706220224403e-02,  2.365146730869494e-01,  1.410226757763090e-02,  
 -3.231589699057937e-02,  9.563884909129237e-01,  5.327701488888538e-03,  
 -3.123410684940927e-02, -1.756994941404730e-01,  1.459727035314452e-02,  
 -2.386449228293084e-02,  2.645142455623201e-02,  1.287803629578976e-02,  
 -1.944503626409501e-02,  4.054741591181015e-01,  1.890683720388499e-02,  
 -8.808200593649371e-03, -8.379258906397793e-01,  5.653566114720740e-03,  
 -3.602758322849902e-03, -7.412893889188407e-01,  9.311057693238088e-03,  
 -1.793626428337108e-03, -8.801377765241419e-01,  7.932756458617183e-03,  
 -8.655140792606699e-04, -9.978429364835631e-01,  1.282195110221903e-03,  
 8.655140792606699e-04,  9.978429364835631e-01,  1.282195110221903e-03,  
 1.793626428337108e-03,  8.801377765241419e-01,  7.932756458617183e-03,  
 3.602758322849902e-03,  7.412893889188407e-01,  9.311057693238088e-03,  
 8.808200593649371e-03,  8.379258906397793e-01,  5.653566114720740e-03,  
 1.944503626409501e-02, -4.054741591181015e-01,  1.890683720388499e-02,  
 2.386449228293084e-02, -2.645142455623201e-02,  1.287803629578976e-02,  
 3.123410684940927e-02,  1.756994941404730e-01,  1.459727035314452e-02,  
 3.231589699057937e-02, -9.563884909129237e-01,  5.327701488888538e-03,  
 3.421706220224403e-02, -2.365146730869494e-01,  1.410226757763090e-02,  
 4.834001433988518e-02,  6.180420749231472e-01,  1.165892332494916e-02,  
 5.089861416336603e-02,  5.276784631402766e-01,  1.097680016715092e-02,  
 5.300829581300114e-02,  9.768027160770031e-01,  3.724202248380016e-03,  
 6.228882188644439e-02, -6.470376895730875e-01,  1.366136970817887e-02,  
 7.533277250983217e-02, -5.253341801281358e-01,  1.477352957389778e-02,  
 7.982169502523445e-02,  7.229964637208218e-01,  8.885119945778230e-03,  
 8.676802116466929e-02, -7.890938948277969e-01,  1.182634147172253e-02,  
 8.755571046923658e-02,  3.265338207762313e-01,  1.966893754969280e-02,  
 9.000801156431583e-02,  9.281582931717732e-01,  7.762421934834004e-03,  
 9.648898098941808e-02, -9.150132212119572e-01,  7.261424197102146e-03,  
 1.100537548339115e-01, -9.869592350981791e-01,  3.620908902716640e-03,  
 1.123053787507008e-01, -1.095876693506785e-01,  1.978565819024786e-02,  
 1.128965150592470e-01,  8.839516814078634e-02,  1.821643608834104e-02,  
 1.151860373260542e-01,  8.151600041578237e-01,  1.116067302973472e-02,  
 1.231008517680125e-01,  4.753879650258501e-01,  1.324596293468438e-02,  
 1.276588070261918e-01, -3.027418975026165e-01,  1.880072826559714e-02,  
 1.442219587876548e-01,  9.917004260484690e-01,  2.527011807500108e-03,  
 1.570373933725618e-01, -6.978163142964436e-01,  1.148876151378708e-02,  
 1.602837781659527e-01, -8.546895483149928e-01,  9.885073478511747e-03,  
 1.679988089754341e-01, -4.388106052157863e-01,  1.571275386456942e-02,  
 1.706449838302763e-01,  8.836551802782431e-01,  8.038658519121712e-03,  
 1.722055467782442e-01,  6.873345735469495e-01,  1.133583684301726e-02,  
 1.725147740607741e-01,  5.976020811915204e-01,  1.140314608712299e-02,  
 1.726116714065732e-01,  2.174974452316975e-01,  1.590035665116296e-02,  
 1.816716354061224e-01, -9.615618491387735e-01,  2.978742099030132e-03,  
 1.910999388491465e-01, -5.748539496478213e-01,  1.509977429582099e-02,  
 1.946536814154290e-01,  9.612563295817905e-01,  5.490013367391810e-03,  
 1.950313398093114e-01, -9.390444256419040e-01,  4.129734438091659e-03,  
 2.042331092646998e-01, -1.225948074751524e-02,  1.663069524482181e-02,  
 2.115604600690373e-01,  4.206501628650725e-01,  1.622528102872075e-02,  
 2.202097667160187e-01, -9.977429662985270e-01,  1.303069934955326e-03,  
 2.254137995022369e-01, -1.945262619590385e-01,  2.032600241526465e-02,  
 2.264962677001022e-01, -7.406196628504332e-01,  9.018221989261329e-03,  
 2.281975753978523e-01,  2.933251049638128e-01,  1.039571151862245e-02,  
 2.299925708319869e-01,  7.766849935728968e-01,  1.162319829976198e-02,  
 2.418266355083030e-01, -8.155977304752622e-01,  5.639586061670630e-03,  
 2.528734987524705e-01,  1.000864569130400e-01,  1.372369295593181e-02,  
 2.539085167701460e-01,  9.992367354749008e-01,  7.362226870467214e-04,  
 2.602577385956935e-01, -3.559789948391511e-01,  1.590809902210510e-02,  
 2.633486798231064e-01,  5.531499703542735e-01,  1.398453718361448e-02,  
 2.701666789762488e-01, -9.741038333559231e-01,  3.879006409933471e-03,  
 2.702194513535268e-01,  8.611546877103153e-01,  7.548029223327319e-03,  
 2.721846392481617e-01, -8.970549509207049e-01,  9.025150443164945e-03,  
 2.722006540631997e-01,  9.272099993727561e-01,  6.281659290118641e-03,  
 2.898542188079066e-01, -6.330069652325342e-01,  1.412145798182586e-02,  
 2.954492755010769e-01,  9.834117127161082e-01,  3.379925266369860e-03,  
 2.957526162080209e-01, -4.876169383565411e-01,  1.534619575085735e-02,  
 3.012423936798629e-01,  6.693885031733898e-01,  1.126757188865965e-02,  
 3.093324993446162e-01, -7.866827669318777e-01,  8.507371224954144e-03,  
 3.098139879229698e-01, -1.066163988920963e-01,  1.095431624202562e-02,  
 3.145433255025609e-01,  1.887048598242300e-01,  1.548218828411259e-02,  
 3.164232593211551e-01,  7.429261686367324e-01,  5.976361940569912e-03,  
 3.211239215007341e-01,  3.481155947386593e-01,  1.639976888297377e-02,  
 3.274412213828406e-01, -2.260401457313204e-02,  1.328209466144314e-02,  
 3.459056603672409e-01,  4.880157144461191e-01,  1.427913060937561e-02,  
 3.486739568508627e-01, -2.706799453032748e-01,  1.790534599137358e-02,  
 3.522240818473209e-01, -9.904239151356983e-01,  2.630094662997393e-03,  
 3.610877408616728e-01,  8.297008620205625e-01,  9.406051770632176e-03,  
 3.617280769528435e-01, -9.401480659088486e-01,  7.154768091047104e-03,  
 3.680086351266054e-01, -6.979889582949302e-01,  1.081487021761422e-02,  
 3.737267040247370e-01,  9.590954871481244e-01,  4.640668672343144e-03,  
 3.796487515464433e-01,  9.092228699079343e-01,  6.356176322652544e-03,  
 3.802442553217521e-01, -8.493133552804323e-01,  1.051968675909273e-02,  
 3.849225170655068e-01, -4.169734666972951e-01,  9.724255552168744e-03,  
 3.864577517310250e-01,  6.299902317618596e-01,  1.049642638160978e-02,  
 3.955046992121652e-01, -5.474259893157579e-01,  1.426771157675970e-02,  
 3.989722688095441e-01,  9.952608430268175e-01,  1.546205690889865e-03,  
 3.994375393561766e-01,  8.413566670896548e-02,  1.767270854523918e-02,  
 4.077259796016033e-01,  7.492102429229035e-01,  8.694161987156229e-03,  
 4.108551792292466e-01, -7.261324870817387e-01,  4.306155002341567e-03,  
 4.145077201239032e-01, -1.434465664707271e-01,  1.725622426589416e-02,  
 4.218638446966653e-01,  2.592840266301589e-01,  1.805298724340071e-02,  
 4.362577546949490e-01,  4.202960350604942e-01,  1.486935839319106e-02,  
 4.441617460367955e-01, -3.742961592477722e-01,  1.369039678808185e-02,  
 4.472892660613361e-01,  5.690445212955879e-01,  1.221020583633636e-02,  
 4.519080731349339e-01, -9.984396765695470e-01,  9.104456319465278e-04,  
 4.561007226835129e-01, -9.700945862732528e-01,  4.912897122852274e-03,  
 4.632227635675115e-01,  9.814205193370379e-01,  2.613335253646615e-03,  
 4.671044062418229e-01, -7.773382366003790e-01,  1.148882380125715e-02,  
 4.681987676963164e-01, -9.000816415421663e-01,  8.752217670591854e-03,  
 4.688360336456553e-01,  8.843163742148189e-01,  7.157111782324953e-03,  
 4.709097305697209e-01, -6.192328037671802e-01,  1.353895520891179e-02,  
 4.731977818372050e-01,  8.122514030227285e-01,  6.930386109087627e-03,  
 4.758233967224794e-01, -9.499700014764531e-03,  1.501969591730733e-02,  
 4.845997407738473e-01,  7.035482990021875e-01,  1.037135994169719e-02,  
 4.936443037514611e-01,  9.465513055935159e-01,  5.403406971553440e-03,  
 4.969937503660588e-01, -2.466042915149466e-01,  1.784450657561326e-02,  
 5.157073778702320e-01,  1.609863620383591e-01,  1.879587748844137e-02,  
 5.196722725049188e-01, -4.801432725924391e-01,  1.725926992286396e-02,  
 5.262824452533256e-01,  3.433052927748735e-01,  1.581695407925873e-02,  
 5.331665865462701e-01,  9.970597494728978e-01,  1.110041538717393e-03,  
 5.343185807415033e-01,  5.029270269025070e-01,  1.396353037202522e-02,  
 5.371325089697084e-01, -8.011203379709990e-02,  1.181135941584131e-02,  
 5.487723900103840e-01, -6.920470750806444e-01,  1.280023752030945e-02,  
 5.492720320374657e-01, -8.373014762031777e-01,  1.023676166331683e-02,  
 5.519019991796891e-01, -9.890368385507939e-01,  2.732564982558912e-03,  
 5.528541698467803e-01,  6.361229352805877e-01,  1.171212237998683e-02,  
 5.576025578329094e-01, -9.401328137991951e-01,  6.500514236109148e-03,  
 5.587300450136236e-01,  8.583430849979702e-01,  5.927281418798553e-03,  
 5.625099260935547e-01,  7.778619069194846e-01,  8.878902849634178e-03,  
 5.799634263647828e-01,  9.772590728941044e-01,  3.449436790328003e-03,  
 5.835973374377773e-01, -3.461086614433988e-01,  1.732203682677555e-02,  
 5.890404501501693e-01,  9.206940307202106e-01,  6.572394666527264e-03,  
 6.002219783980102e-01,  5.403874585262955e-02,  1.797054198971408e-02,  
 6.007203269774244e-01, -1.597960513238969e-01,  1.570057785252238e-02,  
 6.033379016027892e-01, -5.719396137245076e-01,  1.508372611713938e-02,  
 6.122357177770217e-01,  2.548990689966739e-01,  1.629549089611943e-02,  
 6.218404535164949e-01,  4.260251807764488e-01,  1.409803518042624e-02,  
 6.261412120185321e-01, -7.612964882114873e-01,  1.115166684172651e-02,  
 6.312112678821253e-01, -8.887426834499652e-01,  8.035436464026399e-03,  
 6.326491461674595e-01,  7.087147856504342e-01,  1.065338418396687e-02,  
 6.379215112130751e-01,  5.670614401267176e-01,  1.233100287824145e-02,  
 6.410984836103271e-01,  8.238821673751913e-01,  5.824601846420805e-03,  
 6.435026336621807e-01, -9.983082528329512e-01,  8.406070876814557e-04,  
 6.450215203909843e-01, -9.694287012984952e-01,  4.254123969191675e-03,  
 6.547035795617938e-01,  9.940970172871774e-01,  1.595895622818180e-03,  
 6.620238508003119e-01, -4.457520355368754e-01,  1.565706421137813e-02,  
 6.712488971549284e-01,  9.564498500229109e-01,  4.776110132553591e-03,  
 6.743483706032866e-01,  8.786507719647361e-01,  6.600160557324268e-03,  
 6.782866455285573e-01, -2.534754008840426e-01,  1.602307855437726e-02,  
 6.816715380174886e-01, -6.562333074021302e-01,  1.277287173246379e-02,  
 6.831396553262982e-01, -5.025358955518219e-02,  1.692483716041910e-02,  
 6.875688691464135e-01,  1.523532795702211e-01,  1.589039314041529e-02,  
 7.000574548967922e-01, -8.225599957784430e-01,  8.956533081134005e-03,  
 7.024233424547481e-01,  3.412634918186152e-01,  1.381334136967731e-02,  
 7.084219401683487e-01, -9.298201384783297e-01,  5.716321197953060e-03,  
 7.086337444142102e-01,  7.695704670416541e-01,  8.641963674824546e-03,  
 7.140404207255062e-01,  6.371246573044332e-01,  1.070392459478854e-02,  
 7.196190732492783e-01,  4.882248666799530e-01,  1.197379647349226e-02,  
 7.269321822743222e-01, -9.887675638640850e-01,  2.273665309343846e-03,  
 7.329540430986968e-01,  9.994520361414482e-01,  3.041538127530700e-04,  
 7.360777363538358e-01, -5.402149274576373e-01,  1.345453771968750e-02,  
 7.437035450232024e-01,  9.192149785074237e-01,  5.716340360168384e-03,  
 7.453991512679197e-01,  9.822746950042834e-01,  2.777507829800740e-03,  
 7.486275502230029e-01, -3.557473677134377e-01,  1.447118457086799e-02,  
 7.533200770053481e-01, -7.322571707312160e-01,  1.036649979314898e-02,  
 7.594734183304540e-01, -1.526746736533888e-01,  1.510577254629861e-02,  
 7.626828581715114e-01,  5.217879939928463e-02,  1.481683281953144e-02,  
 7.660500336383849e-01,  8.342336877874392e-01,  7.639362847929806e-03,  
 7.677740322724570e-01, -8.743907671109992e-01,  6.716521459650556e-03,  
 7.686352988370738e-01,  2.446641549937693e-01,  1.323529815530171e-02,  
 7.774912262938560e-01, -9.604818908070105e-01,  3.634588036562608e-03,  
 7.803754591141053e-01,  7.029689837797256e-01,  8.961843744448235e-03,  
 7.898299665920954e-01,  5.577510224714766e-01,  1.013316669078794e-02,  
 7.947551849888224e-01,  4.052480669355576e-01,  1.157650073560808e-02,  
 8.009671113820225e-01, -9.981533390719061e-01,  6.852854862182664e-04,  
 8.034618006847678e-01, -6.281857009049345e-01,  1.103532286602404e-02,  
 8.087394328827582e-01,  9.556037745856076e-01,  3.933758242891774e-03,  
 8.132142904625197e-01, -4.548944220943146e-01,  1.223637699266143e-02,  
 8.152897321117292e-01,  9.960859909883866e-01,  9.730665170684366e-04,  
 8.174915256392483e-01, -7.995012686440126e-01,  7.949359593998170e-03,  
 8.226990779980473e-01, -2.594419621957182e-01,  1.295208242924248e-02,  
 8.271269848617255e-01,  8.851367103086550e-01,  5.783392447697547e-03,  
 8.279841059514953e-01, -9.168099196511450e-01,  4.729333631541270e-03,  
 8.298817228165417e-01, -4.932544049099609e-02,  1.308861281523968e-02,  
 8.333486955686686e-01,  1.495187297327515e-01,  1.195411188321836e-02,  
 8.345679943920669e-01,  7.722499650445845e-01,  7.694139784998021e-03,  
 8.371745526664012e-01, -9.808931214242823e-01,  2.050522723814058e-03,  
 8.467158604246162e-01,  6.289407999349215e-01,  8.567266871139807e-03,  
 8.480068796648080e-01,  3.119740973719929e-01,  9.321790315925496e-03,  
 8.619939023548052e-01,  4.806373416483297e-01,  9.672951472047629e-03,  
 8.621111168073954e-01, -7.090421883632249e-01,  8.492263963507059e-03,  
 8.659273047100809e-01,  9.818377837992252e-01,  2.087386821145729e-03,  
 8.702282345000577e-01, -5.484829121208596e-01,  9.793908671588478e-03,  
 8.732550362347075e-01, -8.574796771270368e-01,  5.681748093343370e-03,  
 8.768491423274493e-01, -3.627381824235000e-01,  1.044386961685712e-02,  
 8.801258841317081e-01,  9.290747990279913e-01,  3.975614899427044e-03,  
 8.811873265749205e-01, -9.497474912342982e-01,  3.085534283412631e-03,  
 8.837148490953154e-01, -1.576361975891787e-01,  1.099997902023932e-02,  
 8.860972589276557e-01,  8.331612020727454e-01,  5.781048219808546e-03,  
 8.866199302094060e-01, -9.938258930614400e-01,  9.839665860219130e-04,  
 8.895672957850502e-01,  5.293510599726065e-02,  1.040987558289029e-02,  
 8.940375402275955e-01,  7.041313708313275e-01,  7.142826419236804e-03,  
 8.969710028279102e-01,  2.256802214985589e-01,  7.410425347310207e-03,  
 9.013251796383466e-01,  3.666844788249730e-01,  6.151586476003017e-03,  
 9.087015117883152e-01,  9.969915072869269e-01,  6.470318411854381e-04,  
 9.096781399489776e-01,  5.604773052603598e-01,  7.205603970066971e-03,  
 9.111951012665040e-01, -7.814905098540573e-01,  6.041492892648836e-03,  
 9.172703778429636e-01, -6.365672819732232e-01,  7.262815260314241e-03,  
 9.202380773523146e-01, -9.050386110265841e-01,  3.683312035807689e-03,  
 9.220086198065640e-01, -4.592930118785874e-01,  7.896825458118423e-03,  
 9.235763538947596e-01,  9.640444233499114e-01,  2.312159206833450e-03,  
 9.261329198739888e-01, -9.746027153962696e-01,  1.776302974763280e-03,  
 9.273226373183119e-01, -2.659618987488091e-01,  8.495674903422557e-03,  
 9.290856294325159e-01,  8.871608380321619e-01,  3.918401242147426e-03,  
 9.320728477635706e-01, -5.264490338972241e-02,  8.452404593360153e-03,  
 9.338088134935508e-01,  2.598456851976017e-01,  2.595536800191603e-03,  
 9.343242796602114e-01,  4.294254268855136e-01,  6.109989073144874e-03,  
 9.350865783178156e-01,  7.749842255798853e-01,  5.158635670181725e-03,  
 9.389178998337855e-01, -9.983688364336674e-01,  3.205800161394826e-04,  
 9.395231994348571e-01,  1.457862489409124e-01,  6.657538796439106e-03,  
 9.443304774038754e-01,  6.368742088572625e-01,  5.273401811778445e-03,  
 9.502192536056790e-01, -8.439252795287028e-01,  3.825522511161339e-03,  
 9.539639220051850e-01, -7.173033838147738e-01,  4.862799620669253e-03,  
 9.549989203380340e-01,  9.887724667769165e-01,  1.007773895019914e-03,  
 9.558923457352529e-01, -5.499187290928166e-01,  5.368921482058166e-03,  
 9.572708860210799e-01, -9.424725960383203e-01,  2.087979607175203e-03,  
 9.606958049220916e-01,  3.081366550020263e-01,  5.455334451053538e-03,  
 9.614256374444105e-01,  9.328771743819428e-01,  2.264842731050030e-03,  
 9.617304012154808e-01, -3.684756255396696e-01,  5.961021756038116e-03,  
 9.634120661314701e-01, -1.626856446045910e-01,  5.991502859241982e-03,  
 9.651954595073776e-01,  5.128458551084091e-01,  5.121256639651095e-03,  
 9.666680119711900e-01, -9.879489037902746e-01,  8.035625344075275e-04,  
 9.669765353727785e-01,  8.388123877959717e-01,  3.240365622776667e-03,  
 9.679069092640856e-01,  5.291894734981822e-02,  5.483965867735776e-03,  
 9.708143762319804e-01,  7.098339240446494e-01,  3.611310052438938e-03,  
 9.785540980020077e-01, -8.955915042635302e-01,  2.022068123378164e-03,  
 9.789828886434943e-01, -6.301653850940090e-01,  3.120578758401599e-03,  
 9.799368890832454e-01, -7.898861275347491e-01,  2.697855299373055e-03,  
 9.815923254661588e-01,  9.991082969355470e-01,  1.800328977889874e-04,  
 9.825204731628883e-01,  9.691072435867270e-01,  1.033098155222703e-03,  
 9.826130188082844e-01,  2.018533291539324e-01,  3.940386018971356e-03,  
 9.831116643490232e-01,  3.932597865155385e-01,  2.757351758467422e-03,  
 9.844227148004673e-01, -4.680325982952541e-01,  3.466798907655683e-03,  
 9.853079288654077e-01, -2.623064638103086e-01,  3.238657892966299e-03,  
 9.861629614331282e-01, -9.648994574590848e-01,  9.190271035579097e-04,  
 9.865979212862428e-01, -5.871716068212986e-02,  3.448498853249387e-03,  
 9.867187183083578e-01,  6.036002868761330e-01,  2.989922308625185e-03,  
 9.875040522290420e-01,  8.954189297031747e-01,  1.599426753793162e-03,  
 9.891720527404116e-01, -9.974135252406250e-01,  1.922590066403422e-04,  
 9.896982696240531e-01,  7.781770875290389e-01,  1.992196225105480e-03,  
 9.914052559973405e-01, -7.023250519059472e-01,  1.361348704496822e-03,  
 9.914304305563754e-01,  4.291601514462605e-01,  1.270285302858647e-03,  
 9.933660348449341e-01, -3.161717536031352e-01,  8.387713122106447e-04,  
 9.953468235808713e-01, -8.508120228627952e-01,  1.028310207063733e-03,  
 9.954005028570233e-01,  1.203116337354302e-01,  1.443569885953676e-03,  
 9.964167588339662e-01,  9.892036664406441e-01,  2.516135591721077e-04,  
 9.964624830190837e-01, -5.570787045642487e-01,  1.303165763686854e-03,  
 9.965532592866511e-01, -9.290044070830288e-01,  6.034648824689160e-04,  
 9.972986691166712e-01,  2.707798066058207e-02,  8.893716616277809e-04,  
 9.973454309733404e-01,  9.423377622335455e-01,  4.836806630189215e-04,  
 9.974464559033922e-01,  2.966888554053162e-01,  1.397441303354461e-03,  
 9.978751297025205e-01,  6.879180639452499e-01,  9.450952193083518e-04,  
 9.979107729485314e-01, -6.529159127971879e-01,  3.633867657362896e-04,  
 9.979346610008943e-01,  5.127640690222413e-01,  1.033714442116006e-03,  
 9.979563603675163e-01, -1.627643560997576e-01,  1.227147024948174e-03,  
 9.981572755902530e-01, -3.878455559966326e-01,  9.745188221536845e-04,  
 9.983624118051736e-01, -7.608024429037672e-01,  5.224452130672093e-04,  
 9.985845745857554e-01,  8.445726670375774e-01,  5.544684199320334e-04,  
 9.985928023604709e-01, -9.844383621232889e-01,  1.770821645368481e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr54 ( )

/******************************************************************************/
/*
  Purpose:

    SMR54 returns the SMR rule of degree 54.

  Discussion:
 
    DEGREE: 54
    POINTS CARDINALITY: 530
    NORM INF MOMS. RESIDUAL: 5.39824e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR54[3*530], the requested rule.
*/
{
  const int degree = 54;
  int order;
  double xw[3*530] = {
 -9.989817717908982e-01,  5.919272627455578e-01,  4.192164731453299e-04,  
 -9.987404572465737e-01,  1.308084790329531e-01,  1.021852171532156e-03,  
 -9.986234267784356e-01, -4.263738548438438e-01,  8.092096026376365e-04,  
 -9.981931054807527e-01,  3.646305906433953e-01,  9.508207239229283e-04,  
 -9.981856973324568e-01,  7.272619710460589e-01,  6.106524315481551e-04,  
 -9.980709749587124e-01, -6.001863748613854e-01,  8.126915872357096e-04,  
 -9.980413923840483e-01, -8.914269607610811e-01,  4.682310231840477e-04,  
 -9.979705384624564e-01, -7.412992362417765e-01,  7.151087866573973e-04,  
 -9.978690979638140e-01,  9.663123578468790e-01,  3.202153175837222e-04,  
 -9.977258243819628e-01, -9.652827050987313e-01,  3.283439367940058e-04,  
 -9.971716111831748e-01, -9.974268956785031e-01,  8.241300038356087e-05,
 -9.970352418855494e-01,  9.974255320425583e-01,  8.212998926647490e-05,
 -9.969224314551484e-01, -9.393125488685919e-02,  1.504803327632492e-03,  
 -9.960677559421486e-01, -2.647274988430133e-01,  1.572549858547515e-03,  
 -9.960215426387498e-01,  8.267393820611655e-01,  9.559033420839447e-04,  
 -9.948684167675756e-01,  9.071416133542933e-01,  8.949139768864249e-04,  
 -9.947720129850103e-01,  5.104011858905396e-01,  1.494625194595164e-03,  
 -9.928183610027883e-01, -8.240968026714828e-01,  1.339991144849752e-03,  
 -9.913254503184387e-01,  2.674834631813928e-01,  2.106476272485075e-03,  
 -9.904625945177303e-01,  6.584559213904446e-01,  1.813259044357879e-03,  
 -9.890383005625215e-01, -5.149553957207894e-01,  2.455252158291572e-03,  
 -9.881194568841846e-01,  2.614827265266613e-02,  3.325719901930421e-03,  
 -9.879408478281920e-01, -9.291292547818254e-01,  1.147091172840035e-03,  
 -9.875251490473347e-01, -6.727745764892368e-01,  2.262078818748468e-03,  
 -9.858527951227277e-01, -9.864963721615293e-01,  5.725658200176546e-04,  
 -9.854338631227043e-01,  9.874105156506667e-01,  5.586886490640081e-04,  
 -9.852263671099249e-01, -3.625385392177216e-01,  2.857661335439080e-03,  
 -9.825593639450432e-01,  1.995031163134125e-01,  2.367547927531011e-03,  
 -9.824114240376021e-01,  4.281675290505715e-01,  3.355872483204902e-03,  
 -9.817256672127911e-01,  7.647122894159171e-01,  2.575116468351886e-03,  
 -9.805318040753007e-01, -1.804457704525198e-01,  4.118289237515360e-03,  
 -9.805039503463728e-01,  9.466567028850934e-01,  1.325628488583474e-03,  
 -9.756665239670562e-01,  8.635894110547788e-01,  2.435706692004165e-03,  
 -9.752755423873182e-01,  5.832180325449532e-01,  3.514659543525947e-03,  
 -9.750402397814284e-01, -7.646880569660038e-01,  2.888748522483849e-03,  
 -9.735468564559212e-01, -8.717051891324532e-01,  2.366889660470246e-03,  
 -9.679592288793518e-01, -5.935816838222202e-01,  3.995306431519523e-03,  
 -9.677571838023695e-01, -9.595967788974593e-01,  1.428616809901578e-03,  
 -9.658639079002952e-01, -4.432770743101457e-01,  3.839496537131441e-03,  
 -9.650415941859795e-01,  1.236248887610379e-01,  4.840226470267086e-03,  
 -9.631290872983891e-01, -5.876034750881315e-02,  5.470783159765819e-03,  
 -9.631034141806328e-01, -9.976850977314620e-01,  3.419776280288853e-04,  
 -9.625553199946670e-01,  3.295323982859324e-01,  5.459065077538461e-03,  
 -9.612827522133878e-01,  9.981364356409019e-01,  3.166348923351850e-04,  
 -9.580877877056461e-01, -2.969810053181347e-01,  5.220897083430127e-03,  
 -9.571485087500350e-01,  6.922808060935507e-01,  4.586679952432644e-03,  
 -9.535301324509948e-01,  9.746155590088402e-01,  1.418913803798055e-03,  
 -9.524379004857232e-01,  9.162146344965918e-01,  2.407729567382604e-03,  
 -9.505895051965978e-01,  5.014963263274375e-01,  5.575945233813663e-03,  
 -9.478749822163210e-01, -6.944812783499223e-01,  4.655155635074236e-03,  
 -9.455021911300354e-01,  8.056725087594965e-01,  4.359359472393902e-03,  
 -9.447465384828663e-01, -9.154409664580865e-01,  2.795239997076277e-03,  
 -9.433146066792609e-01, -8.168805299510518e-01,  4.028643084029805e-03,  
 -9.387233616656319e-01, -5.109006904129239e-01,  4.894958084076135e-03,  
 -9.384629482238540e-01, -9.818626877894082e-01,  1.310428168181814e-03,  
 -9.381114810015984e-01,  2.185836698314924e-01,  4.884732944819899e-03,  
 -9.358560535321955e-01, -2.315428002863897e-01,  3.316562519259470e-03,  
 -9.308010611209707e-01, -1.424231144558627e-01,  5.747390039768777e-03,  
 -9.297630644633869e-01,  4.416527314167950e-02,  7.517898257378467e-03,  
 -9.233227723178385e-01,  4.023719757646702e-01,  5.284707530975812e-03,  
 -9.224542858756197e-01,  6.127728993680069e-01,  6.776489078687089e-03,  
 -9.196650460217998e-01, -3.918897734223120e-01,  7.307992712751874e-03,  
 -9.194831397810722e-01,  8.782442449140750e-01,  3.380706025809833e-03,  
 -9.150738342453455e-01,  2.565854509614714e-01,  4.607153630685746e-03,  
 -9.145318414055876e-01, -6.141747725191304e-01,  6.046283805446541e-03,  
 -9.139502328154178e-01,  9.519560268303220e-01,  2.502572477084220e-03,  
 -9.134793665954337e-01,  9.919095371825775e-01,  1.124626818044628e-03,  
 -9.060090402237246e-01, -9.506888110190086e-01,  2.778798298294591e-03,  
 -9.053928987959834e-01,  4.255816005703235e-01,  3.224317780033523e-03,  
 -9.044639609806726e-01,  7.378720657330040e-01,  6.636831081783288e-03,  
 -9.041783402072592e-01, -8.694205435587335e-01,  4.455650498659537e-03,  
 -9.040300328146645e-01, -7.515160741939899e-01,  5.918295079633594e-03,  
 -9.017899755155315e-01, -9.954102906217157e-01,  7.928254709759700e-04,  
 -8.897004636163042e-01, -2.191520488598997e-01,  5.655997887446038e-03,  
 -8.877453802381129e-01, -5.477593167943130e-02,  9.196179323015951e-03,  
 -8.840808803351360e-01,  1.391072028749891e-01,  9.640533450227940e-03,  
 -8.828518434418928e-01, -3.121002666602964e-01,  6.236556130589060e-03,  
 -8.818476420260746e-01,  8.364954439794862e-01,  4.678268202212999e-03,  
 -8.816605510809139e-01, -5.252727670887154e-01,  6.613415579576893e-03,  
 -8.785653704569504e-01,  5.278061262141955e-01,  8.847143039918376e-03,  
 -8.699871131424373e-01,  9.213357639099106e-01,  3.632006018382626e-03,  
 -8.683297949701945e-01,  3.231905589440098e-01,  9.593963354545314e-03,  
 -8.604990767543338e-01, -6.723649810540170e-01,  7.844257742747529e-03,  
 -8.592897950466277e-01,  9.761958158048712e-01,  2.408602549499724e-03,  
 -8.585649827583716e-01, -9.769138516545594e-01,  2.321654990097349e-03,  
 -8.555827158290819e-01, -4.472850328113563e-01,  7.381515678371422e-03,  
 -8.554969798794826e-01, -9.140049134243882e-01,  4.445756671413822e-03,  
 -8.549727674964507e-01, -8.129934326041193e-01,  6.375752094967673e-03,  
 -8.537907187771469e-01,  9.988992207578934e-01,  4.358179382894343e-04,  
 -8.531681357690770e-01,  6.611164416907961e-01,  9.119660780491236e-03,  
 -8.350636199588630e-01,  7.852767143246269e-01,  6.889525487372896e-03,  
 -8.349595897816755e-01, -1.520071332967412e-01,  1.065179565209894e-02,  
 -8.320657289288327e-01,  3.716906860716102e-02,  1.146602495213217e-02,  
 -8.268341463810431e-01, -2.968395593787465e-01,  6.862218866630454e-03,  
 -8.246596591114025e-01, -9.965096629638894e-01,  8.191929500848176e-04,  
 -8.245747953184245e-01,  4.399187035083351e-01,  1.074447207779778e-02,  
 -8.205544234046400e-01,  8.852149825875817e-01,  5.035650441337556e-03,  
 -8.201077685552812e-01,  2.167941468653240e-01,  1.120664310470067e-02,  
 -8.133180823505128e-01, -5.827868689492453e-01,  1.020050720602399e-02,  
 -8.039514840518650e-01, -3.887612693005317e-01,  8.156471508075192e-03,  
 -8.020182152432404e-01, -7.434295570675248e-01,  8.516722515686231e-03,  
 -7.993113635576975e-01,  9.508317269117940e-01,  3.951550791219958e-03,  
 -7.977917653551984e-01, -9.498027641226449e-01,  4.046020691573701e-03,  
 -7.966018517884945e-01, -8.670707527670807e-01,  6.396726072271494e-03,  
 -7.931825421678735e-01,  5.760232971144895e-01,  1.150512626594489e-02,  
 -7.926266834000572e-01,  9.921891129165684e-01,  1.367686056645448e-03,  
 -7.771396199978947e-01,  7.224416691496910e-01,  9.346300134052963e-03,  
 -7.734124506696661e-01,  3.227290869794067e-01,  8.975472976200140e-03,  
 -7.703196567703094e-01, -6.166649668685752e-02,  1.296602865392240e-02,  
 -7.639145055393257e-01, -9.849091728353774e-01,  2.189782887003045e-03,  
 -7.629322821804013e-01,  8.407308321500763e-01,  7.120214624978285e-03,  
 -7.626926298628909e-01, -2.351311412555938e-01,  1.196574993978526e-02,  
 -7.595961758924654e-01, -4.888664940264281e-01,  1.136013589405564e-02,  
 -7.583264577383526e-01,  1.203418784123442e-01,  1.319999781535264e-02,  
 -7.534370979577448e-01,  3.876976391386210e-01,  5.897710869634649e-03,  
 -7.446105000480632e-01, -6.652463657026361e-01,  1.063122807861948e-02,  
 -7.403189886112194e-01,  9.802339164748645e-01,  2.050796688775679e-03,  
 -7.335598541855958e-01, -8.081850052797745e-01,  8.660179094542753e-03,  
 -7.323073282715993e-01,  9.179212596057432e-01,  5.596503741402021e-03,  
 -7.283214984315893e-01, -9.121288534905104e-01,  6.106288648057536e-03,  
 -7.205165128910833e-01,  4.912094353971421e-01,  1.322119178401210e-02,  
 -7.202928498310126e-01, -9.987309089969828e-01,  5.258054963828562e-04,  
 -7.140760443768659e-01, -3.530100176005496e-01,  1.329784234525705e-02,  
 -7.124579482134324e-01,  6.494569766773742e-01,  1.132420139371352e-02,  
 -7.046398991051476e-01,  2.461557767190701e-01,  1.316382807437570e-02,  
 -6.965139599435282e-01,  9.980269396597710e-01,  8.468443147483151e-04,  
 -6.955976699513159e-01,  7.858134610190387e-01,  9.483582940511751e-03,  
 -6.933698254139239e-01, -9.638333240537718e-01,  3.924272626110384e-03,  
 -6.916049886292619e-01, -1.473824067364324e-01,  1.379946652263615e-02,  
 -6.900647649939231e-01, -5.756250123370613e-01,  1.131366317435485e-02,  
 -6.896395099305572e-01,  2.450716766496345e-02,  1.433783710214306e-02,  
 -6.791067170899857e-01,  9.629073491101878e-01,  3.765624216430676e-03,  
 -6.665583661377872e-01, -7.396479470660201e-01,  1.078002527678657e-02,  
 -6.617665117353752e-01,  8.782682043901964e-01,  7.160836419170941e-03,  
 -6.547645869221170e-01, -4.567828647957672e-01,  1.235987868867504e-02,  
 -6.534762438686446e-01, -8.630076300534779e-01,  8.538047957473528e-03,  
 -6.520027037508170e-01,  3.735882243699723e-01,  1.516020774574135e-02,  
 -6.517784533911791e-01, -9.917908605039587e-01,  1.649695282763077e-03,  
 -6.392095883446625e-01,  5.800402186061466e-01,  1.161152099493760e-02,  
 -6.376246103269898e-01,  1.586423655659965e-01,  1.380903763545163e-02,  
 -6.327846798140507e-01, -2.616795092165446e-01,  1.537715962316561e-02,  
 -6.240350274451502e-01,  7.202357912728578e-01,  1.128423081027187e-02,  
 -6.149539141562774e-01, -9.331114005968212e-01,  5.973942783567584e-03,  
 -6.122194846749883e-01, -6.515331165545560e-01,  1.111044461856676e-02,  
 -6.109552256753611e-01,  9.882437872281699e-01,  2.667119864257815e-03,  
 -6.075850901806646e-01, -6.310115283305893e-02,  1.462210878363727e-02,  
 -6.072861502023867e-01,  4.905670021193503e-01,  8.470043747920344e-03,  
 -6.015220267548393e-01,  9.349603376928803e-01,  6.061794422141538e-03,  
 -5.905725005438208e-01,  8.331968654144224e-01,  8.330672895641352e-03,  
 -5.805512578578408e-01, -9.781724160170889e-01,  3.002089846665531e-03,  
 -5.766322657231936e-01, -8.019456106219724e-01,  1.071573135474418e-02,  
 -5.758873833179518e-01, -3.797930059724561e-01,  1.410780437411866e-02,  
 -5.758044628531556e-01, -5.431666836509476e-01,  1.250321425804641e-02,  
 -5.701897881977539e-01,  7.196089886371619e-02,  1.340015602318261e-02,  
 -5.675904138396737e-01,  2.751253062951665e-01,  1.737410839787904e-02,  
 -5.553792678938588e-01, -9.985017652958537e-01,  7.085987040688918e-04,  
 -5.456087648129923e-01,  6.599941556879438e-01,  1.081777781980287e-02,  
 -5.428550764673452e-01, -1.681164911727584e-01,  1.620487411044344e-02,  
 -5.392986597197948e-01,  4.382461398474867e-01,  1.322051456706655e-02,  
 -5.333581011400846e-01, -8.924070574982715e-01,  8.096515253402553e-03,  
 -5.293207101815004e-01, -7.129696889928183e-01,  1.046695608551654e-02,  
 -5.290868756599331e-01,  7.840020586708457e-01,  8.165858398272986e-03,  
 -5.276014126395560e-01,  5.734029485384756e-01,  8.947303079726300e-03,  
 -5.208347199729565e-01,  9.983223158535289e-01,  9.204125169539234e-04,  
 -5.167452045861149e-01,  9.688882331602159e-01,  4.810895911417227e-03,  
 -5.152624846429958e-01,  8.963754564805726e-01,  8.321128511156680e-03,  
 -5.002251071203062e-01, -9.570565024360769e-01,  4.944271560105734e-03,  
 -4.932266910589403e-01, -4.711107586002372e-01,  1.392484590851878e-02,  
 -4.921580787739357e-01, -2.932163995933711e-01,  1.583029572106085e-02,  
 -4.879008547264502e-01, -6.201644318968081e-03,  1.496619326816272e-02,  
 -4.852163690035972e-01,  1.624165605662743e-01,  1.717478193204391e-02,  
 -4.823665194042128e-01, -6.169799586006250e-01,  1.293927977760325e-02,  
 -4.703674730266642e-01, -9.914498714302058e-01,  2.012990135531071e-03,  
 -4.636605522134049e-01,  3.574499996088237e-01,  1.446178985104287e-02,  
 -4.635626709780222e-01, -8.379512800964518e-01,  8.670390056290013e-03,  
 -4.616882999336276e-01,  7.441874849999627e-01,  9.278333622213229e-03,  
 -4.428826220830571e-01,  5.242412903345882e-01,  1.401423158385144e-02,  
 -4.375574474750148e-01, -7.560923913938994e-01,  1.060832188420960e-02,  
 -4.373507999119863e-01,  2.790611242916685e-01,  5.124081896234384e-03,  
 -4.360016080614369e-01, -9.911845198571319e-02,  1.336294282347855e-02,  
 -4.318212671580576e-01,  6.490625104897801e-01,  1.048403694888664e-02,  
 -4.312768828083386e-01,  8.458926838617457e-01,  1.005241229734938e-02,  
 -4.195936220368654e-01,  9.896332053755005e-01,  2.832340745872356e-03,  
 -4.195035071205845e-01,  9.391789505533757e-01,  7.087287993156248e-03,  
 -4.158372945781164e-01, -9.247166955115301e-01,  7.200678481835746e-03,  
 -4.082322252181940e-01, -3.895067692217146e-01,  1.571591993987856e-02,  
 -3.945619771869534e-01, -2.102382908787201e-01,  1.645442705259772e-02,  
 -3.927191939155762e-01, -5.456985704133576e-01,  1.387951318062375e-02,  
 -3.871818805737522e-01, -9.785560486250816e-01,  3.357590491647819e-03,  
 -3.777405489965089e-01,  2.271876155103771e-01,  1.464444862096865e-02,  
 -3.759119908505304e-01,  6.749055163565303e-02,  1.970543400262736e-02,  
 -3.723355165014207e-01, -6.701266603185027e-01,  1.262000893299485e-02,  
 -3.676289846847610e-01, -8.661368970945535e-01,  7.011405339219392e-03,  
 -3.664037660595558e-01,  4.496056266935061e-01,  1.177520117108604e-02,  
 -3.644175466900805e-01, -9.988404483094074e-01,  6.861446217182368e-04,  
 -3.612218369591753e-01,  7.139281737711283e-01,  8.660409393382987e-03,  
 -3.533163408214845e-01,  3.703602260250929e-01,  7.687812735908846e-03,  
 -3.390251629862523e-01,  7.979819236131581e-01,  1.008487673748482e-02,  
 -3.345649108519196e-01,  9.723276852657335e-01,  2.678299050653827e-03,  
 -3.293646261299018e-01,  5.938175713548932e-01,  1.490674822227216e-02,  
 -3.289203518655379e-01,  8.957126445136651e-01,  8.989588878027095e-03,  
 -3.243047057088739e-01, -7.936980547794279e-01,  1.075979049243002e-02,  
 -3.129605000582947e-01, -6.643571783650405e-02,  1.856839158447809e-02,  
 -3.117073855253361e-01, -3.093183812990403e-01,  1.656632086288442e-02,  
 -3.072762353389070e-01, -9.564548826763054e-01,  5.369964649875180e-03,  
 -3.061436378051206e-01, -4.704135840359435e-01,  1.475623099958883e-02,  
 -3.021913077128562e-01,  9.981390270674768e-01,  1.131666739617315e-03,  
 -2.949530243768917e-01,  9.686835034877084e-01,  2.797024137967235e-03,  
 -2.924635827539191e-01, -7.047858510122733e-01,  6.851571387118350e-03,  
 -2.812350771273387e-01, -8.980684313341059e-01,  7.363138635454566e-03,  
 -2.806273605262599e-01,  3.029645468518594e-01,  1.520110596476129e-02,  
 -2.745982375561375e-01, -9.934986711091262e-01,  1.673742994343650e-03,  
 -2.710331296874568e-01,  4.652469064012115e-01,  1.090810494083061e-02,  
 -2.635463086619279e-01,  1.586055674415278e-01,  1.746954739472360e-02,  
 -2.625382248376168e-01, -5.932891429782097e-01,  1.529823413526504e-02,  
 -2.590525077776922e-01, -1.823032100069667e-01,  1.460011251776361e-02,  
 -2.581989912968990e-01,  6.927205540494286e-01,  1.020066380845207e-02,  
 -2.411331427499952e-01,  9.344875760714670e-01,  5.158877832261257e-03,  
 -2.406223697257603e-01,  7.735613151103899e-01,  6.930533482154789e-03,  
 -2.306207507959519e-01,  4.834271168445705e-02,  1.167695287885717e-02,  
 -2.256547660822549e-01, -8.303251302805508e-01,  5.969813944396011e-03,  
 -2.233405416434596e-01,  8.513588948939629e-01,  1.041708126169881e-02,  
 -2.200209241310239e-01,  5.418414720955490e-01,  1.204616875868074e-02,  
 -2.140824323336795e-01, -3.999817827003599e-01,  1.469205327663902e-02,  
 -2.099887189967384e-01, -7.385652177919024e-01,  1.102272008220242e-02,  
 -2.055981693756977e-01, -9.815381529846507e-01,  3.208405941212317e-03,  
 -1.907642188897441e-01,  9.883341858044101e-01,  3.400965087265759e-03,  
 -1.897223918835828e-01, -9.336864994968639e-01,  6.598813190376643e-03,  
 -1.856872749545497e-01,  3.807518860810150e-01,  1.626600502334043e-02,  
 -1.856560896180115e-01,  6.458143580207676e-01,  9.595353199870314e-03,  
 -1.771535862151187e-01, -8.502150916777047e-01,  6.882856119388930e-03,  
 -1.761506840632638e-01, -2.849688737894649e-01,  1.376397443479240e-02,  
 -1.760694512771735e-01,  9.487132134491084e-01,  3.463137052103194e-03,  
 -1.759090616673586e-01, -1.668583040865908e-02,  1.494943461671058e-02,  
 -1.743545387314084e-01, -6.480592314695985e-01,  8.068616752476498e-03,  
 -1.646646667032431e-01, -1.549382245795711e-01,  1.229946774808041e-02,  
 -1.564278540839040e-01, -5.099794466889294e-01,  1.583679910644951e-02,  
 -1.476250668191063e-01,  2.508400888737863e-01,  1.598240477070294e-02,  
 -1.378533885088872e-01,  7.470167466939204e-01,  1.025090566987707e-02,  
 -1.339102361885577e-01,  1.587463638591125e-01,  1.042002071483287e-02,  
 -1.253458474656329e-01,  9.016084675302966e-01,  8.382092697242076e-03,  
 -1.242718966113707e-01, -9.975311977305669e-01,  1.307493707247085e-03,  
 -1.149177253012365e-01,  5.015141775843105e-01,  1.335216066856519e-02,  
 -1.062013123816681e-01,  8.113862649434280e-01,  8.240179055283665e-03,  
 -1.005242315957304e-01, -6.768307306217036e-01,  9.892753624061720e-03,  
 -9.910296904870308e-02, -9.655033098878887e-01,  4.971432564142077e-03,  
 -9.822456345521705e-02,  6.182616980114717e-01,  1.154982585129897e-02,  
 -9.094894553724515e-02, -7.832264404807726e-01,  1.272153770310018e-02,  
 -8.951973571157114e-02, -8.934469335864712e-01,  9.040121806196625e-03,  
 -8.864913498943343e-02, -5.752029154809029e-01,  7.696987946647426e-03,  
 -7.813610453536655e-02, -3.824731713047965e-01,  1.595389785417394e-02,  
 -7.808279619773810e-02,  9.678657629328651e-01,  5.348961931934154e-03,  
 -7.518429220875299e-02, -9.501265478490149e-02,  1.603342783311217e-02,  
 -7.256720788480295e-02,  9.980188020733000e-01,  1.239829395370563e-03,  
 -7.160051871827056e-02,  7.964916268348117e-02,  1.747639962808621e-02,  
 -6.658775866489877e-02, -2.544806391357054e-01,  1.439738622078677e-02,  
 -5.912591896874869e-02,  4.086931280855817e-01,  1.434397636411426e-02,  
 -3.003234825592526e-02,  8.585057270530800e-01,  8.172528647752865e-03,  
 -2.645953523971930e-02,  7.046260937171298e-01,  1.344291776488621e-02,  
 -2.534886371863461e-02,  2.933719416861227e-01,  1.759197717607860e-02,  
 -1.323065725566219e-02, -4.759685548931392e-01,  1.437852891867941e-02,  
 -1.108857312313384e-02, -6.086185473503245e-01,  1.096431541959337e-02,  
 -9.767336568716133e-03, -9.880188324263295e-01,  3.240769608183762e-03,  
 2.472574608889389e-03,  9.298777848313345e-01,  7.408272240383237e-03,  
 3.476131508526145e-03,  5.622804755214021e-01,  1.417273440946883e-02,  
 5.102825364173400e-03, -9.360854000426274e-01,  7.306890259002694e-03,  
 7.481806578463433e-03, -4.304909728461822e-03,  9.644021597489717e-03,  
 1.083187044442501e-02, -8.405067439387872e-01,  1.139227327264933e-02,  
 2.078810983363222e-02, -7.184977995593806e-01,  1.419275964745119e-02,  
 2.352332931112040e-02, -1.777262641278441e-01,  1.513652886721543e-02,  
 2.605792957621816e-02,  1.714141618252540e-01,  1.746784365412643e-02,  
 3.419270449758923e-02,  7.926923352194076e-01,  1.114588247114633e-02,  
 3.689227013453180e-02,  9.869329842141271e-01,  3.587800597955966e-03,  
 5.231331279344743e-02, -2.983724214658152e-01,  1.282800566620749e-02,  
 5.333417882238150e-02, -3.150790865005272e-02,  1.067689529371097e-02,  
 5.515446270123405e-02,  4.640348051148255e-01,  1.483471286370125e-02,  
 7.326926690316637e-02, -3.859166123826371e-01,  1.317399038328787e-02,  
 7.896436713254719e-02,  6.515068803712124e-01,  1.175778018467305e-02,  
 8.106589543358063e-02, -5.455789831489050e-01,  1.257961431518928e-02,  
 9.143189128962997e-02,  8.849636002129454e-01,  7.995804990083446e-03,  
 9.183620472220967e-02, -9.982620877010548e-01,  1.071611175557207e-03,  
 1.020899734795291e-01, -9.680677235297332e-01,  5.359511511849509e-03,  
 1.032064648808839e-01,  3.508166883429220e-01,  1.821445820076782e-02,  
 1.055465484669112e-01, -8.936553035854308e-01,  9.364571370580868e-03,  
 1.116319040200762e-01,  9.569683551028125e-01,  5.799167128957759e-03,  
 1.184093061912173e-01,  6.460797547191485e-02,  1.538648042988892e-02,  
 1.211496833043070e-01, -7.832288499871760e-01,  1.305125306673873e-02,  
 1.222296761980543e-01, -6.414978463247534e-01,  1.274307450341386e-02,  
 1.268780973858983e-01,  2.124489885142361e-01,  1.303843019488049e-02,  
 1.334028983920185e-01,  7.430849024557798e-01,  1.170710723942358e-02,  
 1.377561712790752e-01, -1.149141127497300e-01,  1.518998754371716e-02,  
 1.443645551391211e-01,  5.914798921541217e-01,  9.267995494968094e-03,  
 1.464713397158526e-01,  9.975108317870389e-01,  1.344221020630127e-03,  
 1.471243438702994e-01,  8.406549255746518e-01,  6.868706503673577e-03,  
 1.539021244046412e-01, -2.177903033576761e-01,  1.189096266115889e-02,  
 1.645948745810365e-01, -4.622499482006776e-01,  1.598264890363537e-02,  
 1.737606299255193e-01,  5.108712579502437e-01,  1.343700851176021e-02,  
 1.960337529226180e-01, -3.160892037041645e-01,  1.517528874189867e-02,  
 1.996879640965994e-01, -6.932804184761608e-01,  1.065797263441093e-02,  
 2.020074577970664e-01, -9.886491220693521e-01,  3.111072986126015e-03,  
 2.033963003224787e-01, -9.351529309857213e-01,  7.383713855162398e-03,  
 2.050316445884164e-01,  9.183031846509473e-01,  7.915254944655616e-03,  
 2.133741088627701e-01, -8.457977005703088e-01,  1.089663499513872e-02,  
 2.141494782415598e-01,  9.779765604905496e-01,  4.137849906961731e-03,  
 2.177197497330517e-01,  2.653968084572469e-01,  1.606441497945596e-02,  
 2.182669785207582e-01,  1.002641349031797e-01,  1.470303701111106e-02,  
 2.208729153200149e-01, -3.179321251109352e-02,  1.319786624286162e-02,  
 2.223340049334479e-01,  6.699405548173695e-01,  1.117930035973834e-02,  
 2.292846440205571e-01,  4.151794226086859e-01,  1.606327398417143e-02,  
 2.309770714797946e-01,  8.143538927981072e-01,  8.974695973354508e-03,  
 2.394458713565459e-01, -5.651074560068458e-01,  1.649544265573178e-02,  
 2.617303912242682e-01,  7.450665189174808e-01,  6.665865551621909e-03,  
 2.691992761760191e-01, -7.480558691506524e-01,  1.062817914743759e-02,  
 2.801184378515139e-01, -8.648253256664529e-02,  1.029103279941478e-02,  
 2.802549482883130e-01, -3.882923892722029e-01,  1.369193939295842e-02,  
 2.839000603830919e-01, -2.046740542904322e-01,  1.736776423460412e-02,  
 2.887898581531176e-01,  5.814667573861627e-01,  1.465252164582414e-02,  
 2.943230313566177e-01,  8.763787360351365e-01,  7.624320350783295e-03,  
 2.984713532756781e-01, -9.662504924043853e-01,  5.098404762337242e-03,  
 3.006596174432872e-01,  9.936320220137688e-01,  2.068083074134366e-03,  
 3.050565768027433e-01, -9.982304187004531e-01,  1.009394886038144e-03,  
 3.085263100239341e-01, -7.996443277472217e-01,  3.534840513865065e-03,  
 3.116498242262688e-01, -8.955597721317096e-01,  9.093317546816406e-03,  
 3.117692757107713e-01,  1.675250048357164e-01,  1.698233278167723e-02,  
 3.159624611068410e-01,  9.489971508109396e-01,  6.529106763034471e-03,  
 3.197420491834217e-01, -4.656026992118575e-01,  1.003556952514073e-02,  
 3.267298270221274e-01,  3.348095746744744e-01,  1.595497306519906e-02,  
 3.309355307192962e-01,  7.014929727551507e-01,  6.957256742470056e-03,  
 3.342067700349441e-01, -6.419472908347359e-01,  1.483566807534002e-02,  
 3.430031057615673e-01,  4.809677053778840e-01,  1.448748066501445e-02,  
 3.497052562336275e-01,  1.998383478506136e-02,  1.800443798157775e-02,  
 3.644044878216754e-01,  7.810190581938899e-01,  1.024800809296951e-02,  
 3.661215757514518e-01,  8.526602936761131e-01,  4.944710357542757e-03,  
 3.672978740253939e-01, -8.151652782533108e-01,  8.850306571457656e-03,  
 3.728404816069009e-01, -2.931068378076280e-01,  1.638751096673266e-02,  
 3.898390476140786e-01, -9.858802308984792e-01,  2.780360483093786e-03,  
 3.909041204424732e-01, -5.186781535306678e-01,  1.326546194250014e-02,  
 3.968946098564246e-01,  9.780951815512755e-01,  3.201595614419611e-03,  
 4.004938098642667e-01, -7.280056190997359e-01,  7.945101887599497e-03,  
 4.022693250846630e-01,  6.492118066390665e-01,  1.299783839137487e-02,  
 4.046537911668389e-01, -9.367754362358695e-01,  6.856064424860622e-03,  
 4.069866793578729e-01, -1.279310253654376e-01,  1.953042326766891e-02,  
 4.136981826382187e-01,  2.469380555174871e-01,  1.590510409056284e-02,  
 4.155832387933074e-01,  9.987480710406026e-01,  7.122111647233873e-04,  
 4.163004497201460e-01,  9.096099007093472e-01,  7.935410861629728e-03,  
 4.170780839937515e-01, -3.956847909278206e-01,  6.071769193397902e-03,  
 4.358054536464377e-01,  5.406610991088344e-01,  1.142900377925798e-02,  
 4.402901712712737e-01,  1.068482982519669e-01,  1.483195555696222e-02,  
 4.415350462115391e-01,  3.998613126727678e-01,  1.544068952195007e-02,  
 4.424667710350890e-01,  9.683394190344123e-01,  1.611489458792926e-03,  
 4.438046510707432e-01, -6.946709046201798e-01,  6.566325499215901e-03,  
 4.460211421946402e-01, -8.651830868268215e-01,  8.948003496330081e-03,  
 4.538136212528461e-01, -9.949158557964749e-01,  9.385320236765432e-04,  
 4.539118311079229e-01, -3.619729438336315e-01,  7.295767791185555e-03,  
 4.640451021391556e-01, -5.874486068652885e-01,  1.173519860285180e-02,  
 4.730268087671548e-01,  8.312799295231539e-01,  9.822207517714310e-03,  
 4.758178764632183e-01,  7.358820987969293e-01,  1.092908968471396e-02,  
 4.903555614512899e-01, -1.585768379668491e-02,  1.599968590908050e-02,  
 4.941909567997217e-01, -7.741409899278064e-01,  9.298225635133817e-03,  
 4.963751357099565e-01, -9.672078799697353e-01,  4.661655661126369e-03,  
 4.967756100113436e-01, -4.362959868721491e-01,  1.193356100090212e-02,  
 5.000706488516046e-01, -2.331541719563617e-01,  1.856492166793463e-02,  
 5.046834517044907e-01,  9.440657290862045e-01,  5.549588703986526e-03,  
 5.082232650322930e-01,  9.906467286106726e-01,  2.226696053003991e-03,  
 5.160453615337504e-01,  5.957388605223901e-01,  1.121045861005303e-02,  
 5.174302117309763e-01, -9.984556911044671e-01,  6.178035235308593e-04,  
 5.242858161358990e-01, -6.284397942390747e-01,  6.102441007443274e-03,  
 5.256042669730074e-01,  3.069119064348889e-01,  1.440185388865715e-02,  
 5.269880492231742e-01,  1.756864225241269e-01,  1.321861287755303e-02,  
 5.270935009054812e-01, -9.093268419114411e-01,  7.024404856386155e-03,  
 5.351103385815182e-01,  4.676099826976436e-01,  1.240897009695142e-02,  
 5.522815966751274e-01,  6.908618824073344e-01,  8.695368896060368e-03,  
 5.538334779895970e-01, -8.184578724868724e-01,  6.919587428835741e-03,  
 5.538529139427266e-01,  8.832881173595583e-01,  8.500683283786904e-03,  
 5.632577394770644e-01, -1.008778811503898e-01,  1.434254071405664e-02,  
 5.636677818818019e-01, -6.847919323382405e-01,  9.749954332983632e-03,  
 5.639706182528545e-01, -5.072914896235071e-01,  1.248972405626944e-02,  
 5.855037849088083e-01, -9.870796028611907e-01,  2.635159595180530e-03,  
 5.871939805088643e-01, -3.393304454099807e-01,  1.722776519999956e-02,  
 5.873693348599127e-01,  9.705200439306851e-01,  3.780770676414746e-03,  
 5.906291713968752e-01,  7.237558809133927e-02,  1.587807859048982e-02,  
 5.925278367683712e-01,  7.893333499850927e-01,  1.138048852557252e-02,  
 5.953381157637589e-01,  9.983578941888753e-01,  7.034511014927064e-04,  
 6.048511251578461e-01, -9.438915264002324e-01,  5.098619467503369e-03,  
 6.096234974510961e-01,  3.718408906537116e-01,  1.196081090276131e-02,  
 6.109255118670557e-01,  5.230124092297559e-01,  1.003484742952671e-02,  
 6.137767907325069e-01, -8.605257481153944e-01,  7.236718965777555e-03,  
 6.217826405123270e-01, -5.581746176691810e-01,  4.316164008023176e-03,  
 6.246099189559922e-01,  6.358877552910304e-01,  1.025865841557620e-02,  
 6.284044434870041e-01, -7.434235031370082e-01,  9.441418508366915e-03,  
 6.310832515721740e-01, -1.878541135764036e-01,  1.431221258093288e-02,  
 6.345735406340975e-01,  2.275406791927811e-01,  1.538937487698498e-02,  
 6.360661118767135e-01,  9.263313590847803e-01,  6.260040454883993e-03,  
 6.398284843293994e-01, -5.970215524417410e-01,  8.476553668468471e-03,  
 6.649793750204779e-01,  9.883407907673419e-01,  2.094151290945697e-03,  
 6.654072620160371e-01, -2.363946414555849e-02,  1.496699675280598e-02,  
 6.659574757730714e-01, -9.976555625653712e-01,  8.961864501173595e-04,  
 6.691783842005241e-01, -4.395721919427361e-01,  1.512613718261678e-02,  
 6.721936512472663e-01,  8.515744193688413e-01,  8.861042223773296e-03,  
 6.777928890916691e-01,  4.328419152202564e-01,  9.776985446244503e-03,  
 6.782432986711542e-01, -9.696626891387243e-01,  3.431665660167878e-03,  
 6.812902581446887e-01,  7.225085203170045e-01,  1.117216385145412e-02,  
 6.834490098708866e-01, -9.033281433037320e-01,  6.317527410068836e-03,  
 6.924893003140195e-01, -8.005420801936927e-01,  8.320626487524666e-03,  
 6.983314069183064e-01, -6.580165170885999e-01,  9.761529855522378e-03,  
 6.985277688751799e-01, -2.783908913323763e-01,  1.342822159901166e-02,  
 7.008430500305758e-01,  5.594372141944102e-01,  1.072177885303342e-02,  
 7.068216200939229e-01,  1.246262362418973e-01,  1.472068962752201e-02,  
 7.126940396729210e-01,  9.599964346557995e-01,  4.096951260374946e-03,  
 7.178748920387166e-01,  3.138413638113185e-01,  1.320209574966812e-02,  
 7.341287552219317e-01,  9.979860760796205e-01,  6.952108677952970e-04,  
 7.342099274750985e-01, -1.209563345827185e-01,  1.379890445331191e-02,  
 7.423415965113581e-01, -5.379109496936945e-01,  1.292345963370039e-02,  
 7.444692651522274e-01, -9.882712947131560e-01,  1.957053218307852e-03,  
 7.453095007801902e-01,  9.038501012536742e-01,  6.328045119260687e-03,  
 7.494521020396612e-01,  7.927256925287816e-01,  8.961091095120005e-03,  
 7.528242556745927e-01, -9.406599209068169e-01,  4.646624808921421e-03,  
 7.547920587433695e-01, -3.572335113090026e-01,  7.889039673801524e-03,  
 7.566797098881304e-01, -8.534641077327416e-01,  6.970605288870389e-03,  
 7.576126656619195e-01,  6.437458483576055e-01,  1.076928925040325e-02,  
 7.581112942065328e-01, -7.245614233244616e-01,  9.029141466832830e-03,  
 7.628918949884904e-01,  4.623403366366171e-01,  1.090159565188403e-02,  
 7.766396378745131e-01,  2.261756565641802e-02,  1.348877811014296e-02,  
 7.810744268992557e-01,  2.131893811715405e-01,  1.210095928415743e-02,  
 7.812685180469271e-01,  9.836432079909175e-01,  2.255486894669111e-03,  
 7.833445634886622e-01, -4.071221655913209e-01,  7.458693727198815e-03,  
 7.964722407123696e-01, -2.187772943009381e-01,  1.222549520115298e-02,  
 8.020186660324402e-01, -9.983065602932809e-01,  5.862836379827036e-04,  
 8.041315522722302e-01,  3.586679600337050e-01,  8.633096906834895e-03,  
 8.090967096294495e-01, -6.272230964719828e-01,  1.054178563124901e-02,  
 8.108485375531935e-01,  9.451998657334438e-01,  4.141165511985786e-03,  
 8.109640154941112e-01,  8.551876501059489e-01,  6.621506960771783e-03,  
 8.151954694973160e-01,  7.229674728378743e-01,  8.717208142352892e-03,  
 8.153549506988876e-01, -9.703796385813469e-01,  2.953498033751418e-03,  
 8.172395811056902e-01, -7.891470762601582e-01,  7.528638399462986e-03,  
 8.177798317131469e-01, -9.009186885288820e-01,  5.272832904013914e-03,  
 8.208257565286451e-01,  5.503592548730148e-01,  1.054494230976308e-02,  
 8.329246417765747e-01, -4.845120828987132e-01,  9.960600804233005e-03,  
 8.375428168005339e-01, -8.162809594255294e-02,  1.178121026024084e-02,  
 8.386131595480735e-01,  9.965580003832177e-01,  8.087443020783061e-04,  
 8.415522987753493e-01,  1.153254562596080e-01,  1.088575597786116e-02,  
 8.503864327379893e-01, -3.173993641314918e-01,  1.038483762724286e-02,  
 8.531522884093242e-01,  4.035736040841352e-01,  6.302313466112946e-03,  
 8.541610211751280e-01,  2.680874670901057e-01,  7.527298628284477e-03,  
 8.657666650779589e-01,  9.068436211751228e-01,  4.549038886289249e-03,  
 8.664555255514452e-01, -7.090083499012046e-01,  8.071696882394806e-03,  
 8.664770965796653e-01,  7.958591698926688e-01,  6.538372590971846e-03,  
 8.677306492980269e-01, -9.908410519990466e-01,  1.416231188437276e-03,  
 8.684658881444902e-01,  9.747744029833587e-01,  2.379114842060784e-03,  
 8.691737799892778e-01,  6.418561562064864e-01,  8.197723506703251e-03,  
 8.711421380941257e-01, -8.482965458047063e-01,  5.636974183261061e-03,  
 8.717470929454793e-01, -9.410134880535705e-01,  3.553458092063557e-03,  
 8.842658311334305e-01, -5.712045519918001e-01,  8.457837440018774e-03,  
 8.858918774596265e-01,  4.761224644485181e-01,  7.791095831926886e-03,  
 8.887874898320439e-01, -4.134188226282018e-01,  4.059336672999811e-03,  
 8.888733039484702e-01, -1.867627150101622e-01,  9.832441758484581e-03,  
 8.924277378906769e-01,  1.414711422648437e-02,  9.363946896165124e-03,  
 9.009124683482767e-01,  2.977042992859208e-01,  4.958146707886305e-03,  
 9.010130683954759e-01,  1.826981564981862e-01,  6.492822410153440e-03,  
 9.072024742810378e-01, -4.184292901501477e-01,  4.774740801925348e-03,  
 9.111065823100322e-01,  9.944171031036695e-01,  8.780207710373898e-04,  
 9.114979269985268e-01,  8.578389833509421e-01,  4.544508627245127e-03,  
 9.115732033892179e-01,  7.257086927558489e-01,  6.103200593411189e-03,  
 9.131615645699338e-01,  9.465673322575073e-01,  2.807911611163054e-03,  
 9.141377233271082e-01, -7.823208061882461e-01,  5.719546762015152e-03,  
 9.154133627565975e-01, -9.723972924107900e-01,  2.022847142178555e-03,  
 9.167586103246737e-01, -8.996397400727117e-01,  3.801697006719042e-03,  
 9.185218417882126e-01, -3.128496473837001e-01,  3.188755821162131e-03,  
 9.195615536817429e-01,  5.722168961060426e-01,  6.380773543501595e-03,  
 9.224781848073185e-01, -9.985982423657683e-01,  3.867061146665929e-04,  
 9.267209776934766e-01, -6.555982315165978e-01,  6.278150490060387e-03,  
 9.287273685779625e-01,  3.701731556290727e-01,  6.625786458114385e-03,  
 9.335598233788510e-01, -8.772263219538960e-02,  7.531298731793813e-03,  
 9.372373370259899e-01,  1.003699940791335e-01,  5.803669510571517e-03,  
 9.381596020314867e-01, -2.714682784663502e-01,  5.599760135209719e-03,  
 9.392008661159771e-01, -5.070230655068764e-01,  6.382320939876130e-03,  
 9.458552781613642e-01,  9.787913214594990e-01,  1.364728190261521e-03,  
 9.467118325180552e-01,  2.073531201970276e-01,  3.340176953373344e-03,  
 9.474307117494180e-01,  7.982968423254421e-01,  4.139255006817926e-03,  
 9.488517823808786e-01,  9.079595933711595e-01,  2.809691915547652e-03,  
 9.500559469496047e-01,  4.843282580769499e-01,  4.555672065182541e-03,  
 9.514139598012699e-01,  6.593996703812790e-01,  4.775414025344274e-03,  
 9.515054065604527e-01, -8.462535973926137e-01,  3.659192971392661e-03,  
 9.518829254547306e-01, -9.423704869562158e-01,  2.246099949633720e-03,  
 9.577559031192738e-01, -9.884414315999143e-01,  9.138432349434030e-04,  
 9.597823200164480e-01, -7.333102517228226e-01,  4.172167786588739e-03,  
 9.632858025253836e-01,  2.676516560448716e-01,  4.435731025511098e-03,  
 9.633285939046516e-01, -3.830059130508450e-01,  5.251904961064754e-03,  
 9.659428214621411e-01, -1.681070365939437e-01,  3.910206880549662e-03,  
 9.662259959061779e-01,  9.975594517947205e-01,  3.405077457162791e-04,  
 9.667240278631448e-01,  1.427934466963100e-02,  5.159593067194380e-03,  
 9.682866853444982e-01, -5.956513635056965e-01,  4.355417541710161e-03,  
 9.710401795521018e-01,  4.115441754007046e-01,  3.080413657595975e-03,  
 9.723123261969079e-01,  9.532023404173199e-01,  1.437187961183978e-03,  
 9.749343472618806e-01,  5.694643711049896e-01,  3.514758009687542e-03,  
 9.750107495446679e-01,  8.593595879607496e-01,  2.404761206356202e-03,  
 9.755637104115001e-01, -2.162755744715040e-01,  2.069281536160542e-03,  
 9.761350537022933e-01,  7.378942771881075e-01,  2.990197999475044e-03,  
 9.778730077694230e-01, -9.006863126694932e-01,  2.019519731278123e-03,  
 9.822797218536741e-01, -9.673403735244110e-01,  1.011623047148952e-03,  
 9.828503527488298e-01, -9.972100487317516e-01,  2.034653337738994e-04,  
 9.828700260178675e-01,  1.402696637585946e-01,  3.875549745497106e-03,  
 9.829328496130976e-01, -8.027321126645347e-01,  2.328452025760749e-03,  
 9.830518093779190e-01, -4.725198861348646e-01,  2.884600800613669e-03,  
 9.865083692792747e-01,  3.318292049120302e-01,  2.535389452668076e-03,  
 9.870651427476129e-01,  9.851097580641042e-01,  5.787962104520319e-04,  
 9.878909985266884e-01, -6.792964437614948e-01,  2.397415128865462e-03,  
 9.890599145180482e-01, -3.004235153742925e-01,  2.952394914871963e-03,  
 9.891268190165852e-01, -7.461522335461102e-02,  3.147967359176418e-03,  
 9.900018031563753e-01,  9.183273178173896e-01,  1.129303662157627e-03,  
 9.906700419592033e-01,  6.532346934319574e-01,  1.929434615425692e-03,  
 9.912596163219474e-01,  4.801078529393079e-01,  2.082572420594760e-03,  
 9.924744721609760e-01,  8.057094807256353e-01,  1.431280556327198e-03,  
 9.936122984604325e-01, -5.399266031918037e-01,  1.361643312207529e-03,  
 9.945101783976882e-01, -9.964564449204121e-01,  6.738824280797225e-05,
 9.959237770580724e-01, -9.356939566617255e-01,  6.409569163115698e-04,  
 9.960185717579940e-01, -8.614455712828953e-01,  8.970688263528367e-04,  
 9.963549802489995e-01,  2.297860268936834e-01,  1.493840185718328e-03,  
 9.974280487247386e-01,  9.970685285995574e-01,  8.386486527342163e-05,
 9.974477484292649e-01,  4.872754674637698e-02,  1.368835501840511e-03,  
 9.974884982557854e-01, -9.835909301201050e-01,  2.155878200460052e-04,  
 9.979151073110650e-01,  9.613613215256067e-01,  3.343893771661675e-04,  
 9.979318948645635e-01, -7.553329869388302e-01,  7.631344418442518e-04,  
 9.981736018665053e-01, -4.034601085328000e-01,  1.016793649077959e-03,  
 9.983952046173069e-01, -1.854951369598807e-01,  1.067126311051324e-03,  
 9.985153359170394e-01,  5.693738362511860e-01,  6.823019963489656e-04,  
 9.985841032168380e-01,  8.747010290291490e-01,  4.298394507636698e-04,  
 9.986616936036532e-01,  7.274743018665757e-01,  5.666609989068298e-04,  
 9.986723383294596e-01, -6.114560344532366e-01,  5.878791899273640e-04,  
 9.988762864534128e-01,  3.869508160326630e-01,  6.702204214070438e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *smr55 ( )

/******************************************************************************/
/*
  Purpose:

    SMR55 returns the SMR rule of degree 55.

  Discussion:
 
    DEGREE: 55
    SYMMETRY: (X,  Y),  (-X, -Y).
    POINTS CARDINALITY: 536
    NORM INF MOMS. RESIDUAL: 2.29858e-16
    SUM NEGATIVE WEIGHTS: 0.00000e+00,  

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 February 2018

  Author:

    Original MATLAB version by Mattia Festa, Alvise Sommariva,
    C version by John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, double *SMR55[3*536], the requested rule.
*/
{
  const int degree = 55;
  int order;
  double xw[3*536] = {
 -9.988024883360008e-01, -4.104312670989267e-01,  7.247738364520382e-04,  
 -9.986637711500016e-01,  5.835721439184322e-01,  6.485919247428450e-04,  
 -9.985517638075939e-01,  1.568937801098068e-01,  1.047965997616771e-03,  
 -9.983624199159088e-01, -7.311569400195331e-01,  6.234634259867621e-04,  
 -9.982698924284638e-01, -5.843339960398285e-01,  7.392815641484668e-04,  
 -9.982434766908749e-01,  3.819333028903024e-01,  9.500630778549490e-04,  
 -9.982097416579526e-01, -8.832442641091779e-01,  4.604405106623550e-04,  
 -9.978286522784937e-01, -9.628763075615144e-01,  3.344694660648939e-04,  
 -9.976963561372271e-01,  9.678687355428703e-01,  3.138082077303478e-04,  
 -9.976125620794032e-01,  7.261201764578525e-01,  8.279866159627213e-04,  
 -9.973396392196245e-01, -9.972222237164891e-01,  8.333752929282447e-05,
 -9.972455951936153e-01, -7.187156081293171e-02,  1.410032513903549e-03,  
 -9.971099785500591e-01,  9.975224120853297e-01,  7.798442798007867e-05,
 -9.963480933133427e-01, -2.479538638037798e-01,  1.491315677106339e-03,  
 -9.958519119176469e-01,  9.077787403602237e-01,  7.431854366720857e-04,  
 -9.952342237683616e-01,  8.286466960550624e-01,  1.082707396932906e-03,  
 -9.929995253631880e-01, -8.129871703624600e-01,  1.347117277977657e-03,  
 -9.920960970276202e-01,  5.044070130004836e-01,  1.824136223192767e-03,  
 -9.906699598276788e-01,  2.862146444653838e-01,  2.228303203490404e-03,  
 -9.900482572019094e-01, -4.985621080229760e-01,  2.242724334598082e-03,  
 -9.892479265001065e-01, -6.612276378064350e-01,  2.043285817276434e-03,  
 -9.888908697853098e-01, -9.233667636095402e-01,  1.140018239107126e-03,  
 -9.885804018012844e-01,  4.855418553020024e-02,  3.260277409726965e-03,  
 -9.872410998898277e-01,  6.516124343282037e-01,  2.451688694670727e-03,  
 -9.865494934684096e-01, -9.856652402947823e-01,  5.802863637376822e-04,  
 -9.864237410369340e-01, -3.474984134057699e-01,  2.626333169195453e-03,  
 -9.854696330893135e-01,  9.878927125972993e-01,  5.302485898777602e-04,  
 -9.823718529863428e-01,  9.448695023246775e-01,  1.256965089029987e-03,  
 -9.820307319973294e-01, -1.607872100549523e-01,  3.959806596474525e-03,  
 -9.817367673963038e-01,  2.211661902207940e-01,  2.176154471489884e-03,  
 -9.798298883847092e-01,  7.687042632123031e-01,  2.691125475983456e-03,  
 -9.794817550638735e-01,  4.308079229171551e-01,  3.138802635622372e-03,  
 -9.760951773774511e-01, -7.497184921929896e-01,  2.895893718670046e-03,  
 -9.756611980550673e-01,  8.717067247715160e-01,  2.345719243525908e-03,  
 -9.748150682339674e-01, -8.630701855337108e-01,  2.379490945836736e-03,  
 -9.716942423922518e-01, -5.810982845814314e-01,  3.659348716877558e-03,  
 -9.702051269912042e-01, -9.560511844190226e-01,  1.434791120385777e-03,  
 -9.688706334298569e-01, -4.266194891481059e-01,  3.409732775774852e-03,  
 -9.675772091594030e-01,  5.706238471045659e-01,  4.319580505788219e-03,  
 -9.654793296651025e-01,  1.449151374798731e-01,  4.901363403832491e-03,  
 -9.648815628338514e-01, -9.976194228266280e-01,  3.422316968868938e-04,  
 -9.644011406655369e-01, -3.955662605890648e-02,  5.487620385431768e-03,  
 -9.621685673801630e-01,  9.981498616350863e-01,  2.983264390605248e-04,  
 -9.618072357953964e-01, -2.840075572844367e-01,  4.584997220482829e-03,  
 -9.603547491901058e-01,  3.444098104140523e-01,  5.192860463827343e-03,  
 -9.572722322598644e-01,  9.727383585296555e-01,  1.371820477478312e-03,  
 -9.543120615194950e-01,  6.978166939707769e-01,  4.657220418242932e-03,  
 -9.502228126713501e-01, -6.756755603285315e-01,  4.638832336370128e-03,  
 -9.497373302590694e-01,  9.198416005546896e-01,  2.489219831374708e-03,  
 -9.477372910934111e-01, -9.097890847623551e-01,  2.819888629654258e-03,  
 -9.461037891822155e-01,  8.162510788029149e-01,  4.131502513773345e-03,  
 -9.459596501532294e-01, -8.050199903923727e-01,  4.077330276254603e-03,  
 -9.454153692097916e-01, -4.969416983931578e-01,  4.614178689184361e-03,  
 -9.435279532066055e-01, -2.221999393850942e-01,  3.479548412810748e-03,  
 -9.426467016723202e-01, -9.801477693736759e-01,  1.345953538075658e-03,  
 -9.392911967713488e-01,  4.855179051814372e-01,  6.174008549382279e-03,  
 -9.351449029460894e-01,  2.406511548034665e-01,  5.779691515292159e-03,  
 -9.316323693555080e-01, -1.260692370780684e-01,  6.144629409760324e-03,  
 -9.303888378867309e-01,  6.224958329536455e-02,  7.669256083745869e-03,  
 -9.252698678871364e-01, -3.816000875630634e-01,  6.720562662548456e-03,  
 -9.211332348776220e-01,  9.906945704103310e-01,  1.078080942745430e-03,  
 -9.188758666484276e-01,  6.191245374224351e-01,  6.822998261844405e-03,  
 -9.180486167649172e-01, -5.920245031381465e-01,  6.069384535392124e-03,  
 -9.147536811475745e-01,  8.800465507878222e-01,  3.625599405917247e-03,  
 -9.116846414755537e-01,  3.946552397032295e-01,  4.799510717398269e-03,  
 -9.109269835273496e-01, -9.474408959785233e-01,  2.828303409790731e-03,  
 -9.107962036779229e-01,  9.546466357227235e-01,  2.504361618864681e-03,  
 -9.097119148344930e-01,  2.791721791436264e-01,  3.325039377988705e-03,  
 -9.088140552343917e-01, -8.613880826568586e-01,  4.524206023005564e-03,  
 -9.085091703518080e-01, -7.357866023957996e-01,  5.980225096092428e-03,  
 -9.069440260746182e-01, -9.948615423994508e-01,  8.460206194961731e-04,  
 -9.060257668239784e-01,  7.510933281143483e-01,  6.285183519604021e-03,  
 -8.966458818425863e-01, -3.077535071435578e-01,  5.074492497678043e-03,  
 -8.914497061411687e-01, -2.063254399354762e-01,  6.379677376597891e-03,  
 -8.886925006776532e-01,  4.029207162992898e-01,  3.953122632176603e-03,  
 -8.877478758386065e-01, -3.703102823746122e-02,  9.391237982629010e-03,  
 -8.863873331866154e-01, -5.014911962761207e-01,  6.732637721829442e-03,  
 -8.840931476725340e-01,  1.591395148790940e-01,  9.725396029596314e-03,  
 -8.750871750612564e-01,  8.371208783269141e-01,  4.667481132791865e-03,  
 -8.746997180248225e-01,  5.337452183276610e-01,  8.969697082860535e-03,  
 -8.738193544174702e-01,  9.987050363801271e-01,  4.029777384147725e-04,  
 -8.656342986234824e-01, -6.539955758641589e-01,  8.007673011011452e-03,  
 -8.653144381651936e-01,  9.229713406820786e-01,  3.786147464455085e-03,  
 -8.649186611907598e-01, -9.752422585287235e-01,  2.397696219433860e-03,  
 -8.620920815291837e-01, -9.088307352715838e-01,  4.535170978475270e-03,  
 -8.618783040518693e-01, -8.015653601725335e-01,  6.476664260979469e-03,  
 -8.591213496900382e-01,  9.789218555148047e-01,  2.183949091910629e-03,  
 -8.580096391046452e-01, -4.289163888579028e-01,  7.032590377677609e-03,  
 -8.561231024886632e-01,  6.768698449375528e-01,  8.653374792867137e-03,  
 -8.531080996665429e-01,  3.100864425712632e-01,  9.462959763014268e-03,  
 -8.445552751701417e-01, -2.869258517851172e-01,  7.087178777230579e-03,  
 -8.345746770920350e-01, -1.348195251852799e-01,  1.086669255897672e-02,  
 -8.323840732904080e-01,  5.770931774582546e-02,  1.157981674113329e-02,  
 -8.316280572729237e-01, -9.963536786620084e-01,  8.601012497443448e-04,  
 -8.302233642792779e-01,  7.887974291015537e-01,  6.403870452065013e-03,  
 -8.198903592035567e-01,  4.474759410866835e-01,  1.039723732697557e-02,  
 -8.179555207385244e-01, -5.630877825822931e-01,  1.038670426889326e-02,  
 -8.131642862712356e-01,  8.855936518041989e-01,  5.172308318006293e-03,  
 -8.095710479011895e-01, -7.299545306893604e-01,  8.640988335276857e-03,  
 -8.060880027952726e-01, -9.464168885010812e-01,  4.138102993626548e-03,  
 -8.055768707550288e-01, -8.588418294042808e-01,  6.546425691890088e-03,  
 -8.052848747707124e-01,  2.154694645963307e-01,  1.115929240605312e-02,  
 -8.048061510789419e-01, -3.718357650456645e-01,  8.637973753390449e-03,  
 -8.013660329335811e-01,  9.549385718300994e-01,  3.667653054187556e-03,  
 -7.996575186605993e-01,  9.945437983737444e-01,  1.170500089565615e-03,  
 -7.978946443412313e-01,  5.940088162963154e-01,  1.102206312002593e-02,  
 -7.753719582521668e-01,  7.296837750586209e-01,  8.830371768634843e-03,  
 -7.728941799568024e-01, -9.834791267225803e-01,  2.318079830785805e-03,  
 -7.713573933240646e-01, -2.292623609101414e-01,  1.222664318821314e-02,  
 -7.703655439710254e-01, -4.177172398061163e-02,  1.320655645297225e-02,  
 -7.696542328903390e-01,  3.800140053796911e-01,  5.896276097702543e-03,  
 -7.613061970586104e-01, -4.720892602078328e-01,  1.121593897330926e-02,  
 -7.555601563064301e-01,  8.414687309753481e-01,  6.891618536870428e-03,  
 -7.520357832344026e-01, -6.508886285165648e-01,  1.070105581225020e-02,  
 -7.490155562917605e-01,  3.252336868606283e-01,  9.351093216509690e-03,  
 -7.459343555200221e-01,  1.236717037454283e-01,  1.296776589532101e-02,  
 -7.431555210822531e-01, -7.977482842071556e-01,  8.833161716226669e-03,  
 -7.403849867503648e-01,  9.819171911401473e-01,  2.337724717192945e-03,  
 -7.391722285237710e-01, -9.062068947141577e-01,  6.258431339300329e-03,  
 -7.351348537506192e-01,  9.235000024040693e-01,  5.339474521352486e-03,  
 -7.281406688886811e-01,  5.071254424742396e-01,  1.331196820325115e-02,  
 -7.243383015839274e-01, -9.980207065293273e-01,  7.199560063855860e-04,  
 -7.131083800360229e-01, -3.348252722558369e-01,  1.317500343117314e-02,  
 -7.125260040531168e-01,  6.588957967703316e-01,  1.101941046086741e-02,  
 -7.032675418563811e-01, -9.600474050632336e-01,  4.157108404417536e-03,  
 -6.986567532110330e-01, -1.382567167908484e-01,  1.442120114433883e-02,  
 -6.958360474648256e-01, -5.644565737670422e-01,  1.103743316814278e-02,  
 -6.909159146496135e-01,  7.887887571343239e-01,  8.977062336109128e-03,  
 -6.906859319625951e-01,  9.979604128976195e-01,  8.435777152586793e-04,  
 -6.849076257411216e-01,  2.427166387314666e-01,  1.397568311805146e-02,  
 -6.779414345191699e-01,  3.063740688329146e-02,  1.447701175069298e-02,  
 -6.754749986154636e-01, -7.281422316126919e-01,  1.097118103052011e-02,  
 -6.718973107043948e-01,  9.628615704165838e-01,  3.868709630540442e-03,  
 -6.652837909761897e-01, -8.550121217464759e-01,  8.720558763742966e-03,  
 -6.641092110776139e-01,  8.842872475223941e-01,  7.073002093332755e-03,  
 -6.638595707485085e-01, -4.439193977915850e-01,  1.102925103533717e-02,  
 -6.582656205134384e-01,  4.038261118251286e-01,  1.497892745877775e-02,  
 -6.531607555762389e-01, -9.883039600294047e-01,  2.166784944891255e-03,  
 -6.403455995923052e-01,  5.867373929097057e-01,  1.193450620498925e-02,  
 -6.314704538659979e-01, -2.446105067220338e-01,  1.537286390141198e-02,  
 -6.254538870491240e-01, -9.264854004436116e-01,  6.307266862024064e-03,  
 -6.226576289009583e-01,  7.259246555573967e-01,  1.069584666724211e-02,  
 -6.191838769193574e-01, -6.420040583801523e-01,  1.067988406928965e-02,  
 -6.149834556692348e-01,  1.527830270721475e-01,  1.405889213374533e-02,  
 -6.058697705151179e-01,  9.883839405182854e-01,  2.594759629417247e-03,  
 -6.031110203472072e-01,  5.107400343109616e-01,  6.474717016434753e-03,  
 -6.014430739812223e-01, -6.305652605767732e-02,  1.564707540156174e-02,  
 -5.949690407134853e-01,  9.351174758101611e-01,  5.854723529644378e-03,  
 -5.939522570295417e-01, -5.310108582117370e-01,  1.096129405119757e-02,  
 -5.910214836343624e-01,  8.384444159782082e-01,  8.418868716555618e-03,  
 -5.881718967548081e-01, -3.744506110517851e-01,  1.307998578130345e-02,  
 -5.864634403080233e-01, -7.932418330534410e-01,  1.112227385834183e-02,  
 -5.811601592234984e-01, -9.983496902489798e-01,  7.104280334676121e-04,  
 -5.757548043279564e-01, -9.703367418123594e-01,  3.757168119063795e-03,  
 -5.748025638560177e-01,  3.067973240959255e-01,  1.707935332348776e-02,  
 -5.497845124077343e-01,  7.333202414867040e-02,  1.235895418614051e-02,  
 -5.484074961393921e-01,  6.660476228238359e-01,  1.048532964530446e-02,  
 -5.467362660936782e-01,  4.682073286935134e-01,  1.236063811528119e-02,  
 -5.421728509707354e-01, -8.831112721261267e-01,  8.569226685725167e-03,  
 -5.413187638370147e-01, -7.008354250408056e-01,  9.314699663035950e-03,  
 -5.351205786493067e-01, -1.662338233527932e-01,  1.523192606517475e-02,  
 -5.291031884464018e-01,  7.888885157981417e-01,  7.737672122912299e-03,  
 -5.186382422892405e-01,  5.909018703387654e-01,  8.134241234233111e-03,  
 -5.176647451047708e-01,  9.983923444453340e-01,  8.821790616867712e-04,  
 -5.132865237464714e-01, -4.688970718806879e-01,  1.282967010005945e-02,  
 -5.131329313010590e-01,  9.693478795578427e-01,  4.668299073616817e-03,  
 -5.113306771546843e-01,  8.975233040638488e-01,  8.023411794220729e-03,  
 -5.043040025277375e-01, -6.040349373214349e-01,  1.160242726756205e-02,  
 -5.035820355440569e-01, -2.986926997353190e-01,  1.507793601848234e-02,  
 -4.965158961324884e-01, -9.906821956576266e-01,  2.159685403265884e-03,  
 -4.961172566625360e-01, -9.440998487019658e-01,  5.059202691726304e-03,  
 -4.886505110046377e-01,  2.014030458083448e-01,  1.779060966900524e-02,  
 -4.814712707153859e-01,  1.018471840513952e-03,  1.494149892965163e-02,  
 -4.724465250882208e-01,  3.901946239850855e-01,  1.407056045257186e-02,  
 -4.673690443814725e-01,  7.510905791040010e-01,  8.653955385139918e-03,  
 -4.643134260679443e-01, -8.291696117863686e-01,  9.380625377758188e-03,  
 -4.620662895796879e-01, -7.420575670812756e-01,  1.005785415907135e-02,  
 -4.544968567562652e-01, -9.637138942504565e-01,  1.122463533992389e-03,  
 -4.392936416624263e-01,  5.418537987967835e-01,  1.354180192499032e-02,  
 -4.360207998774642e-01,  3.149360384017255e-01,  5.844690041934657e-03,  
 -4.337443890556876e-01,  6.598862990786999e-01,  8.546812451435981e-03,  
 -4.331554234268176e-01, -1.092637162347169e-01,  1.439377035472382e-02,  
 -4.291577428294838e-01,  8.476059832446078e-01,  9.902296083341852e-03,  
 -4.229143668793170e-01, -3.960647752213135e-01,  1.549781901257185e-02,  
 -4.187017631471830e-01, -5.436803325150400e-01,  1.209743843849932e-02,  
 -4.183500029509192e-01,  9.898883598570750e-01,  2.709117739353572e-03,  
 -4.173246329940232e-01,  9.401616974636222e-01,  6.891766839873124e-03,  
 -4.112319822368788e-01, -9.120363501798638e-01,  7.424471893404875e-03,  
 -4.048315435775057e-01, -9.987956142180350e-01,  6.718324805703920e-04,  
 -3.980418991846619e-01, -2.327471046963004e-01,  1.625275270500379e-02,  
 -3.953464161989157e-01, -9.776274329999616e-01,  3.590227670893820e-03,  
 -3.927964120379244e-01, -6.567324722323492e-01,  1.286468850270801e-02,  
 -3.908992398262501e-01,  1.029204492534816e-01,  1.923372019735730e-02,  
 -3.783036687069794e-01,  7.129987503369131e-01,  8.163366302461943e-03,  
 -3.709983918669602e-01,  3.878951046903481e-01,  5.919722230014070e-03,  
 -3.686946309484030e-01,  2.658237229153717e-01,  1.502100476996729e-02,  
 -3.670884151507721e-01, -8.541749683199031e-01,  5.997903388653519e-03,  
 -3.597392305547168e-01,  4.702440999029917e-01,  1.222936506074443e-02,  
 -3.456801320384574e-01, -7.767804274879180e-01,  1.064901135031854e-02,  
 -3.354206745206995e-01,  7.970083033314623e-01,  1.098275538515688e-02,  
 -3.349659026157715e-01,  9.738986981710231e-01,  2.585251695131729e-03,  
 -3.317394233870357e-01, -3.629784813923093e-02,  1.817689182146082e-02,  
 -3.292032308163682e-01,  8.969852827615720e-01,  8.651055110598674e-03,  
 -3.270737918480568e-01, -4.795137218921213e-01,  1.439474911975008e-02,  
 -3.252517001548298e-01,  6.111780771310250e-01,  1.471608963923809e-02,  
 -3.127045248917160e-01, -9.507593463893184e-01,  6.165042832173903e-03,  
 -3.122739080164743e-01, -7.037282845144895e-01,  6.502793402916389e-03,  
 -3.121872182700364e-01, -3.284494967900573e-01,  1.665094260609503e-02,  
 -3.021802314007289e-01,  9.981802915822515e-01,  1.089216259085527e-03,  
 -2.961390561335081e-01, -9.938134682747217e-01,  1.955987410825677e-03,  
 -2.929939168803610e-01,  9.675850235289137e-01,  2.923308696330317e-03,  
 -2.870583486247197e-01, -1.684615473834412e-01,  1.611587845368105e-02,  
 -2.869268892504222e-01, -8.836970380549014e-01,  7.313309499881776e-03,  
 -2.824132709710231e-01, -5.861790192624122e-01,  1.402973677831503e-02,  
 -2.801601822730441e-01,  4.674597814398905e-01,  7.723487106141499e-03,  
 -2.735536542584517e-01,  1.882929761148383e-01,  1.635032477992683e-02,  
 -2.681837896607717e-01,  3.462108439336833e-01,  1.561212360653534e-02,  
 -2.638750753550576e-01,  7.175917772976728e-01,  9.196701513559774e-03,  
 -2.562280695633936e-01,  7.536618699046908e-02,  1.159566375455242e-02,  
 -2.449718364656067e-01,  9.329876539574047e-01,  4.442995362383195e-03,  
 -2.367076649306707e-01, -8.164340093215012e-01,  8.859159397898358e-03,  
 -2.263564338237641e-01,  8.525868904257583e-01,  1.025853294633492e-02,  
 -2.233777787601983e-01, -6.690920935223389e-01,  8.457199667884932e-03,  
 -2.225881310352093e-01,  5.464598853057760e-01,  1.451315283307596e-02,  
 -2.172243346336479e-01,  7.779346875182629e-01,  5.453876637219251e-03,  
 -2.167851796507998e-01, -7.340009575500001e-01,  7.704445266317693e-03,  
 -2.156912547618889e-01, -4.159114007166079e-01,  1.600761576189837e-02,  
 -2.126675089250964e-01, -9.790313276822009e-01,  3.898756652243800e-03,  
 -2.057013987550619e-01,  6.714574222473618e-01,  8.548373971133082e-03,  
 -2.001222956524658e-01, -9.229708435499334e-01,  7.317697261380912e-03,  
 -1.968485732716530e-01, -2.684443696987204e-01,  1.551989981674327e-02,  
 -1.952851800362058e-01, -1.181886347339289e-01,  1.249411507302537e-02,  
 -1.930088850045736e-01,  1.067037967524868e-02,  1.502128981902244e-02,  
 -1.927893567464448e-01,  9.885913799935848e-01,  3.285042178348613e-03,  
 -1.843627359591440e-01,  9.475189594826643e-01,  3.879323024081221e-03,  
 -1.721744096018839e-01, -5.142401574740272e-01,  1.164304712326221e-02,  
 -1.700184298252278e-01,  4.192688036006606e-01,  1.408971892461283e-02,  
 -1.624664921006047e-01,  2.057032829234850e-01,  1.045498739102006e-02,  
 -1.559859159591793e-01,  2.894304583316343e-01,  1.306941393934462e-02,  
 -1.518484005740585e-01, -8.477732470072303e-01,  7.414729733024272e-03,  
 -1.476070990486803e-01, -5.880708608342150e-01,  9.069852257674605e-03,  
 -1.416105434314038e-01, -9.974967466477315e-01,  1.331241793936731e-03,  
 -1.264308798345233e-01,  9.023791087885762e-01,  8.220753803377345e-03,  
 -1.229412724709716e-01,  7.559125625986661e-01,  9.067738186701686e-03,  
 -1.211233536563693e-01,  6.333611074991552e-01,  1.314389634964796e-02,  
 -1.171435843878661e-01, -7.589099321895559e-01,  1.034402317344686e-02,  
 -1.142916155264042e-01,  8.134828246262563e-01,  6.912585182173686e-03,  
 -1.091562261809793e-01, -9.593556005291021e-01,  5.529710901059238e-03,  
 -1.050166495242263e-01, -2.262609218574975e-01,  1.163508798500837e-02,  
 -1.039822454676996e-01,  1.147960727732085e-01,  1.726822277670347e-02,  
 -9.753315478770204e-02,  5.156121655539427e-01,  1.303842924168740e-02,  
 -9.563339138231701e-02, -8.253348748785061e-02,  1.590204206847470e-02,  
 -9.364067514936512e-02, -6.600655556642241e-01,  1.223016394781105e-02,  
 -8.965966879899780e-02, -3.586799588937428e-01,  1.756886760866844e-02,  
 -8.551197009473779e-02, -8.901928888130525e-01,  7.846676697391447e-03,  
 -8.365029898380197e-02,  9.685292909194466e-01,  5.214647863353589e-03,  
 -7.568647243766341e-02,  9.980944345717083e-01,  1.190071691701019e-03,  
 -5.482069463596000e-02, -4.814553453340769e-01,  1.503245155554792e-02,  
 -4.844652587154250e-02,  4.108333656727153e-01,  1.342616839842313e-02,  
 -3.841094055935779e-02,  2.983156459040408e-01,  1.541784656069183e-02,  
 -3.632741707588952e-02,  8.600961271871967e-01,  8.090610682724464e-03,  
 -3.153704671275477e-02, -9.872255003269456e-01,  3.471711085681394e-03,  
 -3.056480134457628e-02,  2.747004986895673e-02,  1.221572001121651e-02,  
 -2.872714752032467e-02, -8.038829114783085e-01,  9.938639300940503e-03,  
 -2.162030480223479e-02,  7.100363302853934e-01,  1.355512556979677e-02,  
 -7.873257230365114e-03, -1.856407375954660e-01,  1.627356809068969e-02,  
 -1.536827915034127e-03,  9.326306951328229e-01,  7.198183297047558e-03,  
 -2.078796471167668e-05, -5.847656060556753e-01,  1.411565553024802e-02,  
 2.078796471167668e-05, 5.847656060556753e-01,  1.411565553024802e-02,  
 1.536827915034127e-03, -9.326306951328229e-01,  7.198183297047558e-03,  
 7.873257230365114e-03,  1.856407375954660e-01,  1.627356809068969e-02,  
 2.162030480223479e-02, -7.100363302853934e-01,  1.355512556979677e-02,  
 2.872714752032467e-02,  8.038829114783085e-01,  9.938639300940503e-03,  
 3.056480134457628e-02, -2.747004986895673e-02,  1.221572001121651e-02,  
 3.153704671275477e-02,  9.872255003269456e-01,  3.471711085681394e-03,  
 3.632741707588952e-02, -8.600961271871967e-01,  8.090610682724464e-03,  
 3.841094055935779e-02, -2.983156459040408e-01,  1.541784656069183e-02,  
 4.844652587154250e-02, -4.108333656727153e-01,  1.342616839842313e-02,  
 5.482069463596000e-02,  4.814553453340769e-01,  1.503245155554792e-02,  
 7.568647243766341e-02, -9.980944345717083e-01,  1.190071691701019e-03,  
 8.365029898380197e-02, -9.685292909194466e-01,  5.214647863353589e-03,  
 8.551197009473779e-02,  8.901928888130525e-01,  7.846676697391447e-03,  
 8.965966879899780e-02,  3.586799588937428e-01,  1.756886760866844e-02,  
 9.364067514936512e-02,  6.600655556642241e-01,  1.223016394781105e-02,  
 9.563339138231701e-02,  8.253348748785061e-02,  1.590204206847470e-02,  
 9.753315478770204e-02, -5.156121655539427e-01,  1.303842924168740e-02,  
 1.039822454676996e-01, -1.147960727732085e-01,  1.726822277670347e-02,  
 1.050166495242263e-01,  2.262609218574975e-01,  1.163508798500837e-02,  
 1.091562261809793e-01,  9.593556005291021e-01,  5.529710901059238e-03,  
 1.142916155264042e-01, -8.134828246262563e-01,  6.912585182173686e-03,  
 1.171435843878661e-01,  7.589099321895559e-01,  1.034402317344686e-02,  
 1.211233536563693e-01, -6.333611074991552e-01,  1.314389634964796e-02,  
 1.229412724709716e-01, -7.559125625986661e-01,  9.067738186701686e-03,  
 1.264308798345233e-01, -9.023791087885762e-01,  8.220753803377345e-03,  
 1.416105434314038e-01,  9.974967466477315e-01,  1.331241793936731e-03,  
 1.476070990486803e-01,  5.880708608342150e-01,  9.069852257674605e-03,  
 1.518484005740585e-01,  8.477732470072303e-01,  7.414729733024272e-03,  
 1.559859159591793e-01, -2.894304583316343e-01,  1.306941393934462e-02,  
 1.624664921006047e-01, -2.057032829234850e-01,  1.045498739102006e-02,  
 1.700184298252278e-01, -4.192688036006606e-01,  1.408971892461283e-02,  
 1.721744096018839e-01,  5.142401574740272e-01,  1.164304712326221e-02,  
 1.843627359591440e-01, -9.475189594826643e-01,  3.879323024081221e-03,  
 1.927893567464448e-01, -9.885913799935848e-01,  3.285042178348613e-03,  
 1.930088850045736e-01, -1.067037967524868e-02,  1.502128981902244e-02,  
 1.952851800362058e-01,  1.181886347339289e-01,  1.249411507302537e-02,  
 1.968485732716530e-01,  2.684443696987204e-01,  1.551989981674327e-02,  
 2.001222956524658e-01,  9.229708435499334e-01,  7.317697261380912e-03,  
 2.057013987550619e-01, -6.714574222473618e-01,  8.548373971133082e-03,  
 2.126675089250964e-01,  9.790313276822009e-01,  3.898756652243800e-03,  
 2.156912547618889e-01,  4.159114007166079e-01,  1.600761576189837e-02,  
 2.167851796507998e-01,  7.340009575500001e-01,  7.704445266317693e-03,  
 2.172243346336479e-01, -7.779346875182629e-01,  5.453876637219251e-03,  
 2.225881310352093e-01, -5.464598853057760e-01,  1.451315283307596e-02,  
 2.233777787601983e-01,  6.690920935223389e-01,  8.457199667884932e-03,  
 2.263564338237641e-01, -8.525868904257583e-01,  1.025853294633492e-02,  
 2.367076649306707e-01,  8.164340093215012e-01,  8.859159397898358e-03,  
 2.449718364656067e-01, -9.329876539574047e-01,  4.442995362383195e-03,  
 2.562280695633936e-01, -7.536618699046908e-02,  1.159566375455242e-02,  
 2.638750753550576e-01, -7.175917772976728e-01,  9.196701513559774e-03,  
 2.681837896607717e-01, -3.462108439336833e-01,  1.561212360653534e-02,  
 2.735536542584517e-01, -1.882929761148383e-01,  1.635032477992683e-02,  
 2.801601822730441e-01, -4.674597814398905e-01,  7.723487106141499e-03,  
 2.824132709710231e-01,  5.861790192624122e-01,  1.402973677831503e-02,  
 2.869268892504222e-01,  8.836970380549014e-01,  7.313309499881776e-03,  
 2.870583486247197e-01,  1.684615473834412e-01,  1.611587845368105e-02,  
 2.929939168803610e-01, -9.675850235289137e-01,  2.923308696330317e-03,  
 2.961390561335081e-01,  9.938134682747217e-01,  1.955987410825677e-03,  
 3.021802314007289e-01, -9.981802915822515e-01,  1.089216259085527e-03,  
 3.121872182700364e-01,  3.284494967900573e-01,  1.665094260609503e-02,  
 3.122739080164743e-01,  7.037282845144895e-01,  6.502793402916389e-03,  
 3.127045248917160e-01,  9.507593463893184e-01,  6.165042832173903e-03,  
 3.252517001548298e-01, -6.111780771310250e-01,  1.471608963923809e-02,  
 3.270737918480568e-01,  4.795137218921213e-01,  1.439474911975008e-02,  
 3.292032308163682e-01, -8.969852827615720e-01,  8.651055110598674e-03,  
 3.317394233870357e-01,  3.629784813923093e-02,  1.817689182146082e-02,  
 3.349659026157715e-01, -9.738986981710231e-01,  2.585251695131729e-03,  
 3.354206745206995e-01, -7.970083033314623e-01,  1.098275538515688e-02,  
 3.456801320384574e-01,  7.767804274879180e-01,  1.064901135031854e-02,  
 3.597392305547168e-01, -4.702440999029917e-01,  1.222936506074443e-02,  
 3.670884151507721e-01,  8.541749683199031e-01,  5.997903388653519e-03,  
 3.686946309484030e-01, -2.658237229153717e-01,  1.502100476996729e-02,  
 3.709983918669602e-01, -3.878951046903481e-01,  5.919722230014070e-03,  
 3.783036687069794e-01, -7.129987503369131e-01,  8.163366302461943e-03,  
 3.908992398262501e-01, -1.029204492534816e-01,  1.923372019735730e-02,  
 3.927964120379244e-01,  6.567324722323492e-01,  1.286468850270801e-02,  
 3.953464161989157e-01,  9.776274329999616e-01,  3.590227670893820e-03,  
 3.980418991846619e-01,  2.327471046963004e-01,  1.625275270500379e-02,  
 4.048315435775057e-01,  9.987956142180350e-01,  6.718324805703920e-04,  
 4.112319822368788e-01,  9.120363501798638e-01,  7.424471893404875e-03,  
 4.173246329940232e-01, -9.401616974636222e-01,  6.891766839873124e-03,  
 4.183500029509192e-01, -9.898883598570750e-01,  2.709117739353572e-03,  
 4.187017631471830e-01,  5.436803325150400e-01,  1.209743843849932e-02,  
 4.229143668793170e-01,  3.960647752213135e-01,  1.549781901257185e-02,  
 4.291577428294838e-01, -8.476059832446078e-01,  9.902296083341852e-03,  
 4.331554234268176e-01,  1.092637162347169e-01,  1.439377035472382e-02,  
 4.337443890556876e-01, -6.598862990786999e-01,  8.546812451435981e-03,  
 4.360207998774642e-01, -3.149360384017255e-01,  5.844690041934657e-03,  
 4.392936416624263e-01, -5.418537987967835e-01,  1.354180192499032e-02,  
 4.544968567562652e-01,  9.637138942504565e-01,  1.122463533992389e-03,  
 4.620662895796879e-01,  7.420575670812756e-01,  1.005785415907135e-02,  
 4.643134260679443e-01,  8.291696117863686e-01,  9.380625377758188e-03,  
 4.673690443814725e-01, -7.510905791040010e-01,  8.653955385139918e-03,  
 4.724465250882208e-01, -3.901946239850855e-01,  1.407056045257186e-02,  
 4.814712707153859e-01, -1.018471840513952e-03,  1.494149892965163e-02,  
 4.886505110046377e-01, -2.014030458083448e-01,  1.779060966900524e-02,  
 4.961172566625360e-01,  9.440998487019658e-01,  5.059202691726304e-03,  
 4.965158961324884e-01,  9.906821956576266e-01,  2.159685403265884e-03,  
 5.035820355440569e-01,  2.986926997353190e-01,  1.507793601848234e-02,  
 5.043040025277375e-01,  6.040349373214349e-01,  1.160242726756205e-02,  
 5.113306771546843e-01, -8.975233040638488e-01,  8.023411794220729e-03,  
 5.131329313010590e-01, -9.693478795578427e-01,  4.668299073616817e-03,  
 5.132865237464714e-01,  4.688970718806879e-01,  1.282967010005945e-02,  
 5.176647451047708e-01, -9.983923444453340e-01,  8.821790616867712e-04,  
 5.186382422892405e-01, -5.909018703387654e-01,  8.134241234233111e-03,  
 5.291031884464018e-01, -7.888885157981417e-01,  7.737672122912299e-03,  
 5.351205786493067e-01,  1.662338233527932e-01,  1.523192606517475e-02,  
 5.413187638370147e-01,  7.008354250408056e-01,  9.314699663035950e-03,  
 5.421728509707354e-01,  8.831112721261267e-01,  8.569226685725167e-03,  
 5.467362660936782e-01, -4.682073286935134e-01,  1.236063811528119e-02,  
 5.484074961393921e-01, -6.660476228238359e-01,  1.048532964530446e-02,  
 5.497845124077343e-01, -7.333202414867040e-02,  1.235895418614051e-02,  
 5.748025638560177e-01, -3.067973240959255e-01,  1.707935332348776e-02,  
 5.757548043279564e-01,  9.703367418123594e-01,  3.757168119063795e-03,  
 5.811601592234984e-01,  9.983496902489798e-01,  7.104280334676121e-04,  
 5.864634403080233e-01,  7.932418330534410e-01,  1.112227385834183e-02,  
 5.881718967548081e-01,  3.744506110517851e-01,  1.307998578130345e-02,  
 5.910214836343624e-01, -8.384444159782082e-01,  8.418868716555618e-03,  
 5.939522570295417e-01,  5.310108582117370e-01,  1.096129405119757e-02,  
 5.949690407134853e-01, -9.351174758101611e-01,  5.854723529644378e-03,  
 6.014430739812223e-01,  6.305652605767732e-02,  1.564707540156174e-02,  
 6.031110203472072e-01, -5.107400343109616e-01,  6.474717016434753e-03,  
 6.058697705151179e-01, -9.883839405182854e-01,  2.594759629417247e-03,  
 6.149834556692348e-01, -1.527830270721475e-01,  1.405889213374533e-02,  
 6.191838769193574e-01,  6.420040583801523e-01,  1.067988406928965e-02,  
 6.226576289009583e-01, -7.259246555573967e-01,  1.069584666724211e-02,  
 6.254538870491240e-01,  9.264854004436116e-01,  6.307266862024064e-03,  
 6.314704538659979e-01,  2.446105067220338e-01,  1.537286390141198e-02,  
 6.403455995923052e-01, -5.867373929097057e-01,  1.193450620498925e-02,  
 6.531607555762389e-01,  9.883039600294047e-01,  2.166784944891255e-03,  
 6.582656205134384e-01, -4.038261118251286e-01,  1.497892745877775e-02,  
 6.638595707485085e-01,  4.439193977915850e-01,  1.102925103533717e-02,  
 6.641092110776139e-01, -8.842872475223941e-01,  7.073002093332755e-03,  
 6.652837909761897e-01,  8.550121217464759e-01,  8.720558763742966e-03,  
 6.718973107043948e-01, -9.628615704165838e-01,  3.868709630540442e-03,  
 6.754749986154636e-01,  7.281422316126919e-01,  1.097118103052011e-02,  
 6.779414345191699e-01, -3.063740688329146e-02,  1.447701175069298e-02,  
 6.849076257411216e-01, -2.427166387314666e-01,  1.397568311805146e-02,  
 6.906859319625951e-01, -9.979604128976195e-01,  8.435777152586793e-04,  
 6.909159146496135e-01, -7.887887571343239e-01,  8.977062336109128e-03,  
 6.958360474648256e-01,  5.644565737670422e-01,  1.103743316814278e-02,  
 6.986567532110330e-01,  1.382567167908484e-01,  1.442120114433883e-02,  
 7.032675418563811e-01,  9.600474050632336e-01,  4.157108404417536e-03,  
 7.125260040531168e-01, -6.588957967703316e-01,  1.101941046086741e-02,  
 7.131083800360229e-01,  3.348252722558369e-01,  1.317500343117314e-02,  
 7.243383015839274e-01,  9.980207065293273e-01,  7.199560063855860e-04,  
 7.281406688886811e-01, -5.071254424742396e-01,  1.331196820325115e-02,  
 7.351348537506192e-01, -9.235000024040693e-01,  5.339474521352486e-03,  
 7.391722285237710e-01,  9.062068947141577e-01,  6.258431339300329e-03,  
 7.403849867503648e-01, -9.819171911401473e-01,  2.337724717192945e-03,  
 7.431555210822531e-01,  7.977482842071556e-01,  8.833161716226669e-03,  
 7.459343555200221e-01, -1.236717037454283e-01,  1.296776589532101e-02,  
 7.490155562917605e-01, -3.252336868606283e-01,  9.351093216509690e-03,  
 7.520357832344026e-01,  6.508886285165648e-01,  1.070105581225020e-02,  
 7.555601563064301e-01, -8.414687309753481e-01,  6.891618536870428e-03,  
 7.613061970586104e-01,  4.720892602078328e-01,  1.121593897330926e-02,  
 7.696542328903390e-01, -3.800140053796911e-01,  5.896276097702543e-03,  
 7.703655439710254e-01,  4.177172398061163e-02,  1.320655645297225e-02,  
 7.713573933240646e-01,  2.292623609101414e-01,  1.222664318821314e-02,  
 7.728941799568024e-01,  9.834791267225803e-01,  2.318079830785805e-03,  
 7.753719582521668e-01, -7.296837750586209e-01,  8.830371768634843e-03,  
 7.978946443412313e-01, -5.940088162963154e-01,  1.102206312002593e-02,  
 7.996575186605993e-01, -9.945437983737444e-01,  1.170500089565615e-03,  
 8.013660329335811e-01, -9.549385718300994e-01,  3.667653054187556e-03,  
 8.048061510789419e-01,  3.718357650456645e-01,  8.637973753390449e-03,  
 8.052848747707124e-01, -2.154694645963307e-01,  1.115929240605312e-02,  
 8.055768707550288e-01,  8.588418294042808e-01,  6.546425691890088e-03,  
 8.060880027952726e-01,  9.464168885010812e-01,  4.138102993626548e-03,  
 8.095710479011895e-01,  7.299545306893604e-01,  8.640988335276857e-03,  
 8.131642862712356e-01, -8.855936518041989e-01,  5.172308318006293e-03,  
 8.179555207385244e-01,  5.630877825822931e-01,  1.038670426889326e-02,  
 8.198903592035567e-01, -4.474759410866835e-01,  1.039723732697557e-02,  
 8.302233642792779e-01, -7.887974291015537e-01,  6.403870452065013e-03,  
 8.316280572729237e-01,  9.963536786620084e-01,  8.601012497443448e-04,  
 8.323840732904080e-01, -5.770931774582546e-02,  1.157981674113329e-02,  
 8.345746770920350e-01,  1.348195251852799e-01,  1.086669255897672e-02,  
 8.445552751701417e-01,  2.869258517851172e-01,  7.087178777230579e-03,  
 8.531080996665429e-01, -3.100864425712632e-01,  9.462959763014268e-03,  
 8.561231024886632e-01, -6.768698449375528e-01,  8.653374792867137e-03,  
 8.580096391046452e-01,  4.289163888579028e-01,  7.032590377677609e-03,  
 8.591213496900382e-01, -9.789218555148047e-01,  2.183949091910629e-03,  
 8.618783040518693e-01,  8.015653601725335e-01,  6.476664260979469e-03,  
 8.620920815291837e-01,  9.088307352715838e-01,  4.535170978475270e-03,  
 8.649186611907598e-01,  9.752422585287235e-01,  2.397696219433860e-03,  
 8.653144381651936e-01, -9.229713406820786e-01,  3.786147464455085e-03,  
 8.656342986234824e-01,  6.539955758641589e-01,  8.007673011011452e-03,  
 8.738193544174702e-01, -9.987050363801271e-01,  4.029777384147725e-04,  
 8.746997180248225e-01, -5.337452183276610e-01,  8.969697082860535e-03,  
 8.750871750612564e-01, -8.371208783269141e-01,  4.667481132791865e-03,  
 8.840931476725340e-01, -1.591395148790940e-01,  9.725396029596314e-03,  
 8.863873331866154e-01,  5.014911962761207e-01,  6.732637721829442e-03,  
 8.877478758386065e-01,  3.703102823746122e-02,  9.391237982629010e-03,  
 8.886925006776532e-01, -4.029207162992898e-01,  3.953122632176603e-03,  
 8.914497061411687e-01,  2.063254399354762e-01,  6.379677376597891e-03,  
 8.966458818425863e-01,  3.077535071435578e-01,  5.074492497678043e-03,  
 9.060257668239784e-01, -7.510933281143483e-01,  6.285183519604021e-03,  
 9.069440260746182e-01,  9.948615423994508e-01,  8.460206194961731e-04,  
 9.085091703518080e-01,  7.357866023957996e-01,  5.980225096092428e-03,  
 9.088140552343917e-01,  8.613880826568586e-01,  4.524206023005564e-03,  
 9.097119148344930e-01, -2.791721791436264e-01,  3.325039377988705e-03,  
 9.107962036779229e-01, -9.546466357227235e-01,  2.504361618864681e-03,  
 9.109269835273496e-01,  9.474408959785233e-01,  2.828303409790731e-03,  
 9.116846414755537e-01, -3.946552397032295e-01,  4.799510717398269e-03,  
 9.147536811475745e-01, -8.800465507878222e-01,  3.625599405917247e-03,  
 9.180486167649172e-01,  5.920245031381465e-01,  6.069384535392124e-03,  
 9.188758666484276e-01, -6.191245374224351e-01,  6.822998261844405e-03,  
 9.211332348776220e-01, -9.906945704103310e-01,  1.078080942745430e-03,  
 9.252698678871364e-01,  3.816000875630634e-01,  6.720562662548456e-03,  
 9.303888378867309e-01, -6.224958329536455e-02,  7.669256083745869e-03,  
 9.316323693555080e-01,  1.260692370780684e-01,  6.144629409760324e-03,  
 9.351449029460894e-01, -2.406511548034665e-01,  5.779691515292159e-03,  
 9.392911967713488e-01, -4.855179051814372e-01,  6.174008549382279e-03,  
 9.426467016723202e-01,  9.801477693736759e-01,  1.345953538075658e-03,  
 9.435279532066055e-01,  2.221999393850942e-01,  3.479548412810748e-03,  
 9.454153692097916e-01,  4.969416983931578e-01,  4.614178689184361e-03,  
 9.459596501532294e-01,  8.050199903923727e-01,  4.077330276254603e-03,  
 9.461037891822155e-01, -8.162510788029149e-01,  4.131502513773345e-03,  
 9.477372910934111e-01,  9.097890847623551e-01,  2.819888629654258e-03,  
 9.497373302590694e-01, -9.198416005546896e-01,  2.489219831374708e-03,  
 9.502228126713501e-01,  6.756755603285315e-01,  4.638832336370128e-03,  
 9.543120615194950e-01, -6.978166939707769e-01,  4.657220418242932e-03,  
 9.572722322598644e-01, -9.727383585296555e-01,  1.371820477478312e-03,  
 9.603547491901058e-01, -3.444098104140523e-01,  5.192860463827343e-03,  
 9.618072357953964e-01,  2.840075572844367e-01,  4.584997220482829e-03,  
 9.621685673801630e-01, -9.981498616350863e-01,  2.983264390605248e-04,  
 9.644011406655369e-01,  3.955662605890648e-02,  5.487620385431768e-03,  
 9.648815628338514e-01,  9.976194228266280e-01,  3.422316968868938e-04,  
 9.654793296651025e-01, -1.449151374798731e-01,  4.901363403832491e-03,  
 9.675772091594030e-01, -5.706238471045659e-01,  4.319580505788219e-03,  
 9.688706334298569e-01,  4.266194891481059e-01,  3.409732775774852e-03,  
 9.702051269912042e-01,  9.560511844190226e-01,  1.434791120385777e-03,  
 9.716942423922518e-01,  5.810982845814314e-01,  3.659348716877558e-03,  
 9.748150682339674e-01,  8.630701855337108e-01,  2.379490945836736e-03,  
 9.756611980550673e-01, -8.717067247715160e-01,  2.345719243525908e-03,  
 9.760951773774511e-01,  7.497184921929896e-01,  2.895893718670046e-03,  
 9.794817550638735e-01, -4.308079229171551e-01,  3.138802635622372e-03,  
 9.798298883847092e-01, -7.687042632123031e-01,  2.691125475983456e-03,  
 9.817367673963038e-01, -2.211661902207940e-01,  2.176154471489884e-03,  
 9.820307319973294e-01,  1.607872100549523e-01,  3.959806596474525e-03,  
 9.823718529863428e-01, -9.448695023246775e-01,  1.256965089029987e-03,  
 9.854696330893135e-01, -9.878927125972993e-01,  5.302485898777602e-04,  
 9.864237410369340e-01,  3.474984134057699e-01,  2.626333169195453e-03,  
 9.865494934684096e-01,  9.856652402947823e-01,  5.802863637376822e-04,  
 9.872410998898277e-01, -6.516124343282037e-01,  2.451688694670727e-03,  
 9.885804018012844e-01, -4.855418553020024e-02,  3.260277409726965e-03,  
 9.888908697853098e-01,  9.233667636095402e-01,  1.140018239107126e-03,  
 9.892479265001065e-01,  6.612276378064350e-01,  2.043285817276434e-03,  
 9.900482572019094e-01,  4.985621080229760e-01,  2.242724334598082e-03,  
 9.906699598276788e-01, -2.862146444653838e-01,  2.228303203490404e-03,  
 9.920960970276202e-01, -5.044070130004836e-01,  1.824136223192767e-03,  
 9.929995253631880e-01,  8.129871703624600e-01,  1.347117277977657e-03,  
 9.952342237683616e-01, -8.286466960550624e-01,  1.082707396932906e-03,  
 9.958519119176469e-01, -9.077787403602237e-01,  7.431854366720857e-04,  
 9.963480933133427e-01,  2.479538638037798e-01,  1.491315677106339e-03,  
 9.971099785500591e-01, -9.975224120853297e-01,  7.798442798007867e-05,
 9.972455951936153e-01,  7.187156081293171e-02,  1.410032513903549e-03,  
 9.973396392196245e-01,  9.972222237164891e-01,  8.333752929282447e-05,
 9.976125620794032e-01, -7.261201764578525e-01,  8.279866159627213e-04,  
 9.976963561372271e-01, -9.678687355428703e-01,  3.138082077303478e-04,  
 9.978286522784937e-01,  9.628763075615144e-01,  3.344694660648939e-04,  
 9.982097416579526e-01,  8.832442641091779e-01,  4.604405106623550e-04,  
 9.982434766908749e-01, -3.819333028903024e-01,  9.500630778549490e-04,  
 9.982698924284638e-01,  5.843339960398285e-01,  7.392815641484668e-04,  
 9.983624199159088e-01,  7.311569400195331e-01,  6.234634259867621e-04,  
 9.985517638075939e-01, -1.568937801098068e-01,  1.047965997616771e-03,  
 9.986637711500016e-01, -5.835721439184322e-01,  6.485919247428450e-04,  
 9.988024883360008e-01,  4.104312670989267e-01,  7.247738364520382e-04 };
  double *xw_copy;

  order = square_minimal_rule_order ( degree );
  xw_copy = r8mat_copy_new ( 3, order, xw );

  return xw_copy;
}
/******************************************************************************/

double *square_minimal_rule ( int degree )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE returns a minimal rule for the square.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    20 February 2018

  Author:

    John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Input, int DEGREE, the degree, between 0 and 55.

    Output, double *SQUARE_MINIMAL_RULE[3*O], the rule.
*/
{
  double *xw;

  if ( degree == 0 )
  {
    xw = smr00 ( );
  }
  else if ( degree == 1 )
  {
    xw = smr01 ( );
  }
  else if ( degree == 2 )
  {
    xw = smr02 ( );
  }
  else if ( degree == 3 )
  {
    xw = smr03 ( );
  }
  else if ( degree == 4 )
  {
    xw = smr04 ( );
  }
  else if ( degree == 5 )
  {
    xw = smr05 ( );
  }
  else if ( degree == 6 )
  {
    xw = smr06 ( );
  }
  else if ( degree == 7 )
  {
    xw = smr07 ( );
  }
  else if ( degree == 8 )
  {
    xw = smr08 ( );
  }
  else if ( degree == 9 )
  {
    xw = smr09 ( );
  }
  else if ( degree == 10 )
  {
    xw = smr10 ( );
  }
  else if ( degree == 11 )
  {
    xw = smr11 ( );
  }
  else if ( degree == 12 )
  {
    xw = smr12 ( );
  }
  else if ( degree == 13 )
  {
    xw = smr13 ( );
  }
  else if ( degree == 14 )
  {
    xw = smr14 ( );
  }
  else if ( degree == 15 )
  {
    xw = smr15 ( );
  }
  else if ( degree == 16 )
  {
    xw = smr16 ( );
  }
  else if ( degree == 17 )
  {
    xw = smr17 ( );
  }
  else if ( degree == 18 )
  {
    xw = smr18 ( );
  }
  else if ( degree == 19 )
  {
    xw = smr19 ( );
  }
  else if ( degree == 20 )
  {
    xw = smr20 ( );
  }
  else if ( degree == 21 )
  {
    xw = smr21 ( );
  }
  else if ( degree == 22 )
  {
    xw = smr22 ( );
  }
  else if ( degree == 23 )
  {
    xw = smr23 ( );
  }
  else if ( degree == 24 )
  {
    xw = smr24 ( );
  }
  else if ( degree == 25 )
  {
    xw = smr25 ( );
  }
  else if ( degree == 26 )
  {
    xw = smr26 ( );
  }
  else if ( degree == 27 )
  {
    xw = smr27 ( );
  }
  else if ( degree == 28 )
  {
    xw = smr28 ( );
  }
  else if ( degree == 29 )
  {
    xw = smr29 ( );
  }
  else if ( degree == 30 )
  {
    xw = smr30 ( );
  }
  else if ( degree == 31 )
  {
    xw = smr31 ( );
  }
  else if ( degree == 32 )
  {
    xw = smr32 ( );
  }
  else if ( degree == 33 )
  {
    xw = smr33 ( );
  }
  else if ( degree == 34 )
  {
    xw = smr34 ( );
  }
  else if ( degree == 35 )
  {
    xw = smr35 ( );
  }
  else if ( degree == 36 )
  {
    xw = smr36 ( );
  }
  else if ( degree == 37 )
  {
    xw = smr37 ( );
  }
  else if ( degree == 38 )
  {
    xw = smr38 ( );
  }
  else if ( degree == 39 )
  {
    xw = smr39 ( );
  }
  else if ( degree == 40 )
  {
    xw = smr40 ( );
  }
  else if ( degree == 41 )
  {
    xw = smr41 ( );
  }
  else if ( degree == 42 )
  {
    xw = smr42 ( );
  }
  else if ( degree == 43 )
  {
    xw = smr43 ( );
  }
  else if ( degree == 44 )
  {
    xw = smr44 ( );
  }
  else if ( degree == 45 )
  {
    xw = smr45 ( );
  }
  else if ( degree == 46 )
  {
    xw = smr46 ( );
  }
  else if ( degree == 47 )
  {
    xw = smr47 ( );
  }
  else if ( degree == 48 )
  {
    xw = smr48 ( );
  }
  else if ( degree == 49 )
  {
    xw = smr49 ( );
  }
  else if ( degree == 50 )
  {
    xw = smr50 ( );
  }
  else if ( degree == 51 )
  {
    xw = smr51 ( );
  }
  else if ( degree == 52 )
  {
    xw = smr52 ( );
  }
  else if ( degree == 53 )
  {
    xw = smr53 ( );
  }
  else if ( degree == 54 )
  {
    xw = smr54 ( );
  }
  else if ( degree == 55 )
  {
    xw = smr55 ( );
  }
  else
  {
    xw = NULL;
    printf ( "\n" );
    printf ( "SQUARE_MINIMAL_RULE - Fatal error!\n" );
    printf ( "  0 <= DEGREE <= 55 is required.\n" );
    exit ( 1 );
  }

  return xw;
}
/******************************************************************************/

int square_minimal_rule_degree_max ( )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE_DEGREE_MAX returns the maximum rule degree.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    20 February 2018

  Author:

    John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Output, integer DEGREE_MAX, the maximum degree of the minimal
    rules for the square.
*/
{
  const int degree_max = 55;

  return degree_max;
}
/******************************************************************************/

double square_minimal_rule_error_max ( int degree )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE_ERROR_MAX returns the maximum error.

  Discussion:

    The rule of given DEGREE should theoretically have zero error
    for all monomials of degrees 0 <= D <= DEGREE.  This function
    checks every such monomial and reports the maximum error.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    22 February 2018

  Author:

    John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Input, int DEGREE, the desired total polynomial degree exactness
    of the quadrature rule.

    Output, double SQUARE_MINIMAL_RULE_ERROR_MAX, the maximum error observed 
    when using the rule to compute the integrals of all monomials of degree 
    between 0 and DEGREE.
*/
{
  int d;
  int e[2];
  double err;
  double error_max;
  double exact;
  int i;
  int j;
  int k;
  int order;
  double s;
  double *xyw;

  order = square_minimal_rule_order ( degree );
  xyw = square_minimal_rule ( degree );

  error_max = 0.0;

  for ( d = 0; d <= degree; d++ )
  {
    for ( i = 0; i <= d; i++ )
    {
      j = d - i;
      e[0] = i;
      e[1] = j;
      exact = squaresym_monomial_integral ( e );
      s = 0.0;
      for ( k = 0; k < order; k++ )
      {
        s = s + xyw[2+k*3] * pow ( xyw[0+k*3], i ) * pow ( xyw[1+k*3], j );
      }
      err = fabs ( exact - s );
      if ( error_max < err )
      {
        error_max = err;
      }
    }
  }

  return error_max;
}
/******************************************************************************/

int square_minimal_rule_order ( int degree )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MINIMAL_RULE_ORDER returns the order of a minimal square rule.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    20 February 2018

  Author:

    John Burkardt.

  Reference:

    Mattia Festa, Alvise Sommariva,
    Computing almost minimal formulas on the square,
    Journal of Computational and Applied Mathematics,
    Volume 17, Number 236, November 2012, pages 4296-4302.

  Parameters:

    Input, int DEGREE, the degree of the rule,
    between 0 and 55.

    Output, int SQUARE_MINIMAL_RULE_ORDER, the order of the rule.
*/
{
  int degree_max;
  int order;
  int order_list[56] = {
    1,    1,    3,    4,    6,
    7,   10,   12,   16,   17,   
   22,   24,   31,   33,   40,   
   43,   52,   54,   64,   67,   
   78,   81,   93,   96,  109,  
  113,  127,  132,  146,  153,  
  167,  172,  189,  197,  211,  
  220,  238,  245,  265,  274,  
  296,  303,  326,  331,  353,  
  359,  387,  396,  417,  427,  
  454,  462,  493,  498,  530,  
  536 };

  degree_max = square_minimal_rule_degree_max ( );

  if ( degree < 0 )
  {
    order = 0;
  }
  else if ( degree_max < degree )
  {
    order = 0;
  }
  else
  {
    order = order_list[degree];
  }

  return order;
}
/******************************************************************************/

double squaresym_area ( )

/******************************************************************************/
/*
  Purpose:

    SQUARESYM_AREA: area of the symmetric unit square in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2018

  Author:

    John Burkardt

  Parameters:

    Output, double SQUARE01_AREA, the area.
*/
{
  double area;

  area = 4.0;

  return area;
}
/******************************************************************************/

double squaresym_monomial_integral ( int e[2] )

/******************************************************************************/
/*
  Purpose:

    SQUARESYM_MONOMIAL_INTEGRAL: integrals over the symmetric unit square in 2D.

  Discussion:

    The integration region is 

      -1 <= X <= 1,
      -1 <= Y <= 1.

    The monomial is F(X,Y) = X^E(1) * Y^E(2).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2018

  Author:

    John Burkardt

  Reference:

    Philip Davis, Philip Rabinowitz,
    Methods of Numerical Integration,
    Second Edition,
    Academic Press, 1984, page 263.

  Parameters:

    Input, int E[2], the exponents.  
    Each exponent must be nonnegative.

    Output, double SQUARESYM_MONOMIAL_INTEGRAL, the integral.
*/
{
  int i;
  double integral;
  const int m = 2;

  for ( i = 0; i < m; i++ )
  {
    if ( e[i] < 0 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "SQUARESYM_MONOMIAL_INTEGRAL - Fatal error!\n" );
      fprintf ( stderr, "  All exponents must be nonnegative.\n" );
      fprintf ( stderr, "  E[%d] = %d\n", i, e[i] );
      exit ( 1 );
    }
  }

  if ( ( e[0] % 2 ) == 1 || ( e[1] % 2 ) == 1 )
  {
    integral = 0.0;
  }
  else
  {
    integral = 4.0
      / ( double ) ( e[0] + 1 ) 
      / ( double ) ( e[1] + 1 );
  }

  return integral;
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


