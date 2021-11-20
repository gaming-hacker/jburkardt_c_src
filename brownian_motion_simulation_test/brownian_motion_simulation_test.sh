#! /bin/bash
#
gcc -c -Wall -I/$HOME/include brownian_motion_simulation_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc brownian_motion_simulation_test.o /$HOME/libc/brownian_motion_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm brownian_motion_simulation_test.o
#
mv a.out brownian_motion_simulation_test
./brownian_motion_simulation_test > brownian_motion_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm brownian_motion_simulation_test
#
echo "Normal end of execution."
