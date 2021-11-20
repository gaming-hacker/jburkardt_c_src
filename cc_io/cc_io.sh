#! /bin/bash
#
cp cc_io.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cc_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cc_io.o ~/libc/cc_io.o
#
echo "Normal end of execution."
