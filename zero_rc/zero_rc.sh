#! /bin/bash
#
cp zero_rc.h /$HOME/include
#
gcc -c -Wall zero_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv zero_rc.o ~/libc/zero_rc.o
#
echo "Normal end of execution."
