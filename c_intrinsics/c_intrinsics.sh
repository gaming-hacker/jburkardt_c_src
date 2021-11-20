#! /bin/bash
#
gcc -c -Wall c_intrinsics.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc c_intrinsics.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm c_intrinsics.o
#
mv a.out c_intrinsics
./c_intrinsics > c_intrinsics.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c_intrinsics
#
echo "Normal end of execution."
