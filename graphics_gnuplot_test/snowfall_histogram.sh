#! /bin/bash
#
gcc -c -Wall snowfall_histogram.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc snowfall_histogram.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm snowfall_histogram.o
#
mv a.out snowfall_histogram
./snowfall_histogram > snowfall_histogram.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm snowfall_histogram
#
#  Generate graphics.
#
gnuplot < snowfall_commands.txt
#
echo "Normal end of execution."
