#! /bin/bash
#
gcc -c -Wall -I$HOME/include -I/opt/local/include cnoise_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cnoise_test.o /$HOME/libc/cnoise.o -L/opt/local/lib -lm -lgsl -lgslcblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm cnoise_test.o
#
mv a.out cnoise_test
./cnoise_test > cnoise_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cnoise_test
#
echo "Normal end of execution."
