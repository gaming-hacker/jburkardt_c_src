#! /bin/bash
#
cp jacobi.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include jacobi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv jacobi.o ~/libc/jacobi.o
#
echo "Normal end of execution."
