#! /bin/bash
#
cp pink_noise.h /$HOME/include
#
gcc -c -Wall pink_noise.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pink_noise.o ~/libc/pink_noise.o
#
echo "Normal end of execution."
