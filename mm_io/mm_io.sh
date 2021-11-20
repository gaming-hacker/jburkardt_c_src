#! /bin/bash
#
cp mm_io.h /$HOME/include
#
gcc -c -Wall mm_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv mm_io.o ~/libc/mm_io.o
#
echo "Normal end of execution."
