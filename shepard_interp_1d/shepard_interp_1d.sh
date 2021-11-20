#! /bin/bash
#
cp shepard_interp_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include shepard_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv shepard_interp_1d.o ~/libc/shepard_interp_1d.o
#
echo "Normal end of execution."
