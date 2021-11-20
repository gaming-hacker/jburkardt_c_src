#! /bin/bash
#
gcc -c -Wall life_opengl.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  For Mac OSX:
#
#gcc life_opengl.o -framework OpenGL -framework GLUT
#
#  For Ubuntu:
#
gcc life_opengl.o -lglut -lGLU -lGL -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm life_opengl.o
mv a.out ~/binc/life_opengl
#
echo "Normal end of execution."
