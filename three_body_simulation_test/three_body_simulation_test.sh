#! /bin/bash
#
$HOME/binc/three_body_simulation > three_body_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

