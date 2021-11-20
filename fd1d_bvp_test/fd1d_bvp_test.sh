#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fd1d_bvp_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_bvp_test.o /$HOME/libc/fd1d_bvp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd1d_bvp_test.o
#
mv a.out fd1d_bvp_test
./fd1d_bvp_test > fd1d_bvp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fd1d_bvp_test
#
echo "Normal end of execution."
