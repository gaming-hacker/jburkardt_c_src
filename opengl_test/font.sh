#! /bin/bash
#
gcc -c -Wall font.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc font.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm font.o
mv a.out font
#
echo "Normal end of execution."
