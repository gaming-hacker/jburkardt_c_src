# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>

# include "csparse.h"

typedef struct problem_struct
{
  cs *A ;
  cs *C ;
  int sym ;
  double *x ;
  double *b ;
  double *r ;
} problem ;

problem *get_problem (FILE *f, double tol) ;
int demo2 (problem *Prob) ;
problem *free_problem (problem *Prob) ;


/* cs_demo2: read a matrix and solve a linear system */
int main ( )
{
  printf ( "\n" );
  printf ( "csparse_test02:\n" );
  printf ( "  Demonstration of the CSPARSE package.\n" );

  problem *Prob = get_problem (stdin, 1e-14) ;
  demo2 (Prob) ;
  free_problem (Prob) ;
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "csparse_test02:\n" );
  printf ( "  Normal end of execution.\n" );

  return (0) ;
}
