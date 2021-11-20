#! /bin/bash
#
cp tetrahedron_ncc_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tetrahedron_ncc_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_ncc_rule.o ~/libc/tetrahedron_ncc_rule.o
#
echo "Normal end of execution."
