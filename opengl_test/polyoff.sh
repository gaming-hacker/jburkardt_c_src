#! /bin/bash
#
gcc -c -Wall polyoff.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polyoff.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polyoff.o
mv a.out polyoff
#
echo "Normal end of execution."
