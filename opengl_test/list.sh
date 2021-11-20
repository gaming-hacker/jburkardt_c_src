#! /bin/bash
#
gcc -c -Wall list.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc list.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm list.o
mv a.out list
#
echo "Normal end of execution."
