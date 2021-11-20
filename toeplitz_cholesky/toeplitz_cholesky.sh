#! /bin/bash
#
cp toeplitz_cholesky.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toeplitz_cholesky.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toeplitz_cholesky.o ~/libc/toeplitz_cholesky.o
#
echo "Normal end of execution."
