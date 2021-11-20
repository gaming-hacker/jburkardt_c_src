#! /bin/bash
#
gcc -c -Wall figuretree.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc figuretree.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm figuretree.o
mv a.out figuretree
#
echo "Normal end of execution."
