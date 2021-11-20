#! /bin/bash
#
cp hankel_cholesky.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hankel_cholesky.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hankel_cholesky.o ~/libc/hankel_cholesky.o
#
echo "Normal end of execution."
