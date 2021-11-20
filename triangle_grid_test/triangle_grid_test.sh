#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_grid_test.o /$HOME/libc/triangle_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_grid_test.o
#
mv a.out triangle_grid_test
./triangle_grid_test > triangle_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_grid_test
#
echo "Normal end of execution."
