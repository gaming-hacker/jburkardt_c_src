#! /bin/bash
#
cp hammersley.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hammersley.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hammersley.o ~/libc/hammersley.o
#
echo "Normal end of execution."
