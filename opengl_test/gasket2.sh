#! /bin/bash
#
gcc -c -Wall gasket2.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Mac OSX:
#
#gcc gasket2.o -framework OpenGL -framework GLUT
#
#  Ubuntu:
#
gcc gasket2.o -lglut -lGLU -lGL -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket2.o
mv a.out ~/binc/gasket2
#
echo "Normal end of execution."
