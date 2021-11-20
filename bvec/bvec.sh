#! /bin/bash
#
cp bvec.h /$HOME/include
#
gcc -c -Wall bvec.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bvec.o ~/libc/bvec.o
#
echo "Normal end of execution."
