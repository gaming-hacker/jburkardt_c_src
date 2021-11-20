#! /bin/bash
#
cp shepard_interp_2d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include shepard_interp_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv shepard_interp_2d.o ~/libc/shepard_interp_2d.o
#
echo "Normal end of execution."
