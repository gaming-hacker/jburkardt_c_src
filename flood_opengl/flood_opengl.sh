#! /bin/bash
#
gcc -c -Wall flood_opengl.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Mac OSX:
#
#gcc flood_opengl.o -framework OpenGL -framework GLUT
#
#  Ubuntu:
#
gcc flood_opengl.o -lglut -lGLU -lGL -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm flood_opengl.o
mv a.out ~/binc/flood_opengl
#
echo "Normal end of execution."
