#! /bin/bash
#
cp rbf_interp_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include rbf_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rbf_interp_1d.o ~/libc/rbf_interp_1d.o
#
echo "Normal end of execution."
