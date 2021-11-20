#! /bin/bash
#
gcc -c -Wall spring_ode.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o spring_ode spring_ode.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm spring_ode.o
#
mv spring_ode $HOME/binc
#
echo "Normal end of execution."
