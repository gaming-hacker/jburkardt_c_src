#! /bin/bash
#
gcc -c -Wall select.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc select.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm select.o
mv a.out select
#
echo "Normal end of execution."
