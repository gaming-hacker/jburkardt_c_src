#! /bin/bash
#
cp blas2_d.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas2_d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas2_d.o ~/libc/blas2_d.o
#
echo "Normal end of execution."
