#! /bin/bash
#
$HOME/binc/spring_ode > spring_ode_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
