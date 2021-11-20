#! /bin/bash
#
gcc -c -Wall -I/$HOME/include c_sample_hb.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc c_sample_hb.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm c_sample_hb.o
mv a.out c_sample_hb
#
./c_sample_hb < sample_cua.txt > c_sample_hb.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c_sample_hb
#
echo "Normal end of execution."
