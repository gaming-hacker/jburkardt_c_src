#! /bin/bash
#
cp timestamp.h /$HOME/include
#
gcc -c -Wall timestamp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv timestamp.o ~/libc/timestamp.o
#
echo "Normal end of execution."
