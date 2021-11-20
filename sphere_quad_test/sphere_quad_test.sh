#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sphere_quad_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere_quad_test.o /$HOME/libc/sphere_quad.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_quad_test.o
#
mv a.out sphere_quad_test
./sphere_quad_test > sphere_quad_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_quad_test
#
echo "Normal end of execution."
