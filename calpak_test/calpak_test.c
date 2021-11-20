# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "calpak.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CALPAK_TEST.

  Discussion:

    CALPAK_TEST tests the CALPAK library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "CALPAK_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the CALPAK library.\n" );

  ch_cap_test ( );
  datenum_to_jed_test ( );
  datenum_values_test ( );
  day_list_common_test ( );
  easter_gregorian_ds_test ( );
  easter_gregorian_egr_test ( );
  easter_gregorian_egr2_test ( );
  easter_gregorian_knuth_test ( );
  easter_gregorian_stewart_test ( );
  easter_julian_egr_test ( );
  easter_julian_egr2_test ( );
  gps_to_jed_test ( );
  i4_modp_test ( );
  i4_normal_ab_test ( );
  i4_uniform_ab_test ( );
  i4_wrap_test ( );
  jed_ce_values_test ( );
  jed_is_legal_test ( );
  jed_mjd_values_test ( );
  jed_rd_values_test ( );
  jed_to_datenum_test ( );
  jed_to_gps_test ( );
  jed_to_noon_nearest_test ( );
  jed_to_noon_next_test ( );
  jed_to_weekday_test ( );
  jed_weekday_values_test ( );
  month_to_month_name_common_test ( );
  month_to_month_name_common3_test ( );
  r8_mod_test ( );
  r8_nint_test ( );
  r8_uniform_ab_test ( );
  r8_uniform_01_test ( );
  weekday_to_name_common_test ( );
  weekday_to_name_common2_test ( );
  weekday_to_name_common3_test ( );
  weekday_values_test ( );
  y_to_s_common_test ( );
  year_length_days_common_test ( );
  year_to_golden_number_test ( );
  ymd_to_decimal_test ( );
  ymd_to_weekday_common_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CALPAK_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
