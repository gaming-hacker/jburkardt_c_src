#! /bin/bash
#
gcc -c -Wall price_plots.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc price_plots.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm price_plots.o
#
mv a.out price_plots
./price_plots > price_plots.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm price_plots
#
#  Generate graphics.
#
gnuplot < price_commands.txt
#
echo "Normal end of execution."
