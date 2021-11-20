#! /bin/bash
#
cp square_exactness.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include square_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_exactness.o ~/libc/square_exactness.o
#
echo "Normal end of execution."
