#! /bin/bash
#
gcc -c -Wall -I/$HOME/include bvec_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc bvec_test.o /$HOME/libc/bvec.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bvec_test.o
#
mv a.out bvec_test
./bvec_test > bvec_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bvec_test
#
echo "Normal end of execution."
