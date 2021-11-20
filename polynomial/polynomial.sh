#! /bin/bash
#
cp polynomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polynomial.o ~/libc/polynomial.o
#
echo "Normal end of execution."
