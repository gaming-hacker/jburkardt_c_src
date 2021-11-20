#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin quickplot_bar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quickplot_bar quickplot_bar.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quickplot_bar.o
#
./quickplot_bar > quickplot_bar.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_bar
#
echo "Normal end of execution."
