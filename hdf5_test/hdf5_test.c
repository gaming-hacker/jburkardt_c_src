# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "hdf5.h"

int main ( );
void hdf5_test01 ( );
void hdf5_test02 ( );
void hdf5_test03 ( );
void hdf5_test04 ( );
int i4vec_product ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for HDF5_TEST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "HDF5_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the HDF5 library.\n" );

  hdf5_test01 ( );
  hdf5_test02 ( );
  hdf5_test03 ( );
  hdf5_test04 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "HDF5_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void hdf5_test01 ( )

/******************************************************************************/
/*
  Purpose:

    HDF5_TEST01 simply creates an HdF5 file.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2017

  Author:

    John Burkardt
*/
{
  hid_t  file_id;
  herr_t status;

  printf ( "\n" );
  printf ( "HDF5_TEST01:\n" );
  printf ( "  Create an HDF file 'test01.h5'.\n" );
/*
  Get the file id.
*/
  file_id = H5Fcreate ( "test01.h5", H5F_ACC_TRUNC, H5P_DEFAULT,
    H5P_DEFAULT );
/*
  Close the file.
*/
  status = H5Fclose ( file_id );

  return;
}
/******************************************************************************/

void hdf5_test02 ( )

/******************************************************************************/
/*
  Purpose:

    HDF5_TEST02 creates a dataset.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2017

  Author:

    John Burkardt
*/
{
  hid_t   dataset_id;
  hid_t   dataspace_id;
  hsize_t dims[2];
  hid_t   file_id;
  herr_t  status;

  printf ( "\n" );
  printf ( "HDF5_TEST02:\n" );
  printf ( "  Create an HDF file 'test02.h5' containing a dataset.\n" );
/*
  Get the file id.
*/
  file_id = H5Fcreate ( "test02.h5", H5F_ACC_TRUNC, H5P_DEFAULT,
    H5P_DEFAULT );

  dims[0] = 4;
  dims[1] = 6;

  dataspace_id = H5Screate_simple ( 2, dims, NULL );

  dataset_id = H5Dcreate ( file_id, "/dset", H5T_STD_I32BE,
    dataspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT );
/*
  Close the data set.
*/
  status = H5Dclose ( dataset_id );
/*
  Close the data space.
*/
  status = H5Sclose ( dataspace_id );
/*
  Close the file.
*/
  status = H5Fclose ( file_id );

  return;
}
/******************************************************************************/

void hdf5_test03 ( )

/******************************************************************************/
/*
  Purpose:

    HDF5_TEST03 creates a dataset and puts data into it.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2017

  Author:

    John Burkardt
*/
{
  int     dset_data[4*6];
  hsize_t dset_dims[2] = { 4, 6 };
  hid_t   dset_id;
  char   *dset_name = "/dset";
  int     dset_rank = 2;
  hid_t   dspace_id;
  hid_t   file_id;
  char   *file_name = "test03.h5";
  int     i;
  int     j;
  herr_t  status;

  printf ( "\n" );
  printf ( "HDF5_TEST03:\n" );
  printf ( "  Create an HDF file 'test03.h5'\n" );
  printf ( "  Create a dataset.\n" );
  printf ( "  Put data into the dataset.\n" );
/*
  Get the file id.
*/
  file_id = H5Fcreate ( file_name, H5F_ACC_TRUNC, H5P_DEFAULT,
    H5P_DEFAULT );
/*
  Get the data space id.
*/
  dspace_id = H5Screate_simple ( dset_rank, dset_dims, NULL );
/*
  Get the data set id.
*/
  dset_id = H5Dcreate ( file_id, dset_name, H5T_STD_I32BE,
    dspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT );
/*
  Create the data.
*/
  for ( i = 0; i < 4; i++ )
  {
    for ( j = 0; j < 6; j++ )
    {
      dset_data[j+i*6] = 6 * i + j + 1;
    }
  }
/*
  Write the data to the dataset.
*/
  status = H5Dwrite ( dset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT,
    dset_data );
/*
  Print the data.
*/
  printf ( "\n" );
  printf ( "  Dataset /dset written to test03.h5\n" );
  printf ( "\n" );
  for ( i = 0; i < 4; i++ )
  {
    for ( j = 0; j < 6; j++ )
    {
      printf ( "  dset_data[%d][%d] = %d\n", i, j, dset_data[j+i*6] );
    }
  }
/*
  Close the data set.
*/
  status = H5Dclose ( dset_id );
/*
  Close the data space.
*/
  status = H5Sclose ( dspace_id );
/*
  Close the file.
*/
  status = H5Fclose ( file_id );

  return;
}
/******************************************************************************/

void hdf5_test04 ( )

/******************************************************************************/
/*
  Purpose:

    HDF5_TEST04 reads the data from the dataset created by HDF_TEST03.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 February 2017

  Author:

    John Burkardt
*/
{
  int    **dset_data;
  hsize_t *dset_dims;
  hid_t    dset_id;
  char    *dset_name = "/dset";
  int      dset_rank;
  int      dset_size;
  hid_t    dspace_id;
  hid_t    file_id;
  char    *file_name = "test03.h5";
  int      i;
  int      j;
  herr_t   status;

  printf ( "\n" );
  printf ( "HDF5_TEST04:\n" );
  printf ( "  Open the HDF file 'test03.h5'\n" );
  printf ( "  Access a dataset.\n" );
  printf ( "  Read the data from the dataset.\n" );
/*
  Get the file id.
*/
  file_id = H5Fopen ( file_name, H5F_ACC_RDONLY, H5P_DEFAULT );
/*
  Open the data set.
*/
  dset_id = H5Dopen2 ( file_id, dset_name, H5P_DEFAULT );
/*
  Get the data space ID.
*/
  dspace_id = H5Dget_space ( dset_id );
/*
  Get the rank of the data set.
*/
  dset_rank = H5Sget_simple_extent_ndims ( dspace_id );
/*
  Get the dimensions of the data set.
*/
  dset_dims = ( hsize_t * ) calloc ( dset_rank, sizeof ( hsize_t ) );

  status = H5Sget_simple_extent_dims ( dspace_id, dset_dims, NULL );
/*
  Set up pointers for 2D dynamic array.
*/
  dset_size = 1;
  for ( i = 0; i < dset_rank; i++ )
  {
    dset_size = dset_size * dset_dims[i];
  }
  dset_data = ( int ** ) malloc ( dset_dims[0] * sizeof ( int * ) );

  dset_data[0] = ( int * ) malloc ( dset_size * sizeof ( int ) );
  for ( i = 1; i < dset_dims[0]; i++ )
  {
    dset_data[i] = dset_data[0] + i * dset_dims[1];
  }
/*
  Read the data from the dataset.
*/
  status = H5Dread ( dset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT,
    &dset_data[0][0] );
/*
  Print the data.
*/
  printf ( "\n" );
  printf ( "  Dataset /dset read from test03.h5\n" );
  printf ( "\n" );
  for ( i = 0; i < 4; i++ )
  {
    for ( j = 0; j < 6; j++ )
    {
      printf ( "  dset_data[%d][%d] = %d\n", i, j, dset_data[i][j] );
    }
  }
/*
  Close the data set.
*/
  status = H5Dclose ( dset_id ); 
/*
  Close the data space.
*/
  status = H5Sclose ( dspace_id );
/*
  Close the file.
*/
  status = H5Fclose ( file_id );
/*
  Free memory.
*/
  free ( dset_data[0] );
  free ( dset_data );
  free ( dset_dims );

  return;
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

