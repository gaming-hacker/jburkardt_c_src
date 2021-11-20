#! /bin/bash
#
gcc -c -Wall -I$HOME/include svd_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc svd_test.o $HOME/libc/linpack_d.o $HOME/libc/blas1_d.o  $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm svd_test.o
#
chmod ugo+x a.out
mv a.out ~/binc/svd_test
#
echo "Normal end of execution."
