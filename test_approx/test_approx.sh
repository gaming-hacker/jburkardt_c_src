#! /bin/bash
#
cp test_approx.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_approx.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_approx.o ~/libc/test_approx.o
#
echo "Normal end of execution."
