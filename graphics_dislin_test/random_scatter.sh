#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin random_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc random_scatter.o -L/usr/local/dislin -ldislin -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm random_scatter.o
#
mv a.out random_scatter
./random_scatter > random_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm random_scatter
#
echo "Normal end of execution."
