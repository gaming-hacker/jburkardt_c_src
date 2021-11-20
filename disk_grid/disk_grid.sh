#! /bin/bash
#
cp disk_grid.h /$HOME/include
#
gcc -c -Wall disk_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk_grid.o ~/libc/disk_grid.o
#
echo "Normal end of execution."
