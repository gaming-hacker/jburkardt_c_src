#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ubvec_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o ubvec_test ubvec_test.o /$HOME/libc/ubvec.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ubvec_test.o
#
./ubvec_test > ubvec_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ubvec_test
#
echo "Normal end of execution."
