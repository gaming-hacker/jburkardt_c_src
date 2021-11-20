#! /bin/bash
#
cp local_min.h /$HOME/include
#
gcc -c -Wall local_min.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv local_min.o ~/libc/local_min.o
#
echo "Normal end of execution."
