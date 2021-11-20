#! /bin/bash
#
$HOME/binc/clenshaw_curtis_rule 5 -1 +1 cc_o5 > clenshaw_curtis_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
