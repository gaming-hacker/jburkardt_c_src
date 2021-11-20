#! /bin/bash
#
cp test_opt_con.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_opt_con.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_opt_con.o ~/libc/test_opt_con.o
#
echo "Normal end of execution."
