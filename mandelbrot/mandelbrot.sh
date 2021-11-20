#! /bin/bash
#
gcc -c -Wall mandelbrot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mandelbrot.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mandelbrot.o
#
mv a.out ~/binc/mandelbrot
#
echo "Normal end of execution."
