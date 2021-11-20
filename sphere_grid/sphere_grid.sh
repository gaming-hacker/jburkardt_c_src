#! /bin/bash
#
cp sphere_grid.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sphere_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_grid.o ~/libc/sphere_grid.o
#
echo "Normal end of execution."
