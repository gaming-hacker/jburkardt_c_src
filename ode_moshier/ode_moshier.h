/* 
  Debugging printf's 
*/
# define DEBUG 0
/* 
  Maximum Adams order supported: 
*/
# define MAXORD 13
# define MAXRUNG 13

void adstart ( double h, double yn[], double work[], int neq, int ord, double t );
double adstep ( double *t, double yn[], int nequat );
double difpol( double *diffn, int k, double t );
void divdif ( double vec[], int k, double *diffn );
void dupdate ( register double *diffn, int k, double f );
void func ( double t, double yxx[], double v[] );
double intpol( double *diffn, double *coeffs, int k );
void rkstart ( int neq, double work[] );
void rungek (  int neqn, double x, double yold[], double h, double ynew[], 
  double delta[] );
void vcopy ( register double *p, register double *q, register int n );
