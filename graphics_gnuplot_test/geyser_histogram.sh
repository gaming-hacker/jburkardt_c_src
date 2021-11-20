#! /bin/bash
#
gcc -c -Wall geyser_histogram.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc geyser_histogram.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm geyser_histogram.o
#
mv a.out geyser_histogram
./geyser_histogram > geyser_histogram.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm geyser_histogram
#
#  Generate graphics.
#
gnuplot < geyser_commands.txt
#
echo "Normal end of execution."
