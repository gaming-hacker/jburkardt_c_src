#! /bin/bash
#
cp ornstein_uhlenbeck.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ornstein_uhlenbeck.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ornstein_uhlenbeck.o ~/libc/ornstein_uhlenbeck.o
#
echo "Normal end of execution."
