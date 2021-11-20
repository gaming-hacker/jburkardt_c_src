#! /bin/bash
#
cp sphere_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sphere_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_integrals.o ~/libc/sphere_integrals.o
#
echo "Normal end of execution."
