#! /bin/bash
#
gcc -c -Wall pickdepth.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pickdepth.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pickdepth.o
mv a.out pickdepth
#
echo "Normal end of execution."
