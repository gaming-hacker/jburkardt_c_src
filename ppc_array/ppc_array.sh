#! /bin/bash
#
cp ppc_array.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ppc_array.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppc_array.o ~/libc/ppc_array.o
#
echo "Normal end of execution."
