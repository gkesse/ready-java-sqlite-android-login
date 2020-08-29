//===============================================
#include "GGslTest.h"
//===============================================
GGslTest* GGslTest::m_instance = 0;
//===============================================
GGslTest::GGslTest() {
    
}
//===============================================
GGslTest::~GGslTest() {
    
}
//===============================================
GGslTest* GGslTest::Instance() {
    if(m_instance == 0) {
        m_instance = new GGslTest;
    }
    return m_instance;
}
//===============================================
void GGslTest::matrix() {
    int lRows = 5;
    int lCols = 3; 
    const char* lFile = "matrix.bin";
    
    // allocation
    printf("### allocation\n\n");
    gsl_spmatrix* lMat = gsl_spmatrix_alloc(lRows, lCols);
    
    // chargement
    for(int i = 0; i < lRows; i++) {
        for(int j = 0; j < lCols; j++) {
            double lData = i+j;
            gsl_spmatrix_set(lMat, i, j, lData);
        }
    }
    
    // affichage
    matrixShow(lMat);

    // sauvegarde
    printf("### sauvegarde\n\n");
    matrixSave(lFile, lMat);
    gsl_spmatrix* lLoad = matrixLoad(lFile, lRows, lCols);
    matrixShow(lLoad);
    
    // copie
    printf("### copie\n\n");
    gsl_spmatrix* lCopy = gsl_spmatrix_alloc(lRows, lCols);
    gsl_spmatrix_memcpy(lCopy, lMat);
    matrixShow(lCopy);
    
    // transposee
    printf("### transposee\n\n");
    gsl_spmatrix* lTranspose = gsl_spmatrix_alloc(lCols, lRows);
    gsl_spmatrix_transpose_memcpy(lTranspose, lMat);
    matrixShow(lTranspose);
    
    // mise a zero
    printf("### mise a zero\n\n");
    gsl_spmatrix_set_zero(lMat);
    matrixShow(lMat);
    
    // liberation
    gsl_spmatrix_free(lMat);
    gsl_spmatrix_free(lCopy);
    gsl_spmatrix_free(lTranspose);
    gsl_spmatrix_free(lLoad);
}
//===============================================
void GGslTest::matrixShow(gsl_spmatrix* mat) {
    int lRows = mat->size1;
    int lCols = mat->size2;
    for(int i = 0; i < lRows; i++) {
        for(int j = 0; j < lCols; j++) {
            if(j != 0) printf(" | ");
            double lData = gsl_spmatrix_get(mat, i, j);
            printf("%-3.0f", lData);
        }
        printf("\n");
    }
    printf("\n");
}
//===============================================
void GGslTest::matrixSave(const char* filename, gsl_spmatrix* mat) {
    FILE* lpFile = fopen(filename,"wb"); 
    gsl_spmatrix_fwrite(lpFile, mat);
    fclose(lpFile);
}
//===============================================
gsl_spmatrix* GGslTest::matrixLoad(const char* filename, int rows, int cols) {
    gsl_spmatrix* lMat = gsl_spmatrix_alloc_nzmax(rows, cols, rows*cols, 0);
    FILE* lpFile = fopen(filename,"rb"); 
    gsl_spmatrix_fread(lpFile, lMat);
    fclose(lpFile);
    return lMat;
}
//===============================================
