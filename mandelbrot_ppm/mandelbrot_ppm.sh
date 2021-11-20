#! /bin/bash
#
gcc -c -Wall mandelbrot_ppm.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mandelbrot_ppm.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mandelbrot_ppm.o
#
mv a.out ~/binc/mandelbrot_ppm
#
echo "Normal end of execution."
