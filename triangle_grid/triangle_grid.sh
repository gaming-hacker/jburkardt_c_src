#! /bin/bash
#
cp triangle_grid.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_grid.o ~/libc/triangle_grid.o
#
echo "Normal end of execution."
