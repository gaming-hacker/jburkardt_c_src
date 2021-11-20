#! /bin/bash
#
cp hermite_integrands.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hermite_integrands.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_integrands.o ~/libc/hermite_integrands.o
#
echo "Normal end of execution."
