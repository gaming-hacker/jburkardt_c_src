#! /bin/bash
#
gcc -c -Wall polys.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polys.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polys.o
mv a.out polys
#
echo "Normal end of execution."
