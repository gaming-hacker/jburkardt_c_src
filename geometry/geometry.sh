#! /bin/bash
#
cp geometry.h /$HOME/include
#
gcc -c -Wall geometry.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv geometry.o ~/libc/geometry.o
#
echo "Normal end of execution."
