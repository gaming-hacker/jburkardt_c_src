#! /bin/bash
#
$HOME/binc/monte_carlo_rule 4 100 123456789 > monte_carlo_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

