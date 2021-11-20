#! /bin/bash
#
gcc -c -Wall -I/$HOME/include super_blas1_z_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc super_blas1_z_test.o /$HOME/libc/super_blas.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm super_blas1_z_test.o
#
mv a.out super_blas1_z_test
./super_blas1_z_test > super_blas1_z_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm super_blas1_z_test
#
echo "Normal end of execution."
