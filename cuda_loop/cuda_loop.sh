#! /bin/bash
#
cp cuda_loop.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cuda_loop.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cuda_loop.o ~/libc/cuda_loop.o
#
echo "Normal end of execution."
