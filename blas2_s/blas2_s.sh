#! /bin/bash
#
cp blas2_s.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas2_s.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas2_s.o ~/libc/blas2_s.o
#
echo "Normal end of execution."
