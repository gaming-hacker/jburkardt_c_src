#! /bin/bash
#
cp r8s3.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include r8s3.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8s3.o ~/libc/r8s3.o
#
echo "Normal end of execution."
