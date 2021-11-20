#! /bin/bash
#
gcc -c -Wall triangulate.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangulate.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulate.o
#
chmod u+x a.out
mv a.out ~/binc/triangulate
#
echo "Normal end of execution."
