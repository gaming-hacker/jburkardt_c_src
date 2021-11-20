#! /bin/bash
#
cp ellipsoid_grid.h /$HOME/include
#
gcc -c -Wall ellipsoid_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ellipsoid_grid.o ~/libc/ellipsoid_grid.o
#
echo "Normal end of execution."
