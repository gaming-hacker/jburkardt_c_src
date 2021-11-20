char ch_cap ( char ch );
void ch_cap_test ( );

double datenum_to_jed ( double dn );
void datenum_to_jed_test ( );
void datenum_values ( int *n_data, int *y, int *m, int *d, double *date_num );
void datenum_values_test ( );

void day_borrow_common ( int *y, int *m, int *d );
void day_borrow_gregorian ( int *y, int *m, int *d );
void day_borrow_julian ( int *y, int *m, int *d );
void day_carry_common ( int *y, int *m, int *d );
void day_carry_gregorian ( int *y, int *m, int *d );
void day_carry_julian ( int *y, int *m, int *d );

void day_list_common ( int y1, int m1, int d1, int y2, int m2, int d2 );
void day_list_common_test ( );

void deflate_common ( int *y, int *m, int *d );

char digit_to_ch ( int i );

void easter_gregorian_ds ( int y, int *m, int *d );
void easter_gregorian_ds_test ( );
void easter_gregorian_egr ( int y, int *m, int *d );
void easter_gregorian_egr_test ( );
void easter_gregorian_egr2 ( int y, int *m, int *d );
void easter_gregorian_egr2_test ( );
void easter_gregorian_knuth ( int y, int *m, int *d );
void easter_gregorian_knuth_test ( );
void easter_gregorian_stewart ( int y, int *m, int *d );
void easter_gregorian_stewart_test ( );
void easter_julian_egr ( int y, int *m, int *d );
void easter_julian_egr_test ( );
void easter_julian_egr2 ( int y, int *m, int *d );
void easter_julian_egr2_test ( );

double epoch_to_jed_akbar ( );
double epoch_to_jed_alexandrian ( );
double epoch_to_jed_armenian ( );
double epoch_to_jed_bahai ( );
double epoch_to_jed_bessel ( );
double epoch_to_jed_chinese ( );
double epoch_to_jed_common ( );
double epoch_to_jed_coptic ( );
double epoch_to_jed_datenum ( );
double epoch_to_jed_deccan ( );
double epoch_to_jed_eg_civil ( );
double epoch_to_jed_eg_lunar ( );
double epoch_to_jed_english ( );
double epoch_to_jed_ethiopian ( );
double epoch_to_jed_gps ( );
double epoch_to_jed_greek ( );
double epoch_to_jed_gregorian ( );
double epoch_to_jed_hebrew ( );
double epoch_to_jed_hindu_lunar ( );
double epoch_to_jed_hindu_solar ( );
double epoch_to_jed_islamic_a ( );
double epoch_to_jed_islamic_b ( );
double epoch_to_jed_jed ( );
double epoch_to_jed_jelali ( );
double epoch_to_jed_julian ( );
double epoch_to_jed_khwarizmian ( );
double epoch_to_jed_macedonian ( );
double epoch_to_jed_mayan_long ( );
double epoch_to_jed_mjd ( );
double epoch_to_jed_nyt ( );
double epoch_to_jed_nyt_50000 ( );
double epoch_to_jed_persian ( );
double epoch_to_jed_persian_solar ( );
double epoch_to_jed_rd ( );
double epoch_to_jed_republican ( );
double epoch_to_jed_roman ( );
double epoch_to_jed_saka ( );
double epoch_to_jed_soor_san ( );
double epoch_to_jed_syrian ( );
double epoch_to_jed_unix ( );
double epoch_to_jed_y2k ( );
double epoch_to_jed_zoroastrian ( );

int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_modp ( int i, int j );
void i4_modp_test ( );
int i4_normal_ab ( double a, double b, int *seed );
void i4_normal_ab_test ( );
int i4_uniform_ab ( int a, int b, int *seed );
void i4_uniform_ab_test ( );
int i4_wrap ( int ival, int ilo, int ihi );
void i4_wrap_test ( );

double gps_to_jed ( int c, int w, double s );
void gps_to_jed_test ( );

void inflate_common ( int *y, int *m, int *d );

void jed_ce_values ( int *n_data, double *jed, int *y, int *m, int *d, 
  double *f );
void jed_ce_values_test ( );
bool jed_is_legal ( double jed );
void jed_is_legal_test ( );
void jed_mjd_values ( int *n_data, double *jed, double *mjd );
void jed_mjd_values_test ( );
void jed_rd_values ( int *n_data, double *jed, double *rd );
void jed_rd_values_test ( );
double jed_test ( int i );
double jed_to_datenum ( double jed );
void jed_to_datenum_test ( );
void jed_to_gps ( double jed, int *c, int *w, double *s ); 
void jed_to_gps_test ( );
double jed_to_noon_nearest ( double jed1 );
void jed_to_noon_nearest_test ( );
double jed_to_noon_next ( double jed1 );
void jed_to_noon_next_test ( );
void jed_to_weekday ( double jed, int *w, double *f );
void jed_to_weekday_test ( );
void jed_to_ymdf_common ( double jed, int *y, int *m, int *d, double *f );
void jed_to_ymdf_gregorian ( double jed, int *y, int *m, int *d, double *f );
void jed_to_ymdf_julian ( double jed, int *y, int *m, int *d, double *f );
void jed_weekday_values ( int *n_data, double *jed, int *weekday );
void jed_weekday_values_test ( );

void month_borrow_common ( int *y, int *m );
void month_borrow_gregorian ( int *y, int *m );
void month_borrow_julian ( int *y, int *m );
void month_carry_common ( int *y, int *m );
void month_carry_gregorian ( int *y, int *m );
void month_carry_julian ( int *y, int *m );
int month_length_common ( int y, int m );
int month_length_gregorian ( int y, int m );
int month_length_julian ( int y, int m );
char *month_to_month_name_common ( int w );
void month_to_month_name_common_test ( );
char *month_to_month_name_common3 ( int w );
void month_to_month_name_common3_test ( );

double now_to_jed ( );

double r8_mod ( double x, double y );
void r8_mod_test ( );
int r8_nint ( double x );
void r8_nint_test ( );
double r8_uniform_01 ( int *seed );
void r8_uniform_01_test ( );
double r8_uniform_ab ( double a, double b, int *seed );
void r8_uniform_ab_test ( );

void timestamp ( );

double transition_to_jed_common ( );
double transition_to_jed_english ( );
double transition_to_jed_jed ( );
double transition_to_jed_mayan_long ( );

char *weekday_to_name_common ( int w );
void weekday_to_name_common_test ( );
char *weekday_to_name_common2 ( int w );
void weekday_to_name_common2_test ( );
char *weekday_to_name_common3 ( int w );
void weekday_to_name_common3_test ( );
void weekday_values ( int *n_data, int *y, int *m, int *d, int *w );
void weekday_values_test ( );

int y_astronomical_to_common ( int y );
void y_check_common ( int y );
void y_check_gregorian ( int y );
void y_check_julian ( int y );
int y_common_to_astronomical ( int y );
char *y_to_s_common ( int y );
void y_to_s_common_test ( );

bool year_is_leap_common ( int y );
bool year_is_leap_gregorian ( int y );
bool year_is_leap_julian ( int y );

int year_length_days_common ( int y );
void year_length_days_common_test ( );
int year_length_months_common ( int y );
int year_length_months_gregorian ( int y );
int year_length_months_julian ( int y );
int year_to_epact_julian ( int y );
int year_to_golden_number ( int y );
void year_to_golden_number_test ( );

void ym_check_common ( int *y, int *m );
void ym_check_gregorian ( int *y, int *m );
void ym_check_julian ( int *y, int *m );

void ymd_check_common ( int *y, int *m, int *d );
void ymd_check_gregorian ( int *y, int *m, int *d );
void ymd_check_julian ( int *y, int *m, int *d );
char ymd_compare ( int y1, int m1, int d1, int y2, int m2, int d2 );
int ymd_dif_common ( int y1, int m1, int d1, int y2, int m2, int d2 );
double ymd_to_decimal ( int y, int m, int d );
void ymd_to_decimal_test ( );
double ymd_to_jed_common ( int y, int m, int d );
double ymd_to_jed_gregorian ( int y, int m, int d );
double ymd_to_jed_julian ( int y, int m, int d );
char *ymd_to_s_common ( int y, int m, int d );
char *ymd_to_s_gregorian ( int y, int m, int d );
char *ymd_to_s_julian ( int y, int m, int d );
int ymd_to_weekday_common ( int y, int m, int d );
void ymd_to_weekday_common_test ( );
int ymd_to_weekday_english ( int y, int m, int d );
int ymd_to_weekday_gregorian ( int y, int m, int d );

char ymdf_compare ( int y1, int m1, int d1, double f1, int y2, int m2, int d2, 
  double f2 );
void ymdf_next_common ( int y1, int m1, int d1, double f1, int *y2, int *m2, 
  int *d2, double *f2 );

double ymdf_to_jed_common ( int y, int m, int d, double f );
double ymdf_to_jed_english ( int y, int m, int d, double f );
double ymdf_to_jed_gregorian ( int y, int m, int d, double f );
double ymdf_to_jed_julian ( int y, int m, int d, double f );

char *ymdf_to_s_common ( int y, int m, int d, double f );
int ymdf_to_weekday_common ( int y, int m, int d, double f );

void ymdf_uniform_common ( int y1, int m1, int d1, double f1, int y2, int m2, 
  int d2, double f2, int *seed, int *y, int *m, int *d, double *f );
