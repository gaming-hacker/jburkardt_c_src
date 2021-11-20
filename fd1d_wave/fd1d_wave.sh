#! /bin/bash
#
cp fd1d_wave.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fd1d_wave.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fd1d_wave.o ~/libc/fd1d_wave.o
#
echo "Normal end of execution."
