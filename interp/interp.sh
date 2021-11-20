#! /bin/bash
#
cp interp.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include interp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv interp.o ~/libc/interp.o
#
echo "Normal end of execution."
