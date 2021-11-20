#! /bin/bash
#
cp linpack_s.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include linpack_s.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv linpack_s.o ~/libc/linpack_s.o
#
echo "Normal end of execution."
