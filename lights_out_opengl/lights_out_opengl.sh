#! /bin/bash
#
gcc -c -Wall lights_out_opengl.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Mac OSX:
#
#gcc lights_out_opengl.o -framework OpenGL -framework GLUT
#
#  Ubuntu
#
gcc lights_out_opengl.o -lglut -lGLU -lGL -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lights_out_opengl.o
mv a.out ~/binc/lights_out_opengl
#
echo "Normal end of execution."
