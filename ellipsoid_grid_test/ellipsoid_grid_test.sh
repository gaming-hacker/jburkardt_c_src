#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ellipsoid_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ellipsoid_grid_test.o /$HOME/libc/ellipsoid_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ellipsoid_grid_test.o
#
mv a.out ellipsoid_grid_test
./ellipsoid_grid_test > ellipsoid_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ellipsoid_grid_test
#
echo "Normal end of execution."
