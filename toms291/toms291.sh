#! /bin/bash
#
cp toms291.h /$HOME/include
#
gcc -c -Wall toms291.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms291.o ~/libc/toms291.o
#
echo "Normal end of execution."
