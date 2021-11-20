#! /bin/bash
#
gcc -c -Wall -I/$HOME/include circle_arc_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc circle_arc_grid_test.o /$HOME/libc/circle_arc_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_arc_grid_test.o
#
mv a.out circle_arc_grid_test
./circle_arc_grid_test > circle_arc_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_arc_grid_test
#
echo "Normal end of execution."
