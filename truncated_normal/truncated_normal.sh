#! /bin/bash
#
cp truncated_normal.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include truncated_normal.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv truncated_normal.o ~/libc/truncated_normal.o
#
echo "Normal end of execution."
