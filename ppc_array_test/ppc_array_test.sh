#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ppc_array_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o ppc_array_test ppc_array_test.o /$HOME/libc/ppc_array.o /$HOME/libc/ppc_xmalloc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ppc_array_test.o
#
./ppc_array_test > ppc_array_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ppc_array_test
#
echo "Normal end of execution."
