#! /bin/bash
#
gcc -c -Wall fogindex.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fogindex.o -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fogindex.o
mv a.out fogindex
#
echo "Normal end of execution."
