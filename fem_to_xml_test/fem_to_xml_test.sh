#! /bin/bash
#
$HOME/binc/fem_to_xml battery > fem_to_xml_test.txt
$HOME/binc/fem_to_xml channel >> fem_to_xml_test.txt
$HOME/binc/fem_to_xml cheby9 >> fem_to_xml_test.txt
$HOME/binc/fem_to_xml circle >> fem_to_xml_test.txt
$HOME/binc/fem_to_xml rectangle >> fem_to_xml_test.txt
#
echo "Normal end of execution."

