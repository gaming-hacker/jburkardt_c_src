#! /bin/bash
#
cp bisection_rc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include bisection_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bisection_rc.o ~/libc/bisection_rc.o
#
echo "Normal end of execution."
