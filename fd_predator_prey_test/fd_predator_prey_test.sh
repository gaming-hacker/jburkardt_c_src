#! /bin/bash
#
$HOME/binc/fd_predator_prey 100 > fd_predator_prey_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/binc/fd_predator_prey 1000 >> fd_predator_prey_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/binc/fd_predator_prey 10000 >> fd_predator_prey_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
