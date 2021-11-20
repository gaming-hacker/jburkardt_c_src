#! /bin/bash
#
cp sphere_llq_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sphere_llq_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_llq_grid.o ~/libc/sphere_llq_grid.o
#
echo "Normal end of execution."
