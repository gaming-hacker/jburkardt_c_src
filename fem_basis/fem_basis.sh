#! /bin/bash
#
cp fem_basis.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem_basis.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem_basis.o ~/libc/fem_basis.o
#
echo "Normal end of execution."
