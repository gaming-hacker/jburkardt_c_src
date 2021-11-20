#! /bin/bash
#
cp triangle_nco_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_nco_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_nco_rule.o ~/libc/triangle_nco_rule.o
#
echo "Normal end of execution."
