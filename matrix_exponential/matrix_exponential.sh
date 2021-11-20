#! /bin/bash
#
cp matrix_exponential.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include matrix_exponential.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv matrix_exponential.o ~/libc/matrix_exponential.o
#
echo "Normal end of execution."
