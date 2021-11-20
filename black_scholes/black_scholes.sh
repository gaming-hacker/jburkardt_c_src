#! /bin/bash
#
cp black_scholes.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include black_scholes.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv black_scholes.o ~/libc/black_scholes.o
#
echo "Normal end of execution."
