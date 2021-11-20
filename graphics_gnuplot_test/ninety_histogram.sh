#! /bin/bash
#
gcc -c -Wall ninety_histogram.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ninety_histogram.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ninety_histogram.o
#
mv a.out ninety_histogram
./ninety_histogram > ninety_histogram.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ninety_histogram
#
#  Generate graphics.
#
gnuplot < ninety_commands.txt
#
echo "Normal end of execution."
