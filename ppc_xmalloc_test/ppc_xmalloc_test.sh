#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ppc_xmalloc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ppc_xmalloc_test.o /$HOME/libc/ppc_xmalloc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ppc_xmalloc_test.o
#
mv a.out ppc_xmalloc_test
./ppc_xmalloc_test > ppc_xmalloc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ppc_xmalloc_test
#
echo "Normal end of execution."
