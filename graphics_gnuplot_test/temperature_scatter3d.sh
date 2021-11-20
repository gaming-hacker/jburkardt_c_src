#! /bin/bash
#
gcc -c -Wall temperature_scatter3d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc temperature_scatter3d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm temperature_scatter3d.o
#
mv a.out temperature_scatter3d
./temperature_scatter3d > temperature_scatter3d.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm temperature_scatter3d
#
#  Generate graphics.
#
gnuplot < temperature_commands.txt
#
echo "Normal end of execution."
