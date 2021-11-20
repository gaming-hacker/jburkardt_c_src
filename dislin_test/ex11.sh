#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin ex11.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o ex11 ex11.o -L/usr/local/dislin -ldislin_d -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ex11.o
#
./ex11 > ex11.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex11
#
echo "Normal end of execution."
