#! /bin/bash
#
gcc -c -Wall julia_set.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc julia_set.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm julia_set.o
mv a.out $HOME/binc/julia_set
#
echo "Normal end of execution."
