#! /bin/bash
#
cp backtrack_binary_rc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include backtrack_binary_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv backtrack_binary_rc.o ~/libc/backtrack_binary_rc.o
#
echo "Normal end of execution."
