#! /bin/bash
#
gcc -c -Wall gasket_points.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#gcc gasket_points.o -lm -framework GLUT -framework OpenGL
gcc gasket_points.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket_points.o
mv a.out ~/binc/gasket_points
#
echo "Normal end of execution."
