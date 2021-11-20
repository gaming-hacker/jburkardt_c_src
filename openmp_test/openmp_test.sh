#! /bin/bash
#
echo "openmp_test:"
#
./compute_pi_openmp_test.sh
./dot_product_openmp_test.sh
./helmholtz_openmp_test.sh
./saxpy_openmp_test.sh
#
echo "Normal end of execution."

