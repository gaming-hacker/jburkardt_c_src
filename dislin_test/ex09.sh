#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin ex09.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o ex09 ex09.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ex09.o
#
./ex09 > ex09.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex09
#
echo "Normal end of execution."
