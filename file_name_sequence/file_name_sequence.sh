#! /bin/bash
#
cp file_name_sequence.h /$HOME/include
#
gcc -c -Wall file_name_sequence.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv file_name_sequence.o ~/libc/file_name_sequence.o
#
echo "Normal end of execution."
