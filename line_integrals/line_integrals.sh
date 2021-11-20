#! /bin/bash
#
cp line_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include line_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_integrals.o ~/libc/line_integrals.o
#
echo "Normal end of execution."
