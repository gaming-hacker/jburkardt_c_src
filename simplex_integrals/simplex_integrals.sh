#! /bin/bash
#
cp simplex_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include simplex_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_integrals.o ~/libc/simplex_integrals.o
#
echo "Normal end of execution."
