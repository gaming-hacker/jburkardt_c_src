#! /bin/bash
#
cp circle_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include circle_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_integrals.o ~/libc/circle_integrals.o
#
echo "Normal end of execution."
