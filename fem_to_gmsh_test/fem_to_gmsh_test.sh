#! /bin/bash
#
$HOME/binc/fem_to_gmsh cheby9 > fem_to_gmsh_test.txt
$HOME/binc/fem_to_gmsh mesh3d >> fem_to_gmsh_test.txt
$HOME/binc/fem_to_gmsh rectangle >> fem_to_gmsh_test.txt
#
echo "Normal end of execution."

