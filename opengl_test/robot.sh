#! /bin/bash
#
gcc -c -Wall robot.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc robot.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm robot.o
mv a.out robot
#
echo "Normal end of execution."
