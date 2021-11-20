#! /bin/bash
#
cp test_mat.h /$HOME/include
#
gcc -c -Wall test_mat.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_mat.o ~/libc/test_mat.o
#
echo "Normal end of execution."
