#! /bin/bash
#
gcc -c -Wall automobile_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc automobile_scatter.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm automobile_scatter.o
#
mv a.out automobile_scatter
./automobile_scatter > automobile_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm automobile_scatter
#
#  Generate graphics.
#
gnuplot < automobile_commands.txt
#
echo "Normal end of execution."
