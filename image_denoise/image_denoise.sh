#! /bin/bash
#
cp image_denoise.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include image_denoise.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv image_denoise.o ~/libc/image_denoise.o
#
echo "Normal end of execution."
