#! /bin/bash
#
gcc -c -Wall planet.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  This is how to access the OpenGL and GLUT libraries under Mac OSX.
#
#gcc planet.o -framework GLUT -framework OpenGL
#
#  This is how to access the OpenGL and GLUT libraries under a standard installation.
#
gcc planet.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm planet.o
mv a.out planet
#
echo "Normal end of execution."
