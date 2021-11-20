#! /bin/bash
#
cp triangle_ncc_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_ncc_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_ncc_rule.o ~/libc/triangle_ncc_rule.o
#
echo "Normal end of execution."
