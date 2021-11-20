#! /bin/bash
#
cp set_theory.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include set_theory.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv set_theory.o ~/libc/set_theory.o
#
echo "Normal end of execution."
