#! /bin/bash
#
gcc -c -Wall -I/$HOME/include c_sample.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc c_sample.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm c_sample.o
mv a.out c_sample
#
./c_sample > c_sample.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c_sample
#
echo "Normal end of execution."
