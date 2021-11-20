#! /bin/bash
#
gcc -c -Wall -I/$HOME/include d_sample.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc d_sample.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm d_sample.o
mv a.out d_sample
#
./d_sample > d_sample.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm d_sample
#
echo "Normal end of execution."
