#! /bin/bash
#
cp disk_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include disk_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk_rule.o ~/libc/disk_rule.o
#
echo "Normal end of execution."
