#! /bin/bash
#
gcc -c -Wall -I/$HOME/include c_sample_st.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:/usr/local/lib
gcc c_sample_st.o -lsuperlu -lm -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm c_sample_st.o
mv a.out c_sample_st
#
./c_sample_st < sample_cst.txt > c_sample_st.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c_sample_st
#
echo "Normal end of execution."
