#! /bin/bash
#
gcc -c -Wall aaindex.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc aaindex.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm aaindex.o
mv a.out aaindex
#
echo "Normal end of execution."
