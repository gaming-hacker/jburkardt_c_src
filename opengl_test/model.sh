#! /bin/bash
#
gcc -c -Wall model.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc model.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm model.o
mv a.out model
#
echo "Normal end of execution."
