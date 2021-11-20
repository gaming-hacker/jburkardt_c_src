#! /bin/bash
#
gcc -c -Wall poisson.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o poisson poisson.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm poisson.o
#
mv poisson $HOME/binc
#
echo "Normal end of execution."
