#! /bin/bash
#
cp rbf_interp_nd.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include rbf_interp_nd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rbf_interp_nd.o ~/libc/rbf_interp_nd.o
#
echo "Normal end of execution."
