# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "ppc_array_mine.h"

/******************************************************************************/

void free_matrix_double ( double **a )

/******************************************************************************/
/*
  Purpose:

    free_matrix_double releases memory and pointers for a 2D double matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    double **a, pointers to the initial elements of each row.
*/
{
  int i;

  if ( a != NULL )
  {
    for ( i = 0; a[i] != NULL; i++ )
    {
      free ( a[i] );
    }
    free ( a );
  }
  return;
}
/******************************************************************************/

void free_matrix_float ( float **a )

/******************************************************************************/
/*
  Purpose:

    free_matrix_float releases memory and pointers for a float matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    float **a, pointers to the initial elements of each row.
*/
{
  int i;

  if ( a != NULL )
  {
    for ( i = 0; a[i] != NULL; i++ )
    {
      free ( a[i] );
    }
    free ( a );
  }
  return;
}
/******************************************************************************/

void free_vector_float ( float *v )

/******************************************************************************/
/*
  Purpose:

    free_vector_float releases a pointer for a float vector.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    float *v, the pointer to the initial element of the vector.
*/
{
  free ( v );

  v = NULL;

  return;
}
/******************************************************************************/

void free_vector_double ( double *v )

/******************************************************************************/
/*
  Purpose:

    free_vector_double releases a pointer for a double vector.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    double *v, the pointer to the initial element of the vector.
*/
{
  free ( v );

  v = NULL;

  return;
}
/******************************************************************************/

double **make_matrix_double ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    make_matrix_double sets up memory and pointers for a 2D double matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    size_t m, n, the number of rows and columns.

  Output:

    double **make_matrix_double, pointers to the initial elements of each row.
*/
{
  double **a;
  int i;

  a = ( double ** ) malloc ( ( m + 1 ) * sizeof ( double* ) );

  for ( i = 0; i < m; i++ )
  {
    a[i] = ( double * ) malloc ( n * sizeof ( double ) );
  }

  a[m] = NULL;

  return a;
}
/******************************************************************************/

float **make_matrix_float ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    make_matrix_float sets up memory and pointers for a float matrix.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    size_t m, n, the number of rows and columns.

  Output:

    float **make_matrix_float, pointers to the initial elements of each row.
*/
{
  float **a;
  int i;

  a = ( float ** ) malloc ( ( m + 1 ) * sizeof ( float* ) );

  for ( i = 0; i < m; i++ )
  {
    a[i] = ( float * ) malloc ( n * sizeof ( float ) );
  }

  a[m] = NULL;

  return a;
}
/******************************************************************************/

double *make_vector_double ( int n )

/******************************************************************************/
/*
  Purpose:

    make_vector_double sets up a pointer for a double vector.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    int n, the number of entries needed for the vector.

  Output:

    double *make_vector_double, a pointer to the initial elements of the vector.
*/
{
  double *v;

  v = ( double * ) malloc ( n * sizeof ( double ) );

  return v;
}
/******************************************************************************/

float *make_vector_float ( int n )

/******************************************************************************/
/*
  Purpose:

    make_vector_float sets up a pointer for a float vector.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 July 2019

  Author:

    John Burkardt

  Reference:

    Rouben Rostamian,
    Programming Projects in C 
    for Students of Engineering, Science, and Mathematics,
    SIAM, 2014,
    ISBN: 978-1-611973-49-5

  Input:

    int n, the number of entries needed for the vector.

  Output:

    double *make_vector_float, a pointer to the initial elements of the vector.
*/
{
  float *v;

  v = ( float * ) malloc ( n * sizeof ( float ) );

  return v;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

