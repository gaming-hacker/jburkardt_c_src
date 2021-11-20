#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin quickplot_pie.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quickplot_pie quickplot_pie.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quickplot_pie.o
#
./quickplot_pie > quickplot_pie.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_pie
#
echo "Normal end of execution."
