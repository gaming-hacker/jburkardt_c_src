#! /bin/bash
#
cp gegenbauer_cc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include gegenbauer_cc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gegenbauer_cc.o ~/libc/gegenbauer_cc.o
#
echo "Normal end of execution."
