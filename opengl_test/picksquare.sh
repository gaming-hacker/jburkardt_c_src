#! /bin/bash
#
gcc -c -Wall picksquare.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc picksquare.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm picksquare.o
mv a.out picksquare
#
echo "Normal end of execution."
