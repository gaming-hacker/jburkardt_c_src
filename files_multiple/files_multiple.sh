#! /bin/bash
#
gcc -c -Wall files_multiple.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gfortran files_multiple.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm files_multiple.o
#
mv a.out $HOME/binc/files_multiple
#
echo "Normal end of execution."
