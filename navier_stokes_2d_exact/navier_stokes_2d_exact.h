void all_gms ( double nu, double rho, int n, double x[], double y[], double t,
  double u[], double dudt[], double dudx[], double dudxx[], double dudy[], 
  double dudyy[], double us[], 
  double v[], double dvdt[], double dvdx[], double dvdxx[], double dvdy[], 
  double dvdyy[], double vs[],
  double p[], double dpdt[], double dpdx[], double dpdxx[], double dpdy[], 
  double dpdyy[], double ps[] );
void grid_2d ( int x_num, double x_lo, double x_hi, int y_num, double y_lo, 
  double y_hi, double x[], double y[] );
void ns2de_gnuplot ( char *header, int n, double x[], double y[], double u[], 
  double v[], double p[], double s );
double r8vec_amax ( int n, double a[] );
double r8vec_amin ( int n, double a[] );
void r8vec_linspace ( int n, double a, double b, double x[] );
double r8vec_max ( int n, double r8vec[] );
double r8vec_min ( int n, double r8vec[] );
double r8vec_norm_l2 ( int n, double a[] );
double *r8vec_uniform_ab_new ( int n, double a, double b, int *seed );
void resid_gms ( double nu, double rho, int n, double x[], double y[], double t, 
  double ur[], double vr[], double pr[] );
void resid_lukas ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void resid_poiseuille ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void resid_spiral ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void resid_taylor ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] );
void resid_vortex ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] );
void rhs_gms ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void rhs_lukas ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void rhs_poiseuille ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void rhs_spiral ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void rhs_taylor ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void rhs_vortex ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] );
void timestamp ( );
void uvp_gms ( double nu, double rho, int n, double x[], double y[], double t, 
  double u[], double v[], double p[] );
void uvp_lukas ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] );
void uvp_poiseuille ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] );
void uvp_spiral ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] );
void uvp_taylor ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] );
void uvp_vortex ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] );

