#! /bin/bash
#
cp minpack.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include minpack.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv minpack.o ~/libc/minpack.o
#
echo "Normal end of execution."
