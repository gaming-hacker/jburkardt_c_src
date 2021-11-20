void sgemm ( char transa, char transb, int m, int n, int k, 
  float alpha, float a[], int lda, float b[], int ldb, float beta, 
  float c[], int ldc );
void strmm ( char side, char uplo, char transa, char diag, int m, int n, 
  float alpha, float a[], int lda, float b[], int ldb );
void strsm ( char side, char uplo, char transa, char diag, int m, int n, 
  float alpha, float a[], int lda, float b[], int ldb );

