#! /bin/bash
#
cp triangle_symq_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include triangle_symq_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_symq_rule.o ~/libc/triangle_symq_rule.o
#
echo "Normal end of execution."
