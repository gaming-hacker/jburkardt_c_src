#! /bin/bash
#
gcc -c -Wall image.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc image.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm image.o
mv a.out image
#
echo "Normal end of execution."
