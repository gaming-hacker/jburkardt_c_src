#! /bin/bash
#
gcc -c -Wall fem_to_triangle.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem_to_triangle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_to_triangle.o
#
chmod ugo+x a.out
mv a.out ~/binc/fem_to_triangle
#
echo "Normal end of execution."
