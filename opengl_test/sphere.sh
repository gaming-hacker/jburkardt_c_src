#! /bin/bash
#
gcc -c -Wall sphere.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere.o
mv a.out sphere
#
echo "Normal end of execution."
