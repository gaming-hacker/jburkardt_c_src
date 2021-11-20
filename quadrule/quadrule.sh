#! /bin/bash
#
cp quadrule.h /$HOME/include
#
gcc -c -Wall quadrule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrule.o ~/libc/quadrule.o
#
echo "Normal end of execution."
