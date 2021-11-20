#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin quickplot_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quickplot_scatter quickplot_scatter.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quickplot_scatter.o
#
./quickplot_scatter > quickplot_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_scatter
#
echo "Normal end of execution."
