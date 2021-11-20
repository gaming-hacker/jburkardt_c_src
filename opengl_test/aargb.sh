#!/bin/bash
#
gcc -c -Wall aargb.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc aargb.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm aargb.o
mv a.out aargb
#
echo "Normal end of execution."
