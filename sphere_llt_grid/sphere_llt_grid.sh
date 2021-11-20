#! /bin/bash
#
cp sphere_llt_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sphere_llt_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_llt_grid.o ~/libc/sphere_llt_grid.o
#
echo "Normal end of execution."
