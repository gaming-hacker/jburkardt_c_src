#! /bin/bash
#
$HOME/binc/fd1d_advection_diffusion_steady > fd1d_advection_diffusion_steady_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
