#! /bin/bash
#
cp fsolve.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fsolve.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fsolve.o ~/libc/fsolve.o
#
echo "Normal end of execution."
