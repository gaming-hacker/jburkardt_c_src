#! /bin/bash
#
$HOME/binc/triangulation_node_to_element lake > triangulation_node_to_element_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

