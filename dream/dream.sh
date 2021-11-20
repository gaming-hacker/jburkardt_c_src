#! /bin/bash
#
cp dream.h /$HOME/include
cp dream_user.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include dream.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv dream.o ~/libc/dream.o
#
echo "Normal end of execution."
