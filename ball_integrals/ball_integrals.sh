#! /bin/bash
#
cp ball_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ball_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ball_integrals.o ~/libc/ball_integrals.o
#
echo "Normal end of execution."
