void bisection ( double fatol, int step_max, int prob, double xatol, 
  double *xa, double *xb, double *fxa, double *fxb );
void brent ( double fatol, int step_max, int prob, double xatol, double xrtol, 
  double *xa, double *xb, double *fxa, double *fxb );
void muller ( double fatol, int step_max, int prob, double xatol, double xrtol, 
  double *xa, double *xb, double *xc, double *fxa, double *fxb, double *fxc );
void newton ( double fatol, int step_max, int prob, double xatol, double xmin, 
  double xmax, double *xa, double *fxa );
double p00_fx ( int prob, double x );
double p00_fx1 ( int prob, double x );
double p00_fx2 ( int prob, double x );
int p00_prob_num ( );
double *p00_range ( int prob );
double p00_root ( int prob, int i );
int p00_root_num ( int prob );
double p00_start ( int prob, int i );
int p00_start_num ( int prob );
char *p00_title ( int prob );
double p01_fx ( double x );
double p01_fx1 ( double x );
double p01_fx2 ( double x );
double *p01_range ( );
double p01_root ( int i );
int p01_root_num ( );
double p01_start ( int i );
int p01_start_num ( );
char *p01_title ( );
double p02_fx ( double x );
double p02_fx1 ( double x );
double p02_fx2 ( double x );
double *p02_range ( );
double p02_root ( int i );
int p02_root_num ( );
double p02_start ( int i );
int p02_start_num ( );
char *p02_title ( );
double p03_fx ( double x );
double p03_fx1 ( double x );
double p03_fx2 ( double x );
double *p03_range ( );
double p03_root ( int i );
int p03_root_num ( );
double p03_start ( int i );
int p03_start_num ( );
char *p03_title ( );
double p04_fx ( double x );
double p04_fx1 ( double x );
double p04_fx2 ( double x );
double *p04_range ( );
double p04_root ( int i );
int p04_root_num ( );
double p04_start ( int i );
int p04_start_num ( );
char *p04_title ( );
double p05_fx ( double x );
double p05_fx1 ( double x );
double p05_fx2 ( double x );
double *p05_range ( );
double p05_root ( int i );
int p05_root_num ( );
double p05_start ( int i );
int p05_start_num ( );
char *p05_title ( );
double p06_fx ( double x );
double p06_fx1 ( double x );
double p06_fx2 ( double x );
double *p06_range ( );
double p06_root ( int i );
int p06_root_num ( );
double p06_start ( int i );
int p06_start_num ( );
char *p06_title ( );
double p07_fx ( double x );
double p07_fx1 ( double x );
double p07_fx2 ( double x );
double *p07_range ( );
double p07_root ( int i );
int p07_root_num ( );
double p07_start ( int i );
int p07_start_num ( );
char *p07_title ( );
double p08_fx ( double x );
double p08_fx1 ( double x );
double p08_fx2 ( double x );
double *p08_range ( );
double p08_root ( int i );
int p08_root_num ( );
double p08_start ( int i );
int p08_start_num ( );
char *p08_title ( );
double p09_fx ( double x );
double p09_fx1 ( double x );
double p09_fx2 ( double x );
double *p09_range ( );
double p09_root ( int i );
int p09_root_num ( );
double p09_start ( int i );
int p09_start_num ( );
char *p09_title ( );
double p10_fx ( double x );
double p10_fx1 ( double x );
double p10_fx2 ( double x );
double *p10_range ( );
double p10_root ( int i );
int p10_root_num ( );
double p10_start ( int i );
int p10_start_num ( );
char *p10_title ( );
double p11_fx ( double x );
double p11_fx1 ( double x );
double p11_fx2 ( double x );
double *p11_range ( );
double p11_root ( int i );
int p11_root_num ( );
double p11_start ( int i );
int p11_start_num ( );
char *p11_title ( );
double p12_fx ( double x );
double p12_fx1 ( double x );
double p12_fx2 ( double x );
double *p12_range ( );
double p12_root ( int i );
int p12_root_num ( );
double p12_start ( int i );
int p12_start_num ( );
char *p12_title ( );
double p13_fx ( double x );
double p13_fx1 ( double x );
double p13_fx2 ( double x );
double *p13_range ( );
double p13_root ( int i );
int p13_root_num ( );
double p13_start ( int i );
int p13_start_num ( );
char *p13_title ( );
double p14_fx ( double x );
double p14_fx1 ( double x );
double p14_fx2 ( double x );
double *p14_range ( );
double p14_root ( int i );
int p14_root_num ( );
double p14_start ( int i );
int p14_start_num ( );
char *p14_title ( );
double p15_fx ( double x );
double p15_fx1 ( double x );
double p15_fx2 ( double x );
double *p15_range ( );
double p15_root ( int i );
int p15_root_num ( );
double p15_start ( int i );
int p15_start_num ( );
char *p15_title ( );
double p16_fx ( double x );
double p16_fx1 ( double x );
double p16_fx2 ( double x );
double *p16_range ( );
double p16_root ( int i );
int p16_root_num ( );
double p16_start ( int i );
int p16_start_num ( );
char *p16_title ( );
double p17_fx ( double x );
double p17_fx1 ( double x );
double p17_fx2 ( double x );
double *p17_range ( );
double p17_root ( int i );
int p17_root_num ( );
double p17_start ( int i );
int p17_start_num ( );
char *p17_title ( );
double p18_fx ( double x );
double p18_fx1 ( double x );
double p18_fx2 ( double x );
double *p18_range ( );
double p18_root ( int i );
int p18_root_num ( );
double p18_start ( int i );
int p18_start_num ( );
char *p18_title ( );
double p19_fx ( double x );
double p19_fx1 ( double x );
double p19_fx2 ( double x );
double *p19_range ( );
double p19_root ( int i );
int p19_root_num ( );
double p19_start ( int i );
int p19_start_num ( );
char *p19_title ( );
double r8_abs ( double x );
double r8_add ( double x, double y );
double complex r8_csqrt ( double x );
double r8_cube_root ( double x );
double r8_epsilon ( );
double r8_huge ( );
double r8_max ( double x, double y );
double r8_sign ( double x );
void r8poly2_rroot ( double a, double b, double c, double *r1, double *r2 );
void regula_falsi ( double fatol, int step_max, int prob, double xatol,
  double *xa, double *xb, double *fxa, double *fxb );
void secant ( double fatol, int step_max, int prob, double xatol, double xmin, 
  double xmax, double *xa, double *xb, double *fxa, double *fxb );
void timestamp ( );
