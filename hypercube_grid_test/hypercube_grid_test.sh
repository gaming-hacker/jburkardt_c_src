#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hypercube_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o hypercube_grid_test hypercube_grid_test.o /$HOME/libc/hypercube_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypercube_grid_test.o
#
./hypercube_grid_test > hypercube_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypercube_grid_test
#
echo "Normal end of execution."
