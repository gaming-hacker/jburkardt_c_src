#! /bin/bash
#
gcc -c -Wall -I/$HOME/include partial_digest_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o partial_digest_test partial_digest_test.o /$HOME/libc/partial_digest.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm partial_digest_test.o
#
./partial_digest_test > partial_digest_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm partial_digest_test
#
echo "Normal end of execution."
