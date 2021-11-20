int *gray_mean_news ( int m, int n, int gray[] );
int *gray_median_news ( int m, int n, int gray[] );
void i4mat_copy ( int m, int n, int a1[], int a2[] );
int i4vec_frac ( int n, int a[], int k );
int i4vec_mean_i4 ( int n, int a[] );
int i4vec_median ( int n, int a[] );
void i4vec_sort_bubble_a ( int n, int a[] );
void pgma_read_data ( FILE *file_in, int xsize, int ysize, int *g );
void pgma_read_header ( FILE *file_in, int *xsize, int *ysize, int *maxg );
void pgma_write ( char *file_out_name, int xsize, int ysize, int *g );
void pgma_write_data ( FILE *file_out, int xsize, int ysize, int *g );
void pgma_write_header ( FILE *file_out, char *file_out_name, int xsize, 
  int ysize, int maxg );
void ppma_read_data ( FILE *input, int xsize, int ysize, int *r,
  int *g, int *b );
void ppma_read_header ( FILE *input, int *xsize, int *ysize, int *rgb_max );
int ppma_write ( char *file_out_name, int xsize, int ysize, int *r,
  int *g, int *b );
int ppma_write_data ( FILE *file_out, int xsize, int ysize, int *r,
  int *g, int *b );
int ppma_write_header ( FILE *file_out, char *file_out_name, int xsize,
  int ysize, int rgb_max );
void rgb_median_news ( int m, int n, int r[], int g[], int b[] );
void timestamp ( );
