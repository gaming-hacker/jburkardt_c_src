#! /bin/bash
#
$HOME/binc/product_rule < input.txt > product_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

