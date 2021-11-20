#! /bin/bash
#
$HOME/binc/duel_simulation 1000 0.1 0.15 > duel_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
