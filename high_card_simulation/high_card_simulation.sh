#! /bin/bash
#
cp high_card_simulation.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include high_card_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv high_card_simulation.o ~/libc/high_card_simulation.o
#
echo "Normal end of execution."
