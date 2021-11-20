#! /bin/bash
#
gcc -c -Wall light.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc light.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm light.o
mv a.out light
#
echo "Normal end of execution."
