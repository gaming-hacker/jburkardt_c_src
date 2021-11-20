#! /bin/bash
#
gcc -c -Wall feedback.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc feedback.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm feedback.o
mv a.out feedback
#
echo "Normal end of execution."
