#! /bin/bash
#
gcc -c -Wall -I/$HOME/include beta_nc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc beta_nc_test.o /$HOME/libc/beta_nc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm beta_nc_test.o
#
mv a.out beta_nc_test
./beta_nc_test > beta_nc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm beta_nc_test
#
echo "Normal end of execution."
