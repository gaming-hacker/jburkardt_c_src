double *bpath ( int *seed, int n );
void bpath_gnuplot ( int n, double w[] );
void bpath_average ( int *seed, int m, int n, double u[], double umean[], 
  double *error );
void bpath_average_gnuplot ( int m, int n, double u[], double umean[] );
void chain ( int *seed, int n, double xem[], double vem[], double *diff );
void chain_gnuplot ( int n, double x[], double v[] );
void em ( int *seed, int n, double t[], double xtrue[], double t2[], 
  double xem[], double *error );
void em_gnuplot ( int n, double t[], double xtrue[], double t2[], double xem[] );
void emstrong ( int *seed, int m, int n, int p_max, double dtvals[], 
  double xerr[] );
void emstrong_gnuplot ( int p_max, double dtvals[], double xerr[] );
void emweak ( int *seed, int method, int m, int p_max, double dtvals[], 
  double xerr[] );
void emweak_gnuplot ( int p_max, double dtvals[], double xerr[], int method );
void filename_inc ( char *filename );
void milstrong ( int *seed, int p_max, double dtvals[], double xerr[] );
void milstrong_gnuplot ( int p_max, double dtvals[], double xerr[] );
void stab_asymptotic ( int *seed, int n, int p_max );
void stab_meansquare ( int *seed );
void stochastic_integral_ito ( int n, int *seed, double *estimate, 
  double *exact, double *error );
void stochastic_integral_strat ( int n, int *seed, double *estimate, 
  double *exact, double *error );

