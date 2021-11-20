#! /bin/bash
#
gcc -c -Wall sphere_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sphere_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/sphere_exactness
#
echo "Normal end of execution."
