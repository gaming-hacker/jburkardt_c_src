#! /bin/bash
#
cp log_normal_truncated_ab.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include log_normal_truncated_ab.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv log_normal_truncated_ab.o ~/libc/log_normal_truncated_ab.o
#
echo "Normal end of execution."
