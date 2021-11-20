#! /bin/bash
#
gcc -c -Wall teapot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Mac OSX
#
#gcc teapot.o -framework GLUT -framework OpenGL
#
#  Ubuntu.
#
gcc teapot.o -lglut -lGLU -lGL -lm
#
#  This is how to access the OpenGL and GLUT libraries under a standard installation.
#
#gcc teapot.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm teapot.o
mv a.out ~/binc/teapot
#
echo "Normal end of execution."
