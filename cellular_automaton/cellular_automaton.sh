#! /bin/bash
#
gcc -c -Wall cellular_automaton.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cellular_automaton.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm cellular_automaton.o
#
chmod ugo+x a.out
mv a.out ~/binc/cellular_automaton
#
echo "Normal end of execution."
