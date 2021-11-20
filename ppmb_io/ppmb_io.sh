#! /bin/bash
#
cp ppmb_io.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include ppmb_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppmb_io.o ~/libc/ppmb_io.o
#
echo "Normal end of execution."
