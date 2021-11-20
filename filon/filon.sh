#! /bin/bash
#
cp filon.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include filon.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv filon.o ~/libc/filon.o
#
echo "Normal end of execution."
