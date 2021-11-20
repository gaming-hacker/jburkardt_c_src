#! /bin/bash
#
cp colored_noise.h /$HOME/include
#
gcc -c -Wall colored_noise.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv colored_noise.o ~/libc/colored_noise.o
#
echo "Normal end of execution."
