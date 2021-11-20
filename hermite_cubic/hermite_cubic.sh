#! /bin/bash
#
cp hermite_cubic.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hermite_cubic.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_cubic.o ~/libc/hermite_cubic.o
#
echo "Normal end of execution."
