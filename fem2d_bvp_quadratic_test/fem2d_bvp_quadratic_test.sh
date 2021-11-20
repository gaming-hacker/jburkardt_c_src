#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fem2d_bvp_quadratic_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem2d_bvp_quadratic_test.o ~/libc/fem2d_bvp_quadratic.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fem2d_bvp_quadratic_test.o
#
mv a.out fem2d_bvp_quadratic_test
./fem2d_bvp_quadratic_test > fem2d_bvp_quadratic_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem2d_bvp_quadratic_test
#
echo "Normal end of execution."
