double annulus_area ( double center[], double r1, double r2 );
void annulus_rule_compute ( double center[2], double r1, double r2, int nr, 
  int nt, double w[], double x[], double y[] );
double disk01_monomial_integral ( int e[2] );
void imtqlx ( int n, double d[], double e[], double z[] );
void legendre_ek_compute ( int n, double x[], double w[] );
double *monomial_value ( int m, int n, int e[], double x[] );
double r8_epsilon ( );
double r8_gamma ( double x );
double r8_sign ( double x );
double r8vec_dot_product ( int n, double a1[], double a2[] );
void r8vec_print ( int n, double a[], char *title );
double *r8vec_uniform_01_new ( int n, int *seed );
void r8vec3_print ( int n, double a1[], double a2[], double a3[], char *title );
void rule_adjust ( double a, double b, double c, double d, int order, 
  double x[], double w[] );
void timestamp ( );
