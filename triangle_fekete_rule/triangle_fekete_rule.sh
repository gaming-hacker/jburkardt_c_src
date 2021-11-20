#! /bin/bash
#
cp triangle_fekete_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_fekete_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_fekete_rule.o ~/libc/triangle_fekete_rule.o
#
echo "Normal end of execution."
