#! /bin/bash
#
cp cc_to_st.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cc_to_st.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cc_to_st.o ~/libc/cc_to_st.o
#
echo "Normal end of execution."
