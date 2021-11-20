#! /bin/bash
#
cp cg_rc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cg_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cg_rc.o ~/libc/cg_rc.o
#
echo "Normal end of execution."
