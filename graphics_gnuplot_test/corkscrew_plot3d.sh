#! /bin/bash
#
gcc -c -Wall corkscrew_plot3d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc corkscrew_plot3d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm corkscrew_plot3d.o
#
mv a.out corkscrew_plot3d
./corkscrew_plot3d > corkscrew_plot3d.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm corkscrew_plot3d
#
#  Generate graphics.
#
gnuplot < corkscrew_commands.txt
#
echo "Normal end of execution."
