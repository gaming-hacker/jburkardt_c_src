#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin geyser_bar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc geyser_bar.o -L/usr/local/dislin -ldislin -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm geyser_bar.o
#
mv a.out geyser_bar
./geyser_bar > geyser_bar.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm geyser_bar
#
echo "Normal end of execution."
