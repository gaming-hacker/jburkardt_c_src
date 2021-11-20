double *r8vec_linspace_new ( int n, double a, double b );
void stiff_deriv ( double t, double y[], double dydt[] );
void stiff_euler ( int n, double t[], double y[] );
void stiff_euler_backward ( int n, double t[], double y[] );
double *stiff_exact ( int n, double t[] );
void stiff_midpoint ( int n, double t[], double y[] );
void stiff_parameters ( double *lambda, double *t0, double *y0 );
void timestamp ( );
