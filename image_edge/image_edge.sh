#! /bin/bash
#
cp image_edge.h /$HOME/include
#
gcc -c -Wall image_edge.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv image_edge.o ~/libc/image_edge.o
#
echo "Normal end of execution."
