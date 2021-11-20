#! /bin/bash
#
cp halton.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include halton.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv halton.o ~/libc/halton.o
#
echo "Normal end of execution."
