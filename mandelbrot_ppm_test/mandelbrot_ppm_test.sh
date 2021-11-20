#! /bin/bash
#
$HOME/binc/mandelbrot_ppm > mandelbrot.ppm
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

