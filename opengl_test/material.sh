#! /bin/bash
#
gcc -c -Wall material.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc material.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm material.o
mv a.out material
#
echo "Normal end of execution."
