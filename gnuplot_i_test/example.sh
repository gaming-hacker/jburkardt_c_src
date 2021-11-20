#! /bin/bash
#
gcc -c -Wall -I/$HOME/include example.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc example.o ~/libc/gnuplot_i.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm example.o
#
mv a.out ~/binc/example
#
echo "Normal end of execution."
