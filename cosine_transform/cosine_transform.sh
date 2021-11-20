#! /bin/bash
#
cp cosine_transform.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cosine_transform.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cosine_transform.o ~/libc/cosine_transform.o
#
echo "Normal end of execution."
