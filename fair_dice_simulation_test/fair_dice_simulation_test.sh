#! /bin/bash
#
$HOME/binc/fair_dice_simulation 1000 > fair_dice_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
