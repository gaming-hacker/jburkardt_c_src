#! /bin/bash
#
gcc -c -Wall multitex.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc multitex.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm multitex.o
mv a.out multitex
#
echo "Normal end of execution."
