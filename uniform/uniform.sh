#! /bin/bash
#
cp uniform.h /$HOME/include
#
gcc -c -Wall uniform.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv uniform.o ~/libc/uniform.o
#
echo "Normal end of execution."
