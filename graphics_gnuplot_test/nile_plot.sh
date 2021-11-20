#! /bin/bash
#
gcc -c -Wall nile_plot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc nile_plot.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm nile_plot.o
#
mv a.out nile_plot
./nile_plot > nile_plot.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm nile_plot
#
#  Generate graphics.
#
gnuplot < nile_commands.txt
#
echo "Normal end of execution."
