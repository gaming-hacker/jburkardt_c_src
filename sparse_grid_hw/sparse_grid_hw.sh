#! /bin/bash
#
cp sparse_grid_hw.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sparse_grid_hw.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_hw.o ~/libc/sparse_grid_hw.o
#
echo "Normal end of execution."
