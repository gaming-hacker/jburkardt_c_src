#! /bin/bash
#
cp cauchy_principal_value.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cauchy_principal_value.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cauchy_principal_value.o ~/libc/cauchy_principal_value.o
#
echo "Normal end of execution."
