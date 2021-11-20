#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sphere_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere_grid_test.o /$HOME/libc/sphere_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_grid_test.o
#
mv a.out sphere_grid_test
./sphere_grid_test > sphere_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_grid_test
#
mv *.xyz ../../datasets/sphere_grid
echo "XYZ data files moved to ../../datasets/sphere_grid directory."
#
echo "Normal end of execution."
