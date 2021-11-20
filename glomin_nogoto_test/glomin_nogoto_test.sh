#! /bin/bash
#
gcc -c -Wall -I/$HOME/include glomin_nogoto_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc glomin_nogoto_test.o /$HOME/libc/glomin_nogoto.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm glomin_nogoto_test.o
#
mv a.out glomin_nogoto_test
./glomin_nogoto_test > glomin_nogoto_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm glomin_nogoto_test
#
echo "Normal end of execution."
