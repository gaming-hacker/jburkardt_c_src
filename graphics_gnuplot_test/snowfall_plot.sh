#! /bin/bash
#
gcc -c -Wall snowfall_plot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc snowfall_plot.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm snowfall_plot.o
#
mv a.out snowfall_plot
./snowfall_plot > snowfall_plot.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm snowfall_plot
#
#  Generate graphics.
#
gnuplot < snowfall_commands.txt
#
echo "Normal end of execution."
