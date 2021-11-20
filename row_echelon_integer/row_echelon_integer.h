int i4_gcd ( int i, int j );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
void i4mat_print ( int m, int n, int a[], char *title );
void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi,
  int jhi, char *title );
int i4mat_ref ( int m, int n, int a[] );
void i4mat_row_reduce ( int m, int n, int i, int a[] );
void i4mat_row_swap ( int m, int n, int a[], int i, int r );
int i4mat_rref ( int m, int n, int a[] );
double *i4mat_u_solve ( int n, int a[], int b[] );
void i4vec_binary_next ( int n, int bvec[] );
bool i4vec_is_binary ( int n, int x[] );
bool i4vec_is_one ( int n, int x[] );
void i4vec_print ( int n, int a[], char *title );
int i4vec_red ( int n, int a[] );
void i4vec_transpose_print ( int n, int a[], char *title );
void ksub_next4 ( int n, int k, int a[], int *done );
bool r8vec_is_integer ( int n, double a[] );
void r8vec_print ( int n, double a[], char *title );
void r8vec_transpose_print ( int n, double a[], char *title );
int s_len_trim ( char *s );
void timestamp ( );

