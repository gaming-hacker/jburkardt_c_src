#! /bin/bash
#
cp tetrahedron_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tetrahedron_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_integrals.o ~/libc/tetrahedron_integrals.o
#
echo "Normal end of execution."
