#! /bin/bash
#
gcc -c -Wall nile_histogram.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc nile_histogram.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm nile_histogram.o
#
mv a.out nile_histogram
./nile_histogram > nile_histogram.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm nile_histogram
#
#  Generate graphics.
#
gnuplot < nile_commands.txt
#
echo "Normal end of execution."
