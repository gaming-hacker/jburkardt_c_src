#! /bin/bash
#
cp line_cvt_lloyd.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include line_cvt_lloyd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_cvt_lloyd.o ~/libc/line_cvt_lloyd.o
#
echo "Normal end of execution."
