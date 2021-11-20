# include "ppc_xmalloc.h"

# define make_vector(v,n) ((v)=xmalloc((n)*sizeof*(v)))
# define free_vector(v) do { free(v); v = NULL; } while ( 0 )

void free_matrix_double ( double **a );
void free_matrix_float ( float **a );
double **make_matrix_double ( size_t m, size_t n );
float **make_matrix_float ( size_t m, size_t n );
void timestamp ( );
