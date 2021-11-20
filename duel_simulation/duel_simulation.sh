#! /bin/bash
#
gcc -c -Wall duel_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc duel_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm duel_simulation.o
#
chmod ugo+x a.out
mv a.out ~/binc/duel_simulation
#
echo "Normal end of execution."
