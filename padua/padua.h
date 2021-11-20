void filename_inc ( char *filename );
int padua_order ( int l );
void padua_plot ( int l, char *filename );
double *padua_points ( int l );
double *padua_points_set ( int l );
double *padua_weights ( int l );
double *padua_weights_set ( int l );
double r8_max ( double x, double y );
void r8mat_transpose_print ( int m, int n, double a[], char *title );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, char *title );
double *r8vec_copy_new ( int n, double a1[] );
void r8vec_print ( int n, double a[], char *title );
void r8vec_reverse ( int n, double a[] );
void timestamp ( );

