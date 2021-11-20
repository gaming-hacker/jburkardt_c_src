#! /bin/bash
#
cp tetrahedron_grid.h /$HOME/include
#
gcc -c -Wall tetrahedron_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_grid.o ~/libc/tetrahedron_grid.o
#
echo "Normal end of execution."
