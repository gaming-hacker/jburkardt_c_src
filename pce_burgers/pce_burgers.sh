#! /bin/bash
#
gcc -c -Wall pce_burgers.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o pce_burgers pce_burgers.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pce_burgers.o
#
mv pce_burgers $HOME/binc
#
echo "Normal end of execution."
