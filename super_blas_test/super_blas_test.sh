#! /bin/bash
#
./super_blas1_c_test.sh >  super_blas_test.txt
./super_blas1_d_test.sh >> super_blas_test.txt
./super_blas1_s_test.sh >> super_blas_test.txt
./super_blas1_z_test.sh >> super_blas_test.txt
#
echo "Normal end of execution."
