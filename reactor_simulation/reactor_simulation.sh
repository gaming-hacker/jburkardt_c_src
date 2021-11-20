#! /bin/bash
#
gcc -c -Wall reactor_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o reactor_simulation reactor_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm reactor_simulation.o
#
mv reactor_simulation $HOME/binc
#
echo "Normal end of execution."
