#! /bin/bash
#
gcc -c -Wall track_bar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc track_bar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm track_bar.o
#
mv a.out track_bar
./track_bar > track_bar.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm track_bar
#
#  Generate graphics.
#
gnuplot < track_commands.txt
#
echo "Normal end of execution."
