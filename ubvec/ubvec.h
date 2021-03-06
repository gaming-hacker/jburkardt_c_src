int i4_choose ( int n, int k );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_power ( int i, int j );
int i4_uniform_ab ( int a, int b, int *seed );
void i4vec_print ( int n, int a[], char *title );
int i4vec_sum ( int n, int a[] );
void i4vec_transpose_print ( int n, int a[], char *title );
int *ksubset_colex_unrank ( int rank, int k, int n );
int ksubset_enum ( int k, int n );
int morse_thue ( unsigned int ui );
unsigned int nim_sum ( unsigned int ui, unsigned int uj );
void timestamp ( );
int *ubvec_add ( int n, int bvec1[], int bvec2[] );
int *ubvec_and ( int n, int ubvec1[], int ubvec2[] );
bool ubvec_check ( int n, int ubvec[] );
int *ubvec_complement1 ( int n, int ubvec1[] );
int ubvec_enum ( int n );
void ubvec_next ( int n, int ubvec[] );
void ubvec_next_gray ( int n, int t[] );
void ubvec_next_grlex ( int n, int t[] );
int *ubvec_or ( int n, int ubvec1[], int ubvec2[] );
void ubvec_print ( int n, int bvec[], char *title );
int *ubvec_random ( int n, int *seed );
int ubvec_rank_gray ( int n, int ubvec[] );
int *ubvec_reverse ( int n, int ubvec1[] );
unsigned int ubvec_to_ui4 ( int n, int bvec[] );
int *ubvec_unrank_gray ( int rank, int n );
int *ubvec_unrank_grlex ( int rank, int n );
int *ubvec_xor ( int n, int bvec1[], int bvec2[]);
int ui4_rank_gray ( unsigned int ui4 );
int *ui4_to_ubvec ( unsigned int ui4, int n );
int ui4_unrank_gray ( int rank );
