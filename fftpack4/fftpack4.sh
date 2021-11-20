#! /bin/bash
#
cp fftpack4.h /$HOME/include
cp fftpack4_precision.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fftpack4.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fftpack4.o ~/libc/fftpack4.o
#
echo "Normal end of execution."
