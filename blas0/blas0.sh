#! /bin/bash
#
cp blas0.h /$HOME/include
#
gcc -c -Wall blas0.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas0.o ~/libc/blas0.o
#
echo "Normal end of execution."
