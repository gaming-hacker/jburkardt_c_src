#! /bin/bash
#
cp c8_complex_lib.h /$HOME/include
#
gcc -c -Wall c8_complex_lib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c8_complex_lib.o ~/libc/c8_complex_lib.o
#
echo "Normal end of execution."
