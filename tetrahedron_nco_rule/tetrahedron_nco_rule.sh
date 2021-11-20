#! /bin/bash
#
cp tetrahedron_nco_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tetrahedron_nco_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_nco_rule.o ~/libc/tetrahedron_nco_rule.o
#
echo "Normal end of execution."
