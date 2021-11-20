#! /bin/bash
#
cp predator_prey_ode.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include predator_prey_ode.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv predator_prey_ode.o ~/libc/predator_prey_ode.o
#
echo "Normal end of execution."
