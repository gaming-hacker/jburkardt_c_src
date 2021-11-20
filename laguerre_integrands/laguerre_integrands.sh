#! /bin/bash
#
cp laguerre_integrands.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include laguerre_integrands.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv laguerre_integrands.o ~/libc/laguerre_integrands.o
#
echo "Normal end of execution."
