#! /bin/bash
#
gcc -c -Wall figure.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc figure.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm figure.o
mv a.out figure
#
echo "Normal end of execution."
