void comp_next ( int n, int k, int a[], int *more, int *h, int *t );
void gm_general_rule_set ( int rule, int m, int n, double t[], double w[], 
  double x[] );
int gm_rule_size ( int rule, int dim_num );
void gm_unit_rule_set ( int rule, int dim_num, int point_num, double w[],
  double x[] );
int i4_choose ( int n, int k );
int i4_huge ( );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_power ( int i, int j );
double *monomial_value ( int m, int n, int e[], double x[] );
double r8_factorial ( int n );
double r8ge_det ( int n, double a_lu[], int pivot[] );
int r8ge_fa ( int n, double a[], int pivot[] );
void r8mat_transpose_print ( int m, int n, double a[], char *title );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, char *title );
double r8vec_dot_product ( int n, double a1[], double a2[] );
double *r8vec_uniform_01_new ( int n, int *seed );
double simplex_general_volume ( int m, double t[] );
double simplex_unit_monomial_integral ( int dim_num, int expon[] );
double simplex_unit_monomial_quadrature ( int dim_num, int expon[],
  int point_num, double x[], double w[] );
double *simplex_unit_sample ( int dim_num, int n, int *seed );
void simplex_unit_to_general ( int dim_num, int point_num, double t[],
  double ref[], double phy[] );
double simplex_unit_volume ( int dim_num );
void timestamp ( );
