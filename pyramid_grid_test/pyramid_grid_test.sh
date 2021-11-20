#! /bin/bash
#
gcc -c -Wall -I/$HOME/include pyramid_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o pyramid_grid_test pyramid_grid_test.o /$HOME/libc/pyramid_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pyramid_grid_test.o
#
./pyramid_grid_test > pyramid_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pyramid_grid_test
#
echo "Normal end of execution."
