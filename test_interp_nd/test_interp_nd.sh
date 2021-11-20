#! /bin/bash
#
cp test_interp_nd.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_interp_nd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_interp_nd.o ~/libc/test_interp_nd.o
#
echo "Normal end of execution."
