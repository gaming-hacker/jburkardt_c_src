#! /bin/bash
#
gcc -c -Wall fd_predator_prey.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd_predator_prey.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd_predator_prey.o
#
chmod ugo+x a.out
mv a.out ~/binc/fd_predator_prey
#
echo "Normal end of execution."
