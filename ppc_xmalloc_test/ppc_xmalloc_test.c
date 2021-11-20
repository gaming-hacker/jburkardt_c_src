# include <stdio.h>

# include "ppc_xmalloc.h"

//**************************************************************************************80

int main ( )

//**************************************************************************************80
//
//  Purpose:
//
//    ppc_xmalloc_test demonstrates simple calls to ppc_xmalloc.
//
//  License:
//
//    I don't care what the hell you do with this code.
//
//  Modified:
//
//    07 July 2017
//
//  Author:
//
//    John Burkardt
//
{
  int n = 1000;
  size_t nbytes;
  int *x;
  
  printf ( "\n" );
  printf ( "ppc_xmalloc_test:\n" );
  printf ( "  Test ppc_xmalloc for memory allocation.\n" );
  
  nbytes = n * sizeof ( int );
  
  printf ( "\n" );
  printf ( "  Request %zu bytes of memory using malloc:\n", nbytes );
  x = ( int * ) malloc ( nbytes );
  free ( x );
  
  printf ( "\n" );
  printf ( "  Request %zu bytes of memory using malloc_or_exit:\n", nbytes );
  x = ( int * ) malloc_or_exit ( nbytes, __FILE__, __LINE__ );
  free ( x );

  printf ( "\n" );
  printf ( "  Request %zu bytes of memory using ymalloc:\n", nbytes );
  x = ( int * ) ymalloc ( nbytes );
  free ( x );
//
//  As defined in the reference, xmalloc must be called EXACTLY in the form
//    pointer = xmalloc(nbytes);
//  where the string "xmalloc(nbytes)" must have no spaces, and must 
//  use the name "nbytes" for the argument.
//
  printf ( "\n" );
  printf ( "  Request %zu bytes of memory:\n", nbytes );
  x = xmalloc ( nbytes );
  free ( x );
//
//  Demonstrate that xmalloc will produce an error message for a request of 0 bytes.
//
  nbytes = 0;
  printf ( "\n" );
  printf ( "  Request %zu bytes of memory:\n", nbytes );
  x = xmalloc ( nbytes );
  free ( x );
//
//  Terminate.
//
  printf ( "\n" );
  printf ( "ppc_xmalloc_test:\n" );
  printf ( "  Normal end of execution.\n" );
  
  return 0;
}
