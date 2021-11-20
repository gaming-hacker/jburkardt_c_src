#! /bin/bash
#
cp kmeans.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include kmeans.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv kmeans.o ~/libc/kmeans.o
#
echo "Normal end of execution."
