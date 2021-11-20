int ch_is_digit ( char c );
int ch_is_isbn_digit ( char ch );
int ch_to_digit ( char ch );
char i4_to_isbn_digit ( int i );
void i4vec_print ( int n, int a[], char *title );
char isbn_check_digit_calculate ( char *s );
int isbn_is_valid ( char *s );
int isbn_digit_to_i4 ( char c );
int *s_to_digits ( char *s, int n );
int *s_to_isbn_digits ( char *s, int n );
void timestamp ( );

