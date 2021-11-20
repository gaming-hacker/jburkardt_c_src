#! /bin/bash
#
gcc -c -Wall -I/$HOME/include metis_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc metis_test.o -L /usr/local/lib -lmetis -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm metis_test.o
#
mv a.out metis_test
./metis_test > metis_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm metis_test
#
echo "Normal end of execution."
