#! /bin/bash
#
gcc -c -Wall hello.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  This is how to access the OpenGL and GLUT libraries under Mac OSX.
#
#gcc hello.o -framework GLUT -framework OpenGL
#
#  This is how to access the OpenGL and GLUT libraries under a standard installation.
#
gcc hello.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hello.o
mv a.out hello
#
echo "Normal end of execution."
