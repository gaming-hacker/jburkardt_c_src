#! /bin/bash
#
cp hypercube_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hypercube_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypercube_integrals.o ~/libc/hypercube_integrals.o
#
echo "Normal end of execution."
