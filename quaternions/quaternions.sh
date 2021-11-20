#! /bin/bash
#
cp quaternions.h /$HOME/include
#
gcc -c -I/$HOME/include quaternions.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quaternions.o ~/libc/quaternions.o
#
echo "Normal end of execution."
