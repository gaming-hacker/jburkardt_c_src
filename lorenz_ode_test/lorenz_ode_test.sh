#! /bin/bash
#
$HOME/binc/lorenz_ode > lorenz_ode_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

