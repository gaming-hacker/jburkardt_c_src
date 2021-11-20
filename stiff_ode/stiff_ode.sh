#! /bin/bash
#
cp stiff_ode.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include stiff_ode.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stiff_ode.o ~/libc/stiff_ode.o
#
echo "Normal end of execution."
