#! /bin/bash
#
cp test_interp.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_interp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_interp.o ~/libc/test_interp.o
#
echo "Normal end of execution."
