#! /bin/bash
#
cp sphere_fibonacci_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sphere_fibonacci_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_fibonacci_grid.o ~/libc/sphere_fibonacci_grid.o
#
echo "Normal end of execution."
