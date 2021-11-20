#! /bin/bash
#
cp disk01_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include disk01_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_rule.o ~/libc/disk01_rule.o
#
echo "Normal end of execution."
