#! /bin/bash
#
cp pwl_interp_2d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include pwl_interp_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pwl_interp_2d.o ~/libc/pwl_interp_2d.o
#
echo "Normal end of execution."
