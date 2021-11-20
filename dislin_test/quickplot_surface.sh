#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin quickplot_surface.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quickplot_surface quickplot_surface.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quickplot_surface.o
#
./quickplot_surface > quickplot_surface.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_surface
#
echo "Normal end of execution."
