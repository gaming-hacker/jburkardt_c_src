#! /bin/bash
#
gcc -c -Wall newpaint2.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc newpaint2.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm newpaint2.o
mv a.out newpaint2
#
echo "Normal end of execution."
