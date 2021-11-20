# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "subset.h"

int main ( );

void asm_enum_test ( );
void asm_triangle_test ( );
void bell_test ( );
void catalan_test ( );
void catalan_row_next_test ( );
void cfrac_to_rat_test ( );
void cfrac_to_rfrac_test ( );
void change_greedy_test ( );
void change_next_test ( );
void chinese_check_test ( );
void chinese_to_i4_test ( );
void comb_next_test ( );
void comb_row_next_test ( );
void comb_unrank_test ( );
void comp_next_test ( );
void comp_enum_test ( );
void comp_next_grlex_test ( );
void comp_random_test ( );
void comp_random_grlex_test ( );
void comp_rank_grlex_test ( );
void comp_to_ksub_test ( );
void comp_unrank_grlex_test ( );
void compnz_next_test ( );
void compnz_random_test ( );
void compnz_to_ksub_test ( );
void congruence_test ( );
void count_pose_random_test ( );
void debruijn_test ( );
void dec_add_test ( );
void dec_div_test ( );
void dec_mul_test ( );
void dec_round_test ( );
void dec_to_r8_test ( );
void dec_to_rat_test ( );
void dec_to_s_test ( );
void dec_width_test ( );
void decmat_det_test ( );
void decmat_print_test ( );
void derange_enum_test ( );
void derange_enum2_test ( );
void derange_enum3_test ( );
void derange0_back_next_test ( );
void derange0_check_test ( );
void derange0_weed_next_test ( );
void digraph_arc_euler_test ( );
void digraph_arc_print_test ( );
void diophantine_test ( );
void diophantine_solution_minimize_test ( );
void dvec_add_test ( );
void dvec_complementx_test ( );
void dvec_mul_test ( );
void dvec_print_test ( );
void dvec_sub_test ( );
void dvec_to_i4_test ( );
void equiv_next_test ( );
void equiv_next2_test ( );
void equiv_print_test ( );
void equiv_print2_test ( );
void equiv_random_test ( );
void euler_row_test ( );
void frobenius_number_order2_test ( );
void gray_next_test ( );
void gray_rank_test ( );
void gray_rank2_test ( );
void gray_unrank_test ( );
void gray_unrank2_test ( );
void i4_bclr_test ( );
void i4_bset_test ( );
void i4_btest_test ( );
void i4_choose_test ( );
void i4_factor_test ( );
void i4_fall_test ( );
void i4_gcd_test ( );
void i4_huge_test ( );
void i4_log_10_test ( );
void i4_modp_test ( );
void i4_moebius_test ( );
void i4_partition_conj_test ( );
void i4_partition_count_test ( );
void i4_partition_count2_test ( );
void i4_partition_next_test ( );
void i4_partition_next2_test ( );
void i4_partition_print_test ( );
void i4_partition_random_test ( );
void i4_partitions_next_test ( );
void i4_rise_test ( );
void i4_sqrt_test ( );
void i4_sqrt_cf_test ( );
void i4_to_chinese_test ( );
void i4_to_dvec_test ( );
void i4_to_i4poly_test ( );
void i4_to_van_der_corput_test ( );
void i4mat_01_rowcolsum_test ( );
void i4mat_u1_inverse_test ( );
void i4mat_perm0_test ( );
void i4mat_2perm0_test ( );
void i4poly_test ( );
void i4poly_add_test ( );
void i4poly_cyclo_test ( );
void i4poly_degree_test ( );
void i4poly_dif_test ( );
void i4poly_div_test ( );
void i4poly_mul_test ( );
void i4poly_print_test ( );
void i4poly_to_i4_test ( );
void i4vec_backtrack_test ( );
void i4vec_descends_test ( );
void i4vec_frac_test ( );
void i4vec_index_test ( );
void i4vec_maxloc_last_test ( );
void i4vec_pairwise_prime_test ( );
void i4vec_reverse_test ( );
void i4vec_sort_bubble_a_test ( );
void i4vec_sort_heap_index_d_test ( );
void i4vec_transpose_print_test ( );
void i4vec_uniform_ab_test ( );
void index_box_next_2d_test ( );
void index_box_next_3d_test ( );
void index_box2_next_2d_test ( );
void index_box2_next_3d_test ( );
void index_next0_test ( );
void index_next1_test ( );
void index_next2_test ( );
void index_rank0_test ( );
void index_rank1_test ( );
void index_rank2_test ( );
void index_unrank0_test ( );
void index_unrank1_test ( );
void index_unrank2_test ( );
void inverse_mod_n_test ( );
void inversion_to_perm0_test ( );
void involute_enum_test ( );
void jfrac_to_rfrac_test ( );
void josephus_test ( );
void ksub_next_test ( );
void ksub_next2_test ( );
void ksub_next3_test ( );
void ksub_next4_test ( );
void ksub_random_test ( );
void ksub_random2_test ( );
void ksub_random3_test ( );
void ksub_random4_test ( );
void ksub_random5_test ( );
void ksub_rank_test ( );
void ksub_to_comp_test ( );
void ksub_to_compnz_test ( );
void ksub_unrank_test ( );
void l4vec_next_test ( );
void matrix_product_opt_test ( );
void moebius_matrix_test ( );
void monomial_count_test ( );
void monomial_counts_test ( );
void morse_thue_test ( );
void multinomial_coef1_test ( );
void multinomial_coef2_test ( );
void multiperm_enum_test ( );
void multiperm_next_test ( );
void nim_sum_test ( );
void padovan_test ( );
void pell_basic_test ( );
void pell_next_test ( );
void pent_enum_test ( );
void perm_ascend_test ( );
void perm_fixed_enum_test ( );
void perm0_break_count_test ( );
void perm0_check_test ( );
void perm0_cycle_test ( );
void perm0_distance_test ( );
void perm0_free_test ( );
void perm0_inverse_test ( );
void perm0_inverse2_test ( );
void perm0_inverse3_new_test ( );
void perm0_lex_next_test ( );
void perm0_mul_test ( );
void perm0_next_test ( );
void perm0_next2_test ( );
void perm0_next3_test ( );
void perm0_print_test ( );
void perm0_random_test ( );
void perm0_random2_test ( );
void perm0_rank_test ( );
void perm0_sign_test ( );
void perm0_to_equiv_test ( );
void perm0_to_inversion_test ( );
void perm0_to_ytb_test ( );
void perm0_unrank_test ( );
void perm1_check_test ( );
void perm1_canon_to_cycle_test ( );
void perm1_cycle_to_canon_test ( );
void perm1_cycle_to_index_test ( );
void perm1_index_to_cycle_test ( );
void perm1_print_test ( );
void perrin_test ( );
void pord_check_test ( );
void power_mod_test ( );
void power_series1_test ( );
void power_series2_test ( );
void power_series3_test ( );
void power_series4_test ( );
void prime_test ( );
void pythag_triple_next_test ( );
void r8_agm_test ( );
void r8_choose_test ( );
void r8_epsilon_test ( );
void r8_fall_test ( );
void r8_rise_test ( );
void r8_to_cfrac_test ( );
void r8_to_dec_test ( );
void r8_to_rat_test ( );
void r8mat_det_test ( );
void r8mat_perm0_test ( );
void r8mat_2perm0_test ( );
void r8mat_permanent_test ( );
void r8poly_test ( );
void r8poly_f2p_test ( );
void r8poly_fval_test ( );
void r8poly_n2p_test ( );
void r8poly_nval_test ( );
void r8poly_nx_test ( );
void r8poly_p2f_test ( );
void r8poly_p2n_test ( );
void r8poly_p2t_test ( );
void r8poly_power_test ( );
void r8poly_print_test ( );
void r8poly_pval_test ( );
void r8poly_t2p_test ( );
void r8vec_backtrack_test ( );
void r8vec_frac_test ( );
void r8vec_mirror_next_test ( );
void rat_add_test ( );
void rat_div_test ( );
void rat_farey_test ( );
void rat_farey2_test ( );
void rat_mul_test ( );
void rat_normalize_test ( );
void rat_to_cfrac_test ( );
void rat_to_dec_test ( );
void rat_to_r8_test ( );
void rat_to_s_test ( );
void rat_width_test ( );
void rat_sum_formula_test ( );
void ratmat_det_test ( );
void ratmat_print_test ( );
void regro_next_test ( );
void rfrac_to_cfrac_test ( );
void rfrac_to_jfrac_test ( );
void schroeder_test ( );
void sort_heap_external_test ( );
void subset_by_size_next_test ( );
void subset_lex_next_test ( );
void subset_gray_next_test ( );
void subset_random_test ( );
void subset_gray_rank_test ( );
void subset_gray_unrank_test ( );
void subcomp_next_test ( );
void subcompnz_next_test ( );
void subcompnz2_next_test ( );
void subtriangle_next_test ( );
void thue_binary_next_test ( );
void thue_ternary_next_test ( );
void triang_test ( );
void tuple_next_test ( );
void tuple_next_fast_test ( );
void tuple_next_ge_test ( );
void tuple_next2_test ( );
void ubvec_add_test ( );
void ubvec_print_test ( );
void ubvec_to_ui4_test ( );
void ubvec_xor_test ( );
void ui4_to_ubvec_test ( );
void vec_colex_next_test ( );
void vec_colex_next2_test ( );
void vec_colex_next3_test ( );
void vec_gray_next_test ( );
void vec_gray_rank_test ( );
void vec_gray_unrank_test ( );
void vec_lex_next_test ( );
void vec_random_test ( );
void vector_constrained_next_test ( );
void vector_constrained_next2_test ( );
void vector_constrained_next3_test ( );
void vector_constrained_next4_test ( );
void vector_constrained_next5_test ( );
void vector_constrained_next6_test ( );
void vector_constrained_next7_test ( );
void vector_next_test ( );
void ytb_enum_test ( );
void ytb_next_test ( );
void ytb_random_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for subset_test.

  Discussion:

    SUBSET_TEST tests SUBSET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 November 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SUBSET_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SUBSET library.\n" );

  asm_enum_test ( );
  asm_triangle_test ( );
  bell_test ( );
  catalan_test ( );
  catalan_row_next_test ( );
  cfrac_to_rat_test ( );
  cfrac_to_rfrac_test ( );
  change_greedy_test ( );
  change_next_test ( );
  chinese_check_test ( );
  chinese_to_i4_test ( );
  comb_next_test ( );
  comb_row_next_test ( );
  comb_unrank_test ( );
  comp_enum_test ( );
  comp_next_test ( );
  comp_next_grlex_test ( );
  comp_random_test ( );
  comp_random_grlex_test ( );
  comp_rank_grlex_test ( );
  comp_to_ksub_test ( );
  comp_unrank_grlex_test ( );
  compnz_next_test ( );
  compnz_random_test ( );
  compnz_to_ksub_test ( );
  congruence_test ( );
  count_pose_random_test ( );
  debruijn_test ( );
  dec_add_test ( );
  dec_div_test ( );
  dec_mul_test ( );
  dec_round_test ( );
  dec_to_r8_test ( );
  dec_to_rat_test ( );
  dec_to_s_test ( );
  dec_width_test ( );
  decmat_det_test ( );
  decmat_print_test ( );
  derange_enum_test ( );
  derange_enum2_test ( );
  derange_enum3_test ( );
  derange0_back_next_test ( );
  derange0_check_test ( );
  derange0_weed_next_test ( );
  digraph_arc_euler_test ( );
  digraph_arc_print_test ( );
  diophantine_test ( );
  diophantine_solution_minimize_test ( );
  dvec_add_test ( );
  dvec_complementx_test ( );
  dvec_mul_test ( );
  dvec_print_test ( );
  dvec_sub_test ( );
  dvec_to_i4_test ( );
  equiv_next_test ( );
  equiv_next2_test ( );
  equiv_print_test ( );
  equiv_print2_test ( );
  equiv_random_test ( );
  euler_row_test ( );
  frobenius_number_order2_test ( );
  gray_next_test ( );
  gray_rank_test ( );
  gray_rank2_test ( );
  gray_unrank_test ( );
  gray_unrank2_test ( );
  i4_bclr_test ( );
  i4_bset_test ( );
  i4_btest_test ( );
  i4_choose_test ( );
  i4_factor_test ( );
  i4_fall_test ( );
  i4_gcd_test ( );
  i4_huge_test ( );
  i4_log_10_test ( );
  i4_modp_test ( );
  i4_moebius_test ( );
  i4_partition_conj_test ( );
  i4_partition_count_test ( );
  i4_partition_count2_test ( );
  i4_partition_next_test ( );
  i4_partition_next2_test ( );
  i4_partition_print_test ( );
  i4_partition_random_test ( );
  i4_partitions_next_test ( );
  i4_rise_test ( );
  i4_sqrt_test ( );
  i4_sqrt_cf_test ( );
  i4_to_chinese_test ( );
  i4_to_dvec_test ( );
  i4_to_i4poly_test ( );
  i4_to_van_der_corput_test ( );
  i4mat_01_rowcolsum_test ( );
  i4mat_u1_inverse_test ( );
  i4mat_perm0_test ( );
  i4mat_2perm0_test ( );
  i4poly_test ( );
  i4poly_add_test ( );
  i4poly_cyclo_test ( );
  i4poly_degree_test ( );
  i4poly_dif_test ( );
  i4poly_div_test ( );
  i4poly_mul_test ( );
  i4poly_print_test ( );
  i4poly_to_i4_test ( );
  i4vec_backtrack_test ( );
  i4vec_descends_test ( );
  i4vec_frac_test ( );
  i4vec_index_test ( );
  i4vec_maxloc_last_test ( );
  i4vec_pairwise_prime_test ( );
  i4vec_reverse_test ( );
  i4vec_sort_bubble_a_test ( );
  i4vec_sort_heap_index_d_test ( );
  i4vec_transpose_print_test ( );
  i4vec_uniform_ab_test ( );
  index_box_next_2d_test ( );
  index_box_next_3d_test ( );
  index_box2_next_2d_test ( );
  index_box2_next_3d_test ( );
  index_next0_test ( );
  index_next1_test ( );
  index_next2_test ( );
  index_rank0_test ( );
  index_rank1_test ( );
  index_rank2_test ( );
  index_unrank0_test ( );
  index_unrank1_test ( );
  index_unrank2_test ( );
  inverse_mod_n_test ( );
  inversion_to_perm0_test ( );
  involute_enum_test ( );
  jfrac_to_rfrac_test ( );
  josephus_test ( );
  ksub_next_test ( );
  ksub_next2_test ( );
  ksub_next3_test ( );
  ksub_next4_test ( );
  ksub_random_test ( );
  ksub_random2_test ( );
  ksub_random3_test ( );
  ksub_random4_test ( );
  ksub_random5_test ( );
  ksub_rank_test ( );
  ksub_to_comp_test ( );
  ksub_to_compnz_test ( );
  ksub_unrank_test ( );
  l4vec_next_test ( );
  matrix_product_opt_test ( );
  moebius_matrix_test ( );
  monomial_count_test ( );
  monomial_counts_test ( );
  morse_thue_test ( );
  multinomial_coef1_test ( );
  multinomial_coef1_test ( );
  multiperm_enum_test ( );
  multiperm_next_test ( );
  nim_sum_test ( );
  padovan_test ( );
  pell_basic_test ( );
  pell_next_test ( );
  pent_enum_test ( );
  perm_ascend_test ( );
  perm_fixed_enum_test ( );
  perm0_break_count_test ( );
  perm0_check_test ( );
  perm0_cycle_test ( );
  perm0_distance_test ( );
  perm0_free_test ( );
  perm0_inverse_test ( );
  perm0_inverse2_test ( );
  perm0_inverse3_new_test ( );
  perm0_lex_next_test ( );
  perm0_mul_test ( );
  perm0_next_test ( );
  perm0_next2_test ( );
  perm0_next3_test ( );
  perm0_print_test ( );
  perm0_random_test ( );
  perm0_random2_test ( );
  perm0_rank_test ( );
  perm0_sign_test ( );
  perm0_to_equiv_test ( );
  perm0_to_inversion_test ( );
  perm0_to_ytb_test ( );
  perm0_unrank_test ( );
  perm1_canon_to_cycle_test ( );
  perm1_check_test ( );
  perm1_cycle_to_canon_test ( );
  perm1_cycle_to_index_test ( );
  perm1_index_to_cycle_test ( );
  perm1_print_test ( );
  perrin_test ( );
  pord_check_test ( );
  power_mod_test ( );
  power_series1_test ( );
  power_series2_test ( );
  power_series3_test ( );
  power_series4_test ( );
  prime_test ( );
  pythag_triple_next_test ( );
  r8_agm_test ( );
  r8_choose_test ( );
  r8_epsilon_test ( );
  r8_fall_test ( );
  r8_rise_test ( );
  r8_to_cfrac_test ( );
  r8_to_dec_test ( );
  r8_to_rat_test ( );
  r8mat_det_test ( );
  r8mat_perm0_test ( );
  r8mat_2perm0_test ( );
  r8mat_permanent_test ( );
  r8poly_test ( );
  r8poly_f2p_test ( );
  r8poly_fval_test ( );
  r8poly_n2p_test ( );
  r8poly_nval_test ( );
  r8poly_nx_test ( );
  r8poly_p2f_test ( );
  r8poly_p2n_test ( );
  r8poly_p2t_test ( );
  r8poly_print_test ( );
  r8poly_pval_test ( );
  r8poly_t2p_test ( );
  r8vec_backtrack_test ( );
  r8vec_frac_test ( );
  r8vec_mirror_next_test ( );
  rat_add_test ( );
  rat_div_test ( );
  rat_farey_test ( );
  rat_farey2_test ( );
  rat_mul_test ( );
  rat_normalize_test ( );
  rat_to_cfrac_test ( );
  rat_to_dec_test ( );
  rat_to_r8_test ( );
  rat_to_s_test ( );
  rat_width_test ( );
  rat_sum_formula_test ( );
  ratmat_det_test ( );
  ratmat_print_test ( );
  regro_next_test ( );
  rfrac_to_cfrac_test ( );
  rfrac_to_jfrac_test ( );
  schroeder_test ( );
  sort_heap_external_test ( );
  subset_by_size_next_test ( );
  subset_lex_next_test ( );
  subset_gray_next_test ( );
  subset_random_test ( );
  subset_gray_rank_test ( );
  subset_gray_unrank_test ( );
  subcomp_next_test ( );
  subcompnz_next_test ( );
  subcompnz2_next_test ( );
  subtriangle_next_test ( );
  thue_binary_next_test ( );
  thue_ternary_next_test ( );
  triang_test ( );
  tuple_next_test ( );
  tuple_next_fast_test ( );
  tuple_next_ge_test ( );
  tuple_next2_test ( );
  ubvec_add_test ( );
  ubvec_print_test ( );
  ubvec_to_ui4_test ( );
  ubvec_xor_test ( );
  ui4_to_ubvec_test ( );
  vec_colex_next_test ( );
  vec_colex_next2_test ( );
  vec_colex_next3_test ( );
  vec_gray_next_test ( );
  vec_gray_rank_test ( );
  vec_gray_unrank_test ( );
  vec_lex_next_test ( );
  vec_random_test ( );
  vector_constrained_next_test ( );
  vector_constrained_next2_test ( );
  vector_constrained_next3_test ( );
  vector_constrained_next4_test ( );
  vector_constrained_next5_test ( );
  vector_constrained_next6_test ( );
  vector_constrained_next7_test ( );
  vector_next_test ( );
  ytb_enum_test ( );
  ytb_next_test ( );
  ytb_random_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SUBSET_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void asm_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    ASM_ENUM_TEST tests ASM_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 February 2007

  Author:

    John Burkardt
*/
{
  int n;

  printf ( "\n" );
  printf ( "ASM_ENUM_TEST\n" );
  printf ( "  ASM_ENUM returns the number of alternating sign\n" );
  printf ( "  matrices of a given order.\n" );
  printf ( "\n" );

  for ( n = 0; n <= 7; n++ )
  {
    printf ( "  %4d  %6d\n", n, asm_enum ( n ) );
  }

  return;
}
/******************************************************************************/

void asm_triangle_test ( )

/******************************************************************************/
/*
  Purpose:

    ASM_TRIANGLE_TEST tests ASM_TRIANGLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 July 2010

  Author:

    John Burkardt
*/
{
# define N_MAX 7

  int a[N_MAX+1];
  int i;
  int n;

  printf ( "\n" );
  printf ( "ASM_TRIANGLE_TEST\n" );
  printf ( "  ASM_TRIANGLE returns a row of the alternating sign\n" );
  printf ( "  matrix triangle.\n" );
  printf ( "\n" );

  for ( n = 0; n <= N_MAX; n++ )
  {
    asm_triangle ( n, a );
    printf ( "%4d  ", n );
    for ( i = 0; i <= n; i++ )
    {
      printf ( "%8d  ", a[i] );
    }
    printf ( "\n" );
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void bell_test ( )

/******************************************************************************/
/*
  Purpose:

    BELL_TEST tests BELL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 August 2010

  Author:

    John Burkardt
*/
{
  int c;
  int *c2;
  int n;
  int n_data;

  printf ( "\n" );
  printf ( "BELL_TEST\n" );
  printf ( "  BELL computes Bell numbers.\n" );
  printf ( "\n" );
  printf ( "  N  exact C(I)  computed C(I)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bell_values ( &n_data, &n, &c );

    if ( n_data == 0 )
    {
      break;
    }

    c2 = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );

    bell ( n, c2 );

    printf ( "  %4d  %8d  %8d\n", n, c, c2[n] );

    free ( c2 );
  }

  return;
}
/******************************************************************************/

void catalan_test ( )

/******************************************************************************/
/*
  Purpose:

    CATALAN_TEST tests CATALAN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 October 2010

  Author:

    John Burkardt
*/
{
  int c;
  int *c2;
  int n;
  int n_data;

  printf ( "\n" );
  printf ( "CATALAN_TEST\n" );
  printf ( "  CATALAN computes Catalan numbers.\n" );
  printf ( "\n" );
  printf ( "  N  exact C(I)  computed C(I)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    catalan_values ( &n_data, &n, &c );

    if ( n_data == 0 )
    {
      break;
    }

    c2 = ( int * ) malloc ( ( n + 1 ) * sizeof ( int ) );

    catalan ( n, c2 );

    printf ( "  %4d  %8d  %8d\n", n, c, c2[n] );

    free ( c2 );
  }

  return;
}
/******************************************************************************/

void catalan_row_next_test ( )

/******************************************************************************/
/*
  Purpose:

    CATALAN_ROW_NEXT_TEST tests CATALAN_ROW_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 October 2006

  Author:

    John Burkardt
*/
{
# define N_MAX 10

  int c[N_MAX+1];
  int i;
  int n;
  int next;

  printf ( "\n" );
  printf ( "CATALAN_ROW_NEXT_TEST\n" );
  printf ( "  CATALAN_ROW_NEXT computes a row of the Catalan triangle.\n" );
  printf ( "\n" );
  printf ( "  First, compute row 7:\n" );
  printf ( "\n" );

  next = 0;
  n = 7;
  catalan_row_next ( next, n, c );

  printf ( "%4d", n );
  for ( i = 0; i <= n; i++ )
  {
    printf ( "  %8d", c[i] );
  }
  printf ( "\n" );

  printf ( "\n" );
  printf ( "  Now compute rows consecutively, one at a time:\n" );
  printf ( "\n" );

  next = 0;

  for ( n = 0; n <= N_MAX; n++ )
  {
    catalan_row_next ( next, n, c );
    next = 1;

    printf ( "%4d", n );
    for ( i = 0; i <= n; i++ )
    {
      printf ( "  %8d", c[i] );
    }
    printf ( "\n" );
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void cfrac_to_rat_test ( )

/******************************************************************************/
/*
  Purpose:

    CFRAC_TO_RAT_TEST tests CFRAC_TO_RAT.

  Discussion:

    Compute the continued fraction form of 4096/15625.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 November 2013

  Author:

    John Burkardt
*/
{
# define M 10

  int a[M];
  int bot = 15625;
  int error;
  int i;
  int n;
  int p[M];
  int q[M];
  int top = 4096;

  printf ( "\n" );
  printf ( "CFRAC_TO_RAT_TEST\n" );
  printf ( "  CFRAC_TO_RAT continued fraction => fraction.\n" );
  printf ( "\n" );
  printf ( "  Regular fraction is %d/%d\n", top, bot );

  rat_to_cfrac ( top, bot, M, &n, a, &error );
 
  i4vec1_print ( n, a, "  Continued fraction coefficients:" );

  cfrac_to_rat ( n, a, p, q );
 
  printf ( "\n" );
  printf ( "  The continued fraction convergents.\n" );
  printf ( "  The last row contains the value of the continued\n" );
  printf ( "  fraction, written as a common fraction.\n" );
  printf ( "\n" );
  printf ( "  I, P(I), Q(I), P(I)/Q(I)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "%3d  %6d  %6d  %14g\n", 
      i, p[i], q[i], ( double ) p[i] / ( double ) q[i] );
  }
 
  return;
# undef M
}
/******************************************************************************/

void cfrac_to_rfrac_test ( )

/******************************************************************************/
/*
  Purpose:

    CFRAC_TO_RFRAC_TEST tests CFRAC_TO_RFRAC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 November 2013

  Author:

    John Burkardt
*/
{
# define MAXM 10

  int error;
  double g[2*MAXM];
  double h[2*MAXM];
  int i;
  int m;
  double p[MAXM];
  double q[MAXM+1];

  m = 3;

  p[0] = 1.0;
  p[1] = 1.0;
  p[2] = 2.0;

  q[0] = 1.0;
  q[1] = 3.0;
  q[2] = 1.0;
  q[3] = 1.0;

  printf ( "\n" );
  printf ( "CFRAC_TO_RFRAC_TEST\n" );
  printf ( "  CFRAC_TO_RFRAC: continued fraction to ratio;\n" );

  printf ( "\n" );
  printf ( "  Rational polynomial fraction coefficients:\n" );
  printf ( "\n" );

  printf ( "  P:  " );
  for ( i = 0; i < m; i++ )
  {
    printf ( "%12g", p[i] );
  }
  printf ( "\n" );

  printf ( "  Q:  " );
  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%12g", q[i] );
  }
  printf ( "\n" );

  rfrac_to_cfrac ( m, p, q, h, &error );
 
  r8vec_print ( 2*m, h, "  Continued fraction coefficients:" );

  for ( i = 0; i < 2 * m; i++ )
  {
    g[i] = 1.0;
  }

  cfrac_to_rfrac ( 2 * m, g, h, p, q );
 
  printf ( "\n" );
  printf ( "  Recovered rational polynomial:\n" );
  printf ( "\n" );
  
  printf ( "  P:  " );
  for ( i = 0; i < m; i++ )
  {
    printf ( "%12g", p[i] );
  }
  printf ( "\n" );

  printf ( "  Q:  " );
  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%12g", q[i] );
  }
  printf ( "\n" );

  return;
# undef MAXM
}
/******************************************************************************/

void change_greedy_test( )

/******************************************************************************/
/*
  Purpose:

    CHANGE_GREEDY_TEST tests CHANGE_GREEDY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 December 2013

  Author:

    John Burkardt
*/
{
# define COIN_NUM 6

  int change[100];
  int change_num;
  int coin_value[COIN_NUM] = { 1, 5, 10, 25, 50, 100 };
  int i;
  int total;
  int total2;

  printf ( "\n" );
  printf ( "CHANGE_GREEDY_TEST\n" );
  printf ( "  CHANGE_GREEDY makes change using the biggest\n" );
  printf ( "  coins first.\n" );

  total = 73;

  printf ( "\n" );
  printf ( "  The total for which change is to be made: %d\n", total );
  printf ( "\n" );
  printf ( "  The available coins are:\n" );
  printf ( "\n" );

  for ( i = 0; i < COIN_NUM; i++ )
  {
    printf ( "%6d\n", coin_value[i] );
  }

  change_greedy ( total, COIN_NUM, coin_value, &change_num, change );

  printf ( "\n" );
  printf ( "  The number of coins in change is: %d\n", change_num );
  printf ( "\n" );

  printf ( "        " );  
  for ( i = 0; i < change_num; i++ )
  {
    printf ( "%3d  ", change[i] );
  }
  printf ( "\n" );

  total2 = 0;
  for ( i = 0; i < change_num; i++ )
  {
    total2 = total2 + coin_value[change[i]];
  }

  printf ( "%6d  ", total2 );
  for ( i = 0; i < change_num; i++ )
  {
    printf ( "%3d  ", coin_value[change[i]] );
  }
  printf ( "\n" );

  return;
# undef COIN_NUM
}
/******************************************************************************/

void change_next_test ( )

/******************************************************************************/
/*
  Purpose:

    CHANGE_NEXT_TEST tests CHANGE_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 December 2013

  Author:

    John Burkardt
*/
{
# define COIN_NUM 6

  int change[100];
  int change_num;
  int coin_value[COIN_NUM] = { 1, 5, 10, 25, 50, 100 };
  int done;
  int i;
  int j;
  int total;

  printf ( "\n" );
  printf ( "CHANGE_NEXT_TEST\n" );
  printf ( "  CHANGE_NEXT displays the next possible way to make\n" );
  printf ( "  change for a given total\n" );

  total = 50;

  printf ( "\n" );
  printf ( "  The total for which change is to be made: %d\n", total );
  printf ( "\n" );

  printf ( "\n" );
  printf ( "  The available coins are:\n" );
  printf ( "\n" );
  for ( i = 0; i < COIN_NUM; i++ )
  {
    printf ( "%6d\n", coin_value[i] );
  }

  done = 1;
  i = 0;

  for ( ; ; )
  {
    change_next ( total, COIN_NUM, coin_value, &change_num, change, &done );

    if ( done || 9 < i )
    {
      break;
    }

    i = i + 1;
    printf ( "\n" );
    printf ( "%3d", i );
    for ( j = 0; j < change_num; j++ )
    {
      printf ( "%3d  ", coin_value[change[j]] );
    }
    printf ( "\n" );
  }

  return;
# undef COIN_NUM
}
/******************************************************************************/

void chinese_check_test ( )

/******************************************************************************/
/*
  Purpose:

    CHINESE_CHECK_TEST tests CHINESE_CHECK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 May 2015

  Author:

    John Burkardt
*/
{
  int ierror;
  int m1[4] = { 1, 3,  8, 25  };
  int m2[4] = { 1, 3, -8, 25  };
  int m3[4] = { 1, 3,  1, 25  };
  int m4[4] = { 1, 3,  8, 24  };
  int n = 4;

  printf ( "\n" );
  printf ( "CHINESE_CHECK_TEST\n" );
  printf ( "  CHINESE_CHECK checks a set of moduluses for use with the\n" );
  printf ( "  Chinese Remainder representation.\n" );

  i4vec1_print ( n, m1, "  Modulus set #1:" );
  ierror = chinese_check ( n, m1 );
  printf ( "  IERROR = %d\n", ierror );

  i4vec1_print ( n, m2, "  Modulus set #2:" );
  ierror = chinese_check ( n, m2 );
  printf ( "  IERROR = %d\n", ierror );

  i4vec1_print ( n, m3, "  Modulus set #3:" );
  ierror = chinese_check ( n, m3 );
  printf ( "  IERROR = %d\n", ierror );

  i4vec1_print ( n, m4, "  Modulus set #4:" );
  ierror = chinese_check ( n, m4 );
  printf ( "  IERROR = %d\n", ierror );

  return;
}
/******************************************************************************/

void chinese_to_i4_test ( )

/******************************************************************************/
/*
  Purpose:

    CHINESE_TO_I4_TEST tests CHINESE_TO_I4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int j;
  int j2;
  int m[N] = { 3, 4, 5, 7 };
  int r[N];

  printf ( "\n" );
  printf ( "CHINESE_TO_I4_TEST\n" );
  printf ( "  CHINESE_TO_I4 computes an integer with the given\n" );
  printf ( "  Chinese Remainder representation.\n" );

  i4vec1_print ( N, m, "  The moduli:" );

  j = 37;

  printf ( "\n" );
  printf ( "  The number being analyzed is %d\n", j );

  i4_to_chinese ( j, N, m, r );

  i4vec1_print ( N, r, "  The remainders:" );

  j2 = chinese_to_i4 ( N, m, r );

  printf ( "\n" );
  printf ( "  The reconstructed number is %d\n", j2 );

  i4_to_chinese ( j2, N, m, r );

  i4vec1_print ( N, r, "  The remainders of the reconstructed number are:" );

  return;
# undef N
}
/******************************************************************************/

void comb_next_test ( )

/******************************************************************************/
/*
  Purpose:

    COMB_NEXT_TEST tests COMB_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 April 2009

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N];
  int done;
  int i;
  int k;
  int n = N;

  printf ( "\n" );
  printf ( "COMB_NEXT_TEST\n" );
  printf ( "  COMB_NEXT produces combinations.\n" );

  for ( k = 1; k <= n; k++ )
  {
    printf ( "\n" );
    printf ( "  Combinations of size K = %d\n", k );
    printf ( "\n" );

    done = 1;

    for ( ; ; )
    {
      comb_next ( n, k, a, &done );

      if ( done )
      {
        break;
      }

      for ( i = 0; i < k; i++ )
      {
        printf ( "  %4d", a[i] );
      }
      printf ( "\n" );
    }
  }

  return;
# undef N
}
/******************************************************************************/

void comb_row_next_test ( )

/******************************************************************************/
/*
  Purpose:

    TEST012 tests COMB_ROW_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 May 2011

  Author:

    John Burkardt
*/
{
  int *c;
  int i;
  int n;
  int n_max = 10;

  printf ( "\n" );
  printf ( "COMB_ROW_NEXT_TEST\n" );
  printf ( "  COMB_ROW_NEXT computes the next row of the Pascal triangle.\n" );
  printf ( "\n" );

  c = ( int * ) malloc ( ( n_max + 1 ) * sizeof ( int ) );

  for ( n = 0; n <= n_max; n++ )
  {
    comb_row_next ( n, c );
    printf ( "  %2d  ", n );
    for ( i = 0; i <= n; i++ )
    {
      printf ( "%5d", c[i] );
    }
    printf ( "\n" );
  }

  free ( c );

  return;
}
/******************************************************************************/

void comb_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    COMB_UNRANK_TEST tests COMB_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 December 2013

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N];
  int cnk;
  int i;
  int m = 10;
  int rank;

  cnk = i4_choose ( m, N );

  printf ( "\n" );
  printf ( "COMB_UNRANK_TEST\n" );
  printf ( "  COMB_UNRANK returns a combination of N things\n" );
  printf ( "  out of M, given the lexicographic rank.\n" );
  printf ( "\n" );
  printf ( "  The total set size is M = %d\n", m );
  printf ( "  The subset size is N =    %d\n", N );
  printf ( "  The number of combinations of N out of M is %d\n", cnk );
  printf ( "\n" );
  printf ( "   Rank	  Combination\n" );
  printf ( "\n" );
 
  for ( rank = 1; rank <= 3; rank++ )
  {
    comb_unrank ( m, N, rank, a );
    printf ( "  %3d  ", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );
  }
 
  for ( rank = 6; rank <= 8; rank++ )
  {
    comb_unrank ( m, N, rank, a );
    printf ( "  %3d  ", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );
  }
 
  for ( rank = 250; rank <= 252; rank++ )
  {
    comb_unrank ( m, N, rank, a );
    printf ( "  %3d  ", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );
  }
 
  return;
# undef N
}
/******************************************************************************/

void comp_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_ENUM_TEST tests COMP_ENUM;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 October 2014

  Author:

    John Burkardt
*/
{
  int num;
  int k;
  int n;

  printf ( "\n" );
  printf ( "COMP_ENUM_TEST\n" );
  printf ( "  COMP_ENUM counts compositions;\n" );
  printf ( "\n" );
  for ( n = 0; n <= 10; n++ )
  {
    for ( k = 1; k <= 10; k++ )
    {
      num = comp_enum ( n, k );
      printf ( "  %6d", num );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void comp_next_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_NEXT_TEST tests COMP_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 January 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int h;
  int i;
  int index;
  int more;
  int n = 6;
  int t;

  printf ( "\n" );
  printf ( "COMP_NEXT_TEST\n" );
  printf ( "  COMP_NEXT produces compositions.\n" );
  printf ( "\n" );
  printf ( "  Seeking all compositions of N = %d\n", n );
  printf ( "  using %d parts.\n", K );
  printf ( "\n" );

  more = 0;
  index = 0;

  for ( ; ; )
  {
    comp_next ( n, K, a, &more, &h, &t );

    index = index + 1;
    printf ( "  " );
    printf ( "  %4d  ", index );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }
  }
 
  return;
# undef K
}
/******************************************************************************/

void comp_next_grlex_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_NEXT_GRLEX_TEST tests COMP_NEXT_GRLEX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 October 2014

  Author:

    John Burkardt
*/
{
  int j;
  int kc = 3;
  int nc;
  int rank;
  int xc[3];

  printf ( "\n" );
  printf ( "COMP_NEXT_GRLEX_TEST\n" );
  printf ( "  A COMP is a composition of an integer N into K parts.\n" );
  printf ( "  Each part is nonnegative.  The order matters.\n" );
  printf ( "  COMP_NEXT_GRLEX determines the next COMP in\n" );
  printf ( "  graded lexicographic (grlex) order.\n" );
  
  printf ( "\n" );
  printf ( "  Rank:     NC       COMP\n" );
  printf ( "  ----:     --   ------------\n" );

  for ( rank = 1; rank <= 71; rank++ )
  {
    if ( rank == 1 )
    {
      for ( j = 0; j < kc; j++ )
      {
        xc[j] = 0;
      }
    }
    else
    {
      comp_next_grlex ( kc, xc );
    }

    nc = i4vec_sum ( kc, xc );

    printf ( "   %3d: ", rank );
    printf ( "    %2d = ", nc );
    for ( j = 0; j < kc - 1; j++ )
    {
      printf ( "%2d + ", xc[j] );
    }
    printf ( "%2d\n", xc[kc-1] );
/*
  When XC(1) == NC, we have completed the compositions associated with
  a particular integer, and are about to advance to the next integer.
*/
    if ( xc[0] == nc )
    {
      printf ( "  ----:     --   ------------\n" );
    }
  }

  return;
}
/******************************************************************************/

void comp_random_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_RANDOM_TEST tests COMP_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2014

  Author:

    John Burkardt
*/
{
# define K 5

  int a[K];
  int i;
  int j;
  int n = 10;
  int seed;

  printf ( "\n" );
  printf ( "COMP_RANDOM_TEST\n" );
  printf ( "  COMP_RANDOM produces compositions at random.\n" );
  printf ( "\n" );
  printf ( "  Seeking random compositions of N = %d\n", n );
  printf ( "  using %d parts.\n", K );
  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 5; j++ )
  {
    comp_random ( n, K, &seed, a );

    printf ( "  " );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );
  }
 
  return;
# undef K
}
/******************************************************************************/

void comp_random_grlex_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_RANDOM_GRLEX_TEST tests COMP_RANDOM_GRLEX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 October 2014

  Author:

    John Burkardt
*/
{
  int j;
  int kc;
  int nc;
  int rank;
  int rank1;
  int rank2;
  int seed;
  int test;
  int *xc;

  printf ( "\n" );
  printf ( "COMP_RANDOM_GRLEX_TEST\n" );
  printf ( "  A COMP is a composition of an integer N into K parts.\n" );
  printf ( "  Each part is nonnegative.  The order matters.\n" );
  printf ( "  COMP_RANDOM_GRLEX selects a random COMP in\n" );
  printf ( "  graded lexicographic (grlex) order between indices RANK1 and RANK2.\n" );
  printf ( "\n" );

  kc = 3;
  rank1 = 20;
  rank2 = 60;
  seed = 123456789;

  for ( test = 1; test <= 5; test++ )
  {
    xc = comp_random_grlex ( kc, rank1, rank2, &seed, &rank );
    nc = i4vec_sum ( kc, xc );

    printf ( "   %3d: ", rank );
    printf ( "    %2d = ", nc );
    for ( j = 0; j < kc - 1; j++ )
    {
      printf ( "%2d + ", xc[j] );
    }
    printf ( "%2d\n", xc[kc-1] );
    free ( xc );
  }

  return;
}
/******************************************************************************/

void comp_rank_grlex_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_RANK_GRLEX_TEST tests COMP_RANK_GRLEX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 October 2014

  Author:

    John Burkardt
*/
{
  int kc;
  int rank1;
  int rank2;
  int rank3;
  int rank4;
  int seed;
  int test;
  int *xc;

  printf ( "\n" );
  printf ( "COMP_RANK_GRLEX_TEST\n" );
  printf ( "  A COMP is a composition of an integer N into K parts.\n" );
  printf ( "  Each part is nonnegative.  The order matters.\n" );
  printf ( "  COMP_RANK_GRLEX determines the rank of a COMP\n" );
  printf ( "  from its parts.\n" );
  printf ( "\n" );
  printf ( "        Actual  Inferred\n" );
  printf ( "  Test    Rank      Rank\n" );
  printf ( "\n" );

  kc = 3;
  rank1 = 20;
  rank2 = 60;
  seed = 123456789;

  for ( test = 1; test <= 5; test++ )
  {
    xc = comp_random_grlex ( kc, rank1, rank2, &seed, &rank3 );
    rank4 = comp_rank_grlex ( kc, xc );
    printf ( "  %4d  %6d  %8d\n", test, rank3, rank4 );
    free ( xc );
  }
  return;
}
/******************************************************************************/

void comp_to_ksub_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_TO_KSUB_TEST tests COMP_TO_KSUB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2013

  Author:

    John Burkardt
*/
{
  int ac[5];
  int as[4];
  int i;
  int j;
  int kc;
  int ks;
  int nc;
  int ns;
  int seed;
  
  printf ( "\n" );
  printf ( "COMP_TO_KSUB_TEST\n" );
  printf ( "  COMP_TO_KSUB returns the K subset corresponding to a composition.\n" );

  nc = 10;
  kc = 5;
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    printf ( "\n" );

    comp_random ( nc, kc, &seed, ac );
    printf ( "  COMP:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );

    comp_to_ksub ( nc, kc, ac, &ns, &ks, as );
    printf ( "  KSUB:" );
    for ( j = 0; j < ks; j++ )
    {
      printf ( "%4d", as[j] );
    }
    printf ( "\n" );

    ksub_to_comp ( ns, ks, as, &nc, &kc, ac );
    printf ( "  COMP:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );
    
  }

  return;
}
/******************************************************************************/

void comp_unrank_grlex_test ( )

/******************************************************************************/
/*
  Purpose:

    COMP_UNRANK_GRLEX_TEST tests COMP_UNRANK_GRLEX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 December 2013

  Author:

    John Burkardt
*/
{
  int j;
  int kc = 3;
  int nc;
  int rank1;
  int *xc;

  printf ( "\n" );
  printf ( "COMP_UNRANK_GRLEX_TEST\n" );
  printf ( "  A COMP is a composition of an integer N into K parts.\n" );
  printf ( "  Each part is nonnegative.  The order matters.\n" );
  printf ( "  COMP_UNRANK_GRLEX determines the parts\n" );
  printf ( "  of a COMP from its rank.\n" );
 
  printf ( "\n" );
  printf ( "  Rank: ->  NC       COMP    \n" );
  printf ( "  ----:     --   ------------ \n" );

  for ( rank1 = 1; rank1 <= 71; rank1++ )
  {
    xc = comp_unrank_grlex ( kc, rank1 );
    nc = i4vec_sum ( kc, xc );
    printf ( "   %3d: ", rank1 );
    printf ( "    %2d = ", nc );
    for ( j = 0; j < kc - 1; j++ )
    {
      printf ( "%2d + ", xc[j] );
    }
    printf ( "%2d\n", xc[kc-1] ); 
/*
  When XC(1) == NC, we have completed the compositions associated with
  a particular integer, and are about to advance to the next integer.
*/
    if ( xc[0] == nc )
    {
      printf ( "  ----:     --   ------------\n" );
    }
    free ( xc );
  }
  return;
}
/******************************************************************************/

void compnz_next_test ( )

/******************************************************************************/
/*
  Purpose:

    COMPNZ_NEXT_TEST tests COMPNZ_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 May 2015

  Author:

    John Burkardt
*/
{
  int a[3];
  int h;
  int i;
  int k;
  int more;
  int n;
  int t;

  n = 6;
  k = 3;
  more = 0;

  printf ( "\n" );
  printf ( "COMPNZ_NEXT_TEST\n" );
  printf ( "  COMPNZ_NEXT produces compositions using nonzero parts.\n" );
  printf ( "\n" );
  printf ( "  Seeking all compositions of N = %d\n", n );
  printf ( "  using %d nonzero parts.\n", k );
  printf ( "\n" );

  for ( ; ; )
  {
    compnz_next ( n, k, a, &more, &h, &t );

    printf ( "  " );
    for ( i = 0; i < k; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }
  }
 
  return;
}
/******************************************************************************/

void compnz_random_test ( )

/******************************************************************************/
/*
  Purpose:

    COMPNZ_RANDOM_TEST tests COMPNZ_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
# define K 5

  int a[K];
  int i;
  int j;
  int n = 10;
  int seed;

  printf ( "\n" );
  printf ( "COMPNZ_RANDOM_TEST\n" );
  printf ( "  COMPNZ_RANDOM produces compositions at random\n" );
  printf ( "  with only nonzero parts.\n" );
  printf ( "\n" );
  printf ( "  Seeking random compositions of N = %d\n", n );
  printf ( "  using %d nonzero parts.\n", K );
  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 5; j++ )
  {
    compnz_random ( n, K, &seed, a );

    printf ( "  " );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );
  }
 
  return;
# undef K
}
/******************************************************************************/

void compnz_to_ksub_test ( )

/******************************************************************************/
/*
  Purpose:

    COMPNZ_TO_KSUB_TEST tests COMPNZ_TO_KSUB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 December 2013

  Author:

    John Burkardt
*/
{
  int ac[5];
  int as[4];
  int i;
  int j;
  int kc;
  int ks;
  int nc;
  int ns;
  int seed;
  
  printf ( "\n" );
  printf ( "COMPNZ_TO_KSUB_TEST\n" );
  printf ( "  COMPNZ_TO_KSUB returns the K subset corresponding\n" );
  printf ( "  to a nonzero composition.\n" );
  printf ( "  KSUB_TO_COMPNZ returns the nonzero composition \n" );
  printf ( "  corresponding to a K subset.\n" );

  nc = 10;
  kc = 5;
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    printf ( "\n" );

    compnz_random ( nc, kc, &seed, ac );
    printf ( "  COMPNZ:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );

    compnz_to_ksub ( nc, kc, ac, &ns, &ks, as );
    printf ( "  KSUB:  " );
    for ( j = 0; j < ks; j++ )
    {
      printf ( "%4d", as[j] );
    }
    printf ( "\n" );

    ksub_to_compnz ( ns, ks, as, &nc, &kc, ac );
    printf ( "  COMPNZ:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );
    
  }

  return;
}
/******************************************************************************/

void congruence_test ( )

/******************************************************************************/
/*
  Purpose:

    CONGRUENCE_TEST tests CONGRUENCE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
# define TEST_NUM 20

  int a;
  int a_test[TEST_NUM] = {
     1027,   1027,  1027,   1027, -1027,
    -1027, - 1027, -1027,      6,     0,
        0,      0,     1,      1,     1,
     1024,      0,     0,      5,     2 };
  int b;
  int b_test[TEST_NUM] = {
      712,    712,  -712,   -712,   712,
      712,   -712,  -712,      8,     0,
        1,      1,     0,      0,     1,
   -15625,      0,     3,      0,     4 };
  int c;
  int c_test[TEST_NUM] = {
        7,     -7,     7,     -7,     7,
       -7,      7,    -7,     50,     0,
        0,      1,     0,      1,     0,
    11529,      1,    11,     19,     7 };
  int error;
  int result;
  int test_i;
  int x;

  printf ( "\n" );
  printf ( "CONGRUENCE_TEST\n" );
  printf ( "  CONGRUENCE solves a congruence equation:\n" );
  printf ( "    A * X = C mod ( B )\n" );
  printf ( "\n" );
  printf ( "   I        A         B         C         X     Mod ( A*X-C,B)\n" );
  printf ( "\n" );

  for ( test_i = 1; test_i < TEST_NUM; test_i++ )
  {
    a = a_test[test_i];
    b = b_test[test_i];
    c = c_test[test_i];

    x = congruence ( a, b, c, &error );

    if ( error )
    {
      printf ( "  %2d  %10d  %10d  %10d  (An error occurred)\n", test_i, a, b, c );
    }
    else
    {
      if ( b != 0 )
      {
        result = i4_modp ( a * x - c, b );
      }
      else
      {
        result = 0;
      }
      printf ( "  %2d  %10d  %10d  %10d  %10d  %10d\n", test_i, a, b, c, x, result );
    }

  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void count_pose_random_test ( )

/******************************************************************************/
/*
  Purpose:

    COUNT_POSE_RANDOM_TEST tests COUNT_POSE_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 January 2014

  Author:

    John Burkardt
*/
{
  int blocks[6];
  int goal;
  int i;
  int j;
  int seed;

  printf ( "\n" );
  printf ( "COUNT_POSE_RANDOM_TEST\n" );
  printf ( "  COUNT_POSE_RANDOM poses a random problem for\n" );
  printf ( "  the game The Count is Good.\n" );

  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    count_pose_random ( &seed, blocks, &goal );

    printf ( "\n" );
    printf ( "  Problem #%d\n", i );
    printf ( "\n" );
    printf ( "    The goal = %d\n", goal );
    printf ( "\n" );
    printf ( "    The available numbers are\n" );
    printf ( "\n" );
    for ( j = 0; j < 6; j++ )
    {
      printf ( "%4d  ", blocks[j] );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void debruijn_test ( )

/******************************************************************************/
/*
  Purpose:

    DEBRUIJN_TEST tests DEBRUIJN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 January 2014

  Author:

    John Burkardt
*/
{
# define NUM_TEST 3

  int i;
  int ihi;
  int m;
  int mtest[NUM_TEST] = { 2, 3, 2 };
  int n;
  int ntest[NUM_TEST] = { 3, 3, 4 };
  int string[28];
  int test;

  printf ( "\n" );
  printf ( "DEBRUIJN_TEST\n" );
  printf ( "  DEBRUIJN computes a de Bruijn string.\n" );

  for ( test = 0; test < NUM_TEST; test++ )
  {
    m = mtest[test];
    n = ntest[test];

    printf ( "\n" );
    printf ( "  The alphabet size is M = %d\n", m );
    printf ( "  The string length is N = %d\n", n );

    debruijn ( m, n, string );

    ihi = i4_power ( m, n );

    printf ( "\n" );
    printf ( "  " );
    for ( i = 0; i < ihi; i++ )
    {
      printf ( "%d", string[i] );
    }
    printf ( "\n" );

  }

  return;
# undef NUM_TEST
}
/******************************************************************************/

void dec_add_test ( )

/******************************************************************************/
/*
  Purpose:

    TEST022 tests DEC_ADD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 January 2014

  Author:

    John Burkardt
*/
{
  int abot;
  int atop;
  int bbot;
  int btop;
  int cbot;
  int ctop;
  int dec_digit;

  printf ( "\n" );
  printf ( "DEC_ADD_TEST\n" );
  printf ( "  DEC_ADD adds two decimals.\n" );
  printf ( "\n" );

  dec_digit = 3;
  atop = 128;
  abot = -1;
  btop = 438;
  bbot = -2;

  dec_add ( atop, abot, btop, bbot, dec_digit, &ctop, &cbot );

  printf ( "\n" );
  printf ( "  Number of decimal places is %d\n", dec_digit );
  printf ( "\n" );

  printf ( "  A =           %d * 10^(%d)\n", atop, abot );
  printf ( "  B =           %d * 10^(%d)\n", btop, bbot );
  printf ( "  C = A + B =   %d * 10^(%d)\n", ctop, cbot );
 
  return;
}
/******************************************************************************/

void dec_div_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_DIV_TEST tests DEC_DIV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 January 2014

  Author:

    John Burkardt
*/
{
  int abot = -1;
  int atop = 523;
  int bbot = 2;
  int btop = 134;
  int cbot;
  int ctop;
  int dec_digit;
  int error;

  printf ( "\n" );
  printf ( "DEC_DIV_TEST\n" );
  printf ( "  DEC_DIV divides two decimals.\n" );

  dec_digit = 3;

  dec_div ( atop, abot, btop, bbot, dec_digit, &ctop, &cbot, &error );

  printf ( "\n" );
  printf ( "  Number of decimal places is %d\n", dec_digit );
  printf ( "\n" );

  printf ( "  A         = %d*10^(%d)\n", atop, abot );
  printf ( "  B         = %d*10^(%d)\n", btop, bbot );
  printf ( "  C = A / B = %d*10^(%d)\n", ctop, cbot );

  return;
}
/******************************************************************************/

void dec_mul_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_MUL_TEST tests DEC_MUL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 January 2014

  Author:

    John Burkardt
*/
{
  int abot = -4;
  int atop = 14;
  int bbot = 2;
  int btop = 16;
  int cbot;
  int ctop;
  int dec_digit;

  printf ( "\n" );
  printf ( "DEC_MUL_TEST\n" );
  printf ( "  DEC_MUL multiplies two decimals.\n" );

  dec_digit = 2;

  dec_mul ( atop, abot, btop, bbot, dec_digit, &ctop, &cbot );

  printf ( "\n" );
  printf ( "  Number of decimal places is %d\n", dec_digit );
  printf ( "\n" );

  printf ( "  A =         %d*10^(%d)\n", atop, abot );
  printf ( "  B =         %d*10^(%d)\n", btop, bbot );
  printf ( "  C = A * B = %d*10^(%d)\n", ctop, cbot );

  return;
}
/******************************************************************************/

void dec_round_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_ROUND_TEST tests DEC_ROUND.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 July 2007

  Author:

    John Burkardt
*/
{
# define N_TEST 7

  int a;
  int a_test[N_TEST] = { 523, 523, 523, 523, 6340, 6340, 6340 };
  int b;
  int b_test[N_TEST] = { -1,  -1, -1, -1, 2, 2, 2 };
  int dec_digit;
  int r8_test[N_TEST] = { 1, 2, 3, 4, 2, 3, 4 };
  int i;

  printf ( "\n" );
  printf ( "DEC_ROUND_TEST\n" );
  printf ( "  DEC_ROUND rounds a decimal to a number of digits.\n" );
  printf ( "\n" );
  printf ( "           -----Before-------  -----After--------\n" );
  printf ( "  Digits   Mantissa  Exponent  Mantissa  Exponent\n" );
  printf ( "\n" );

  for ( i = 0; i < N_TEST; i++ )
  {
    dec_digit = r8_test[i];

    a = a_test[i];
    b = b_test[i];

    dec_round ( a, b, dec_digit, &a, &b );

    printf ( "%6d  %6d  %6d    %6d  %6d\n", 
      r8_test[i], a_test[i], b_test[i], a, b );
  }

  return;
# undef N_TEST
}
/******************************************************************************/

void dec_to_r8_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_TO_R8_TEST tests DEC_TO_R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 June 2015

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int dec_digit;
  int i;
  double r;
  double r2;
  double r8_hi;
  double r8_lo;
  int seed;

  printf ( "\n" );
  printf ( "DEC_TO_R8_TEST\n" );
  printf ( "  DEC_TO_R8 converts a decimal to a real number.\n" );

  dec_digit = 5;

  printf ( "\n" );
  printf ( "  The maximum number of digits allowed is %d\n", dec_digit );

  r8_lo = -10.0;
  r8_hi = +10.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "     R   =>  A * 10^B  =>  R2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_uniform_ab ( r8_lo, r8_hi, &seed );

    r8_to_dec ( r, dec_digit, &a, &b );
    r2 = dec_to_r8 ( a, b );

    printf ( "  %10.4g  %6d  %6d  %10.4g\n", r, a, b, r2 );
  }

  return;
}
/******************************************************************************/

void dec_to_rat_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_TO_RAT_TEST tests DEC_TO_RAT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2014

  Author:

    John Burkardt
*/
{
  int exponent;
  int i;
  int mantissa;
  double r1;
  double r2;
  double r3;
  int rat_bot;
  int rat_bot2;
  int rat_top;
  int rat_top2;
  int seed;

  printf ( "\n" );
  printf ( "DEC_TO_RAT_TEST\n" );
  printf ( "  DEC_TO_RAT decimal => fraction.\n" );
  printf ( "\n" );
  printf ( "  In this test, choose the top and bottom\n" );
  printf ( "  of a rational at random, and compute the\n" );
  printf ( "  equivalent real number.\n" );
  printf ( "\n" );
  printf ( "  Then convert to decimal, and the equivalent real.\n" );
  printf ( "\n" );
  printf ( "  Then convert back to rational and the equivalent real.\n" );
  
  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    rat_top = i4_uniform_ab ( -1000, 1000, &seed );
    rat_bot = i4_uniform_ab (     1, 1000, &seed );

    r1 = ( double ) rat_top / ( double ) rat_bot;

    rat_to_dec ( rat_top, rat_bot, &mantissa, &exponent );
    r2 = ( double ) mantissa * pow ( 10.0, exponent );

    dec_to_rat ( mantissa, exponent, &rat_top2, &rat_bot2 );
    r3 = ( double ) rat_top2 / ( double ) rat_bot2;

    printf ( "\n" );
    printf ( "  %g = %d / %d\n", r1, rat_top, rat_bot );
    printf ( "  %g = %d * 10 ^ %d\n", r2, mantissa, exponent );
    printf ( "  %g = %d / %d\n", r3, rat_top2, rat_bot2 );
  }
 
  return;
}
/******************************************************************************/

void dec_to_s_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_TO_S_TEST tests DEC_TO_S.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 January 2015

  Author:

    John Burkardt
*/
{
  int exponent;
  int mantissa;
  char *s;

  printf ( "\n" );
  printf ( "DEC_TO_S_TEST\n" );
  printf ( "  DEC_TO_S prints out a decimal.\n" );
  printf ( "\n" );
  printf ( "  Mantissa  Exponent  String\n" );
  printf ( "\n" );

  mantissa = 523;
  exponent = -1;
  s = dec_to_s ( mantissa, exponent );
  printf ( "%8d  %8d  %s\n", mantissa, exponent, s );
  free ( s );

  mantissa = 134;
  exponent = 2;
  s = dec_to_s ( mantissa, exponent );
  printf ( "%8d  %8d  %s\n", mantissa, exponent, s );
  free ( s );

  mantissa = -134;
  exponent = 2;
  s = dec_to_s ( mantissa, exponent );
  printf ( "%8d  %8d  %s\n", mantissa, exponent, s );
  free ( s );

  mantissa = 0;
  exponent = 10;
  s = dec_to_s ( mantissa, exponent );
  printf ( "%8d  %8d  %s\n", mantissa, exponent, s );
  free ( s );

  for ( exponent = -8;exponent < 4; exponent++ )
  {
    mantissa = 123456;
    s = dec_to_s ( mantissa, exponent );
    printf ( "%8d  %8d  %s\n", mantissa, exponent, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void dec_width_test ( )

/******************************************************************************/
/*
  Purpose:

    DEC_WIDTH_TEST tests DEC_WIDTH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 January 2014

  Author:

    John Burkardt
*/
{
  int exponent;
  int i;
  int mantissa;

  printf ( "\n" );
  printf ( "DEC_WIDTH_TEST\n" );
  printf ( "  DEC_WIDTH determines the \"width\" of a decimal.\n" );
  printf ( "\n" );
  printf ( "  Mantissa  Exponent  Width\n" );
  printf ( "\n" );

  mantissa = 523;
  exponent = -1;
  i = dec_width ( mantissa, exponent );
  printf ( "%8d  %8d  %8d\n", mantissa, exponent, i );

  mantissa = 134;
  exponent = 2;
  i = dec_width ( mantissa, exponent );
  printf ( "%8d  %8d  %8d\n", mantissa, exponent, i );

  mantissa = -134;
  exponent = 2;
  i = dec_width ( mantissa, exponent );
  printf ( "%8d  %8d  %8d\n", mantissa, exponent, i );

  mantissa = 0;
  exponent = 10;
  i = dec_width ( mantissa, exponent );
  printf ( "%8d  %8d  %8d\n", mantissa, exponent, i );

  for ( exponent = -8; exponent < 4; exponent++ )
  {
    mantissa = 123456;
    i = dec_width ( mantissa, exponent );
    printf ( "%8d  %8d  %8d\n", mantissa, exponent, i );
  }

  return;
}
/******************************************************************************/

void decmat_det_test ( )

/******************************************************************************/
/*
  Purpose:

    DECMAT_DET_TEST tests DECMAT_DET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 January 2014

  Author:

    John Burkardt
*/
{
# define N3 3
# define N4 4

  int a;
  int b;
  int a3[N3*N3];
  int a4[N4*N4];
  int b3[N3*N3];
  int b4[N4*N4];
  int i;
  int dbot;
  int dec_digit;
  int dtop;
  int j;
  int k;
  double r;

  printf ( "\n" );
  printf ( "DECMAT_DET_TEST\n" );
  printf ( "  DECMAT_DET: determinant of a decimal matrix.\n" );
 
  dec_digit = 5;

  k = 0;
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      k = k + 1;
      a3[i+j*N3] = k;
    }
  }

  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      b3[i+j*N3] = 0;
    }
  }
 
  decmat_print ( N3, N3, a3, b3, "  The 123/456/789 matrix:" );

  decmat_det ( N3, a3, b3, dec_digit, &dtop, &dbot );
 
  printf ( "\n" );
  printf ( "  Determinant of the 123/456/789 matrix = %d * 10^(%d)\n",
    dtop, dbot ); 

  for ( i = 0; i < N4; i++ )
  {
    for ( j = 0; j < N4; j++ )
    {
      r = 1.0 / ( double ) ( i + j + 2 );
      
      r8_to_dec ( r, dec_digit, &a, &b );
      a4[i+j*N4] = a;
      b4[i+j*N4] = b;
    }
  }
 
  decmat_print ( N4, N4, a4, b4, "  The Hilbert matrix:" );
 
  decmat_det ( N4, a4, b4, dec_digit, &dtop, &dbot );
 
  printf ( "\n" );
  printf ( "  Determinant of the Hilbert matrix = %d * 10^(%d)\n",
    dtop, dbot ); 
 
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      if ( i == j )
      {
        a3[i+j*N3] = 2;
      }
      else if ( i == j+1 || i == j-1 )
      {
        a3[i+j*N3] = -1;
      }
      else
      {
        a3[i+j*N3] = 0;
      }
    }
  }
 
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      b3[i+j*N3] = 0;
    }
  }

  decmat_print ( N3, N3, a3, b3, "  The -1,2,-1 matrix:" );
 
  decmat_det ( N3, a3, b3, dec_digit, &dtop, &dbot );
 
  printf ( "\n" );
  printf ( "  Determinant of the -1,2,-1 matrix = %d * 10^(%d)\n",
    dtop, dbot ); 
 
  return;
# undef N3
# undef N4
}
/******************************************************************************/

void decmat_print_test ( )

/******************************************************************************/
/*
  Purpose:

    DECMAT_PRINT_TEST tests DECMAT_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 June 2015

  Author:

    John Burkardt
*/
{
  int a;
  int amat[4*3];
  int b;
  int bmat[4*3];
  int dec_digit;
  int i;
  int j;
  int m = 4;
  int n = 3;
  double r;

  printf ( "\n" );
  printf ( "DECMAT_PRINT_TEST\n" );
  printf ( "  DECMAT_PRINT prints a decimal matrix.\n" );
 
  dec_digit = 5;

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      r = 1.0 / ( double ) ( i + j + 2 );
      
      r8_to_dec ( r, dec_digit, &a, &b );
      amat[i+j*m] = a;
      bmat[i+j*m] = b;
    }
  }
 
  decmat_print ( m, n, amat, bmat, "  The Hilbert matrix:" );
 
  return;
}
/******************************************************************************/

void derange_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGE_ENUM_TEST tests DERANGE_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 January 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int i;

  printf ( "\n" );
  printf ( "DERANGE_ENUM_TEST\n" );
  printf ( "  DERANGE_ENUM counts derangements;\n" );
  printf ( "\n" );
  printf ( "       N    # of derangements\n" );
  printf ( "\n" );

  for ( i = 0; i<= N; i++ )
  {
    printf ( "  %8d  %8d\n", i, derange_enum ( i ) );
  }

  return;
# undef N
}
/******************************************************************************/

void derange_enum2_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGE_ENUM2_TEST tests DERANGE_ENUM2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 January 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int d[N+1];
  int i;

  printf ( "\n" );
  printf ( "DERANGE_ENUM2_TEST\n" );
  printf ( "  DERANGE_ENUM2 counts derangements.\n" );
  printf ( "\n" );
  printf ( "       N    # of derangements\n" );
  printf ( "\n" );

  derange_enum2 ( N, d );

  for ( i = 0; i<= N; i++ )
  {
    printf ( "  %8d  %8d\n", i, d[i] );
  }

  return;
# undef N
}
/******************************************************************************/

void derange_enum3_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGE_ENUM3_TEST tests DERANGE_ENUM3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 January 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int i;

  printf ( "\n" );
  printf ( "DERANGE_ENUM3_TEST\n" );
  printf ( "  DERANGE_ENUM3 counts derangements.\n" );
  printf ( "\n" );
  printf ( "       N    # of derangements\n" );
  printf ( "\n" );

  for ( i = 0; i<= N; i++ )
  {
    printf ( "  %8d  %8d\n", i, derange_enum3 ( i ) );
  }

  return;
# undef N
}
/******************************************************************************/

void derange0_back_next_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGE0_BACK_NEXT_TEST tests DERANGE0_BACK_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2015

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N];
  int i;
  int more;
  int rank;

  printf ( "\n" );
  printf ( "DERANGE0_BACK_NEXT_TEST\n" );
  printf ( "  DERANGE0_BACK_NEXT generates derangements\n" );
  printf ( "  using backtracking.\n" );
  printf ( "\n" );

  more = 0;
  rank = 0;

  for ( ; ; )
  {
    derange0_back_next ( N, a, &more );

    if ( !more )
    {
      break;
    }

    rank = rank + 1;

    printf ( "%4d    ", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void derange0_check_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGE0_CHECK_TEST tests DERANGE0_CHECK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 June 2015

  Author:

    John Burkardt
*/
{
  int a[5];
  int a_test[5*5] = {
    1, 2, 3, 4, 0, 
    1, 4, 2, 0, 3, 
    1, 2, 3, 0, 3, 
   -1, 2, 3, 4, 0, 
    0, 3, 8, 1, 2 };
  int check;
  int i;
  int j;
  int n = 5;
  int n_test = 5;

  printf ( "\n" );
  printf ( "DERANGE0_CHECK_TEST\n" );
  printf ( "  DERANGE0_CHECK checks whether a vector of N objects\n" );
  printf ( "  is a derangement of (0,...,N-1).\n" );

  for ( j = 0; j < n_test; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i] = a_test[i+j*n];
    }

    i4vec_transpose_print ( n, a, "  Potential derangement:" );
    check = derange0_check ( n, a );
    printf ( "  CHECK = %d\n", check );
  }

  return;
}
/******************************************************************************/

void derange0_weed_next_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGE0_WEED_NEXT_TEST tests DERANGE0_WEED_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 June 2015

  Author:

    John Burkardt
*/
{
  int *a;
  int i;
  int maxder;
  int more;
  int n;
  int numder;
  int rank;

  n = 5;
  a = ( int * ) malloc ( n * sizeof ( int ) );
  more = 0;
  maxder = 0;
  numder = 0;

  printf ( "\n" );
  printf ( "DERANGE0_WEED_NEXT_TEST\n" );
  printf ( "  DERANGE0_WEED_NEXT generates derangements\n" );
  printf ( "  by generating ALL permutations, and weeding out\n" );
  printf ( "  the ones that are not derangements.\n" );
  printf ( "\n" );

  rank = 0;
 
  for ( ; ; )
  {
    derange0_weed_next ( n, a, &more, &maxder, &numder );

    rank = rank + 1;

    printf ( "%4d:   ", rank );
    for ( i = 0; i < n; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }
 
  }

  free ( a );

  return;
}
/******************************************************************************/

void digraph_arc_euler_test ( )

/******************************************************************************/
/*
  Purpose:

    DIGRAPH_ARC_EULER_TEST calls DIGRAPH_ARC_EULER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 January 2014

  Author:

    John Burkardt
*/
{
# define NEDGE 7
# define NNODE 5

  int i;
  int in;
  int inode[NEDGE] = { 2, 1, 2, 1, 3, 5, 4 };
  int j;
  int jnode[NEDGE] = { 5, 4, 3, 2, 1, 1, 2 };
  int jp1;
  int success;
  int trail[NEDGE];

  printf ( "\n" );
  printf ( "DIGRAPH_ARC_EULER_TEST\n" );
  printf ( "  DIGRAPH_ARC_EULER finds an Euler circuit of a digraph.\n" );

  digraph_arc_print ( NEDGE, inode, jnode, "  The arc list of the digraph:" );

  digraph_arc_euler ( NNODE, NEDGE, inode, jnode, &success, trail );

  if ( success )
  {
    i4vec1_print ( NEDGE, trail, "  The edge list of the Euler circuit:" );

    printf ( "\n" );
    printf ( "  The node list of the Euler circuit:\n" );
    printf ( "\n" );
    printf ( "	 I  Edge  Node\n" );
    printf ( "\n" );

    for ( i = 0; i < NEDGE; i++ )
    {
      j = trail[i];

      if ( i+1 == NEDGE )
      {
        jp1 = trail[0];
      }
      else
      {
        jp1 = trail[i+1];
      }

      if ( jnode[j-1] == inode[jp1-1] )
      {
        in = jnode[j-1];
      }
      else
      {
        printf ( "\n" );
        printf ( "The circuit has failed!\n" );
        printf ( "  JNODE[%d] = %d\n", j-1, jnode[j-1] );
        printf ( "  INODE[%d] = %d\n", jp1-1, inode[jp1-1] );
        break;
      }

      printf ( "%6d  %6d  %6d\n", i, j, in );
    }
  }
  else
  {
    printf ( "\n" );
    printf ( "  The digraph is not eulerian.\n" );
    printf ( "\n" );
  }

  return;
# undef NEDGE
# undef NNODE
}
/******************************************************************************/

void digraph_arc_print_test ( )

/******************************************************************************/
/*
  Purpose:

    DIGRAPH_ARC_PRINT_TEST calls DIGRAPH_ARC_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2015

  Author:

    John Burkardt
*/
{
  int inode[7] = { 2, 1, 2, 1, 3, 5, 4 };
  int jnode[7] = { 5, 4, 3, 2, 1, 1, 2 };
  int nedge;

  printf ( "\n" );
  printf ( "DIGRAPH_ARC_PRINT_TEST\n" );
  printf ( "  DIGRAPH_ARC_PRINT prints a digraph.\n" );

  nedge = 7;

  digraph_arc_print ( nedge, inode, jnode, "  The arc list of the digraph:" );

  return;
}
/******************************************************************************/

void diophantine_test ( )

/******************************************************************************/
/*
  Purpose:

    DIOPHANTINE_TEST tests DIOPHANTINE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 February 2014

  Author:

    John Burkardt
*/
{
# define TEST_NUM 20

  int a;
  int a_test[TEST_NUM] = {
      1027,    1027,    1027,    1027,   -1027,
     -1027,   -1027,   -1027,       6,       0,
         0,       0,       1,       1,       1,
      1024,       0,       0,       5,       2 };
  int b;
  int b_test[TEST_NUM] = {
       712,     712,    -712,    -712,     712,
       712,    -712,    -712,       8,       0,
         1,       1,       0,       0,       1,
    -15625,       0,       3,       0,       4 };
  int c;
  int c_test[TEST_NUM] = {
         7,      -7,       7,      -7,       7,
        -7,       7,      -7,      50,       0,
         0,       1,       0,       1,       0,
     11529,       1,      11,      19,       7 };

  int error;
  int r;
  int test_i;
  int x;
  int y;

  printf ( "\n" );
  printf ( "DIOPHANTINE_TEST\n" );
  printf ( "  DIOPHANTINE solves a Diophantine equation:\n" );
  printf ( "    A * X + B * Y = C\n" );
  printf ( "\n" );
  printf ( "        A         B         C         X     Y     Residual\n" );
  printf ( "\n" );

  for ( test_i = 0; test_i < TEST_NUM; test_i++ )
  {
    a = a_test[test_i];
    b = b_test[test_i];
    c = c_test[test_i];

    diophantine ( a, b, c, &error, &x, &y );

    if ( error )
    {
      printf ( "%10d  %10d  %10d  (Error occurred!)\n", a, b, c );
    }
    else
    {
      r = a * x + b * y - c;
      printf ( "%10d  %10d  %10d  %10d  %10d  %10d\n", a, b, c, x, y, r );
    }

  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void diophantine_solution_minimize_test ( )

/******************************************************************************/
/*
  Purpose:

    DIOPHANTINE_SOLUTION_MINIMIZE_TEST tests DIOPHANTINE_SOLUTION_MINIMIZE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 February 2014

  Author:

    John Burkardt
*/
{
  int a = 4096;
  int b = -15625;
  int c = 46116;
  int r;
  int x;
  int y;

  printf ( "\n" );
  printf ( "DIOPHANTINE_SOLUTION_MINIMIZE_TEST\n" );
  printf ( "  DIOPHANTINE_SOLUTION_MINIMIZE computes a minimal\n" );
  printf ( "  Euclidean norm solution of a Diophantine equation:\n" );
  printf ( "    A * X + B * Y = C\n" );

  x = 665499996;
  y = 174456828;

  r = a * x + b * y - c;

  printf ( "\n" );
  printf ( "  Coefficients:\n" );
  printf ( "    A = %12d\n", a );
  printf ( "    B = %12d\n", b );
  printf ( "    C = %12d\n", c );
  printf ( "  Solution:\n" );
  printf ( "    X = %12d\n", x );
  printf ( "    Y = %12d\n", y );
  printf ( "  Residual R = A * X + B * Y - C:\n" );
  printf ( "    R = %12d\n", r );

  diophantine_solution_minimize ( a, b, &x, &y );

  r = a * x + b * y - c;

  printf ( "\n" );
  printf ( "  DIOPHANTINE_SOLUTION_MINIMIZE returns\n" );
  printf ( "  the minimized solution:\n" );
  printf ( "    X = %12d\n", x );
  printf ( "    Y = %12d\n", y );
  printf ( "  Residual R = A * X + B * Y - C:\n" );
  printf ( "    R = %12d\n", r );

  x = 15621;
  y = 4092;

  r = a * x + b * y - c;

  printf ( "\n" );
  printf ( "  Here is the minimal positive solution:\n" );
  printf ( "    X = %12d\n", x );
  printf ( "    Y = %12d\n", y );
  printf ( "  Residual R = A * X + B * Y - C:\n" );
  printf ( "    R = %12d\n", r );

  return;
}
/******************************************************************************/

void dvec_add_test ( )

/******************************************************************************/
/*
  Purpose:

    DVEC_ADD_TEST tests DVEC_ADD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int dvec1[N];
  int dvec2[N];
  int dvec3[N];
  int i;
  int j;
  int k;
  int l;
  int seed = 123456789;
  int test;
  int test_num = 10;

  printf ( "\n" );
  printf ( "DVEC_ADD_TEST\n" );
  printf ( "  DVEC_ADD adds decimal vectors representing integers;\n" );
  printf ( "\n" );
  printf ( "        I        J        I + J    DVEC_ADD\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  { 
    i = i4_uniform_ab ( -100, 100, &seed );
    j = i4_uniform_ab ( -100, 100, &seed );

    k = i + j;
 
    i4_to_dvec ( i, N, dvec1 );
    i4_to_dvec ( j, N, dvec2 );
    dvec_add ( N, dvec1, dvec2, dvec3 );
    l = dvec_to_i4 ( N, dvec3 );

    printf ( "  %8d  %8d  %8d  %8d\n", i, j, k, l );
  }

  return;
# undef N
}
/******************************************************************************/

void dvec_complementx_test ( )

/******************************************************************************/
/*
  Purpose:

    DVEC_COMPLEMENTX_TEST tests DVEC_COMPLEMENTX;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 February 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int dvec1[N];
  int dvec2[N];
  int i;
  int j;
  int seed = 123456789;
  int test;
  int test_num = 5;

  printf ( "\n" );
  printf ( "DVEC_COMPLEMENTX_TEST\n" );
  printf ( "  DVEC_COMPLEMENTX returns the ten's complement\n" );
  printf ( "  of a (signed) decimal vector;\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    i = i4_uniform_ab ( -100, 100, &seed );

    i4_to_dvec ( i, N, dvec1 );

    dvec_complementx ( N, dvec1, dvec2 );

    j = dvec_to_i4 ( N, dvec2 );

    printf ( "\n" );
    printf ( "  I = %d\n", i );
    printf ( "  J = %d\n", j );
    dvec_print ( N, dvec1, "" );
    dvec_print ( N, dvec2, "" );
  }

  return;
# undef N
}
/******************************************************************************/

void dvec_mul_test ( )

/******************************************************************************/
/*
  Purpose:

    DVEC_MUL_TEST tests DVEC_MUL;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 February 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int dvec1[N];
  int dvec2[N];
  int dvec3[N];
  int i;
  int j;
  int k;
  int n2;
  int seed = 123456789;
  int test;
  int test_num = 10;
  int test2;
  int test2_num = 2;

  printf ( "\n" );
  printf ( "DVEC_MUL_TEST\n" );
  printf ( "  DVEC_MUL multiplies decimal vectors\n" );
  printf ( "  representing integers;\n" );

  for ( test2 = 1; test2 <= test2_num; test2++ )
  {
    if ( test2 == 1 )
    {
      n2 = N;
    }
    else if ( test2 == 2 )
    {
      n2 = 6;

      printf ( "\n" );
      printf ( "  NOW REPEAT THE TEST...\n" );
      printf ( "\n" );
      printf ( "  but use too few digits to represent big products.\n" );
      printf ( "  This corresponds to an \"overflow\".\n" );
      printf ( "  The result here should get the final decimal\n" );
      printf ( "  digits correctly, though.\n" );
    }

    printf ( "\n" );
    printf ( "        I        J        K = I * J\n" );
    printf ( "\n" );

    for ( test = 1; test <= test_num; test++ )
    { 
      i = i4_uniform_ab ( -1000, 1000, &seed );
      j = i4_uniform_ab ( -1000, 1000, &seed );

      printf ( "\n" );
      printf ( "  %8d  %8d\n", i, j );

      k = i * j;

      printf ( "  Directly:           %8d\n", k );

      i4_to_dvec ( i, n2, dvec1 );
      i4_to_dvec ( j, n2, dvec2 );

      dvec_mul ( n2, dvec1, dvec2, dvec3 );
      k = dvec_to_i4 ( n2, dvec3 );

      printf ( "  DVEC_MUL            %8d\n", k );
    }
  }
  return;
# undef N
}
/******************************************************************************/

void dvec_print_test ( )

/******************************************************************************/
/*
  Purpose:

    DVEC_PRINT_TEST tests DVEC_PRINT;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 May 2015

  Author:

    John Burkardt
*/
{
  int dvec[20] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    3, 4, 1, 7, 7, 5, 5, 0, 0, 9 };
  int n = 20;

  printf ( "\n" );
  printf ( "DVEC_PRINT_TEST\n" );
  printf ( "  DVEC_PRINT prints a (signed) decimal vector;\n" );

  dvec_print ( n, dvec, "  The DVEC:" );

  return;
}
/******************************************************************************/

void dvec_sub_test ( )

/******************************************************************************/
/*
  Purpose:

    DVEC_SUB_TEST tests DVEC_SUB;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 February 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int dvec1[N];
  int dvec2[N];
  int dvec4[N];
  int i;
  int j;
  int k;
  int l;
  int seed = 123456789;
  int test;
  int test_num = 10;

  printf ( "\n" );
  printf ( "DVEC_SUB_TEST\n" );
  printf ( "  DVEC_SUB subtracts decimal vectors representing integers;\n" );
  printf ( "\n" );
  printf ( "        I        J        I - J    DVEC_SUB\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  { 
    i = i4_uniform_ab ( -100, 100, &seed );
    j = i4_uniform_ab ( -100, 100, &seed );

    k = i - j;

    i4_to_dvec ( i, N, dvec1 );
    i4_to_dvec ( j, N, dvec2 );
    dvec_sub ( N, dvec1, dvec2, dvec4 );
    l = dvec_to_i4 ( N, dvec4 );

    printf ( "  %8d  %8d  %8d  %8d\n", i, j, k, l );
  }

  return;
# undef N
}
/******************************************************************************/

void dvec_to_i4_test ( )

/******************************************************************************/
/*
  Purpose:

    DVEC_TO_I4_TEST tests DVEC_TO_I4;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2015

  Author:

    John Burkardt
*/
{
  int dvec[6];
  int i;
  int i1;
  int i2;
  int n;
  int seed;

  printf ( "\n" );
  printf ( "DVEC_TO_I4_TEST\n" );
  printf ( "  DVEC_TO_I4 converts a DVEC to an I4;\n" );
  printf ( "\n" );
  printf ( "        I4 => DVEC => I4\n" );
  printf ( "\n" );

  seed = 123456789;
  i1 = i4_uniform_ab ( -10000, 10000, &seed );

  n = 6;
  i4_to_dvec ( i1, n, dvec );

  i2 = dvec_to_i4 ( n, dvec );

  printf ( "  %6d  ", i1 );
  for  ( i = n - 1; 0 <= i; i-- )
  {
    printf ( "%2d", dvec[i] );
  }
  printf ( "  %6d\n", i2 );

  return;
}
/******************************************************************************/

void equiv_next_test ( )

/******************************************************************************/
/*
  Purpose:

    EQUIV_NEXT_TEST tests EQUIV_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 February 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int a[N];
  int i;
  int jarray[N];
  int more;
  int npart;
  int rank;

  printf ( "\n" );
  printf ( "EQUIV_NEXT_TEST\n" );
  printf ( "  EQUIV_NEXT generates all partitions of a set.\n" );
  printf ( "\n" );
  printf ( "  Rankelement:\n" );
  printf ( "\n" );
  printf ( "   ");
  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %2d", i );
  }
  printf ( "\n" );
  printf ( "\n" );
 
  rank = 0;
  more = 0;
 
  for ( ; ; )
  {
    equiv_next ( N, &npart, jarray, a, &more );
 
    rank = rank + 1;

    printf ( "  %2d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "  %2d", a[i] );
    }
    printf ( "\n" );
 
    if ( !more )
    {
      break;
    }

  }

  return;
# undef N
}
/******************************************************************************/

void equiv_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    EQUIV_NEXT2_TEST tests EQUIV_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 February 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int a[N];
  int done;
  int i;
  int rank;

  printf ( "\n" );
  printf ( "EQUIV_NEXT2_TEST\n" );
  printf ( "  EQUIV_NEXT2 generates all partitions of a set.\n" );
  printf ( "\n" );
  printf ( "  Rankelement:\n" );
  printf ( "\n" );
  printf ( "    " );
  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %2d", i );
  }
  printf ( "\n" );
  printf ( "\n" );
 
  rank = 0;
  done = 1;
 
  for ( ; ; )
  {
    equiv_next2 ( &done, a, N );

    if ( done )
    {
      break;
    }

    rank = rank + 1;

    printf ( "  %2d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "  %2d", a[i] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void equiv_print_test ( )

/******************************************************************************/
/*
  Purpose:

    EQUIV_PRINT_TEST tests EQUIV_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2015

  Author:

    John Burkardt
*/
{
  int a[4];
  int i;
  int n = 4;
  int npart;
  int seed;

  printf ( "\n" );
  printf ( "EQUIV_PRINT_TEST\n" );
  printf ( "  EQUIV_PRINT prints a set partition.\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    equiv_random ( n, &seed, &npart, a );

    equiv_print ( n, a, "  The partition:" );
  }

  return;
}
/******************************************************************************/

void equiv_print2_test ( )

/******************************************************************************/
/*
  Purpose:

    EQUIV_PRINT2_TEST tests EQUIV_PRINT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2015

  Author:

    John Burkardt
*/
{
  int a[4];
  int i;
  int n = 4;
  int npart;
  int seed;

  printf ( "\n" );
  printf ( "EQUIV_PRINT2_TEST\n" );
  printf ( "  EQUIV_PRINT2 prints a set partition.\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    equiv_random ( n, &seed, &npart, a );

    equiv_print2 ( n, a, "  The partition:" );
  }

  return;
}
/******************************************************************************/

void equiv_random_test ( )

/******************************************************************************/
/*
  Purpose:

    EQUIV_RANDOM_TEST tests EQUIV_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 February 2014

  Author:

    John Burkardt
*/
{
  int a[4];
  int i;
  int n = 4;
  int npart;
  int seed;

  printf ( "\n" );
  printf ( "EQUIV_RANDOM_TEST\n" );
  printf ( "  EQUIV_RANDOM selects a random set partition.\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    equiv_random ( n, &seed, &npart, a );

    equiv_print ( n, a, "  The partition:" );
  }

  return;
}
/******************************************************************************/

void euler_row_test ( )

/******************************************************************************/
/*
  Purpose:

    EULER_ROW_TEST tests EULER_ROW.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 June 2015

  Author:

    John Burkardt
*/
{
# define N_MAX 9

  int i;
  int ieuler[N_MAX+1];
  int n;

  printf ( "\n" );
  printf ( "EULER_ROW_TEST\n" );
  printf ( "  EULER_ROW gets rows of the Euler triangle.\n" );
  printf ( "\n" );

  for ( n = 0; n <= N_MAX; n++ )
  {
    euler_row ( n, ieuler );

    for ( i = 0; i <= n; i++ )
    {
      printf ( "  %7d", ieuler[i] );
    }
    printf ( "\n" );
  }
 
  return;
# undef N_MAX
}
/******************************************************************************/

void frobenius_number_order2_test ( )

/******************************************************************************/
/*
  Purpose:

   FROBENIUS_NUMBER_ORDER2_TEST tests FROBENIUS_NUMBER_ORDER2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 February 2014

  Author:

    John Burkardt
*/
{
  int c1;
  int c2;
  int f1;
  int f2;
  int n_data;

  printf ( "\n" );
  printf ( "FROBENIUS_NUMBER_ORDER2_TEST\n" );
  printf ( "  FROBENIUS_NUMBER_ORDER2 computes Frobenius numbers of order 2.\n" );
  printf ( "\n" );
  printf ( "        C1        C1   exact F  comput F\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    frobenius_number_order2_values ( &n_data, &c1, &c2, &f1 );

    if ( n_data == 0 )
    {
      break;
    }

    f2 = frobenius_number_order2 ( c1, c2 );

    printf ( "  %8d  %8d  %8d  %8d\n", c1, c2, f1, f2 );
  }
  return;
}
/******************************************************************************/

void gray_next_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_NEXT_TEST tests GRAY_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int a[4];
  int change;
  int g[4];
  int i;
  int k;
  int n = 4;

  printf ( "\n" );
  printf ( "GRAY_NEXT_TEST\n" );
  printf ( "  GRAY_NEXT returns the index of the single item\n" );
  printf ( "  to be changed in order to get the next Gray code.\n" );

  printf ( "\n" );
  printf ( "   K  Switch  Gray Code\n" );
  printf ( "\n" );

  change = -n;

  for ( ; ; )
  {
    gray_next ( n, &change, &k, a );

    if ( change == -n )
    {
      break;
    }
    else if ( change == 0 )
    {
      for ( i = 0; i < n; i++ )
      {
        g[i] = 0;
      }
    }
    else
    {
      g[abs(change)-1] = 1 - g[abs(change)-1];
    }

    printf ( "  %2d  %6d  ", k, change );
    for ( i = 0; i < n; i++ )
    {
      printf ( "%d", g[i] );
    }
    printf ( "\n" );    
  }

  return;
}
/******************************************************************************/

void gray_rank_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_RANK_TEST tests GRAY_RANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 February 2014

  Author:

    John Burkardt
*/
{
  int gray;
  int rank;
  int rank2;

  printf ( "\n" );
  printf ( "GRAY_RANK_TEST\n" );
  printf ( "  GRAY_RANK ranks a Gray code;\n" );
  printf ( "\n" );
  printf ( "    R  =                        RANK\n" );
  printf ( "    G  =            GRAY_UNRANK(RANK)\n" );
  printf ( "    R2 =  GRAY_RANK(GRAY_UNRANK(RANK))\n" );
  printf ( "\n" );
  printf ( "    R    G    R2\n" );
  printf ( "\n" );
 
  for ( rank = 0; rank <= 24; rank++ )
  {
    gray = gray_unrank ( rank );

    rank2 = gray_rank ( gray );

    printf ( "%9d  %9d  %9d\n", rank, gray, rank2 );
  }
 
  return;
}
/******************************************************************************/

void gray_rank2_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_RANK2_TEST tests GRAY_RANK2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 February 2014

  Author:

    John Burkardt
*/
{
  int gray;
  int rank;
  int rank2;

  printf ( "\n" );
  printf ( "GRAY_RANK2_TEST\n" );
  printf ( "  GRAY_RANK2 ranks a Gray code;\n" );
  printf ( "\n" );
  printf ( "    R  =                          RANK\n" );
  printf ( "    G  =             GRAY_UNRANK2(RANK)\n" );
  printf ( "    R2 =  GRAY_RANK2(GRAY_UNRANK2(RANK))\n" );
  printf ( "\n" );
  printf ( "    R    G    R2\n" );
  printf ( "\n" );
 
  for ( rank = 0; rank <= 24; rank++ )
  {
    gray = gray_unrank2 ( rank );

    rank2 = gray_rank2 ( gray );

    printf ( "%9d  %9d  %9d\n", rank, gray, rank2 );
  }
 
  return;
}
/******************************************************************************/

void gray_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_UNRANK_TEST tests GRAY_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 February 2014

  Author:

    John Burkardt
*/
{
  int gray;
  int rank;
  int rank2;

  printf ( "\n" );
  printf ( "GRAY_UNRANK_TEST\n" );
  printf ( "  GRAY_UNRANK unranks a Gray code.\n" );
  printf ( "\n" );
  printf ( "    R  =                        RANK\n" );
  printf ( "    G  =            GRAY_UNRANK(RANK)\n" );
  printf ( "    R2 =  GRAY_RANK(GRAY_UNRANK(RANK))\n" );
  printf ( "\n" );
  printf ( "    R    G    R2\n" );
  printf ( "\n" );
 
  for ( rank = 0; rank <= 24; rank++ )
  {
    gray = gray_unrank ( rank );

    rank2 = gray_rank ( gray );

    printf ( "%9d  %9d  %9d\n", rank, gray, rank2 );
  }
 
  return;
}
/******************************************************************************/

void gray_unrank2_test ( )

/******************************************************************************/
/*
  Purpose:

    GRAY_UNRANK2_TEST tests GRAY_UNRANK2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 February 2014

  Author:

    John Burkardt
*/
{
  int gray;
  int rank;
  int rank2;

  printf ( "\n" );
  printf ( "GRAY_UNRANK2_TEST\n" );
  printf ( "  GRAY_UNRANK2 unranks a Gray code.\n" );
  printf ( "\n" );
  printf ( "    R  =                          RANK\n" );
  printf ( "    G  =             GRAY_UNRANK2(RANK)\n" );
  printf ( "    R2 =  GRAY_RANK2(GRAY_UNRANK2(RANK))\n" );
  printf ( "\n" );
  printf ( "    R    G    R2\n" );
  printf ( "\n" );
 
  for ( rank = 0; rank <= 24; rank++ )
  {
    gray = gray_unrank2 ( rank );

    rank2 = gray_rank2 ( gray );

    printf ( "%9d  %9d  %9d\n", rank, gray, rank2 );
  }
 
  return;
}
/******************************************************************************/

void i4_bclr_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_BCLR_TEST tests I4_BCLR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2015

  Author:

    John Burkardt
*/
{
  int i4;
  int i4_test[2] = { 101, -31 };
  int j;
  int pos;
  int test;
  int test_num = 2;

  printf ( "\n" );
  printf ( "I4_BCLR_TEST\n" );
  printf ( "  I4_BCLR sets a given bit to 0.\n" );

  for ( test = 0; test < test_num; test++ )
  {
    i4 = i4_test[test];

    printf ( "\n" );
    printf ( "  Working on I4 = %d\n", i4 );
    printf ( "\n" );
    printf ( "       Pos     I4_BCLR(I4,POS)\n" );
    printf ( "\n" );

    for ( pos = 0; pos < 32; pos++ )
    {
      j = i4_bclr ( i4, pos );

      printf ( "  %8d  %12d\n", pos, j );
    }
  }

  return;
}
/******************************************************************************/

void i4_bset_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_BSET_TEST tests I4_BSET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 June 2015

  Author:

    John Burkardt
*/
{
  int i4;
  int i4_test[2] = { 101, -31 };
  int j;
  int pos;
  int test;
  int test_num = 2;

  printf ( "\n" );
  printf ( "I4_BSET_TEST\n" );
  printf ( "  I4_BSET sets a given bit to 1.\n" );

  for ( test = 0; test < test_num; test++ )
  {
    i4 = i4_test[test];

    printf ( "\n" );
    printf ( "  Working on I4 = %d\n", i4 );
    printf ( "\n" );
    printf ( "       Pos     I4_BSET(I4,POS)\n" );
    printf ( "\n" );

    for ( pos = 0; pos < 32; pos++ )
    {
      j = i4_bset ( i4, pos );

      printf ( "  %8d  %12d\n", pos, j );
    }
  }

  return;
}
/******************************************************************************/

void i4_btest_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_BTEST_TEST tests I4_BTEST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  int i4;
  int i4_test[2] = { 101, -31 };
  int j;
  int pos;
  int test;

  printf ( "\n" );
  printf ( "I4_BTEST_TEST\n" );
  printf ( "  I4_BTEST reports whether a given bit is 0 or 1.\n" );

  for ( test = 0; test < 2; test++ )
  {
    i4 = i4_test[test];

    printf ( "\n" );
    printf ( "  Analyze the integer I4 = %d\n", i4 );
    printf ( "\n" );
    printf ( "       Pos     I4_BTEST(I4,POS)\n" );
    printf ( "\n" );

    for ( pos = 0; pos <= 31; pos++ )
    {
      j = i4_btest ( i4, pos );

      printf ( "  %8d  %8d\n", pos, j );
    }
  }

  return;
}
/******************************************************************************/

void i4_choose_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_CHOOSE_TEST tests I4_CHOOSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2014

  Author:

    John Burkardt
*/
{
  int cnk;
  int k;
  int n;

  printf ( "\n" );
  printf ( "I4_CHOOSE_TEST\n" );
  printf ( "  I4_CHOOSE evaluates C(N,K).\n" );
  printf ( "\n" );
  printf ( "       N       K     CNK\n" );

  for ( n = 0; n <= 4; n++ )
  {
    printf ( "\n" );
    for ( k = 0; k <= n; k++ )
    {
      cnk = i4_choose ( n, k );

      printf ( "  %6d  %6d  %6d\n", n, k, cnk );
    }
  }

  return;
}
/******************************************************************************/

void i4_factor_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_FACTOR_TEST tests I4_FACTOR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 February 2014

  Author:

    John Burkardt
*/
{
# define FACTOR_MAX 10

  int factor[FACTOR_MAX];
  int factor_num;
  int i;
  int n;
  int nleft;
  int power[FACTOR_MAX];

  printf ( "\n" );
  printf ( "I4_FACTOR_TEST\n" );
  printf ( "  I4_FACTOR factors an integer,\n" );

  n = 2 * 2 * 17 * 37;

  printf ( "\n" );
  printf ( "  The integer is %d\n", n );

  i4_factor ( n, FACTOR_MAX, &factor_num, factor, power, &nleft );

  printf ( "\n" );
  printf ( "  Prime representation:\n" );
  printf ( "\n" );
  printf ( "  I  FACTOR(I)  POWER(I)\n" );
  printf ( "\n" );

  if ( abs ( nleft ) != 1 )
  {
    printf ( "  %6d  %6d  (Unfactored portion)\n", 0, nleft );
  }

  for ( i = 0; i < factor_num; i++ )
  {
    printf ( "  %6d  %6d  %6d\n", i+1, factor[i], power[i] );
  }
 
  return;
# undef FACTOR_MAX
}
/******************************************************************************/

void i4_fall_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_FALL_TEST tests I4_FALL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 December 2014

  Author:

    John Burkardt
*/
{
  int f1;
  int f2;
  int m;
  int n;
  int n_data;

  printf ( "\n" );
  printf ( "I4_FALL_TEST\n" );
  printf ( "  I4_FALL evaluates the falling factorial function.\n" );
  printf ( "\n" );
  printf ( "         M         N     Exact  I4_Fall(M,N)\n" );

  n_data = 0;

  while ( 1 )
  {
    i4_fall_values ( &n_data, &m, &n, &f1 );

    if ( n_data == 0 )
    {
      break;
    }

    f2 = i4_fall ( m, n );

    printf ( "  %8d  %8d  %8d  %8d\n", m, n, f1, f2 );

  }
 
  return;
}
/******************************************************************************/

void i4_gcd_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_GCD_TEST tests I4_GCD.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2010

  Author:

    John Burkardt
*/
{
# define TEST_NUM 7

  int i;
  int i_test[TEST_NUM] = { 36, 49, 0, 12, 36, 1, 91 };
  int j;
  int j_test[TEST_NUM] = { 30, -7, 71, 12, 49, 42, 28 };
  int test;

  printf ( "\n" );
  printf ( "I4_GCD_TEST\n" );
  printf ( "  I4_GCD computes the greatest common divisor of two I4s\n" );
  printf ( "\n" );
  printf ( "     I     J   I4_GCD\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    i = i_test[test];
    j = j_test[test];
    printf ( "  %6d  %6d  %6d\n", i, j, i4_gcd ( i, j ) );
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void i4_huge_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_HUGE_TEST tests I4_HUGE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 January 2007

  Author:

    John Burkardt
*/
{
  printf ( "\n" );
  printf ( "I4_HUGE_TEST\n" );
  printf ( "  I4_HUGE returns a huge integer.\n" );
  printf ( "\n" );
  printf ( "  I4_HUGE() = %d\n", i4_huge ( ) );

  return;
}
/******************************************************************************/

void i4_log_10_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_LOG_10_TEST tests I4_LOG_10.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 February 2014

  Author:

    John Burkardt
*/
{
# define N 21

  int i;
  int x[N] = {
    0, 1, 2, 3, 9, 10, 11, 99, 100, 101, 999, 1000, 1001,
   -1, -2, -3, -9, -10, -11, -99, -101 };

  printf ( "\n" );
  printf ( "I4_LOG_10_TEST\n" );
  printf ( "  I4_LOG_10: whole part of log base 10,\n" );
  printf ( "\n" );
  printf ( "     X I4_LOG_10\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%6d  %6d\n", x[i], i4_log_10 ( x[i] ) );
  }

  return;
# undef N
}
/******************************************************************************/

void i4_modp_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_MODP_TEST tests I4_MODP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 July 2010

  Author:

    John Burkardt
*/
{
# define TEST_NUM 4

  int ndivid[TEST_NUM] = { 50, -50, 50, -50 };
  int nmult;
  int nrem;
  int number[TEST_NUM] = { 107, 107, -107, -107 };
  int test;

  printf ( "\n" );
  printf ( "I4_MODP_TEST\n" );
  printf ( "  I4_MODP factors a number\n" );
  printf ( "  into a multiple and a remainder.\n" );
  printf ( "\n" );
  printf ( "    Number   Divisor  Multiple Remainder\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    nrem = i4_modp ( number[test], ndivid[test] );
    nmult = number[test] / ndivid[test];

    printf ( "  %10d  %10d  %10d  %10d\n",
      number[test], ndivid[test], nmult, nrem );
  }

  printf ( "\n" );
  printf ( "  Repeat using C percent operator:\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    nrem = ( number[test] % ndivid[test] );
    nmult = number[test] / ndivid[test];

    printf ( "  %10d  %10d  %10d  %10d\n",
      number[test], ndivid[test], nmult, nrem );
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void i4_moebius_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_MOEBIUS_TEST tests I4_MOEBIUS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 May 2015

  Author:

    John Burkardt
*/
{
  int c1;
  int c2;
  int n;
  int n_data;

  printf ( "\n" );
  printf ( "I4_MOEBIUS_TEST\n" );
  printf ( "  I4_MOEBIUS evaluates the Moebius function.\n" );
  printf ( "\n" );
  printf ( "         N     Exact  I4_Moebius(N)\n" );

  n_data = 0;

  while ( 1 )
  {
    moebius_values ( &n_data, &n, &c1 );

    if ( n_data == 0 )
    {
      break;
    }

    c2 = i4_moebius ( n );

    printf ( "  %8d  %8d  %8d\n", n, c1, c2 );
  }
 
  return;
}
/******************************************************************************/

void i4_partition_conj_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_CONJ_TEST tests I4_PARTITION_CONJ.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 February 2014

  Author:

    John Burkardt
*/
{
# define N 14
# define NPART1 4

  int a1[NPART1] = { 2, 5, 1, 4 };
  int a2[N];
  int mult1[NPART1] = { 1, 1, 3, 1 };
  int mult2[N];
  int npart2;

  printf ( "\n" );
  printf ( "I4_PARTITION_CONJ_TEST\n" );
  printf ( "  I4_PARTITION_CONJ conjugates an integer partition.\n" );
  printf ( "\n" );
  printf ( "  Original partition:\n" );
  printf ( "\n" );

  i4_partition_print ( N, NPART1, a1, mult1 );

  i4_partition_conj ( N, a1, mult1, NPART1, a2, mult2, &npart2 );

  printf ( "\n" );
  printf ( "  Conjugate partition:\n" );
  printf ( "\n" );

  i4_partition_print ( N, npart2, a2, mult2 );

  return;
# undef N
# undef NPART1
}
/******************************************************************************/

void i4_partition_count_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_COUNT_TEST tests I4_PARTITION_COUNT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 February 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 20

  int n;
  int n_data;
  int p;
  int p2[N_MAX+1];

  printf ( "\n" );
  printf ( "I4_PARTITION_COUNT_TEST\n" );
  printf ( "  I4_PARTITION_COUNT counts partitions of an integer.\n" );

  n_data = 0;

  printf ( "\n" );
  printf ( "   N     Exact     Count\n" );
  printf ( "\n" );

  for ( ; ; )
  {
    i4_partition_count_values ( &n_data, &n, &p );

    if ( n_data == 0 )
    {
      break;
    }

    printf ( "%4d  %10d\n", n, p );

    if ( n <= N_MAX )
    {
      i4_partition_count ( n, p2 );
      printf ( "%10d", p2[n] );
    }

    printf ( "\n" );

  }

  return;
# undef N_MAX
}
/******************************************************************************/

void i4_partition_count2_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_COUNT2_TEST tests I4_PARTITION_COUNT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 20

  int n;
  int n_data;
  int p;
  int *p2;

  printf ( "\n" );
  printf ( "I4_PARTITION_COUNT2_TEST\n" );
  printf ( "  I4_PARTITION_COUNT2 counts partitions of an integer.\n" );

  n_data = 0;

  printf ( "\n" );
  printf ( "   N     Exact     Count\n" );
  printf ( "\n" );

  for ( ; ; )
  {
    i4_partition_count_values ( &n_data, &n, &p );

    if ( n_data == 0 )
    {
      break;
    }

    printf ( "  %4d  %10d  ", n, p );

    if ( n <= N_MAX )
    {
      p2 = i4_partition_count2 ( n );
      printf ( "        %10d", p2[n] );
      free ( p2 );
    }
    printf ( "\n" );
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void i4_partition_next_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_NEXT_TEST tests I4_PARTITION_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 February 2014

  Author:

    John Burkardt
*/
{
# define N 7

  int a[N];
  int done;
  int mult[N];
  int npart;
  int rank;

  printf ( "\n" );
  printf ( "I4_PARTITION_NEXT_TEST\n" );
  printf ( "  I4_PARTITION_NEXT generates partitions of an integer.\n" );
  printf ( "  Here N = %d\n", N );
  printf ( "\n" );

  rank = 0;
  done = 1;
 
  for ( ; ; )
  {
    i4_partition_next ( &done, a, mult, N, &npart );
 
    if ( done )
    {
      break;
    }

    rank = rank + 1;

    i4_partition_print ( N, npart, a, mult );

  }
 
  return;
# undef N
}
/******************************************************************************/

void i4_partition_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_NEXT2_TEST tests I4_PARTITION_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 February 2014

  Author:

    John Burkardt
*/
{
# define N 7

  int a[N];
  int more;
  int mult[N];
  int npart;

  printf ( "\n" );
  printf ( "I4_PARTITION_NEXT2_TEST\n" );
  printf ( "  I4_PARTITION_NEXT2 produces partitions of an integer.\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    i4_partition_next2 ( N, a, mult, &npart, &more );

    i4_partition_print ( N, npart, a, mult );

    if ( !more )
    {
      break;
    }

  }
  
  return;
# undef N
}
/******************************************************************************/

void i4_partition_print_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_PRINT_TEST tests I4_PARTITION_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    29 May 2015

  Author:

    John Burkardt
*/
{
  int a[4] = { 2, 5, 1, 4 };
  int mult[4] = { 1, 1, 3, 1 };
  int n;
  int npart;

  printf ( "\n" );
  printf ( "I4_PARTITION_PRINT_TEST\n" );
  printf ( "  I4_PARTITION_PRINT prints an integer partition.\n" );
  printf ( "\n" );

  n = 14;
  npart = 4;
  i4_partition_print ( n, npart, a, mult );

  return;
}
/******************************************************************************/

void i4_partition_random_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITION_RANDOM_TEST tests I4_PARTITION_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2014

  Author:

    John Burkardt
*/
{
# define N 8

  int a[N];
  int i;
  int j;
  int mult[N];
  int npart;
  int seed;
  int *table;

  printf ( "\n" );
  printf ( "I4_PARTITION_RANDOM_TEST\n" );
  printf ( "  I4_PARTITION_RANDOM generates a random partition.\n" );
  printf ( "\n" );

  seed = 123456789;
/*
  Call once just to get the partition table.
*/
  table = i4_partition_count2 ( N );

  printf ( "\n" );
  printf ( "  The number of partitions of N.\n" );
  printf ( "\n" );
  printf ( "     N    Number of partitions\n" );
  printf ( "\n" );

  for ( j = 0; j < N; j++ )
  {
    printf ( "%6d  %6d\n", j+1, table[j] );
  }

  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    i4_partition_random ( N, table, &seed, a, mult, &npart );

    i4_partition_print ( N, npart, a, mult );
  }
 
  free ( table );

  return;
# undef N
}
/******************************************************************************/

void i4_partitions_next_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_PARTITIONS_NEXT_TEST tests I4_PARTITIONS_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 August 2010

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int m[3];
  int msum;
  int s = 3;

  printf ( "\n" );
  printf ( "I4_PARTITIONS_NEXT_TEST\n" );
  printf ( "  I4_PARTITIONS_NEXT produces the next\n" );
  printf ( "  nondecreasing partitions of an integer, and\n" );
  printf ( "  if necessary, increments the integer to keep on going.\n" );

  i = 0;
  m[0] = 0;
  m[1] = 0;
  m[2] = 0;

  printf ( "\n" );
  printf ( "   I Sum    Partition\n" );
  printf ( "\n" );
  msum = i4vec_sum ( s, m );
  printf ( "  %2d  %2d    ", i, msum );
  for ( j = 0; j < s; j++ )
  {
    printf ( "%2d", m[j] );
  }
  printf ( "\n" );

  for ( i = 1; i <= 15; i++ )
  {
    i4_partitions_next ( s, m );
    msum = i4vec_sum ( s, m );
    printf ( "  %2d  %2d    ", i, msum );
    for ( j = 0; j < s; j++ )
    {
      printf ( "%2d", m[j] );
    }
    printf ( "\n" );
  }
  printf ( "\n" );
  printf ( "  You can start from any legal partition.\n" );
  printf ( "  Here, we restart at ( 2, 1, 0 ).\n" );

  i = 0;
  m[0] = 2;
  m[1] = 1;
  m[2] = 0;

  printf ( "\n" );
  printf ( "   I Sum    Partition\n" );
  printf ( "\n" );
  msum = i4vec_sum ( s, m );
  printf ( "  %2d  %2d    ", i, msum );
  for ( j = 0; j < s; j++ )
  {
    printf ( "%2d", m[j] );
  }
  printf ( "\n" );

  for ( i = 1; i <= 15; i++ )
  {
    i4_partitions_next ( s, m );
    msum = i4vec_sum ( s, m );
    printf ( "  %2d  %2d    ", i, msum );
    for ( j = 0; j < s; j++ )
    {
      printf ( "%2d", m[j] );
    }
    printf ( "\n" );
  }
  return;
}
/******************************************************************************/

void i4_rise_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_RISE_TEST tests I4_RISE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 December 2014

  Author:

    John Burkardt
*/
{
  int f1;
  int f2;
  int m;
  int n;
  int n_data;

  printf ( "\n" );
  printf ( "I4_RISE_TEST\n" );
  printf ( "  I4_RISE evaluates the rising factorial function.\n" );
  printf ( "\n" );
  printf ( "         M         N     Exact    I4_RISE(M,N)\n" );

  n_data = 0;

  while ( 1 )
  {
    i4_rise_values ( &n_data, &m, &n, &f1 );

    if ( n_data == 0 )
    {
      break;
    }

    f2 = i4_rise ( m, n );

    printf ( "  %8d  %8d  %8d  %8d\n", m, n, f1, f2 );

  }
 
  return;
}
/******************************************************************************/

void i4_sqrt_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_SQRT_TEST tests I4_SQRT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 February 2014

  Author:

    John Burkardt
*/
{
  int n;
  int q;
  int r;

  printf ( "\n" );
  printf ( "I4_SQRT_TEST\n" );
  printf ( "  I4_SQRT computes the square root of an integer.\n" );
  printf ( "\n" );
  printf ( "       N  Sqrt(N) Remainder\n" );
  printf ( "\n" );

  for ( n = -5; n <= 20; n++ )
  {
    i4_sqrt ( n, &q, &r );

    printf ( "%9d  %9d  %9d\n", n, q, r );
  }

  return;
}
/******************************************************************************/

void i4_sqrt_cf_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_SQRT_CF_TEST tests I4_SQRT_CF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 February 2014

  Author:

    John Burkardt
*/
{
# define MAX_TERM 100

  int b[MAX_TERM+1];
  int i;
  int n;
  int n_term;

  printf ( "\n" );
  printf ( "I4_SQRT_CF_TEST\n" );
  printf ( "  I4_SQRT_CF computes the continued fraction form\n" );
  printf ( "  of the square root of an integer.\n" );
  printf ( "\n" );
  printf ( "   N  Period  Whole  Repeating Part\n" );
  printf ( "\n" );

  for ( n = 1; n <= 20; n++ )
  {
    i4_sqrt_cf ( n, MAX_TERM, &n_term, b );
    printf ( "%5d  %5d", n, n_term );
    for ( i = 0; i <= n_term; i++ )
    {
      printf ( "  %5d", b[i] );
    }
    printf ( "\n" );
  }

  return;
# undef MAX_TERM
}
/******************************************************************************/

void i4_to_chinese_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_TO_CHINESE_TEST tests I4_TO_CHINESE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int j;
  int j2;
  int m[N] = { 3, 4, 5, 7 };
  int r[N];

  printf ( "\n" );
  printf ( "I4_TO_CHINESE_TEST\n" );
  printf ( "  I4_TO_CHINESE computes the Chinese Remainder\n" );
  printf ( "  representation of an integer.\n" );

  i4vec1_print ( N, m, "  The moduli:" );

  j = 37;

  printf ( "\n" );
  printf ( "  The number being analyzed is %d\n", j );

  i4_to_chinese ( j, N, m, r );

  i4vec1_print ( N, r, "  The remainders:" );

  j2 = chinese_to_i4 ( N, m, r );

  printf ( "\n" );
  printf ( "  The reconstructed number is %d\n", j2 );

  i4_to_chinese ( j2, N, m, r );

  i4vec1_print ( N, r, "  The remainders of the reconstructed number are:" );

  return;
# undef N
}
/******************************************************************************/

void i4_to_dvec_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_TO_DVEC_TEST tests I4_TO_DVEC;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2015

  Author:

    John Burkardt
*/
{
  int dvec[6];
  int i;
  int i1;
  int i2;
  int n;
  int seed;

  printf ( "\n" );
  printf ( "I4_TO_DVEC_TEST\n" );
  printf ( "  I4_TO_DVEC converts a DVEC to an I4;\n" );
  printf ( "\n" );
  printf ( "        I4 => DVEC => I4\n" );
  printf ( "\n" );

  seed = 123456789;
  i1 = i4_uniform_ab ( -10000, 10000, &seed );

  n = 6;
  i4_to_dvec ( i1, n, dvec );

  i2 = dvec_to_i4 ( n, dvec );

  printf ( "  %6d  ", i1 );
  for  ( i = n - 1; 0 <= i; i-- )
  {
    printf ( "%2d", dvec[i] );
  }
  printf ( "  %6d\n", i2 );

  return;
}
/******************************************************************************/

void i4_to_i4poly_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_TO_I4POLY_TEST tests I4_TO_I4POLY;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2014

  Author:

    John Burkardt
*/
{
# define DEGREE_MAX 5
# define TEST_NUM 9

  int a[DEGREE_MAX+1];
  int base;
  int base_test[TEST_NUM] = { 2, 2, 2, 3, 4, 5, 6, 23, 24 };
  int degree;
  int i;
  int intval;
  int intval2;
  int intval_test[TEST_NUM] = { 1, 6, 23, 23, 23, 23, 23, 23, 23 };
  int test;

  printf ( "\n" );
  printf ( "I4_TO_I4POLY_TEST\n" );
  printf ( "  I4_TO_I4POLY converts an integer to a polynomial\n" );
  printf ( "  in a given base;\n" );
  printf ( "\n" );
  printf ( "       I    BASE  DEGREE  Coefficients\n" );
  printf ( "\n" );
  for ( test = 0; test < TEST_NUM; test++ )
  {
    intval = intval_test[test];
    base = base_test[test];
    i4_to_i4poly ( intval, base, DEGREE_MAX, &degree, a );
    printf ( "  %6d  %6d  %6d\n", intval, base, degree );
    for ( i = 0; i <= degree; i++ )
    {
      printf ( "  %6d", a[i] );
    }
    printf ( "\n" );
  }
  printf ( "\n" );
  printf ( "  Now let I4_TO_I4POLY convert I to a polynomial,\n" );
  printf ( "  use I4POLY_TO_I4 to evaluate it, and compare.\n" );
  printf ( "\n" );
  printf ( "       I    I2\n" );
  printf ( "\n" );
  for ( test = 0; test < TEST_NUM; test++ )
  {
    intval = intval_test[test];
    base = base_test[test];
    i4_to_i4poly ( intval, base, DEGREE_MAX, &degree, a );
    intval2 = i4poly_to_i4 ( degree, a, base );
    printf ( "  %6d  %6d\n", intval, intval2 );
  }

  return;

# undef DEGREE_MAX
# undef TEST_NUM
}
/******************************************************************************/

void i4_to_van_der_corput_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_TO_VAN_DER_CORPUT_TEST tests I4_TO_VAN_DER_CORPUT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2014

  Author:

    John Burkardt
*/
{
  double h;
  int i;
  int j;
  int p;

  printf ( "\n" );
  printf ( "I4_TO_VAN_DER_CORPUT_TEST\n" );
  printf ( "  I4_TO_VAN_DER_CORPUT computes the elements \n" );
  printf ( "  of a van der Corput sequence.\n" );
  printf ( "  The sequence depends on the prime number used\n" );
  printf ( "  as a base.\n" );
  printf ( "\n" );
  printf ( "Base: " );
  for ( j = 1; j <= 5; j++ )
  {
    p = prime ( j );
    printf ( "%10d  ", p );
  }
  printf ( "\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    printf ( "%4d  ", i );
    for ( j = 1; j <= 5; j++ )
    {
      p = prime ( j );
      h = i4_to_van_der_corput ( i, p );
      printf ( "%10g  ", h );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void i4mat_01_rowcolsum_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_01_ROWCOLSUM_TEST tests I4MAT_01_ROWCOLSUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 February 2014

  Author:

    John Burkardt
*/
{
# define M 5
# define N 5

  int a[M*N];
  int c[N] = { 2, 2, 2, 2, 1 };
  int error;
  int r[M] = { 3, 2, 2, 1, 1 };

  printf ( "\n" );
  printf ( "I4MAT_01_ROWCOLSUM_TEST\n" );
  printf ( "  I4MAT_01_ROWCOLSUM constructs a 01 matrix with\n" );
  printf ( "  given row and column sums.\n" );
  
  i4vec1_print ( M, r, "  The rowsum vector:" );
  i4vec1_print ( N, c, "  The columnsum vector: " );

  i4mat_01_rowcolsum ( M, N, r, c, a, &error );

  if ( error )
  {
    printf ( "\n" );
    printf ( "  I4MAT_01_ROWCOLSUM returned error flag.\n" );
  }
  else
  {
    i4mat_print ( M, N, a, "  The rowcolsum matrix:" );
  }

  return;
# undef M
# undef N
}
/******************************************************************************/

void i4mat_u1_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_U1_INVERSE_TEST tests I4MAT_U1_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 February 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int a[N*N] = {
    1, 0, 0, 0, 0, 0, 
    1, 1, 0, 0, 0, 0, 
    0, 0, 1, 0, 0, 0, 
    0, 0, 1, 1, 0, 0, 
    0, 0, 0, 0, 1, 0, 
   75, 0, 0, 0, 1, 1 };
  int  b[N*N];

  printf ( "\n" );
  printf ( "I4MAT_U1_INVERSE_TEST\n" );
  printf ( "  I4MAT_U1_INVERSE inverts a unit upper triangular matrix.\n" );

  i4mat_print ( N, N, a, "  The input matrix:" );

  i4mat_u1_inverse ( N, a, b );

  i4mat_print ( N, N, b, "  The inverse matrix:" );

  return;
# undef N
}
/******************************************************************************/

void i4mat_perm0_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_PERM0_TEST tests I4MAT_PERM0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2014

  Author:

    John Burkardt
*/
{
# define N 9

  int a[N*N];
  int i;
  int j;
  int p[N] = { 1,2,8,5,6,7,4,3,0 };

  printf ( "\n" );
  printf ( "I4MAT_PERM0_TEST\n" );
  printf ( "  I4MAT_PERM0 reorders an integer matrix in place.\n" );
  printf ( "  The rows and columns use the same permutation.\n" );

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*N] = (i+1) * 10 + (j+1);
    }
  }

  i4mat_print ( N, N, a, "  The input matrix:" );
 
  perm0_print ( N, p, "  The row and column permutation:" );
 
  i4mat_perm0 ( N, a, p );
 
  i4mat_print ( N, N, a, "  The permuted matrix:" );
 
  return;
# undef N
}
/******************************************************************************/

void i4mat_2perm0_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_2PERM0_TEST tests I4MAT_2PERM0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 February 2014

  Author:

    John Burkardt
*/
{
# define M 9
# define N 7

  int a[M*N];
  int i;
  int j;
  int p[M] = { 1,2,8,5,6,7,4,3,0 };
  int q[N] = { 2,3,4,5,6,0,1 };

  printf ( "\n" );
  printf ( "I4MAT_2PERM0_TEST\n" );
  printf ( "  I4MAT_2PERM0 reorders an integer matrix in place.\n" );
  printf ( "  Rows and columns use different permutations.\n" );

  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*M] = (i+1) * 10 + (j+1);
    }
  }
 
  i4mat_print ( M, N, a, "  The input matrix:" );
 
  perm0_print ( M, p, "  The row permutation:" );

  perm0_print ( N, q, "  The column permutation:" );
 
  i4mat_2perm0 ( M, N, a, p, q );
 
  i4mat_print ( M, N, a, "  The permuted matrix:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void i4poly_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_TEST test I4POLY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int a[N];
  int iopt;
  int test;
  int val;
  int x0;

  printf ( "\n" );
  printf ( "I4POLY_TEST\n" );
  printf ( "  I4POLY converts between power sum, factorial\n" );
  printf ( "  and Taylor forms, and can evaluate a polynomial\n" );
  printf ( "\n" );
 
  for ( test = 1; test <= 6; test++ )
  {
    if ( test == 1 )
    {
      iopt = -3;
    }
    else if ( test == 2 )
    {
      iopt = -2;
    }
    else if ( test == 3 )
    {
      iopt = -1;
      x0 = 2;
    }
    else if ( test == 4 )
    {
      iopt = 0;
      x0 = 2;
    }
    else if ( test == 5 )
    {
      iopt = 6;
      x0 = 2;
    }
    else if ( test == 6 )
    {
      iopt = 6;
      x0 = -2;
    }

    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 1;

    if ( test == 1 )
    {
      i4vec1_print ( N, a, "  All calls have input A as follows:" );
    }
 
    i4poly ( N, a, x0, iopt, &val );
 
    printf ( "\n" );
    printf ( "  Option IOPT = %d\n", iopt );

    if ( -1 <= iopt )
    {
      printf ( "  X0 = %d\n", x0 );
    }

    if ( iopt == -3 || iopt == -2 || iopt > 0 )
    {
      i4vec1_print ( N, a, "  Output array:" );
    }

    if ( iopt == -1 || iopt == 0 )
    {
      printf ( "  Value = %d\n", val );
    }
 
  }

  return;
# undef N
}
/******************************************************************************/

void i4poly_add_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_ADD_TEST tests I4POLY_ADD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 May 2015

  Author:

    John Burkardt
*/
{
  int a[6] = { 0, 1, 2, 3, 4, 5 };
  int b[6] = { 1, -2, 7, 8, 0, -5 };
  int *c;
  int na = 5;
  int nb = 5;
  int nc;
  int nc2;

  printf ( "\n" );
  printf ( "I4POLY_ADD_TEST\n" );
  printf ( "  I4POLY_ADD adds two polynomials.\n" );

  i4poly_print ( na, a, "  Polynomial A:" );

  i4poly_print ( nb, b, "  Polynomial B:" );

  c = i4poly_add ( na, a, nb, b );

  nc = i4_max ( na, nb );

  nc2 = i4poly_degree ( nc, c );

  i4poly_print ( nc2, c, "  Polynomial C = A+B:" );

  free ( c );

  return;
}
/******************************************************************************/

void i4poly_cyclo_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_CYCLO_TEST tests I4POLY_CYCLO.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 10

  int phi[N_MAX+1];
  int n;

  printf ( "\n" );
  printf ( "I4POLY_CYCLO_TEST\n" );
  printf ( "  I4POLY_CYCLO computes cyclotomic polynomials.\n" );

  for ( n = 0; n <= N_MAX; n++ )
  {
    printf ( "\n" );
    printf ( "  N = %d\n", n );
    printf ( "\n" );

    i4poly_cyclo ( n, phi );

    i4poly_print ( n, phi, "  The cyclotomic polynomial:" );
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void i4poly_degree_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_DEGREE_TEST tests I4POLY_DEGREE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 May 2015

  Author:

    John Burkardt
*/
{
  int a[11] = { 0, 1, 0, 3, 4, 0, 6, 7, 0, 0, 0 };
  int degree;
  int n = 10;

  printf ( "\n" );
  printf ( "I4POLY_DEGREE_TEST\n" );
  printf ( "  I4POLY_DEGREE determines the degree of an I4POLY.\n" );

  i4poly_print ( n, a, "  The polynomial:" );

  degree = i4poly_degree ( n, a );

  printf ( "\n" );
  printf ( "  The polynomial degree is %d\n", degree );

  return;
}
/******************************************************************************/

void i4poly_dif_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_DIF_TEST tests I4POLY_DIF.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 November 2013

  Author:

    John Burkardt
*/
{
  int a[11];
  int *b;
  int d;
  int na;
  int test_num = 2;
  int test;

  printf ( "\n" );
  printf ( "I4POLY_DIF_TEST\n" );
  printf ( "  I4POLY_DIF computes derivatives of an I4POLY.\n" );
  printf ( "\n" );
/*
  1: Differentiate X^3 + 2*X^2 - 5*X - 6 once.
  2: Differentiate X^4 + 3*X^3 + 2*X^2 - 2  3 times.
*/
  for ( test = 1; test <= test_num; test++ )
  {
    if ( test == 1 )
    {
      na = 3;
      d = 1;
      a[0] = -6;
      a[1] = -5;
      a[2] = 2;
      a[3] = 1;
    }
    else if ( test == 2 )
    {
      na = 4;
      d = 3;
      a[0] = -2;
      a[1] = 5;
      a[2] = 2;
      a[3] = 3;
      a[4] = 1;
    }

    i4poly_print ( na, a, "  The polynomial A:" );

    printf ( "\n" );
    printf ( "  Differentiate A %d times.\n", d );

    b = i4poly_dif ( na, a, d );
    i4poly_print ( na - d, b, "  The derivative, B:" );
    free ( b );
  }

  return;
}
/******************************************************************************/

void i4poly_div_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_DIV_TEST tests I4POLY_DIV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2014

  Author:

    John Burkardt
*/
{
  int a[11];
  int b[11];
  int na;
  int nb;
  int nq;
  int nr;
  int ntest = 2;
  int q[11];
  int r[11];
  int test;

  printf ( "\n" );
  printf ( "I4POLY_DIV_TEST\n" );
  printf ( "  I4POLY_DIV computes the quotient and\n" );
  printf ( "  remainder for polynomial division.\n" );
  printf ( "\n" );
/*
  1: Divide X^3 + 2*X^2 - 5*X - 6  by X-2.  
     Quotient is 3+4*X+X^2, remainder is 0.

  2: Divide X^4 + 3*X^3 + 2*X^2 - 2  by  X^2 + X - 3.
     Quotient is X^2 + 2*X + 3, remainder 8*X + 7.
*/
  for ( test = 1; test <= ntest; test++ )
  {
    if ( test == 1 )
    {
      na = 3;
      a[0] = -6;
      a[1] = -5;
      a[2] =  2;
      a[3] =  1;

      nb = 1;
      b[0] = -2;
      b[1] =  1;
    }
    else if ( test == 2 )
    {
      na = 4;
      a[0] = -2;
      a[1] =  5;
      a[2] =  2;
      a[3] =  3;
      a[4] =  1;
      nb = 2;
      b[0] = -3;
      b[1] =  1;
      b[2] =  1;
    }

    i4poly_print ( na, a, "  The polynomial to be divided, A:" );
    i4poly_print ( nb, b, "  The divisor polynomial, B:" );

    i4poly_div ( na, a, nb, b, &nq, q, &nr, r );
 
    i4poly_print ( nq, q, "  The quotient polynomial, Q:" );
    i4poly_print ( nr, r, "  The remainder polynomial, R:" );
  }

  return;
}
/******************************************************************************/

void i4poly_mul_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_MUL_TEST tests I4POLY_MUL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2014

  Author:

    John Burkardt
*/
{
# define MAXN 5

  int a[MAXN+1];
  int b[MAXN+1];
  int c[MAXN+1];
  int na;
  int nb;
  int ntest = 2;
  int test;

  printf ( "\n" );
  printf ( "I4POLY_MUL_TEST\n" );
  printf ( "  I4POLY_MUL multiplies two polynomials.\n" );
  printf ( "\n" );
/*
  1: Multiply (1+X) times (1-X).  Answer is 1-X^2.
  2: Multiply (1+2*X+3*X^2) by (1-2*X). Answer is 1 + 0*X - X^2 - 6*X^3
*/
  for ( test = 1; test <= ntest; test++ )
  {
    if ( test == 1 )
    {
      na = 1;
      a[0] =  1;
      a[1] =  1;
      nb = 1;
      b[0] =  1;
      b[1] = -1;
    }
    else if ( test == 2 )
    {
      na = 2;
      a[0] =  1;
      a[1] =  2;
      a[2] =  3;
      nb = 1;
      b[0] =  1;
      b[1] = -2;
    }

    i4poly_mul ( na, a, nb, b, c );

    i4poly_print ( na, a, "  The factor A:" );

    i4poly_print ( nb, b, "  The factor B:" );

    i4poly_print ( na+nb, c, "  The product C = A*B:" );
  }

  return;
# undef MAXN
}
/******************************************************************************/

void i4poly_print_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_PRINT_TEST tests I4POLY_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 May 2015

  Author:

    John Burkardt
*/
{
  int a[5] = { -2, 5,2, 3, 1 };
  int n = 4;

  printf ( "\n" );
  printf ( "I4POLY_PRINT_TEST\n" );
  printf ( "  I4POLY_PRINT prints an I4POLY.\n" );

  i4poly_print ( n, a, "  The polynomial:" );

  return;
}
/******************************************************************************/

void i4poly_to_i4_test ( )

/******************************************************************************/
/*
  Purpose:

    I4POLY_TO_I4_TEST tests I4POLY_TO_I4;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2014

  Author:

    John Burkardt
*/
{
# define DEGREE_MAX 5
# define TEST_NUM 9

  int a[DEGREE_MAX+1];
  int base;
  int base_test[TEST_NUM] = { 2, 2, 2, 3, 4, 5, 6, 23, 24 };
  int degree;
  int i;
  int intval;
  int intval2;
  int intval_test[TEST_NUM] = { 1, 6, 23, 23, 23, 23, 23, 23, 23 };
  int test;

  printf ( "\n" );
  printf ( "I4POLY_TO_I4_TEST\n" );
  printf ( "  I4POLY_TO_I4 evaluates an integer polynomial\n" );
  printf ( "  at a given point;\n" );
  printf ( "\n" );
  printf ( "       I    BASE  DEGREE  Coefficients\n" );
  printf ( "\n" );
  for ( test = 0; test < TEST_NUM; test++ )
  {
    intval = intval_test[test];
    base = base_test[test];
    i4_to_i4poly ( intval, base, DEGREE_MAX, &degree, a );
    printf ( "  %6d  %6d  %6d\n", intval, base, degree );
    for ( i = 0; i <= degree; i++ )
    {
      printf ( "  %6d", a[i] );
    }
    printf ( "\n" );
  }
  printf ( "\n" );
  printf ( "  Now let I4_TO_I4POLY convert I to a polynomial,\n" );
  printf ( "  use I4POLY_TO_I4 to evaluate it, and compare.\n" );
  printf ( "\n" );
  printf ( "       I    I2\n" );
  printf ( "\n" );
  for ( test = 0; test < TEST_NUM; test++ )
  {
    intval = intval_test[test];
    base = base_test[test];
    i4_to_i4poly ( intval, base, DEGREE_MAX, &degree, a );
    intval2 = i4poly_to_i4 ( degree, a, base );
    printf ( "  %6d  %6d\n", intval, intval2 );
  }

  return;

# undef DEGREE_MAX
# undef TEST_NUM
}
/******************************************************************************/

void i4vec_backtrack_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_BACKTRACK_TEST tests I4VEC_BACKTRACK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 June 2015

  Author:

    John Burkardt
*/
{
  int found_num;
  int i;
  int indx;
  int k;
  int n = 8;
  int maxstack = 100;
  int ncan[8];
  int nstack;
  int stacks[100];
  int t;
  int total;
  int w[8] = { 15, 22, 14, 26, 32, 9, 16, 8 };
  int x[8];

  printf ( "\n" );
  printf ( "I4VEC_BACKTRACK_TEST\n" );
  printf ( "  I4VEC_BACKTRACK uses backtracking, seeking an I4VEC X of\n" );
  printf ( "  N values which satisfies some condition.\n" );

  printf ( "\n" );
  printf ( "  In this demonstration, we have 8 integers W(I).\n" );
  printf ( "  We seek all subsets that sum to 53.\n" );
  printf ( "  X(I) is 0 or 1 if the entry is skipped or used.\n" );
  printf ( "\n" );

  t = 53;

  for ( i = 0; i < n; i++ )
  {
    x[i] = 0;
  }
  indx = 0;
  k = 0;
  nstack = 0;
  for ( i = 0; i < n; i++ )
  {
    ncan[i] = 0;
  }

  found_num = 0;

  for ( ; ; )
  {
    i4vec_backtrack ( n, maxstack, x, &indx, &k, &nstack, stacks, ncan );

    if ( indx == 1 )
    {
      found_num = found_num + 1;
      printf ( "  %2d   ", found_num );

      total = i4vec_dot_product ( n, w, x );
      printf ( "  %3d:  ", total );

      for ( i = 0; i < n; i++ )
      {
        if ( x[i] == 1 )
        {
          printf ( "  %2d", w[i] );
        }
      }
      printf ( "\n" );
    }
/*
  Given that we've chose X(1:K-1), what are our choices for X(K)?

     if T < TOTAL, 
       no choices
     if T = TOTAL, 
       X(K) = 0
     if T > TOTAL and K < N, 
       X(k) = 0
       If ( W(K)+TOTAL <= T ) X(K) = 1
     If T > TOTAL and K = N,
       If ( W(K) + TOTAL) = T ) X(K) = 1
*/
    else if ( indx == 2 )
    {
      total = i4vec_dot_product ( k - 1, w, x );

      if ( t < total )
      {
        ncan[k-1] = 0;
      }
      else if ( t == total )
      {
        ncan[k-1] = ncan[k-1] + 1;
        stacks[nstack] = 0;
        nstack = nstack + 1;
      }
      else if ( total < t && k < n )
      {
        ncan[k-1] = ncan[k-1] + 1;
        stacks[nstack] = 0;
        nstack = nstack + 1;

        if ( total + w[k-1] <= t )
        {
          ncan[k-1] = ncan[k-1] + 1;
          stacks[nstack] = 1;
          nstack = nstack + 1;
        }
      }
      else if ( total < t && k == n )
      {
        if ( total + w[k-1] == t )
        {
          ncan[k-1] = ncan[k-1] + 1;
          stacks[nstack] = 1;
          nstack = nstack + 1;
        }
      }
    }
    else
    {
      printf ( "\n" );
      printf ( "  Done!\n" );
      break;
    }
  }

  return;
}
/******************************************************************************/

void i4vec_descends_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_DESCENDS_TEST tests I4VEC_DESCENDS;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 February 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int *a;
  int i;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_DESCENDS_TEST\n" );
  printf ( "  I4VEC_DESCENDS is true if an I4VEC decreases.\n" );

  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    a = i4vec_uniform_ab_new ( N, 1, N, &seed );

    i4vec1_print ( N, a, "  The integer array to search:" );
 
    if ( i4vec_descends ( N, a ) )
    {
      printf ( "  The preceding vector is descending.\n" );
    }
    else
    {
      printf ( "  The preceding vector is not descending.\n" );
    }
    free ( a );
  }

  return;
# undef N
}
/******************************************************************************/

void i4vec_frac_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_FRAC_TEST tests I4VEC_FRAC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int *a;
  int afrac;
  int k;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_FRAC_TEST\n" );
  printf ( "  I4VEC_FRAC: K-th smallest entry in an I4VEC.\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( N, 1, 2*N, &seed );

  i4vec1_print ( N, a, "  The integer array to search:" );

  printf ( "\n" );
  printf ( "     K   K-th smallest\n" );
  printf ( "\n" );

  for ( k = 1; k <= N; k++ )
  {
    afrac = i4vec_frac ( N, a, k );

    printf ( "%6d  %6d\n", k, afrac );

  }

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void i4vec_index_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_INDEX_TEST tests I4VEC_INDEX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 March 2014

  Author:

    John Burkardt
*/
{
# define N 20

  int *a;
  int aval;
  int first;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_INDEX_TEST\n" );
  printf ( "  I4VEC_INDEX returns the index of the first occurrence\n" );
  printf ( "  of a given value in an I4VEC.\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( N, 1, N/2, &seed );

  aval = a[N/2];

  i4vec1_print ( N, a, "  The integer array to search:" );

  first = i4vec_index ( N, a, aval );

  printf ( "\n" );
  printf ( "  The value searched for is %d\n", aval );
  printf ( "  The index of first occurrence is %d\n", first );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void i4vec_maxloc_last_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_MAXLOC_LAST_TEST tests I4VEC_MAXLOC_LAST;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 March 2014

  Author:

    John Burkardt
*/
{
# define N 20

  int *a;
  int last;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_MAXLOC_LAST_TEST\n" );
  printf ( "  I4VEC_MAXLOC_LAST: index of the last maximal\n" );
  printf ( "  entry in an I4VEC.\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( N, 1, N/4, &seed );

  i4vec1_print ( N, a, "  The integer array to search:" );
 
  last = i4vec_maxloc_last ( N, a );

  printf ( "\n" );
  printf ( "  Index of last maximal entry is %d\n", last );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void i4vec_pairwise_prime_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_PAIRWISE_PRIME_TEST tests I4VEC_PAIRWISE_PRIME;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int *a;
  int i;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_PAIRWISE_PRIME_TEST\n" );
  printf ( "  I4VEC_PAIRWISE_PRIME is true if an I4VEC\n" );
  printf ( "  is pairwise prime.\n" );

  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    a = i4vec_uniform_ab_new ( N, 1, N, &seed );

    i4vec1_print ( N, a, "  The array to check:" );
 
    if ( i4vec_pairwise_prime ( N, a ) )
    {
      printf ( "  The preceding vector is pairwise prime.\n" );
    }
    else
    {
      printf ( "  The preceding vector is not pairwise prime.\n" );
    }
    free ( a );
  }

  return;
# undef N
}
/******************************************************************************/

void i4vec_reverse_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_REVERSE_TEST tests I4VEC_REVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  int *a;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_REVERSE_TEST\n" );
  printf ( "  I4VEC_REVERSE reverses an I4VEC.\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( N, 1, N, &seed );

  i4vec1_print ( N, a, "  The integer array:" );

  i4vec_reverse ( N, a );

  i4vec1_print ( N, a, "  The reversed integer array:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void i4vec_sort_bubble_a_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_SORT_BUBBLE_A_TEST tests I4VEC_SORT_BUBBLE_A.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 March 2014

  Author:

    John Burkardt
*/
{
# define N 20

  int *a;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_SORT_BUBBLE_A_TEST\n" );
  printf ( "  I4VEC_SORT_BUBBLE_A ascending sorts an I4VEC\n" );
  printf ( "  using bubble sort.\n" );
  printf ( "\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( N, 0, 3*N, &seed );

  i4vec1_print ( N, a, "  Unsorted array:" );

  i4vec_sort_bubble_a ( N, a );

  i4vec1_print ( N, a, "  Sorted array:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void i4vec_sort_heap_index_d_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_SORT_HEAP_INDEX_D_TEST tests I4VEC_SORT_HEAP_INDEX_D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 March 2014

  Author:

    John Burkardt
*/
{
# define N 20

  int *a;
  int i;
  int *indx;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_SORT_HEAP_INDEX_D_TEST\n" );
  printf ( "  I4VEC_SORT_HEAP_INDEX_D descending index-sorts\n" );
  printf ( "  an I4VEC using heap sort.\n" );
  printf ( "\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( N, 0, 3*N, &seed );

  i4vec1_print ( N, a, "  Unsorted array:" );

  indx = i4vec_sort_heap_index_d ( N, a );

  printf ( "\n" );
  printf ( "     I  INDX[I]  A[INDX[I]-1]\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%6d  %6d  %6d\n", i, indx[i], a[indx[i]] );
  }

  free ( a );
  free ( indx );

  return;
# undef N
}
/******************************************************************************/

void i4vec_transpose_print_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_TRANSPOSE_PRINT_TEST tests I4VEC_TRANSPOSE_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 September 2013

  Author:

    John Burkardt
*/
{
# define N 12

  int *a;

  printf ( "\n" );
  printf ( "I4VEC_TRANSPOSE_PRINT_TEST\n" );
  printf ( "  I4VEC_TRANSPOSE_PRINT prints an I4VEC\n" );
  printf ( "  with 5 entries to a row, and an optional title.\n" );

  a = i4vec_indicator1_new ( N );

  i4vec_transpose_print ( N, a, "  My array:  " );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void i4vec_uniform_ab_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_UNIFORM_AB_TEST tests I4_UNIFORM_AB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2014

  Author:

    John Burkardt
*/
{
  int a = -100;
  int b = 200;
  int n = 20;
  int seed = 123456789;
  int *v;

  printf ( "\n" );
  printf ( "I4VEC_UNIFORM_AB_TEST\n" );
  printf ( "  I4VEC_UNIFORM_AB_NEW computes pseudorandom values\n" );
  printf ( "  in an interval [A,B].\n" );

  printf ( "\n" );
  printf ( "  The lower endpoint A = %d\n", a );
  printf ( "  The upper endpoint B = %d\n", b );
  printf ( "  The initial seed is %d\n", seed );
  printf ( "\n" );

  v = i4vec_uniform_ab_new ( n, a, b, &seed );

  i4vec_print ( n, v, "  The vector:" );

  free ( v );

  return;
}
/******************************************************************************/

void index_box_next_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_BOX_NEXT_2D_TEST tests INDEX_BOX_NEXT_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 February 2014

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int more;
  int n1 = 5;
  int n2 = 3;
  int n;

  printf ( "\n" );
  printf ( "INDEX_BOX_NEXT_2D_TEST\n" );
  printf ( "  INDEX_BOX_NEXT_2D produces IJ indices that\n" );
  printf ( "  lie on the surface of a box in 2D.\n" );
  printf ( "\n" );
  printf ( "  The box has logical dimensions:\n" );
  printf ( "%3d  %3d\n", n1, n2 );
  printf ( "\n" );
  printf ( "   #    I   J\n" );
  printf ( "\n" );

  more = 0;
  n = 0;

  for ( ; ; )
  {
    index_box_next_2d ( n1, n2, &i, &j, &more );

    if ( !more )
    {
      break;
    }

    n = n + 1;
    printf ( "%3d  %3d  %3d\n", n, i, j );
  }

  return;
}
/******************************************************************************/

void index_box_next_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_BOX_NEXT_3D_TEST tests INDEX_BOX_NEXT_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 February 2014

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int more;
  int n1 = 5;
  int n2 = 3;
  int n3 = 4;
  int n;

  printf ( "\n" );
  printf ( "INDEX_BOX_NEXT_3D_TEST\n" );
  printf ( "  INDEX_BOX_NEXT_3D produces IJK indices that\n" );
  printf ( "  lie on the surface of a box.\n" );
  printf ( "\n" );
  printf ( "  The box has logical dimensions:\n" );
  printf ( "%3d  %3d  %3d\n", n1, n2, n3 );
  printf ( "\n" );
  printf ( "   #    I   J   K\n" );
  printf ( "\n" );

  more = 0;
  n = 0;

  for ( ; ; )
  {
    index_box_next_3d ( n1, n2, n3, &i, &j, &k, &more );

    if ( !more )
    {
      break;
    }

    n = n + 1;
    printf ( "%3d  %3d  %3d  %3d\n", n, i, j, k );

  }

  return;
}
/******************************************************************************/

void index_box2_next_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_BOX2_NEXT_2D_TEST tests INDEX_BOX2_NEXT_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 February 2014

  Author:

    John Burkardt
*/
{
  int i;
  int ic = 10;
  int j;
  int jc = 20;
  int more;
  int n1 = 4;
  int n2 = 3;
  int n;

  printf ( "\n" );
  printf ( "INDEX_BOX2_NEXT_2D_TEST\n" );
  printf ( "  INDEX_BOX2_NEXT_2D produces IJ indices that\n" );
  printf ( "  lie on the surface of a box2 in 2D.\n" );
  printf ( "\n" );
  printf ( "  The box has half-widths:\n" );
  printf ( "%3d  %3d\n", n1, n2 );
  printf ( "\n" );
  printf ( "  and has center cell:\n" );
  printf ( "%3d  %3d\n", ic, jc );
  printf ( "\n" );
  printf ( "   #    I   J\n" );
  printf ( "\n" );

  more = 0;
  n = 0;

  for ( ; ; )
  {
    index_box2_next_2d ( n1, n2, ic, jc, &i, &j, &more );

    if ( !more )
    {
      break;
    }

    n = n + 1;
    printf ( "%3d  %3d  %3d\n", n, i, j );
  }

  return;
}
/******************************************************************************/

void index_box2_next_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_BOX2_NEXT_3D_TEST tests INDEX_BOX2_NEXT_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2014

  Author:

    John Burkardt
*/
{
  int i;
  int ic = 10;
  int j;
  int jc = 20;
  int k;
  int kc = 30;
  int more;
  int n1 = 5;
  int n2 = 3;
  int n3 = 4;
  int n;

  printf ( "\n" );
  printf ( "INDEX_BOX2_NEXT_3D_TEST\n" );
  printf ( "  INDEX_BOX2_NEXT_3D produces IJK indices that\n" );
  printf ( "  lie on the surface of a box.\n" );
  printf ( "\n" );
  printf ( "  The box has half widths:\n" );
  printf ( "%3d  %3d  %3d\n", n1, n2, n3 );
  printf ( "\n" );
  printf ( "  and central cell:\n" );
  printf ( "%3d  %3d  %3d\n", ic, jc, kc );
  printf ( "\n" );
  printf ( "  We will only print a PORTION of the data!\n" );
  printf ( "\n" );
  printf ( "   #    I   J   K\n" );
  printf ( "\n" );

  more = 0;
  n = 0;

  for ( ; ; )
  {
    index_box2_next_3d ( n1, n2, n3, ic, jc, kc, &i, &j, &k, &more );

    if ( !more )
    {
      break;
    }

    n = n + 1;

    if ( n <= 10 || 370 <= n )
    {
      printf ( "%3d  %3d  %3d  %3d\n", n, i, j, k );
    }
  }

  return;
}
/******************************************************************************/

void index_next0_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_NEXT0_TEST tests INDEX_NEXT0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int hi = 3;
  int i;
  int more;

  printf ( "\n" );
  printf ( "INDEX_NEXT0_TEST\n" );
  printf ( "  INDEX_NEXT0 generates all indices of an\n" );
  printf ( "  array of given shape, with\n" );
  printf ( "  lower limit 1 and given upper limit.\n" );
  printf ( "\n" );
  printf ( "  Number of index entries = %d\n", N );
  printf ( "  Coordinate maximum HI =   %d\n", hi );
 
  printf ( "\n" );
  printf ( "  Index arrays:\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    index_next0 ( N, hi, a, &more );

    for ( i = 0; i < N; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }

  }

  return;
# undef N
}
/******************************************************************************/

void index_next1_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_NEXT1_TEST tests INDEX_NEXT1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int hi[N] = { 4, 2, 3 };
  int i;
  int more;

  printf ( "\n" );
  printf ( "INDEX_NEXT1_TEST\n" );
  printf ( "  INDEX_NEXT1 generates all indices of an\n" );
  printf ( "  array of given shape, with\n" );
  printf ( "  lower limit 1 and given upper limits.\n" );
  printf ( "\n" );
  printf ( "  Number of index entries = %d\n", N );

  i4vec1_print ( N, hi, "  Coordinate maximum indices:" );
 
  printf ( "\n" );
  printf ( "  Index arrays:\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    index_next1 ( N, hi, a, &more );

    for ( i = 0; i < N; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }

  }

  return;
# undef N
}
/******************************************************************************/

void index_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_NEXT2_TEST tests INDEX_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int hi[N] = { 11, -3, 1 };
  int i;
  int lo[N] = { 10, -5, 0 };
  int more;

  printf ( "\n" );
  printf ( "INDEX_NEXT2_TEST\n" );
  printf ( "  INDEX_NEXT2 generates all indices of an\n" );
  printf ( "  array of given shape with given\n" );
  printf ( "  lower and upper limits.\n" );
  printf ( "\n" );
  printf ( "  Number of index entries = %d\n", N );
  printf ( "\n" );
  printf ( "  Coordinate, Maximum Index\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%8d  %8d  %8d\n", i+1, lo[i], hi[i] );
  }
 
  printf ( "\n" );
  printf ( "Index arrays:\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    index_next2 ( N, lo, hi, a, &more );

    for ( i = 0; i < N; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }

  }

  return;
# undef N
}
/******************************************************************************/

void index_rank0_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_RANK0_TEST tests INDEX_RANK0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N] = { 3, 1, 2 };
  int hi = 3;
  int rank;

  printf ( "\n" );
  printf ( "INDEX_RANK0_TEST\n" );
  printf ( "  INDEX_RANK0 ranks an index with\n" );
  printf ( "  lower limit 1 and given upper limit.\n" );
  printf ( "\n" );
  printf ( "  Number of index entries = %d\n", N );
  printf ( "\n" );
  printf ( "  Coordinate maximum Index = %d\n", hi );
  printf ( "\n" );

  i4vec1_print ( N, a, "  The index array:" );

  rank = index_rank0 ( N, hi, a );

  printf ( "\n" );
  printf ( "  The rank of this object is %d\n", rank );

  return;
# undef N
}
/******************************************************************************/

void index_rank1_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_RANK1_TEST tests INDEX_RANK1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N] = { 4, 1, 2 };
  int hi[N] = { 4, 2, 3 };
  int i;
  int rank;

  printf ( "\n" );
  printf ( "INDEX_RANK1_TEST\n" );
  printf ( "  INDEX_RANK1 ranks an index with\n" );
  printf ( "  lower limit 1 and given upper limits.\n" );
  printf ( "\n" );
  printf ( "  Number of index entries = %d\n", N );
  printf ( "\n" );
  printf ( "  Coordinate, Maximum Index\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%10d  %10d\n", i+1, hi[i] );
  }
 
  i4vec1_print ( N, a, "  The index array:" );

  rank = index_rank1 ( N, hi, a );

  printf ( "\n" );
  printf ( "  The rank of this object is %d\n", rank );

  return;
# undef N
}
/******************************************************************************/

void index_rank2_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_RANK2_TEST tests INDEX_RANK2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N] = { 1, 11, 5 };
  int hi[N] = { 2, 11, 6 };
  int i;
  int lo[N] = { 1, 10, 4 };
  int rank;

  printf ( "\n" );
  printf ( "INDEX_RANK2_TEST\n" );
  printf ( "  INDEX_RANK2 ranks an index with given\n" );
  printf ( "  lower and upper limits.\n" );
  printf ( "\n" );
  printf ( "  Number of index entries = %d\n", N );
  printf ( "\n" );
  printf ( "  Coordinate, Minimum index, Maximum Index\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%10d  %10d  %10d\n", i+1, lo[i], hi[i] );
  }
 
  i4vec1_print ( N, a, "  The index array:" );

  rank = index_rank2 ( N, lo, hi, a );

  printf ( "\n" );
  printf ( "  The rank of this object is %d\n", rank );

  return;
# undef N
}
/******************************************************************************/

void index_unrank0_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_UNRANK0_TEST tests INDEX_UNRANK0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int hi = 3;
  int i;
  int maxrank;
  int rank;

  printf ( "\n" );
  printf ( "INDEX_UNRANK0_TEST\n" );
  printf ( "  INDEX_UNRANK0 unranks a multi-index.\n" );
  printf ( "\n" );
  printf ( "  The multi-index has dimension %d\n", N );
  printf ( "\n" );
  printf ( "  The upper limit is HI = %d\n", hi );
  printf ( "\n" );
  printf ( "  Rank, Multi-Index:\n" );
  printf ( "\n" );
 
  maxrank = i4_power ( hi, N );

  for ( rank = 1; rank <= maxrank; rank++ )
  {
    index_unrank0 ( N, hi, rank, a );
    printf ( "%3d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "  %6d", a[i] );
    }
    printf ( "\n" );
  }
 
  return;
# undef N
}
/******************************************************************************/

void index_unrank1_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_UNRANK1_TEST tests INDEX_UNRANK1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int hi[N] = { 4, 2, 3 };
  int i;
  int maxrank;
  int rank;

  printf ( "\n" );
  printf ( "INDEX_UNRANK1_TEST\n" );
  printf ( "  INDEX_UNRANK1 unranks a multi-index.\n" );
  printf ( "\n" );
  printf ( "  The multi-index has dimension %d\n", N );

  i4vec1_print ( N, hi, "  The upper limits:" );

  printf ( "\n" );
  printf ( "  Rank, Multi-Index:\n" );
  printf ( "\n" );
 
  maxrank = i4vec_product ( N, hi );

  for ( rank = 1; rank <= maxrank; rank++ )
  {
    index_unrank1 ( N, hi, rank, a );
    printf ( "%3d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "  %6d", a[i] );
    }
    printf ( "\n" );
  }
 
  return;
# undef N
}
/******************************************************************************/

void index_unrank2_test ( )

/******************************************************************************/
/*
  Purpose:

    INDEX_UNRANK2_TEST tests INDEX_UNRANK2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int hi[N] = { 2, 11, 6 };
  int i;
  int lo[N] = { 1, 10, 4 };
  int rank;

  printf ( "\n" );
  printf ( "INDEX_UNRANK2_TEST\n" );
  printf ( "  INDEX_UNRANK2 unranks a multi-index.\n" );
  printf ( "\n" );
  printf ( "  The multi-index has dimension %d\n", N );
  printf ( "\n" );
  printf ( "  The lower and upper limits are:\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%10d  %10d  %10d\n", i, lo[i], hi[i] );
  }
  printf ( "\n" );
  printf ( "  Rank, Multi-Index:\n" );
  printf ( "\n" );
 
  rank = 7;

  index_unrank2 ( N, lo, hi, rank, a );
  printf ( "%3d", rank );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d", a[i] );
  }
  printf ( "\n" );
 
  return;
# undef N
}
/******************************************************************************/

void inverse_mod_n_test ( )

/******************************************************************************/
/*
  Purpose:

    INVERSE_MOD_N_TEST tests INVERSE_MOD_N.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 May 2011

  Author:

    John Burkardt
*/
{
  int b;
  int n;
  int y;
  int z;

  printf ( "\n" );
  printf ( "INVERSE_MOD_N_TEST\n" );
  printf ( "  INVERSE_MOD_N seeks Y, the inverse of B mod N,\n" );
  printf ( "  so that mod ( B * Y, N ) = 1, but returns 0\n" );
  printf ( "  if the inverse does not exist.\n" );

  printf ( "\n" );
  printf ( "     B     N     Y     Z = ( ( B * Y ) %% N )\n" );
  printf ( "\n" );

  for ( n = 1; n <= 10; n++ )
  {
    for ( b = 1; b < n; b++ )
    {
      y = inverse_mod_n ( b, n );
      z = ( ( b * y ) % n );
      printf ( "  %4d  %4d  %4d  %4d\n", b, n, y, z );
    }
  }

  return;
}
/******************************************************************************/

void inversion_to_perm0_test ( )

/******************************************************************************/
/*
  Purpose:

    INVERSION_TO_PERM0_TEST tests INVERSION_TO_PERM0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2015

  Author:

    John Burkardt
*/
{
# define N 5
 
  int ins[N];
  int perm[N] = { 2, 4, 0, 3, 1 };
  int perm2[N];

  printf ( "\n" );
  printf ( "INVERSION_TO_PERM0_TEST\n" );
  printf ( "  INVERSION_TO_PERM0: inversion => permutation (0,...,N-1).\n" );
  printf ( "\n" );

  i4vec1_print ( N, perm, "  The permutation:" );
  
  perm0_to_inversion ( N, perm, ins );

  i4vec1_print ( N, ins, "  The inversion sequence:" );

  inversion_to_perm0 ( N, ins, perm2 );

  i4vec1_print ( N, perm2, "  The recovered permutation:" );
 
  return;
# undef N
}
/******************************************************************************/

void involute_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    INVOLUTE_ENUM_TEST tests INVOLUTE_ENUM;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int i;
  int s[N+1];

  printf ( "\n" );
  printf ( "INVOLUTE_ENUM_TEST\n" );
  printf ( "  INVOLUTE_ENUM counts involutions;\n" );
  printf ( "\n" );

  involute_enum ( N, s );

  printf ( "\n" );
  printf ( "  N    # of involutions\n" );
  printf ( "\n" );

  for ( i = 0; i <= N; i++ )
  {
    printf ( "%10d  %10d\n", i, s[i] );
  }

  return;
# undef N
}
/******************************************************************************/

void jfrac_to_rfrac_test ( )

/******************************************************************************/
/*
  Purpose:

    JFRAC_TO_RFRAC_TEST tests JFRAC_TO_RFRAC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 October 2010

  Author:

    John Burkardt
*/
{
# define MAXM 10

  int i;
  int m;
  double p[MAXM];
  double q[MAXM];
  double r[MAXM];
  double s[MAXM];
  int seed;
/*
  Generate the data, but force Q(M+1) to be 1.  
  That will make it easier to see that the two operations are inverses
  of each other.  JFRAC_TO_RFRAC is free to scale its output, and chooses
  a scaling in which Q(M+1) is 1.
*/
  seed = 123456789;
  m = 6;
  r8vec_uniform_01 ( m, &seed, p );
  r8vec_uniform_01 ( m + 1, &seed, q );

  for ( i = 0; i < m; i++ )
  {
    q[i] = q[i] / q[m];
  }
  q[m] = 1.0;

  printf ( "\n" );
  printf ( "JFRAC_TO_RFRAC_TEST\n" );
  printf ( "  JFRAC_TO_RFRAC converts a J fraction\n" );
  printf ( "  to a rational polynomial fraction.\n" );
  printf ( "\n" );
  printf ( "  The original rational polynomial coefficients:\n" );
  printf ( "\n" );

  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", p[i] );
  }
  printf ( "\n" );

  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%14f  ", q[i] );
  }
  printf ( "\n" );
 
  rfrac_to_jfrac ( m, p, q, r, s );
 
  printf ( "\n" );
  printf ( "  The J fraction coefficients:\n" );
  printf ( "\n" );

  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", r[i] );
  }
  printf ( "\n" );
  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", s[i] );
  }
  printf ( "\n" );
 
  jfrac_to_rfrac ( m, r, s, p, q );

  printf ( "\n" );
  printf ( "  The recovered rational polynomial:\n" );
  printf ( "\n" );

  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", p[i] );
  }
  printf ( "\n" );

  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%14f  ", q[i] );
  }
  printf ( "\n" );

  return;
# undef MAXM
}
/******************************************************************************/

void josephus_test ( )

/******************************************************************************/
/*
  Purpose:

    JOSEPHUS_TEST tests JOSEPHUS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 March 2014

  Author:

    John Burkardt
*/
{
  int k;
  int m;
  int n;
  int x;

  printf ( "\n" );
  printf ( "JOSEPHUS_TEST\n" );
  printf ( "  JOSEPHUS solves Josephus problems.\n" );
  printf ( "\n" );
  printf ( "    N    M    K	 X\n" );
  printf ( "\n" );

  m = 3;
  n = 41;
  k = 41;
  x = josephus ( n, m, k );

  printf ( "%5d  %5d  %5d  %5d\n", n, m, k, x );

  m = -38;
  n = 41;
  k = 41;
  x = josephus ( n, m, k );

  printf ( "%5d  %5d  %5d  %5d\n", n, m, k, x );

  m = 3;
  n = 41;
  k = 40;
  x = josephus ( n, m, k );

  printf ( "%5d  %5d  %5d  %5d\n", n, m, k, x );

  m = 2;
  n = 64;
  k = 64;
  x = josephus ( n, m, k );

  printf ( "%5d  %5d  %5d  %5d\n", n, m, k, x );

  m = 2;
  n = 1000;
  k = 1000;
  x = josephus ( n, m, k );

  printf ( "%5d  %5d  %5d  %5d\n", n, m, k, x );

  return;
}
/******************************************************************************/

void ksub_next_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_NEXT_TEST tests KSUB_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2015

  Author:

    John Burkardt
*/
{
  int a[3];
  int i;
  int k;
  int m;
  int m2;
  int more;
  int n;
  int rank;

  printf ( "\n" );
  printf ( "KSUB_NEXT_TEST\n" );
  printf ( "  KSUB_NEXT generates all K subsets of an N set\n" );
  printf ( "  in lexicographic order.\n" );
  printf ( "\n" );

  rank = 0;

  n = 5;
  k = 3;
  for ( i = 0; i < k; i++ )
  {
    a[i] = 0;
  }
  more = 0;
  m = 0;
  m2 = 0;
 
  for ( ; ; )
  {
    ksub_next ( n, k, a, &more, &m, &m2 );

    rank = rank + 1;

    printf ( "%4d    ", rank );
    for ( i = 0; i < k; i++ )
    {
      printf ( "%4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }

  }
 
  return;
}
/******************************************************************************/

void ksub_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_NEXT2_TEST tests KSUB_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int i;
  int i_in;
  int i_out;
  int more;
  int n = 5;
  int rank;

  printf ( "\n" );
  printf ( "KSUB_NEXT2_TEST\n" );
  printf ( "  KSUB_NEXT2 generates the next K subset of an\n" );
  printf ( "  N set by the revolving door method.\n" );
  printf ( "\n" );
  printf ( "Rank  Subset  Added  Removed\n" );
  printf ( "\n" );
/*
  KSUB_NEXT2 does not have a good way of stopping.  
  We will save the starting subset, and stop when the
  new subset is the same as the starting one.
*/
  i_in = 0;
  i_out = 0;
  rank = 0;
 
  i4vec_indicator1 ( K, a );
 
  for ( ; ; )
  {
    rank = rank + 1;
    printf ( "%4d  ", rank );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%2d  ", a[i] );
    }
    printf ( "   " );
    printf ( "%2d  ", i_in );
    printf ( "%2d\n", i_out );
 
    ksub_next2 ( n, K, a, &i_in, &i_out );
 
    more = 0;

    for ( i = 1; i <= K; i++ )
    {
      if ( a[i-1] != i )
      {
        more = 1;
      }
    }

    if ( !more )
    {
      break;
    }

  }
 
  return;
# undef K
}
/******************************************************************************/

void ksub_next3_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_NEXT3_TEST tests KSUB_NEXT3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int i;
  int i_in = 0;
  int i_out = 0;
  int more;
  int n = 5;
  int rank;

  printf ( "\n" );
  printf ( "KSUB_NEXT3_TEST\n" );
  printf ( "  KSUB_NEXT3 generates all K subsets of an N set\n" );
  printf ( "  using the revolving door method.\n" );
  printf ( "\n" );
  printf ( "  Rank    Subset  Added Removed\n" );
  printf ( "\n" );

  rank = 0;
  more = 0;
 
  for ( ; ; )
  {
    ksub_next3 ( n, K, a, &more, &i_in, &i_out );

    rank = rank + 1;
    printf ( "%4d  ", rank );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%2d  ", a[i] );
    }
    printf ( "   " );
    printf ( "%2d  ", i_in );
    printf ( "%2d\n", i_out );

    if ( !more )
    {
      break;
    }

  }

  return;
# undef K
}
/******************************************************************************/

void ksub_next4_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_NEXT4_TEST tests KSUB_NEXT4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int done;
  int i;
  int n = 5;
  int rank;

  printf ( "\n" );
  printf ( "KSUB_NEXT4_TEST\n" );
  printf ( "  KSUB_NEXT4 generates K subsets of an N set.\n" );
  printf ( "  N = %d\n", n );
  printf ( "  K = %d\n", K );
  printf ( "\n" );
  printf ( "Rank    Subset\n" );
  printf ( "\n" );

  done = 1;
  rank = 0;
 
  for ( ; ; )
  {
    ksub_next4 ( n, K, a, &done );
 
    if ( done )
    {
      break;
    }

    rank = rank + 1;
    printf ( "%4d  ", rank );
    printf ( "  " );
    for ( i = 0; i < K; i++ )
    {
      printf ( "%4d  ", a[i] );
    }
    printf ( "\n" );

  }
 
  return;
# undef K
}
/******************************************************************************/

void ksub_random_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_RANDOM_TEST tests KSUB_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int i;
  int j;
  int n = 5;
  int seed;

  printf ( "\n" );
  printf ( "KSUB_RANDOM_TEST\n" );
  printf ( "  KSUB_RANDOM generates a random K subset of an N set.\n" );
  printf ( "  Set size is N =    %d\n", n );
  printf ( "  Subset size is K = %d\n", K );
  printf ( "\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    ksub_random ( n, K, &seed, a );
    for ( j = 0; j < K; j++ )
    {
      printf ( "  %3d", a[j] );
    }
    printf ( "\n" );
  }
 
  return;
# undef K
}
/******************************************************************************/

void ksub_random2_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_RANDOM2_TEST tests KSUB_RANDOM2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int a[K];
  int i;
  int j;
  int n = 5;
  int seed;

  printf ( "\n" );
  printf ( "KSUB_RANDOM2_TEST\n" );
  printf ( "  KSUB_RANDOM2 generates a random K subset of an N set.\n" );
  printf ( "  Set size is N =    %d\n", n );
  printf ( "  Subset size is K = %d\n", K );
  printf ( "\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    ksub_random2 ( n, K, &seed, a );
    for ( j = 0; j < K; j++ )
    {
      printf ( "  %3d", a[j] );
    }
    printf ( "\n" );
  }
 
  return;
# undef K
}
/******************************************************************************/

void ksub_random3_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_RANDOM3_TEST tests KSUB_RANDOM3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2014

  Author:

    John Burkardt
*/
{
# define K 3
# define N 5

  int a[N];
  int i;
  int j;
  int seed;

  printf ( "\n" );
  printf ( "KSUB_RANDOM3_TEST\n" );
  printf ( "  KSUB_RANDOM3 generates a random K subset of an N set.\n" );
  printf ( "  Set size is N =    %d\n", N );
  printf ( "  Subset size is K = %d\n", K );
  printf ( "\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    ksub_random3 ( N, K, &seed, a );
    for ( j = 0; j < N; j++ )
    {
      printf ( "  %3d", a[j] );
    }
    printf ( "\n" );
  }
 
  return;
# undef K
# undef N
}
/******************************************************************************/

void ksub_random4_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_RANDOM4_TEST tests KSUB_RANDOM4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 March 2014

  Author:

    John Burkardt
*/
{
# define K 3
# define N 5

  int a[N];
  int i;
  int j;
  int seed;

  printf ( "\n" );
  printf ( "KSUB_RANDOM4_TEST\n" );
  printf ( "  KSUB_RANDOM4 generates a random K subset of an N set.\n" );
  printf ( "  Set size is N =    %d\n", N );
  printf ( "  Subset size is K = %d\n", K );
  printf ( "\n" );
 
  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    ksub_random4 ( N, K, &seed, a );
    for ( j = 0; j < K; j++ )
    {
      printf ( "  %3d", a[j] );
    }
    printf ( "\n" );
  }
 
  return;
# undef K
# undef N
}
/******************************************************************************/

void ksub_random5_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_RANDOM5_TEST tests KSUB_RANDOM5.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 June 2011

  Author:

    John Burkardt
*/
{
  int *a;
  int i;
  int j;
  int k = 5;
  int n = 52;
  int seed;

  printf ( "\n" );
  printf ( "KSUB_RANDOM5_TEST\n" );
  printf ( "  KSUB_RANDOM5 generates a random K subset of an N set.\n" );
  printf ( "  Set size is N =    %d\n", n );
  printf ( "  Subset size is K = %d\n", k );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    a = ksub_random5 ( n, k, &seed );
    for ( j = 0; j < k; j++ )
    {
      printf ( "  %3d", a[j] );
    }
    printf ( "\n" );
    free ( a );
  }
  return;
}
/******************************************************************************/

void ksub_rank_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_RANK_TEST tests KSUB_RANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 March 2014

  Author:

    John Burkardt
*/
{
# define N 6
# define K 3

  int a[K] = { 1, 3, 5 };
  int i;
  int rank;

  printf ( "\n" );
  printf ( "KSUB_RANK_TEST\n" );
  printf ( "  KSUB_RANK: determine the rank of a K subset of an N set.\n" );
  printf ( "\n" );
  printf ( "  For N = %d\n", N );
  printf ( "  and K = %d\n", K );
  printf ( "  the subset is:\n" );
  printf ( "\n" );

  for ( i = 0; i < K; i++ )
  {
    printf ( "%4d", a[i] );
  }
  printf ( "\n" );

  ksub_rank ( K, a, &rank );

  printf ( "\n" );
  printf ( "  The computed rank is %d\n", rank );

  return;

# undef N
# undef K
}
/******************************************************************************/

void ksub_to_comp_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_TO_COMP_TEST tests KSUB_TO_COMP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2013

  Author:

    John Burkardt
*/
{
  int ac[5];
  int as[4];
  int i;
  int j;
  int kc;
  int ks;
  int nc;
  int ns;
  int seed;
  
  printf ( "\n" );
  printf ( "KSUB_TO_COMP_TEST\n" );
  printf ( "  KSUB_TO_COMP returns the composition corresponding to a K subset.\n" );

  nc = 10;
  kc = 5;
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    printf ( "\n" );

    comp_random ( nc, kc, &seed, ac );
    printf ( "  COMP:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );

    comp_to_ksub ( nc, kc, ac, &ns, &ks, as );
    printf ( "  KSUB:" );
    for ( j = 0; j < ks; j++ )
    {
      printf ( "%4d", as[j] );
    }
    printf ( "\n" );

    ksub_to_comp ( ns, ks, as, &nc, &kc, ac );
    printf ( "  COMP:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );
    
  }

  return;
}
/******************************************************************************/

void ksub_to_compnz_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_TO_COMPNZ_TEST tests KSUB_TO_COMPNZ.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 December 2013

  Author:

    John Burkardt
*/
{
  int ac[5];
  int as[4];
  int i;
  int j;
  int kc;
  int ks;
  int nc;
  int ns;
  int seed;
  
  printf ( "\n" );
  printf ( "KSUB_TO_COMPNZ_TEST\n" );
  printf ( "  KSUB_TO_COMPNZ returns the nonzero composition \n" );
  printf ( "  corresponding to a K subset.\n" );

  nc = 10;
  kc = 5;
  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    printf ( "\n" );

    compnz_random ( nc, kc, &seed, ac );
    printf ( "  COMPNZ:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );

    compnz_to_ksub ( nc, kc, ac, &ns, &ks, as );
    printf ( "  KSUB:  " );
    for ( j = 0; j < ks; j++ )
    {
      printf ( "%4d", as[j] );
    }
    printf ( "\n" );

    ksub_to_compnz ( ns, ks, as, &nc, &kc, ac );
    printf ( "  COMPNZ:" );
    for ( j = 0; j < kc; j++ )
    {
      printf ( "%4d", ac[j] );
    }
    printf ( "\n" );
    
  }

  return;
}
/******************************************************************************/

void ksub_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    KSUB_UNRANK_TEST tests KSUB_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 March 2014

  Author:

    John Burkardt
*/
{
# define K 3

  int i;
  int a[K];
  int n = 5;
  int rank;

  rank = 8;

  printf ( "\n" );
  printf ( "KSUB_UNRANK_TEST\n" );
  printf ( "  KSUB_UNRANK: find the K-subset of an N set\n" );
  printf ( "  of a given rank.\n" );
  printf ( "\n" );
  printf ( "  For N = %d\n", n );
  printf ( "  and K = %d\n", K );
  printf ( "  and the desired rank is %d\n", rank );

  ksub_unrank ( K, rank, a );

  printf ( "\n" );
  printf ( "  The subset of the given rank is:\n" );
  printf ( "\n" );

  for ( i = 0; i < K; i++ )
  {
    printf ( "%4d", a[i] );
  }
  printf ( "\n" );

  return;
# undef K
}
/******************************************************************************/

void l4vec_next_test ( )

/******************************************************************************/
/*
  Purpose:

    L4VEC_NEXT_TEST tests L4VEC_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 November 2015

  Author:

    John Burkardt
*/
{
  int done;
  int i;
  int l4vec[3];
  int n = 3;

  printf ( "\n" );
  printf ( "L4VEC_NEXT_TEST\n" );
  printf ( "  L4VEC_NEXT generates logical vectors in order.\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    l4vec[i] = 0;
  }
 
  done = 0;

  for ( ; ; )
  {
    printf ( "  " );
    for ( i = 0; i < n; i++ )
    {
      printf ( "%d", l4vec[i] );
    }
    printf ( "\n" );

    if ( done )
    {
      break;
    }

    l4vec_next ( n, l4vec );

    done = 1;
    for ( i = 0; i < n; i++ )
    {
      if ( ! l4vec[i] )
      {
        done = 0;
      }
    }
  }
 
  return;
}
/******************************************************************************/

void matrix_product_opt_test ( )

/******************************************************************************/
/*
  Purpose:

    MATRIX_PRODUCT_OPT_TEST tests MATRIX_PRODUCT_OPT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 March 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int cost;
  int i;
  int order[N-1];
  int rank[N+1] = { 4, 2, 3, 1, 2, 2, 3 };

  printf ( "\n" );
  printf ( "MATRIX_PRODUCT_OPT_TEST\n" );
  printf ( "  MATRIX_PRODUCT_OPT seeks the optimal order\n" );
  printf ( "  for a chain of matrix products.\n" );
  printf ( "\n" );
  printf ( "  Matrix ranks:\n" );
  printf ( "\n" );
  printf ( "   I    R    C\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "%5d  %5d  %5d\n", i, rank[i], rank[i+1] );
  }

  matrix_product_opt ( N, rank, &cost, order );

  printf ( "\n" );
  printf ( "  Optimal cost is %d\n",cost );

  i4vec1_print ( N-1, order, "  Ordering:" );

  return;
# undef N
}
/******************************************************************************/

void moebius_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    MOEBIUS_MATRIX_TEST tests MOEBIUS_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 March 2014

  Author:

    John Burkardt
*/
{
# define N 11

  int ih[N*N] = {
    0,0,1,1,0,0,0,0,0,0,0, 
    0,0,0,0,0,0,0,1,0,0,0, 
    0,1,0,0,0,0,0,0,0,0,0, 
    0,1,0,0,0,0,0,0,0,0,0, 
    0,0,0,1,0,0,0,0,0,0,0, 
    1,0,0,0,1,0,0,0,1,0,0, 
    0,0,0,0,0,1,0,0,0,1,1, 
    0,0,0,0,0,0,0,0,0,0,0, 
    0,0,1,1,0,0,0,0,0,0,0, 
    1,0,0,0,0,0,0,0,1,0,0, 
    0,0,0,0,0,0,0,0,1,0,0 };
  int matrix[N*N];

  printf ( "\n" );
  printf ( "MOEBIUS_MATRIX_TEST\n" );
  printf ( "  MOEBIUS_MATRIX computes the Moebius matrix.\n" );
 
  i4mat_print ( N, N, ih, "  The input matrix:" );

  moebius_matrix ( N, ih, matrix );
 
  i4mat_print ( N, N, matrix, "  The Moebius matrix:" );
 
  return;
# undef N
}
/******************************************************************************/

void monomial_count_test ( )

/******************************************************************************/
/*
  Purpose:

    MONOMIAL_COUNT_TEST tests MONOMIAL_COUNT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 March 2014

  Author:

    John Burkardt
*/
{
  int degree_max = 9;
  int dim;
  int total;

  printf ( "\n" );
  printf ( "MONOMIAL_COUNT_TEST\n" );
  printf ( "  MONOMIAL_COUNT counts the number of monomials of\n" );
  printf ( "  degrees 0 through DEGREE_MAX in a space of dimension DIM.\n" );
  printf ( "\n" );
  printf ( "  DIM  Total\n" );
  printf ( "\n" );

  for ( dim = 1; dim <= 6; dim++ )
  {
    total = monomial_count ( degree_max, dim );
    printf ( "  %4d  %8d\n", dim, total );
  }

  return;
}
/******************************************************************************/

void monomial_counts_test ( )

/******************************************************************************/
/*
  Purpose:

    MONOMIAL_COUNTS_TEST tests MONOMIAL_COUNTS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 March 2014

  Author:

    John Burkardt
*/
{
  int *counts;
  int degree;
  int degree_max = 9;
  int dim;
  int total;

  printf ( "\n" );
  printf ( "MONOMIAL_COUNTS_TEST\n" );
  printf ( "  MONOMIAL_COUNTS counts the number of monomials of\n" );
  printf ( "  various degrees in a space of dimension DIM.\n" );
 
  for ( dim = 1; dim <= 6; dim++ )
  {
    counts = monomial_counts ( degree_max, dim );

    printf ( "\n" );
    printf ( "  DIM = %d\n", dim );
    printf ( "\n" );

    for ( degree = 0; degree <= degree_max; degree++ )
    {
      printf ( "  %8d  %8d\n", degree, counts[degree] );
    }

    total = 0;
    for ( degree = 0; degree <= degree_max; degree++ )
    {
      total = total + counts[degree];
    }
    printf ( "\n" );
    printf ( "     Total  %8d\n", total );

    free ( counts );
  }

  return;
}
/******************************************************************************/

void morse_thue_test ( )

/******************************************************************************/
/*
  Purpose:

    MORSE_THUE_TEST tests MORSE_THUE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define N 100

  unsigned int i;
  int ihi;
  int ilo;
  int s[N+1];

  printf ( "\n" );
  printf ( "MORSE_THUE_TEST\n" );
  printf ( "  MORSE_THUE computes the Morse-Thue numbers.\n" );
  printf ( "\n" );

  for ( i = 0; i <= N; i++ )
  {
    s[i] = morse_thue ( i );
  }

  for ( ilo = 0; ilo <= N; ilo = ilo + 10 )
  {
    printf ( "  " );
    ihi = i4_min ( ilo + 9, N );
    for ( i = ilo; i <= ihi; i++ )
    {
      printf ( "%d", s[i] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void multinomial_coef1_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTINOMIAL_COEF1_TEST tests MULTINOMIAL_COEF1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define MAXFACTOR 5

  int factor[MAXFACTOR];
  int i;
  int j;
  int n;
  int ncomb;
  int nfactor;

  printf ( "\n" );
  printf ( "MULTINOMIAL_COEF1_TEST\n" );
  printf ( "  MULTINOMIAL_COEF1 computes multinomial\n" );
  printf ( "  coefficients using the Gamma function;\n" );

  printf ( "\n" );
  printf ( "  Line 10 of the BINOMIAL table:\n" );
  printf ( "\n" );

  n = 10;
  nfactor = 2;

  for ( i = 0; i <= n; i++ )
  {
    factor[0] = i;
    factor[1] = n - i;

    ncomb = multinomial_coef1 ( nfactor, factor );

    printf ( "%4d  %4d       %5d\n", 
      factor[0], factor[1], ncomb );
  }

  printf ( "\n" );
  printf ( "  Level 5 of the TRINOMIAL coefficients:\n" );

  n = 5;
  nfactor = 3;

  for ( i = 0; i <= n; i++ )
  {
    factor[0] = i;

    printf ( "\n" );

    for ( j = 0; j <= n - factor[0]; j++ )
    {
      factor[1] = j;
      factor[2] = n - factor[0] - factor[1];

      ncomb = multinomial_coef1 ( nfactor, factor );

      printf ( "%4d  %4d  %4d  %5d\n", 
        factor[0], factor[1], factor[2], ncomb );
    }
  }

  return;
# undef MAXFACTOR
}
/******************************************************************************/

void multinomial_coef2_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTINOMIAL_COEF2_TEST tests MULTINOMIAL_COEF2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define MAXFACTOR 5

  int factor[MAXFACTOR];
  int i;
  int j;
  int n;
  int ncomb;
  int nfactor;

  printf ( "\n" );
  printf ( "MULTINOMIAL_COEF2_TEST\n" );
  printf ( "  MULTINOMIAL_COEF2 computes multinomial\n" );
  printf ( "  coefficients using the Gamma function;\n" );

  printf ( "\n" );
  printf ( "  Line 10 of the BINOMIAL table:\n" );
  printf ( "\n" );

  n = 10;
  nfactor = 2;

  for ( i = 0; i <= n; i++ )
  {
    factor[0] = i;
    factor[1] = n - i;

    ncomb = multinomial_coef2 ( nfactor, factor );

    printf ( "%4d  %4d       %5d\n", 
      factor[0], factor[1], ncomb );
  }

  printf ( "\n" );
  printf ( "  Level 5 of the TRINOMIAL coefficients:\n" );

  n = 5;
  nfactor = 3;

  for ( i = 0; i <= n; i++ )
  {
    factor[0] = i;

    printf ( "\n" );

    for ( j = 0; j <= n - factor[0]; j++ )
    {
      factor[1] = j;
      factor[2] = n - factor[0] - factor[1];

      ncomb = multinomial_coef2 ( nfactor, factor );

      printf ( "%4d  %4d  %4d  %5d\n", 
        factor[0], factor[1], factor[2], ncomb );
    }
  }

  return;
# undef MAXFACTOR
}
/******************************************************************************/

void multiperm_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTIPERM_ENUM_TEST tests MULTIPERM_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  int counts[N];
  int i;
  int k;
  int number;
  int seed = 123456789;
  int test;
  int test_num = 5;
  
  printf ( "\n" );
  printf ( "MULTIPERM_ENUM_TEST\n" );
  printf ( "  MULTIPERM_ENUM enumerates multipermutations.\n" );
  printf ( "\n" );
  printf ( "  N is the number of objects to be permuted.\n" );
  printf ( "  K is the number of distinct types of objects.\n" );
  printf ( "  COUNTS is the number of objects of each type.\n" );
  printf ( "  NUMBER is the number of multipermutations.\n" );
  printf ( "\n" );
  printf ( "  Number       N       K       Counts(1:K)\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  {  
    k = i4_uniform_ab ( 1, N, &seed );

    compnz_random ( N, k, &seed, counts );

    number = multiperm_enum ( N, k, counts );

    printf ( "  %6d  %6d  %6d\n", number, N, k );
    for ( i = 0; i < k; i++ )
    {
      printf ( "  %4d", counts[i] );
    }
    printf ( "\n" );
  }
  
  return;
# undef N
}
/******************************************************************************/

void multiperm_next_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTIPERM_NEXT_TEST tests MULTIPERM_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int a[N] = { 1, 2, 2, 3, 3, 3 };
  int i;
  int more;
  int tally;
  
  printf ( "\n" );
  printf ( "MULTIPERM_NEXT_TEST\n" );
  printf ( "  MULTIPERM_NEXT computes multipermutations in\n" );
  printf ( "  lexical order.\n" );
  printf ( "\n" );

  tally = 0;
  more = 1;
 
  while ( more )
  {
    tally = tally + 1;

    printf ( "  %4d", tally );
    for ( i = 0; i < N; i++ )
    {
      printf ( "  %2d", a[i] );
    }
    printf ( "\n" );

    multiperm_next ( N, a, &more );
  }
 
  return;
# undef N
}
/******************************************************************************/

void nim_sum_test ( )

/******************************************************************************/
/*
  Purpose:

    NIM_SUM_TEST tests NIM_SUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define N 32

  int i;
  int i1vec[N];
  int i2vec[N];
  int i3vec[N];
  int ihi = 1000;
  int ilo = 0;
  int ntest = 5;
  int seed;
  unsigned int ui1;
  unsigned int ui2;
  unsigned int ui3;

  printf ( "\n" );
  printf ( "NIM_SUM_TEST\n" );
  printf ( "  NIM_SUM computes the Nim sum of two integers.\n" );
  printf ( "\n" );
  printf ( "    I    J    Nim(I+J)\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= ntest; i++ )
  {
    ui1 = ( unsigned int ) i4_uniform_ab ( ilo, ihi, &seed );
    ui4_to_ubvec ( ui1, N, i1vec );

    ui2 = ( unsigned int ) i4_uniform_ab ( ilo, ihi, &seed );
    ui4_to_ubvec ( ui2, N, i2vec );

    ui3 = nim_sum ( ui1, ui2 );
    ui4_to_ubvec ( ui3, N, i3vec );

    printf ( "\n" );
    printf ( "  UI1, UI2, UI3 in decimal:\n" );
    printf ( "\n" );

    printf ( "  %5d", ui1 );
    printf ( "  %5d", ui2 );
    printf ( "  %5d", ui3 );

    printf ( "\n" );
    printf ( "  I1, I2, I3 in binary:\n" );
    printf ( "\n" );

    ubvec_print ( N, i1vec, "" );
    ubvec_print ( N, i2vec, "" );
    ubvec_print ( N, i3vec, "" );
  }

  return;
# undef N
}
/******************************************************************************/

void padovan_test ( )

/******************************************************************************/
/*
  Purpose:

    PADOVAN_TEST tests PADOVAN;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int i;
  int p[N];

  printf ( "\n" );
  printf ( "PADOVAN_TEST\n" );
  printf ( "  PADOVAN computes the Padovan numbers.\n" );
  printf ( "\n" );

  padovan ( N, p );

  printf ( "\n" );
  printf ( "   N    P(N)\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d  %6d\n", i, p[i] );
  }

  return;
# undef N
}
/******************************************************************************/

void pell_basic_test ( )

/******************************************************************************/
/*
  Purpose:

    PELL_BASIC_TEST tests PELL_BASIC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 March 2014

  Author:

    John Burkardt
*/
{
  int d;
  int q;
  int r;
  int x0;
  int y0;

  printf ( "\n" );
  printf ( "PELL_BASIC_TEST\n" );
  printf ( "  PELL_BASIC solves the basic Pell equation.\n" );
  printf ( "\n" );
  printf ( "       D       X        Y         R\n" );
  printf ( "\n" );

  for ( d = 2; d <= 20; d++ )
  {
    i4_sqrt ( d, &q, &r );

    if ( r != 0 )
    {
      pell_basic ( d, &x0, &y0 );

      r = x0 * x0 - d * y0 * y0;

      printf ( "%9d  %9d  %9d  %9d\n", d, x0, y0, r );
    }
  }

  return;
}
/******************************************************************************/

void pell_next_test ( )

/******************************************************************************/
/*
  Purpose:

    PELL_NEXT_TEST tests PELL_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 March 2014

  Author:

    John Burkardt
*/
{
  int d;
  int q;
  int r;
  int x0;
  int x1;
  int y0;
  int y1;

  printf ( "\n" );
  printf ( "PELL_NEXT_TEST\n" );
  printf ( "  PELL_NEXT computes the next solution to the Pell equation.\n" );
  printf ( "\n" );
  printf ( "       D       X        Y         R\n" );
  printf ( "\n" );

  for ( d = 2; d <= 20; d++ )
  {
    i4_sqrt ( d, &q, &r );

    if ( r != 0 )
    {
      pell_basic ( d, &x0, &y0 );

      r = x0 * x0 - d * y0 * y0;

      printf ( "%9d  %9d  %9d  %9d\n", d, x0, y0, r );

      pell_next ( d, x0, y0, x0, y0, &x1, &y1 );

      r = x1 * x1 - d * y1 * y1;

      printf ( "           %9d  %9d  %9d\n", x1, y1, r );
    }
  }

  return;
}
/******************************************************************************/

void pent_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    PENT_ENUM_TEST tests PENT_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int i;

  printf ( "\n" );
  printf ( "PENT_ENUM_TEST\n" );
  printf ( "  PENT_ENUM counts points in pentagons.\n" );
  printf ( "\n" );
  printf ( "   N  Pent(N)\n" );
  printf ( "\n" );

  for ( i = 0; i <= N; i++ )
  {
    printf ( "%4d  %6d\n", i, pent_enum ( i ) );
  }

  return;
# undef N
}
/******************************************************************************/

void perm_ascend_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM_ASCEND_TEST tests PERM_ASCEND.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 March 2014

  Author:

    John Burkardt
*/
{
# define N 9

  int length;
  int p[N] = { 1,2,8,5,6,7,4,3,0 };
  int subseq[N];

  printf ( "\n" );
  printf ( "PERM_ASCEND_TEST\n" );
  printf ( "  PERM_ASCEND determines the length of the longest\n" );
  printf ( "  increasing subsequence in a permutation.\n" );

  perm0_print ( N, p, "  The permutation:" );

  perm_ascend ( N, p, &length, subseq );

  printf ( "\n" );
  printf ( "  The length of the longest increasing subsequence is %d\n", 
    length );

  i4vec1_print ( length, subseq, "  A longest increasing subsequence:" );

  return;
# undef N
}
/******************************************************************************/

void perm_fixed_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM_FIXED_ENUM_TEST tests PERM_FIXED_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 March 2014

  Author:

    John Burkardt
*/
{
  int fnm;
  int m;
  int n = 10;

  printf ( "\n" );
  printf ( "PERM_FIXED_ENUM_TEST\n" );
  printf ( "  PERM_FIXED_ENUM enumerates the permutations\n" );
  printf ( "  of N objects that leave M unchanged.\n" );
  printf ( "\n" );
  printf ( "  For this test, N = %d\n", n );
  printf ( "\n" );
  printf ( "    M    F(N,M)\n" );
  printf ( "\n" );

  for ( m = 0; m <= n; m++ )
  {
    fnm = perm_fixed_enum ( n, m );

    printf ( "  %3d  %8d\n", m, fnm );
  }

  return;
}
/******************************************************************************/

void perm0_break_count_test ( )

/******************************************************************************/
/* 
  Purpose:

    PERM0_BREAK_COUNT_TEST tests PERM0_BREAK_COUNT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  int break_count;
  int n = 6;
  int p[6] = { 3, 4, 1, 0, 5, 2 };

  printf ( "\n" );
  printf ( "PERM0_BREAK_COUNT_TEST\n" );
  printf ( "  PERM0_BREAK_COUNT counts the breaks in a permutation.\n" );
 
  perm0_print ( n, p, "  The permutation:" );
 
  break_count = perm0_break_count ( n, p );

  printf ( "\n" );
  printf ( "  The number of breaks is %d\n", break_count );

  return;
}
/******************************************************************************/

void perm0_check_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_CHECK_TEST tests PERM0_CHECK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 May 2015

  Author:

    John Burkardt
*/
{
  int n = 5;
  int p1[5] = { 5, 2, 3, 4, 1 };
  int p2[5] = { 4, 1, 3, 0, 2 };
  int p3[5] = { 0, 2, 1, 3, 2 };

  printf ( "\n" );
  printf ( "PERM0_CHECK_TEST\n" );
  printf ( "  PERM0_CHECK checks a permutation of (0,...,N-1).\n" );
  printf ( "\n" );

  perm0_print ( n, p1, "  Permutation 1:" );
  perm0_check( n, p1 );

  perm0_print ( n, p2, "  Permutation 2:" );
  perm0_check( n, p2 );

  perm0_print ( n, p3, "  Permutation 3:" );
  perm0_check( n, p3 );

  return;
}
/******************************************************************************/

void perm0_cycle_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_CYCLE_TEST tests PERM0_CYCLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 March 2014

  Author:

    John Burkardt
*/
{
  int iopt = 1;
  int isgn;
  int n = 9;
  int ncycle;
  int p[9] = { 1,2,8,5,6,7,4,3,0 };

  printf ( "\n" );
  printf ( "PERM0_CYCLE_TEST\n" );
  printf ( "  PERM0_CYCLE analyzes a permutation of (0,...,N-1).\n" );

  perm0_print ( n, p, "  The permutation:" );

  perm0_cycle ( n, p, &isgn, &ncycle, iopt );

  printf ( "\n" );
  printf ( "  NCYCLE = %d\n", ncycle );
  printf ( "  ISGN =   %d\n", isgn );

  perm0_print ( n, p, "  The permutation in cycle form:" );

  return;
}
/******************************************************************************/

void perm0_distance_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_DISTANCE_TEST tests PERM0_DISTANCE

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int k11;
  int k12;
  int k13;
  int k21;
  int k23;
  int p1[N];
  int p2[N];
  int p3[N];
  int seed;

  printf ( "\n" );
  printf ( "PERM0_DISTANCE_TEST\n" );
  printf ( "  PERM0_DISTANCE computes the Ulam metric distance\n" );
  printf ( "  between two permutations of (0,...,N-1).\n" );

  seed = 123456789;

  perm0_random2 ( N, &seed, p1 );
  perm0_random2 ( N, &seed, p2 );
  perm0_random2 ( N, &seed, p3 );

  perm0_print ( N, p1, "  Permutation P1" );
  perm0_print ( N, p2, "  Permutation P2" );
  perm0_print ( N, p3, "  Permutation P3" );

  k11 = perm0_distance ( N, p1, p1 );
  k12 = perm0_distance ( N, p1, p2 );
  k21 = perm0_distance ( N, p2, p1 );
  k13 = perm0_distance ( N, p1, p3 );
  k23 = perm0_distance ( N, p2, p3 );

  printf ( "\n" );
  printf ( "  K(P1,P1) should be 0.\n" );
  printf ( "\n" );
  printf ( "  K(P1,P1) = %d\n", k11 );
  printf ( "\n" );
  printf ( "  K(P1,P2) should equal K(P2,P1).\n" );
  printf ( "\n" );
  printf ( "  K(P1,P2) = %d\n", k12 );
  printf ( "  K(P2,P1) = %d\n", k21 );
  printf ( "\n" );
  printf ( "  K(P1,P2) + K(P2,P3) >= K(P1,P3).\n" );
  printf ( "\n" );
  printf ( "  K(P1,P3) = %d\n", k13 );
  printf ( "  K(P1,P2) = %d\n", k12 );
  printf ( "  K(P2,P3) = %d\n", k23 );
  printf ( "  K(P1,P2) + K(P2,P3) = %d\n", k12 + k23 );

  return;
# undef N
}
/******************************************************************************/

void perm0_free_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_FREE_TEST tests PERM0_FREE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int ifree[5];
  int ipart[5];
  int n = 5;
  int nfree;
  int npart;
  int p[5] = { 4, 1, 2, 3, 0 };

  printf ( "\n" );
  printf ( "PERM0_FREE_TEST\n" );
  printf ( "  PERM0_FREE returns the unused values in a partial permutation\n" );
  printf ( "   of (0,...,N-1).\n" );

  for ( npart = 0; npart <= n; npart++ )
  {
    for ( i = 0; i < npart; i++ )
    {
      ipart[i] = p[i];
    }
    nfree = n - npart;
    perm0_free ( npart, ipart, nfree, ifree );
    i4vec_transpose_print ( npart, ipart, "  Partial permutation:" );
    i4vec_transpose_print ( nfree, ifree, "  Values not yet used:" );
  }
  return;
}
/******************************************************************************/

void perm0_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_INVERSE_TEST tests PERM0_INVERSE;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 June 2015

  Author:

    John Burkardt
*/
{
  int n = 7;
  int p1[7] = { 3, 2, 4, 0, 6, 5, 1 };
  int *p2;

  printf ( "\n" );
  printf ( "PERM0_INVERSE_TEST\n" );
  printf ( "  PERM0_INVERSE inverts a permutation of (0,...,N-1);\n" );
  printf ( "\n" );

  perm0_print ( n, p1, "  The original permutation:" );
 
  p2 = perm0_inverse ( n, p1 );
 
  perm0_print ( n, p2, "  The inverted permutation:" );
 
  free ( p2 );

  return;
}
/******************************************************************************/

void perm0_inverse2_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_INVERSE2_TEST tests PERM0_INVERSE2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int n = 7;
  int p[7] = { 3, 2, 4, 0, 6, 5, 1 };

  printf ( "\n" );
  printf ( "PERM0_INVERSE2_TEST\n" );
  printf ( "  PERM0_INVERSE2 inverts a permutation of (0,...,N-1).\n" );

  perm0_print ( n, p, "  The original permutation:" );
 
  perm0_inverse2 ( n, p );
 
  perm0_print ( n, p, "  The inverted permutation:" );
 
  return;
}
/******************************************************************************/

void perm0_inverse3_new_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_INVERSE3_NEW_TEST tests PERM0_INVERSE3_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int n = 7;
  int p[7] = { 3, 2, 4, 0, 6, 5, 1 };
  int *p_inv;

  printf ( "\n" );
  printf ( "PERM0_INVERSE3_NEW_TEST\n" );
  printf ( "  PERM0_INVERSE3_NEW inverts a permutation of (0,...,N-1).\n" );

  perm0_print ( n, p, "  The original permutation:" );
 
  p_inv = perm0_inverse3_new ( n, p );
 
  perm0_print ( n, p_inv, "  The inverted permutation:" );
 
  free ( p_inv );

  return;
}
/******************************************************************************/

void perm0_lex_next_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_LEX_NEXT_TEST tests PERM0_LEX_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 March 2014

  Author:

    John Burkardt
*/
{
  int more;
  int n = 4;
  int p[4];

  printf ( "\n" );
  printf ( "PERM0_LEX_NEXT_TEST\n" );
  printf ( "  PERM0_LEX_NEXT generates permutations of (0,...,N-1).\n" );
  printf ( "\n" );

  more = 0;
 
  for ( ; ; )
  {
    perm0_lex_next ( n, p, &more );

    if ( !more )
    {
      break;
    }

    perm0_print ( n, p, "" );
  }
 
  return;
}
/******************************************************************************/

void perm0_mul_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_MUL_TEST tests PERM0_MUL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 June 2015

  Author:

    John Burkardt
*/
{
# define N 5

  int p1[N];
  int p2[N];
  int p3[N];
  int seed;

  printf ( "\n" );
  printf ( "PERM0_MUL_TEST\n" );
  printf ( "  PERM0_MUL multiplies two permutations of (0,...,N-1).\n" );
  printf ( "\n" );

  seed = 123456789;

  perm0_random ( N, &seed, p1 );
  perm0_random ( N, &seed, p2 );

  perm0_print ( N, p1, "  Permutation P1:" );

  perm0_print ( N, p2, "  Permutation P2:" );

  perm0_mul ( N, p1, p2, p3 );

  perm0_print ( N, p3, "  Product permutation: P3" );

  return;
# undef N
}
/******************************************************************************/

void perm0_next_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_NEXT_TEST tests PERM0_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 June 2015

  Author:

    John Burkardt
*/
{
  int even;
  int more;
  int n = 4;
  int p[4];

  printf ( "\n" );
  printf ( "PERM0_NEXT_TEST\n" );
  printf ( "  PERM0_NEXT generates permutations of (0,...,N-1).\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    perm0_next ( n, p, &more, &even );

    perm0_print ( n, p, "" );

    if ( !more )
    {
      break;
    }

  }

  return;
}
/******************************************************************************/

void perm0_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_NEXT2_TEST tests PERM0_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int done;
  int p[N];

  printf ( "\n" );
  printf ( "PERM0_NEXT2_TEST\n" );
  printf ( "  PERM0_NEXT2 generates permutations of (0,...,N-1).\n" );
  printf ( "\n" );

  done = 1;
 
  for ( ; ; )
  {
    perm0_next2 ( N, p, &done );
 
    if ( done )
    {
      break;
    }

    perm0_print ( N, p, "" );

  }
 
  return;
# undef N
}
/******************************************************************************/

void perm0_next3_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_NEXT3_TEST tests PERM0_NEXT3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 November 2018

  Author:

    John Burkardt
*/
{
  int more;
  int n;
  int *p;
  int rank;

  printf ( "\n" );
  printf ( "PERM0_NEXT3_TEST\n" );
  printf ( "  PERM0_NEXT3 generates permutations of (0,...,N-1).\n" );
  printf ( "\n" );

  n = 4;
  more = 0;
  p = ( int * ) malloc ( n * sizeof ( int ) );
  rank = 0;
 
  for ( ; ; )
  {
    perm0_next3 ( n, p, &more, &rank );

    if ( ! more )
    {
      break;
    }
    perm0_print ( n, p, "" );
  }
 
  free ( p );

  return;
}
/******************************************************************************/

void perm0_print_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_PRINT_TEST tests PERM0_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2015

  Author:

    John Burkardt
*/
{
  int n = 7;
  int p[7] = { 6, 1, 3, 0, 4, 2, 5 };

  printf ( "\n" );
  printf ( "PERM0_PRINT_TEST\n" );
  printf ( "  PERM0_PRINT prints a permutation of (0,...,N-1).\n" );

  perm0_print ( n, p, "  The 0-based permutation:" );
 
  return;
}
/******************************************************************************/

void perm0_random_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_RANDOM_TEST tests PERM0_RANDOM;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int i;
  int p[N];
  int seed = 123456789;

  printf ( "\n" );
  printf ( "PERM0_RANDOM_TEST\n" );
  printf ( "  PERM0_RANDOM produces a random permutation of (0,...,N-1).\n" );
  printf ( "  For this test, N = %d\n", N );
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    perm0_random ( N, &seed, p );
    perm0_print ( N, p, "" );
  }
 
  return;
# undef N
}
/******************************************************************************/

void perm0_random2_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_RANDOM2_TEST tests PERM0_RANDOM2;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int i;
  int p[N];
  int seed = 123456789;

  printf ( "\n" );
  printf ( "PERM0_RANDOM2_TEST\n" );
  printf ( "  PERM0_RANDOM2 produces a random permutation of (0,...,N-1).\n" );
  printf ( "  For this test, N = %d\n", N );
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    perm0_random2 ( N, &seed, p );
    perm0_print ( N, p, "" );
  }
 
  return;
# undef N
}
/******************************************************************************/

void perm0_rank_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_RANK_TEST tests PERM0_RANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 March 2014

  Author:

    John Burkardt
*/
{
  int invers[4];
  int n = 4;
  int p[4] = { 0, 3, 1, 2 };
  int rank;

  printf ( "\n" );
  printf ( "PERM0_RANK_TEST\n" );
  printf ( "  PERM0_RANK ranks a permutation of (0,...,N-1).\n" );

  perm0_print ( n, p, "  The permutation:" );
 
  rank = perm0_rank ( n, p, invers );
 
  printf ( "\n" );
  printf ( "  The rank is %d\n", rank );
 
  return;
}
/******************************************************************************/

void perm0_sign_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_SIGN_TEST tests PERM0_SIGN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 November 2012

  Author:

    John Burkardt
*/
{
# define N 4

  int i;
  int more;
  int p[N];
  int rank;
  int p_sign;

  printf ( "\n" );
  printf ( "PERM0_SIGN_TEST\n" );
  printf ( "  PERM0_SIGN computes the sign of a permutation of (0,...,N-1).\n" );
  printf ( "\n" );
  printf ( "  RANK  SIGN  Permutation\n" );
  printf ( "\n" );

  more = 0;
  rank = 0; 

  for ( ; ; )
  {
    perm0_lex_next ( N, p, &more );

    p_sign = perm0_sign ( N, p );

    if ( !more )
    {
      break;
    }

    printf ( "%4d  %4d", rank, p_sign );

    for ( i = 0; i < N; i++ )
    {
      printf ( "  %4d", p[i] );
    }
    printf ( "\n" );

    rank = rank + 1;
  }
 
  return;
# undef N
}
/******************************************************************************/

void perm0_to_equiv_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_TO_EQUIV_TEST tests PERM0_TO_EQUIV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  int a[9];
  int jarray[9];
  int n = 9;
  int npart;
  int p[9] = { 1,2,8,5,6,7,4,3,0 };

  printf ( "\n" );
  printf ( "PERM0_TO_EQUIV_TEST\n" );
  printf ( "  PERM0_TO_EQUIV returns the set partition\n" );
  printf ( "  or equivalence classes determined by a\n" );
  printf ( "  permutation of (0,...,N-1).\n" );

  perm0_print ( n, p, "  The input permutation:" );
 
  perm0_to_equiv ( n, p, &npart, jarray, a );

  equiv_print ( n, a, "  The partition:" );
 
  return;
}
/******************************************************************************/

void perm0_to_inversion_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_TO_INVERSION_TEST tests PERM0_TO_INVERSION.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2015

  Author:

    John Burkardt
*/
{
# define N 5
 
  int ins[N];
  int perm[N] = { 2, 4, 0, 3, 1 };
  int perm2[N];

  printf ( "\n" );
  printf ( "PERM0_TO_INVERSION_TEST\n" );
  printf ( "  PERM0_TO_INVERSION: permutation (0,...,N-1) to inversion.\n" );
  printf ( "\n" );

  i4vec1_print ( N, perm, "  The permutation:" );
  
  perm0_to_inversion ( N, perm, ins );

  i4vec1_print ( N, ins, "  The inversion sequence:" );

  inversion_to_perm0 ( N, ins, perm2 );

  i4vec1_print ( N, perm2, "  The recovered permutation:" );
 
  return;
# undef N
}
/******************************************************************************/

void perm0_to_ytb_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_TO_YTB_TEST tests PERM0_TO_YTB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  int a[7];
  int lambda[7];
  int n = 7;
  int p[7] = { 6, 1, 3, 0, 4, 2, 5 };

  printf ( "\n" );
  printf ( "PERM0_TO_YTB_TEST\n" );
  printf ( "  PERM0_TO_YTB converts a permutation of (0,...,N-1) to a Young tableau.\n" );

  perm0_print ( n, p, "  The permutation:" );
 
  perm0_to_ytb ( n, p, lambda, a );

  ytb_print ( n, a, "  The Young tableau:" );
 
  return;
}
/******************************************************************************/

void perm0_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM0_UNRANK_TEST tests PERM0_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int n = 4;
  int p[4];
  int rank = 6;

  printf ( "\n" );
  printf ( "PERM0_UNRANK_TEST\n" );
  printf ( "  PERM0_UNRANK, given a rank, computes the\n" );
  printf ( "  corresponding permutation of (0,...,N-1).\n" );
  printf ( "\n" );
  printf ( "  The requested rank is %d\n", rank );
 
  perm0_unrank ( n, rank, p );
 
  perm0_print ( n, p, "  The permutation:" );
 
  return;
}
/******************************************************************************/

void perm1_canon_to_cycle_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM1_CANON_TO_CYCLE_TEST tests PERM1_CANON_TO_CYCLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2015

  Author:

    John Burkardt
*/
{
  int n = 6;
  int p1[6] = { 4, 5, 2, 1, 6, 3 };
  int p2[6];

  printf ( "\n" );
  printf ( "PERM1_CANON_TO_CYCLE_TEST\n" );
  printf ( "  PERM1_CANON_TO_CYCLE converts a permutation of (1,...,N) from\n" );
  printf ( "  canonical to cycle form.\n" );
 
  perm1_print ( n, p1, "  The permutation in canonical form:");
 
  perm1_canon_to_cycle ( n, p1, p2 );

  perm1_print ( n, p2, "  The permutation in cycle form:" );
 
  return;
}
/******************************************************************************/

void perm1_check_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM1_CHECK_TEST tests PERM1_CHECK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 May 2015

  Author:

    John Burkardt
*/
{
  int n = 5;
  int p1[5] = { 5, 2, 3, 4, 1 };
  int p2[5] = { 4, 1, 3, 0, 2 };
  int p3[5] = { 0, 2, 1, 3, 2 };

  printf ( "\n" );
  printf ( "PERM1_CHECK_TEST\n" );
  printf ( "  PERM1_CHECK checks a permutation of (1,...,N).\n" );
  printf ( "\n" );

  perm1_print ( n, p1, "  Permutation 1:" );
  perm1_check( n, p1 );

  perm1_print ( n, p2, "  Permutation 2:" );
  perm1_check( n, p2 );

  perm1_print ( n, p3, "  Permutation 3:" );
  perm1_check( n, p3 );

  return;
}
/******************************************************************************/

void perm1_cycle_to_canon_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM1_CYCLE_TO_CANON_TEST tests PERM1_CYCLE_TO_CANON.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2015

  Author:

    John Burkardt
*/
{
  int n = 6;
  int p1[6] = { -6, 3, 1, -5, 4, -2 };
  int p2[6];

  printf ( "\n" );
  printf ( "PERM1_CYCLE_TO_CANON_TEST\n" );
  printf ( "  PERM1_CYCLE_TO_CANON converts a permutation of (1,...,N) from\n" );
  printf ( "  cycle to canonical form.\n" );
 
  perm1_print ( n, p1, "  The permutation in cycle form:" );
 
  perm1_cycle_to_canon ( n, p1, p2 );

  perm1_print ( n, p2, "  The permutation in canonical form:" );
 
  return;
}
/******************************************************************************/

void perm1_cycle_to_index_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM1_CYCLE_TO_INDEX_TEST tests PERM1_CYCLE_TO_INDEX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2015

  Author:

    John Burkardt
*/
{
  int n = 9;
  int p1[9] = { 2,3,9,6,7,8,5,4,1 };
  int p2[9];
  int p3[9];

  printf ( "\n" );
  printf ( "PERM1_CYCLE_TO_INDEX_TEST\n" );
  printf ( "  PERM1_CYCLE_TO_INDEX converts a permutation of (1,...,N) from\n" );
  printf ( "  cycle to standard index form.\n" );

  perm1_print ( n, p1, "  The standard index form permutation:" );
 
  perm1_index_to_cycle ( n, p1, p2 );

  perm1_print ( n, p2, "  The permutation in cycle form:" );

  perm1_cycle_to_index ( n, p2, p3 );
 
  perm1_print ( n, p3, "  The standard index form permutation:" );
 
  return;
}
/******************************************************************************/

void perm1_index_to_cycle_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM1_INDEX_TO_CYCLE_TEST tests PERM1_INDEX_TO_CYCLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2015

  Author:

    John Burkardt
*/
{
  int n = 9;
  int p1[9] = { 2,3,9,6,7,8,5,4,1 };
  int p2[9];
  int p3[9];

  printf ( "\n" );
  printf ( "PERM1_INDEX_TO_CYCLE_TEST\n" );
  printf ( "  PERM1_INDEX_TO_CYCLE converts a permutation of (1,...,N) from\n" );
  printf ( "  standard index to cycle form.\n" );
 
  perm1_print ( n, p1, "  The standard index form permutation:" );
 
  perm1_index_to_cycle ( n, p1, p2 );

  perm1_print ( n, p2, "  The permutation in cycle form:" );

  perm1_cycle_to_index ( n, p2, p3 );
 
  perm1_print ( n, p3, "  The standard index form permutation:" );
 
  return;
}
/******************************************************************************/

void perm1_print_test ( )

/******************************************************************************/
/*
  Purpose:

    PERM1_PRINT_TEST tests PERM1_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 June 2015

  Author:

    John Burkardt
*/
{
  int n = 7;
  int p[7] = { 7, 2, 4, 1, 5, 3, 6 };

  printf ( "\n" );
  printf ( "PERM1_PRINT_TEST\n" );
  printf ( "  PERM1_PRINT prints a permutation of (1,...,N).\n" );

  perm1_print ( n, p, "  The 1-based permutation:" );
 
  return;
}
/******************************************************************************/

void perrin_test ( )

/******************************************************************************/
/*
  Purpose:

    PERRIN_TEST tests PERRIN;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int i;
  int p[N];

  printf ( "\n" );
  printf ( "PERRIN_TEST\n" );
  printf ( "  PERRIN computes the Perrin numbers.\n" );
  printf ( "\n" );

  perrin ( N, p );

  printf ( "\n" );
  printf ( "   N    P(N)\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d  %6d\n", i, p[i] );
  }

  return;
# undef N
}
/******************************************************************************/

void pord_check_test ( )

/******************************************************************************/
/*
  Purpose:

    PORD_CHECK_TEST tests PORD_CHECK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 May 2015

  Author:

    John Burkardt
*/
{
  int a[10*10] = {
    1,0,1,0,1,0,1,0,0,1, 
    0,1,0,0,1,0,0,0,0,0, 
    0,0,1,0,1,0,1,0,0,1, 
    0,1,1,1,1,1,1,1,0,1, 
    0,0,0,0,1,0,0,0,0,0, 
    0,1,0,0,1,1,1,0,0,0, 
    0,0,0,0,1,0,1,0,0,0, 
    0,1,0,0,1,1,1,1,0,1, 
    0,0,0,0,0,0,0,0,0,0, 
    0,0,0,0,1,0,1,0,0,1 };
  int ierror;
  int n = 10;

  printf ( "\n" );
  printf ( "PORD_CHECK_TEST\n" );
  printf ( "  PORD_CHECK checks a partial ordering.\n" );

  i4mat_print ( n, n, a, "  The partial ordering matrix:" );
 
  ierror = pord_check ( n, a );
 
  printf ( "\n" );
  printf ( "  CHECK FLAG = %d\n", ierror );
  printf ( "  0 means no error.\n" );
  printf ( "  1 means illegal value of N.\n" );
  printf ( "  2 means some A(I,J) and A(J,I) are both nonzero.\n" );
 
  return;
}
/******************************************************************************/

void power_mod_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_MOD_TEST tests POWER_MOD;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 March 2014

  Author:

    John Burkardt
*/
{
  int a;
  int m;
  int n;

  printf ( "\n" );
  printf ( "POWER_MOD_TEST\n" );
  printf ( "  POWER_MOD computes the remainder of a power\n" );
  printf ( "  of an integer modulo another integer.\n" );

  a = 7;
  n = 50;
  m = 11;

  printf ( "\n" );
  printf ( "  A = %d\n", a );
  printf ( "  N = %d\n", n );
  printf ( "  M = %d\n", m );
  printf ( "  mod ( A^N, M ) = %d\n", power_mod ( a, n, m ) );

  a = 3;
  n = 118;
  m = 119;

  printf ( "\n" );
  printf ( "  A = %d\n", a );
  printf ( "  N = %d\n", n );
  printf ( "  M = %d\n", m );
  printf ( "  mod ( A^N, M ) = %d\n", power_mod ( a, n, m ) );

  return;
}
/******************************************************************************/

void power_series1_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_SERIES1_TEST tests POWER_SERIES1;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  double a[N];
  double alpha;
  double b[N];
  int i;

  printf ( "\n" );
  printf ( "POWER_SERIES1_TEST\n" );
  printf ( "  POWER_SERIES1 composes a power series;\n" );

  alpha = 7.0;
 
  a[0] = 1.0;
  for ( i = 1; i < N; i++ )
  {
    a[i] = 0.0;
  }
 
  for ( i = 0; i < N; i++ )
  {
    b[i] = 0.0;
  }

  printf ( "\n" );
  printf ( "  Power series of G(x) = (1+F(x))^alpha\n" );
  printf ( "\n" );
  printf ( "  N = %d\n", N );
  printf ( "  ALPHA = %g\n", alpha );

  r8vec_print ( N, a, "  Series for F(x):" );

  power_series1 ( N, alpha, a, b );
 
  r8vec_print ( N, b, "  Series for G(X):" );

  return;
# undef N
}
/******************************************************************************/

void power_series2_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_SERIES2_TEST tests POWER_SERIES2;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double a[N];
  double b[N];
  int i;

  printf ( "\n" );
  printf ( "POWER_SERIES2_TEST\n" );
  printf ( "  POWER_SERIES2 composes a power series;\n" );

  a[0] = -4.0;
  for ( i = 1; i < N; i++ )
  {
    a[i] = 0.0;
  } 

  printf ( "\n" );
  printf ( "  Power series of G(x) = exp(F(x))-1\n" );
  printf ( "\n" );
  printf ( "  N = %d\n", N );

  r8vec_print ( N, a, "  Series for F(X):" );

  power_series2 ( N, a, b );
 
  r8vec_print ( N, b, "  Series for G(X):" );

  return;
# undef N
}
/******************************************************************************/

void power_series3_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_SERIES3_TEST tests POWER_SERIES3;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double a[N];
  double b[N];
  double c[N];

  printf ( "\n" );
  printf ( "POWER_SERIES3_TEST\n" );
  printf ( "  POWER_SERIES3 composes two power series;\n" );
 
  a[0] = 1.0;
  a[1] = 1.0;
  a[2] = 0.0;
  a[3] = 0.0;

  r8vec_print ( N, a, "  Series for F(X):" );

  b[0] = 1.0;
  b[1] = 1.0;
  b[2] = 0.0;
  b[3] = 0.0;

  r8vec_print ( N, b, "  Series for G(X):" );

  power_series3 ( N, a, b, c );
 
  r8vec_print ( N, c, "  Series for H(X) = G(F(X)):" );

  return;
# undef N
}
/******************************************************************************/

void power_series4_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_SERIES4_TEST tests POWER_SERIES4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
# define N 10
/*
  The order of arguments for POWER_SERIES4 is a shame.
*/
  double a[N];
  double b[N];
  double c[N];
  int i;

  printf ( "\n" );
  printf ( "POWER_SERIES4_TEST\n" );
  printf ( "  POWER_SERIES4 composes a power series;\n" );
  printf ( "  Given power series for F(X) and G(X), we compute\n" );
  printf ( "  the power series of H(x) = G(1/F(x)).\n" );

  for ( i = 0; i < N; i++ )
  {
    a[i] = 1.0 / ( double ) ( i + 1 );
  }
  r8vec_print ( N, a, "  Series for F(x):" );
 
  b[0] = 1.0;
  for ( i = 1; i < N; i++ )
  {
    b[i] = 0.0;
  }
  r8vec_print ( N, b, "  Series for G(x):" );

  power_series4 ( N, a, b, c );
 
  r8vec_print ( N, c, "  Series for H(x):" );

  return;
# undef N
}
/******************************************************************************/

void prime_test ( )

/******************************************************************************/
/*
  Purpose:

    PRIME_TEST tests PRIME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 December 2014

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  int prime_max;

  printf ( "\n" );
  printf ( "PRIME_TEST\n" );
  printf ( "  PRIME returns primes from a table.\n" );

  n = -1;
  prime_max = prime ( n );
  printf ( "\n" );
  printf ( "  Number of primes stored is %d\n", prime_max );
  printf ( "\n" );
  printf ( "     I    Prime(I)\n" );
  printf ( "\n" );
  for ( i = 1; i <= 10; i++ )
  {
    printf ( "  %4d  %6d\n", i, prime ( i ) );
  }
  printf ( "\n" );
  for ( i = prime_max - 10; i <= prime_max; i++ )
  {
    printf ( "  %4d  %6d\n", i, prime ( i ) );
  }
  
  return;
}
/******************************************************************************/

void pythag_triple_next_test ( )

/******************************************************************************/
/*
  Purpose:

    PYTHAG_TRIPLE_NEXT_TEST tests PYTHAG_TRIPLE_NEXT;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int c;
  int d;
  int e;
  int i;
  int j;
  int k;

  printf ( "\n" );
  printf ( "PYTHAG_TRIPLE_NEXT_TEST\n" );
  printf ( "  PYTHAG_TRIPLE_NEXT computes the next\n" );
  printf ( "  Pythagorean triple.\n" );
  printf ( "\n" );
  printf ( "     I       J       A       B       C A^2+B^2     C^2\n" );
  printf ( "\n" );

  i = 0;
  j = 0;

  for ( k = 0; k <= 20; k++ )
  {
    pythag_triple_next ( &i, &j, &a, &b, &c );

    d = a * a + b * b;
    e = c * c;

    printf ( "%6d  %6d  %6d  %6d  %6d  %6d  %6d\n", i, j, a, b, c, d, e );
  }

  return;
}
/******************************************************************************/

void r8_agm_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_AGM_TEST tests R8_AGM;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  int i;
  int seed;
  double x;
  double y;
  double z;

  printf ( "\n" );
  printf ( "R8_AGM_TEST\n" );
  printf ( "  R8_AGM computes the arithmetic-geometric mean (AGM)\n" );
  printf ( "  of two nonnegative real numbers.\n" );

  printf ( "\n" );
  printf ( "    X        Y    R8_AGM(X,Y)\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    x = ( double ) i4_uniform_ab ( 1, 10, &seed );

    y = ( double ) i4_uniform_ab ( 1, 10, &seed );

    z = r8_agm ( x, y );

    printf ( "%10.4g  %10.4g  %10.4g\n", x, y, z );
  }

  return;
}
/******************************************************************************/

void r8_choose_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CHOOSE_TEST tests R8_CHOOSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 December 2013

  Author:

    John Burkardt
*/
{
  double cnk;
  int k;
  int n;

  printf ( "\n" );
  printf ( "R8_CHOOSE_TEST\n" );
  printf ( "  R8_CHOOSE evaluates C(N,K).\n" );
  printf ( "\n" );
  printf ( "     N     K    CNK\n" );
  printf ( "\n" );

  for ( n = 0; n <= 4; n++ )
  {
    for ( k = 0; k <= n; k++ )
    {
      cnk = r8_choose ( n, k );

      printf ( "%6d  %6d  %6g\n", n, k, cnk );
    }
  }

  return;
}
/******************************************************************************/

void r8_epsilon_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_EPSILON_TEST tests R8_EPSILON

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  double r;
  double s;

  printf ( "\n" );
  printf ( "R8_EPSILON_TEST\n" );
  printf ( "  R8_EPSILON produces the floating point machine precision.\n" );
  printf ( "\n" );

  r = r8_epsilon ( );
  printf ( "  R = R8_EPSILON() = %14.6g\n", r );

  s = ( double ) ( 1.0 + r ) - 1.0;
  printf ( "  ( 1 + R ) - 1 = %14.6g\n", s );

  s = ( double ) ( 1.0 + ( double ) ( r / 2.0 ) ) - 1.0;
  printf ( "  ( 1 + (R/2) ) - 1 = %14.6g\n", s );

  return;
}
/******************************************************************************/

void r8_fall_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_FALL_TEST tests R8_FALL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2014

  Author:

    John Burkardt
*/
{
  double f1;
  double f2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_FALL_TEST\n" );
  printf ( "  R8_FALL evaluates the falling factorial Fall(X,N).\n" );
  printf ( "\n" );
  printf ( "    X          N                Exact                  Computed\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    r8_fall_values ( &n_data, &x, &n, &f1 );

    if ( n_data == 0 )
    {
      break;
    }

    f2 = r8_fall ( x, n );

    printf ( "  %8f  %4d  %24.16g  %24.16g\n", x, n, f1, f2 );

  }
 
  return;
}
/******************************************************************************/

void r8_rise_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_RISE_TEST tests R8_RISE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 December 2014

  Author:

    John Burkardt
*/
{
  double f1;
  double f2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_RISE_TEST\n" );
  printf ( "  R8_RISE evaluates the rising factorial Fall(X,N).\n" );
  printf ( "\n" );
  printf ( "    X          N                Exact                  Computed\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    r8_rise_values ( &n_data, &x, &n, &f1 );

    if ( n_data == 0 )
    {
      break;
    }

    f2 = r8_rise ( x, n );

    printf ( "  %8f  %4d  %24.16g  %24.16g\n", x, n, f1, f2 );

  }
 
  return;
}
/******************************************************************************/

void r8_to_cfrac_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_TO_CFRAC_TEST tests R8_TO_CFRAC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
# define N 7

  int a[N+1];
  double err;
  int i;
  int p[N+2];
  int q[N+2];
  double r;
  double temp;

  printf ( "\n" );
  printf ( "R8_TO_CFRAC_TEST\n" );
  printf ( "  R8_TO_CFRAC converts a real number to a sequence\n" );
  printf ( "  of continued fraction convergents.\n" );

  r = 2.0 * r8_pi ( );

  printf ( "\n" );
  printf ( "  Use the real number R = %14.6g\n", r );

  r8_to_cfrac ( r, N, a, p, q );

  printf ( "\n" );
  printf ( " I        A[I]      P[I+1]      Q[I+1]   P[I]/Q[I]    Error\n" );
  printf ( "\n" );

  for ( i = 0; i <= N; i++ )
  {
    temp = ( double ) p[i+1] / ( double ) q[i+1];
    err = temp - r;
    printf ( "  %2d  %10d  %10d  %10d  %10.4g  %10.4g\n", 
      i, a[i], p[i+1], q[i+1], temp, err );
  }

  return;
# undef N
}
/******************************************************************************/

void r8_to_dec_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_TO_DEC_TEST tests R8_TO_DEC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 June 2015

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int dec_digit;
  int i;
  double r;
  double r2;
  double r8_hi;
  double r8_lo;
  int seed;

  printf ( "\n" );
  printf ( "R8_TO_DEC_TEST\n" );
  printf ( "  R8_TO_DEC converts a real number to a decimal;\n" );

  dec_digit = 5;

  printf ( "\n" );
  printf ( "  The maximum number of digits allowed is %d\n", dec_digit );

  r8_lo = -10.0;
  r8_hi = +10.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "     R   =>  A * 10^B  =>  R2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_uniform_ab ( r8_lo, r8_hi, &seed );

    r8_to_dec ( r, dec_digit, &a, &b );
    r2 = dec_to_r8 ( a, b );

    printf ( "  %10.4g  %6d  %6d  %10.4g\n", r, a, b, r2 );
  }

  return;
}
/******************************************************************************/

void r8_to_rat_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_TO_RAT_TEST tests R8_TO_RAT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int i;
  int ndig = 4;
  double r;
  double r2;
  int seed;

  printf ( "\n" );
  printf ( "R8_TO_RAT_TEST\n" );
  printf ( "  R8_TO_RAT converts a real number to a rational;\n" );
  printf ( "\n" );
  printf ( "  The maximum number of digits allowed is %d\n", ndig );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     R   =>  A / B  =>  R2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_uniform_01 ( &seed );
    r = 10.0 * ( r - 0.25 );

    r8_to_rat ( r, ndig, &a, &b );
    r2 = rat_to_r8 ( a, b );

    printf ( "  %10.4g  %6d  %6d  %10.4g\n", r, a, b, r2 );
  }

  return;
}
/******************************************************************************/

void r8mat_det_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_DET_TEST tests R8MAT_DET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N3 3
# define N4 4

  double a3[N3*N3];
  double a4[N4*N4];
  double det;
  int i;
  int j;
  int k;

  printf ( "\n" );
  printf ( "R8MAT_DET_TEST\n" );
  printf ( "  R8MAT_DET: determinant of a real matrix.\n" );
  printf ( "\n" );

  k = 0;
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      k = k + 1;
      a3[i+j*N3] = ( double ) k;
    }
  }

  r8mat_print ( N3, N3, a3, "  The 123/456/789 matrix:" );

  det = r8mat_det ( N3, a3 );

  printf ( "\n" );
  printf ( "  Determinant of the 123/456/789 matrix is %g\n", det );

  for ( i = 0; i < N4; i++ )
  {
    for ( j = 0; j < N4; j++ )
    {
      a4[i+j*N4] = 1.0 / ( double ) ( 2 + i + j );
    }
  }

  r8mat_print ( N4, N4, a4, "  The Hilbert matrix:" );

  det = r8mat_det ( N4, a4 );

  printf ( "\n" );
  printf ( "  Determinant of the Hilbert matrix is %g\n", det );

  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      if ( i == j )
      {
        a3[i+j*N3] = 2.0;
      }
      else if ( i == j+1 || i == j-1 )
      {
        a3[i+j*N3] = -1.0;
      }
      else
      {
        a3[i+j*N3] = 0.0;
      }
    }
  }

  r8mat_print ( N3, N3, a3, "  The -1,2,-1 matrix:" );

  det = r8mat_det ( N3, a3 );

  printf ( "\n" );
  printf ( "  Determinant of the -1,2,-1 matrix is %g\n", det );

  return;
# undef N3
# undef N4
}
/******************************************************************************/

void r8mat_perm0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PERM0_TEST tests R8MAT_PERM0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N 9

  double a[N*N];
  int i;
  int p[N] = { 1,2,8,5,6,7,4,3,0 };
  int j;

  printf ( "\n" );
  printf ( "R8MAT_PERM0_TEST\n" );
  printf ( "  R8MAT_PERM0 reorders a real matrix in place.\n" );
  printf ( "  The rows and columns use the same permutation.\n" );

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*N] = ( double ) ( (i+1) * 10 + (j+1) );
    }
  }

  r8mat_print ( N, N, a, "  The original matrix" );

  perm0_print ( N, p, "  The row and column permutation:" );

  r8mat_perm0 ( N, a, p );

  r8mat_print ( N, N, a, "  The permuted matrix" );

  return;
# undef N
}
/******************************************************************************/

void r8mat_2perm0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_2PERM0_TEST tests R8MAT_2PERM0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define M 9
# define N 7

  double a[M*N];
  int i;
  int j;
  int p[M] = { 1, 2, 8, 5, 6, 7, 4, 3, 0 };
  int q[N] = { 2, 3, 4, 5, 6, 0, 1 };

  printf ( "\n" );
  printf ( "R8MAT_2PERM0_TEST\n" );
  printf ( "  R8MAT_2PERM0 reorders a real matrix in place.\n" );
  printf ( "  Rows and columns use different permutations.\n" );
 
  for ( i = 0; i < M; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*M] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
 
  r8mat_print ( M, N, a, "  The original matrix" );
 
  perm0_print ( M, p, "  The row permutation:" );
 
  perm0_print ( N, q, "  The column permutation:" );

  r8mat_2perm0 ( M, N, a, p, q );
 
  r8mat_print ( M, N, a, "  The permuted matrix" );
 
  return;
# undef M
# undef N
}
/******************************************************************************/

void r8mat_permanent_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PERMANENT_TEST tests R8MAT_PERMANENT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
  double *a;
  int i;
  int j;
  int n;
  double perm;

  printf ( "\n" );
  printf ( "R8MAT_PERMANENT_TEST\n" );
  printf ( "  R8MAT_PERMANENT: the matrix permanent function.\n" );
  printf ( "  We will analyze matrices with 0 diagonal and\n" );
  printf ( "  1 on all offdiagonals.\n" );
  printf ( "\n" );
  printf ( "  Order	    Permanent.\n" );
  printf ( "\n" );

  for ( n = 2; n <= 12; n++ )
  {
    a = ( double * ) malloc ( n * n * sizeof ( double ) );

    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        if ( i == j ) 
        {
          a[i+j*n] = 0.0;
        }
        else
        {
          a[i+j*n] = 1.0;
        }
      }
    }

    perm = r8mat_permanent ( n, a );

    printf ( "%4d  %10g", n, perm );
 
    free ( a );
  }

  return;
}
/******************************************************************************/

void r8poly_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_TEST test R8POLY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int i;
  double a[N];
  int iopt;
  int test;
  double val;
  double x0;

  printf ( "\n" );
  printf ( "R8POLY_TEST\n" );
  printf ( "  R8POLY converts between power sum, factorial\n" );
  printf ( "  and Taylor forms, and can evaluate a polynomial\n" );
  printf ( "\n" );
 
  for ( test = 1; test <= 6; test++ )
  {
    if ( test == 1 )
    {
      iopt = -3;
    }
    else if ( test == 2 )
    {
      iopt = -2;
    }
    else if ( test == 3 )
    {
      iopt = -1;
      x0 = 2.0;
    }
    else if ( test == 4 )
    {
      iopt = 0;
      x0 = 2.0;
    }
    else if ( test == 5 )
    {
      iopt = 6;
      x0 = 2.0;
    }
    else if ( test == 6 )
    {
      iopt = 6;
      x0 = -2.0;
    }

    for ( i = 0; i < N-1; i++ )
    {
      a[i] = 0.0;
    }
    a[N-1] = 1.0;

    if ( test == 1 )
    {
      r8vec_print ( N, a, "  All calls have input A as follows:" );
    }
 
    r8poly ( N, a, x0, iopt, &val );
 
    printf ( "\n" );
    printf ( "  Option IOPT = %d\n", iopt );

    if ( -1 <= iopt )
    {
      printf ( "  X0 = %g\n", x0 );
    }

    if ( iopt == -3 || iopt == -2 || 0 < iopt )
    {
      r8vec_print ( N, a, "  Output array:" );
    }

    if ( iopt == -1 || iopt == 0 )
    {
      printf ( "  Value = %g\n", val );
    }
  }

  return;
# undef N
}
/******************************************************************************/

void r8poly_f2p_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_F2P_TEST tests R8POLY_F2P.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double *a;

  printf ( "\n" );
  printf ( "R8POLY_F2P_TEST\n" );
  printf ( "  R8POLY_F2P: factorial => power sum.\n" );

  a = r8vec_indicator1_new ( N );

  r8poly_print ( N-1, a, "  The power sum polynomial:" );

  r8poly_p2f ( N, a );
 
  r8vec_print ( N, a, "  The factorial coefficients:" );

  r8poly_f2p ( N, a );
 
  r8poly_print ( N-1, a, "  The recovered power sum polynomial:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_fval_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_FVAL_TEST tests R8POLY_FVAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  double *a;
  double val;
  double x;

  printf ( "\n" );
  printf ( "R8POLY_FVAL_TEST\n" );
  printf ( "  R8POLY_FVAL evaluates a polynomial in factorial form.\n" );

  a = r8vec_indicator1_new ( N );
 
  r8vec_print ( N, a, "  The factorial coefficients:" );

  x = 2.0;

  val = r8poly_fval ( N, a, x );

  printf ( "\n" );
  printf ( "  R8POLY (%g) = %g\n", x, val );
  printf ( "  The correct value is 11.\n" );
 
  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_n2p_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_N2P_TEST tests R8POLY_N2P.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int i;
  double *a;
  double a2[N];

  printf ( "\n" );
  printf ( "R8POLY_N2P_TEST\n" );
  printf ( "  R8POLY_N2P: Newton => power sum;\n" );

  a = r8vec_indicator1_new ( N );

  for ( i = 0; i < N; i++ )
  {
    a2[i] = 2.0 * a[i];
  }

  r8poly_print ( N-1, a, "  The power sum polynomial:" );

  r8poly_p2n ( N, a, a2 );
 
  r8vec_print ( N, a, "  Derived Newton form coefficients:" );

  r8vec_print ( N, a2, "  Newton form abscissas:" );

  r8poly_n2p ( N, a, a2 );
 
  r8poly_print ( N-1, a, "  The recovered power sum polynomial:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_nval_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_NVAL_TEST tests R8POLY_NVAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  double *a;
  double a2[N];
  int i;
  double val;
  double x;

  printf ( "\n" );
  printf ( "R8POLY_NVAL_TEST\n" );
  printf ( "  R8POLY_NVAL evaluates a polynomial in Newton form.\n" );

  a = r8vec_indicator1_new ( N );

  for ( i = 0; i < N; i++ )
  {
    a2[i] = a[i] - 1.0;
  }
 
  r8vec_print ( N, a, "  Newton polynomial coefficients:" );

  r8vec_print ( N, a2, "  Newton polynomial abscissas:" );

  x = 2.0;
 
  val = r8poly_nval ( N, a, a2, x );
 

  printf ( "\n" );
  printf ( "  R8POLY (%g) = %g\n", x, val );
  printf ( "  The correct value is 11.\n" );
 
  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_nx_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_NX_TEST tests R8POLY_NX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 June 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int n;
  double x;
  double *xarray;

  printf ( "\n" );
  printf ( "R8POLY_NXL_TEST\n" );
  printf ( "  R8POLY_NX replaces one abscissa in a Newton polynomial.\n" );

  n = 3;

  a = r8vec_indicator1_new ( n );
  xarray = r8vec_indicator1_new ( n );

  r8vec_print ( n, a, "  Newton polynomial coefficients:" );
  r8vec_print ( n, xarray, "  Newton polynomial abscissas:" );
/*
  Shift the X array by inserting X=0.
*/
  x = 0.0;
  printf ( "\n" );
  printf ( "  Replace one abscissa by X = %g\n", x );

  r8poly_nx ( n, a, xarray, x );
/*
  Report the new polynomial form.
*/
  r8vec_print ( n, a, "  Revised Newton polynomial coefficients:" );
  r8vec_print ( n, xarray, "  Revised Newton polynomial abscissas:" );
 
  free ( a );
  free ( xarray );

  return;
}
/******************************************************************************/

void r8poly_p2f_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_P2F_TEST tests R8POLY_P2F.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double *a;

  printf ( "\n" );
  printf ( "R8POLY_P2F_TEST\n" );
  printf ( "  R8POLY_P2F: power sum => factorial;\n" );

  a = r8vec_indicator1_new ( N );

  r8poly_print ( N-1, a, "  The power sum polynomial:" );

  r8poly_p2f ( N, a );
 
  r8vec_print ( N, a, "  The factorial coefficients:" );

  r8poly_f2p ( N, a );
 
  r8poly_print ( N-1, a, "  The recovered power sum polynomial:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_p2n_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_P2N_TEST tests R8POLY_P2N.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int i;
  double *a;
  double a2[N];

  printf ( "\n" );
  printf ( "R8POLY_P2N_TEST\n" );
  printf ( "  R8POLY_P2N: Power sum => Newton.\n" );

  a = r8vec_indicator1_new ( N );

  for ( i = 0; i < N; i++ )
  {
    a2[i] = 2.0 * a[i];
  }

  r8poly_print ( N-1, a, "  The power sum polynomial:" );

  r8poly_p2n ( N, a, a2 );
 
  r8vec_print ( N, a, "  Derived Newton form coefficients:" );

  r8vec_print ( N, a2, "  Newton form abscissas:" );

  r8poly_n2p ( N, a, a2 );
 
  r8poly_print ( N-1, a, "  The recovered power sum polynomial:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_p2t_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_P2T_TEST tests R8POLY_P2T.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double *a;
  double x = 2.0;

  printf ( "\n" );
  printf ( "R8POLY_P2T_TEST\n" );
  printf ( "  R8POLY_P2T: Power sum => Taylor.\n" );
  printf ( "  The Taylor form uses the base point X0 = %g\n", x );

  a = r8vec_indicator1_new ( N + 1 );

  r8vec_print ( N, a, "  Initial Taylor sum form:" );

  r8poly_t2p ( N, a, x );

  r8poly_print ( N, a, "  Power sum form:" );

  r8poly_p2t ( N, a, x );

  r8vec_print ( N, a, "  Recovered Taylor sum form:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_PRINT_TEST tests R8POLY_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2015

  Author:

    John Burkardt
*/
{
  double a[5] = { -2.0, 5.1, 2.2, 3.3, 1.4 };
  int n = 4;

  printf ( "\n" );
  printf ( "R8POLY_PRINT_TEST\n" );
  printf ( "  R8POLY_PRINT prints an R8POLY.\n" );

  r8poly_print ( n, a, "  The polynomial:" );

  return;
}
/******************************************************************************/

void r8poly_pval_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_PVAL_TEST tests R8POLY_PVAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double *a;
  double val;
  double x;

  a = r8vec_indicator1_new ( N + 1 );

  printf ( "\n" );
  printf ( "R8POLY_PVAL_TEST\n" );
  printf ( "  R8POLY_PVAL evaluates a polynomial\n" );
  printf ( "  in power sum form.\n" );

  r8poly_print ( N, a, "  The polynomial to be evaluated:" );

  x = 2.0;
 
  val = r8poly_pval ( N, a, x );

  printf ( "  At X = %g\n", x );
  printf ( "  Computed polynomial value is %g\n", val );
  printf ( "  Correct value is 129.\n" );
 
  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8vec_frac_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_FRAC_TEST tests R8VEC_FRAC;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  double *a;
  double ahi = 10.0;
  double alo = 0.0;
  int k;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "R8VEC_FRAC_TEST\n" );
  printf ( "  R8VEC_FRAC: K-th smallest real vector entry;\n" );

  a = r8vec_uniform_ab_new ( N, alo, ahi, &seed );

  r8vec_print ( N, a, "  The real array to search: " );

  printf ( "\n" );
  printf ( "Frac     Value\n" );
  printf ( "\n" );

  for ( k = 1; k <= N; k++ )
  {
    printf ( "%4d  %10g\n", k, r8vec_frac ( N, a, k ) );

  }

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8poly_t2p_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_T2P_TEST tests R8POLY_T2P.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  double *a;
  double x = 2.0;

  printf ( "\n" );
  printf ( "R8POLY_T2P_TEST\n" );
  printf ( "  R8POLY_T2P: Taylor => Power sum;\n" );
  printf ( "  The Taylor form uses the base point X0 = %g\n", x );

  a = r8vec_indicator1_new ( N + 1 );

  r8vec_print ( N, a, "  Initial Taylor sum form:" );

  r8poly_t2p ( N, a, x );

  r8poly_print ( N, a, "  Power sum form:" );

  r8poly_p2t ( N, a, x );

  r8vec_print ( N, a, "  Recovered Taylor sum form:" );

  free ( a );

  return;
# undef N
}
/******************************************************************************/

void r8vec_backtrack_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_BACKTRACK_TEST tests R8VEC_BACKTRACK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 June 2015

  Author:

    John Burkardt
*/
{
  int found_num;
  int i;
  int indx;
  int k;
  int n = 8;
  int maxstack = 100;
  int ncan[8];
  int nstack;
  double stacks[100];
  double t;
  double total;
  double w[8] = { 15.0, 22.0, 14.0, 26.0, 32.0, 9.0, 16.0, 8.0 };
  double x[8];

  printf ( "\n" );
  printf ( "R8VEC_BACKTRACK_TEST\n" );
  printf ( "  R8VEC_BACKTRACK uses backtracking, seeking a vector X of\n" );
  printf ( "  N values which satisfies some condition.\n" );

  printf ( "\n" );
  printf ( "  In this demonstration, we have 8 values W(I).\n" );
  printf ( "  We seek all subsets that sum to 53.0.\n" );
  printf ( "  X(I) is 0.0 or 1.0 if the entry is skipped or used.\n" );
  printf ( "\n" );

  t = 53.0;

  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }
  indx = 0;
  k = 0;
  nstack = 0;
  for ( i = 0; i < n; i++ )
  {
    ncan[i] = 0;
  }

  found_num = 0;

  for ( ; ; )
  {
    r8vec_backtrack ( n, maxstack, x, &indx, &k, &nstack, stacks, ncan );

    if ( indx == 1 )
    {
      found_num = found_num + 1;
      printf ( "  %2d   ", found_num );

      total = r8vec_dot_product ( n, w, x );
      printf ( "  %6.2f:  ", total );

      for ( i = 0; i < n; i++ )
      {
        if ( x[i] == 1.0 )
        {
          printf ( "  %6.2f", w[i] );
        }
      }
      printf ( "\n" );
    }
/*
  Given that we've chose X(1:K-1), what are our choices for X(K)?

     if T < TOTAL, 
       no choices
     if T = TOTAL, 
       X(K) = 0
     if T > TOTAL and K < N, 
       X(k) = 0
       If ( W(K)+TOTAL <= T ) X(K) = 1
     If T > TOTAL and K = N,
       If ( W(K) + TOTAL) = T ) X(K) = 1
*/
    else if ( indx == 2 )
    {
      total = r8vec_dot_product ( k - 1, w, x );

      if ( t < total )
      {
        ncan[k-1] = 0;
      }
      else if ( t == total )
      {
        ncan[k-1] = ncan[k-1] + 1;
        stacks[nstack] = 0.0;
        nstack = nstack + 1;
      }
      else if ( total < t && k < n )
      {
        ncan[k-1] = ncan[k-1] + 1;
        stacks[nstack] = 0.0;
        nstack = nstack + 1;

        if ( total + w[k-1] <= t )
        {
          ncan[k-1] = ncan[k-1] + 1;
          stacks[nstack] = 1.0;
          nstack = nstack + 1;
        }
      }
      else if ( total < t && k == n )
      {
        if ( total + w[k-1] == t )
        {
          ncan[k-1] = ncan[k-1] + 1;
          stacks[nstack] = 1.0;
          nstack = nstack + 1;
        }
      }
    }
    else
    {
      printf ( "\n" );
      printf ( "  Done!\n" );
      break;
    }
  }

  return;
}
/******************************************************************************/

void r8vec_mirror_next_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_MIRROR_NEXT_TEST tests R8VEC_MIRROR_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define N 3

  double a[N];
  int done;

  printf ( "\n" );
  printf ( "R8VEC_MIRROR_NEXT_TEST\n" );
  printf ( "  R8VEC_MIRROR_NEXT generates all sign variations\n" );
  printf ( "  of a real vector.\n" );

  a[0] = 1.0;
  a[1] = 2.0;
  a[2] = 3.0;

  for ( ; ; )
  {
    r8vec_print ( N, a, "  Next vector:" );

    done = r8vec_mirror_next ( N, a );

    if ( done )
    {
      printf ( "\n" );
      printf ( "  Done.\n" );
      break;
    }
  }

  a[0] = 1.0;
  a[1] = 0.0;
  a[2] = 3.0;

  for ( ; ; )
  {
    r8vec_print ( N, a, "  Next vector:" );

    done = r8vec_mirror_next ( N, a );

    if ( done )
    {
      printf ( "\n" );
      printf ( "  Done.\n" );
      break;
    }
  }

  return;
# undef N
}
/******************************************************************************/

void rat_add_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_ADD_TEST tests RAT_ADD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  int abot = 4;
  int atop = 3;
  int bbot = 7;
  int btop = 10;
  int cbot;
  int ctop;
  int error;

  printf ( "\n" );
  printf ( "RAT_ADD_TEST\n" );
  printf ( "  RAT_ADD adds two rationals.\n" );

  rat_add ( atop, abot, btop, bbot, &ctop, &cbot, &error );

  printf ( "\n" );
  printf ( "  A =         %d/%d\n", atop, abot );
  printf ( "  B =         %d/%d\n", btop, bbot );
  printf ( "  C = A + B = %d/%d\n", ctop, cbot );
 
  return;
}
/******************************************************************************/

void rat_div_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_DIV_TEST tests RAT_DIV.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  int abot = 4;
  int atop = 3;
  int bbot = 7;
  int btop = 10;
  int cbot;
  int ctop;
  int error;

  printf ( "\n" );
  printf ( "RAT_DIV_TEST\n" );
  printf ( "  RAT_DIV divides two rationals.\n" );

  rat_div ( atop, abot, btop, bbot, &ctop, &cbot, &error );

  printf ( "\n" );
  printf ( "  A =         %d/%d\n", atop, abot ); 
  printf ( "  B =         %d/%d\n", btop, bbot ); 
  printf ( "  C = A / B = %d/%d\n", ctop, cbot ); 
 
  return;
}
/******************************************************************************/

void rat_farey_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_FAREY_TEST tests RAT_FAREY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
# define FRAC_MAX 20

  int a[FRAC_MAX];
  int b[FRAC_MAX];
  int frac_num;
  int i;
  int ihi;
  int ilo;
  int n;

  printf ( "\n" );
  printf ( "RAT_FAREY_TEST\n" );
  printf ( "  RAT_FAREY computes a row of the Farey fraction table.\n" );

  for ( n = 1; n <= 7; n++ )
  {
    rat_farey ( n, FRAC_MAX, &frac_num, a, b );
 
    printf ( "\n" );
    printf ( "  Row %d\n", n );
    printf ( "  Number of fractions: %d\n", frac_num );
    printf ( "\n" );

    for ( ilo = 0; ilo < frac_num; ilo = ilo + 20 )
    {
      ihi = i4_min ( ilo+20-1, frac_num-1 );
      for ( i = ilo; i <= ihi; i++ )
      {
        printf ( "%3d", a[i] );
      }
      printf ( "\n" );
      for ( i = ilo; i <= ihi; i++ )
      {
        printf ( "%3d", b[i] );
      }
      printf ( "\n" );
    }

  }

  return;
# undef FRAC_MAX
}
/******************************************************************************/

void rat_farey2_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_FAREY2_TEST tests RAT_FAREY2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 4
# define TWO_POWER_MAX 16

  int a[TWO_POWER_MAX+1];
  int b[TWO_POWER_MAX+1];
  int i;
  int ihi;
  int ilo;
  int n;
  int two_power;

  printf ( "\n" );
  printf ( "RAT_FAREY2_TEST\n" );
  printf ( "  RAT_FAREY2 computes a row of the Farey fraction table.\n" );

  for ( n = 0; n <= N_MAX; n++ )
  {
    rat_farey2 ( n, a, b );
 
    printf ( "\n" );
    printf ( "  Row %d\n", n+1 );

    two_power = i4_power ( 2, n );

    for ( ilo = 0; ilo <= two_power; ilo = ilo + 20 )

    {
      ihi = i4_min ( ilo+20-1, two_power );
      printf ( "\n" );
      for ( i = ilo; i <= ihi; i++ )
      {
        printf ( "%3d", a[i] );
      }
      printf ( "\n" );
      for ( i = ilo; i <= ihi; i++ )
      {
        printf ( "%3d", b[i] );
      }
      printf ( "\n" );

    }

  }

  return;
# undef N_MAX
# undef TWO_POWER_MAX
}
/******************************************************************************/

void rat_mul_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_MUL_TEST tests RAT_MUL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
  int abot = 4;
  int atop = 3;
  int bbot = 7;
  int btop = 10;
  int cbot;
  int ctop;
  int error;

  printf ( "\n" );
  printf ( "RAT_MUL_TEST\n" );
  printf ( "  RAT_MUL multiplies two rationals.\n" );

  rat_mul ( atop, abot, btop, bbot, &ctop, &cbot, &error );

  printf ( "\n" );
  printf ( "  A =         %d/%d\n", atop, abot );
  printf ( "  B =         %d/%d\n", btop, bbot );
  printf ( "  C = A * B = %d/%d\n", ctop, cbot );
 
  return;
}
/******************************************************************************/

void rat_normalize_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_NORMALIZE_TEST tests RAT_NORMALIZE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 June 2015

  Author:

    John Burkardt
*/
{
  int a1;
  int a2;
  int b1;
  int b2;
  int i;
  int rat_top[7] = { 3, 1,    20,  8, -10,   9, -11 };
  int rat_bot[7] = { 4, 1000,  1,  4,   7, -15, -11 };

  printf ( "\n" );
  printf ( "RAT_NORMALIZE_TEST\n" );
  printf ( "  RAT_NORMALIZE normalizes a rational.\n" );

  printf ( "\n" );
  printf ( "       A       B       A       B\n" );
  printf ( "                       Normalized\n" );
  printf ( "\n" );

  for ( i = 0; i < 7; i++ )
  {
    a1 = rat_top[i];
    b1 = rat_bot[i];
    a2 = a1;
    b2 = b1;
    rat_normalize ( &a2, &b2 );
    printf ( "  %6d  %6d    %6d  %6d\n", a1, b1, a2, b2 );
  }

  return;
}
/******************************************************************************/

void rat_to_cfrac_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_TO_CFRAC_TEST tests RAT_TO_CFRAC.

  Discussion:

    Compute the continued fraction form of 4096/15625.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 November 2013

  Author:

    John Burkardt
*/
{
# define M 10

  int a[M];
  int bot = 15625;
  int error;
  int i;
  int n;
  int p[M];
  int q[M];
  int top = 4096;

  printf ( "\n" );
  printf ( "RAT_TO_CFRAC_TEST\n" );
  printf ( "  RAT_TO_CFRAC fraction => continued fraction,\n" );
  printf ( "\n" );
  printf ( "  Regular fraction is %d/%d\n", top, bot );

  rat_to_cfrac ( top, bot, M, &n, a, &error );
 
  i4vec1_print ( n, a, "  Continued fraction coefficients:" );

  cfrac_to_rat ( n, a, p, q );
 
  printf ( "\n" );
  printf ( "  The continued fraction convergents.\n" );
  printf ( "  The last row contains the value of the continued\n" );
  printf ( "  fraction, written as a common fraction.\n" );
  printf ( "\n" );
  printf ( "  I, P(I), Q(I), P(I)/Q(I)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "%3d  %6d  %6d  %14g\n", 
      i, p[i], q[i], ( double ) p[i] / ( double ) q[i] );
  }
 
  return;
# undef M
}
/******************************************************************************/

void rat_to_dec_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_TO_DEC_TEST tests RAT_TO_DEC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2014

  Author:

    John Burkardt
*/
{
  int exponent;
  int i;
  int mantissa;
  double r1;
  double r2;
  double r3;
  int rat_bot;
  int rat_bot2;
  int rat_top;
  int rat_top2;
  int seed;

  printf ( "\n" );
  printf ( "RAT_TO_DEC_TEST\n" );
  printf ( "  RAT_TO_DEC fraction => decimal,\n" );
  printf ( "\n" );
  printf ( "  In this test, choose the top and bottom\n" );
  printf ( "  of a rational at random, and compute the\n" );
  printf ( "  equivalent real number.\n" );
  printf ( "\n" );
  printf ( "  Then convert to decimal, and the equivalent real.\n" );
  printf ( "\n" );
  printf ( "  Then convert back to rational and the equivalent real.\n" );
  
  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    rat_top = i4_uniform_ab ( -1000, 1000, &seed );
    rat_bot = i4_uniform_ab (     1, 1000, &seed );

    r1 = ( double ) rat_top / ( double ) rat_bot;

    rat_to_dec ( rat_top, rat_bot, &mantissa, &exponent );
    r2 = ( double ) mantissa * pow ( 10.0, exponent );

    dec_to_rat ( mantissa, exponent, &rat_top2, &rat_bot2 );
    r3 = ( double ) rat_top2 / ( double ) rat_bot2;

    printf ( "\n" );
    printf ( "  %g = %d / %d\n", r1, rat_top, rat_bot );
    printf ( "  %g = %d * 10 ^ %d\n", r2, mantissa, exponent );
    printf ( "  %g = %d / %d\n", r3, rat_top2, rat_bot2 );
  }
 
  return;
}
/******************************************************************************/

void rat_to_r8_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_TO_R8_TEST tests RAT_TO_R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 March 2014

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int i;
  int ndig = 4;
  double r;
  double r2;
  int seed;

  printf ( "\n" );
  printf ( "RAT_TO_R8_TEST\n" );
  printf ( "  RAT_TO_R8 converts a rational to a real number.\n" );
  printf ( "\n" );
  printf ( "  The maximum number of digits allowed is %d\n", ndig );

  seed = 123456789;

  printf ( "\n" );
  printf ( "     R   =>  A / B  =>  R2\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    r = r8_uniform_01 ( &seed );
    r = 10.0 * ( r - 0.25 );

    r8_to_rat ( r, ndig, &a, &b );
    r2 = rat_to_r8 ( a, b );

    printf ( "  %10.4g  %6d  %6d  %10.4g\n", r, a, b, r2 );
  }

  return;
}
/******************************************************************************/

void rat_to_s_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_TO_S_TEST tests RAT_TO_S.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 June 2015

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int i;
  int rat_top[7] = { 3, 1,    20,  8, -10,   9, -11 };
  int rat_bot[7] = { 4, 1000,  1,  4,   7, -15, -11 };
  char *s;

  printf ( "\n" );
  printf ( "RAT_TO_S_TEST\n" );
  printf ( "  RAT_TO_S converts a rational to a string.\n" );

  printf ( "\n" );
  printf ( "       A       B      S\n" );
  printf ( "\n" );

  for ( i = 0; i < 7; i++ )
  {
    a = rat_top[i];
    b = rat_bot[i];
    s = rat_to_s ( a, b );
    printf ( "  %6d  %6d  %s\n", a, b, s );
    free ( s );
  }

  return;
}
/******************************************************************************/

void rat_width_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_WIDTH_TEST tests RAT_WIDTH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N_TEST 17

  int a;
  int a_test[N_TEST] = {
    1000, 1000, 1000, 1000, 1000, 1, -1, -10, -100, -1000,
    1, 10, 100, 1000, 10000, 17, 4000000 };
  int b;
  int b_test[N_TEST] = {
    3, 40, 500, 6000, 70000, 1, 200, 200, 200, 200, 
   -200, -200, -200, -200, -200, 3000, 4000000 };
  int i;
  int width;

  printf ( "\n" );
  printf ( "RAT_WIDTH_TEST\n" );
  printf ( "  RAT_WIDTH determines the \"width\" of a rational.\n" );
  printf ( "\n" );
  printf ( "  Top    Bottom  Width\n" );
  printf ( "\n" );

  for ( i = 0; i < N_TEST; i++ )
  {
    a = a_test[i];
    b = b_test[i];

    width = rat_width ( a, b );

    printf ( "  %8d  %8d  %8d\n", a, b, width );
  }

  return;
# undef N_TEST
}
/******************************************************************************/

void rat_sum_formula_test ( )

/******************************************************************************/
/*
  Purpose:

    RAT_SUM_FORMULA_TEST tests RAT_SUM_FORMULA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int a[(N+1)*(N+1)];
  int b[(N+1)*(N+1)];

  printf ( "\n" );
  printf ( "RAT_SUM_FORMULA_TEST\n" );
  printf ( "  RAT_SUM_FORMULA computes the coefficients for the\n" );
  printf ( "  formulas for the sums of powers of integers.\n" );
  
  rat_sum_formula ( N, a, b );

  ratmat_print ( N+1, N+1, a, b, "  Power Sum Coefficients:" );

  return;
# undef N
}
/******************************************************************************/

void ratmat_det_test ( )

/******************************************************************************/
/*
  Purpose:

    RATMAT_DET_TEST tests RATMAT_DET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N3 3

  int a3[N3*N3];
  int b3[N3*N3];
  int error;
  int i;
  int idbot;
  int idtop;
  int j;
  int k;

  printf ( "\n" );
  printf ( "RATMAT_DET_TEST\n" );
  printf ( "  RATMAT_DET: determinant of a rational matrix.\n" );
  printf ( "\n" );
 
  k = 0;
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      k = k + 1;
      a3[i+j*N3] = k;
    }
  }

  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      b3[i+j*N3] = 1;
    }
  }
 
  ratmat_print ( N3, N3, a3, b3, "  The 123/456/789 matrix:" );

  ratmat_det ( N3, a3, b3, &idtop, &idbot, &error );
 
  printf ( "\n" );
  printf ( "  Determinant of the 123/456/789 matrix = %d/%d", idtop, idbot );
 
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      a3[i+j*N3] = 1;
    }
  }
 
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      b3[i+j*N3] = i + j + 2;
    }
  }
  ratmat_print ( N3, N3, a3, b3, "  The Hilbert matrix:" );

  ratmat_det ( N3, a3, b3, &idtop, &idbot, &error );
 
  printf ( "\n" );
  printf ( "  Determinant of the Hilbert matrix = %d/%d", idtop, idbot );
 
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      if ( i == j )
      {
        a3[i+j*N3] = 2;
      }
      else if ( i == j+1 || i == j-1 )
      {
        a3[i+j*N3] = -1;
      }
      else
      {
        a3[i+j*N3] = 0;
      }
    }
  }
 
  for ( i = 0; i < N3; i++ )
  {
    for ( j = 0; j < N3; j++ )
    {
      b3[i+j*N3] = 1;
    }
  }

  ratmat_print ( N3, N3, a3, b3, "  The -1 2 -1 matrix:" );

  ratmat_det ( N3, a3, b3, &idtop, &idbot, &error );
 
  printf ( "\n" );
  printf ( "  Determinant of the -1,2,-1 matrix = %d/%d", idtop, idbot );
 
  return;
# undef N3
}
/******************************************************************************/

void ratmat_print_test ( )

/******************************************************************************/
/*
  Purpose:

    RATMAT_PRINT_TEST tests RATMAT_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    31 May 2015

  Author:

    John Burkardt
*/
{
  int a[4*3];
  int b[4*3];
  int i;
  int j;
  int m = 4;
  int n = 3;

  printf ( "\n" );
  printf ( "RATMAT_PRINT_TEST\n" );
  printf ( "  RATMAT_PRINT prints a rational matrix.\n" );
  printf ( "\n" );
 
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i+j*m] = 1;
    }
  }
 
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      b[i+j*m] = i + j + 2;
    }
  }
  ratmat_print ( m, n, a, b, "  The Hilbert matrix:" );

  return;
}
/******************************************************************************/

void regro_next_test ( )

/******************************************************************************/
/*
  Purpose:

    REGRO_NEXT_TEST tests REGRO_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
# define N 4

  int done;
  int i;
  int rank;
  int v[N];
  int vmax[N];

  printf ( "\n" );
  printf ( "REGRO_NEXT_TEST\n" );
  printf ( "  REGRO_NEXT generates all restricted growth\n" );
  printf ( "  functions.\n" );
  printf ( "\n" );

  rank = 0;

  done = 1;
 
  for ( ; ; )
  {
    regro_next ( &done, N, v, vmax );

    if ( done )
    {
      break;
    }

    rank = rank + 1;
    printf ( "  %3d  ", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%d  ", v[i]  );
    }
    printf ( "\n" );

  }
 
  return;
# undef N
}
/******************************************************************************/

void rfrac_to_cfrac_test ( )

/******************************************************************************/
/*
  Purpose:

    RFRAC_TO_CFRAC_TEST tests RFRAC_TO_CFRAC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 November 2013

  Author:

    John Burkardt
*/
{
# define MAXM 10

  int error;
  double g[2*MAXM];
  double h[2*MAXM];
  int i;
  int m;
  double p[MAXM];
  double q[MAXM+1];

  m = 3;

  p[0] = 1.0;
  p[1] = 1.0;
  p[2] = 2.0;

  q[0] = 1.0;
  q[1] = 3.0;
  q[2] = 1.0;
  q[3] = 1.0;

  printf ( "\n" );
  printf ( "RFRAC_TO_CFRAC_TEST\n" );
  printf ( "  RFRAC_TO_CFRAC: ratio to continued fration.\n" );

  printf ( "\n" );
  printf ( "  Rational polynomial fraction coefficients:\n" );
  printf ( "\n" );

  printf ( "  P:  " );
  for ( i = 0; i < m; i++ )
  {
    printf ( "%12g", p[i] );
  }
  printf ( "\n" );

  printf ( "  Q:  " );
  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%12g", q[i] );
  }
  printf ( "\n" );

  rfrac_to_cfrac ( m, p, q, h, &error );
 
  r8vec_print ( 2*m, h, "  Continued fraction coefficients:" );

  for ( i = 0; i < 2 * m; i++ )
  {
    g[i] = 1.0;
  }

  cfrac_to_rfrac ( 2 * m, g, h, p, q );
 
  printf ( "\n" );
  printf ( "  Recovered rational polynomial:\n" );
  printf ( "\n" );
  
  printf ( "  P:  " );
  for ( i = 0; i < m; i++ )
  {
    printf ( "%12g", p[i] );
  }
  printf ( "\n" );

  printf ( "  Q:  " );
  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%12g", q[i] );
  }
  printf ( "\n" );

  return;
# undef MAXM
}
/******************************************************************************/

void rfrac_to_jfrac_test ( )

/******************************************************************************/
/*
  Purpose:

    RFRAC_TO_JFRAC_TEST tests RFRAC_TO_JFRAC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 October 2010

  Author:

    John Burkardt
*/
{
# define MAXM 10

  int i;
  int m;
  double p[MAXM];
  double q[MAXM];
  double r[MAXM];
  double s[MAXM];
  int seed;
/*
  Generate the data, but force Q(M+1) to be 1.  
  That will make it easier to see that the two operations are inverses
  of each other.  JFRAC_TO_RFRAC is free to scale its output, and chooses
  a scaling in which Q(M+1) is 1.
*/
  seed = 123456789;
  m = 6;
  r8vec_uniform_01 ( m, &seed, p );
  r8vec_uniform_01 ( m + 1, &seed, q );

  for ( i = 0; i < m; i++ )
  {
    q[i] = q[i] / q[m];
  }
  q[m] = 1.0;

  printf ( "\n" );
  printf ( "RFRAC_TO_JFRAC_TEST\n" );
  printf ( "  RFRAC_TO_JFRAC converts a rational polynomial\n" );
  printf ( "  fraction to a J fraction.\n" );
  printf ( "\n" );
  printf ( "  The original rational polynomial coefficients:\n" );
  printf ( "\n" );

  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", p[i] );
  }
  printf ( "\n" );

  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%14f  ", q[i] );
  }
  printf ( "\n" );
 
  rfrac_to_jfrac ( m, p, q, r, s );
 
  printf ( "\n" );
  printf ( "  The J fraction coefficients:\n" );
  printf ( "\n" );

  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", r[i] );
  }
  printf ( "\n" );
  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", s[i] );
  }
  printf ( "\n" );
 
  jfrac_to_rfrac ( m, r, s, p, q );

  printf ( "\n" );
  printf ( "  The recovered rational polynomial:\n" );
  printf ( "\n" );

  for ( i = 0; i < m; i++ )
  {
    printf ( "%14f  ", p[i] );
  }
  printf ( "\n" );

  for ( i = 0; i < m + 1; i++ )
  {
    printf ( "%14f  ", q[i] );
  }
  printf ( "\n" );

  return;
# undef MAXM
}
/******************************************************************************/

void schroeder_test ( )

/******************************************************************************/
/*
  Purpose:

    SCHROEDER_TEST tests SCHROEDER;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
  int i;
  int n = 10;
  int s[10];

  printf ( "\n" );
  printf ( "SCHROEDER_TEST\n" );
  printf ( "  SCHROEDER computes the Schroeder numbers.\n" );

  schroeder ( n, s );

  printf ( "\n" );
  printf ( "   N    S(N)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %4d  %6d\n", i+1, s[i] );
  }

  return;
}
/******************************************************************************/

void sort_heap_external_test ( )

/******************************************************************************/
/*
  Purpose:

    SORT_HEAP_EXTERNAL_TEST tests SORT_HEAP_EXTERNAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  int *a;
  int i;
  int i1;
  int indx;
  int isgn;
  int j;
  int j1;
  int k0;
  int k1;
  int n = 20;
  int n1;
  int seed;
  int temp;

  printf ( "\n" );
  printf ( "SORT_HEAP_EXTERNAL_TEST\n" );
  printf ( "  SORT_HEAP_EXTERNAL sorts objects externally.\n" );

  seed = 123456789;

  a = i4vec_uniform_ab_new ( n, 1, n, &seed );

  i4vec1_print ( n, a, "  Before sorting:" );
 
  indx = 0;
  i = 0;
  j = 0;
  isgn = 0;
  i1 = 0;
  j1 = 0;
  k0 = 0;
  k1 = 0;
  n1 = 0;

  for ( ; ; )
  {
    sort_heap_external ( n, &indx, &i, &j, isgn, &i1, &j1, &k0, &k1, &n1 );
 
    if ( indx < 0 )
    {

      if ( a[i-1] <= a[j-1] )
      {
        isgn = -1;
      }
      else
      {
        isgn = +1;
      }
    }
    else if ( 0 < indx )
    {
      temp = a[i-1];
      a[i-1] = a[j-1];
      a[j-1] = temp;
    }
    else
    {
      break;
    }

  }

  i4vec1_print ( n, a, "  After sorting:" ); 

  free ( a );
 
  return;
}
/******************************************************************************/

void subset_by_size_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_BY_SIZE_NEXT_TEST tests SUBSET_BY_SIZE_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 June 2015

  Author:

    John Burkardt
*/
{
  int *a;
  int i;
  int m;
  int m2;
  int more;
  int more2;
  int n;
  int rank;
  int subsize;

  printf ( "\n" );
  printf ( "SUBSET_BY_SIZE_NEXT_TEST\n" );
  printf ( "  SUBSET_BY_SIZE_NEXT generates all subsets of an N set.\n" );
  printf ( "\n" );

  n = 5;
  a = ( int * ) malloc ( n * sizeof ( int ) );
  subsize = 0;
  more = 0;
  more2 = 0;
  m = 0;
  m2 = 0;

  rank = 0;

  for ( ; ; )
  {
    subset_by_size_next ( n, a, &subsize, &more, &more2, &m, &m2 );

    rank = rank + 1;

    printf ( "%4d  ", rank );

    if ( 0 < subsize )
    {
      for ( i = 0; i < subsize; i++ )
      {
        printf ( "%2d  ", a[i] );
      }
      printf ( "\n" );
    }
    else
    {
      printf ( "The empty set\n" );
    }

    if ( !more )
    {
      break;
    }

  }

  free ( a );

  return;
}
/******************************************************************************/

void subset_lex_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_LEX_NEXT_TEST tests SUBSET_LEX_NEXT with size restrictions.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define NDIM 3

  int a[NDIM];
  int i;
  int k;
  int ltest;
  int n = 5;

  printf ( "\n" );
  printf ( "SUBSET_LEX_NEXT_TEST\n" );
  printf ( "  SUBSET_LEX_NEXT generates all subsets of an N set.\n" );
  printf ( "  The user can impose a restriction on the\n" );
  printf ( "  maximum size of the subsets.\n" );
  printf ( "\n" );
  printf ( "  Here, we require the subsets to be no larger\n" );
  printf ( "  than NDIM = %d\n", NDIM );

  k = 0;
 
  for ( ; ; )
  {
    ltest = ( k == NDIM );

    subset_lex_next ( n, ltest, NDIM, &k, a );
 
    if ( 0 < k )
    {
      printf ( "  " );
      for ( i = 0; i < k; i++ )
      {
        printf ( "%2d  ", a[i] );
      }
      printf ( "\n" );
    }
    else
    {
      printf ( "  The empty set.\n" );
    }
 
    if ( k == 0 )
    {
      break;
    }

  }
 
  return;
# undef NDIM
}
/******************************************************************************/

void subset_gray_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_GRAY_NEXT_TEST tests SUBSET_GRAY_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N];
  int i;
  int j;
  int iadd;
  int more;
  int ncard;

  printf ( "\n" );
  printf ( "SUBSET_GRAY_NEXT_TEST\n" );
  printf ( "  SUBSET_GRAY_NEXT generates all subsets of an N set\n" );
  printf ( "  using the Gray code ordering:\n" );
  printf ( "  0 0 1 0 1 means the subset contains 3 and 5.\n" );
  printf ( "\n" );
  printf ( "  Gray code\n" );
  printf ( "\n" );

  more = 0;
  j = 0;

  for ( ; ; )
  {
    subset_gray_next ( N, a, &more, &ncard, &iadd );

    j = j + 1;
    printf ( "%4d  ", j );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%2d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }

  }

  return;

# undef N
}
/******************************************************************************/

void subset_random_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_RANDOM_TEST tests SUBSET_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N];
  int i;
  int j;
  int seed;

  printf ( "\n" );
  printf ( "SUBSET_RANDOM_TEST\n" );
  printf ( "  SUBSET_RANDOM picks a subset at random.\n" );
  printf ( "  The number of elements in the main set is %d\n", N );
  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 5; j++ )
  {
    subset_random ( N, &seed, a );

    printf ( "%4d   ", j  );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%2d", a[i] );
    }
    printf ( "\n" );

  }

  return;
# undef N
}
/******************************************************************************/

void subset_gray_rank_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_GRAY_RANK_TEST tests SUBSET_GRAY_RANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N] = { 1, 0, 1, 1, 0 };
  int i;
  int rank;

  printf ( "\n" );
  printf ( "SUBSET_GRAY_RANK_TEST\n" );
  printf ( "  SUBSET_GRAY_RANK returns rank of a subset of an N set\n" );
  printf ( "  using the Gray code ordering.\n" );
  printf ( "\n" );
  printf ( "  For N = %d, the subset is:\n", N );

  printf ( "  " );
  for ( i = 0; i < N; i++ )
  {
    printf ( "%d ", a[i] );
  }
  printf ( "\n" );
 
  rank = subset_gray_rank ( N, a );
 
  printf ( "\n" );
  printf ( "  The rank is %d\n", rank );
 
  return;
# undef N
}
/******************************************************************************/

void subset_gray_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBSET_GRAY_UNRANK_TEST tests SUBSET_GRAY_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 5

  int a[N];
  int i;
  int rank;

  printf ( "\n" );
  printf ( "SUBSET_GRAY_UNRANK_TEST\n" );
  printf ( "  SUBSET_GRAY_UNRANK finds the subset of an N set\n" );
  printf ( "  of a given rank under the Gray code ordering.\n" );
  printf ( "\n" );
  printf ( "  N is %d\n", N );
  printf ( "\n" );
  printf ( "  Rank   Subset\n" );
  printf ( "\n" );

  for ( rank = 1; rank <= 10; rank++ )
  {
    subset_gray_unrank ( rank, N, a );

    printf ( "  %4d  ", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%2d", a[i] );
    }
    printf ( "\n" );

  }
 
  return;
# undef N
}
/******************************************************************************/

void subcomp_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBCOMP_NEXT_TEST tests SUBCOMP_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 June 2015

  Author:

    John Burkardt
*/
{
  int *a;
  int h;
  int i;
  int k;
  int more;
  int more2;
  int n;
  int n2;
  int rank;
  int t;
  int total;

  n = 6;
  k = 3;
  a = ( int * ) malloc ( k * sizeof ( int ) );
  more = 0;
  h = 0;
  t = 0;
  n2 = 0 ;
  more2 = 0;

  printf ( "\n" );
  printf ( "SUBCOMP_NEXT_TEST\n" );
  printf ( "  SUBCOMP_NEXT generates subcompositions.\n" );
  printf ( "\n" );
  printf ( "  Seek all subcompositions of N = %d\n", n );
  printf ( "  using K = %d parts.\n", k );
  printf ( "\n" );
  printf ( "     #   Sum\n" );
  printf ( "\n" );

  rank = 0;

  for ( ; ; )
  {
    subcomp_next ( n, k, a, &more, &h, &t, &n2, &more2 );

    total = 0;
    for ( i = 0; i < k; i++ )
    {
      total = total + a[i];
    }
    rank = rank + 1;
    printf ( "  %4d  %4d  ", rank, total );

    for ( i = 0; i < k; i++ )
    {
      printf ( "%4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }
  }

  free ( a );

  return;
}
/******************************************************************************/

void subcompnz_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBCOMPNZ_NEXT_TEST tests SUBCOMPNZ_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 June 2015

  Author:

    John Burkardt
*/
{
  int *a;
  int h;
  int i;
  int k;
  int more;
  int more2;
  int n;
  int n2;
  int rank;
  int t;
  int total;

  n = 6;
  k = 3;
  a = ( int * ) malloc ( k * sizeof ( int ) );
  more = 0;
  h = 0;
  t = 0;
  n2 = 0 ;
  more2 = 0;

  printf ( "\n" );
  printf ( "SUBCOMPNZ_NEXT_TEST\n" );
  printf ( "  SUBCOMPNZ_NEXT generates subcompositions using nonzero parts.\n" );
  printf ( "\n" );
  printf ( "  Seek all subcompositions of N = %d\n", n );
  printf ( "  using K = %d nonzero parts.\n", k );
  printf ( "\n" );
  printf ( "     #   Sum\n" );
  printf ( "\n" );

  rank = 0;

  for ( ; ; )
  {
    subcompnz_next ( n, k, a, &more, &h, &t, &n2, &more2 );

    total = 0;
    for ( i = 0; i < k; i++ )
    {
      total = total + a[i];
    }
    rank = rank + 1;
    printf ( "  %4d  %4d  ", rank, total );

    for ( i = 0; i < k; i++ )
    {
      printf ( "%4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }
  }

  free ( a );

  return;
}
/******************************************************************************/

void subcompnz2_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBCOMPNZ2_NEXT_TEST tests SUBCOMPNZ2_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 June 2015

  Author:

    John Burkardt
*/
{
  int *a;
  int rank;
  int h;
  int i;
  int k;
  int more;
  int more2;
  int n;
  int n_hi;
  int n_lo;
  int n2;
  int t;

  n_lo = 5;
  n_hi = 7;
  k = 3;
  a = ( int * ) malloc ( k * sizeof ( int ) );
  more = 0;
  h = 0;
  t = 0;
  n2 = 0 ;
  more2 = 0;

  printf ( "\n" );
  printf ( "SUBCOMPNZ2_NEXT_TEST\n" );
  printf ( "  SUBCOMPNZ2_NEXT generates subcompositions using nonzero parts.\n" );
  printf ( "\n" );
  printf ( "  Seek all subcompositions of N\n" );
  printf ( "  using K = %d nonzero parts.\n", k );
  printf ( "\n" );
  printf ( "  Here N is in the range %d <= N <= %d\n", n_lo, n_hi );
  printf ( "\n" );
  printf ( "     #     N\n" );
  printf ( "\n" );

  rank = 0;

  for ( ; ; )
  {
    subcompnz2_next ( n_lo, n_hi, k, a, &more, &h, &t, &n2, &more2 );

    n = 0;
    for ( i = 0; i < k; i++ )
    {
      n = n + a[i];
    }
    rank = rank + 1;
    printf ( "  %4d  %4d  ", rank, n );

    for ( i = 0; i < k; i++ )
    {
      printf ( "%4d", a[i] );
    }
    printf ( "\n" );

    if ( !more )
    {
      break;
    }
  }

  free ( a );

  return;
}
/******************************************************************************/

void subtriangle_next_test ( )

/******************************************************************************/
/*
  Purpose:

    SUBTRIANGLE_NEXT_TEST tests SUBTRIANGLE_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
  int i1;
  int i2;
  int i3;
  int j1;
  int j2;
  int j3;
  int more;
  int n;
  int rank;

  n = 4;
  rank = 0;

  more = 0;
  i1 = 0;
  j1 = 0;
  i2 = 0;
  j2 = 0;
  i3 = 0;
  j3 = 0;

  printf ( "\n" );
  printf ( "SUBTRIANGLE_NEXT_TEST\n" );
  printf ( "  SUBTRIANGLE_NEXT generates the indices of subtriangles\n" );
  printf ( "  in a triangle whose edges were divided into N subedges.\n" );
  printf ( "\n" );
  printf ( "  For this test, N = %d\n", n );
  printf ( "\n" );
  printf ( "  Rank    I1  J1    I2  J2    I3  J3\n" );
  printf ( "\n" );

  for ( ; ; )
  {
    subtriangle_next ( n, &more, &i1, &j1, &i2, &j2, &i3, &j3 );

    rank = rank + 1;

    printf ( "  %4d  %2d  %2d  %2d  %2d  %2d  %2d\n",
      rank, i1, j1, i2, j2, i3, j3 ); 

    if ( !more )
    {
      break;
    }

  }

  return;
}
/******************************************************************************/

void thue_binary_next_test ( )

/******************************************************************************/
/*
  Purpose:

    THUE_BINARY_NEXT_TEST tests THUE_BINARY_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 100

  int i;
  int j;
  int n;
  int thue[N_MAX];

  printf ( "\n" );
  printf ( "THUE_BINARY_NEXT_TEST\n" );
  printf ( "  THUE_BINARY_NEXT returns the next\n" );
  printf ( "  Thue binary sequence.\n" );
  printf ( "\n" );

  n = 1;
  thue[0] = 0;
  printf ( "%4d   ", n );
  for ( i = 0; i < n; i++ )
  {
    printf ( "%d", thue[i] );
  }
  printf ( "\n" );

  for ( i = 1; i <= 6; i++ )
  {
    thue_binary_next ( &n, thue );

    printf ( "%4d   ", n );
    for ( j = 0; j < n; j++ )
    {
      printf ( "%d", thue[j] );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void thue_ternary_next_test ( )

/******************************************************************************/
/*
  Purpose:

    THUE_TERNARY_NEXT_TEST tests THUE_TERNARY_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 100

  int i;
  int j;
  int n;
  int thue[N_MAX];

  printf ( "\n" );
  printf ( "THUE_TERNARY_NEXT_TEST\n" );
  printf ( "  THUE_TERNARY_NEXT returns the next\n" );
  printf ( "  Thue ternary sequence.\n" );
  printf ( "\n" );

  n = 1;
  thue[0] = 1;
  printf ( "%4d   ", n );
  for ( i = 0; i < n; i++ )
  {
    printf ( "%d", thue[i] );
  }
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    thue_ternary_next ( &n, thue );

    printf ( "%4d   ", n );
    for ( j = 0; j < n; j++ )
    {
      printf ( "%d", thue[j] );
    }
    printf ( "\n" );
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void triang_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANG_TEST tests TRIANG.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 February 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int a[N*N] = {
    1,0,1,0,1,0,1,0,0,1, 
    0,1,0,0,1,0,0,0,0,0, 
    0,0,1,0,1,0,1,0,0,1, 
    0,1,1,1,1,1,1,1,0,1, 
    0,0,0,0,1,0,0,0,0,0, 
    0,1,0,0,1,1,1,0,0,0, 
    0,0,0,0,1,0,1,0,0,0, 
    0,1,0,0,1,1,1,1,0,1, 
    0,0,0,0,0,0,0,0,0,0, 
    0,0,0,0,1,0,1,0,0,1 };
  int p[N];

  printf ( "\n" );
  printf ( "TRIANG_TEST\n" );
  printf ( "  TRIANG relabels elements for a partial ordering,\n" );

  i4mat_print ( N, N, a, "  The input matrix:" );
 
  triang ( N, a, p );
 
  perm0_print ( N, p, "  The new ordering:" );

  i4mat_2perm0 ( N, N, a, p, p );
 
  i4mat_print ( N, N, a, "  The reordered matrix:" );
 
  return;
# undef N
}
/******************************************************************************/

void tuple_next_test ( )

/******************************************************************************/
/*
  Purpose:

    TUPLE_NEXT_TEST tests TUPLE_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 2

  int i;
  int m1 = 2;
  int m2 = 4;
  int rank;
  int x[N];

  printf ( "\n" );
  printf ( "TUPLE_NEXT_TEST\n" );
  printf ( "  TUPLE_NEXT returns the next \"tuple\", that is,\n" );
  printf ( "  a vector of N integers, each between M1 and M2.\n" );
  printf ( "\n" );
  printf ( "  M1 = %d\n", m1 );
  printf ( "  M2 = %d\n", m2 );
  printf ( "  N = %d\n", N );
  printf ( "\n" );

  rank = 0;

  for ( ; ; )
  {
    tuple_next ( m1, m2, N, &rank, x );

    if ( rank == 0 )
    {
      break;
    }

    printf ( "%4d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( " %4d  ", x[i] );
    }
    printf ( "\n" );

  }

  return;
# undef N
}
/******************************************************************************/

void tuple_next_fast_test ( )

/******************************************************************************/
/*
  Purpose:

    TUPLE_NEXT_FAST_TEST tests TUPLE_NEXT_FAST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 June 2015

  Author:

    John Burkardt
*/
{
  int base[2];
  int i;
  int m = 3;
  int n = 2;
  int rank;
  int rank_hi;
  int x[2];

  printf ( "\n" );
  printf ( "TUPLE_NEXT_FAST_TEST\n" );
  printf ( "  TUPLE_NEXT_FAST returns the next \"tuple\", that is,\n" );
  printf ( "  a vector of N integers, each between 1 and M.\n" );
  printf ( "\n" );
  printf ( "  M = %d\n", m );
  printf ( "  N = %d\n", n );
  printf ( "\n" );
/*
  Initialize.
*/
  rank = -1;
  tuple_next_fast ( m, n, rank, base, x );

  rank_hi = i4_power ( m, n );

  for ( rank = 0; rank < rank_hi; rank++ )
  {
    tuple_next_fast ( m, n, rank, base, x );

    printf ( "%4d", rank );
    for ( i = 0; i < n; i++ )
    {
      printf ( "%4d  ", x[i] );
    }
    printf ( "\n" );
  }

  return;
}
/******************************************************************************/

void tuple_next_ge_test ( )

/******************************************************************************/
/*
  Purpose:

    TUPLE_NEXT_GE_TEST tests TUPLE_NEXT_GE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int i;
  int m = 3;
  int rank;
  int x[N];

  printf ( "\n" );
  printf ( "TUPLE_NEXT_GE_TEST\n" );
  printf ( "  TUPLE_NEXT_GE returns the next nondecreasting \"tuple\",\n" );
  printf ( "  that is, a vector of N integers, each between 1 and M,\n" );
  printf ( "  with the additional property that the digits never decrease\n" );
  printf ( "  reading from left to right.\n" );
  printf ( "\n" );
  printf ( "  M = %d\n", m );
  printf ( "  N = %d\n", N );
  printf ( "\n" );

  rank = 0;

  for ( ; ; )
  {
    tuple_next_ge ( m, N, &rank, x );

    if ( rank == 0 )
    {
      break;
    }

    printf ( "%4d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%4d  ", x[i] );
    }
    printf ( "\n" );

  }

  return;
# undef N
}
/******************************************************************************/

void tuple_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    TUPLE_NEXT2_TEST tests TUPLE_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int i;
  int rank;
  int x[N];
  int xmin[N] = { 2, 3, 8 };
  int xmax[N] = { 4, 3, 5 };

  printf ( "\n" );
  printf ( "TUPLE_NEXT2_TEST\n" );
  printf ( "  TUPLE_NEXT2 returns the next \"tuple\",\n" );
  printf ( "  that is, a vector of N integers.\n" );
  printf ( "  Each position in the vector has a separate min and max.\n" );
  printf ( "  reading from left to right.\n" );
  printf ( "\n" );
  printf ( "  N = %d\n", N );
  printf ( "\n" );
  i4vec1_print ( N, xmin, "  The minimum values:" );
  i4vec1_print ( N, xmax, "  The maximum values:" );

  printf ( "\n" );
  printf ( "\n" );

  rank = 0;

  for ( ; ; )
  {
    tuple_next2 ( N, xmin, xmax, x, &rank );

    if ( rank == 0 )
    {
      break;
    }

    printf ( "%4d", rank );
    for ( i = 0; i < N; i++ )
    {
      printf ( "%4d  ", x[i] );
    }
    printf ( "\n" );

  }

  return;
# undef N
}
/******************************************************************************/

void ubvec_add_test ( )

/******************************************************************************/
/*
  Purpose:

    UBVEC_ADD_TEST tests UBVEC_ADD;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int bvec1[N];
  int bvec2[N];
  int bvec3[N];
  int seed = 123456789;
  int test;
  int test_num = 10;
  unsigned int ui;
  unsigned int uj;
  unsigned int uk;

  printf ( "\n" );
  printf ( "UBVEC_ADD_TEST\n" );
  printf ( "  UBVEC_ADD adds unsigned binary vectors \n" );
  printf ( "  representing unsigned integers;\n" );
  printf ( "\n" );
  printf ( "        I        J        K = I + J\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  { 
    ui = i4_uniform_ab ( 0, 100, &seed );
    uj = i4_uniform_ab ( 0, 100, &seed );

    printf ( "\n" );
    printf ( "  %8d  %8d\n", ui, uj );

    uk = ui + uj;

    printf ( "  Directly:           %8d\n", uk );

    ui4_to_ubvec ( ui, N, bvec1 );
    ui4_to_ubvec ( uj, N, bvec2 );

    ubvec_add ( N, bvec1, bvec2, bvec3 );
    uk = ubvec_to_ui4 ( N, bvec3 );

    printf ( "  UBVEC_ADD           %8d\n", uk );
  }

  return;
# undef N
}
/******************************************************************************/

void ubvec_print_test ( )

/******************************************************************************/
/*
  Purpose:

    UBVEC_PRINT_TEST tests UBVEC_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 May 2015

  Author:

    John Burkardt
*/
{
  int n = 10;
  int ubvec[10] = { 1, 0, 0, 1, 0, 1, 1, 1, 0, 0 };

  printf ( "\n" );
  printf ( "UBVEC_PRINT_TEST\n" );
  printf ( "  UBVEC_PRINT prints an unsigned binary vector.\n" );

  ubvec_print ( n, ubvec, "  UBVEC:" );

  return;
}
/******************************************************************************/

void ubvec_to_ui4_test ( )

/******************************************************************************/
/*
  Purpose:

    UBVEC_TO_UI4_TEST tests UBVEC_TO_UI4;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int bvec[N];
  int i;
  int j;
  unsigned int ui1;
  unsigned int ui2;

  printf ( "\n" );
  printf ( "UBVEC_TO_UI4_TEST\n" );
  printf ( "  UBVEC_TO_UI4 converts an unsigned binary vector\n" );
  printf ( "  to an unsigned integer;\n" );
  printf ( "\n" );
  printf ( "  I --> BVEC  -->  I\n" );
  printf ( "\n" );

  for ( i = 0; i <= 10; i++ )
  {
    ui1 = ( unsigned int ) ( i );
    ui4_to_ubvec ( ui1, N, bvec );

    ui2 = ubvec_to_ui4 ( N, bvec );

    printf ( "%3d  ", ui1 );
    for ( j = 0; j < N; j++ )
    {
      printf ( "%d", bvec[j] );
    }
    printf ( "  " );
    printf ( "%3d\n", ui2 );
  }

  return;
# undef N
}
/******************************************************************************/

void ubvec_xor_test ( )

/******************************************************************************/
/*
  Purpose:

    UBVEC_XOR_TEST tests UBVEC_XOR;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 May 2015

  Author:

    John Burkardt
*/
{
  int bvec1[10];
  int bvec2[10];
  int bvec3[10];
  int n = 10;
  int seed = 123456789;
  int test;
  int test_num = 10;
  unsigned int ui;
  unsigned int uj;
  unsigned int uk;

  printf ( "\n" );
  printf ( "UBVEC_XOR_TEST\n" );
  printf ( "  UBVEC_XOR exclusive-ors two unsigned binary vectors \n" );
  printf ( "  representing unsigned integers;\n" );
  printf ( "\n" );
  printf ( "        I        J        K = I XOR J\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  { 
    ui = i4_uniform_ab ( 0, 100, &seed );
    uj = i4_uniform_ab ( 0, 100, &seed );
    ui4_to_ubvec ( ui, n, bvec1 );
    ui4_to_ubvec ( uj, n, bvec2 );
    ubvec_add ( n, bvec1, bvec2, bvec3 );
    uk = ubvec_to_ui4 ( n, bvec3 );
    printf ( "  %8d  %8d  %8d\n", ui, uj, uk );
  }

  return;
}
/******************************************************************************/

void ui4_to_ubvec_test ( )

/******************************************************************************/
/*
  Purpose:

    UI4_TO_UBVEC_TEST tests UI4_TO_UBVEC;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 March 2014

  Author:

    John Burkardt
*/
{
# define N 10

  int bvec[N];
  int i;
  int j;
  unsigned int ui1;
  unsigned int ui2;

  printf ( "\n" );
  printf ( "UI4_TO_UBVEC_TEST\n" );
  printf ( "  UI4_TO_UBVEC converts an unsigned integer to an \n" );
  printf ( "  unsigned binary vector;\n" );
  printf ( "\n" );
  printf ( "  I --> BVEC  -->  I\n" );
  printf ( "\n" );

  for ( i = 0; i <= 10; i++ )
  {
    ui1 = ( unsigned int ) ( i );
    ui4_to_ubvec ( ui1, N, bvec );

    ui2 = ubvec_to_ui4 ( N, bvec );

    printf ( "%3d  ", ui1 );
    for ( j = 0; j < N; j++ )
    {
      printf ( "%d", bvec[j] );
    }
    printf ( "  " );
    printf ( "%3d\n", ui2 );
  }

  return;
# undef N
}
/******************************************************************************/

void vec_colex_next_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_COLEX_NEXT_TEST tests VEC_COLEX_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2014

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3

  int a[DIM_NUM];
  int base = 3;
  int i;
  int more;

  printf ( "\n" );
  printf ( "VEC_COLEX_NEXT_TEST\n" );
  printf ( "  VEC_COLEX_NEXT generates all DIM_NUM-vectors\n" );
  printf ( "  in colex order in a given base BASE.\n" );
  printf ( "\n" );
  printf ( "  The spatial dimension DIM_NUM = %d\n", DIM_NUM );
  printf ( "  The base BASE =                 %d\n", base );

  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    vec_colex_next ( DIM_NUM, base, a, &more );

    if ( !more ) 
    {
      break;
    }

    for ( i = 0; i < DIM_NUM; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );
  }

  return;
# undef DIM_NUM
}
/******************************************************************************/

void vec_colex_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_COLEX_NEXT2_TEST tests VEC_COLEX_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 February 2014

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3

  int a[DIM_NUM];
  int base[DIM_NUM] = { 2, 1, 3 };
  int i;
  int more;

  printf ( "\n" );
  printf ( "VEC_COLEX_NEXT2_TEST\n" );
  printf ( "  VEC_COLEX_NEXT2 generates all DIM_NUM-vectors\n" );
  printf ( "  in colex order in a given base BASE.\n" );
  printf ( "\n" );
  printf ( "  The spatial dimension DIM_NUM = %d\n", DIM_NUM );
  printf ( "\n" );
  printf ( "  The base vector:\n" );
  printf ( "\n" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %4d", base[i] );
  }
  printf ( "\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    vec_colex_next2 ( DIM_NUM, base, a, &more );

    if ( !more ) 
    {
      break;
    }

    for ( i = 0; i < DIM_NUM; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );
  }

  return;
# undef DIM_NUM
}
/******************************************************************************/

void vec_colex_next3_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_COLEX_NEXT3_TEST tests VEC_COLEX_NEXT3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 February 2014

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3

  int a[DIM_NUM];
  int base[DIM_NUM] = { 2, 1, 3 };
  int i;
  int more;

  printf ( "\n" );
  printf ( "VEC_COLEX_NEXT3_TEST\n" );
  printf ( "  VEC_COLEX_NEXT3 generates all DIM_NUM-vectors\n" );
  printf ( "  in colex order in a given base BASE.\n" );
  printf ( "\n" );
  printf ( "  The spatial dimension DIM_NUM = %d\n", DIM_NUM );
  printf ( "\n" );
  printf ( "  The base vector:\n" );
  printf ( "\n" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %4d", base[i] );
  }
  printf ( "\n" );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    vec_colex_next3 ( DIM_NUM, base, a, &more );

    if ( !more ) 
    {
      break;
    }

    for ( i = 0; i < DIM_NUM; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );
  }

  return;
# undef DIM_NUM
}
/******************************************************************************/

void vec_gray_next_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_GRAY_NEXT_TEST tests VEC_GRAY_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 May 2007

  Author:

    John Burkardt
*/
{
# define N 4

  int a[N];
  int active[N];
  int base[N] = { 2, 2, 1, 4 };
  int change;
  int dir[N];
  int done;
  int i;
  int prod;
  int rank;

  prod = 1;
  for ( i = 0; i < N; i++ )
  {
    prod = prod * base[i];
  }

  printf ( "\n" );
  printf ( "VEC_GRAY_NEXT_TEST\n" );
  printf ( "  VEC_GRAY_NEXT generates product space elements.\n" );
  printf ( "\n" );
  printf ( "  The number of components is %d\n", N );
  printf ( "  The number of elements is %d\n", prod );
  printf ( "  Each component has its own number of degrees of\n" );
  printf ( "  freedom.\n" );
  printf ( "\n" );
  printf ( "  Rank Change   " );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d", base[i] );
  }
  printf ( "\n" );
  printf ( "\n" );

  rank = 0;
  done = 1;

  for ( ; ; )
  {
    rank = rank + 1;

    vec_gray_next ( N, base, a, &done, active, dir, &change );

    if ( done )
    {
      break;
    }

    printf ( "%4d%4d", rank, change );
    for ( i = 0; i < N; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );

  }

# undef N
}
/******************************************************************************/

void vec_gray_rank_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_GRAY_RANK_TEST tests VEC_GRAY_RANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 May 2007

  Author:

    John Burkardt
*/
{
# define N 4

  int a[N];
  int base[N] = { 2, 2, 1, 4 };
  int i;
  int prod;
  int rank;

  prod = 1;
  for ( i = 0; i < N; i++ )
  {
    prod = prod * base[i];
  }

  printf ( "\n" );
  printf ( "VEC_GRAY_RANK_TEST\n" );
  printf ( "  VEC_GRAY_RANK ranks product space elements.\n" );
  printf ( "\n" );
  printf ( "  The number of components is %d\n", N );
  printf ( "  The number of elements is %d\n", prod );
  printf ( "  Each component has its own number of degrees of\n" );
  printf ( "  freedom, which, for this example, are:\n" );
  printf ( "\n" );
  printf ( "  Rank Change   " );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d", base[i] );
  }
  printf ( "\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    a[i] = base[i] / 2;
  }

  rank = vec_gray_rank ( N, base, a );

  printf ( "\n" );
  printf ( "  VEC_GRAY_RANK reports the element\n" );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d", a[i] );
  }
  printf ( "\n" );
  printf ( "\n" );
  printf ( "  has rank %d\n", rank );

  return;
# undef N
}
/******************************************************************************/

void vec_gray_unrank_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_GRAY_UNRANK_TEST tests VEC_GRAY_UNRANK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 May 2007

  Author:

    John Burkardt
*/
{
# define N 4

  int a[N];
  int base[N] = { 2, 2, 1, 4 };
  int i;
  int prod;
  int rank;

  prod = 1;
  for ( i = 0; i < N; i++ )
  {
    prod = prod * base[i];
  }

  printf ( "\n" );
  printf ( "VEC_GRAY_UNRANK_TEST\n" );
  printf ( "  VEC_GRAY_UNRANK unranks product space elements.\n" );
  printf ( "\n" );
  printf ( "  The number of components is %d\n", N );
  printf ( "  The number of elements is %d\n", prod );
  printf ( "  Each component has its own number of degrees of\n" );
  printf ( "  freedom, which, for this example, are:\n" );
  printf ( "\n" );
  printf ( "  Rank Change   " );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d", base[i] );
  }
  printf ( "\n" );
  printf ( "\n" );

  rank = 7;
  vec_gray_unrank ( N, base, rank, a );

  printf ( "\n" );
  printf ( "  VEC_GRAY_UNRANK reports the element of rank %d is:\n", rank );
  printf ( "\n" );
  for ( i = 0; i < N; i++ )
  {
    printf ( "  %4d", a[i] );
  }
  printf ( "\n" );

  return;
# undef N
}
/******************************************************************************/

void vec_lex_next_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_LEX_NEXT_TEST tests VEC_LEX_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 February 2014

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3

  int a[DIM_NUM];
  int base = 3;
  int i;
  int more;

  printf ( "\n" );
  printf ( "VEC_LEX_NEXT_TEST\n" );
  printf ( "  VEC_LEX_NEXT generates all DIM_NUM-vectors\n" );
  printf ( "  in a given base.  Here we use base %d\n", base );
  printf ( "\n" );

  more = 0;

  for ( ; ; )
  {
    vec_lex_next ( DIM_NUM, base, a, &more );

    if ( !more ) 
    {
      break;
    }

    for ( i = 0; i < DIM_NUM; i++ )
    {
      printf ( "  %4d", a[i] );
    }
    printf ( "\n" );

  }

  return;
# undef DIM_NUM
}
/******************************************************************************/

void vec_random_test ( )

/******************************************************************************/
/*
  Purpose:

    VEC_RANDOM_TEST tests VEC_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int a[N];
  int base;
  int i;
  int j;
  int seed;

  base = 3;
  seed = 123456789;

  printf ( "\n" );
  printf ( "VEC_RANDOM_TEST\n" );
  printf ( "  VEC_RANDOM generates a random N-vector\n" );
  printf ( "  in a given base.\n" );
  printf ( "  Here, we use base %d\n", base );
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    vec_random ( N, base, &seed, a );

    printf ( "%4d    ", i );
    for ( j = 0; j < N; j++ )
    {
      printf ( "  %4d", a[j] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void vector_constrained_next_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT_TEST tests VECTOR_CONSTRAINED_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 February 2014

  Author:

    John Burkardt
*/
{
# define N 3

  int constraint;
  int i;
  int j;
  int more;
  int x[N];
  int x_max[N] = { 4, 5, 3 };
  int x_min[N] = { 2, 2, 1 };
  int x_prod;

  printf ( "\n" );
  printf ( "VECTOR_CONSTRAINED_NEXT_TEST\n" );
  printf ( "  VECTOR_CONSTRAINED_NEXT:\n" );
  printf ( "  Consider vectors:\n" );
  printf ( "    X_MIN(1:N) <= X(1:N) <= X_MAX(1:N),\n" );
  printf ( "  Set\n" );
  printf ( "    P = Product X_MAX(1:N)\n" );
  printf ( "  Accept only vectors for which:\n" );
  printf ( "    sum ( (X(1:N)-1) * P / X_MAX(1:N) ) <= P\n" );

  more = 0;

  printf ( "\n" );
  printf ( "  X_MIN:\n" );
  for ( j = 0; j < N; j++ )
  {
    printf ( "  %4d", x_min[j] );
  }
  printf ( "\n" );
  printf ( "\n" );
  printf ( "  X_MAX:\n" );
  for ( j = 0; j < N; j++ )
  {
    printf ( "  %4d", x_max[j] );
  }
  printf ( "\n" );

  i = 0;

  x_prod = 1;
  for ( j = 0; j < N; j++ )
  {
    x_prod = x_prod * x_max[j];
  }

  printf ( "\n" );
  printf ( "  Maximum allowed CONSTRAINT = P = %d\n", x_prod );
  printf ( "\n" );

  for ( ; ; )
  {
    vector_constrained_next ( N, x_min, x_max, x, &constraint, &more );

    if ( !more )
    {
      break;
    }

    i = i + 1;
    printf ( "  %8d", i );
    printf ( "  %12d", constraint );
    for ( j = 0; j < N; j++ )
    {
      printf ( "  %8d", x[j] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void vector_constrained_next2_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT2_TEST tests VECTOR_CONSTRAINED_NEXT2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 March 2006

  Author:

    John Burkardt
*/
{
# define N_MAX 3

  int constraint;
  int i;
  int j;
  int more;
  int n;
  int x[N_MAX];
  int x_max[N_MAX] = { 5, 6, 4 };
  int x_min[N_MAX] = { 1, 1, 1 };
  int x_prod;

  printf ( "\n" );
  printf ( "VECTOR_CONSTRAINED_NEXT2_TEST\n" );
  printf ( "  VECTOR_CONSTRAINED_NEXT2:\n" );
  printf ( "  Consider vectors:\n" );
  printf ( "    X_MIN(1:N) <= X(1:N) <= X_MAX(1:N),\n" );
  printf ( "  Set\n" );
  printf ( "    P = Product X_MAX(1:N)\n" );
  printf ( "  Accept only vectors for which:\n" );
  printf ( "    sum ( X(1:N) * P / X_MAX(1:N) ) <= P\n" );

  for ( n = 2; n <= N_MAX; n++ )
  {
    more = 0;

    printf ( "\n" );
    printf ( "  X_MIN:\n" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_min[j] );
    }
    printf ( "\n" );
    printf ( "\n" );
    printf ( "  X_MAX:\n" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_max[j] );
    }
    printf ( "\n" );

    i = 0;

    x_prod = 1;
    for ( j = 0; j < n; j++ )
    {
      x_prod = x_prod * x_max[j];
    }

    printf ( "\n" );
    printf ( "  Maximum allowed CONSTRAINT = P = %d\n", x_prod );
    printf ( "\n" );

    for ( ; ; )
    {
      vector_constrained_next2 ( n, x_min, x_max, x, &constraint, &more );

      if ( !more )
      {
        break;
      }

      i = i + 1;
      printf ( "  %8d", i );
      printf ( "  %12d", constraint );
      for ( j = 0; j < n; j++ )
      {
        printf ( "  %8d", x[j] );
      }
      printf ( "\n" );
    }
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void vector_constrained_next3_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT3_TEST tests VECTOR_CONSTRAINED_NEXT3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 February 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 3

  double constraint;
  int i;
  int j;
  int more;
  int n;
  int x[N_MAX];
  int x_max[N_MAX] = { 5, 6, 4 };
  int x_min[N_MAX] = { 1, 1, 1 };

  printf ( "\n" );
  printf ( "VECTOR_CONSTRAINED_NEXT3_TEST\n" );
  printf ( "  VECTOR_CONSTRAINED_NEXT3:\n" );
  printf ( "  Consider vectors:\n" );
  printf ( "    X_MIN(1:N) <= X(1:N) <= X_MAX(1:N),\n" );
  printf ( "  Set\n" );
  printf ( "    CONSTRAINT = sum ( X(1:N) / X_MAX(1:N) )\n" );
  printf ( "  Accept only vectors for which:\n" );
  printf ( "    CONSTRAINT <= 1\n" );

  for ( n = 2; n <= N_MAX; n++ )
  {
    more = 0;

    printf ( "\n" );
    printf ( "  X_MIN:\n" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_min[j] );
    }
    printf ( "\n" );
    printf ( "\n" );
    printf ( "  X_MAX:\n" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_max[j] );
    }
    printf ( "\n" );
    printf ( "\n" );

    i = 0;

    for ( ; ; )
    {
      vector_constrained_next3 ( n, x_min, x_max, x, &constraint, &more );

      if ( !more )
      {
        break;
      }

      i = i + 1;
      printf ( "  %8d", i );
      printf ( "  %14g", constraint );
      for ( j = 0; j < n; j++ )
      {
        printf ( "  %8d", x[j] );
      }
      printf ( "\n" );
    }
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void vector_constrained_next4_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT4_TEST tests VECTOR_CONSTRAINED_NEXT4.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 February 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 3

  double alpha[N_MAX] = { 4.0, 3.0, 5.0 };
  int i;
  int j;
  int more;
  int n;
  double q = 20.0;
  double total;
  int x[N_MAX];
  int x_max[N_MAX] = { 2, 6, 4 };
  int x_min[N_MAX] = { 1, 0, 1 };

  printf ( "\n" );
  printf ( "VECTOR_CONSTRAINED_NEXT4_TEST\n" );
  printf ( "  VECTOR_CONSTRAINED_NEXT4:\n" );
  printf ( "  Consider vectors:\n" );
  printf ( "    X_MIN(1:N) <= X(1:N) <= X_MAX(1:N),\n" );
  printf ( "  Set\n" );
  printf ( "    TOTAL = sum ( ALPHA(1:N) * X(1:N) )\n" );
  printf ( "  Accept only vectors for which:\n" );
  printf ( "    TOTAL <= Q\n" );

  for ( n = 2; n <= N_MAX; n++ )
  {
    more = 0;

    printf ( "\n" );
    printf ( "  ALPHA:" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %8g", alpha[j] );
    }
    printf ( "\n" );
    printf ( "  Q:    " );
    printf ( "  %8g", q );
    printf ( "\n" );
    printf ( "  X_MIN:" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_min[j] );
    }
    printf ( "\n" );
    printf ( "  X_MAX:" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_max[j] );
    }
    printf ( "\n" );
    printf ( "\n" );

    i = 0;

    for ( ; ; )
    {
      vector_constrained_next4 ( n, alpha, x_min, x_max, x, q, &more );

      if ( !more )
      {
        break;
      }

      total = 0.0;
      for ( j = 0; j < n; j++ )
      {
        total = total + alpha[j] * ( double ) x[j];
      }
      i = i + 1;
      printf ( "  %8d", i );
      printf ( "  %14g", total );
      for ( j = 0; j < n; j++ )
      {
        printf ( "  %8d", x[j] );
      }
      printf ( "\n" );
    }
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void vector_constrained_next5_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT5_TEST tests VECTOR_CONSTRAINED_NEXT5

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 May 2015

  Author:

    John Burkardt
*/
{
  int base;
  int i;
  int j;
  int more;
  int n;
  int sum_max;
  int sum_min;
  int x[3];

  printf ( "\n" );
  printf ( "VECTOR_CONSTRAINED_NEXT5_TEST\n" );
  printf ( "  VECTOR_CONSTRAINED_NEXT5:\n" );
  printf ( "  Generate integer vectors X such that:\n" );
  printf ( "    SUM_MIN <= sum ( X(1:N) ) <= SUM_MAX,\n" );
  printf ( "  We require every X(I) to be at least 1.\n" );

  n = 3;
  sum_min = 5;
  sum_max = 7;
  base = 0;
  more = 0;

  printf ( "\n" );
  printf ( "  N =       %d\n", n );
  printf ( "  SUM_MIN = %d\n", sum_min );
  printf ( "  SUM_MAX = %d\n", sum_max );
  printf ( "\n" );
  printf ( "         #        X(1)      X(2)      X(3)\n" );
  printf ( "\n" );

  i = 0;

  for ( ; ; )
  {
    vector_constrained_next5 ( n, x, sum_min, sum_max, &base, &more );

    if ( !more )
    {
      break;
    }

    i = i + 1;
    printf ( "  %8d", i );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %8d", x[j] );
    }
    printf ( "\n" );
  }
  return;
}
/******************************************************************************/

void vector_constrained_next6_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT6_TEST tests VECTOR_CONSTRAINED_NEXT6.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 January 2014

  Author:

    John Burkardt
*/
{
# define N_MAX 3

  double alpha[N_MAX] = { 4.0, 3.0, 5.0 };
  int i;
  int j;
  int more;
  int n;
  double q_max = 20.0;
  double q_min = 16.0;
  double total;
  int x[N_MAX];
  int x_max[N_MAX] = { 2, 6, 4 };
  int x_min[N_MAX] = { 1, 0, 1 };

  printf ( "\n" );
  printf ( "VECTOR_CONSTRAINED_NEXT6_TEST\n" );
  printf ( "  VECTOR_CONSTRAINED_NEXT6:\n" );
  printf ( "  Consider vectors:\n" );
  printf ( "    X_MIN(1:N) <= X(1:N) <= X_MAX(1:N),\n" );
  printf ( "  Set\n" );
  printf ( "    TOTAL = sum ( ALPHA(1:N) * X(1:N) )\n" );
  printf ( "  Accept only vectors for which:\n" );
  printf ( "    Q_MIN <= TOTAL <= Q_MAX\n" );

  for ( n = 2; n <= N_MAX; n++ )
  {
    more = 0;

    printf ( "\n" );
    printf ( "  ALPHA:" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %8f", alpha[j] );
    }
    printf ( "\n" );
    printf ( "  Q_MIN:" );
    printf ( "  %8f", q_min );
    printf ( "\n" );
    printf ( "  Q_MAX:" );
    printf ( "  %8f", q_max );
    printf ( "\n" );
    printf ( "  X_MIN:" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_min[j] );
    }
    printf ( "\n" );
    printf ( "  X_MAX:" );
    for ( j = 0; j < n; j++ )
    {
      printf ( "  %4d", x_max[j] );
    }
    printf ( "\n" );
    printf ( "\n" );

    i = 0;

    for ( ; ; )
    {
      vector_constrained_next6 ( n, alpha, x_min, x_max, x, q_min, 
        q_max, &more );

      if ( !more )
      {
        break;
      }

      total = 0.0;
      for ( j = 0; j < n; j++ )
      {
        total = total + alpha[j] * ( double ) x[j];
      }
      i = i + 1;
      printf ( "  %8d", i );
      printf ( "  %14g", total );
      for ( j = 0; j < n; j++ )
      {
        printf ( "  %8d", x[j] );
      }
      printf ( "\n" );
    }
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void vector_constrained_next7_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_CONSTRAINED_NEXT7_TEST tests VECTOR_CONSTRAINED_NEXT7.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 July 2010

  Author:

    John Burkardt
*/
{
# define N_MAX 3

  double alpha[N_MAX] = { 4.0, 3.0, 5.0 };
  int i;
  int j;
  int more;
  int n;
  double q_max = 20.0;
  double q_min = 16.0;
  double total;
  int x[N_MAX];
  int x_max[N_MAX] = { 2, 6, 4 };

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "VECTOR_CONSTRAINED_NEXT7_TEST\n" );
  fprintf ( stdout, "  VECTOR_CONSTRAINED_NEXT7:\n" );
  fprintf ( stdout, "  Consider vectors:\n" );
  fprintf ( stdout, "    0 <= X(1:N) <= X_MAX(1:N),\n" );
  fprintf ( stdout, "  Set\n" );
  fprintf ( stdout, "    TOTAL = sum ( ALPHA(1:N) * X(1:N) )\n" );
  fprintf ( stdout, "  Accept only vectors for which:\n" );
  fprintf ( stdout, "    Q_MIN <= TOTAL <= Q_MAX\n" );

  for ( n = 2; n <= N_MAX; n++ )
  {
    more = 0;

    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  ALPHA:" );
    for ( j = 0; j < n; j++ )
    {
      fprintf ( stdout, "  %8f", alpha[j] );
    }
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Q_MIN:" );
    fprintf ( stdout, "  %8f", q_min );
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Q_MAX:" );
    fprintf ( stdout, "  %8f", q_max );
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  X_MAX:" );
    for ( j = 0; j < n; j++ )
    {
      fprintf ( stdout, "  %4d", x_max[j] );
    }
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "\n" );

    i = 0;

    for ( ; ; )
    {
      vector_constrained_next7 ( n, alpha, x_max, x, q_min, 
        q_max, &more );

      if ( !more )
      {
        break;
      }

      total = 0.0;
      for ( j = 0; j < n; j++ )
      {
        total = total + alpha[j] * ( double ) x[j];
      }
      i = i + 1;
      fprintf ( stdout, "  %8d", i );
      fprintf ( stdout, "  %14f", total );
      for ( j = 0; j < n; j++ )
      {
        fprintf ( stdout, "  %8d", x[j] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void vector_next_test ( )

/******************************************************************************/
/*
  Purpose:

    VECTOR_NEXT_TEST tests VECTOR_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 July 2010

  Author:

    John Burkardt
*/
{
# define N_MAX 3

  int i;
  int j;
  int more;
  int n;
  int x[N_MAX];
  int x_max[N_MAX] = { 2, 6, 4 };
  int x_min[N_MAX] = { 1, 4, 3 };

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "VECTOR_NEXT_TEST\n" );
  fprintf ( stdout, "  VECTOR_NEXT:\n" );
  fprintf ( stdout, "  Generate all vectors X such that:\n" );
  fprintf ( stdout, "    X_MIN(1:N) <= X(1:N) <= X_MAX(1:N),\n" );

  for ( n = 2; n <= N_MAX; n++ )
  {
    more = 0;

    fprintf ( stdout, "\n" );
    fprintf ( stdout, "    X_MIN:" );
    for ( j = 0; j < n; j++ )
    {
      fprintf ( stdout, "  %8d", x_min[j] );
    }
    fprintf ( stdout, "\n" );

    i = 0;

    for ( ; ; )
    {
      vector_next ( n, x_min, x_max, x, &more );

      if ( !more )
      {
        break;
      }

      i = i + 1;
      fprintf ( stdout, "  %8d", i );
      for ( j = 0; j < n; j++ )
      {
        fprintf ( stdout, "  %8d", x[j] );
      }
      fprintf ( stdout, "\n" );
    }
    fprintf ( stdout, "    X_MAX:" );
    for ( j = 0; j < n; j++ )
    {
      fprintf ( stdout, "  %8d", x_max[j] );
    }
    fprintf ( stdout, "\n" );
  }

  return;
# undef N_MAX
}
/******************************************************************************/

void ytb_enum_test ( )

/******************************************************************************/
/*
  Purpose:

    YTB_ENUM_TEST tests YTB_ENUM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 January 2014

  Author:

    John Burkardt
*/
{
  int n;

  printf ( "\n" );
  printf ( "YTB_ENUM_TEST\n" );
  printf ( "  YTB_ENUM counts Young tableau.\n" );
  printf ( "\n" );
  printf ( "   N  YTB_ENUM(N)\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    printf ( "%4d  %10d\n", n, ytb_enum ( n ) );
  }

  return;
}
/******************************************************************************/

void ytb_next_test ( )

/******************************************************************************/
/*
  Purpose:

    YTB_NEXT_TEST tests YTB_NEXT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 January 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int i;
  int a[N];
  int lambda[N] = { 3, 2, 1, 0, 0, 0 };
  int more;

  for ( i = 0; i < N; i++ )
  {
    a[i] = 0;
  }

  printf ( "\n" );
  printf ( "YTB_NEXT_TEST\n" );
  printf ( "  YTB_NEXT generates Young tableaus.\n" );
  printf ( "\n" );

  more = 0;

  i = 0;

  for ( ; ; )
  {
    i = i + 1;
    ytb_next ( N, lambda, a, &more );

    ytb_print ( N, a, "" );

    if ( !more || 100 < i )
    {
      break;
    }

  }

  return;

# undef N
}
/******************************************************************************/

void ytb_random_test ( )

/******************************************************************************/
/*
  Purpose:

    YTB_RANDOM_TEST tests YTB_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 January 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int a[N];
  int i;
  int lambda[N] = { 3, 2, 1, 0, 0, 0 };
  int seed;

  printf ( "\n" );
  printf ( "YTB_RANDOM_TEST\n" );
  printf ( "  YTB_RANDOM generates a random Young tableau\n" );

  seed = 123456789;

  for ( i = 1; i <= 5; i++ )
  {
    ytb_random ( N, lambda, &seed, a );

    ytb_print ( N, a, "" );
  }

  return;
# undef N
}
