#! /bin/bash
#
cp tetrahedron_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tetrahedron_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_felippa_rule.o ~/libc/tetrahedron_felippa_rule.o
#
echo "Normal end of execution."
