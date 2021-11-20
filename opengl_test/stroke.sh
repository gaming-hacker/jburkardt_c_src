#! /bin/bash
#
gcc -c -Wall stroke.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc stroke.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stroke.o
mv a.out stroke
#
echo "Normal end of execution."
