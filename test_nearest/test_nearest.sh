#! /bin/bash
#
gcc -c -Wall test_nearest.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o test_nearest test_nearest.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm test_nearest.o
#
mv test_nearest $HOME/binc
#
echo "Normal end of execution."
