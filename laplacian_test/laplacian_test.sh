#! /bin/bash
#
gcc -c -Wall -I/$HOME/include laplacian_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc laplacian_test.o /$HOME/libc/laplacian.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm laplacian_test.o
#
mv a.out laplacian_test
./laplacian_test > laplacian_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm laplacian_test
#
echo "Normal end of execution."
