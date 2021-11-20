#! /bin/bash
#
cp wtime.h /$HOME/include
#
gcc -c -Wall wtime.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wtime.o ~/libc/wtime.o
#
echo "Normal end of execution."
