#! /bin/bash
#
gcc -c -Wall rot13.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc rot13.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rot13.o
#
chmod ugo+x a.out
mv a.out ~/binc/rot13
#
echo "Normal end of execution."
