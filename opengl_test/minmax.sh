#! /bin/bash
#
gcc -c -Wall minmax.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c read_image.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
cc minmax.o read_image.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm minmax.o
rm read_image.o
mv a.out minmax
#
echo "Normal end of execution."
