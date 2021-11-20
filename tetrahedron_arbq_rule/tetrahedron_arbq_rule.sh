#! /bin/bash
#
cp tetrahedron_arbq_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include tetrahedron_arbq_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_arbq_rule.o ~/libc/tetrahedron_arbq_rule.o
#
echo "Normal end of execution."
