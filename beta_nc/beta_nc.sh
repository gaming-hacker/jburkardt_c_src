#! /bin/bash
#
cp beta_nc.h /$HOME/include
#
gcc -c -Wall beta_nc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv beta_nc.o ~/libc/beta_nc.o
#
echo "Normal end of execution."
