#! /bin/bash
#
gcc -c -Wall double.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc double.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm double.o
mv a.out double
#
echo "Normal end of execution."
