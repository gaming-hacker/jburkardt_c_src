#! /bin/bash
#
cp brownian_motion_simulation.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include brownian_motion_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv brownian_motion_simulation.o ~/libc/brownian_motion_simulation.o
#
echo "Normal end of execution."
