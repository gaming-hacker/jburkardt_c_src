#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sphere_llq_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o sphere_llq_grid_test sphere_llq_grid_test.o /$HOME/libc/sphere_llq_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_llq_grid_test.o
#
./sphere_llq_grid_test > sphere_llq_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_llq_grid_test
#
echo "Normal end of execution."
