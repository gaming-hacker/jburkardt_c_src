#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fsolve_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fsolve_test.o /$HOME/libc/fsolve.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fsolve_test.o
#
mv a.out fsolve_test
./fsolve_test > fsolve_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fsolve_test
#
echo "Normal end of execution."
