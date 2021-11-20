#! /bin/bash
#
cp triangle.h $HOME/include
#
gcc -c -Wall triangle.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm triangle.o
mv a.out ~/binc/triangle
#
echo "Executable installed as ~/binc/triangle"
#
#  Using the TRILIBRARY switch, the file can be compiled as a library.
#
gcc -c -DTRILIBRARY -g triangle.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle.o ~/libc/triangle.o
#
echo "Normal end of execution."
