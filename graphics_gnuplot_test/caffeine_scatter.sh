#! /bin/bash
#
gcc -c -Wall caffeine_scatter.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc caffeine_scatter.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm caffeine_scatter.o
#
mv a.out caffeine_scatter
./caffeine_scatter > caffeine_scatter.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm caffeine_scatter
#
#  Generate graphics.
#
gnuplot < caffeine_commands.txt
#
echo "Normal end of execution."
