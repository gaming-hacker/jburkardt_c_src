#! /bin/bash
#
gcc -c -Wall fog.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fog.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fog.o
mv a.out fog
#
echo "Normal end of execution."
