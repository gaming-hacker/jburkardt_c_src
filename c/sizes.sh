#! /bin/bash
#
gcc -c -Wall sizes.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sizes.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sizes.o
#
mv a.out sizes
./sizes > sizes.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sizes
#
echo "Normal end of execution."
