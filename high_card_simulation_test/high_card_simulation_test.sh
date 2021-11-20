#! /bin/bash
#
gcc -c -Wall -I/$HOME/include high_card_simulation_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc high_card_simulation_test.o /$HOME/libc/high_card_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm high_card_simulation_test.o
#
mv a.out high_card_simulation_test
./high_card_simulation_test > high_card_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm high_card_simulation_test
#
echo "Normal end of execution."
