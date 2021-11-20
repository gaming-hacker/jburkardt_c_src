#! /bin/bash
#
cp ppc_xmalloc.h /$HOME/include
#
gcc -c -Wall ppc_xmalloc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppc_xmalloc.o ~/libc/ppc_xmalloc.o
#
echo "Normal end of execution."
