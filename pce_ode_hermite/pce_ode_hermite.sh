#! /bin/bash
#
cp pce_ode_hermite.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include pce_ode_hermite.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pce_ode_hermite.o ~/libc/pce_ode_hermite.o
#
echo "Normal end of execution."
