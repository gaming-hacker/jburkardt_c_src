#! /bin/bash
#
cp ppc_array_mine.h /$HOME/include
#
gcc -c -Wall ppc_array_mine.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppc_array_mine.o ~/libc/ppc_array_mine.o
#
echo "Normal end of execution."
