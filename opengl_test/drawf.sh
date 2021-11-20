#! /bin/bash
#
gcc -c -Wall drawf.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc drawf.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm drawf.o
mv a.out drawf
#
echo "Normal end of execution."
