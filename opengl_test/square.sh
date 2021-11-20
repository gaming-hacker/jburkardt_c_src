#! /bin/bash
#
gcc -c -Wall square.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc square.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square.o
mv a.out square
#
echo "Normal end of execution."
