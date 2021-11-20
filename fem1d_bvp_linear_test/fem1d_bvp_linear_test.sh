#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fem1d_bvp_linear_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem1d_bvp_linear_test.o ~/libc/fem1d_bvp_linear.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fem1d_bvp_linear_test.o
#
mv a.out fem1d_bvp_linear_test
./fem1d_bvp_linear_test > fem1d_bvp_linear_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem1d_bvp_linear_test
#
echo "Normal end of execution."
