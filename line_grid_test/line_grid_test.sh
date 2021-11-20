#! /bin/bash
#
gcc -c -Wall -I/$HOME/include line_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o line_grid_test line_grid_test.o /$HOME/libc/line_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_grid_test.o
#
./line_grid_test > line_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_grid_test
#
echo "Normal end of execution."
