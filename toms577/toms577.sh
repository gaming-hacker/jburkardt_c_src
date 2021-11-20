#! /bin/bash
#
cp toms577.h /$HOME/include
#
gcc -c -I/$HOME/include toms577.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms577.o ~/libc/toms577.o
#
echo "Normal end of execution."
