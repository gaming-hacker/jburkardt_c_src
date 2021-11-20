#! /bin/bash
#
cp van_der_corput.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include van_der_corput.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv van_der_corput.o ~/libc/van_der_corput.o
#
echo "Normal end of execution."
