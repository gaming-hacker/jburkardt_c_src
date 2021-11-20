#! /bin/bash
#
cp glomin_nogoto.h /$HOME/include
#
gcc -c -Wall glomin_nogoto.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv glomin_nogoto.o ~/libc/glomin_nogoto.o
#
echo "Normal end of execution."
