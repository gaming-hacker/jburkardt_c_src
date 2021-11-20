#! /bin/bash
#
cp test_partial_digest.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_partial_digest.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_partial_digest.o ~/libc/test_partial_digest.o
#
echo "Normal end of execution."
