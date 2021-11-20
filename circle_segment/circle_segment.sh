#! /bin/bash
#
cp circle_segment.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include circle_segment.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_segment.o ~/libc/circle_segment.o
#
echo "Normal end of execution."
