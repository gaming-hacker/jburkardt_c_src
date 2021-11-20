#! /bin/bash
#
cp spline.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include spline.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv spline.o ~/libc/spline.o
#
echo "Normal end of execution."
