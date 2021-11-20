#! /bin/bash
#
cp ode.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include ode.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ode.o ~/libc/ode.o
#
echo "Normal end of execution."
