#! /bin/bash
#
cp sparse_grid_cc.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sparse_grid_cc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_cc.o ~/libc/sparse_grid_cc.o
#
echo "Normal end of execution."
