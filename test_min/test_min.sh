#! /bin/bash
#
cp test_min.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_min.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_min.o ~/libc/test_min.o
#
echo "Normal end of execution."
