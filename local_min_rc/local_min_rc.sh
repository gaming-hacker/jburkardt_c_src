#! /bin/bash
#
cp local_min_rc.h /$HOME/include
#
gcc -c -Wall local_min_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv local_min_rc.o ~/libc/local_min_rc.o
#
echo "Normal end of execution."
