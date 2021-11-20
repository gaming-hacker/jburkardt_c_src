#! /bin/bash
#
cp blas3_s.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas3_s.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas3_s.o ~/libc/blas3_s.o
#
echo "Normal end of execution"
