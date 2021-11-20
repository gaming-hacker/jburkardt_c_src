void i4mat_copy ( int m, int n, int a1[], int a2[] );
int *i4mat_copy_new ( int m, int n, int a1[] );
void i4mat_flip_cols ( int m, int n, int a[] );
void i4mat_flip_rows ( int m, int n, int a[] );
int i4mat_sum ( int m, int n, int a[] );
void i4mat_transpose ( int m, int n, int a[] );
int *i4rows_copy_new ( int m, int n, int a1[] );
int *i4rows_zeros_new ( int m, int n );
void i4vec_copy ( int n, int a1[], int a2[] );
void pentomino_matrix ( char name, int *p_m, int *p_n, int **p );
void pentomino_plot ( int p_m, int p_n, int p[], char *label );
void polyomino_condense ( int mp, int np, int p[], int *mq, int *nq, int **q );
int *polyomino_embed_list ( int mr, int nr, int r[], int mp, int np, int p[], 
  int number );
int polyomino_embed_number ( int mr, int nr, int r[], int mp, int np, int p[] );
void polyomino_enumerate_chiral ( int *n_data, int *order, 
  long long int *number );
void polyomino_enumerate_fixed ( int *n_data, int *order, 
  long long int *number );
void polyomino_enumerate_free ( int *n_data, int *order, 
  long long int *number );
int *polyomino_index ( int m, int n, int p[] );
void polyomino_lp_write ( char *filename, char *label, int m, int n, int a[], 
  int b[] );
void polyomino_monohedral_example_reid_size ( int *m, int *n );
void polyomino_monohedral_example_reid_system ( int m, int n, int a[], int b[] );
void polyomino_print ( int m, int n, int p[], char *label );
void polyomino_transform ( int m, int n, int p[], int rotate, int reflect, 
  int *mq, int *nq, int **q );
void timestamp ( );
