#! /bin/bash
#
cp pwl_interp_2d_scattered.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include pwl_interp_2d_scattered.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pwl_interp_2d_scattered.o ~/libc/pwl_interp_2d_scattered.o
#
echo "Normal end of execution."
