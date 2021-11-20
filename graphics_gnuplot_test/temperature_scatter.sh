#! /bin/bash
#
gcc -c -Wall temperature_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc temperature_scatter.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm temperature_scatter.o
#
mv a.out temperature_scatter
./temperature_scatter > temperature_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm temperature_scatter
#
#  Generate graphics.
#
gnuplot < temperature_commands.txt
#
echo "Normal end of execution."
