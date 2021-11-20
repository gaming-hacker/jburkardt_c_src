#! /bin/bash
#
gcc -c -Wall peri1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall pdblas.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o peri1d peri1d.o pdblas.o -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm peri1d.o
rm pdblas.o
#
mv peri1d $HOME/binc/peri1d
#
echo "Normal end of execution."

