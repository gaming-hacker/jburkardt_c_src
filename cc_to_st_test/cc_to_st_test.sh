#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cc_to_st_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o cc_to_st_test cc_to_st_test.o /$HOME/libc/cc_to_st.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cc_to_st_test.o
#
./cc_to_st_test > cc_to_st_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cc_to_st_test
#
echo "Normal end of execution."
