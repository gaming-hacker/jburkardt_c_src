#! /bin/bash
#
cp toms322.h /$HOME/include
#
gcc -c -Wall toms322.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms322.o ~/libc/toms322.o
#
echo "Normal end of execution."
