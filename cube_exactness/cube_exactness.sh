#! /bin/bash
#
cp cube_exactness.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cube_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_exactness.o ~/libc/cube_exactness.o
#
echo "Normal end of execution."
