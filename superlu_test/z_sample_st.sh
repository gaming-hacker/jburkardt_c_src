#! /bin/bash
#
gcc -c -Wall -I/$HOME/include z_sample_st.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc z_sample_st.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm z_sample_st.o
mv a.out z_sample_st
#
./z_sample_st < sample_cst.txt > z_sample_st.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm z_sample_st
#
echo "Normal end of execution."
