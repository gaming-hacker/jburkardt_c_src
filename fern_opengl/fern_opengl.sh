#! /bin/bash
#
gcc -c -Wall fern_opengl.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Here is the load statement for Apple's OS X.
#
#gcc fern_opengl.o -lm -framework GLUT -framework OpenGL
#
#  Here is the load statement for a normal UNIX system!
#
gcc fern_opengl.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fern_opengl.o
mv a.out ~/binc/fern_opengl
#
echo "Normal end of execution."
