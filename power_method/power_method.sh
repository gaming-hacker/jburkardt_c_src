#! /bin/bash
#
cp power_method.h /$HOME/include
#
gcc -c -Wall power_method.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv power_method.o ~/libc/power_method.o
#
echo "Normal end of execution."
