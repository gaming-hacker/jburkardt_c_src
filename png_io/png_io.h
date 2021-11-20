unsigned char *i41_to_uc1 ( int width, int height, int *i41, int gmin, 
  int gmax );
int i4vec_max ( int n, int a[] );
int i4vec_min ( int n, int a[] );

unsigned char *r41_to_uc1 ( int width, int height, float *r41, float gmin, 
  float gmax );

unsigned char *r43_to_uc3 ( int width, int height, float *r43 );
unsigned char *r43_to_uc3_trimmed ( int width, int height, float *r43,
  float cmin[3], float cmax[3] );

float r4vec_max ( int n, float r4vec[] );
float r4vec_min ( int n, float r4vec[] );

int read_png ( const char *filename, int *width, int *height, 
  unsigned char **uc3, unsigned char **alpha );

unsigned char *uc1_to_uc3 ( int width, int height, unsigned char *uc1 );
unsigned char *uc1_to_uc3_hot ( int width, int height, unsigned char *uc1 );
unsigned char *uc1_to_uc3_hot2 ( int width, int height, unsigned char *uc1 );

unsigned char *ucrgb_to_uc3 ( int width, int height, unsigned char *ucr,
  unsigned char *ucg, unsigned char *ucb );

int write_png_i41 ( char *filename, int width, int height, int *i41 );
int write_png_i41_hot ( char *filename, int width, int height, int *i41 );
int write_png_i41_hot2 ( char *filename, int width, int height, int *i41 );

int write_png_r41 ( char *filename, int width, int height, float *r41 );
int write_png_r41_hot ( char *filename, int width, int height, float *r41 );
int write_png_r41_hot2 ( char *filename, int width, int height, float *r41 );
int write_png_r41_trimmed ( char *filename, int width, int height, float *r41,
  float gmin, float gmax );

int write_png_r43 ( char *filename, int width, int height, float *r43 );
int write_png_r43_trimmed ( char *filename, int width, int height, float *r43,
  float cmin[3], float cmax[3] );

int write_png_uc3 ( char *filename, int width, int height, 
  unsigned char *uc3, unsigned char *alpha );

