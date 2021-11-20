#! /bin/bash
#
gcc -c -Wall mandelbrot_ascii.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mandelbrot_ascii.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mandelbrot_ascii.o
mv a.out ~/binc/mandelbrot_ascii
#
echo "Normal end of execution."
