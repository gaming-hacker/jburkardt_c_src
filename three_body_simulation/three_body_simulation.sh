#! /bin/bash
#
gcc -c -Wall -I/$HOME/include three_body_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o three_body_simulation three_body_simulation.o /$HOME/libc/rkf45.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm three_body_simulation.o
#
mv three_body_simulation $HOME/binc
#
echo "Normal end of execution."
