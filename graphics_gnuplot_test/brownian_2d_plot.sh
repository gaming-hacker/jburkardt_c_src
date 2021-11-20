#! /bin/bash
#
gcc -c -Wall brownian_2d_plot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc brownian_2d_plot.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm brownian_2d_plot.o
#
mv a.out brownian_2d_plot
./brownian_2d_plot > brownian_2d_plot.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm brownian_2d_plot
#
#  Generate graphics.
#
gnuplot < brownian_2d_commands.txt
#
echo "Normal end of execution."
