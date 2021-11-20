#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin life_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o life_grid life_grid.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm life_grid.o
#
./life_grid > life_grid.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm life_grid
#
echo "Normal end of execution."
