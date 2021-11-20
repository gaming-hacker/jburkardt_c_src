# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int main ( int argc, char *argv[] );
void assemble_newton ( double adiag[], double aleft[], double arite[], 
  double f[], double fold[], double h[], int indx[], int n, int nl, 
  int node[], int nquad, int nu, int problem, double ul, double ur, 
  double xn[], double xquad[] );
void assemble_picard ( double adiag[], double aleft[], double arite[], 
  double f[], double fold[], double h[], int indx[], int n, int nl, 
  int node[], int nquad, int nu, int problem, double ul, double ur, 
  double xn[], double xquad[] );
void compare ( double f[], int indx[], int n, int nl, int node[], int nprint, 
  int nu, int problem, double ul, double ur, double xl, double xn[], 
  double xr );
double ff ( double x, int problem );
void geometry ( double h[], int ibc, int indx[], int nl, int node[], int nsub, 
  int *nu, double xl, double xn[], double xquad[], double xr );
void init ( int *ibc, int *imax, int *nprint, int *nquad, int problem, 
  double *ul, double *ur, double *xl, double *xr );
void output ( double f[], int ibc, int indx[], int nsub, int nu, double ul, 
  double ur, double xn[] );
void phi ( int il, double x, double *phii, double *phiix, double xleft, 
  double xrite );
double pp ( double x, int problem );
void prsys ( double adiag[], double aleft[], double arite[], double f[], 
  int nu );
double qq ( double x, int problem );
void solve ( double adiag[], double aleft[], double arite[], double f[], 
  int nu );
void timestamp ( );
double u_exact ( double x, int problem );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for FEM1D_NONLINEAR.

  Discussion:

    FEM1D_NONLINLEAR solves a nonlinear one dimensional boundary value problem.

    The differential equation has the form:

      -d/dx (p(x) du/dx) + q(x)*u + u*u' =  f(x)

    The finite-element method uses piecewise linear basis functions.

    Here U is an unknown scalar function of X defined on the
    interval [XL,XR], and P, Q and F are given functions of X.

    The values of U or U' at XL and XR are also specified.

    Sample problem #1:

    u(x)  = x,
    p(x)  = 1,
    q(x)  = 0,
    f(x)  = x,
    u(0)  = 0,
    u'(1) = 1.
    The code should solve this problem exactly.

    Sample problem #2:

    u(x)  = 2*(1-cos(0.5*pi*x))/pi,
    p(x)  = 1,
    q(x)  = 0,
    f(x)  = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0)  = 0,
    u'(1) = 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2019

  Author:

    C version by John Burkardt

  Parameters:

    double ADIAG(NU).
    ADIAG(I) is the "diagonal" coefficient of the I-th
    equation in the linear system.  That is, ADIAG(I) is
    the coefficient of the I-th unknown in the I-th equation.

    double ALEFT(NU).
    ALEFT(I) is the "left hand" coefficient of the I-th
    equation in the linear system.  That is, ALEFT(I) is the
    coefficient of the (I-1)-th unknown in the I-th equation.
    There is no value in ALEFT(1), since the first equation
    does not refer to a "0-th" unknown.

    double ARITE(NU).
    ARITE(I) is the "right hand" coefficient of the I-th
    equation in the linear system.  ARITE(I) is the coefficient
    of the (I+1)-th unknown in the I-th equation.  There is
    no value in ARITE(NU) because the NU-th equation does not
    refer to an "NU+1"-th unknown.

    double F(NU).
    ASSEMBLE stores into F the right hand side of the linear
    equations.
    SOLVE replaces those values of F by the solution of the
    linear equations.

    double FOLD(NU).
    FOLD contains the value of F from the previous iteration,
    and is used in ASSEMBLE to add correction terms to the
    matrix and right hand side.

    double H(N), the length of the subintervals.  

    int IBC.
    IBC declares what the boundary conditions are.
    1, at the left endpoint, U has the value UL,
       at the right endpoint, U' has the value UR.
    2, at the left endpoint, U' has the value UL,
       at the right endpoint, U has the value UR.
    3, at the left endpoint, U has the value UL,
       and at the right endpoint, U has the value UR.
    4, at the left endpoint, U' has the value UL,
       at the right endpoint U' has the value UR.

    int IMAX.
    The number of Newton iterations to carry out.

    int INDX(0:N).
    For a node I, INDX(I) is the index of the unknown
    associated with node I.
    If INDX(I) is equal to -1, then no unknown is associated
    with the node, because a boundary condition fixing the
    value of U has been applied at the node instead.
    Unknowns are numbered beginning with 1.
    If IBC is 2 or 4, then there is an unknown value of U
    at node 0, which will be unknown number 1.  Otherwise,
    unknown number 1 will be associated with node 1.
    If IBC is 1 or 4, then there is an unknown value of U
    at node N, which will be unknown N or N+1,
    depending on whether there was an unknown at node 0.

    int NL.
    The number of basis functions used in a single
    subinterval.  (NL-1) is the degree of the polynomials
    used.  For this code, NL is fixed at 2, meaning that
    piecewise linear functions are used as the basis.

    int NODE(NL,N).
    For each subinterval I:
    NODE(1,I) is the number of the left node, and
    NODE(2,I) is the number of the right node.

    int NPRINT.
    The number of points at which the computed solution
    should be printed out when compared to the exact solution.

    int NQUAD.
    The number of quadrature points used in a subinterval.
    This code uses NQUAD = 1.

    int N.
    The number of subintervals into which the interval
    [XL,XR] is broken.

    int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be N-1,
    N, or N+1 unknown values, which are the coefficients
    of basis functions.

    int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    double UL.
    If IBC is 1 or 3, UL is the value that U is required
    to have at X = XL.
    If IBC is 2 or 4, UL is the value that U' is required
    to have at X = XL.

    double UR.
    If IBC is 2 or 3, UR is the value that U is required
    to have at X = XR.
    If IBC is 1 or 4, UR is the value that U' is required
    to have at X = XR.

    double XL.
    XL is the left endpoint of the interval over which the
    differential equation is being solved.

    double XN(0:N).
    XN(I) is the location of the I-th node.  XN(0) is XL,
    and XN(N) is XR.

    double XQUAD(N)
    XQUAD(I) is the location of the single quadrature point
    in interval I.

    double XR.
    XR is the right endpoint of the interval over which the
    differential equation is being solved.
*/
{
# define N 10
# define NL 2

  double adiag[N+1];
  double aleft[N+1];
  double arite[N+1];
  double f[N+1];
  double fold[N+1];
  double h[N];
  int i;
  int ibc;
  int imax;
  int indx[N+1];
  int j;
  int node[NL*N];
  int nprint;
  int nquad;
  int nu;
  int problem;
  double ul;
  double ur;
  double xl;
  double xn[N+1];
  double xquad[N];
  double xr;

  timestamp ( );

  printf ( "\n" );
  printf ( "FEM1D_NONLINEAR\n" );
  printf ( "  C version\n" );
  printf ( "\n" );
  printf ( "  Solve a nonlinear boundary value problem:\n" );
  printf ( "\n" );
  printf ( "    -d/dx (p(x) du/dx) + q(x)*u + u*u' = f(x)\n" );
  printf ( "\n" );
  printf ( "  on an interval [xl,xr], with the values of\n" );
  printf ( "  u or u' specified at xl and xr.\n" );
  printf ( "\n" );
  printf ( "  The interval [XL,XR] is broken into N = %d subintervals\n", N );
  printf ( "  Number of basis functions per element is NL = %d\n", NL );
/*
  PROBLEM specifies the problem, and should be 1 or 2.
*/
  if ( 1 < argc )
  {
    problem = atoi ( argv[1] );
/*
  s_to_i4 ( argv[1], &length, &ierror );
*/
  }
  else
  {
    printf ( "\n" );
    printf ( "FEM1D_NONLINEAR:\n" );
    printf ( "  Please enter the problem number (1 or 2):\n" );
    scanf ( "%d", &problem );
  }

  if ( problem < 1 || 2 < problem )
  {
    printf ( "n" );
    printf ( "FEM1D_NONLINEAR\n" );
    printf ( "  Illegal input value, PROBLEM = %d\n", problem );
    exit ( 1 );
  }
/*
  Initialize variables that define the problem.
*/
  init ( &ibc, &imax, &nprint, &nquad, problem, &ul, &ur, &xl, &xr );
/*
  Compute the quantities that describe the geometry of the problem.
*/
  geometry ( h, ibc, indx, NL, node, N, &nu, xl, xn, xquad, xr );
/*
  Initialize the "previous" solution to 0.
*/
  for ( i = 0; i < nu; i++ )
  {
    fold[i] = 0.0;
  }
/*
  Begin the iteration.
*/
  for ( i = 1; i <= imax; i++ )
  {
/*
  Is it time for full nonlinear Newton iteration?
*/
    if ( i <= 3 )
    {
    assemble_picard ( adiag, aleft, arite, f, fold, h, indx, N, NL, node, 
      nquad, nu, problem, ul, ur, xn, xquad );
    }
    else
    {
    assemble_newton ( adiag, aleft, arite, f, fold, h, indx, N, NL, node, 
      nquad, nu, problem, ul, ur, xn, xquad );
    }
/*
  Print out the linear system, just once.
*/
    if ( i == 1 )
    {
      prsys ( adiag, aleft, arite, f, nu );
    }
/*
  Solve the linear system.
*/
    solve ( adiag, aleft, arite, f, nu );
/*
  Print the current solution.
*/
    output ( f, ibc, indx, N, nu, ul, ur, xn );
/*
  Save a copy of the current solution in FOLD.
*/
    for ( j = 0; j < nu; j++ )
    {
      fold[j] = f[j];
    }
  }
/*
  Compare the solution to the exact solution.
*/
  compare ( f, indx, N, NL, node, nprint, nu, problem, ul, ur, xl, xn, xr );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "FEM1D_NONLINEAR:\n" );
  printf ( "  Normal end of execution.\n" );

  printf ( "\n" );
  timestamp ( );

  return 0;
# undef N
# undef NL
}
/******************************************************************************/

void assemble_newton ( double adiag[], double aleft[], double arite[], 
  double f[], double fold[], double h[], int indx[], int n, int nl, 
  int node[], int nquad, int nu, int problem, double ul, double ur, 
  double xn[], double xquad[] )

/******************************************************************************/
/*
  Purpose:

    ASSEMBLE_NEWTON assembles the Newton linear system.

  Discussion:

    The linear system being solved here is for the Newton correction
    to an approximate solution of a nonlinear system.

    Thus, we suppose that we have a nonlinear function F(X),
    and an approximate solution X0.  If we can suppose there is an
    exact solution X* that is "nearby", and in fact close enough
    that Taylor's theorem gives us a useful estimate, then we
    may write:

      F(X*) = F(X0) + F'(X0) * ( X* - X0 ) + Order ( X* - X0 )^2 

    and by rearranging, we get the Newton system (which is only
    approximately correct):

      F'(X0) * ( X* - X0 ) = - F(X0)

    We solve this system and add the solution to X0 to get a
    new approximate solution that, we hope, is much improved.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Output, double ADIAG(NU).
    ADIAG(I) is the "diagonal" coefficient of the I-th
    equation in the linear system.  That is, ADIAG(I) is
    the coefficient of the I-th unknown in the I-th equation.

    Output, double ALEFT(NU).
    ALEFT(I) is the "left hand" coefficient of the I-th
    equation in the linear system.  That is, ALEFT(I) is the
    coefficient of the (I-1)-th unknown in the I-th equation.
    There is no value in ALEFT(1), since the first equation
    does not refer to a "0-th" unknown.

    Output, double ARITE(NU).
    ARITE(I) is the "right hand" coefficient of the I-th
    equation in the linear system.  ARITE(I) is the coefficient
    of the (I+1)-th unknown in the I-th equation.  There is
    no value in ARITE(NU) because the NU-th equation does not
    refer to an "NU+1"-th unknown.

    Output, double F(NU), the right hand side of the linear
    equations.

    Input, double FOLD(NU), the solution value 
    from the previous iteration,

    Input, double H(N), the length of the subintervals.  

    Input, int INDX(0:N).
    For a node I, INDX(I) is the index of the unknown
    associated with node I.
    If INDX(I) is equal to -1, then no unknown is associated
    with the node, because a boundary condition fixing the
    value of U has been applied at the node instead.
    Unknowns are numbered beginning with 1.
    If IBC is 2 or 4, then there is an unknown value of U
    at node 0, which will be unknown number 1.  Otherwise,
    unknown number 1 will be associated with node 1.
    If IBC is 1 or 4, then there is an unknown value of U
    at node N, which will be unknown N or N+1,
    depending on whether there was an unknown at node 0.

    Input, int N.
    The number of subintervals into which the interval
    [XL,XR] is broken.

    Input, int NL.
    The number of basis functions used in a single
    subinterval.  (NL-1) is the degree of the polynomials
    used.  For this code, NL is fixed at 2, meaning that
    piecewise linear functions are used as the basis.

    Input, int NODE(NL,N).
    For each subinterval I:
    NODE(1,I) is the number of the left node, and
    NODE(2,I) is the number of the right node.

    Input, int NQUAD.
    The number of quadrature points used in a subinterval.
    This code uses NQUAD = 1.

    Input, int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be N-1,
    N, or N+1 unknown values, which are the coefficients
    of basis functions.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Input, double UL.
    If IBC is 1 or 3, UL is the value that U is required
    to have at X = XL.
    If IBC is 2 or 4, UL is the value that U' is required
    to have at X = XL.

    Input, double UR.
    If IBC is 2 or 3, UR is the value that U is required
    to have at X = XR.
    If IBC is 1 or 4, UR is the value that U' is required
    to have at X = XR.

    Input, double XN(0:N).
    XN(I) is the location of the I-th node.  XN(0) is XL,
    and XN(N) is XR.

    Input, double XQUAD(N)
    XQUAD(I) is the location of the single quadrature point
    in interval I.
*/
{
  double aij;
  double he;
  int i;
  int ie;
  int ig;
  int il;
  int iu;
  int iul;
  int iur;
  int iq;
  int jg;
  int jl;
  int jr;
  int ju;
  double phii;
  double phiix;
  double phij;
  double phijx;
  double total;
  double uold;
  double uoldx;
  double x;
  double xleft;
  double xqe;
  double xrite;

  for ( i = 0; i < nu; i++ )
  {
    f[i] = 0.0;
  }
  for ( i = 0; i < nu; i++ )
  {
    adiag[i] = 0.0;
  }
  for ( i = 0; i < nu; i++ )
  {
    aleft[i] = 0.0;
  }
  for ( i = 0; i < nu; i++ )
  {
    arite[i] = 0.0;
  }
/*
  For element IE...
*/
  for ( ie = 0; ie < n; ie++ )
  {
    he = h[ie];
    xleft = xn[node[0+ie*2]];
    xrite = xn[node[1+ie*2]];
/*
  For quadrature point IQ...
*/
    for ( iq = 0; iq < nquad; iq++ )
    {
      xqe = xquad[ie];
/*
  Compute value of U for previous solution.
*/
      total = 0.0;

      for ( il = 1; il <= nl; il++ )
      {
        ig = node[il-1+ie*2];
        iu = indx[ig] - 1;

        if ( iu < 0 )
        {
          if ( il == 1 )
          {
            total = total + ul;
          }
          else
          {
            total = total + ur;
          }
        }
        else
        {
          total = total + fold[iu];
        }
      }

      uold = total / ( double ) ( nl );
/*
  Compute value of U' for previous solution.
*/
      jl = node[0+ie*2];
      jr = node[1+ie*2];
      iul = indx[jl] - 1;
      iur = indx[jr] - 1;

      if ( iul < 0 )
      {
        uoldx = ( fold[iur] - ul ) / he;
      }
      else if ( iur < 0 )
      {
        uoldx = ( ur - fold[iul] ) / he;
      }
      else
      {
        uoldx = ( fold[iur] - fold[iul] ) / he;
      }
/*
  For basis function IL...
*/
      for ( il = 1; il <= nl; il++ )
      {
        ig = node[il-1+ie*2];
        iu = indx[ig] - 1;

        if ( 0 <= iu )
        {
          phi ( il, xqe, &phii, &phiix, xleft, xrite );

          f[iu] = f[iu] + he * phii * ( ff ( xqe, problem ) + uold * uoldx );
/*
  Handle boundary conditions that prescribe the value of U'.
*/
          if ( ig == 0 )
          {
            x = 0.0;
            f[iu] = f[iu] - pp ( x, problem ) * ul;
          }
          else if ( ig == n )
          {
            x = 1.0;
            f[iu] = f[iu] + pp ( x, problem ) * ur;
          }
/*
  For basis function JL...
*/
          for ( jl = 1; jl <= nl; jl++ )
          {
            jg = node[jl-1+ie*2];
            ju = indx[jg] - 1;

            phi ( jl, xqe, &phij, &phijx, xleft, xrite );

            aij = he * ( pp ( xqe, problem ) * phiix * phijx 
                  + qq ( xqe, problem ) * phii * phij 
                  + uold * phii * phijx 
                  + uoldx * phij * phii );

            if ( ju < 0 )
            {
              if ( jg == 0 )
              {
                f[iu] = f[iu] - aij * ul;
              }
              else if ( jg == n )
              {
                f[iu] = f[iu] - aij * ur;
              }
            }
            else if ( iu == ju )
            {
              adiag[iu] = adiag[iu] + aij;
            }
            else if ( ju < iu )
            {
              aleft[iu] = aleft[iu] + aij;
            }
            else
            {
              arite[iu] = arite[iu] + aij;
            }
          }
        }
      }
    }
  }

  return;
}
/******************************************************************************/

void assemble_picard ( double adiag[], double aleft[], double arite[], 
  double f[], double fold[], double h[], int indx[], int n, int nl, 
  int node[], int nquad, int nu, int problem, double ul, double ur, 
  double xn[], double xquad[] )

/******************************************************************************/
/*
  Purpose:

    ASSEMBLE_PICARD assembles the Picard linear system.

  Discussion:

    The equation we are trying to solve has the form:

      -d/dx ( p(x) du/dx ) + q(x) * u + u * u' = f(x)

    For the Picard iteration, we need to modify the nonlinear term u * u'
    so that it is linear in the unknown u, and any other factors of u are
    lagged.  One way to do this gives us the following equation:

      -d/dx ( p(x) du/dx ) + q(x) * u + u * uold' = f(x)

    where uold is the previous iterate.

    Now we can formulate this system as a (linear) finite element problem

      A * u = rhs

    to be solved for the new approximate solution u.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Output, double ADIAG(NU).
    ADIAG(I) is the "diagonal" coefficient of the I-th
    equation in the linear system.  That is, ADIAG(I) is
    the coefficient of the I-th unknown in the I-th equation.

    Output, double ALEFT(NU).
    ALEFT(I) is the "left hand" coefficient of the I-th
    equation in the linear system.  That is, ALEFT(I) is the
    coefficient of the (I-1)-th unknown in the I-th equation.
    There is no value in ALEFT(1), since the first equation
    does not refer to a "0-th" unknown.

    Output, double ARITE(NU).
    ARITE(I) is the "right hand" coefficient of the I-th
    equation in the linear system.  ARITE(I) is the coefficient
    of the (I+1)-th unknown in the I-th equation.  There is
    no value in ARITE(NU) because the NU-th equation does not
    refer to an "NU+1"-th unknown.

    Output, double F(NU), the right hand side of the linear
    equations.

    Input, double FOLD(NU), the solution value 
    from the previous iteration,

    Input, double H(N), the length of the subintervals.  

    Input, int INDX(0:N).
    For a node I, INDX(I) is the index of the unknown
    associated with node I.
    If INDX(I) is equal to -1, then no unknown is associated
    with the node, because a boundary condition fixing the
    value of U has been applied at the node instead.
    Unknowns are numbered beginning with 1.
    If IBC is 2 or 4, then there is an unknown value of U
    at node 0, which will be unknown number 1.  Otherwise,
    unknown number 1 will be associated with node 1.
    If IBC is 1 or 4, then there is an unknown value of U
    at node N, which will be unknown N or N+1,
    depending on whether there was an unknown at node 0.

    Input, int N.
    The number of subintervals into which the interval
    [XL,XR] is broken.

    Input, int NL.
    The number of basis functions used in a single
    subinterval.  (NL-1) is the degree of the polynomials
    used.  For this code, NL is fixed at 2, meaning that
    piecewise linear functions are used as the basis.

    Input, int NODE(NL,N).
    For each subinterval I:
    NODE(1,I) is the number of the left node, and
    NODE(2,I) is the number of the right node.

    Input, int NQUAD.
    The number of quadrature points used in a subinterval.
    This code uses NQUAD = 1.

    Input, int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be N-1,
    N, or N+1 unknown values, which are the coefficients
    of basis functions.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Input, double UL.
    If IBC is 1 or 3, UL is the value that U is required
    to have at X = XL.
    If IBC is 2 or 4, UL is the value that U' is required
    to have at X = XL.

    Input, double UR.
    If IBC is 2 or 3, UR is the value that U is required
    to have at X = XR.
    If IBC is 1 or 4, UR is the value that U' is required
    to have at X = XR.

    Input, double XN(0:N).
    XN(I) is the location of the I-th node.  XN(0) is XL,
    and XN(N) is XR.

    Input, double XQUAD(N)
    XQUAD(I) is the location of the single quadrature point
    in interval I.
*/
{
  double aij;
  double he;
  int i;
  int ie;
  int ig;
  int il;
  int iu;
  int iq;
  int jg;
  int jl;
  int ju;
  double phii;
  double phiix;
  double phij;
  double phijx;
  double total;
  double uold;
  double x;
  double xleft;
  double xqe;
  double xrite;

  for ( i = 0; i < nu; i++ )
  {
    f[i] = 0.0;
  }
  for ( i = 0; i < nu; i++ )
  {
    adiag[i] = 0.0;
  }
  for ( i = 0; i < nu; i++ )
  {
    aleft[i] = 0.0;
  }
  for ( i = 0; i < nu; i++ )
  {
    arite[i] = 0.0;
  }
/*
  For element IE...
*/
  for ( ie = 0; ie < n; ie++ )
  {
    he = h[ie];
    xleft = xn[node[0+ie*2]];
    xrite = xn[node[1+ie*2]];
/*
  For quadrature point IQ...
*/
    for ( iq = 0; iq < nquad; iq++ )
    {
      xqe = xquad[ie];
/*
  Compute value of U for previous solution.
*/
      total = 0.0;

      for ( il = 1; il <= nl; il++ )
      {
        ig = node[il-1+ie*2];
        iu = indx[ig] - 1;

        if ( iu < 0 )
        {
          if ( il == 1 )
          {
            total = total + ul;
          }
          else
          {
            total = total + ur;
          }
        }
        else
        {
          total = total + fold[iu];
        }
      }

      uold = total / ( double ) ( nl );
/*
  Compute value of U' for previous solution.
*/
      jl = node[0+ie*2];
/*
  For basis function IL...
*/
      for ( il = 1; il <= nl; il++ )
      {
        ig = node[il-1+ie*2];
        iu = indx[ig] - 1;

        if ( 0 <= iu )
        {
          phi ( il, xqe, &phii, &phiix, xleft, xrite );

          f[iu] = f[iu] + he * phii * ( ff ( xqe, problem ) );
/*
  Handle boundary conditions that prescribe the value of U'.
*/
          if ( ig == 0 )
          {
            x = 0.0;
            f[iu] = f[iu] - pp ( x, problem ) * ul;
          }
          else if ( ig == n )
          {
            x = 1.0;
            f[iu] = f[iu] + pp ( x, problem ) * ur;
          }
/*
  For basis function JL...
*/
          for ( jl = 1; jl <= nl; jl++ )
          {
            jg = node[jl-1+ie*2];
            ju = indx[jg] - 1;

            phi ( jl, xqe, &phij, &phijx, xleft, xrite );

            aij = he * ( pp ( xqe, problem ) * phiix * phijx 
                  + qq ( xqe, problem ) * phii * phij 
                  + uold * phii * phijx );

            if ( ju < 0 )
            {
              if ( jg == 0 )
              {
                f[iu] = f[iu] - aij * ul;
              }
              else if ( jg == n )
              {
                f[iu] = f[iu] - aij * ur;
              }
            }
            else if ( iu == ju )
            {
              adiag[iu] = adiag[iu] + aij;
            }
            else if ( ju < iu )
            {
              aleft[iu] = aleft[iu] + aij;
            }
            else
            {
              arite[iu] = arite[iu] + aij;
            }
          }
        }
      }
    }
  }

  return;
}
/******************************************************************************/

void compare ( double f[], int indx[], int n, int nl, int node[], int nprint, 
  int nu, int problem, double ul, double ur, double xl, double xn[], 
  double xr )

/******************************************************************************/
/*
  Purpose:

    COMPARE compares the computed and exact solutions.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, double F(NU), the solution of the linear equations.

    Input, int INDX(0:N).
    For a node I, INDX(I) is the index of the unknown
    associated with node I.
    If INDX(I) is equal to -1, then no unknown is associated
    with the node, because a boundary condition fixing the
    value of U has been applied at the node instead.
    Unknowns are numbered beginning with 1.
    If IBC is 2 or 4, then there is an unknown value of U
    at node 0, which will be unknown number 1.  Otherwise,
    unknown number 1 will be associated with node 1.
    If IBC is 1 or 4, then there is an unknown value of U
    at node N, which will be unknown N or N+1,
    depending on whether there was an unknown at node 0.

    Input, int N.
    The number of subintervals into which the interval
    [XL,XR] is broken.

    Input, int NL.
    The number of basis functions used in a single
    subinterval.  (NL-1) is the degree of the polynomials
    used.  For this code, NL is fixed at 2, meaning that
    piecewise linear functions are used as the basis.

    Input, int NODE(NL,N).
    For each subinterval I:
    NODE(1,I) is the number of the left node, and
    NODE(2,I) is the number of the right node.

    Input, int NPRINT.
    The number of points at which the computed solution
    should be printed out when compared to the exact solution.

    Input, int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be N-1,
    N, or N+1 unknown values, which are the coefficients
    of basis functions.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Input, double UL.
    If IBC is 1 or 3, UL is the value that U is required
    to have at X = XL.
    If IBC is 2 or 4, UL is the value that U' is required
    to have at X = XL.

    Input, double UR.
    If IBC is 2 or 3, UR is the value that U is required
    to have at X = XR.
    If IBC is 1 or 4, UR is the value that U' is required
    to have at X = XR.

    Input, double XL.
    XL is the left endpoint of the interval over which the
    differential equation is being solved.

    Input, double XN(0:N).
    XN(I) is the location of the I-th node.  XN(0) is XL,
    and XN(N) is XR.

    Input, double XR.
    XR is the right endpoint of the interval over which the
    differential equation is being solved.
*/
{
  int i;
  int ig;
  int iu;
  int j;
  int k;
  double phii;
  double phiix;
  double u;
  double ux;
  double x;
  double xleft;
  double xrite;

  printf ( "\n" );
  printf ( "Compare computed and exact solutions:\n" );
  printf ( "\n" );
  printf ( "      X      Computed U      Exact U\n" );
  printf ( "\n" );

  for ( i = 1; i <= nprint; i++ )
  {
    x = ( ( double ) ( nprint - i     ) * xl   
        + ( double ) (          i - 1 ) * xr ) 
        / ( double ) ( nprint     - 1 );

    ux = u_exact ( x, problem );

    for ( j = 1; j <= n; j++ )
    {
      xleft = xn[j-1];
      xrite = xn[j];
/*
  Search for the interval that X lies in.
*/
      if ( xleft <= x && x <= xrite )
      {
        u = 0.0;

        for ( k = 1; k <= nl; k++ )
        {
          ig = node[k-1+(j-1)*2];
          iu = indx[ig];
          phi ( k, x, &phii, &phiix, xleft, xrite );

          if ( iu <= 0 )
          {
            if ( j == 1 && k == 1 )
            {
              u = u + ul * phii;
            }
            else if ( j == n && k == nl )
            {
              u = u + ur * phii;
            }
          }
          else
          {
            u = u + f[iu-1] * phii;
          }
        }
        break;
      }
    }
    printf ( "  %12g  %12g  %12g\n", x, u, ux );
  }

  return;
}
/******************************************************************************/

double ff ( double x, int problem )

/******************************************************************************/
/*
  Purpose:

    FF returns the right hand side of the differential equation.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, double X, the evaluation point.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Output, double FF, the value of F(X).
*/
{
  double pi = 3.141592653589793;
  double value;
/*
  Test problem 1
*/
  if ( problem == 1 )
  {
    value = x;
  }
/*
  Test problem 2
*/
  else if ( problem == 2 )
  {
    value = - 0.5 * pi * cos ( 0.5 * pi * x ) 
      + 2.0 * sin ( 0.5 * pi * x ) 
      * ( 1.0 - cos ( 0.5 * pi * x ) ) / pi;
  }

  return value;
}
/******************************************************************************/

void geometry ( double h[], int ibc, int indx[], int nl, int node[], int nsub, 
  int *nu, double xl, double xn[], double xquad[], double xr )

/******************************************************************************/
/*
  Purpose:

    GEOMETRY sets up the geometry for the interval [XL,XR].

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Output, double H(N), the length of the subintervals.  

    Input, int IBC.
    IBC declares what the boundary conditions are.
    1, at the left endpoint, U has the value UL,
       at the right endpoint, U' has the value UR.
    2, at the left endpoint, U' has the value UL,
       at the right endpoint, U has the value UR.
    3, at the left endpoint, U has the value UL,
       and at the right endpoint, U has the value UR.
    4, at the left endpoint, U' has the value UL,
       at the right endpoint U' has the value UR.

    Output, int INDX(0:N).
    For a node I, INDX(I) is the index of the unknown
    associated with node I.
    If INDX(I) is equal to -1, then no unknown is associated
    with the node, because a boundary condition fixing the
    value of U has been applied at the node instead.
    Unknowns are numbered beginning with 1.
    If IBC is 2 or 4, then there is an unknown value of U
    at node 0, which will be unknown number 1.  Otherwise,
    unknown number 1 will be associated with node 1.
    If IBC is 1 or 4, then there is an unknown value of U
    at node N, which will be unknown N or N+1,
    depending on whether there was an unknown at node 0.

    Input, int NL.
    The number of basis functions used in a single
    subinterval.  (NL-1) is the degree of the polynomials
    used.  For this code, NL is fixed at 2, meaning that
    piecewise linear functions are used as the basis.

    Output, int NODE(NL,N).
    For each subinterval I:
    NODE(1,I) is the number of the left node, and
    NODE(2,I) is the number of the right node.

    Input, int NSUB.
    The number of subintervals into which the interval
    [XL,XR] is broken.

    Output, int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be N-1,
    N, or N+1 unknown values, which are the coefficients
    of basis functions.

    Input, double XL.
    XL is the left endpoint of the interval over which the
    differential equation is being solved.

    Output, double XN(0:N).
    XN(I) is the location of the I-th node.  XN(0) is XL,
    and XN(N) is XR.

    Output, double XQUAD(N)
    XQUAD(I) is the location of the single quadrature point
    in interval I.

    Input, double XR.
    XR is the right endpoint of the interval over which the
    differential equation is being solved.
*/
{
  int i;
/*
  Set the value of XN, the locations of the nodes.
*/
  printf ( "\n" );
  printf ( "  Node      Location\n" );
  printf ( "\n" );
  for ( i = 0; i <= nsub; i++ )
  {
    xn[i]  =  ( ( double ) ( nsub - i ) * xl 
              + ( double )          i   * xr ) 
              / ( double ) ( nsub );
    printf ( "  %8d  %14g\n", i, xn[i] );
  }
/*
  Set the lengths of each subinterval.
*/
  printf ( "\n" );
  printf ( "Subint    Length\n" );
  printf ( "\n" );
  for ( i = 0; i < nsub; i++ )
  {
    h[i] = xn[i+1] - xn[i];
    printf ( "  %8d  %14g\n", i+1, h[i] );
  }
/*
  Set the quadrature points, each of which is the midpoint
  of its subinterval.
*/
  printf ( "\n" );
  printf ( "Subint    Quadrature point\n" );
  printf ( "\n" );
  for ( i = 0; i < nsub; i++ )
  {
    xquad[i] = 0.5 * ( xn[i] + xn[i+1] );
    printf ( "  %8d  %14g\n", i+1, xquad[i] );
  }
/*
  Set the value of NODE, which records, for each interval,
  the node numbers at the left and right.
*/
  printf ( "\n" );
  printf ( "Subint  Left Node  Right Node\n" );
  printf ( "\n" );
  for ( i = 0; i < nsub; i++ )
  {
    node[0+i*2] = i;
    node[1+i*2] = i + 1;
    printf ( "  %8d  %8d  %8d\n", i+1, node[0+i*2], node[1+i*2] );
  }
/*
  Starting with node 0, see if an unknown is associated with
  the node.  If so, give it an index.
*/
  *nu = 0;
/*
  Handle first node.
*/
  i = 0;
  if ( ibc == 1 || ibc == 3 )
  {
    indx[i] = -1;
  }
  else
  {
    *nu = *nu + 1;
    indx[i] = *nu;
  }
/*
  Handle nodes 1 through nsub-1
*/
  for ( i = 1; i < nsub; i++ )
  {
    *nu = *nu + 1;
    indx[i] = *nu;
  }
/*
  Handle the last node.
*/
  i = nsub;

  if ( ibc == 2 || ibc == 3 )
  {
    indx[i] = -1;
  }
  else
  {
    *nu = *nu + 1;
    indx[i] = *nu;
  }

  printf ( "\n" );
  printf ( "  Number of unknowns NU = %d\n", *nu );
  printf ( "\n" );
  printf ( "  Node  Unknown\n" );
  printf ( "\n" );
  for ( i = 0; i <= nsub; i++ )
  {
    printf ( "  %8d  %8d\n", i, indx[i] );
  }

  return;
}
/******************************************************************************/

void init ( int *ibc, int *imax, int *nprint, int *nquad, int problem, 
  double *ul, double *ur, double *xl, double *xr )

/******************************************************************************/
/*
  Purpose:

    INIT initializes variables that define the problem.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Output, int *IBC.
    IBC declares what the boundary conditions are.
    1, at the left endpoint, U has the value UL,
       at the right endpoint, U' has the value UR.
    2, at the left endpoint, U' has the value UL,
       at the right endpoint, U has the value UR.
    3, at the left endpoint, U has the value UL,
       and at the right endpoint, U has the value UR.
    4, at the left endpoint, U' has the value UL,
       at the right endpoint U' has the value UR.

    Output, int *IMAX.
    The number of Newton iterations to carry out.

    Output, int *NPRINT.
    The number of points at which the computed solution
    should be printed out when compared to the exact solution.

    Output, int *NQUAD.
    The number of quadrature points used in a subinterval.
    This code uses NQUAD = 1.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Output, double *UL.
    If IBC is 1 or 3, UL is the value that U is required
    to have at X = XL.
    If IBC is 2 or 4, UL is the value that U' is required
    to have at X = XL.

    Output, double *UR.
    If IBC is 2 or 3, UR is the value that U is required
    to have at X = XR.
    If IBC is 1 or 4, UR is the value that U' is required
    to have at X = XR.

    Output, double *XL.
    XL is the left endpoint of the interval over which the
    differential equation is being solved.

    Output, double *XR.
    XR is the right endpoint of the interval over which the
    differential equation is being solved.
*/
{
  *ibc = 1;
  *imax = 10;
  *nprint = 9;
  *nquad = 1;
  *ul = 0.0;
  *ur = 1.0;
  *xl = 0.0;
  *xr = 1.0;
/*
  Print out the values that have been set.
*/
  printf ( "\n" );
  printf ( "  The equation is to be solved for\n" );
  printf ( "  X greater than XL = %g\n", *xl );
  printf ( "  and less than XR = %g\n", *xr );
  printf ( "\n" );
  printf ( "  The boundary conditions are:\n" );
  printf ( "\n" );

  if ( *ibc == 1 || *ibc == 3 )
  {
    printf ( "  At X = XL, U = %g\n", *ul );
  }
  else
  {
    printf ( "  At X = XL, U' = %g\n", *ul );
  }

  if ( *ibc == 2 || *ibc == 3 )
  {
    printf ( "  At X = XR, U = %g\n", *ur );
  }
  else
  {
    printf ( "  At X = XR, U' = %g\n", *ur );
  }

  if ( problem == 1 )
  {
    printf ( "\n" );
    printf ( "  This is test problem #1:\n" );
    printf ( "\n" );
    printf ( "  P(X) = 1, Q(X) = 0, F(X) = X.\n" );
    printf ( "  Boundary conditions: U(0) = 0, U''(1) = 1.\n" );
    printf ( "\n" );
    printf ( "  The exact solution is U(X) = X\n" );
  }
  else if ( problem == 2 )
  {
    printf ( "\n" );
    printf ( "  This is test problem #2:\n" );
    printf ( "\n" );
    printf ( "  P(X) = 1, Q(X) = 0, \n" );
    printf ( "  F(X) = -0.5*pi*cos(0.5*pi*X)\n" );
    printf ( "        + 2*sin(0.5*pi*X)*(1-cos(0.5*pi*X)/pi.\n" );
    printf ( "  Boundary conditions: U(0) = 0, U''(1) = 1.\n" );
    printf ( "\n" );
    printf ( "  The exact solution is U(X) = 2*(1-cos(pi*x/2))/pi\n" );
  }

  printf ( "\n" );
  printf ( "  Number of quadrature points per element is %d\n", *nquad );
  printf ( "  Number of iterations is %d\n", *imax );
  
  return;
}
/******************************************************************************/

void output ( double f[], int ibc, int indx[], int nsub, int nu, double ul, 
  double ur, double xn[] )

/******************************************************************************/
/*
  Purpose:

    OUTPUT prints out the computed solution at the nodes.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, double F(NU), the solution of the linear equations.

    Input, int IBC.
    IBC declares what the boundary conditions are.
    1, at the left endpoint, U has the value UL,
       at the right endpoint, U' has the value UR.
    2, at the left endpoint, U' has the value UL,
       at the right endpoint, U has the value UR.
    3, at the left endpoint, U has the value UL,
       and at the right endpoint, U has the value UR.
    4, at the left endpoint, U' has the value UL,
       at the right endpoint U' has the value UR.

    Input, int INDX(0:N).
    For a node I, INDX(I) is the index of the unknown
    associated with node I.
    If INDX(I) is equal to -1, then no unknown is associated
    with the node, because a boundary condition fixing the
    value of U has been applied at the node instead.
    Unknowns are numbered beginning with 1.
    If IBC is 2 or 4, then there is an unknown value of U
    at node 0, which will be unknown number 1.  Otherwise,
    unknown number 1 will be associated with node 1.
    If IBC is 1 or 4, then there is an unknown value of U
    at node N, which will be unknown N or N+1,
    depending on whether there was an unknown at node 0.

    int NSUB.
    The number of subintervals into which the interval
    [XL,XR] is broken.

    Input, int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be N-1,
    N, or N+1 unknown values, which are the coefficients
    of basis functions.

    Input, double UL.
    If IBC is 1 or 3, UL is the value that U is required
    to have at X = XL.
    If IBC is 2 or 4, UL is the value that U' is required
    to have at X = XL.

    Input, double UR.
    If IBC is 2 or 3, UR is the value that U is required
    to have at X = XR.
    If IBC is 1 or 4, UR is the value that U' is required
    to have at X = XR.

    Input, double XN(0:N).
    XN(I) is the location of the I-th node.  XN(0) is XL,
    and XN(N) is XR.
*/
{
  int i;
  double u;

  printf ( "\n" );
  printf ( "Computed solution:\n" );
  printf ( "\n" );
  printf ( "Node    X(I)        U(X(I))\n" );
  printf ( "\n" );

  for ( i = 0; i <= nsub; i++ )
  {
    if ( i == 0 )
    {
      if ( ibc == 1 || ibc == 3 )
      {
        u = ul;
      }
      else
      {
        u = f[indx[i]-1];
      }
    }
    else if ( i == nsub )
    {
      if ( ibc == 2 || ibc == 3 )
      {
        u = ur;
      }
      else
      {
        u = f[indx[i]-1];
      }
    }
    else
    {
      u = f[indx[i]-1];
    }
    printf ( "  %6d  %12g  %12g\n", i, xn[i], u );
  }
  return;
}
/******************************************************************************/

void phi ( int il, double x, double *phii, double *phiix, double xleft, 
  double xrite )

/******************************************************************************/
/*
  Purpose:

    PHI evaluates a linear basis function and its derivative.

  Discussion:

    In any interval, there are just two basis functions.  The first
    basis function is a line which is 1 at the left endpoint
    and 0 at the right.  The second basis function is 0 at
    the left endpoint and 1 at the right.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, int IL, the index of the basis function.
    1, the function which is 1 at XLEFT and 0 at XRITE.
    2, the function which is 0 at XLEFT and 1 at XRITE.

    Input, double X, the evaluation point.

    Output, double PHII, PHIIX, the value of the
    basis function and its derivative at X.

    Input, double XLEFT, XRITE, the left and right
    endpoints of the interval.
*/
{
  if ( xleft <= x && x <= xrite )
  {
    if ( il == 1 )
    {
      *phii = ( xrite - x ) / ( xrite - xleft );
      *phiix =         -1.0 / ( xrite - xleft );
    }
    else
    {
      *phii = ( x - xleft ) / ( xrite - xleft );
      *phiix = 1.0          / ( xrite - xleft );
    }
  }
/*
  If X is outside of the interval, just set everything to 0.
*/
  else
  {
    *phii  = 0.0;
    *phiix = 0.0;
  }

  return;
}
/******************************************************************************/

double pp ( double x, int problem )

/******************************************************************************/
/*
  Purpose:

    PP evaluates the function P in the differential equation.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, double X, the evaluation point.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Output, double PP, the value of P(X).
*/
{
  double value;
/*
  Test problem 1
*/
  if ( problem == 1 )
  {
    value = 1.0;
  }
/*
  Test problem 2
*/
  else if ( problem == 2 )
  {
    value = 1.0;
  }
  return value;
}
/******************************************************************************/

void prsys ( double adiag[], double aleft[], double arite[], double f[], 
  int nu )

/******************************************************************************/
/*
  Purpose:

    PRSYS prints out the tridiagonal linear system.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameter:

    Input, double ADIAG(NU), the "diagonal" coefficients.  That is, 
    ADIAG(I) is the coefficient of the I-th unknown in the I-th equation.

    Input, double ALEFT(NU), the "left hand" coefficients.  That is, ALEFT(I) 
    is the coefficient of the (I-1)-th unknown in the I-th equation.
    There is no value in ALEFT(1), since the first equation
    does not refer to a "0-th" unknown.

    Input, double ARITE(NU).
    ARITE(I) is the "right hand" coefficient of the I-th
    equation in the linear system.  ARITE(I) is the coefficient
    of the (I+1)-th unknown in the I-th equation.  There is
    no value in ARITE(NU) because the NU-th equation does not
    refer to an "NU+1"-th unknown.

    Input, double F(NU).
    ASSEMBLE stores into F the right hand side of the linear
    equations.
    SOLVE replaces those values of F by the solution of the
    linear equations.

    Input, int NU.
    NU is the number of unknowns in the linear system.
    Depending on the value of IBC, there will be NSUB-1,
    NSUB, or NSUB+1 unknown values, which are the coefficients
    of basis functions.
*/
{
  int i;

  printf ( "\n" );
  printf ( "Printout of tridiagonal linear system:\n" );
  printf ( "\n" );
  printf ( "Equation  ALEFT  ADIAG  ARITE  RHS\n" );
  printf ( "\n" );

  for ( i = 0; i < nu; i++ )
  {
    printf ( "  %8d  %14g  %14g  %14g  %14g\n", i + 1, aleft[i], adiag[i], arite[i], f[i] );
  }

  return;
}
/******************************************************************************/

double qq ( double x, int problem )

/******************************************************************************/
/*
  Purpose:

    QQ returns the value of the coefficient function Q(X).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, double X, the evaluation point.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Output, double QQ, the value of Q(X).
*/
{
  double value;
/*
  Test problem 1
*/
  if ( problem == 1 )
  {
    value = 0.0;
  }
/*
  Test problem 2
*/
  else if ( problem == 2 )
  {
    value = 0.0;
  }

  return value;
}
/******************************************************************************/

void solve ( double adiag[], double aleft[], double arite[], double f[], 
  int nu )

/******************************************************************************/
/*
  Purpose: 

    SOLVE solves a tridiagonal matrix system of the form A*x = b.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input/output, double ADIAG(NU), ALEFT(NU), ARITE(NU).
    On input, ADIAG, ALEFT, and ARITE contain the diagonal,
    left and right entries of the equations.
    On output, ADIAG and ARITE have been changed in order
    to compute the solution.
    Note that for the first equation, there is no ALEFT
    coefficient, and for the last, there is no ARITE.
    So there is no need to store a value in ALEFT(1), nor
    in ARITE(NU).

    Input/output, double F(NU).
    On input, F contains the right hand side of the linear
    system to be solved.
    On output, F contains the solution of the linear system.

    Input, int NU, the number of equations to be solved.
*/
{
  int i;
/*
  Carry out Gauss elimination on the matrix, saving information
  needed for the backsolve.
*/
  arite[0] = arite[0] / adiag[0];

  for ( i = 1; i < nu - 1; i++ )
  {
    adiag[i] = adiag[i] - aleft[i] * arite[i-1];
    arite[i] = arite[i] / adiag[i];
  }
  adiag[nu-1] = adiag[nu-1] - aleft[nu-1] * arite[nu-2];
/*
  Carry out the same elimination steps on F that were done to the
  matrix.
*/
  f[0] = f[0] / adiag[0];
  for ( i = 1; i < nu; i++ )
  {
    f[i] = ( f[i] - aleft[i] * f[i-1] ) / adiag[i];
  }
/*
  And now carry out the steps of "back substitution".
*/
  for ( i = nu - 2; 0 <= i; i-- )
  {
    f[i] = f[i] - arite[i] * f[i+1];
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
/******************************************************************************/

double u_exact ( double x, int problem )

/******************************************************************************/
/*
  Purpose:

    U_EXACT returns the value of the exact solution at a point X.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 July 2013

  Author:

    C version by John Burkardt

  Parameters:

    Input, double X, the evaluation point.

    Input, int PROBLEM, indicates which problem to be solved.
    * 1, u = x, p=1, q=0, f=x, u(0)=0, u'(1)=1.
    * 2, u = 2*(1-cos(0.5*pi*x))/pi, p=1, q=0,
    f = -0.5*pi*cos(0.5*pi*x) + 2*sin(0.5*pi*x)*(1-cos(0.5*pi*x)/pi
    u(0) = 0, u'(1)=1.

    Output, double U_EXACT, the value of the exact solution at X.
*/
{
  double pi = 3.141592653589793;
  double value;
/*
  Test problem 1
*/
  if ( problem == 1 )
  {
    value = x;
  }
/*
  Test problem 2
*/
  else if ( problem == 2 )
  {
    value = 2.0 * ( 1.0 - cos ( 0.5 * pi * x ) ) / pi;
  }

  return value;
}
