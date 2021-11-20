#! /bin/bash
#
cp sgmga.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sgmga.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sgmga.o ~/libc/sgmga.o
#
echo "Normal end of execution."
