#! /bin/bash
#
cp linpack_d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include linpack_d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv linpack_d.o ~/libc/linpack_d.o
#
echo "Normal end of execution."
