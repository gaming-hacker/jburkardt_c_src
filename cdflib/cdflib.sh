#! /bin/bash
#
cp cdflib.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cdflib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cdflib.o ~/libc/cdflib.o
#
echo "Normal end of execution."
