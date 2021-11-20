#! /bin/bash
#
gcc -c -Wall geyser_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc geyser_scatter.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm geyser_scatter.o
#
mv a.out geyser_scatter
./geyser_scatter > geyser_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm geyser_scatter
#
#  Generate graphics.
#
gnuplot < geyser_commands.txt
#
echo "Normal end of execution."
