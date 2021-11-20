#! /bin/bash
#
cp nearest_interp_1d.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include nearest_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv nearest_interp_1d.o ~/libc/nearest_interp_1d.o
#
echo "Normal end of execution."
