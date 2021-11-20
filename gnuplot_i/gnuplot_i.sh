#! /bin/bash
#
cp gnuplot_i.h /$HOME/include
cp gnuplot_i.hpp /$HOME/include
#
gcc -c -Wall gnuplot_i.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gnuplot_i.o ~/libc/gnuplot_i.o
#
echo "Normal end of execution."
