# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "ppc_array.h"

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
  if ( a != NULL )
  {
    for ( size_t i = 0; a[i] != NULL; i++ )
    {
      free_vector ( a[i] );
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

    free_matrix_float releases memory and pointers for a 2D float matrix.

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
  if ( a != NULL )
  {
    for ( size_t i = 0; a[i] != NULL; i++ )
    {
      free_vector ( a[i] );
    }
    free ( a );
  }
  return;
}
/******************************************************************************/

double **make_matrix_double ( size_t m, size_t n )

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
  make_vector ( a, m + 1 );
  for ( size_t i = 0; i < m; i++ )
  {
    make_vector ( a[i], n );
  }
  a[m] = NULL;

  return a;
}
/******************************************************************************/

float **make_matrix_float ( size_t m, size_t n )

/******************************************************************************/
/*
  Purpose:

    make_matrix_float sets up memory and pointers for a 2D float matrix.

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
  make_vector ( a, m + 1 );
  for ( size_t i = 0; i < m; i++ )
  {
    make_vector ( a[i], n );
  }
  a[m] = NULL;

  return a;
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

