#! /bin/bash
#
cp annulus_monte_carlo.h /$HOME/include
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
ar qc libannulus_monte_carlo.a *.o
if [ $? -ne 0 ]; then
  echo "Archive error."
  exit
fi
rm *.o
mv libannulus_monte_carlo.a ~/libc
#
echo "Normal end of execution."
