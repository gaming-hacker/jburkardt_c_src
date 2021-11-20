#! /bin/bash
#
echo "sgmga_test" > sgmga_test.txt
echo "" >> sgmga_test.txt
#
echo "  sgmga_aniso_normalize_test" >> sgmga_test.txt
./sgmga_aniso_normalize_test.sh
echo "  sgmga_index_test" >> sgmga_test.txt
./sgmga_index_test.sh
echo "  sgmga_point_test" >> sgmga_test.txt
./sgmga_point_test.sh
echo "  sgmga_product_weight_test" >> sgmga_test.txt
./sgmga_product_weight_test.sh
echo "  sgmga_size_table_test" >> sgmga_test.txt
./sgmga_size_table_test.sh
echo "  sgmga_size_test" >> sgmga_test.txt
./sgmga_size_test.sh
echo "  sgmga_unique_index_test" >> sgmga_test.txt
./sgmga_unique_index_test.sh
echo "  sgmga_vcn_coef_test" >> sgmga_test.txt
./sgmga_vcn_coef_test.sh
echo "  sgmga_vcn_test" >> sgmga_test.txt
./sgmga_vcn_test.sh
echo "  sgmga_weight_test" >> sgmga_test.txt
./sgmga_weight_test.sh
echo "  sgmga_write_test" >> sgmga_test.txt
./sgmga_write_test.sh
#
echo "" >> sgmga_test.txt
echo "Normal end of execution." >> sgmga_test.txt
