#! /bin/bash
#
cp cyclic_reduction.h /$HOME/include
#
gcc -c -Wall cyclic_reduction.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cyclic_reduction.o ~/libc/cyclic_reduction.o
#
echo "Normal end of execution."
