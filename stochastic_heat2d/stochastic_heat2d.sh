#! /bin/bash
#
cp stochastic_heat2d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include stochastic_heat2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stochastic_heat2d.o ~/libc/stochastic_heat2d.o
#
echo "Normal end of execution."
