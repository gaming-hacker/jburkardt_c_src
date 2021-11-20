#! /bin/bash
#
cp blas3_d.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas3_d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas3_d.o ~/libc/blas3_d.o
#
echo "Normal end of execution."
