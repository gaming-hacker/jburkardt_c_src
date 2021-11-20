# include <stdio.h>

# include "ppc_xmalloc.h"

//**************************************************************************************80

void *ymalloc ( size_t nbytes )

//**************************************************************************************80
//
//  Purpose:
//
//    ymalloc deals with a user request for memory.
//
//  License:
//
//    I don't care what you do with this code.
//
//  Modified:
//
//    07 July 2017
//
//  Reference:
//
//    Rouben Rostamian,
//    Programming Projects in C 
//    for Students of Engineering, Science, and Mathematics,
//    SIAM, 2014,
//    ISBN: 978-1-611973-49-5
//
//  Parameters:
//
//    Input, size_t nbytes, the number of bytes of memory requested.
//
//    Output, void *ymalloc, a pointer to nbytes bytes of memory.
//
{
  void *x;
  
  x = malloc_or_exit ( nbytes, __FILE__, __LINE__ );
  
  return x;
}
//**************************************************************************************80

void *malloc_or_exit ( size_t nbytes, const char *file, int line )

//**************************************************************************************80
//
//  Purpose:
//
//    malloc_or_exit deals with a user request for memory.
//
//  Discussion:
//
//    Rostamian recommends an error return for a request of 0 bytes.
//    I don't see why.
//
//  License:
//
//    I don't care what you do with this code.
//
//  Modified:
//
//    07 July 2017
//
//  Reference:
//
//    Rouben Rostamian,
//    Programming Projects in C 
//    for Students of Engineering, Science, and Mathematics,
//    SIAM, 2014,
//    ISBN: 978-1-611973-49-5
//
//  Parameters:
//
//    Input, size_t nbytes, the number of bytes of memory requested.
//
//    Input, const char *file, the name of the file that called this function.
//
//    Input, int line, the line in the file where the call originated.
//
//    Output, void *malloc_or_exit, a pointer to nbytes bytes of memory.
//
{
  void *x;
  
  if ( nbytes <= 0 )
  {
    printf ( "\n" );
    printf ( "%s: line %d: Illegal request for malloc() of %zu bytes.\n",
      file, line, nbytes );

    fprintf ( stderr, "\n" );
    fprintf ( stderr, "%s: line %d: Illegal request for malloc() of %zu bytes.\n",
      file, line, nbytes );
    return NULL;
  }
  
  x = malloc ( nbytes );
  
  if ( x == NULL )
  {
    printf ( "\n" );
    printf ( "%s: line %d: malloc() of %zu bytes failed.\n",
      file, line, nbytes );

    fprintf ( stderr, "\n" );
    fprintf ( stderr, "%s: line %d: malloc() of %zu bytes failed.\n",
      file, line, nbytes );
    exit ( EXIT_FAILURE );
  }
  
  return x;
}
