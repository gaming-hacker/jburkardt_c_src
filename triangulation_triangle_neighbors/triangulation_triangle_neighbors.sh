#! /bin/bash
#
gcc -c -Wall triangulation_triangle_neighbors.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangulation_triangle_neighbors.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_triangle_neighbors.o
#
chmod ugo+x a.out
mv a.out ~/binc/triangulation_triangle_neighbors
#
echo "Normal end of execution."
