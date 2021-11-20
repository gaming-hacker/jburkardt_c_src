#! /bin/bash
#
gcc -c -Wall *.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o ascii_to_mri *.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm *.o
mv ascii_to_mri ~/binc
#
echo "Normal end of execution."
