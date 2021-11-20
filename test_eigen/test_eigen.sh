#! /bin/bash
#
cp test_eigen.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_eigen.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_eigen.o ~/libc/test_eigen.o
#
echo "Normal end of execution."
