#! /bin/bash
#
cp fd1d_bvp.h /$HOME/include
#
gcc -c -Wall fd1d_bvp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fd1d_bvp.o ~/libc/fd1d_bvp.o
#
echo "Normal end of execution."
