#! /bin/bash
#
cp rbf_interp_2d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include rbf_interp_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rbf_interp_2d.o ~/libc/rbf_interp_2d.o
#
echo "Normal end of execution."
