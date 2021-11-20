#! /bin/bash
#
cp ziggurat.h /$HOME/include
#
gcc -c -Wall ziggurat.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ziggurat.o ~/libc/ziggurat.o
#
echo "Normal end of execution."
