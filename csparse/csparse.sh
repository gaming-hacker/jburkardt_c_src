#! /bin/bash
#
cp csparse.h /$HOME/include
#
gcc -c -Wall csparse.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv csparse.o ~/libc/csparse.o
#
echo "Normal end of execution."
