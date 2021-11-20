#! /bin/bash
#
cp table_io.h /$HOME/include
#
gcc -c -Wall table_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv table_io.o ~/libc/table_io.o
#
echo "Normal end of execution."
