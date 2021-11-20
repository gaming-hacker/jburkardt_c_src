#! /bin/bash
#
gcc -c -Wall triangulation_node_to_element.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangulation_node_to_element.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_node_to_element.o
#
chmod ugo+x a.out
mv a.out ~/binc/triangulation_node_to_element
#
echo "Normal end of execution."
