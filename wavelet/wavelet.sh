#! /bin/bash
#
cp wavelet.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include wavelet.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wavelet.o ~/libc/wavelet.o
#
echo "Normal end of execution."
