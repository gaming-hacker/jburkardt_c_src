#! /bin/bash
#
gcc -c -Wall -I$HOME/include atbash_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc atbash_test.o -L $HOME/libc -latbash -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm atbash_test.o
#
mv a.out atbash_test
./atbash_test > atbash_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm atbash_test
#
echo "Normal end of execution."
