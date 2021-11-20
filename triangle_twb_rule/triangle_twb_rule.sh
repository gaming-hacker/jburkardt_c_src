#! /bin/bash
#
cp triangle_twb_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_twb_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_twb_rule.o ~/libc/triangle_twb_rule.o
#
echo "Normal end of execution."
