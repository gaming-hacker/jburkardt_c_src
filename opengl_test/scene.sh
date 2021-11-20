#! /bin/bash
#
gcc -c -Wall scene.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc scene.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm scene.o
mv a.out scene
#
echo "Normal end of execution."
