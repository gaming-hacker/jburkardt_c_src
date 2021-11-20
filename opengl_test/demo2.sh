#! /bin/bash
#
gcc -c -Wall demo2.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc demo2.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm demo2.o
mv a.out demo2
#
echo "Normal end of execution."
