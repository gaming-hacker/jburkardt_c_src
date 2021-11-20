#! /bin/bash
#
cp cube_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cube_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_integrals.o ~/libc/cube_integrals.o
#
echo "Normal end of execution."
