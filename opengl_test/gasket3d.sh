#! /bin/bash
#
gcc -c -Wall gasket3d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc gasket3d.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket3d.o
mv a.out gasket3d
#
echo "Normal end of execution."
