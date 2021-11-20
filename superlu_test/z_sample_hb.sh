#! /bin/bash
#
gcc -c -Wall -I/$HOME/include z_sample_hb.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc z_sample_hb.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm z_sample_hb.o
mv a.out z_sample_hb
#
./z_sample_hb < sample_cua.txt > z_sample_hb.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm z_sample_hb
#
echo "Normal end of execution."
