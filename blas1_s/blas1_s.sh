#! /bin/bash
#
cp blas1_s.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas1_s.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas1_s.o ~/libc/blas1_s.o
#
echo "Normal end of execution."
