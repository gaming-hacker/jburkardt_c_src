#! /bin/bash
#
cp tetrahedron_keast_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tetrahedron_keast_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_keast_rule.o ~/libc/tetrahedron_keast_rule.o
#
echo "Normal end of execution."
