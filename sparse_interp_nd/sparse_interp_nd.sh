#! /bin/bash
#
cp sparse_interp_nd.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sparse_interp_nd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_interp_nd.o ~/libc/sparse_interp_nd.o
#
echo "Normal end of execution."
