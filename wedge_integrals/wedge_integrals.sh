#! /bin/bash
#
cp wedge_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include wedge_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_integrals.o ~/libc/wedge_integrals.o
#
echo "Normal end of execution."
