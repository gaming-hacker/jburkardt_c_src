#! /bin/bash
#
gcc -c -Wall gcc_intrinsics.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc gcc_intrinsics.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm gcc_intrinsics.o
#
mv a.out $HOME/binc/gcc_intrinsics
#
echo "Normal end of execution."
