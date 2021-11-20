#! /bin/bash
#
cp asa299.h /$HOME/include
#
gcc -c -Wall asa299.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa299.o ~/libc/asa299.o
#
echo "Normal end of execution."
