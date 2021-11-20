#! /bin/bash
#
cp elliptic_integral.h /$HOME/include
#
gcc -c -I/$HOME/include elliptic_integral.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv elliptic_integral.o ~/libc/elliptic_integral.o
#
echo "Normal end of execution."
