#! /bin/bash
#
cp hilbert_curve.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hilbert_curve.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hilbert_curve.o ~/libc/hilbert_curve.o
#
echo "Normal end of execution."
