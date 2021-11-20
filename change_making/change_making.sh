#! /bin/bash
#
cp change_making.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include change_making.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv change_making.o ~/libc/change_making.o
#
echo "Normal end of execution."
