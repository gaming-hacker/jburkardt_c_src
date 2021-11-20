#! /bin/bash
#
gcc -c -Wall least_squares_plots.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc least_squares_plots.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm least_squares_plots.o
#
mv a.out least_squares_plots
./least_squares_plots > least_squares_plots.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm least_squares_plots
#
#  Generate graphics.
#
gnuplot < least_squares_commands.txt
#
echo "Normal end of execution."
