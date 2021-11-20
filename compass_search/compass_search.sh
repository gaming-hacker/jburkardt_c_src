#! /bin/bash
#
cp compass_search.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include compass_search.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv compass_search.o ~/libc/compass_search.o
#
echo "Normal end of execution."
