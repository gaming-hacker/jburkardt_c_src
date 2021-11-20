#! /bin/bash
#
gcc -c -Wall stencil.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc stencil.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stencil.o
mv a.out stencil
#
echo "Normal end of execution."
