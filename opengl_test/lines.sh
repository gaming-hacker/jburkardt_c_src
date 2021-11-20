#! /bin/bash
#
gcc -c -Wall lines.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc lines.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lines.o
mv a.out lines
#
echo "Normal end of execution."
