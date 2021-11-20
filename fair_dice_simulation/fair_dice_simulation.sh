#! /bin/bash
#
gcc -c -Wall fair_dice_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fair_dice_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fair_dice_simulation.o
#
chmod ugo+x a.out
mv a.out ~/binc/fair_dice_simulation
#
echo "Normal end of execution."
