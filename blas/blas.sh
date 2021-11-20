#! /bin/bash
#
cd ../blas0
./blas0.sh
#
cd ../blas1_c
./blas1_c.sh
cd ../blas1_d
./blas1_d.sh
cd ../blas1_s
./blas1_s.sh
cd ../blas1_z
./blas1_z.sh
#
cd ../blas2_d
./blas2_d.sh
cd ../blas2_s
./blas2_s.sh
#
cd ../blas3_d
./blas3_d.sh
cd ../blas3_s
./blas3_s.sh
cd ../blas
#
echo "Normal end of execution."