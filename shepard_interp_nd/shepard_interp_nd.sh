#! /bin/bash
#
cp shepard_interp_nd.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include shepard_interp_nd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv shepard_interp_nd.o ~/libc/shepard_interp_nd.o
#
echo "Normal end of execution."
