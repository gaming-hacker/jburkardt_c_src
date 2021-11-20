# ifndef XMALLOC_H
# define XMALLOC_H
#   include <stdlib.h>
    void *malloc_or_exit ( size_t nbytes, const char *file, int line );
    void *ymalloc ( size_t nbytes );
# define xmalloc(nbytes) malloc_or_exit ( ( nbytes ), __FILE__, __LINE__ )
# endif
