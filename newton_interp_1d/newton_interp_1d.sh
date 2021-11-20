#! /bin/bash
#
cp newton_interp_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include newton_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv newton_interp_1d.o ~/libc/newton_interp_1d.o
#
echo "Normal end of execution."
