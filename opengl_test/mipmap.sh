#! /bin/bash
#
gcc -c -Wall mipmap.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mipmap.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mipmap.o
mv a.out mipmap
#
echo "Normal end of execution."
