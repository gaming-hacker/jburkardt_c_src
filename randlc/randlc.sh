#! /bin/bash
#
cp randlc.h /$HOME/include
#
gcc -c -Wall randlc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv randlc.o ~/libc/randlc.o
#
echo "Normal end of execution."
