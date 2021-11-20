#! /bin/bash
#
gcc -c -Wall bulgaria_plot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc bulgaria_plot.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm bulgaria_plot.o
#
mv a.out bulgaria_plot
./bulgaria_plot > bulgaria_plot.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bulgaria_plot
#
#  Generate graphics.
#
gnuplot < bulgaria_commands.txt
#
echo "Normal end of execution."
