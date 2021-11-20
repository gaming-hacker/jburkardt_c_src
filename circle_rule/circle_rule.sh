#! /bin/bash
#
cp circle_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include circle_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_rule.o ~/libc/circle_rule.o
#
echo "Normal end of execution."
