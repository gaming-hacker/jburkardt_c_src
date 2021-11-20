#! /bin/bash
#
gcc -c -Wall histogram.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall read_image.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc histogram.o read_image.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm histogram.o
rm read_image.o
mv a.out histogram
#
echo "Normal end of execution."
