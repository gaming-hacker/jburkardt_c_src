#! /bin/bash
#
cp kronrod.h /$HOME/include
#
gcc -c -Wall kronrod.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv kronrod.o ~/libc/kronrod.o
#
echo "Normal end of execution."
