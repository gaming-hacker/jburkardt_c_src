#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ball_grid_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ball_grid_test.o /$HOME/libc/ball_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ball_grid_test.o
#
mv a.out ball_grid_test
./ball_grid_test > ball_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ball_grid_test
#
echo "Normal end of execution."
