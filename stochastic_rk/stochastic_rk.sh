#! /bin/bash
#
cp stochastic_rk.h /$HOME/include
#
gcc -c -Wall stochastic_rk.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stochastic_rk.o ~/libc/stochastic_rk.o
#
echo "Normal end of execution."
