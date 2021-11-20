#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hankel_pds_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o hankel_pds_test hankel_pds_test.o /$HOME/libc/hankel_pds.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hankel_pds_test.o
#
./hankel_pds_test > hankel_pds_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hankel_pds_test
#
echo "Normal end of execution."
