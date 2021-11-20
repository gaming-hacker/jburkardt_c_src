#! /bin/bash
#
$HOME/binc/hyperball_volume_monte_carlo 10 123456789 > hyperball_volume_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

