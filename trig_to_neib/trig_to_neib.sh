#! /bin/bash
#
gcc -c -Wall trig_to_neib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc trig_to_neib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm trig_to_neib.o
mv a.out ~/binc/trig_to_neib
#
echo "Normal end of execution."
