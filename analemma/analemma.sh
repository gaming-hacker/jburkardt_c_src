#! /bin/bash
#
cp analemma.h /$HOME/include
#
for FILE in `ls -1 *.c`;
do
  gcc -c -Wall $FILE
  if [ $? -ne 0 ]; then
    echo "Compile error: " $FILE
    exit
  fi
done
#
gcc -o analemma *.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm *.o
mv analemma ~/binc
#
echo "Normal end of execution."
