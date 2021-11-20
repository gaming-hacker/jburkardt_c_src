#! /bin/bash
#
gcc -c -Wall -I/$HOME/include wedge_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o wedge_grid_test wedge_grid_test.o /$HOME/libc/wedge_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wedge_grid_test.o
#
./wedge_grid_test > wedge_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wedge_grid_test
#
echo "Normal end of execution."
