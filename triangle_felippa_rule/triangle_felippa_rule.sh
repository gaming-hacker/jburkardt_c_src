#! /bin/bash
#
cp triangle_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_felippa_rule.o ~/libc/triangle_felippa_rule.o
#
echo "Normal end of execution."
