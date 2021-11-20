#! /bin/bash
#
cp hypercube_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hypercube_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypercube_grid.o ~/libc/hypercube_grid.o
#
echo "Normal end of execution."
