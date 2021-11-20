#! /bin/bash
#
gcc -c -Wall corvette_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc corvette_scatter.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm corvette_scatter.o
#
mv a.out corvette_scatter
./corvette_scatter > corvette_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm corvette_scatter
#
#  Generate graphics.
#
gnuplot < corvette_commands.txt
#
echo "Normal end of execution."
