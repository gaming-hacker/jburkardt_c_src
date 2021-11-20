#! /bin/bash
#
cp latin_random.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include latin_random.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latin_random.o ~/libc/latin_random.o
#
echo "Normal end of execution."
