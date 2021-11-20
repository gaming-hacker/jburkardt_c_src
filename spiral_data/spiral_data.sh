#! /bin/bash
#
cp spiral_data.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include spiral_data.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv spiral_data.o ~/libc/spiral_data.o
#
echo "Normal end of execution."
