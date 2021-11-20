#! /bin/bash
#
cp c4lib.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include c4lib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c4lib.o ~/libc/c4lib.o
#
echo "Normal end of execution."
