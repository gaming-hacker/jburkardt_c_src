#! /bin/bash
#
gcc -c -Wall movelight.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc movelight.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm movelight.o
mv a.out movelight
#
echo "Normal end of execution."
