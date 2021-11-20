#! /bin/bash
#
cp square_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include square_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_integrals.o ~/libc/square_integrals.o
#
echo "Normal end of execution."
