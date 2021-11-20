#! /bin/bash
#
gcc -c -Wall -I/$HOME/include z_sample.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc z_sample.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm z_sample.o
mv a.out z_sample
#
./z_sample > z_sample.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm z_sample
#
echo "Normal end of execution."
