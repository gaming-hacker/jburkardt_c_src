int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
double r8_sign ( double x );
void r82poly2_print ( double a, double b, double c, double d, double e, double f );
int r82poly2_type ( double a, double b, double c, double d, double e, double f );
void r82poly2_type_print ( int type );
double r8mat_det_3d ( double a[] );
double *r8mat_inverse_3d ( double a[] );
void r8mat_print ( int m, int n, double a[], char *title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, char *title );
double *r8poly_add ( int na, double a[], int nb, double b[] );
double *r8poly_ant_coef ( int n, double poly_cof[] );
double r8poly_ant_value ( int n, double poly_cof[], double xval );
int r8poly_degree ( int na, double a[] );
double *r8poly_deriv ( int n, double c[], int p );
void r8poly_division ( int na, double a[], int nb, double b[], int *nq, 
  double q[], int *nr, double r[] );
double r8poly_lagrange_0 ( int npol, double xpol[], double xval );
double r8poly_lagrange_1 ( int npol, double xpol[], double xval );
double r8poly_lagrange_2 ( int npol, double xpol[], double xval );
double *r8poly_lagrange_coef ( int npol, int ipol, double xpol[] );
void r8poly_lagrange_factor ( int npol, double xpol[], double xval,
  double *wval, double *dwdx );
int r8poly_lagrange_value ( int npol, int ipol, double xpol[], double xval,
  double *pval, double *dpdx );
void r8poly_multiply ( int na, double a[], int nb, double b[], double c[] );
void r8poly_power ( int na, double a[], int p, double b[] );
void r8poly_print ( int n, double a[], char *title );
void r8poly_shift ( double scale, double shift, int n, double poly_cof[] );
double r8poly_value ( int n, double a[], double x );
double r8poly_value_horner ( int n, double a[], double x );
double *r8poly_values_horner ( int m, double c[], int n, double x[] );
double *r8poly_value_2d ( int m, double c[], int n, double x[], double y[] );
int r8poly2_ex ( double x1, double y1, double x2, double y2, double x3, double y3,
  double *x, double *y );
int r8poly2_ex2 ( double x1, double y1, double x2, double y2, double x3, double y3,
  double *x, double *y, double *a, double *b, double *c );
void r8poly2_root ( double a, double b, double c, double complex *r1, double complex *r2 );
void r8poly2_rroot ( double a, double b, double c, double *r1, double *r2 );
void r8poly2_val ( double x1, double y1, double x2, double y2,
  double x3, double y3, double x, double *y, double *yp, double *ypp );
void r8poly2_val2 ( int ndata, double tdata[],
  double ydata[], int left, double tval, double *yval );
void r8poly3_root ( double a, double b, double c, double d, double complex *r1, 
  double complex *r2, double complex *r3 );
void r8poly4_root ( double a, double b, double c, double d, double e, 
  double complex *r1, double complex *r2, double complex *r3, double complex *r4 );
void r8r8_print ( double a1, double a2, char *title );
double *r8vec_copy_new ( int n, double a1[] );
double *r8vec_even_new ( int n, double alo, double ahi );
double r8vec_even_select ( int n, double xlo, double xhi, int ival );
double *r8vec_indicator1_new ( int n );
bool r8vec_is_distinct ( int n, double x[] );
double *r8vec_linspace_new ( int n, double a_lo, double a_hi );
void r8vec_print ( int n, double a[], char *title );
void r8vec_transpose_print ( int n, double a[], char *title );
double *r8vec_uniform_01_new ( int n, int *seed );
double *r8vec_zeros_new ( int n );
void r8vec2_print ( int n, double a1[], double a2[], char *title );
double *roots_to_r8poly ( int n, double x[] );
int s_len_trim ( char *s );
void timestamp ( );
