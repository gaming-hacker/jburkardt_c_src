#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin quickplot_contour.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quickplot_contour quickplot_contour.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quickplot_contour.o
#
./quickplot_contour > quickplot_contour.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_contour
#
echo "Normal end of execution."
