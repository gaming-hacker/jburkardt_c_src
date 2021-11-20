#! /bin/bash
#
cp image_components.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include image_components.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv image_components.o ~/libc/image_components.o
#
echo "Normal end of execution."
