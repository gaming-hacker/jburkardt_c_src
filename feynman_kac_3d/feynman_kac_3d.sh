#! /bin/bash
#
gcc -c -Wall feynman_kac_3d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc feynman_kac_3d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm feynman_kac_3d.o
mv a.out $HOME/binc/feynman_kac_3d
#
echo "Normal end of execution."
