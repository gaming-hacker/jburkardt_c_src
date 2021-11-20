#! /bin/bash
#
cp test_interp_2d.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_interp_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_interp_2d.o ~/libc/test_interp_2d.o
#
echo "Normal end of execution."
