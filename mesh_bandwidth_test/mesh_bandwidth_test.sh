#! /bin/bash
#
~/binc/mesh_bandwidth sphere_q4_elements.txt > mesh_bandwidth_test.txt
#
~/binc/mesh_bandwidth twenty_order4_elements.txt >> mesh_bandwidth_test.txt
#
~/binc/mesh_bandwidth ell3_elements.txt >> mesh_bandwidth_test.txt
#
echo "Normal end of execution."
