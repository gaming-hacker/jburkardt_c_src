#! /bin/bash
#
$HOME/binc/sphere_exactness xyz1 design_04 5 > sphere_exactness_test.txt
$HOME/binc/sphere_exactness dtpw lebedev_013 5 >> sphere_exactness_test.txt
#
echo "Normal end of execution."

