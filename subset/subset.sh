#! /bin/bash
#
cp subset.h /$HOME/include
#
gcc -c -Wall subset.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subset.o ~/libc/subset.o
#
echo "Normal end of execution."
