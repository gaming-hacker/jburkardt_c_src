# include <stdio.h>

char ch_cap ( char ch );
bool pbmb_check_data ( int xsize, int ysize, int *barray );
bool pbmb_example ( int xsize, int ysize, int *barray );
bool pbmb_read ( char *file_name, int *xsize, int *ysize, int **barray );
bool pbmb_read_data ( FILE *file_pointer, int xsize, int ysize, int *barray );
bool pbmb_read_header ( FILE *file_pointer, int *xsize, int *ysize );
bool pbmb_read_test ( char *file_name );
bool pbmb_write ( char *file_name, int xsize, int ysize, int *barray );
bool pbmb_write_data ( FILE *file_pointer, int xsize, int ysize, int *barray );
bool pbmb_write_header ( FILE *file_pointer, int xsize, int ysize );
bool pbmb_write_test ( char *file_name );
void s_adjustl ( char *s );
int s_eqi ( char *s1, char *s2 );
int s_len_trim ( char *s );
char *s_word_extract_first ( char *s );
