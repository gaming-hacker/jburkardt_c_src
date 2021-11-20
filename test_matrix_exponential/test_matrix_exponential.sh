#! /bin/bash
#
cp test_matrix_exponential.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_matrix_exponential.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_matrix_exponential.o ~/libc/test_matrix_exponential.o
#
echo "Normal end of execution."
