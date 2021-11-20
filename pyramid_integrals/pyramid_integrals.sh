#! /bin/bash
#
cp pyramid_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include pyramid_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_integrals.o ~/libc/pyramid_integrals.o
#
echo "Normal end of execution."
