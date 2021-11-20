#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_svg_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_svg_test.o /$HOME/libc/triangle_svg.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_svg_test.o
#
mv a.out triangle_svg_test
./triangle_svg_test > triangle_svg_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_svg_test
#
echo "Normal end of execution."
