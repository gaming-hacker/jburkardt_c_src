#! /bin/bash
#
gcc -c -Wall -I/$HOME/include predator_prey_ode_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o predator_prey_ode_test predator_prey_ode_test.o /$HOME/libc/predator_prey_ode.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm predator_prey_ode_test.o
#
./predator_prey_ode_test > predator_prey_ode_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm predator_prey_ode_test
#
gnuplot < predator_prey_euler_commands.txt
gnuplot < predator_prey_midpoint_commands.txt
#
echo "Normal end of execution."
