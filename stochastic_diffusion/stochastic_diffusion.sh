#! /bin/bash
#
cp stochastic_diffusion.h $HOME/include
#
gcc -c -Wall -I$HOME/include stochastic_diffusion.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stochastic_diffusion.o ~/libc/stochastic_diffusion.o
#
echo "Normal end of execution."
