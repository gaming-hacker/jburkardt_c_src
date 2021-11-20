#! /bin/bash
#
gcc -c -Wall robot_angel.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc robot_angel.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm robot_angel.o
mv a.out robot_angel
#
echo "Normal end of execution."
