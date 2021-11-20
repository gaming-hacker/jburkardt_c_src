#! /bin/bash
#
gcc -c -Wall -I/$HOME/include tetrahedron_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tetrahedron_grid_test.o /$HOME/libc/tetrahedron_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tetrahedron_grid_test.o
#
mv a.out tetrahedron_grid_test
./tetrahedron_grid_test > tetrahedron_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tetrahedron_grid_test
#
echo "Normal end of execution."
