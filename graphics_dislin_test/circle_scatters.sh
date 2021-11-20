#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin circle_scatters.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o circle_scatters circle_scatters.o -L/usr/local/dislin -ldislin -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm circle_scatters.o
#
./circle_scatters > circle_scatters.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_scatters
#
echo "Normal end of execution."
