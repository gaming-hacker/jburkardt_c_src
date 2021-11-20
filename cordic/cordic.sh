#! /bin/bash
#
cp cordic.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cordic.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cordic.o ~/libc/cordic.o
#
echo "Normal end of execution."
