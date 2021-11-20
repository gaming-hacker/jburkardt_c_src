#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin grid_surface.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc grid_surface.o -L/usr/local/dislin -ldislin -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm grid_surface.o
#
mv a.out grid_surface
./grid_surface > grid_surface.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm grid_surface
#
echo "Normal end of execution."
