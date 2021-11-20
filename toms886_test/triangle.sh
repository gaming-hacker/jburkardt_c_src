#! /bin/bash
#
gcc -c -Wall -I$HOME/include triangle.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle.o $HOME/libc/toms886.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm triangle.o
#
mv a.out triangle
./triangle > triangle.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle
#
echo "Normal end of execution."
