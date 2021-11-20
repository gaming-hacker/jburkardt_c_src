#! /bin/bash
#
gcc -c -Wall single_double.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc single_double.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm single_double.o
mv a.out single_double
#
echo "Normal end of execution."
